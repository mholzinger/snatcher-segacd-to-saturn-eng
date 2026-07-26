# Ghidra headless post-script (Jython).
# Dumps decompiled C for the functions around known anchors:
# the "DATA.BIN" literal ref at 0x060b22e0 and "save old scene" ref at 0x060b212c,
# plus their callers, to analysis/ghidra_out/.

import os
from ghidra.app.decompiler import DecompInterface
from ghidra.util.task import ConsoleTaskMonitor

OUT = os.path.join(os.environ.get("SNATCHER_ROOT", "."), "analysis", "ghidra_out")
if not os.path.isdir(OUT):
    os.makedirs(OUT)

prog = currentProgram
listing = prog.getListing()
fm = prog.getFunctionManager()
decomp = DecompInterface()
decomp.openProgram(prog)
monitor = ConsoleTaskMonitor()

ANCHORS = [0x060B22E0, 0x060B212C]


def addr(a):
    return prog.getAddressFactory().getDefaultAddressSpace().getAddress(a)


def decompile_to(func, seen, depth_callers=1):
    if func is None or func.getEntryPoint() in seen:
        return
    seen.add(func.getEntryPoint())
    res = decomp.decompileFunction(func, 120, monitor)
    name = "%s_%s" % (func.getName(), func.getEntryPoint())
    path = os.path.join(OUT, name + ".c")
    f = open(path, "w")
    f.write(res.getDecompiledFunction().getC() if res.decompileCompleted() else "// decomp failed\n")
    f.close()
    print("dumped %s" % name)
    if depth_callers > 0:
        for caller in func.getCallingFunctions(monitor):
            decompile_to(caller, seen, depth_callers - 1)


seen = set()
rm = prog.getReferenceManager()
for a in ANCHORS:
    for ref in rm.getReferencesTo(addr(a)):
        src = ref.getFromAddress()
        func = fm.getFunctionContaining(src)
        print("anchor %x <- ref from %s in %s" % (a, src, func))
        decompile_to(func, seen, 1)

# also dump a full function index
f = open(os.path.join(OUT, "functions.txt"), "w")
for fn in fm.getFunctions(True):
    f.write("%s  %s  size=%d\n" % (fn.getEntryPoint(), fn.getName(), fn.getBody().getNumAddresses()))
f.close()
print("function index written")
