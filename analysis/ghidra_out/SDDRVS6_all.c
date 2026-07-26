typedef unsigned char   undefined;

typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned short    ushort;



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined8 FUN_000013e6(void)

{
  undefined4 in_D0;
  undefined4 in_D1;
  
  if ((_DAT_00100420 & 0x80) != 0) {
    _DAT_0010041a = 0x1d4;
    _DAT_00100422 = 0x80;
    _DAT_0000781a = _DAT_0000781a + 0xa0;
    _DAT_00007838 = _DAT_00007838 + 1;
    FUN_0000431c();
  }
  return CONCAT44(in_D0,in_D1);
}



void FUN_0000428c(void)

{
  return;
}



void FUN_00004292(void)

{
  return;
}



void FUN_0000431c(void)

{
  short sVar1;
  int unaff_A4;
  
  FUN_00004b76();
  *(char *)(unaff_A4 + 5) = *(char *)(unaff_A4 + 5) + '\x01';
  if ((*(byte *)(unaff_A4 + 1) & 0x80) == 0) {
    *(byte *)(unaff_A4 + 1) = *(byte *)(unaff_A4 + 1) | 0x80;
    FUN_00004a5c();
    FUN_00004acc();
    sVar1 = 0x1f;
    do {
      FUN_000049ee();
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
    FUN_00004b76();
    FUN_00004798();
    FUN_00004798();
    FUN_00004798();
    FUN_00004798();
    FUN_00004798();
    FUN_00004798();
    FUN_00004798();
    FUN_00004798();
    *(byte *)(unaff_A4 + 1) = *(byte *)(unaff_A4 + 1) & 0x7f;
  }
  FUN_0000428c();
  return;
}



void FUN_0000446e(void)

{
  ushort uVar1;
  undefined2 *puVar2;
  uint uVar3;
  uint uVar4;
  byte in_D0b;
  int iVar5;
  byte bVar6;
  byte in_D1b;
  uint unaff_D2;
  byte unaff_D3b;
  undefined4 unaff_D4;
  undefined4 in_A0;
  ushort *extraout_A0;
  undefined4 unaff_A4;
  undefined4 unaff_A5;
  byte *unaff_A6;
  undefined8 uVar7;
  
  *unaff_A6 = 0;
  FUN_00004c2a();
  unaff_A6[0x20] = 0;
  unaff_D2 = unaff_D2 & 1;
  unaff_A6[1] = in_D0b & 7;
  unaff_A6[4] = in_D1b & 0x1f;
  unaff_A6[5] = (byte)unaff_D2;
  *(undefined4 *)(unaff_A6 + 0x10) = in_A0;
  unaff_A6[2] = 1;
  if ((*unaff_A6 & 0x10) != 0) {
    unaff_A6[2] = 2;
  }
  unaff_A6[3] = 0;
  iVar5 = FUN_00004cde();
  iVar5 = iVar5 * 2 + DAT_00000404;
  *(int *)(unaff_A6 + 0x3c) = iVar5 + 0x80;
  puVar2 = (undefined2 *)(iVar5 + 0xb0);
  *(undefined2 **)(unaff_A6 + 0x38) = puVar2;
  *puVar2 = 0;
  uVar1 = *extraout_A0;
  if ((uVar1 < 0x18) || (0x3c0 < uVar1)) {
    unaff_A6[3] = 0x80;
    goto LAB_00004606;
  }
  *(ushort *)(unaff_A6 + 6) = uVar1;
  unaff_A6[0x20] = 0;
  FUN_00004ec0();
  uVar7 = FUN_00004e44();
  bVar6 = (byte)((ulonglong)uVar7 >> 0x20);
  if (bVar6 == 0) {
    if ((unaff_D2 < 200000) || (1500000 < unaff_D2)) {
      unaff_A6[3] = 0x83;
      goto LAB_00004606;
    }
    *(int *)(unaff_A6 + 0xc) = (int)uVar7;
    *(uint *)(unaff_A6 + 8) = unaff_D2;
    *(int *)(unaff_A6 + 0x1c) = (int)uVar7 << 8;
    uVar1 = *(ushort *)(unaff_A6 + 6);
    uVar3 = unaff_D2 / uVar1;
    uVar4 = 0x7d000 / uVar3 & 0xffff;
    *(uint *)(unaff_A6 + 0x14) = uVar4;
    *(uint *)(unaff_A6 + 0x30) = uVar4;
    FUN_00004ec0(unaff_A4,unaff_A5);
    uVar7 = FUN_00004e44();
    bVar6 = (byte)((ulonglong)uVar7 >> 0x20);
    if (bVar6 == 0) {
      unaff_A6[0x2d] = unaff_D3b & 0xf0;
      unaff_A6[0x2f] = (byte)unaff_D4;
      unaff_A6[0x2e] = (byte)((uint)unaff_D4 >> 0x10);
      *(int *)(unaff_A6 + 0x18) = (int)uVar7 << 8;
      *(uint *)(unaff_A6 + 0x28) = (unaff_D2 % (uint)uVar1 << 0x10 | uVar3) << 8;
      unaff_A6[0x2d] = (byte)((ulonglong)uVar7 >> 0x28) & 0xf | unaff_A6[0x2d];
      unaff_A6[0x2c] = (byte)(((ushort)((ulonglong)uVar7 >> 0x28) & 0xff) >> 4) & 1;
      *unaff_A6 = *unaff_A6 & 0x10;
      *unaff_A6 = *unaff_A6 | 0x80;
      FUN_0000428c();
      return;
    }
    if (bVar6 == 1) {
      unaff_A6[3] = 0x82;
      goto LAB_00004606;
    }
  }
  unaff_A6[3] = bVar6;
LAB_00004606:
  FUN_00004cde();
  FUN_00004292();
  return;
}



void FUN_00004798(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  uint uVar7;
  char cVar8;
  byte bVar9;
  uint unaff_D2;
  int iVar10;
  byte bVar11;
  uint unaff_D4;
  undefined4 unaff_A4;
  undefined4 unaff_A5;
  byte *unaff_A6;
  undefined8 uVar12;
  
  if ((*unaff_A6 & 0x80) == 0) {
    return;
  }
  if ((*unaff_A6 & 0x40) != 0) {
    return;
  }
  uVar1 = *(uint *)(unaff_A6 + 0x1c);
  *(uint *)(unaff_A6 + 0x1c) = uVar1 - *(uint *)(unaff_A6 + 0x14);
  if (uVar1 < *(uint *)(unaff_A6 + 0x14)) {
    FUN_00004ec0();
    uVar12 = FUN_00004e44();
    bVar9 = (byte)((ulonglong)uVar12 >> 0x20);
    if ((bVar9 == 0) || (bVar9 == 2)) {
      if ((199999 < unaff_D2) && (unaff_D2 < 0x16e361)) {
        *(int *)(unaff_A6 + 0xc) = (int)uVar12;
        *(uint *)(unaff_A6 + 8) = unaff_D2;
        *(int *)(unaff_A6 + 0x1c) = (int)uVar12 * 0x100 + *(int *)(unaff_A6 + 0x1c);
        uVar1 = unaff_D2 / *(ushort *)(unaff_A6 + 6) & 0xffff;
        unaff_D2 = unaff_D2 % (uint)*(ushort *)(unaff_A6 + 6) << 0x10 | uVar1;
        uVar1 = 0x7d000 / uVar1 & 0xffff;
        *(uint *)(unaff_A6 + 0x14) = uVar1;
        *(uint *)(unaff_A6 + 0x30) = uVar1;
        goto LAB_00004826;
      }
      unaff_A6[3] = 0x83;
    }
    else {
      if (bVar9 == 1) goto LAB_00004826;
LAB_000049d2:
      unaff_A6[3] = bVar9;
    }
    FUN_00004c2a();
  }
  else {
LAB_00004826:
    if (((*unaff_A6 & 0x10) == 0) ||
       (bVar9 = unaff_A6[0x35], unaff_A6[0x35] = bVar9 - 1, bVar9 != 0)) {
LAB_000048b4:
      bVar9 = unaff_A6[0x34];
      unaff_A6[0x34] = bVar9 - 1;
      if (bVar9 == 0) {
        unaff_A6[0x34] = 0x31;
        **(short **)(unaff_A6 + 0x38) = **(short **)(unaff_A6 + 0x38) + 1;
      }
      if ((*unaff_A6 & 1) != 0) {
        return;
      }
      uVar1 = *(uint *)(unaff_A6 + 0x18);
      uVar7 = uVar1 - *(uint *)(unaff_A6 + 0x14);
      *(uint *)(unaff_A6 + 0x18) = uVar7;
      if ((uVar7 != 0) && (*(uint *)(unaff_A6 + 0x14) <= uVar1)) {
        return;
      }
      iVar10 = CONCAT31((int3)(unaff_D2 >> 8),unaff_A6[0x2f]);
      bVar11 = unaff_A6[0x2c];
      cVar8 = FUN_00004d54();
      if (cVar8 == -0x70) {
        iVar2 = *(int *)(unaff_A6 + 0x28);
        iVar3 = *(int *)(unaff_A6 + 0x18);
        FUN_00004d08();
        unaff_A6[0x20] = unaff_A6[0x20] + 1;
        unaff_D4 = iVar3 + iVar2;
      }
      while( true ) {
        FUN_00004ec0(unaff_A4,unaff_A5);
        uVar12 = FUN_00004e44();
        bVar9 = (byte)((ulonglong)uVar12 >> 0x20);
        if (bVar9 != 0) break;
        unaff_A6[0x2d] = bVar11 & 0xf0;
        unaff_A6[0x2f] = (byte)unaff_D4;
        unaff_A6[0x2e] = (byte)(unaff_D4 >> 0x10);
        unaff_A6[0x2d] = (byte)((ulonglong)uVar12 >> 0x28) & 0xf | unaff_A6[0x2d];
        unaff_A6[0x2c] = (byte)(((ushort)((ulonglong)uVar12 >> 0x28) & 0xff) >> 4) & 1;
        *(int *)(unaff_A6 + 0x28) = iVar10 << 8;
        iVar2 = (int)uVar12 * 0x100 + *(int *)(unaff_A6 + 0x18);
        *(int *)(unaff_A6 + 0x18) = iVar2;
        if ((iVar2 != 0) && (-1 < iVar2)) {
          return;
        }
        iVar10 = CONCAT31((int3)iVar10,unaff_A6[0x2f]);
        bVar11 = unaff_A6[0x2c];
        cVar8 = FUN_00004d54();
        unaff_D4 = unaff_D4 << 0x10 | unaff_D4 >> 0x10;
        if (cVar8 == -0x70) {
          unaff_D4 = *(int *)(unaff_A6 + 0x18) + *(int *)(unaff_A6 + 0x28);
          FUN_00004d08();
          unaff_A6[0x20] = unaff_A6[0x20] + 1;
        }
      }
      if (bVar9 != 1) goto LAB_000049d2;
      *unaff_A6 = *unaff_A6 | 1;
      if (unaff_A6[0x20] != 0) {
        return;
      }
    }
    else {
      unaff_A6[0x35] = 0x31;
      uVar4 = *(ushort *)(unaff_A6 + 0x22);
      uVar5 = *(ushort *)(unaff_A6 + 0x26);
      unaff_D2 = CONCAT22((short)(unaff_D2 >> 0x10),uVar5);
      if (uVar4 <= *(ushort *)(unaff_A6 + 0x24)) {
        uVar6 = *(ushort *)(unaff_A6 + 0x24);
        *(ushort *)(unaff_A6 + 0x24) = uVar6 - uVar5;
        if (((uVar6 < uVar5) || (uVar4 == *(ushort *)(unaff_A6 + 0x24))) ||
           (*(ushort *)(unaff_A6 + 0x24) <= uVar4)) {
LAB_00004886:
          *unaff_A6 = *unaff_A6 & 0xef;
          unaff_A6[2] = 1;
          unaff_A6[3] = 0;
          FUN_00004cde();
        }
        goto LAB_000048b4;
      }
      uVar6 = *(ushort *)(unaff_A6 + 0x24);
      *(ushort *)(unaff_A6 + 0x24) = uVar5 + uVar6;
      if (((!CARRY2(uVar5,uVar6)) && (uVar4 != *(ushort *)(unaff_A6 + 0x24))) &&
         (*(ushort *)(unaff_A6 + 0x24) <= uVar4)) goto LAB_000048b4;
      if (uVar4 != 0x7f00) goto LAB_00004886;
      *unaff_A6 = 0;
      FUN_00004c2a();
      unaff_A6[0x20] = 0;
    }
    unaff_A6[3] = 0;
  }
  unaff_A6[2] = 0;
  *unaff_A6 = 0;
  FUN_00004cde();
  return;
}



void FUN_000049ee(void)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  byte *unaff_A5;
  
  if (((*unaff_A5 & 0x80) != 0) && (pbVar1 = *(byte **)(unaff_A5 + 8), (*pbVar1 & 0x40) == 0)) {
    iVar3 = *(int *)(unaff_A5 + 4) - *(int *)(pbVar1 + 0x14);
    *(int *)(unaff_A5 + 4) = iVar3;
    if ((iVar3 == 0) || (iVar3 < 0)) {
      FUN_00004d54();
      *unaff_A5 = *unaff_A5 & 0x7f;
      bVar2 = pbVar1[0x20] - 1;
      pbVar1[0x20] = bVar2;
      if ((bVar2 == 0) && ((*pbVar1 & 1) != 0)) {
        *pbVar1 = 0;
        pbVar1[2] = 0;
        pbVar1[3] = 0;
        FUN_00004cde();
      }
    }
  }
  return;
}



void FUN_00004a5c(void)

{
  char cVar1;
  int iVar2;
  undefined2 uVar3;
  int unaff_A4;
  
  if (((*(byte *)(unaff_A4 + 2) & 0x80) != 0) &&
     (cVar1 = *(char *)(unaff_A4 + 3), *(char *)(unaff_A4 + 3) = cVar1 + -1, cVar1 == '\0')) {
    *(undefined *)(unaff_A4 + 3) = 7;
    iVar2 = DAT_00000404;
    FUN_00004dc4();
    FUN_00004dc4();
    uVar3 = FUN_00004dc4();
    *(undefined2 *)(iVar2 + 0x96) = uVar3;
    uVar3 = FUN_00004dc4();
    *(undefined2 *)(iVar2 + 0x9a) = uVar3;
    uVar3 = FUN_00004dc4();
    *(undefined2 *)(iVar2 + 0x9e) = uVar3;
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00004acc(void)

{
  char cVar1;
  byte *pbVar2;
  byte extraout_D1b;
  short sVar3;
  int unaff_A4;
  
  cVar1 = *(char *)(unaff_A4 + 4);
  *(char *)(unaff_A4 + 4) = cVar1 + -1;
  if (cVar1 == '\0') {
    *(undefined *)(unaff_A4 + 4) = 7;
    FUN_00004b42();
    sVar3 = 7;
    do {
      FUN_00004de0();
      pbVar2 = DAT_00000412;
      sVar3 = sVar3 + -1;
    } while (sVar3 != -1);
    if (((*DAT_00000412 & 0x80) != 0) && (extraout_D1b != 0)) {
      DAT_00000412[2] = extraout_D1b;
      pbVar2[1] = 1;
      _DAT_0010042a = 0x20;
      _DAT_0010042c = 0x20;
    }
  }
  return;
}



void FUN_00004b42(void)

{
  return;
}



undefined4 FUN_00004b44(void)

{
  undefined4 in_D0;
  short sVar1;
  short sVar2;
  undefined1 *puVar3;
  int unaff_A4;
  
  puVar3 = &DAT_000007a0;
  sVar2 = 7;
  sVar1 = *(short *)(unaff_A4 + 0x10);
  do {
    *(undefined1 *)(sVar1 + 0xf0000) = *puVar3;
    puVar3 = puVar3 + 2;
    sVar1 = sVar1 + 1;
    sVar2 = sVar2 + -1;
  } while (sVar2 != -1);
  *(short *)(unaff_A4 + 0x10) = sVar1;
  return in_D0;
}



void FUN_00004b76(void)

{
  return;
}



void FUN_00004bea(void)

{
  byte bVar1;
  short sVar2;
  int unaff_A4;
  byte *pbVar3;
  
  pbVar3 = (byte *)(unaff_A4 + 0x100);
  sVar2 = 7;
  bVar1 = 0xff;
  do {
    if (((*pbVar3 & 0xe0) == 0x80) && (pbVar3[4] <= bVar1)) {
      bVar1 = pbVar3[4];
    }
    pbVar3 = pbVar3 + 0x60;
    sVar2 = sVar2 + -1;
  } while (sVar2 != -1);
  return;
}



void FUN_00004c2a(void)

{
  short sVar1;
  char unaff_D7b;
  byte *unaff_A5;
  int unaff_A6;
  
  sVar1 = 0x1f;
  do {
    if (((*unaff_A5 & 0x80) != 0) && (unaff_A6 == *(int *)(unaff_A5 + 8))) {
      if (unaff_D7b != '\0') {
        *unaff_A5 = *unaff_A5 & 0x7f;
      }
      FUN_00004d54();
    }
    unaff_A5 = unaff_A5 + 0xc;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}



void FUN_00004c7c(void)

{
  short sVar1;
  byte *unaff_A5;
  int unaff_A6;
  
  sVar1 = 0x1f;
  do {
    if (((*unaff_A5 & 0x80) != 0) && (unaff_A6 == *(int *)(unaff_A5 + 8))) {
      FUN_00004d54();
    }
    unaff_A5 = unaff_A5 + 0xc;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}



undefined8 FUN_00004cc4(void)

{
  uint in_D0;
  uint in_D1;
  
  return CONCAT44((in_D1 & 0xffff) * (in_D0 >> 0x10) * 0x10000 + (in_D1 & 0xffff) * (in_D0 & 0xffff)
                  ,in_D1);
}



undefined8 FUN_00004cde(void)

{
  undefined uVar1;
  int iVar2;
  undefined4 in_D0;
  undefined4 in_D1;
  short sVar3;
  int unaff_A6;
  
  iVar2 = DAT_00000404;
  uVar1 = *(undefined *)(unaff_A6 + 3);
  sVar3 = (ushort)*(byte *)(unaff_A6 + 1) << 1;
  *(undefined *)(DAT_00000404 + 0x80 + (int)sVar3) = *(undefined *)(unaff_A6 + 2);
  *(undefined *)(iVar2 + 0x81 + (int)sVar3) = uVar1;
  return CONCAT44(in_D0,in_D1);
}



void FUN_00004d08(void)

{
  byte in_D0b;
  byte in_D1b;
  byte unaff_D2b;
  byte unaff_D3b;
  undefined4 unaff_D4;
  char cVar1;
  byte *unaff_A5;
  undefined4 unaff_A6;
  
  cVar1 = ' ';
  do {
    if ((*unaff_A5 & 0x80) == 0) {
      unaff_A5[1] = in_D0b;
      unaff_A5[2] = in_D1b;
      unaff_A5[3] = unaff_D2b;
      *unaff_A5 = unaff_D3b;
      *(undefined4 *)(unaff_A5 + 4) = unaff_D4;
      *(undefined4 *)(unaff_A5 + 8) = unaff_A6;
      *unaff_A5 = *unaff_A5 | 0x80;
      return;
    }
    unaff_A5 = unaff_A5 + 0xc;
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  return;
}



void FUN_00004d54(void)

{
  byte bVar1;
  int iVar2;
  byte in_D0b;
  byte in_D1b;
  byte unaff_D2b;
  char unaff_D3b;
  byte bVar3;
  byte *pbVar4;
  byte *unaff_A6;
  bool bVar5;
  
  pbVar4 = (byte *)(DAT_00000450 + 0x1840);
  iVar2 = DAT_00000450 + 0x1a00;
  if ((in_D0b & 0xf0) == 0x90) {
    bVar3 = unaff_A6[0x22];
    if ((*unaff_A6 & 0x10) != 0) {
      bVar3 = unaff_A6[0x24];
    }
    bVar5 = unaff_D2b < bVar3;
    unaff_D2b = unaff_D2b - bVar3;
    if (bVar5) {
      unaff_D2b = 0;
    }
  }
  bVar1 = unaff_A6[1];
  bVar3 = *pbVar4;
  *pbVar4 = *pbVar4 + 1;
  pbVar4 = (byte *)((uint)bVar3 * 4 + iVar2);
  *pbVar4 = in_D0b >> 4 & 7;
  pbVar4[1] = bVar1 << 5 | unaff_D3b << 4 | in_D0b & 0xf;
  pbVar4[2] = in_D1b;
  pbVar4[3] = unaff_D2b;
  return;
}



void FUN_00004dc4(void)

{
  short sVar1;
  short *in_A0;
  ushort *in_A1;
  
  sVar1 = *in_A0;
  if (sVar1 < 0) {
    sVar1 = -sVar1;
  }
  *in_A1 = (ushort)(*in_A1 + sVar1) >> 1;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00004de0(void)

{
  short sVar1;
  byte *in_A0;
  char *in_A1;
  
  if ((*in_A0 & 0x80) == 0) {
    *in_A1 = '\0';
  }
  else {
    _DAT_00100408 = (ushort)*in_A0 << 0xb;
    sVar1 = 0xe;
    do {
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
    if (*in_A1 != '\0') {
      *in_A1 = '\0';
    }
  }
  return;
}



void FUN_00004e44(void)

{
  undefined2 *puVar1;
  undefined2 in_D0w;
  undefined4 in_D1;
  undefined4 unaff_D2;
  undefined unaff_D3b;
  undefined4 unaff_D4;
  byte *unaff_A4;
  
  if ((*unaff_A4 & 1) != 0) {
    puVar1 = *(undefined2 **)(unaff_A4 + 0x10);
    *puVar1 = in_D0w;
    *(undefined4 *)(puVar1 + 2) = in_D1;
    *(undefined4 *)(puVar1 + 4) = unaff_D2;
    *(undefined *)(puVar1 + 6) = unaff_D3b;
    *(char *)(puVar1 + 7) = (char)unaff_D4;
    *(char *)((int)puVar1 + 0xd) = (char)((uint)unaff_D4 >> 0x10);
    *(int *)(unaff_A4 + 0x10) = *(int *)(unaff_A4 + 0x10) + 0x10;
  }
  return;
}



void FUN_00004e7e(void)

{
  int iVar1;
  int iVar2;
  undefined4 *in_A0;
  
  iVar2 = DAT_00000450;
  iVar1 = *(int *)(DAT_00000450 + 0x3814);
  *(int *)(DAT_00000450 + 0x3814) = *(int *)(DAT_00000450 + 0x3814) + 0x10;
  if (*(int *)(iVar2 + 0x3814) == 0x800) {
    *(undefined4 *)(iVar2 + 0x3814) = 0;
  }
  *(undefined4 *)(iVar1 + 0x800) = *in_A0;
  *(undefined4 *)(iVar1 + 0x804) = in_A0[1];
  *(undefined4 *)(iVar1 + 0x808) = in_A0[2];
  *(undefined4 *)(iVar1 + 0x80c) = in_A0[3];
  return;
}



ulonglong FUN_00004ec0(void)

{
  undefined4 *puVar1;
  byte bVar2;
  char cVar3;
  short in_D0w;
  int iVar4;
  short in_D1w;
  short sVar6;
  int iVar5;
  ushort uVar7;
  ushort uVar8;
  ushort *puVar9;
  byte *pbVar10;
  ushort *puVar11;
  bool bVar12;
  ulonglong uVar13;
  
  sVar6 = in_D1w << 5;
  puVar1 = (undefined4 *)(&DAT_00004f22 + sVar6);
  if ((short)(in_D0w * 2) != 0) {
                    // WARNING: Could not recover jumptable at 0x00005232. Too many branches
                    // WARNING: Treating indirect jump as call
    uVar13 = (*(code *)(&DAT_00005236 + *(short *)(&DAT_00005236 + (short)(in_D0w * 2))))();
    return uVar13;
  }
  iVar4 = 0;
  iVar5 = 0;
  puVar11 = (ushort *)*puVar1;
LAB_00004edc:
  puVar9 = (ushort *)((int)puVar11 + 1);
  bVar2 = *(byte *)puVar11;
  uVar7 = (ushort)bVar2;
  uVar8 = (ushort)bVar2;
  if (bVar2 < 0x80) {
    pbVar10 = (byte *)((int)puVar11 + 5);
    iVar5 = (uint)CONCAT11((char)((ushort)((uVar8 & 0x3f) << 3) >> 8),*(byte *)(puVar11 + 2)) +
            iVar5;
    uVar7 = (ushort)(bVar2 & 0x1f);
LAB_00004f08:
    if (*(short *)(&DAT_00004f3a + sVar6) == 0) {
      *puVar1 = pbVar10;
      return (ulonglong)CONCAT24(uVar7 << 8,iVar5);
    }
    cVar3 = (&DAT_00004f3a)[sVar6] + -1;
    (&DAT_00004f3a)[sVar6] = cVar3;
    if (cVar3 == '\0') {
      *puVar1 = *(undefined4 *)(&DAT_00004f2a + sVar6);
      return (ulonglong)CONCAT24(uVar7 << 8,iVar5);
    }
    *puVar1 = pbVar10;
LAB_0000503e:
    return CONCAT44(iVar4 + (uint)(ushort)(uVar7 << 8),iVar5);
  }
  switch(uVar8) {
  default:
    iVar4 = 0xff;
    goto LAB_0000503e;
  case 0x81:
    uVar7 = *puVar9;
    (&DAT_00004f3a)[sVar6] = *(byte *)((int)puVar11 + 3);
    *(ushort **)(&DAT_00004f2a + sVar6) = puVar11 + 2;
    puVar11 = (ushort *)(*(int *)(&DAT_00004f2e + sVar6) + (uint)uVar7);
    goto LAB_00004edc;
  case 0x82:
    puVar11 = puVar11 + 1;
    iVar5 = (uint)*(byte *)puVar9 + iVar5;
    if (*(int *)(&DAT_00004f26 + sVar6) == 0) {
      *(ushort **)(&DAT_00004f26 + sVar6) = puVar11;
    }
    else {
      puVar11 = *(ushort **)(&DAT_00004f26 + sVar6);
    }
    goto LAB_00004edc;
  case 0x83:
    iVar4 = 1;
    goto LAB_0000503e;
  case 0x88:
  case 0x89:
  case 0x8a:
  case 0x8b:
    puVar11 = puVar9;
    goto LAB_00004edc;
  case 0x8c:
  case 0x8d:
  case 0x8e:
  case 0x8f:
    goto switchD_0000505a_caseD_8c;
  case 0xa0:
  case 0xa1:
  case 0xa2:
  case 0xa3:
  case 0xa4:
  case 0xa5:
  case 0xa6:
  case 0xa7:
  case 0xa8:
  case 0xa9:
  case 0xaa:
  case 0xab:
  case 0xac:
  case 0xad:
  case 0xae:
  case 0xaf:
  case 0xb0:
  case 0xb1:
  case 0xb2:
  case 0xb3:
  case 0xb4:
  case 0xb5:
  case 0xb6:
  case 0xb7:
  case 0xb8:
  case 0xb9:
  case 0xba:
  case 0xbb:
  case 0xbc:
  case 0xbd:
  case 0xbe:
  case 0xbf:
    puVar11 = (ushort *)((int)puVar11 + 3);
    bVar12 = (*(byte *)puVar9 & 0x80) == 0;
    break;
  case 0xc0:
  case 0xc1:
  case 0xc2:
  case 0xc3:
  case 0xc4:
  case 0xc5:
  case 0xc6:
  case 199:
  case 200:
  case 0xc9:
  case 0xca:
  case 0xcb:
  case 0xcc:
  case 0xcd:
  case 0xce:
  case 0xcf:
  case 0xd0:
  case 0xd1:
  case 0xd2:
  case 0xd3:
  case 0xd4:
  case 0xd5:
  case 0xd6:
  case 0xd7:
  case 0xd8:
  case 0xd9:
  case 0xda:
  case 0xdb:
  case 0xdc:
  case 0xdd:
  case 0xde:
  case 0xdf:
    puVar11 = puVar11 + 1;
    bVar12 = (*(byte *)puVar9 & 0x80) == 0;
    break;
  case 0xe0:
  case 0xe1:
  case 0xe2:
  case 0xe3:
  case 0xe4:
  case 0xe5:
  case 0xe6:
  case 0xe7:
  case 0xe8:
  case 0xe9:
  case 0xea:
  case 0xeb:
  case 0xec:
  case 0xed:
  case 0xee:
  case 0xef:
    puVar11 = puVar11 + 1;
    bVar12 = (*(byte *)puVar9 & 0x80) == 0;
  }
  if (bVar12) {
    uVar7 = (ushort)(bVar2 & 0xf);
    pbVar10 = (byte *)((int)puVar11 + 1);
    iVar5 = (uint)*(byte *)puVar11 + iVar5;
  }
  else {
    uVar7 = bVar2 & 0xf | 0x10;
    pbVar10 = (byte *)((int)puVar11 + 1);
    iVar5 = (uint)*(byte *)puVar11 + iVar5;
  }
  goto LAB_00004f08;
switchD_0000505a_caseD_8c:
  iVar5 = (uint)*(ushort *)(&DAT_00005204 + (short)((uVar8 - 0x80) * 2)) + iVar5;
  puVar11 = puVar9;
  goto LAB_00004edc;
}


