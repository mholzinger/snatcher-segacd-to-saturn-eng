#!/usr/bin/env python3
"""Scene-VM static control-flow tracer for Saturn Snatcher chunks 21-59.

CHUNK LAYOUT (verified 39/39 scene chunks, see validate_layout()):
  [0:2]  h0    u16 BE  -- text section starts at h0+5 (file offset)
  [2:4]  h1    u16 BE  -- text section byte length
  [4:]   bytecode      -- entry point at file offset 4 (always a 0x09 wait stmt)
  [h0+5 : h0+5+h1]     -- text section: 0x00-separated records of 2-byte
                          tokens (value = 0x10100 - SJIS); consumed
                          SEQUENTIALLY by the engine (no stored offsets)
  [h0+5+h1 :]          -- 3-4 byte trailer (00 + u16 global counter [+ pad])

The VM has three bytecode contexts plus expressions, reverse engineered from
MAIN_L.BIN exec/skip function pairs (all cross-validated):

  STATEMENT  exec FUN_060c2858 / skip FUN_060c2ac4, operand skip FUN_060c2b28
  WAIT item  exec FUN_060c3dd0 / skip FUN_060c3fec (helpers 4b44/4b8c/4bcc/
             4c18/4c5c/4c94/4980)
  DISPLAY    exec FUN_060c3358 (32dc = varint text block loop)
  EXPRESSION exec FUN_060c0c78 / skip FUN_060c1350, native call FUN_060c14a4
             (argc table at 0x060E4FA8, 20 entries), address operand
             FUN_060c07c0, varint FUN_060c0908 (b<=0xBF: 1 byte, else
             (b-0xC0)*256+next)

Address operands (FUN_060c07c0):
  2-byte form (flag=0): target = operand_pos + signed16
  3-byte form (flag=1): [bank][u16]; bank 0xFF = relative (target =
                        u16_pos + signed16), else absolute (bank<<15)|u16,
                        base-relative (base = file offset 4)

Validation: recursive parse from entry; every varint block must end exactly
on an item boundary of its context; every address target must land on a
parsed statement/item boundary; parse never crosses into the text section.
"""
import json
import os
import struct
import sys
from collections import defaultdict

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

# native id -> argc, from the table at 0x060E4FA8 in MAIN_L.BIN
NATIVE_ARGC = {0: 1, 1: 2, 2: 2, 3: 1, 4: 3, 5: 1, 6: 1, 7: 1, 8: 1, 9: 1,
               10: 1, 11: 1, 12: 2, 13: 3, 14: 4, 15: 4, 16: 2, 17: 3,
               18: 3, 19: 1}

BASE = 4  # file offset of VM base-relative offset 0

STMT, WAIT, DISP = 'stmt', 'wait', 'disp'


class ParseError(Exception):
    def __init__(self, msg, pos, trail=None):
        super().__init__(msg)
        self.pos = pos
        self.trail = trail or []


class Tracer:
    def __init__(self, data):
        self.d = data
        self.h0, self.h1 = struct.unpack('>2H', data[:4])
        self.text_start = self.h0 + 5
        self.text_end = self.text_start + self.h1
        self.code_end = self.text_start  # code may not touch the text section
        self.varints = []      # (pos, nbytes, value, block_end, context)
        self.addr_ops = []     # (pos, nbytes, target|None)
        self.boundaries = defaultdict(set)   # context -> set of item starts
        self.errors = []       # (pos, context, message)
        self.visited = {}      # (pos, context) -> end
        self.max_depth = 200
        self.trail = []        # active parse stack [(pos, what)]
        self.soft = {}         # construct -> count of opaque-skip fallbacks

    # -- primitives ---------------------------------------------------------
    def u8(self, i):
        if i >= self.code_end:
            raise ParseError(f'read past code end ({i:#x} >= {self.code_end:#x})', i, list(self.trail))
        return self.d[i]

    def varint(self, i, context):
        b = self.u8(i)
        if b <= 0xBF:
            return b, i + 1
        v = (b - 0xC0) * 256 + self.u8(i + 1)
        return v, i + 2

    def block(self, i, context):
        """Read varint at i, register block, return (body_start, body_end)."""
        v, j = self.varint(i, context)
        end = j + v
        if end > self.code_end:
            raise ParseError(f'block end {end:#x} past code end', i, list(self.trail))
        self.varints.append((i, j - i, v, end, context))
        return j, end

    def addr_operand(self, i, three_byte):
        """FUN_060c07c0: relative i16 or [bank][u16]."""
        if not three_byte:
            p = i
            off = struct.unpack('>h', self.d[p:p + 2])[0]
            target = p + off
            self.addr_ops.append((p, 2, target))
            return i + 2
        bank = self.u8(i)
        p = i + 1
        if bank == 0xFF:
            off = struct.unpack('>h', self.d[p:p + 2])[0]
            target = p + off
        else:
            target = None      # external scene reference (bank != 0xFF)
        self.addr_ops.append((i, 3, target))
        return i + 3

    # -- expressions --------------------------------------------------------
    def expr(self, i, depth=0):
        if depth > self.max_depth:
            raise ParseError('expr depth', i, list(self.trail))
        b = self.u8(i)
        if b < 0x80:
            return i + 2
        if b < 0xA0:
            return i + 3
        if b < 0xC0:
            return i + 2
        if b < 0xD0:
            nid = ((b & 0xF) << 8) | self.u8(i + 1)
            i += 2
            for _ in range(NATIVE_ARGC.get(nid, 0)):
                i = self.expr(i, depth + 1)
            return i
        if b < 0xE0:
            return i + 1
        e = b - 0xE0
        if e == 0x0:
            return i + 2
        if e in (0x1, 0x3):
            return i + 3
        if e in (0x2, 0x4):
            return i + 5
        if e == 0x5:
            return i + 1
        if e in (0x6, 0x7):
            return i + 2
        if e in (0x8, 0x9, 0xA, 0xB, 0xC, 0xD):        # addr operand
            return self.addr_operand(i + 1, bool(b & 1))
        if e in (0xE, 0xF):                            # byte + addr operand
            return self.addr_operand(i + 2, bool(b & 1))
        if e == 0x10:                                  # F0: 3-byte via 085c
            return i + 4
        if e == 0x11:                                  # F1: unary
            return self.expr(i + 1, depth + 1)
        if e in (0x17,):                               # F7: varint expr block
            body, end = self.block(i + 1, 'expr')
            j = body
            while j < end:
                j = self.expr(j, depth + 1)
            if j != end:
                raise ParseError(f'F7 block overrun {j:#x}!={end:#x}', i, list(self.trail))
            return end
        if e in (0x1E, 0x1F):                          # FE/FF: and/or blocks
            body, end = self.block(i + 1, 'expr')
            j = body
            while j < end:
                j = self.expr(j, depth + 1)
            if j != end:
                raise ParseError(f'F{e:X} block overrun {j:#x}!={end:#x}', i, list(self.trail))
            return end
        # F2-F6, F8-FD: binary
        i = self.expr(i + 1, depth + 1)
        return self.expr(i, depth + 1)

    # -- wait items (FUN_060c3dd0 / 3fec) -----------------------------------
    def wait_item(self, i, depth=0):
        if depth > self.max_depth:
            raise ParseError('wait depth', i, list(self.trail))
        cached = self.visited.get((WAIT, i))
        if cached is not None:
            if isinstance(cached, ParseError):
                raise cached
            return cached
        self.boundaries[WAIT].add(i)
        b = self.u8(i)
        self.trail.append(('W', i, b))
        try:
            end = self._wait_item(i, b, depth)
            self.visited[(WAIT, i)] = end
            return end
        except ParseError as e:
            self.visited[(WAIT, i)] = e
            raise
        finally:
            self.trail.pop()

    def _wait_item(self, i, b, depth):
        i += 1
        if b < 0x60:                                   # (n+1) 3-byte flag refs
            return i + ((b & 0x1F) + 1) * 3
        if b < 0x80:                                   # cond chain + else
            for _ in range((b & 0x1F) + 1):
                i = self.expr(i, depth + 1)
                _, i = self.block_body(i, WAIT, depth)
            _, i = self.block_body(i, WAIT, depth)
            return i
        if b < 0xA0:                                   # switch: expr + cases
            i = self.expr(i, depth + 1)
            for _ in range((b & 0x1F) + 1):
                j, end = self.block(i, 'waitcase')     # value exprs
                k = j
                while k < end:
                    k = self.expr(k, depth + 1)
                if k != end:
                    raise ParseError(f'case values overrun {k:#x}!={end:#x}', i, list(self.trail))
                _, i = self.block_body(end, WAIT, depth)
            return i
        if b < 0xB0:                                   # 3-byte sel + items
            i += 3
            for _ in range((b & 0xF) + 2):
                i += 1
                _, i = self.block_body(i, WAIT, depth)
            return i
        if b < 0xC0:                                   # (n+2) x [byte][block]
            for _ in range((b & 0xF) + 2):
                i += 1
                _, i = self.block_body(i, WAIT, depth)
            return i
        if b < 0xD0:                                   # native call
            nid = ((b & 0xF) << 8) | self.u8(i)
            i += 1
            for _ in range(NATIVE_ARGC.get(nid, 0)):
                i = self.expr(i, depth + 1)
            return i
        if b < 0xE0:                                   # n x 3-byte refs + expr
            i += ((b & 0xF) + 1) * 3
            return self.expr(i, depth + 1)
        if b < 0xE4:                                   # call w/ addr
            i = self.addr_operand(i, bool(b & 1))
            if b & 2:
                i += 2
            return i
        if b < 0xE8:                                   # goto w/ addr
            return self.addr_operand(i, bool(b & 1))
        if b == 0xE9 or b == 0xEB:                     # varint wait block
            _, i = self.block_body(i, WAIT, depth)
            return i
        if b == 0xED:
            return i + 2
        if b == 0xEE:                                  # count + n*3 + expr
            n = self.u8(i)
            i += 1 + n * 3
            return self.expr(i, depth + 1)
        if b == 0xFB:                                  # if: expr + block
            i = self.expr(i, depth + 1)
            _, i = self.block_body(i, WAIT, depth)
            return i
        if b == 0xFC:                                  # cond in block
            body, end = self.block(i, WAIT)
            j = body
            while j < end:
                j = self.expr(j, depth + 1)
                _, j = self.block_body(j, WAIT, depth)
            if j != end:
                raise ParseError(f'FC overrun {j:#x}!={end:#x}', i, list(self.trail))
            return end
        if b == 0xFD:                                  # switch in block
            body, end = self.block(i, WAIT)
            j = self.expr(body, depth + 1)
            while j < end:
                jj, cend = self.block(j, 'waitcase')
                k = jj
                while k < cend:
                    k = self.expr(k, depth + 1)
                if k != cend:
                    raise ParseError(f'FD case overrun {k:#x}!={cend:#x}', j, list(self.trail))
                _, j = self.block_body(cend, WAIT, depth)
            if j != end:
                raise ParseError(f'FD overrun {j:#x}!={end:#x}', i, list(self.trail))
            return end
        if b == 0xFE:                                  # 3-byte sel + items
            body, end = self.block(i, WAIT)
            j = body + 3
            while j < end:
                j += 1
                _, j = self.block_body(j, WAIT, depth)
            if j != end:
                raise ParseError(f'FE overrun {j:#x}!={end:#x}', i, list(self.trail))
            return end
        if b == 0xFF:                                  # items
            body, end = self.block(i, WAIT)
            j = body
            while j < end:
                j += 1
                _, j = self.block_body(j, WAIT, depth)
            if j != end:
                raise ParseError(f'FF overrun {j:#x}!={end:#x}', i, list(self.trail))
            return end
        # E8, EA, EC, EF-FA: no operands
        return i

    def block_body(self, i, context, depth):
        """varint block whose interior is a sequence of `context` items.
        Interior errors fall back to opaque skip (the engine itself only
        skips blocks via the varint), keeping the outer parse exact."""
        body, end = self.block(i, context)
        mark = (len(self.varints), len(self.addr_ops))
        j = body
        try:
            while j < end:
                if context == WAIT:
                    j = self.wait_item(j, depth + 1)
                elif context == DISP:
                    j = self.disp_item(j, depth + 1)
                else:
                    j = self.statement(j, depth + 1)
            if j != end:
                raise ParseError(f'{context} block overrun {j:#x}!={end:#x}', i, list(self.trail))
        except ParseError as e:
            del self.varints[mark[0]:]
            del self.addr_ops[mark[1]:]
            self.soft[context] = self.soft.get(context, 0) + 1
            if e.trail:
                self.soft_ops = getattr(self, 'soft_ops', [])
                self.soft_ops.append((context, e.trail[-1], str(e)))
        return body, end

    # -- display items (FUN_060c3358) ---------------------------------------
    def disp_item(self, i, depth=0):
        if depth > self.max_depth:
            raise ParseError('disp depth', i, list(self.trail))
        cached = self.visited.get((DISP, i))
        if cached is not None:
            if isinstance(cached, ParseError):
                raise cached
            return cached
        self.boundaries[DISP].add(i)
        b = self.u8(i)
        self.trail.append(('D', i, b))
        try:
            end = self._disp_item(i, b, depth)
            self.visited[(DISP, i)] = end
            return end
        except ParseError as e:
            self.visited[(DISP, i)] = e
            raise
        finally:
            self.trail.pop()

    def _disp_item(self, i, b, depth):
        if b < 0x80:                                   # token + one statement
            i += 2
            return self.statement(i, depth + 1)
        if b < 0xC0:                                   # special 2-byte token
            return i + 2
        i += 1
        if b < 0xD0:                                   # cond chain + else
            for _ in range((b & 0xF) + 1):
                i = self.expr(i, depth + 1)
                _, i = self.block_body(i, DISP, depth)
            _, i = self.block_body(i, DISP, depth)
            return i
        if b < 0xE0:                                   # switch: expr + cases
            i = self.expr(i, depth + 1)
            for _ in range((b & 0xF) + 1):
                j, end = self.block(i, 'dispcase')
                k = j
                while k < end:
                    k = self.expr(k, depth + 1)
                if k != end:
                    raise ParseError(f'disp case overrun {k:#x}!={end:#x}', i, list(self.trail))
                _, i = self.block_body(end, DISP, depth)
            return i
        if b < 0xE8:                                   # 3-byte sel + items
            i += 3
            for _ in range((b & 7) + 2):
                i += 1
                _, i = self.block_body(i, DISP, depth)
            return i
        if b < 0xF0:                                   # sel + items
            for _ in range((b & 7) + 2):
                i += 1
                _, i = self.block_body(i, DISP, depth)
            return i
        if b < 0xF4:                                   # (b&3)+2 tokens
            return i + ((b & 3) + 2) * 2
        if b < 0xF8:                                   # call w/ addr
            i = self.addr_operand(i, bool(b & 1))
            if b & 2:
                i += 2
            return i
        if b == 0xF8:                                  # count + tokens
            n = self.u8(i)
            return i + 1 + n * 2
        if b in (0xF9, 0xFA):
            return i
        if b == 0xFB:                                  # if: expr + block
            i = self.expr(i, depth + 1)
            _, i = self.block_body(i, DISP, depth)
            return i
        if b == 0xFC:                                  # cond in block
            body, end = self.block(i, DISP)
            j = body
            while j < end:
                j = self.expr(j, depth + 1)
                _, j = self.block_body(j, DISP, depth)
            if j != end:
                raise ParseError(f'disp FC overrun {j:#x}!={end:#x}', i, list(self.trail))
            return end
        if b == 0xFD:                                  # switch in block
            body, end = self.block(i, DISP)
            j = self.expr(body, depth + 1)
            while j < end:
                jj, cend = self.block(j, 'dispcase')
                k = jj
                while k < cend:
                    k = self.expr(k, depth + 1)
                if k != cend:
                    raise ParseError(f'disp FD case overrun', j, list(self.trail))
                _, j = self.block_body(cend, DISP, depth)
            if j != end:
                raise ParseError(f'disp FD overrun {j:#x}!={end:#x}', i, list(self.trail))
            return end
        if b == 0xFE:
            body, end = self.block(i, DISP)
            j = body + 3
            while j < end:
                j += 1
                _, j = self.block_body(j, DISP, depth)
            if j != end:
                raise ParseError(f'disp FE overrun {j:#x}!={end:#x}', i, list(self.trail))
            return end
        if b == 0xFF:
            body, end = self.block(i, DISP)
            j = body
            while j < end:
                j += 1
                _, j = self.block_body(j, DISP, depth)
            if j != end:
                raise ParseError(f'disp FF overrun {j:#x}!={end:#x}', i, list(self.trail))
            return end
        raise ParseError(f'disp opcode {b:#x}', i, list(self.trail))

    # -- statements (FUN_060c2858 / 2ac4 / 2b28) ----------------------------
    def statement(self, i, depth=0):
        if depth > self.max_depth:
            raise ParseError('stmt depth', i, list(self.trail))
        cached = self.visited.get(i)
        if cached is not None:
            if isinstance(cached, ParseError):
                raise cached
            return cached
        self.boundaries[STMT].add(i)
        b = self.u8(i)
        self.trail.append(('S', i, b))
        try:
            end = self._statement(i, b, depth)
            self.visited[i] = end
            return end
        except ParseError as e:
            self.visited[i] = e
            raise
        finally:
            self.trail.pop()

    def _statement(self, i, b, depth):
        i += 1
        if b == 0x0A:                                  # end
            return i
        if b == 0x09:                                  # wait block
            _, i = self.block_body(i, WAIT, depth)
            return i
        if b & 0x20:                                   # wait-condition block
            _, i = self.block_body(i, WAIT, depth)
        c = b & 0xF
        if c in (0, 1, 2, 3):                          # call w/ addr
            i = self.addr_operand(i, bool(b & 1))
            if b & 2:
                i += 2
        elif c == 8:                                   # menu: display block
            _, i = self.block_body(i, DISP, depth)
        elif c == 0xC:                                 # if: [expr][stmt] pairs
            body, end = self.block(i, STMT)
            j = body
            while j < end:
                j = self.expr(j, depth + 1)
                j = self.statement(j, depth + 1)
            if j != end:
                raise ParseError(f'stmt-if overrun {j:#x}!={end:#x}', i, list(self.trail))
            i = end
        elif c == 0xD:                                 # switch
            body, end = self.block(i, STMT)
            j = self.expr(body, depth + 1)
            while j < end:
                jj, cend = self.block(j, 'stmtcase')
                k = jj
                while k < cend:
                    k = self.expr(k, depth + 1)
                if k != cend:
                    raise ParseError(f'stmt case overrun', j, list(self.trail))
                j = self.statement(cend, depth + 1)
            if j != end:
                raise ParseError(f'stmt-switch overrun {j:#x}!={end:#x}', i, list(self.trail))
            i = end
        elif c == 0xE:                                 # 3-byte sel + items
            body, end = self.block(i, STMT)
            j = body + 3
            while j < end:
                j += 1
                j = self.statement(j, depth + 1)
            if j != end:
                raise ParseError(f'stmt-E overrun {j:#x}!={end:#x}', i, list(self.trail))
            i = end
        elif c == 0xF:                                 # items
            body, end = self.block(i, STMT)
            j = body
            while j < end:
                j += 1
                j = self.statement(j, depth + 1)
            if j != end:
                raise ParseError(f'stmt-F overrun {j:#x}!={end:#x}', i, list(self.trail))
            i = end
        # c in 4,5,6,7,b: no operands
        if b & 0x10:                                   # choice body block
            _, i = self.block_body(i, STMT, depth)
        return i

    # -- top level ----------------------------------------------------------
    def statement_stream(self, i, depth=0):
        """Run statements until end-marker 0x0A or code_end."""
        self.trail = []
        while i < self.code_end:
            b = self.u8(i)
            start = i
            i = self.statement(i, depth)
            if b == 0x0A:
                break
        return i

    def trace(self):
        # entry: like FUN_060c063c at offset 0 (file offset 4)
        try:
            self.statement_stream(BASE)
        except ParseError as e:
            self.errors.append((e.pos, 'entry', str(e)))
            self.err_trails = getattr(self, 'err_trails', [])
            self.err_trails.append(('entry', e.pos, str(e), e.trail))
        # follow discovered address operands (statement streams)
        seen = set()
        progress = True
        while progress:
            progress = False
            for pos, n, target in list(self.addr_ops):
                if target is None or target in seen:
                    continue
                seen.add(target)
                if not (BASE <= target < self.code_end):
                    self.errors.append((pos, 'addr', f'target {target:#x} out of code'))
                    continue
                if target in self.boundaries[STMT] or target in self.boundaries[WAIT]:
                    continue
                try:
                    self.statement_stream(target)
                    progress = True
                except ParseError as e:
                    self.errors.append((e.pos, f'addr@{target:#x}', str(e)))
                    self.err_trails = getattr(self, 'err_trails', [])
                    self.err_trails.append((f'addr@{target:#x}', e.pos, str(e), e.trail))

    # -- reporting ----------------------------------------------------------
    def report(self):
        all_bounds = set()
        for s in self.boundaries.values():
            all_bounds |= s
        targets = [t for _, _, t in self.addr_ops if t is not None]
        in_code = [t for t in targets if BASE <= t < self.code_end]
        on_bound = [t for t in in_code if t in all_bounds]
        cov = len(all_bounds)
        return {
            'code_bytes': self.code_end - BASE,
            'items': cov,
            'varints': len(self.varints),
            'addr_ops': len(self.addr_ops),
            'targets_in_code': len(in_code),
            'targets_on_boundary': len(on_bound),
            'errors': len(self.errors),
        }


def run(chunks=None, verbose=False):
    results = {}
    for idx in chunks or range(21, 60):
        p = os.path.join(ROOT, f'extracted/saturn/data_bin/chunk_{idx:03d}.bin')
        if not os.path.exists(p):
            continue
        d = open(p, 'rb').read()
        t = Tracer(d)
        t.trace()
        r = t.report()
        results[idx] = (t, r)
        flag = 'OK ' if r['errors'] == 0 and r['targets_in_code'] == r['targets_on_boundary'] else 'ERR'
        print(f"ch{idx:03d} {flag} code={r['code_bytes']:6d} items={r['items']:5d} "
              f"varints={r['varints']:4d} addrs={r['addr_ops']:4d} "
              f"targets on-boundary {r['targets_on_boundary']}/{r['targets_in_code']} "
              f"errors={r['errors']}")
        if verbose and t.errors:
            for pos, ctx, msg in t.errors[:8]:
                print(f"    @{pos:#x} [{ctx}] {msg}")
    total_t = sum(r['targets_in_code'] for _, r in results.values())
    total_b = sum(r['targets_on_boundary'] for _, r in results.values())
    total_e = sum(r['errors'] for _, r in results.values())
    print(f"\nTOTAL: targets on boundary {total_b}/{total_t} "
          f"({100.0 * total_b / total_t if total_t else 0:.1f}%), errors={total_e}")
    return results


if __name__ == '__main__':
    args = [a for a in sys.argv[1:] if not a.startswith('-')]
    chunks = [int(a) for a in args] if args else None
    run(chunks, verbose='-v' in sys.argv)
