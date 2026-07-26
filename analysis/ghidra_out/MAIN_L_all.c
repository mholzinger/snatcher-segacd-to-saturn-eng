typedef unsigned char   undefined;

typedef unsigned char    byte;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned short    ushort;
typedef unsigned short    wchar16;



void FUN_060b0240(void)

{
  int iVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  
  puVar2 = PTR_FUN_060b02cc;
  iVar1 = DAT_060b02c4;
  if ((*(char *)(DAT_060b02c4 + 0x17) != '\0') &&
     (iVar8 = 0, *(char *)(DAT_060b02c4 + DAT_060b02b8) == '\0')) {
    iVar9 = (int)DAT_060b02ba;
    puVar6 = DAT_060b02c8;
    puVar7 = DAT_060b02c0;
    do {
      uVar3 = (*(code *)puVar2)(*(undefined *)(iVar1 + DAT_060b02bc),iVar8);
      if ((uVar3 & 1) == 0) {
        iVar4 = (int)DAT_060b02be;
        do {
          uVar5 = *puVar6;
          puVar6 = puVar6 + 1;
          iVar4 = iVar4 + -1;
          *puVar7 = uVar5;
          puVar7 = puVar7 + 1;
        } while (iVar4 != 0);
      }
      else {
        puVar7 = (undefined4 *)((int)puVar7 + iVar9);
        puVar6 = (undefined4 *)((int)puVar6 + iVar9);
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < 8);
    *(undefined *)(iVar1 + 0x17) = 0;
  }
  return;
}



void FUN_060b02d0(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  short *psVar6;
  int iVar7;
  short *psVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  short local_24 [4];
  short local_1c [4];
  
  iVar9 = DAT_060b03e8;
  piVar4 = DAT_060b03e4;
  iVar2 = DAT_060b03e0;
  psVar6 = local_24;
  if (*(short *)(DAT_060b03e4 + 3) != 0) {
    iVar7 = *(int *)(DAT_060b03d6 + DAT_060b03e8);
    iVar5 = 0xc;
    if (iVar7 != 0) {
      *(int *)(iVar7 + 0x14) = *DAT_060b03e4;
      iVar3 = (int)DAT_060b03d8;
      *(int *)(iVar7 + 0x18) = piVar4[1];
      iVar7 = (int)DAT_060b03da;
      do {
        iVar10 = iVar9 + iVar3;
        iVar3 = iVar3 + 0x4c;
        *(int *)(iVar10 + 8) = *(int *)(iVar10 + 8) - *piVar4;
        iVar5 = iVar5 + 1;
        *(int *)(iVar10 + 0xc) = *(int *)(iVar10 + 0xc) - piVar4[1];
      } while (iVar5 <= iVar7);
      sVar1 = *(short *)(piVar4 + 3);
      if (sVar1 != -1) {
        *(short *)(piVar4 + 3) = sVar1 + -1;
      }
    }
  }
  iVar5 = 0xc;
  iVar3 = (int)DAT_060b03da;
  iVar7 = (int)DAT_060b03dc;
  do {
    iVar10 = iVar9 + DAT_060b03de + iVar7;
    psVar8 = (short *)(iVar10 + 0x38);
    if (*psVar8 != 0) {
      *(short *)(iVar10 + 0x10) = *(short *)(iVar10 + 0x10) + *(short *)(iVar10 + 0x34);
      *(short *)(iVar10 + 0x12) = *(short *)(iVar10 + 0x12) + *(short *)(iVar10 + 0x36);
      *(int *)(iVar10 + 8) = *(int *)(iVar10 + 8) + *(int *)(iVar10 + 0x2c);
      *(int *)(iVar10 + 0xc) = *(int *)(iVar10 + 0xc) + *(int *)(iVar10 + 0x30);
      if (*psVar8 != -1) {
        *psVar8 = *psVar8 + -1;
      }
    }
    iVar5 = iVar5 + 1;
    iVar7 = iVar7 + 0x4c;
  } while (iVar5 <= iVar3);
  iVar7 = 0;
  iVar5 = iVar9;
  do {
    iVar3 = *(int *)(iVar5 + DAT_060b03d6);
    if (iVar3 == 0) {
      *psVar6 = 0;
      psVar6[4] = 0;
    }
    else {
      *psVar6 = *(undefined2 *)(iVar3 + 6);
      piVar4 = (int *)(iVar3 + 0xc);
      psVar6[4] = *(undefined2 *)(iVar3 + 8);
      *(undefined2 *)(iVar3 + 6) = *(undefined2 *)piVar4;
      piVar11 = (int *)(iVar3 + 0x10);
      *(undefined2 *)(iVar3 + 8) = *(undefined2 *)piVar11;
      *piVar4 = *piVar4 + *(int *)(iVar3 + 0x14);
      *piVar11 = *piVar11 + *(int *)(iVar3 + 0x18);
    }
    psVar6 = psVar6 + 1;
    iVar7 = iVar7 + 1;
    iVar5 = iVar5 + 4;
  } while (iVar7 < 4);
  if ((*(short *)(DAT_060b0486 + iVar9) == 0) &&
     (iVar9 = *(int *)(iVar9 + DAT_060b0488), iVar9 != 0)) {
    *(undefined4 *)(iVar9 + 0x14) = 0;
    *(undefined4 *)(iVar9 + 0x18) = 0;
  }
  *(int *)(iVar2 + DAT_060b048a) = (int)local_24[0] << 0x10;
  *(int *)(iVar2 + DAT_060b048c) = (int)local_1c[0] << 0x10;
  *(int *)(iVar2 + DAT_060b048e) = (int)local_24[1] << 0x10;
  *(int *)(iVar2 + DAT_060b0490) = (int)local_1c[1] << 0x10;
  *(short *)(iVar2 + DAT_060b0492) = local_24[2];
  *(short *)(iVar2 + DAT_060b0494) = local_1c[2];
  *(short *)(iVar2 + DAT_060b0496) = local_24[3];
  *(short *)(iVar2 + DAT_060b0498) = local_1c[3];
  *(undefined *)(iVar2 + 7) = 1;
  return;
}



undefined4 FUN_060b0538(void)

{
  short sVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 in_r0;
  int iVar4;
  uint uVar5;
  int iVar6;
  short sVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  
  iVar2 = DAT_060b069c;
  iVar6 = DAT_060b0698;
  if (*(char *)(DAT_060b0698 + 10) == '\0') {
    *(undefined *)(DAT_060b0698 + DAT_060b0678) = 1;
    *(undefined *)(iVar6 + DAT_060b067a) = 1;
    *(undefined *)(iVar6 + DAT_060b067c) = 1;
    *(undefined *)(iVar6 + DAT_060b067e) = 1;
    puVar3 = PTR_FUN_060b06a0;
    (*(code *)PTR_FUN_060b06a0)(0);
    *(undefined *)(iVar6 + DAT_060b0680) = 1;
    *(undefined *)(iVar6 + DAT_060b0682) = 1;
    *(undefined *)(iVar6 + DAT_060b0684) = 1;
    *(undefined *)(iVar6 + DAT_060b0686) = 1;
    (*(code *)puVar3)(1);
    (*(code *)PTR_FUN_060b06ac)(DAT_060b06a8,0,DAT_060b06a4);
    iVar6 = 0;
    iVar10 = 0;
    do {
      iVar8 = 0;
      do {
        uVar9 = 0;
        sVar7 = 0;
        do {
          uVar5 = uVar9 & 3;
          iVar4 = (int)uVar9 >> 2;
          uVar9 = uVar9 + 1;
          *(ushort *)(uVar5 * 0x200 + iVar4 * 0x20 + DAT_060b06a8 + (iVar8 + iVar10) * 2) =
               (DAT_060b0688 + sVar7 + ((ushort)iVar6 & 7) * 0xf + (short)iVar8) * 2;
          sVar7 = sVar7 + 0x78;
        } while ((int)uVar9 < 8);
        iVar8 = iVar8 + 1;
      } while (iVar8 < 0xf);
      iVar6 = iVar6 + 1;
      iVar10 = iVar10 + 0x20;
    } while (iVar6 < 8);
    iVar6 = 0;
    sVar7 = 0;
    iVar10 = 0;
    do {
      iVar8 = 0;
      do {
        iVar4 = (iVar8 + iVar10) * 2;
        sVar1 = (sVar7 + (short)iVar8) * 2;
        *(short *)(iVar4 + DAT_060b06b0) = DAT_060b068a + sVar1;
        *(short *)(iVar4 + DAT_060b06b4) = DAT_060b068c + sVar1;
        iVar8 = iVar8 + 1;
        *(short *)(iVar4 + DAT_060b06b8) = sVar1 + DAT_060b0688;
      } while (iVar8 < 0x1e);
      sVar7 = sVar7 + 0x1e;
      iVar6 = iVar6 + 1;
      iVar10 = iVar10 + 0x20;
    } while (iVar6 < 0x10);
    (*(code *)PTR_FUN_060b06bc)();
    (*(code *)PTR_FUN_060b06c0)();
    *(undefined4 *)(iVar2 + DAT_060b068e) = DAT_060b06c4;
    *(undefined2 *)(iVar2 + DAT_060b0690) = 0;
    (*(code *)PTR_FUN_060b06c8)(0x20,0x10,(int)DAT_060b0694,(int)DAT_060b0692);
    in_r0 = (*(code *)PTR_FUN_060b06cc)(1);
  }
  return in_r0;
}



int FUN_060b06d0(int param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = PTR_FUN_060b0728;
  iVar2 = (*(code *)PTR_FUN_060b0728)(0,0,(int)DAT_060b0722);
  if (iVar2 != 0) {
    param_1 = param_1 + -1;
  }
  iVar2 = (*(code *)puVar1)(0,0,(int)DAT_060b0724);
  if (iVar2 != 0) {
    param_1 = param_1 + 1;
  }
  if (param_1 < 0) {
    param_1 = param_2 + -1;
  }
  if (param_2 + -1 < param_1) {
    param_1 = 0;
  }
  return param_1;
}



int FUN_060b0748(void)

{
  byte bVar1;
  char cVar2;
  undefined2 *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  short sVar10;
  int iVar9;
  ushort uVar11;
  short sVar14;
  undefined2 *puVar12;
  code *pcVar13;
  int iVar15;
  ushort *puVar16;
  short *psVar17;
  int iVar18;
  byte *pbVar19;
  short local_38 [4];
  undefined2 local_30;
  undefined2 local_2e;
  undefined2 local_2c;
  undefined2 local_2a;
  short local_28;
  undefined2 local_26;
  undefined2 local_24;
  
  puVar5 = PTR_FUN_060b0e88;
  puVar4 = PTR_FUN_060b0d04;
  puVar3 = DAT_060b0944;
  iVar15 = DAT_060b0940;
  pbVar19 = *(byte **)PTR_DAT_060b0938;
  local_38[0] = *(short *)PTR_DAT_060b093c;
  local_38[1] = *(short *)(PTR_DAT_060b093c + 2);
  local_38[2] = *(short *)(PTR_DAT_060b093c + 4);
  local_38[3] = *(short *)(PTR_DAT_060b093c + 6);
  local_30 = *(undefined2 *)(PTR_DAT_060b093c + 8);
  local_2e = *(undefined2 *)(PTR_DAT_060b093c + 10);
  local_2c = *(undefined2 *)(PTR_DAT_060b093c + 0xc);
  local_2a = *(undefined2 *)(PTR_DAT_060b093c + 0xe);
  local_28 = *(short *)(PTR_DAT_060b093c + 0x10);
  iVar7 = (int)local_28;
  local_26 = *(undefined2 *)(PTR_DAT_060b093c + 0x12);
  local_24 = *(undefined2 *)(PTR_DAT_060b093c + 0x14);
  switch(*(undefined *)(DAT_060b0940 + 10)) {
  case 0:
    puVar12 = (undefined2 *)(PTR_DAT_060b0948 + (uint)pbVar19[1] * 6);
    *DAT_060b0944 = *puVar12;
    puVar3[1] = puVar12[1];
    puVar4 = PTR_FUN_060b094c;
    puVar3[2] = puVar12[2];
    (*(code *)puVar4)();
    (*(code *)PTR_FUN_060b0950)(1,1,0,0);
    (*(code *)PTR_FUN_060b0954)(0x20,0x10);
    (*(code *)PTR_FUN_060b0958)(0x20,0x10);
    (*(code *)PTR_FUN_060b095c)(0,(int)DAT_060b0924);
    (*(code *)PTR_FUN_060b0960)(1);
    (*(code *)PTR_FUN_060b0964)();
    iVar15 = (*(code *)PTR_FUN_060b0968)();
    return iVar15;
  case 1:
    *(undefined **)(DAT_060b0926 + DAT_060b0940) = PTR_DAT_060b096c;
    *(undefined2 *)(DAT_060b0928 + iVar15) = 0;
    *(undefined2 *)(DAT_060b092a + iVar15) = 1;
    puVar4 = PTR_FUN_060b0970;
    iVar7 = (int)DAT_060b092c;
    cVar2 = *(char *)(iVar7 + iVar15);
    while (cVar2 == '\0') {
      (*(code *)puVar4)();
      cVar2 = *(char *)(iVar7 + iVar15);
    }
    *DAT_060b0974 = 0;
    (*(code *)PTR_FUN_060b0968)();
  case 2:
    iVar7 = *DAT_060b0974;
    *DAT_060b0974 = iVar7 + 1;
    puVar4 = PTR_FUN_060b0980;
    if ((int)DAT_060b092e < iVar7 + 1) {
      *(undefined *)(DAT_060b0930 + iVar15) = 1;
      puVar4 = PTR_FUN_060b0970;
      iVar7 = (int)DAT_060b0932;
      cVar2 = *(char *)(iVar7 + iVar15);
      while (cVar2 == '\0') {
        (*(code *)puVar4)();
        cVar2 = *(char *)(iVar7 + iVar15);
      }
      iVar15 = (*(code *)PTR_FUN_060b0978)();
      return iVar15;
    }
    iVar7 = (*(code *)PTR_FUN_060b0980)(0,0,DAT_060b097c);
    puVar5 = PTR_DAT_060b0984;
    if (iVar7 != 0) {
      iVar7 = (*(code *)puVar4)(0,0,(int)local_38[*(short *)PTR_DAT_060b0984]);
      if (iVar7 == 0) {
        *(undefined2 *)puVar5 = 0;
      }
      else {
        *(short *)puVar5 = *(short *)puVar5 + 1;
        if (*(short *)puVar5 == 10) {
          sVar14 = *(short *)(pbVar19 + 4) + 1;
          *(short *)(pbVar19 + 4) = sVar14;
          sVar10 = DAT_060b0934;
          if ((sVar14 == 1) || (sVar10 = DAT_060b0936, sVar14 == 2)) {
            (*(code *)PTR_FUN_060b0988)((int)sVar10);
          }
          else {
            (*(code *)PTR_FUN_060b0988)((int)DAT_060b0934);
            pbVar19[4] = 0;
            pbVar19[5] = 0;
          }
          *(undefined2 *)PTR_DAT_060b0984 = 0;
        }
      }
    }
    iVar7 = (*(code *)PTR_FUN_060b0abc)(0,0,(int)DAT_060b0a9e);
    if (iVar7 == 0) {
      return 0;
    }
    *(undefined *)(DAT_060b0aa0 + iVar15) = 0;
    *(undefined *)(DAT_060b0aa2 + iVar15) = 1;
    puVar4 = PTR_FUN_060b0ac0;
    iVar7 = (int)DAT_060b0aa4;
    cVar2 = *(char *)(iVar7 + iVar15);
    while (cVar2 == '\0') {
      (*(code *)puVar4)();
      cVar2 = *(char *)(iVar7 + iVar15);
    }
    *(undefined *)(DAT_060b0aa4 + iVar15) = 1;
    *(undefined2 *)(DAT_060b0aa6 + iVar15) = 0;
    uVar8 = (*(code *)PTR_FUN_060b0ac8)(0x3c,PTR_DAT_060b0ac4);
    uVar6 = DAT_060b0ad0;
    (*(code *)PTR_FUN_060b0ad4)
              (DAT_060b0ad0,1,*(int *)PTR_DAT_060b0acc - *(int *)(PTR_DAT_060b0acc + -4),uVar8);
    (*(code *)PTR_FUN_060b0ad8)(uVar8);
    iVar7 = (int)DAT_060b0aa8;
    *(undefined2 *)(iVar7 + iVar15) = 0;
    *(undefined4 *)(DAT_060b0aaa + iVar15) = uVar6;
    *(undefined2 *)(DAT_060b0aac + iVar15) = 0;
    *(undefined2 *)(iVar7 + iVar15) = 1;
    *(undefined *)(DAT_060b0aae + iVar15) = 1;
    (*(code *)PTR_FUN_060b0adc)();
  case 3:
    sVar10 = DAT_060b0ab2;
    if (pbVar19[2] == 0) {
      sVar10 = DAT_060b0ab0;
    }
    (*(code *)PTR_FUN_060b0ae0)((int)sVar10);
    puVar4 = PTR_FUN_060b0ac0;
    iVar7 = (int)DAT_060b0aa0;
    cVar2 = *(char *)(iVar7 + iVar15);
    while (cVar2 == '\0') {
      (*(code *)puVar4)();
      cVar2 = *(char *)(iVar7 + iVar15);
    }
    psVar17 = (short *)(DAT_060b0aa6 + iVar15);
    *psVar17 = 0;
    puVar4 = PTR_FUN_060b0abc;
    iVar18 = (int)DAT_060b0a9e;
    iVar7 = (int)DAT_060b0ab4;
    while (iVar9 = (*(code *)puVar4)(0,0,iVar18), puVar5 = PTR_FUN_060b0bc0, iVar9 == 0) {
      sVar10 = (*(code *)PTR_FUN_060b0ae4)((int)*psVar17);
      *psVar17 = sVar10;
      *(undefined *)(iVar7 + iVar15) = 0;
      *(undefined *)(DAT_060b0ab6 + iVar15) = 0;
      *(undefined *)(DAT_060b0ab8 + iVar15) = 0;
      *(undefined *)(iVar7 + iVar15 + *psVar17) = 1;
      (*(code *)PTR_FUN_060b0ac0)();
    }
    if (*(short *)(iVar15 + DAT_060b0bb0) < 2) {
      (*(code *)PTR_FUN_060b0bc0)((int)DAT_060b0bb2,3);
      (*(code *)puVar5)((int)DAT_060b0bb4);
    }
    *(undefined *)(DAT_060b0bb6 + iVar15) = 1;
    puVar4 = PTR_FUN_060b0bc4;
    iVar7 = (int)DAT_060b0bb8;
    cVar2 = *(char *)(iVar7 + iVar15);
    pcVar13 = (code *)PTR_FUN_060b0bc4;
    while (PTR_FUN_060b0bc4 = pcVar13, cVar2 == '\0') {
      (*(code *)puVar4)();
      pcVar13 = (code *)PTR_FUN_060b0bc4;
      cVar2 = *(char *)(iVar7 + iVar15);
    }
    if (*(short *)(iVar15 + DAT_060b0bb0) < 2) {
      iVar7 = 0;
      do {
        iVar7 = iVar7 + 1;
        (*pcVar13)();
      } while (iVar7 < 0x78);
    }
    (*(code *)PTR_FUN_060b0bc8)(0xe);
    iVar7 = (int)DAT_060b0bb0;
    *(undefined *)(DAT_060b0bba + iVar15) = *(undefined *)(iVar15 + iVar7 + 1);
    iVar7 = (int)*(short *)(iVar15 + iVar7);
    if (iVar7 == 1) {
      *(undefined2 *)(DAT_060b0bbc + iVar15) = 0;
      sVar10 = 4;
      pcVar13 = (code *)PTR_FUN_060b0bcc;
    }
    else if (iVar7 < 2) {
      if (iVar7 != 0) {
        return iVar7;
      }
      sVar10 = 4;
      pcVar13 = (code *)PTR_FUN_060b0bcc;
    }
    else {
      if (iVar7 != 2) {
        return iVar7;
      }
      *(undefined *)(iVar15 + DAT_060b0bbe) = 0;
      sVar10 = 5;
      pcVar13 = (code *)PTR_FUN_060b0bcc;
    }
    break;
  case 4:
    iVar15 = (int)*(short *)(DAT_060b0bb0 + DAT_060b0940);
    pcVar13 = (code *)PTR_FUN_060b0d00;
    if (iVar15 == 1) {
      sVar10 = 4;
    }
    else if (iVar15 < 2) {
      if (iVar15 != 0) {
        return iVar15;
      }
      sVar10 = 2;
    }
    else {
      if (iVar15 != 2) {
        return iVar15;
      }
      sVar10 = 4;
    }
    break;
  case 5:
    *(undefined2 *)(DAT_060b0ce4 + DAT_060b0940) = 0;
    puVar4 = PTR_FUN_060b0d04;
    iVar7 = (int)DAT_060b0ce6;
    cVar2 = *(char *)(iVar7 + iVar15);
    pcVar13 = (code *)PTR_FUN_060b0d08;
    while (PTR_FUN_060b0d08 = pcVar13, cVar2 == '\0') {
      (*(code *)puVar4)();
      pcVar13 = (code *)PTR_FUN_060b0d08;
      cVar2 = *(char *)(iVar7 + iVar15);
    }
    iVar18 = (int)DAT_060b0ce8;
    psVar17 = (short *)(iVar15 + DAT_060b0ce4);
    iVar7 = (int)DAT_060b0cea;
    while (iVar9 = (*pcVar13)(0,0,iVar18), iVar9 == 0) {
      sVar10 = (*(code *)PTR_FUN_060b0d0c)((int)*psVar17,4);
      *psVar17 = sVar10;
      *(undefined *)(iVar7 + iVar15) = 0;
      *(undefined *)(DAT_060b0cec + iVar15) = 0;
      *(undefined *)(DAT_060b0cee + iVar15) = 0;
      *(undefined *)(DAT_060b0cf0 + iVar15) = 0;
      *(undefined *)(iVar7 + iVar15 + *psVar17) = 1;
      (*(code *)PTR_FUN_060b0d04)();
    }
    *(undefined *)(iVar15 + DAT_060b0cf2) = 1;
    sVar10 = *(short *)(iVar15 + DAT_060b0ce4) + 6;
    pcVar13 = (code *)PTR_FUN_060b0d10;
    break;
  case 6:
    iVar7 = (int)DAT_060b0cf2;
    cVar2 = *(char *)(iVar7 + DAT_060b0940);
    while (cVar2 != '\0') {
      (*(code *)puVar4)();
      cVar2 = *(char *)(iVar7 + iVar15);
    }
    puVar16 = (ushort *)(iVar15 + DAT_060b0ce4);
    iVar18 = (int)DAT_060b0ce8;
    iVar7 = (int)DAT_060b0cf4;
    *puVar16 = (ushort)*pbVar19;
    while (iVar9 = (*(code *)PTR_FUN_060b0d08)(0,0,iVar18), iVar9 == 0) {
      uVar11 = (*(code *)PTR_FUN_060b0d0c)((int)(short)*puVar16,3);
      *puVar16 = uVar11;
      *(undefined *)(iVar7 + iVar15) = 0;
      *(undefined *)(DAT_060b0cf6 + iVar15) = 0;
      *(undefined *)(DAT_060b0cf8 + iVar15) = 0;
      *(undefined *)(iVar7 + iVar15 + (short)*puVar16) = 1;
      (*(code *)PTR_FUN_060b0d04)();
    }
    *pbVar19 = *(byte *)(iVar15 + DAT_060b0cfa);
    *(undefined *)(iVar15 + DAT_060b0cfc) = 1;
    *(undefined *)(iVar15 + DAT_060b0ce6) = 0;
    sVar10 = 5;
    pcVar13 = (code *)PTR_FUN_060b0d10;
    break;
  case 7:
    iVar7 = (int)DAT_060b0e6c;
    cVar2 = *(char *)(iVar7 + DAT_060b0940);
    while (cVar2 != '\0') {
      (*(code *)puVar5)();
      cVar2 = *(char *)(iVar7 + iVar15);
    }
    puVar16 = (ushort *)(iVar15 + DAT_060b0e6e);
    iVar18 = (int)DAT_060b0e70;
    iVar7 = (int)DAT_060b0e72;
    *puVar16 = (ushort)pbVar19[1];
    while (iVar9 = (*(code *)PTR_FUN_060b0e8c)(0,0,iVar18), iVar9 == 0) {
      uVar11 = (*(code *)PTR_FUN_060b0e90)((int)(short)*puVar16,4);
      *puVar16 = uVar11;
      *(undefined *)(iVar7 + iVar15) = 0;
      *(undefined *)(DAT_060b0e74 + iVar15) = 0;
      *(undefined *)(DAT_060b0e76 + iVar15) = 0;
      *(undefined *)(DAT_060b0e78 + iVar15) = 0;
      *(undefined *)(iVar7 + iVar15 + (short)*puVar16) = 1;
      (*(code *)PTR_FUN_060b0e88)();
    }
    *(undefined *)(DAT_060b0e7a + iVar15) = 1;
    *(undefined *)(DAT_060b0e7c + iVar15) = 0;
    puVar3 = DAT_060b0e94;
    bVar1 = *(byte *)(DAT_060b0e7e + iVar15);
    pbVar19[1] = bVar1;
    puVar12 = (undefined2 *)(PTR_DAT_060b0e98 + (uint)bVar1 * 6);
    *puVar3 = *puVar12;
    puVar3[1] = puVar12[1];
    puVar3[2] = puVar12[2];
    sVar10 = 5;
    pcVar13 = (code *)PTR_FUN_060b0e9c;
    break;
  case 8:
    iVar7 = (int)DAT_060b0e6c;
    cVar2 = *(char *)(iVar7 + DAT_060b0940);
    while (cVar2 != '\0') {
      (*(code *)puVar5)();
      cVar2 = *(char *)(iVar7 + iVar15);
    }
    puVar16 = (ushort *)(iVar15 + DAT_060b0e6e);
    iVar18 = (int)DAT_060b0e70;
    iVar7 = (int)DAT_060b0e80;
    *puVar16 = (ushort)pbVar19[2];
    while (iVar9 = (*(code *)PTR_FUN_060b0e8c)(0,0,iVar18), iVar9 == 0) {
      uVar11 = (*(code *)PTR_FUN_060b0e90)((int)(short)*puVar16,2);
      *puVar16 = uVar11;
      *(undefined *)(iVar7 + iVar15) = 0;
      *(undefined *)(DAT_060b0e82 + iVar15) = 0;
      *(undefined *)(iVar7 + iVar15 + (short)*puVar16) = 1;
      (*(code *)PTR_FUN_060b0e88)();
    }
    *(undefined *)(iVar15 + DAT_060b0e84) = 1;
    *(undefined *)(iVar15 + DAT_060b0e7c) = 0;
    pbVar19[2] = *(byte *)(iVar15 + DAT_060b0e7e);
    sVar10 = 5;
    pcVar13 = (code *)PTR_FUN_060b0e9c;
    break;
  case 9:
    sVar10 = 3;
    pcVar13 = (code *)PTR_FUN_060b0e9c;
    break;
  default:
    goto switchD_060b07c2_caseD_a;
  }
  iVar7 = (*pcVar13)(sVar10);
switchD_060b07c2_caseD_a:
  return iVar7;
}



void FUN_060b0ea0(undefined param_1)

{
  int iVar1;
  
  iVar1 = DAT_060b0eb8;
  *(undefined *)(DAT_060b0eb8 + 0x10) = param_1;
  *(undefined *)(iVar1 + 0x11) = 0;
  return;
}



void FUN_060b0efc(undefined param_1)

{
  int iVar1;
  
  iVar1 = DAT_060b0f20;
  *(undefined *)(DAT_060b0f20 + 0xe) = param_1;
  *(undefined *)(iVar1 + 0xf) = 0;
  (*(code *)PTR_FUN_060b0f24)(0);
  return;
}



void FUN_060b0f28(void)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)(DAT_060b0f50 + 0xf);
  *(char *)(DAT_060b0f50 + 0xe) = *(char *)(DAT_060b0f50 + 0xe) + '\x01';
  *puVar1 = 0;
  (*(code *)PTR_FUN_060b0f54)(0);
  return;
}



void FUN_060b0f88(undefined param_1)

{
  int iVar1;
  
  iVar1 = DAT_060b0fac;
  *(undefined *)(DAT_060b0fac + 0xc) = param_1;
  *(undefined *)(iVar1 + 0xd) = 0;
  (*(code *)PTR_FUN_060b0fb0)(0);
  return;
}



void FUN_060b0fb4(void)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)(DAT_060b0fdc + 0xd);
  *(char *)(DAT_060b0fdc + 0xc) = *(char *)(DAT_060b0fdc + 0xc) + '\x01';
  *puVar1 = 0;
  (*(code *)PTR_FUN_060b0fe0)(0);
  return;
}



void FUN_060b1014(undefined param_1)

{
  int iVar1;
  
  iVar1 = DAT_060b1038;
  *(undefined *)(DAT_060b1038 + 10) = param_1;
  *(undefined *)(iVar1 + 0xb) = 0;
  (*(code *)PTR_FUN_060b103c)(0);
  return;
}



void FUN_060b1040(void)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)(DAT_060b1068 + 0xb);
  *(char *)(DAT_060b1068 + 10) = *(char *)(DAT_060b1068 + 10) + '\x01';
  *puVar1 = 0;
  (*(code *)PTR_FUN_060b106c)(0);
  return;
}



void FUN_060b10a0(undefined param_1)

{
  int iVar1;
  
  iVar1 = DAT_060b10c4;
  *(undefined *)(DAT_060b10c4 + 8) = param_1;
  *(undefined *)(iVar1 + 9) = 0;
  (*(code *)PTR_FUN_060b10c8)(0);
  return;
}



void FUN_060b10cc(void)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)(DAT_060b10f4 + 9);
  *(char *)(DAT_060b10f4 + 8) = *(char *)(DAT_060b10f4 + 8) + '\x01';
  *puVar1 = 0;
  (*(code *)PTR_FUN_060b10f8)(0);
  return;
}



void FUN_060b1220(void)

{
  undefined2 uVar1;
  int iVar2;
  undefined *puVar3;
  
  iVar2 = DAT_060b1348;
  *(ushort *)(DAT_060b1348 + 0x18) = *(ushort *)(DAT_060b1348 + 0x18) & DAT_060b1334 | 0x10;
  *(undefined2 *)(iVar2 + 0x1a) = 0;
  puVar3 = PTR_FUN_060b1350;
  uVar1 = DAT_060b1338;
  *(ushort *)(iVar2 + 0x1e) = *DAT_060b134c & DAT_060b1336;
  *(undefined2 *)(iVar2 + 0x26) = uVar1;
  (*(code *)puVar3)(0);
  *(undefined4 *)(iVar2 + DAT_060b133a) = 0;
  *(undefined *)(iVar2 + 4) = 1;
  (*(code *)PTR_FUN_060b1354)(0);
  *(undefined2 *)(iVar2 + 0x52) = 0;
  *(undefined2 *)(iVar2 + 0x54) = 0x12;
  puVar3 = PTR_FUN_060b1358;
  (*(code *)PTR_FUN_060b1358)(0,0,2,4,6);
  (*(code *)puVar3)(1,0,1,1,1);
  (*(code *)puVar3)(2,0,0,0,0);
  uVar1 = DAT_060b133c;
  *(undefined2 *)(iVar2 + 0x48) = DAT_060b133c;
  *(undefined2 *)(iVar2 + 0x4a) = uVar1;
  *(undefined2 *)(iVar2 + 0x4c) = DAT_060b133e;
  *(undefined2 *)(iVar2 + 0x4e) = 0;
  *(undefined2 *)(iVar2 + DAT_060b1340) = 0;
  (*(code *)PTR_FUN_060b135c)(1,7,0,0,0);
  *(undefined2 *)(iVar2 + DAT_060b1342) = 0x6f;
  *(undefined2 *)(iVar2 + DAT_060b1344) = 0;
  (*(code *)PTR_FUN_060b1360)(0);
  *(undefined *)(iVar2 + 9) = 1;
  *(undefined2 *)(iVar2 + DAT_060b1346) = 0;
  *(undefined *)(iVar2 + 6) = 1;
  (*(code *)PTR_FUN_060b1368)(DAT_060b1364);
  (*(code *)PTR_FUN_060b136c)();
  (*(code *)PTR_FUN_060b1370)();
  (*(code *)PTR_FUN_060b1374)();
  return;
}



void FUN_060b1378(void)

{
  undefined4 uVar1;
  
  *DAT_060b13bc = 0;
  *DAT_060b13c0 = 0;
  *DAT_060b13c4 = 0;
  *DAT_060b13c8 = 0;
  *DAT_060b13cc = 0;
  *DAT_060b13d0 = 0;
  *DAT_060b13d4 = 0;
  *DAT_060b13d8 = 0;
  uVar1 = DAT_060b13e0;
  *DAT_060b13dc = DAT_060b13e0;
  *DAT_060b13e4 = uVar1;
  *DAT_060b13e8 = uVar1;
  *DAT_060b13ec = uVar1;
  *DAT_060b13f0 = 1;
  return;
}



void FUN_060b13f4(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  puVar1 = DAT_060b1484;
  *DAT_060b1488 = DAT_060b1470;
  (*(code *)PTR_FUN_060b148c)();
  *(undefined2 *)(puVar1 + 10) = 8;
  *(undefined2 *)(puVar1 + 0xc) = 3;
  *(undefined2 *)(puVar1 + 0xe) = 2;
  *(undefined2 *)(puVar1 + 0x10) = 0;
  *(undefined2 *)(puVar1 + 0x12) = 0;
  *(undefined2 *)(puVar1 + 0x14) = DAT_060b1472;
  *puVar1 = 1;
  *(undefined2 *)(puVar1 + DAT_060b1474) = DAT_060b1476;
  *(undefined4 *)(puVar1 + DAT_060b1478) = DAT_060b1490;
  *(undefined4 *)(puVar1 + DAT_060b147a) = DAT_060b1494;
  uVar2 = DAT_060b1498;
  *(undefined4 *)(puVar1 + DAT_060b147c) = DAT_060b1498;
  *(undefined4 *)(puVar1 + DAT_060b147e) = uVar2;
  *(undefined2 *)(puVar1 + DAT_060b1480) = 0;
  puVar1[5] = 1;
  *DAT_060b149c = 0;
  return;
}



void FUN_060b14a0(void)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  
  uVar2 = DAT_060b14d2;
  uVar1 = *DAT_060b14d4;
  while ((uVar1 & 2) == 0) {
    uVar1 = *DAT_060b14d4;
  }
  iVar3 = (int)DAT_060b14d0;
  puVar4 = DAT_060b14d8 + 4;
  puVar5 = DAT_060b14d8;
  do {
    *puVar5 = uVar2;
    *puVar4 = 0;
    puVar4 = puVar4 + 0x10;
    iVar3 = iVar3 + -1;
    puVar5 = puVar5 + 0x10;
  } while (iVar3 != 0);
  return;
}



void FUN_060b14dc(void)

{
  undefined *puVar1;
  
  puVar1 = *(undefined **)PTR_DAT_060b150c;
  (*(code *)PTR_FUN_060b1510)(puVar1,0,4);
  *puVar1 = 1;
  puVar1[1] = 0;
  puVar1[2] = 0;
  return;
}



void FUN_060b162c(int param_1)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)(param_1 * 2 + DAT_060b1648);
  *puVar1 = *DAT_060b164c;
  *puVar1 = *DAT_060b1650;
  return;
}



void FUN_060b1788(void)

{
  undefined4 *puVar1;
  undefined *puVar2;
  
  (*(code *)PTR_FUN_060b17dc)();
  (*(code *)PTR_FUN_060b17e0)();
  puVar1 = DAT_060b17e4;
  (*(code *)*DAT_060b17e4)(DAT_060b17e8);
  puVar2 = PTR_FUN_060b17ec;
  (*(code *)PTR_FUN_060b17ec)(0x40,0);
  (*(code *)puVar2)(0x41,0);
  (*(code *)puVar2)(0x43,0);
  (*(code *)puVar2)(0x42,0);
  (*(code *)*puVar1)(0);
  return;
}



void FUN_060b17f0(void)

{
  ushort uVar1;
  
  uVar1 = *DAT_060b1808;
  while ((uVar1 & 2) == 0) {
    uVar1 = *DAT_060b1808;
  }
  return;
}



void FUN_060b180c(void)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
  iVar1 = DAT_060b1a24;
  pcVar3 = (char *)(DAT_060b1a24 + 4);
  if (*pcVar3 != '\0') {
    iVar2 = (int)DAT_060b19ee;
    *DAT_060b1a28 = *(undefined2 *)(DAT_060b1a24 + 0x18);
    *DAT_060b1a2c = *(undefined2 *)(iVar1 + 0x1a);
    *DAT_060b1a30 = *(undefined2 *)(iVar1 + 0x1e);
    *DAT_060b1a34 = *(undefined2 *)(iVar1 + 0x26);
    *DAT_060b1a38 = *(undefined4 *)(iVar1 + 0x28);
    *DAT_060b1a3c = *(undefined4 *)(iVar1 + 0x2c);
    *DAT_060b1a40 = *(undefined4 *)(iVar1 + 0x30);
    *DAT_060b1a44 = *(undefined4 *)(iVar1 + 0x34);
    *DAT_060b1a48 = *(undefined4 *)(iVar1 + iVar2);
    *pcVar3 = '\0';
  }
  if (*(char *)(iVar1 + 5) != '\0') {
    *DAT_060b1a4c = *(undefined2 *)(iVar1 + DAT_060b19f0);
    *DAT_060b1a50 = *(undefined4 *)(iVar1 + DAT_060b19f2);
    *DAT_060b1a54 = *(undefined4 *)(iVar1 + DAT_060b19f4);
    *DAT_060b1a58 = *(undefined4 *)(iVar1 + DAT_060b19f6);
    *DAT_060b1a5c = *(undefined4 *)(iVar1 + DAT_060b19f8);
    *DAT_060b1a60 = *(undefined2 *)(iVar1 + DAT_060b19fa);
    *(char *)(iVar1 + 5) = '\0';
  }
  if (*(char *)(iVar1 + 6) != '\0') {
    iVar2 = (int)DAT_060b19fc;
    *DAT_060b1a64 = *(undefined2 *)(iVar1 + 0x38);
    *DAT_060b1a68 = *(undefined4 *)(iVar1 + iVar2);
    iVar2 = (int)DAT_060b19fe;
    *DAT_060b1a6c = *(undefined4 *)(iVar1 + 0x40);
    *DAT_060b1a70 = *(undefined4 *)(iVar1 + 0x58);
    *DAT_060b1a74 = *(undefined4 *)(iVar1 + 0x5c);
    *DAT_060b1a78 = *(undefined4 *)(iVar1 + 0x60);
    *DAT_060b1a7c = *(undefined4 *)(iVar1 + 100);
    *DAT_060b1a80 = *(undefined2 *)(iVar1 + iVar2);
    *DAT_060b1a84 = *(undefined4 *)(iVar1 + DAT_060b1a00);
    *DAT_060b1a88 = *(undefined2 *)(iVar1 + DAT_060b1a02);
    *DAT_060b1a8c = *(undefined2 *)(iVar1 + DAT_060b1a04);
    iVar2 = (int)DAT_060b1a06;
    *DAT_060b1a90 = *(undefined2 *)(iVar1 + 0x48);
    *DAT_060b1a94 = *(undefined2 *)(iVar1 + 0x4a);
    *DAT_060b1a98 = *(undefined2 *)(iVar1 + 0x4c);
    *DAT_060b1a9c = *(undefined2 *)(iVar1 + 0x4e);
    *DAT_060b1aa0 = *(undefined4 *)(iVar1 + iVar2);
    *DAT_060b1aa4 = *(undefined2 *)(iVar1 + DAT_060b1a08);
    iVar2 = (int)DAT_060b1a0a;
    *DAT_060b1aa8 = *(undefined2 *)(iVar1 + 0x52);
    *DAT_060b1aac = *(undefined2 *)(iVar1 + 0x54);
    *DAT_060b1ab0 = *(undefined2 *)(iVar1 + iVar2);
    *(char *)(iVar1 + 6) = '\0';
  }
  if (*(char *)(iVar1 + 7) != '\0') {
    *DAT_060b1ab4 = *(undefined4 *)(iVar1 + DAT_060b1a0c);
    *DAT_060b1ab8 = *(undefined4 *)(iVar1 + DAT_060b1a0e);
    *DAT_060b1abc = *(undefined4 *)(iVar1 + DAT_060b1a10);
    *DAT_060b1ac0 = *(undefined4 *)(iVar1 + DAT_060b1a12);
    *DAT_060b1ac4 = *(undefined2 *)(iVar1 + DAT_060b1a14);
    *DAT_060b1ac8 = *(undefined2 *)(iVar1 + DAT_060b1a16);
    *DAT_060b1acc = *(undefined2 *)(iVar1 + DAT_060b1a18);
    *DAT_060b1ad0 = *(undefined2 *)(iVar1 + DAT_060b1a1a);
    *DAT_060b1ad4 = *(undefined4 *)(iVar1 + DAT_060b1a1c);
    *DAT_060b1ad8 = *(undefined4 *)(iVar1 + DAT_060b1a1e);
    *DAT_060b1adc = *(undefined4 *)(iVar1 + DAT_060b1a20);
    *DAT_060b1ae0 = *(undefined4 *)(iVar1 + DAT_060b1a22);
    *(char *)(iVar1 + 7) = '\0';
  }
  if (*(char *)(iVar1 + 9) != '\0') {
    *DAT_060b1bb4 = *(undefined2 *)(iVar1 + DAT_060b1b90);
    *DAT_060b1bb8 = *(undefined2 *)(iVar1 + DAT_060b1b92);
    *DAT_060b1bbc = *(undefined2 *)(iVar1 + DAT_060b1b94);
    *DAT_060b1bc0 = *(undefined2 *)(iVar1 + DAT_060b1b96);
    *DAT_060b1bc4 = *(undefined2 *)(iVar1 + DAT_060b1b98);
    *DAT_060b1bc8 = *(undefined2 *)(iVar1 + DAT_060b1b9a);
    *DAT_060b1bcc = *(undefined2 *)(iVar1 + DAT_060b1b9c);
    *DAT_060b1bd0 = *(undefined2 *)(iVar1 + DAT_060b1b9e);
    *(char *)(iVar1 + 9) = '\0';
  }
  if (*(char *)(iVar1 + 8) != '\0') {
    *DAT_060b1bd4 = *(undefined2 *)(iVar1 + DAT_060b1ba0);
    *DAT_060b1bd8 = *(undefined2 *)(iVar1 + DAT_060b1ba2);
    *DAT_060b1bdc = *(undefined2 *)(iVar1 + DAT_060b1ba4);
    *DAT_060b1be0 = *(undefined2 *)(iVar1 + DAT_060b1ba6);
    *DAT_060b1be4 = *(undefined2 *)(iVar1 + DAT_060b1ba8);
    *DAT_060b1be8 = *(undefined2 *)(iVar1 + DAT_060b1baa);
    *DAT_060b1bec = *(undefined2 *)(iVar1 + DAT_060b1bac);
    *DAT_060b1bf0 = *(undefined2 *)(iVar1 + DAT_060b1bae);
    *DAT_060b1bf4 = *(undefined4 *)(iVar1 + DAT_060b1bb0);
    *DAT_060b1bf8 = *(undefined2 *)(iVar1 + DAT_060b1bb2);
    *(char *)(iVar1 + 8) = '\0';
  }
  return;
}



void FUN_060b1bfc(void)

{
  (*(code *)PTR_FUN_060b1c1c)(DAT_060b1c18,DAT_060b1c14,0xc);
  return;
}



void FUN_060b1c20(void)

{
  undefined *puVar1;
  
  puVar1 = DAT_060b1c74;
  *DAT_060b1c78 = DAT_060b1c70;
  (*(code *)PTR_FUN_060b1c7c)(puVar1 + 10,0xc);
  *(undefined2 *)(puVar1 + 0xc) = 3;
  *(undefined2 *)(puVar1 + 0xe) = 2;
  do {
  } while ((*DAT_060b1c80 & 8) == 0);
  (*(code *)PTR_FUN_060b1c84)();
  *puVar1 = 0;
  puVar1[1] = *puVar1;
  return;
}



void FUN_060b1c88(void)

{
  int iVar1;
  
  iVar1 = DAT_060b1d00;
  (*(code *)PTR_FUN_060b1d04)(DAT_060b1d00 + 0x18,(int)DAT_060b1cfa);
  *(ushort *)(iVar1 + 0x1e) = *DAT_060b1d08 & DAT_060b1cfc;
  *(undefined4 *)(iVar1 + 0x28) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x2c) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x30) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x34) = 0xffffffff;
  do {
  } while ((*DAT_060b1d0c & 8) == 0);
  (*(code *)PTR_FUN_060b1d14)(DAT_060b1d10,iVar1 + 0x18,(int)DAT_060b1cfa);
  *(undefined *)(iVar1 + 4) = 0;
  *(undefined *)(iVar1 + 5) = 0;
  *(undefined *)(iVar1 + 6) = 0;
  *(undefined *)(iVar1 + 7) = 0;
  *(undefined *)(iVar1 + 9) = 0;
  *(undefined *)(iVar1 + 8) = 0;
  return;
}



void FUN_060b1d18(undefined2 *param_1,undefined2 *param_2,int param_3)

{
  undefined2 uVar1;
  
  for (param_3 = param_3 >> 1; param_3 != 0; param_3 = param_3 + -1) {
    uVar1 = *param_2;
    param_2 = param_2 + 1;
    *param_1 = uVar1;
    param_1 = param_1 + 1;
  }
  return;
}



void FUN_060b1e04(undefined2 *param_1,undefined2 *param_2,uint param_3)

{
  undefined2 uVar1;
  int iVar2;
  
  for (iVar2 = (int)param_3 >> 1; iVar2 != 0; iVar2 = iVar2 + -1) {
    uVar1 = *param_2;
    param_2 = param_2 + 1;
    *param_1 = uVar1;
    param_1 = param_1 + 1;
  }
  if ((param_3 & 1) != 0) {
    *(undefined *)param_1 = *(undefined *)param_2;
  }
  return;
}



void FUN_060b1e68(undefined2 *param_1,int param_2)

{
  for (param_2 = param_2 >> 1; param_2 != 0; param_2 = param_2 + -1) {
    *param_1 = 0;
    param_1 = param_1 + 1;
  }
  return;
}



void FUN_060b1e84(undefined2 *param_1,uint param_2)

{
  int iVar1;
  
  for (iVar1 = (int)param_2 >> 1; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = 0;
    param_1 = param_1 + 1;
  }
  if ((param_2 & 1) != 0) {
    *(undefined *)param_1 = 0;
  }
  return;
}



void FUN_060b1eac(undefined4 *param_1,int param_2)

{
  int iVar1;
  
  for (iVar1 = param_2 >> 2; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = 0;
    param_1 = param_1 + 1;
  }
  if (param_2 + (param_2 >> 2) * -4 != 0) {
    (*(code *)PTR_FUN_060b1ee4)();
  }
  return;
}



void FUN_060b1fb0(char param_1,undefined param_2)

{
  int iVar1;
  int iVar2;
  ushort *puVar3;
  ushort uVar4;
  
  puVar3 = DAT_060b1ffc;
  iVar2 = DAT_060b1ff8;
  iVar1 = DAT_060b1ff4;
  if (param_1 == '\0') {
    uVar4 = *(ushort *)(DAT_060b1ff4 + 0x18) & DAT_060b1ff2;
    *(ushort *)(DAT_060b1ff4 + 0x18) = uVar4;
    *puVar3 = uVar4;
  }
  else {
    *(ushort *)(DAT_060b1ff4 + 0x18) = *(ushort *)(DAT_060b1ff4 + 0x18) & DAT_060b1ff2;
    *(undefined *)(iVar1 + 4) = 1;
  }
  *(undefined *)(iVar2 + 0x16) = param_2;
  return;
}



void FUN_060b20d4(void)

{
  short *psVar1;
  short *psVar2;
  int iVar3;
  short *psVar4;
  
  psVar2 = DAT_060b2124;
  psVar1 = DAT_060b2120;
  *DAT_060b2120 = *DAT_060b2124;
  iVar3 = DAT_060b2128;
  if (*psVar1 == 0) {
    psVar4 = (short *)(DAT_060b2128 + DAT_060b211c);
    (*(code *)PTR_FUN_060b2130)(PTR_s_save_old_scene_is_0__060b212c,(int)*psVar4);
    *psVar1 = *psVar4;
  }
  *psVar2 = 0;
  *(undefined2 *)(iVar3 + DAT_060b211e) = 0;
  return;
}



void FUN_060b2134(ushort *param_1,char *param_2,int param_3)

{
  ushort uVar1;
  ushort *puVar2;
  
  if (param_3 != 0) {
    do {
      if (*param_2 == '\0') break;
      param_3 = param_3 + -1;
      param_2 = param_2 + 4;
    } while (param_3 != 0);
    if (param_3 != 0) {
      puVar2 = param_1 + 1;
      *puVar2 = *param_1;
      uVar1 = ~((ushort)(byte)param_2[3] + (ushort)(byte)param_2[2] * 0x100);
      *param_1 = uVar1;
      param_1[2] = ~*puVar2 & uVar1;
      param_1[3] = ~*param_1 & *puVar2;
      return;
    }
  }
  *param_1 = 1;
  param_1[2] = 0;
  return;
}



void FUN_060b21a0(void)

{
  short *psVar1;
  int *piVar2;
  int *piVar3;
  undefined *puVar4;
  uint uVar5;
  
  piVar3 = DAT_060b221c;
  piVar2 = DAT_060b2218;
  psVar1 = DAT_060b2214;
  (*(code *)PTR_FUN_060b2220)(DAT_060b221c,DAT_060b2218);
  puVar4 = PTR_FUN_060b2224;
  uVar5 = (uint)*(byte *)(*piVar2 + 1);
  (*(code *)PTR_FUN_060b2224)(psVar1,*piVar3,uVar5);
  if (*psVar1 == 1) {
    psVar1[4] = 1;
    psVar1[6] = 0;
  }
  else {
    (*(code *)puVar4)(psVar1 + 4,uVar5 * 4 + *piVar3,*(undefined *)(*piVar2 + 3));
  }
  return;
}



bool FUN_060b2228(int param_1,int param_2,ushort param_3)

{
  short sVar1;
  
  sVar1 = DAT_060b2264;
  if (param_2 == 1) {
    sVar1 = DAT_060b2262;
  }
  return (*(ushort *)((int)sVar1 + param_1 * 8 + DAT_060b2268) & param_3) != 0;
}



undefined4 FUN_060b22b4(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)PTR_FUN_060b22e4)(PTR_s_DATA_BIN_060b22e0);
  (*(code *)PTR_FUN_060b22e8)(uVar1,param_1,0);
  return uVar1;
}



int FUN_060b22ec(short param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  
  *DAT_060b2354 = DAT_060b2350;
  (*(code *)PTR_FUN_060b2358)(6);
  *DAT_060b235c = 1;
  puVar3 = (undefined2 *)(PTR_DAT_060b2360 + param_1 * 4);
  uVar2 = *puVar3;
  while (iVar1 = (*(code *)PTR_FUN_060b2364)(uVar2), iVar1 == -1) {
    (*(code *)PTR_FUN_060b2368)();
    uVar2 = *puVar3;
  }
  (*(code *)PTR_FUN_060b236c)(iVar1,0);
  *DAT_060b2370 = (uint)(ushort)puVar3[1] * 2;
  return iVar1;
}



void FUN_060b2374(void)

{
  (*(code *)PTR_FUN_060b238c)();
  *DAT_060b2390 = 0;
  return;
}



int FUN_060b2394(undefined4 param_1)

{
  char local_c [8];
  
  (*(code *)PTR_FUN_060b23c0)(local_c,1,1,param_1);
  if (*DAT_060b23c4 < 0) {
    local_c[0] = -1;
  }
  return (int)local_c[0];
}



void FUN_060b23c8(uint param_1,int param_2,int param_3,undefined4 param_4)

{
  short *psVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  psVar1 = DAT_060b24f4;
  uVar8 = param_2 * param_3;
  *DAT_060b24f0 = *DAT_060b24f0 - uVar8;
  iVar4 = (int)*psVar1;
  if ((int)DAT_060b24ea < (int)(iVar4 + uVar8)) {
    iVar6 = (int)DAT_060b24ec;
    if (iVar4 != iVar6) {
      (*(code *)PTR_FUN_060b24fc)(param_1,*(int *)PTR_DAT_060b24f8 + iVar4,iVar6 - iVar4);
      param_1 = (param_1 + iVar6) - (int)*psVar1;
      uVar8 = (uVar8 - iVar6) + (int)*psVar1;
    }
    *psVar1 = 0;
    uVar3 = DAT_060b250c;
    if (iVar6 < (int)uVar8) {
      if ((DAT_060b2500 & param_1) == DAT_060b2504) {
        uVar7 = uVar8 & DAT_060b2508;
        uVar5 = uVar8;
        (*(code *)PTR_FUN_060b2510)(uVar8);
        (*(code *)PTR_FUN_060b2514)(param_4,uVar5,uVar3,uVar7);
        (*(code *)PTR_FUN_060b24fc)(param_1,uVar3,uVar7);
        (*(code *)PTR_FUN_060b2518)(1);
      }
      else {
        uVar5 = uVar8;
        (*(code *)PTR_FUN_060b2510)(uVar8);
        (*(code *)PTR_FUN_060b2514)(param_4,uVar5,param_1);
      }
      uVar5 = uVar8;
      if ((int)uVar8 < 0) {
        uVar5 = uVar8 + (int)DAT_060b24ea;
      }
      (*(code *)PTR_FUN_060b2510)();
      param_1 = param_1 + uVar5 * (int)DAT_060b24ec;
      uVar8 = uVar8 - uVar5 * (int)DAT_060b24ec;
    }
    puVar2 = PTR_DAT_060b24f8;
    if (uVar8 != 0) {
      (*(code *)PTR_FUN_060b2514)(param_4,1,*(undefined4 *)PTR_DAT_060b24f8,(int)DAT_060b24ec);
      (*(code *)PTR_FUN_060b24fc)(param_1,*(undefined4 *)puVar2,uVar8);
      *DAT_060b24f4 = *DAT_060b24f4 + (short)uVar8;
    }
  }
  else {
    (*(code *)PTR_FUN_060b24fc)(param_1,*(int *)PTR_DAT_060b24f8 + iVar4,uVar8);
    *psVar1 = *psVar1 + (short)param_3 * (short)uVar8;
  }
  return;
}



void FUN_060b251c(int param_1)

{
  (*(code *)PTR_FUN_060b2540)(param_1 * DAT_060b253a + DAT_060b253c,0);
  return;
}



undefined4 FUN_060b2544(int param_1)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  short sVar4;
  int iVar5;
  short *psVar6;
  
  iVar1 = DAT_060b2614;
  if ((*DAT_060b2610 != 1) || (param_1 != 2)) {
    *(undefined4 *)PTR_DAT_060b2618 = 0;
  }
  if (*(char *)(iVar1 + DAT_060b2608) != '\0') goto LAB_060b257c;
  sVar4 = *(short *)(iVar1 + DAT_060b260a);
  do {
    if ((sVar4 == 0) && (*DAT_060b2610 != 1)) {
      return 0;
    }
LAB_060b257c:
    do {
      puVar2 = PTR_DAT_060b2618;
      if ((*DAT_060b2610 == 1) &&
         (iVar3 = *(int *)PTR_DAT_060b2618, iVar5 = (int)DAT_060b260c,
         *(int *)PTR_DAT_060b2618 = iVar3 + 1, iVar5 < iVar3 + 1)) {
        (*(code *)PTR_FUN_060b261c)(0x10);
        *(undefined4 *)puVar2 = 0;
      }
      iVar3 = (int)DAT_060b2608;
      psVar6 = (short *)(iVar1 + DAT_060b260a);
      sVar4 = *psVar6;
      if (sVar4 == 1) {
        (*(code *)PTR_FUN_060b261c)(0x10);
        *psVar6 = 0;
        *(short *)(iVar1 + DAT_060b260e) = *(short *)(iVar1 + DAT_060b260e) + 1;
        sVar4 = *psVar6;
      }
      if (sVar4 == 2) {
        (*(code *)PTR_FUN_060b261c)(0x10);
      }
      if (param_1 == 2) {
        return 0xffffffff;
      }
      (*(code *)PTR_FUN_060b2620)();
    } while (*(char *)(iVar1 + iVar3) != '\0');
    sVar4 = *psVar6;
  } while( true );
}



undefined4 FUN_060b2624(short param_1,int param_2,undefined4 param_3)

{
  undefined2 uVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  undefined uVar7;
  uint uVar6;
  int *piVar8;
  int iVar9;
  
  iVar9 = DAT_060b2764;
  uVar1 = *(undefined2 *)(PTR_DAT_060b2760 + param_1 * 4);
  piVar8 = (int *)(param_2 * DAT_060b2752 + 0x1c + DAT_060b2764);
  iVar4 = (*(code *)PTR_FUN_060b2768)(2);
  if (iVar4 != 0) {
    return 0xffffffff;
  }
  *(undefined *)(iVar9 + DAT_060b2754) = 2;
  switch(param_3) {
  case 0:
    (*(code *)PTR_FUN_060b276c)(param_2);
    uVar7 = 3;
    break;
  case 1:
    uVar7 = 0xd;
    break;
  case 2:
    uVar7 = 0x17;
    break;
  case 3:
    uVar7 = 0x18;
    break;
  default:
    goto switchD_060b2684_caseD_4;
  }
  *(undefined *)((int)piVar8 + 5) = uVar7;
switchD_060b2684_caseD_4:
  *(undefined *)(iVar9 + DAT_060b2756) = 2;
  puVar2 = PTR_FUN_060b2770;
  iVar9 = (int)DAT_060b2758;
  do {
    piVar8[2] = 0;
    iVar4 = 0;
    do {
      if (iVar9 < iVar4) break;
      iVar5 = (*(code *)puVar2)(uVar1);
      piVar8[2] = iVar5;
      iVar4 = iVar4 + 1;
    } while (iVar5 == 0);
    puVar3 = PTR_DAT_060b2774;
    if (iVar4 != DAT_060b275a) {
      *piVar8 = (int)param_1;
      piVar8[4] = (uint)*(ushort *)(puVar3 + param_1 * 4) * 2;
      iVar9 = (uint)*(ushort *)(puVar3 + param_1 * 4) * 2 + 0xf;
      if (param_2 == 0) {
        uVar6 = DAT_060b277c - iVar9;
      }
      else {
        uVar6 = DAT_060b2778 - iVar9;
      }
      piVar8[3] = uVar6 & 0xfffffff0;
      iVar9 = piVar8[4] + (int)DAT_060b275c;
      if (iVar9 < 0) {
        iVar9 = iVar9 + DAT_060b275c;
      }
      (*(code *)PTR_FUN_060b2780)(iVar9);
      (*(code *)PTR_FUN_060b2784)(piVar8[2],iVar9);
      return 0;
    }
  } while( true );
}



void FUN_060b2788(uint *param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint *extraout_r3;
  uint *puVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  
  uVar1 = *param_1;
  if (uVar1 != 0xffffffff) {
    pcVar7 = (char *)(param_2 + 0x18);
    pcVar6 = (char *)(param_2 + 0x19);
    pcVar5 = (char *)(param_2 + 0x1a);
    pcVar4 = (char *)(param_2 + 0x1b);
    do {
      (*(code *)PTR_FUN_060b2888)();
      puVar3 = extraout_r3;
      switch(uVar1) {
      case 0:
        *(int *)(*pcVar7 * 8 + param_2 + 0x1c) = param_3;
        puVar3 = extraout_r3 + 1;
        *(uint *)(*pcVar7 * 8 + param_2 + 0x20) = *puVar3;
        *pcVar7 = *pcVar7 + '\x01';
        break;
      case 1:
        *(int *)(*pcVar6 * 8 + param_2 + 0x5c) = param_3;
        puVar3 = extraout_r3 + 1;
        *(uint *)(*pcVar6 * 8 + param_2 + 0x60) = *puVar3;
        *pcVar6 = *pcVar6 + '\x01';
        break;
      case 2:
        puVar3 = extraout_r3 + 1;
        *(int *)(*pcVar5 * 8 + param_2 + (int)DAT_060b2880) = param_3;
        *(uint *)(*pcVar5 * 8 + param_2 + (int)DAT_060b2882) = *puVar3;
        *pcVar5 = *pcVar5 + '\x01';
        break;
      case 3:
        puVar3 = extraout_r3 + 1;
        *(int *)(*pcVar4 * 8 + param_2 + (int)DAT_060b2884) = param_3;
        *(uint *)(*pcVar4 * 8 + param_2 + (int)DAT_060b2886) = *puVar3;
        *pcVar4 = *pcVar4 + '\x01';
      }
      uVar2 = *puVar3;
      if ((int)uVar2 < 0) {
        uVar2 = uVar2 + 3;
      }
      uVar1 = puVar3[1];
      param_3 = param_3 + (uVar2 & 0xfffffffc);
    } while (uVar1 != 0xffffffff);
  }
  return;
}



int FUN_060b288c(void)

{
  bool bVar1;
  int iVar2;
  int in_r0;
  int iVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  int iStack_28;
  int iStack_24;
  
  iVar2 = DAT_060b29c8;
  if (*DAT_060b29c4 != '\0') {
    iVar7 = 0;
    iVar11 = 0;
    iVar5 = DAT_060b29c8;
    do {
      iVar11 = iVar11 + 1;
      if (*(char *)(iVar5 + 0x21) != '\0') {
        iVar7 = iVar7 + 1;
      }
      iVar5 = iVar5 + DAT_060b29b8;
    } while (iVar11 < 2);
    iVar5 = 0;
    if (iVar7 == 0) {
      in_r0 = (int)DAT_060b29ba;
      *(undefined *)(DAT_060b29c8 + in_r0) = 0;
    }
    else {
      iVar7 = DAT_060b29c8 + 0x1c;
      iStack_28 = DAT_060b29c8;
      iStack_24 = 0;
      do {
        iVar11 = iVar2 + iStack_24 + 0x1c;
        piVar10 = DAT_060b29cc;
        if (iVar5 != 0) {
          piVar10 = DAT_060b29d0;
        }
        piVar8 = piVar10;
        switch(*(undefined *)(iVar11 + 5)) {
        case 1:
switchD_060b2914_caseD_1:
          iVar3 = *piVar10;
          while (iVar3 != -1) {
            piVar8 = piVar8 + 1;
            iVar3 = *piVar8;
          }
          *(undefined *)(iVar11 + 0x18) = 0;
          *(undefined *)(iVar11 + 0x19) = 0;
          *(undefined *)(iVar11 + 0x1b) = 0;
          *(undefined *)(iVar11 + 0x1a) = 0;
          pcVar4 = (code *)PTR_FUN_060b2ba4;
          iVar3 = iVar11;
          goto LAB_060b2b42;
        case 2:
switchD_060b2914_caseD_2:
          *DAT_060b2b94 = 0;
          (*(code *)PTR_FUN_060b2b98)((int)DAT_060b2b80);
          if ((*DAT_060b2b9c != 0) &&
             (*(undefined *)(iVar11 + 5) = 1, *(uint *)PTR_DAT_060b2ba0 <= (uint)(int)DAT_060b2b82))
          goto switchD_060b2914_caseD_1;
          break;
        case 3:
          iVar3 = (*(code *)PTR_FUN_060b2b88)(*(undefined4 *)(iStack_28 + 0x24));
          if (iVar3 == 0) {
            *(undefined *)(iVar2 + DAT_060b2b7c) = 0;
            (*(code *)PTR_FUN_060b2b8c)(*(undefined4 *)(iVar11 + 0xc),piVar10);
            *(undefined *)(iVar11 + 5) = 2;
            (*(code *)PTR_FUN_060b2b90)(*(undefined4 *)(iVar11 + 8));
            *(undefined *)(iVar2 + DAT_060b2b7e) = 1;
            goto switchD_060b2914_caseD_2;
          }
          break;
        case 0xb:
switchD_060b2914_caseD_b:
          iVar3 = *piVar10;
          while (iVar3 != -1) {
            piVar8 = piVar8 + 1;
            iVar3 = *piVar8;
          }
          bVar1 = piVar8[1] == -2;
          pcVar4 = (code *)PTR_FUN_060b2ab4;
          iVar3 = iVar7;
          if (bVar1) {
            *(undefined *)(DAT_060b2a8c + iVar2) = 0;
            *(undefined4 *)(DAT_060b2a92 + iVar11) = 0;
            (*(code *)PTR_FUN_060b2ab0)((int)(short)(*(short *)(iVar11 + 2) + 1),bVar1,bVar1);
            pcVar4 = (code *)PTR_FUN_060b2ab4;
          }
LAB_060b2b42:
          (*pcVar4)(piVar10,iVar3,piVar8 + 2);
          *(undefined *)(iStack_28 + 0x21) = 0;
          break;
        case 0xc:
switchD_060b2914_caseD_c:
          *DAT_060b2aa0 = 0;
          (*(code *)PTR_FUN_060b2aa4)((int)DAT_060b2a8e);
          if ((*DAT_060b2aa8 != 0) &&
             (*(undefined *)(iVar11 + 5) = 0xb, *(uint *)PTR_DAT_060b2aac <= (uint)(int)DAT_060b2a90
             )) goto switchD_060b2914_caseD_b;
          break;
        case 0xd:
          iVar3 = (*(code *)PTR_FUN_060b2a94)(*(undefined4 *)(iStack_28 + 0x24));
          if (iVar3 == 0) {
            *(undefined *)(iVar2 + DAT_060b2a8a) = 0;
            (*(code *)PTR_FUN_060b2a98)(*(undefined4 *)(iVar11 + 0xc),piVar10);
            *(undefined *)(iVar11 + 5) = 0xc;
            (*(code *)PTR_FUN_060b2a9c)(*(undefined4 *)(iVar11 + 8));
            *(undefined *)(iVar2 + DAT_060b2a8c) = 1;
            goto switchD_060b2914_caseD_c;
          }
          break;
        case 0x17:
          iVar3 = (*(code *)PTR_FUN_060b29d4)(*(undefined4 *)(iStack_28 + 0x24));
          if (iVar3 == 0) {
            *(undefined *)(DAT_060b29bc + iVar2) = 0;
            *(undefined *)(iVar11 + 5) = 0;
            (*(code *)PTR_FUN_060b29d8)(*(undefined4 *)(iVar11 + 8));
            piVar10 = DAT_060b29dc;
            iVar9 = (int)DAT_060b29be;
            iVar3 = *DAT_060b29dc * 4 + iVar2;
            if (*(int *)(iVar9 + iVar3) < *(int *)(iVar11 + 0x10)) {
              piVar8 = (int *)(iVar2 + DAT_060b29c2);
              *(int *)(DAT_060b29c0 + iVar3) = *piVar8;
              *piVar8 = *piVar8 + *(int *)(iVar11 + 0x10);
            }
            iVar6 = *piVar10 * 4 + iVar2;
            iVar3 = (int)DAT_060b29c0;
            *(undefined4 *)(iVar9 + iVar6) = *(undefined4 *)(iVar11 + 0x10);
            (*(code *)PTR_FUN_060b29e0)
                      (*(undefined4 *)(iVar3 + iVar6),*(undefined4 *)(iVar11 + 0xc),
                       *(undefined4 *)(iVar11 + 0x10));
            *(undefined *)(DAT_060b29ba + iVar2) = 0;
          }
        }
        iVar5 = iVar5 + 1;
        in_r0 = iStack_28 + DAT_060b2b84;
        iStack_24 = iStack_24 + DAT_060b2b84;
        iStack_28 = in_r0;
      } while (iVar5 < 2);
    }
  }
  return in_r0;
}



void FUN_060b2ba8(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(param_1 + param_2 * 8 + 0x1c);
  (*(code *)PTR_FUN_060b2bd8)(0,*(undefined4 *)(PTR_LAB_060b2bd4 + param_3 * 4),*puVar1,puVar1[1]);
  return;
}



void FUN_060b2bdc(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = (int *)(param_1 + param_2 * 8 + 0x5c);
  if (param_5 == 0) {
    uVar2 = *(undefined4 *)(PTR_DAT_060b2c24 + param_3 * 4);
    iVar3 = *piVar1;
    param_5 = piVar1[1];
  }
  else {
    uVar2 = *(undefined4 *)(PTR_DAT_060b2c24 + param_3 * 4);
    param_5 = param_5 * 2;
    iVar3 = param_4 * 2 + *piVar1;
  }
  (*(code *)PTR_FUN_060b2c28)(uVar2,iVar3,param_5);
  return;
}



void FUN_060b2c2c(int param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  
  piVar1 = DAT_060b2c90;
  puVar2 = (undefined4 *)(param_1 + param_2 * 8 + (int)DAT_060b2c8a);
  if (param_3 == DAT_060b2c8c) {
    (*(code *)PTR_FUN_060b2c94)(0,*DAT_060b2c90,*puVar2,puVar2[1]);
    *piVar1 = *piVar1 + puVar2[1];
  }
  else {
    piVar1 = (int *)(PTR_DAT_060b2c98 + param_3 * 4);
    (*(code *)PTR_FUN_060b2c94)(0,*piVar1,*puVar2,puVar2[1]);
    *DAT_060b2c90 = *piVar1 + puVar2[1];
  }
  return;
}



void FUN_060b2c9c(int param_1,short *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = ((int)*param_2 + 3U & DAT_060b2ce8) + ((int)param_2[1] + 3U & DAT_060b2ce8);
  piVar2 = (int *)(param_1 + 0x10);
  (*(code *)PTR_FUN_060b2cec)();
  iVar1 = 0;
  if (0 < iVar3) {
    do {
      iVar1 = iVar1 + 1;
      *piVar2 = *piVar2 + (int)param_2;
      piVar2 = piVar2 + 1;
    } while (iVar1 < iVar3);
  }
  return;
}



void FUN_060b2cf0(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  short *psVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = *(int *)(PTR_DAT_060b2d54 + param_3 * 4);
  puVar2 = (undefined4 *)(param_1 + param_2 * 8 + (int)DAT_060b2d52);
  psVar3 = (short *)*puVar2;
  piVar4 = (int *)(iVar6 + 0x10);
  iVar5 = ((int)*psVar3 + 3U & DAT_060b2d58) + ((int)psVar3[1] + 3U & DAT_060b2d58);
  (*(code *)PTR_FUN_060b2d5c)(iVar6,psVar3,puVar2[1]);
  iVar1 = 0;
  if (0 < iVar5) {
    do {
      iVar1 = iVar1 + 1;
      *piVar4 = *piVar4 + iVar6;
      piVar4 = piVar4 + 1;
    } while (iVar1 < iVar5);
  }
  return;
}



void FUN_060b2d60(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  
  iVar1 = param_1 * DAT_060b2de2 + DAT_060b2de4;
  if (*(char *)(iVar1 + 0x18) != '\0') {
    (*(code *)PTR_FUN_060b2de8)(iVar1,0,param_4);
  }
  if (*(char *)(iVar1 + 0x19) != '\0') {
    (*(code *)PTR_FUN_060b2dec)(iVar1,0,param_5,0,0);
  }
  if (*(char *)(iVar1 + 0x1a) != '\0') {
    (*(code *)PTR_FUN_060b2df0)(iVar1,0,param_2);
  }
  if (*(char *)(iVar1 + 0x1b) != '\0') {
    (*(code *)PTR_FUN_060b2df4)(iVar1,0,param_3);
  }
  return;
}



void FUN_060b2ed0(undefined4 param_1)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  
  puVar1 = PTR_FUN_060b2f08;
  uVar3 = (uint)DAT_060b2f04;
  do {
    iVar2 = (*(code *)puVar1)(param_1);
  } while (uVar3 < iVar2 - 1U);
  (*(code *)PTR_FUN_060b2f0c)(iVar2);
  return;
}



void FUN_060b2f38(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uStack_28 = 0x100;
  uStack_24 = 1;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 1;
  uStack_14 = 7;
  uStack_10 = 3;
  local_34 = param_3;
  uStack_30 = param_2;
  uStack_2c = param_4;
  (*(code *)PTR_FUN_060b2f80)(&local_34,param_1);
  (*(code *)PTR_FUN_060b2f84)(param_1);
  return;
}



void FUN_060b2f8c(short param_1,undefined2 *param_2,int param_3)

{
  undefined2 uVar1;
  ushort uVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined *puVar5;
  undefined4 uVar6;
  int iVar7;
  undefined2 *puVar8;
  
  uVar2 = *(ushort *)(PTR_DAT_060b3018 + param_1 * 4);
  uVar6 = (*(code *)PTR_FUN_060b3020)((int)param_1,PTR_DAT_060b301c);
  puVar8 = DAT_060b3028;
  uVar3 = DAT_060b3024;
  (*(code *)PTR_FUN_060b302c)(DAT_060b3024,1,(uint)uVar2 * 2,uVar6);
  (*(code *)PTR_FUN_060b3030)(uVar6);
  (*(code *)PTR_FUN_060b3034)(uVar3,puVar8);
  puVar5 = PTR_FUN_060b303c;
  piVar4 = DAT_060b3038;
  if (*DAT_060b3038 == 0) {
    iVar7 = (int)DAT_060b3014;
    do {
      (*(code *)puVar5)(iVar7);
    } while (*piVar4 == 0);
  }
  if (0 < param_3) {
    do {
      uVar1 = *puVar8;
      puVar8 = puVar8 + 1;
      param_3 = param_3 + -2;
      *param_2 = uVar1;
      param_2 = param_2 + 1;
    } while (0 < param_3);
  }
  return;
}



undefined4 FUN_060b3040(int param_1)

{
  int iVar1;
  short *psVar2;
  
  if (param_1 != 0) {
    psVar2 = (short *)(DAT_060b3098 + DAT_060b3096);
    iVar1 = 8;
    do {
      iVar1 = iVar1 + -1;
      if (*psVar2 == 0) {
        (*(code *)PTR_FUN_060b309c)(psVar2);
        *psVar2 = *(short *)(param_1 + 2);
        *(int *)(psVar2 + 4) = param_1;
        *(int *)(psVar2 + 6) = param_1 + 8;
        return 1;
      }
      psVar2 = psVar2 + 8;
    } while (1 < iVar1);
  }
  return 0;
}



void FUN_060b30a0(int param_1)

{
  undefined2 *puVar1;
  
  if (param_1 != 0) {
    puVar1 = (undefined2 *)(DAT_060b30dc + DAT_060b30d8);
    (*(code *)PTR_FUN_060b30e0)(puVar1);
    *puVar1 = *(undefined2 *)(param_1 + 2);
    *(int *)(puVar1 + 4) = param_1;
    *(int *)(puVar1 + 6) = param_1 + 8;
  }
  return;
}



void FUN_060b30e4(undefined2 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 6) = 0;
  return;
}



void FUN_060b3108(void)

{
  short *psVar1;
  short *psVar2;
  undefined *puVar3;
  
  psVar1 = DAT_060b3158;
  if (DAT_060b3150 < DAT_060b3158) {
    puVar3 = (undefined *)(DAT_060b3154 + 0x17);
    psVar2 = DAT_060b3150;
    do {
      if (*psVar2 != 0) {
        (**(code **)(PTR_PTR_LAB_060b315c + (*psVar2 + -1) * 4))(psVar2);
        *puVar3 = 1;
      }
      psVar2 = psVar2 + 8;
    } while (psVar2 < psVar1);
  }
  return;
}



void FUN_060b3618(undefined2 param_1)

{
  *DAT_060b3624 = param_1;
  return;
}



void FUN_060b3628(ushort param_1)

{
  *DAT_060b364c = param_1;
  param_1 = param_1 & DAT_060b364a;
  *DAT_060b3650 = param_1;
  *DAT_060b3654 = param_1;
  *DAT_060b3658 = param_1;
  *DAT_060b365c = 1;
  return;
}



void FUN_060b3738(void)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  int iVar7;
  short *psVar8;
  short *psVar9;
  char *pcVar10;
  char *pcVar11;
  int iVar12;
  byte *pbVar13;
  
  uVar2 = DAT_060b381a;
  iVar12 = (int)DAT_060b3818;
  psVar8 = (short *)(DAT_060b381c + 0x24);
  psVar9 = (short *)(DAT_060b381c + 0x26);
  pbVar13 = (byte *)(DAT_060b381c + 3);
  pcVar11 = DAT_060b381c + 2;
  pcVar10 = DAT_060b381c;
  do {
    if (((*pcVar10 != '\0') && (psVar6 = *(short **)(pcVar10 + 0x14), psVar6 != (short *)0x0)) &&
       (*pcVar11 == '\0')) {
      if (*psVar9 == 0) {
        if (*psVar8 < *psVar6) goto LAB_060b37b0;
        uVar3 = (ushort)*pbVar13;
        if (uVar3 == 2) {
          *pcVar11 = '\x01';
          goto LAB_060b37f8;
        }
        if (*pbVar13 < 3) {
          if (uVar3 == 1) {
            *psVar8 = 0;
LAB_060b37b0:
            iVar4 = (int)*psVar8;
          }
          else {
            iVar4 = (int)*psVar8;
          }
        }
        else {
          if (uVar3 == uVar2) {
            *pcVar10 = '\0';
            goto LAB_060b37b0;
          }
          iVar4 = (int)*psVar8;
        }
        iVar7 = (int)**(short **)(pcVar10 + 0x20);
        iVar5 = iVar7 + 3;
        if (iVar5 < 0) {
          iVar5 = iVar7 + 6;
        }
        *(undefined4 *)(pcVar10 + 0x18) =
             *(undefined4 *)
              (*(short **)(pcVar10 + 0x20) + (iVar5 >> 2) * 8 + psVar6[iVar4 * 2 + 1] * 2 + 8);
        *psVar9 = (psVar6 + iVar4 * 2 + 1)[1];
      }
      sVar1 = *psVar9;
      *psVar9 = sVar1 + -1;
      if ((short)(sVar1 + -1) < 1) {
        *psVar9 = 0;
        *psVar8 = *psVar8 + 1;
      }
    }
LAB_060b37f8:
    iVar12 = iVar12 + -1;
    psVar8 = psVar8 + 0x26;
    psVar9 = psVar9 + 0x26;
    pbVar13 = pbVar13 + 0x4c;
    pcVar11 = pcVar11 + 0x4c;
    pcVar10 = pcVar10 + 0x4c;
    if (iVar12 == 0) {
      return;
    }
  } while( true );
}



undefined2 * FUN_060b3838(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  short sVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  short sVar9;
  undefined *puVar10;
  byte bVar12;
  undefined2 *puVar11;
  uint uVar13;
  short sVar15;
  byte *pbVar14;
  short *psVar16;
  undefined2 *puVar17;
  short *psVar18;
  char *pcVar19;
  int iVar20;
  undefined4 *puVar21;
  
  iVar5 = DAT_060b39dc;
  sVar15 = 0x20;
  puVar21 = DAT_060b39e0;
  do {
    *puVar21 = 0;
    puVar6 = DAT_060b39e0;
    sVar15 = sVar15 + -1;
    puVar21 = puVar21 + 1;
  } while (sVar15 != 0);
  pcVar19 = (char *)(iVar5 + DAT_060b39bc);
  iVar20 = (int)DAT_060b39be;
  pbVar14 = (byte *)(pcVar19 + 1);
  do {
    iVar20 = iVar20 + -1;
    if ((*pcVar19 != '\0') && (bVar12 = *pbVar14, bVar12 < 0x20)) {
      *(undefined4 *)(pcVar19 + 0x28) = puVar6[0x1f - (uint)bVar12];
      puVar6[0x1f - (uint)bVar12] = pcVar19;
    }
    iVar8 = DAT_060b39e8;
    uVar7 = DAT_060b39e4;
    uVar1 = DAT_060b39c0;
    pbVar14 = pbVar14 + 0x4c;
    pcVar19 = pcVar19 + 0x4c;
  } while (iVar20 != 0);
  bVar12 = *(byte *)(iVar5 + 0x12) ^ 1;
  *(byte *)(iVar5 + 0x12) = bVar12;
  uVar13 = (bVar12 & 7) * 0x2000;
  puVar17 = (undefined2 *)(uVar7 | uVar13);
  *puVar17 = 9;
  uVar2 = DAT_060b39c2;
  puVar17[10] = DAT_060b39c2;
  puVar17[0xb] = uVar1;
  puVar17[0x10] = 8;
  puVar17[0x16] = *(undefined2 *)(iVar5 + DAT_060b39c4);
  uVar3 = DAT_060b39c8;
  puVar17[0x17] = *(undefined2 *)(iVar5 + DAT_060b39c6);
  puVar17[0x1a] = *(undefined2 *)(iVar5 + DAT_060b39ca);
  puVar17[0x1b] = *(undefined2 *)(iVar5 + DAT_060b39cc);
  puVar17[0x20] = 4;
  puVar17[0x22] = uVar3;
  puVar17[0x23] = 0;
  puVar17[0x26] = 0;
  puVar17[0x27] = 0;
  puVar17[0x28] = uVar2;
  puVar17[0x29] = 0;
  puVar17[0x2a] = uVar2;
  puVar17[0x2b] = uVar1;
  puVar17[0x2c] = 0;
  puVar17[0x2d] = uVar1;
  *(undefined2 *)(iVar5 + DAT_060b39ce) = 0;
  iVar20 = iVar5 + DAT_060b39bc;
  puVar17[0x30] = 4;
  puVar17[0x32] = uVar3;
  puVar17[0x33] = DAT_060b39d0;
  sVar9 = DAT_060b3ae0;
  sVar4 = DAT_060b3ade;
  puVar21 = DAT_060b39ec;
  sVar15 = DAT_060b39d4;
  puVar11 = (undefined2 *)(int)*(short *)(iVar5 + DAT_060b39d2);
  if (puVar11 == (undefined2 *)0x2) {
    psVar18 = (short *)(iVar20 + 8);
    psVar16 = (short *)(iVar20 + 0xc);
    puVar17[0x36] = *psVar18;
    sVar4 = DAT_060b39d6;
    puVar17[0x37] = *psVar16 + sVar15;
    puVar17[0x38] = *psVar18 + sVar4;
    puVar17[0x39] = *psVar16 + sVar15;
    puVar17[0x3a] = *psVar18 + sVar4;
    sVar15 = DAT_060b39d8;
    puVar17[0x3b] = *psVar16 + DAT_060b39d8;
    puVar17[0x3c] = *psVar18;
  }
  else {
    psVar18 = (short *)(iVar20 + 8);
    psVar16 = (short *)(iVar20 + 0xc);
    puVar17[0x36] = *psVar18 + 8;
    puVar17[0x37] = *psVar16 + sVar4;
    puVar17[0x38] = *psVar18 + sVar9;
    puVar17[0x39] = *psVar16 + sVar4;
    puVar17[0x3a] = *psVar18 + sVar9;
    sVar15 = DAT_060b3ae2;
    puVar17[0x3b] = *psVar16 + DAT_060b3ae2;
    puVar17[0x3c] = *psVar18 + 8;
  }
  puVar17[0x3d] = *(short *)(iVar20 + 0xc) + sVar15;
  puVar10 = PTR_FUN_060b3ae8;
  puVar17 = puVar17 + 0x40;
  iVar20 = 0;
  do {
    for (pbVar14 = (byte *)*puVar21; pbVar14 != (byte *)0x0; pbVar14 = *(byte **)(pbVar14 + 0x28)) {
      puVar11 = (undefined2 *)(uint)*pbVar14;
      if (puVar11 == (undefined2 *)0x2) {
        puVar11 = (undefined2 *)(*(code *)PTR_FUN_060b3aec)(pbVar14);
        puVar17 = puVar11;
      }
      else if (puVar11 < (undefined2 *)0x3) {
        if (puVar11 == (undefined2 *)0x1) {
LAB_060b3a78:
          puVar11 = (undefined2 *)(*(code *)puVar10)(pbVar14);
          puVar17 = puVar11;
        }
      }
      else if (puVar11 == (undefined2 *)0x3) goto LAB_060b3a78;
      if ((undefined2 *)(iVar8 + uVar13) <= puVar17) goto LAB_060b3a9c;
    }
    iVar20 = iVar20 + 1;
    puVar21 = puVar21 + -1;
  } while (iVar20 < 0x20);
LAB_060b3a9c:
  *puVar17 = DAT_060b3ae4;
  puVar17 = DAT_060b3af0;
  *DAT_060b3af0 = DAT_060b3ae6;
  puVar17[1] = (ushort)*(byte *)(iVar5 + 0x12) * 0x400 + 4;
  puVar17[6] = 0;
  puVar17[7] = 0;
  return puVar11;
}



ushort * FUN_060b3af4(int param_1,ushort *param_2)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  ushort uVar5;
  short extraout_r1;
  short sVar6;
  short extraout_r2;
  short extraout_r2_00;
  ushort uVar7;
  ushort extraout_r3;
  ushort *puVar8;
  ushort *puVar9;
  ushort *puVar10;
  short local_72;
  short local_6e;
  ushort local_66;
  ushort local_62;
  ushort local_5e;
  byte *pbStack_58;
  ushort *puStack_54;
  byte *pbStack_50;
  ushort *puStack_4c;
  ushort *puStack_48;
  ushort *puStack_44;
  ushort *puStack_40;
  ushort *puStack_3c;
  ushort *local_38;
  ushort *local_34;
  ushort *local_30;
  ushort *local_2c;
  ushort *local_28;
  ushort *local_24;
  
  puStack_48 = *(ushort **)(param_1 + 0x18);
  if (puStack_48 != (ushort *)0x0) {
    local_5e = *puStack_48;
    sVar1 = *(short *)(param_1 + 8);
    sVar2 = *(short *)(param_1 + 0xc);
    local_6e = *(short *)(param_1 + 0x10);
    puVar10 = puStack_48 + 4;
    if (local_6e < 0) {
      local_66 = 0x10;
      local_6e = -local_6e;
    }
    else {
      local_66 = 0;
    }
    local_72 = *(short *)(param_1 + 0x12);
    if (local_72 < 0) {
      local_62 = 0x20;
      local_72 = -local_72;
    }
    else {
      local_62 = 0;
    }
    if (local_5e != 0) {
      pbStack_58 = (byte *)((int)puStack_48 + 0xb);
      puStack_54 = puStack_48 + 5;
      puVar8 = puStack_48 + 9;
      puVar9 = puStack_48 + 8;
      pbStack_50 = (byte *)((int)puStack_48 + 9);
      puStack_4c = puStack_48 + 7;
      local_2c = param_2 + 2;
      puStack_44 = param_2 + 9;
      puStack_40 = param_2 + 8;
      local_24 = param_2 + 7;
      local_28 = param_2 + 6;
      puStack_3c = param_2 + 0xe;
      local_38 = param_2 + 5;
      local_34 = param_2 + 4;
      local_30 = param_2 + 3;
      do {
        puStack_48 = puStack_48 + 6;
        if (local_66 == 0) {
          iVar4 = (int)(short)*puVar9;
        }
        else {
          iVar4 = -(int)(short)*puVar9;
        }
        if ((iVar4 + sVar1 + (int)DAT_060b3d4a & 0xffffU) <= (uint)(int)DAT_060b3d4c) {
          if (local_62 == 0) {
            iVar4 = (int)(short)*puVar8;
          }
          else {
            iVar4 = -(int)(short)*puVar8;
          }
          if ((iVar4 + sVar2 + (int)DAT_060b3d4a & 0xffffU) <= (uint)(int)DAT_060b3d4e) {
            uVar7 = (ushort)*(byte *)puVar10;
            if ((*(byte *)puVar10 & 8) == 0) {
              uVar3 = (int)*(char *)(param_1 + 4) << 4 & (int)DAT_060b3d50;
              *local_30 = DAT_060b3d52 | (ushort)uVar3;
              if ((uVar3 & 0xf0) != 0) {
                uVar7 = uVar7 & 0xdf | 0x10;
              }
            }
            else {
              *local_30 = *puStack_48;
            }
            *local_34 = *(short *)(param_1 + 0x1c) + *puStack_4c;
            *local_38 = (ushort)*pbStack_58 + ((short)(char)*(byte *)puStack_54 & 0xf8U) * 0x20;
            *puStack_3c = 0;
            uVar5 = (short)(char)*pbStack_50 & 0x30U ^ (local_66 | local_62);
            sVar6 = local_6e;
            if ((*pbStack_50 & 0x40) != 0) {
              sVar6 = (short)((uint)(local_6e * 5) >> 2);
            }
            if ((sVar6 == 0x1000) && (local_72 == 0x1000)) {
              if (local_66 == 0) {
                *local_28 = *puVar9 + sVar1;
              }
              else {
                *local_28 = (sVar1 - *puVar9) - (ushort)(*(byte *)puStack_54 >> 1);
              }
              if (local_62 == 0) {
                *local_24 = *puVar8 + sVar2;
              }
              else {
                *local_24 = (sVar2 - *puVar8) - (ushort)(*pbStack_58 >> 1);
              }
              uVar7 = uVar7 | DAT_060b3e1a;
              *param_2 = uVar5;
              *local_2c = uVar7;
              if (*(byte *)(param_1 + 1) < 0x18) {
                *local_2c = DAT_060b3e1c | uVar7;
              }
            }
            else {
              if (local_66 == 0) {
                sVar6 = sVar6 * *puVar9;
                (*DAT_060b3e20)();
                uVar7 = sVar1 + sVar6;
              }
              else {
                (*DAT_060b3e20)();
                uVar7 = (sVar1 - *puVar9) - sVar6;
              }
              *local_28 = uVar7;
              if (local_62 == 0) {
                sVar6 = local_72 * *puVar8;
                (*DAT_060b3f44)();
                *local_24 = sVar2 + sVar6;
                sVar6 = extraout_r2_00;
              }
              else {
                sVar6 = local_72;
                (*DAT_060b3e20)();
                *local_24 = extraout_r1 - sVar6;
                sVar6 = extraout_r2;
              }
              uVar7 = (ushort)*(byte *)puStack_54 * sVar6;
              (*DAT_060b3f44)();
              *puStack_40 = uVar7;
              uVar7 = (ushort)*pbStack_58 * local_72;
              (*DAT_060b3f44)();
              *puStack_44 = uVar7;
              *param_2 = DAT_060b3f3c | uVar5;
              *local_2c = DAT_060b3f3e | extraout_r3;
            }
            local_2c = local_2c + 0x10;
            puStack_44 = puStack_44 + 0x10;
            puStack_40 = puStack_40 + 0x10;
            local_24 = local_24 + 0x10;
            local_28 = local_28 + 0x10;
            puStack_3c = puStack_3c + 0x10;
            local_38 = local_38 + 0x10;
            local_34 = local_34 + 0x10;
            local_30 = local_30 + 0x10;
            sVar6 = *(short *)(DAT_060b3f48 + DAT_060b3f40) + 1;
            *(short *)(DAT_060b3f48 + DAT_060b3f40) = sVar6;
            param_2 = param_2 + 0x10;
            if (DAT_060b3f42 < sVar6) {
              return param_2;
            }
          }
        }
        local_5e = local_5e - 1;
        puVar8 = puVar8 + 6;
        puVar9 = puVar9 + 6;
        pbStack_58 = pbStack_58 + 0xc;
        puStack_54 = puStack_54 + 6;
        pbStack_50 = pbStack_50 + 0xc;
        puStack_4c = puStack_4c + 6;
        puVar10 = puVar10 + 6;
      } while (local_5e != 0);
    }
  }
  return param_2;
}



undefined2 * FUN_060b3f4c(int param_1,undefined2 *param_2)

{
  ushort uVar1;
  ushort *puVar2;
  short *psVar3;
  short *psVar4;
  
  *param_2 = 4;
  uVar1 = DAT_060b402c;
  puVar2 = param_2 + 2;
  *puVar2 = DAT_060b402c;
  if (*(int *)(param_1 + 0x20) != 0) {
    *puVar2 = uVar1 | 4;
  }
  if (*(byte *)(param_1 + 1) < 0x18) {
    *puVar2 = *puVar2 | DAT_060b402e;
  }
  psVar4 = (short *)(param_1 + 8);
  psVar3 = (short *)(param_1 + 0xc);
  param_2[3] = *(undefined2 *)(param_1 + 3);
  param_2[6] = *psVar4;
  param_2[7] = *psVar3;
  param_2[8] = *psVar4 + *(short *)(param_1 + 0x10);
  param_2[9] = *psVar3 + *(short *)(param_1 + 0x12);
  param_2[10] = *psVar4 + *(short *)(param_1 + 0x3c);
  param_2[0xb] = *psVar3 + *(short *)(param_1 + 0x3e);
  param_2[0xc] = *psVar4 + *(short *)(param_1 + 0x40);
  param_2[0xd] = *psVar3 + *(short *)(param_1 + 0x42);
  param_2[0xe] = (short)(*(int *)(param_1 + 0x20) >> 3);
  return param_2 + 0x10;
}



void FUN_060b4030(undefined *param_1,undefined *param_2)

{
  if (param_1 < param_2) {
    do {
      *param_1 = 0;
      param_1 = param_1 + 1;
    } while (param_1 < param_2);
  }
  return;
}



void FUN_060b4048(void)

{
  (*(code *)PTR_FUN_060b4068)(DAT_060b4064,0,(int)DAT_060b4060);
  return;
}



void FUN_060b415c(undefined4 param_1)

{
  (*(code *)PTR_FUN_060b4174)(param_1,0,0x1c);
  return;
}



void FUN_060b4178(uint param_1,undefined4 param_2)

{
  if (param_1 < 4) {
    *(undefined4 *)((int)DAT_060b4196 + param_1 * 4 + DAT_060b4198) = param_2;
  }
  return;
}



void FUN_060b419c(void)

{
  (*(code *)PTR_FUN_060b41b8)(DAT_060b41b4,0,0x10);
  return;
}



void FUN_060b41bc(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  *DAT_060b41ec =
       (param_4 * 0x1000 + param_3 * 0x100 + param_2 * 0x10 + param_1) * 0x10000 + param_5 * 0x10;
  *DAT_060b41f0 = 1;
  return;
}



void FUN_060b41f4(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)(DAT_060b421c + 6);
  *(int *)(param_1 * 4 + DAT_060b421c + 0x58) =
       (param_3 * 0x100 + param_2) * 0x10000 + param_5 * 0x100 + param_4;
  *puVar1 = 1;
  return;
}



void FUN_060b4220(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = DAT_060b4248;
  puVar2 = (undefined4 *)(PTR_DAT_060b424c + param_1 * 0x10);
  *(undefined4 *)(DAT_060b4248 + 0x28) = *puVar2;
  *(undefined4 *)(iVar1 + 0x2c) = puVar2[1];
  *(undefined4 *)(iVar1 + 0x30) = puVar2[2];
  *(undefined4 *)(iVar1 + 0x34) = puVar2[3];
  *(undefined *)(iVar1 + 4) = 1;
  return;
}



void FUN_060b4250(void)

{
  byte bVar1;
  undefined *puVar2;
  ushort uVar3;
  ushort *puVar4;
  byte *pbVar5;
  ushort *puVar6;
  int iVar7;
  int iVar8;
  byte local_38 [20];
  int iStack_24;
  
  iStack_24 = DAT_060b448c;
  local_38[0] = 0;
  local_38[1] = '\0';
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = '\0';
  local_38[5] = '\0';
  local_38[6] = '\0';
  local_38[7] = '\0';
  local_38[8] = 1;
  local_38[9] = '\x01';
  local_38[10] = 1;
  local_38[0xb] = 0;
  local_38[0xc] = '\0';
  local_38[0xd] = '\0';
  local_38[0xe] = 0;
  local_38[0xf] = 0;
  local_38[0x10] = '\x01';
  local_38[0x11] = '\x01';
  local_38[0x12] = 0;
  local_38[0x13] = 0;
  puVar4 = (ushort *)(DAT_060b448c + 0x38);
  *puVar4 = 0;
  *(undefined2 *)(DAT_060b4484 + iStack_24) = 0;
  puVar2 = PTR_FUN_060b4490;
  iVar7 = 0;
  iVar8 = DAT_060b4494;
  do {
    pbVar5 = *(byte **)(iVar8 + DAT_060b4486);
    if (pbVar5 != (byte *)0x0) {
      if ((*pbVar5 & pbVar5[1]) != 0) {
        uVar3 = (*(code *)puVar2)(1,iVar7);
        *puVar4 = *puVar4 | uVar3;
      }
      local_38[iVar7] = pbVar5[2] & 7;
      local_38[iVar7 + 4] = pbVar5[3];
      bVar1 = pbVar5[4];
      if ((bVar1 & 0x1f) != 0) {
        puVar6 = (ushort *)(iStack_24 + 0x104);
        uVar3 = (*(code *)puVar2)(1,iVar7);
        *puVar6 = *puVar6 | uVar3;
        local_38[iVar7 + 8] = 0x1f - (bVar1 & 0x1f);
      }
    }
    iVar7 = iVar7 + 1;
    iVar8 = iVar8 + 4;
  } while (iVar7 < 4);
  *(uint *)(iStack_24 + DAT_060b4488) =
       (uint)local_38[0] << 0x10 | (int)(char)local_38[1] << 0x18 | (uint)local_38[2] |
       (uint)local_38[3] << 8;
  *(uint *)(iStack_24 + 0x40) =
       ((int)(char)local_38[4] & 3U) << 0x14 | ((int)(char)local_38[0xc] & 1U) * 0x20000 |
       ((int)(char)local_38[0x10] & 1U) << 0x10 | ((int)(char)local_38[5] & 3U) << 0x1c |
       ((int)(char)local_38[0xd] & 1U) << 0x19 | ((int)(char)local_38[0x11] & 1U) << 0x18 |
       ((int)(char)local_38[6] & 1U) * 2 | ((int)(char)local_38[7] & 1U) << 5;
  *(uint *)(iStack_24 + DAT_060b448a) =
       (uint)local_38[8] << 0x10 | (int)(char)local_38[9] << 0x18 | (uint)local_38[10] |
       (uint)local_38[0xb] << 8;
  *(ushort *)(DAT_060b4484 + iStack_24) = *(ushort *)(DAT_060b4484 + iStack_24) | 0x40;
  *(undefined *)(iStack_24 + 6) = 1;
  return;
}



void FUN_060b44b4(void)

{
  undefined2 uVar1;
  undefined *puVar2;
  
  puVar2 = DAT_060b4520;
  DAT_060b4520[4] = 0;
  *puVar2 = 1;
  puVar2[1] = 0x1c;
  puVar2[2] = 0;
  *(undefined4 *)(puVar2 + 0x18) = 0;
  *(undefined4 *)(puVar2 + 8) = 0;
  *(undefined4 *)(puVar2 + 0xc) = 0;
  uVar1 = DAT_060b451c;
  *(undefined2 *)(puVar2 + 0x10) = DAT_060b451c;
  *(undefined2 *)(puVar2 + 0x12) = uVar1;
  *(undefined2 *)(puVar2 + 0x1c) = 0;
  *(undefined4 *)(puVar2 + 0x14) = 0;
  *(undefined4 *)(puVar2 + 0x20) = *(undefined4 *)PTR_PTR_DAT_060b4524;
  *(undefined4 *)(puVar2 + 0x18) = *(undefined4 *)PTR_PTR_DAT_060b4528;
  *(undefined2 *)(puVar2 + 0x24) = 0;
  *(undefined2 *)(puVar2 + 0x26) = 0;
  (*(code *)PTR_FUN_060b452c)();
  return;
}



void FUN_060b4530(void)

{
  undefined *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar1 = PTR_FUN_060b4594;
  (*(code *)PTR_FUN_060b4594)(0,DAT_060b4590,DAT_060b458c);
  (*(code *)puVar1)(1,DAT_060b4598,(int)DAT_060b4584);
  (*(code *)puVar1)(2,DAT_060b459c,(int)DAT_060b4586);
  iVar3 = (int)DAT_060b4588;
  puVar2 = (undefined4 *)(PTR_DAT_060b45a0 + 4);
  (*(code *)puVar1)(8,*(undefined4 *)PTR_DAT_060b45a0,iVar3);
  (*(code *)puVar1)(9,*puVar2,iVar3);
  (*(code *)PTR_FUN_060b45ac)(DAT_060b45a4,PTR_DAT_060b45a8,(int)DAT_060b458a);
  return;
}



void FUN_060b45b0(undefined2 *param_1,undefined2 param_2,undefined param_3)

{
  *param_1 = param_2;
  *(undefined *)(param_1 + 1) = param_3;
  return;
}



void FUN_060b45c4(short param_1,short param_2,ushort *param_3)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  ushort *puVar6;
  byte bVar7;
  int iVar8;
  
  iVar3 = DAT_060b4684;
  pbVar4 = *(byte **)PTR_DAT_060b4688;
  bVar7 = 7;
  iVar5 = param_2 * 0x50 + (int)DAT_060b467c + DAT_060b4684;
  (*(code *)PTR_FUN_060b468c)();
  uVar2 = *param_3;
  iVar5 = iVar5 + param_1 * 4;
  do {
    if ((DAT_060b4726 & uVar2) == 0) {
      return;
    }
    if (*(ushort *)PTR_DAT_060b4690 == uVar2) {
      param_3 = param_3 + 1;
      bVar7 = 0;
      puVar6 = (ushort *)PTR_DAT_060b4690;
      do {
        if (*param_3 == *puVar6) break;
        bVar7 = bVar7 + 1;
        puVar6 = puVar6 + 1;
      } while (bVar7 < 9);
      if (bVar7 == 8) {
        *(undefined *)(DAT_060b467e + iVar3) = 10;
      }
      iVar8 = iVar5;
      if (7 < bVar7) {
        bVar7 = 7;
      }
LAB_060b4678:
      param_3 = param_3 + 1;
    }
    else {
      if (*(ushort *)PTR_DAT_060b4694 == uVar2) {
        param_2 = param_2 + 1;
        param_1 = 0;
        iVar8 = iVar3 + param_2 * 0x50 + (int)DAT_060b467c;
        if (param_2 == 4) {
          iVar8 = iVar3 + DAT_060b4680;
          (*(code *)PTR_FUN_060b4698)(PTR_DAT_060b469c);
        }
        goto LAB_060b4678;
      }
      uVar2 = *param_3;
      param_3 = param_3 + 1;
      iVar8 = iVar5 + 4;
      (*(code *)PTR_FUN_060b4728)(iVar5,(int)(short)uVar2,(int)(char)bVar7);
      param_1 = param_1 + 1;
      if ((param_1 == 0x14) || ((param_1 == 0xe && (*(short *)(iVar3 + DAT_060b4722) == 7)))) {
        param_2 = param_2 + 1;
        param_1 = 0;
        iVar8 = iVar3 + param_2 * 0x50 + (int)DAT_060b4724;
      }
      if (*(short *)(iVar3 + DAT_060b4722) == 7) {
LAB_060b46f0:
        (*(code *)PTR_FUN_060b472c)();
LAB_060b46f6:
        (*(code *)PTR_FUN_060b472c)();
      }
      else {
        bVar1 = *pbVar4;
        if (bVar1 == 1) goto LAB_060b46f6;
        if ((1 < bVar1) && (bVar1 == 2)) goto LAB_060b46f0;
      }
    }
    uVar2 = *param_3;
    iVar5 = iVar8;
  } while( true );
}



void FUN_060b4730(ushort *param_1)

{
  ushort uVar1;
  undefined *puVar2;
  ushort uVar3;
  ushort *puVar4;
  int iVar5;
  int iVar6;
  char cVar7;
  
  puVar2 = PTR_FUN_060b47e8;
  cVar7 = '\a';
  iVar6 = 0;
  iVar5 = DAT_060b47ec;
  do {
    (*(code *)puVar2)(iVar5 + DAT_060b47de,iVar5 + DAT_060b47e0,0x50);
    iVar6 = iVar6 + 1;
    iVar5 = iVar5 + 0x50;
  } while (iVar6 < 3);
  (*(code *)PTR_FUN_060b47f0)(3);
  puVar2 = PTR_FUN_060b47f4;
  iVar5 = DAT_060b47ec + DAT_060b47e2;
  uVar1 = *param_1;
  uVar3 = DAT_060b47e4 & uVar1;
  iVar6 = 0;
  do {
    if ((uVar3 == 0) || (0x13 < iVar6)) {
      return;
    }
    if (*(ushort *)PTR_DAT_060b47f8 == uVar1) {
      cVar7 = '\0';
      puVar4 = (ushort *)PTR_DAT_060b47f8;
      do {
        if (param_1[1] == *puVar4) break;
        cVar7 = cVar7 + '\x01';
        puVar4 = puVar4 + 1;
      } while (cVar7 < '\a');
      param_1 = param_1 + 2;
    }
    uVar1 = *param_1;
    param_1 = param_1 + 1;
    (*(code *)puVar2)(iVar5,(int)(short)uVar1,(int)cVar7);
    iVar6 = iVar6 + 1;
    uVar1 = *param_1;
    uVar3 = DAT_060b47e4 & uVar1;
    iVar5 = iVar5 + 4;
  } while( true );
}



void FUN_060b47fc(int param_1,ushort *param_2)

{
  ushort uVar1;
  ushort uVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  uVar7 = param_1 - 1;
  (*(code *)PTR_FUN_060b48b0)();
  puVar3 = PTR_FUN_060b48b8;
  iVar5 = 0;
  iVar6 = (uVar7 & 3) * 0x50 + (int)DAT_060b48ac + DAT_060b48b4 + ((uVar7 & 4) << 2 | uVar7 & 4) * 2
  ;
  do {
    (*(code *)puVar3)(iVar6);
    puVar4 = PTR_FUN_060b48bc;
    uVar2 = DAT_060b48ae;
    iVar5 = iVar5 + 1;
    iVar6 = iVar6 + 4;
  } while (iVar5 < 10);
  iVar5 = DAT_060b48b4 + (uVar7 & 3) * 0x50 + (int)DAT_060b48ac + ((uVar7 & 4) << 2 | uVar7 & 4) * 2
  ;
  uVar1 = *param_2;
  for (iVar6 = 0; ((uVar1 & uVar2) != 0 && (iVar6 < 10)); iVar6 = iVar6 + 1) {
    uVar1 = *param_2;
    param_2 = param_2 + 1;
    (*(code *)puVar4)(iVar5,(int)(short)uVar1,7);
    uVar1 = *param_2;
    iVar5 = iVar5 + 4;
  }
  return;
}



void FUN_060b48c0(undefined4 param_1)

{
  (*(code *)PTR_FUN_060b48d8)(param_1,(int)DAT_060b48d6,7);
  return;
}



void FUN_060b48dc(int param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = PTR_FUN_060b491c;
  iVar2 = 0x14;
  iVar3 = param_1 * 0x50 + (int)DAT_060b4914 + DAT_060b4918;
  do {
    (*(code *)puVar1)(iVar3);
    iVar2 = iVar2 + -1;
    iVar3 = iVar3 + 4;
  } while (iVar2 != 0);
  return;
}



void FUN_060b4920(void)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = PTR_FUN_060b494c;
  iVar2 = 0;
  do {
    (*(code *)puVar1)(iVar2);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  return;
}



void FUN_060b4970(void)

{
  ushort uVar1;
  short sVar2;
  char *pcVar3;
  short *psVar4;
  short sVar5;
  ushort *puVar6;
  short *psVar7;
  int iVar8;
  short *psVar9;
  ushort *puVar10;
  int local_3c [4];
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 uStack_20;
  
  psVar4 = DAT_060b4a68;
  pcVar3 = DAT_060b4a64;
  sVar2 = DAT_060b4a56;
  local_3c[0] = *(int *)PTR_DAT_060b4a5c;
  local_3c[1] = *(undefined4 *)(PTR_DAT_060b4a5c + 4);
  iVar8 = 0;
  local_3c[2] = *(undefined4 *)(PTR_DAT_060b4a5c + 8);
  local_3c[3] = *(undefined4 *)(PTR_DAT_060b4a5c + 0xc);
  local_2c = *(undefined4 *)(PTR_DAT_060b4a5c + 0x10);
  local_28 = *(undefined4 *)(PTR_DAT_060b4a5c + 0x14);
  local_24 = *(undefined4 *)(PTR_DAT_060b4a5c + 0x18);
  puVar10 = DAT_060b4a60 + 1;
  uStack_20 = *(undefined4 *)(PTR_DAT_060b4a5c + 0x1c);
  psVar9 = (short *)(PTR_DAT_060b4a6c + 6);
  psVar7 = (short *)(PTR_DAT_060b4a6c + 4);
  puVar6 = DAT_060b4a60;
  do {
    uVar1 = *(ushort *)(DAT_060b4a70 + (uint)*puVar6 * 2);
    if (((*pcVar3 == '\0') || (iVar8 < local_3c[*psVar4])) || (local_3c[*psVar4] + 10 <= iVar8)) {
      sVar5 = (short)((int)((uVar1 & 3) * 0x20 + (uint)*(byte *)puVar10 * 0x80 + DAT_060b4a74) >> 3)
      ;
    }
    else {
      sVar5 = (uVar1 & 3) * 4 + sVar2;
    }
    *psVar7 = sVar5;
    psVar7 = psVar7 + 6;
    puVar10 = puVar10 + 2;
    puVar6 = puVar6 + 2;
    iVar8 = iVar8 + 1;
    *psVar9 = (uVar1 >> 2) * 0xe + DAT_060b4a58;
    psVar9 = psVar9 + 6;
  } while (iVar8 < 0x50);
  return;
}



void FUN_060b4a78(void)

{
  *DAT_060b4a88 = 1;
  return;
}



void FUN_060b4a8c(void)

{
  *DAT_060b4a9c = 0;
  return;
}



void FUN_060b4ac8(undefined2 param_1,undefined2 param_2)

{
  *DAT_060b4ad8 = param_1;
  *DAT_060b4adc = param_2;
  return;
}



undefined4 FUN_060b4ae0(void)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  short sVar6;
  int iVar7;
  
  iVar1 = DAT_060b4b9c;
  if (*DAT_060b4b98 == 2) {
    sVar6 = 1;
    *(short *)(DAT_060b4b9c + DAT_060b4b8e) = *(short *)(DAT_060b4b9c + DAT_060b4b8e) + 8;
    do {
      iVar5 = (int)DAT_060b4b90;
      pcVar3 = (char *)(iVar1 + sVar6 * 0x4c + iVar5);
      sVar6 = sVar6 + 3;
      if (*pcVar3 == '\x01') {
        *(short *)(pcVar3 + 0xc) = *(short *)(pcVar3 + 0xc) + 8;
        *(short *)(pcVar3 + 0x58) = *(short *)(pcVar3 + 0x58) + 8;
        *(short *)(pcVar3 + 0xa4) = *(short *)(pcVar3 + 0xa4) + 8;
      }
    } while (sVar6 < 8);
    iVar4 = iVar1 + iVar5;
    uVar2 = 1;
    if (0x77 < *(short *)(iVar4 + 0xc)) {
      sVar6 = 1;
      iVar7 = 0x4c;
      do {
        *(undefined *)(iVar7 + iVar1 + iVar5) = 0;
        sVar6 = sVar6 + 1;
        iVar7 = sVar6 * 0x4c;
      } while (sVar6 < 10);
      *(undefined2 *)(iVar1 + DAT_060b4b92) = 0;
      *(undefined2 *)(iVar4 + 0xc) = DAT_060b4b94;
      uVar2 = 0;
      *(undefined4 *)(iVar4 + 0x18) = *(undefined4 *)PTR_PTR_DAT_060b4ba0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



void FUN_060b4ba4(void)

{
  short sVar1;
  int iVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  short *psVar6;
  
  puVar3 = PTR_FUN_060b4c44;
  iVar2 = DAT_060b4c40;
  iVar5 = (int)DAT_060b4c3c;
  if (*(short *)(iVar5 + DAT_060b4c40) == 1) {
    do {
      (*(code *)puVar3)();
    } while (*(short *)(iVar5 + iVar2) == 1);
    iVar5 = (int)DAT_060b4c3c;
  }
  puVar4 = PTR_FUN_060b4c48;
  puVar3 = PTR_FUN_060b4c44;
  sVar1 = *(short *)(iVar5 + iVar2);
  while (sVar1 == 2) {
    (*(code *)puVar4)();
    (*(code *)puVar3)();
    sVar1 = *(short *)(iVar5 + iVar2);
  }
  (*(code *)PTR_FUN_060b4c4c)(10,0x14);
  psVar6 = (short *)(iVar2 + DAT_060b4c3e);
  sVar1 = *psVar6;
  while (0 < sVar1) {
    *psVar6 = *psVar6 + -8;
    (*(code *)PTR_FUN_060b4c44)();
    sVar1 = *psVar6;
  }
  (*(code *)PTR_FUN_060b4c50)(0,0);
  (*(code *)PTR_FUN_060b4c44)();
  return;
}



int FUN_060b4c54(int param_1)

{
  ushort uVar1;
  bool bVar2;
  short sVar3;
  int iVar4;
  undefined *puVar5;
  int iVar6;
  undefined2 *puVar7;
  int iVar8;
  undefined2 *puVar9;
  short *psVar10;
  ushort *puVar11;
  
  puVar7 = DAT_060b4da0;
  puVar5 = PTR_FUN_060b4d9c;
  iVar4 = DAT_060b4d98;
  puVar11 = (ushort *)(DAT_060b4d86 + DAT_060b4d98);
  do {
    iVar6 = (*(code *)puVar5)(0,0,(int)DAT_060b4d88);
    sVar3 = (short)param_1;
    if ((iVar6 != 0) && (*puVar11 = *puVar11 - 1, (short)*puVar11 < 0)) {
      *puVar11 = sVar3 - 1;
    }
    iVar6 = (*(code *)puVar5)(0,0,(int)DAT_060b4d8a);
    if ((iVar6 != 0) && (*puVar11 = *puVar11 + 1, param_1 <= (short)*puVar11)) {
      *puVar11 = 0;
    }
    iVar6 = (*(code *)puVar5)(0,0,(int)DAT_060b4d8c);
    if (iVar6 != 0) {
      *puVar11 = *puVar11 - 4;
      if ((short)*puVar11 < 0) {
        *puVar11 = *puVar11 + 8;
      }
      if (param_1 <= (short)*puVar11) {
        *puVar11 = sVar3 - 1;
      }
    }
    iVar6 = (*(code *)puVar5)(0,0,DAT_060b4da4);
    if (iVar6 == 0) {
LAB_060b4cf2:
      bVar2 = -1 < (short)*puVar11;
    }
    else {
      *puVar11 = *puVar11 + 4;
      uVar1 = *puVar11;
      bVar2 = -1 < (short)uVar1;
      if (param_1 <= (short)uVar1) {
        *puVar11 = uVar1 - 8;
        goto LAB_060b4cf2;
      }
    }
    if (!bVar2) {
      *puVar11 = 0;
    }
    if (param_1 <= (short)*puVar11) {
      *puVar11 = sVar3 - 1;
    }
    iVar6 = (*(code *)puVar5)(0,0,*puVar7);
    if (iVar6 != 0) {
      (*(code *)PTR_FUN_060b4da8)(iVar4 + DAT_060b4d92,iVar4 + DAT_060b4d90,(int)DAT_060b4d8e);
      iVar8 = 0;
      iVar6 = iVar4;
      do {
        puVar9 = (undefined2 *)(iVar6 + DAT_060b4d90);
        iVar6 = iVar6 + 4;
        puVar7 = (undefined2 *)
                 ((((short)(*puVar11 & 4) * 5 >> 1) + iVar8) * 4 +
                 ((int)(short)*puVar11 & 3U) * 0x50 + iVar4 + (int)DAT_060b4d94);
        iVar8 = iVar8 + 1;
        *puVar9 = *puVar7;
        puVar9[1] = puVar7[1];
      } while (iVar8 < 10);
      (*(code *)PTR_FUN_060b4dac)((int)DAT_060b4d96);
      return *(short *)(iVar4 + DAT_060b4d86) + 1;
    }
    iVar6 = (*(code *)puVar5)(0,0,*DAT_060b4e14);
    if (iVar6 != 0) {
      (*(code *)PTR_FUN_060b4e18)((int)DAT_060b4e0e);
      return 0;
    }
    psVar10 = (short *)(iVar4 + DAT_060b4e10);
    if (*psVar10 != 0) {
      iVar6 = (*(code *)PTR_FUN_060b4e1c)(2);
      if (iVar6 == 0) {
        (*(code *)PTR_FUN_060b4e20)((int)*psVar10);
      }
      *psVar10 = 0;
    }
    (*(code *)PTR_FUN_060b4e24)();
  } while( true );
}



undefined4 FUN_060b4e28(void)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  undefined *puVar4;
  undefined *puVar5;
  int iVar6;
  int iVar7;
  char cVar8;
  char *pcVar9;
  int iVar10;
  short *psVar11;
  
  puVar4 = PTR_FUN_060b4f70;
  iVar7 = DAT_060b4f6c;
  bVar3 = false;
  bVar2 = false;
  iVar10 = 9;
  do {
    iVar6 = (*(code *)puVar4)(0,0,*DAT_060b4f74);
    puVar5 = PTR_FUN_060b4f78;
    if (iVar6 != 0) {
      bVar2 = true;
    }
    iVar10 = iVar10 + -1;
    (*(code *)PTR_FUN_060b4f78)();
  } while (iVar10 != 0);
  pcVar9 = (char *)(iVar7 + DAT_060b4f58);
  cVar8 = *pcVar9 + -1;
  if (*pcVar9 == '\0') {
    bVar1 = **(short **)(iVar7 + DAT_060b4f5a) == 0x58;
    if (bVar1) {
      (*(code *)PTR_FUN_060b4f7c)(0xb,0x11,0xffffffff,0x1f,bVar1,7,7);
      *(undefined2 *)(iVar7 + DAT_060b4f5c) = DAT_060b4f5e;
      *(undefined2 *)(iVar7 + DAT_060b4f60) = DAT_060b4f62;
    }
    puVar4 = PTR_FUN_060b4f70;
    psVar11 = (short *)(iVar7 + DAT_060b4f64);
    while ((iVar10 = (*(code *)puVar4)(0,0,*DAT_060b4f74), iVar10 == 0 && (!bVar2))) {
      if (*psVar11 != 0) {
        iVar10 = (*(code *)PTR_FUN_060b4f80)(2);
        if (iVar10 == 0) {
          (*(code *)PTR_FUN_060b4f84)((int)*psVar11);
          bVar3 = true;
        }
        *psVar11 = 0;
      }
      (*(code *)PTR_FUN_060b4f78)();
    }
    *(undefined *)(iVar7 + DAT_060b4f66) = 0;
    (*(code *)PTR_FUN_060b4f88)((int)DAT_060b4f68);
    puVar4 = PTR_FUN_060b4f70;
    iVar7 = (*(code *)PTR_FUN_060b4f70)(0,0,*DAT_060b4f8c);
    if (iVar7 != 0) {
      return 1;
    }
    iVar7 = (*(code *)puVar4)(0,0,(int)DAT_060b4f6a);
    if (iVar7 != 0) {
      return 2;
    }
    if (bVar3) {
      *(undefined4 *)PTR_DAT_060b4f90 = 1;
    }
    else {
      *(undefined4 *)PTR_DAT_060b4f90 = 0;
    }
  }
  else {
    *pcVar9 = cVar8;
    if (cVar8 != '\0') {
      do {
        (*(code *)puVar5)();
        cVar8 = *pcVar9;
        *pcVar9 = cVar8 + -1;
      } while ((char)(cVar8 + -1) != '\0');
      return 0;
    }
  }
  return 0;
}



void FUN_060b5238(short param_1,short param_2)

{
  *DAT_060b5258 = -param_1;
  *DAT_060b525c = -param_2;
  (*(code *)PTR_FUN_060b5260)();
  return;
}



void FUN_060b5264(undefined2 param_1,undefined2 param_2)

{
  *DAT_060b5274 = param_1;
  *DAT_060b5278 = param_2;
  return;
}



void FUN_060b527c(short param_1,undefined2 param_2,short param_3,undefined2 param_4)

{
  *DAT_060b52a0 = param_1 * 2;
  *DAT_060b52a4 = param_3 * 2;
  *DAT_060b52a8 = param_2;
  *DAT_060b52ac = param_4;
  *DAT_060b52b0 = 1;
  return;
}



void FUN_060b52b4(short param_1,undefined2 param_2,short param_3,undefined2 param_4)

{
  *DAT_060b52d8 = param_1 * 2;
  *DAT_060b52dc = param_3 * 2;
  *DAT_060b52e0 = param_2;
  *DAT_060b52e4 = param_4;
  *DAT_060b52e8 = 1;
  return;
}



void FUN_060b52ec(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  *DAT_060b5304 = param_1;
  *DAT_060b5308 = param_3;
  *DAT_060b530c = param_2;
  *DAT_060b5310 = param_4;
  return;
}



void FUN_060b5314(int param_1,int param_2,int param_3,int param_4)

{
  (*(code *)PTR_FUN_060b5364)(param_1 + -2,param_2 + -2,param_3 + 1,param_4 + 1);
  (*(code *)PTR_FUN_060b5368)(param_1,param_2,param_3 + -1,param_4 + -1);
  (*(code *)PTR_FUN_060b536c)(param_1,param_2,param_3 + -1,param_4 + -1);
  return;
}



void FUN_060b5370(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  (*(code *)PTR_FUN_060b541c)(0x26,0xe,(int)DAT_060b5414,(int)DAT_060b5412);
  iVar1 = 0x28;
  if (0x27 < param_1 + -0x20) {
    iVar1 = param_1 + -0x20;
  }
  iVar2 = 0x10;
  if (0xf < param_2 + -0x1a) {
    iVar2 = param_2 + -0x1a;
  }
  iVar3 = (int)DAT_060b5416;
  if (param_1 + 0x20 <= (int)DAT_060b5416) {
    iVar3 = param_1 + 0x20;
  }
  iVar4 = (int)DAT_060b5418;
  if (param_2 + 0x1a <= (int)DAT_060b5418) {
    iVar4 = param_2 + 0x1a;
  }
  (*(code *)PTR_FUN_060b5420)(iVar1,iVar2,iVar3,iVar4);
  iVar1 = 0x28;
  if (0x27 < param_1 + -0x24) {
    iVar1 = param_1 + -0x24;
  }
  iVar2 = 0x10;
  if (0xf < param_2 + -0x1e) {
    iVar2 = param_2 + -0x1e;
  }
  iVar3 = (int)DAT_060b5416;
  if (param_1 + 0x24 <= (int)DAT_060b5416) {
    iVar3 = param_1 + 0x24;
  }
  iVar4 = (int)DAT_060b5418;
  if (param_2 + 0x1e <= (int)DAT_060b5418) {
    iVar4 = param_2 + 0x1e;
  }
  (*(code *)PTR_FUN_060b5424)(iVar1,iVar2,iVar3,iVar4);
  return;
}



void FUN_060b5428(short param_1,short param_2,char param_3,undefined param_4,undefined param_5,
                 short param_6,short param_7)

{
  undefined2 uVar1;
  int iVar2;
  undefined *puVar3;
  
  iVar2 = DAT_060b5508;
  puVar3 = (undefined *)(param_1 * 0x4c + (int)DAT_060b5500 + DAT_060b5508);
  (*(code *)PTR_FUN_060b550c)(puVar3,0,0x4c);
  puVar3[4] = param_3 * '\x10' + '\x10';
  *puVar3 = 1;
  puVar3[1] = param_4;
  puVar3[3] = param_5;
  uVar1 = DAT_060b5504;
  *(undefined2 *)(puVar3 + 8) = *(undefined2 *)(iVar2 + DAT_060b5502);
  *(undefined2 *)(puVar3 + 0xc) = *(undefined2 *)(iVar2 + DAT_060b5506);
  *(undefined2 *)(puVar3 + 0x10) = uVar1;
  *(undefined2 *)(puVar3 + 0x12) = uVar1;
  iVar2 = *(int *)(PTR_DAT_060b5510 + param_7 * 4) + DAT_060b5514;
  if (iVar2 < 0) {
    iVar2 = iVar2 + 7;
  }
  *(short *)(puVar3 + 0x1c) = (short)(iVar2 >> 3);
  iVar2 = *(int *)(PTR_DAT_060b5518 + param_6 * 4);
  *(int *)(puVar3 + 0x20) = iVar2;
  *(undefined4 *)(puVar3 + 0x14) = *(undefined4 *)(param_2 * 4 + iVar2 + 0x10);
  return;
}



void FUN_060b551c(short param_1,short param_2,short param_3,short param_4,short param_5)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (int)param_4;
  iVar1 = 0;
  if (0 < **(short **)(PTR_DAT_060b5598 + iVar2 * 4)) {
    do {
      (*(code *)PTR_FUN_060b559c)
                ((int)(short)((short)iVar1 + 0xc),(int)(short)iVar1,(int)param_1,(int)param_2,
                 (int)param_3,iVar2,(int)param_5);
      iVar1 = iVar1 + 1;
    } while (iVar1 < **(short **)(PTR_DAT_060b5598 + iVar2 * 4));
  }
  return;
}



void FUN_060b55a0(void)

{
  undefined *puVar1;
  int *piVar2;
  byte *pbVar3;
  int iVar4;
  
  (*(code *)PTR_FUN_060b5630)();
  (*(code *)PTR_FUN_060b5634)();
  (*(code *)PTR_FUN_060b5638)();
  (*(code *)PTR_FUN_060b563c)();
  (*(code *)PTR_FUN_060b5640)();
  (*(code *)PTR_FUN_060b5644)();
  (*(code *)PTR_FUN_060b5648)();
  (*(code *)PTR_FUN_060b564c)(1);
  (*(code *)PTR_FUN_060b5650)();
  puVar1 = PTR_DAT_060b5654;
  *(undefined4 *)PTR_DAT_060b5654 = 0;
  *(undefined4 *)PTR_DAT_060b5658 = 0;
  piVar2 = DAT_060b565c;
  iVar4 = *(int *)puVar1;
  while (iVar4 == 0) {
    iVar4 = *(int *)puVar1;
  }
  do {
  } while (*(int *)PTR_DAT_060b5658 == 0);
  (*(code *)PTR_FUN_060b5660)();
  pbVar3 = DAT_060b5664;
  (*(code *)PTR_FUN_060b5668)(DAT_060b5664);
  if ((*pbVar3 & 0xf) == 6) {
    (*(code *)*DAT_060b566c)();
  }
  *piVar2 = *piVar2 + 1;
  return;
}



void FUN_060b5670(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_060b569c;
  if (param_1 == 1) {
    *(ushort *)(DAT_060b569a + DAT_060b569c) = *(ushort *)(DAT_060b569a + DAT_060b569c) | 0x40;
  }
  else {
    *(undefined2 *)(DAT_060b569c + DAT_060b569a) = 0;
  }
  *(undefined *)(iVar1 + 6) = 1;
  return;
}



void FUN_060b56a0(int param_1,undefined param_2,undefined param_3,short param_4,short param_5,
                 short param_6,short param_7,short param_8,short param_9,short param_10,
                 short param_11)

{
  int iVar1;
  undefined *extraout_r2;
  undefined *extraout_r3;
  
  param_6 = param_6 - param_4;
  param_8 = param_8 - param_4;
  param_10 = param_10 - param_4;
  *(undefined *)(param_1 * 0x4c + (int)DAT_060b5780 + DAT_060b5788 + 4) = param_2;
  (*DAT_060b578c)();
  *extraout_r3 = param_2;
  *extraout_r2 = 2;
  extraout_r2[1] = param_3;
  extraout_r2[2] = 0;
  *(undefined4 *)(extraout_r2 + 0x18) = 0;
  iVar1 = DAT_060b5788;
  *(short *)(extraout_r2 + 8) = *(short *)(DAT_060b5782 + DAT_060b5788) + param_4;
  *(short *)(extraout_r2 + 0xc) = *(short *)(DAT_060b5784 + iVar1) + param_5;
  *(short *)(extraout_r2 + 0x10) = param_6;
  *(short *)(extraout_r2 + 0x12) = param_7 - param_5;
  *(short *)(extraout_r2 + 0x3c) = param_8;
  *(short *)(extraout_r2 + 0x3e) = param_9 - param_5;
  *(short *)(extraout_r2 + 0x40) = param_10;
  *(short *)(extraout_r2 + 0x42) = param_11 - param_5;
  *(undefined2 *)(extraout_r2 + 0x1c) = 0;
  *(undefined4 *)(extraout_r2 + 0x20) = 0;
  *(undefined4 *)(extraout_r2 + 0x14) = 0;
  *(undefined4 *)(extraout_r2 + 0x18) = 0;
  *(undefined2 *)(extraout_r2 + 0x24) = 0;
  *(undefined2 *)(extraout_r2 + 0x26) = 0;
  *(undefined4 *)(extraout_r2 + 0x20) = 0;
  return;
}



void FUN_060b5790(int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
                 undefined2 param_5)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)((param_1 + 0xc) * 8 + DAT_060b57c8);
  *(undefined2 **)(param_1 * 0x4c + (int)DAT_060b57c2 + DAT_060b57c4 + 0x20) = puVar1;
  *puVar1 = param_2;
  puVar1[1] = param_3;
  puVar1[2] = param_4;
  puVar1[3] = param_5;
  return;
}



void FUN_060b57cc(void)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  short *psVar5;
  short *psVar6;
  
  psVar5 = DAT_060b5928;
  iVar2 = DAT_060b5924;
  sVar4 = *DAT_060b5928;
  pcVar1 = (code *)PTR_FUN_060b5930;
  while (PTR_FUN_060b5930 = pcVar1, sVar4 < 0x80) {
    *psVar5 = *psVar5 + 8;
    (*(code *)PTR_FUN_060b592c)();
    pcVar1 = (code *)PTR_FUN_060b5930;
    sVar4 = *psVar5;
  }
  if ((*(char *)(iVar2 + DAT_060b5906) != '\0') && (*(char *)(iVar2 + DAT_060b5908) == '\x01')) {
    psVar6 = (short *)(iVar2 + DAT_060b590a);
    psVar5 = (short *)(iVar2 + DAT_060b590c);
    while (iVar3 = (*pcVar1)(0,1,*DAT_060b5934), iVar3 != 0) {
      iVar3 = (*pcVar1)(0,1,(int)DAT_060b590e);
      if (iVar3 != 0) {
        *psVar6 = *psVar6 + -2;
      }
      iVar3 = (*pcVar1)(0,1,DAT_060b5938);
      if (iVar3 != 0) {
        *psVar6 = *psVar6 + 2;
      }
      iVar3 = (*pcVar1)(0,1,(int)DAT_060b5910);
      if (iVar3 != 0) {
        *psVar5 = *psVar5 + -2;
      }
      iVar3 = (*pcVar1)(0,1,(int)DAT_060b5912);
      if (iVar3 != 0) {
        *psVar5 = *psVar5 + 2;
      }
      sVar4 = *psVar6;
      if (sVar4 < -0x78) {
        *psVar6 = -0x78;
        sVar4 = *psVar6;
      }
      if (0x77 < sVar4) {
        *psVar6 = 0x77;
      }
      sVar4 = *psVar5;
      if (sVar4 < -0x40) {
        *psVar5 = -0x40;
        sVar4 = *psVar5;
      }
      if (0x3f < sVar4) {
        *psVar5 = 0x3f;
      }
      *(short *)(DAT_060b5916 + iVar2) = *psVar6 + *(short *)(DAT_060b5914 + iVar2) + 0x5a;
      *(short *)(DAT_060b591a + iVar2) = *psVar5 + *(short *)(DAT_060b5918 + iVar2) + 0x28;
      (*(code *)PTR_FUN_060b593c)((int)*psVar6 + (int)DAT_060b591c,*psVar5 + 0x50);
      (*(code *)PTR_FUN_060b592c)();
    }
  }
  if (*(short *)(DAT_060b591e + iVar2) == 1) {
    *(short *)(DAT_060b591e + iVar2) = 0;
  }
  (*(code *)PTR_FUN_060b5940)(0,(int)DAT_060b5920);
  (*(code *)PTR_FUN_060b592c)();
  return;
}



void FUN_060b5944(short param_1,short param_2,char *param_3)

{
  char cVar1;
  short *psVar2;
  
  if (*DAT_060b5984 != '\x01') {
    psVar2 = (short *)(param_2 * 0x80 + param_1 * 2 + DAT_060b5988);
    cVar1 = *param_3;
    while (cVar1 != '\0') {
      cVar1 = *param_3;
      param_3 = param_3 + 1;
      *psVar2 = (short)cVar1;
      psVar2 = psVar2 + 1;
      cVar1 = *param_3;
    }
  }
  return;
}



void FUN_060b59a0(undefined4 param_1,undefined4 param_2)

{
  undefined auStack_6c [104];
  
  (*(code *)PTR_FUN_060b59cc)(auStack_6c,PTR_s_ERROR__s___d_060b59c8,param_1,param_2);
  (*(code *)PTR_FUN_060b59d0)(1,0x1b,auStack_6c);
  return;
}



void FUN_060b59dc(void)

{
  char cVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = DAT_060b5a78;
  if (*DAT_060b5a74 == '\0') {
    *DAT_060b5a74 = 'c';
    puVar2 = PTR_FUN_060b5a7c;
    (*(code *)PTR_FUN_060b5a7c)(0x11);
    (*(code *)puVar2)(0x10);
    (*(code *)puVar2)(0xe);
    (*(code *)puVar2)(0xf);
    (*(code *)PTR_FUN_060b5a80)(0,0);
    cVar1 = *(char *)(iVar4 + 8);
    if ((cVar1 == '\0') || ((cVar1 == '\x01' && (*(byte *)(iVar4 + 10) < 3)))) {
      (*(code *)*DAT_060b5a84)();
    }
    (*(code *)PTR_FUN_060b5a88)();
    uVar3 = (*(code *)PTR_FUN_060b5a90)(PTR_s_A_BIN_060b5a8c);
    iVar4 = (*(code *)PTR_FUN_060b5a9c)(uVar3,0,DAT_060b5a98,DAT_060b5a94);
    if (iVar4 < 0) {
      (*(code *)*DAT_060b5a84)();
    }
    (**(code **)PTR_DAT_060b5aa0)();
  }
  return;
}



void FUN_060b5aa4(void)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = PTR_FUN_060b5afc;
  iVar2 = (*(code *)PTR_FUN_060b5afc)(0,1,(int)DAT_060b5af2);
  if ((((iVar2 != 0) && (iVar2 = (*(code *)puVar1)(0,1,(int)DAT_060b5af4), iVar2 != 0)) &&
      (iVar2 = (*(code *)puVar1)(0,1,(int)DAT_060b5af6), iVar2 != 0)) &&
     (iVar2 = (*(code *)puVar1)(0,0,(int)DAT_060b5af8), iVar2 != 0)) {
    (*(code *)PTR_FUN_060b5b00)();
  }
  return;
}



void FUN_060b5b1c(void)

{
  (*(code *)PTR_FUN_060b5b58)(DAT_060b5b54,0,(int)DAT_060b5b50);
  *DAT_060b5b5c = 1;
  *DAT_060b5b60 = 1;
  *DAT_060b5b64 = 0;
  *DAT_060b5b68 = 7;
  (*(code *)PTR_FUN_060b5b6c)(2);
  return;
}



undefined4 FUN_060b64e4(int param_1)

{
  undefined4 uVar1;
  undefined2 *puVar2;
  
  puVar2 = DAT_060b6538;
  uVar1 = *(undefined4 *)(param_1 + 2);
  DAT_060b6538[1] = *DAT_060b6538;
  puVar2[5] = 0;
  puVar2[0x12] = 0;
  puVar2[0x11] = 0;
  if (*DAT_060b653c == 0) {
    puVar2[0xf] = 0;
  }
  puVar2[0x10] = 0;
  return uVar1;
}



short * FUN_060b6924(short *param_1)

{
  undefined *puVar1;
  int iVar2;
  
  iVar2 = DAT_060b699c;
  puVar1 = PTR_DAT_060b6998;
  *(undefined4 *)(PTR_DAT_060b6994 + *param_1 * 8) =
       *(undefined4 *)(PTR_DAT_060b6998 + param_1[1] * 4);
  if (*param_1 < 6) {
    *(undefined4 *)(PTR_DAT_060b69a0 + *param_1 * 8) = *(undefined4 *)(puVar1 + param_1[1] * 4);
  }
  if (param_1[2] != 0) {
    (*(code *)PTR_FUN_060b69a8)(PTR_DAT_060b69a4);
    *(undefined *)(iVar2 + 0x17) = 1;
  }
  return param_1 + 3;
}



int FUN_060b6a74(int param_1)

{
  *DAT_060b6a88 = 1;
  return param_1 + -2;
}



void FUN_060b6ab8(void)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  undefined2 uVar4;
  char cVar5;
  short *extraout_r3;
  short *psVar6;
  short *extraout_r3_00;
  short sVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  
  psVar6 = DAT_060b6afc;
  iVar1 = DAT_060b6af8;
  sVar7 = *DAT_060b6afc;
  *DAT_060b6afc = sVar7 + 1;
  if (2 < (short)(sVar7 + 1)) {
    *psVar6 = 0;
  }
  if (*(short *)(iVar1 + DAT_060b6af4) == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = *DAT_060b6b04;
  }
  *(undefined2 *)(DAT_060b6b00 + *psVar6 * 2) = uVar4;
  psVar2 = DAT_060b6c60;
  psVar6 = DAT_060b6c5c;
  *DAT_060b6c60 = *DAT_060b6c5c + DAT_060b6c5c[1] + DAT_060b6c5c[2];
  if ((psVar6[(int)*DAT_060b6c64 + 2U & 3] == 0) && (sVar7 = psVar6[*DAT_060b6c64], sVar7 != 0)) {
    *psVar2 = sVar7 * 3;
  }
  iVar10 = (int)*DAT_060b6c60 * (int)*(short *)(iVar1 + DAT_060b6c52);
  if (iVar10 < 0) {
    iVar10 = iVar10 + 0x7f;
  }
  sVar7 = (short)iVar10;
  (*DAT_060b6c68)();
  *extraout_r3 = sVar7;
  iVar10 = 1;
  if (0x60 < *extraout_r3) {
    *extraout_r3 = 0x60;
  }
  iVar9 = 0x4c;
  do {
    pcVar8 = (char *)(iVar1 + DAT_060b6c54 + iVar9);
    if (*pcVar8 != '\0') {
      iVar3 = (*(code *)PTR_FUN_060b6c6c)();
      if ((iVar3 < 0x40) && (pcVar8[0x4c] == '\0')) {
        pcVar8[0x4f] = (char)DAT_060b6c56;
        pcVar8[100] = '\0';
        pcVar8[0x65] = '\0';
        pcVar8[0x66] = '\0';
        pcVar8[0x67] = '\0';
        pcVar8[0x70] = '\0';
        pcVar8[0x71] = '\0';
        pcVar8[0x72] = '\0';
        pcVar8[0x73] = '\0';
        pcVar8[0x4c] = '\x01';
      }
      if (*extraout_r3 == 0) {
        cVar5 = '\0';
      }
      else {
        psVar6 = (short *)(pcVar8 + 0xd4);
        iVar3 = 0;
        if (*psVar6 != *(short *)(DAT_060b6c58 + iVar1)) {
          do {
            if (7 < iVar3) break;
            psVar6 = psVar6 + 1;
            iVar3 = iVar3 + 1;
          } while (*psVar6 != *(short *)(DAT_060b6c58 + iVar1));
        }
        if (iVar3 == 8) goto LAB_060b6c34;
        pcVar8[0x9b] = (char)DAT_060b6c56;
        pcVar8[0xb0] = '\0';
        pcVar8[0xb1] = '\0';
        pcVar8[0xb2] = '\0';
        pcVar8[0xb3] = '\0';
        iVar3 = (int)*extraout_r3 * (int)**(short **)(pcVar8 + 0xac);
        if (iVar3 < 0) {
          iVar3 = iVar3 + 0x7f;
        }
        sVar7 = (short)iVar3;
        (*DAT_060b6c68)();
        *extraout_r3_00 = sVar7;
        if ((*extraout_r3_00 == 0) && (10 < *extraout_r3)) {
          *extraout_r3_00 = 1;
        }
        pcVar8[0xbe] = '\0';
        pcVar8[0xbf] = '\0';
        cVar5 = '\x01';
      }
      pcVar8[0x98] = cVar5;
    }
LAB_060b6c34:
    iVar9 = iVar9 + DAT_060b6c5a;
    iVar10 = iVar10 + 3;
    if (9 < iVar10) {
      return;
    }
  } while( true );
}



void FUN_060b6f20(undefined2 param_1,undefined2 param_2)

{
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  
  local_c = 1;
  local_10 = param_1;
  local_e = param_2;
  (*(code *)PTR_FUN_060b6f50)(&local_10);
  return;
}



void FUN_060b8148(void)

{
  int iVar1;
  undefined *puVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  short *psVar7;
  int *piVar8;
  
  iVar1 = DAT_060b820c;
  if (*DAT_060b8208 != 0) {
    piVar8 = (int *)(DAT_060b820c + DAT_060b81fe);
    psVar7 = *(short **)(DAT_060b820c + DAT_060b8200);
    if (*(short *)piVar8 != 0) {
      *(short *)piVar8 = *(short *)piVar8 + -1;
    }
    (*(code *)PTR_FUN_060b8210)();
    (*(code *)PTR_FUN_060b8214)();
    *(undefined2 *)(iVar1 + DAT_060b8202) = 0;
    *DAT_060b8218 = 0;
    puVar2 = PTR_PTR_FUN_060b8220;
    if (*(char *)(iVar1 + DAT_060b8204) == '\0') {
      uVar6 = (uint)*psVar7;
      uVar5 = (uint)DAT_060b8206;
      if (uVar6 != uVar5) {
        iVar4 = *piVar8;
        while (iVar4 == 0) {
          if (((int)uVar6 < 0) || (0x6b < (uVar6 & 0xffff))) {
            pcVar3 = *(code **)puVar2;
          }
          else {
            pcVar3 = *(code **)(puVar2 + uVar6 * 4);
          }
          psVar7 = (short *)(*pcVar3)(psVar7 + 1);
          uVar6 = (uint)*psVar7;
          if (uVar6 == uVar5) break;
          iVar4 = *(int *)(iVar1 + DAT_060b81fe);
        }
      }
    }
    else {
      (*(code *)PTR_FUN_060b821c)();
    }
    *DAT_060b8218 = 1;
    *(short **)(iVar1 + DAT_060b8200) = psVar7;
  }
  return;
}



void FUN_060b8224(undefined4 param_1)

{
  int iVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined *puVar4;
  undefined2 *puVar5;
  
  iVar1 = DAT_060b8294;
  puVar4 = (undefined *)(DAT_060b8294 + 1);
  puVar5 = *(undefined2 **)(DAT_060b8294 + 0x18);
  *puVar4 = 0x14;
  *puVar5 = 0x50;
  (*(code *)PTR_FUN_060b8298)();
  puVar3 = (undefined2 *)(iVar1 + 8);
  *puVar3 = 0x20;
  puVar2 = (undefined2 *)(iVar1 + 0xc);
  *puVar2 = 0xffa8;
  (*(code *)PTR_FUN_060b829c)(0,0,param_1);
  (*(code *)PTR_FUN_060b82a0)();
  (*(code *)PTR_FUN_060b82a4)();
  *puVar3 = 0;
  *puVar2 = DAT_060b8290;
  *puVar4 = 0x1c;
  *puVar5 = 0x58;
  return;
}



void FUN_060b85fc(int param_1)

{
  int iVar1;
  uint *puVar2;
  undefined2 uVar3;
  undefined auStack_28 [24];
  
  iVar1 = DAT_060b863c;
  if (param_1 == 0x56) {
    param_1 = 0xe;
  }
  if (param_1 - 0xeU < 6) {
    if (param_1 == 0xe) {
      *(undefined2 *)(DAT_060b8638 + DAT_060b863c) = 0;
    }
    (*(code *)PTR_FUN_060b8640)(param_1);
  }
  else {
    uVar3 = (undefined2)param_1;
    if ((uint)(param_1 + DAT_060b876e) < 0x3a) {
      *(undefined2 *)(DAT_060b863c + DAT_060b8770) = uVar3;
      (*(code *)PTR_FUN_060b8790)(auStack_28,PTR_s_SEQ_NO__03x_060b878c,param_1);
      (*(code *)PTR_FUN_060b8794)(2,10,auStack_28);
      (*(code *)PTR_FUN_060b8798)(param_1);
      puVar2 = DAT_060b879c;
      if (((*DAT_060b879c & 0xff) - 1 != (int)*(short *)(iVar1 + DAT_060b8772)) &&
         ((*DAT_060b879c & 0xff) != 1)) {
        (*(code *)PTR_FUN_060b87a0)(8);
        (*(code *)PTR_FUN_060b87a4)((*puVar2 & 0xff) - 1);
      }
      *DAT_060b879c = *DAT_060b879c & DAT_060b87a8 | (int)DAT_060b8774;
    }
    if (((uint)(DAT_060b8776 + param_1) <= (uint)(int)DAT_060b8778) &&
       (((param_1 != *(short *)(iVar1 + DAT_060b877a) || (param_1 == DAT_060b877c)) ||
        (param_1 == DAT_060b877e)))) {
      (*(code *)PTR_FUN_060b8790)(auStack_28,PTR_s_XA_NO__04x_060b87ac,param_1);
      (*(code *)PTR_FUN_060b87a0)(1);
      *(undefined2 *)(DAT_060b8780 + iVar1) = 2;
      (*(code *)PTR_FUN_060b8798)(param_1);
      *(undefined2 *)(DAT_060b877a + iVar1) = uVar3;
      *(undefined4 *)(DAT_060b8782 + iVar1) = 0;
    }
    if ((uint)(param_1 + DAT_060b8784) < 0x31) {
      (*(code *)PTR_FUN_060b8790)(auStack_28,PTR_s_vag_NO__03x_060b87b0,param_1);
      (*(code *)PTR_FUN_060b8794)(2,0xc,auStack_28);
      (*(code *)PTR_FUN_060b8798)(param_1);
    }
    if ((uint)(param_1 + DAT_060b8786) < 0x48) {
      (*(code *)PTR_FUN_060b8798)(param_1);
    }
    if ((uint)(param_1 + DAT_060b8788) <= (uint)(int)DAT_060b878a) {
      (*(code *)PTR_FUN_060b8790)(auStack_28,PTR_s_XA_NO__04x_060b87ac,param_1);
      (*(code *)PTR_FUN_060b8794)(2,0xb,auStack_28);
      (*(code *)PTR_FUN_060b87a0)(1);
      *(undefined2 *)(DAT_060b8780 + iVar1) = 1;
      (*(code *)PTR_FUN_060b8798)(param_1);
      *(undefined2 *)(DAT_060b877a + iVar1) = uVar3;
    }
  }
  return;
}



void FUN_060b89f8(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char acStack_5c [32];
  char acStack_3c [36];
  
  puVar3 = PTR_FUN_060b8abc;
  iVar2 = DAT_060b8ab4;
  (*(code *)PTR_FUN_060b8abc)(acStack_5c,PTR_DAT_060b8ab8,0x20);
  (*(code *)puVar3)(acStack_3c,PTR_DAT_060b8ac0,0x20);
  if (param_1 == DAT_060b8aaa) {
    cVar1 = acStack_5c[param_2];
    if (((int)*(short *)(DAT_060b8aac + iVar2) != (int)cVar1) && (cVar1 != -1)) {
      (*(code *)PTR_FUN_060b8ac4)(8);
      (*(code *)PTR_FUN_060b8ac8)((int)cVar1);
    }
    iVar4 = (int)DAT_060b8aae;
    if ((*(short *)(iVar2 + iVar4) != param_3) && (iVar6 = (int)acStack_3c[param_3], iVar6 != -1)) {
      (*(code *)PTR_FUN_060b8ad0)(PTR_s_vag_file_change_060b8acc,iVar6);
      (*(code *)PTR_FUN_060b8ac4)(8);
      iVar5 = (int)DAT_060b8ab0;
      *(undefined *)(iVar2 + iVar5) = 8;
      (*(code *)PTR_FUN_060b8ad4)(iVar6 + DAT_060b8ab2);
      *(undefined *)(iVar2 + iVar5) = 0;
      *(short *)(iVar2 + iVar4) = (short)param_3;
    }
  }
  return;
}



void FUN_060b904c(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)PTR_FUN_060b907c)(param_1 + *DAT_060b9078);
  (*(code *)PTR_FUN_060b9084)(PTR_s_<<<<__s_>>>>_060b9080,uVar1);
  (*(code *)PTR_FUN_060b9088)(uVar1);
  return;
}



uint FUN_060b908c(void)

{
  uint uVar1;
  
  uVar1 = *(int *)PTR_DAT_060b90ac * DAT_060b90b0 + (int)DAT_060b90a8;
  *(uint *)PTR_DAT_060b90ac = uVar1;
  return uVar1 >> 0x10 & 0xff;
}



undefined FUN_060b90b4(void)

{
  undefined uVar1;
  
  uVar1 = (*(code *)PTR_FUN_060b90c8)();
  return uVar1;
}



uint FUN_060b90cc(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  
  puVar1 = PTR_FUN_060b9104;
  uVar2 = (*(code *)PTR_FUN_060b9104)();
  uVar3 = (*(code *)puVar1)(param_1,param_2);
  return uVar3 & 0xff | (uVar2 & 0xff) << 8;
}



uint FUN_060b9108(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  
  puVar1 = PTR_FUN_060b9140;
  uVar2 = (*(code *)PTR_FUN_060b9140)();
  uVar3 = (*(code *)puVar1)(param_1,param_2);
  return (uVar2 & 0xffff) << 8 | uVar3 & 0xffff;
}



void FUN_060b9144(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)PTR_FUN_060b9160)(param_2,param_3,1,param_1);
  return;
}



void FUN_060b918c(uint param_1)

{
  short sVar1;
  short sVar2;
  short sVar3;
  undefined *puVar4;
  undefined *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined2 uVar10;
  undefined2 uVar11;
  undefined4 uVar9;
  int iVar12;
  int iVar13;
  int iVar14;
  short sStack_26;
  
  puVar5 = PTR_s_0123456789ABCDEF_060b9384;
  puVar4 = PTR_DAT_060b9380;
  PTR_DAT_060b9380[9] = PTR_s_0123456789ABCDEF_060b9384[(int)param_1 >> 4];
  puVar4[10] = puVar5[param_1 & 0xf];
  iVar6 = DAT_060b9388;
  sStack_26 = (short)param_1;
  if (param_1 != 5) {
    *(short *)(DAT_060b9350 + DAT_060b9388) = sStack_26;
  }
  *(undefined2 *)(DAT_060b9352 + iVar6) = 0;
  if (((param_1 - 6 < 2) && (*(short *)(iVar6 + DAT_060b9354) == 0)) || (param_1 == 5)) {
    (*(code *)PTR_FUN_060b9390)(DAT_060b938c,iVar6 + DAT_060b9356,(int)DAT_060b9358);
    *(undefined2 *)(DAT_060b935a + iVar6) = 0;
    (*(code *)PTR_FUN_060b9394)(iVar6 + DAT_060b935c,0,0xc);
    *(undefined2 *)(DAT_060b9354 + iVar6) = *(undefined2 *)(DAT_060b935e + iVar6);
    *(undefined4 *)(DAT_060b9360 + iVar6) = *(undefined4 *)(DAT_060b9362 + iVar6);
    *(undefined2 *)(DAT_060b9364 + iVar6) = *(undefined2 *)(DAT_060b9366 + iVar6);
    *(undefined2 *)(DAT_060b9368 + iVar6) = *(undefined2 *)(DAT_060b936a + iVar6);
  }
  iVar12 = param_1 * 4;
  uVar8 = (*(code *)PTR_FUN_060b93a0)((int)*(short *)(PTR_DAT_060b9398 + iVar12),PTR_DAT_060b939c);
  puVar5 = PTR_FUN_060b93a4;
  puVar4 = PTR_DAT_060b9380;
  uVar10 = (*(code *)PTR_FUN_060b93a4)(uVar8,PTR_DAT_060b9380);
  uVar11 = (*(code *)puVar5)(uVar8,puVar4);
  puVar5 = PTR_FUN_060b93ac;
  (*(code *)PTR_FUN_060b93ac)(uVar8,*DAT_060b93a8,uVar10,puVar4);
  (*(code *)puVar5)(uVar8,*DAT_060b93b0,uVar11,puVar4);
  puVar7 = DAT_060b93b4;
  uVar9 = (*(code *)PTR_FUN_060b93b8)(uVar8,puVar4);
  *puVar7 = uVar9;
  puVar4 = PTR_FUN_060b93bc;
  (*(code *)PTR_FUN_060b93bc)(uVar8);
  uVar8 = (*(code *)PTR_FUN_060b93a0)((int)(short)(sStack_26 + 0x3c),PTR_DAT_060b939c);
  (*(code *)PTR_FUN_060b93c8)
            (DAT_060b93c4,1,
             *(int *)(PTR_DAT_060b93c0 + iVar12) - *(int *)(PTR_DAT_060b93c0 + iVar12 + -4),uVar8);
  (*(code *)puVar4)(uVar8);
  iVar14 = 0;
  iVar13 = (int)DAT_060b936c;
  iVar12 = iVar6;
  do {
    *(undefined4 *)(iVar13 + iVar12) = 0;
    iVar14 = iVar14 + 1;
    iVar12 = iVar12 + 4;
  } while (iVar14 < 0x20);
  *(undefined4 *)(DAT_060b936e + iVar6) = DAT_060b93cc;
  *(undefined4 *)(DAT_060b9362 + iVar6) = DAT_060b93c4;
  *(undefined2 *)(DAT_060b9370 + iVar6) = 0;
  *(undefined2 *)(DAT_060b9372 + iVar6) = 0;
  iVar12 = (int)DAT_060b935e;
  iVar13 = (int)DAT_060b9374;
  iVar14 = (int)DAT_060b9352;
  *(short *)(iVar6 + iVar12) = *(short *)(iVar13 + iVar6);
  *(undefined2 *)(iVar14 + iVar6) = 1;
  if (*(short *)(iVar13 + iVar6) == 0) goto LAB_060b9502;
  if (*(char *)(iVar6 + DAT_060b9376) != '\0') {
    (*(code *)PTR_FUN_060b93d0)(0x12);
  }
  iVar14 = (int)*(short *)(DAT_060b936a + iVar6);
  iVar13 = (int)DAT_060b937a;
  sVar1 = *(short *)(iVar6 + DAT_060b9378);
  sVar2 = *(short *)(iVar13 + iVar6);
  *(short *)(iVar6 + DAT_060b9378) = 0;
  *(short *)(iVar13 + iVar6) = 0;
  (*(code *)PTR_FUN_060b93d0)(0xe);
  (*(code *)PTR_FUN_060b93d4)(8);
  sVar3 = *(short *)(iVar6 + iVar12);
  iVar12 = 3;
  if (((sVar3 != DAT_060b937c) && (sVar3 != DAT_060b949a)) &&
     ((sVar3 == DAT_060b949c || (iVar12 = (int)sVar1, sVar3 == DAT_060b949e)))) {
    iVar12 = 0xf;
  }
  (*(code *)PTR_FUN_060b94b0)(iVar12);
  (*(code *)PTR_FUN_060b94b4)((int)DAT_060b94a0,1,(int)sVar2);
  iVar12 = (int)DAT_060b94a2;
  *(undefined2 *)(iVar12 + iVar6) = 1;
  puVar4 = PTR_FUN_060b94b8;
  do {
    (*(code *)puVar4)();
    puVar5 = PTR_FUN_060b94c0;
  } while (*(short *)(iVar12 + iVar6) != 0);
  (*(code *)PTR_FUN_060b94c0)(PTR_DAT_060b94bc,(int)*(short *)(iVar6 + DAT_060b94a4));
  (*(code *)puVar5)(PTR_DAT_060b94c4,iVar14);
  iVar12 = iVar14;
  if ((iVar14 != 0) ||
     (iVar12 = (int)*(short *)(iVar6 + DAT_060b94a6), *(short *)(iVar6 + DAT_060b94a6) != 0)) {
    (*(code *)PTR_FUN_060b94c8)(iVar12);
  }
  if (((*(short *)(iVar6 + DAT_060b94a4) != 0) && (*(short *)(iVar6 + DAT_060b94a4) != DAT_060b94a8)
      ) || ((*(short *)(iVar6 + DAT_060b94aa) != 0 &&
            (*(short *)(iVar6 + DAT_060b94aa) != DAT_060b94a8)))) {
    (*(code *)PTR_FUN_060b94c8)();
  }
  puVar4 = PTR_FUN_060b9530;
  sVar1 = *(short *)(iVar6 + DAT_060b94ac);
  if (sVar1 == DAT_060b94ae) {
LAB_060b94cc:
    if (((*(short *)(iVar6 + DAT_060b9520) == 3) && (iVar14 != DAT_060b9522)) &&
       (iVar14 != DAT_060b9524)) {
      (*(code *)PTR_FUN_060b9530)((int)DAT_060b9526);
    }
  }
  else if (DAT_060b94ae < sVar1) {
    if ((sVar1 == DAT_060b949c) || (sVar1 == DAT_060b949e)) {
      (*(code *)PTR_FUN_060b9530)((int)DAT_060b9528);
      (*(code *)puVar4)((int)DAT_060b952a);
    }
  }
  else if (sVar1 == DAT_060b949a) goto LAB_060b94cc;
  *(undefined2 *)(DAT_060b952c + iVar6) = 0;
LAB_060b9502:
  *(undefined2 *)(DAT_060b952e + iVar6) = 0;
  return;
}



void FUN_060b9534(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)PTR_FUN_060b95a0;
  if (*DAT_060b9598 == 0) {
    pcVar1 = (code *)PTR_FUN_060b95b4;
    switch(*(undefined2 *)(DAT_060b959c + DAT_060b9596)) {
    case 3:
      pcVar1 = (code *)PTR_FUN_060b95a4;
      break;
    case 4:
      pcVar1 = (code *)PTR_FUN_060b95a8;
      break;
    case 5:
      pcVar1 = (code *)PTR_FUN_060b95ac;
      break;
    case 6:
    case 7:
    case 8:
      pcVar1 = (code *)PTR_FUN_060b95b0;
    }
  }
  (*pcVar1)();
  return;
}



int FUN_060b95b8(void)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined4 uVar6;
  int iVar7;
  int unaff_r8;
  int iVar8;
  uint uVar9;
  
  puVar4 = PTR_FUN_060b9714;
  piVar3 = DAT_060b9710;
  iVar2 = DAT_060b970c;
  do {
    while( true ) {
      bVar1 = *(byte *)(DAT_060b970c + 0xe);
      if (bVar1 == 1) goto LAB_060b96c0;
      if (bVar1 < 2) break;
      if (bVar1 == 2) goto LAB_060b96d6;
    }
  } while (bVar1 != 0);
  iVar8 = 0;
  (*(code *)PTR_FUN_060b9718)();
  (*(code *)PTR_FUN_060b971c)();
  puVar5 = PTR_FUN_060b9720;
  if (0 < *piVar3) {
    do {
      uVar6 = (*(code *)puVar4)(iVar8 * 0x40 + DAT_060b9724);
      iVar8 = iVar8 + 1;
      (*(code *)puVar5)(iVar8,uVar6);
      (*(code *)PTR_FUN_060b9728)(uVar6);
    } while (iVar8 < *piVar3);
  }
  *(undefined2 *)(iVar2 + DAT_060b9702) = 0;
  iVar8 = 0;
  do {
    uVar9 = 0;
    if (((*(ushort *)(iVar2 + DAT_060b9704) == DAT_060b972c) &&
        (*(ushort *)(iVar2 + DAT_060b9706) == DAT_060b9730)) && (iVar8 == 0)) {
      iVar8 = 2;
    }
    if (0 < *piVar3) {
      do {
        iVar7 = (*(code *)PTR_FUN_060b9734)
                          (iVar2 + (4 - iVar8) * 0x28 + (int)DAT_060b970a,
                           iVar2 + (uVar9 & 3) * 0x50 + (int)DAT_060b9708 +
                           ((uVar9 & 4) << 2 | uVar9 & 4) * 2,0x28);
        if (iVar7 == 0) {
          *(short *)(iVar2 + DAT_060b9702) = (short)uVar9;
        }
        uVar9 = uVar9 + 1;
      } while ((int)uVar9 < *piVar3);
    }
    iVar8 = iVar8 + 1;
  } while (iVar8 < 5);
  (*(code *)PTR_FUN_060b9738)();
  (*(code *)PTR_FUN_060b973c)();
LAB_060b96c0:
  iVar8 = (*(code *)PTR_FUN_060b9740)(*piVar3);
  unaff_r8 = iVar8 + -1;
  (*(code *)PTR_FUN_060b9744)();
  (*(code *)PTR_FUN_060b973c)();
LAB_060b96d6:
  *(undefined *)(iVar2 + 0x11) = 1;
  *(undefined *)(iVar2 + 0xe) = 0;
  *(undefined2 *)(iVar2 + DAT_060b9702) = 0;
  return unaff_r8;
}



void FUN_060b9748(void)

{
  char cVar1;
  undefined *puVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  (*(code *)PTR_FUN_060b97cc)();
  puVar2 = PTR_FUN_060b97d4;
  (*(code *)PTR_FUN_060b97d4)(DAT_060b97d0,0,0xe);
  (*(code *)puVar2)(DAT_060b97d8,0,0xe);
  iVar8 = 0;
  iVar9 = 0;
  iVar7 = DAT_060b97e0;
  if (0 < *DAT_060b97dc) {
    do {
      pcVar3 = (char *)(*(code *)PTR_FUN_060b97e8)(iVar9 + DAT_060b97e4);
      iVar5 = 0;
      cVar1 = *pcVar3;
      pcVar6 = pcVar3;
      while (cVar1 != '\0') {
        pcVar4 = pcVar6 + 1;
        pcVar6 = pcVar6 + 2;
        *(char *)(iVar5 + iVar7) = *pcVar4 + -0x40;
        iVar5 = iVar5 + 1;
        cVar1 = *pcVar6;
      }
      *(undefined *)(iVar5 + iVar7) = 0;
      (*(code *)PTR_FUN_060b97ec)(pcVar3);
      iVar8 = iVar8 + 1;
      iVar9 = iVar9 + 0x40;
      iVar7 = iVar7 + 0xe;
    } while (iVar8 < *DAT_060b97dc);
  }
  return;
}



int FUN_060b97f0(char *param_1,int param_2)

{
  char cVar1;
  bool bVar2;
  short *psVar3;
  undefined *puVar4;
  ushort *puVar5;
  int iVar6;
  int iVar7;
  short sVar8;
  undefined4 uVar9;
  short *psVar10;
  short sVar11;
  short sVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  
  iVar7 = DAT_060b9934;
  psVar3 = DAT_060b9930;
  psVar10 = DAT_060b9930 + 1;
  sVar12 = (short)*param_1;
  cVar1 = param_1[1];
  do {
    bVar2 = false;
    iVar6 = (*(code *)PTR_FUN_060b9938)(0,0,(int)DAT_060b992a);
    if (iVar6 != 0) {
      if (param_1[(int)sVar12 * (int)*psVar10 + (int)*psVar3 + 2] == '8') {
        *psVar3 = 10;
      }
      else {
        *psVar3 = *psVar3 + -1;
      }
    }
    iVar6 = (*(code *)PTR_FUN_060b9938)(0,0,DAT_060b993c);
    if (iVar6 != 0) {
      if (param_1[(int)sVar12 * (int)*psVar10 + (int)*psVar3 + 2] == '8') {
        *psVar3 = 0;
      }
      else {
        *psVar3 = *psVar3 + 1;
      }
    }
    puVar4 = PTR_FUN_060b9938;
    iVar6 = (*(code *)PTR_FUN_060b9938)(0,0,(int)DAT_060b992c);
    if (iVar6 != 0) {
      *psVar10 = *psVar10 + -1;
    }
    iVar6 = (*(code *)puVar4)(0,0,(int)DAT_060b992e);
    if (iVar6 != 0) {
      *psVar10 = *psVar10 + 1;
    }
    sVar8 = 0;
    if (*psVar3 < sVar12) {
      sVar8 = *psVar3;
    }
    *psVar3 = sVar8;
    if (*psVar3 < 0) {
      sVar8 = sVar12 + -1;
    }
    *psVar3 = sVar8;
    sVar8 = 0;
    if (*psVar10 < (short)cVar1) {
      sVar8 = *psVar10;
    }
    *psVar10 = sVar8;
    sVar8 = *psVar10;
    if (sVar8 < 0) {
      sVar8 = cVar1 + -1;
    }
    *psVar10 = sVar8;
    sVar11 = (short)param_1[(int)sVar12 * (int)sVar8 + (int)*psVar3 + 2];
    if (param_2 == 3) {
      uVar9 = 4;
      uVar14 = 4;
      uVar13 = 4;
    }
    else {
      uVar14 = 2;
      uVar13 = 2;
      uVar9 = 5;
    }
    (*(code *)PTR_FUN_060b9a5c)
              (0xb,(int)(short)param_1[(int)sVar12 * (int)sVar8 + (int)*psVar3 + 2],uVar9,0x1f,1,
               uVar13,uVar14);
    *(undefined2 *)(DAT_060b9a4c + iVar7) = 0;
    *(undefined2 *)(DAT_060b9a4e + iVar7) = 0;
    (*(code *)PTR_FUN_060b9a60)();
    if (param_2 == 2) {
      iVar6 = (*(code *)PTR_FUN_060b9a64)(0,0,(int)DAT_060b9a50);
      bVar2 = iVar6 != 0;
      if (bVar2) {
        sVar11 = 0x38;
      }
    }
    if ((param_2 == 3) && (iVar6 = (*(code *)PTR_FUN_060b9a64)(0,0,(int)DAT_060b9a50), iVar6 != 0))
    {
      bVar2 = true;
      sVar11 = 0xe;
    }
    puVar5 = DAT_060b9a68;
    iVar6 = (*(code *)PTR_FUN_060b9a64)(0,0,*DAT_060b9a68 | DAT_060b9a68[-1]);
  } while ((iVar6 == 0) && (!bVar2));
  iVar7 = (*(code *)PTR_FUN_060b9a64)(0,0,*puVar5);
  if (iVar7 == 0) {
    iVar6 = (int)sVar11;
    if ((int)(uint)(iVar7 == 0) < param_2) goto LAB_060b9a2c;
    if (iVar6 == 0) {
LAB_060b9a18:
      iVar7 = (int)DAT_060b9a52;
    }
    else {
      iVar7 = (*(code *)PTR_FUN_060b9a6c)(iVar6,3);
      iVar6 = iVar6 + iVar7 * -3;
      if (iVar6 == 1) goto LAB_060b9a18;
      if (iVar6 == 2) {
        iVar7 = (int)DAT_060b9a54;
      }
      else {
        iVar7 = (int)DAT_060b9a56;
      }
    }
  }
  else {
    sVar11 = -1;
    if (param_2 < 2) goto LAB_060b9a34;
LAB_060b9a2c:
    iVar7 = (int)DAT_060b9a58;
  }
  (*(code *)PTR_FUN_060b9a70)(iVar7);
LAB_060b9a34:
  return (int)sVar11;
}



uint FUN_060b9a74(int param_1,undefined4 param_2,char param_3,char param_4)

{
  char cVar1;
  byte bVar2;
  bool bVar3;
  short sVar5;
  int iVar4;
  ushort uVar7;
  undefined *puVar6;
  int iVar8;
  char *pcVar9;
  short *psVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  ushort *puVar15;
  byte *pbVar16;
  int iStack_3c;
  
  (*(code *)PTR_FUN_060b9ba4)();
  iVar14 = 0;
  iVar11 = (int)param_4;
  puVar15 = (ushort *)(param_1 + 4);
  pbVar16 = DAT_060b9ba8;
  iStack_3c = param_1;
  do {
    puVar6 = PTR_FUN_060b9bac;
    *puVar15 = DAT_060b9b98 | *puVar15 & 0xf;
    sVar5 = (*(code *)puVar6)(param_2,iVar11);
    uVar13 = (uint)sVar5;
    if (uVar13 != 0xffffffff) {
      if (iVar11 < 2) {
        (*(code *)PTR_FUN_060b9bb8)(0xb,(int)sVar5,4,0x1f,0xff,3,3);
        puVar6 = PTR_FUN_060b9bbc;
        iVar8 = (int)DAT_060b9ba0;
        cVar1 = *(char *)(iVar8 + DAT_060b9bb4);
        while (cVar1 != '\0') {
          (*(code *)puVar6)();
          cVar1 = *(char *)(iVar8 + DAT_060b9bb4);
        }
      }
      (*(code *)PTR_FUN_060b9bbc)();
      if (iVar11 != 2) {
        *pbVar16 = (char)sVar5 + 0xf;
        if (uVar13 == 10) {
          uVar7 = *(ushort *)PTR_DAT_060b9bc0;
LAB_060b9bec:
          uVar12 = (uint)uVar7;
        }
        else {
          if (uVar13 == 0xb) {
            uVar7 = *(ushort *)PTR_DAT_060b9bc4;
            goto LAB_060b9bec;
          }
          if (uVar13 == 0xd) {
            uVar12 = (uint)*(ushort *)PTR_u__________0_060b9dd8;
            *pbVar16 = 0xf;
          }
          else {
            if (uVar13 != 0xe) {
              uVar7 = *(ushort *)(PTR_u__________0_060b9dd8 + uVar13 * 2);
              goto LAB_060b9bec;
            }
            uVar12 = 0;
            *pbVar16 = 0;
          }
        }
        pbVar16 = pbVar16 + 1;
        iVar14 = iVar14 + 1;
LAB_060b9d36:
        *puVar15 = ((ushort)uVar12 & 3) * 4 + DAT_060b9dd0;
        puVar15 = puVar15 + 6;
        psVar10 = (short *)(iStack_3c + 6);
        iStack_3c = iStack_3c + 0xc;
        *psVar10 = (short)((int)uVar12 >> 2) * 0xe + DAT_060b9dd4;
        goto LAB_060b9d62;
      }
      bVar2 = PTR_DAT_060b9ddc[uVar13 * 2];
      uVar12 = (uint)bVar2;
      if (uVar12 == 0x57) {
        if ((iVar14 != 0) && ((*(byte *)(DAT_060b9de0 + iVar14) & 1) != 0)) {
          *(byte *)(DAT_060b9de0 + iVar14) = 0;
          pcVar9 = (char *)(iVar14 + DAT_060b9de4);
          *pcVar9 = *pcVar9 + '\x01';
          puVar15 = puVar15 + -6;
          iStack_3c = iStack_3c + -0xc;
          uVar7 = *(ushort *)(PTR_DAT_060b9de8 + *pcVar9 * 2);
LAB_060b9d34:
          uVar12 = (uint)uVar7;
          goto LAB_060b9d36;
        }
      }
      else if (uVar12 < 0x58) {
        if (uVar12 == 0) {
          uVar13 = (uint)(uVar12 == 0);
          goto switchD_060b9d76_caseD_4;
        }
        if (uVar12 == 0x56) {
          if ((iVar14 != 0) && (*(char *)(DAT_060b9de0 + iVar14) == '\x03')) {
            *(char *)(DAT_060b9de0 + iVar14) = '\0';
            pcVar9 = (char *)(iVar14 + DAT_060b9de4);
            *pcVar9 = *pcVar9 + '\x02';
            puVar15 = puVar15 + -6;
            iStack_3c = iStack_3c + -0xc;
            uVar7 = *(ushort *)(PTR_DAT_060b9de8 + *pcVar9 * 2);
            goto LAB_060b9d34;
          }
        }
        else {
LAB_060b9cee:
          if (iVar14 != param_3) {
            if (uVar12 == (int)DAT_060b9dd2) {
              *pbVar16 = 0x1b;
            }
            else {
              *pbVar16 = bVar2;
            }
            pbVar16 = pbVar16 + 1;
            *(undefined *)(DAT_060b9dec + iVar14) = PTR_DAT_060b9df0[uVar13 * 2];
            iVar14 = iVar14 + 1;
            puVar6 = PTR_DAT_060b9de8;
            if ((bVar2 & 0x80) != 0) {
              puVar6 = PTR_DAT_060b9df4;
            }
            uVar7 = *(ushort *)(puVar6 + uVar12 * 2);
            goto LAB_060b9d34;
          }
        }
      }
      else if (uVar12 == 0x58) {
        if (iVar14 != 0) {
          pbVar16 = pbVar16 + -1;
          iVar14 = iVar14 + -1;
          *puVar15 = DAT_060b9dd0 | *puVar15 & 0xf;
          puVar15 = puVar15 + -6;
          iStack_3c = iStack_3c + -0xc;
        }
      }
      else {
        if (uVar12 != 0x59) goto LAB_060b9cee;
        if (iVar14 < param_3) {
          pbVar16 = pbVar16 + 1;
          iVar14 = iVar14 + 1;
          *puVar15 = DAT_060b9dd0 | *puVar15 & 0xf;
          puVar15 = puVar15 + 6;
          iStack_3c = iStack_3c + 0xc;
        }
      }
LAB_060b9e7a:
      uVar13 = 0xffffffff;
      goto switchD_060b9d76_caseD_4;
    }
    if ((iVar14 == 0) && (iVar11 == 2)) goto switchD_060b9d76_caseD_4;
    if (iVar11 == 2) {
      pbVar16[-1] = 0;
      *(undefined *)(DAT_060b9bb0 + iVar14 + -1) = 0;
    }
    else {
      *pbVar16 = 0;
      *(undefined *)(DAT_060b9bb0 + iVar14) = 0;
    }
    pbVar16 = pbVar16 + -1;
    iVar14 = iVar14 + -1;
    *puVar15 = DAT_060b9b9a | *puVar15 & 0xf;
    if (iVar11 != 0) {
      puVar15 = puVar15 + -6;
      iStack_3c = iStack_3c + -0xc;
    }
    *puVar15 = DAT_060b9b98;
    *(undefined2 *)(iStack_3c + 6) = DAT_060b9b9c;
    if (iVar14 == -1) {
      *(undefined2 *)(DAT_060b9b9e + DAT_060b9bb4) = 0xffff;
      return 0xffffffff;
    }
LAB_060b9d62:
    puVar6 = PTR_FUN_060b9eac;
    switch(iVar11) {
    case 0:
      uVar12 = 0;
      if ('\x18' < *DAT_060b9df8) {
        *DAT_060b9df8 = '\x17';
      }
      puVar6 = PTR_FUN_060b9e00;
      uVar13 = 0xffffffff;
      if (0 < *DAT_060b9dfc) {
        iVar8 = 0;
        do {
          if (uVar13 != 0xffffffff) break;
          iVar4 = (*(code *)puVar6)(iVar8 + DAT_060b9e04,(int)*DAT_060b9df8);
          if (iVar4 != 0) {
            uVar13 = uVar12;
          }
          uVar12 = uVar12 + 1;
          iVar8 = iVar8 + 0xe;
        } while ((int)uVar12 < *DAT_060b9dfc);
      }
      break;
    case 1:
      uVar12 = 0;
      uVar13 = 0xffffffff;
      if (0 < *DAT_060b9ea8) {
        iVar8 = 0;
        do {
          bVar3 = uVar13 == 0xffffffff;
          if (!bVar3) goto LAB_060b9e42;
          iVar4 = (*(code *)puVar6)(iVar8 + DAT_060b9eb0,DAT_060b9eb4);
          if (iVar4 == 0) {
            uVar13 = uVar12;
          }
          uVar12 = uVar12 + 1;
          iVar8 = iVar8 + 0xe;
        } while ((int)uVar12 < *DAT_060b9ea8);
      }
      bVar3 = uVar13 == 0xffffffff;
LAB_060b9e42:
      if ((bVar3) && (bVar3 = uVar13 == 0xffffffff, iVar14 == param_3)) {
LAB_060b9e50:
        uVar13 = 0;
        break;
      }
      goto LAB_060b9e80;
    case 2:
      if (PTR_DAT_060b9eb8[uVar13 * 2] != '\0') {
        uVar13 = 0xffffffff;
      }
      break;
    case 3:
      if (uVar13 == 0xe) goto LAB_060b9e50;
      uVar13 = 0;
      if (iVar14 != param_3) goto LAB_060b9e7a;
    }
switchD_060b9d76_caseD_4:
    bVar3 = uVar13 == 0xffffffff;
LAB_060b9e80:
    if (!bVar3) {
      *(short *)(DAT_060b9ea4 + DAT_060b9ebc) = (short)uVar13;
      return uVar13;
    }
  } while( true );
}



int FUN_060b9ec0(void)

{
  char cVar1;
  short sVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  int iVar6;
  undefined *puVar7;
  int iVar8;
  int iVar9;
  undefined *puVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  
  iVar6 = DAT_060ba008;
switchD_060b9eee_caseD_5:
  puVar10 = PTR_FUN_060ba138;
  uVar5 = DAT_060b9ffe;
  uVar4 = DAT_060b9ffc;
  switch(*(undefined *)(iVar6 + 0xe)) {
  case 0:
    iVar9 = 0;
    puVar10 = PTR_DAT_060ba00c;
    do {
      *(undefined2 *)(puVar10 + 4) = uVar4;
      *(undefined2 *)(puVar10 + 6) = uVar5;
      puVar7 = PTR_PTR_DAT_060ba010;
      iVar9 = iVar9 + 1;
      puVar10 = puVar10 + 0xc;
    } while (iVar9 < 10);
    *(undefined4 *)(DAT_060ba000 + iVar6) = *(undefined4 *)PTR_PTR_DAT_060ba010;
    puVar10 = PTR_FUN_060ba014;
    iVar9 = (int)DAT_060ba002;
    **(undefined2 **)puVar7 = 0x13;
    *(undefined *)(iVar9 + iVar6) = 0xc;
    (*(code *)puVar10)();
    (*(code *)PTR_FUN_060ba018)();
    break;
  case 2:
    (*(code *)PTR_FUN_060ba030)(DAT_060ba034,0,(int)DAT_060ba004);
    iVar9 = 0;
    if (0 < *DAT_060ba038) {
      iVar15 = 0;
      iVar13 = DAT_060ba034;
      do {
        iVar8 = (*(code *)PTR_FUN_060ba040)(iVar15 + DAT_060ba03c);
        iVar11 = 0;
        cVar1 = *(char *)(iVar8 + 2);
        iVar3 = iVar8;
        while (cVar1 != '\0') {
          *(char *)(iVar11 + iVar13) = *(char *)(iVar3 + 3) + -0x40;
          iVar11 = iVar11 + 1;
          cVar1 = *(char *)(iVar3 + 4);
          iVar3 = iVar3 + 2;
        }
        (*(code *)PTR_FUN_060ba044)(iVar8);
        *(undefined *)(iVar11 + iVar13) = 0;
        iVar13 = iVar13 + 0xe;
        iVar9 = iVar9 + 1;
        iVar15 = iVar15 + 0x40;
      } while (iVar9 < *DAT_060ba038);
    }
    puVar10 = PTR_FUN_060ba048;
    uVar12 = *DAT_060ba038 - 1;
    uVar14 = 0;
    if (uVar12 != 0) {
      iVar9 = uVar12 * 0xe;
      do {
        iVar13 = (*(code *)puVar10)(iVar9 + DAT_060ba034,DAT_060ba028);
        iVar9 = iVar9 + -0xe;
        if (iVar13 == 0) {
          uVar14 = uVar12;
        }
        uVar12 = uVar12 - 1;
      } while (uVar12 != 0);
    }
    iVar9 = (int)*DAT_060ba028;
    if (iVar9 == 0) {
      uVar14 = (uint)(iVar9 == 0);
    }
    else if ((*(char *)(iVar6 + DAT_060ba11e) == '\x03') && (uVar14 == 0)) {
      if (DAT_060ba028[1] == 0) {
        uVar14 = 3;
      }
      else if (iVar9 == 0xf) {
        uVar14 = 2;
      }
      else if (*DAT_060ba12c == '\0') {
        if ((iVar9 + -0xf) * 10 + -0xf + (int)DAT_060ba028[1] < 0x50) {
          uVar14 = 0xb;
        }
        else if (iVar9 == 0x17) {
          uVar14 = 9;
        }
        else if (iVar9 == 0x18) {
          uVar14 = 10;
        }
      }
      else {
        uVar14 = 0xc;
      }
    }
    *(short *)(iVar6 + DAT_060ba120) = (short)uVar14;
    (*(code *)PTR_FUN_060ba130)(4);
    goto switchD_060b9eee_caseD_5;
  case 3:
    goto switchD_060b9eee_caseD_3;
  case 4:
    goto switchD_060b9eee_caseD_4;
  default:
    goto switchD_060b9eee_caseD_5;
  }
  iVar9 = (*(code *)PTR_FUN_060ba024)(PTR_DAT_060ba020,PTR_DAT_060ba01c,3,3);
  if (iVar9 == -1) {
    *DAT_060ba028 = '\0';
  }
  (*(code *)PTR_FUN_060ba02c)(2);
  goto switchD_060b9eee_caseD_5;
switchD_060b9eee_caseD_3:
  *(undefined2 *)(DAT_060ba120 + iVar6) = 0xffff;
  (*(code *)PTR_FUN_060ba134)();
  goto switchD_060b9eee_caseD_5;
switchD_060b9eee_caseD_4:
  iVar9 = (int)DAT_060ba120;
  sVar2 = *(short *)(iVar6 + iVar9);
  *(undefined *)(DAT_060ba122 + iVar6) = 0;
  (*(code *)puVar10)();
  puVar10 = PTR_PTR_DAT_060ba13c;
  *(undefined4 *)(DAT_060ba124 + iVar6) = *(undefined4 *)PTR_PTR_DAT_060ba13c;
  *(undefined *)(DAT_060ba126 + iVar6) = 0;
  *(undefined *)(iVar6 + 0x11) = 1;
  *(undefined *)(iVar6 + 0xe) = 0;
  *(short *)(iVar6 + iVar9) = 0;
  *(undefined2 *)(DAT_060ba128 + iVar6) = 0;
  **(undefined2 **)(puVar10 + 0x10) = 0x12;
  return (int)sVar2;
}



int FUN_060ba140(void)

{
  short sVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined *puVar5;
  undefined *puVar6;
  int iVar7;
  
  iVar4 = DAT_060ba298;
  uVar2 = DAT_060ba288;
  do {
    puVar6 = PTR_FUN_060ba2bc;
    uVar3 = DAT_060ba28a;
    switch(*(undefined *)(iVar4 + 0xe)) {
    case 0:
      iVar7 = 0;
      puVar6 = PTR_DAT_060ba29c;
      do {
        *(undefined2 *)(puVar6 + 4) = uVar2;
        *(undefined2 *)(puVar6 + 6) = uVar3;
        iVar7 = iVar7 + 1;
        puVar6 = puVar6 + 0xc;
      } while (iVar7 < 10);
      *(undefined4 *)(iVar4 + DAT_060ba28c) = *(undefined4 *)PTR_PTR_DAT_060ba2a0;
      *(undefined *)(iVar4 + DAT_060ba28e) = 0xc;
      (*(code *)PTR_FUN_060ba2a4)();
      (*(code *)PTR_FUN_060ba2a8)();
switchD_060ba16e_caseD_1:
      iVar7 = (*(code *)PTR_FUN_060ba2b0)(PTR_DAT_060ba29c,PTR_LAB_060ba2ac,1,0);
      if (iVar7 == -1) {
        (*(code *)PTR_FUN_060ba2b4)(3);
      }
      else {
        (*(code *)PTR_FUN_060ba2a8)();
      }
      if (0xb < iVar7) {
        iVar7 = 0xc;
      }
      *(short *)(iVar4 + DAT_060ba290) = (short)iVar7;
      return iVar7;
    case 1:
      goto switchD_060ba16e_caseD_1;
    case 2:
      iVar7 = (*(code *)PTR_FUN_060ba2b0)(PTR_DAT_060ba2b8,PTR_LAB_060ba2ac,9,1);
      if (iVar7 == -1) {
        (*(code *)PTR_FUN_060ba2b4)(5);
      }
      else {
        (*(code *)PTR_FUN_060ba2b4)(4);
      }
      break;
    case 3:
      *(undefined2 *)(DAT_060ba290 + iVar4) = 0xffff;
      (*(code *)PTR_FUN_060ba2a8)();
      break;
    case 4:
      iVar7 = 0;
      do {
        iVar7 = iVar7 + 1;
        (*(code *)puVar6)();
        puVar5 = PTR_FUN_060ba2c0;
      } while (iVar7 < 0x1e);
      sVar1 = *(short *)(DAT_060ba290 + iVar4);
      *(undefined *)(DAT_060ba292 + iVar4) = 0;
      (*(code *)puVar5)();
      *(undefined4 *)(DAT_060ba28c + iVar4) = *(undefined4 *)PTR_PTR_DAT_060ba2c4;
      *(undefined *)(DAT_060ba28e + iVar4) = 0;
      *(undefined *)(iVar4 + 0x11) = 1;
      *(undefined *)(iVar4 + 0xe) = 0;
      *(undefined2 *)(DAT_060ba294 + iVar4) = 0;
      return (int)sVar1;
    case 5:
      (*(code *)PTR_FUN_060ba2b4)(1);
      *(undefined2 *)(DAT_060ba290 + iVar4) = 0xffff;
      return -1;
    }
  } while( true );
}



int FUN_060ba2c8(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  short sVar6;
  undefined2 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  iVar3 = DAT_060ba3e4;
  uVar2 = DAT_060ba3d8;
  uVar1 = DAT_060ba3d6;
  while (*(char *)(DAT_060ba3e4 + 0xe) != '\0') {
    if (*(char *)(DAT_060ba3e4 + 0xe) == '\x01') goto LAB_060ba342;
  }
  iVar10 = 0;
  sVar6 = 0x70;
  puVar5 = PTR_DAT_060ba3e8;
  do {
    *(undefined2 *)(puVar5 + 4) = uVar1;
    *(undefined2 *)(puVar5 + 6) = uVar2;
    *(short *)(puVar5 + 8) = sVar6;
    sVar6 = sVar6 + 0x10;
    iVar10 = iVar10 + 1;
    puVar5 = puVar5 + 0xc;
  } while (iVar10 < 0xb);
  iVar10 = (int)DAT_060ba3da;
  iVar8 = (int)DAT_060ba3dc;
  *(undefined4 *)(iVar3 + iVar10) = *(undefined4 *)PTR_PTR_DAT_060ba3ec;
  *(undefined *)(iVar8 + iVar3) = 0xc;
  puVar7 = *(undefined2 **)(iVar3 + iVar10);
  (*(code *)PTR_FUN_060ba3f0)();
  *puVar7 = 8;
  (*(code *)PTR_FUN_060ba3f4)();
LAB_060ba342:
  (*(code *)PTR_FUN_060ba3f8)(PTR_DAT_060ba3e8,PTR_DAT_060ba3fc,4,2);
  puVar5 = PTR_FUN_060ba404;
  iVar8 = 0;
  iVar10 = -1;
  if (0 < *DAT_060ba400) {
    iVar9 = 0;
    do {
      iVar4 = (*(code *)puVar5)(iVar9 + DAT_060ba408,DAT_060ba40c);
      iVar9 = iVar9 + 0xe;
      if (iVar4 == 0) {
        iVar10 = iVar8;
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < *DAT_060ba400);
  }
  if (iVar10 == -1) {
    iVar10 = 0;
  }
  *(short *)(DAT_060ba3de + iVar3) = (short)iVar10;
  iVar8 = (int)DAT_060ba3da;
  **(undefined2 **)(iVar3 + iVar8) = 4;
  *(undefined *)(DAT_060ba3e0 + iVar3) = 0;
  (*(code *)PTR_FUN_060ba410)();
  *(undefined4 *)(iVar3 + iVar8) = *(undefined4 *)PTR_PTR_DAT_060ba414;
  *(undefined *)(DAT_060ba3dc + iVar3) = 0;
  *(undefined *)(iVar3 + 0x11) = 1;
  *(undefined *)(iVar3 + 0xe) = 0;
  *(undefined2 *)(DAT_060ba3e2 + iVar3) = 0;
  return iVar10;
}



int FUN_060ba418(void)

{
  char cVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  undefined *puVar9;
  int iVar10;
  short sVar11;
  char *pcVar12;
  undefined2 *puVar13;
  int iVar14;
  
  iVar4 = DAT_060ba508;
  do {
    puVar9 = PTR_FUN_060ba694;
    uVar3 = DAT_060ba4fe;
    uVar2 = DAT_060ba4fc;
    switch(*(undefined *)(iVar4 + 0xe)) {
    case 0:
      iVar7 = 0;
      sVar11 = 0x40;
      puVar9 = PTR_DAT_060ba50c;
      do {
        *(undefined2 *)(puVar9 + 4) = uVar2;
        *(undefined2 *)(puVar9 + 6) = uVar3;
        *(short *)(puVar9 + 8) = sVar11;
        sVar11 = sVar11 + 0x10;
        iVar7 = iVar7 + 1;
        puVar9 = puVar9 + 0xc;
      } while (iVar7 < 0xb);
      iVar7 = (int)DAT_060ba500;
      iVar8 = (int)DAT_060ba502;
      *(undefined4 *)(iVar4 + iVar7) = *(undefined4 *)PTR_PTR_DAT_060ba510;
      *(undefined *)(iVar8 + iVar4) = 0xc;
      puVar13 = *(undefined2 **)(iVar4 + iVar7);
      (*(code *)PTR_FUN_060ba514)();
      *puVar13 = 0xf;
      (*(code *)PTR_FUN_060ba518)();
switchD_060ba448_caseD_1:
      (*(code *)PTR_FUN_060ba51c)(PTR_DAT_060ba50c,PTR_DAT_060ba520,10,2);
      puVar9 = PTR_FUN_060ba528;
      iVar8 = 0;
      iVar7 = -1;
      if (0 < *DAT_060ba524) {
        iVar14 = 0;
        do {
          iVar10 = (*(code *)puVar9)(iVar14 + DAT_060ba530,(int)*DAT_060ba52c);
          iVar14 = iVar14 + 0xe;
          if (iVar10 != 0) {
            iVar7 = iVar8;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < *DAT_060ba524);
      }
      if (iVar7 == -1) {
        (*(code *)PTR_FUN_060ba534)(3);
      }
      else {
        (*(code *)PTR_FUN_060ba518)();
      }
      *(short *)(iVar4 + DAT_060ba504) = (short)iVar7;
      return iVar7;
    case 1:
      goto switchD_060ba448_caseD_1;
    case 2:
      iVar7 = 0;
      (*(code *)PTR_FUN_060ba668)();
      (*(code *)PTR_FUN_060ba66c)(DAT_060ba670,0,(int)DAT_060ba65c);
      if (0 < *DAT_060ba674) {
        iVar14 = 0;
        iVar8 = DAT_060ba670;
        do {
          pcVar5 = (char *)(*(code *)PTR_FUN_060ba67c)(iVar14 + DAT_060ba678);
          iVar10 = 0;
          cVar1 = *pcVar5;
          pcVar12 = pcVar5;
          while (cVar1 != '\0') {
            pcVar6 = pcVar12 + 1;
            pcVar12 = pcVar12 + 2;
            *(char *)(iVar10 + iVar8) = *pcVar6 + -0x40;
            iVar10 = iVar10 + 1;
            cVar1 = *pcVar12;
          }
          (*(code *)PTR_FUN_060ba680)(pcVar5);
          iVar8 = iVar8 + 0xe;
          iVar7 = iVar7 + 1;
          iVar14 = iVar14 + 0x40;
        } while (iVar7 < *DAT_060ba674);
      }
      puVar9 = PTR_FUN_060ba684;
      iVar8 = *DAT_060ba674 + -1;
      iVar7 = 0;
      if (iVar8 != 0) {
        iVar14 = iVar8 * 0xe;
        do {
          iVar10 = (*(code *)puVar9)(iVar14 + DAT_060ba670,DAT_060ba688);
          iVar14 = iVar14 + -0xe;
          if (iVar10 == 0) {
            iVar7 = iVar8;
          }
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
      *(short *)(DAT_060ba65e + iVar4) = (short)iVar7;
      if (iVar7 == -1) {
        (*(code *)PTR_FUN_060ba68c)(5);
      }
      else {
        (*(code *)PTR_FUN_060ba68c)(4);
      }
      break;
    case 3:
      *(undefined2 *)(DAT_060ba65e + iVar4) = 0xffff;
      (*(code *)PTR_FUN_060ba690)();
      break;
    case 4:
      iVar7 = (int)DAT_060ba65e;
      iVar8 = (int)DAT_060ba660;
      sVar11 = *(short *)(iVar4 + iVar7);
      **(undefined2 **)(iVar4 + iVar8) = 4;
      *(undefined *)(DAT_060ba662 + iVar4) = 0;
      (*(code *)puVar9)();
      *(undefined4 *)(iVar4 + iVar8) = *(undefined4 *)PTR_PTR_DAT_060ba698;
      *(undefined *)(DAT_060ba664 + iVar4) = 0;
      *(undefined *)(iVar4 + 0x11) = 1;
      *(undefined *)(iVar4 + 0xe) = 0;
      *(short *)(iVar4 + iVar7) = 0;
      *(undefined2 *)(DAT_060ba666 + iVar4) = 0;
      return (int)sVar11;
    case 5:
      (*(code *)PTR_FUN_060ba68c)(1);
      *(undefined2 *)(DAT_060ba65e + iVar4) = 0xffff;
      return -1;
    }
  } while( true );
}



undefined4 FUN_060ba69c(void)

{
  int *piVar1;
  undefined *puVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  undefined4 uVar5;
  int iVar6;
  
  piVar1 = DAT_060ba6f0;
  puVar3 = (undefined2 *)(*(code *)PTR_FUN_060ba6f4)(*DAT_060ba6f0);
  iVar6 = 0;
  puVar4 = puVar3;
  if (0 < *piVar1) {
    do {
      puVar4[2] = (short)iVar6;
      iVar6 = iVar6 + 1;
      puVar4 = puVar4 + 1;
    } while (iVar6 < *piVar1);
  }
  puVar2 = PTR_FUN_060ba6fc;
  *puVar3 = *DAT_060ba6f8;
  uVar5 = (*(code *)puVar2)(puVar3,0);
  (*(code *)PTR_FUN_060ba700)(puVar3);
  return uVar5;
}



uint FUN_060ba724(ushort *param_1,uint param_2)

{
  ushort uVar1;
  undefined *puVar2;
  ushort *puVar3;
  int iVar4;
  ushort *puVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  ushort *puVar11;
  
  puVar3 = (ushort *)(*(code *)PTR_FUN_060ba880)();
  iVar4 = (*(code *)PTR_FUN_060ba884)();
  if (param_2 < 0x20) {
    iVar10 = 0;
    puVar11 = param_1;
    if (*param_1 != 0) {
      do {
        uVar1 = *(ushort *)((uint)puVar11[2] * 0x40 + DAT_060ba888 + param_2 * 2);
        iVar8 = 0;
        puVar5 = puVar3;
        if (*puVar3 != 0) {
          do {
            if (puVar5[2] == uVar1) break;
            iVar8 = iVar8 + 1;
            puVar5 = puVar5 + 1;
          } while (iVar8 < (int)(uint)*puVar3);
        }
        iVar10 = iVar10 + 1;
        if ((int)(uint)*puVar3 <= iVar8) {
          puVar3 = (ushort *)(*(code *)PTR_FUN_060ba88c)(puVar3,uVar1);
          uVar6 = (*(code *)PTR_FUN_060ba880)();
          iVar4 = (*(code *)PTR_FUN_060ba890)(iVar4,uVar6);
        }
        puVar9 = (undefined4 *)(iVar8 * 4 + iVar4 + 4);
        uVar6 = (*(code *)PTR_FUN_060ba88c)(*puVar9,puVar11[2]);
        *puVar9 = uVar6;
        puVar11 = puVar11 + 1;
      } while (iVar10 < (int)(uint)*param_1);
    }
    puVar2 = PTR_FUN_060ba894;
    if ((*puVar3 == 1) && ((short)puVar3[2] < 0)) {
      param_1 = *(ushort **)(iVar4 + 4);
    }
    else {
      while( true ) {
        iVar10 = 0;
        (*(code *)puVar2)(PTR_s______MOUSE__060ba898);
        (*(code *)puVar2)(PTR_s______060ba89c);
        if (*puVar3 != 0) {
          iVar8 = 1;
          do {
            iVar10 = iVar8;
            iVar8 = iVar10 + 1;
          } while (iVar10 < (int)(uint)*puVar3);
        }
        do {
          do {
            (*(code *)puVar2)(PTR_s_CLICK__>_060ba8a0);
          } while (iVar10 < 0);
        } while ((int)(*puVar3 + 1) <= iVar10);
        iVar8 = iVar10 + -1;
        if (iVar8 < 0) {
          return 0xffffffff;
        }
        if ((short)puVar3[iVar10 + 1] < 0) break;
        uVar7 = (*(code *)PTR_FUN_060ba8a4)(*(undefined4 *)(iVar8 * 4 + iVar4 + 4),param_2 + 1);
        if (-1 < (int)uVar7) {
          return uVar7;
        }
      }
      param_1 = *(ushort **)(iVar8 * 4 + iVar4 + 4);
    }
  }
  return (uint)param_1[2];
}



void FUN_060ba8a8(void)

{
  return;
}



void FUN_060ba998(short param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int local_2c;
  int iStack_28;
  int aiStack_24 [2];
  
  if (param_1 != 0) {
    if (param_1 == -1) {
      param_1 = 0;
    }
    (*(code *)PTR_FUN_060baa98)(0xe);
    *(undefined *)(DAT_060baa92 + DAT_060baa9c) = 8;
    puVar6 = (undefined4 *)(PTR_PTR_s_BGM_XX_CAT_060baaa0 + param_1 * 0xc);
    (*(code *)PTR_FUN_060baaa4)(*puVar6,(int)param_1);
    (*(code *)PTR_FUN_060baaa8)(2,0xe,*puVar6);
    uVar3 = (*(code *)PTR_FUN_060baaac)(*puVar6);
    puVar1 = PTR_FUN_060baab0;
    do {
      iVar4 = (*(code *)puVar1)(uVar3);
    } while (iVar4 == 0);
    (*(code *)PTR_FUN_060baab4)(iVar4,&local_2c,&iStack_28,aiStack_24);
    (*(code *)PTR_FUN_060baabc)
              (iVar4,iStack_28,DAT_060baab8,(iStack_28 + -1) * local_2c + aiStack_24[0]);
    puVar2 = PTR_FUN_060baac4;
    puVar1 = PTR_FUN_060baac0;
    do {
      iVar5 = (*(code *)puVar1)(iVar4);
      (*(code *)puVar2)();
    } while (iVar5 != 0);
    (*(code *)PTR_FUN_060baac8)(iVar4);
    puVar2 = PTR_FUN_060baacc;
    iVar4 = DAT_060baab8;
    puVar1 = PTR_PTR_s_BGM_XX_CAT_060baaa0;
    uVar3 = 0;
    if (1 < param_1) {
      uVar3 = 2;
    }
    (*(code *)PTR_FUN_060baacc)
              (DAT_060baab8,*(undefined4 *)(PTR_PTR_s_BGM_XX_CAT_060baaa0 + param_1 * 0xc + 4),0,
               uVar3);
    uVar3 = 0;
    if (1 < param_1) {
      uVar3 = 2;
    }
    (*(code *)puVar2)(iVar4 + *(int *)(puVar1 + param_1 * 0xc + 4),
                      *(undefined4 *)(puVar1 + param_1 * 0xc + 8),1,uVar3);
    iVar4 = DAT_060baa9c;
    *(undefined *)(DAT_060baa92 + DAT_060baa9c) = 0;
    *(short *)(DAT_060baa94 + iVar4) = param_1;
  }
  return;
}



void FUN_060baad0(undefined4 param_1,undefined2 param_2,undefined2 param_3)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_20;
  uint *apuStack_1c [2];
  
  uVar2 = (*(code *)PTR_FUN_060bab48)();
  (*(code *)PTR_FUN_060bab4c)(&local_20,apuStack_1c,param_2,param_3);
  puVar1 = PTR_FUN_060bab50;
  (*(code *)PTR_FUN_060bab50)(uVar2,3);
  iVar3 = (*(code *)PTR_FUN_060bab54)(param_1,0,local_20,0xffffffff);
  if (iVar3 == -0x17) {
    (*(code *)*DAT_060bab58)();
  }
  (*(code *)puVar1)(uVar2,0);
  (*(code *)PTR_FUN_060bab5c)(uVar2);
  *apuStack_1c[0] = *apuStack_1c[0] | DAT_060bab60;
  return;
}



void FUN_060bad5c(void)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_FUN_060bad7c)();
  if (iVar1 == -0x17) {
    (*(code *)*DAT_060bad80)();
  }
  return;
}



void FUN_060bad84(void)

{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  *DAT_060badf0 = 0;
  puVar3 = DAT_060badf4;
  *(undefined *)(DAT_060badf4 + 1) = 1;
  *(undefined *)(puVar3 + 4) = 2;
  *(undefined *)(puVar3 + 7) = 3;
  *(undefined *)(puVar3 + 10) = 4;
  *(undefined *)(puVar3 + 0xd) = 5;
  *(undefined *)(puVar3 + 0x10) = 6;
  *(undefined *)(puVar3 + 0x13) = 7;
  *(undefined *)(puVar3 + 0x16) = 8;
  puVar1 = PTR_DAT_060badf8;
  iVar4 = 0;
  puVar2 = DAT_060badfc;
  do {
    *puVar2 = 0;
    *puVar3 = 0;
    *(undefined4 *)puVar1 = 0;
    puVar3 = puVar3 + 3;
    iVar4 = iVar4 + 1;
    puVar2 = puVar2 + 1;
  } while (iVar4 < 8);
  return;
}



void FUN_060bae58(undefined param_1)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  puVar3 = PTR_FUN_060baf10;
  puVar2 = PTR_DAT_060baf0c;
  iVar7 = 0;
  do {
    uVar6 = *(uint *)puVar2;
    *(uint *)puVar2 = uVar6 - 1;
    cVar4 = (*(code *)puVar3)(param_1,uVar6 & 0xff);
    if (cVar4 == '\0') break;
    iVar5 = 1;
    do {
      bVar1 = iVar5 <= DAT_060baf0a;
      iVar5 = iVar5 + 1;
    } while (bVar1);
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0x40);
  if (*(int *)PTR_DAT_060baf0c < 1) {
    *(undefined4 *)PTR_DAT_060baf14 = 0;
    puVar2 = PTR_FUN_060baf1c;
    iVar7 = 0;
    if (*(int *)PTR_DAT_060baf18 != 0) {
      do {
        cVar4 = (*(code *)puVar2)(0);
        puVar3 = PTR_FUN_060baf20;
        if (cVar4 == '\0') break;
        iVar5 = 1;
        do {
          bVar1 = iVar5 <= DAT_060baf0a;
          iVar5 = iVar5 + 1;
        } while (bVar1);
        iVar7 = iVar7 + 1;
      } while (iVar7 < 0x40);
      iVar7 = 0;
      do {
        cVar4 = (*(code *)puVar3)(0);
        puVar2 = PTR_DAT_060baf18;
        if (cVar4 == '\0') break;
        iVar5 = 1;
        do {
          bVar1 = iVar5 <= DAT_060baf0a;
          iVar5 = iVar5 + 1;
        } while (bVar1);
        iVar7 = iVar7 + 1;
      } while (iVar7 < 0x40);
      *(undefined4 *)PTR_DAT_060baf14 = 0;
      *(undefined4 *)puVar2 = 0;
    }
  }
  return;
}



void FUN_060baf24(undefined4 param_1,uint param_2)

{
  undefined *puVar1;
  
  *(undefined4 *)PTR_DAT_060baf3c = 1;
  puVar1 = PTR_DAT_060baf40;
  *(uint *)PTR_DAT_060baf44 = param_2 & 0xff;
  *(uint *)puVar1 = param_2 & 0xff;
  return;
}



void FUN_060baf48(undefined param_1)

{
  *(undefined *)(*DAT_060baf58 + 3) = param_1;
  return;
}



uint FUN_060baf5c(uint param_1)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  char cVar6;
  uint uVar5;
  int iVar7;
  undefined2 uVar8;
  int iVar9;
  undefined2 *puVar10;
  short local_14 [4];
  
  puVar10 = (undefined2 *)PTR_DAT_060bb260;
  puVar4 = PTR_FUN_060bb25c;
  puVar3 = PTR_FUN_060bb204;
  puVar2 = PTR_FUN_060bb1ec;
  if (param_1 == 0x12) {
    iVar9 = 0;
    do {
      uVar5 = (*(code *)puVar3)(10);
      if ((uVar5 & 0xff) == 0) {
        return uVar5;
      }
      iVar7 = 1;
      do {
        bVar1 = iVar7 <= DAT_060bb1da;
        iVar7 = iVar7 + 1;
      } while (bVar1);
      iVar9 = iVar9 + 1;
    } while (iVar9 < 0x40);
    return uVar5;
  }
  if ((int)param_1 < 0x13) {
    if (param_1 == 0xf) {
      uVar5 = (*(code *)PTR_FUN_060bb1f8)();
      return uVar5;
    }
    if (0xf < (int)param_1) {
      if (param_1 == 0x10) {
        (*(code *)PTR_FUN_060bb1fc)();
        uVar5 = (*(code *)PTR_FUN_060bb200)();
        return uVar5;
      }
      if (param_1 != 0x11) {
        return param_1;
      }
      uVar5 = (*(code *)PTR_FUN_060bb1e0)(local_14,7);
      puVar2 = PTR_FUN_060bb1ec;
      iVar9 = 0;
      if (local_14[0] == 0) {
        return uVar5;
      }
      do {
        cVar6 = (*(code *)puVar2)(7);
        puVar3 = PTR_FUN_060bb1f0;
        if (cVar6 == '\0') break;
        iVar7 = 1;
        do {
          bVar1 = iVar7 <= DAT_060bb1da;
          iVar7 = iVar7 + 1;
        } while (bVar1);
        iVar9 = iVar9 + 1;
      } while (iVar9 < 0x40);
      iVar9 = 0;
      do {
        uVar5 = (*(code *)puVar3)(7);
        if ((uVar5 & 0xff) == 0) {
          return uVar5;
        }
        iVar7 = 1;
        do {
          bVar1 = iVar7 <= DAT_060bb1da;
          iVar7 = iVar7 + 1;
        } while (bVar1);
        iVar9 = iVar9 + 1;
      } while (iVar9 < 0x40);
      return uVar5;
    }
    if (param_1 != 2) {
      if (param_1 != 0xe) {
        return param_1;
      }
      iVar9 = 0;
      if (*(int *)PTR_DAT_060bb1dc == 0) {
        return 0xe;
      }
      do {
        cVar6 = (*(code *)puVar2)(0);
        puVar3 = PTR_FUN_060bb1f0;
        if (cVar6 == '\0') break;
        iVar7 = 1;
        do {
          bVar1 = iVar7 <= DAT_060bb1da;
          iVar7 = iVar7 + 1;
        } while (bVar1);
        iVar9 = iVar9 + 1;
      } while (iVar9 < 0x40);
      iVar9 = 0;
      do {
        uVar5 = (*(code *)puVar3)(0);
        puVar2 = PTR_DAT_060bb1dc;
        if ((uVar5 & 0xff) == 0) break;
        iVar7 = 1;
        do {
          bVar1 = iVar7 <= DAT_060bb1da;
          iVar7 = iVar7 + 1;
        } while (bVar1);
        iVar9 = iVar9 + 1;
      } while (iVar9 < 0x40);
      *(undefined4 *)PTR_DAT_060bb1f4 = 0;
      *(undefined4 *)puVar2 = 0;
      return uVar5;
    }
    puVar10 = (undefined2 *)PTR_DAT_060bb07c;
    if (*(short *)PTR_DAT_060bb07c == 0) {
      (*(code *)PTR_FUN_060bb080)(*(short *)PTR_DAT_060bb07c == 0);
      puVar2 = PTR_FUN_060bb084;
      iVar9 = 0;
      do {
        cVar6 = (*(code *)puVar2)(7,0x7f);
        puVar3 = PTR_FUN_060bb088;
        if (cVar6 == '\0') break;
        iVar7 = 1;
        do {
          bVar1 = iVar7 <= DAT_060bb078;
          iVar7 = iVar7 + 1;
        } while (bVar1);
        iVar9 = iVar9 + 1;
      } while (iVar9 < 0x40);
      iVar9 = 0;
      do {
        uVar5 = (*(code *)puVar3)(7,0,0x21,1);
        if ((uVar5 & 0xff) == 0) break;
        iVar7 = 1;
        do {
          bVar1 = iVar7 <= DAT_060bb078;
          iVar7 = iVar7 + 1;
        } while (bVar1);
        iVar9 = iVar9 + 1;
      } while (iVar9 < 0x40);
      *(undefined2 *)PTR_DAT_060bb07c = 1;
      return uVar5;
    }
  }
  else {
    if (param_1 == (int)DAT_060bb070) {
      if ((*(int *)PTR_DAT_060bb1dc != 0) &&
         ((*(code *)PTR_FUN_060bb1e0)(local_14,0), local_14[0] != 0)) {
        (*(code *)PTR_FUN_060bb1e4)(0,5);
      }
      uVar5 = (*(code *)PTR_FUN_060bb1e8)(4);
      return uVar5;
    }
    if ((int)DAT_060bb070 < (int)param_1) {
      if (param_1 == (int)DAT_060bb072) {
        uVar5 = (*(code *)PTR_FUN_060bb08c)((int)DAT_060bb07a);
        *(undefined4 *)PTR_DAT_060bb090 = 0xd;
        return uVar5;
      }
      if ((int)DAT_060bb072 < (int)param_1) {
        if (param_1 != (int)DAT_060bb076) {
          return param_1;
        }
        uVar5 = (*(code *)PTR_FUN_060bb08c)(0);
        *(undefined4 *)PTR_DAT_060bb090 = 0;
        return uVar5;
      }
      if (param_1 != (int)DAT_060bb074) {
        return param_1;
      }
      if ((*(int *)PTR_DAT_060bb1dc != 0) &&
         ((*(code *)PTR_FUN_060bb1e0)(local_14,0), local_14[0] != 0)) {
        (*(code *)PTR_FUN_060bb1e4)(0,3);
      }
      uVar5 = (*(code *)PTR_FUN_060bb1e8)(6);
      return uVar5;
    }
    if (param_1 == 0x13) {
      iVar9 = 0;
      do {
        uVar5 = (*(code *)puVar4)(0xf);
        if ((uVar5 & 0xff) == 0) {
          return uVar5;
        }
        iVar7 = 1;
        do {
          bVar1 = iVar7 <= DAT_060bb258;
          iVar7 = iVar7 + 1;
        } while (bVar1);
        iVar9 = iVar9 + 1;
      } while (iVar9 < 0x40);
      return uVar5;
    }
    if (param_1 != 0x16) {
      return param_1;
    }
    if (*(short *)PTR_DAT_060bb260 == 0) {
      uVar5 = (*(code *)PTR_FUN_060bb264)(*(short *)PTR_DAT_060bb260 == 0);
      uVar8 = 1;
      goto LAB_060bb248;
    }
  }
  uVar5 = (*(code *)PTR_FUN_060bb264)(0);
  uVar8 = 0;
LAB_060bb248:
  *puVar10 = uVar8;
  return uVar5;
}



void FUN_060bb268(int param_1)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  int iVar8;
  int iVar9;
  short local_20 [4];
  
  if (*(short *)PTR_DAT_060bb390 == 0) {
    *DAT_060bb394 = 0;
    uVar6 = DAT_060bb384 + param_1;
    if (uVar6 <= (uint)(int)DAT_060bb386) {
      *(uint *)PTR_DAT_060bb398 = uVar6;
      puVar3 = PTR_DAT_060bb3a4;
      puVar2 = PTR_DAT_060bb3a0;
      pbVar7 = PTR_DAT_060bb39c + uVar6 * 4;
      uVar6 = (uint)*pbVar7;
      iVar9 = (int)(char)pbVar7[3];
      *(uint *)PTR_DAT_060bb3a4 = (uint)pbVar7[2];
      *(undefined4 *)puVar2 = *(undefined4 *)puVar3;
      *(uint *)PTR_DAT_060bb3a8 = (uint)pbVar7[1];
      puVar2 = PTR_DAT_060bb3ac;
      *(undefined4 *)PTR_DAT_060bb3ac = 1;
      if (*(int *)PTR_DAT_060bb3b0 != iVar9) {
        *(int *)PTR_DAT_060bb3b0 = iVar9;
        if (*(uint *)PTR_DAT_060bb3b4 == uVar6) {
          *(undefined4 *)puVar2 = 0;
          (*(code *)PTR_FUN_060bb3b8)(local_20,0);
          puVar2 = PTR_FUN_060bb3bc;
          iVar8 = 0;
          if (local_20[0] != 0) {
            do {
              cVar4 = (*(code *)puVar2)(0);
              puVar3 = PTR_FUN_060bb3c0;
              if (cVar4 == '\0') break;
              iVar5 = 1;
              do {
                bVar1 = iVar5 <= DAT_060bb388;
                iVar5 = iVar5 + 1;
              } while (bVar1);
              iVar8 = iVar8 + 1;
            } while (iVar8 < 0x40);
            iVar8 = 0;
            do {
              cVar4 = (*(code *)puVar3)(0);
              if (cVar4 == '\0') break;
              iVar5 = 1;
              do {
                bVar1 = iVar5 <= DAT_060bb388;
                iVar5 = iVar5 + 1;
              } while (bVar1);
              iVar8 = iVar8 + 1;
            } while (iVar8 < 0x40);
          }
        }
        else {
          *(uint *)PTR_DAT_060bb3b4 = uVar6;
        }
      }
      if (0x39 < *(int *)PTR_DAT_060bb398) {
        return;
      }
      *DAT_060bb3c4 = uVar6 * 0x100 + iVar9 | (int)DAT_060bb38a;
    }
    uVar6 = DAT_060bb38c + param_1;
    if ((uVar6 <= (uint)(int)DAT_060bb386) &&
       (*(uint *)PTR_DAT_060bb398 = uVar6, (int)uVar6 <= (int)DAT_060bb38e)) {
      (*(code *)PTR_FUN_060bb3c8)();
    }
  }
  else {
    *DAT_060bb394 = param_1;
  }
  return;
}



undefined4 FUN_060bb3cc(int param_1)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 uVar4;
  char cVar5;
  int iVar6;
  int *piVar7;
  byte *pbVar8;
  int local_28;
  int iStack_24;
  
  puVar2 = PTR_DAT_060bb46c;
  if ((uint)(param_1 + DAT_060bb452) < 0x16) {
    (*(code *)PTR_FUN_060bb460)();
    uVar4 = 0;
  }
  else if (DAT_060bb454 < param_1) {
    (*(code *)PTR_FUN_060bb464)(param_1 + DAT_060bb456);
    uVar4 = 0;
  }
  else if (DAT_060bb458 < param_1) {
    (*(code *)PTR_FUN_060bb468)(param_1 + DAT_060bb45a);
    uVar4 = 0;
  }
  else {
    iVar6 = (int)DAT_060bb45c;
    *(int *)PTR_DAT_060bb46c = iVar6 + param_1;
    puVar3 = PTR_DAT_060bb470;
    pbVar8 = PTR_DAT_060bb470 + (iVar6 + param_1) * 0x10;
    bVar1 = pbVar8[9];
    piVar7 = (int *)(DAT_060bb474 + (uint)bVar1 * 0xc);
    if (*(int *)(pbVar8 + 4) < *piVar7) {
      uVar4 = 2;
    }
    else {
      if (*piVar7 != 0) {
        (*(code *)PTR_FUN_060bb580)(*(undefined *)(piVar7 + 1));
      }
      iVar6 = *(int *)puVar2;
      *piVar7 = *(int *)(puVar3 + iVar6 * 0x10 + 4);
      *(undefined *)(piVar7 + 1) = puVar3[iVar6 * 0x10 + 9];
      piVar7[2] = (uint)*pbVar8;
      local_28 = 0;
      *(undefined4 *)(DAT_060bb584 + (uint)bVar1 * 4) =
           *(undefined4 *)(puVar3 + *(int *)puVar2 * 0x10 + 0xc);
      puVar2 = PTR_FUN_060bb588;
      do {
        cVar5 = (*(code *)puVar2)(*(undefined *)(piVar7 + 1),pbVar8[8]);
        puVar3 = PTR_FUN_060bb58c;
        if (cVar5 == '\0') break;
        iStack_24 = 0;
        if (-1 < DAT_060bb57c) {
          do {
            iStack_24 = iStack_24 + 1;
          } while (iStack_24 <= DAT_060bb57c);
        }
        local_28 = local_28 + 1;
      } while (local_28 < 0x40);
      local_28 = 0;
      do {
        cVar5 = (*(code *)puVar3)(*(undefined *)(piVar7 + 1),*pbVar8,pbVar8[1],0);
        if (cVar5 == '\0') break;
        iStack_24 = 0;
        if (-1 < DAT_060bb57c) {
          do {
            iStack_24 = iStack_24 + 1;
          } while (iStack_24 <= DAT_060bb57c);
        }
        local_28 = local_28 + 1;
      } while (local_28 < 0x40);
      uVar4 = 0;
    }
  }
  return uVar4;
}



void FUN_060bb590(void)

{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  puVar1 = PTR_DAT_060bb640;
  if (*(int *)PTR_DAT_060bb63c == 0) {
    iVar6 = 0;
    uVar8 = (uint)DAT_060bb634;
    iVar7 = (int)DAT_060bb636;
    do {
      iVar2 = *(int *)puVar1;
      if (*(int *)PTR_DAT_060bb644 != iVar2) {
        *(int *)puVar1 = iVar2 + 1;
        iVar5 = *(int *)(DAT_060bb648 + iVar2 * 4);
        if (0x3f < iVar2 + 1) {
          *(undefined4 *)puVar1 = 0;
        }
        if (uVar8 < iVar5 - 2U) {
          if ((uint)(iVar5 + iVar7) <= (uint)(int)DAT_060bb638) {
            (*(code *)PTR_FUN_060bb650)();
          }
        }
        else {
          (*(code *)PTR_FUN_060bb64c)();
        }
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 4);
  }
  iVar6 = 0;
  piVar3 = DAT_060bb65c;
  puVar4 = DAT_060bb658;
  if (*(int *)PTR_DAT_060bb654 == 0) {
    do {
      if (*piVar3 < 1) {
        *puVar4 = 0;
      }
      else {
        *piVar3 = *piVar3 + -1;
      }
      iVar6 = iVar6 + 1;
      piVar3 = piVar3 + 1;
      puVar4 = puVar4 + 3;
    } while (iVar6 < 8);
  }
  return;
}



void FUN_060bb678(void)

{
  ushort uVar1;
  bool bVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined2 *puVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  short local_18 [4];
  
  (*(code *)PTR_FUN_060bb81c)();
  (*(code *)PTR_FUN_060bb820)();
  (*(code *)PTR_FUN_060bb824)();
  puVar3 = PTR_DAT_060bb82c;
  if ((*(int *)PTR_DAT_060bb828 != 0) &&
     (iVar8 = *(int *)PTR_DAT_060bb82c, *(int *)PTR_DAT_060bb82c = iVar8 + -1, iVar8 < 1)) {
    *(undefined4 *)puVar3 = *(undefined4 *)PTR_DAT_060bb830;
    (*(code *)PTR_FUN_060bb834)(0,1);
  }
  if (*(int *)PTR_DAT_060bb838 == 0) {
    *(uint *)PTR_DAT_060bb838 = (uint)(*(int *)PTR_DAT_060bb838 == 0);
    if (*(int *)PTR_DAT_060bb83c == 0) {
      (*(code *)PTR_FUN_060bb840)();
    }
    if (*(int *)PTR_DAT_060bb844 == 0) {
      (*(code *)PTR_FUN_060bb848)();
    }
    if ((*(int *)PTR_DAT_060bb84c == 0) && ((*(uint *)PTR_DAT_060bb850 & 8) == 0)) {
      (*(code *)PTR_FUN_060bb854)();
    }
    *(undefined4 *)PTR_DAT_060bb838 = 0;
  }
  if (((*DAT_060bb858 & DAT_060bb85c) == 0) && (((int)DAT_060bb816 & *DAT_060bb858) != 0)) {
    if (*(int *)PTR_DAT_060bb860 != 0) {
      (*(code *)PTR_FUN_060bb864)(local_18,0);
      puVar3 = PTR_FUN_060bb868;
      iVar8 = 0;
      if (local_18[0] != 0) {
        do {
          cVar6 = (*(code *)puVar3)(0);
          puVar4 = PTR_FUN_060bb86c;
          if (cVar6 == '\0') break;
          iVar7 = 1;
          do {
            bVar2 = iVar7 <= DAT_060bb818;
            iVar7 = iVar7 + 1;
          } while (bVar2);
          iVar8 = iVar8 + 1;
        } while (iVar8 < 0x40);
        iVar8 = 0;
        do {
          cVar6 = (*(code *)puVar4)(0);
          if (cVar6 == '\0') break;
          iVar7 = 1;
          do {
            bVar2 = iVar7 <= DAT_060bb818;
            iVar7 = iVar7 + 1;
          } while (bVar2);
          iVar8 = iVar8 + 1;
        } while (iVar8 < 0x40);
      }
    }
    puVar3 = PTR_FUN_060bb870;
    iVar8 = 0;
    do {
      cVar6 = (*(code *)puVar3)(0,*(uint *)PTR_DAT_060bb874 & 0xff);
      puVar4 = PTR_FUN_060bb878;
      if (cVar6 == '\0') break;
      iVar7 = 1;
      do {
        bVar2 = iVar7 <= DAT_060bb818;
        iVar7 = iVar7 + 1;
      } while (bVar2);
      iVar8 = iVar8 + 1;
    } while (iVar8 < 0x40);
    iVar8 = 0;
    do {
      cVar6 = (*(code *)puVar4)(0,*(uint *)PTR_DAT_060bb880 & 0xff,*(uint *)PTR_DAT_060bb87c & 0xff,
                                1);
      if (cVar6 == '\0') break;
      iVar7 = 1;
      do {
        bVar2 = iVar7 <= DAT_060bb818;
        iVar7 = iVar7 + 1;
      } while (bVar2);
      iVar8 = iVar8 + 1;
    } while (iVar8 < 0x40);
    *(undefined4 *)PTR_DAT_060bb884 = 1;
    *DAT_060bb858 = *DAT_060bb858 & DAT_060bb888;
  }
  puVar5 = DAT_060bb894;
  puVar3 = PTR_DAT_060bb88c;
  if (*(short *)PTR_DAT_060bb88c != *(short *)PTR_DAT_060bb890) {
    uVar1 = *(ushort *)PTR_DAT_060bb88c;
    *(ushort *)PTR_DAT_060bb88c = uVar1 + 1;
    *puVar5 = *(undefined2 *)(DAT_060bb898 + (uint)uVar1 * 2);
    if ((uint)(int)DAT_060bb81a < (uint)*(ushort *)puVar3) {
      *(undefined2 *)puVar3 = 0;
    }
  }
  return;
}



void FUN_060bb8a8(int param_1)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  char cVar4;
  int iVar5;
  code *pcVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  
  puVar3 = PTR_FUN_060bb950;
  puVar2 = PTR_FUN_060bb94c;
  if (param_1 == 1) {
    uVar8 = 0;
    iVar9 = 0;
    do {
      iVar7 = 0;
      do {
        cVar4 = (*(code *)puVar2)(uVar8 & 0xff);
        if (cVar4 == '\0') break;
        iVar5 = 1;
        do {
          bVar1 = iVar5 <= DAT_060bb94a;
          iVar5 = iVar5 + 1;
        } while (bVar1);
        iVar7 = iVar7 + 1;
      } while (iVar7 < 0x40);
      iVar7 = 0;
      do {
        cVar4 = (*(code *)puVar3)(uVar8 & 0xff);
        if (cVar4 == '\0') break;
        iVar5 = 1;
        do {
          bVar1 = iVar5 <= DAT_060bb94a;
          iVar5 = iVar5 + 1;
        } while (bVar1);
        iVar7 = iVar7 + 1;
      } while (iVar7 < 0x40);
      *(undefined4 *)(DAT_060bb954 + iVar9) = 0;
      uVar8 = uVar8 + 1;
      iVar9 = iVar9 + 0xc;
      pcVar6 = (code *)PTR_FUN_060bb958;
      iVar7 = param_1;
    } while ((int)uVar8 < 8);
  }
  else {
    pcVar6 = (code *)PTR_FUN_060bb960;
    iVar7 = *DAT_060bb95c;
    if (*DAT_060bb95c == 0) {
      pcVar6 = (code *)PTR_FUN_060bb958;
      iVar7 = param_1;
    }
  }
  (*pcVar6)(iVar7);
  return;
}



void FUN_060bb964(void)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  (*(code *)PTR_FUN_060bba50)();
  (*(code *)PTR_FUN_060bba54)();
  (*(code *)PTR_FUN_060bba58)();
  puVar2 = PTR_FUN_060bba60;
  iVar7 = 0;
  if (*(int *)PTR_DAT_060bba5c != 0) {
    do {
      cVar4 = (*(code *)puVar2)(0);
      puVar3 = PTR_FUN_060bba64;
      if (cVar4 == '\0') break;
      iVar5 = 1;
      do {
        bVar1 = iVar5 <= DAT_060bba4e;
        iVar5 = iVar5 + 1;
      } while (bVar1);
      iVar7 = iVar7 + 1;
    } while (iVar7 < 0x40);
    iVar7 = 0;
    do {
      cVar4 = (*(code *)puVar3)(0);
      puVar2 = PTR_DAT_060bba5c;
      if (cVar4 == '\0') break;
      iVar5 = 1;
      do {
        bVar1 = iVar5 <= DAT_060bba4e;
        iVar5 = iVar5 + 1;
      } while (bVar1);
      iVar7 = iVar7 + 1;
    } while (iVar7 < 0x40);
    *(undefined4 *)PTR_DAT_060bba68 = 0;
    *(undefined4 *)puVar2 = 0;
  }
  puVar3 = PTR_FUN_060bba64;
  puVar2 = PTR_FUN_060bba60;
  uVar8 = 0;
  iVar7 = 0;
  do {
    iVar5 = 0;
    do {
      cVar4 = (*(code *)puVar2)(uVar8 & 0xff);
      if (cVar4 == '\0') break;
      iVar6 = 1;
      do {
        bVar1 = iVar6 <= DAT_060bba4e;
        iVar6 = iVar6 + 1;
      } while (bVar1);
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0x40);
    iVar5 = 0;
    do {
      cVar4 = (*(code *)puVar3)(uVar8 & 0xff);
      if (cVar4 == '\0') break;
      iVar6 = 1;
      do {
        bVar1 = iVar6 <= DAT_060bba4e;
        iVar6 = iVar6 + 1;
      } while (bVar1);
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0x40);
    *(undefined4 *)(DAT_060bba6c + iVar7) = 0;
    uVar8 = uVar8 + 1;
    iVar7 = iVar7 + 0xc;
    if (7 < (int)uVar8) {
      (*(code *)PTR_FUN_060bba70)();
      return;
    }
  } while( true );
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_060bba74(int param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  
  *(undefined4 *)PTR_DAT_060bbaec = 1;
  puVar1 = PTR_DAT_060bbaf8;
  if ((uint)(int)DAT_060bbae0 < param_1 - 2U) {
    if ((uint)(int)DAT_060bbae4 < (uint)(param_1 + DAT_060bbae2)) {
      if ((uint)(param_1 + DAT_060bbae6) <= (uint)(int)DAT_060bbae8) {
        iVar2 = *(int *)PTR_DAT_060bbaf8;
        iVar3 = iVar2 + 1;
        *(int *)PTR_DAT_060bbaf8 = iVar3;
        *(int *)(_DAT_060bbafc + iVar2 * 4) = param_1;
        if (0x3f < iVar3) {
          *(undefined4 *)puVar1 = 0;
        }
      }
    }
    else {
      (*(code *)PTR_FUN_060bbaf4)();
    }
  }
  else {
    (*(code *)PTR_FUN_060bbaf0)();
  }
  *(undefined4 *)PTR_DAT_060bbaec = 0;
  return;
}



void FUN_060bbd10(void)

{
  undefined4 uVar1;
  int iVar2;
  int extraout_r2;
  undefined4 auStack_bc [45];
  
  (*(code *)PTR_FUN_060bbd68)(auStack_bc,PTR_PTR_s_ADPCM_XX_CAT_060bbd64,0x14);
  iVar2 = (int)DAT_060bbd60;
  uVar1 = (*(code *)PTR_FUN_060bbd6c)(auStack_bc[(extraout_r2 + iVar2) * 2]);
  (*(code *)PTR_FUN_060bbd70)(uVar1,0,auStack_bc[(extraout_r2 + iVar2) * 2 + 1],0xffffffff);
  return;
}



void FUN_060bbde8(void)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 uVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  undefined4 local_5c;
  undefined2 local_58;
  undefined4 uStack_54;
  undefined2 local_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  puVar2 = PTR_FUN_060bbf68;
  uStack_4c = *(undefined4 *)PTR_PTR_s_SDDRVS6_TSK_060bbf64;
  uStack_48 = *(undefined4 *)(PTR_PTR_s_SDDRVS6_TSK_060bbf64 + 4);
  uStack_44 = *(undefined4 *)(PTR_PTR_s_SDDRVS6_TSK_060bbf64 + 8);
  uStack_40 = *(undefined4 *)(PTR_PTR_s_SDDRVS6_TSK_060bbf64 + 0xc);
  uStack_3c = *(undefined4 *)(PTR_PTR_s_SDDRVS6_TSK_060bbf64 + 0x10);
  uStack_38 = *(undefined4 *)(PTR_PTR_s_SDDRVS6_TSK_060bbf64 + 0x14);
  uStack_34 = *(undefined4 *)(PTR_PTR_s_SDDRVS6_TSK_060bbf64 + 0x18);
  uStack_30 = *(undefined4 *)(PTR_PTR_s_SDDRVS6_TSK_060bbf64 + 0x1c);
  uStack_2c = *(undefined4 *)(PTR_PTR_s_SDDRVS6_TSK_060bbf64 + 0x20);
  uStack_28 = *(undefined4 *)(PTR_PTR_s_SDDRVS6_TSK_060bbf64 + 0x24);
  uStack_24 = *(undefined4 *)(PTR_PTR_s_SDDRVS6_TSK_060bbf64 + 0x28);
  uStack_20 = *(undefined4 *)(PTR_PTR_s_SDDRVS6_TSK_060bbf64 + 0x2c);
  local_1c = *(undefined4 *)(PTR_PTR_s_SDDRVS6_TSK_060bbf64 + 0x30);
  local_18 = *(undefined4 *)(PTR_PTR_s_SDDRVS6_TSK_060bbf64 + 0x34);
  local_14 = *(undefined4 *)(PTR_PTR_s_SDDRVS6_TSK_060bbf64 + 0x38);
  uVar4 = (*(code *)PTR_FUN_060bbf68)(uStack_40);
  puVar3 = PTR_FUN_060bbf6c;
  (*(code *)PTR_FUN_060bbf6c)(uVar4,0,uStack_3c,0xffffffff);
  uVar4 = (*(code *)puVar2)(uStack_4c);
  (*(code *)puVar3)(uVar4,0,uStack_48,0xffffffff);
  local_5c = uStack_48;
  local_58 = uStack_44._2_2_;
  uStack_54 = uStack_3c;
  local_50 = uStack_38._2_2_;
  (*(code *)PTR_FUN_060bbf70)(&local_5c);
  puVar2 = PTR_FUN_060bbf74;
  iVar7 = 0;
  do {
    cVar5 = (*(code *)puVar2)();
    puVar3 = PTR_FUN_060bbf78;
    if (cVar5 == '\0') break;
    iVar6 = 1;
    do {
      bVar1 = iVar6 <= DAT_060bbf5e;
      iVar6 = iVar6 + 1;
    } while (bVar1);
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0x40);
  iVar7 = 0;
  do {
    cVar5 = (*(code *)puVar3)();
    puVar2 = PTR_FUN_060bbf7c;
    if (cVar5 == '\0') break;
    iVar6 = 1;
    do {
      bVar1 = iVar6 <= DAT_060bbf5e;
      iVar6 = iVar6 + 1;
    } while (bVar1);
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0x40);
  iVar7 = 0;
  do {
    cVar5 = (*(code *)puVar2)(0);
    puVar3 = PTR_FUN_060bbf68;
    if (cVar5 == '\0') break;
    iVar6 = 1;
    do {
      bVar1 = iVar6 <= DAT_060bbf5e;
      iVar6 = iVar6 + 1;
    } while (bVar1);
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0x40);
  uVar4 = (*(code *)PTR_FUN_060bbf68)(uStack_34);
  puVar2 = PTR_FUN_060bbf80;
  (*(code *)PTR_FUN_060bbf80)(uVar4,2,0);
  uVar4 = (*(code *)puVar3)(uStack_28);
  (*(code *)puVar2)(uVar4,1,1);
  puVar2 = PTR_FUN_060bbf84;
  iVar7 = 0;
  do {
    cVar5 = (*(code *)puVar2)(0);
    if (cVar5 == '\0') break;
    iVar6 = 1;
    do {
      bVar1 = iVar6 <= DAT_060bbf5e;
      iVar6 = iVar6 + 1;
    } while (bVar1);
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0x40);
  *(undefined4 *)PTR_DAT_060bbf88 = 1;
  uVar4 = (*(code *)PTR_FUN_060bbf68)(local_1c);
  (*(code *)PTR_FUN_060bbf80)(uVar4,0,1);
  puVar2 = PTR_FUN_060bbf8c;
  (*(code *)PTR_FUN_060bbf8c)((int)DAT_060bbf60);
  (*(code *)puVar2)((int)DAT_060bbf62);
  return;
}



void FUN_060bbf90(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  
  puVar5 = PTR_DAT_060bbfe8;
  puVar4 = PTR_DAT_060bbfe4;
  puVar3 = PTR_DAT_060bbfe0;
  puVar2 = PTR_DAT_060bbfdc;
  puVar1 = PTR_DAT_060bbfd8;
  *PTR_DAT_060bbfec = 8;
  *puVar5 = 8;
  *puVar4 = 8;
  *puVar3 = 8;
  *puVar2 = 8;
  *puVar1 = 8;
  puVar1 = PTR_DAT_060bbff0;
  *(undefined4 *)PTR_DAT_060bbff4 = 0;
  *(undefined4 *)puVar1 = 0;
  *(undefined2 *)PTR_DAT_060bbff8 = 0;
  *(undefined4 *)PTR_DAT_060bbffc = 0;
  (*(code *)PTR_FUN_060bc000)();
  (*(code *)PTR_FUN_060bc004)();
  return;
}



void FUN_060bc008(undefined4 param_1)

{
  if (*(int *)PTR_DAT_060bc028 == 0) {
    *(uint *)PTR_DAT_060bc028 = (uint)(*(int *)PTR_DAT_060bc028 == 0);
    *(undefined4 *)PTR_DAT_060bc02c = param_1;
    *(undefined4 *)PTR_DAT_060bc030 = param_1;
  }
  return;
}



void FUN_060bc034(void)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  
  puVar2 = PTR_DAT_060bc134;
  if (*(int *)PTR_DAT_060bc12c != 0) {
    if (*(int *)PTR_DAT_060bc130 == 0) {
      if ((*(uint *)PTR_DAT_060bc134 < 0x7f) &&
         (iVar5 = *(uint *)PTR_DAT_060bc134 + 2, *(int *)PTR_DAT_060bc134 = iVar5, 0x7f < iVar5)) {
        *(undefined4 *)puVar2 = 0x7f;
      }
      *(undefined4 *)PTR_DAT_060bc130 = *(undefined4 *)PTR_DAT_060bc138;
      iVar5 = *(int *)PTR_DAT_060bc134;
      uVar7 = 0;
      if ((((10 < iVar5 - 0x75U) && (uVar7 = 1, 0xf < iVar5 - 0x65U)) &&
          (uVar7 = 2, 0xf < iVar5 - 0x55U)) &&
         ((uVar7 = 3, 0xf < iVar5 - 0x45U && (uVar7 = 4, 0x10 < iVar5 - 0x34U)))) {
        if (iVar5 - 0x23U < 0x11) {
          uVar7 = 5;
        }
        else {
          uVar7 = 7;
          if (iVar5 - 0x12U < 0x11) {
            uVar7 = 6;
          }
        }
      }
      (*(code *)PTR_FUN_060bc140)(*DAT_060bc13c,uVar7);
      puVar3 = PTR_FUN_060bc148;
      puVar2 = DAT_060bc144;
      iVar5 = 0;
      do {
        cVar4 = (*(code *)puVar3)(0,*puVar2);
        if (cVar4 == '\0') break;
        iVar6 = 1;
        do {
          bVar1 = iVar6 <= DAT_060bc128;
          iVar6 = iVar6 + 1;
        } while (bVar1);
        iVar5 = iVar5 + 1;
      } while (iVar5 < 0x40);
      if ((*(int *)PTR_DAT_060bc134 == 0x7f) &&
         (*(undefined4 *)PTR_DAT_060bc12c = 0, *DAT_060bc14c == 1)) {
        (*(code *)PTR_FUN_060bc150)();
      }
    }
    else {
      *(int *)PTR_DAT_060bc130 = *(int *)PTR_DAT_060bc130 + -1;
    }
  }
  return;
}



void FUN_060bc1dc(int param_1)

{
  undefined *puVar1;
  int *piVar2;
  
  puVar1 = PTR_DAT_060bc24c;
  *(undefined4 *)PTR_DAT_060bc24c = 1;
  piVar2 = DAT_060bc250;
  if (*DAT_060bc250 == 1) {
    (*(code *)PTR_FUN_060bc254)();
  }
  (*(code *)PTR_FUN_060bc258)();
  (*(code *)PTR_FUN_060bc25c)();
  *DAT_060bc260 = 1;
  *DAT_060bc264 = 0;
  *DAT_060bc268 = 0;
  *DAT_060bc26c = 0;
  *DAT_060bc270 = param_1;
  *DAT_060bc274 = 1;
  *piVar2 = 1;
  *DAT_060bc278 = *(undefined4 *)(PTR_DAT_060bc27c + param_1 * 0xc + 4);
  *(undefined4 *)puVar1 = 0;
  return;
}



void FUN_060bc280(void)

{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR_DAT_060bc2d4;
  *(undefined4 *)PTR_DAT_060bc2d4 = 1;
  if (*DAT_060bc2d8 == 1) {
    *DAT_060bc2d8 = 0;
    puVar2 = DAT_060bc2dc;
    (*(code *)PTR_FUN_060bc2e0)(*DAT_060bc2dc);
    (*(code *)PTR_FUN_060bc2e4)(*puVar2);
    (*(code *)PTR_FUN_060bc2ec)(*DAT_060bc2e8);
    (*(code *)PTR_FUN_060bc2f4)(*DAT_060bc2f0);
  }
  *DAT_060bc2f8 = 0;
  *(undefined4 *)puVar1 = 0;
  return;
}



void FUN_060bc2fc(void)

{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR_DAT_060bc368;
  *(undefined4 *)PTR_DAT_060bc368 = 1;
  if (*DAT_060bc36c == 1) {
    *DAT_060bc36c = 0;
    puVar2 = DAT_060bc370;
    (*(code *)PTR_FUN_060bc374)(*DAT_060bc370);
    (*(code *)PTR_FUN_060bc378)(*puVar2);
    (*(code *)PTR_FUN_060bc380)(*DAT_060bc37c);
    (*(code *)PTR_FUN_060bc388)(*DAT_060bc384);
  }
  *DAT_060bc38c = 0;
  if (*DAT_060bc390 == (int)DAT_060bc364) {
    (*(code *)PTR_FUN_060bc398)(*DAT_060bc394);
  }
  *(undefined4 *)puVar1 = 0;
  return;
}



void FUN_060bc39c(void)

{
  (*(code *)PTR_FUN_060bc3b0)();
  return;
}



void FUN_060bc3b4(void)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  int *piVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  
  puVar2 = PTR_FUN_060bc4ec;
  iVar7 = *(int *)PTR_DAT_060bc4e8;
  if (iVar7 != 0) {
    if (iVar7 < 0x3d) {
      *(int *)PTR_DAT_060bc4e8 = iVar7 + 1;
    }
    else {
      iVar7 = 0;
      do {
        cVar5 = (*(code *)puVar2)(0,0);
        puVar3 = PTR_FUN_060bc4f0;
        if (cVar5 == '\0') break;
        iVar6 = 1;
        do {
          bVar1 = iVar6 <= DAT_060bc4e4;
          iVar6 = iVar6 + 1;
        } while (bVar1);
        iVar7 = iVar7 + 1;
      } while (iVar7 < 0x40);
      iVar7 = 0;
      do {
        cVar5 = (*(code *)puVar3)(0,7,0xfffffff1);
        puVar2 = PTR_FUN_060bc4f0;
        if (cVar5 == '\0') break;
        iVar6 = 1;
        do {
          bVar1 = iVar6 <= DAT_060bc4e4;
          iVar6 = iVar6 + 1;
        } while (bVar1);
        iVar7 = iVar7 + 1;
      } while (iVar7 < 0x40);
      iVar7 = 0;
      do {
        cVar5 = (*(code *)puVar2)(1,7,0xf);
        puVar3 = PTR_FUN_060bc4ec;
        if (cVar5 == '\0') break;
        iVar6 = 1;
        do {
          bVar1 = iVar6 <= DAT_060bc4e4;
          iVar6 = iVar6 + 1;
        } while (bVar1);
        iVar7 = iVar7 + 1;
      } while (iVar7 < 0x40);
      iVar7 = 0;
      do {
        cVar5 = (*(code *)puVar3)(1,0);
        puVar2 = PTR_FUN_060bc4f0;
        if (cVar5 == '\0') break;
        iVar6 = 1;
        do {
          bVar1 = iVar6 <= DAT_060bc4e4;
          iVar6 = iVar6 + 1;
        } while (bVar1);
        iVar7 = iVar7 + 1;
      } while (iVar7 < 0x40);
      iVar7 = 0;
      do {
        cVar5 = (*(code *)puVar2)(0,7,0xfffffff1);
        puVar3 = PTR_FUN_060bc4f0;
        if (cVar5 == '\0') break;
        iVar6 = 1;
        do {
          bVar1 = iVar6 <= DAT_060bc4e4;
          iVar6 = iVar6 + 1;
        } while (bVar1);
        iVar7 = iVar7 + 1;
      } while (iVar7 < 0x40);
      iVar7 = 0;
      do {
        cVar5 = (*(code *)puVar3)(1,7,0xf);
        puVar2 = PTR_FUN_060bc4ec;
        if (cVar5 == '\0') break;
        iVar6 = 1;
        do {
          bVar1 = iVar6 <= DAT_060bc4e4;
          iVar6 = iVar6 + 1;
        } while (bVar1);
        iVar7 = iVar7 + 1;
      } while (iVar7 < 0x40);
      iVar7 = 0;
      do {
        cVar5 = (*(code *)puVar2)(2,0);
        puVar3 = PTR_FUN_060bc5c8;
        if (cVar5 == '\0') break;
        iVar6 = 1;
        do {
          bVar1 = iVar6 <= DAT_060bc4e4;
          iVar6 = iVar6 + 1;
        } while (bVar1);
        iVar7 = iVar7 + 1;
      } while (iVar7 < 0x40);
      iVar7 = 0;
      do {
        cVar5 = (*(code *)puVar3)(0,7,0xfffffff1);
        puVar2 = PTR_FUN_060bc5c8;
        if (cVar5 == '\0') break;
        iVar6 = 1;
        do {
          bVar1 = iVar6 <= DAT_060bc5c4;
          iVar6 = iVar6 + 1;
        } while (bVar1);
        iVar7 = iVar7 + 1;
      } while (iVar7 < 0x40);
      iVar7 = 0;
      do {
        cVar5 = (*(code *)puVar2)(1,7,0xf);
        if (cVar5 == '\0') break;
        iVar6 = 1;
        do {
          bVar1 = iVar6 <= DAT_060bc5c4;
          iVar6 = iVar6 + 1;
        } while (bVar1);
        iVar7 = iVar7 + 1;
      } while (iVar7 < 0x40);
      *(undefined4 *)PTR_DAT_060bc5cc = 0;
    }
  }
  piVar4 = DAT_060bc5d4;
  if (*DAT_060bc5d0 == 1) {
    if (*DAT_060bc5d4 == 1) {
      (*(code *)PTR_FUN_060bc5dc)(*DAT_060bc5d8);
      *piVar4 = 0;
    }
    iVar7 = 0;
    (*(code *)PTR_FUN_060bc5e0)(*DAT_060bc5d8);
    puVar3 = PTR_FUN_060bc5e8;
    puVar2 = DAT_060bc5e4;
    do {
      cVar5 = (*(code *)puVar3)(0,*puVar2);
      if (cVar5 == '\0') break;
      iVar6 = 1;
      do {
        bVar1 = iVar6 <= DAT_060bc5c4;
        iVar6 = iVar6 + 1;
      } while (bVar1);
      iVar7 = iVar7 + 1;
    } while (iVar7 < 0x40);
    iVar7 = (*(code *)PTR_FUN_060bc5f0)(*DAT_060bc5ec);
    if (iVar7 != 0) {
      (*(code *)PTR_FUN_060bc5f4)();
    }
  }
  return;
}



undefined4 FUN_060bc5f8(uint param_1)

{
  bool bVar1;
  int *piVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  char cVar6;
  int iVar7;
  undefined4 uVar8;
  
  piVar2 = DAT_060bc74c;
  uVar8 = 0;
  iVar5 = (*(code *)PTR_FUN_060bc750)((int)*(short *)((int)DAT_060bc74c + 2));
  *DAT_060bc754 = iVar5;
  if (iVar5 != 0) {
    iVar5 = (*(code *)PTR_FUN_060bc75c)
                      (iVar5,param_1 + ((int)(((param_1 >> 0x10) * 2 >> 0x10) + param_1) >> 1) * -2,
                       *DAT_060bc758 == 0);
    *DAT_060bc760 = iVar5;
    if (iVar5 != 0) {
      (*(code *)PTR_FUN_060bc764)(iVar5,0);
      iVar5 = *(int *)(PTR_DAT_060bc768 + *piVar2 * 0xc + 8) + *(int *)PTR_DAT_060bc76c;
      *(int *)PTR_DAT_060bc770 = iVar5;
      piVar2 = DAT_060bc760;
      if ((((10 < iVar5 - 0x75U) && (uVar8 = 1, 0xf < iVar5 - 0x65U)) &&
          (uVar8 = 2, 0xf < iVar5 - 0x55U)) &&
         ((uVar8 = 3, 0xf < iVar5 - 0x45U && (uVar8 = 4, 0x10 < iVar5 - 0x34U)))) {
        if (iVar5 - 0x23U < 0x11) {
          uVar8 = 5;
        }
        else {
          uVar8 = 7;
          if (iVar5 - 0x12U < 0x11) {
            uVar8 = 6;
          }
        }
      }
      (*(code *)PTR_FUN_060bc774)(*DAT_060bc760,uVar8);
      (*(code *)PTR_FUN_060bc778)(*piVar2,2);
      (*(code *)PTR_FUN_060bc77c)(*piVar2,3);
      (*(code *)PTR_FUN_060bc780)(*piVar2,(int)DAT_060bc746);
      if (*DAT_060bc758 == 0) {
        (*(code *)PTR_FUN_060bc784)(*piVar2);
        puVar4 = PTR_DAT_060bc78c;
        puVar3 = PTR_DAT_060bc788;
        *(undefined4 *)PTR_DAT_060bc790 = 0;
        *(undefined4 *)puVar4 = 0;
        *(undefined4 *)puVar3 = 0;
        puVar4 = PTR_FUN_060bc798;
        puVar3 = DAT_060bc794;
        iVar5 = 0;
        do {
          cVar6 = (*(code *)puVar4)(0,*puVar3);
          if (cVar6 == '\0') break;
          iVar7 = 1;
          do {
            bVar1 = iVar7 <= DAT_060bc748;
            iVar7 = iVar7 + 1;
          } while (bVar1);
          iVar5 = iVar5 + 1;
        } while (iVar5 < 0x40);
        *DAT_060bc758 = 1;
      }
      else {
        (*(code *)PTR_FUN_060bc79c)(*piVar2);
      }
      return 1;
    }
  }
  return 0;
}



int FUN_060bc7a0(undefined4 param_1,int param_2)

{
  int iVar1;
  int local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  local_1c = param_2 * DAT_060bc7e4 + DAT_060bc7e8;
  uStack_18 = *(undefined4 *)(PTR_DAT_060bc7f0 + param_2 * 4);
  uStack_14 = DAT_060bc7ec;
  uStack_10 = DAT_060bc7f4;
  uStack_c = 0x2000;
  iVar1 = (*(code *)PTR_FUN_060bc7f8)(&local_1c,param_1);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  return iVar1;
}



void FUN_060bc7fc(void)

{
  ushort *puVar1;
  ushort *puVar2;
  int iVar3;
  int extraout_r2;
  ushort uVar4;
  
  (*(code *)PTR_FUN_060bc85c)();
  puVar1 = DAT_060bc864;
  *DAT_060bc860 = DAT_060bc864;
  puVar2 = DAT_060bc868;
  uVar4 = *puVar1;
  *DAT_060bc868 = uVar4;
  if (((int)(short)*puVar2 & DAT_060bc86c) != 0) {
    *puVar2 = -uVar4;
  }
  *(short *)PTR_DAT_060bc870 = *(short *)PTR_DAT_060bc870 + 1;
  uVar4 = *puVar2;
  iVar3 = (*(code *)PTR_FUN_060bc878)();
  *(ushort *)(extraout_r2 + iVar3) = uVar4 & 0xff;
  if ((uint)(int)DAT_060bc85a < (uint)*(ushort *)PTR_DAT_060bc870) {
    *(undefined2 *)PTR_DAT_060bc870 = 0;
  }
  (*(code *)PTR_FUN_060bc87c)(0);
  return;
}



int FUN_060bc880(int param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 local_14;
  undefined4 uStack_10;
  
  puVar1 = PTR_DAT_060bc934;
  uStack_10 = 0;
  *(undefined4 *)PTR_DAT_060bc934 = 1;
  if (param_1 == 1) {
    if (*DAT_060bc938 == 1) {
      *(undefined4 *)puVar1 = 0;
      iVar3 = (int)DAT_060bc92e;
      do {
        iVar2 = (*(code *)PTR_FUN_060bc940)(*DAT_060bc93c);
        if ((1 < iVar2 - 2U) && (iVar2 != 5)) break;
        local_14 = 0;
        if (-1 < DAT_060bc930) {
          do {
            local_14 = local_14 + 1;
          } while (local_14 <= DAT_060bc930);
        }
        uStack_10 = uStack_10 + 1;
      } while (uStack_10 <= iVar3);
      *(undefined4 *)PTR_DAT_060bc934 = 1;
      (*(code *)PTR_FUN_060bc948)(DAT_060bc944,(int)DAT_060bc932);
      (*(code *)PTR_FUN_060bc94c)(*DAT_060bc93c,0);
    }
    iVar3 = (*(code *)PTR_FUN_060bc950)();
  }
  else {
    iVar3 = *DAT_060bc938;
    if (iVar3 == 1) {
      iVar3 = (*(code *)PTR_FUN_060bc94c)(*DAT_060bc93c,iVar3 == 1);
    }
  }
  *(undefined4 *)PTR_DAT_060bc934 = 0;
  return iVar3;
}



bool FUN_060bc954(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = DAT_060bc988;
  iVar2 = (*(code *)PTR_FUN_060bc98c)(*DAT_060bc988);
  if (iVar2 == 5) {
    (*(code *)PTR_FUN_060bc990)(*puVar1);
    (*(code *)PTR_FUN_060bc998)(*DAT_060bc994);
  }
  return iVar2 == 5;
}



void FUN_060bc99c(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  *(undefined4 *)PTR_DAT_060bca6c = 0;
  *(undefined4 *)PTR_DAT_060bca70 = 0;
  *(undefined4 *)PTR_DAT_060bca74 = 0;
  puVar2 = PTR_DAT_060bca7c;
  puVar1 = PTR_DAT_060bca78;
  *(undefined4 *)PTR_DAT_060bca80 = 1;
  *(undefined4 *)puVar2 = 1;
  *(undefined4 *)puVar1 = 1;
  *(undefined4 *)PTR_DAT_060bca84 = 0;
  *(undefined4 *)PTR_DAT_060bca88 = 0;
  *(undefined4 *)PTR_DAT_060bca8c = 0;
  *(undefined4 *)PTR_DAT_060bca90 = 0;
  *DAT_060bca94 = 0;
  iVar7 = 0;
  (*(code *)PTR_FUN_060bca98)();
  (*(code *)PTR_FUN_060bca9c)();
  (*(code *)PTR_FUN_060bcaa4)(PTR_LAB_060bcaa0,0);
  *DAT_060bcaa8 = 0;
  *DAT_060bcaac = 0;
  *DAT_060bcab0 = 0;
  *DAT_060bcab4 = 1;
  *DAT_060bcab8 = 0;
  iVar6 = DAT_060bcabc;
  do {
    *(undefined4 *)(iVar6 + 4) = 0;
    *(undefined *)(DAT_060bcac0 + iVar7) = 0;
    *(undefined *)(DAT_060bcac4 + iVar7) = 0;
    iVar5 = iVar7 * 4;
    *(undefined4 *)(DAT_060bcac8 + iVar5) = 0;
    *(undefined4 *)(DAT_060bcacc + iVar5) = 0;
    *(undefined4 *)(DAT_060bcad0 + iVar5) = 0;
    *(undefined4 *)(DAT_060bcad4 + iVar5) = 0;
    *(undefined4 *)(DAT_060bcad8 + iVar5) = 0;
    *(undefined4 *)(DAT_060bcadc + iVar5) = 0;
    *(undefined4 *)(DAT_060bcae0 + iVar5) = 0;
    *(undefined4 *)(DAT_060bcae4 + iVar5) = 0;
    *(undefined4 *)(DAT_060bcae8 + iVar5) = 0;
    puVar4 = DAT_060bcaf0;
    puVar3 = DAT_060bcaec;
    iVar7 = iVar7 + 1;
    iVar6 = iVar6 + 8;
  } while (iVar7 < 2);
  *DAT_060bcaf4 = 0;
  *puVar4 = 0;
  *puVar3 = 0;
  puVar2 = PTR_DAT_060bca80;
  puVar1 = PTR_DAT_060bca78;
  *(undefined4 *)PTR_DAT_060bca7c = 0;
  *(undefined4 *)puVar1 = 0;
  *(undefined4 *)puVar2 = 0;
  return;
}



void FUN_060bcaf8(void)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_FUN_060bcb1c)();
  *DAT_060bcb20 = iVar1;
  if (iVar1 != 0) {
    (*(code *)PTR_FUN_060bcb24)(iVar1);
  }
  return;
}



void FUN_060bcb28(void)

{
  (*(code *)PTR_FUN_060bcb5c)(0xc,0x18,DAT_060bcb58);
  (*(code *)PTR_FUN_060bcb64)(PTR_LAB_060bcb60,0);
  (*(code *)PTR_FUN_060bcb6c)(PTR_LAB_060bcb68,0);
  *DAT_060bcb70 = 0;
  return;
}



void FUN_060bcb84(short param_1)

{
  int iVar1;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  undefined2 local_12;
  
  iVar1 = (*(code *)PTR_FUN_060bcbe0)(PTR_s_SDAIF_00_AIF_060bcbdc);
  local_12 = 0xffff;
  local_14 = 0xffff;
  local_16 = 0xffff;
  local_18 = 0xffff;
  local_1a = 0xffff;
  local_1c = 0xffff;
  (*(code *)PTR_FUN_060bcbe8)(*DAT_060bcbe4,iVar1 + param_1,&local_1c,0);
  return;
}



void FUN_060bcbec(void)

{
  (*(code *)PTR_FUN_060bcc00)();
  return;
}



void FUN_060bccb4(int param_1)

{
  uint *puVar1;
  int *piVar2;
  undefined4 uVar3;
  
  uVar3 = DAT_060bcd10;
  if (*(int *)(DAT_060bcd08 + param_1 * 4) != 0) {
    uVar3 = DAT_060bcd0c;
  }
  (*(code *)PTR_FUN_060bcd14)(uVar3,0,(int)DAT_060bcd04);
  piVar2 = (int *)(param_1 * 4 + DAT_060bcd18);
  *piVar2 = *piVar2 + (int)DAT_060bcd04;
  puVar1 = (uint *)(param_1 * 4 + DAT_060bcd08);
  *puVar1 = ~*puVar1 & 1;
  return;
}



void FUN_060bcd1c(int param_1,undefined *param_2)

{
  bool bVar1;
  uint *puVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  
  iVar5 = 0;
  puVar6 = (uint *)(param_1 * 4 + DAT_060bcd84);
  puVar2 = (uint *)(param_1 * 4 + DAT_060bcd88);
  do {
    *param_2 = *(undefined *)*puVar6;
    uVar3 = *puVar6;
    *puVar6 = uVar3 + 1;
    bVar1 = *puVar2 < uVar3 + 1;
    if (bVar1) break;
    iVar5 = iVar5 + 1;
    param_2 = param_2 + 1;
    bVar1 = false;
  } while (iVar5 <= DAT_060bcd80);
  if ((bVar1) && (iVar7 = (int)DAT_060bcd80, iVar5 <= iVar7)) {
    piVar4 = (int *)(param_1 * 4 + DAT_060bcd84);
    do {
      *param_2 = 0;
      param_2 = param_2 + 1;
      iVar5 = iVar5 + 1;
      *piVar4 = *piVar4 + 1;
    } while (iVar5 <= iVar7);
  }
  return;
}



void FUN_060bcd8c(int param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  
  uVar2 = DAT_060bcddc;
  if (*(int *)(DAT_060bcdd0 + param_1 * 4) != 0) {
    uVar2 = DAT_060bcdd4;
  }
  (*(code *)PTR_FUN_060bcdd8)(param_1,uVar2);
  puVar1 = (uint *)(param_1 * 4 + DAT_060bcdd0);
  *puVar1 = ~*puVar1 & 1;
  return;
}



void FUN_060bcde0(int param_1)

{
  bool bVar1;
  undefined *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  undefined *puVar6;
  undefined4 *puVar7;
  char cVar8;
  int iVar9;
  int iVar10;
  undefined local_48 [2];
  undefined2 local_46;
  undefined2 local_44;
  undefined local_3c;
  undefined local_3b;
  undefined local_3a;
  undefined2 local_38;
  undefined local_36;
  byte local_35;
  uint *puStack_28;
  
  *(undefined4 *)PTR_DAT_060bcef0 = 1;
  puVar2 = PTR_FUN_060bcef8;
  if (*DAT_060bcef4 != '\0') {
    iVar10 = 0;
    do {
      cVar8 = (*(code *)puVar2)(1);
      if (cVar8 == '\0') break;
      iVar9 = 1;
      do {
        bVar1 = iVar9 <= DAT_060bcee8;
        iVar9 = iVar9 + 1;
      } while (bVar1);
      iVar10 = iVar10 + 1;
    } while (iVar10 < 0x40);
  }
  puVar3 = DAT_060bcefc;
  puStack_28 = DAT_060bcefc;
  *DAT_060bcf00 = 0;
  puVar5 = DAT_060bcf0c;
  puVar4 = DAT_060bcf08;
  puVar2 = DAT_060bcf04;
  *puVar3 = 0;
  *puVar5 = 0;
  *puVar4 = 0;
  *puVar2 = 0;
  puVar2 = PTR_DAT_060bcf10;
  local_48[0] = 0x10;
  local_46 = DAT_060bceea;
  local_44 = DAT_060bceec;
  local_3c = 1;
  local_3b = 7;
  local_38 = *(undefined2 *)(PTR_DAT_060bcf10 + param_1 * 0x20 + 0x12);
  *puVar4 = *(uint *)(PTR_DAT_060bcf10 + param_1 * 0x20 + 0x18);
  puVar6 = PTR_FUN_060bcf14;
  *puVar5 = *(int *)(puVar2 + param_1 * 0x20 + 0x18) + *(int *)(puVar2 + param_1 * 0x20 + 0x1c);
  local_36 = 0;
  local_35 = puVar2[param_1 * 0x20 + 0xf] & 7;
  local_3a = 0;
  (*(code *)puVar6)(0);
  puVar7 = DAT_060bcf18;
  *DAT_060bcf18 = 1;
  if (*puVar5 <= *puVar4) {
    *puStack_28 = (uint)(*puVar5 <= *puVar4);
  }
  else {
    (*(code *)PTR_FUN_060bcfc0)(0);
    *puVar7 = 0;
  }
  iVar10 = 0;
  do {
    cVar8 = (*(code *)PTR_FUN_060bcfc4)(local_48,&local_3c);
    puVar2 = PTR_FUN_060bcfc8;
    if (cVar8 == '\0') break;
    iVar9 = 1;
    do {
      bVar1 = iVar9 <= DAT_060bcfbe;
      iVar9 = iVar9 + 1;
    } while (bVar1);
    iVar10 = iVar10 + 1;
  } while (iVar10 < 0x40);
  iVar10 = 0;
  do {
    cVar8 = (*(code *)puVar2)(1,PTR_DAT_060bcfcc[param_1 * 0x20]);
    if (cVar8 == '\0') break;
    iVar9 = 1;
    do {
      bVar1 = iVar9 <= DAT_060bcfbe;
      iVar9 = iVar9 + 1;
    } while (bVar1);
    iVar10 = iVar10 + 1;
  } while (iVar10 < 0x40);
  *DAT_060bcfd0 = PTR_DAT_060bcfd4[param_1 * 0x20];
  *(undefined4 *)PTR_DAT_060bcfd8 = 0;
  return;
}



void FUN_060bcfdc(void)

{
  bool bVar1;
  undefined *puVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  
  *(undefined4 *)PTR_DAT_060bd044 = 1;
  puVar2 = PTR_FUN_060bd04c;
  if (*DAT_060bd048 != '\0') {
    iVar5 = 0;
    do {
      cVar3 = (*(code *)puVar2)(1);
      if (cVar3 == '\0') break;
      iVar4 = 1;
      do {
        bVar1 = iVar4 <= DAT_060bd040;
        iVar4 = iVar4 + 1;
      } while (bVar1);
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0x40);
    *DAT_060bd048 = '\0';
  }
  *(undefined4 *)PTR_DAT_060bd044 = 0;
  return;
}



uint FUN_060bd050(void)

{
  bool bVar1;
  uint *puVar2;
  undefined *puVar3;
  uint in_r0;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  char local_18 [8];
  
  puVar3 = PTR_FUN_060bd1d8;
  puVar2 = DAT_060bd1c4;
  if (*DAT_060bd1b4 == '\0') {
    return in_r0;
  }
  bVar1 = *DAT_060bd1b8 == 0;
  if (bVar1) {
    uVar4 = (*(code *)PTR_FUN_060bd1bc)(local_18,bVar1);
    if (local_18[0] == *DAT_060bd1c0) {
      return uVar4;
    }
    *DAT_060bd1c0 = local_18[0];
    puVar3 = PTR_FUN_060bd1d8;
    puVar2 = DAT_060bd1c4;
    uVar4 = *DAT_060bd1c4;
    if (uVar4 == 1) {
      uVar4 = (*(code *)PTR_FUN_060bd1d4)(0);
      *puVar2 = *puVar2 + 1;
      return uVar4;
    }
    if ((int)uVar4 <= (int)(uint)bVar1) {
      if (uVar4 != 0) {
        return uVar4;
      }
      uVar4 = (*(code *)PTR_FUN_060bd1c8)(0);
      if (*DAT_060bd1d0 > *DAT_060bd1cc) {
        return uVar4;
      }
      *puVar2 = (uint)(*DAT_060bd1d0 <= *DAT_060bd1cc);
      return uVar4;
    }
    iVar7 = 0;
    if (uVar4 != 2) {
      return uVar4;
    }
    do {
      uVar4 = (*(code *)puVar3)(1);
      if ((uVar4 & 0xff) == 0) break;
      iVar5 = 1;
      do {
        bVar1 = iVar5 <= DAT_060bd1b2;
        iVar5 = iVar5 + 1;
      } while (bVar1);
      iVar7 = iVar7 + 1;
    } while (iVar7 < 0x40);
    *DAT_060bd1b4 = '\0';
    puVar6 = DAT_060bd1c4;
  }
  else {
    uVar4 = *DAT_060bd1c4;
    if (uVar4 == 1) {
      uVar4 = (*(code *)PTR_FUN_060bd1d4)(0);
      *puVar2 = *puVar2 + 1;
      puVar6 = DAT_060bd1b8;
    }
    else {
      puVar6 = DAT_060bd1b8;
      if ((int)uVar4 < 2) {
        if (uVar4 == 0) {
          uVar4 = (*(code *)PTR_FUN_060bd1c8)(0);
          puVar6 = DAT_060bd1b8;
          if (*DAT_060bd1d0 <= *DAT_060bd1cc) {
            *puVar2 = (uint)(*DAT_060bd1d0 <= *DAT_060bd1cc);
            puVar6 = DAT_060bd1b8;
          }
        }
      }
      else {
        iVar7 = 0;
        if (uVar4 == 2) {
          do {
            uVar4 = (*(code *)puVar3)(1);
            if ((uVar4 & 0xff) == 0) break;
            iVar5 = 1;
            do {
              bVar1 = iVar5 <= DAT_060bd1b2;
              iVar5 = iVar5 + 1;
            } while (bVar1);
            iVar7 = iVar7 + 1;
          } while (iVar7 < 0x40);
          *DAT_060bd1b4 = '\0';
          *DAT_060bd1c4 = 0;
          puVar6 = DAT_060bd1b8;
        }
      }
    }
  }
  *puVar6 = 0;
  return uVar4;
}



void FUN_060bd1dc(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = 0;
  *(undefined4 *)PTR_DAT_060bd28c = 0;
  *(undefined4 *)PTR_DAT_060bd290 = 0;
  *(undefined4 *)PTR_DAT_060bd294 = 0;
  puVar2 = PTR_DAT_060bd29c;
  puVar1 = PTR_DAT_060bd298;
  *(undefined4 *)PTR_DAT_060bd2a0 = 1;
  *(undefined4 *)puVar2 = 1;
  *(undefined4 *)puVar1 = 1;
  *(undefined4 *)PTR_DAT_060bd2a4 = 0;
  *(undefined4 *)PTR_DAT_060bd2a8 = 0;
  *(undefined4 *)PTR_DAT_060bd2ac = 0;
  *(undefined4 *)PTR_DAT_060bd2b0 = 0;
  *DAT_060bd2b4 = 0;
  *DAT_060bd2b8 = 0;
  *DAT_060bd2bc = 0;
  *DAT_060bd2c0 = 0;
  *DAT_060bd2c4 = 1;
  *DAT_060bd2c8 = 0;
  iVar6 = DAT_060bd2cc;
  do {
    *(undefined4 *)(iVar6 + 4) = 0;
    *(undefined *)(DAT_060bd2d0 + iVar7) = 0;
    *(undefined *)(DAT_060bd2d4 + iVar7) = 0;
    iVar5 = iVar7 * 4;
    *(undefined4 *)(DAT_060bd2d8 + iVar5) = 0;
    *(undefined4 *)(DAT_060bd2dc + iVar5) = 0;
    *(undefined4 *)(DAT_060bd2e0 + iVar5) = 0;
    *(undefined4 *)(DAT_060bd2e4 + iVar5) = 0;
    *(undefined4 *)(DAT_060bd2e8 + iVar5) = 0;
    *(undefined4 *)(DAT_060bd2ec + iVar5) = 0;
    *(undefined4 *)(DAT_060bd2f0 + iVar5) = 0;
    *(undefined4 *)(DAT_060bd2f4 + iVar5) = 0;
    *(undefined4 *)(DAT_060bd2f8 + iVar5) = 0;
    puVar4 = DAT_060bd300;
    puVar3 = DAT_060bd2fc;
    iVar7 = iVar7 + 1;
    iVar6 = iVar6 + 8;
  } while (iVar7 < 2);
  *DAT_060bd304 = 0;
  *puVar4 = 0;
  *puVar3 = 0;
  puVar2 = PTR_DAT_060bd29c;
  puVar1 = PTR_DAT_060bd298;
  *(undefined4 *)PTR_DAT_060bd2a0 = 0;
  *(undefined4 *)puVar2 = 0;
  *(undefined4 *)puVar1 = 0;
  return;
}



void FUN_060bd308(int param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  
  uVar2 = DAT_060bd350;
  if (*(int *)(DAT_060bd348 + param_1 * 4) != 0) {
    uVar2 = DAT_060bd34c;
  }
  (*(code *)PTR_FUN_060bd354)(uVar2);
  puVar1 = (uint *)(param_1 * 4 + DAT_060bd348);
  *puVar1 = ~*puVar1 & 1;
  return;
}



void FUN_060bd358(int param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  
  uVar2 = DAT_060bd3a8;
  if (*(int *)(DAT_060bd39c + param_1 * 4) != 0) {
    uVar2 = DAT_060bd3a0;
  }
  (*(code *)PTR_FUN_060bd3a4)(param_1,uVar2);
  puVar1 = (uint *)(param_1 * 4 + DAT_060bd39c);
  *puVar1 = ~*puVar1 & 1;
  return;
}



void FUN_060bd3ac(int param_1)

{
  bool bVar1;
  undefined2 uVar2;
  undefined *puVar3;
  undefined *puVar4;
  char cVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  byte *pbVar9;
  undefined4 *puVar10;
  int iVar11;
  
  *(undefined4 *)PTR_DAT_060bd4e4 = 1;
  puVar3 = PTR_FUN_060bd4ec;
  if (*(char *)(DAT_060bd4e8 + 1) != '\0') {
    iVar11 = 0;
    do {
      cVar5 = (*(code *)puVar3)(0);
      if (cVar5 == '\0') break;
      iVar6 = 1;
      do {
        bVar1 = iVar6 <= DAT_060bd4de;
        iVar6 = iVar6 + 1;
      } while (bVar1);
      iVar11 = iVar11 + 1;
    } while (iVar11 < 0x40);
  }
  iVar11 = DAT_060bd4f0;
  *(undefined4 *)(DAT_060bd4f4 + 4) = 0;
  *(undefined4 *)(iVar11 + 4) = 0;
  iVar11 = DAT_060bd4f8;
  piVar7 = (int *)(DAT_060bd4fc + 4);
  puVar10 = (undefined4 *)(DAT_060bd500 + 4);
  *puVar10 = 0;
  puVar4 = DAT_060bd508;
  puVar3 = DAT_060bd504;
  uVar2 = DAT_060bd4e0;
  *piVar7 = 0;
  *(undefined *)(iVar11 + 1) = 0;
  *puVar3 = 0;
  *(undefined2 *)(puVar3 + 2) = uVar2;
  *(undefined2 *)(puVar3 + 4) = DAT_060bd4e2;
  *puVar4 = 0;
  puVar4[1] = 7;
  *(undefined2 *)(puVar4 + 4) = uVar2;
  *(undefined4 *)PTR_DAT_060bd50c = 0;
  pbVar9 = PTR_DAT_060bd510 + param_1 * 0xc;
  *piVar7 = (uint)*(ushort *)(pbVar9 + 8) + DAT_060bd514;
  puVar3 = PTR_DAT_060bd518;
  *puVar10 = *(undefined4 *)(pbVar9 + 4);
  puVar4[6] = 0;
  puVar4[7] = 0;
  puVar4[2] = 0;
  *DAT_060bd51c = 0;
  *DAT_060bd520 = 7;
  *DAT_060bd524 = 0;
  *(int *)puVar3 = (int)*(short *)(pbVar9 + 2);
  puVar3 = PTR_DAT_060bd528;
  uVar8 = (int)(short)*(ushort *)(pbVar9 + 8) << 0x10;
  *(uint *)PTR_DAT_060bd528 = uVar8;
  *(uint *)puVar3 = (uint)*pbVar9 << 8 | uVar8 | 0xb;
  *(undefined4 *)PTR_DAT_060bd52c = 0xf;
  *(byte *)(DAT_060bd4e8 + 1) = pbVar9[10];
  *(undefined4 *)PTR_DAT_060bd4e4 = 0;
  return;
}



void FUN_060bd530(void)

{
  bool bVar1;
  undefined *puVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  
  *(undefined4 *)PTR_DAT_060bd5a8 = 1;
  puVar2 = PTR_FUN_060bd5b0;
  if (*(char *)(DAT_060bd5ac + 1) != '\0') {
    iVar5 = 0;
    do {
      cVar3 = (*(code *)puVar2)(0);
      if (cVar3 == '\0') break;
      iVar4 = 1;
      do {
        bVar1 = iVar4 <= DAT_060bd5a2;
        iVar4 = iVar4 + 1;
      } while (bVar1);
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0x40);
    *(undefined *)(DAT_060bd5ac + 1) = 0;
    *(uint *)PTR_DAT_060bd5b4 = *(uint *)PTR_DAT_060bd5b4 & (int)DAT_060bd5a4;
  }
  *PTR_DAT_060bd5b8 = 2;
  *(undefined4 *)PTR_DAT_060bd5a8 = 0;
  return;
}



void FUN_060bd5bc(void)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  char cVar6;
  int iVar5;
  int iVar7;
  int iVar8;
  
  *(undefined4 *)PTR_DAT_060bd660 = 1;
  puVar2 = PTR_FUN_060bd668;
  if (*(char *)(DAT_060bd664 + 1) != '\0') {
    iVar8 = 0;
    do {
      cVar6 = (*(code *)puVar2)(0);
      puVar4 = PTR_DAT_060bd670;
      puVar3 = PTR_FUN_060bd66c;
      if (cVar6 == '\0') break;
      iVar7 = 1;
      do {
        bVar1 = iVar7 <= DAT_060bd65a;
        iVar7 = iVar7 + 1;
      } while (bVar1);
      iVar8 = iVar8 + 1;
    } while (iVar8 < 0x40);
    iVar8 = 0;
    iVar7 = (int)DAT_060bd65c;
    do {
      iVar5 = (*(code *)puVar3)(*(undefined4 *)PTR_DAT_060bd674);
      iVar8 = iVar8 + 1;
      if (-1 < iVar5) {
        *(uint *)puVar4 = *(uint *)puVar4 & (int)DAT_060bd65e;
        break;
      }
      *(uint *)puVar4 = *(uint *)puVar4 | 0x10;
    } while (iVar8 <= iVar7);
    (*(code *)PTR_FUN_060bd678)(*(undefined4 *)PTR_DAT_060bd674);
    *(undefined *)(DAT_060bd664 + 1) = 0;
  }
  *PTR_DAT_060bd67c = 2;
  *(undefined4 *)PTR_DAT_060bd660 = 0;
  return;
}



uint FUN_060bd680(void)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  uint in_r0;
  char cVar4;
  uint uVar5;
  int iVar6;
  undefined uVar7;
  uint uVar8;
  int iVar9;
  uint *puVar10;
  uint uVar11;
  char local_22 [6];
  
  puVar2 = PTR_DAT_060bd800;
  if (*DAT_060bd7fc == '\0') {
    return in_r0;
  }
  if ((*(uint *)PTR_DAT_060bd800 & 1) != 0) {
    *DAT_060bd804 = 0;
    puVar3 = PTR_FUN_060bd808;
    (*(code *)PTR_FUN_060bd808)(1);
    (*(code *)puVar3)(1);
    *PTR_DAT_060bd80c = 1;
    *(uint *)puVar2 = *(uint *)puVar2 & 0xfffffffe;
  }
  if (*PTR_DAT_060bd80c == '\x02') {
    uVar8 = *(uint *)PTR_DAT_060bd810;
    uVar5 = *DAT_060bd814;
    if (uVar5 < uVar8) {
      *(uint *)puVar2 = *(uint *)puVar2 & 0xfffffffd;
      *(uint *)(DAT_060bd818 + 4) = (uint)(uVar5 < uVar8);
    }
    puVar2 = PTR_FUN_060bd81c;
    iVar9 = 0;
    do {
      cVar4 = (*(code *)puVar2)(DAT_060bd824,DAT_060bd820);
      puVar3 = DAT_060bd828;
      if (cVar4 == '\0') break;
      iVar6 = 1;
      do {
        bVar1 = iVar6 <= DAT_060bd7f8;
        iVar6 = iVar6 + 1;
      } while (bVar1);
      iVar9 = iVar9 + 1;
    } while (iVar9 < 0x40);
    iVar9 = 0;
    do {
      cVar4 = (*(code *)PTR_FUN_060bd82c)(0,*puVar3);
      if (cVar4 == '\0') break;
      iVar6 = 1;
      do {
        bVar1 = iVar6 <= DAT_060bd7f8;
        iVar6 = iVar6 + 1;
      } while (bVar1);
      iVar9 = iVar9 + 1;
    } while (iVar9 < 0x40);
    uVar7 = 0;
  }
  else {
    uVar7 = 2;
    if (*PTR_DAT_060bd80c != '\x01') goto LAB_060bd756;
  }
  *PTR_DAT_060bd80c = uVar7;
LAB_060bd756:
  puVar3 = PTR_FUN_060bd948;
  puVar2 = PTR_DAT_060bd800;
  if ((*(uint *)PTR_DAT_060bd800 & 0x10) == 0) {
    bVar1 = *(int *)(DAT_060bd834 + 4) == 0;
    if (bVar1) {
      uVar11 = (uint)bVar1;
      uVar8 = uVar11 - 1;
      (*(code *)PTR_FUN_060bd838)(local_22,uVar8 & 0xff);
      uVar5 = (int)*(char *)(DAT_060bd83c + 1) & 1;
      if (((int)local_22[0] & 1U) != uVar5) {
        *(char *)(DAT_060bd83c + 1) = local_22[0];
        puVar3 = PTR_FUN_060bd948;
        puVar10 = (uint *)(DAT_060bd818 + 4);
        uVar5 = *puVar10;
        if (uVar5 == 1) {
          uVar5 = (*(code *)PTR_FUN_060bd944)(1);
          *puVar10 = *puVar10 + 1;
        }
        else if ((int)uVar11 < (int)uVar5) {
          iVar9 = 0;
          if (uVar5 == 2) {
            do {
              cVar4 = (*(code *)puVar3)(uVar8 & 0xff);
              if (cVar4 == '\0') break;
              iVar6 = 1;
              do {
                bVar1 = iVar6 <= DAT_060bd940;
                iVar6 = iVar6 + 1;
              } while (bVar1);
              iVar9 = iVar9 + 1;
            } while (iVar9 < 0x40);
            *(undefined *)(DAT_060bd94c + 1) = 0;
            uVar5 = 4;
            *(undefined4 *)(DAT_060bd950 + 4) = 0;
            *PTR_DAT_060bd954 = 2;
          }
        }
        else if (uVar5 == 0) {
          (*(code *)PTR_FUN_060bd808)(1);
          uVar5 = 4;
          bVar1 = *(uint *)(DAT_060bd840 + 4) < *(uint *)PTR_DAT_060bd810;
          if (bVar1) {
            *(uint *)puVar2 = *(uint *)puVar2 & 0xfffffffd;
            *puVar10 = (uint)bVar1;
          }
          else {
            uVar5 = 4;
          }
        }
      }
    }
    else {
      puVar10 = (uint *)(DAT_060bd950 + 4);
      uVar5 = *puVar10;
      if (uVar5 == 1) {
        (*(code *)PTR_FUN_060bd944)(1);
        *puVar10 = *puVar10 + 1;
      }
      else if ((int)uVar5 < 2) {
        if (uVar5 == 0) {
          (*(code *)PTR_FUN_060bd958)(1);
          bVar1 = *(uint *)(DAT_060bd960 + 4) <= *(uint *)(DAT_060bd95c + 4);
          if (bVar1) {
            *puVar10 = (uint)bVar1;
          }
        }
      }
      else {
        iVar9 = 0;
        if (uVar5 == 2) {
          do {
            cVar4 = (*(code *)puVar3)(0);
            if (cVar4 == '\0') break;
            iVar6 = 1;
            do {
              bVar1 = iVar6 <= DAT_060bd940;
              iVar6 = iVar6 + 1;
            } while (bVar1);
            iVar9 = iVar9 + 1;
          } while (iVar9 < 0x40);
          *(undefined *)(DAT_060bd94c + 1) = 0;
          *(undefined4 *)(DAT_060bd950 + 4) = 0;
          *PTR_DAT_060bd954 = 2;
        }
      }
      uVar5 = 4;
      *(undefined4 *)(DAT_060bd964 + 4) = 0;
    }
  }
  else {
    uVar5 = (*(code *)PTR_FUN_060bd830)();
  }
  return uVar5;
}



void FUN_060bd968(int param_1,undefined *param_2)

{
  ushort uVar1;
  bool bVar2;
  bool bVar3;
  uint *puVar4;
  undefined *puVar5;
  uint uVar6;
  undefined *puVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int extraout_r2;
  int extraout_r2_00;
  int extraout_r3;
  undefined uVar11;
  int iVar12;
  int *piVar13;
  byte bVar14;
  int iVar15;
  byte *pbVar16;
  byte *pbVar17;
  byte *pbStack_28;
  
  puVar5 = PTR_DAT_060bdb9c;
  puVar4 = DAT_060bdb94;
  bVar2 = false;
  bVar3 = false;
  pbStack_28 = (byte *)0x0;
  iVar15 = 0;
  uVar8 = *(uint *)(DAT_060bdb98 + param_1 * 4);
  pbVar16 = *(byte **)(DAT_060bdb90 + param_1 * 4);
  do {
    if (bVar2) {
      bVar14 = *pbStack_28 & 0xf;
      pbVar17 = pbVar16;
    }
    else {
      iVar9 = *(int *)PTR_DAT_060bdba0;
      *(uint *)PTR_DAT_060bdba0 = iVar9 + 1U;
      pbVar17 = pbVar16 + 1;
      if (uVar8 < iVar9 + 1U) {
        bVar3 = true;
        *(uint *)PTR_DAT_060bdc74 = *(uint *)PTR_DAT_060bdc74 & 0xfffffffd;
        break;
      }
      uVar6 = 6;
      if (pbVar17 == DAT_060bdba4) {
        uVar10 = *(uint *)PTR_DAT_060bdba8;
        pbVar17 = DAT_060bdbac;
LAB_060bd9e8:
        *(uint *)PTR_DAT_060bdba8 = uVar10 | uVar6;
      }
      else if (pbVar17 == DAT_060bdbb0) {
        uVar6 = 2;
        uVar10 = *(uint *)PTR_DAT_060bdba8 & 0xfffffffb;
        goto LAB_060bd9e8;
      }
      bVar14 = *pbVar16 >> 4;
      pbStack_28 = pbVar16;
    }
    bVar2 = (bool)(bVar2 ^ 1);
    iVar12 = *DAT_060bdbb4;
    iVar9 = iVar12 >> 3;
    if ((bVar14 & 4) != 0) {
      iVar9 = iVar9 + iVar12;
    }
    if ((bVar14 & 2) != 0) {
      iVar9 = iVar9 + (iVar12 >> 1);
    }
    if ((bVar14 & 1) != 0) {
      iVar9 = iVar9 + (iVar12 >> 2);
    }
    if ((bVar14 & 8) == 0) {
      uVar6 = *puVar4 + iVar9;
    }
    else {
      uVar6 = *puVar4 - iVar9;
    }
    *puVar4 = uVar6;
    if ((int)*puVar4 < -0x8000) {
      *puVar4 = 0xffff8000;
    }
    else if ((int)DAT_060bdb88 < (int)*puVar4) {
      *puVar4 = (int)DAT_060bdb88;
    }
    iVar12 = (int)DAT_060bdb8a;
    iVar9 = (*(code *)PTR_FUN_060bdbb8)(iVar15);
    if ((iVar15 == iVar9 * iVar12) && (iVar15 != 0)) {
      uVar6 = *puVar4;
      if ((DAT_060bdbbc & uVar6) == 0) {
        *(short *)puVar5 = *(short *)puVar5 + 1;
        iVar9 = (*(code *)PTR_FUN_060bdbc4)();
        *(ushort *)(extraout_r2 + iVar9) = (ushort)uVar6 & 0xff;
      }
      else {
        uVar1 = *(ushort *)puVar5;
        *(ushort *)puVar5 = uVar1 + 1;
        *(ushort *)(DAT_060bdbc0 + (uint)uVar1 * 2) = (ushort)(-uVar6 >> 8) & 0xff;
      }
      if ((uint)(int)DAT_060bdb8c < (uint)*(ushort *)puVar5) {
        *(undefined2 *)puVar5 = 0;
      }
    }
    uVar11 = (undefined)*puVar4;
    piVar13 = DAT_060bdbcc;
    puVar7 = (undefined *)(*(code *)PTR_FUN_060bdbc4)();
    *param_2 = uVar11;
    param_2[1] = *puVar7;
    param_2 = param_2 + 2;
    iVar9 = *piVar13 + *(int *)(PTR_DAT_060bdbd0 + extraout_r3 * 4);
    *piVar13 = iVar9;
    if (iVar9 < 0) {
      *piVar13 = 0;
    }
    else if (0x58 < iVar9) {
      *DAT_060bdbcc = 0x58;
    }
    iVar15 = iVar15 + 1;
    *DAT_060bdbb4 = *(int *)(PTR_DAT_060bdbd4 + *DAT_060bdbcc * 4);
    pbVar16 = pbVar17;
  } while (iVar15 <= DAT_060bdb8e);
  if (bVar3) {
    iVar12 = (int)DAT_060bdb8a;
    iVar9 = (*(code *)PTR_FUN_060bdbb8)(iVar15);
    if ((iVar15 == iVar9 * iVar12) && (iVar15 != 0)) {
      uVar8 = *DAT_060bdb94;
      if ((uVar8 & DAT_060bdbbc) == 0) {
        *(short *)PTR_DAT_060bdb9c = *(short *)PTR_DAT_060bdb9c + 1;
        iVar9 = (*(code *)PTR_FUN_060bdbc4)();
        *(ushort *)(extraout_r2_00 + iVar9) = (ushort)uVar8 & 0xff;
      }
      else {
        uVar1 = *(ushort *)PTR_DAT_060bdc78;
        *(ushort *)PTR_DAT_060bdc78 = uVar1 + 1;
        *(ushort *)(DAT_060bdc7c + (uint)uVar1 * 2) = (ushort)(-uVar8 >> 8) & 0xff;
      }
      if ((uint)(int)DAT_060bdc70 < (uint)*(ushort *)PTR_DAT_060bdc78) {
        *(undefined2 *)PTR_DAT_060bdc78 = 0;
      }
    }
    else {
      uVar1 = *(ushort *)PTR_DAT_060bdc78;
      *(ushort *)PTR_DAT_060bdc78 = uVar1 + 1;
      *(undefined2 *)(DAT_060bdc7c + (uint)uVar1 * 2) = 0;
    }
    puVar5 = PTR_DAT_060bdc80;
    iVar9 = (int)DAT_060bdc72;
    for (; iVar15 <= iVar9; iVar15 = iVar15 + 1) {
      *param_2 = 0;
      param_2[1] = 0;
      param_2 = param_2 + 2;
      pbVar17 = pbVar17 + 2;
      *(int *)puVar5 = *(int *)puVar5 + 2;
    }
  }
  *(byte **)(DAT_060bdc84 + param_1 * 4) = pbVar17;
  return;
}



void FUN_060bdc88(undefined *param_1)

{
  ushort uVar1;
  undefined *puVar2;
  uint uVar3;
  uint uVar4;
  
  puVar2 = PTR_DAT_060bdcd4;
  uVar1 = *(ushort *)PTR_DAT_060bdcd4;
  uVar3 = 0;
  *(ushort *)PTR_DAT_060bdcd4 = uVar1 + 1;
  *(undefined2 *)(DAT_060bdcd8 + (uint)uVar1 * 2) = 0;
  if ((uint)(int)DAT_060bdcd0 < (uint)*(ushort *)puVar2) {
    *(undefined2 *)puVar2 = 0;
  }
  puVar2 = PTR_DAT_060bdcdc;
  uVar4 = (uint)DAT_060bdcd2;
  do {
    *param_1 = 0;
    param_1[1] = 0;
    param_1 = param_1 + 2;
    uVar3 = uVar3 + 1;
    *(int *)puVar2 = *(int *)puVar2 + 2;
  } while (uVar3 <= uVar4);
  return;
}



void FUN_060bdd04(void)

{
  undefined *puVar1;
  undefined *puVar2;
  int *piVar3;
  undefined *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint *puVar9;
  int iVar10;
  
  puVar1 = PTR_DAT_060bde14;
  uVar5 = *(uint *)PTR_DAT_060bde14;
  if ((uVar5 & 2) == 0) goto LAB_060bdfa0;
  *(uint *)PTR_DAT_060bde14 = uVar5 | 8;
  puVar2 = PTR_FUN_060bde1c;
  if ((uVar5 & 1) != 0) {
    iVar7 = 0;
    if (*PTR_DAT_060bde18 != '\0') {
      iVar10 = (int)DAT_060bde10;
      do {
        iVar8 = (*(code *)puVar2)(*(undefined4 *)PTR_DAT_060bde20);
        iVar7 = iVar7 + 1;
        if (-1 < iVar8) {
          *(uint *)PTR_DAT_060bde14 = *(uint *)PTR_DAT_060bde14 & (int)DAT_060bde12;
          break;
        }
        *(uint *)puVar1 = *(uint *)puVar1 | 0x10;
      } while (iVar7 <= iVar10);
      (*(code *)PTR_FUN_060bde24)(*(undefined4 *)PTR_DAT_060bde20);
    }
    uVar5 = DAT_060bde28;
    puVar1 = PTR_DAT_060bde14;
    iVar7 = 0;
    iVar10 = (int)DAT_060bde10;
    do {
      iVar8 = (*(code *)PTR_FUN_060bde30)
                        (*(undefined4 *)(PTR_DAT_060bde2c + ((*(uint *)puVar1 & uVar5) >> 6)));
      iVar7 = iVar7 + 1;
      if (-1 < iVar8) {
        *(uint *)puVar1 = *(uint *)puVar1 & (int)DAT_060bde12;
        break;
      }
      *(uint *)puVar1 = *(uint *)puVar1 | 0x10;
    } while (iVar7 <= iVar10);
    puVar2 = PTR_FUN_060bde34;
    puVar1 = PTR_DAT_060bde14;
    iVar7 = 0;
    iVar10 = (int)DAT_060bde10;
    do {
      iVar6 = (*(code *)puVar2)(iVar8);
      *(int *)PTR_DAT_060bde20 = iVar6;
      if (iVar6 != 0) {
        *(uint *)PTR_DAT_060bde14 = *(uint *)PTR_DAT_060bde14 & (int)DAT_060bde12;
        break;
      }
      iVar7 = iVar7 + 1;
      *(uint *)puVar1 = *(uint *)puVar1 | 0x10;
    } while (iVar7 <= iVar10);
    puVar1 = PTR_DAT_060bde20;
    (*(code *)PTR_FUN_060bde38)(*(undefined4 *)PTR_DAT_060bde20,4);
    (*(code *)PTR_FUN_060bde3c)(*(undefined4 *)puVar1,4);
    (*(code *)PTR_FUN_060bde40)(*(undefined4 *)puVar1,3);
    uVar5 = *(uint *)PTR_DAT_060bde14;
    if ((uVar5 & 0x10) != 0) {
      *(uint *)PTR_DAT_060bde14 = uVar5 & 0xfffffff7;
      return;
    }
    *(uint *)PTR_DAT_060bde14 = (int)DAT_060bdf16 & uVar5;
    piVar3 = DAT_060bdf1c;
    *DAT_060bdf1c = 0;
    puVar2 = PTR_FUN_060bdf24;
    puVar1 = PTR_DAT_060bdf20;
    iVar7 = 0;
    iVar10 = (int)DAT_060bdf18;
    do {
      iVar8 = (*(code *)puVar2)(*(undefined4 *)PTR_DAT_060bdf28,*(int *)puVar1 + *piVar3,0);
      iVar7 = iVar7 + 1;
      if (-1 < iVar8) {
        *(uint *)PTR_DAT_060bde14 = *(uint *)PTR_DAT_060bde14 & (int)DAT_060bde12;
        break;
      }
      *(uint *)PTR_DAT_060bdf2c = *(uint *)PTR_DAT_060bdf2c | 0x10;
    } while (iVar7 <= iVar10);
  }
  puVar4 = PTR_FUN_060be014;
  puVar2 = PTR_FUN_060bdf30;
  puVar1 = PTR_DAT_060bdf2c;
  uVar5 = *(uint *)PTR_DAT_060bdf2c;
  if ((uVar5 & 0x10) != 0) {
    *(uint *)PTR_DAT_060bdf2c = uVar5 & 0xfffffff7;
    return;
  }
  iVar7 = 0;
  if ((uVar5 & 1) == 0) {
    if ((uVar5 & 4) == 0) {
      iVar7 = 0;
      iVar10 = (int)DAT_060bdf18;
      do {
        iVar8 = (*(code *)puVar2)(*(undefined4 *)PTR_DAT_060bdf28,4,DAT_060bdf34,(int)DAT_060bdf1a);
        iVar7 = iVar7 + 1;
        if (-1 < iVar8) goto LAB_060bdec6;
        *(uint *)puVar1 = *(uint *)puVar1 | 0x10;
      } while (iVar7 <= iVar10);
    }
    else {
      iVar10 = (int)DAT_060bdf18;
      do {
        iVar8 = (*(code *)puVar2)(*(undefined4 *)PTR_DAT_060bdf28,4,DAT_060bdf38,(int)DAT_060bdf1a);
        iVar7 = iVar7 + 1;
        if (-1 < iVar8) goto LAB_060bdec6;
        *(uint *)puVar1 = *(uint *)puVar1 | 0x10;
      } while (iVar7 <= iVar10);
    }
    goto LAB_060bdef2;
  }
  iVar10 = (int)DAT_060be00e;
  do {
    iVar8 = (*(code *)puVar4)(*(undefined4 *)PTR_DAT_060be018,8,DAT_060be01c,(int)DAT_060be010);
    iVar7 = iVar7 + 1;
    if (-1 < iVar8) {
      *(uint *)PTR_DAT_060bdf2c = *(uint *)PTR_DAT_060bdf2c & (int)DAT_060bdf16;
      break;
    }
    *(uint *)puVar1 = *(uint *)puVar1 | 0x10;
  } while (iVar7 <= iVar10);
  uVar5 = *(uint *)PTR_DAT_060be020;
  puVar9 = (uint *)PTR_DAT_060be020;
  if ((uVar5 & 0x10) != 0) goto LAB_060bdf6c;
  *DAT_060be028 = 8;
  goto LAB_060bdf90;
LAB_060bdec6:
  *(uint *)PTR_DAT_060bdf2c = *(uint *)PTR_DAT_060bdf2c & (int)DAT_060bdf16;
LAB_060bdef2:
  uVar5 = *(uint *)PTR_DAT_060bdf2c;
  puVar9 = (uint *)PTR_DAT_060bdf2c;
  if ((uVar5 & 0x10) != 0) {
LAB_060bdf6c:
    *puVar9 = uVar5 & 0xfffffff7;
    (*(code *)PTR_FUN_060be024)(*(undefined4 *)PTR_DAT_060be018);
    return;
  }
  *DAT_060bdf1c = *DAT_060bdf1c + 4;
LAB_060bdf90:
  *PTR_DAT_060be02c = 1;
  *(uint *)PTR_DAT_060be020 = *(uint *)PTR_DAT_060be020 & 0xfffffffd;
LAB_060bdfa0:
  puVar1 = PTR_DAT_060be020;
  if (((*(uint *)PTR_DAT_060be020 & 8) != 0) &&
     (iVar7 = (*(code *)PTR_FUN_060be030)(*(undefined4 *)PTR_DAT_060be018), iVar7 == 0)) {
    *(uint *)puVar1 = *(uint *)puVar1 & 0xfffffff7;
  }
  puVar2 = PTR_FUN_060be034;
  puVar1 = PTR_DAT_060be020;
  iVar7 = 0;
  if (*PTR_DAT_060be02c == '\x02') {
    iVar10 = (int)DAT_060be00e;
    do {
      iVar8 = (*(code *)puVar2)(*(undefined4 *)PTR_DAT_060be018);
      if (-1 < iVar8) {
        *(uint *)PTR_DAT_060be020 = *(uint *)PTR_DAT_060be020 & (int)DAT_060be012;
        break;
      }
      iVar7 = iVar7 + 1;
      *(uint *)puVar1 = *(uint *)puVar1 | 0x10;
    } while (iVar7 <= iVar10);
    puVar1 = PTR_DAT_060be018;
    (*(code *)PTR_FUN_060be038)(*(undefined4 *)PTR_DAT_060be018,0);
    (*(code *)PTR_FUN_060be024)(*(undefined4 *)puVar1);
    *PTR_DAT_060be02c = 0;
  }
  return;
}



int FUN_060be03c(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined4 uVar6;
  short sVar7;
  short *psVar8;
  short sVar9;
  
  iVar3 = DAT_060be110;
  iVar2 = DAT_060be108;
  sVar7 = *DAT_060be10c;
  *DAT_060be10c = sVar7 + -1;
  puVar4 = PTR_FUN_060be114;
  if ((short)(sVar7 + -1) == 0) {
    sVar9 = -*(short *)(iVar3 + DAT_060be0fe);
    sVar7 = -*(short *)(iVar3 + DAT_060be100);
  }
  else {
    uVar6 = (*(code *)PTR_FUN_060be114)();
    puVar5 = PTR_FUN_060be118;
    sVar7 = (*(code *)PTR_FUN_060be118)(uVar6,3);
    sVar9 = (short)uVar6 + sVar7 * -3 + -1;
    uVar6 = (*(code *)puVar4)();
    sVar7 = (*(code *)puVar5)(uVar6,3);
    sVar1 = *(short *)(iVar3 + DAT_060be0fe);
    sVar7 = (short)uVar6 + sVar7 * -3 + -1;
    if (2 < (int)sVar9 + (int)sVar1) {
      sVar9 = 0;
    }
    psVar8 = (short *)(iVar3 + DAT_060be100);
    if (2 < (int)*psVar8 + (int)sVar7) {
      sVar7 = 0;
    }
    *(short *)(iVar3 + DAT_060be0fe) = sVar9 + sVar1;
    *psVar8 = *psVar8 + sVar7;
  }
  psVar8 = (short *)(DAT_060be102 + iVar2);
  psVar8[6] = 1;
  *psVar8 = sVar9;
  psVar8[2] = sVar7;
  return (int)*(short *)(iVar3 + DAT_060be104);
}



void FUN_060be11c(void)

{
  short sVar1;
  int iVar2;
  short sVar3;
  short *psVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = DAT_060be1b8;
  psVar4 = DAT_060be1b4;
  if (*DAT_060be1b4 != 0) {
    iVar6 = (int)DAT_060be1ae;
    iVar5 = DAT_060be1b8 + iVar6;
    *(short *)(iVar5 + 8) = *(short *)(iVar5 + 8) + *DAT_060be1b4 * -3;
    *(short *)(iVar5 + 0x54) = *(short *)(iVar5 + 0x54) + *psVar4 * -2;
    *(short *)(iVar5 + 0xa0) = *(short *)(iVar5 + 0xa0) - *psVar4;
    *(short *)(iVar5 + 0xec) = *(short *)(iVar5 + 0xec) - *psVar4;
    *(short *)(iVar5 + 0x138) = *(short *)(iVar5 + 0x138) - *psVar4;
    sVar1 = DAT_060be1b0;
    *(short *)(iVar5 + 0x184) = *(short *)(iVar5 + 0x184) - *psVar4;
    sVar3 = 0xf;
    psVar4 = (short *)(iVar2 + iVar6 + 8);
    do {
      sVar3 = sVar3 + 1;
      if (*psVar4 < -0x27) {
        *psVar4 = sVar1;
      }
      psVar4 = psVar4 + 0x26;
    } while (sVar3 < 0x15);
  }
  return;
}



void FUN_060be1bc(void)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  
  psVar2 = DAT_060be210;
  sVar1 = *DAT_060be210;
  if (sVar1 == 7) {
    iVar3 = (*(code *)PTR_FUN_060be214)();
    if (iVar3 == 0) {
      *psVar2 = 8;
    }
  }
  else {
    if (sVar1 < 8) {
      if (sVar1 != 6) {
        return;
      }
      iVar3 = (*(code *)PTR_FUN_060be214)();
      if (iVar3 != 0) {
        return;
      }
      *psVar2 = 1;
      return;
    }
    if (sVar1 != 8) {
      return;
    }
  }
  (*(code *)PTR_FUN_060be218)();
  return;
}



uint FUN_060be21c(void)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined *puVar9;
  undefined *puVar10;
  uint uVar11;
  char cVar18;
  short sVar17;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  short sVar19;
  ushort uVar20;
  short extraout_r2;
  short extraout_r2_00;
  short extraout_r2_01;
  short extraout_r2_02;
  short *psVar21;
  short *extraout_r3;
  short *extraout_r3_00;
  short *extraout_r3_01;
  short *extraout_r3_02;
  int iVar22;
  char *pcVar23;
  int *piVar24;
  short *psVar25;
  int iVar26;
  int iVar27;
  int iStack_24;
  
  iVar22 = DAT_060c046c;
  iVar13 = DAT_060c0460;
  iVar14 = DAT_060c0358;
  puVar10 = PTR_FUN_060c00c8;
  puVar9 = PTR_FUN_060bfe14;
  puVar8 = PTR_FUN_060bf9a0;
  puVar7 = PTR_FUN_060bf99c;
  puVar6 = PTR_FUN_060bf510;
  puVar5 = PTR_FUN_060bf50c;
  puVar4 = PTR_FUN_060bf01c;
  puVar3 = PTR_FUN_060bf018;
  sVar17 = DAT_060bee7c;
  puVar2 = PTR_FUN_060be978;
  iVar26 = DAT_060be404;
  piVar24 = DAT_060be400;
  uVar11 = DAT_060be3f8;
  sVar19 = *DAT_060be3fc;
  if (0x14 < (uint)(int)sVar19) {
                    // WARNING: Could not recover jumptable at 0x060be242. Too many branches
                    // WARNING: Treating indirect jump as call
    uVar11 = (*DAT_060be248)();
    return uVar11;
  }
  uVar16 = (int)&switchD_060be256::switchdataD_060be25c +
           (int)(short)(&switchD_060be256::switchdataD_060be25c)[sVar19];
  switch(sVar19) {
  case 0:
    iVar13 = 0;
    iVar14 = (int)DAT_060be3da;
    *(undefined2 *)((int)DAT_060be3d8 + DAT_060be3f8) = 1;
    *(undefined2 *)((int)DAT_060be3dc + uVar11) = 0;
    iVar26 = DAT_060be404;
    do {
      *piVar24 = 0;
      piVar24[1] = iVar26;
      iVar13 = iVar13 + 1;
      piVar24 = piVar24 + 2;
    } while (iVar13 <= iVar14);
    *DAT_060be408 = DAT_060be3de;
    *DAT_060be40c = (int)DAT_060be3e0;
    *DAT_060be410 = (int)DAT_060be3e2;
                    // WARNING: Could not recover jumptable at 0x060be2c4. Too many branches
                    // WARNING: Treating indirect jump as call
    uVar11 = (*DAT_060be2c8)();
    return uVar11;
  case 2:
    iVar13 = 0x40;
    iVar14 = 0;
    psVar21 = (short *)(DAT_060be3f8 + (int)DAT_060be3dc);
    iVar26 = DAT_060be418;
    piVar24 = DAT_060be414;
    do {
      iVar13 = iVar13 + -1;
      *piVar24 = *psVar21 * 0x10000 + iVar26;
      piVar24[1] = iVar14;
      sVar19 = DAT_060be3e6;
      piVar24 = piVar24 + 2;
      iVar14 = iVar14 + DAT_060be3e4;
      iVar26 = iVar26 + DAT_060be41c;
    } while (iVar13 != 0);
    psVar21 = (short *)(uVar11 + (int)DAT_060be3dc);
    sVar17 = *psVar21;
    *psVar21 = sVar17 + 1;
    if (sVar19 < (short)(sVar17 + 1)) {
      *psVar21 = 0;
    }
    goto LAB_060be378;
  case 3:
    iVar22 = 0;
    iVar13 = (int)DAT_060be3e8;
    iVar14 = (int)DAT_060be3ea;
    psVar21 = (short *)(DAT_060be3f8 + (int)DAT_060be3dc);
    do {
      iVar22 = iVar22 + 1;
      *piVar24 = *psVar21 * iVar13;
      piVar24[1] = iVar26;
      piVar24 = piVar24 + 2;
    } while (iVar22 <= iVar14);
    iVar27 = 6;
    iVar13 = (int)DAT_060be3dc;
    iVar22 = (int)DAT_060be3e8;
    iVar26 = DAT_060be424;
    iVar14 = DAT_060be420;
    do {
      iVar27 = iVar27 + 1;
      *piVar24 = *(short *)(uVar11 + iVar13) * iVar22 + iVar26;
      piVar24[1] = iVar14;
      piVar24 = piVar24 + 2;
      iVar14 = iVar14 + DAT_060be3ec;
      iVar26 = iVar26 + DAT_060be428;
    } while (iVar27 < 0x10);
    psVar21 = (short *)(uVar11 + (int)DAT_060be3dc);
    sVar19 = *psVar21;
    *psVar21 = sVar19 + -1;
    if ((short)(sVar19 + -1) < 0) {
      *psVar21 = DAT_060be3e4;
    }
LAB_060be378:
    *DAT_060be408 = 10;
    *DAT_060be40c = (int)DAT_060be3e0;
                    // WARNING: Could not recover jumptable at 0x060be38a. Too many branches
                    // WARNING: Treating indirect jump as call
    uVar11 = (*DAT_060be390)();
    return uVar11;
  case 4:
    iVar26 = 0x16;
    iVar14 = (int)DAT_060be3ee;
    do {
      puVar2 = PTR_FUN_060be42c;
      pcVar23 = (char *)(uVar11 + DAT_060be3f0 + iVar14);
      if (*pcVar23 == '\0') {
        uVar16 = (*(code *)PTR_FUN_060be578)();
        if ((uVar16 & 0x7f) == 0) {
          (*(code *)PTR_FUN_060be57c)((int)(short)iVar26,2,5,0x1a,2,2,2);
          pcVar23[0xc] = '\0';
          pcVar23[0xd] = '\x1e';
          uVar12 = (*(code *)PTR_FUN_060be578)();
          sVar19 = DAT_060be56c;
          sVar17 = (*(code *)PTR_FUN_060be580)(uVar12);
          *(short *)(pcVar23 + 8) = ((short)uVar12 - sVar17 * sVar19) + 0x3c;
        }
      }
      else {
        *(int *)(pcVar23 + 0xc) = *(int *)(pcVar23 + 0xc) + (int)DAT_060be3f2;
        iVar22 = (*(code *)puVar2)();
        iVar13 = iVar22;
        if (iVar22 < 0) {
          iVar13 = iVar22 + 7;
        }
        if (iVar22 + (iVar13 >> 3) * -8 == 3) {
          iVar13 = *(int *)(pcVar23 + 8);
          sVar19 = DAT_060be3f4;
LAB_060be458:
          *(int *)(pcVar23 + 8) = iVar13 + sVar19;
        }
        else {
          iVar22 = (*(code *)PTR_FUN_060be578)();
          iVar13 = iVar22;
          if (iVar22 < 0) {
            iVar13 = iVar22 + 7;
          }
          if (iVar22 + (iVar13 >> 3) * -8 < 3) {
            iVar13 = *(int *)(pcVar23 + 8);
            sVar19 = DAT_060be566;
            goto LAB_060be458;
          }
        }
        if ((DAT_060be568 < *(short *)(pcVar23 + 0xc)) ||
           ((uint)(int)DAT_060be56a < ((int)*(short *)(pcVar23 + 8) - 0x32U & 0xffff))) {
          *pcVar23 = '\0';
        }
      }
      puVar2 = PTR_FUN_060be578;
      iVar26 = iVar26 + 1;
      iVar14 = iVar14 + 0x4c;
    } while (iVar26 < 0x20);
    iVar26 = 0x20;
    iVar14 = (int)DAT_060be56e;
    do {
      pcVar23 = (char *)(uVar11 + DAT_060be570 + iVar14);
      if (*pcVar23 == '\0') {
        uVar16 = (*(code *)puVar2)();
        if ((uVar16 & 0x7f) == 0) {
          (*(code *)PTR_FUN_060be674)((int)(short)iVar26,2,5,0x18,2,2,2);
          pcVar23[0xc] = '\0';
          pcVar23[0xd] = '\x1e';
          uVar12 = (*(code *)puVar2)();
          sVar19 = (*(code *)PTR_FUN_060be678)(uVar12,0x28);
          *(short *)(pcVar23 + 8) = (short)uVar12 + sVar19 * -0x28 + 0x3c;
        }
      }
      else {
        *(int *)(pcVar23 + 0xc) = *(int *)(pcVar23 + 0xc) + (int)DAT_060be572;
        iVar22 = (*(code *)puVar2)();
        iVar13 = iVar22;
        if (iVar22 < 0) {
          iVar13 = iVar22 + 7;
        }
        if (iVar22 + (iVar13 >> 3) * -8 == 2) {
          iVar13 = *(int *)(pcVar23 + 8);
          sVar19 = DAT_060be574;
LAB_060be540:
          *(int *)(pcVar23 + 8) = iVar13 + sVar19;
        }
        else {
          iVar22 = (*(code *)puVar2)();
          iVar13 = iVar22;
          if (iVar22 < 0) {
            iVar13 = iVar22 + 7;
          }
          if (iVar22 + (iVar13 >> 3) * -8 < 2) {
            iVar13 = *(int *)(pcVar23 + 8);
            sVar19 = DAT_060be566;
            goto LAB_060be540;
          }
        }
        if ((DAT_060be568 < *(short *)(pcVar23 + 0xc)) ||
           (0x32 < (ushort)(*(short *)(pcVar23 + 8) - 0x32U))) {
          *pcVar23 = '\0';
        }
      }
      puVar3 = PTR_FUN_060be67c;
      iVar26 = iVar26 + 1;
      iVar14 = iVar14 + 0x4c;
    } while (iVar26 < 0x22);
    iVar26 = 0x22;
    iVar14 = (int)DAT_060be664;
    do {
      pcVar23 = (char *)(uVar11 + DAT_060be666 + iVar14);
      if (*pcVar23 == '\0') {
        uVar16 = (*(code *)puVar3)();
        if ((uVar16 & 0x7f) == 0) {
          (*(code *)PTR_FUN_060be770)((int)(short)iVar26,2,5,0x18,2,2,2);
          pcVar23[0xc] = '\0';
          pcVar23[0xd] = '\x1e';
          uVar12 = (*(code *)puVar3)();
          psVar21 = (short *)(pcVar23 + 8);
          sVar19 = (*(code *)PTR_FUN_060be774)(uVar12,0x32);
          *psVar21 = (short)uVar12 + sVar19 * -0x32 + DAT_060be760;
        }
      }
      else {
        *(int *)(pcVar23 + 0xc) = *(int *)(pcVar23 + 0xc) + (int)DAT_060be668;
        iVar22 = (*(code *)puVar3)();
        iVar13 = iVar22;
        if (iVar22 < 0) {
          iVar13 = iVar22 + 7;
        }
        if (iVar22 + (iVar13 >> 3) * -8 == 2) {
          iVar13 = *(int *)(pcVar23 + 8);
          sVar19 = DAT_060be66a;
LAB_060be63c:
          *(int *)(pcVar23 + 8) = iVar13 + sVar19;
        }
        else {
          iVar22 = (*(code *)puVar3)();
          iVar13 = iVar22;
          if (iVar22 < 0) {
            iVar13 = iVar22 + 7;
          }
          if (iVar22 + (iVar13 >> 3) * -8 < 2) {
            iVar13 = *(int *)(pcVar23 + 8);
            sVar19 = DAT_060be66c;
            goto LAB_060be63c;
          }
        }
        if ((DAT_060be66e < *(short *)(pcVar23 + 0xc)) ||
           (0x32 < (ushort)(*(short *)(pcVar23 + 8) + DAT_060be670))) {
          *pcVar23 = '\0';
        }
      }
      puVar2 = PTR_FUN_060be778;
      iVar26 = iVar26 + 1;
      iVar14 = iVar14 + 0x4c;
    } while (iVar26 < 0x25);
    iVar26 = 0x25;
    iVar14 = (int)DAT_060be762;
    do {
      pcVar23 = (char *)(uVar11 + DAT_060be764 + iVar14);
      if (*pcVar23 == '\0') {
        uVar16 = (*(code *)puVar2)();
        if ((uVar16 & 0x7f) == 0) {
          (*(code *)PTR_FUN_060be8d0)((int)(short)iVar26,3,5,0x16,2,2,2);
          pcVar23[0xc] = '\0';
          pcVar23[0xd] = '\x1e';
          uVar12 = (*(code *)puVar2)();
          sVar19 = (*(code *)PTR_FUN_060be8d4)(uVar12,0x28);
          *(short *)(pcVar23 + 8) = (short)uVar12 + sVar19 * -0x28 + 0x3c;
        }
      }
      else {
        *(int *)(pcVar23 + 0xc) = *(int *)(pcVar23 + 0xc) + (int)DAT_060be766;
        iVar22 = (*(code *)puVar2)();
        iVar13 = iVar22;
        if (iVar22 < 0) {
          iVar13 = iVar22 + 7;
        }
        if (iVar22 + (iVar13 >> 3) * -8 == 2) {
          iVar13 = *(int *)(pcVar23 + 8);
          sVar19 = DAT_060be768;
LAB_060be73a:
          *(int *)(pcVar23 + 8) = iVar13 + sVar19;
        }
        else {
          iVar22 = (*(code *)puVar2)();
          iVar13 = iVar22;
          if (iVar22 < 0) {
            iVar13 = iVar22 + 7;
          }
          if (iVar22 + (iVar13 >> 3) * -8 < 2) {
            iVar13 = *(int *)(pcVar23 + 8);
            sVar19 = DAT_060be76a;
            goto LAB_060be73a;
          }
        }
        if ((DAT_060be76c < *(short *)(pcVar23 + 0xc)) ||
           (0x32 < (ushort)(*(short *)(pcVar23 + 8) - 0x32U))) {
          *pcVar23 = '\0';
        }
      }
      puVar3 = PTR_FUN_060be8d8;
      iVar26 = iVar26 + 1;
      iVar14 = iVar14 + 0x4c;
    } while (iVar26 < 0x27);
    iVar26 = 0x27;
    iVar14 = (int)DAT_060be8c0;
    do {
      pcVar23 = (char *)(uVar11 + DAT_060be8c2 + iVar14);
      if (*pcVar23 == '\0') {
        uVar16 = (*(code *)puVar3)();
        if ((uVar16 & 0x7f) == 0) {
          (*(code *)PTR_FUN_060be8d0)((int)(short)iVar26,3,5,0x16,2,2,2);
          pcVar23[0xc] = '\0';
          pcVar23[0xd] = '\x1e';
          uVar12 = (*(code *)puVar3)();
          psVar21 = (short *)(pcVar23 + 8);
          sVar19 = (*(code *)PTR_FUN_060be8d4)(uVar12,0x32);
          *psVar21 = (short)uVar12 + sVar19 * -0x32 + DAT_060be8ce;
        }
      }
      else {
        *(int *)(pcVar23 + 0xc) = *(int *)(pcVar23 + 0xc) + (int)DAT_060be8c4;
        iVar22 = (*(code *)puVar3)();
        iVar13 = iVar22;
        if (iVar22 < 0) {
          iVar13 = iVar22 + 7;
        }
        if (iVar22 + (iVar13 >> 3) * -8 == 2) {
          iVar13 = *(int *)(pcVar23 + 8);
          sVar19 = DAT_060be8c6;
LAB_060be836:
          *(int *)(pcVar23 + 8) = iVar13 + sVar19;
        }
        else {
          iVar22 = (*(code *)puVar3)();
          iVar13 = iVar22;
          if (iVar22 < 0) {
            iVar13 = iVar22 + 7;
          }
          if (iVar22 + (iVar13 >> 3) * -8 < 2) {
            iVar13 = *(int *)(pcVar23 + 8);
            sVar19 = DAT_060be8c8;
            goto LAB_060be836;
          }
        }
        if ((DAT_060be8ca < *(short *)(pcVar23 + 0xc)) ||
           (0x32 < (ushort)(*(short *)(pcVar23 + 8) + DAT_060be8cc))) {
          *pcVar23 = '\0';
        }
      }
      iVar26 = iVar26 + 1;
      iVar14 = iVar14 + 0x4c;
      if (0x29 < iVar26) {
                    // WARNING: Could not recover jumptable at 0x060be8b8. Too many branches
                    // WARNING: Treating indirect jump as call
        uVar11 = (*DAT_060be8bc)();
        return uVar11;
      }
    } while( true );
  case 5:
    iVar26 = 0x3e;
    iVar14 = (int)DAT_060be96a;
    do {
      pcVar23 = (char *)(uVar11 + DAT_060be96c + iVar14);
      if (*pcVar23 == '\0') {
        cVar18 = (*(code *)puVar2)();
        if (cVar18 == '\0') {
          (*(code *)PTR_FUN_060bea70)((int)(short)iVar26,cVar18 == '\0',3,5,2,0,0);
          pcVar23[0xc] = '\0';
          pcVar23[0xd] = '\x10';
          uVar12 = (*(code *)puVar2)();
          sVar19 = DAT_060bea60;
          sVar17 = (*(code *)PTR_FUN_060bea74)(uVar12);
          *(short *)(pcVar23 + 8) = ((short)uVar12 - sVar17 * sVar19) + 0x28;
        }
      }
      else {
        *(int *)(pcVar23 + 0xc) = *(int *)(pcVar23 + 0xc) + (int)DAT_060be96e;
        iVar22 = (*(code *)puVar2)();
        iVar13 = iVar22;
        if (iVar22 < 0) {
          iVar13 = iVar22 + 7;
        }
        if (iVar22 + (iVar13 >> 3) * -8 == 3) {
          iVar13 = *(int *)(pcVar23 + 8);
          sVar19 = DAT_060be970;
LAB_060be944:
          *(int *)(pcVar23 + 8) = iVar13 + sVar19;
        }
        else {
          iVar22 = (*(code *)puVar2)();
          iVar13 = iVar22;
          if (iVar22 < 0) {
            iVar13 = iVar22 + 7;
          }
          if (iVar22 + (iVar13 >> 3) * -8 < 3) {
            iVar13 = *(int *)(pcVar23 + 8);
            sVar19 = DAT_060be972;
            goto LAB_060be944;
          }
        }
        if ((DAT_060be974 < *(short *)(pcVar23 + 0xc)) ||
           ((uint)(int)DAT_060be976 < ((int)*(short *)(pcVar23 + 8) - 0x28U & 0xffff))) {
          *pcVar23 = '\0';
        }
      }
      puVar3 = PTR_FUN_060bea78;
      iVar26 = iVar26 + 1;
      iVar14 = iVar14 + 0x4c;
    } while (iVar26 < 0x52);
    iVar26 = 0x52;
    iVar14 = (int)DAT_060bea62;
    do {
      pcVar23 = (char *)(uVar11 + DAT_060bea64 + iVar14);
      if (*pcVar23 == '\0') {
        uVar16 = (*(code *)puVar3)();
        if ((uVar16 & 0x7f) == 0) {
          (*(code *)PTR_FUN_060beb6c)((int)(short)iVar26,2,3,5,2,0,0);
          pcVar23[0xc] = '\0';
          pcVar23[0xd] = '\x10';
          uVar12 = (*(code *)puVar3)();
          sVar19 = DAT_060beb5e;
          sVar17 = (*(code *)PTR_FUN_060beb70)(uVar12);
          *(short *)(pcVar23 + 8) = ((short)uVar12 - sVar17 * sVar19) + 0x28;
        }
      }
      else {
        *(int *)(pcVar23 + 0xc) = *(int *)(pcVar23 + 0xc) + (int)DAT_060bea66;
        iVar22 = (*(code *)puVar3)();
        iVar13 = iVar22;
        if (iVar22 < 0) {
          iVar13 = iVar22 + 7;
        }
        if (iVar22 + (iVar13 >> 3) * -8 == 3) {
          iVar13 = *(int *)(pcVar23 + 8);
          sVar19 = DAT_060bea68;
LAB_060bea3a:
          *(int *)(pcVar23 + 8) = iVar13 + sVar19;
        }
        else {
          iVar22 = (*(code *)puVar3)();
          iVar13 = iVar22;
          if (iVar22 < 0) {
            iVar13 = iVar22 + 7;
          }
          if (iVar22 + (iVar13 >> 3) * -8 < 3) {
            iVar13 = *(int *)(pcVar23 + 8);
            sVar19 = DAT_060bea6a;
            goto LAB_060bea3a;
          }
        }
        if ((DAT_060bea6c < *(short *)(pcVar23 + 0xc)) ||
           ((uint)(int)DAT_060bea60 < ((int)*(short *)(pcVar23 + 8) - 0x28U & 0xffff))) {
          *pcVar23 = '\0';
        }
      }
      puVar2 = PTR_FUN_060beb74;
      iVar26 = iVar26 + 1;
      iVar14 = iVar14 + 0x4c;
    } while (iVar26 < 0x5c);
    iVar26 = 0x5c;
    iVar14 = (int)DAT_060beb60;
    do {
      pcVar23 = (char *)(uVar11 + DAT_060beb62 + iVar14);
      if (*pcVar23 == '\0') {
        uVar16 = (*(code *)puVar2)();
        if ((uVar16 & 0x7f) == 0) {
          (*(code *)PTR_FUN_060becd0)((int)(short)iVar26,3,3,5,2,0,0);
          pcVar23[0xc] = '\0';
          pcVar23[0xd] = '\x10';
          uVar12 = (*(code *)puVar2)();
          sVar19 = DAT_060becc4;
          sVar17 = (*(code *)PTR_FUN_060becd4)(uVar12);
          *(short *)(pcVar23 + 8) = ((short)uVar12 - sVar17 * sVar19) + 0x28;
        }
      }
      else {
        *(int *)(pcVar23 + 0xc) = *(int *)(pcVar23 + 0xc) + (int)DAT_060beb64;
        iVar22 = (*(code *)puVar2)();
        iVar13 = iVar22;
        if (iVar22 < 0) {
          iVar13 = iVar22 + 7;
        }
        if (iVar22 + (iVar13 >> 3) * -8 == 2) {
          iVar13 = *(int *)(pcVar23 + 8);
          sVar19 = DAT_060beb66;
LAB_060beb38:
          *(int *)(pcVar23 + 8) = iVar13 + sVar19;
        }
        else {
          iVar22 = (*(code *)puVar2)();
          iVar13 = iVar22;
          if (iVar22 < 0) {
            iVar13 = iVar22 + 7;
          }
          if (iVar22 + (iVar13 >> 3) * -8 < 2) {
            iVar13 = *(int *)(pcVar23 + 8);
            sVar19 = DAT_060beb68;
            goto LAB_060beb38;
          }
        }
        if ((DAT_060beb6a < *(short *)(pcVar23 + 0xc)) ||
           ((uint)(int)DAT_060beb5e < ((int)*(short *)(pcVar23 + 8) - 0x28U & 0xffff))) {
          *pcVar23 = '\0';
        }
      }
      puVar3 = PTR_FUN_060becd8;
      iVar26 = iVar26 + 1;
      iVar14 = iVar14 + 0x4c;
    } while (iVar26 < 0x6b);
    iVar26 = 0x6b;
    iVar14 = (int)DAT_060becc6;
    do {
      pcVar23 = (char *)(uVar11 + DAT_060becc8 + iVar14);
      if (*pcVar23 == '\0') {
        uVar16 = (*(code *)puVar3)();
        if ((uVar16 & 0x7f) == 0) {
          (*(code *)PTR_FUN_060becd0)((int)(short)iVar26,4,3,5,2,0,0);
          pcVar23[0xc] = '\0';
          pcVar23[0xd] = '\x10';
          uVar12 = (*(code *)puVar3)();
          sVar19 = DAT_060becc4;
          sVar17 = (*(code *)PTR_FUN_060becd4)(uVar12);
          *(short *)(pcVar23 + 8) = ((short)uVar12 - sVar17 * sVar19) + 0x28;
        }
      }
      else {
        *(int *)(pcVar23 + 0xc) = *(int *)(pcVar23 + 0xc) + 0x3000;
        iVar22 = (*(code *)puVar3)();
        iVar13 = iVar22;
        if (iVar22 < 0) {
          iVar13 = iVar22 + 7;
        }
        if (iVar22 + (iVar13 >> 3) * -8 == 2) {
          iVar13 = *(int *)(pcVar23 + 8) + (int)DAT_060becca;
LAB_060bec3c:
          *(int *)(pcVar23 + 8) = iVar13;
        }
        else {
          iVar22 = (*(code *)puVar3)();
          iVar13 = iVar22;
          if (iVar22 < 0) {
            iVar13 = iVar22 + 7;
          }
          if (iVar22 + (iVar13 >> 3) * -8 < 2) {
            iVar13 = *(int *)(pcVar23 + 8) + -0x3000;
            goto LAB_060bec3c;
          }
        }
        if ((DAT_060beccc < *(short *)(pcVar23 + 0xc)) ||
           ((uint)(int)DAT_060becc4 < ((int)*(short *)(pcVar23 + 8) - 0x28U & 0xffff))) {
          *pcVar23 = '\0';
        }
      }
      iVar26 = iVar26 + 1;
      iVar14 = iVar14 + 0x4c;
      if (DAT_060becce < iVar26) {
                    // WARNING: Could not recover jumptable at 0x060becba. Too many branches
                    // WARNING: Treating indirect jump as call
        uVar11 = (*DAT_060becc0)();
        return uVar11;
      }
    } while( true );
  case 9:
    iVar13 = 0x3e;
    iVar14 = (int)DAT_060bed00;
    iVar26 = (int)DAT_060bed02;
    do {
      iVar13 = iVar13 + 1;
      *(undefined *)(uVar11 + iVar26) = 0;
      iVar26 = iVar26 + 0x4c;
    } while (iVar13 <= iVar14);
                    // WARNING: Could not recover jumptable at 0x060becf8. Too many branches
                    // WARNING: Treating indirect jump as call
    uVar11 = (*DAT_060becfc)();
    return uVar11;
  case 10:
    iVar26 = 0x3e;
    iVar13 = (int)DAT_060bee7c;
    iVar14 = (int)DAT_060bee7e;
    do {
      iVar22 = uVar11 + DAT_060bee80 + iVar14;
      uVar16 = (*(code *)PTR_FUN_060bee88)();
      bVar1 = (uVar16 & 1) == 0;
      if (bVar1) {
        (*(code *)PTR_FUN_060bee8c)((int)(short)iVar26,bVar1,3,5,2,0,0);
        iVar27 = (*(code *)PTR_FUN_060bee88)();
        if (iVar27 < 0) {
          iVar27 = iVar27 + 0x7f;
        }
        sVar19 = (short)iVar27;
        (*DAT_060bee90)();
        *extraout_r3 = extraout_r2 + sVar19 * -0x80 + 0x10;
        uVar12 = (*(code *)PTR_FUN_060bee88)();
        sVar19 = (*(code *)PTR_FUN_060bee94)(uVar12,iVar13);
        *(short *)(iVar22 + 8) = ((short)uVar12 - sVar19 * sVar17) + 0x28;
      }
      sVar19 = DAT_060bee7c;
      iVar26 = iVar26 + 1;
      iVar14 = iVar14 + 0x4c;
    } while (iVar26 < 0x52);
    iVar26 = 0x52;
    iVar13 = (int)DAT_060bee7c;
    iVar14 = (int)DAT_060bee82;
    do {
      iVar22 = uVar11 + DAT_060bee80 + iVar14;
      uVar16 = (*(code *)PTR_FUN_060bee88)();
      if ((uVar16 & 1) == 0) {
        (*(code *)PTR_FUN_060bee8c)((int)(short)iVar26,2,3,5,2,0,0);
        iVar27 = (*(code *)PTR_FUN_060bee88)();
        if (iVar27 < 0) {
          iVar27 = iVar27 + 0x7f;
        }
        sVar17 = (short)iVar27;
        (*DAT_060bee90)();
        *extraout_r3_00 = extraout_r2_00 + sVar17 * -0x80 + 0x10;
        uVar12 = (*(code *)PTR_FUN_060bee88)();
        sVar17 = (*(code *)PTR_FUN_060bee94)(uVar12,iVar13);
        *(short *)(iVar22 + 8) = ((short)uVar12 - sVar17 * sVar19) + 0x28;
      }
      sVar17 = DAT_060bee7c;
      iVar26 = iVar26 + 1;
      iVar14 = iVar14 + 0x4c;
    } while (iVar26 < 0x5c);
    iVar26 = 0x5c;
    iVar13 = (int)DAT_060bee7c;
    iVar14 = (int)DAT_060bee84;
    do {
      iVar22 = uVar11 + DAT_060bee80 + iVar14;
      uVar16 = (*(code *)PTR_FUN_060bee88)();
      if ((uVar16 & 1) == 0) {
        (*(code *)PTR_FUN_060bee8c)((int)(short)iVar26,3,3,5,2,0,0);
        iVar27 = (*(code *)PTR_FUN_060bee88)();
        if (iVar27 < 0) {
          iVar27 = iVar27 + 0x7f;
        }
        sVar19 = (short)iVar27;
        (*DAT_060bee90)();
        *extraout_r3_01 = extraout_r2_01 + sVar19 * -0x80 + 0x10;
        uVar12 = (*(code *)PTR_FUN_060bf018)();
        sVar19 = (*(code *)PTR_FUN_060bf01c)(uVar12,iVar13);
        *(short *)(iVar22 + 8) = ((short)uVar12 - sVar19 * sVar17) + 0x28;
      }
      sVar19 = DAT_060bf010;
      iVar26 = iVar26 + 1;
      iVar14 = iVar14 + 0x4c;
    } while (iVar26 < 0x6b);
    iVar26 = 0x6b;
    iVar13 = (int)DAT_060bf010;
    iVar14 = (int)DAT_060bf012;
    do {
      iVar22 = uVar11 + DAT_060bf014 + iVar14;
      uVar16 = (*(code *)PTR_FUN_060bf018)();
      if ((uVar16 & 1) == 0) {
        (*(code *)PTR_FUN_060bf020)((int)(short)iVar26,4,3,5,2,0,0);
        iVar27 = (*(code *)PTR_FUN_060bf018)();
        if (iVar27 < 0) {
          iVar27 = iVar27 + 0x7f;
        }
        sVar17 = (short)iVar27;
        (*DAT_060bf024)();
        *extraout_r3_02 = extraout_r2_02 + sVar17 * -0x80 + 0x10;
        uVar12 = (*(code *)PTR_FUN_060bf018)();
        sVar17 = (*(code *)PTR_FUN_060bf01c)(uVar12,iVar13);
        *(short *)(iVar22 + 8) = ((short)uVar12 - sVar17 * sVar19) + 0x28;
      }
      iVar26 = iVar26 + 1;
      iVar14 = iVar14 + 0x4c;
    } while (iVar26 <= DAT_060bf016);
                    // WARNING: Could not recover jumptable at 0x060bef60. Too many branches
                    // WARNING: Treating indirect jump as call
    uVar11 = (*DAT_060bef64)();
    return uVar11;
  case 0xb:
    iVar26 = 0x3e;
    do {
      pcVar23 = (char *)(uVar11 + iVar26 * 0x4c + (int)DAT_060bf014);
      if (*pcVar23 == '\0') {
        iVar14 = (*(code *)puVar3)();
        iVar13 = (*(code *)puVar4)(iVar14,0x1e);
        bVar1 = iVar14 + iVar13 * -0x1e == 0;
        if (bVar1) {
          (*(code *)PTR_FUN_060bf208)((int)(short)iVar26,8,4,0x18,bVar1,0,0);
          uVar12 = (*(code *)puVar3)();
          psVar21 = (short *)(pcVar23 + 0xc);
          sVar19 = (*(code *)puVar4)(uVar12,0x14);
          *psVar21 = (short)uVar12 + sVar19 * -0x14 + 0x2a;
          uVar16 = (*(code *)puVar3)();
          if ((uVar16 & 1) == 0) {
            uVar12 = (*(code *)puVar3)();
            psVar21 = (short *)(pcVar23 + 8);
            sVar19 = (*(code *)puVar4)(uVar12,10);
            sVar19 = (short)uVar12 + sVar19 * -10 + 0x78;
          }
          else {
            uVar12 = (*(code *)puVar3)();
            psVar21 = (short *)(pcVar23 + 8);
            sVar19 = (*(code *)puVar4)(uVar12,10);
            sVar19 = (short)uVar12 + sVar19 * -10 + DAT_060bf36c;
          }
          *psVar21 = sVar19;
        }
      }
      else {
        psVar21 = (short *)(pcVar23 + 0xc);
        if (*psVar21 < 0x33) {
          iVar13 = (*(code *)puVar3)();
          iVar14 = iVar13;
          if (iVar13 < 0) {
            iVar14 = iVar13 + 3;
          }
          *psVar21 = *psVar21 - ((short)iVar13 - ((ushort)iVar14 & 0xfffc));
          iVar13 = (*(code *)puVar3)();
          iVar14 = iVar13;
          if (iVar13 < 0) {
            iVar14 = iVar13 + 7;
          }
          if (iVar13 + (iVar14 >> 3) * -8 == 2) {
            uVar12 = (*(code *)puVar3)();
            sVar19 = *psVar21;
            sVar17 = (*(code *)puVar4)(uVar12,5);
            *psVar21 = (sVar19 + -2) - ((short)uVar12 + sVar17 * -5);
          }
          else {
            iVar13 = (*(code *)puVar3)();
            iVar14 = iVar13;
            if (iVar13 < 0) {
              iVar14 = iVar13 + 7;
            }
            if (iVar13 + (iVar14 >> 3) * -8 < 2) goto LAB_060bf0a2;
          }
        }
        else {
          uVar12 = (*(code *)puVar3)();
          sVar19 = (*(code *)puVar4)(uVar12,3);
          *psVar21 = *psVar21 + (short)uVar12 + sVar19 * -3;
          iVar13 = (*(code *)puVar3)();
          iVar14 = iVar13;
          if (iVar13 < 0) {
            iVar14 = iVar13 + 7;
          }
          if (iVar13 + (iVar14 >> 3) * -8 == 3) {
LAB_060bf0a2:
            iVar13 = (*(code *)puVar3)();
            iVar14 = iVar13;
            if (iVar13 < 0) {
              iVar14 = iVar13 + 3;
            }
            sVar19 = ((short)iVar13 - ((ushort)iVar14 & 0xfffc)) + *psVar21 + 2;
          }
          else {
            iVar13 = (*(code *)puVar3)();
            iVar14 = iVar13;
            if (iVar13 < 0) {
              iVar14 = iVar13 + 7;
            }
            if (2 < iVar13 + (iVar14 >> 3) * -8) goto LAB_060bf0c2;
            iVar13 = (*(code *)puVar3)();
            iVar14 = iVar13;
            if (iVar13 < 0) {
              iVar14 = iVar13 + 3;
            }
            sVar19 = (*psVar21 + -2) - ((short)iVar13 - ((ushort)iVar14 & 0xfffc));
          }
          *psVar21 = sVar19;
        }
LAB_060bf0c2:
        psVar21 = (short *)(pcVar23 + 8);
        sVar19 = *psVar21;
        if (sVar19 < 0x5a) {
          iVar13 = (*(code *)puVar3)();
          iVar14 = iVar13;
          if (iVar13 < 0) {
            iVar14 = iVar13 + 3;
          }
          sVar19 = (*psVar21 + -4) - ((short)iVar13 - ((ushort)iVar14 & 0xfffc));
LAB_060bf15a:
          *psVar21 = sVar19;
        }
        else if (DAT_060bf202 < sVar19) {
          if (DAT_060bf204 < sVar19) {
            iVar13 = (*(code *)puVar3)();
            iVar14 = iVar13;
            if (iVar13 < 0) {
              iVar14 = iVar13 + 3;
            }
            sVar19 = ((short)iVar13 - ((ushort)iVar14 & 0xfffc)) + *psVar21 + 4;
            goto LAB_060bf15a;
          }
          uVar16 = (*(code *)puVar3)();
          *psVar21 = *psVar21 + 3 +
                     (short)uVar16 +
                     (short)((int)(((uVar16 >> 0x10) * 2 >> 0x10) + uVar16) >> 1) * -2;
        }
        else {
          uVar16 = (*(code *)puVar3)();
          *psVar21 = (*psVar21 + -3) -
                     ((short)uVar16 +
                     (short)((int)(((uVar16 >> 0x10) * 2 >> 0x10) + uVar16) >> 1) * -2);
        }
        if ((0x36 < (ushort)(*(short *)(pcVar23 + 0xc) - 0x10U)) ||
           ((uint)(int)DAT_060bf206 < ((int)*(short *)(pcVar23 + 8) - 0x28U & 0xffff))) {
          *pcVar23 = '\0';
        }
      }
      puVar5 = PTR_FUN_060bf37c;
      puVar2 = PTR_FUN_060bf378;
      iVar26 = iVar26 + 1;
    } while (iVar26 < 0x7a);
    iVar26 = 0x7a;
    iStack_24 = (int)DAT_060bf36e;
    do {
      pcVar23 = (char *)(uVar11 + DAT_060bf370 + iStack_24);
      if (*pcVar23 == '\0') {
        iVar14 = (*(code *)puVar2)();
        iVar13 = (*(code *)puVar5)(iVar14,0x14);
        bVar1 = iVar14 + iVar13 * -0x14 == 0;
        if (bVar1) {
          (*(code *)PTR_FUN_060bf508)((int)(short)iVar26,8,4,0x18,bVar1,0,0);
          uVar12 = (*(code *)puVar2)();
          psVar21 = (short *)(pcVar23 + 0xc);
          sVar19 = (*(code *)puVar5)(uVar12,10);
          *psVar21 = (short)uVar12 + sVar19 * -10 + 0x2a;
          uVar12 = (*(code *)puVar2)();
          psVar21 = (short *)(pcVar23 + 8);
          sVar19 = (*(code *)puVar5)(uVar12,10);
          *psVar21 = (short)uVar12 + sVar19 * -10 + DAT_060bf500;
        }
      }
      else {
        uVar12 = (*(code *)puVar2)();
        psVar21 = (short *)(pcVar23 + 0xc);
        sVar19 = (*(code *)puVar5)(uVar12,3);
        psVar25 = (short *)(pcVar23 + 8);
        *psVar21 = *psVar21 + -1 + (sVar19 * 3 - (short)uVar12);
        if (DAT_060bf372 < *psVar25) {
          iVar13 = (*(code *)puVar2)();
          iVar14 = iVar13;
          if (iVar13 < 0) {
            iVar14 = iVar13 + 3;
          }
          sVar19 = *psVar25 + ((short)iVar13 - ((ushort)iVar14 & 0xfffc));
        }
        else {
          uVar12 = (*(code *)puVar2)();
          sVar19 = (*(code *)puVar5)(uVar12,3);
          sVar19 = *psVar25 + (sVar19 * 3 - (short)uVar12);
        }
        *psVar25 = sVar19;
        iVar14 = (*(code *)puVar2)();
        iVar13 = (*(code *)puVar5)(iVar14,6);
        if (iVar14 + iVar13 * -6 < 3) {
          iVar14 = (*(code *)puVar2)();
          iVar13 = (*(code *)puVar5)(iVar14,6);
          if (iVar14 + iVar13 * -6 < 3) {
            uVar16 = (*(code *)puVar2)();
            sVar19 = (*(short *)(pcVar23 + 8) + -1) -
                     ((short)uVar16 +
                     (short)((int)(((uVar16 >> 0x10) * 2 >> 0x10) + uVar16) >> 1) * -2);
            goto LAB_060bf342;
          }
        }
        else {
          uVar16 = (*(code *)puVar2)();
          sVar19 = *(short *)(pcVar23 + 8) + 1 +
                   (short)uVar16 + (short)((int)(((uVar16 >> 0x10) * 2 >> 0x10) + uVar16) >> 1) * -2
          ;
LAB_060bf342:
          *(short *)(pcVar23 + 8) = sVar19;
        }
        if ((0x36 < (ushort)(*(short *)(pcVar23 + 0xc) - 0x10U)) ||
           ((uint)(int)DAT_060bf374 < ((int)*(short *)(pcVar23 + 8) - 0x28U & 0xffff))) {
          *pcVar23 = '\0';
        }
      }
      iVar26 = iVar26 + 1;
      iStack_24 = iStack_24 + 0x4c;
      if (DAT_060bf502 < iVar26) {
                    // WARNING: Could not recover jumptable at 0x060bf414. Too many branches
                    // WARNING: Treating indirect jump as call
        uVar11 = (*DAT_060bf418)();
        return uVar11;
      }
    } while( true );
  case 0xc:
    iVar26 = 0x3e;
    do {
      pcVar23 = (char *)(uVar11 + iVar26 * 0x4c + (int)DAT_060bf504);
      if (*pcVar23 == '\0') {
        iVar14 = (*(code *)puVar5)();
        iVar13 = (*(code *)puVar6)(iVar14,0x1e);
        bVar1 = iVar14 + iVar13 * -0x1e == 0;
        if (bVar1) {
          (*(code *)PTR_FUN_060bf68c)((int)(short)iVar26,8,4,0x18,bVar1,0,0);
          uVar12 = (*(code *)puVar5)();
          psVar21 = (short *)(pcVar23 + 0xc);
          sVar19 = (*(code *)puVar6)(uVar12,0x14);
          *psVar21 = (short)uVar12 + sVar19 * -0x14 + 0x23;
          uVar16 = (*(code *)puVar5)();
          if ((uVar16 & 1) == 0) {
            uVar12 = (*(code *)puVar5)();
            psVar21 = (short *)(pcVar23 + 8);
            sVar19 = (*(code *)puVar6)(uVar12,10);
            sVar19 = (short)uVar12 + sVar19 * -10 + 0x78;
          }
          else {
            uVar12 = (*(code *)puVar5)();
            psVar21 = (short *)(pcVar23 + 8);
            sVar19 = (*(code *)puVar6)(uVar12,10);
            sVar19 = (short)uVar12 + sVar19 * -10 + DAT_060bf7ec;
          }
          *psVar21 = sVar19;
        }
      }
      else {
        psVar21 = (short *)(pcVar23 + 0xc);
        if (*psVar21 < 0x2e) {
          uVar16 = (*(code *)puVar5)();
          *psVar21 = *psVar21 -
                     ((short)uVar16 +
                     (short)((int)(((uVar16 >> 0x10) * 2 >> 0x10) + uVar16) >> 1) * -2);
          iVar13 = (*(code *)puVar5)();
          iVar14 = iVar13;
          if (iVar13 < 0) {
            iVar14 = iVar13 + 7;
          }
          if (iVar13 + (iVar14 >> 3) * -8 != 2) {
            iVar13 = (*(code *)puVar5)();
            iVar14 = iVar13;
            if (iVar13 < 0) {
              iVar14 = iVar13 + 7;
            }
            if (1 < iVar13 + (iVar14 >> 3) * -8) goto LAB_060bf552;
            goto LAB_060bf534;
          }
LAB_060bf4e0:
          uVar12 = (*(code *)puVar5)();
          sVar19 = *psVar21;
          sVar17 = (*(code *)puVar6)(uVar12,3);
          *psVar21 = sVar19 + -1 + (sVar17 * 3 - (short)uVar12);
        }
        else {
          uVar12 = (*(code *)puVar5)();
          sVar19 = (*(code *)puVar6)(uVar12,3);
          *psVar21 = *psVar21 + (short)uVar12 + sVar19 * -3;
          iVar13 = (*(code *)puVar5)();
          iVar14 = iVar13;
          if (iVar13 < 0) {
            iVar14 = iVar13 + 7;
          }
          if (iVar13 + (iVar14 >> 3) * -8 == 3) {
LAB_060bf534:
            uVar16 = (*(code *)puVar5)();
            *psVar21 = *psVar21 + 1 +
                       (short)uVar16 +
                       (short)((int)(((uVar16 >> 0x10) * 2 >> 0x10) + uVar16) >> 1) * -2;
          }
          else {
            iVar13 = (*(code *)puVar5)();
            iVar14 = iVar13;
            if (iVar13 < 0) {
              iVar14 = iVar13 + 7;
            }
            if (iVar13 + (iVar14 >> 3) * -8 < 3) goto LAB_060bf4e0;
          }
        }
LAB_060bf552:
        psVar21 = (short *)(pcVar23 + 8);
        sVar19 = *psVar21;
        if (sVar19 < 0x5a) {
          uVar12 = (*(code *)puVar5)();
          sVar19 = *psVar21;
          sVar17 = (*(code *)puVar6)(uVar12,5);
          sVar19 = (sVar19 + -2) - ((short)uVar12 + sVar17 * -5);
        }
        else if (DAT_060bf686 < sVar19) {
          if (DAT_060bf688 < sVar19) {
            uVar12 = (*(code *)puVar5)();
            sVar19 = *psVar21;
            sVar17 = (*(code *)puVar6)(uVar12,5);
            sVar17 = (short)uVar12 + sVar17 * -5;
            sVar19 = sVar19 + 2;
          }
          else {
            uVar12 = (*(code *)puVar5)();
            sVar19 = *psVar21;
            sVar17 = (*(code *)puVar6)(uVar12,3);
            sVar17 = (short)uVar12 + sVar17 * -3;
            sVar19 = sVar19 + 1;
          }
          sVar19 = sVar19 + sVar17;
        }
        else {
          uVar12 = (*(code *)puVar5)();
          sVar19 = *psVar21;
          sVar17 = (*(code *)puVar6)(uVar12,3);
          sVar19 = sVar19 + -1 + (sVar17 * 3 - (short)uVar12);
        }
        *psVar21 = sVar19;
        if ((0x36 < (ushort)(*(short *)(pcVar23 + 0xc) - 0x10U)) ||
           ((uint)(int)DAT_060bf68a < ((int)*(short *)(pcVar23 + 8) - 0x28U & 0xffff))) {
          *pcVar23 = '\0';
        }
      }
      puVar3 = PTR_FUN_060bf7fc;
      puVar2 = PTR_FUN_060bf7f8;
      iVar26 = iVar26 + 1;
    } while (iVar26 < 0x7a);
    iVar26 = 0x7a;
    iStack_24 = (int)DAT_060bf7ee;
    do {
      pcVar23 = (char *)(uVar11 + DAT_060bf7f0 + iStack_24);
      if (*pcVar23 == '\0') {
        iVar14 = (*(code *)puVar2)();
        uVar16 = (*(code *)puVar3)(iVar14,0x14);
        bVar1 = iVar14 + uVar16 * -0x14 == 0;
        if (bVar1) {
          (*(code *)PTR_FUN_060bf998)((int)(short)iVar26,8,4,0x18,bVar1,0,0);
          uVar12 = (*(code *)puVar2)();
          psVar21 = (short *)(pcVar23 + 0xc);
          sVar19 = (*(code *)puVar3)(uVar12,10);
          *psVar21 = (short)uVar12 + sVar19 * -10 + 0x2a;
          uVar12 = (*(code *)puVar2)();
          psVar21 = (short *)(pcVar23 + 8);
          uVar16 = (*(code *)puVar3)(uVar12,10);
          *psVar21 = (short)uVar12 + (short)uVar16 * -10 + DAT_060bf990;
        }
      }
      else {
        uVar16 = (*(code *)puVar2)();
        psVar21 = (short *)(pcVar23 + 8);
        *(short *)(pcVar23 + 0xc) =
             *(short *)(pcVar23 + 0xc) +
             (short)uVar16 + (short)((int)(((uVar16 >> 0x10) * 2 >> 0x10) + uVar16) >> 1) * -2;
        if (DAT_060bf7f2 < *psVar21) {
          uVar12 = (*(code *)puVar2)();
          sVar19 = (*(code *)puVar3)(uVar12,3);
          sVar19 = *psVar21 + (short)uVar12 + sVar19 * -3;
        }
        else {
          uVar12 = (*(code *)puVar2)();
          sVar19 = (*(code *)puVar3)(uVar12,3);
          sVar19 = *psVar21 + (sVar19 * 3 - (short)uVar12);
        }
        *psVar21 = sVar19;
        iVar14 = (*(code *)puVar2)();
        iVar13 = (*(code *)puVar3)(iVar14,6);
        if (iVar14 + iVar13 * -6 < 3) {
          iVar14 = (*(code *)puVar2)();
          uVar16 = (*(code *)puVar3)(iVar14,6);
          if ((int)(iVar14 + uVar16 * -6) < 3) {
            uVar16 = (*(code *)puVar2)();
            uVar16 = uVar16 + ((int)(((uVar16 >> 0x10) * 2 >> 0x10) + uVar16) >> 1) * -2;
            sVar19 = (*(short *)(pcVar23 + 8) + -1) - (short)uVar16;
            goto LAB_060bf7c2;
          }
        }
        else {
          uVar16 = (*(code *)puVar2)();
          uVar16 = uVar16 + ((int)(((uVar16 >> 0x10) * 2 >> 0x10) + uVar16) >> 1) * -2;
          sVar19 = *(short *)(pcVar23 + 8) + 1 + (short)uVar16;
LAB_060bf7c2:
          *(short *)(pcVar23 + 8) = sVar19;
        }
        if ((0x36 < (ushort)(*(short *)(pcVar23 + 0xc) - 0x10U)) ||
           ((uint)(int)DAT_060bf7f4 < ((int)*(short *)(pcVar23 + 8) - 0x28U & 0xffff))) {
          *pcVar23 = '\0';
        }
      }
      iVar26 = iVar26 + 1;
      iStack_24 = iStack_24 + 0x4c;
      if (DAT_060bf992 < iVar26) {
        return uVar16;
      }
    } while( true );
  case 0xd:
    iVar26 = 0x3e;
    do {
      pcVar23 = (char *)(uVar11 + iVar26 * 0x4c + (int)DAT_060bf994);
      if (*pcVar23 == '\0') {
        iVar14 = (*(code *)puVar7)();
        iVar13 = (*(code *)puVar8)(iVar14,0x28);
        bVar1 = iVar14 + iVar13 * -0x28 == 0;
        if (bVar1) {
          (*(code *)PTR_FUN_060bfb20)((int)(short)iVar26,8,4,0x18,bVar1,0,0);
          uVar12 = (*(code *)puVar7)();
          psVar21 = (short *)(pcVar23 + 0xc);
          sVar19 = (*(code *)puVar8)(uVar12,0x14);
          *psVar21 = (short)uVar12 + sVar19 * -0x14 + 0x1e;
          uVar16 = (*(code *)puVar7)();
          if ((uVar16 & 1) == 0) {
            uVar12 = (*(code *)puVar7)();
            psVar21 = (short *)(pcVar23 + 8);
            sVar19 = (*(code *)puVar8)(uVar12,10);
            sVar19 = (short)uVar12 + sVar19 * -10 + 0x78;
          }
          else {
            uVar12 = (*(code *)puVar7)();
            psVar21 = (short *)(pcVar23 + 8);
            sVar19 = (*(code *)puVar8)(uVar12,10);
            sVar19 = (short)uVar12 + sVar19 * -10 + DAT_060bfc80;
          }
          *psVar21 = sVar19;
        }
      }
      else {
        psVar21 = (short *)(pcVar23 + 0xc);
        if (*psVar21 < 0x29) {
          uVar16 = (*(code *)puVar7)();
          *psVar21 = *psVar21 -
                     ((short)uVar16 +
                     (short)((int)(((uVar16 >> 0x10) * 2 >> 0x10) + uVar16) >> 1) * -2);
          iVar13 = (*(code *)puVar7)();
          iVar14 = iVar13;
          if (iVar13 < 0) {
            iVar14 = iVar13 + 7;
          }
          if (iVar13 + (iVar14 >> 3) * -8 == 2) {
            uVar16 = (*(code *)puVar7)();
            *psVar21 = *psVar21 -
                       ((short)uVar16 +
                       (short)((int)(((uVar16 >> 0x10) * 2 >> 0x10) + uVar16) >> 1) * -2);
          }
          else {
            iVar13 = (*(code *)puVar7)();
            iVar14 = iVar13;
            if (iVar13 < 0) {
              iVar14 = iVar13 + 7;
            }
            if (iVar13 + (iVar14 >> 3) * -8 < 2) goto LAB_060bf9c4;
          }
        }
        else {
          uVar12 = (*(code *)puVar7)();
          sVar19 = (*(code *)puVar8)(uVar12,3);
          *psVar21 = *psVar21 + (short)uVar12 + sVar19 * -3;
          iVar13 = (*(code *)puVar7)();
          iVar14 = iVar13;
          if (iVar13 < 0) {
            iVar14 = iVar13 + 7;
          }
          if (iVar13 + (iVar14 >> 3) * -8 == 3) {
LAB_060bf9c4:
            uVar16 = (*(code *)puVar7)();
            *psVar21 = *psVar21 + 1 +
                       (short)uVar16 +
                       (short)((int)(((uVar16 >> 0x10) * 2 >> 0x10) + uVar16) >> 1) * -2;
          }
          else {
            iVar13 = (*(code *)puVar7)();
            iVar14 = iVar13;
            if (iVar13 < 0) {
              iVar14 = iVar13 + 7;
            }
            if (iVar13 + (iVar14 >> 3) * -8 < 3) {
              uVar12 = (*(code *)puVar7)();
              sVar19 = *psVar21;
              sVar17 = (*(code *)puVar8)(uVar12,3);
              *psVar21 = sVar19 + -2 + (sVar17 * 3 - (short)uVar12);
            }
          }
        }
        psVar21 = (short *)(pcVar23 + 8);
        sVar19 = *psVar21;
        if (sVar19 < 0x5a) {
          uVar12 = (*(code *)puVar7)();
          sVar19 = *psVar21;
          sVar17 = (*(code *)puVar8)(uVar12,5);
          sVar19 = (sVar19 + -2) - ((short)uVar12 + sVar17 * -5);
LAB_060bfa70:
          *psVar21 = sVar19;
        }
        else if (DAT_060bfb18 < sVar19) {
          if (DAT_060bfb1a < sVar19) {
            uVar12 = (*(code *)puVar7)();
            sVar19 = *psVar21;
            sVar17 = (*(code *)puVar8)(uVar12,5);
            sVar19 = sVar19 + 2 + (short)uVar12 + sVar17 * -5;
            goto LAB_060bfa70;
          }
          iVar13 = (*(code *)puVar7)();
          iVar14 = iVar13;
          if (iVar13 < 0) {
            iVar14 = iVar13 + 3;
          }
          *psVar21 = *psVar21 + ((short)iVar13 - ((ushort)iVar14 & 0xfffc));
        }
        else {
          iVar13 = (*(code *)puVar7)();
          iVar14 = iVar13;
          if (iVar13 < 0) {
            iVar14 = iVar13 + 3;
          }
          *psVar21 = *psVar21 - ((short)iVar13 - ((ushort)iVar14 & 0xfffc));
        }
        if ((0x36 < (ushort)(*(short *)(pcVar23 + 0xc) - 0x10U)) ||
           ((uint)(int)DAT_060bfb1c < ((int)*(short *)(pcVar23 + 8) - 0x28U & 0xffff))) {
          *pcVar23 = '\0';
        }
      }
      puVar3 = PTR_FUN_060bfc90;
      puVar2 = PTR_FUN_060bfc8c;
      iVar26 = iVar26 + 1;
    } while (iVar26 < 0x7a);
    iVar26 = 0x7a;
    iStack_24 = (int)DAT_060bfc82;
    do {
      pcVar23 = (char *)(uVar11 + DAT_060bfc84 + iStack_24);
      if (*pcVar23 == '\0') {
        iVar14 = (*(code *)puVar2)();
        uVar16 = (*(code *)puVar3)(iVar14,0x1e);
        bVar1 = iVar14 + uVar16 * -0x1e == 0;
        if (bVar1) {
          (*(code *)PTR_FUN_060bfe10)((int)(short)iVar26,8,4,0x18,bVar1,0,0);
          uVar12 = (*(code *)puVar2)();
          psVar21 = (short *)(pcVar23 + 0xc);
          sVar19 = (*(code *)puVar3)(uVar12,10);
          *psVar21 = (short)uVar12 + sVar19 * -10 + 0x28;
          uVar12 = (*(code *)puVar2)();
          psVar21 = (short *)(pcVar23 + 8);
          uVar16 = (*(code *)puVar3)(uVar12,10);
          *psVar21 = (short)uVar12 + (short)uVar16 * -10 + DAT_060bfe00;
        }
      }
      else {
        uVar12 = (*(code *)puVar2)();
        psVar21 = (short *)(pcVar23 + 0xc);
        sVar19 = (*(code *)puVar3)(uVar12,3);
        psVar25 = (short *)(pcVar23 + 8);
        *psVar21 = *psVar21 + (short)uVar12 + sVar19 * -3;
        if (DAT_060bfc86 < *psVar25) {
          iVar13 = (*(code *)puVar2)();
          iVar14 = iVar13;
          if (iVar13 < 0) {
            iVar14 = iVar13 + 3;
          }
          sVar19 = *psVar25 + ((short)iVar13 - ((ushort)iVar14 & 0xfffc));
        }
        else {
          uVar12 = (*(code *)puVar2)();
          sVar19 = (*(code *)puVar3)(uVar12,3);
          sVar19 = *psVar25 + (sVar19 * 3 - (short)uVar12);
        }
        *psVar25 = sVar19;
        iVar14 = (*(code *)puVar2)();
        iVar13 = (*(code *)puVar3)(iVar14,6);
        if (iVar14 + iVar13 * -6 < 3) {
          iVar14 = (*(code *)puVar2)();
          uVar16 = (*(code *)puVar3)(iVar14,6);
          if ((int)(iVar14 + uVar16 * -6) < 3) {
            uVar16 = (*(code *)puVar2)();
            uVar16 = uVar16 + ((int)(((uVar16 >> 0x10) * 2 >> 0x10) + uVar16) >> 1) * -2;
            sVar19 = (*(short *)(pcVar23 + 8) + -1) - (short)uVar16;
            goto LAB_060bfc56;
          }
        }
        else {
          uVar16 = (*(code *)puVar2)();
          uVar16 = uVar16 + ((int)(((uVar16 >> 0x10) * 2 >> 0x10) + uVar16) >> 1) * -2;
          sVar19 = *(short *)(pcVar23 + 8) + 1 + (short)uVar16;
LAB_060bfc56:
          *(short *)(pcVar23 + 8) = sVar19;
        }
        if ((0x36 < (ushort)(*(short *)(pcVar23 + 0xc) - 0x10U)) ||
           ((uint)(int)DAT_060bfc88 < ((int)*(short *)(pcVar23 + 8) - 0x28U & 0xffff))) {
          *pcVar23 = '\0';
        }
      }
      iVar26 = iVar26 + 1;
      iStack_24 = iStack_24 + 0x4c;
      if (DAT_060bfe02 < iVar26) {
        return uVar16;
      }
    } while( true );
  case 0xe:
    iVar26 = 0x3e;
    iVar14 = (int)DAT_060bfe04;
    do {
      pcVar23 = (char *)(uVar11 + DAT_060bfe06 + iVar14);
      if (*pcVar23 == '\0') {
        iVar13 = (*(code *)puVar9)();
        iVar22 = (*(code *)PTR_FUN_060bff88)(iVar13,0x32);
        bVar1 = iVar13 + iVar22 * -0x32 == 0;
        if (bVar1) {
          (*(code *)PTR_FUN_060bff8c)((int)(short)iVar26,8,4,0x18,bVar1,0,0);
          uVar12 = (*(code *)puVar9)();
          sVar19 = (*(code *)PTR_FUN_060bff88)(uVar12,0xf);
          *(short *)(pcVar23 + 0xc) = (short)uVar12 + sVar19 * -0xf + 0x14;
          uVar12 = (*(code *)puVar9)();
          iVar13 = (int)DAT_060bff80;
          sVar19 = (*(code *)PTR_FUN_060bff88)(uVar12,iVar13);
          *(short *)(pcVar23 + 8) = ((short)uVar12 - sVar19 * (short)iVar13) + 0x3c;
        }
      }
      else {
        uVar16 = (*(code *)puVar9)();
        psVar21 = (short *)(pcVar23 + 8);
        *(short *)(pcVar23 + 0xc) =
             *(short *)(pcVar23 + 0xc) +
             (short)uVar16 + (short)((int)(((uVar16 >> 0x10) * 2 >> 0x10) + uVar16) >> 1) * -2;
        sVar19 = *psVar21;
        if (sVar19 < 0x5a) {
          iVar22 = (*(code *)puVar9)();
          iVar13 = iVar22;
          if (iVar22 < 0) {
            iVar13 = iVar22 + 3;
          }
          sVar19 = *psVar21 - ((short)iVar22 - ((ushort)iVar13 & 0xfffc));
        }
        else if (DAT_060bfe08 < sVar19) {
          if (DAT_060bfe0a < sVar19) {
            uVar15 = (*(code *)puVar9)();
            uVar16 = uVar15;
            if ((int)uVar15 < 0) {
              uVar16 = uVar15 + 3;
            }
            uVar20 = (ushort)uVar16 & 0xfffc;
          }
          else {
            uVar15 = (*(code *)puVar9)();
            uVar20 = (short)((int)(((uVar15 >> 0x10) * 2 >> 0x10) + uVar15) >> 1) * 2;
          }
          sVar19 = *psVar21 + ((short)uVar15 - uVar20);
        }
        else {
          uVar16 = (*(code *)puVar9)();
          sVar19 = *psVar21 -
                   ((short)uVar16 +
                   (short)((int)(((uVar16 >> 0x10) * 2 >> 0x10) + uVar16) >> 1) * -2);
        }
        *psVar21 = sVar19;
        if ((0x36 < (ushort)(*(short *)(pcVar23 + 0xc) - 0x10U)) ||
           ((uint)(int)DAT_060bfe0c < ((int)*(short *)(pcVar23 + 8) - 0x28U & 0xffff))) {
          *pcVar23 = '\0';
        }
      }
      puVar3 = PTR_FUN_060bff90;
      puVar2 = PTR_FUN_060bff88;
      iVar26 = iVar26 + 1;
      iVar14 = iVar14 + 0x4c;
    } while (iVar26 < 0x7a);
    iVar26 = 0x7a;
    iStack_24 = (int)DAT_060bff82;
    do {
      pcVar23 = (char *)(uVar11 + DAT_060bff84 + iStack_24);
      if (*pcVar23 == '\0') {
        iVar14 = (*(code *)puVar3)();
        uVar16 = (*(code *)puVar2)(iVar14,0x19);
        bVar1 = iVar14 + uVar16 * -0x19 == 0;
        if (bVar1) {
          (*(code *)PTR_FUN_060c00c4)((int)(short)iVar26,8,4,0x18,bVar1,0,0);
          uVar12 = (*(code *)puVar3)();
          psVar21 = (short *)(pcVar23 + 0xc);
          sVar19 = (*(code *)puVar2)(uVar12,10);
          *psVar21 = (short)uVar12 + sVar19 * -10 + 0x19;
          uVar12 = (*(code *)puVar3)();
          psVar21 = (short *)(pcVar23 + 8);
          uVar16 = (*(code *)puVar2)(uVar12,10);
          *psVar21 = (short)uVar12 + (short)uVar16 * -10 + DAT_060c00b6;
        }
      }
      else {
        uVar16 = (*(code *)puVar3)();
        *(short *)(pcVar23 + 0xc) =
             *(short *)(pcVar23 + 0xc) +
             (short)uVar16 + (short)((int)(((uVar16 >> 0x10) * 2 >> 0x10) + uVar16) >> 1) * -2;
        iVar14 = (*(code *)puVar3)();
        iVar13 = (*(code *)puVar2)(iVar14,10);
        if (iVar14 + iVar13 * -10 == 0) {
          uVar12 = (*(code *)puVar3)();
          psVar21 = (short *)(pcVar23 + 8);
          sVar19 = *psVar21;
          uVar16 = (*(code *)puVar2)(uVar12,3);
          sVar19 = sVar19 + 1 + (short)uVar12 + (short)uVar16 * -3;
LAB_060bff56:
          *psVar21 = sVar19;
        }
        else {
          iVar14 = (*(code *)puVar3)();
          iVar13 = (*(code *)puVar2)(iVar14,10);
          uVar16 = iVar14 + iVar13 * -10;
          if (uVar16 == 1) {
            uVar12 = (*(code *)puVar3)();
            psVar21 = (short *)(pcVar23 + 8);
            sVar19 = *psVar21;
            uVar16 = (*(code *)puVar2)(uVar12,3);
            sVar19 = sVar19 + -1 + ((short)uVar16 * 3 - (short)uVar12);
            goto LAB_060bff56;
          }
        }
        if ((0x36 < (ushort)(*(short *)(pcVar23 + 0xc) - 0x10U)) ||
           ((uint)(int)DAT_060bff86 < ((int)*(short *)(pcVar23 + 8) - 0x28U & 0xffff))) {
          *pcVar23 = '\0';
        }
      }
      iVar26 = iVar26 + 1;
      iStack_24 = iStack_24 + 0x4c;
      if (DAT_060c00b8 < iVar26) {
        return uVar16;
      }
    } while( true );
  case 0xf:
    iVar26 = 0x3e;
    iVar14 = (int)DAT_060c00ba;
    do {
      pcVar23 = (char *)(uVar11 + DAT_060c00bc + iVar14);
      if (*pcVar23 == '\0') {
        cVar18 = (*(code *)puVar10)();
        if (cVar18 == '\0') {
          (*(code *)PTR_FUN_060c021c)((int)(short)iVar26,8,4,0x18,cVar18 == '\0',0,0);
          pcVar23[0xc] = '\0';
          pcVar23[0xd] = '\x10';
          uVar12 = (*(code *)puVar10)();
          sVar19 = DAT_060c020e;
          sVar17 = (*(code *)PTR_FUN_060c0220)(uVar12);
          *(short *)(pcVar23 + 8) = ((short)uVar12 - sVar17 * sVar19) + 0x28;
        }
      }
      else {
        *(int *)(pcVar23 + 0xc) = *(int *)(pcVar23 + 0xc) + DAT_060c00cc;
        iVar22 = (*(code *)puVar10)();
        iVar13 = iVar22;
        if (iVar22 < 0) {
          iVar13 = iVar22 + 7;
        }
        if (iVar22 + (iVar13 >> 3) * -8 == 3) {
          iVar13 = *(int *)(pcVar23 + 8);
          sVar19 = DAT_060c00be;
LAB_060c008c:
          *(int *)(pcVar23 + 8) = iVar13 + sVar19;
        }
        else {
          iVar22 = (*(code *)puVar10)();
          iVar13 = iVar22;
          if (iVar22 < 0) {
            iVar13 = iVar22 + 7;
          }
          if (iVar22 + (iVar13 >> 3) * -8 < 3) {
            iVar13 = *(int *)(pcVar23 + 8);
            sVar19 = DAT_060c00c0;
            goto LAB_060c008c;
          }
        }
        if ((0x36 < (ushort)(*(short *)(pcVar23 + 0xc) - 0x10U)) ||
           ((uint)(int)DAT_060c00c2 < ((int)*(short *)(pcVar23 + 8) - 0x28U & 0xffff))) {
          *pcVar23 = '\0';
        }
      }
      puVar2 = PTR_FUN_060c0224;
      iVar26 = iVar26 + 1;
      iVar14 = iVar14 + 0x4c;
    } while (iVar26 < 0x66);
    iVar26 = 0x66;
    iVar14 = (int)DAT_060c0210;
    do {
      pcVar23 = (char *)(uVar11 + DAT_060c0212 + iVar14);
      if (*pcVar23 == '\0') {
        uVar16 = (*(code *)puVar2)();
        bVar1 = (uVar16 & 0xff) == 0;
        if (bVar1) {
          (*(code *)PTR_FUN_060c021c)((int)(short)iVar26,7,4,0x18,bVar1,0,0);
          pcVar23[0xc] = '\0';
          pcVar23[0xd] = '\x10';
          uVar12 = (*(code *)puVar2)();
          sVar19 = DAT_060c020e;
          uVar16 = (*(code *)PTR_FUN_060c0220)(uVar12);
          *(short *)(pcVar23 + 8) = ((short)uVar12 - (short)uVar16 * sVar19) + 0x28;
        }
      }
      else {
        *(int *)(pcVar23 + 0xc) = *(int *)(pcVar23 + 0xc) + (int)DAT_060c0214;
        iVar22 = (*(code *)puVar2)();
        iVar13 = iVar22;
        if (iVar22 < 0) {
          iVar13 = iVar22 + 7;
        }
        if (iVar22 + (iVar13 >> 3) * -8 == 3) {
          iVar13 = *(int *)(pcVar23 + 8);
          uVar16 = 3;
          sVar19 = DAT_060c0216;
LAB_060c018c:
          *(int *)(pcVar23 + 8) = iVar13 + sVar19;
        }
        else {
          uVar16 = (*(code *)puVar2)();
          uVar15 = uVar16;
          if ((int)uVar16 < 0) {
            uVar15 = uVar16 + 7;
          }
          if ((int)(uVar16 + ((int)uVar15 >> 3) * -8) < 3) {
            iVar13 = *(int *)(pcVar23 + 8);
            sVar19 = DAT_060c0218;
            goto LAB_060c018c;
          }
        }
        if ((0x36 < (ushort)(*(short *)(pcVar23 + 0xc) - 0x10U)) ||
           ((uint)(int)DAT_060c020e < ((int)*(short *)(pcVar23 + 8) - 0x28U & 0xffff))) {
          *pcVar23 = '\0';
        }
      }
      iVar26 = iVar26 + 1;
      iVar14 = iVar14 + 0x4c;
      if (DAT_060c021a < iVar26) {
        return uVar16;
      }
    } while( true );
  case 0x10:
    iVar26 = 0;
    piVar24 = DAT_060c0354;
    if (0 < *(short *)((int)DAT_060c0350 + DAT_060be3f8)) {
      do {
        iVar26 = iVar26 + 1;
        piVar24 = piVar24 + 2;
      } while (iVar26 < *(short *)((int)DAT_060c0350 + DAT_060be3f8));
    }
    iVar26 = (int)*(short *)((int)DAT_060c0350 + DAT_060be3f8);
    if (iVar26 < iVar26 + 3) {
      do {
        iVar26 = iVar26 + 1;
        iVar13 = (*(code *)PTR_FUN_060c035c)();
        iVar22 = (*(code *)PTR_FUN_060c0360)(iVar13,10);
        *piVar24 = (iVar13 + iVar22 * -10) * 0x10000;
        piVar24[1] = iVar14;
        piVar24 = piVar24 + 2;
      } while (iVar26 < *(short *)((int)DAT_060c0350 + uVar11) + 3);
    }
    iVar26 = DAT_060c0358;
    iVar14 = (int)*(short *)((int)DAT_060c0350 + uVar11);
    if (iVar14 < iVar14 + 5) {
      do {
        iVar14 = iVar14 + 1;
        iVar13 = (*(code *)PTR_FUN_060c035c)();
        iVar22 = (*(code *)PTR_FUN_060c0360)(iVar13,0x14);
        *piVar24 = (iVar13 + iVar22 * -0x14) * 0x10000;
        piVar24[1] = iVar26;
        piVar24 = piVar24 + 2;
      } while (iVar14 < *(short *)((int)DAT_060c0350 + uVar11) + 5);
    }
    iVar26 = DAT_060c0358;
    iVar14 = (int)*(short *)((int)DAT_060c0350 + uVar11);
    uVar16 = uVar11;
    if (iVar14 < iVar14 + 3) {
      do {
        iVar14 = iVar14 + 1;
        iVar13 = (*(code *)PTR_FUN_060c035c)();
        iVar22 = (*(code *)PTR_FUN_060c0360)(iVar13,10);
        *piVar24 = (iVar13 + iVar22 * -10) * 0x10000;
        piVar24[1] = iVar26;
        piVar24 = piVar24 + 2;
      } while (iVar14 < *(short *)((int)DAT_060c0350 + uVar11) + 3);
      return uVar11;
    }
    break;
  case 0x11:
    iVar26 = (*(code *)PTR_FUN_060c035c)();
    iVar14 = (*(code *)PTR_FUN_060c0360)(iVar26,0x50);
    iVar26 = iVar26 + iVar14 * -0x50;
    iVar14 = iVar26 + 0x28;
    if (((iVar14 < 0x3c) || (iVar26 - 0x2eU < 4)) || (uVar16 = uVar11, 0x6e < iVar14)) {
      *(short *)((int)DAT_060c0350 + uVar11) = (short)iVar14;
      uVar16 = uVar11;
    }
    break;
  case 0x12:
    iVar26 = 0;
    piVar24 = DAT_060c045c;
    do {
      iVar14 = (*(code *)PTR_FUN_060c0464)();
      iVar27 = (int)DAT_060c0456;
      uVar15 = (uint)*(short *)(iVar27 + uVar11);
      iVar22 = 0xa0 - ((int)(((uVar15 >> 0x10) * 2 >> 0x10) + uVar15) >> 1);
      uVar16 = (*(code *)PTR_FUN_060c0468)(iVar14,iVar22);
      iVar26 = iVar26 + 1;
      if ((int)uVar15 < 0) {
        uVar15 = uVar15 + 3;
      }
      *piVar24 = ((0x50 - (iVar14 - uVar16 * iVar22)) - (int)(short)((int)uVar15 >> 2)) * 0x10000;
      piVar24[1] = iVar13;
      sVar19 = DAT_060c045a;
      piVar24 = piVar24 + 2;
    } while (iVar26 <= DAT_060c0458);
    psVar21 = (short *)(uVar11 + iVar27);
    sVar17 = *psVar21;
    *psVar21 = sVar17 + 1;
    if (sVar19 < (short)(sVar17 + 1)) {
      *psVar21 = sVar19;
    }
    break;
  case 0x13:
    iVar26 = 0;
    psVar21 = (short *)(DAT_060be3f8 + (int)DAT_060c0456);
    piVar24 = DAT_060c045c;
    do {
      *piVar24 = (0x28 - *psVar21) * iVar22;
      piVar24[1] = iVar13;
      iVar26 = iVar26 + 1;
      piVar24[2] = (*psVar21 + -0x28) * iVar22;
      piVar24[3] = iVar13;
      piVar24 = piVar24 + 4;
    } while (iVar26 < 0x78);
    psVar21 = (short *)(uVar11 + (int)DAT_060c0456);
    sVar19 = *psVar21;
    *psVar21 = sVar19 + 1;
    uVar16 = 0x28;
    if (0x27 < (short)(sVar19 + 1)) {
      *psVar21 = 0x28;
    }
    break;
  case 0x14:
    uVar16 = (*(code *)PTR_FUN_060c0478)(DAT_060c0474,0,DAT_060c0470);
  }
  return uVar16;
}



void FUN_060c047c(void)

{
  *DAT_060c0494 = 0;
  (*(code *)PTR_FUN_060c0498)();
  return;
}



void FUN_060c05a4(void)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  *DAT_060c05ec = 0;
  uVar1 = 0;
  puVar2 = DAT_060c05f0;
  do {
    *puVar2 = 0xffffffff;
    puVar3 = DAT_060c05f4;
    uVar1 = uVar1 + 1;
    puVar2 = puVar2 + 1;
  } while (uVar1 < 0x40);
  DAT_060c05f0[*DAT_060c05ec] = 0;
  *DAT_060c05f8 = 0;
  uVar1 = 0;
  do {
    *puVar3 = 0;
    uVar1 = uVar1 + 1;
    puVar3 = puVar3 + 1;
  } while (uVar1 < 0x10);
  return;
}



void FUN_060c05fc(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  puVar1 = PTR_FUN_060c0630;
  uVar2 = *(undefined4 *)(DAT_060c062c + *DAT_060c0628 * 4);
  *DAT_060c0634 = 0;
  *DAT_060c0638 = 0xffffffff;
  do {
    uVar2 = (*(code *)puVar1)(uVar2);
  } while( true );
}



uint FUN_060c063c(uint param_1)

{
  char cVar1;
  uint *puVar2;
  undefined *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  puVar2 = DAT_060c0744;
  uVar4 = *DAT_060c0744;
  uVar5 = uVar4 + 1;
  *DAT_060c0744 = uVar5;
  *(uint *)(DAT_060c0748 + uVar4 * 4) = param_1;
  if (0x3f < uVar5) {
    *puVar2 = 0;
  }
  (*(code *)PTR_FUN_060c074c)(param_1);
  (*(code *)PTR_FUN_060c0750)();
  puVar2 = DAT_060c0754;
  *DAT_060c0754 = (int)DAT_060c073e & param_1;
  (*(code *)PTR_FUN_060c0758)(param_1);
  uVar5 = *puVar2;
  uVar4 = 0;
  iVar6 = DAT_060c075c;
  do {
    *(undefined *)(iVar6 + 0x41) = 0;
    puVar2 = DAT_060c0754;
    uVar4 = uVar4 + 1;
    iVar6 = iVar6 + DAT_060c0740;
  } while (uVar4 < 0x10);
  cVar1 = *(char *)(*DAT_060c0754 + *DAT_060c0760);
  if (cVar1 == '\t') {
    uVar5 = *DAT_060c0754 + 1;
    *DAT_060c0754 = uVar5;
    puVar3 = PTR_FUN_060c0764;
    *puVar2 = uVar5;
    while (uVar4 = (*(code *)puVar3)(0), (int)uVar4 < 0) {
      *puVar2 = uVar5;
    }
  }
  else if (cVar1 == '\n') {
    uVar4 = 0xffffffff;
  }
  else {
    *DAT_060c0768 = 0xffffffff;
    puVar3 = PTR_FUN_060c076c;
    do {
      *puVar2 = uVar5;
      uVar4 = (*(code *)puVar3)();
    } while ((int)uVar4 < 0);
  }
  (*(code *)PTR_FUN_060c0770)();
  if (DAT_060c0774 < (int)uVar4) {
    if (DAT_060c0778 < (int)uVar4) {
      iVar6 = *DAT_060c077c;
      *DAT_060c077c = iVar6 + -1;
      uVar4 = *(uint *)(DAT_060c0780 + (iVar6 + -1) * 4);
    }
    else {
      iVar6 = *DAT_060c077c;
      *DAT_060c077c = iVar6 + 1;
      *(uint *)(DAT_060c0780 + iVar6 * 4) = param_1;
      uVar4 = uVar4 & DAT_060c0784;
    }
  }
  return uVar4;
}



void FUN_060c0788(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = *DAT_060c07a4;
  *DAT_060c07a4 = iVar1 + 1;
  *(undefined4 *)(DAT_060c07a8 + iVar1 * 4) = param_1;
  return;
}



void FUN_060c07ac(void)

{
  *DAT_060c07bc = *DAT_060c07bc + -1;
  return;
}



uint FUN_060c07c0(int param_1)

{
  byte bVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  ushort uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  piVar3 = DAT_060c0850;
  piVar2 = DAT_060c084c;
  if (param_1 == 0) {
    iVar8 = *DAT_060c084c;
    uVar7 = *DAT_060c0858;
    *DAT_060c084c = iVar8 + 1;
    iVar6 = *DAT_060c0850;
    bVar1 = *(byte *)(iVar8 + iVar6);
    *DAT_060c0854 = (uint)bVar1;
    iVar9 = iVar8 + 2;
    *piVar2 = iVar9;
    uVar5 = CONCAT11(bVar1,*(undefined *)(iVar8 + 1 + iVar6));
  }
  else {
    iVar8 = *DAT_060c084c;
    *DAT_060c084c = iVar8 + 1;
    iVar6 = *piVar3;
    uVar7 = (uint)*(byte *)(iVar8 + iVar6);
    *piVar2 = iVar8 + 2;
    bVar1 = *(byte *)(iVar8 + 1 + iVar6);
    *DAT_060c0854 = (uint)bVar1;
    iVar9 = iVar8 + 3;
    *piVar2 = iVar9;
    uVar5 = CONCAT11(bVar1,*(undefined *)(iVar8 + 2 + iVar6));
    uVar4 = (uint)uVar5;
    if (uVar7 != (int)DAT_060c084a) goto LAB_060c083a;
    uVar7 = *DAT_060c0858;
  }
  uVar4 = (short)uVar5 + -2 + iVar9;
LAB_060c083a:
  return uVar4 | ((uVar7 << 8) >> 1) << 8;
}



uint FUN_060c085c(void)

{
  byte bVar1;
  ushort uVar2;
  uint *puVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  
  piVar5 = DAT_060c08a8;
  piVar4 = DAT_060c08a4;
  puVar3 = DAT_060c08a0;
  iVar6 = *DAT_060c08a4;
  *DAT_060c08a4 = iVar6 + 1;
  iVar7 = *piVar5;
  bVar1 = *(byte *)(iVar6 + iVar7);
  *puVar3 = (uint)bVar1;
  *piVar4 = iVar6 + 2;
  uVar2 = CONCAT11(bVar1,*(undefined *)(iVar6 + 1 + iVar7));
  *puVar3 = (uint)uVar2;
  *piVar4 = iVar6 + 3;
  return DAT_060c08ac & CONCAT21(uVar2,*(undefined *)(iVar6 + 2 + iVar7));
}



int FUN_060c08b0(void)

{
  byte bVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  piVar3 = DAT_060c08fc;
  piVar2 = DAT_060c08f8;
  iVar4 = *DAT_060c08f8;
  *DAT_060c08f8 = iVar4 + 1;
  iVar5 = *piVar3;
  bVar1 = *(byte *)(iVar4 + iVar5);
  *DAT_060c0900 = (uint)bVar1;
  *piVar2 = iVar4 + 2;
  iVar4 = (uint)CONCAT11(bVar1,*(undefined *)(iVar4 + 1 + iVar5)) * 2;
  if (*(char *)(*DAT_060c0904 + iVar4 + -1) != '\0') {
    iVar4 = iVar4 + -1;
  }
  return iVar4;
}



void FUN_060c0908(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  piVar2 = DAT_060c0958;
  piVar1 = DAT_060c0954;
  iVar4 = *DAT_060c0954;
  *DAT_060c0954 = iVar4 + 1;
  iVar6 = *piVar2;
  uVar5 = (uint)*(byte *)(iVar4 + iVar6);
  *DAT_060c095c = uVar5;
  if ((uint)(int)DAT_060c0950 < uVar5) {
    iVar3 = (int)DAT_060c0952;
    *piVar1 = iVar4 + 2;
    uVar5 = (uVar5 + iVar3) * 0x100 | (uint)*(byte *)(iVar4 + 1 + iVar6);
  }
  *DAT_060c0954 = *DAT_060c0954 + uVar5;
  return;
}



undefined4 FUN_060c0960(undefined4 param_1)

{
  return param_1;
}



uint FUN_060c096c(uint param_1)

{
  int iVar1;
  int iVar2;
  
  param_1 = param_1 & 0xffff;
  if (DAT_060c09ac < (int)param_1) {
    iVar1 = (*(code *)PTR_FUN_060c09b4)(*DAT_060c09b0);
    iVar2 = DAT_060c09b8;
  }
  else {
    if ((int)param_1 <= DAT_060c09bc) {
      return param_1;
    }
    iVar1 = (*(code *)PTR_FUN_060c09b4)(*DAT_060c09c0);
    iVar2 = DAT_060c09c4;
  }
  return param_1 + iVar1 + iVar2;
}



void FUN_060c09c8(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)PTR_FUN_060c09f4)();
  (*(code *)PTR_FUN_060c09f8)(uVar1,((int)(short)((uint)param_1 >> 0x10) & 0x1fU) + 1);
  return;
}



uint FUN_060c09fc(uint param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = (int)param_1 >> 3;
  param_1 = param_1 & 7;
  if ((int)(param_1 + param_2) < 9) {
    uVar2 = (*(code *)PTR_FUN_060c0acc)
                      (*(undefined *)(iVar6 + *DAT_060c0ac8),(8 - param_2) - param_1);
    iVar6 = (*(code *)PTR_FUN_060c0ad0)(1,param_2);
    uVar2 = iVar6 - 1U & uVar2;
  }
  else {
    iVar7 = *DAT_060c0ac8;
    bVar1 = *(byte *)(iVar6 + iVar7);
    uVar2 = (*(code *)PTR_FUN_060c0acc)((int)DAT_060c0ac4,param_1);
    uVar2 = bVar1 & uVar2;
    iVar5 = param_2 + -8 + param_1;
    iVar6 = iVar6 + 1;
    if (7 < iVar5) {
      pbVar4 = (byte *)(iVar6 + iVar7);
      do {
        bVar1 = *pbVar4;
        pbVar4 = pbVar4 + 1;
        iVar6 = iVar6 + 1;
        iVar5 = iVar5 + -8;
        uVar2 = uVar2 << 8 | (uint)bVar1;
      } while (7 < iVar5);
    }
    if (iVar5 != 0) {
      uVar2 = (*(code *)PTR_FUN_060c0ad0)(uVar2,iVar5);
      uVar3 = (*(code *)PTR_FUN_060c0acc)(*(undefined *)(iVar6 + *DAT_060c0ac8),8 - iVar5);
      uVar2 = uVar2 | uVar3;
    }
  }
  return uVar2;
}



void FUN_060c0ad4(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)PTR_FUN_060c0b04)();
  (*(code *)PTR_FUN_060c0b08)(uVar1,((int)(short)((uint)param_1 >> 0x10) & 0x1fU) + 1,param_2);
  return;
}



void FUN_060c0b0c(int param_1,int param_2,int param_3)

{
  undefined *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  uint uVar5;
  char cVar9;
  int iVar10;
  int iVar11;
  
  uVar3 = param_1 + -1 + param_2;
  iVar11 = (int)uVar3 >> 3;
  uVar3 = uVar3 & 7;
  if ((param_2 < 0x20) && (iVar4 = (*(code *)PTR_FUN_060c0c3c)(param_3), iVar4 != 0)) {
    param_3 = (*(code *)PTR_FUN_060c0c40)(1,param_2);
    param_3 = param_3 + -1;
  }
  puVar1 = PTR_FUN_060c0c40;
  if ((int)(uVar3 + 1) < param_2) {
    iVar4 = *DAT_060c0c44;
    bVar7 = *(byte *)(iVar11 + iVar4);
    iVar10 = (*(code *)PTR_FUN_060c0c40)(2,uVar3);
    bVar8 = (*(code *)puVar1)(iVar10 + -1,7 - uVar3);
    bVar6 = (*(code *)puVar1)(param_3,7 - uVar3);
    *(byte *)(iVar11 + iVar4) = bVar7 & ~bVar8 | bVar6;
    uVar5 = (*(code *)PTR_FUN_060c0c3c)(param_3,uVar3 + 1);
    piVar2 = DAT_060c0c44;
    iVar4 = (param_2 + -1) - uVar3;
    while( true ) {
      iVar11 = iVar11 + -1;
      if (iVar4 < 8) break;
      iVar4 = iVar4 + -8;
      *(byte *)(iVar11 + *piVar2) = (byte)uVar5;
      uVar5 = uVar5 >> 8;
    }
    if (iVar4 == 0) {
      return;
    }
    iVar10 = *DAT_060c0c44;
    bVar7 = *(byte *)(iVar11 + iVar10);
    cVar9 = (*(code *)PTR_FUN_060c0c40)(1,iVar4);
    bVar7 = bVar7 & -cVar9 | (byte)uVar5;
  }
  else {
    iVar10 = *DAT_060c0c44;
    bVar8 = *(byte *)(iVar11 + iVar10);
    iVar4 = (*(code *)PTR_FUN_060c0c40)(1,param_2);
    bVar6 = (*(code *)puVar1)(iVar4 + -1,7 - uVar3);
    bVar7 = (*(code *)puVar1)(param_3,7 - uVar3);
    bVar7 = bVar8 & ~bVar6 | bVar7;
  }
  *(byte *)(iVar11 + iVar10) = bVar7;
  return;
}



void FUN_060c0c48(int param_1)

{
  int *piVar1;
  
  piVar1 = DAT_060c0c70;
  if (*DAT_060c0c70 != param_1) {
    (*(code *)PTR_FUN_060c0c74)();
    *piVar1 = param_1;
  }
  return;
}



uint FUN_060c0c78(void)

{
  undefined uVar1;
  ushort uVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  uint *puVar9;
  undefined *puVar10;
  code *pcVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  byte bVar14;
  uint uVar15;
  int extraout_r2;
  int iVar16;
  uint uVar17;
  int iVar18;
  
  piVar5 = DAT_060c0de4;
  piVar3 = DAT_060c0de0;
  iVar16 = *DAT_060c0de0;
  *DAT_060c0de0 = iVar16 + 1;
  puVar10 = PTR_FUN_060c103c;
  puVar9 = DAT_060c1024;
  piVar8 = DAT_060c1020;
  piVar7 = DAT_060c101c;
  piVar6 = DAT_060c0de4;
  piVar4 = DAT_060c0de0;
  iVar18 = *piVar5;
  bVar14 = *(byte *)(iVar16 + iVar18);
  uVar17 = (uint)bVar14;
  if ((bVar14 & 0x80) == 0) {
    *piVar3 = iVar16;
    uVar17 = (*(code *)PTR_FUN_060c0de8)();
    return uVar17;
  }
  if ((uVar17 & 0xe0) == (int)DAT_060c0dd2) {
    *piVar3 = iVar16;
    uVar17 = (*(code *)PTR_FUN_060c0dec)();
    pcVar11 = (code *)PTR_FUN_060c0df0;
LAB_060c0eae:
    uVar17 = (*pcVar11)(uVar17);
    return uVar17;
  }
  uVar15 = uVar17 & 0xf0;
  if (uVar15 == (int)DAT_060c0dd4) {
LAB_060c0cfa:
    iVar16 = *DAT_060c0de0;
    *DAT_060c0de0 = iVar16 + 1;
    return (uint)*(byte *)(iVar16 + *DAT_060c0de4) | (uVar17 & 0xf) << 8;
  }
  if ((int)DAT_060c0dd4 < (int)uVar15) {
    if (uVar15 == (int)DAT_060c0dd8) {
      *piVar3 = iVar16 + 2;
      uVar17 = (uVar17 & 0xf) << 8 | (uint)*(byte *)(iVar16 + 1 + iVar18);
      pcVar11 = (code *)PTR_FUN_060c0df4;
      goto LAB_060c0e88;
    }
    if (uVar15 == (int)DAT_060c0dda) {
      return uVar17 & 0xf;
    }
  }
  else if (uVar15 == (int)DAT_060c0dd6) goto LAB_060c0cfa;
  switch(uVar17 - (int)DAT_060c0ddc) {
  case 0:
    iVar16 = *DAT_060c0de0;
    *DAT_060c0de0 = iVar16 + 1;
    uVar17 = (uint)*(byte *)(iVar16 + *DAT_060c0de4);
    break;
  case 1:
    iVar16 = *DAT_060c0de0;
    *DAT_060c0de0 = iVar16 + 1;
    iVar18 = *piVar6;
    uVar17 = (uint)*(byte *)(iVar16 + iVar18);
    *DAT_060c0df8 = uVar17;
    *piVar4 = iVar16 + 2;
    bVar14 = *(byte *)(iVar16 + 1 + iVar18);
    goto LAB_060c0e5e;
  case 2:
  case 4:
    iVar16 = *DAT_060c101c;
    *DAT_060c101c = iVar16 + 1;
    iVar18 = *piVar8;
    bVar14 = *(byte *)(iVar16 + iVar18);
    *puVar9 = (uint)bVar14;
    *piVar7 = iVar16 + 2;
    uVar2 = CONCAT11(bVar14,*(undefined *)(iVar16 + 1 + iVar18));
    *puVar9 = (uint)uVar2;
    *piVar7 = iVar16 + 3;
    uVar17 = (uint)CONCAT21(uVar2,*(undefined *)(iVar16 + 2 + iVar18));
    *puVar9 = uVar17;
    *piVar7 = iVar16 + 4;
    bVar14 = *(byte *)(iVar16 + 3 + iVar18);
    goto LAB_060c0e5e;
  case 3:
    iVar16 = *DAT_060c101c;
    *DAT_060c101c = iVar16 + 1;
    iVar18 = *piVar8;
    uVar17 = (uint)*(byte *)(iVar16 + iVar18);
    *DAT_060c1024 = uVar17;
    *piVar7 = iVar16 + 2;
    bVar14 = *(byte *)(iVar16 + 1 + iVar18);
LAB_060c0e5e:
    uVar17 = (uint)bVar14 | uVar17 << 8;
    break;
  case 5:
    uVar17 = (*(code *)PTR_FUN_060c1028)(0xffffffff);
    break;
  case 6:
    iVar16 = *DAT_060c101c;
    *DAT_060c101c = iVar16 + 1;
    uVar17 = (uint)*(byte *)(iVar16 + *DAT_060c1020);
    pcVar11 = (code *)PTR_FUN_060c1028;
LAB_060c0e88:
    uVar17 = (*pcVar11)(uVar17);
    return uVar17;
  case 7:
    iVar16 = *DAT_060c101c;
    *DAT_060c101c = iVar16 + 1;
    uVar1 = *(undefined *)(iVar16 + *DAT_060c1020);
    uVar13 = 0xffffffff;
    goto LAB_060c0f0a;
  case 8:
  case 9:
    uVar17 = uVar17 & 1;
    pcVar11 = (code *)PTR_FUN_060c102c;
    goto LAB_060c0eae;
  case 10:
  case 0xb:
    uVar17 = (*(code *)PTR_FUN_060c102c)(uVar17 & 1);
    uVar17 = (*(code *)PTR_FUN_060c1028)(uVar17 | DAT_060c1030);
    break;
  case 0xc:
  case 0xd:
    uVar13 = (*(code *)PTR_FUN_060c102c)(uVar17 & 1);
    uVar17 = (*(code *)PTR_FUN_060c1034)(0xffffffff,uVar13);
    break;
  case 0xe:
  case 0xf:
    iVar16 = *DAT_060c101c;
    *DAT_060c101c = iVar16 + 1;
    uVar1 = *(undefined *)(iVar16 + *DAT_060c1020);
    uVar13 = (*(code *)PTR_FUN_060c102c)(uVar17 & 1);
LAB_060c0f0a:
    uVar17 = (*(code *)PTR_FUN_060c1034)(uVar1,uVar13);
    break;
  case 0x10:
    uVar17 = (*(code *)PTR_FUN_060c1038)();
    break;
  case 0x11:
    iVar16 = (*(code *)PTR_FUN_060c103c)();
    uVar17 = (uint)(iVar16 == 0);
    break;
  case 0x12:
    iVar16 = (*(code *)PTR_FUN_060c103c)();
    iVar18 = (*(code *)puVar10)();
    uVar17 = iVar16 * iVar18;
    break;
  case 0x13:
    uVar13 = (*(code *)PTR_FUN_060c103c)();
    uVar12 = (*(code *)puVar10)();
    uVar17 = (*(code *)PTR_FUN_060c1040)(uVar13,uVar12);
    break;
  case 0x14:
    iVar16 = (*(code *)PTR_FUN_060c103c)();
    uVar13 = (*(code *)puVar10)();
    iVar18 = (*(code *)PTR_FUN_060c1040)(iVar16,uVar13);
    uVar17 = iVar16 - iVar18 * extraout_r2;
    break;
  case 0x15:
    iVar16 = (*(code *)PTR_FUN_060c103c)();
    iVar18 = (*(code *)puVar10)();
    uVar17 = iVar18 + iVar16;
    break;
  case 0x16:
    iVar16 = (*(code *)PTR_FUN_060c103c)();
    iVar18 = (*(code *)puVar10)();
    uVar17 = iVar16 - iVar18;
    break;
  case 0x17:
    uVar17 = (*(code *)PTR_FUN_060c1044)();
    break;
  case 0x18:
    uVar17 = (*(code *)PTR_FUN_060c103c)();
    uVar15 = (*(code *)puVar10)();
    uVar17 = (uint)(uVar17 < uVar15);
    break;
  case 0x19:
    uVar17 = (*(code *)PTR_FUN_060c103c)();
    uVar15 = (*(code *)puVar10)();
    uVar17 = (uint)(uVar15 < uVar17);
    break;
  case 0x1a:
    uVar17 = (*(code *)PTR_FUN_060c103c)();
    uVar15 = (*(code *)puVar10)();
    uVar17 = (uint)(uVar17 <= uVar15);
    break;
  case 0x1b:
    uVar17 = (*(code *)PTR_FUN_060c103c)();
    uVar15 = (*(code *)puVar10)();
    uVar17 = (uint)(uVar15 <= uVar17);
    break;
  case 0x1c:
    iVar16 = (*(code *)PTR_FUN_060c103c)();
    iVar18 = (*(code *)puVar10)();
    uVar17 = (uint)(iVar16 == iVar18);
    break;
  case 0x1d:
    iVar16 = (*(code *)PTR_FUN_060c103c)();
    iVar18 = (*(code *)puVar10)();
    uVar17 = iVar16 == iVar18 ^ 1;
    break;
  case 0x1e:
    uVar17 = (*(code *)PTR_FUN_060c1048)();
    break;
  case 0x1f:
    uVar17 = (*(code *)PTR_FUN_060c104c)();
    break;
  default:
    uVar17 = 0;
  }
  return uVar17;
}



int FUN_060c1050(void)

{
  int *piVar1;
  int *piVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  piVar2 = DAT_060c10cc;
  piVar1 = DAT_060c10c8;
  iVar5 = *DAT_060c10c8;
  *DAT_060c10c8 = iVar5 + 1;
  iVar7 = *piVar2;
  uVar6 = (uint)*(byte *)(iVar5 + iVar7);
  *DAT_060c10d0 = uVar6;
  iVar8 = 0;
  if ((uint)(int)DAT_060c10c2 < uVar6) {
    iVar4 = (int)DAT_060c10c4;
    *piVar1 = iVar5 + 2;
    uVar6 = (uVar6 + iVar4) * 0x100 | (uint)*(byte *)(iVar5 + 1 + iVar7);
  }
  puVar3 = PTR_FUN_060c10d4;
  piVar1 = DAT_060c10c8;
  iVar5 = *DAT_060c10c8;
  iVar7 = uVar6 + iVar5;
  while (iVar5 < iVar7) {
    iVar5 = (*(code *)puVar3)();
    iVar8 = iVar8 + iVar5;
    iVar5 = *piVar1;
  }
  return iVar8;
}



undefined4 FUN_060c10d8(void)

{
  int *piVar1;
  int *piVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  piVar2 = DAT_060c1158;
  piVar1 = DAT_060c1154;
  iVar5 = *DAT_060c1154;
  *DAT_060c1154 = iVar5 + 1;
  iVar7 = *piVar2;
  uVar6 = (uint)*(byte *)(iVar5 + iVar7);
  *DAT_060c115c = uVar6;
  if ((uint)(int)DAT_060c114e < uVar6) {
    iVar4 = (int)DAT_060c1150;
    *piVar1 = iVar5 + 2;
    uVar6 = (uVar6 + iVar4) * 0x100 | (uint)*(byte *)(iVar5 + 1 + iVar7);
  }
  puVar3 = PTR_FUN_060c1160;
  piVar1 = DAT_060c1154;
  iVar5 = *DAT_060c1154;
  iVar7 = uVar6 + iVar5;
  while( true ) {
    if (iVar7 <= iVar5) {
      return 1;
    }
    iVar5 = (*(code *)puVar3)();
    if (iVar5 == 0) break;
    iVar5 = *piVar1;
  }
  *DAT_060c1154 = iVar7;
  return 0;
}



undefined4 FUN_060c1164(void)

{
  int *piVar1;
  int *piVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  piVar2 = DAT_060c11e4;
  piVar1 = DAT_060c11e0;
  iVar5 = *DAT_060c11e0;
  *DAT_060c11e0 = iVar5 + 1;
  iVar7 = *piVar2;
  uVar6 = (uint)*(byte *)(iVar5 + iVar7);
  *DAT_060c11e8 = uVar6;
  if ((uint)(int)DAT_060c11da < uVar6) {
    iVar4 = (int)DAT_060c11dc;
    *piVar1 = iVar5 + 2;
    uVar6 = (uVar6 + iVar4) * 0x100 | (uint)*(byte *)(iVar5 + 1 + iVar7);
  }
  puVar3 = PTR_FUN_060c11ec;
  piVar1 = DAT_060c11e0;
  iVar5 = *DAT_060c11e0;
  iVar7 = uVar6 + iVar5;
  while( true ) {
    if (iVar7 <= iVar5) {
      return 0;
    }
    iVar5 = (*(code *)puVar3)();
    if (iVar5 != 0) break;
    iVar5 = *piVar1;
  }
  *DAT_060c11e0 = iVar7;
  return 1;
}



uint FUN_060c11f0(uint param_1)

{
  uint uVar1;
  uint *puVar2;
  
  if (-1 < (int)param_1) {
    if (DAT_060c1258 < (int)param_1) {
      uVar1 = *DAT_060c125c - 1;
      if (-1 < (int)uVar1) {
        puVar2 = DAT_060c1260 + uVar1;
        do {
          if (*puVar2 == (param_1 & DAT_060c1264)) break;
          uVar1 = uVar1 - 1;
          puVar2 = puVar2 + -1;
        } while (-1 < (int)uVar1);
      }
      return (~uVar1 >> 0x10) * 2 >> 0x10;
    }
    if ((int)param_1 <= *DAT_060c125c + -1) {
      return DAT_060c1260[*DAT_060c125c - (param_1 + 1)];
    }
  }
  return *DAT_060c1260;
}



uint FUN_060c1268(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  
  if (((int)param_1 < 0) || (-1 < param_2)) {
    if (((int)param_1 < 0) && (-1 < param_2)) {
      iVar1 = *DAT_060c1330 + -2;
      uVar2 = 1;
      if (iVar1 < 0) {
        iVar1 = *DAT_060c1330 + 0x3e;
      }
      piVar3 = (int *)(iVar1 * 4 + DAT_060c1334);
      while (-1 < *piVar3) {
        iVar4 = iVar1 + -1;
        if (*piVar3 == param_2) {
          return uVar2;
        }
        piVar3 = piVar3 + -1;
        if (iVar4 < 0) {
          piVar3 = (int *)((int)piVar3 + (int)DAT_060c132c);
          iVar4 = iVar1 + 0x3f;
        }
        uVar2 = uVar2 + 1;
        iVar1 = iVar4;
        if (0x3f < uVar2) {
          return 0;
        }
      }
    }
    else {
      if (0x3f < param_1) {
        param_1 = 0x3f;
      }
      iVar1 = *DAT_060c1330 + -2;
      if (iVar1 < 0) {
        iVar1 = *DAT_060c1330 + 0x3e;
      }
      if (0 < (int)param_1) {
        piVar3 = (int *)(iVar1 * 4 + DAT_060c1334);
        do {
          iVar4 = *piVar3;
          if (iVar4 < 0) {
            return 0;
          }
          iVar1 = iVar1 + -1;
          if (iVar4 == param_2) {
            return (uint)(iVar4 == param_2);
          }
          piVar3 = piVar3 + -1;
          if (iVar1 < 0) {
            piVar3 = (int *)(DAT_060c132e + DAT_060c1334);
            iVar1 = 0x3f;
          }
        } while (0 < (int)param_1);
      }
    }
  }
  else if (param_1 < 0x40) {
    iVar1 = *DAT_060c1330 - (param_1 + 1);
    if (iVar1 < 0) {
      iVar1 = iVar1 + 0x40;
    }
    uVar2 = *(uint *)(DAT_060c1334 + iVar1 * 4);
    if ((int)uVar2 < 0) {
      return 0;
    }
    return uVar2;
  }
  return 0;
}



void FUN_060c1338(void)

{
  (*(code *)PTR_FUN_060c134c)();
  return;
}



int FUN_060c1350(void)

{
  int *piVar1;
  int *piVar2;
  undefined *puVar3;
  code *pcVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  piVar2 = DAT_060c1494;
  piVar1 = DAT_060c1490;
  iVar6 = *DAT_060c1490;
  *DAT_060c1490 = iVar6 + 1;
  puVar3 = PTR_FUN_060c149c;
  iVar7 = *piVar2;
  uVar8 = (uint)*(byte *)(iVar6 + iVar7);
  if ((*(byte *)(iVar6 + iVar7) & 0x80) == 0) {
    *piVar1 = iVar6 + 2;
    return iVar7;
  }
  if ((uVar8 & 0xe0) == (int)DAT_060c1484) {
    *piVar1 = iVar6 + 3;
    return iVar7;
  }
  uVar5 = uVar8 & 0xf0;
  if (uVar5 == (int)DAT_060c1486) {
switchD_060c13f2_caseD_0:
    *DAT_060c1490 = *DAT_060c1490 + 1;
    return iVar7;
  }
  if ((int)DAT_060c1486 < (int)uVar5) {
    if (uVar5 == (int)DAT_060c148a) {
      *piVar1 = iVar6 + 2;
      iVar7 = (*(code *)PTR_FUN_060c1498)((uVar8 & 0xf) << 8 | (uint)*(byte *)(iVar6 + 1 + iVar7));
      return iVar7;
    }
    if (uVar5 == (int)DAT_060c148c) {
      return iVar7;
    }
  }
  else if (uVar5 == (int)DAT_060c1488) goto switchD_060c13f2_caseD_0;
  uVar8 = uVar8 - (int)DAT_060c148e;
  if (0x1f < uVar8) {
    return iVar7;
  }
  iVar7 = (int)&switchD_060c13f2::switchdataD_060c13f8 +
          (int)(short)(&switchD_060c13f2::switchdataD_060c13f8)[uVar8];
  switch(uVar8) {
  case 0:
  case 6:
  case 7:
    goto switchD_060c13f2_caseD_0;
  case 1:
  case 3:
  case 8:
  case 10:
  case 0xc:
    *DAT_060c1490 = *DAT_060c1490 + 2;
    break;
  case 2:
  case 4:
  case 0xf:
    *DAT_060c1490 = *DAT_060c1490 + 4;
    break;
  case 5:
    break;
  case 9:
  case 0xb:
  case 0xd:
  case 0xe:
  case 0x10:
    *DAT_060c1490 = *DAT_060c1490 + 3;
    break;
  case 0x11:
    pcVar4 = (code *)PTR_FUN_060c149c;
    goto LAB_060c1476;
  default:
    (*(code *)PTR_FUN_060c149c)();
    iVar7 = (*(code *)puVar3)();
    return iVar7;
  case 0x17:
  case 0x1e:
  case 0x1f:
    pcVar4 = (code *)PTR_FUN_060c14a0;
LAB_060c1476:
    iVar7 = (*pcVar4)();
  }
  return iVar7;
}



undefined4 FUN_060c14a4(int param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  short *psVar3;
  undefined4 *puVar4;
  code *pcVar5;
  int iVar6;
  undefined4 local_48 [4];
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  puVar1 = PTR_FUN_060c1738;
  puVar4 = local_48;
  psVar3 = (short *)(PTR_DAT_060c1734 + param_1 * 8);
  iVar6 = 0;
  if (0 < *psVar3) {
    do {
      iVar6 = iVar6 + 1;
      uVar2 = (*(code *)puVar1)();
      *puVar4 = uVar2;
      puVar4 = puVar4 + 1;
    } while (iVar6 < *psVar3);
  }
  puVar4 = (undefined4 *)(PTR_PTR_LAB_060c173c + param_1 * 8);
  pcVar5 = (code *)*puVar4;
  if (*(short *)(puVar4 + 1) == 0) {
    switch(*(undefined2 *)((int)puVar4 + 6)) {
    case 0:
      (*pcVar5)();
      break;
    case 1:
      (*pcVar5)(local_48[0]);
      break;
    case 2:
      (*pcVar5)(local_48[0],local_48[1]);
      break;
    case 3:
      (*pcVar5)(local_48[0],local_48[1],local_48[2]);
      break;
    case 4:
      (*pcVar5)(local_48[0],local_48[1],local_48[2],local_48[3]);
      break;
    case 5:
      (*pcVar5)(local_48[0],local_48[1],local_48[2],local_48[3],uStack_38);
      break;
    case 6:
      (*pcVar5)(local_48[0],local_48[1],local_48[2],local_48[3],uStack_38,uStack_34);
      break;
    case 7:
      (*pcVar5)(local_48[0],local_48[1],local_48[2],local_48[3],uStack_38,uStack_34,uStack_30);
      break;
    case 8:
      (*pcVar5)(local_48[0],local_48[1],local_48[2],local_48[3],uStack_38,uStack_34,uStack_30,
                uStack_2c);
      break;
    case 9:
      (*pcVar5)(local_48[0],local_48[1],local_48[2],local_48[3],uStack_38,uStack_34,uStack_30,
                uStack_2c,uStack_28);
      break;
    case 10:
      (*pcVar5)(local_48[0],local_48[1],local_48[2],local_48[3],uStack_38,uStack_34,uStack_30,
                uStack_2c,uStack_28,uStack_24);
    }
switchD_060c1622_caseD_b:
    uVar2 = 0;
  }
  else {
    switch(*(undefined2 *)((int)puVar4 + 6)) {
    case 0:
      uVar2 = (*pcVar5)();
      break;
    case 1:
      uVar2 = (*pcVar5)(local_48[0]);
      break;
    case 2:
      uVar2 = (*pcVar5)(local_48[0],local_48[1]);
      break;
    case 3:
      uVar2 = (*pcVar5)(local_48[0],local_48[1],local_48[2]);
      break;
    case 4:
      uVar2 = (*pcVar5)(local_48[0],local_48[1],local_48[2],local_48[3]);
      break;
    case 5:
      uVar2 = (*pcVar5)(local_48[0],local_48[1],local_48[2],local_48[3],uStack_38);
      break;
    case 6:
      uVar2 = (*pcVar5)(local_48[0],local_48[1],local_48[2],local_48[3],uStack_38,uStack_34);
      break;
    case 7:
      uVar2 = (*pcVar5)(local_48[0],local_48[1],local_48[2],local_48[3],uStack_38,uStack_34,
                        uStack_30);
      break;
    case 8:
      uVar2 = (*pcVar5)(local_48[0],local_48[1],local_48[2],local_48[3],uStack_38,uStack_34,
                        uStack_30,uStack_2c);
      break;
    case 9:
      uVar2 = (*pcVar5)(local_48[0],local_48[1],local_48[2],local_48[3],uStack_38,uStack_34,
                        uStack_30,uStack_2c,uStack_28);
      break;
    case 10:
      uVar2 = (*pcVar5)(local_48[0],local_48[1],local_48[2],local_48[3],uStack_38,uStack_34,
                        uStack_30,uStack_2c,uStack_28,uStack_24);
      break;
    default:
      goto switchD_060c1622_caseD_b;
    }
  }
  return uVar2;
}



void FUN_060c1740(int param_1)

{
  undefined *puVar1;
  short *psVar2;
  int iVar3;
  
  puVar1 = PTR_FUN_060c177c;
  psVar2 = (short *)(PTR_DAT_060c1778 + param_1 * 8);
  iVar3 = 0;
  if (0 < *psVar2) {
    do {
      iVar3 = iVar3 + 1;
      (*(code *)puVar1)();
    } while (iVar3 < *psVar2);
  }
  return;
}



void FUN_060c1780(void)

{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = DAT_060c17c8;
  puVar2 = DAT_060c17c4;
  do {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  } while (puVar2 <= puVar1);
  *DAT_060c17cc = DAT_060c17c4;
  *DAT_060c17d0 = *(undefined4 *)PTR_DAT_060c17d4;
  *DAT_060c17d8 = *(undefined4 *)PTR_DAT_060c17dc;
  (*(code *)PTR_FUN_060c17e0)();
  (*(code *)PTR_FUN_060c17e4)();
  (*(code *)PTR_FUN_060c17e8)();
  return;
}



void FUN_060c1cb8(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  
  puVar2 = PTR_DAT_060c1f1c;
  puVar1 = PTR_DAT_060c1f14;
  **(undefined4 **)PTR_DAT_060c1f14 = PTR_DAT_060c1f18;
  puVar3 = PTR_DAT_060c1f20;
  iVar4 = *(int *)puVar1;
  *(undefined **)(iVar4 + 4) = puVar2;
  *(undefined **)(iVar4 + 8) = puVar3;
  *(undefined **)(iVar4 + 0xc) = PTR_DAT_060c1f24;
  *(undefined **)(iVar4 + 0x10) = PTR_DAT_060c1f28;
  *(undefined **)(iVar4 + 0x14) = PTR_DAT_060c1f2c;
  *(undefined **)(iVar4 + 0x18) = PTR_DAT_060c1f30;
  *(undefined **)(iVar4 + 0x1c) = PTR_DAT_060c1f34;
  *(undefined **)(iVar4 + 0x20) = PTR_DAT_060c1f38;
  *(undefined **)(iVar4 + 0x24) = PTR_DAT_060c1f3c;
  *(undefined **)(iVar4 + 0x28) = PTR_DAT_060c1f40;
  *(undefined **)(iVar4 + 0x2c) = PTR_DAT_060c1f44;
  *(undefined **)(iVar4 + 0x30) = PTR_DAT_060c1f48;
  *(undefined **)(iVar4 + 0x34) = PTR_DAT_060c1f4c;
  *(undefined **)(iVar4 + 0x38) = PTR_DAT_060c1f50;
  *(undefined **)(iVar4 + 0x3c) = PTR_DAT_060c1f54;
  *(undefined **)(iVar4 + 0x40) = PTR_DAT_060c1f58;
  *(undefined **)(iVar4 + 0x44) = PTR_DAT_060c1f5c;
  *(undefined **)(iVar4 + 0x48) = PTR_DAT_060c1f60;
  *(undefined **)(iVar4 + 0x4c) = PTR_DAT_060c1f64;
  *(undefined **)(iVar4 + 0x50) = PTR_DAT_060c1f68;
  *(undefined **)(iVar4 + 0x54) = PTR_DAT_060c1f6c;
  *(undefined **)(iVar4 + 0x58) = PTR_DAT_060c1f70;
  *(undefined **)(iVar4 + 0x5c) = PTR_DAT_060c1f74;
  *(undefined **)(iVar4 + 0x60) = PTR_DAT_060c1f78;
  *(undefined **)(iVar4 + 100) = PTR_DAT_060c1f7c;
  *(undefined **)(iVar4 + 0x68) = PTR_DAT_060c1f80;
  *(undefined **)(iVar4 + 0x6c) = PTR_DAT_060c1f84;
  *(undefined **)(iVar4 + 0x70) = PTR_DAT_060c1f88;
  *(undefined **)(iVar4 + 0x74) = PTR_DAT_060c1f8c;
  *(undefined **)(iVar4 + 0x78) = PTR_DAT_060c1f90;
  *(undefined **)(iVar4 + 0x7c) = PTR_DAT_060c1f94;
  *(undefined **)(iVar4 + 0x80) = PTR_DAT_060c1f98;
  *(undefined **)(DAT_060c1ece + iVar4) = PTR_DAT_060c1f9c;
  *(undefined **)(DAT_060c1ed0 + iVar4) = PTR_DAT_060c1fa0;
  *(undefined **)(DAT_060c1ed2 + iVar4) = PTR_DAT_060c1fa4;
  *(undefined **)(iVar4 + 0x90) = PTR_DAT_060c1fa8;
  *(undefined **)(DAT_060c1ed4 + iVar4) = PTR_DAT_060c1fac;
  *(undefined **)(DAT_060c1ed6 + iVar4) = PTR_DAT_060c1fb0;
  *(undefined **)(DAT_060c1ed8 + iVar4) = PTR_DAT_060c1fb4;
  *(undefined **)(iVar4 + 0xa0) = PTR_DAT_060c1fb8;
  *(undefined **)(DAT_060c1eda + iVar4) = PTR_DAT_060c1fbc;
  *(undefined **)(DAT_060c1edc + iVar4) = PTR_DAT_060c1fc0;
  *(undefined **)(DAT_060c1ede + iVar4) = PTR_DAT_060c1fc4;
  *(undefined **)(iVar4 + 0xb0) = PTR_DAT_060c1fc8;
  *(undefined **)(DAT_060c1ee0 + iVar4) = PTR_DAT_060c1fcc;
  *(undefined **)(DAT_060c1ee2 + iVar4) = PTR_DAT_060c1fd0;
  *(undefined **)(DAT_060c1ee4 + iVar4) = PTR_DAT_060c1fd4;
  *(undefined **)(iVar4 + 0xc0) = PTR_DAT_060c1fd8;
  *(undefined **)(DAT_060c1ee6 + iVar4) = PTR_DAT_060c1fdc;
  *(undefined **)(DAT_060c1ee8 + iVar4) = PTR_DAT_060c1fe0;
  *(undefined **)(DAT_060c1eea + iVar4) = PTR_DAT_060c1fe4;
  *(undefined **)(iVar4 + 0xd0) = PTR_DAT_060c1fe8;
  *(undefined **)(DAT_060c1eec + iVar4) = PTR_DAT_060c1fec;
  *(undefined **)(DAT_060c1eee + iVar4) = PTR_DAT_060c1ff0;
  *(undefined **)(DAT_060c1ef0 + iVar4) = PTR_DAT_060c1ff4;
  *(undefined **)(iVar4 + 0xe0) = PTR_DAT_060c1ff8;
  *(undefined **)(DAT_060c1ef2 + iVar4) = PTR_DAT_060c1ffc;
  *(undefined **)(DAT_060c1ef4 + iVar4) = PTR_DAT_060c2000;
  *(undefined **)(DAT_060c1ef6 + iVar4) = PTR_DAT_060c2004;
  *(undefined **)(iVar4 + 0xf0) = PTR_DAT_060c2008;
  *(undefined **)(DAT_060c1ef8 + iVar4) = PTR_DAT_060c200c;
  *(undefined **)(DAT_060c1efa + iVar4) = PTR_DAT_060c2010;
  *(undefined **)(DAT_060c1efc + iVar4) = PTR_DAT_060c2014;
  *(undefined **)(iVar4 + 0x100) = PTR_DAT_060c2018;
  *(undefined **)(DAT_060c1efe + iVar4) = PTR_DAT_060c201c;
  *(undefined **)(DAT_060c1f00 + iVar4) = PTR_DAT_060c2020;
  *(undefined **)(DAT_060c1f02 + iVar4) = PTR_DAT_060c2024;
  *(undefined **)(iVar4 + 0x110) = PTR_DAT_060c2028;
  *(undefined **)(DAT_060c1f04 + iVar4) = PTR_DAT_060c202c;
  *(undefined **)(DAT_060c1f06 + iVar4) = PTR_DAT_060c2030;
  *(undefined **)(DAT_060c1f08 + iVar4) = PTR_DAT_060c2034;
  *(undefined **)(iVar4 + 0x120) = PTR_DAT_060c2038;
  *(undefined **)(DAT_060c1f0a + iVar4) = PTR_DAT_060c203c;
  *(undefined **)(DAT_060c1f0c + iVar4) = PTR_DAT_060c2040;
  *(undefined **)(DAT_060c1f0e + iVar4) = PTR_DAT_060c2044;
  *(undefined **)(iVar4 + 0x130) = PTR_DAT_060c2048;
  *(undefined **)(DAT_060c1f10 + iVar4) = PTR_DAT_060c204c;
  *(undefined **)(DAT_060c1f12 + iVar4) = PTR_DAT_060c2050;
  *DAT_060c2054 = 0x4f;
  return;
}



int FUN_060c2058(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 < 0x10) {
    iVar1 = 0x10;
  }
  else {
    iVar2 = (int)DAT_060c20a6;
    iVar1 = 0x20;
    if (iVar2 < param_1) {
      param_1 = param_1 + iVar2;
      if (param_1 < 0) {
        param_1 = param_1 + iVar2;
      }
      (*DAT_060c20ac)();
      iVar1 = DAT_060c20b0;
      if (param_1 * DAT_060c20a8 <= DAT_060c20b0) {
        iVar1 = param_1 * DAT_060c20a8;
      }
    }
    else if (0x20 < param_1) {
      do {
        iVar1 = iVar1 * 2;
      } while (iVar1 < param_1);
    }
  }
  return iVar1;
}



undefined8 FUN_060c20b4(int param_1)

{
  int iVar1;
  
  if (DAT_060c20de < param_1) {
    if (DAT_060c20e4 < param_1) {
      param_1 = 0xffff;
      iVar1 = DAT_060c20e8;
    }
    else {
      param_1 = DAT_060c20e0 + param_1;
      iVar1 = DAT_060c20e4;
    }
  }
  else {
    param_1 = param_1 * 2;
    iVar1 = (int)DAT_060c20de;
  }
  return CONCAT44(iVar1,param_1);
}



void FUN_060c20ec(void)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)(*(code *)PTR_FUN_060c210c)(0x44);
  *puVar1 = 0;
  puVar1[1] = 0x10;
  return;
}



ushort * FUN_060c21a4(ushort *param_1,undefined4 param_2)

{
  ushort uVar1;
  
  if (param_1 == (ushort *)0x0) {
    param_1 = (ushort *)(*(code *)PTR_FUN_060c2208)();
  }
  if (*param_1 == param_1[1]) {
    uVar1 = (*(code *)PTR_FUN_060c220c)();
    param_1[1] = uVar1;
    param_1 = (ushort *)(*(code *)PTR_FUN_060c2210)(param_1,(uint)uVar1 * 4 + 4);
  }
  uVar1 = *param_1;
  *param_1 = uVar1 + 1;
  *(undefined4 *)(param_1 + (uint)uVar1 * 2 + 2) = param_2;
  return param_1;
}



void FUN_060c22d4(void)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)(*(code *)PTR_FUN_060c22f4)(0x24);
  *puVar1 = 0;
  puVar1[1] = 0x10;
  return;
}



void FUN_060c22f8(void)

{
  int iVar1;
  undefined2 *puVar2;
  
  iVar1 = (*(code *)PTR_FUN_060c2324)();
  puVar2 = (undefined2 *)(*(code *)PTR_FUN_060c2328)(iVar1 * 2 + 4);
  *puVar2 = 0;
  puVar2[1] = (short)iVar1;
  return;
}



ushort * FUN_060c238c(ushort *param_1,ushort param_2)

{
  ushort uVar1;
  
  if (param_1 == (ushort *)0x0) {
    param_1 = (ushort *)(*(code *)PTR_FUN_060c23f4)();
  }
  if (*param_1 == param_1[1]) {
    uVar1 = (*(code *)PTR_FUN_060c23f8)();
    param_1[1] = uVar1;
    param_1 = (ushort *)(*(code *)PTR_FUN_060c23fc)(param_1,(uint)uVar1 * 2 + 4);
  }
  uVar1 = *param_1;
  *param_1 = uVar1 + 1;
  param_1[uVar1 + 2] = param_2;
  return param_1;
}



void FUN_060c25a8(void)

{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  
  iVar3 = *DAT_060c263c;
  *DAT_060c263c = iVar3 + 1;
  puVar2 = PTR_FUN_060c2640;
  iVar4 = (iVar3 + 1) * (int)DAT_060c263a + DAT_060c2644;
  *(undefined *)(iVar4 + 0x40) = *DAT_060c2648;
  uVar6 = *DAT_060c264c;
  *(undefined *)(iVar4 + 0x43) = 0;
  *(undefined *)(iVar4 + 0x42) = 0;
  iVar3 = (*(code *)puVar2)();
  pcVar5 = (char *)(iVar4 + 0x41);
  cVar1 = *pcVar5;
  while (((cVar1 != '\0' && (iVar3 < 0)) && (iVar3 = (*(code *)PTR_FUN_060c2650)(), iVar3 < 0))) {
    *(undefined *)(iVar4 + 0x43) = 0;
    *(undefined *)(iVar4 + 0x42) = 0;
    *DAT_060c264c = uVar6;
    *pcVar5 = '\x02';
    iVar3 = (*(code *)PTR_FUN_060c2640)();
    cVar1 = *pcVar5;
  }
  *DAT_060c263c = *DAT_060c263c + -1;
  return;
}



int FUN_060c2654(void)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  byte *pbVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  if (*DAT_060c2678 != 0) {
    iVar10 = *DAT_060c2678 + -1;
    if (-1 < iVar10) {
      iVar12 = iVar10 * DAT_060c27c4;
      iVar3 = (int)DAT_060c27c6;
      iVar11 = (int)DAT_060c27c8;
      do {
        iVar8 = iVar12 + DAT_060c27d0;
        iVar7 = *(char *)(iVar8 + 0x43) + -1;
        if (-1 < iVar7) {
          iVar6 = iVar7 * 8 + iVar8;
          do {
            *DAT_060c27d4 = (uint)*(byte *)(iVar8 + 0x40) + *(int *)(iVar3 + iVar6);
            iVar1 = (*(code *)PTR_FUN_060c27d8)(*(undefined4 *)(iVar11 + iVar6));
            if (-1 < iVar1) {
              return iVar1;
            }
            iVar7 = iVar7 + -1;
            iVar6 = iVar6 + -8;
          } while (-1 < iVar7);
        }
        iVar10 = iVar10 + -1;
        iVar12 = iVar12 + DAT_060c27ca;
      } while (-1 < iVar10);
    }
    *DAT_060c27d4 = 1;
    iVar10 = 0;
    iVar3 = 0;
    if (0 < *DAT_060c27dc) {
      do {
        puVar9 = (undefined4 *)(iVar3 + DAT_060c27d0);
        iVar12 = 0;
        if ('\0' < *(char *)((int)puVar9 + 0x42)) {
          puVar5 = puVar9;
          do {
            iVar11 = 0;
            puVar2 = puVar9;
            if (0 < (int)puVar5[0x12]) {
              do {
                *(undefined4 *)(((uint)*(byte *)(puVar9 + 0x10) + iVar11) * 4 + DAT_060c27e0) =
                     *puVar2;
                iVar11 = iVar11 + 1;
                puVar2 = puVar2 + 1;
              } while (iVar11 < (int)puVar5[0x12]);
            }
            *DAT_060c27d4 = (uint)*(byte *)(puVar9 + 0x10) + puVar5[0x12];
            iVar11 = (*(code *)PTR_FUN_060c27d8)(puVar5[0x11]);
            iVar12 = iVar12 + 1;
            if (-1 < iVar11) {
              return iVar11;
            }
            puVar5 = puVar5 + 2;
          } while (iVar12 < *(char *)((int)puVar9 + 0x42));
        }
        iVar11 = 0;
        iVar12 = (int)DAT_060c27cc;
        pbVar4 = (byte *)(puVar9 + 0x10);
        puVar5 = puVar9;
        if (0 < (int)((uint)*(byte *)((int)puVar9 + iVar12) - (uint)*pbVar4)) {
          do {
            *(undefined4 *)(((uint)*pbVar4 + iVar11) * 4 + DAT_060c27e0) = *puVar5;
            iVar11 = iVar11 + 1;
            puVar5 = puVar5 + 1;
          } while (iVar11 < (int)((uint)*(byte *)((int)puVar9 + iVar12) - (uint)*pbVar4));
        }
        iVar12 = (int)DAT_060c27c4;
        *DAT_060c27d4 = (uint)*(byte *)((int)puVar9 + iVar12 + 0x40);
        iVar10 = iVar10 + 1;
        iVar3 = iVar3 + iVar12;
      } while (iVar10 < *DAT_060c27dc);
    }
  }
  return -1;
}



undefined4 FUN_060c27f4(uint param_1)

{
  uint *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  puVar2 = PTR_FUN_060c284c;
  puVar1 = DAT_060c2844;
  uVar4 = *DAT_060c2848;
  uVar5 = *DAT_060c2844;
  (*(code *)PTR_FUN_060c2850)();
  (*(code *)puVar2)();
  *puVar1 = param_1 & (int)DAT_060c2840;
  uVar3 = (*(code *)PTR_FUN_060c2854)();
  (*(code *)puVar2)(uVar4);
  *puVar1 = uVar5;
  return uVar3;
}



int FUN_060c2858(void)

{
  byte bVar1;
  uint *puVar2;
  int *piVar3;
  code *pcVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  uint uVar8;
  
  uVar6 = *DAT_060c29d8;
  uVar8 = uVar6 + 1;
  *DAT_060c29d8 = uVar8;
  piVar3 = DAT_060c29e4;
  bVar1 = *(byte *)(uVar6 + *DAT_060c29dc);
  if (bVar1 == 10) goto LAB_060c2a24;
  if (bVar1 == 9) goto LAB_060c2a28;
  if ((bVar1 & 0x20) != 0) {
    iVar5 = *DAT_060c29e0 * (int)DAT_060c29d2 + DAT_060c29e8;
    pcVar7 = (char *)(iVar5 + 0x42);
    *(uint *)(iVar5 + *pcVar7 * 8 + 0x44) = ((uint)(*DAT_060c29ec << 8) >> 1) << 8 | uVar8;
    *(uint *)(iVar5 + *pcVar7 * 8 + 0x48) = *piVar3 - (uint)*(byte *)(iVar5 + 0x40);
    *pcVar7 = *pcVar7 + '\x01';
    iVar5 = (*(code *)PTR_FUN_060c29f0)(*(char *)(iVar5 + 0x41) != '\x02');
    if (-1 < iVar5) {
      return iVar5;
    }
  }
  puVar2 = DAT_060c29d8;
  if ((bVar1 & 0x10) != 0) {
    iVar5 = *DAT_060c29e0 * (int)DAT_060c29d2 + DAT_060c29e8;
    uVar6 = *DAT_060c29d8;
    (*(code *)PTR_FUN_060c29f4)(bVar1);
    pcVar7 = (char *)(iVar5 + 0x43);
    *(uint *)((int)DAT_060c29d4 + iVar5 + *pcVar7 * 8) =
         ((uint)(*DAT_060c29ec << 8) >> 1) << 8 | *puVar2;
    *(uint *)((int)DAT_060c29d6 + iVar5 + *pcVar7 * 8) =
         *DAT_060c29e4 - (uint)*(byte *)(iVar5 + 0x40);
    *pcVar7 = *pcVar7 + '\x01';
    *puVar2 = uVar6;
  }
  switch(bVar1 & 0xf) {
  case 0:
  case 1:
  case 2:
  case 3:
    iVar5 = (*(code *)PTR_FUN_060c29f8)(bVar1 & 3);
    goto LAB_060c2a12;
  default:
    iVar5 = -1;
    goto LAB_060c2a12;
  case 8:
    pcVar4 = (code *)PTR_FUN_060c29fc;
    break;
  case 0xc:
    pcVar4 = (code *)PTR_FUN_060c2a00;
    break;
  case 0xd:
    pcVar4 = (code *)PTR_FUN_060c2a04;
    break;
  case 0xe:
    pcVar4 = (code *)PTR_FUN_060c2a08;
    break;
  case 0xf:
    pcVar4 = (code *)PTR_FUN_060c2a0c;
  }
  iVar5 = (*pcVar4)();
LAB_060c2a12:
  if (iVar5 == -2) {
    if ((bVar1 & 0x10) != 0) {
      (*(code *)PTR_FUN_060c2a5c)();
    }
  }
  else if (iVar5 == -1) {
    if ((bVar1 & 0x10) == 0) {
LAB_060c2a24:
      iVar5 = -1;
    }
    else {
LAB_060c2a28:
      iVar5 = (*(code *)PTR_FUN_060c2a58)(0);
    }
  }
  return iVar5;
}



undefined4 FUN_060c2a60(uint param_1)

{
  uint *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  puVar2 = PTR_FUN_060c2ab8;
  puVar1 = DAT_060c2ab0;
  uVar4 = *DAT_060c2ab4;
  uVar5 = *DAT_060c2ab0;
  (*(code *)PTR_FUN_060c2abc)();
  (*(code *)puVar2)();
  *puVar1 = param_1 & (int)DAT_060c2aac;
  uVar3 = (*(code *)PTR_FUN_060c2ac0)();
  (*(code *)puVar2)(uVar4);
  *puVar1 = uVar5;
  return uVar3;
}



void FUN_060c2ac4(void)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = *DAT_060c2b18;
  *DAT_060c2b18 = iVar2 + 1;
  bVar1 = *(byte *)(iVar2 + *DAT_060c2b1c);
  if (bVar1 != 10) {
    if (bVar1 != 9) {
      if ((bVar1 & 0x20) != 0) {
        (*(code *)PTR_FUN_060c2b20)();
      }
      (*(code *)PTR_FUN_060c2b24)(bVar1);
      if ((bVar1 & 0x10) == 0) {
        return;
      }
    }
    (*(code *)PTR_FUN_060c2b20)();
  }
  return;
}



uint FUN_060c2b28(uint param_1)

{
  uint uVar1;
  
  param_1 = param_1 & 0xf;
  uVar1 = param_1;
  if (param_1 < 0x10) {
    uVar1 = (int)&switchD_060c2b42::switchdataD_060c2b48 +
            (int)(short)(&switchD_060c2b42::switchdataD_060c2b48)[param_1];
    switch(param_1) {
    case 0:
      *DAT_060c2ba0 = *DAT_060c2ba0 + 2;
      break;
    case 1:
      *DAT_060c2ba0 = *DAT_060c2ba0 + 3;
      break;
    case 2:
      *DAT_060c2ba0 = *DAT_060c2ba0 + 4;
      break;
    case 3:
      *DAT_060c2ba0 = *DAT_060c2ba0 + 5;
      break;
    case 8:
    case 0xc:
    case 0xd:
    case 0xe:
    case 0xf:
      uVar1 = (*(code *)PTR_FUN_060c2ba4)();
    }
  }
  return uVar1;
}



undefined4 FUN_060c2ba8(uint param_1)

{
  byte bVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  
  uVar9 = 0;
  uVar5 = (*(code *)PTR_FUN_060c2c2c)(param_1 & 1);
  piVar4 = DAT_060c2c38;
  piVar3 = DAT_060c2c34;
  puVar2 = DAT_060c2c30;
  if ((param_1 & 2) != 0) {
    iVar8 = *DAT_060c2c34;
    uVar9 = *DAT_060c2c30;
    *DAT_060c2c34 = iVar8 + 1;
    iVar7 = *piVar4;
    bVar1 = *(byte *)(iVar8 + iVar7);
    *DAT_060c2c3c = (uint)bVar1;
    *piVar3 = iVar8 + 2;
    uVar6 = (*(code *)PTR_FUN_060c2c40)(CONCAT11(bVar1,*(undefined *)(iVar8 + 1 + iVar7)));
    *puVar2 = uVar6;
  }
  (*(code *)PTR_FUN_060c2c44)(uVar5);
  uVar5 = (*(code *)PTR_FUN_060c2c48)(uVar5);
  (*(code *)PTR_FUN_060c2c4c)();
  if ((param_1 & 2) != 0) {
    *DAT_060c2c30 = uVar9;
  }
  return uVar5;
}



undefined4 FUN_060c2c50(void)

{
  int *piVar1;
  int *piVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  
  piVar2 = DAT_060c2cdc;
  piVar1 = DAT_060c2cd8;
  iVar7 = *DAT_060c2cd8;
  *DAT_060c2cd8 = iVar7 + 1;
  iVar9 = *piVar2;
  uVar8 = (uint)*(byte *)(iVar7 + iVar9);
  *DAT_060c2ce0 = uVar8;
  if ((uint)(int)DAT_060c2cd4 < uVar8) {
    iVar6 = (int)DAT_060c2cd6;
    *piVar1 = iVar7 + 2;
    uVar8 = (uVar8 + iVar6) * 0x100 | (uint)*(byte *)(iVar7 + 1 + iVar9);
  }
  puVar4 = PTR_FUN_060c2ce8;
  puVar3 = PTR_FUN_060c2ce4;
  iVar7 = *DAT_060c2cd8;
  iVar9 = uVar8 + iVar7;
  while ((iVar7 < iVar9 && (iVar7 = (*(code *)puVar3)(), iVar7 == 0))) {
    (*(code *)puVar4)();
    iVar7 = *DAT_060c2cd8;
  }
  piVar1 = DAT_060c2cd8;
  uVar5 = 0xffffffff;
  if (*DAT_060c2cd8 != iVar9) {
    uVar5 = (*(code *)PTR_FUN_060c2cec)();
    *piVar1 = iVar9;
  }
  return uVar5;
}



undefined4 FUN_060c2cf0(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  piVar2 = DAT_060c2d88;
  piVar1 = DAT_060c2d84;
  iVar6 = *DAT_060c2d84;
  *DAT_060c2d84 = iVar6 + 1;
  iVar8 = *piVar2;
  uVar7 = (uint)*(byte *)(iVar6 + iVar8);
  *DAT_060c2d8c = uVar7;
  if ((uint)(int)DAT_060c2d80 < uVar7) {
    iVar5 = (int)DAT_060c2d82;
    *piVar1 = iVar6 + 2;
    uVar7 = (uVar7 + iVar5) * 0x100 | (uint)*(byte *)(iVar6 + 1 + iVar8);
  }
  puVar3 = PTR_FUN_060c2d94;
  piVar1 = DAT_060c2d84;
  if (uVar7 == 0) {
LAB_060c2d42:
    uVar4 = (*(code *)PTR_FUN_060c2d90)();
  }
  else {
    iVar6 = *DAT_060c2d84;
    iVar8 = uVar7 + iVar6;
    while (iVar6 < iVar8) {
      iVar6 = (*(code *)puVar3)();
      if (iVar6 == param_1) {
        *DAT_060c2d84 = iVar8;
        goto LAB_060c2d42;
      }
      iVar6 = *piVar1;
    }
    (*(code *)PTR_FUN_060c2d98)();
    uVar4 = 0xffffff9d;
  }
  return uVar4;
}



int FUN_060c2d9c(void)

{
  int *piVar1;
  int *piVar2;
  undefined *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  piVar2 = DAT_060c2e28;
  piVar1 = DAT_060c2e24;
  iVar6 = *DAT_060c2e24;
  *DAT_060c2e24 = iVar6 + 1;
  iVar8 = *piVar2;
  uVar7 = (uint)*(byte *)(iVar6 + iVar8);
  *DAT_060c2e2c = uVar7;
  iVar9 = -1;
  if ((uint)(int)DAT_060c2e20 < uVar7) {
    iVar5 = (int)DAT_060c2e22;
    *piVar1 = iVar6 + 2;
    uVar7 = (uVar7 + iVar5) * 0x100 | (uint)*(byte *)(iVar6 + 1 + iVar8);
  }
  piVar1 = DAT_060c2e24;
  iVar6 = *DAT_060c2e24;
  uVar4 = (*(code *)PTR_FUN_060c2e30)();
  puVar3 = PTR_FUN_060c2e34;
  iVar8 = *piVar1;
  while ((iVar8 < (int)(uVar7 + iVar6) && (iVar9 = (*(code *)puVar3)(uVar4), iVar9 == -99))) {
    iVar8 = *piVar1;
  }
  *DAT_060c2e24 = uVar7 + iVar6;
  return iVar9;
}



undefined4 FUN_060c2e38(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  piVar2 = DAT_060c2ee8;
  piVar1 = DAT_060c2ee4;
  iVar6 = *DAT_060c2ee4;
  *DAT_060c2ee4 = iVar6 + 1;
  iVar8 = *piVar2;
  uVar7 = (uint)*(byte *)(iVar6 + iVar8);
  *DAT_060c2eec = uVar7;
  if ((uint)(int)DAT_060c2ede < uVar7) {
    iVar5 = (int)DAT_060c2ee0;
    *piVar1 = iVar6 + 2;
    uVar7 = (uVar7 + iVar5) * 0x100 | (uint)*(byte *)(iVar6 + 1 + iVar8);
  }
  piVar1 = DAT_060c2ee4;
  iVar6 = *DAT_060c2ee4;
  uVar3 = (*(code *)PTR_FUN_060c2ef4)();
  uVar4 = (*(code *)PTR_FUN_060c2ef8)(uVar3);
  (*(code *)PTR_FUN_060c2efc)(uVar3,uVar4 + 1);
  iVar8 = *piVar1;
  while( true ) {
    if ((int)(uVar7 + iVar6) <= iVar8) {
      return 0xffffffff;
    }
    iVar8 = *piVar1;
    *piVar1 = iVar8 + 1;
    if (uVar4 <= *(byte *)(iVar8 + *DAT_060c2ee8)) break;
    (*(code *)PTR_FUN_060c2f00)();
    iVar8 = *piVar1;
  }
  uVar3 = (*(code *)PTR_FUN_060c2ef0)();
  *piVar1 = uVar7 + iVar6;
  return uVar3;
}



undefined4 FUN_060c2f04(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  iVar3 = (*(code *)PTR_FUN_060c2f98)();
  piVar2 = DAT_060c2fa0;
  piVar1 = DAT_060c2f9c;
  iVar6 = *DAT_060c2f9c;
  *DAT_060c2f9c = iVar6 + 1;
  iVar8 = *piVar2;
  uVar7 = (uint)*(byte *)(iVar6 + iVar8);
  *DAT_060c2fa4 = uVar7;
  if ((uint)(int)DAT_060c2f92 < uVar7) {
    iVar5 = (int)DAT_060c2f94;
    *piVar1 = iVar6 + 2;
    uVar7 = (uVar7 + iVar5) * 0x100 | (uint)*(byte *)(iVar6 + 1 + iVar8);
  }
  piVar1 = DAT_060c2f9c;
  iVar6 = *DAT_060c2f9c;
  iVar8 = uVar7 + iVar6;
  while( true ) {
    if (iVar8 <= iVar6) {
      return 0xffffffff;
    }
    iVar6 = *piVar1;
    *piVar1 = iVar6 + 1;
    if (iVar3 <= (int)(uint)*(byte *)(iVar6 + *DAT_060c2fa0)) break;
    (*(code *)PTR_FUN_060c2fac)();
    iVar6 = *piVar1;
  }
  uVar4 = (*(code *)PTR_FUN_060c2fa8)();
  *piVar1 = iVar8;
  return uVar4;
}



int FUN_060c2fb0(void)

{
  byte bVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined *puVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  uint uVar10;
  int iVar11;
  undefined4 *puVar12;
  int *piVar13;
  
  iVar4 = DAT_060c30f0;
  piVar3 = DAT_060c30ec;
  piVar2 = DAT_060c30e8;
  uVar7 = *DAT_060c30e4;
  do {
    piVar13 = DAT_060c30f4;
    *DAT_060c30e4 = uVar7;
    *piVar13 = 0;
    puVar9 = DAT_060c30f8;
    *piVar2 = *piVar3;
    *puVar9 = 0;
    (*(code *)PTR_FUN_060c30fc)();
    puVar5 = PTR_FUN_060c3108;
    if (*DAT_060c30f4 == 0) {
      return -1;
    }
    if (*(char *)(DAT_060c3104 + *DAT_060c3100 * (int)DAT_060c30e0) == '\0') {
      iVar6 = (*(code *)PTR_FUN_060c3108)();
      if (iVar6 < 0) {
        return -2;
      }
    }
    else {
      do {
        iVar6 = (*(code *)puVar5)();
      } while (iVar6 < 0);
    }
    puVar12 = (undefined4 *)(*DAT_060c3100 * (int)DAT_060c30e0 + DAT_060c310c);
    uVar10 = 0;
    iVar11 = *piVar2 - (uint)*(byte *)(puVar12 + 0x10);
    puVar9 = puVar12;
    if (0 < iVar11) {
      do {
        iVar8 = *(byte *)(puVar12 + 0x10) + uVar10;
        uVar10 = uVar10 + 1;
        *puVar9 = *(undefined4 *)(iVar4 + iVar8 * 4);
        puVar9 = puVar9 + 1;
      } while ((int)uVar10 < iVar11);
    }
    if (uVar10 < 0x10) {
      piVar13 = puVar12 + uVar10;
      do {
        bVar1 = *(byte *)(puVar12 + 0x10);
        iVar8 = *(int *)(iVar6 * 0x40 + DAT_060c3110 + (uVar10 - iVar11) * 4);
        *piVar13 = iVar8;
        *(int *)(iVar4 + (bVar1 + uVar10) * 4) = iVar8;
        if (*piVar13 < 0) break;
        uVar10 = uVar10 + 1;
        piVar13 = piVar13 + 1;
      } while (uVar10 < 0x10);
    }
    *piVar3 = *(byte *)(puVar12 + 0x10) + uVar10;
    iVar11 = *piVar2;
    iVar6 = (*(code *)PTR_FUN_060c3118)(*(undefined4 *)(DAT_060c3114 + iVar6 * 4));
    *piVar3 = iVar11;
    if (iVar6 != -2) {
      return iVar6;
    }
  } while( true );
}



void FUN_060c311c(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  iVar4 = DAT_060c319c;
  iVar3 = DAT_060c3198;
  piVar2 = DAT_060c3194;
  piVar1 = DAT_060c3190;
  iVar6 = 0;
  uVar7 = *DAT_060c318c - *DAT_060c3190;
  if (0 < (int)uVar7) {
    do {
      iVar8 = iVar6 * 4;
      iVar5 = *piVar1 + iVar6;
      iVar6 = iVar6 + 1;
      *(undefined4 *)(*piVar2 * 0x40 + iVar3 + iVar8) = *(undefined4 *)(iVar4 + iVar5 * 4);
    } while (iVar6 < (int)uVar7);
  }
  if (uVar7 < 0x10) {
    *(undefined4 *)(*DAT_060c3194 * 0x40 + DAT_060c3198 + uVar7 * 4) = 0xffffffff;
  }
  return;
}



void FUN_060c31a0(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = DAT_060c3208;
  (*(code *)PTR_FUN_060c320c)(param_1 + *DAT_060c3208);
  piVar2 = DAT_060c3214;
  (*(code *)PTR_FUN_060c3210)(*DAT_060c3214 * 0x40 + DAT_060c3218,param_1 + *piVar1);
  *(uint *)(DAT_060c321c + *piVar2 * 4) = ((uint)(*DAT_060c3220 << 8) >> 1) << 8 | *DAT_060c3224;
  (*(code *)PTR_FUN_060c3228)();
  *piVar2 = *piVar2 + 1;
  *DAT_060c322c = 0;
  return;
}



void FUN_060c3230(void)

{
  undefined2 uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined2 *puVar6;
  uint uVar7;
  
  iVar5 = DAT_060c32c0;
  piVar4 = DAT_060c32bc;
  piVar3 = DAT_060c32b8;
  uVar7 = 0;
  puVar6 = DAT_060c32c4;
  do {
    if (*piVar3 <= (int)uVar7) break;
    iVar2 = uVar7 * 2;
    uVar7 = uVar7 + 1;
    uVar1 = *puVar6;
    puVar6 = puVar6 + 1;
    *(undefined2 *)(*piVar4 * 0x40 + iVar5 + iVar2) = uVar1;
  } while (uVar7 < 0x20);
  if (uVar7 < 0x20) {
    *(undefined2 *)(*DAT_060c32bc * 0x40 + DAT_060c32c0 + uVar7 * 2) = 0xffff;
  }
  piVar3 = DAT_060c32bc;
  *(uint *)(DAT_060c32c8 + *DAT_060c32bc * 4) =
       ((uint)(*DAT_060c32cc << 8) >> 1) << 8 | *DAT_060c32d0;
  (*(code *)PTR_FUN_060c32d4)();
  *piVar3 = *piVar3 + 1;
  *DAT_060c32d8 = 1;
  return;
}



void FUN_060c32dc(void)

{
  int *piVar1;
  int *piVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  piVar2 = DAT_060c334c;
  piVar1 = DAT_060c3348;
  iVar5 = *DAT_060c3348;
  *DAT_060c3348 = iVar5 + 1;
  iVar7 = *piVar2;
  uVar6 = (uint)*(byte *)(iVar5 + iVar7);
  *DAT_060c3350 = uVar6;
  if ((uint)(int)DAT_060c3344 < uVar6) {
    iVar4 = (int)DAT_060c3346;
    *piVar1 = iVar5 + 2;
    uVar6 = (uVar6 + iVar4) * 0x100 | (uint)*(byte *)(iVar5 + 1 + iVar7);
  }
  puVar3 = PTR_FUN_060c3354;
  piVar1 = DAT_060c3348;
  iVar5 = *DAT_060c3348;
  iVar7 = uVar6 + iVar5;
  while (iVar5 < iVar7) {
    (*(code *)puVar3)();
    iVar5 = *piVar1;
  }
  return;
}



uint FUN_060c3358(void)

{
  byte bVar1;
  bool bVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  code *pcVar6;
  uint uVar7;
  int iVar8;
  
  bVar1 = *(byte *)(*DAT_060c34c8 + *DAT_060c34c4);
  uVar7 = (uint)bVar1;
  if ((bVar1 & 0x80) == 0) {
    uVar3 = (*(code *)PTR_FUN_060c34cc)();
    (*(code *)PTR_FUN_060c34d0)(uVar3);
    uVar7 = (*(code *)PTR_FUN_060c34d4)();
    return uVar7;
  }
  bVar2 = (uVar7 & 0xc0) == (int)DAT_060c34ba;
  if (bVar2) {
    uVar7 = (uint)bVar2;
    pcVar6 = (code *)PTR_FUN_060c34d8;
  }
  else {
    *DAT_060c34c8 = *DAT_060c34c8 + 1;
    switch((uVar7 & 0xf8) - (int)DAT_060c34bc) {
    case 0:
    case 8:
      uVar7 = uVar7 & 0xf;
      pcVar6 = (code *)PTR_FUN_060c34dc;
      break;
    default:
      if ((uVar7 & 0xfc) == (int)DAT_060c34be) {
        uVar7 = (uVar7 & 3) + 2;
        pcVar6 = (code *)PTR_FUN_060c34d8;
      }
      else {
        uVar4 = uVar7 - (int)DAT_060c34c0;
        if (0xb < uVar4) {
          return uVar4;
        }
        uVar5 = (int)&switchD_060c346e::switchdataD_060c3474 +
                (int)(short)(&switchD_060c346e::switchdataD_060c3474)[uVar4];
        switch(uVar4) {
        default:
          uVar7 = uVar7 & 3;
          pcVar6 = (code *)PTR_FUN_060c34ec;
          break;
        case 4:
          iVar8 = *DAT_060c34c8;
          *DAT_060c34c8 = iVar8 + 1;
          uVar7 = (uint)*(byte *)(iVar8 + *DAT_060c34c4);
          pcVar6 = (code *)PTR_FUN_060c34d8;
          break;
        case 5:
        case 6:
          goto switchD_060c346e_caseD_5;
        case 7:
          uVar7 = 0xfffffffe;
          pcVar6 = (code *)PTR_FUN_060c34dc;
          break;
        case 8:
          uVar7 = 0xffffffff;
          pcVar6 = (code *)PTR_FUN_060c34dc;
          break;
        case 9:
          uVar7 = 0xffffffff;
          pcVar6 = (code *)PTR_FUN_060c350c;
          break;
        case 10:
          uVar7 = 0xffffffff;
          pcVar6 = (code *)PTR_FUN_060c3510;
          break;
        case 0xb:
          uVar7 = 0xffffffff;
          pcVar6 = (code *)PTR_FUN_060c3514;
        }
      }
      break;
    case 0x10:
    case 0x18:
      uVar7 = uVar7 & 0xf;
      pcVar6 = (code *)PTR_FUN_060c34e0;
      break;
    case 0x20:
      uVar7 = uVar7 & 7;
      pcVar6 = (code *)PTR_FUN_060c34e4;
      break;
    case 0x28:
      uVar7 = uVar7 & 7;
      pcVar6 = (code *)PTR_FUN_060c34e8;
    }
  }
  uVar5 = (*pcVar6)(uVar7);
switchD_060c346e_caseD_5:
  return uVar5;
}



void FUN_060c3518(int param_1)

{
  byte bVar1;
  uint *puVar2;
  int *piVar3;
  int *piVar4;
  undefined *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  piVar3 = DAT_060c3594;
  puVar2 = DAT_060c3590;
  iVar8 = 0;
  if (0 < param_1) {
    do {
      piVar4 = DAT_060c3598;
      iVar6 = *piVar3;
      *piVar3 = iVar6 + 1;
      iVar7 = *piVar4;
      bVar1 = *(byte *)(iVar6 + iVar7);
      *puVar2 = (uint)bVar1;
      *piVar3 = iVar6 + 2;
      iVar8 = iVar8 + 1;
      (*(code *)PTR_FUN_060c359c)(CONCAT11(bVar1,*(undefined *)(iVar6 + 1 + iVar7)) & DAT_060c358c);
    } while (iVar8 < param_1);
  }
  iVar8 = 0;
  (*(code *)PTR_FUN_060c35a0)();
  puVar5 = PTR_FUN_060c35a4;
  if (0 < param_1) {
    do {
      iVar8 = iVar8 + 1;
      (*(code *)puVar5)();
    } while (iVar8 < param_1);
  }
  (*(code *)PTR_FUN_060c35a8)();
  return;
}



void FUN_060c35ac(uint param_1)

{
  byte bVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  
  uVar9 = 0;
  uVar5 = (*(code *)PTR_FUN_060c362c)(param_1 & 1);
  piVar4 = DAT_060c3638;
  piVar3 = DAT_060c3634;
  puVar2 = DAT_060c3630;
  if ((param_1 & 2) != 0) {
    iVar8 = *DAT_060c3634;
    uVar9 = *DAT_060c3630;
    *DAT_060c3634 = iVar8 + 1;
    iVar7 = *piVar4;
    bVar1 = *(byte *)(iVar8 + iVar7);
    *DAT_060c363c = (uint)bVar1;
    *piVar3 = iVar8 + 2;
    uVar6 = (*(code *)PTR_FUN_060c3640)(CONCAT11(bVar1,*(undefined *)(iVar8 + 1 + iVar7)));
    *puVar2 = uVar6;
  }
  (*(code *)PTR_FUN_060c3644)(uVar5);
  (*(code *)PTR_FUN_060c3648)(uVar5);
  (*(code *)PTR_FUN_060c364c)();
  if ((param_1 & 2) != 0) {
    *DAT_060c3630 = uVar9;
  }
  return;
}



void FUN_060c3650(int param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  code *pcVar7;
  int iVar8;
  int iVar9;
  
  piVar4 = DAT_060c3750;
  piVar3 = DAT_060c374c;
  puVar2 = PTR_FUN_060c3740;
  puVar1 = PTR_FUN_060c373c;
  if (param_1 < 0) {
    if (param_1 == -1) {
      iVar9 = *DAT_060c374c;
      *DAT_060c374c = iVar9 + 1;
      iVar5 = *piVar4;
      uVar6 = (uint)*(byte *)(iVar9 + iVar5);
      *DAT_060c3754 = uVar6;
      if ((uint)(int)DAT_060c3738 < uVar6) {
        iVar8 = (int)DAT_060c373a;
        *piVar3 = iVar9 + 2;
        uVar6 = (iVar8 + uVar6) * 0x100 | (uint)*(byte *)(iVar9 + 1 + iVar5);
      }
      puVar2 = PTR_FUN_060c3740;
      puVar1 = PTR_FUN_060c373c;
      iVar9 = *DAT_060c374c;
      iVar5 = uVar6 + iVar9;
      while( true ) {
        if (iVar5 <= iVar9) {
          return;
        }
        iVar9 = (*(code *)puVar1)();
        if (iVar9 != 0) break;
        (*(code *)puVar2)();
        iVar9 = *DAT_060c374c;
      }
      (*(code *)PTR_FUN_060c3744)();
      *DAT_060c374c = iVar5;
      return;
    }
    iVar9 = (*(code *)PTR_FUN_060c373c)();
    pcVar7 = (code *)PTR_FUN_060c3744;
    if (iVar9 != 0) goto LAB_060c3724;
  }
  else {
    param_1 = param_1 + 1;
    iVar9 = 0;
    if (0 < param_1) {
      do {
        iVar5 = (*(code *)puVar1)();
        if (iVar5 != 0) break;
        iVar9 = iVar9 + 1;
        (*(code *)puVar2)();
      } while (iVar9 < param_1);
    }
    (*(code *)PTR_FUN_060c3744)();
    puVar2 = PTR_FUN_060c3748;
    puVar1 = PTR_FUN_060c3740;
    if (param_1 <= iVar9) {
      return;
    }
    while (iVar9 = iVar9 + 1, iVar9 < param_1) {
      (*(code *)puVar2)();
      (*(code *)puVar1)();
    }
  }
  pcVar7 = (code *)PTR_FUN_060c3740;
LAB_060c3724:
  (*pcVar7)();
  return;
}



undefined4 FUN_060c3758(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  piVar2 = DAT_060c37f0;
  piVar1 = DAT_060c37ec;
  iVar6 = *DAT_060c37ec;
  *DAT_060c37ec = iVar6 + 1;
  iVar8 = *piVar2;
  uVar7 = (uint)*(byte *)(iVar6 + iVar8);
  *DAT_060c37f4 = uVar7;
  if ((uint)(int)DAT_060c37e8 < uVar7) {
    iVar5 = (int)DAT_060c37ea;
    *piVar1 = iVar6 + 2;
    uVar7 = (uVar7 + iVar5) * 0x100 | (uint)*(byte *)(iVar6 + 1 + iVar8);
  }
  puVar3 = PTR_FUN_060c37fc;
  piVar1 = DAT_060c37ec;
  if (uVar7 == 0) {
LAB_060c37aa:
    (*(code *)PTR_FUN_060c37f8)();
    uVar4 = 0xffffffff;
  }
  else {
    iVar6 = *DAT_060c37ec;
    iVar8 = uVar7 + iVar6;
    while (iVar6 < iVar8) {
      iVar6 = (*(code *)puVar3)();
      if (iVar6 == param_1) {
        *DAT_060c37ec = iVar8;
        goto LAB_060c37aa;
      }
      iVar6 = *piVar1;
    }
    (*(code *)PTR_FUN_060c3800)();
    uVar4 = 0xffffff9d;
  }
  return uVar4;
}



void FUN_060c3804(int param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  piVar4 = DAT_060c38d0;
  piVar3 = DAT_060c38cc;
  if (param_1 < 0) {
    iVar9 = *DAT_060c38cc;
    *DAT_060c38cc = iVar9 + 1;
    iVar6 = *piVar4;
    uVar7 = (uint)*(byte *)(iVar9 + iVar6);
    *DAT_060c38d4 = uVar7;
    if ((uint)(int)DAT_060c38ba < uVar7) {
      iVar8 = (int)DAT_060c38bc;
      *piVar3 = iVar9 + 2;
      uVar7 = (iVar8 + uVar7) * 0x100 | (uint)*(byte *)(iVar9 + 1 + iVar6);
    }
    piVar3 = DAT_060c38cc;
    iVar9 = *DAT_060c38cc;
    uVar5 = (*(code *)PTR_FUN_060c38c0)();
    puVar1 = PTR_FUN_060c38c4;
    iVar6 = *piVar3;
    while ((iVar6 < (int)(uVar7 + iVar9) && (iVar6 = (*(code *)puVar1)(uVar5), iVar6 != -1))) {
      iVar6 = *piVar3;
    }
    *DAT_060c38cc = uVar7 + iVar9;
  }
  else {
    param_1 = param_1 + 1;
    uVar5 = (*(code *)PTR_FUN_060c38c0)();
    puVar2 = PTR_FUN_060c38c4;
    iVar9 = 0;
    puVar1 = PTR_FUN_060c38c8;
    if (0 < param_1) {
      do {
        iVar6 = (*(code *)puVar2)(uVar5);
        puVar1 = PTR_FUN_060c38c8;
        if (iVar6 == -1) break;
        iVar9 = iVar9 + 1;
      } while (iVar9 < param_1);
    }
    while (puVar2 = PTR_FUN_060c38c8, iVar9 = iVar9 + 1, PTR_FUN_060c38c8 = puVar1, iVar9 < param_1)
    {
      (*(code *)puVar2)();
      (*(code *)puVar2)();
      puVar1 = PTR_FUN_060c38c8;
      PTR_FUN_060c38c8 = puVar2;
    }
  }
  return;
}



void FUN_060c38d8(int param_1)

{
  undefined *puVar1;
  int *piVar2;
  undefined *puVar3;
  int *piVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  piVar4 = DAT_060c39fc;
  piVar2 = DAT_060c39f8;
  if (param_1 < 0) {
    iVar10 = *DAT_060c39f8;
    *DAT_060c39f8 = iVar10 + 1;
    iVar8 = *piVar4;
    uVar6 = (uint)*(byte *)(iVar10 + iVar8);
    *DAT_060c3a08 = uVar6;
    if ((uint)(int)DAT_060c39e8 < uVar6) {
      iVar9 = (int)DAT_060c39ea;
      *piVar2 = iVar10 + 2;
      uVar6 = (iVar9 + uVar6) * 0x100 | (uint)*(byte *)(iVar10 + 1 + iVar8);
    }
    piVar2 = DAT_060c39f8;
    iVar10 = *DAT_060c39f8;
    uVar5 = (*(code *)PTR_FUN_060c39ec)();
    uVar7 = (*(code *)PTR_FUN_060c39f0)(uVar5);
    (*(code *)PTR_FUN_060c39f4)(uVar5,uVar7 + 1);
    iVar8 = *piVar2;
    while (piVar4 = DAT_060c39f8, iVar8 < (int)(uVar6 + iVar10)) {
      iVar8 = *piVar2;
      *piVar2 = iVar8 + 1;
      if (uVar7 <= *(byte *)(iVar8 + *DAT_060c39fc)) {
        (*(code *)PTR_FUN_060c3a04)();
        *piVar2 = uVar6 + iVar10;
        return;
      }
      (*(code *)PTR_FUN_060c3a00)();
      iVar8 = *piVar2;
    }
  }
  else {
    param_1 = param_1 + 2;
    uVar5 = (*(code *)PTR_FUN_060c39ec)();
    uVar6 = (*(code *)PTR_FUN_060c39f0)(uVar5);
    (*(code *)PTR_FUN_060c39f4)(uVar5,uVar6 + 1);
    piVar2 = DAT_060c39f8;
    iVar10 = 0;
    piVar4 = DAT_060c39f8;
    puVar1 = PTR_FUN_060c3a00;
    if (0 < param_1) {
      do {
        iVar8 = *piVar2;
        *piVar2 = iVar8 + 1;
        if (uVar6 <= *(byte *)(iVar8 + *DAT_060c39fc)) {
          (*(code *)PTR_FUN_060c3a04)();
          piVar4 = DAT_060c39f8;
          puVar1 = PTR_FUN_060c3a00;
          break;
        }
        iVar10 = iVar10 + 1;
        (*(code *)PTR_FUN_060c3a00)();
        piVar4 = DAT_060c39f8;
        puVar1 = PTR_FUN_060c3a00;
      } while (iVar10 < param_1);
    }
    while (puVar3 = PTR_FUN_060c3a00, piVar2 = DAT_060c39f8, iVar10 = iVar10 + 1,
          PTR_FUN_060c3a00 = puVar1, iVar10 < param_1) {
      *DAT_060c39f8 = *DAT_060c39f8 + 1;
      DAT_060c39f8 = piVar4;
      (*(code *)puVar3)();
      piVar4 = DAT_060c39f8;
      puVar1 = PTR_FUN_060c3a00;
      PTR_FUN_060c3a00 = puVar3;
      DAT_060c39f8 = piVar2;
    }
  }
  DAT_060c39f8 = piVar4;
  return;
}



void FUN_060c3a0c(int param_1)

{
  undefined *puVar1;
  int *piVar2;
  undefined *puVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar5 = (*(code *)PTR_FUN_060c3af4)();
  piVar4 = DAT_060c3afc;
  piVar2 = DAT_060c3af8;
  if (param_1 < 0) {
    iVar9 = *DAT_060c3af8;
    *DAT_060c3af8 = iVar9 + 1;
    iVar7 = *piVar4;
    uVar6 = (uint)*(byte *)(iVar9 + iVar7);
    *DAT_060c3b08 = uVar6;
    if ((uint)(int)DAT_060c3af0 < uVar6) {
      iVar8 = (int)DAT_060c3af2;
      *piVar2 = iVar9 + 2;
      uVar6 = (iVar8 + uVar6) * 0x100 | (uint)*(byte *)(iVar9 + 1 + iVar7);
    }
    piVar2 = DAT_060c3af8;
    iVar9 = *DAT_060c3af8;
    iVar7 = uVar6 + iVar9;
    while (piVar4 = DAT_060c3af8, iVar9 < iVar7) {
      iVar9 = *piVar2;
      *piVar2 = iVar9 + 1;
      if (iVar5 <= (int)(uint)*(byte *)(iVar9 + *DAT_060c3afc)) {
        (*(code *)PTR_FUN_060c3b04)();
        *piVar2 = iVar7;
        return;
      }
      (*(code *)PTR_FUN_060c3b00)();
      iVar9 = *piVar2;
    }
  }
  else {
    param_1 = param_1 + 2;
    iVar9 = 0;
    piVar4 = DAT_060c3af8;
    puVar1 = PTR_FUN_060c3b00;
    if (0 < param_1) {
      do {
        iVar7 = *piVar2;
        *piVar2 = iVar7 + 1;
        if (iVar5 <= (int)(uint)*(byte *)(iVar7 + *DAT_060c3afc)) {
          (*(code *)PTR_FUN_060c3b04)();
          piVar4 = DAT_060c3af8;
          puVar1 = PTR_FUN_060c3b00;
          break;
        }
        iVar9 = iVar9 + 1;
        (*(code *)PTR_FUN_060c3b00)();
        piVar4 = DAT_060c3af8;
        puVar1 = PTR_FUN_060c3b00;
      } while (iVar9 < param_1);
    }
    while (puVar3 = PTR_FUN_060c3b00, piVar2 = DAT_060c3af8, iVar9 = iVar9 + 1,
          PTR_FUN_060c3b00 = puVar1, iVar9 < param_1) {
      *DAT_060c3af8 = *DAT_060c3af8 + 1;
      DAT_060c3af8 = piVar4;
      (*(code *)puVar3)();
      piVar4 = DAT_060c3af8;
      puVar1 = PTR_FUN_060c3b00;
      PTR_FUN_060c3b00 = puVar3;
      DAT_060c3af8 = piVar2;
    }
  }
  DAT_060c3af8 = piVar4;
  return;
}



void FUN_060c3b0c(uint param_1)

{
  char cVar1;
  int *piVar2;
  code *pcVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  piVar2 = DAT_060c3b94;
  uVar5 = *DAT_060c3b98;
  iVar6 = *DAT_060c3b94;
  (*(code *)PTR_FUN_060c3b9c)();
  (*(code *)PTR_FUN_060c3ba0)();
  param_1 = param_1 & (int)DAT_060c3b8e;
  *piVar2 = param_1 + 1;
  iVar4 = *DAT_060c3ba4;
  cVar1 = *(char *)(param_1 + iVar4);
  pcVar3 = (code *)PTR_FUN_060c3ba8;
  if (cVar1 != '\0') {
    *piVar2 = param_1 + 2;
    (*(code *)PTR_FUN_060c3bac)(CONCAT11(cVar1,*(undefined *)(param_1 + 1 + iVar4)) & DAT_060c3b90);
    (*(code *)PTR_FUN_060c3ba8)();
    pcVar3 = (code *)PTR_FUN_060c3bb0;
  }
  (*pcVar3)();
  (*(code *)PTR_FUN_060c3ba0)(uVar5);
  *DAT_060c3b94 = iVar6;
  return;
}



void FUN_060c3bb4(undefined2 param_1)

{
  int iVar1;
  
  iVar1 = *DAT_060c3bd0;
  *DAT_060c3bd0 = iVar1 + 1;
  *(undefined2 *)(DAT_060c3bd4 + iVar1 * 2) = param_1;
  return;
}



void FUN_060c3bd8(void)

{
  *DAT_060c3be8 = *DAT_060c3be8 + -1;
  return;
}



int FUN_060c3bec(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  piVar2 = DAT_060c3c70;
  piVar1 = DAT_060c3c6c;
  iVar5 = *DAT_060c3c6c;
  *DAT_060c3c6c = iVar5 + 1;
  iVar7 = *piVar2;
  uVar6 = (uint)*(byte *)(iVar5 + iVar7);
  *DAT_060c3c74 = uVar6;
  if ((uint)(int)DAT_060c3c66 < uVar6) {
    iVar4 = (int)DAT_060c3c68;
    *piVar1 = iVar5 + 2;
    uVar6 = (uVar6 + iVar4) * 0x100 | (uint)*(byte *)(iVar5 + 1 + iVar7);
  }
  puVar3 = PTR_FUN_060c3c78;
  piVar1 = DAT_060c3c6c;
  iVar5 = *DAT_060c3c6c;
  iVar7 = uVar6 + iVar5;
  while( true ) {
    if (iVar7 <= iVar5) {
      return -1;
    }
    iVar5 = (*(code *)puVar3)(param_1);
    if (-1 < iVar5) break;
    iVar5 = *piVar1;
  }
  return iVar5;
}



undefined4 FUN_060c3c7c(uint param_1,undefined4 param_2)

{
  uint *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  puVar2 = PTR_FUN_060c3cd8;
  puVar1 = DAT_060c3cd0;
  uVar4 = *DAT_060c3cd4;
  uVar5 = *DAT_060c3cd0;
  (*(code *)PTR_FUN_060c3cdc)();
  (*(code *)puVar2)();
  *puVar1 = param_1 & (int)DAT_060c3cce;
  uVar3 = (*(code *)PTR_FUN_060c3ce0)(param_2);
  (*(code *)puVar2)(uVar4);
  *puVar1 = uVar5;
  return uVar3;
}



int FUN_060c3ce4(void)

{
  int *piVar1;
  int *piVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  piVar2 = DAT_060c3d60;
  piVar1 = DAT_060c3d5c;
  iVar5 = *DAT_060c3d5c;
  *DAT_060c3d5c = iVar5 + 1;
  iVar7 = *piVar2;
  uVar6 = (uint)*(byte *)(iVar5 + iVar7);
  *DAT_060c3d64 = uVar6;
  if ((uint)(int)DAT_060c3d58 < uVar6) {
    iVar4 = (int)DAT_060c3d5a;
    *piVar1 = iVar5 + 2;
    uVar6 = (uVar6 + iVar4) * 0x100 | (uint)*(byte *)(iVar5 + 1 + iVar7);
  }
  puVar3 = PTR_FUN_060c3d68;
  piVar1 = DAT_060c3d5c;
  iVar5 = *DAT_060c3d5c;
  iVar7 = uVar6 + iVar5;
  while( true ) {
    if (iVar7 <= iVar5) {
      return -1;
    }
    iVar5 = (*(code *)puVar3)();
    if (-1 < iVar5) break;
    iVar5 = *piVar1;
  }
  return iVar5;
}



undefined4 FUN_060c3d6c(uint param_1)

{
  uint *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  puVar2 = PTR_FUN_060c3dc4;
  puVar1 = DAT_060c3dbc;
  uVar4 = *DAT_060c3dc0;
  uVar5 = *DAT_060c3dbc;
  (*(code *)PTR_FUN_060c3dc8)();
  (*(code *)puVar2)();
  *puVar1 = param_1 & (int)DAT_060c3db8;
  uVar3 = (*(code *)PTR_FUN_060c3dcc)();
  (*(code *)puVar2)(uVar4);
  *puVar1 = uVar5;
  return uVar3;
}



undefined4 FUN_060c3dd0(undefined4 param_1)

{
  byte bVar1;
  code *pcVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  iVar5 = *DAT_060c3ef4;
  *DAT_060c3ef4 = iVar5 + 1;
  bVar1 = *(byte *)(iVar5 + *DAT_060c3ef8);
  uVar6 = (uint)bVar1;
  uVar4 = uVar6 & 0xe0;
  if (uVar4 == 0x40) {
    uVar6 = uVar6 & 0x1f;
    pcVar2 = (code *)PTR_FUN_060c3f04;
    goto LAB_060c3f36;
  }
  if (uVar4 < 0x41) {
    if ((bVar1 & 0xe0) == 0) {
      uVar6 = uVar6 & 0x1f;
      pcVar2 = (code *)PTR_FUN_060c3efc;
      goto LAB_060c3f36;
    }
    if (uVar4 == 0x20) {
      uVar6 = uVar6 & 0x1f;
      pcVar2 = (code *)PTR_FUN_060c3f00;
      goto LAB_060c3f36;
    }
  }
  else {
    if (uVar4 == 0x60) {
      uVar6 = uVar6 & 0x1f;
      pcVar2 = (code *)PTR_FUN_060c3f08;
      goto LAB_060c3f26;
    }
    if (uVar4 == (int)DAT_060c3ee8) {
      uVar6 = uVar6 & 0x1f;
      pcVar2 = (code *)PTR_FUN_060c3f0c;
      goto LAB_060c3f26;
    }
  }
  uVar4 = uVar6 & 0xf0;
  if (uVar4 == (int)DAT_060c3eea) {
    uVar6 = uVar6 & 0xf;
    pcVar2 = (code *)PTR_FUN_060c3f14;
LAB_060c3f26:
    uVar3 = (*pcVar2)(uVar6,param_1);
    return uVar3;
  }
  if ((int)DAT_060c3eea < (int)uVar4) {
    if (uVar4 == (int)DAT_060c3eee) {
      uVar6 = uVar6 & 0xf;
      pcVar2 = (code *)PTR_FUN_060c3f18;
      goto LAB_060c3f36;
    }
    if (uVar4 == (int)DAT_060c3ef0) {
      uVar6 = uVar6 & 0xf;
      pcVar2 = (code *)PTR_FUN_060c3f1c;
      goto LAB_060c3f36;
    }
  }
  else if (uVar4 == (int)DAT_060c3eec) {
    uVar6 = uVar6 & 0xf;
    pcVar2 = (code *)PTR_FUN_060c3f10;
    goto LAB_060c3f26;
  }
  switch(uVar6 - (int)DAT_060c3ef2) {
  case 0:
  case 1:
  case 2:
  case 3:
    uVar6 = uVar6 & 3;
    pcVar2 = (code *)PTR_FUN_060c3fbc;
    goto LAB_060c3f26;
  case 4:
  case 5:
  case 6:
  case 7:
    uVar6 = uVar6 & 3;
    pcVar2 = (code *)PTR_FUN_060c3fc0;
LAB_060c3f36:
    uVar3 = (*pcVar2)(uVar6);
    return uVar3;
  case 8:
    uVar3 = (*(code *)PTR_FUN_060c3fc4)(0,param_1);
    break;
  case 9:
    uVar3 = (*(code *)PTR_FUN_060c3fc4)(1,param_1);
    break;
  case 10:
    uVar3 = (*(code *)PTR_FUN_060c3fc8)();
    break;
  case 0xb:
    uVar3 = (*(code *)PTR_FUN_060c3fcc)();
    break;
  case 0xc:
    uVar3 = (*(code *)PTR_FUN_060c3fd0)();
    break;
  case 0xd:
    uVar3 = (*(code *)PTR_FUN_060c3fd4)();
    break;
  case 0xe:
    uVar3 = (*(code *)PTR_FUN_060c3fd8)(0xffffffff);
    break;
  default:
    uVar3 = 0xffffffff;
    break;
  case 0x1b:
    uVar3 = (*(code *)PTR_FUN_060c3fdc)(0xfffffffe,param_1);
    break;
  case 0x1c:
    pcVar2 = (code *)PTR_FUN_060c3fdc;
    goto LAB_060c3faa;
  case 0x1d:
    pcVar2 = (code *)PTR_FUN_060c3fe0;
    goto LAB_060c3faa;
  case 0x1e:
    pcVar2 = (code *)PTR_FUN_060c3fe4;
    goto LAB_060c3faa;
  case 0x1f:
    pcVar2 = (code *)PTR_FUN_060c3fe8;
LAB_060c3faa:
    uVar3 = (*pcVar2)(0xffffffff,param_1);
  }
  return uVar3;
}



undefined4 FUN_060c3fec(void)

{
  byte bVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  code *pcVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  
  iVar8 = *DAT_060c4128;
  *DAT_060c4128 = iVar8 + 1;
  piVar3 = DAT_060c41e4;
  piVar2 = DAT_060c41d0;
  bVar1 = *(byte *)(iVar8 + *DAT_060c412c);
  uVar10 = (uint)bVar1;
  uVar6 = uVar10 & 0xe0;
  if (uVar6 == 0x40) {
LAB_060c4036:
    *DAT_060c4128 = ((uVar10 & 0x1f) + 1) * 3 + *DAT_060c4128;
    return 0xffffffff;
  }
  if (uVar6 < 0x41) {
    if (((bVar1 & 0xe0) == 0) || (uVar6 == 0x20)) goto LAB_060c4036;
  }
  else {
    if (uVar6 == 0x60) {
      uVar10 = uVar10 & 0x1f;
      pcVar5 = (code *)PTR_FUN_060c4130;
      goto LAB_060c4056;
    }
    if (uVar6 == (int)DAT_060c411a) {
      uVar10 = uVar10 & 0x1f;
      pcVar5 = (code *)PTR_FUN_060c4134;
      goto LAB_060c4056;
    }
  }
  uVar6 = uVar10 & 0xf0;
  if (uVar6 == (int)DAT_060c411c) {
    uVar10 = uVar10 & 0xf;
    pcVar5 = (code *)PTR_FUN_060c413c;
  }
  else if ((int)DAT_060c411c < (int)uVar6) {
    if (uVar6 == (int)DAT_060c4120) {
      uVar10 = uVar10 & 0xf;
      pcVar5 = (code *)PTR_FUN_060c4140;
    }
    else {
      if (uVar6 != (int)DAT_060c4122) goto LAB_060c40aa;
      uVar10 = uVar10 & 0xf;
      pcVar5 = (code *)PTR_FUN_060c4144;
    }
  }
  else {
    if (uVar6 != (int)DAT_060c411e) {
LAB_060c40aa:
      switch(uVar10 - (int)DAT_060c4124) {
      case 0:
      case 1:
      case 2:
      case 3:
        uVar4 = (*(code *)PTR_FUN_060c4148)(uVar10 & 3);
        return uVar4;
      case 4:
      case 6:
      case 0xd:
        *DAT_060c41d0 = *DAT_060c41d0 + 2;
        break;
      case 5:
      case 7:
        *DAT_060c41d0 = *DAT_060c41d0 + 3;
        break;
      case 0xb:
        uVar4 = (*(code *)PTR_FUN_060c41d4)();
        return uVar4;
      case 0xe:
        (*(code *)PTR_FUN_060c41d8)(0xffffffff);
        return 0xffffffff;
      case 0x1b:
        (*(code *)PTR_FUN_060c41dc)();
      case 9:
        (*(code *)PTR_FUN_060c41e0)();
        return 0xffffffff;
      case 0x1c:
      case 0x1d:
      case 0x1e:
      case 0x1f:
        iVar8 = *DAT_060c41d0;
        *DAT_060c41d0 = iVar8 + 1;
        iVar9 = *piVar3;
        uVar10 = (uint)*(byte *)(iVar8 + iVar9);
        *DAT_060c41e8 = uVar10;
        if ((uint)(int)DAT_060c41cc < uVar10) {
          iVar7 = (int)DAT_060c41ce;
          *piVar2 = iVar8 + 2;
          uVar10 = (iVar7 + uVar10) * 0x100 | (uint)*(byte *)(iVar8 + 1 + iVar9);
        }
        *DAT_060c41d0 = *DAT_060c41d0 + uVar10;
      }
      return 0xffffffff;
    }
    uVar10 = uVar10 & 0xf;
    pcVar5 = (code *)PTR_FUN_060c4138;
  }
LAB_060c4056:
  (*pcVar5)(uVar10);
  return 0xffffffff;
}



undefined4 FUN_060c41ec(int param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  puVar2 = PTR_FUN_060c422c;
  puVar1 = PTR_FUN_060c4228;
  iVar4 = 0;
  if (0 < param_1 + 1) {
    do {
      iVar4 = iVar4 + 1;
      uVar3 = (*(code *)puVar1)();
      (*(code *)puVar2)(uVar3,1);
    } while (iVar4 < param_1 + 1);
  }
  return 0xffffffff;
}



undefined4 FUN_060c4230(int param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  puVar2 = PTR_FUN_060c4288;
  puVar1 = PTR_FUN_060c4284;
  iVar5 = 0;
  if (0 < param_1 + 1) {
    do {
      uVar3 = (*(code *)PTR_FUN_060c428c)();
      iVar4 = (*(code *)puVar1)(uVar3);
      iVar5 = iVar5 + 1;
      if (iVar4 != -1) {
        (*(code *)puVar2)(uVar3,iVar4 + 1);
      }
    } while (iVar5 < param_1 + 1);
  }
  return 0xffffffff;
}



undefined4 FUN_060c4290(int param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  puVar2 = PTR_FUN_060c42d0;
  puVar1 = PTR_FUN_060c42cc;
  iVar4 = 0;
  if (0 < param_1 + 1) {
    do {
      iVar4 = iVar4 + 1;
      uVar3 = (*(code *)puVar1)();
      (*(code *)puVar2)(uVar3,0);
    } while (iVar4 < param_1 + 1);
  }
  return 0xffffffff;
}



int FUN_060c42d4(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  piVar4 = DAT_060c43e8;
  piVar3 = DAT_060c43e4;
  puVar2 = PTR_FUN_060c43d8;
  puVar1 = PTR_FUN_060c43d4;
  if (param_1 < 0) {
    if (param_1 == -1) {
      iVar8 = *DAT_060c43e4;
      *DAT_060c43e4 = iVar8 + 1;
      iVar5 = *piVar4;
      uVar6 = (uint)*(byte *)(iVar8 + iVar5);
      *DAT_060c43ec = uVar6;
      if ((uint)(int)DAT_060c43d0 < uVar6) {
        iVar7 = (int)DAT_060c43d2;
        *piVar3 = iVar8 + 2;
        uVar6 = (iVar7 + uVar6) * 0x100 | (uint)*(byte *)(iVar8 + 1 + iVar5);
      }
      puVar2 = PTR_FUN_060c43d8;
      puVar1 = PTR_FUN_060c43d4;
      iVar8 = uVar6 + *DAT_060c43e4;
      if (*DAT_060c43e4 < iVar8) {
        do {
          iVar5 = (*(code *)puVar1)();
          if (iVar5 != 0) {
            iVar5 = (*(code *)PTR_FUN_060c43dc)(param_2);
            *DAT_060c43e4 = iVar8;
            return iVar5;
          }
          (*(code *)puVar2)();
        } while (*DAT_060c43e4 < iVar8);
        return -1;
      }
      return -1;
    }
    iVar8 = (*(code *)PTR_FUN_060c43d4)();
    if (iVar8 != 0) {
      iVar8 = (*(code *)PTR_FUN_060c43dc)(param_2);
      return iVar8;
    }
  }
  else {
    param_1 = param_1 + 1;
    iVar8 = 0;
    if (0 < param_1) {
      do {
        iVar5 = (*(code *)puVar1)();
        if (iVar5 != 0) break;
        iVar8 = iVar8 + 1;
        (*(code *)puVar2)();
      } while (iVar8 < param_1);
    }
    iVar5 = (*(code *)PTR_FUN_060c43dc)(param_2);
    puVar2 = PTR_FUN_060c43e0;
    puVar1 = PTR_FUN_060c43d8;
    if (-1 < iVar5) {
      return iVar5;
    }
    if (param_1 <= iVar8) {
      return -1;
    }
    while (iVar8 = iVar8 + 1, iVar8 < param_1) {
      (*(code *)puVar2)();
      (*(code *)puVar1)();
    }
  }
  (*(code *)PTR_FUN_060c43d8)();
  return -1;
}



int FUN_060c43f0(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  piVar4 = DAT_060c44e0;
  piVar3 = DAT_060c44dc;
  if (param_1 < 0) {
    iVar6 = *DAT_060c44dc;
    *DAT_060c44dc = iVar6 + 1;
    iVar9 = *piVar4;
    uVar7 = (uint)*(byte *)(iVar6 + iVar9);
    *DAT_060c44e4 = uVar7;
    if ((uint)(int)DAT_060c44cc < uVar7) {
      iVar8 = (int)DAT_060c44ce;
      *piVar3 = iVar6 + 2;
      uVar7 = (iVar8 + uVar7) * 0x100 | (uint)*(byte *)(iVar6 + 1 + iVar9);
    }
    piVar3 = DAT_060c44dc;
    iVar6 = -1;
    iVar9 = *DAT_060c44dc;
    uVar5 = (*(code *)PTR_FUN_060c44d0)();
    puVar1 = PTR_FUN_060c44d4;
    iVar8 = *piVar3;
    while ((iVar8 < (int)(uVar7 + iVar9) && (iVar6 = (*(code *)puVar1)(param_2,uVar5), iVar6 == -99)
           )) {
      iVar8 = *piVar3;
    }
    *DAT_060c44dc = uVar7 + iVar9;
  }
  else {
    param_1 = param_1 + 1;
    uVar5 = (*(code *)PTR_FUN_060c44d0)();
    puVar2 = PTR_FUN_060c44d4;
    iVar9 = 0;
    puVar1 = PTR_FUN_060c44d8;
    if (0 < param_1) {
      do {
        iVar6 = (*(code *)puVar2)(param_2,uVar5);
        if (-1 < iVar6) {
          return iVar6;
        }
        puVar1 = PTR_FUN_060c44d8;
      } while ((iVar6 != -1) && (iVar9 = iVar9 + 1, iVar9 < param_1));
    }
    while( true ) {
      puVar2 = PTR_FUN_060c44d8;
      iVar9 = iVar9 + 1;
      iVar6 = -1;
      PTR_FUN_060c44d8 = puVar1;
      if (param_1 <= iVar9) break;
      (*(code *)puVar2)();
      (*(code *)puVar2)();
      puVar1 = PTR_FUN_060c44d8;
      PTR_FUN_060c44d8 = puVar2;
    }
  }
  return iVar6;
}



undefined4 FUN_060c44e8(undefined4 param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  undefined *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  piVar2 = DAT_060c4588;
  piVar1 = DAT_060c4584;
  iVar6 = *DAT_060c4584;
  *DAT_060c4584 = iVar6 + 1;
  iVar8 = *piVar2;
  uVar7 = (uint)*(byte *)(iVar6 + iVar8);
  *DAT_060c458c = uVar7;
  if ((uint)(int)DAT_060c457e < uVar7) {
    iVar5 = (int)DAT_060c4580;
    *piVar1 = iVar6 + 2;
    uVar7 = (uVar7 + iVar5) * 0x100 | (uint)*(byte *)(iVar6 + 1 + iVar8);
  }
  puVar3 = PTR_FUN_060c4594;
  piVar1 = DAT_060c4584;
  if (uVar7 == 0) {
LAB_060c453e:
    uVar4 = (*(code *)PTR_FUN_060c4590)(param_1);
  }
  else {
    iVar6 = *DAT_060c4584;
    iVar8 = uVar7 + iVar6;
    while (iVar6 < iVar8) {
      iVar6 = (*(code *)puVar3)();
      if (iVar6 == param_2) {
        *DAT_060c4584 = iVar8;
        goto LAB_060c453e;
      }
      iVar6 = *piVar1;
    }
    (*(code *)PTR_FUN_060c4598)();
    uVar4 = 0xffffff9d;
  }
  return uVar4;
}



int FUN_060c459c(int param_1,undefined4 param_2)

{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  undefined *puVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  piVar3 = DAT_060c46dc;
  piVar2 = DAT_060c46d8;
  if (param_1 < 0) {
    iVar10 = *DAT_060c46d8;
    *DAT_060c46d8 = iVar10 + 1;
    iVar9 = *piVar3;
    uVar6 = (uint)*(byte *)(iVar10 + iVar9);
    *DAT_060c46e8 = uVar6;
    if ((uint)(int)DAT_060c46c8 < uVar6) {
      iVar8 = (int)DAT_060c46ca;
      *piVar2 = iVar10 + 2;
      uVar6 = (iVar8 + uVar6) * 0x100 | (uint)*(byte *)(iVar10 + 1 + iVar9);
    }
    piVar2 = DAT_060c46d8;
    iVar10 = *DAT_060c46d8;
    uVar5 = (*(code *)PTR_FUN_060c46cc)();
    uVar7 = (*(code *)PTR_FUN_060c46d0)(uVar5);
    (*(code *)PTR_FUN_060c46d4)(uVar5,uVar7 + 1);
    iVar9 = *piVar2;
    while (iVar9 < (int)(uVar6 + iVar10)) {
      iVar9 = *piVar2;
      *piVar2 = iVar9 + 1;
      if (uVar7 <= *(byte *)(iVar9 + *DAT_060c46dc)) {
        iVar9 = (*(code *)PTR_FUN_060c46e4)(param_2);
        *piVar2 = uVar6 + iVar10;
        return iVar9;
      }
      (*(code *)PTR_FUN_060c46e0)();
      iVar9 = *piVar2;
    }
    iVar10 = -1;
  }
  else {
    iVar10 = -1;
    param_1 = param_1 + 2;
    uVar5 = (*(code *)PTR_FUN_060c46cc)();
    uVar6 = (*(code *)PTR_FUN_060c46d0)(uVar5);
    (*(code *)PTR_FUN_060c46d4)(uVar5,uVar6 + 1);
    piVar2 = DAT_060c46d8;
    iVar9 = 0;
    bVar1 = false;
    if (0 < param_1) {
      do {
        iVar8 = *piVar2;
        *piVar2 = iVar8 + 1;
        if (uVar6 <= *(byte *)(iVar8 + *DAT_060c46dc)) {
          iVar10 = (*(code *)PTR_FUN_060c46e4)(param_2);
          break;
        }
        iVar9 = iVar9 + 1;
        (*(code *)PTR_FUN_060c46e0)();
      } while (iVar9 < param_1);
      bVar1 = -1 < iVar10;
    }
    puVar4 = PTR_FUN_060c46e0;
    piVar2 = DAT_060c46d8;
    iVar9 = iVar9 + 1;
    if ((!bVar1) && (iVar10 = -1, iVar9 < param_1)) {
      do {
        *piVar2 = *piVar2 + 1;
        (*(code *)puVar4)();
        iVar9 = iVar9 + 1;
      } while (iVar9 < param_1);
      iVar10 = -1;
    }
  }
  return iVar10;
}



int FUN_060c46ec(int param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar4 = (*(code *)PTR_FUN_060c47f0)();
  piVar2 = DAT_060c47f8;
  piVar1 = DAT_060c47f4;
  if (param_1 < 0) {
    iVar8 = *DAT_060c47f4;
    *DAT_060c47f4 = iVar8 + 1;
    iVar7 = *piVar2;
    uVar5 = (uint)*(byte *)(iVar8 + iVar7);
    *DAT_060c4804 = uVar5;
    if ((uint)(int)DAT_060c47ea < uVar5) {
      iVar6 = (int)DAT_060c47ec;
      *piVar1 = iVar8 + 2;
      uVar5 = (iVar6 + uVar5) * 0x100 | (uint)*(byte *)(iVar8 + 1 + iVar7);
    }
    piVar1 = DAT_060c47f4;
    iVar8 = *DAT_060c47f4;
    iVar7 = uVar5 + iVar8;
    while (iVar8 < iVar7) {
      iVar8 = *piVar1;
      *piVar1 = iVar8 + 1;
      if (iVar4 <= (int)(uint)*(byte *)(iVar8 + *DAT_060c47f8)) {
        iVar4 = (*(code *)PTR_FUN_060c4800)(param_2);
        *piVar1 = iVar7;
        return iVar4;
      }
      (*(code *)PTR_FUN_060c47fc)();
      iVar8 = *piVar1;
    }
    iVar8 = -1;
  }
  else {
    param_1 = param_1 + 2;
    iVar7 = 0;
    iVar8 = -1;
    if (0 < param_1) {
      do {
        iVar6 = *piVar1;
        *piVar1 = iVar6 + 1;
        if (iVar4 <= (int)(uint)*(byte *)(iVar6 + *DAT_060c47f8)) {
          iVar8 = (*(code *)PTR_FUN_060c4800)(param_2);
          break;
        }
        iVar7 = iVar7 + 1;
        (*(code *)PTR_FUN_060c47fc)();
      } while (iVar7 < param_1);
    }
    puVar3 = PTR_FUN_060c47fc;
    piVar1 = DAT_060c47f4;
    iVar7 = iVar7 + 1;
    if ((iVar8 < 0) && (iVar8 = -1, iVar7 < param_1)) {
      do {
        *piVar1 = *piVar1 + 1;
        (*(code *)puVar3)();
        iVar7 = iVar7 + 1;
      } while (iVar7 < param_1);
      iVar8 = -1;
    }
  }
  return iVar8;
}



undefined4 FUN_060c4808(int param_1)

{
  int iVar1;
  
  iVar1 = *DAT_060c4834;
  *DAT_060c4834 = iVar1 + 1;
  (*(code *)PTR_FUN_060c483c)(param_1 << 8 | (uint)*(byte *)(iVar1 + *DAT_060c4838));
  return 0xffffffff;
}



undefined4 FUN_060c4840(int param_1)

{
  int *piVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  if (param_1 < 0) {
    iVar6 = *DAT_060c48bc;
    *DAT_060c48bc = iVar6 + 1;
    uVar7 = (uint)*(byte *)(iVar6 + *DAT_060c48c0);
  }
  else {
    uVar7 = param_1 + 1;
  }
  puVar2 = PTR_FUN_060c48c4;
  piVar1 = DAT_060c48bc;
  iVar6 = *DAT_060c48bc;
  *DAT_060c48bc = uVar7 * 3 + iVar6;
  uVar4 = (*(code *)puVar2)();
  iVar8 = *piVar1;
  *piVar1 = iVar6;
  puVar3 = PTR_FUN_060c48cc;
  puVar2 = PTR_FUN_060c48c8;
  iVar6 = 0;
  if (0 < (int)uVar7) {
    do {
      iVar6 = iVar6 + 1;
      uVar5 = (*(code *)puVar2)();
      (*(code *)puVar3)(uVar5,uVar4);
    } while (iVar6 < (int)uVar7);
  }
  *DAT_060c48bc = iVar8;
  return 0xffffffff;
}



undefined4 FUN_060c48d0(uint param_1,undefined4 param_2)

{
  byte bVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  
  uVar9 = 0;
  uVar5 = (*(code *)PTR_FUN_060c495c)(param_1 & 1);
  piVar4 = DAT_060c4968;
  piVar3 = DAT_060c4964;
  puVar2 = DAT_060c4960;
  if ((param_1 & 2) != 0) {
    iVar8 = *DAT_060c4964;
    uVar9 = *DAT_060c4960;
    *DAT_060c4964 = iVar8 + 1;
    iVar7 = *piVar4;
    bVar1 = *(byte *)(iVar8 + iVar7);
    *DAT_060c496c = (uint)bVar1;
    *piVar3 = iVar8 + 2;
    uVar6 = (*(code *)PTR_FUN_060c4970)(CONCAT11(bVar1,*(undefined *)(iVar8 + 1 + iVar7)));
    *puVar2 = uVar6;
  }
  (*(code *)PTR_FUN_060c4974)(uVar5);
  uVar5 = (*(code *)PTR_FUN_060c4978)(uVar5,param_2);
  (*(code *)PTR_FUN_060c497c)();
  if ((param_1 & 2) != 0) {
    *DAT_060c4960 = uVar9;
  }
  return uVar5;
}



undefined4 FUN_060c4980(uint param_1)

{
  byte bVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  
  uVar9 = 0;
  uVar5 = (*(code *)PTR_FUN_060c4a04)(param_1 & 1);
  piVar4 = DAT_060c4a10;
  piVar3 = DAT_060c4a0c;
  puVar2 = DAT_060c4a08;
  if ((param_1 & 2) != 0) {
    iVar8 = *DAT_060c4a0c;
    uVar9 = *DAT_060c4a08;
    *DAT_060c4a0c = iVar8 + 1;
    iVar7 = *piVar4;
    bVar1 = *(byte *)(iVar8 + iVar7);
    *DAT_060c4a14 = (uint)bVar1;
    *piVar3 = iVar8 + 2;
    uVar6 = (*(code *)PTR_FUN_060c4a18)(CONCAT11(bVar1,*(undefined *)(iVar8 + 1 + iVar7)));
    *puVar2 = uVar6;
  }
  (*(code *)PTR_FUN_060c4a1c)(uVar5);
  uVar5 = (*(code *)PTR_FUN_060c4a20)(uVar5);
  (*(code *)PTR_FUN_060c4a24)();
  if ((param_1 & 2) != 0) {
    *DAT_060c4a08 = uVar9;
  }
  return uVar5;
}



uint FUN_060c4a28(uint param_1)

{
  uint uVar1;
  
  uVar1 = (*(code *)PTR_FUN_060c4a50)(param_1 & 1);
  if ((param_1 & 2) != 0) {
    uVar1 = uVar1 | DAT_060c4a54;
  }
  return uVar1;
}



undefined4 FUN_060c4a58(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    if (param_1 != 0) {
      (*(code *)PTR_FUN_060c4aa4)();
    }
  }
  else {
    *(undefined *)(DAT_060c4a9c + *DAT_060c4a98 * (int)DAT_060c4a96) = 1;
    if (param_1 != 0) {
      uVar1 = (*(code *)PTR_FUN_060c4aa0)(0);
      return uVar1;
    }
  }
  return 0xffffffff;
}



undefined4 FUN_060c4aa8(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *DAT_060c4aec;
  if (-1 < iVar2) {
    iVar1 = DAT_060c4af0 + iVar2 * DAT_060c4ae8;
    do {
      if (*(char *)(iVar1 + 0x41) != '\0') break;
      iVar2 = iVar2 + -1;
      iVar1 = iVar1 + DAT_060c4aea;
    } while (-1 < iVar2);
  }
  *(undefined *)(DAT_060c4af4 + iVar2 * DAT_060c4ae8) = 0;
  return 0xffffffff;
}



void FUN_060c4af8(void)

{
  (*(code *)PTR_FUN_060c4b0c)(0);
  return;
}



undefined4 FUN_060c4b10(void)

{
  return DAT_060c4b1c;
}



undefined4 FUN_060c4b20(void)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)PTR_FUN_060c4b3c)();
  (*(code *)PTR_FUN_060c4b40)(uVar1);
  return 0xffffffff;
}



void FUN_060c4b44(int param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  
  puVar2 = PTR_FUN_060c4b88;
  puVar1 = PTR_FUN_060c4b84;
  iVar3 = 0;
  if (0 < param_1 + 1) {
    do {
      iVar3 = iVar3 + 1;
      (*(code *)puVar1)();
      (*(code *)puVar2)();
    } while (iVar3 < param_1 + 1);
  }
  (*(code *)PTR_FUN_060c4b88)();
  return;
}



void FUN_060c4b8c(int param_1)

{
  undefined *puVar1;
  int iVar2;
  
  (*(code *)PTR_FUN_060c4bc4)();
  puVar1 = PTR_FUN_060c4bc8;
  iVar2 = 0;
  if (0 < param_1 + 1) {
    do {
      iVar2 = iVar2 + 1;
      (*(code *)puVar1)();
      (*(code *)puVar1)();
    } while (iVar2 < param_1 + 1);
  }
  return;
}



void FUN_060c4bcc(int param_1)

{
  int *piVar1;
  undefined *puVar2;
  int iVar3;
  
  piVar1 = DAT_060c4c10;
  iVar3 = 0;
  *DAT_060c4c10 = *DAT_060c4c10 + 3;
  puVar2 = PTR_FUN_060c4c14;
  if (0 < param_1 + 2) {
    do {
      *piVar1 = *piVar1 + 1;
      (*(code *)puVar2)();
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_1 + 2);
  }
  return;
}



void FUN_060c4c18(int param_1)

{
  int *piVar1;
  undefined *puVar2;
  int iVar3;
  
  puVar2 = PTR_FUN_060c4c58;
  piVar1 = DAT_060c4c54;
  iVar3 = 0;
  if (0 < param_1 + 2) {
    do {
      *piVar1 = *piVar1 + 1;
      (*(code *)puVar2)();
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_1 + 2);
  }
  return;
}



void FUN_060c4c5c(int param_1)

{
  int iVar1;
  
  iVar1 = *DAT_060c4c88;
  *DAT_060c4c88 = iVar1 + 1;
  (*(code *)PTR_FUN_060c4c90)(param_1 << 8 | (uint)*(byte *)(iVar1 + *DAT_060c4c8c));
  return;
}



void FUN_060c4c94(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 < 0) {
    iVar1 = *DAT_060c4cd4;
    *DAT_060c4cd4 = iVar1 + 1;
    uVar2 = (uint)*(byte *)(iVar1 + *DAT_060c4cd8);
  }
  else {
    uVar2 = param_1 + 1;
  }
  *DAT_060c4cd4 = uVar2 * 3 + *DAT_060c4cd4;
  (*(code *)PTR_FUN_060c4cdc)();
  return;
}



undefined4 FUN_060c4ce0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*(code *)PTR_FUN_060c4d10)();
  uVar2 = (*(code *)PTR_FUN_060c4d14)(iVar1 + 1);
  (*(code *)PTR_FUN_060c4d18)(uVar2,param_1);
  return uVar2;
}



char * FUN_060c4d24(char *param_1)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  char cVar4;
  
  if (param_1 == (char *)0x0) {
    pcVar1 = (char *)(*(code *)PTR_FUN_060c4d78)(PTR_s__NULL__060c4d74);
  }
  else {
    iVar2 = (*(code *)PTR_FUN_060c4d7c)(param_1);
    pcVar1 = (char *)(*(code *)PTR_FUN_060c4d80)(iVar2 + 1);
    cVar4 = *param_1;
    pcVar3 = pcVar1;
    while (param_1 = param_1 + 1, cVar4 != '\0') {
      *pcVar3 = -cVar4;
      pcVar3 = pcVar3 + 1;
      cVar4 = *param_1;
    }
    *pcVar3 = '\0';
  }
  return pcVar1;
}



int FUN_060c4da0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_FUN_060c4dcc)();
  if (iVar1 == 0) {
    (*(code *)PTR_FUN_060c4dd4)(PTR_s_virtual_memory_exhausted_060c4dd0,param_1);
  }
  return iVar1;
}



int FUN_060c4df8(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_FUN_060c4e2c)();
  if ((iVar1 == 0) && (param_2 != 0)) {
    (*(code *)PTR_FUN_060c4e34)(PTR_s_virtual_memory_exhausted__re__060c4e30,param_2);
  }
  return iVar1;
}



void FUN_060c4e38(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = DAT_060c4e58;
    param_1[1] = DAT_060c4e5c;
  }
  (*(code *)PTR_FUN_060c4e60)();
  return;
}



void FUN_060c4f3c(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = param_1 + 3 >> 2;
  piVar1 = (int *)(*(code *)PTR_FUN_060c4f70)((iVar2 + 2) * 4);
  *piVar1 = iVar2;
  (piVar1 + 1)[iVar2] = DAT_060c4f74 ^ (uint)(piVar1 + 1);
  return;
}



void FUN_060c4f78(int param_1)

{
  if (param_1 != 0) {
    (*(code *)PTR_FUN_060c4f90)(param_1 + -4);
  }
  return;
}



uint * FUN_060c4f94(uint *param_1,int param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  
  if (param_1 == (uint *)0x0) {
    param_1 = (uint *)(*(code *)PTR_FUN_060c5048)(param_2);
  }
  else {
    uVar5 = param_1[-1];
    uVar4 = param_2 + 3 >> 2;
    if (uVar4 != uVar5) {
      if ((uVar5 < 0x20) || (uVar4 < 0x20)) {
        puVar1 = (uint *)(*(code *)PTR_FUN_060c5054)((uVar4 + 2) * 4);
        *puVar1 = uVar4;
        puVar1 = puVar1 + 1;
        puVar1[uVar4] = DAT_060c5050 ^ (uint)puVar1;
        puVar2 = puVar1;
        puVar3 = param_1;
        if ((int)uVar4 <= (int)uVar5) {
          uVar5 = uVar4;
        }
        while (uVar5 - 1 != 0xffffffff) {
          *puVar2 = *puVar3;
          puVar2 = puVar2 + 1;
          puVar3 = puVar3 + 1;
          uVar5 = uVar5 - 1;
        }
        (*(code *)PTR_FUN_060c5058)(param_1 + -1);
        param_1 = puVar1;
      }
      else {
        param_1 = (uint *)(*(code *)PTR_FUN_060c504c)(param_1 + -1,(uVar4 + 2) * 4);
        *param_1 = uVar4;
        param_1 = param_1 + 1;
        param_1[uVar4] = DAT_060c5050 ^ (uint)param_1;
      }
    }
  }
  return param_1;
}



undefined4 FUN_060c5dbc(byte *param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 uVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte *pbVar12;
  int iVar13;
  uint uVar14;
  char acStack_e0 [2];
  short local_de;
  
  iVar3 = DAT_060c5fa0;
  iVar13 = *(int *)PTR_DAT_060c5fa4;
  uVar14 = 0;
  uVar8 = 0;
  pbVar9 = param_1 + 2;
  pbVar10 = param_1 + 1;
  puVar7 = DAT_060c5fa8;
  pbVar12 = param_1;
  do {
    pbVar11 = pbVar12;
    uVar8 = uVar8 + 1;
    bVar1 = *pbVar10;
    pbVar10 = pbVar10 + 3;
    pbVar12 = pbVar11 + 3;
    *puVar7 = (int)(char)*pbVar11 << 0x10 | (uint)bVar1 << 8 | (uint)*pbVar9;
    pbVar9 = pbVar9 + 3;
    puVar7 = puVar7 + 1;
  } while (uVar8 < 0x40);
  uVar8 = 0;
  pbVar9 = pbVar11 + 5;
  pbVar11 = pbVar11 + 4;
  puVar7 = DAT_060c5fac;
  do {
    bVar1 = *pbVar12;
    uVar8 = uVar8 + 1;
    bVar2 = *pbVar11;
    pbVar11 = pbVar11 + 3;
    pbVar12 = pbVar12 + 3;
    *puVar7 = (int)(char)bVar1 << 0x10 | (uint)bVar2 << 8 | (uint)*pbVar9;
    puVar4 = PTR_FUN_060c5fb4;
    pbVar9 = pbVar9 + 3;
    puVar7 = puVar7 + 1;
  } while (uVar8 < 0x10);
  (*(code *)PTR_FUN_060c5fb4)(DAT_060c5fb0,pbVar12,(int)DAT_060c5f78);
  pbVar12 = pbVar12 + DAT_060c5f78;
  (*(code *)puVar4)(acStack_e0,pbVar12,0xc0);
  iVar6 = (int)DAT_060c5f7a;
  if ((local_de != DAT_060c5f7c) && (local_de != DAT_060c5f7e)) {
    *(undefined *)(DAT_060c5f80 + iVar3) = 0;
    *(undefined *)(DAT_060c5f82 + iVar3) = 0;
    *(undefined *)(DAT_060c5f84 + iVar3) = 0;
    *(undefined *)(DAT_060c5f86 + iVar3) = 0;
    *(undefined *)(DAT_060c5f88 + iVar3) = 0;
    *(undefined *)(DAT_060c5f8a + iVar3) = 0;
    *(undefined *)(DAT_060c5f8c + iVar3) = 0;
    *(undefined *)(DAT_060c5f8e + iVar3) = 0;
    *(undefined *)(DAT_060c5f90 + iVar3) = 0;
    puVar4 = PTR_FUN_060c5fb8;
    *(undefined *)
     ((int)DAT_060c5f94 + iVar3 + *(short *)(iVar13 + 4) * 3 + (int)acStack_e0[DAT_060c5f92]) = 1;
    iVar13 = (int)DAT_060c5f96;
    *(undefined *)(iVar13 + iVar3) = 1;
    do {
      (*(code *)puVar4)();
    } while (*(char *)(iVar13 + iVar3) != '\0');
  }
  *(undefined *)(iVar3 + DAT_060c5f98) = 1;
  (*(code *)PTR_FUN_060c5fb4)(DAT_060c5fbc,pbVar12 + iVar6,(int)DAT_060c5f9a);
  pbVar12 = pbVar12 + iVar6 + DAT_060c5f9a;
  iVar13 = (int)DAT_060c5f9c;
  do {
    bVar1 = *param_1;
    param_1 = param_1 + 1;
    iVar13 = iVar13 + -1;
    uVar14 = uVar14 + bVar1;
  } while (iVar13 != 0);
  uVar5 = 4;
  if (uVar14 == ((int)(char)*pbVar12 << 0x18 | (uint)pbVar12[1] << 0x10 | (uint)pbVar12[2] << 8 |
                (uint)pbVar12[3])) {
    (*(code *)PTR_FUN_060c5fc0)(iVar3 + DAT_060c5f9e,acStack_e0,0x30);
    *DAT_060c5fc4 = 0;
    uVar8 = 0;
    puVar7 = DAT_060c5fac;
    do {
      if ((int)*puVar7 < 0) break;
      uVar8 = uVar8 + 1;
      puVar7 = puVar7 + 1;
    } while (uVar8 < 0x10);
    *DAT_060c5fc8 = uVar8;
    (*(code *)PTR_FUN_060c5fcc)();
    uVar5 = 0;
  }
  return uVar5;
}



void FUN_060c5fd0(void)

{
  undefined *puVar1;
  
  *DAT_060c6000 = DAT_060c6004;
  *DAT_060c6008 = 0;
  *DAT_060c600c = 0;
  *DAT_060c6010 = 1;
  (*(code *)PTR_FUN_060c6014)(1);
  puVar1 = PTR_FUN_060c6018;
  do {
    (*(code *)puVar1)();
  } while( true );
}



void FUN_060c601c(void)

{
  *DAT_060c6034 = 1;
  (*(code *)PTR_FUN_060c6038)();
  return;
}



void FUN_060c603c(void)

{
  code *pcVar1;
  
  switch(*DAT_060c60dc) {
  case 0:
    pcVar1 = (code *)PTR_FUN_060c60e0;
    break;
  case 1:
    pcVar1 = (code *)PTR_FUN_060c60e4;
    break;
  case 2:
    pcVar1 = (code *)PTR_FUN_060c60e8;
    break;
  case 3:
    pcVar1 = (code *)PTR_FUN_060c60ec;
    break;
  case 4:
    pcVar1 = (code *)PTR_FUN_060c60f0;
    break;
  case 5:
    pcVar1 = (code *)PTR_FUN_060c60f4;
    break;
  case 6:
    pcVar1 = (code *)PTR_FUN_060c60f8;
    break;
  case 7:
    pcVar1 = (code *)PTR_FUN_060c60fc;
    break;
  case 8:
    pcVar1 = (code *)PTR_FUN_060c6100;
    break;
  case 9:
    pcVar1 = (code *)PTR_FUN_060c6104;
    break;
  case 10:
    pcVar1 = (code *)PTR_FUN_060c6108;
    break;
  case 0xb:
    pcVar1 = (code *)PTR_FUN_060c610c;
    break;
  case 0xc:
    pcVar1 = (code *)PTR_FUN_060c6110;
    break;
  case 0xd:
    pcVar1 = (code *)PTR_FUN_060c6114;
    break;
  case 0xe:
    pcVar1 = (code *)PTR_FUN_060c6118;
    break;
  default:
    goto switchD_060c6056_caseD_f;
  }
  (*pcVar1)();
switchD_060c6056_caseD_f:
  return;
}



void FUN_060c611c(int param_1)

{
  int *piVar1;
  undefined *puVar2;
  int iVar3;
  code *pcVar4;
  
  iVar3 = (*(code *)PTR_FUN_060c61c8)(0x62);
  if (iVar3 == 0) {
    *DAT_060c61cc = 0;
    (*(code *)PTR_FUN_060c61dc)
              (0x62,6,(int)*DAT_060c61d0,7,iVar3 == 0,(int)*DAT_060c61d8,(int)*DAT_060c61d4);
    (*(code *)PTR_FUN_060c61e0)(0x62,(int)DAT_060c61c2,(int)DAT_060c61c0);
  }
  puVar2 = PTR_FUN_060c61e4;
  piVar1 = DAT_060c61cc;
  iVar3 = (int)DAT_060c61c4;
  *DAT_060c61cc = *DAT_060c61cc + 1;
  iVar3 = (*(code *)puVar2)(0,0,iVar3);
  if ((iVar3 == 0) && (*piVar1 <= (int)DAT_060c61c6)) {
    return;
  }
  (*(code *)PTR_FUN_060c61e8)(0x62);
  pcVar4 = (code *)PTR_FUN_060c61f0;
  if (param_1 != 1) {
    if (param_1 < 2) {
      pcVar4 = (code *)PTR_FUN_060c61ec;
      if (param_1 != 0) {
        return;
      }
    }
    else {
      pcVar4 = (code *)PTR_FUN_060c61f4;
      if (param_1 != 2) {
        return;
      }
    }
  }
  (*pcVar4)();
  return;
}



void FUN_060c61f8(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  (*(code *)PTR_FUN_060c623c)(*DAT_060c6238);
  *DAT_060c6240 = param_1;
  *DAT_060c6244 = param_2;
  *DAT_060c6248 = param_3;
  *DAT_060c624c = param_4;
  return;
}



void FUN_060c6250(undefined4 param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  
  *DAT_060c6280 = 0;
  *DAT_060c6284 = 9;
  *DAT_060c6288 = param_1;
  *DAT_060c628c = 0;
  *DAT_060c6290 = 0;
  puVar2 = DAT_060c6294 + 9;
  puVar1 = DAT_060c6294;
  do {
    *puVar1 = 9;
    puVar1 = puVar1 + 1;
  } while ((int)puVar1 <= (int)puVar2);
  return;
}



void FUN_060c62d8(void)

{
  bool bVar1;
  undefined *puVar2;
  int *piVar3;
  undefined *puVar4;
  short *psVar5;
  short *psVar6;
  uint *puVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  byte *pbVar12;
  byte *pbVar13;
  int iVar14;
  short *psVar15;
  short sVar16;
  int aiStack_70 [16];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  
  (*(code *)PTR_FUN_060c6490)(aiStack_70,PTR_DAT_060c648c,0x10);
  iVar8 = (*(code *)PTR_FUN_060c6494)(0,0,(int)DAT_060c6480);
  if (iVar8 != 0) {
    *(undefined2 *)(DAT_060c6482 + DAT_060c6498) = 1;
    puVar2 = PTR_FUN_060c64a0;
    iVar8 = (int)DAT_060c6484;
    uVar11 = *DAT_060c649c + 1;
    *DAT_060c649c = uVar11 + ((int)(((uVar11 >> 0x10) * 2 >> 0x10) + uVar11) >> 1) * -2;
    (*(code *)puVar2)(iVar8);
  }
  iVar8 = (*(code *)PTR_FUN_060c64a8)(0,1,DAT_060c64a4);
  (*DAT_060c64ac)();
  iVar8 = aiStack_70[iVar8];
  *DAT_060c64b0 = iVar8;
  puVar2 = PTR_FUN_060c64c0;
  piVar3 = DAT_060c64bc;
  iVar14 = *(int *)(PTR_DAT_060c64b4 + iVar8 * 8);
  local_30 = iVar14 + -0x14;
  local_24 = *(int *)((int)(PTR_DAT_060c64b4 + iVar8 * 8) + 4);
  local_2c = 0x2a;
  local_28 = 0x14;
  sVar16 = (short)local_24 + -6;
  if (*DAT_060c64b8 == 1) {
    *DAT_060c64bc = *DAT_060c64bc + 1;
    iVar8 = (*(code *)puVar2)();
    puVar4 = PTR_FUN_060c64c4;
    iVar14 = iVar14 + -0x28;
    iVar9 = (*(code *)PTR_FUN_060c64c4)(iVar8,0x28);
    local_30 = iVar14 + iVar8 + iVar9 * -0x28;
    uVar10 = (*(code *)puVar2)();
    iVar8 = local_24;
    sVar16 = (*(code *)puVar4)(uVar10,0x28,uVar10,local_24);
    sVar16 = (short)iVar8 + -0x1a + (short)uVar10 + sVar16 * -0x28;
    iVar8 = (*(code *)puVar2)();
    iVar14 = (*(code *)puVar4)(iVar8,6);
    local_2c = iVar8 + iVar14 * -6 + 0x27;
    iVar8 = (*(code *)puVar2)();
    iVar14 = (*(code *)puVar4)(iVar8,6);
    local_28 = iVar8 + iVar14 * -6 + 0x11;
    if (0xf < *piVar3) {
      *DAT_060c64b8 = 0;
      *piVar3 = 0;
    }
  }
  puVar2 = PTR_FUN_060c6494;
  iVar8 = (*(code *)PTR_FUN_060c6494)(0,0,(int)DAT_060c6486);
  if ((iVar8 != 0) && (iVar8 = (*(code *)puVar2)(0,0,8), piVar3 = DAT_060c64c8, iVar8 != 0)) {
    iVar14 = *DAT_060c64c8 + 1;
    iVar8 = (*(code *)PTR_FUN_060c64c4)(iVar14,3);
    *piVar3 = iVar14 + iVar8 * -3;
    *(undefined *)(DAT_060c6488 + DAT_060c6498) = *DAT_060c64cc;
  }
  puVar2 = PTR_FUN_060c65ec;
  psVar6 = DAT_060c64dc;
  psVar15 = DAT_060c64d8;
  psVar5 = DAT_060c64d0;
  bVar1 = *DAT_060c649c == 1;
  if (bVar1) {
    (*(code *)PTR_FUN_060c65ec)
              (0x57,(int)*DAT_060c64d4,(int)*DAT_060c64d0,0x19,bVar1,(int)*DAT_060c64dc,
               (int)*DAT_060c64d8);
    (*(code *)puVar2)(0x58,4,(int)*psVar5,0x19,bVar1,(int)*psVar6,(int)*psVar15);
    puVar4 = PTR_FUN_060c65f0;
    (*(code *)PTR_FUN_060c65f0)(0x57,(int)local_30._2_2_,(int)sVar16);
    (*(code *)puVar4)(0x58,(int)local_2c._2_2_,(int)local_28._2_2_);
    iVar8 = (*(code *)PTR_FUN_060c65f4)(0,0,(int)DAT_060c65e8);
    puVar7 = DAT_060c65f8;
    if (iVar8 == 0) {
      *DAT_060c65f8 = 9;
    }
    else {
      psVar15 = (short *)((int)DAT_060c65f8 + 2);
      (*(code *)puVar2)((int)(short)(*psVar15 + 0x59),3,(int)*psVar5,0x19,0xff,(int)*psVar6,
                        (int)*DAT_060c65fc);
      (*(code *)puVar4)((int)(short)(*psVar15 + 0x59),
                        (int)(short)(*(short *)(PTR_DAT_060c6600 + *puVar7 * 8 + 2) + -4),
                        (int)(short)(*(short *)(PTR_DAT_060c6600 + *puVar7 * 8 + 6) + -4));
    }
  }
  else {
    *DAT_060c65f8 = 9;
    puVar2 = PTR_FUN_060c6604;
    (*(code *)PTR_FUN_060c6604)(0x57);
    (*(code *)puVar2)(0x58);
  }
  pbVar12 = DAT_060c6608;
  iVar8 = 0;
  uVar11 = *DAT_060c65f8;
  *DAT_060c65f8 = (uint)*DAT_060c6608;
  pbVar13 = pbVar12 + 2;
  pbVar12 = pbVar12 + 1;
  do {
    iVar8 = iVar8 + 1;
    *pbVar13 = *pbVar12;
    pbVar13 = pbVar13 + -1;
    pbVar12 = pbVar12 + -1;
  } while (iVar8 < 9);
  *DAT_060c660c = (char)uVar11;
  if ((int)uVar11 < 9) {
    (*(code *)PTR_FUN_060c6610)((int)DAT_060c65ea);
  }
  return;
}



void FUN_060c6614(void)

{
  undefined *puVar1;
  int iVar2;
  
  *DAT_060c664c = 0;
  puVar1 = PTR_FUN_060c6650;
  iVar2 = 0;
  do {
    (*(code *)puVar1)((int)(short)((short)iVar2 + 0x57));
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0xb);
  return;
}



void FUN_060c6654(void)

{
  int iVar1;
  
  (*(code *)PTR_FUN_060c6674)(0);
  iVar1 = (int)DAT_060c6672;
  *DAT_060c6678 = iVar1;
  *DAT_060c667c = iVar1;
  return;
}



void FUN_060c6680(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  undefined *puVar3;
  undefined *puVar4;
  short sVar6;
  int iVar5;
  short sVar7;
  uint uVar8;
  int iVar9;
  code *pcVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined2 local_2a;
  
  piVar1 = DAT_060c67f4;
  if (*DAT_060c67f4 < 0) {
    *DAT_060c67f4 = 0;
  }
  piVar2 = DAT_060c67f8;
  iVar12 = *piVar1;
  iVar9 = *DAT_060c67f8;
  if (iVar12 < iVar9) {
    uVar8 = *DAT_060c67fc;
    *DAT_060c67fc = uVar8 + 1;
    if ((uVar8 + 1 & 1) == 0) {
      *piVar2 = iVar9 + -1;
    }
    else {
      *piVar2 = iVar9 + -1;
      if (iVar9 + -1 < iVar12) {
        *piVar2 = iVar12;
      }
    }
  }
  (*(code *)PTR_FUN_060c680c)
            (0x56,5,(int)*DAT_060c6800,0x19,2,(int)*DAT_060c6808,(int)*DAT_060c6804);
  iVar9 = param_2 + 8;
  local_2a = (short)iVar9;
  (*(code *)PTR_FUN_060c6810)(0x56,(int)(short)((short)param_1 + -10),(int)local_2a);
  puVar3 = PTR_FUN_060c6814;
  if (*DAT_060c67f4 == 0) {
    (*(code *)PTR_FUN_060c6814)(0x50);
    (*(code *)puVar3)(0x51);
  }
  else {
    iVar11 = (int)DAT_060c67f2;
    iVar5 = *DAT_060c67f8;
    iVar13 = *DAT_060c67f4 + param_1;
    pcVar10 = (code *)PTR_FUN_060c6818;
    iVar12 = (*(code *)PTR_FUN_060c6818)(iVar5 + iVar11,0xf);
    sVar7 = (*pcVar10)(iVar5 * 0x11,iVar11);
    sVar6 = (*pcVar10)((iVar11 - iVar5) * 0x11,iVar11);
    (*(code *)PTR_FUN_060c6820)
              (0x50,DAT_060c681c,0x18,param_1,param_2,iVar13,param_2,iVar13,param_2 + 7,param_1,
               param_2 + 7);
    iVar5 = (int)(short)((ushort)(iVar12 << 5) | 0x1f);
    iVar12 = (int)(short)(sVar7 * 0x20 + sVar6);
    (*(code *)PTR_FUN_060c6824)(0x50,iVar12,iVar12,iVar5,iVar5);
    (*(code *)PTR_FUN_060c6820)
              (0x51,DAT_060c681c,0x18,param_1,iVar9,iVar13,iVar9,iVar13,param_2 + 0xf,param_1,
               param_2 + 0xf);
    (*(code *)PTR_FUN_060c6824)(0x51,iVar5,iVar5,iVar12,iVar12);
  }
  puVar3 = PTR_FUN_060c6814;
  iVar9 = *DAT_060c67f8;
  if (iVar9 == 0) {
    (*(code *)PTR_FUN_060c6814)(0x52);
    (*(code *)puVar3)(0x53);
  }
  else {
    iVar13 = (int)DAT_060c6956;
    pcVar10 = (code *)PTR_FUN_060c695c;
    iVar12 = (*(code *)PTR_FUN_060c695c)(iVar9 + iVar13,0x1e);
    iVar11 = *DAT_060c6960;
    iVar9 = param_1 + iVar9;
    iVar5 = (*pcVar10)(iVar11);
    sVar7 = (*pcVar10)(iVar13 - iVar11,0x1e);
    (*(code *)PTR_FUN_060c6968)
              (0x52,DAT_060c6964,0x18,param_1,param_2,iVar9,param_2,iVar9,param_2 + 7,param_1,
               param_2 + 7);
    iVar11 = (int)(short)((ushort)(iVar12 << 5) | 0xf);
    iVar12 = (int)(short)((short)(iVar5 << 5) + sVar7);
    (*(code *)PTR_FUN_060c696c)(0x52,iVar12,iVar12,iVar11,iVar11);
    (*(code *)PTR_FUN_060c6968)
              (0x53,DAT_060c6964,0x18,param_1,param_2 + 8,iVar9,param_2 + 8,iVar9,param_2 + 0xf,
               param_1,param_2 + 0xf);
    (*(code *)PTR_FUN_060c696c)(0x53,iVar11,iVar11,iVar12,iVar12);
  }
  puVar3 = PTR_FUN_060c6968;
  iVar12 = param_1 + DAT_060c6958;
  (*(code *)PTR_FUN_060c6968)
            (0x54,DAT_060c6964,0x18,param_1,param_2,iVar12,param_2,iVar12,param_2 + 7,param_1,
             param_2 + 7);
  puVar4 = PTR_FUN_060c696c;
  iVar9 = (int)DAT_060c695a;
  (*(code *)PTR_FUN_060c696c)(0x54,0,0,iVar9,iVar9);
  (*(code *)puVar3)(0x55,DAT_060c6964,0x18,param_1,param_2 + 8,iVar12,param_2 + 8,iVar12,
                    param_2 + 0xf,param_1,param_2 + 0xf);
  (*(code *)puVar4)(0x55,iVar9,iVar9,0,0);
  return;
}



void FUN_060c6970(void)

{
  undefined *puVar1;
  int iVar2;
  
  (*(code *)PTR_FUN_060c69a8)(1);
  puVar1 = PTR_FUN_060c69ac;
  iVar2 = 0;
  do {
    (*(code *)puVar1)((int)(short)((short)iVar2 + 0x50));
    iVar2 = iVar2 + 1;
  } while (iVar2 < 7);
  return;
}



void FUN_060c69b0(int param_1)

{
  undefined *puVar1;
  int iVar2;
  
  *DAT_060c69e4 = 1;
  *DAT_060c69e8 = 0;
  puVar1 = PTR_FUN_060c69f0;
  *DAT_060c69ec = *DAT_060c69ec - param_1;
  iVar2 = (int)DAT_060c69e0;
  *DAT_060c69f4 = *DAT_060c69f4 + '\x01';
  (*(code *)puVar1)(iVar2);
  return;
}



void FUN_060c69f8(short param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = param_1 + 0xc;
  iVar1 = (int)DAT_060c6a2c;
  if (iVar3 <= iVar1) {
    iVar4 = (int)DAT_060c6a2e;
    iVar2 = iVar3 * 0x4c + DAT_060c6a30;
    do {
      *(undefined *)(iVar2 + iVar4) = 0;
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x4c;
    } while (iVar3 <= iVar1);
  }
  return;
}



void FUN_060c6a58(short param_1)

{
  *(undefined *)((int)DAT_060c6a76 + (param_1 + 0xc) * 0x4c + DAT_060c6a78) = 0;
  return;
}



undefined FUN_060c6a7c(short param_1)

{
  return *(undefined *)((int)DAT_060c6a9c + (param_1 + 0xc) * 0x4c + DAT_060c6aa0);
}



void FUN_060c6aa4(short param_1)

{
  *(undefined *)((int)DAT_060c6ac2 + (param_1 + 0xc) * 0x4c + DAT_060c6ac4) = 1;
  return;
}



void FUN_060c6ac8(short param_1,short param_2,short param_3,short param_4,short param_5,
                 short param_6,short param_7)

{
  (*(code *)PTR_FUN_060c6af8)
            ((int)(short)(param_1 + 0xc),(int)param_2,(int)param_3,(int)param_4,(int)param_5,
             (int)param_6,(int)param_7);
  return;
}



void FUN_060c6afc(short param_1,undefined2 param_2,undefined2 param_3)

{
  int iVar1;
  
  iVar1 = (param_1 + 0xc) * 0x4c + DAT_060c6b20;
  *(undefined2 *)(DAT_060c6b1c + iVar1) = param_2;
  *(undefined2 *)(DAT_060c6b1e + iVar1) = param_3;
  return;
}



void FUN_060c6b24(short param_1,short param_2,short param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_060c6b60;
  iVar2 = (param_1 + 0xc) * 0x4c + DAT_060c6b60;
  *(short *)(DAT_060c6b56 + iVar2) = param_2 + *(short *)(DAT_060c6b58 + DAT_060c6b60);
  *(short *)(DAT_060c6b5c + iVar2) = param_3 + *(short *)(DAT_060c6b5a + iVar1);
  return;
}



ushort FUN_060c6b64(int param_1,int param_2,ushort param_3)

{
  short sVar1;
  
  sVar1 = DAT_060c6b98;
  if (param_2 == 1) {
    sVar1 = DAT_060c6b96;
  }
  return *(ushort *)((int)sVar1 + param_1 * 8 + DAT_060c6b9c) & param_3;
}



void FUN_060c6ba0(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = iVar1 + 1;
  if (param_2 < iVar1 + 1) {
    *param_1 = 0;
    (*(code *)PTR_FUN_060c6bc4)();
  }
  return;
}



void FUN_060c6bc8(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = iVar1 + 1;
  if (param_2 < iVar1 + 1) {
    *param_1 = 0;
    (*(code *)PTR_FUN_060c6bec)();
  }
  return;
}



void FUN_060c6bf0(void)

{
  code *pcVar1;
  short sVar2;
  uint uVar3;
  int extraout_r2;
  uint extraout_r3;
  short *psVar4;
  code *pcVar5;
  short *psVar6;
  int iVar7;
  int iVar8;
  
  psVar4 = *(short **)PTR_DAT_060c6c68;
  iVar7 = 0;
  iVar8 = (int)DAT_060c6c60;
  psVar6 = (short *)((int)psVar4 + (int)DAT_060c6c62);
  do {
    pcVar1 = DAT_060c6c6c;
    sVar2 = *psVar6;
    psVar6 = psVar6 + 1;
    *psVar4 = sVar2;
    uVar3 = (uint)*psVar4;
    pcVar5 = (code *)PTR_FUN_060c6c70;
    (*pcVar1)(uVar3,3);
    sVar2 = (*pcVar5)((uVar3 & 0x1f) + (extraout_r2 >> 5 & 0x1fU) + (extraout_r3 & 0x1f));
    iVar7 = iVar7 + 1;
    *psVar4 = sVar2 * DAT_060c6c64;
    psVar4 = psVar4 + 1;
  } while (iVar7 <= iVar8);
  (*(code *)PTR_FUN_060c6c78)(PTR_DAT_060c6c74);
  return;
}



void FUN_060c6c7c(void)

{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_060c6c9c;
  *(undefined2 *)PTR_DAT_060c6c9c = 1;
  *(undefined2 *)(puVar1 + 2) = 0x20;
  (*(code *)PTR_FUN_060c6ca0)(puVar1 + -4);
  return;
}



void FUN_060c6ca4(void)

{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_060c6cc4;
  *(undefined2 *)PTR_DAT_060c6cc4 = 1;
  *(undefined2 *)(puVar1 + 2) = 0x20;
  (*(code *)PTR_FUN_060c6cc8)(puVar1 + -4);
  return;
}



void FUN_060c6ccc(undefined *param_1)

{
  undefined uVar1;
  int iVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  undefined *puVar6;
  int iVar7;
  
  puVar6 = DAT_060c6d14 + 8;
  puVar3 = DAT_060c6d14;
  puVar4 = DAT_060c6d18;
  do {
    *puVar4 = 0;
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  } while ((int)puVar3 <= (int)puVar6);
  iVar7 = 0;
  iVar5 = DAT_060c6d1c;
  do {
    iVar2 = 0;
    puVar3 = param_1;
    do {
      uVar1 = *puVar3;
      puVar3 = puVar3 + 1;
      *(undefined *)(iVar5 + iVar2) = uVar1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 3);
    param_1 = param_1 + 3;
    iVar7 = iVar7 + 1;
    iVar5 = iVar5 + 3;
  } while (iVar7 < 9);
  *DAT_060c6d20 = 0;
  return;
}



void FUN_060c6d24(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_060c6d70;
  *DAT_060c6d70 = param_1;
  *DAT_060c6d74 = param_2;
  *DAT_060c6d78 = param_3;
  *DAT_060c6d7c = param_4;
  if (param_1 == 0) {
    *PTR_DAT_060c6d80 = 0x28;
  }
  iVar2 = *piVar1;
  if (iVar2 == 1) {
    *PTR_DAT_060c6d80 = 0x23;
    iVar2 = *piVar1;
  }
  if (iVar2 == 2) {
    *PTR_DAT_060c6d80 = 0x1e;
  }
  if (*piVar1 == 3) {
    *PTR_DAT_060c6d80 = 0x19;
  }
  return;
}



void FUN_060c6d84(void)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  char cVar4;
  int iVar5;
  
  iVar5 = 0;
  *DAT_060c6e7c = *DAT_060c6e7c + 1;
  piVar1 = DAT_060c6e7c;
  pcVar3 = DAT_060c6e80;
  do {
    cVar4 = *pcVar3;
    pcVar3 = pcVar3 + 1;
    if (cVar4 != '\0') {
      iVar5 = iVar5 + 1;
    }
  } while ((int)pcVar3 <= (int)(DAT_060c6e80 + 8));
  if (((iVar5 + *DAT_060c6e84 < *DAT_060c6e88) && (iVar5 < *DAT_060c6e8c)) && (0x13 < *DAT_060c6e7c)
     ) {
    if (*DAT_060c6e7c <= (int)DAT_060c6e7a) {
      iVar5 = (*(code *)PTR_FUN_060c6e90)();
      iVar2 = (*(code *)PTR_FUN_060c6e94)(iVar5,0x32);
      if (iVar5 + iVar2 * -0x32 != 0) {
        return;
      }
    }
    *piVar1 = 0;
    iVar5 = (*(code *)PTR_FUN_060c6e90)();
    iVar2 = (*(code *)PTR_FUN_060c6e94)(iVar5,9);
    iVar5 = iVar5 + iVar2 * -9;
    if (DAT_060c6e80[iVar5] != '\0') goto LAB_060c6e30;
    cVar4 = *(char *)(DAT_060c6e98 + iVar5 * 3);
    while ('\x03' < cVar4) {
LAB_060c6e30:
      do {
        iVar5 = iVar5 + 1;
        iVar2 = (*(code *)PTR_FUN_060c6e94)(iVar5,9);
        iVar5 = iVar5 + iVar2 * -9;
      } while (DAT_060c6e80[iVar5] != '\0');
      cVar4 = *(char *)(DAT_060c6e98 + iVar5 * 3);
    }
    DAT_060c6e80[iVar5] = '\x01';
  }
  return;
}



void FUN_060c6e9c(void)

{
  short sVar1;
  short sVar2;
  undefined *puVar3;
  undefined4 uVar4;
  byte bVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  int iVar9;
  short sVar10;
  
  puVar3 = PTR_FUN_060c6fa4;
  iVar9 = 0;
  sVar10 = 99;
  pbVar7 = DAT_060c6fa8;
  pbVar8 = DAT_060c6fac;
  do {
    uVar6 = (uint)*pbVar8;
    if (uVar6 != 0) {
      if (uVar6 == 4) {
        bVar5 = *pbVar7;
        if (bVar5 == 9) {
          (*(code *)PTR_FUN_060c6fb0)(0x28);
          goto LAB_060c6ed6;
        }
      }
      else {
LAB_060c6ed6:
        bVar5 = *pbVar7;
      }
      if (bVar5 == 0) {
        if (uVar6 < 5) {
          sVar1 = *DAT_060c6fbc;
          sVar2 = *DAT_060c6fc0;
          uVar4 = 2;
        }
        else {
          sVar1 = *DAT_060c6fbc;
          sVar2 = *DAT_060c6fc0;
          uVar4 = 0xff;
        }
        (*(code *)puVar3)((int)sVar10,
                          PTR_DAT_060c6fb8[uVar6 + *(char *)(DAT_060c6fb4 + iVar9 * 3) * 8],
                          (int)sVar1,5,uVar4,(int)*DAT_060c6fc4,(int)sVar2);
        (*(code *)PTR_FUN_060c6fcc)
                  ((int)sVar10,(int)*(short *)(PTR_DAT_060c6fc8 + iVar9 * 8 + 2),
                   (int)*(short *)(PTR_DAT_060c6fc8 + iVar9 * 8 + 6));
      }
      if ((byte)PTR_DAT_060c6fd0[uVar6] < *pbVar7) {
        if (uVar6 < 5) {
          bVar5 = *pbVar8 + 1;
        }
        else {
          bVar5 = 0;
        }
        *pbVar8 = bVar5;
        if (uVar6 == 3) {
          (*(code *)PTR_FUN_060c6fd4)((int)DAT_060c6fa0);
        }
        bVar5 = 0;
      }
      else {
        bVar5 = *pbVar7 + 1;
      }
      *pbVar7 = bVar5;
    }
    pbVar7 = pbVar7 + 1;
    pbVar8 = pbVar8 + 1;
    iVar9 = iVar9 + 1;
    sVar10 = sVar10 + 1;
    if (8 < iVar9) {
      return;
    }
  } while( true );
}



void FUN_060c6fd8(int param_1)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  
  if (param_1 < 9) {
    pbVar3 = (byte *)(param_1 + DAT_060c703c);
    bVar1 = *pbVar3;
    if ((bVar1 < 5) && (1 < bVar1)) {
      (*(code *)PTR_FUN_060c7040)((int)DAT_060c7038);
      iVar2 = *DAT_060c7044;
      *DAT_060c7044 = iVar2 + 1;
      if (iVar2 + 1 == *DAT_060c7048) {
        *DAT_060c704c = *DAT_060c704c + 1;
      }
      *pbVar3 = 7;
      *(undefined *)(DAT_060c7050 + param_1) = 0;
    }
  }
  return;
}



void FUN_060c7054(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  
  (*(code *)PTR_FUN_060c70f0)(0,0,1,2);
  *DAT_060c70f4 = 1;
  *DAT_060c70f8 = 1;
  *DAT_060c70fc = 3;
  *DAT_060c7100 = 2;
  *DAT_060c7104 = 3;
  *DAT_060c7108 = 4;
  *DAT_060c710c = 5;
  *DAT_060c7110 = 5;
  puVar2 = DAT_060c7114 + 0x1f;
  puVar1 = DAT_060c7114;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while ((int)puVar1 <= (int)puVar2);
  puVar4 = DAT_060c7118 + 8;
  puVar1 = DAT_060c7118;
  puVar2 = DAT_060c7120;
  puVar3 = DAT_060c711c;
  do {
    *puVar2 = 0;
    *puVar3 = 8;
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
    puVar2 = puVar2 + 1;
  } while ((int)puVar1 <= (int)puVar4);
  *DAT_060c7124 = *DAT_060c7128 + 1;
  *DAT_060c712c = 0;
  *DAT_060c7130 = 0;
  *DAT_060c7134 = 0;
  *DAT_060c7138 = 0;
  *DAT_060c713c = 0;
  *DAT_060c7140 = 0;
  *DAT_060c7144 = 0;
  return;
}



int FUN_060c7148(void)

{
  char cVar1;
  uint *puVar2;
  uint *puVar3;
  int *piVar4;
  int in_r0;
  int iVar5;
  int iVar6;
  ushort *puVar7;
  
  piVar4 = DAT_060c73d8;
  iVar5 = DAT_060c72bc;
  switch(*(undefined *)(DAT_060c72bc + 10)) {
  case 0:
    *(undefined *)(DAT_060c72bc + DAT_060c72a6) = 0;
    puVar2 = DAT_060c72c0;
    cVar1 = *(char *)(iVar5 + DAT_060c72a8);
    *DAT_060c72c0 = (int)cVar1;
    if (2 < (uint)(int)cVar1) {
      *puVar2 = 0;
    }
    puVar3 = DAT_060c72c4;
    cVar1 = *(char *)(iVar5 + DAT_060c72aa);
    *DAT_060c72c4 = (int)cVar1;
    if (2 < (uint)(int)cVar1) {
      *puVar3 = 0;
    }
    puVar3 = DAT_060c72c8;
    cVar1 = *(char *)(iVar5 + DAT_060c72ac);
    *DAT_060c72c8 = (int)cVar1;
    if (1 < (uint)(int)cVar1) {
      *puVar3 = 0;
    }
    *DAT_060c72cc = (int)*(short *)(iVar5 + DAT_060c72ae);
    *DAT_060c72d0 = 0;
    (*(code *)PTR_FUN_060c72d4)(0);
    (*(code *)PTR_FUN_060c72d8)();
    (*(code *)PTR_FUN_060c72dc)(*puVar2);
    break;
  case 1:
    iVar5 = (*(code *)PTR_FUN_060c72e0)();
    return iVar5;
  case 2:
    (*(code *)PTR_FUN_060c72e4)(5,(int)DAT_060c72b0,1);
    (*(code *)PTR_FUN_060c72e8)();
    if (*DAT_060c72ec < 9) {
      *DAT_060c72f0 = *DAT_060c72f0 + 1;
    }
    piVar4 = DAT_060c72d0;
    iVar5 = *DAT_060c72d0;
    *DAT_060c72d0 = iVar5 + 1;
    if (iVar5 + 1 == 0x3c) {
      (*(code *)PTR_FUN_060c72f4)((int)DAT_060c72b2);
    }
    iVar5 = *piVar4;
    if (iVar5 == 0x78) {
      iVar5 = (*(code *)PTR_FUN_060c72f4)((int)DAT_060c72b2);
    }
    iVar6 = *piVar4;
    if (iVar6 == DAT_060c72b4) {
      iVar5 = (*(code *)PTR_FUN_060c72f4)((int)DAT_060c72b2);
      iVar6 = *piVar4;
    }
    if (iVar6 != DAT_060c72b6) {
      return iVar5;
    }
    (*(code *)PTR_FUN_060c72f4)((int)DAT_060c72b8);
    (*(code *)PTR_FUN_060c72f8)((int)DAT_060c72ba);
    *piVar4 = 0;
    break;
  case 3:
    (*(code *)PTR_FUN_060c72e4)(5,(int)DAT_060c72b0,1);
    (*(code *)PTR_FUN_060c72e8)();
    if (*DAT_060c72ec < 9) {
      (*(code *)PTR_FUN_060c72fc)();
    }
    (*(code *)PTR_FUN_060c7300)();
    iVar5 = (*(code *)PTR_FUN_060c7304)();
    if (*DAT_060c7308 < 0x20) {
      return iVar5;
    }
    break;
  case 4:
    iVar5 = (int)DAT_060c73c8;
    *DAT_060c73d8 = *DAT_060c73d8 + 1;
    (*(code *)PTR_FUN_060c73dc)(5,iVar5,1);
    (*(code *)PTR_FUN_060c73e0)();
    if (*DAT_060c73e4 < 9) {
      (*(code *)PTR_FUN_060c73e8)();
    }
    iVar5 = (*(code *)PTR_FUN_060c73ec)();
    if (*piVar4 < 0x79) {
      return iVar5;
    }
    break;
  case 5:
    *(undefined *)(DAT_060c72bc + DAT_060c73ca) = *DAT_060c73f0;
    puVar7 = (ushort *)(iVar5 + DAT_060c73cc);
    *(char *)puVar7 = *DAT_060c73f4;
    iVar6 = (int)DAT_060c73ce;
    *(short *)(iVar5 + iVar6) = *DAT_060c73f8;
    *(undefined *)(iVar5 + DAT_060c73d0) = *DAT_060c73fc;
    (*(code *)PTR_FUN_060c7400)();
    if (((int)*(char *)puVar7 == (int)*(short *)(iVar5 + iVar6)) &&
       ((uint)*puVar7 == (int)DAT_060c73d2)) {
      iVar5 = (*(code *)PTR_FUN_060c7404)();
      return iVar5;
    }
    break;
  case 6:
    iVar5 = (*(code *)PTR_FUN_060c740c)(1);
    return iVar5;
  case 7:
    iVar5 = (*(code *)PTR_FUN_060c7410)();
    return iVar5;
  case 8:
    (*(code *)PTR_FUN_060c7414)(0);
    in_r0 = (int)DAT_060c73d4;
    *(undefined *)(iVar5 + in_r0) = 1;
  default:
    goto switchD_060c7172_caseD_9;
  }
  in_r0 = (*(code *)PTR_FUN_060c7408)();
switchD_060c7172_caseD_9:
  return in_r0;
}



void FUN_060c7418(void)

{
  int *piVar1;
  int *piVar2;
  undefined *puVar3;
  code *pcVar4;
  int iVar5;
  
  puVar3 = PTR_FUN_060c74e0;
  piVar2 = DAT_060c74d8;
  piVar1 = DAT_060c74d4;
  switch(*DAT_060c74d0) {
  case 0:
    *DAT_060c74d4 = -0x48;
    *DAT_060c74d8 = 0x118;
    pcVar4 = (code *)PTR_FUN_060c74dc;
    break;
  case 1:
    iVar5 = *DAT_060c74d4;
    *DAT_060c74d4 = iVar5 + 8;
    *piVar2 = *piVar2 + -8;
    (*(code *)PTR_FUN_060c74e0)(0x46,iVar5 + 8,1);
    (*(code *)PTR_FUN_060c74e4)(5,*piVar2,1);
    pcVar4 = (code *)PTR_FUN_060c74dc;
    if ((int)DAT_060c74ce < *piVar2) {
      return;
    }
    break;
  case 2:
    (*(code *)PTR_FUN_060c74e8)(2);
    return;
  case 3:
    iVar5 = *DAT_060c74d4;
    *DAT_060c74d4 = iVar5 + -8;
    (*(code *)puVar3)(0x46,iVar5 + -8,1);
    pcVar4 = (code *)PTR_FUN_060c74dc;
    if (-0x48 < *piVar1) {
      return;
    }
    break;
  case 4:
    (*(code *)PTR_FUN_060c74e0)(0x46,*DAT_060c74d4,0);
    pcVar4 = (code *)PTR_FUN_060c74ec;
    break;
  default:
    goto switchD_060c7436_caseD_5;
  }
  (*pcVar4)();
switchD_060c7436_caseD_5:
  return;
}



void FUN_060c74f0(int param_1,int param_2,int param_3)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  
  puVar1 = PTR_FUN_060c7618;
  if (param_3 == 1) {
    if (*DAT_060c75f4 == 1) {
      (*(code *)PTR_FUN_060c7604)
                (0,0x24,(int)*DAT_060c75f8,6,2,(int)*DAT_060c7600,(int)*DAT_060c75fc);
      (*(code *)PTR_FUN_060c7608)(0,(int)(short)param_1,(int)(short)param_2);
      puVar1 = PTR_FUN_060c760c;
      (*(code *)PTR_FUN_060c760c)(1,1,param_1,param_2);
      uVar3 = *DAT_060c7610;
      if (99 < uVar3) {
        uVar3 = 99;
      }
      iVar2 = (*(code *)PTR_FUN_060c7614)(uVar3,10,param_1 + 0x7a);
      (*(code *)puVar1)(2,iVar2 + 4);
      (*(code *)puVar1)(3,uVar3 + iVar2 * -10 + 4,param_1 + DAT_060c75f0,param_2 + 6);
    }
    else {
      (*(code *)PTR_FUN_060c7604)
                (0,0x24,(int)*DAT_060c75f8,6,2,(int)*DAT_060c7600,(int)*DAT_060c75fc);
      (*(code *)PTR_FUN_060c7608)(0,(int)(short)param_1,(int)(short)param_2);
      (*(code *)PTR_FUN_060c760c)(1,2,param_1,param_2);
    }
  }
  else {
    (*(code *)PTR_FUN_060c7618)(0);
    (*(code *)puVar1)(1);
    (*(code *)puVar1)(2);
    (*(code *)puVar1)(3);
  }
  return;
}



void FUN_060c761c(int param_1,int param_2,int param_3)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  int extraout_r2;
  int extraout_r2_00;
  int extraout_r2_01;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined2 uStack_2e;
  undefined2 local_2a;
  
  if (param_3 == 1) {
    (*(code *)PTR_FUN_060c77cc)(4,0,(int)*DAT_060c77c0,6,2,(int)*DAT_060c77c8,(int)*DAT_060c77c4);
    local_2a = (short)param_2;
    uStack_2e = (short)param_1;
    (*(code *)PTR_FUN_060c77d0)(4,(int)uStack_2e,(int)local_2a);
    puVar2 = PTR_FUN_060c77d4;
    iVar11 = 0;
    iVar9 = 0x20;
    iVar10 = param_1;
    do {
      bVar1 = *(byte *)(DAT_060c77d8 + iVar11);
      if (bVar1 == 1) {
        uVar8 = 0x23;
LAB_060c76b4:
        (*(code *)puVar2)(iVar9,uVar8,iVar10,param_2);
      }
      else if (bVar1 < 2) {
        if (bVar1 == 0) {
          (*(code *)PTR_FUN_060c77dc)((int)(short)iVar9);
        }
      }
      else if (bVar1 == 2) {
        uVar8 = 0x22;
        goto LAB_060c76b4;
      }
      iVar9 = iVar9 + 1;
      iVar11 = iVar11 + 1;
      iVar10 = iVar10 + 8;
    } while (iVar11 < 0x20);
    iVar10 = 0;
    if (*DAT_060c77e0 != '\0') {
      iVar10 = (*(code *)PTR_FUN_060c77e8)(*DAT_060c77e4 * (int)DAT_060c77b2);
    }
    puVar3 = PTR_FUN_060c77ec;
    puVar2 = PTR_FUN_060c77d4;
    iVar9 = (*(code *)PTR_FUN_060c77ec)(iVar10,(int)DAT_060c77b2,param_1 + DAT_060c77b4);
    iVar11 = (*(code *)puVar3)(iVar9,10);
    (*(code *)puVar2)(5,iVar9 + iVar11 * -10 + 4);
    iVar11 = (*(code *)puVar3)(iVar10,(int)DAT_060c77b8,param_1 + DAT_060c77b6,param_2 + 0x10);
    (*(code *)puVar2)(6,iVar11 + iVar9 * -10 + 4);
    iVar9 = (*(code *)puVar3)(iVar10,100,param_1 + DAT_060c77ba,param_2 + 0x10);
    (*(code *)puVar2)(7,iVar9 + iVar11 * -10 + 4);
    iVar11 = (*(code *)puVar3)(iVar10,10,param_1 + DAT_060c77bc);
    (*(code *)puVar2)(8,iVar11 + iVar9 * -10 + 0xe);
    (*(code *)puVar2)(9,iVar10 + iVar11 * -10 + 0xe,param_1 + DAT_060c77be,param_2 + 0x18);
    iVar10 = 0;
    if (*DAT_060c77f0 != 0) {
      iVar10 = (*(code *)PTR_FUN_060c77e8)(*DAT_060c77f4 * (int)DAT_060c77b2);
    }
    puVar3 = PTR_FUN_060c798c;
    puVar2 = PTR_FUN_060c7988;
    iVar9 = (*(code *)PTR_FUN_060c7988)(iVar10,(int)DAT_060c797a,param_1 + DAT_060c7978);
    iVar11 = (*(code *)puVar2)(iVar9,10);
    (*(code *)puVar3)(10,iVar9 + iVar11 * -10 + 4);
    iVar11 = param_1 + DAT_060c797c;
    iVar5 = (*(code *)puVar2)(iVar10,(int)DAT_060c797e,(int)DAT_060c797c,param_2 + 0x20);
    (*(code *)puVar3)(0xb,iVar5 + iVar9 * -10 + 4,iVar11);
    iVar9 = param_1 + DAT_060c7980;
    iVar6 = (*(code *)puVar2)(iVar10,100,(int)DAT_060c7980,param_2 + 0x20);
    (*(code *)puVar3)(0xc,iVar6 + iVar5 * -10 + 4,iVar9);
    iVar5 = (*(code *)puVar2)(iVar10,10,param_1 + DAT_060c7982);
    (*(code *)puVar3)(0xd,iVar5 + iVar6 * -10 + 0xe);
    (*(code *)puVar3)(0xe,iVar10 + iVar5 * -10 + 0xe,param_1 + DAT_060c7984,param_2 + 0x28);
    puVar2 = PTR_FUN_060c7994;
    puVar4 = DAT_060c7990;
    uVar7 = *DAT_060c7990;
    if (uVar7 < 10) {
      if (uVar7 == 0) {
        iVar10 = (*(code *)PTR_FUN_060c7994)(0,10);
        (*(code *)puVar3)(0xf,iVar10 + 4,iVar11,param_2 + 0x30);
        iVar10 = (*(code *)puVar2)(*puVar4,10,iVar9,param_2 + 0x30);
        iVar10 = extraout_r2_01 + iVar10 * -10 + 4;
      }
      else {
        iVar10 = (*(code *)PTR_FUN_060c7994)(uVar7,10);
        (*(code *)puVar3)(0xf,iVar10 + 4,iVar11,param_2 + 0x30);
        iVar10 = (*(code *)puVar2)(*puVar4,10,iVar9,param_2 + 0x30);
        iVar10 = extraout_r2_00 + iVar10 * -10 + 0x18;
      }
    }
    else {
      iVar10 = (*(code *)PTR_FUN_060c7994)(uVar7,10);
      (*(code *)puVar3)(0xf,iVar10 + 0x18,iVar11,param_2 + 0x30);
      iVar10 = (*(code *)puVar2)(*puVar4,10,iVar9,param_2 + 0x30);
      iVar10 = extraout_r2 + iVar10 * -10 + 0x18;
    }
    (*(code *)puVar3)(0x10,iVar10);
  }
  else {
    (*(code *)PTR_FUN_060c7998)(4);
  }
  return;
}



void FUN_060c799c(short param_1,short param_2,short param_3,short param_4)

{
  (*(code *)PTR_FUN_060c79f8)
            ((int)param_1,(int)param_2,(int)*DAT_060c79ec,7,2,(int)*DAT_060c79f4,(int)*DAT_060c79f0)
  ;
  (*(code *)PTR_FUN_060c79fc)((int)param_1,(int)param_3,(int)param_4);
  return;
}



void FUN_060c7a00(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int *piVar4;
  uint uVar5;
  byte *pbVar6;
  int unaff_r9;
  int iVar7;
  short sVar8;
  
  *(undefined *)(DAT_060c7b20 + unaff_r9) = 0;
  *(undefined *)(DAT_060c7b24 + unaff_r9) = 0;
  iVar7 = 0;
  sVar8 = 99;
  do {
    bVar2 = *(byte *)(DAT_060c7b20 + iVar7);
    bVar3 = *(byte *)(DAT_060c7b24 + iVar7);
    if (bVar3 < 8) {
      if ((*(char *)(DAT_060c7b28 + iVar7) == '\0') &&
         (((bVar2 == 0 || (bVar2 == 3)) || (bVar2 == 6)))) {
        (*(code *)PTR_FUN_060c7b2c)((int)DAT_060c7b1c);
      }
      piVar4 = DAT_060c7b30;
      pbVar6 = (byte *)(iVar7 + DAT_060c7b28);
      bVar1 = *pbVar6;
      *pbVar6 = bVar1 + 1;
      uVar5 = (uint)bVar2;
      if ((byte)PTR_DAT_060c7b34[uVar5 + *piVar4 * 8] < (byte)(bVar1 + 1)) {
        if ((uVar5 == 4) || (uVar5 == 7)) {
          (*(code *)PTR_FUN_060c7b38)(iVar7);
          *(undefined *)(DAT_060c7b24 + iVar7) = 8;
          *pbVar6 = 0;
          (*(code *)PTR_FUN_060c7b3c)((int)sVar8);
        }
        else {
          *(char *)(iVar7 + DAT_060c7b20) = *(char *)(iVar7 + DAT_060c7b20) + '\x01';
          *pbVar6 = 0;
          (*(code *)PTR_FUN_060c7b50)
                    ((int)sVar8,PTR_DAT_060c7b40[((int)(char)bVar2 + 1U & 0xff) + (uint)bVar3 * 8],
                     (int)*DAT_060c7b44,4,2,(int)*DAT_060c7b4c,(int)*DAT_060c7b48);
          (*(code *)PTR_FUN_060c7b58)
                    ((int)sVar8,(int)*(short *)(PTR_DAT_060c7b54 + iVar7 * 8 + 2),
                     (int)*(short *)(PTR_DAT_060c7b54 + iVar7 * 8 + 6));
        }
      }
    }
    iVar7 = iVar7 + 1;
    sVar8 = sVar8 + 1;
  } while (iVar7 < 9);
  return;
}



void FUN_060c7b5c(int param_1)

{
  byte *pbVar1;
  undefined uVar3;
  int iVar2;
  byte bVar4;
  
  if (*(char *)(DAT_060c7bdc + param_1) == '\x04') {
    if (4 < *(byte *)(DAT_060c7be0 + param_1)) {
      return;
    }
    bVar4 = *DAT_060c7be4;
    uVar3 = 1;
  }
  else {
    if (*(char *)(DAT_060c7bdc + param_1) != '\a') {
      return;
    }
    if (4 < *(byte *)(DAT_060c7be0 + param_1)) {
      if (7 < *(byte *)(DAT_060c7be0 + param_1)) {
        return;
      }
      *DAT_060c7bf4 = *DAT_060c7bf4 + 1;
      return;
    }
    iVar2 = *DAT_060c7bec;
    *DAT_060c7bec = iVar2 + 1;
    if (iVar2 + 1 == 0x14) {
      *DAT_060c7bf0 = *DAT_060c7bf0 + 1;
    }
    bVar4 = *DAT_060c7be4;
    uVar3 = 2;
  }
  pbVar1 = DAT_060c7be4;
  *(undefined *)(DAT_060c7be8 + (uint)bVar4) = uVar3;
  *pbVar1 = *pbVar1 + 1;
  return;
}



void FUN_060c7bf8(void)

{
  int *piVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte bVar7;
  uint uVar8;
  int iVar9;
  
  puVar2 = PTR_FUN_060c7d10;
  piVar1 = DAT_060c7d0c;
  *DAT_060c7d0c = *DAT_060c7d0c + 1;
  iVar3 = (*(code *)puVar2)();
  if ((iVar3 < *DAT_060c7d14) && (iVar3 = *piVar1, 0x13 < iVar3)) {
    if (iVar3 <= DAT_060c7d08) {
      iVar3 = (*(code *)PTR_FUN_060c7d18)();
      iVar4 = (*(code *)PTR_FUN_060c7d1c)(iVar3,0x32);
      if (iVar3 + iVar4 * -0x32 != 0) {
        return;
      }
    }
    *piVar1 = 0;
    iVar4 = (*(code *)PTR_FUN_060c7d18)();
    puVar2 = PTR_FUN_060c7d1c;
    iVar5 = (*(code *)PTR_FUN_060c7d1c)(iVar4,9);
    iVar3 = DAT_060c7d20;
    iVar4 = iVar4 + iVar5 * -9;
    uVar8 = 7;
    if (*(byte *)(DAT_060c7d20 + iVar4) < 8) {
      do {
        iVar4 = iVar4 + 1;
        iVar5 = (*(code *)puVar2)(iVar4,9);
        iVar4 = iVar4 + iVar5 * -9;
      } while (*(byte *)(iVar3 + iVar4) <= uVar8);
    }
    iVar3 = (*(code *)PTR_FUN_060c7d18)();
    puVar2 = PTR_DAT_060c7d28;
    iVar9 = 7;
    iVar6 = *DAT_060c7d24;
    iVar5 = (*(code *)PTR_FUN_060c7d1c)(iVar3,7);
    bVar7 = puVar2[(iVar3 - iVar5 * iVar9) + iVar6 * 7];
    if (0x1f < *DAT_060c7d2c) {
      bVar7 = 5;
    }
    if (bVar7 < 5) {
      *DAT_060c7d2c = *DAT_060c7d2c + 1;
    }
    else {
      *DAT_060c7d30 = *DAT_060c7d30 + 1;
    }
    (*(code *)PTR_FUN_060c7d34)(iVar4,bVar7,0);
  }
  return;
}



void FUN_060c7d38(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  *(undefined *)(DAT_060c7e0c + param_1) = 0;
  *(char *)(DAT_060c7e10 + param_1) = (char)param_3;
  *(char *)(DAT_060c7e14 + param_1) = (char)param_2;
  iVar1 = (int)(short)((short)param_1 + 99);
  (*(code *)PTR_FUN_060c7e28)
            (iVar1,PTR_DAT_060c7e18[param_3 + param_2 * 8],(int)*DAT_060c7e1c,4,2,(int)*DAT_060c7e24
             ,(int)*DAT_060c7e20);
  (*(code *)PTR_FUN_060c7e30)
            (iVar1,(int)*(short *)(PTR_DAT_060c7e2c + param_1 * 8 + 2),
             (int)*(short *)(PTR_DAT_060c7e2c + param_1 * 8 + 6));
  if (param_3 == 5) {
    switch(param_2) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      iVar1 = (int)DAT_060c7e04;
      break;
    case 5:
      iVar1 = (int)DAT_060c7e06;
      break;
    case 6:
      iVar1 = (int)DAT_060c7e06;
      break;
    case 7:
      iVar1 = (int)DAT_060c7e08;
      break;
    default:
      goto switchD_060c7dc2_caseD_8;
    }
    (*(code *)PTR_FUN_060c7e34)(iVar1);
  }
switchD_060c7dc2_caseD_8:
  return;
}



int FUN_060c7e38(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar4 = 0;
  pbVar1 = DAT_060c7e78;
  pbVar2 = DAT_060c7e74;
  do {
    if ((*pbVar1 < 8) && ((*pbVar2 < 3 || (*pbVar2 == 5)))) {
      iVar3 = iVar3 + 1;
    }
    pbVar2 = pbVar2 + 1;
    iVar4 = iVar4 + 1;
    pbVar1 = pbVar1 + 1;
  } while (iVar4 < 9);
  return iVar3;
}



uint FUN_060c7e7c(void)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  *DAT_060c7f3c = *DAT_060c7f3c + 1;
  bVar1 = *(byte *)(DAT_060c7f48 + *DAT_060c7f40);
  uVar2 = (uint)*(byte *)(DAT_060c7f44 + *DAT_060c7f40);
  if ((uVar2 == 2) && (bVar1 < 8)) {
    uVar2 = (int)&switchD_060c7eb0::switchdataD_060c7eb4 +
            (int)(short)(&switchD_060c7eb0::switchdataD_060c7eb4)[bVar1];
    switch(bVar1) {
    case 0:
      uVar2 = (*(code *)PTR_FUN_060c7f4c)();
      if ((uVar2 & 1) == 0) {
        iVar3 = *DAT_060c7f40;
        uVar4 = 0;
      }
      else {
        iVar3 = *DAT_060c7f40;
        uVar4 = 1;
      }
      break;
    case 1:
      goto switchD_060c7eb0_caseD_1;
    case 2:
      iVar3 = *DAT_060c7f40;
      uVar4 = 2;
      break;
    case 3:
      iVar3 = *DAT_060c7f40;
      uVar4 = 3;
      break;
    case 4:
      iVar3 = *DAT_060c7f40;
      uVar4 = 4;
      break;
    case 5:
      iVar3 = *DAT_060c7f40;
      uVar4 = 5;
      break;
    case 6:
      iVar3 = *DAT_060c7f40;
      uVar4 = 6;
      break;
    case 7:
      iVar3 = *DAT_060c7f40;
      uVar4 = 7;
    }
    uVar2 = (*(code *)PTR_FUN_060c7f50)(iVar3,uVar4,5);
    if (bVar1 < 5) {
      *DAT_060c7f54 = *DAT_060c7f54 + 1;
    }
  }
switchD_060c7eb0_caseD_1:
  return uVar2;
}



void FUN_060c7f58(void)

{
  int *piVar1;
  code *pcVar2;
  
  piVar1 = DAT_060c7fec;
  if (*DAT_060c7fe4 == '\0') {
    (*(code *)PTR_FUN_060c7fe8)((int)DAT_060c7fde);
    *DAT_060c7fec = 0x140;
    pcVar2 = (code *)PTR_FUN_060c7ff0;
  }
  else {
    if (*DAT_060c7fe4 != '\x01') {
      return;
    }
    *DAT_060c7fec = *DAT_060c7fec + -0x10;
    (*(code *)PTR_FUN_060c8000)(0x11,3,(int)*DAT_060c7ff4,7,2,(int)*DAT_060c7ffc,(int)*DAT_060c7ff8)
    ;
    (*(code *)PTR_FUN_060c8004)(0x11,(int)*(short *)((int)piVar1 + 2),0);
    (*(code *)PTR_FUN_060c8008)(5,(int)DAT_060c7fe0,1);
    pcVar2 = (code *)PTR_FUN_060c800c;
    if (*piVar1 != 0) {
      return;
    }
  }
  (*pcVar2)();
  return;
}



void FUN_060c8010(void)

{
  int *piVar1;
  int *piVar2;
  code *pcVar3;
  
  piVar2 = DAT_060c8094;
  piVar1 = DAT_060c8090;
  if (*DAT_060c808c == '\0') {
    *DAT_060c8090 = 0;
    *DAT_060c8094 = 0x98;
    (*(code *)PTR_FUN_060c8098)(0x10);
    pcVar3 = (code *)PTR_FUN_060c809c;
  }
  else {
    if (*DAT_060c808c != '\x01') {
      return;
    }
    *DAT_060c8090 = *DAT_060c8090 + -0x10;
    *piVar2 = *piVar2 + 8;
    (*(code *)PTR_FUN_060c80a0)(0x11,(int)*(short *)((int)piVar1 + 2),0);
    (*(code *)PTR_FUN_060c80a4)(5,*piVar2,1);
    pcVar3 = (code *)PTR_FUN_060c80a8;
    if (*piVar1 != (int)DAT_060c8088) {
      return;
    }
  }
  (*pcVar3)();
  return;
}



void FUN_060c80ac(void)

{
  ushort uVar1;
  int iVar2;
  ushort uVar3;
  code *pcVar4;
  
  iVar2 = DAT_060c81cc;
  uVar3 = (ushort)*(byte *)(DAT_060c81cc + 10);
  if (uVar3 == DAT_060c81b8) {
    (*(code *)PTR_FUN_060c82a0)();
    pcVar4 = (code *)PTR_FUN_060c82a4;
LAB_060c822a:
    (*pcVar4)();
    (*(code *)PTR_FUN_060c82ac)(DAT_060c82a8,0x1e);
    return;
  }
  if ((short)DAT_060c81b8 < (short)uVar3) {
    if (uVar3 == DAT_060c81bc) {
      (*(code *)PTR_FUN_060c82a0)();
      (*(code *)PTR_FUN_060c82b4)(0x14,(int)DAT_060c8296);
      if (0 < *DAT_060c82b8) {
        return;
      }
LAB_060c826c:
      (*(code *)PTR_FUN_060c82c0)();
      return;
    }
    if ((short)DAT_060c81bc < (short)uVar3) {
      if (uVar3 == DAT_060c81c0) {
        (*(code *)PTR_FUN_060c82bc)();
        (*(code *)PTR_FUN_060c82a4)();
        goto LAB_060c826c;
      }
      if (uVar3 == DAT_060c81c2) {
        (*(code *)PTR_FUN_060c82ac)(DAT_060c82a8,0x3c);
        return;
      }
    }
    else {
      uVar1 = DAT_060c8294;
      if (uVar3 == DAT_060c81be) goto LAB_060c823c;
    }
  }
  else {
    if (uVar3 == 1) {
      (*(code *)PTR_FUN_060c81f8)();
      (*(code *)PTR_FUN_060c81fc)(0x14,(int)DAT_060c81ca);
      (*(code *)PTR_FUN_060c8200)();
      (*(code *)PTR_FUN_060c8204)();
      (*(code *)PTR_FUN_060c820c)(*DAT_060c8208);
      if (*DAT_060c8210 < 1) {
        (*(code *)PTR_FUN_060c8214)((int)(short)DAT_060c81bc);
      }
      uVar1 = DAT_060c81ba;
      if (*DAT_060c8218 != 0x1e) {
        return;
      }
LAB_060c823c:
      (*(code *)PTR_FUN_060c82b0)((int)(short)uVar1);
      return;
    }
    if (uVar3 < 2) {
      if (uVar3 == 0) {
        *DAT_060c81d0 = 0;
        *(undefined *)(iVar2 + DAT_060c81c4) = 0;
        *(undefined *)(DAT_060c81c6 + iVar2) = 0;
        (*(code *)PTR_FUN_060c81d4)(2,3,3,4);
        *DAT_060c81d8 = 0;
        *DAT_060c81dc = 0;
        *DAT_060c81e0 = 2;
        (*(code *)PTR_FUN_060c81e4)((int)*(char *)(iVar2 + DAT_060c81c8));
        (*(code *)PTR_FUN_060c81e8)();
        (*(code *)PTR_FUN_060c81f0)(PTR_DAT_060c81ec);
        (*(code *)PTR_FUN_060c81f4)(0,0x1e,1,0xf);
        goto LAB_060c826c;
      }
    }
    else {
      pcVar4 = (code *)PTR_FUN_060c829c;
      if (uVar3 == DAT_060c81ba) goto LAB_060c822a;
    }
  }
  *(undefined *)(DAT_060c81cc + DAT_060c8298) = 1;
  return;
}



void FUN_060c82c4(void)

{
  ushort uVar1;
  int iVar2;
  ushort uVar3;
  code *pcVar4;
  
  iVar2 = DAT_060c83e4;
  uVar3 = (ushort)*(byte *)(DAT_060c83e4 + 10);
  if (uVar3 == DAT_060c83d0) {
    (*(code *)PTR_FUN_060c84b8)();
    pcVar4 = (code *)PTR_FUN_060c84bc;
LAB_060c8442:
    (*pcVar4)();
    (*(code *)PTR_FUN_060c84c4)(DAT_060c84c0,0x1e);
    return;
  }
  if ((short)DAT_060c83d0 < (short)uVar3) {
    if (uVar3 == DAT_060c83d4) {
      (*(code *)PTR_FUN_060c84b8)();
      (*(code *)PTR_FUN_060c84cc)(0x14,(int)DAT_060c84ae);
      if (0 < *DAT_060c84d0) {
        return;
      }
LAB_060c8484:
      (*(code *)PTR_FUN_060c84d8)();
      return;
    }
    if ((short)DAT_060c83d4 < (short)uVar3) {
      if (uVar3 == DAT_060c83d8) {
        (*(code *)PTR_FUN_060c84d4)();
        (*(code *)PTR_FUN_060c84bc)();
        goto LAB_060c8484;
      }
      if (uVar3 == DAT_060c83da) {
        (*(code *)PTR_FUN_060c84c4)(DAT_060c84c0,0x3c);
        return;
      }
    }
    else {
      uVar1 = DAT_060c84ac;
      if (uVar3 == DAT_060c83d6) goto LAB_060c8454;
    }
  }
  else {
    if (uVar3 == 1) {
      (*(code *)PTR_FUN_060c8410)();
      (*(code *)PTR_FUN_060c8414)(0x14,(int)DAT_060c83e2);
      (*(code *)PTR_FUN_060c8418)();
      (*(code *)PTR_FUN_060c841c)();
      (*(code *)PTR_FUN_060c8424)(*DAT_060c8420);
      if (*DAT_060c8428 < 1) {
        (*(code *)PTR_FUN_060c842c)((int)(short)DAT_060c83d4);
      }
      uVar1 = DAT_060c83d2;
      if (*DAT_060c8430 != 0x28) {
        return;
      }
LAB_060c8454:
      (*(code *)PTR_FUN_060c84c8)((int)(short)uVar1);
      return;
    }
    if (uVar3 < 2) {
      if (uVar3 == 0) {
        *DAT_060c83e8 = 0;
        *(undefined *)(iVar2 + DAT_060c83dc) = 0;
        *(undefined *)(DAT_060c83de + iVar2) = 0;
        (*(code *)PTR_FUN_060c83ec)(2,3,3,4);
        *DAT_060c83f0 = 0;
        *DAT_060c83f4 = 0;
        *DAT_060c83f8 = 2;
        (*(code *)PTR_FUN_060c83fc)((int)*(char *)(iVar2 + DAT_060c83e0));
        (*(code *)PTR_FUN_060c8400)();
        (*(code *)PTR_FUN_060c8408)(PTR_DAT_060c8404);
        (*(code *)PTR_FUN_060c840c)(1,0x28,1,0x14);
        goto LAB_060c8484;
      }
    }
    else {
      pcVar4 = (code *)PTR_FUN_060c84b4;
      if (uVar3 == DAT_060c83d2) goto LAB_060c8442;
    }
  }
  *(undefined *)(DAT_060c83e4 + DAT_060c84b0) = 1;
  return;
}



void FUN_060c84dc(void)

{
  ushort uVar1;
  int iVar2;
  ushort uVar3;
  code *pcVar4;
  
  iVar2 = DAT_060c85d8;
  uVar3 = (ushort)*(byte *)(DAT_060c85d8 + 10);
  uVar1 = DAT_060c85d6;
  if (uVar3 == DAT_060c85c2) {
LAB_060c85b8:
    (*(code *)PTR_FUN_060c85fc)((int)(short)uVar1);
    return;
  }
  if ((short)DAT_060c85c2 < (short)uVar3) {
    if (uVar3 != DAT_060c85c6) {
      if ((short)DAT_060c85c6 < (short)uVar3) {
        if (uVar3 == DAT_060c85ca) goto LAB_060c8644;
        goto LAB_060c8650;
      }
      if (uVar3 != DAT_060c85c8) goto LAB_060c8650;
      (*(code *)PTR_FUN_060c8664)();
      (*(code *)PTR_FUN_060c8668)(0x14,(int)DAT_060c8660);
      if (0 < *DAT_060c866c) {
        return;
      }
      goto LAB_060c863a;
    }
    (*(code *)PTR_FUN_060c8670)();
    pcVar4 = (code *)PTR_FUN_060c8674;
  }
  else {
    if (uVar3 == 1) {
      (*(code *)PTR_FUN_060c85ec)();
      (*(code *)PTR_FUN_060c85f0)(0x14,(int)DAT_060c85d2);
      (*(code *)PTR_FUN_060c85f4)();
      if (*DAT_060c85f8 < 1) {
        (*(code *)PTR_FUN_060c85fc)((int)(short)DAT_060c85c8);
      }
      if (*DAT_060c8600 != 4) {
        return;
      }
      (*(code *)PTR_FUN_060c8604)((int)DAT_060c85d4);
      uVar1 = DAT_060c85c4;
      goto LAB_060c85b8;
    }
    if (1 < *(byte *)(DAT_060c85d8 + 10)) {
      if (uVar3 == DAT_060c85c4) {
        (*(code *)PTR_FUN_060c8608)();
        (*(code *)PTR_FUN_060c860c)();
        (*(code *)PTR_FUN_060c8610)(0);
LAB_060c8644:
        (*(code *)PTR_FUN_060c8680)(DAT_060c867c,0x3c);
        return;
      }
LAB_060c8650:
      *(undefined *)(DAT_060c85d8 + DAT_060c8662) = 1;
      return;
    }
    if (uVar3 != 0) goto LAB_060c8650;
    *DAT_060c85dc = 0;
    *(undefined *)(iVar2 + DAT_060c85cc) = 0;
    *(undefined *)(DAT_060c85ce + iVar2) = 0;
    (*(code *)PTR_FUN_060c85e0)(2,3,3,4);
    (*(code *)PTR_FUN_060c85e4)((int)*(char *)(iVar2 + DAT_060c85d0));
    pcVar4 = (code *)PTR_FUN_060c85e8;
  }
  (*pcVar4)();
LAB_060c863a:
  (*(code *)PTR_FUN_060c8678)();
  return;
}



void FUN_060c8684(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  piVar1 = DAT_060c8764;
  switch(*DAT_060c8760) {
  case 0:
    *DAT_060c8764 = 0;
    goto LAB_060c8718;
  case 1:
    (*(code *)PTR_FUN_060c8768)(DAT_060c8764,0x1e);
    break;
  case 2:
    uVar3 = 3;
    goto LAB_060c8714;
  case 3:
    iVar2 = *DAT_060c8764;
    if (iVar2 == 0x14) {
      (*(code *)PTR_FUN_060c8770)((int)DAT_060c875c);
      iVar2 = *piVar1;
    }
    if (iVar2 == 0x19) {
      (*(code *)PTR_FUN_060c8774)(0x28);
    }
    uVar3 = 0x4b;
    goto LAB_060c8744;
  case 4:
    uVar3 = 4;
LAB_060c8714:
    (*(code *)PTR_FUN_060c876c)(0,uVar3,1,5);
LAB_060c8718:
    (*(code *)PTR_FUN_060c8778)();
    break;
  case 5:
    iVar2 = *DAT_060c8764;
    if (iVar2 == 5) {
      (*(code *)PTR_FUN_060c8770)((int)DAT_060c875c);
      iVar2 = *piVar1;
    }
    if (iVar2 == 10) {
      (*(code *)PTR_FUN_060c8774)(0x28);
    }
    uVar3 = 0x3c;
LAB_060c8744:
    (*(code *)PTR_FUN_060c8768)(piVar1,uVar3);
    break;
  case 6:
    (*(code *)PTR_FUN_060c877c)(4);
  }
  return;
}



void FUN_060c8780(void)

{
  ushort uVar1;
  int iVar2;
  ushort uVar3;
  code *pcVar4;
  
  iVar2 = DAT_060c8880;
  uVar3 = (ushort)*(byte *)(DAT_060c8880 + 10);
  if (uVar3 == DAT_060c886c) {
LAB_060c88fc:
    (*(code *)PTR_FUN_060c8940)(DAT_060c893c,0x3c);
    return;
  }
  if ((short)DAT_060c886c < (short)uVar3) {
    if (uVar3 == DAT_060c8870) {
      (*(code *)PTR_FUN_060c8924)();
      (*(code *)PTR_FUN_060c8928)(0x14,(int)DAT_060c891a);
      if (0 < *DAT_060c892c) {
        return;
      }
      goto LAB_060c88f2;
    }
    if ((short)uVar3 <= (short)DAT_060c8870) {
      uVar1 = DAT_060c8918;
      if (uVar3 == DAT_060c8872) goto LAB_060c88c2;
      goto LAB_060c8908;
    }
    if (uVar3 != DAT_060c8874) {
      if (uVar3 == DAT_060c8876) goto LAB_060c88fc;
      goto LAB_060c8908;
    }
    (*(code *)PTR_FUN_060c8930)();
    pcVar4 = (code *)PTR_FUN_060c8934;
  }
  else {
    if (uVar3 == 1) {
      (*(code *)PTR_FUN_060c8898)();
      (*(code *)PTR_FUN_060c889c)(0x14,(int)DAT_060c887e);
      (*(code *)PTR_FUN_060c88a0)();
      (*(code *)PTR_FUN_060c88a4)();
      if (*DAT_060c88a8 < 1) {
        (*(code *)PTR_FUN_060c88ac)((int)(short)DAT_060c8870);
      }
      uVar1 = DAT_060c886e;
      if (*DAT_060c88b0 != 0) {
        return;
      }
LAB_060c88c2:
      (*(code *)PTR_FUN_060c8920)((int)(short)uVar1);
      return;
    }
    if (1 < *(byte *)(DAT_060c8880 + 10)) {
      if (uVar3 == DAT_060c886e) {
        (*(code *)PTR_FUN_060c88b4)();
        (*(code *)PTR_FUN_060c88b8)();
        (*(code *)PTR_FUN_060c88bc)(10);
        goto LAB_060c88f2;
      }
LAB_060c8908:
      *(undefined *)(DAT_060c8880 + DAT_060c891c) = 1;
      return;
    }
    if (uVar3 != 0) goto LAB_060c8908;
    *DAT_060c8884 = 0;
    *(undefined *)(iVar2 + DAT_060c8878) = 0;
    *(undefined *)(DAT_060c887a + iVar2) = 0;
    (*(code *)PTR_FUN_060c8888)(2,5,3,4);
    (*(code *)PTR_FUN_060c888c)((int)*(char *)(iVar2 + DAT_060c887c));
    (*(code *)PTR_FUN_060c8890)();
    pcVar4 = (code *)PTR_FUN_060c8894;
  }
  (*pcVar4)();
LAB_060c88f2:
  (*(code *)PTR_FUN_060c8938)();
  return;
}



void FUN_060c8944(int param_1)

{
  undefined4 uVar1;
  
  (*(code *)PTR_FUN_060c8998)((int)DAT_060c8996);
  *DAT_060c899c = 0x10;
  if (param_1 == 0) {
    uVar1 = 5;
  }
  else {
    uVar1 = 6;
  }
  (*(code *)PTR_FUN_060c89a0)(10,uVar1,1,6,0xff,0,0);
  return;
}



void FUN_060c89a4(void)

{
  int iVar1;
  
  if ((*DAT_060c89cc != 0) && (iVar1 = *DAT_060c89cc + -1, *DAT_060c89cc = iVar1, iVar1 == 1)) {
    (*(code *)PTR_FUN_060c89d0)(0x28);
  }
  return;
}



void FUN_060c89d4(void)

{
  *DAT_060c89f4 = 3;
  *DAT_060c89f8 = 5;
  *DAT_060c89fc = 8;
  *DAT_060c8a00 = 0;
  return;
}



uint FUN_060c8a04(void)

{
  uint *puVar1;
  uint in_r0;
  int iVar2;
  int iVar3;
  code *pcVar4;
  uint uVar5;
  undefined4 uVar6;
  bool bVar7;
  uint *puVar8;
  uint *puVar9;
  
  puVar1 = DAT_060c8e70;
  puVar9 = DAT_060c8c18;
  puVar8 = DAT_060c8b28;
  iVar3 = DAT_060c8b24;
  uVar5 = *DAT_060c8b20;
  if (8 < uVar5) goto LAB_060c8eb6;
  in_r0 = (int)&switchD_060c8a28::switchdataD_060c8a2c +
          (int)(short)(&switchD_060c8a28::switchdataD_060c8a2c)[uVar5];
  switch(uVar5) {
  case 0:
    if ((int)*DAT_060c8b28 < 0x1e) goto LAB_060c8eb6;
    if ((int)*DAT_060c8b28 <= (int)DAT_060c8b1a) {
      iVar3 = (*(code *)PTR_FUN_060c8b2c)();
      in_r0 = (*(code *)PTR_FUN_060c8b30)(iVar3,0x32);
      if (iVar3 + in_r0 * -0x32 != 0) goto LAB_060c8eb6;
    }
    iVar2 = (*(code *)PTR_FUN_060c8b2c)();
    iVar3 = (*(code *)PTR_FUN_060c8b30)(iVar2,3);
    iVar2 = iVar2 + iVar3 * -3;
    if (iVar2 == 1) {
      uVar5 = 3;
LAB_060c8ab8:
      *DAT_060c8b20 = uVar5;
    }
    else if (iVar2 < 2) {
      if (iVar2 == 0) {
        uVar5 = 2;
        goto LAB_060c8ab8;
      }
    }
    else {
      uVar5 = 4;
      if (iVar2 == 2) goto LAB_060c8ab8;
    }
    in_r0 = (*(code *)PTR_FUN_060c8b34)((int)DAT_060c8b1c);
    *DAT_060c8b28 = 0;
    goto LAB_060c8eb6;
  case 1:
    if (*DAT_060c8b38 != 3) {
      in_r0 = *DAT_060c8c18;
      if (in_r0 == 1) {
        (*(code *)PTR_FUN_060c8c1c)(0,0x14,in_r0 == 1,5,2,0,0);
        in_r0 = (*(code *)PTR_FUN_060c8c20)((int)DAT_060c8c16);
      }
      if ((int)*puVar9 < 0x1e) goto LAB_060c8eb6;
      goto LAB_060c8d40;
    }
    in_r0 = *DAT_060c8b28;
    if (in_r0 == 1) {
      (*(code *)PTR_FUN_060c8b3c)(0,0x13,in_r0 == 1,5,2,0,0);
      in_r0 = (*(code *)PTR_FUN_060c8b34)((int)DAT_060c8b1e);
    }
    uVar5 = *puVar8;
    iVar3 = 0x1d;
    goto LAB_060c8afc;
  case 2:
    if (*DAT_060c8c18 == 1) {
      if (*DAT_060c8c24 == 1) {
        uVar6 = 8;
      }
      else {
        uVar6 = 7;
      }
      (*(code *)PTR_FUN_060c8c1c)(0,uVar6,1,5,2,0,0);
      *DAT_060c8c24 = 3;
    }
    puVar8 = DAT_060c8c18;
    in_r0 = *DAT_060c8c18;
    if (in_r0 == 0x3e) {
      in_r0 = (*(code *)PTR_FUN_060c8c28)(0);
    }
    if (*puVar8 - 0xc < 0x47) {
      in_r0 = *DAT_060c8c2c;
      if (in_r0 == 1) {
        *DAT_060c8c30 = *DAT_060c8c30 + -1;
        *DAT_060c8c34 = (uint)(in_r0 == 1);
        *puVar8 = 0;
      }
    }
    uVar5 = *DAT_060c8c18;
    iVar3 = 0x51;
    puVar8 = DAT_060c8c18;
LAB_060c8afc:
    if (iVar3 < (int)uVar5) {
      uVar5 = (*(code *)PTR_FUN_060c8b2c)();
      in_r0 = uVar5 & 1;
      if (in_r0 == 0) {
LAB_060c8ca2:
        *puVar8 = 0;
        *DAT_060c8e80 = 5;
      }
      else {
        *puVar8 = 0;
LAB_060c8cae:
        *DAT_060c8e80 = 6;
      }
    }
    goto LAB_060c8eb6;
  case 3:
    if (*DAT_060c8c18 == 1) {
      if (*DAT_060c8c24 == 1) {
        uVar6 = 0xc;
        pcVar4 = (code *)PTR_FUN_060c8c1c;
      }
      else {
        uVar6 = 0xb;
        pcVar4 = (code *)PTR_FUN_060c8e68;
      }
      (*pcVar4)(0,uVar6,1,5,2,0,0);
      *DAT_060c8e6c = 3;
    }
    puVar8 = DAT_060c8e70;
    in_r0 = *DAT_060c8e70;
    if (in_r0 == 0x38) {
      in_r0 = (*(code *)PTR_FUN_060c8e74)(0);
    }
    if (*puVar8 - 6 < 0x47) {
      in_r0 = *DAT_060c8e78;
      if (in_r0 == 1) {
        *DAT_060c8e7c = *DAT_060c8e7c + -1;
        *DAT_060c8e80 = (uint)(in_r0 == 1);
        *puVar8 = 0;
      }
    }
    puVar8 = DAT_060c8e70;
    if ((int)*DAT_060c8e70 < 0x4c) goto LAB_060c8eb6;
    uVar5 = (*(code *)PTR_FUN_060c8e84)();
    in_r0 = uVar5 & 1;
    if (in_r0 != 0) {
      *puVar8 = 0;
      goto LAB_060c8cae;
    }
    goto LAB_060c8ca2;
  case 4:
    if (*DAT_060c8e70 == 1) {
      if (*DAT_060c8e6c == 1) {
        uVar6 = 10;
      }
      else {
        uVar6 = 9;
      }
      (*(code *)PTR_FUN_060c8e68)(0,uVar6,1,5,2,0,0);
      *DAT_060c8e6c = 4;
    }
    puVar8 = DAT_060c8e70;
    in_r0 = *DAT_060c8e70;
    if (in_r0 == 0x38) {
      in_r0 = (*(code *)PTR_FUN_060c8e74)(in_r0 == 0x38);
    }
    if (*puVar8 - 6 < 0x47) {
      in_r0 = *DAT_060c8e78;
      if (in_r0 == 4) {
        *DAT_060c8e7c = *DAT_060c8e7c + -1;
        *DAT_060c8e80 = (uint)(in_r0 == 4);
        *puVar8 = 0;
      }
    }
    puVar9 = DAT_060c8e70;
    if ((int)*DAT_060c8e70 < 0x4c) goto LAB_060c8eb6;
    uVar5 = (*(code *)PTR_FUN_060c8e84)();
    in_r0 = uVar5 & 1;
LAB_060c8d40:
    *puVar9 = 0;
    *DAT_060c8e80 = 7;
    goto LAB_060c8eb6;
  case 5:
    in_r0 = *DAT_060c8e70;
    if (in_r0 == 5) {
      (*(code *)PTR_FUN_060c8e88)((int)DAT_060c8e64);
      in_r0 = *puVar1;
    }
    if (in_r0 == 1) {
      uVar5 = (*(code *)PTR_FUN_060c8e84)();
      bVar7 = (uVar5 & 1) == 0;
      if (bVar7) {
        *DAT_060c8e6c = (uint)bVar7;
        uVar6 = 0xe;
      }
      else {
        *DAT_060c8e6c = 2;
        bVar7 = true;
        uVar6 = 0xd;
      }
LAB_060c8e4a:
      in_r0 = (*(code *)PTR_FUN_060c8e68)(0,uVar6,bVar7,5,2,0,0);
    }
    break;
  case 6:
    in_r0 = *DAT_060c8e70;
    if (in_r0 == 5) {
      (*(code *)PTR_FUN_060c8e88)((int)DAT_060c8e64);
      in_r0 = *puVar1;
    }
    if (in_r0 == 1) {
      uVar5 = (*(code *)PTR_FUN_060c8e84)();
      bVar7 = (uVar5 & 1) == 0;
      if (bVar7) {
        *DAT_060c8e6c = (uint)bVar7;
        uVar6 = 0x12;
      }
      else {
        *DAT_060c8e6c = 2;
        bVar7 = true;
        uVar6 = 0x11;
      }
      goto LAB_060c8e4a;
    }
    break;
  case 7:
    in_r0 = *DAT_060c8e70;
    if (in_r0 == 5) {
      (*(code *)PTR_FUN_060c8e88)((int)DAT_060c8e64);
      in_r0 = *puVar1;
    }
    if (in_r0 == 1) {
      uVar5 = (*(code *)PTR_FUN_060c8e84)();
      bVar7 = (uVar5 & 1) == 0;
      if (bVar7) {
        *DAT_060c8e6c = (uint)bVar7;
        uVar6 = 0x10;
      }
      else {
        *DAT_060c8e6c = 2;
        bVar7 = true;
        uVar6 = 0xf;
      }
      goto LAB_060c8e4a;
    }
    break;
  case 8:
    (*(code *)PTR_FUN_060c8f04)(0,0xc,1,5,2,0,0);
    in_r0 = (uint)DAT_060c8f02;
    *(undefined2 *)(iVar3 + in_r0) = 2;
    *DAT_060c8f08 = 3;
    *DAT_060c8f0c = 6;
    goto LAB_060c8eb6;
  }
  puVar8 = DAT_060c8e70;
  if (9 < (int)*DAT_060c8e70) {
    *DAT_060c8e80 = 0;
    *puVar8 = 0;
  }
LAB_060c8eb6:
  *DAT_060c8f0c = *DAT_060c8f0c + 1;
  if (*DAT_060c8f10 == 0) {
    if (*DAT_060c8f14 == 3) {
      uVar6 = 0x15;
    }
    else {
      uVar6 = 0x16;
    }
    in_r0 = (*(code *)PTR_FUN_060c8f04)(0,uVar6,1,5,2,0,0);
  }
  return in_r0;
}



void FUN_060c8f18(void)

{
  ushort uVar2;
  int iVar1;
  uint uVar3;
  
  iVar1 = DAT_060c9004;
  uVar2 = (ushort)*(byte *)(DAT_060c9004 + 10);
  if (uVar2 == DAT_060c8ff6) {
    (*(code *)PTR_FUN_060c902c)(0);
    (*(code *)PTR_FUN_060c9030)();
    (*(code *)PTR_FUN_060c9034)();
LAB_060c9070:
    iVar1 = (int)DAT_060c9090;
LAB_060c9072:
    (*(code *)PTR_FUN_060c90b0)(iVar1);
  }
  else {
    if ((short)DAT_060c8ff6 < (short)uVar2) {
      if (uVar2 != DAT_060c8ff8) {
        if (uVar2 != DAT_060c8ffa) goto LAB_060c907c;
        (*(code *)PTR_FUN_060c90a4)();
        (*(code *)PTR_FUN_060c90a8)();
        (*(code *)PTR_FUN_060c90ac)(0);
        *(undefined *)(iVar1 + DAT_060c908e) = 6;
        goto LAB_060c9070;
      }
      (*(code *)PTR_FUN_060c9094)();
      (*(code *)PTR_FUN_060c9098)(0x14,(int)DAT_060c908c);
      if (0 < *DAT_060c909c) {
        return;
      }
    }
    else {
      if (uVar2 != 0) {
        if (uVar2 != 1) {
LAB_060c907c:
          *(undefined *)(DAT_060c9004 + DAT_060c9092) = 1;
          return;
        }
        (*(code *)PTR_FUN_060c901c)();
        (*(code *)PTR_FUN_060c9020)(0x14,(int)DAT_060c9002);
        uVar3 = *DAT_060c9008;
        *DAT_060c9008 = uVar3 + 1;
        if ((uVar3 + 1 & 1) == 0) {
          *DAT_060c9024 = *DAT_060c9024 + -1;
        }
        iVar1 = *DAT_060c9028;
        if (((iVar1 == 1) || (iVar1 == 4)) || (iVar1 == 7)) {
          *DAT_060c900c = 1;
        }
        if (0 < *DAT_060c9024) {
          return;
        }
        if (*DAT_060c900c == 1) {
          iVar1 = (int)(short)DAT_060c8ff6;
        }
        else {
          iVar1 = (int)(short)DAT_060c8ff8;
        }
        goto LAB_060c9072;
      }
      *(undefined *)(DAT_060c9004 + DAT_060c8ffc) = 0;
      *(undefined *)(DAT_060c8ffe + iVar1) = 0;
      *DAT_060c9008 = 0;
      *DAT_060c900c = 0;
      (*(code *)PTR_FUN_060c9010)(2,3,3,4);
      (*(code *)PTR_FUN_060c9014)((int)*(char *)(iVar1 + DAT_060c9000));
      (*(code *)PTR_FUN_060c9018)();
    }
    (*(code *)PTR_FUN_060c90a0)();
  }
  return;
}



void FUN_060c90b4(void)

{
  int iVar1;
  uint uVar2;
  code *pcVar3;
  uint uVar4;
  
  iVar1 = DAT_060c91cc;
  uVar4 = (uint)DAT_060c91b8;
  uVar2 = (uint)*(byte *)(DAT_060c91cc + 10);
  if (uVar2 == uVar4) {
    (*(code *)PTR_FUN_060c91f8)(0,0,uVar2 == uVar4,5,2,0,0);
    (*(code *)PTR_FUN_060c91fc)(0,0xffffffc4,0);
    (*(code *)PTR_FUN_060c9200)();
    (*(code *)PTR_FUN_060c9204)();
    (*(code *)PTR_FUN_060c91f0)((int)DAT_060c91c8);
    return;
  }
  if ((int)uVar4 < (int)uVar2) {
    if (uVar2 != (int)DAT_060c91ba) {
      if ((int)DAT_060c91ba < (int)uVar2) {
        if (uVar2 == (int)DAT_060c91be) {
          (*(code *)PTR_FUN_060c9254)(DAT_060c9250,0x3c);
          return;
        }
LAB_060c922e:
        *(undefined *)(DAT_060c91cc + DAT_060c9240) = 1;
        return;
      }
      if (uVar2 != (int)DAT_060c91bc) goto LAB_060c922e;
      (*(code *)PTR_FUN_060c9200)();
      (*(code *)PTR_FUN_060c91e4)(0x14,(int)DAT_060c91c6);
      if (0 < *DAT_060c9208) {
        return;
      }
      goto LAB_060c9218;
    }
    (*(code *)PTR_FUN_060c9244)();
    pcVar3 = (code *)PTR_FUN_060c9248;
  }
  else {
    if (uVar2 != 0) {
      if (uVar2 == 1) {
        (*(code *)PTR_FUN_060c91e0)();
        (*(code *)PTR_FUN_060c91e4)(0x14,(int)DAT_060c91c6);
        (*(code *)PTR_FUN_060c91e8)();
        if (*DAT_060c91ec < 1) {
          (*(code *)PTR_FUN_060c91f0)((int)DAT_060c91bc);
        }
        if (*DAT_060c91f4 != 1) {
          return;
        }
        (*(code *)PTR_FUN_060c91f0)(uVar4);
        return;
      }
      goto LAB_060c922e;
    }
    *DAT_060c91d0 = 0;
    *(undefined *)(iVar1 + DAT_060c91c0) = 0;
    *(undefined *)(DAT_060c91c2 + iVar1) = 0;
    (*(code *)PTR_FUN_060c91d4)(2,3,3,4);
    (*(code *)PTR_FUN_060c91d8)((int)*(char *)(iVar1 + DAT_060c91c4));
    pcVar3 = (code *)PTR_FUN_060c91dc;
  }
  (*pcVar3)();
LAB_060c9218:
  (*(code *)PTR_FUN_060c924c)();
  return;
}



void FUN_060c9258(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_060c9304;
  switch(*DAT_060c9300) {
  case 0:
    *DAT_060c9304 = 0;
    goto LAB_060c92b8;
  case 1:
    (*(code *)PTR_FUN_060c9308)(DAT_060c9304,0x14);
    break;
  case 2:
    (*(code *)PTR_FUN_060c930c)(0,2,1,5);
    (*(code *)PTR_FUN_060c9310)(0,0xffffffc4,0);
LAB_060c92b8:
    (*(code *)PTR_FUN_060c9314)();
    break;
  case 3:
    iVar2 = *DAT_060c9304;
    if (iVar2 == 0x14) {
      (*(code *)PTR_FUN_060c9318)((int)DAT_060c92fc);
      iVar2 = *piVar1;
    }
    if (iVar2 == 0x1e) {
      (*(code *)PTR_FUN_060c931c)(0x28);
    }
    (*(code *)PTR_FUN_060c9308)(piVar1,0x37);
    break;
  case 4:
    (*(code *)PTR_FUN_060c9320)(2);
  }
  return;
}



void FUN_060c9324(void)

{
  short sVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  ushort uVar5;
  
  piVar4 = DAT_060c9440;
  iVar3 = DAT_060c943c;
  uVar5 = (ushort)*(byte *)(DAT_060c943c + 10);
  if (uVar5 == DAT_060c942a) {
LAB_060c94fe:
    (*(code *)PTR_FUN_060c9560)(DAT_060c9550,0x3c);
    return;
  }
  if ((short)DAT_060c942a < (short)uVar5) {
    if (uVar5 != DAT_060c942e) {
      if ((short)DAT_060c942e < (short)uVar5) {
        if (uVar5 == DAT_060c9432) {
          (*(code *)PTR_FUN_060c9558)();
          (*(code *)PTR_FUN_060c954c)();
          goto LAB_060c94f4;
        }
        if (uVar5 == DAT_060c9434) goto LAB_060c94fe;
      }
      else {
        sVar1 = DAT_060c9522;
        if (uVar5 == DAT_060c9430) goto LAB_060c94be;
      }
LAB_060c950a:
      *(undefined *)(DAT_060c943c + DAT_060c9524) = 1;
      return;
    }
    *DAT_060c9550 = 0;
    (*(code *)PTR_FUN_060c9548)();
    (*(code *)PTR_FUN_060c952c)(0x14,(int)DAT_060c951c);
    if (0 < *DAT_060c9554) {
      return;
    }
  }
  else if (uVar5 == 1) {
    *DAT_060c9440 = *DAT_060c9440 + 4;
    (*(code *)PTR_FUN_060c9450)(0,4,uVar5 == 1,5);
    (*(code *)PTR_FUN_060c9454)(0,(int)*(short *)((int)piVar4 + 2),0);
    if (*piVar4 < 0x6d) {
      return;
    }
  }
  else if (uVar5 < 2) {
    if (uVar5 != 0) goto LAB_060c950a;
    *DAT_060c9440 = 0;
    *(undefined *)(iVar3 + DAT_060c9436) = 0;
    *(undefined *)(DAT_060c9438 + iVar3) = 0;
    (*(code *)PTR_FUN_060c9444)(2,3,3,4);
    (*(code *)PTR_FUN_060c9448)((int)*(char *)(iVar3 + DAT_060c943a));
    (*(code *)PTR_FUN_060c944c)();
    (*(code *)PTR_FUN_060c9450)(1,9,1,5);
    (*(code *)PTR_FUN_060c9454)(1,0xffffffdc,0x10);
  }
  else {
    if (uVar5 == 2) {
      (*(code *)PTR_FUN_060c9528)();
      (*(code *)PTR_FUN_060c952c)(0x14,(int)DAT_060c951c);
      (*(code *)PTR_FUN_060c9530)();
      if (*DAT_060c9534 < 1) {
        (*(code *)PTR_FUN_060c9538)((int)DAT_060c951e);
      }
      sVar1 = DAT_060c9520;
      if (*DAT_060c953c != 6) {
        return;
      }
LAB_060c94be:
      (*(code *)PTR_FUN_060c9538)((int)sVar1);
      return;
    }
    bVar2 = uVar5 == DAT_060c942c;
    if (!bVar2) goto LAB_060c950a;
    (*(code *)PTR_FUN_060c9540)(bVar2,0xc,bVar2,5);
    (*(code *)PTR_FUN_060c9544)(1,0xffffffdc,0x10);
    (*(code *)PTR_FUN_060c9548)();
    (*(code *)PTR_FUN_060c954c)();
    *DAT_060c9550 = 0;
  }
LAB_060c94f4:
  (*(code *)PTR_FUN_060c955c)();
  return;
}



void FUN_060c9564(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_060c9610;
  switch(*DAT_060c960c) {
  case 0:
    *DAT_060c9610 = 0;
    goto LAB_060c95c6;
  case 1:
    (*(code *)PTR_FUN_060c9614)(DAT_060c9610,0x14);
    break;
  case 2:
    (*(code *)PTR_FUN_060c9618)(1,10,1,5);
    (*(code *)PTR_FUN_060c961c)(1,0xffffffdc,0x10);
LAB_060c95c6:
    (*(code *)PTR_FUN_060c9620)();
    break;
  case 3:
    iVar2 = *DAT_060c9610;
    if (iVar2 == 0xf) {
      (*(code *)PTR_FUN_060c9624)((int)DAT_060c960a);
      iVar2 = *piVar1;
    }
    if (iVar2 == 0x19) {
      (*(code *)PTR_FUN_060c9628)(0x28);
    }
    (*(code *)PTR_FUN_060c9614)(piVar1,0x32);
    break;
  case 4:
    (*(code *)PTR_FUN_060c962c)(2);
  }
  return;
}



void FUN_060c9630(void)

{
  ushort uVar1;
  int iVar2;
  ushort uVar3;
  code *pcVar4;
  
  iVar2 = DAT_060c9750;
  uVar3 = (ushort)*(byte *)(DAT_060c9750 + 10);
  if (uVar3 == DAT_060c973a) {
    (*(code *)PTR_FUN_060c9820)();
    pcVar4 = (code *)PTR_FUN_060c9824;
LAB_060c97ae:
    (*pcVar4)();
    (*(code *)PTR_FUN_060c982c)(DAT_060c9828,0x1e);
    return;
  }
  if ((short)DAT_060c973a < (short)uVar3) {
    if (uVar3 == DAT_060c973e) {
      (*(code *)PTR_FUN_060c9820)();
      (*(code *)PTR_FUN_060c9834)(0x14,(int)DAT_060c9818);
      if (0 < *DAT_060c9838) {
        return;
      }
LAB_060c97f0:
      (*(code *)PTR_FUN_060c9840)();
      return;
    }
    if ((short)DAT_060c973e < (short)uVar3) {
      if (uVar3 == DAT_060c9742) {
        (*(code *)PTR_FUN_060c983c)();
        (*(code *)PTR_FUN_060c9824)();
        goto LAB_060c97f0;
      }
      if (uVar3 == DAT_060c9744) {
        (*(code *)PTR_FUN_060c982c)(DAT_060c9828,0x3c);
        return;
      }
    }
    else {
      uVar1 = DAT_060c9816;
      if (uVar3 == DAT_060c9740) goto LAB_060c97c0;
    }
  }
  else {
    if (uVar3 == 1) {
      (*(code *)PTR_FUN_060c977c)();
      (*(code *)PTR_FUN_060c9780)(0x14,(int)DAT_060c974c);
      (*(code *)PTR_FUN_060c9784)();
      (*(code *)PTR_FUN_060c9788)();
      (*(code *)PTR_FUN_060c9790)(*DAT_060c978c);
      if (*DAT_060c9794 < 1) {
        (*(code *)PTR_FUN_060c9798)((int)(short)DAT_060c973e);
      }
      uVar1 = DAT_060c973c;
      if (*DAT_060c979c != 0x28) {
        return;
      }
LAB_060c97c0:
      (*(code *)PTR_FUN_060c9830)((int)(short)uVar1);
      return;
    }
    if (*(byte *)(DAT_060c9750 + 10) < 2) {
      if (uVar3 == 0) {
        *DAT_060c9754 = 0;
        *(undefined *)(iVar2 + DAT_060c9746) = 0;
        *(undefined *)(DAT_060c9748 + iVar2) = 0;
        (*(code *)PTR_FUN_060c9758)(3,3,3,4);
        *DAT_060c975c = 1;
        *DAT_060c9760 = 1;
        *DAT_060c9764 = 2;
        (*(code *)PTR_FUN_060c9768)((int)*(char *)(iVar2 + DAT_060c974a));
        (*(code *)PTR_FUN_060c976c)();
        (*(code *)PTR_FUN_060c9774)(PTR_DAT_060c9770);
        (*(code *)PTR_FUN_060c9778)(2,0x28,2,0x14);
        goto LAB_060c97f0;
      }
    }
    else {
      pcVar4 = (code *)PTR_FUN_060c981c;
      if (uVar3 == DAT_060c973c) goto LAB_060c97ae;
    }
  }
  *(undefined *)(DAT_060c9750 + DAT_060c981a) = 1;
  return;
}



void FUN_060c9844(void)

{
  ushort uVar1;
  int iVar2;
  ushort uVar3;
  code *pcVar4;
  
  iVar2 = DAT_060c9964;
  uVar3 = (ushort)*(byte *)(DAT_060c9964 + 10);
  if (uVar3 == DAT_060c994e) {
    (*(code *)PTR_FUN_060c9a34)();
    pcVar4 = (code *)PTR_FUN_060c9a38;
LAB_060c99c2:
    (*pcVar4)();
    (*(code *)PTR_FUN_060c9a40)(DAT_060c9a3c,0x1e);
    return;
  }
  if ((short)DAT_060c994e < (short)uVar3) {
    if (uVar3 == DAT_060c9952) {
      (*(code *)PTR_FUN_060c9a34)();
      (*(code *)PTR_FUN_060c9a48)(0x14,(int)DAT_060c9a2c);
      if (0 < *DAT_060c9a4c) {
        return;
      }
LAB_060c9a04:
      (*(code *)PTR_FUN_060c9a54)();
      return;
    }
    if ((short)DAT_060c9952 < (short)uVar3) {
      if (uVar3 == DAT_060c9956) {
        (*(code *)PTR_FUN_060c9a50)();
        (*(code *)PTR_FUN_060c9a38)();
        goto LAB_060c9a04;
      }
      if (uVar3 == DAT_060c9958) {
        (*(code *)PTR_FUN_060c9a40)(DAT_060c9a3c,0x3c);
        return;
      }
    }
    else {
      uVar1 = DAT_060c9a2a;
      if (uVar3 == DAT_060c9954) goto LAB_060c99d4;
    }
  }
  else {
    if (uVar3 == 1) {
      (*(code *)PTR_FUN_060c9990)();
      (*(code *)PTR_FUN_060c9994)(0x14,(int)DAT_060c9960);
      (*(code *)PTR_FUN_060c9998)();
      (*(code *)PTR_FUN_060c999c)();
      (*(code *)PTR_FUN_060c99a4)(*DAT_060c99a0);
      if (*DAT_060c99a8 < 1) {
        (*(code *)PTR_FUN_060c99ac)((int)(short)DAT_060c9952);
      }
      uVar1 = DAT_060c9950;
      if (*DAT_060c99b0 != 0x32) {
        return;
      }
LAB_060c99d4:
      (*(code *)PTR_FUN_060c9a44)((int)(short)uVar1);
      return;
    }
    if (*(byte *)(DAT_060c9964 + 10) < 2) {
      if (uVar3 == 0) {
        *DAT_060c9968 = 0;
        *(undefined *)(iVar2 + DAT_060c995a) = 0;
        *(undefined *)(DAT_060c995c + iVar2) = 0;
        (*(code *)PTR_FUN_060c996c)(3,3,3,4);
        *DAT_060c9970 = 1;
        *DAT_060c9974 = 1;
        *DAT_060c9978 = 2;
        (*(code *)PTR_FUN_060c997c)((int)*(char *)(iVar2 + DAT_060c995e));
        (*(code *)PTR_FUN_060c9980)();
        (*(code *)PTR_FUN_060c9988)(PTR_DAT_060c9984);
        (*(code *)PTR_FUN_060c998c)(3,0x32,2,0x19);
        goto LAB_060c9a04;
      }
    }
    else {
      pcVar4 = (code *)PTR_FUN_060c9a30;
      if (uVar3 == DAT_060c9950) goto LAB_060c99c2;
    }
  }
  *(undefined *)(DAT_060c9964 + DAT_060c9a2e) = 1;
  return;
}



void FUN_060c9a58(void)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  undefined *puVar4;
  ushort uVar5;
  
  iVar3 = DAT_060c9b6c;
  uVar5 = (ushort)*(byte *)(DAT_060c9b6c + 10);
  if (uVar5 == DAT_060c9b54) {
LAB_060c9bfa:
    (*(code *)PTR_FUN_060c9c40)(DAT_060c9c3c,0x3c);
    return;
  }
  if ((short)DAT_060c9b54 < (short)uVar5) {
    if (uVar5 == DAT_060c9b58) {
      (*(code *)PTR_FUN_060c9c20)();
      (*(code *)PTR_FUN_060c9c24)(0x14,(int)DAT_060c9c18);
      if (0 < *DAT_060c9c28) {
        return;
      }
      goto LAB_060c9bf0;
    }
    if ((short)DAT_060c9b58 < (short)uVar5) {
      if (uVar5 == DAT_060c9b5c) {
        (*(code *)PTR_FUN_060c9c2c)();
        (*(code *)PTR_FUN_060c9c30)();
        puVar4 = PTR_FUN_060c9c34;
        (*(code *)PTR_FUN_060c9c34)(0);
        (*(code *)puVar4)(1);
        (*(code *)puVar4)(2);
        (*(code *)puVar4)(3);
        (*(code *)puVar4)(4);
        goto LAB_060c9bf0;
      }
      if (uVar5 == DAT_060c9b5e) goto LAB_060c9bfa;
    }
    else {
      uVar1 = DAT_060c9c16;
      if (uVar5 == DAT_060c9b5a) goto LAB_060c9baa;
    }
    goto LAB_060c9c06;
  }
  if (uVar5 == 1) {
    (*(code *)PTR_FUN_060c9b80)();
    (*(code *)PTR_FUN_060c9b84)(0x14,(int)DAT_060c9b66);
    (*(code *)PTR_FUN_060c9b88)();
    if (*DAT_060c9b8c < 1) {
      (*(code *)PTR_FUN_060c9b90)((int)(short)DAT_060c9b58);
    }
    uVar1 = DAT_060c9b56;
    if (*DAT_060c9b94 != 5) {
      return;
    }
LAB_060c9baa:
    (*(code *)PTR_FUN_060c9c1c)((int)(short)uVar1);
    return;
  }
  if (*(byte *)(DAT_060c9b6c + 10) < 2) {
    if (uVar5 == 0) {
      *DAT_060c9b70 = 0;
      *(undefined *)(iVar3 + DAT_060c9b60) = 0;
      *(undefined *)(DAT_060c9b62 + iVar3) = 0;
      (*(code *)PTR_FUN_060c9b74)(2,2,3,4);
      (*(code *)PTR_FUN_060c9b78)((int)*(char *)(iVar3 + DAT_060c9b64));
      (*(code *)PTR_FUN_060c9b7c)();
LAB_060c9bf0:
      (*(code *)PTR_FUN_060c9c38)();
      return;
    }
  }
  else {
    bVar2 = uVar5 == DAT_060c9b56;
    if (bVar2) {
      (*(code *)PTR_FUN_060c9b98)(bVar2,7,bVar2,5);
      (*(code *)PTR_FUN_060c9b9c)();
      (*(code *)PTR_FUN_060c9ba0)();
      (*(code *)PTR_FUN_060c9ba4)((int)DAT_060c9b68);
      goto LAB_060c9bf0;
    }
  }
LAB_060c9c06:
  *(undefined *)(DAT_060c9b6c + DAT_060c9c1a) = 1;
  return;
}



void FUN_060c9c44(void)

{
  int *piVar1;
  
  piVar1 = DAT_060c9cfc;
  switch(*DAT_060c9cf8) {
  case 0:
    *DAT_060c9cfc = 0;
    goto LAB_060c9cc2;
  case 1:
    (*(code *)PTR_FUN_060c9d00)(1,4,1,5);
    goto LAB_060c9cc2;
  case 2:
    (*(code *)PTR_FUN_060c9d04)(DAT_060c9cfc,100);
    break;
  case 3:
    (*(code *)PTR_FUN_060c9d00)(10,6,1,6);
    (*(code *)PTR_FUN_060c9d08)((int)DAT_060c9cf6);
LAB_060c9cc2:
    (*(code *)PTR_FUN_060c9d0c)();
    break;
  case 4:
    if (*DAT_060c9cfc == 7) {
      (*(code *)PTR_FUN_060c9d10)(0x28);
    }
    (*(code *)PTR_FUN_060c9d04)(piVar1,0x2d);
    break;
  case 5:
    (*(code *)PTR_FUN_060c9d14)(3);
  }
  return;
}



uint FUN_060c9d18(void)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  
  iVar5 = DAT_060c9e0c;
  uVar2 = (uint)*(byte *)(DAT_060c9e0c + 10);
  if (uVar2 != (int)DAT_060c9df8) {
    if ((int)DAT_060c9df8 < (int)uVar2) {
      if (uVar2 != (int)DAT_060c9dfc) {
        if ((int)DAT_060c9dfc < (int)uVar2) {
          if (uVar2 == (int)DAT_060c9e00) {
            uVar2 = (*(code *)PTR_FUN_060c9f6c)(DAT_060c9f40,0x3c);
            return uVar2;
          }
        }
        else if (uVar2 == (int)DAT_060c9dfe) {
          (*(code *)PTR_FUN_060c9f54)();
          uVar2 = (*(code *)PTR_FUN_060c9f58)(0x14,(int)DAT_060c9f3a);
          if (0 < *DAT_060c9f5c) {
            return uVar2;
          }
          goto LAB_060c9f10;
        }
        goto LAB_060c9f26;
      }
      (*(code *)PTR_FUN_060c9f60)();
      pcVar4 = (code *)PTR_FUN_060c9f64;
LAB_060c9f0c:
      (*pcVar4)();
LAB_060c9f10:
      uVar2 = (*(code *)PTR_FUN_060c9f68)();
      return uVar2;
    }
    if (uVar2 != 1) {
      if (1 < uVar2) {
        if (uVar2 != (int)DAT_060c9dfa) goto LAB_060c9f26;
        (*(code *)PTR_FUN_060c9e38)();
        (*(code *)PTR_FUN_060c9e3c)();
        (*(code *)PTR_FUN_060c9e40)((int)DAT_060c9e0a);
        goto LAB_060c9f10;
      }
      if (uVar2 != 0) {
LAB_060c9f26:
        uVar2 = (uint)DAT_060c9f3c;
        *(undefined *)(DAT_060c9e0c + uVar2) = 1;
        return uVar2;
      }
      *DAT_060c9e10 = 0;
      *(undefined *)(iVar5 + DAT_060c9e02) = 0;
      *(undefined *)(DAT_060c9e04 + iVar5) = 0;
      (*(code *)PTR_FUN_060c9e14)(2,2,3,4);
      (*(code *)PTR_FUN_060c9e18)((int)*(char *)(iVar5 + DAT_060c9e06));
      pcVar4 = (code *)PTR_FUN_060c9e1c;
      goto LAB_060c9f0c;
    }
    (*(code *)PTR_FUN_060c9e20)();
    (*(code *)PTR_FUN_060c9e24)(0x14,(int)DAT_060c9e08);
    (*(code *)PTR_FUN_060c9e28)();
    if (*DAT_060c9e2c < 1) {
      (*(code *)PTR_FUN_060c9e30)((int)DAT_060c9dfe);
    }
    sVar1 = DAT_060c9dfa;
    if (*DAT_060c9e34 != 1) {
      return *DAT_060c9e34;
    }
    goto LAB_060c9ee0;
  }
  uVar3 = *DAT_060c9f40 - 0x14;
  if (0x1e < uVar3) goto switchD_060c9e58_caseD_16;
  uVar2 = (int)&switchD_060c9e58::switchdataD_060c9e5c +
          (int)(short)(&switchD_060c9e58::switchdataD_060c9e5c)[uVar3];
  pcVar4 = (code *)PTR_FUN_060c9f44;
  switch(*DAT_060c9f40) {
  case 0x14:
  case 0x20:
  case 0x2c:
    (*(code *)PTR_FUN_060c9f48)();
    uVar2 = (*(code *)PTR_FUN_060c9f4c)((int)DAT_060c9f36);
    goto switchD_060c9e58_caseD_16;
  case 0x15:
    break;
  default:
    goto switchD_060c9e58_caseD_16;
  case 0x1a:
  case 0x26:
  case 0x32:
    pcVar4 = (code *)PTR_FUN_060c9f48;
    break;
  case 0x1c:
    break;
  case 0x23:
    break;
  case 0x2a:
    break;
  case 0x31:
  }
  uVar2 = (*pcVar4)();
switchD_060c9e58_caseD_16:
  iVar5 = *DAT_060c9f40;
  *DAT_060c9f40 = iVar5 + 1;
  sVar1 = DAT_060c9f38;
  if (0x32 < iVar5 + 1) {
LAB_060c9ee0:
    uVar2 = (*(code *)PTR_FUN_060c9f50)((int)sVar1);
  }
  return uVar2;
}



void FUN_060c9f70(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_060ca01c;
  switch(*DAT_060ca018) {
  case 0:
    *DAT_060ca01c = 0;
    goto LAB_060c9fd2;
  case 1:
    (*(code *)PTR_FUN_060ca020)(DAT_060ca01c,0xd);
    break;
  case 2:
    (*(code *)PTR_FUN_060ca024)(4,8,1,5);
    (*(code *)PTR_FUN_060ca028)(4,0,0xffffffe0);
LAB_060c9fd2:
    (*(code *)PTR_FUN_060ca02c)();
    break;
  case 3:
    iVar2 = *DAT_060ca01c;
    if (iVar2 == 10) {
      (*(code *)PTR_FUN_060ca030)((int)DAT_060ca016);
      iVar2 = *piVar1;
    }
    if (iVar2 == 0x16) {
      (*(code *)PTR_FUN_060ca034)(0x28);
    }
    (*(code *)PTR_FUN_060ca020)(piVar1,0x28);
    break;
  case 4:
    (*(code *)PTR_FUN_060ca038)(2);
  }
  return;
}



void FUN_060ca03c(void)

{
  short sVar1;
  int iVar2;
  ushort uVar4;
  int iVar3;
  code *pcVar5;
  
  iVar2 = DAT_060ca0e0;
  uVar4 = (ushort)*(byte *)(DAT_060ca0e0 + 10);
  sVar1 = DAT_060ca1d6;
  if (uVar4 == DAT_060ca0d0) {
LAB_060ca16e:
    (*(code *)PTR_FUN_060ca1f0)((int)sVar1);
    return;
  }
  if ((short)DAT_060ca0d0 < (short)uVar4) {
    if (uVar4 != DAT_060ca0d4) {
      if ((short)DAT_060ca0d4 < (short)uVar4) {
        if (uVar4 == DAT_060ca0d8) goto LAB_060ca1ae;
        goto LAB_060ca1ba;
      }
      if (uVar4 != DAT_060ca0d6) goto LAB_060ca1ba;
      (*(code *)PTR_FUN_060ca200)();
      (*(code *)PTR_FUN_060ca1e0)(0x14,(int)DAT_060ca1ca);
      if (0 < *DAT_060ca208) {
        return;
      }
      goto LAB_060ca1a4;
    }
    (*(code *)PTR_FUN_060ca20c)();
    (*(code *)PTR_FUN_060ca200)();
    pcVar5 = (code *)PTR_FUN_060ca204;
  }
  else {
    if (uVar4 == 1) {
      (*(code *)PTR_FUN_060ca1dc)();
      (*(code *)PTR_FUN_060ca1e0)(0x14,(int)DAT_060ca1ca);
      (*(code *)PTR_FUN_060ca1e4)();
      (*(code *)PTR_FUN_060ca1e8)();
      if (*DAT_060ca1ec == 0) {
        (*(code *)PTR_FUN_060ca1f0)((int)DAT_060ca1cc);
      }
      iVar3 = *DAT_060ca1f4;
      if (((iVar3 == 1) || (iVar3 - 4U < 2)) || (iVar3 == 7)) {
        (*(code *)PTR_FUN_060ca1f8)((int)DAT_060ca1ce);
        *(undefined *)(iVar2 + DAT_060ca1d0) = 6;
        (*(code *)PTR_FUN_060ca1f0)((int)DAT_060ca1d2);
      }
      sVar1 = DAT_060ca1d4;
      if (0 < *DAT_060ca1fc) {
        return;
      }
      goto LAB_060ca16e;
    }
    if (1 < *(byte *)(DAT_060ca0e0 + 10)) {
      if (uVar4 == DAT_060ca0d2) {
        (*(code *)PTR_FUN_060ca200)();
        (*(code *)PTR_FUN_060ca204)();
LAB_060ca1ae:
        (*(code *)PTR_FUN_060ca218)(DAT_060ca214,0x3c);
        return;
      }
LAB_060ca1ba:
      *(undefined *)(DAT_060ca0e0 + DAT_060ca1d8) = 1;
      return;
    }
    if (uVar4 != 0) goto LAB_060ca1ba;
    *DAT_060ca0e4 = 0;
    *(undefined *)(iVar2 + DAT_060ca0da) = 0;
    *(undefined *)(DAT_060ca0dc + iVar2) = 0;
    (*(code *)PTR_FUN_060ca0e8)(2,2,5,4);
    (*(code *)PTR_FUN_060ca0ec)((int)*(char *)(iVar2 + DAT_060ca0de));
    (*(code *)PTR_FUN_060ca0f0)();
    pcVar5 = (code *)PTR_FUN_060ca0f4;
  }
  (*pcVar5)();
LAB_060ca1a4:
  (*(code *)PTR_FUN_060ca210)();
  return;
}



void FUN_060ca21c(int param_1)

{
  (*(code *)PTR_FUN_060ca26c)((int)DAT_060ca268);
  *DAT_060ca270 = 0x10;
  (*(code *)PTR_FUN_060ca274)(10,2,1,0xc,0xff,0,0);
  (*(code *)PTR_FUN_060ca27c)
            (10,(int)*(short *)(PTR_DAT_060ca278 + param_1 * 4),
             (int)*(short *)((int)(PTR_DAT_060ca278 + param_1 * 4) + 2));
  return;
}



void FUN_060ca280(void)

{
  int iVar1;
  
  if ((*DAT_060ca2a8 != 0) && (iVar1 = *DAT_060ca2a8 + -1, *DAT_060ca2a8 = iVar1, iVar1 == 1)) {
    (*(code *)PTR_FUN_060ca2ac)(0x28);
  }
  return;
}



void FUN_060ca2b0(void)

{
  *DAT_060ca2c4 = 0;
  *DAT_060ca2c8 = 5;
  return;
}



int FUN_060ca2cc(void)

{
  byte bVar1;
  int *piVar2;
  undefined *puVar3;
  int in_r0;
  int iVar4;
  int iVar5;
  code *pcVar6;
  undefined uVar7;
  int *piVar8;
  
  puVar3 = PTR_FUN_060ca530;
  piVar2 = DAT_060ca510;
  piVar8 = DAT_060ca448;
  bVar1 = *DAT_060ca444;
  if (4 < bVar1) {
    return in_r0;
  }
  iVar4 = (int)&switchD_060ca2f8::switchdataD_060ca2fc +
          (int)(short)(&switchD_060ca2f8::switchdataD_060ca2fc)[bVar1];
  switch(bVar1) {
  case 0:
    *DAT_060ca448 = 0;
    goto LAB_060ca434;
  case 1:
    iVar5 = *DAT_060ca448 + 1;
    *DAT_060ca448 = iVar5;
    if (iVar5 < 0x1e) {
      return iVar4;
    }
    if (iVar5 <= DAT_060ca43e) {
      iVar4 = (*(code *)PTR_FUN_060ca44c)();
      iVar5 = (*(code *)PTR_FUN_060ca450)(iVar4,0x32);
      if (iVar4 + iVar5 * -0x32 != 0) {
        return iVar5;
      }
    }
    iVar4 = (*(code *)PTR_FUN_060ca44c)();
    iVar5 = (*(code *)PTR_FUN_060ca450)(iVar4,9);
    *DAT_060ca454 = iVar4 + iVar5 * -9;
    break;
  case 2:
    (*(code *)PTR_FUN_060ca458)(1,1,1,3);
    puVar3 = PTR_FUN_060ca460;
    piVar2 = DAT_060ca454;
    (*(code *)PTR_FUN_060ca460)
              (1,(int)*(short *)(PTR_DAT_060ca45c + *DAT_060ca454 * 4),
               (int)*(short *)((int)(PTR_DAT_060ca45c + *DAT_060ca454 * 4) + 2));
    piVar8 = DAT_060ca448;
    iVar4 = *DAT_060ca448;
    *DAT_060ca448 = iVar4 + 1;
    if (iVar4 + 1 < 0x1e) {
      iVar4 = (*(code *)PTR_FUN_060ca464)();
      if (*piVar8 < 0x10) {
        return iVar4;
      }
      if (*DAT_060ca468 != *piVar2) {
        return iVar4;
      }
      (*(code *)PTR_FUN_060ca46c)((int)DAT_060ca440);
      *DAT_060ca470 = *DAT_060ca470 + -1;
      uVar7 = 4;
      pcVar6 = (code *)PTR_FUN_060ca474;
      goto LAB_060ca4f6;
    }
    iVar4 = *piVar2;
    if (((iVar4 == 1) || (iVar4 - 4U < 2)) || (iVar4 == 7)) {
      if (*DAT_060ca448 < 0x3c) {
        return iVar4;
      }
      *DAT_060ca448 = 0x1e;
      uVar7 = 4;
      pcVar6 = (code *)PTR_FUN_060ca474;
      goto LAB_060ca4f6;
    }
    (*(code *)PTR_FUN_060ca458)(1,3,1,3);
    (*(code *)puVar3)(1,(int)*(short *)(PTR_DAT_060ca45c + *piVar2 * 4),
                      (int)*(short *)((int)(PTR_DAT_060ca45c + *piVar2 * 4) + 2));
    break;
  case 3:
    iVar5 = *DAT_060ca510;
    *DAT_060ca510 = iVar5 + 1;
    piVar8 = DAT_060ca524;
    if (*DAT_060ca514 == *DAT_060ca518) {
      (*(code *)PTR_FUN_060ca51c)((int)DAT_060ca50e);
      (*(code *)PTR_FUN_060ca520)(1);
      *DAT_060ca524 = *DAT_060ca524 + -1;
      *piVar2 = 0x1e;
      uVar7 = 4;
      pcVar6 = (code *)PTR_FUN_060ca528;
    }
    else {
      if (iVar5 + 1 == *DAT_060ca524 * 3 + 0xf) {
        iVar4 = (*(code *)PTR_FUN_060ca52c)();
      }
      if (*piVar2 < *piVar8 * 3 + 0x1e) {
        return iVar4;
      }
      *piVar2 = 0x1e;
      uVar7 = 4;
      pcVar6 = (code *)PTR_FUN_060ca528;
    }
    goto LAB_060ca4f6;
  case 4:
    *DAT_060ca510 = *DAT_060ca510 + -1;
    iVar4 = (*(code *)puVar3)();
    uVar7 = *piVar2 == 0;
    pcVar6 = (code *)PTR_FUN_060ca528;
    if (!(bool)uVar7) {
      return iVar4;
    }
LAB_060ca4f6:
    iVar4 = (*pcVar6)(uVar7);
    return iVar4;
  }
  *piVar8 = 0;
LAB_060ca434:
  iVar4 = (*(code *)PTR_FUN_060ca478)();
  return iVar4;
}



void FUN_060ca534(int param_1)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  puVar2 = PTR_FUN_060ca5c8;
  iVar8 = 0;
  iVar9 = (int)DAT_060ca5c6;
  do {
    iVar1 = iVar8 * 2;
    uVar7 = (uint)*(short *)(DAT_060ca5cc + iVar1);
    uVar6 = uVar7 >> 5;
    iVar8 = iVar8 + 1;
    iVar3 = (*(code *)puVar2)(((uVar7 & 0x7c00) >> 10) * param_1,0x1e,uVar6);
    iVar4 = (*(code *)puVar2)((uVar6 & 0x1f) * param_1);
    uVar5 = (*(code *)puVar2)((uVar7 & 0x1f) * param_1);
    *(ushort *)(DAT_060ca5d0 + iVar1) = (ushort)(iVar3 << 10) | (ushort)(iVar4 << 5) | uVar5;
  } while (iVar8 <= iVar9);
  *(undefined *)(DAT_060ca5d4 + 0x17) = 1;
  return;
}



void FUN_060ca5d8(void)

{
  short sVar1;
  ushort uVar3;
  int iVar2;
  int iVar4;
  
  iVar2 = DAT_060ca6cc;
  uVar3 = (ushort)*(byte *)(DAT_060ca6cc + 10);
  sVar1 = DAT_060ca7a6;
  if (uVar3 != DAT_060ca6ba) {
    if ((short)DAT_060ca6ba < (short)uVar3) {
      if (uVar3 == DAT_060ca6be) {
        (*(code *)PTR_FUN_060ca7d8)();
        (*(code *)PTR_FUN_060ca7d0)();
        *(int *)PTR_DAT_060ca7dc = *(int *)PTR_DAT_060ca7dc + 1;
LAB_060ca778:
        (*(code *)PTR_FUN_060ca7e0)();
        return;
      }
      if ((short)DAT_060ca6be < (short)uVar3) {
        if (uVar3 == DAT_060ca6c2) goto LAB_060ca782;
      }
      else if (uVar3 == DAT_060ca6c0) {
        (*(code *)PTR_FUN_060ca7cc)();
        (*(code *)PTR_FUN_060ca7b8)(0x14,(int)DAT_060ca79e);
        if (0 < *DAT_060ca7d4) {
          return;
        }
        goto LAB_060ca778;
      }
LAB_060ca78e:
      *(undefined *)(DAT_060ca6cc + DAT_060ca7a8) = 1;
      return;
    }
    if (uVar3 != 1) {
      if (*(byte *)(DAT_060ca6cc + 10) < 2) {
        if (uVar3 == 0) {
          *DAT_060ca6d0 = 0;
          *(undefined *)(iVar2 + DAT_060ca6c4) = 0;
          *(undefined *)(DAT_060ca6c6 + iVar2) = 0;
          iVar4 = *(int *)PTR_DAT_060ca6d4;
          if (iVar4 < 3) {
            *DAT_060ca6d8 = 0x32;
          }
          else if (iVar4 < 6) {
            *DAT_060ca6d8 = 0x28;
          }
          else if (iVar4 < 9) {
            *DAT_060ca6d8 = 0x1e;
          }
          else if (iVar4 < 0xc) {
            *DAT_060ca6d8 = 0x14;
          }
          else {
            *DAT_060ca6d8 = 10;
          }
          (*(code *)PTR_FUN_060ca6dc)(1,1,2,3);
          (*(code *)PTR_FUN_060ca6e0)((int)*(char *)(iVar2 + DAT_060ca6c8));
          (*(code *)PTR_FUN_060ca6e4)();
          (*(code *)PTR_FUN_060ca6e8)();
          goto LAB_060ca778;
        }
      }
      else if (uVar3 == DAT_060ca6bc) {
        (*(code *)PTR_FUN_060ca7cc)();
        (*(code *)PTR_FUN_060ca7d0)();
LAB_060ca782:
        (*(code *)PTR_FUN_060ca7e8)(DAT_060ca7e4,0x3c);
        return;
      }
      goto LAB_060ca78e;
    }
    (*(code *)PTR_FUN_060ca7ac)();
    (*(code *)PTR_FUN_060ca7b0)();
    (*(code *)PTR_FUN_060ca7b4)();
    (*(code *)PTR_FUN_060ca7b8)(0x14,(int)DAT_060ca79e);
    if (*DAT_060ca7bc < 1) {
      (*(code *)PTR_FUN_060ca7c0)((int)DAT_060ca7a0);
    }
    iVar2 = (*(code *)PTR_FUN_060ca7c4)();
    if (iVar2 == 0) {
      return;
    }
    (*(code *)PTR_FUN_060ca7c8)((int)DAT_060ca7a2);
    sVar1 = DAT_060ca7a4;
  }
  (*(code *)PTR_FUN_060ca7c0)((int)sVar1);
  return;
}



void FUN_060ca7ec(int param_1)

{
  (*(code *)PTR_FUN_060ca834)((int)DAT_060ca830);
  *(undefined4 *)(DAT_060ca838 + param_1 * 4) = 7;
  (*(code *)PTR_FUN_060ca83c)
            ((int)(short)((short)param_1 + 0x6c),(int)(short)((short)param_1 + 0x24),1,6,0xff,0,0);
  return;
}



void FUN_060ca840(void)

{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  puVar1 = PTR_FUN_060ca880;
  iVar4 = 0;
  do {
    piVar3 = (int *)(iVar4 * 4 + DAT_060ca884);
    iVar2 = *piVar3;
    iVar4 = iVar4 + 1;
    if ((iVar2 != 0) && (iVar2 = iVar2 + -1, *piVar3 = iVar2, iVar2 == 1)) {
      (*(code *)puVar1)(0x28);
    }
  } while (iVar4 < 9);
  return;
}



void FUN_060ca888(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  
  *DAT_060ca8c8 = 0;
  *DAT_060ca8cc = 0;
  *DAT_060ca8d0 = 2;
  iVar4 = 0;
  puVar1 = DAT_060ca8e0;
  puVar2 = DAT_060ca8dc;
  puVar3 = DAT_060ca8d8;
  puVar5 = DAT_060ca8d4;
  do {
    *puVar1 = 0;
    *puVar2 = 0;
    *puVar3 = 0;
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
    puVar3 = puVar3 + 1;
    puVar2 = puVar2 + 1;
    iVar4 = iVar4 + 1;
    puVar1 = puVar1 + 1;
  } while (iVar4 < 9);
  return;
}



bool FUN_060ca8e4(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_060ca918;
  iVar2 = *DAT_060ca918;
  if (iVar2 == 0x14) {
    *DAT_060ca91c = (uint)(iVar2 == 0x14);
    iVar2 = *piVar1;
  }
  if (iVar2 == 0x28) {
    *DAT_060ca920 = 3;
  }
  return *DAT_060ca924 <= *piVar1;
}



void FUN_060ca928(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  short unaff_r10;
  uint uVar4;
  bool bVar5;
  
  switch(param_1) {
  case 1:
    bVar5 = *DAT_060caaa0 == 0;
    if (bVar5) {
      if (DAT_060caaa0[2] != 0) {
        bVar5 = *DAT_060caaa0 == 0;
        goto LAB_060ca994;
      }
      uVar4 = (*(code *)PTR_FUN_060caaa4)();
      uVar4 = (uVar4 + ((int)(((uVar4 >> 0x10) * 2 >> 0x10) + uVar4) >> 1) * -2) * 2 + 3;
    }
    else {
LAB_060ca994:
      if (bVar5) {
        uVar4 = 3;
      }
      else {
        uVar4 = 0;
        if (DAT_060caaa0[2] == 0) {
          uVar4 = 5;
        }
      }
    }
    if (uVar4 == 3) {
      unaff_r10 = 0x2f;
    }
    bVar5 = uVar4 == 0;
    if (uVar4 == 5) {
      unaff_r10 = 0x2d;
    }
    break;
  default:
    uVar4 = 0;
    bVar5 = true;
    break;
  case 3:
    bVar5 = *DAT_060caaa8 == 0;
    if (bVar5) {
      if (DAT_060caaa8[6] != 0) {
        bVar5 = *DAT_060caaa8 == 0;
        goto LAB_060ca9ee;
      }
      uVar4 = (*(code *)PTR_FUN_060caaa4)();
      uVar4 = (uVar4 + ((int)(((uVar4 >> 0x10) * 2 >> 0x10) + uVar4) >> 1) * -2) * 6 + 1;
    }
    else {
LAB_060ca9ee:
      if (bVar5) {
        uVar4 = (uint)bVar5;
      }
      else {
        uVar4 = 0;
        if (DAT_060caaa8[6] == 0) {
          uVar4 = 7;
        }
      }
    }
    if (uVar4 == 1) {
      unaff_r10 = 0x30;
    }
    bVar5 = uVar4 == 0;
    if (uVar4 == 7) {
      unaff_r10 = 0x31;
    }
    break;
  case 5:
    uVar4 = 0;
    if (*DAT_060caaa8 == 0) {
      uVar4 = (uint)(*DAT_060caaa8 == 0);
    }
    bVar5 = uVar4 == 0;
    if (uVar4 == 1) {
      unaff_r10 = 0x2e;
    }
    break;
  case 7:
    uVar4 = 0;
    if (*DAT_060caaa0 == 0) {
      uVar4 = 3;
    }
    bVar5 = uVar4 == 0;
    if (uVar4 == 3) {
      unaff_r10 = 0x32;
    }
  }
  if (!bVar5) {
    (*(code *)PTR_FUN_060caaac)((int)(short)((short)param_1 + 99));
    iVar1 = DAT_060caab0;
    *(undefined4 *)(DAT_060caab0 + param_1 * 4) = 0;
    iVar2 = DAT_060caab4;
    *(undefined4 *)(DAT_060caab4 + param_1 * 4) = 0;
    (*(code *)PTR_FUN_060caab8)((int)(short)((short)uVar4 + 99),(int)unaff_r10,1,5,2,0,0);
    iVar3 = uVar4 * 4;
    *(int *)(DAT_060caabc + iVar3) = param_1;
    *(undefined4 *)(iVar1 + iVar3) = 4;
    *(undefined4 *)(iVar2 + iVar3) = 0;
  }
  return;
}



int * FUN_060caac0(void)

{
  short sVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int *piVar10;
  short sVar11;
  int *piVar12;
  bool bVar13;
  
  piVar8 = DAT_060cac98;
  piVar10 = DAT_060cac94;
  iVar9 = 0;
  piVar12 = (int *)0x0;
  sVar11 = 99;
  *DAT_060cac90 = *DAT_060cac90 + 1;
  do {
    piVar2 = DAT_060cac90;
    iVar6 = *piVar10;
    if (iVar6 == 2) {
      piVar2 = (int *)(*piVar8 + 1);
      *piVar8 = (int)piVar2;
      if (piVar2 == (int *)0x1) {
        piVar2 = (int *)(*(code *)PTR_FUN_060cacb4)((int)DAT_060cac8c);
      }
      iVar7 = *piVar8;
      iVar6 = 0x27;
LAB_060cac7e:
      if (iVar6 < iVar7) {
LAB_060cae24:
        piVar2 = (int *)0x0;
        *piVar8 = 0;
        *piVar10 = 0;
      }
    }
    else {
      sVar1 = (short)iVar9;
      if (2 < iVar6) {
        if (iVar6 == 4) {
          iVar6 = *piVar8;
          *piVar8 = iVar6 + 1;
          if (iVar6 + 1 == 5) {
            (*(code *)PTR_FUN_060cadf8)((int)DAT_060cadf6);
          }
          if ((*piVar8 == 0x1a) && (uVar3 = (*(code *)PTR_FUN_060cadfc)(), (uVar3 & 1) == 0)) {
            (*(code *)PTR_FUN_060cae00)(iVar9);
          }
          piVar2 = (int *)*piVar10;
          if (piVar2 == (int *)0x4) {
            piVar4 = (int *)(DAT_060cae04 + (int)piVar12);
            piVar2 = (int *)*piVar4;
            if (piVar2 == (int *)0x3c) {
              piVar2 = (int *)(*(code *)PTR_FUN_060cae08)(iVar9);
            }
            if (*piVar4 < 9) {
              bVar13 = *DAT_060cae0c == *(int *)(DAT_060cae10 + (int)piVar12);
              piVar2 = piVar12;
              if (bVar13) {
                (*(code *)PTR_FUN_060cae18)
                          ((int)sVar11,(int)(short)(*DAT_060cae14 + 0x1b),bVar13,5,0xff,0,0);
                *piVar4 = 0;
                piVar2 = (int *)0x3;
                *piVar10 = 3;
                *DAT_060cae1c = *DAT_060cae1c + 1;
              }
            }
            iVar6 = *piVar8;
            if ((0xe < iVar6) && (*DAT_060cae0c == iVar9)) {
              (*(code *)PTR_FUN_060cae18)
                        ((int)sVar11,(int)(short)(sVar1 + 0x1b),*DAT_060cae0c == iVar9,5,0xff,0,0);
              *piVar8 = 0;
              *(undefined4 *)((int)piVar12 + (int)DAT_060cae20) = 3;
              piVar2 = DAT_060cae1c;
              *DAT_060cae1c = *DAT_060cae1c + 1;
              iVar6 = *piVar8;
            }
            bVar13 = 0x4f < iVar6;
            if (bVar13) goto LAB_060cadca;
          }
          goto LAB_060cae2a;
        }
        if (3 < iVar6) goto LAB_060cae24;
        piVar2 = (int *)(*piVar8 + 1);
        *piVar8 = (int)piVar2;
        if (piVar2 == (int *)0x1) {
          piVar2 = (int *)(*(code *)PTR_FUN_060cadf8)((int)DAT_060cadf4);
        }
        iVar7 = *piVar8;
        iVar6 = 0x1d;
        goto LAB_060cac7e;
      }
      if (iVar6 != 0) {
        if (iVar6 == 1) {
          iVar6 = *piVar8;
          *piVar8 = iVar6 + 1;
          if (iVar6 + 1 == 0x46) {
            (*(code *)PTR_FUN_060cacb8)(iVar9);
          }
          if ((*piVar8 - 0x17U < 0x43) && (*DAT_060cacbc == iVar9)) {
            (*(code *)PTR_FUN_060cacb0)
                      ((int)sVar11,(int)(short)(sVar1 + 0x1b),*DAT_060cacbc == iVar9,5,0xff,0,0);
            *piVar8 = 0;
            *piVar10 = 3;
            *DAT_060cac9c = *DAT_060cac9c + 1;
          }
          piVar2 = (int *)*DAT_060cacc0;
          if ((piVar2 == (int *)0x1) && (piVar2 = (int *)*piVar8, piVar2 == (int *)0x19)) {
            iVar6 = (*(code *)PTR_FUN_060caca8)();
            piVar2 = (int *)(*(code *)PTR_FUN_060cacac)(iVar6,3);
            if (iVar6 + (int)piVar2 * -3 != 0) {
              piVar2 = (int *)(*(code *)PTR_FUN_060cacc4)(iVar9);
            }
          }
          bVar13 = 0x59 < *piVar8;
          if (bVar13) {
LAB_060cadca:
            (*(code *)PTR_FUN_060cae18)((int)sVar11,(int)(short)(sVar1 + 0x12),bVar13,4,0xff,0,0);
            *piVar8 = 0;
            piVar2 = DAT_060cae20;
            *(undefined4 *)((int)piVar12 + (int)DAT_060cae20) = 2;
          }
          goto LAB_060cae2a;
        }
        goto LAB_060cae24;
      }
      iVar6 = 0;
      if (iVar9 == 4) {
        piVar2 = (int *)0x4;
      }
      else {
        iVar7 = 0;
        piVar4 = DAT_060cac94;
        do {
          iVar5 = *piVar4;
          piVar4 = piVar4 + 1;
          if (iVar5 != 0) {
            iVar6 = iVar6 + 1;
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < 9);
        if ((iVar6 + *DAT_060cac9c < *DAT_060caca0) && (iVar6 < *DAT_060caca4)) {
          if (0x13 < *DAT_060cac90) {
            if (*DAT_060cac90 <= (int)DAT_060cac8a) {
              iVar6 = (*(code *)PTR_FUN_060caca8)();
              piVar2 = (int *)(*(code *)PTR_FUN_060cacac)(iVar6,0x32);
              if (iVar6 + (int)piVar2 * -0x32 != 0) goto LAB_060cae2a;
            }
            (*(code *)PTR_FUN_060cacb0)((int)sVar11,(int)(short)(sVar1 + 9),1,4,2,0,0);
            (*(code *)PTR_FUN_060cacb4)((int)DAT_060cac8c);
            *DAT_060cac90 = 0;
            piVar2 = (int *)0x0;
            *piVar8 = 0;
            *piVar10 = 1;
          }
        }
        else {
          *DAT_060cac90 = 0;
        }
      }
    }
LAB_060cae2a:
    piVar10 = piVar10 + 1;
    piVar8 = piVar8 + 1;
    piVar12 = piVar12 + 1;
    iVar9 = iVar9 + 1;
    sVar11 = sVar11 + 1;
    if (8 < iVar9) {
      return piVar2;
    }
  } while( true );
}



void FUN_060cae54(void)

{
  short sVar1;
  undefined *puVar2;
  ushort uVar4;
  int iVar3;
  int iVar5;
  
  puVar2 = PTR_FUN_060cb054;
  iVar3 = DAT_060caf48;
  uVar4 = (ushort)*(byte *)(DAT_060caf48 + 10);
  sVar1 = DAT_060cb026;
  if (uVar4 != DAT_060caf36) {
    if ((short)DAT_060caf36 < (short)uVar4) {
      if (uVar4 == DAT_060caf3a) {
        (*(code *)PTR_FUN_060cb054)(99);
        (*(code *)puVar2)(100);
        (*(code *)puVar2)(0x65);
        (*(code *)PTR_FUN_060cb058)();
        (*(code *)PTR_FUN_060cb04c)();
        *(int *)PTR_DAT_060cb05c = *(int *)PTR_DAT_060cb05c + 1;
LAB_060caffa:
        (*(code *)PTR_FUN_060cb060)();
        return;
      }
      if ((short)DAT_060caf3a < (short)uVar4) {
        if (uVar4 == DAT_060caf3e) goto LAB_060cb004;
      }
      else if (uVar4 == DAT_060caf3c) {
        (*(code *)PTR_FUN_060cb048)();
        (*(code *)PTR_FUN_060cb038)(0x14,(int)DAT_060cb020);
        if (0 < *DAT_060cb050) {
          return;
        }
        goto LAB_060caffa;
      }
LAB_060cb010:
      *(undefined *)(DAT_060caf48 + DAT_060cb028) = 1;
      return;
    }
    if (uVar4 != 1) {
      if (*(byte *)(DAT_060caf48 + 10) < 2) {
        if (uVar4 == 0) {
          *DAT_060caf4c = 0;
          *(undefined *)(iVar3 + DAT_060caf40) = 0;
          *(undefined *)(DAT_060caf42 + iVar3) = 0;
          iVar5 = *(int *)PTR_DAT_060caf50;
          if (iVar5 < 3) {
            *DAT_060caf54 = 0x3c;
          }
          else if (iVar5 < 6) {
            *DAT_060caf54 = 0x32;
          }
          else if (iVar5 < 9) {
            *DAT_060caf54 = 0x28;
          }
          else if (iVar5 < 0xc) {
            *DAT_060caf54 = 0x1e;
          }
          else {
            *DAT_060caf54 = 0x14;
          }
          (*(code *)PTR_FUN_060caf58)(1,3,2,3);
          (*(code *)PTR_FUN_060caf5c)((int)*(char *)(iVar3 + DAT_060caf44));
          (*(code *)PTR_FUN_060caf60)();
          (*(code *)PTR_FUN_060caf64)();
          goto LAB_060caffa;
        }
      }
      else if (uVar4 == DAT_060caf38) {
        (*(code *)PTR_FUN_060cb048)();
        (*(code *)PTR_FUN_060cb04c)();
LAB_060cb004:
        (*(code *)PTR_FUN_060cb068)(DAT_060cb064,0x3c);
        return;
      }
      goto LAB_060cb010;
    }
    (*(code *)PTR_FUN_060cb02c)();
    (*(code *)PTR_FUN_060cb030)();
    (*(code *)PTR_FUN_060cb034)();
    (*(code *)PTR_FUN_060cb038)(0x14,(int)DAT_060cb020);
    if (*DAT_060cb03c < 1) {
      (*(code *)PTR_FUN_060cb040)((int)DAT_060cb022);
    }
    iVar3 = (*(code *)PTR_FUN_060cb044)();
    sVar1 = DAT_060cb024;
    if (iVar3 == 0) {
      return;
    }
  }
  (*(code *)PTR_FUN_060cb040)((int)sVar1);
  return;
}



void FUN_060cb06c(int param_1)

{
  char cVar1;
  
  (*(code *)PTR_FUN_060cb0c4)((int)DAT_060cb0c0);
  cVar1 = PTR_DAT_060cb0c8[param_1 * 3];
  *(undefined4 *)(DAT_060cb0cc + cVar1 * 4) = 0x10;
  (*(code *)PTR_FUN_060cb0d4)
            ((int)(short)(cVar1 + 0x6c),(int)(char)PTR_DAT_060cb0d0[param_1 * 3],1,7,0xff,0,0);
  return;
}



void FUN_060cb0d8(void)

{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  puVar1 = PTR_FUN_060cb118;
  iVar4 = 0;
  do {
    piVar3 = (int *)(iVar4 * 4 + DAT_060cb11c);
    iVar2 = *piVar3;
    iVar4 = iVar4 + 1;
    if ((iVar2 != 0) && (iVar2 = iVar2 + -1, *piVar3 = iVar2, iVar2 == 1)) {
      (*(code *)puVar1)(0x28);
    }
  } while (iVar4 < 3);
  return;
}



void FUN_060cb120(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar4 = 0;
  puVar1 = DAT_060cb168;
  puVar2 = DAT_060cb164;
  puVar3 = DAT_060cb160;
  puVar5 = DAT_060cb15c;
  do {
    *puVar1 = 0xd;
    *puVar2 = 0;
    *puVar3 = 0;
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
    puVar3 = puVar3 + 1;
    puVar2 = puVar2 + 1;
    iVar4 = iVar4 + 1;
    puVar1 = puVar1 + 1;
  } while (iVar4 < 3);
  *DAT_060cb16c = 2;
  *DAT_060cb170 = 0;
  return;
}



bool FUN_060cb174(void)

{
  int *piVar1;
  
  piVar1 = DAT_060cb19c;
  if (*DAT_060cb19c == 0x1e) {
    *DAT_060cb1a0 = 3;
  }
  return *DAT_060cb1a4 <= *piVar1;
}



int FUN_060cb1a8(void)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int *local_28;
  
  iVar8 = 0;
  local_28 = DAT_060cb330;
  iVar6 = 0;
  piVar7 = DAT_060cb32c;
  do {
    iVar2 = DAT_060cb528;
    iVar3 = *piVar7;
    iVar5 = *local_28;
    if (iVar3 == 1) {
      piVar4 = (int *)(iVar6 + DAT_060cb528);
      iVar2 = *piVar4 + 1;
      *piVar4 = iVar2;
      if (iVar2 == 1) {
        iVar2 = (*(code *)PTR_FUN_060cb52c)((int)DAT_060cb50c);
      }
      puVar1 = PTR_DAT_060cb530;
      if (*piVar4 == (int)(char)*PTR_DAT_060cb530) {
        iVar2 = (*(code *)PTR_FUN_060cb52c)((int)DAT_060cb50c);
      }
      if (*piVar4 == (int)(char)puVar1[-3]) {
        iVar2 = (*(code *)PTR_FUN_060cb534)(iVar5);
      }
      if (*piVar4 == (int)(char)puVar1[-2]) {
        iVar2 = 0xff;
        *piVar7 = 0xff;
      }
      if (((int)(char)puVar1[-1] <= *piVar4) && (*piVar4 <= (int)(char)*puVar1)) {
        iVar5 = iVar5 * 3;
        if (*DAT_060cb53c == (int)(char)PTR_DAT_060cb538[iVar5 + 1]) {
          (*(code *)PTR_FUN_060cb524)
                    ((int)(short)((short)iVar8 + 99),(int)(char)PTR_DAT_060cb540[iVar5],
                     *DAT_060cb53c == (int)(char)PTR_DAT_060cb538[iVar5 + 1],
                     (int)(char)PTR_DAT_060cb538[iVar5 + 2],0xff,0,0);
          *piVar4 = 0;
          piVar4 = DAT_060cb544;
          *piVar7 = *piVar7 + 1;
          *piVar4 = *piVar4 + 1;
          iVar2 = 0;
        }
      }
    }
    else if (iVar3 < 2) {
      iVar5 = 0;
      if (iVar3 == 0) {
        iVar2 = 0;
        piVar4 = DAT_060cb32c;
        do {
          iVar3 = *piVar4;
          piVar4 = piVar4 + 1;
          if (iVar3 != 0) {
            iVar5 = iVar5 + 1;
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < 3);
        iVar2 = 0;
        if ((iVar5 + *DAT_060cb334 < *DAT_060cb338) && (iVar5 < *DAT_060cb33c)) {
          iVar5 = *(int *)(iVar6 + DAT_060cb340) + 1;
          *(int *)(iVar6 + DAT_060cb340) = iVar5;
          if (0x1d < iVar5) {
            if (iVar5 <= DAT_060cb32a) {
              iVar5 = (*(code *)PTR_FUN_060cb344)();
              iVar2 = (*(code *)PTR_FUN_060cb348)(iVar5,0x32);
              if (iVar5 + iVar2 * -0x32 != 0) goto LAB_060cb4e0;
            }
            if (iVar8 == 1) {
              if ((*DAT_060cb510 == 0) || (DAT_060cb510[2] == 1)) {
                iVar5 = (*(code *)PTR_FUN_060cb514)();
                iVar2 = (*(code *)PTR_FUN_060cb518)(iVar5,3);
                iVar5 = iVar5 + iVar2 * -3 + 8;
                goto LAB_060cb37e;
              }
              iVar5 = (*(code *)PTR_FUN_060cb514)();
              piVar4 = (int *)((int)DAT_060cb510 + iVar6);
              iVar5 = iVar5 % 4 + 8;
LAB_060cb3a2:
              *piVar4 = iVar5;
            }
            else if (iVar8 < 2) {
              if (iVar8 == 0) {
                if (*DAT_060cb34c != 0xb) {
                  iVar5 = (*(code *)PTR_FUN_060cb344)();
                  piVar4 = (int *)((int)DAT_060cb330 + iVar6);
                  iVar5 = (iVar5 % 4) * 2;
                  goto LAB_060cb3a2;
                }
                iVar5 = (*(code *)PTR_FUN_060cb344)();
                iVar2 = (*(code *)PTR_FUN_060cb348)(iVar5,3);
                iVar5 = (iVar5 + iVar2 * -3) * 2 + 2;
LAB_060cb37e:
                *(int *)(iVar6 + (int)DAT_060cb510) = iVar5;
              }
            }
            else if (iVar8 == 2) {
              if (*DAT_060cb34c != 0xb) {
                iVar5 = (*(code *)PTR_FUN_060cb344)();
                piVar4 = (int *)((int)DAT_060cb330 + iVar6);
                iVar5 = (iVar5 % 4) * 2 + 1;
                goto LAB_060cb3a2;
              }
              iVar5 = (*(code *)PTR_FUN_060cb344)();
              iVar2 = (*(code *)PTR_FUN_060cb348)(iVar5,3);
              iVar5 = (iVar5 + iVar2 * -3) * 2 + 3;
              goto LAB_060cb37e;
            }
            (*(code *)PTR_FUN_060cb524)
                      ((int)(short)((short)iVar8 + 99),(int)(char)PTR_DAT_060cb520[*local_28 * 3],1,
                       (int)(char)PTR_DAT_060cb51c[*local_28 * 3],0xff,0,0);
            *(undefined4 *)(DAT_060cb528 + iVar6) = 0;
            *piVar7 = *piVar7 + 1;
            iVar2 = iVar6;
          }
        }
      }
      else {
LAB_060cb4d0:
        *local_28 = 0xd;
        *(undefined4 *)(iVar2 + iVar6) = 0;
        *piVar7 = 0;
        iVar2 = 0;
      }
    }
    else {
      if (iVar3 != 2) goto LAB_060cb4d0;
      piVar4 = (int *)(iVar6 + DAT_060cb528);
      if (*piVar4 == 0) {
        (*(code *)PTR_FUN_060cb52c)((int)DAT_060cb50e);
      }
      iVar2 = *piVar4;
      if (iVar2 == 0x1e) {
        *piVar7 = 0xff;
      }
      *piVar4 = *piVar4 + 1;
    }
LAB_060cb4e0:
    piVar7 = piVar7 + 1;
    iVar6 = iVar6 + 4;
    iVar8 = iVar8 + 1;
    local_28 = local_28 + 1;
    if (2 < iVar8) {
      return iVar2;
    }
  } while( true );
}



void FUN_060cb548(uint param_1)

{
  byte bVar1;
  ushort uVar2;
  bool bVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  uint *puVar10;
  ushort *puVar11;
  byte *pbVar12;
  int iVar13;
  uint uVar14;
  byte *pbVar15;
  byte *pbVar16;
  
  puVar4 = DAT_060cb6f4;
  iVar6 = *DAT_060cb6d8;
  uVar7 = *DAT_060cb6dc;
  pbVar9 = (byte *)*DAT_060cb6e0;
  puVar10 = (uint *)*DAT_060cb6e4;
  puVar11 = (ushort *)*DAT_060cb6e8;
  pbVar12 = (byte *)*DAT_060cb6ec;
  iVar13 = *DAT_060cb6f0;
  *DAT_060cb6f4 = 0;
  if (iVar13 == 0) {
LAB_060cb588:
    if (*puVar4 < param_1) {
      iVar6 = iVar6 + -1;
      uVar5 = uVar7 & 1;
      uVar7 = uVar7 >> 1;
      if (iVar6 == 0) {
        uVar7 = *puVar10;
        puVar10 = puVar10 + 1;
        iVar6 = 0x20;
      }
      if (uVar5 == 1) {
        iVar6 = iVar6 + -1;
        bVar3 = (uVar7 & 1) == 1;
        uVar7 = uVar7 >> 1;
        if (iVar6 == 0) {
          uVar7 = *puVar10;
          puVar10 = puVar10 + 1;
          iVar6 = 0x20;
        }
        if (bVar3) {
          bVar1 = *pbVar12;
          pbVar12 = pbVar12 + 1;
          uVar5 = (uint)bVar1;
          pbVar15 = pbVar9 + (-(uint)bVar3 - uVar5);
          iVar6 = iVar6 + -1;
          uVar14 = uVar7 & 1;
          uVar8 = uVar7 >> 1;
          if (iVar6 == 0) {
            uVar8 = *puVar10;
            puVar10 = puVar10 + 1;
            iVar6 = 0x20;
          }
          iVar6 = iVar6 + -1;
          uVar7 = uVar8 >> 1;
          if (iVar6 == 0) {
            uVar7 = *puVar10;
            puVar10 = puVar10 + 1;
            iVar6 = 0x20;
          }
          uVar14 = ((uint)(uVar14 == 1) << 1 | (uint)((uVar8 & 1) == 1)) + 2;
          pbVar9 = pbVar9 + uVar14;
        }
        else {
          uVar2 = *puVar11;
          puVar11 = puVar11 + 1;
          if (uVar2 == 0) goto LAB_060cb5d8;
          bVar3 = (uVar2 & 0xf) != 0;
          if (bVar3) {
            uVar14 = (uVar2 & 0xf) + 2;
            uVar5 = (uint)(uVar2 >> 4);
            pbVar15 = pbVar9 + (-(uint)bVar3 - uVar5);
            pbVar9 = pbVar9 + uVar14;
          }
          else {
            bVar1 = *pbVar12;
            pbVar12 = pbVar12 + 1;
            uVar14 = (uint)bVar1;
            pbVar15 = pbVar9 + -(uint)(uVar2 >> 4);
            uVar5 = (uVar2 >> 4) - 1;
            pbVar9 = pbVar9 + uVar14;
          }
        }
        do {
          (pbVar15 + 1)[uVar5] = *pbVar15;
          if (uVar14 == 1) break;
          (pbVar15 + 2)[uVar5] = pbVar15[1];
          if (uVar14 == 2) break;
          (pbVar15 + 3)[uVar5] = pbVar15[2];
          if (uVar14 == 3) break;
          (pbVar15 + 4)[uVar5] = pbVar15[3];
          if (uVar14 == 4) break;
          pbVar16 = pbVar15 + 5;
          pbVar16[uVar5] = pbVar15[4];
          if (uVar14 == 5) break;
          pbVar15 = pbVar15 + 6;
          uVar14 = uVar14 - 6;
          pbVar15[uVar5] = *pbVar16;
        } while (uVar14 != 0);
      }
      else {
        bVar1 = *pbVar12;
        pbVar12 = pbVar12 + 1;
        *pbVar9 = bVar1;
        pbVar9 = pbVar9 + 1;
      }
      goto LAB_060cb588;
    }
    *DAT_060cb6d8 = iVar6;
    *DAT_060cb6dc = uVar7;
    *DAT_060cb6e0 = pbVar9;
    *DAT_060cb6e4 = puVar10;
    *DAT_060cb6e8 = puVar11;
    *DAT_060cb6ec = pbVar12;
  }
  else {
LAB_060cb5d8:
    *DAT_060cb6f0 = 1;
  }
  return;
}



void FUN_060cb6fc(undefined4 *param_1,undefined4 param_2)

{
  ushort uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = DAT_060cb75c;
  *DAT_060cb758 = *param_1;
  *puVar2 = param_1 + 2;
  uVar1 = *(ushort *)(param_1 + 1);
  *DAT_060cb760 = param_1 + uVar1 + 2;
  *DAT_060cb764 = (int)param_1 + (uint)uVar1 * 4 + (uint)*(ushort *)((int)param_1 + 6) * 2 + 8;
  *DAT_060cb768 = param_2;
  puVar3 = DAT_060cb76c;
  *puVar2 = param_1 + 3;
  *puVar3 = param_1[2];
  *DAT_060cb770 = 0x20;
  *DAT_060cb774 = 0;
  return;
}



void FUN_060cb778(code *UNRECOVERED_JUMPTABLE)

{
                    // WARNING: Could not recover jumptable at 0x060cb778. Too many branches
                    // WARNING: Treating indirect jump as call
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



void FUN_060cb77c(void)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  (*(code *)*DAT_060cb7a8)(DAT_060cb7ac);
  iVar1 = DAT_060cb7b8;
  iVar3 = 0;
  puVar2 = DAT_060cb7b0;
  puVar4 = DAT_060cb7b4;
  do {
    uVar5 = *puVar2;
    puVar2 = puVar2 + 1;
    iVar3 = iVar3 + 1;
    *puVar4 = uVar5;
    puVar4 = puVar4 + 1;
  } while (iVar3 <= iVar1);
  return;
}



void FUN_060cb7bc(void)

{
  (*(code *)PTR_FUN_060cb7d8)();
  (*(code *)PTR_FUN_060cb7e0)(DAT_060cb7dc);
  return;
}



void FUN_060cb7e4(undefined4 *param_1,int param_2)

{
  if ((param_1[9] & 1) != 0) {
    *(undefined4 *)(param_2 * 0x20 + DAT_060cb854) = *param_1;
  }
  if ((param_1[9] & 2) != 0) {
    *(undefined4 *)(param_2 * 0x20 + DAT_060cb858) = param_1[1];
  }
  param_2 = param_2 * 0x20;
  *(undefined4 *)(param_2 + DAT_060cb85c) = param_1[2];
  *(undefined4 *)(param_2 + DAT_060cb860) = param_1[3] | param_1[4];
  *(undefined4 *)(param_2 + DAT_060cb864) =
       param_1[6] << 0x10 | param_1[5] | param_1[7] << 8 | param_1[8];
  return;
}



void FUN_060cb868(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  code *pcVar2;
  undefined4 unaff_r9;
  undefined *unaff_r11;
  
  if (param_1 == 1) {
    unaff_r9 = 0x4a;
    unaff_r11 = PTR_LAB_060cb934;
  }
  else if (param_1 == 0) {
    unaff_r9 = 0x4b;
    unaff_r11 = PTR_LAB_060cb930;
  }
  else if (param_1 == 2) {
    unaff_r9 = 0x49;
    unaff_r11 = PTR_LAB_060cb938;
  }
  uVar1 = (*(code *)PTR_FUN_060cb93c)(unaff_r9);
  *(undefined4 *)(DAT_060cb940 + param_1 * 4) = uVar1;
  pcVar2 = (code *)*DAT_060cb944;
  uVar1 = (*pcVar2)(unaff_r9);
  *(undefined4 *)(DAT_060cb948 + param_1 * 4) = uVar1;
  *(undefined *)(DAT_060cb94c + param_1) = 1;
  (*(code *)PTR_FUN_060cb950)(unaff_r9,unaff_r11,param_3,param_4,pcVar2);
  (*(code *)*DAT_060cb954)(unaff_r9,0);
  *(int *)(param_1 * 0x20 + DAT_060cb958) = (int)DAT_060cb92a;
  return;
}



void FUN_060cb95c(uint *param_1,int param_2)

{
  *param_1 = (uint)*(byte *)(DAT_060cb998 + param_2);
  return;
}



undefined4 FUN_060cbaec(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined auStack_1c [12];
  
  uStack_20 = 0;
  local_24 = 0;
  uVar1 = (*(code *)PTR_FUN_060cbb34)(0,&local_24,auStack_1c,1);
  (*(code *)PTR_FUN_060cbb38)(auStack_1c,param_1);
  return uVar1;
}



void FUN_060cbb3c(void)

{
  (*(code *)PTR_FUN_060cbb50)();
  return;
}



int FUN_060cbb54(byte *param_1)

{
  int iVar1;
  undefined auStack_18 [12];
  
  iVar1 = (*(code *)PTR_FUN_060cbb9c)(auStack_18);
  if (iVar1 == 0) {
    (*(code *)PTR_FUN_060cbba0)(auStack_18,param_1);
    if ((*param_1 == DAT_060cbb9a) || ((*param_1 & 0x20) == 0)) {
      iVar1 = -8;
    }
  }
  return iVar1;
}



undefined4 FUN_060cbba4(int *param_1)

{
  undefined *puVar1;
  int iVar2;
  int local_28;
  int iStack_24;
  
  puVar1 = PTR_FUN_060cbc24;
  iVar2 = 0;
  while( true ) {
    (*(code *)puVar1)(param_1);
    (*(code *)puVar1)(&local_28);
    if ((*param_1 == local_28) && (param_1[1] == iStack_24)) break;
    iVar2 = iVar2 + 1;
    if (99 < iVar2) {
      return 0xfffffffd;
    }
  }
  return 0;
}



void FUN_060cbc90(undefined4 param_1)

{
  int iVar1;
  undefined4 local_20;
  undefined4 uStack_1c;
  uint local_18 [3];
  
  uStack_1c = 0;
  local_20 = 0x2000000;
  iVar1 = (*(code *)PTR_FUN_060cbcd4)(0,&local_20,local_18);
  if (iVar1 == 0) {
    (*(code *)PTR_FUN_060cbcdc)(local_18[0] & DAT_060cbcd8,param_1);
  }
  return;
}



void FUN_060cbce0(byte param_1,undefined4 *param_2)

{
  undefined local_1c;
  int3 iStack_1b;
  undefined4 uStack_18;
  undefined auStack_14 [4];
  undefined4 uStack_10;
  
  uStack_18 = 0;
  _local_1c = CONCAT13(3,(uint3)param_1 << 0x10);
  (*(code *)PTR_FUN_060cbd18)(0,&local_1c,auStack_14);
  *param_2 = uStack_10;
  return;
}



int FUN_060cbd1c(byte param_1,undefined2 param_2,undefined param_3,undefined param_4)

{
  int iVar1;
  undefined2 local_14;
  undefined2 uStack_12;
  uint uStack_10;
  
  _local_14 = CONCAT22(CONCAT11(4,param_1),param_2);
  uStack_10 = (uint)CONCAT11(param_3,param_4);
  if ((param_1 & 0x81) == 1) {
    (*(code *)PTR_FUN_060cbd90)((int)DAT_060cbd8e);
    (*(code *)PTR_FUN_060cbd94)(0x41);
    iVar1 = (*(code *)PTR_FUN_060cbd98)(0x40,&local_14);
    if (iVar1 == 0) {
      (*(code *)PTR_FUN_060cbd9c)();
    }
  }
  else {
    iVar1 = (*(code *)PTR_FUN_060cbd98)(0,&local_14);
  }
  return iVar1;
}



int FUN_060cbdc8(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  uint local_18;
  undefined auStack_14 [8];
  
  uVar3 = 2;
  if (param_1 == 1) {
    uVar3 = 0x82;
  }
  iVar2 = (*(code *)PTR_FUN_060cbe28)(uVar3,&local_18);
  bVar1 = iVar2 == 0;
  if (((param_1 == 1) && (bVar1)) && (bVar1 = true, (local_18 & 0x80) != 0)) {
    iVar2 = -4;
    bVar1 = false;
  }
  if (!bVar1) {
    (*(code *)PTR_FUN_060cbe2c)(auStack_14);
  }
  (*(code *)PTR_FUN_060cbe30)(0xfffffffd);
  return iVar2;
}



undefined4 FUN_060cbe34(uint *param_1)

{
  undefined4 uVar1;
  undefined4 local_24;
  undefined4 uStack_20;
  uint local_1c [3];
  
  uStack_20 = 0;
  local_24 = 0x6000000;
  uVar1 = (*(code *)PTR_FUN_060cbe80)(0,&local_24,local_1c);
  *param_1 = local_1c[0] & DAT_060cbe84;
  (*(code *)PTR_FUN_060cbe88)(0xfffffffd);
  return uVar1;
}



void FUN_060cbe8c(void)

{
  (*(code *)PTR_FUN_060cbea0)();
  return;
}



void FUN_060cbea4(undefined4 param_1,undefined4 param_2)

{
  undefined auStack_10 [12];
  
  (*(code *)PTR_FUN_060cbec0)(param_1,param_2,auStack_10,1);
  return;
}



int FUN_060cbec4(undefined4 param_1,undefined4 param_2,undefined *param_3,int param_4)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_FUN_060cbf28)();
  if (iVar1 == 0) {
    if (param_4 == 0) {
      *DAT_060cbf2c = *param_3;
    }
    else {
      (*(code *)PTR_FUN_060cbf30)(param_3);
    }
  }
  return iVar1;
}



longlong FUN_060cbf34(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint in_sr;
  
  puVar1 = DAT_060cbf70;
  uVar3 = (uint)DAT_060cbf6c;
  puVar2 = DAT_060cbf70 + 1;
  *param_1 = *DAT_060cbf70;
  param_1[1] = *puVar2;
  param_1[2] = puVar1[2];
  return (ulonglong)((in_sr & 0xfff0fff | 0xf0) & uVar3 | in_sr & 0xf0) << 0x20;
}



void FUN_060cbf74(undefined *param_1,undefined *param_2)

{
  *param_2 = *param_1;
  param_2[4] = param_1[1];
  param_2[5] = param_1[2];
  param_2[6] = param_1[3];
  param_2[7] = param_1[4];
  *(uint *)(param_2 + 8) = *(uint *)(param_1 + 4) & DAT_060cbfb8;
  return;
}



void FUN_060cbfbc(int param_1)

{
  undefined4 local_8;
  
  for (local_8 = param_1; 0 < local_8; local_8 = local_8 + -1) {
  }
  return;
}



undefined4 FUN_060cbfe0(void)

{
  return DAT_060cbfec;
}



undefined2 FUN_060cbff0(void)

{
  return *DAT_060cc000;
}



void FUN_060cc004(uint param_1)

{
  *DAT_060cc028 = *DAT_060cc028 | *DAT_060cc02c;
  (*(code *)PTR_FUN_060cc030)(param_1 | 1);
  return;
}



void FUN_060cc034(undefined2 param_1)

{
  *DAT_060cc040 = param_1;
  return;
}



void FUN_060cc044(void)

{
  short sVar1;
  
  sVar1 = DAT_060cc062;
  (*(code *)PTR_FUN_060cc064)((int)DAT_060cc062);
  *DAT_060cc068 = sVar1;
  return;
}



void FUN_060cc06c(ushort param_1)

{
  *DAT_060cc07c = *DAT_060cc07c | param_1;
  return;
}



int FUN_060cc0b4(int param_1,undefined2 *param_2)

{
  undefined2 *puVar1;
  int iVar2;
  int iVar3;
  int local_14 [2];
  
  iVar2 = (*(code *)PTR_FUN_060cc104)(0);
  puVar1 = DAT_060cc108;
  iVar3 = 0;
  if (iVar2 == 0) {
    if (0 < param_1) {
      do {
        iVar3 = iVar3 + 1;
        *param_2 = *puVar1;
        param_2 = param_2 + 1;
      } while (iVar3 < param_1);
    }
    iVar2 = (*(code *)PTR_FUN_060cc10c)(local_14);
    if ((iVar2 == 0) && (param_1 != local_14[0])) {
      iVar2 = -7;
    }
  }
  return iVar2;
}



void FUN_060cc110(void)

{
  (*(code *)PTR_FUN_060cc14c)();
  return;
}



int FUN_060cc150(uint param_1,undefined4 param_2,byte *param_3)

{
  ushort *puVar1;
  ushort uVar3;
  int iVar2;
  undefined auStack_1c [8];
  
  puVar1 = DAT_060cc1f4;
  uVar3 = *DAT_060cc1f4 | *DAT_060cc1f8;
  *DAT_060cc1f4 = uVar3;
  if ((uVar3 & param_1) == param_1) {
    if ((uVar3 & 1) == 0) {
      iVar2 = -2;
    }
    else {
      (*(code *)PTR_FUN_060cc1fc)(~(param_1 | 1));
      *puVar1 = *puVar1 & (ushort)DAT_060cc200;
      (*(code *)PTR_FUN_060cc204)(param_2);
      iVar2 = (*(code *)PTR_FUN_060cc208)(1,auStack_1c);
      if (iVar2 == 0) {
        (*(code *)PTR_FUN_060cc20c)(param_3);
        if (*param_3 == DAT_060cc1f0) {
          iVar2 = -5;
        }
        else if ((*param_3 & 0x80) != 0) {
          iVar2 = -6;
        }
        if (iVar2 == 0) {
          *DAT_060cc1f4 = *DAT_060cc1f4 & ~(ushort)param_1;
        }
      }
    }
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}



undefined4 FUN_060cc210(uint param_1,uint *param_2)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
    if ((*DAT_060cc23c & param_1) != 0) {
      *param_2 = (uint)*DAT_060cc23c;
      return 0;
    }
  } while (iVar1 <= DAT_060cc240);
  return 0xfffffffd;
}



void FUN_060cc244(undefined2 *param_1)

{
  *DAT_060cc270 = *param_1;
  *DAT_060cc274 = param_1[1];
  *DAT_060cc278 = param_1[2];
  *DAT_060cc27c = param_1[3];
  return;
}



void FUN_060cc280(undefined2 *param_1)

{
  *param_1 = *DAT_060cc2ac;
  param_1[1] = *DAT_060cc2b0;
  param_1[2] = *DAT_060cc2b4;
  param_1[3] = *DAT_060cc2b8;
  return;
}



int FUN_060cc39c(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_14 [2];
  
  if (param_2 == 0) {
    if (*(int *)(*DAT_060cc428 + (int)DAT_060cc424 + 8) == 0) {
      iVar1 = (*(code *)PTR_FUN_060cc430)();
      if (iVar1 < 0) {
        iVar1 = (*(code *)PTR_FUN_060cc42c)(iVar1);
      }
    }
    else {
      iVar1 = (*(code *)PTR_FUN_060cc42c)(0xfffffff9);
    }
  }
  else {
    iVar2 = (*(code *)PTR_FUN_060cc434)();
    if (iVar2 == 0) {
      iVar1 = *(int *)(*DAT_060cc428 + (int)DAT_060cc426 + 8);
    }
    else {
      (*(code *)PTR_FUN_060cc438)(iVar2,0,local_14,0);
      iVar1 = (*(code *)PTR_FUN_060cc43c)(iVar2,param_2,local_14[0]);
      (*(code *)PTR_FUN_060cc440)(iVar2);
    }
  }
  return iVar1;
}



void FUN_060cc444(undefined4 *param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)(*DAT_060cc4a0 + (int)DAT_060cc49c);
  if (param_1 == (undefined4 *)0x0) {
    uVar2 = 0xfffffff9;
    if (puVar3[2] != 0) goto LAB_060cc48e;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[1] = 0;
  }
  else {
    *puVar3 = *param_1;
    puVar3[1] = param_1[1];
    puVar1 = PTR_FUN_060cc4a8;
    puVar3[2] = param_1[2];
    uVar2 = (*(code *)puVar1)();
    puVar3[3] = uVar2;
  }
  uVar2 = 0;
LAB_060cc48e:
  (*(code *)PTR_FUN_060cc4a4)(uVar2);
  return;
}



int FUN_060cc4ac(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  piVar2 = (int *)(*DAT_060cc4fc + (int)DAT_060cc4f8);
  if ((piVar2[2] == 0) || (*piVar2 != 1)) {
    uVar3 = 0xfffffff8;
  }
  else {
    iVar1 = (*(code *)PTR_FUN_060cc504)(piVar2[2],param_1,piVar2[1]);
    uVar3 = 0xfffffff7;
    if (-1 < iVar1) {
      (*(code *)PTR_FUN_060cc500)(0);
      return iVar1;
    }
  }
  iVar1 = (*(code *)PTR_FUN_060cc500)(uVar3);
  return iVar1;
}



void FUN_060cc56c(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int *piVar3;
  undefined4 uVar4;
  code *pcVar2;
  
  piVar3 = (int *)((int)DAT_060cc5c8 + *DAT_060cc5cc);
  if (((piVar3[2] == 0) || (param_1 < 0)) || (piVar3[3] <= param_1)) {
    uVar4 = 0xfffffff6;
  }
  else {
    pcVar2 = (code *)PTR_FUN_060cc5d8;
    if (*piVar3 == 1) {
      pcVar2 = (code *)PTR_FUN_060cc5d4;
    }
    puVar1 = (undefined4 *)(*pcVar2)();
    *param_2 = *puVar1;
    param_2[1] = puVar1[1];
    param_2[2] = puVar1[2];
    uVar4 = 0;
  }
  (*(code *)PTR_FUN_060cc5d0)(uVar4);
  return;
}



int FUN_060cc660(int param_1)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  
  piVar5 = (int *)(*DAT_060cc6f4 + (int)DAT_060cc6f2);
  iVar4 = param_1;
  if ((piVar5[2] == 0) || ((iVar4 = -10, -1 < param_1 && (param_1 < piVar5[3])))) {
    iVar1 = (*(code *)PTR_FUN_060cc6fc)(iVar4);
    iVar4 = -0x13;
    if (iVar1 != 0) {
      uVar3 = 0;
      if (piVar5[2] != 0) {
        pcVar2 = (code *)PTR_FUN_060cc704;
        if (*piVar5 == 0) {
          pcVar2 = (code *)PTR_FUN_060cc700;
        }
        uVar3 = (*pcVar2)(param_1);
      }
      iVar4 = (*(code *)PTR_FUN_060cc708)(iVar1,uVar3,param_1);
      uVar3 = 0;
      if (iVar4 == 0) {
        uVar3 = 0xfffffff6;
      }
      (*(code *)PTR_FUN_060cc6f8)(uVar3);
      return iVar4;
    }
  }
  (*(code *)PTR_FUN_060cc6f8)(iVar4);
  return 0;
}



void FUN_060cc70c(int param_1)

{
  if (param_1 != 0) {
    (*(code *)PTR_FUN_060cc738)();
    (*(code *)PTR_FUN_060cc73c)(param_1);
  }
  (*(code *)PTR_FUN_060cc740)(0);
  return;
}



undefined4 FUN_060cc744(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int local_1c [2];
  
  if (param_1 == 0) {
    uVar2 = 0xfffffff5;
  }
  else {
    iVar3 = *(int *)(param_1 + 0x28) * 0x10 + 4 + *DAT_060cc7e0;
    (*(code *)PTR_FUN_060cc7e4)(param_1,0,local_1c,0);
    if (param_3 == 1) {
      iVar1 = (**(code **)(iVar3 + 0xc))(param_1 + 0xc);
      param_2 = param_2 + iVar1;
    }
    else if (param_3 == 2) {
      param_2 = param_2 + local_1c[0];
    }
    else {
      uVar2 = 0xfffffff3;
      if (param_3 != 0) goto LAB_060cc7c6;
    }
    if ((-1 < param_2) && (param_2 <= local_1c[0])) {
      uVar2 = (**(code **)(iVar3 + 8))(param_1 + 0xc,param_2);
      (*(code *)PTR_FUN_060cc7dc)(0);
      return uVar2;
    }
    uVar2 = 0xfffffff4;
  }
LAB_060cc7c6:
  uVar2 = (*(code *)PTR_FUN_060cc7dc)(uVar2);
  return uVar2;
}



undefined4 FUN_060cc7e8(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = (*(code *)PTR_FUN_060cc82c)(0xfffffff5);
  }
  else {
    uVar1 = (**(code **)(*(int *)(param_1 + 0x28) * 0x10 + *DAT_060cc828 + 0x10))(param_1 + 0xc);
    (*(code *)PTR_FUN_060cc82c)(0);
  }
  return uVar1;
}



void FUN_060cc8e0(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  uint local_10 [2];
  
  if (param_1 == 0) {
    (*(code *)PTR_FUN_060cc930)(0xfffffff5);
  }
  else {
    (*(code *)PTR_FUN_060cc934)(param_1 + 0xc,0,0,param_2,param_3,param_4,0,local_10);
    if ((local_10[0] & 0x18) == 0x18) {
      *param_2 = 0;
    }
  }
  (*(code *)PTR_FUN_060cc930)(0);
  return;
}



void FUN_060cc938(int param_1,undefined4 param_2,undefined4 param_3,int *param_4,uint *param_5)

{
  int local_18;
  int aiStack_14 [2];
  
  if (param_1 == 0) {
    (*(code *)PTR_FUN_060cc9a4)(0xfffffff5);
  }
  else {
    (*(code *)PTR_FUN_060cc9a8)(param_1 + 0xc,param_2,0,0,&local_18,aiStack_14,param_3,param_5);
    if (param_5 != (uint *)0x0) {
      *param_5 = *param_5 & 0xfffffff9;
    }
    if (param_4 != (int *)0x0) {
      *param_4 = (local_18 + -1) * 0x800 + aiStack_14[0];
    }
  }
  (*(code *)PTR_FUN_060cc9a4)(0);
  return;
}



int FUN_060cc9d4(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = (*(code *)PTR_FUN_060cca7c)();
  if (iVar1 == 0) {
    iVar2 = *(int *)(*DAT_060cca80 + (int)DAT_060cca76 + 8);
  }
  else {
    iVar2 = (*(code *)PTR_FUN_060cca84)(iVar1,param_2,0);
    if (iVar2 < 0) {
      iVar2 = (*(code *)PTR_FUN_060cca88)(0xfffffff1);
    }
    else {
      iVar3 = *(int *)(iVar1 + 0x1c);
      iVar2 = iVar3;
      if (iVar3 == 0) {
        iVar3 = (int)DAT_060cca78;
        iVar2 = (int)DAT_060cca7a;
      }
      param_2 = *(int *)(iVar1 + 0x20) - param_2;
      if (param_4 == -1) {
        param_4 = param_2 * iVar3;
      }
      iVar2 = (*(code *)PTR_FUN_060cca8c)(param_4 + iVar3 + -1,iVar2);
      if (iVar2 < param_2) {
        param_2 = iVar2;
      }
      iVar2 = (*(code *)PTR_FUN_060cca90)(iVar1,param_2,param_3,param_4);
      (*(code *)PTR_FUN_060cca94)(iVar1);
      if (-1 < iVar2) {
        (*(code *)PTR_FUN_060cca88)(0);
      }
    }
  }
  return iVar2;
}



int FUN_060cca98(int param_1)

{
  int iVar1;
  int iVar2;
  undefined auStack_18 [4];
  int aiStack_14 [2];
  
  if (param_1 == 0) {
    iVar1 = (*(code *)PTR_FUN_060ccb10)(0xfffffff5);
  }
  else {
    iVar1 = (*(code *)PTR_FUN_060ccb14)(param_1);
    if (iVar1 == 0) {
      iVar2 = (*(code *)PTR_FUN_060ccb1c)(param_1,DAT_060ccb18);
      iVar1 = (*(code *)PTR_FUN_060ccb20)(param_1);
      if (iVar1 < 0) {
        aiStack_14[0] = (*(code *)PTR_FUN_060ccb10)(iVar1);
      }
      else {
        (*(code *)PTR_FUN_060ccb24)(param_1,auStack_18,aiStack_14);
        (*(code *)PTR_FUN_060ccb10)(0);
      }
      iVar1 = aiStack_14[0];
      if (-1 < iVar2) {
        (*(code *)PTR_FUN_060ccb1c)(param_1,iVar2);
        iVar1 = aiStack_14[0];
      }
    }
  }
  return iVar1;
}



int FUN_060ccb28(int param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  uint local_1c [2];
  
  (*(code *)PTR_FUN_060ccb9c)(param_1,0,0,0,local_1c);
  puVar1 = PTR_FUN_060ccba0;
  iVar3 = 0;
  if ((local_1c[0] & 0x40) != 0) {
    iVar3 = -1;
  }
  do {
    iVar2 = (*(code *)puVar1)(param_1);
    if (iVar2 == 0) {
      return 0;
    }
    if (iVar2 < 0) {
      return iVar2;
    }
    if (*(int *)(param_1 + 0xa0) == 6) {
      return iVar2;
    }
  } while (((*(int *)(param_1 + 0x74) != 0) || (iVar3 < 0)) ||
          (iVar3 = iVar3 + 1, iVar3 <= DAT_060ccba4));
  return -0x16;
}



void FUN_060ccba8(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint local_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uStack_28 = param_3;
  uStack_24 = param_4;
  if (param_1 == 0) {
    uVar3 = 0xfffffff5;
  }
  else {
    iVar2 = (*(code *)PTR_FUN_060ccc98)(param_1);
    iVar2 = *(int *)(param_1 + 0x20) - iVar2;
    iVar4 = param_1 + 0x6c;
    if (param_2 < iVar2) {
      iVar2 = param_2;
    }
    uVar3 = 0xffffffef;
    if (-1 < iVar2) {
      bVar1 = *(int *)(param_1 + 4) != 0;
      if (!bVar1) {
        (*(code *)PTR_FUN_060ccc9c)(param_1 + 0xc,iVar2);
      }
      *(undefined4 *)(param_1 + 4) = 1;
      (*(code *)PTR_FUN_060ccca0)(param_1,0,0,0,&local_2c);
      if ((local_2c & 0x40) == 0) {
        if ((*(int *)(param_1 + 0xa0) == 0) || (*(int *)(param_1 + 0xa0) == 6)) {
          (*(code *)PTR_FUN_060ccca4)(iVar4,iVar2);
          (*(code *)PTR_FUN_060ccca8)(iVar4,uStack_28,uStack_24,1);
          (*(code *)PTR_FUN_060cccac)(iVar4);
          bVar1 = false;
        }
      }
      else {
        (*(code *)PTR_FUN_060ccca4)(iVar4,0);
        (*(code *)PTR_FUN_060ccca8)(iVar4,0,0,1);
      }
      uVar3 = 0xfffffff0;
      if (!bVar1) {
        (*(code *)PTR_FUN_060cccb0)(param_1);
        *(undefined4 *)(param_1 + 8) = 1;
        uVar3 = 0;
      }
    }
  }
  (*(code *)PTR_FUN_060ccc94)(uVar3);
  return;
}



void FUN_060cccb4(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 0xfffffff5;
  }
  else if (*(int *)(param_1 + 4) == 0) {
    iVar1 = (*(code *)PTR_FUN_060ccd20)(param_1);
    iVar1 = *(int *)(param_1 + 0x20) - iVar1;
    if (param_2 < iVar1) {
      iVar1 = param_2;
    }
    (*(code *)PTR_FUN_060ccd24)(param_1 + 0xc,iVar1);
    *(undefined4 *)(param_1 + 4) = 2;
    *(undefined4 *)(param_1 + 8) = 1;
    (*(code *)PTR_FUN_060ccd28)(param_1);
    uVar2 = 0;
  }
  else {
    uVar2 = 0xfffffff0;
  }
  (*(code *)PTR_FUN_060ccd1c)(uVar2);
  return;
}



undefined4 FUN_060ccd5c(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = (*(code *)PTR_FUN_060ccdac)(0xfffffff5);
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    (*(code *)PTR_FUN_060ccda0)();
    (*(code *)PTR_FUN_060ccda4)(param_1);
    uVar1 = (*(code *)PTR_FUN_060ccda8)(param_1);
    (*(code *)PTR_FUN_060ccdac)(0);
  }
  return uVar1;
}



void FUN_060ccdb0(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined *puVar1;
  undefined4 uVar2;
  uint local_18 [2];
  
  puVar1 = PTR_FUN_060cce24;
  if (param_1 == 0) {
    (*(code *)PTR_FUN_060cce20)(0xfffffff5);
  }
  else {
    *param_2 = *(undefined4 *)(param_1 + 4);
    (*(code *)puVar1)(param_1,0,0,0,local_18);
    if ((local_18[0] & 0x40) == 0) {
      if (*(int *)(param_1 + 4) == 2) {
        uVar2 = (*(code *)PTR_FUN_060cce28)(param_1);
        *param_3 = uVar2;
      }
      else {
        *param_3 = *(undefined4 *)(param_1 + 0x74);
      }
    }
    else {
      *param_3 = 0;
    }
  }
  (*(code *)PTR_FUN_060cce20)(0);
  return;
}



undefined4 FUN_060cce2c(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x28) == 0) {
    iVar1 = (*(code *)PTR_FUN_060cce58)(param_1 + 0xc);
    if (iVar1 == 2) {
      *(uint *)(param_1 + 8) = (uint)(iVar1 == 2);
    }
  }
  return *(undefined4 *)(param_1 + 8);
}



int FUN_060cce5c(int param_1)

{
  int *piVar1;
  undefined *puVar2;
  int iVar3;
  undefined auStack_14 [8];
  
  piVar1 = DAT_060ccef0;
  if (param_1 == 0) {
    iVar3 = (*(code *)PTR_FUN_060cceec)(0xfffffff5);
    return iVar3;
  }
  if (*(int *)(param_1 + 8) != 0) {
    if ((*DAT_060ccef0 == 1) && ((*(code *)PTR_FUN_060ccef4)(param_1,auStack_14), *piVar1 == 1))
    goto LAB_060ccedc;
    puVar2 = PTR_FUN_060ccefc;
    if (*(int *)(param_1 + 8) == -1) {
      iVar3 = (*(code *)PTR_FUN_060ccef8)(param_1);
      return iVar3;
    }
    iVar3 = (*(code *)PTR_FUN_060ccefc)(param_1);
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar3 = (*(code *)PTR_FUN_060ccf00)(param_1);
    if (iVar3 == 6) {
      iVar3 = (*(code *)puVar2)(param_1);
      if (iVar3 < 0) {
        return iVar3;
      }
      iVar3 = (*(code *)PTR_FUN_060ccf04)(param_1);
      if (iVar3 != 0) {
        *(undefined4 *)(param_1 + 4) = 0;
        *(undefined4 *)(param_1 + 8) = 0;
        (*(code *)PTR_FUN_060ccf08)(param_1);
      }
    }
  }
  (*(code *)PTR_FUN_060cceec)(0);
LAB_060ccedc:
  return *(int *)(param_1 + 8);
}



undefined4 FUN_060ccf90(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined4 uVar2;
  uint local_14 [2];
  
  if (param_1 == 0) {
    uVar2 = (*(code *)PTR_FUN_060ccfe8)(0xfffffff5);
  }
  else {
    (*(code *)PTR_FUN_060ccfec)(param_1,0,0,0,local_14);
    puVar1 = PTR_FUN_060ccfe8;
    if ((local_14[0] & 0x40) == 0) {
      uVar2 = *(undefined4 *)(param_1 + 0x58);
      *(undefined4 *)(param_1 + 0x58) = param_2;
      (*(code *)puVar1)(0);
    }
    else {
      uVar2 = 0xffffffef;
    }
  }
  return uVar2;
}



undefined4 FUN_060ccff0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint local_14 [2];
  
  if (param_1 == 0) {
    uVar1 = (*(code *)PTR_FUN_060cd04c)(0xfffffff5);
  }
  else {
    (*(code *)PTR_FUN_060cd050)(param_1,0,0,0,local_14);
    if ((local_14[0] & 0x40) == 0) {
      uVar1 = (*(code *)PTR_FUN_060cd054)(param_1 + 0x6c,param_2);
      (*(code *)PTR_FUN_060cd04c)(0);
    }
    else {
      uVar1 = 0xffffffef;
    }
  }
  return uVar1;
}



undefined4 FUN_060cd058(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined4 uVar2;
  uint local_14 [2];
  
  if (param_1 == 0) {
    uVar2 = (*(code *)PTR_FUN_060cd0b0)(0xfffffff5);
  }
  else {
    (*(code *)PTR_FUN_060cd0b4)(param_1,0,0,0,local_14);
    puVar1 = PTR_FUN_060cd0b0;
    if ((local_14[0] & 0x40) == 0) {
      uVar2 = *(undefined4 *)(param_1 + 0x68);
      *(undefined4 *)(param_1 + 0x68) = param_2;
      (*(code *)puVar1)(0);
    }
    else {
      uVar2 = 0xffffffef;
    }
  }
  return uVar2;
}



undefined4 FUN_060cd0b8(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint local_14 [2];
  
  if (param_1 == 0) {
    uVar1 = (*(code *)PTR_FUN_060cd114)(0xfffffff5);
  }
  else {
    (*(code *)PTR_FUN_060cd118)(param_1,0,0,0,local_14);
    if ((local_14[0] & 0x40) == 0) {
      uVar1 = (*(code *)PTR_FUN_060cd11c)(param_1 + 0x6c,param_2);
      (*(code *)PTR_FUN_060cd114)(0);
    }
    else {
      uVar1 = 0xffffffef;
    }
  }
  return uVar1;
}



void FUN_060cd23c(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = PTR_FUN_060cd264;
  iVar3 = *DAT_060cd260;
  iVar2 = (int)DAT_060cd25c;
  *(undefined4 *)(iVar3 + iVar2) = param_1;
  ((undefined4 *)(iVar3 + iVar2))[1] = param_2;
  (*(code *)puVar1)(0);
  return;
}



void FUN_060cd268(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*DAT_060cd288 + (int)DAT_060cd286);
  *param_1 = *puVar1;
  param_1[1] = puVar1[1];
  param_1[2] = puVar1[2];
  return;
}



void FUN_060cd390(void)

{
  int iVar1;
  
  iVar1 = *DAT_060cd3d0;
  *(undefined **)(iVar1 + 4) = PTR_LAB_060cd3d4;
  *(undefined **)(iVar1 + 8) = PTR_LAB_060cd3d8;
  *(undefined **)(iVar1 + 0xc) = PTR_LAB_060cd3dc;
  *(undefined **)(iVar1 + 0x10) = PTR_LAB_060cd3e0;
  *(undefined **)(iVar1 + 0x14) = PTR_LAB_060cd3e4;
  *(undefined **)(iVar1 + 0x18) = PTR_LAB_060cd3e8;
  *(undefined **)(iVar1 + 0x1c) = PTR_FUN_060cd3ec;
  *(undefined **)(iVar1 + 0x20) = PTR_FUN_060cd3f0;
  *(undefined **)(iVar1 + 0x24) = PTR_LAB_060cd3f4;
  *(undefined **)(iVar1 + 0x28) = PTR_LAB_060cd3f8;
  *(undefined **)(iVar1 + 0x2c) = PTR_FUN_060cd3fc;
  *(undefined **)(iVar1 + 0x30) = PTR_FUN_060cd400;
  return;
}



int FUN_060cd4a8(int *param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  puVar2 = PTR_FUN_060cd50c;
  puVar1 = PTR_FUN_060cd508;
  iVar4 = param_1[1];
  iVar5 = 0;
  if (0 < iVar4) {
    do {
      if (*param_1 == 0) {
        uVar3 = (*(code *)puVar1)(iVar5,param_1[2]);
      }
      else {
        uVar3 = (*(code *)puVar2)(iVar5,param_1[2]);
      }
    } while (((uVar3 & 1) == 0) && (iVar5 = iVar5 + 1, iVar5 < param_1[1]));
    iVar4 = param_1[1];
  }
  if (iVar4 < iVar5) {
    iVar5 = 0;
  }
  else {
    iVar5 = iVar5 + 1;
  }
  return iVar5;
}



int * FUN_060cd510(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = (int *)(*DAT_060cd554 + (int)DAT_060cd550);
  iVar2 = *(int *)*DAT_060cd554;
  iVar3 = 0;
  if (0 < iVar2) {
    do {
      if (*piVar1 == 0) break;
      iVar3 = iVar3 + 1;
      piVar1 = (int *)((int)piVar1 + (int)DAT_060cd552);
    } while (iVar3 < iVar2);
  }
  if (iVar3 == *(int *)*DAT_060cd554) {
    piVar1 = (int *)0x0;
  }
  else {
    *piVar1 = 1;
  }
  return piVar1;
}



void FUN_060cd558(undefined4 *param_1)

{
  *param_1 = 0;
  return;
}



void FUN_060cd564(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = DAT_060cd5dc;
  if (*(int *)((int)DAT_060cd5d6 + *DAT_060cd5dc) == param_1) {
    *(int *)((int)DAT_060cd5d6 + *DAT_060cd5dc) = 0;
    (*(code *)PTR_FUN_060cd5e0)(param_1,0xffffffff);
  }
  iVar4 = *piVar3;
  piVar3 = (int *)(iVar4 + DAT_060cd5d8);
  iVar2 = *piVar3;
  iVar1 = *(int *)(param_1 + 0x28);
  if ((iVar2 == param_1) || ((iVar1 != 0 && (iVar2 == 0)))) {
    *piVar3 = 0;
    (**(code **)(iVar1 * 0x10 + iVar4 + 8))(param_1 + 0xc,1);
    *(undefined4 *)(param_1 + 0x5c) = 0;
    *(undefined4 *)(param_1 + 100) = 0;
  }
  return;
}



int FUN_060cd5e4(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*DAT_060cd618 + (int)DAT_060cd616);
  puVar1[2] = param_1;
  if ((param_1 != 0) && ((code *)*puVar1 != (code *)0x0)) {
    (*(code *)*puVar1)(puVar1[1],param_1);
  }
  return param_1;
}



int FUN_060cd61c(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = *DAT_060cd658;
  piVar3 = (int *)(iVar2 + 0x34);
  iVar1 = 0;
  if (0 < *(int *)(iVar2 + 0x94)) {
    do {
      if (param_1 == *piVar3) break;
      iVar1 = iVar1 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar1 < *(int *)(iVar2 + 0x94));
  }
  if (iVar1 == *(int *)(iVar2 + 0x94)) {
    iVar1 = -1;
  }
  return iVar1;
}



void FUN_060cd65c(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (*(code *)PTR_FUN_060cd690)();
  if (iVar1 == -1) {
    piVar2 = (int *)(*DAT_060cd694 + 0x94);
    *(undefined4 *)(*DAT_060cd694 + 0x34 + *piVar2 * 4) = param_1;
    *piVar2 = *piVar2 + 1;
  }
  return;
}



void FUN_060cd698(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  
  if ((param_1 != 0) && (iVar1 = (*(code *)PTR_FUN_060cd6ec)(), iVar1 != -1)) {
    iVar5 = *DAT_060cd6f0 + 0x34;
    piVar3 = (int *)(*DAT_060cd6f0 + 0x94);
    iVar2 = *piVar3 + -1;
    *piVar3 = iVar2;
    if (iVar1 < iVar2) {
      puVar4 = (undefined4 *)(iVar1 * 4 + iVar5);
      do {
        iVar1 = iVar1 + 1;
        *puVar4 = puVar4[1];
        puVar4 = puVar4 + 1;
      } while (iVar1 < iVar2);
    }
    *(undefined4 *)(iVar5 + iVar1 * 4) = 0;
  }
  return;
}



int FUN_060cd6f4(int param_1,int param_2,undefined4 param_3)

{
  byte bVar3;
  int iVar1;
  code *pcVar2;
  
  if (param_1 == 0) {
    return 0;
  }
  (*(code *)PTR_FUN_060cd768)(param_1 + 0x6c);
  pcVar2 = (code *)PTR_FUN_060cd774;
  if (param_2 != 0) {
    bVar3 = *(byte *)(param_2 + 0xb) & 6;
    if (bVar3 == 4) {
      (*(code *)PTR_FUN_060cd76c)(param_1 + 0xc,param_2,param_3);
      iVar1 = 1;
      goto LAB_060cd74a;
    }
    if (bVar3 == 2) {
      pcVar2 = (code *)PTR_FUN_060cd770;
    }
  }
  iVar1 = (*pcVar2)(param_1 + 0xc,param_2,param_3);
LAB_060cd74a:
  if (iVar1 == 0) {
    return 0;
  }
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return param_1;
}



int FUN_060cd780(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int unaff_r10;
  int local_30;
  int iStack_2c;
  undefined local_28;
  undefined local_27;
  undefined local_26;
  undefined local_25;
  undefined auStack_24 [8];
  int iStack_1c;
  
  iVar1 = (*(code *)PTR_FUN_060cd848)(0,0);
  if (iVar1 == 5) {
LAB_060cd80a:
    unaff_r10 = -1;
  }
  else {
    if (iVar1 < 6) {
      if (iVar1 == 4) {
        return -2;
      }
    }
    else if (iVar1 == 6) {
      return -0x19;
    }
    local_30 = (*(code *)PTR_FUN_060cd84c)();
    local_30 = DAT_060cd844 + local_30;
    iVar4 = (int)DAT_060cd846;
    local_26 = 0;
    local_25 = 0;
    local_28 = 0;
    local_27 = 0;
    iStack_2c = iVar4;
    uVar2 = (*(code *)PTR_FUN_060cd850)();
    iVar1 = (*(code *)PTR_FUN_060cd854)(uVar2,&local_30,0);
    if (iVar1 != 0) {
      iVar3 = (*(code *)PTR_FUN_060cd858)(iVar1,1,param_1,iVar4);
      if (iVar3 != iVar4) goto LAB_060cd80a;
      (*(code *)PTR_FUN_060cd85c)(auStack_24);
      unaff_r10 = iStack_1c;
    }
    if ((unaff_r10 == 0) &&
       (iVar4 = (*(code *)PTR_FUN_060cd864)(param_1,PTR_DAT_060cd860,6), iVar4 != 0)) {
      unaff_r10 = -3;
    }
    (*(code *)PTR_FUN_060cd868)(iVar1);
  }
  return unaff_r10;
}



int FUN_060cd86c(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined extraout_r2;
  int iVar5;
  int extraout_r3;
  
  piVar1 = DAT_060cd95c;
  if ((*(uint *)(*DAT_060cd95c + (int)DAT_060cd94c) & 1) == 0) {
    iVar2 = -2;
  }
  else {
    iVar2 = (*(code *)PTR_FUN_060cd960)(*DAT_060cd95c + (int)DAT_060cd94e);
    if (iVar2 == 0) {
      iVar5 = *piVar1 + (int)DAT_060cd950;
      *(undefined *)param_1 = *(undefined *)(iVar5 + 6);
      *(undefined *)((int)param_1 + 1) = *(undefined *)(iVar5 + 7);
      *(undefined *)((int)param_1 + 2) = *(undefined *)(iVar5 + 8);
      *(undefined *)((int)param_1 + 3) = *(undefined *)(iVar5 + 9);
      iVar3 = *param_1;
      iVar4 = (int)DAT_060cd952;
      *param_1 = iVar3 + iVar4;
      iVar2 = -3;
      if (((int)DAT_060cd954 < iVar3 + iVar4) && (0 < *(int *)(iVar5 + 0xe))) {
        iVar3 = *(int *)(iVar5 + 0xe) + (int)DAT_060cd956;
        if (iVar3 < 0) {
          iVar3 = iVar3 + DAT_060cd956;
        }
        (*(code *)PTR_FUN_060cd964)();
        iVar2 = 0;
        param_1[1] = iVar3 * DAT_060cd958;
        *(undefined *)((int)param_1 + 10) = extraout_r2;
        *(undefined *)(extraout_r3 + 0xb) = 0x80;
        *(undefined *)(param_1 + 2) = extraout_r2;
        *(undefined *)((int)param_1 + 9) = extraout_r2;
      }
    }
  }
  return iVar2;
}



int FUN_060cd968(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined auStack_20 [4];
  undefined4 uStack_1c;
  
  iVar1 = (*(code *)PTR_FUN_060cd9d8)(auStack_20);
  iVar3 = 0;
  if (iVar1 == 0) {
    uVar2 = (*(code *)PTR_FUN_060cd9dc)();
    iVar3 = (*(code *)PTR_FUN_060cd9e0)(uVar2,auStack_20,0);
  }
  if ((((*(uint *)(*DAT_060cd9e4 + (int)DAT_060cd9d6) & 1) == 0) || (iVar3 != 0)) &&
     (iVar1 = (*(code *)PTR_FUN_060cd9e8)(iVar3,param_1,uStack_1c), iVar3 != 0)) {
    (*(code *)PTR_FUN_060cd9ec)(iVar3);
  }
  return iVar1;
}



int FUN_060cd9f0(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = DAT_060cda90;
  iVar2 = *(int *)(param_1 + 0x5c);
  if ((iVar2 != 4) &&
     ((*(int *)(*DAT_060cda90 + (int)DAT_060cda8a) == 0 ||
      (iVar2 = 7, *(int *)(*DAT_060cda90 + (int)DAT_060cda8a) == param_1)))) {
    iVar2 = (**(code **)(*DAT_060cda90 + *(int *)(param_1 + 0x28) * 0x10 + 4))(param_1 + 0xc);
    if (iVar2 == 1) {
      *(int *)(*piVar1 + (int)DAT_060cda8a) = param_1;
    }
    else if (iVar2 == 4) {
      iVar3 = *piVar1;
      if (*(int *)(iVar3 + DAT_060cda8a) == param_1) {
        *(int *)(iVar3 + DAT_060cda8a) = 0;
        iVar4 = (int)DAT_060cda8c;
        *(undefined4 *)(DAT_060cda8e + iVar3) = 0;
        *(undefined4 *)(iVar4 + iVar3) = 0;
      }
    }
    *(int *)(param_1 + 0x5c) = iVar2;
    iVar2 = (*(code *)PTR_FUN_060cda94)(param_1,iVar2);
  }
  return iVar2;
}



int FUN_060cda98(int param_1)

{
  int iVar1;
  uint local_14;
  int aiStack_10 [2];
  
  aiStack_10[0] = 0;
  if ((*(int *)((int)DAT_060cdb3c + *DAT_060cdb40) == param_1) ||
     (iVar1 = 1, *(int *)((int)DAT_060cdb3c + *DAT_060cdb40) == 0)) {
    (*(code *)PTR_FUN_060cdb44)(param_1,0,0,0,&local_14);
    if ((local_14 & 0x40) == 0) {
      iVar1 = (*(code *)PTR_FUN_060cdb48)(param_1 + 0x6c);
      if (iVar1 == 0) {
        iVar1 = (*(code *)PTR_FUN_060cdb4c)(param_1);
      }
      else {
        iVar1 = (*(code *)PTR_FUN_060cdb50)(param_1,aiStack_10);
      }
      if (iVar1 == 6) {
        if (*(int *)((int)DAT_060cdb3c + *DAT_060cdb40) == param_1) {
          *(int *)((int)DAT_060cdb3c + *DAT_060cdb40) = 0;
        }
      }
      else if ((*(int *)((int)DAT_060cdb3c + *DAT_060cdb40) == 0) && (aiStack_10[0] == 1)) {
        *(int *)((int)DAT_060cdb3c + *DAT_060cdb40) = param_1;
      }
    }
    else {
      iVar1 = 6;
    }
  }
  return iVar1;
}



void FUN_060cdbac(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 0x1c) == 0) {
    (*(code *)PTR_FUN_060cdbe8)();
  }
  else {
    *(undefined4 *)(param_1 + 0x54) = param_2;
    *(undefined4 *)(param_1 + 0x58) = 0;
  }
  *(undefined4 *)(param_1 + 0x50) = 0;
  return;
}



void FUN_060cdbec(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 *param_5,int *param_6,uint *param_7,uint *param_8)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *param_1;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = param_1[1];
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = param_1[4];
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = param_1[5];
  }
  if (param_6 != (int *)0x0) {
    *param_6 = param_1[4] - param_1[6];
  }
  if (param_7 != (uint *)0x0) {
    *param_7 = (uint)*(byte *)((int)param_1 + 0xe);
  }
  if (param_8 != (uint *)0x0) {
    *param_8 = (uint)*(byte *)((int)param_1 + 0xf);
  }
  return;
}



void FUN_060cdc50(int param_1)

{
  int iVar1;
  code *pcVar2;
  
  if (param_1 != 0) {
    (*(code *)PTR_FUN_060cdc90)();
    (*(code *)PTR_FUN_060cdc94)(param_1);
    iVar1 = *(int *)(param_1 + 0x28);
    pcVar2 = (code *)PTR_FUN_060cdc98;
    if ((iVar1 == 0) || (pcVar2 = (code *)PTR_FUN_060cdc9c, iVar1 == 2)) {
      (*pcVar2)((int *)(param_1 + 0x28));
    }
  }
  return;
}



undefined4 FUN_060cdca0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x58);
}



undefined4 FUN_060cdcac(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint local_10 [2];
  
  (*(code *)PTR_FUN_060cdcf8)(param_1,0,0,0,local_10);
  if (*(int *)(param_1 + 0x5c) == 4) {
    iVar1 = (*(code *)PTR_FUN_060cdcfc)(param_1);
    if ((iVar1 == 0) || (uVar2 = 0, (local_10[0] & 0x40) != 0)) {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



undefined4 FUN_060cdd00(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  switch(param_2) {
  case 3:
    iVar1 = (*(code *)PTR_FUN_060cdd6c)(param_1);
    if (iVar1 != 1) {
      return 0;
    }
    uVar2 = 0xffffffe8;
    break;
  default:
    *(undefined4 *)(param_1 + 8) = 1;
    return 0;
  case 5:
    uVar2 = 0xffffffe9;
    break;
  case 6:
    uVar2 = 0xfffffffe;
    break;
  case 7:
    uVar2 = 0xffffffec;
    break;
  case 8:
    uVar2 = 0xffffffff;
    break;
  case 9:
    uVar2 = 0xffffffe7;
  }
  *(undefined4 *)(param_1 + 8) = uVar2;
  uVar2 = (*(code *)PTR_FUN_060cdd70)();
  return uVar2;
}



bool FUN_060cde14(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int extraout_r1;
  int iVar3;
  int extraout_r2;
  int extraout_r3;
  code *pcVar4;
  uint uVar5;
  
  if (param_2 == (undefined4 *)0x0) {
    *param_1 = param_3;
    iVar1 = (*(code *)PTR_FUN_060cdf48)(param_3,param_1 + 1);
    if (iVar1 != 0) {
      return false;
    }
    uVar5 = param_1[2];
  }
  else {
    uVar5 = param_2[1];
    if (((int)*(char *)((int)param_2 + 0xb) & 0x80U) != 0) {
      iVar1 = uVar5 + (int)DAT_060cdf44;
      if (iVar1 < 0) {
        iVar1 = iVar1 + DAT_060cdf44;
      }
      (*(code *)PTR_FUN_060cdf4c)();
      uVar5 = iVar1 << 0xb;
    }
    *param_1 = param_3;
    param_1[1] = *param_2;
    param_1[2] = uVar5;
    *(undefined *)(param_1 + 3) = *(undefined *)(param_2 + 2);
    *(undefined *)((int)param_1 + 0xd) = *(undefined *)((int)param_2 + 9);
    *(undefined *)((int)param_1 + 0xe) = *(undefined *)((int)param_2 + 10);
    *(undefined *)((int)param_1 + 0xf) = *(undefined *)((int)param_2 + 0xb);
  }
  uVar2 = (*(code *)PTR_FUN_060cdf50)(*(undefined *)((int)param_2 + 0xb));
  param_1[4] = uVar2;
  iVar1 = (int)DAT_060cdf44;
  param_1[5] = uVar5 + iVar1 >> 0xb;
  if (param_1[4] == 0) {
    param_1[6] = 0;
  }
  else {
    if ((int)uVar5 < 0) {
      uVar5 = uVar5 + iVar1;
    }
    pcVar4 = (code *)PTR_FUN_060cdf4c;
    (*(code *)PTR_FUN_060cdf4c)();
    iVar3 = (int)DAT_060cdf46 - (extraout_r1 + uVar5 * -0x800);
    if (iVar3 < 0) {
      iVar3 = iVar3 + iVar1;
    }
    (*pcVar4)();
    param_1[6] = extraout_r2 - iVar3 * extraout_r3;
  }
  iVar1 = (*(code *)PTR_FUN_060cdf54)(param_1);
  if (iVar1 != 0) {
    param_1[0x13] = 0;
    param_1[0x14] = 0;
    param_1[0x16] = 0;
    param_1[0x15] = 0;
    param_1[0x17] = DAT_060cdf58;
  }
  return iVar1 != 0;
}



void FUN_060cdf5c(int param_1,int param_2)

{
  int iVar1;
  
  *(int *)(param_1 + 0x54) = param_2;
  iVar1 = (*(code *)PTR_FUN_060cdf9c)(param_1,DAT_060cdf98,0);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  if (param_2 < iVar1) {
    iVar1 = param_2;
  }
  *(int *)(param_1 + 0x58) = iVar1;
  return;
}



void FUN_060cdfa0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 *param_5,int *param_6,uint *param_7,uint *param_8)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *param_1;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = param_1[1];
  }
  if (param_7 != (uint *)0x0) {
    *param_7 = (uint)*(byte *)((int)param_1 + 0xe);
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = param_1[4];
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = param_1[5];
  }
  if (param_8 != (uint *)0x0) {
    *param_8 = (uint)*(byte *)((int)param_1 + 0xf);
  }
  if (param_6 != (int *)0x0) {
    if ((*(byte *)((int)param_1 + 0xf) & 0x18) == 0x18) {
      *param_6 = 0;
    }
    else {
      *param_6 = param_1[4] - param_1[6];
    }
  }
  return;
}



undefined4 FUN_060ce1d4(int param_1)

{
  int iVar1;
  undefined4 local_20 [2];
  undefined4 uStack_18;
  undefined local_10;
  
  iVar1 = (*(code *)PTR_FUN_060ce214)(param_1 + 0x1c);
  if (iVar1 != 0) {
    local_20[0] = 3;
    uStack_18 = 3;
    local_10 = 0xff;
    iVar1 = (*(code *)PTR_FUN_060ce218)(local_20,*(undefined4 *)(param_1 + 0x38));
    if (iVar1 == 0) {
      return 2;
    }
  }
  return 8;
}



int FUN_060ce2e8(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (uint)*(byte *)(param_1 + 0xc);
  if (uVar2 != 0) {
    iVar1 = (*(code *)PTR_FUN_060ce338)(param_2,uVar2);
    param_2 = (param_2 - iVar1 * uVar2) + iVar1 * (*(byte *)(param_1 + 0xd) + uVar2);
  }
  return param_2;
}



undefined4 FUN_060ce33c(undefined4 *param_1,uint *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  byte local_1c [8];
  undefined4 uStack_14;
  
  uVar1 = (*(code *)PTR_FUN_060ce3c0)(local_1c);
  if (param_2 != (uint *)0x0) {
    *param_2 = uVar1;
  }
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = uStack_14;
  }
  if ((uVar1 & 0x20) == 0) {
    switch(local_1c[0] & 0xf) {
    case 0:
    case 4:
      uVar2 = 2;
      break;
    case 1:
    case 2:
      uVar2 = 0;
      break;
    case 3:
    case 5:
    case 8:
      uVar2 = 1;
      break;
    case 6:
      goto switchD_060ce37e_caseD_6;
    case 7:
      uVar2 = 4;
      break;
    default:
      uVar2 = 5;
      break;
    case 10:
      uVar2 = 6;
    }
  }
  else {
switchD_060ce37e_caseD_6:
    uVar2 = 3;
  }
  return uVar2;
}



int FUN_060ce3c4(uint param_1)

{
  int iVar1;
  
  if ((param_1 & 0x40) == 0) {
    if ((param_1 & 0x10) == 0) {
      iVar1 = (int)DAT_060ce3fc;
    }
    else {
      iVar1 = (int)DAT_060ce3fa;
      if ((param_1 & 8) != 0) {
        iVar1 = 0;
      }
    }
  }
  else {
    iVar1 = (int)DAT_060ce3f8;
  }
  return iVar1;
}



undefined4 FUN_060ce400(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  switch(param_2) {
  case 0:
    iVar1 = (*(code *)PTR_FUN_060ce460)();
    if (iVar1 != 0) goto LAB_060ce454;
    uVar2 = 3;
    break;
  case 1:
  case 2:
LAB_060ce454:
    *param_3 = 1;
    return 1;
  case 3:
    uVar2 = 5;
    break;
  case 4:
    uVar2 = 6;
    break;
  default:
    uVar2 = 8;
    break;
  case 6:
    uVar2 = 9;
  }
  *param_3 = uVar2;
  return 0;
}



undefined4 FUN_060ce464(int param_1,int *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  iVar4 = *(int *)(param_1 + 0x54) - *(int *)(param_1 + 0x58);
  *param_2 = iVar4;
  if (*(int *)(param_1 + 0x5c) < iVar4) {
    *param_2 = *(int *)(param_1 + 0x5c);
  }
  uVar1 = (*(code *)PTR_FUN_060ce594)(param_1 + 0x1c);
  iVar2 = (*(code *)PTR_FUN_060ce598)(param_1,uVar1);
  iVar2 = iVar2 + *(int *)(param_1 + 4);
  iVar4 = 0;
  if (*(int *)(param_1 + 0x4c) == 1) {
    iVar3 = (*(code *)PTR_FUN_060ce5a0)(param_1,DAT_060ce59c,0);
    iVar4 = iVar3;
    if (iVar3 < 0) {
      iVar4 = 0;
    }
    if ((0 < iVar3) && (iVar2 < *(int *)((int)DAT_060ce590 + *DAT_060ce5a4))) {
      iVar4 = iVar4 - (*(int *)((int)DAT_060ce590 + *DAT_060ce5a4) - iVar2);
    }
  }
  iVar3 = *param_2;
  if (iVar4 < iVar3) {
    *param_2 = iVar3 - iVar4;
    *(int *)(param_1 + 0x44) = iVar2;
    iVar4 = (*(code *)PTR_FUN_060ce594)(param_1 + 0x1c);
    iVar4 = (*(code *)PTR_FUN_060ce598)(param_1,iVar4 + *param_2);
    iVar4 = iVar4 + *(int *)(param_1 + 4);
    *(int *)(param_1 + 0x48) = iVar4;
    iVar3 = *(int *)(param_1 + 0x44);
    piVar6 = (int *)(*DAT_060ce5a4 + (int)DAT_060ce590);
    iVar2 = *piVar6;
    if (iVar3 < iVar2) {
      return 1;
    }
    iVar5 = *(int *)(*DAT_060ce5a4 + (int)DAT_060ce592);
    if (((iVar5 <= iVar3) || (iVar4 <= iVar2)) || (iVar5 < iVar4)) {
      return 1;
    }
    *piVar6 = iVar3;
    *param_3 = 1;
  }
  else {
    iVar3 = *(int *)(param_1 + 0x58) + iVar3;
    *(int *)(param_1 + 0x58) = iVar3;
    if (*(int *)(param_1 + 0x54) == iVar3) {
      *param_3 = 4;
      *(undefined4 *)((int)DAT_060ce590 + *DAT_060ce5a4) =
           *(undefined4 *)((int)DAT_060ce592 + *DAT_060ce5a4);
    }
    else {
      *param_3 = 2;
      *(int *)((int)DAT_060ce590 + *DAT_060ce5a4) = iVar2;
    }
  }
  return 0;
}



void FUN_060ce5d0(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  int extraout_r2;
  int iVar2;
  int extraout_r2_00;
  uint uVar3;
  int extraout_r3;
  code *pcVar4;
  int iVar5;
  
  iVar5 = (int)DAT_060ce682;
  uVar3 = param_2[1];
  iVar1 = (int)DAT_060ce684;
  *param_1 = param_3;
  param_1[1] = 0;
  param_1[2] = uVar3;
  *(undefined *)(param_1 + 3) = *(undefined *)(param_2 + 2);
  *(undefined *)((int)param_1 + 0xd) = *(undefined *)((int)param_2 + 9);
  *(undefined *)((int)param_1 + 0xe) = 0;
  *(undefined *)((int)param_1 + 0xf) = *(undefined *)((int)param_2 + 0xb);
  param_1[4] = iVar5;
  param_1[5] = uVar3 + iVar1 >> 0xb;
  if ((int)uVar3 < 0) {
    uVar3 = uVar3 + iVar1;
  }
  pcVar4 = (code *)PTR_FUN_060ce688;
  iVar1 = (*(code *)PTR_FUN_060ce688)();
  iVar2 = extraout_r2 - (extraout_r3 - uVar3 * iVar5);
  if (iVar2 < 0) {
    iVar2 = iVar2 + iVar1;
  }
  (*pcVar4)();
  param_1[6] = extraout_r2_00 - iVar2 * iVar5;
  (*(code *)PTR_FUN_060ce68c)(param_1,*param_2);
  param_1[0x13] = 0;
  param_1[0x16] = 0;
  param_1[0x15] = 0;
  param_1[0x17] = DAT_060ce690;
  return;
}



int FUN_060ce6fc(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x14) < param_2) {
    param_2 = *(int *)(param_1 + 0x14);
  }
  iVar1 = *(int *)(param_1 + 0x24);
  if (param_2 < 0) {
    param_2 = 0;
  }
  if ((param_2 < iVar1) || (*(int *)(param_1 + 0x2c) + iVar1 < param_2)) {
    *(int *)(param_1 + 0x24) = param_2;
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  else if (*(int *)(param_1 + 0x4c) == 1) {
    *(int *)(param_1 + 0x28) = param_2 - iVar1;
  }
  else {
    *(int *)(param_1 + 0x24) = param_2;
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) - (param_2 - iVar1);
  }
  return param_2;
}



int FUN_060ce754(int param_1)

{
  return *(int *)(param_1 + 0x24) + *(int *)(param_1 + 0x28);
}



undefined4 FUN_060ce7a8(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int extraout_r2;
  int iVar3;
  int extraout_r2_00;
  uint uVar4;
  int extraout_r3;
  code *pcVar5;
  int iVar6;
  
  iVar1 = (*(code *)*DAT_060ce87c)(*param_2);
  uVar2 = 0;
  if (iVar1 == 0) {
    iVar6 = (int)DAT_060ce876;
    uVar4 = param_2[1];
    iVar1 = (int)DAT_060ce878;
    *param_1 = param_3;
    param_1[1] = 0;
    param_1[2] = uVar4;
    *(undefined *)(param_1 + 3) = *(undefined *)(param_2 + 2);
    *(undefined *)((int)param_1 + 0xd) = *(undefined *)((int)param_2 + 9);
    *(undefined *)((int)param_1 + 0xe) = 0;
    *(undefined *)((int)param_1 + 0xf) = *(undefined *)((int)param_2 + 0xb);
    param_1[4] = iVar6;
    param_1[5] = uVar4 + iVar1 >> 0xb;
    if ((int)uVar4 < 0) {
      uVar4 = uVar4 + iVar1;
    }
    pcVar5 = (code *)PTR_FUN_060ce880;
    (*(code *)PTR_FUN_060ce880)();
    iVar3 = extraout_r2 - (extraout_r3 - uVar4 * iVar6);
    if (iVar3 < 0) {
      iVar3 = iVar3 + iVar1;
    }
    (*pcVar5)();
    param_1[6] = extraout_r2_00 - iVar3 * iVar6;
    (*(code *)PTR_FUN_060ce884)(param_1,*param_2);
    param_1[0x13] = 0;
    param_1[0x16] = 0;
    param_1[0x15] = 0;
    param_1[0x17] = DAT_060ce888;
    uVar2 = 1;
  }
  return uVar2;
}



int FUN_060ce8f4(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x14) < param_2) {
    param_2 = *(int *)(param_1 + 0x14);
  }
  iVar1 = *(int *)(param_1 + 0x24);
  if (param_2 < 0) {
    param_2 = 0;
  }
  if ((param_2 < iVar1) || (*(int *)(param_1 + 0x2c) + iVar1 < param_2)) {
    *(int *)(param_1 + 0x24) = param_2;
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  else if (*(int *)(param_1 + 0x4c) == 1) {
    *(int *)(param_1 + 0x28) = param_2 - iVar1;
  }
  else {
    *(int *)(param_1 + 0x24) = param_2;
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) - (param_2 - iVar1);
  }
  return param_2;
}



int FUN_060ce94c(int param_1)

{
  return *(int *)(param_1 + 0x24) + *(int *)(param_1 + 0x28);
}



void FUN_060ce95c(int param_1)

{
  (*(code *)*DAT_060ce974)(*(undefined4 *)(param_1 + 4));
  return;
}



void FUN_060ce978(undefined4 param_1,int *param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  
  if (*param_2 == 0) {
    iVar3 = param_2[1];
    iVar2 = param_2[2];
    pcVar1 = (code *)PTR_FUN_060ce9a0;
  }
  else {
    iVar3 = param_2[1];
    iVar2 = param_2[2];
    pcVar1 = (code *)PTR_FUN_060ce9a4;
  }
  (*pcVar1)(param_1,iVar2,iVar3);
  return;
}



int FUN_060ce9a8(int param_1,undefined4 param_2,int param_3)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  
  puVar1 = PTR_FUN_060cea04;
  iVar3 = 0;
  if (0 < param_3) {
    pbVar4 = (byte *)(param_1 + 0xb);
    do {
      iVar2 = (*(code *)puVar1)(param_2,param_1 + 0xc,0xc);
      if (iVar2 == 0) {
        return iVar3;
      }
      iVar3 = iVar3 + 1;
      if ((*pbVar4 & 1) != 0) {
        return -1;
      }
      pbVar4 = pbVar4 + 0x18;
      param_1 = param_1 + 0x18;
    } while (iVar3 < param_3);
  }
  return -1;
}



int FUN_060cea08(int param_1,int param_2)

{
  return param_2 + param_1 * 0xc;
}



int FUN_060cea1c(int param_1,int param_2)

{
  return param_2 + param_1 * 0x18;
}



undefined FUN_060cea30(int param_1,int param_2)

{
  return *(undefined *)(param_1 * 0xc + param_2 + 0xb);
}



undefined FUN_060cea48(int param_1,int param_2)

{
  return *(undefined *)(param_1 * 0x18 + param_2 + 0xb);
}



void FUN_060cea60(void)

{
  (*(code *)PTR_FUN_060cea74)(0xffffffff);
  return;
}



undefined4 FUN_060cea78(undefined4 param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_14 [2];
  
  (*(code *)PTR_FUN_060ceadc)(DAT_060cead8);
  puVar1 = PTR_FUN_060ceae0;
  do {
    iVar2 = (*(code *)puVar1)(param_1,0x17,local_14);
    if (iVar2 == -5) {
      return 0xfffffff9;
    }
    iVar2 = (*(code *)PTR_FUN_060ceae4)();
    if (iVar2 == -0xc) {
      return 0xffffffea;
    }
    if (iVar2 == -0x10) goto LAB_060ceabc;
  } while (iVar2 != 0);
  iVar2 = (*(code *)PTR_FUN_060ceae8)();
  if (iVar2 == -0x10) {
LAB_060ceabc:
    uVar3 = 0xffffffe7;
  }
  else {
    uVar3 = 0xffffffff;
    if (iVar2 == 0) {
      uVar3 = local_14[0];
    }
  }
  return uVar3;
}



// WARNING: Restarted to delay deadcode elimination for space: stack

int FUN_060ceaec(undefined4 param_1,int param_2,int param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  short sVar7;
  undefined auStack_80 [20];
  undefined auStack_6c [8];
  char local_64;
  undefined auStack_60 [16];
  undefined4 auStack_50 [4];
  undefined auStack_40 [4];
  undefined4 local_3c;
  undefined auStack_38 [4];
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  
  local_2c = param_2;
  iVar4 = (*(code *)PTR_FUN_060ced04)();
  puVar1 = PTR_FUN_060ced08;
  local_34 = 0;
  if (0 < iVar4) {
    do {
      (*(code *)puVar1)(local_34,0);
      local_34 = local_34 + 1;
    } while (local_34 < iVar4);
  }
  (*(code *)PTR_FUN_060ced0c)(auStack_80,param_1);
  local_28 = 0;
  if (0 < param_3) {
    do {
      iVar5 = (*(code *)PTR_FUN_060ced10)(auStack_80,auStack_6c);
      if (iVar5 != 0) {
        return iVar5;
      }
      if (local_64 == '\0') break;
      local_34 = 0;
      if (0 < iVar4) {
        do {
          uVar6 = (*(code *)PTR_FUN_060ced1c)(local_34);
          iVar5 = (*(code *)PTR_FUN_060ced20)(auStack_60,uVar6,0xc);
          if (iVar5 == 0) {
            (*(code *)PTR_FUN_060ced14)(local_34,auStack_40,&local_3c,auStack_38);
            (*(code *)PTR_FUN_060ced18)(param_2,local_34,local_3c);
            break;
          }
          local_34 = local_34 + 1;
        } while (local_34 < iVar4);
      }
      if (local_34 == iVar4) {
        iVar5 = (*(code *)PTR_FUN_060ced24)(auStack_60,&local_34,&local_3c);
        if (iVar5 == 1) {
          (*(code *)PTR_FUN_060ced28)(param_2,local_34,local_3c);
        }
        else {
          (*(code *)PTR_FUN_060ced2c)(param_2,auStack_6c);
        }
      }
      param_2 = param_2 + 0xc;
      param_3 = param_3 + -1;
      local_28 = local_28 + 1;
    } while (0 < param_3);
  }
  puVar1 = PTR_FUN_060ced18;
  local_34 = 0;
  if (0 < iVar4) {
    do {
      if (param_3 < 1) break;
      sVar7 = (*(code *)PTR_FUN_060ced30)(local_34);
      if (sVar7 != 1) {
        (*(code *)PTR_FUN_060ced14)(local_34,auStack_40,&local_3c,auStack_38);
        param_3 = param_3 + -1;
        (*(code *)puVar1)(param_2,local_34,local_3c);
        param_2 = param_2 + 0xc;
        local_28 = local_28 + 1;
      }
      local_34 = local_34 + 1;
    } while (local_34 < iVar4);
  }
  (*(code *)PTR_FUN_060ced34)(iVar4);
  if ((*(uint *)(*DAT_060ced38 + (int)DAT_060ced02) & 2) != 0) {
    (*(code *)*DAT_060ced3c)(&local_30);
    puVar3 = DAT_060ced44;
    puVar2 = PTR_FUN_060ced40;
    puVar1 = PTR_FUN_060ced28;
    local_34 = 0;
    if (0 < local_30) {
      do {
        if (param_3 < 1) break;
        iVar4 = (*(code *)puVar2)(local_2c,param_2,local_34);
        if (iVar4 != 1) {
          (*(code *)*puVar3)(local_34,auStack_50);
          (*(code *)puVar1)(param_2,local_34,auStack_50[0]);
        }
        local_28 = local_28 + 1;
        local_34 = local_34 + 1;
        param_2 = param_2 + 0xc;
      } while (local_34 < local_30);
    }
  }
  *(byte *)(param_2 + -1) = *(byte *)(param_2 + -1) | 1;
  return local_28;
}



int FUN_060ced48(undefined4 param_1,int param_2,int param_3)

{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  byte *pbVar6;
  int iVar7;
  int iVar8;
  undefined auStack_7c [20];
  undefined auStack_68 [8];
  char local_60;
  undefined auStack_5c [16];
  undefined4 uStack_4c;
  undefined auStack_48 [12];
  int local_3c;
  undefined auStack_38 [4];
  undefined4 local_34;
  undefined auStack_30 [4];
  int local_2c;
  int local_28;
  int local_24;
  
  local_2c = param_2;
  (*(code *)PTR_FUN_060cef00)(auStack_7c,param_1);
  puVar2 = PTR_FUN_060cef04;
  iVar8 = 0;
  if (0 < param_3) {
    do {
      iVar3 = (*(code *)PTR_FUN_060cef08)(auStack_7c,auStack_68);
      if (iVar3 != 0) {
        return iVar3;
      }
      if (local_60 == '\0') break;
      if ((iVar8 < 3) || (iVar3 = (*(code *)puVar2)(param_2 + -0xc,auStack_5c,0xc), iVar3 != 0)) {
        (*(code *)PTR_FUN_060cef0c)(param_2,auStack_68);
        (*(code *)PTR_FUN_060cef10)(param_2 + 0xc,auStack_5c,0xc);
      }
      param_2 = param_2 + 0x18;
      param_3 = param_3 + -1;
      iVar8 = iVar8 + 1;
    } while (0 < param_3);
  }
  if ((*(uint *)(*DAT_060cef14 + (int)DAT_060ceefc) & 2) != 0) {
    (*(code *)*DAT_060cef18)(&local_3c);
    iVar3 = 0;
    iVar7 = 0;
    if (0 < local_3c) {
      bVar1 = param_3 < 1;
      do {
        if (bVar1) break;
        (*(code *)*DAT_060cef1c)(iVar3,&uStack_4c);
        iVar4 = (*(code *)PTR_FUN_060cef20)(local_2c,iVar8,auStack_48);
        if (iVar4 == 0) {
          local_24 = iVar8 + iVar7;
          iVar4 = local_2c + local_24 * 0x18;
          (*(code *)PTR_FUN_060cef24)(iVar4,iVar3,uStack_4c);
          (*(code *)PTR_FUN_060cef10)(iVar4 + 0xc,auStack_48,0xc);
          iVar7 = iVar7 + 1;
        }
        else {
          (*(code *)PTR_FUN_060cef24)(iVar4,iVar3,uStack_4c);
        }
        iVar3 = iVar3 + 1;
        bVar1 = param_3 <= iVar7;
      } while (iVar3 < local_3c);
    }
    iVar8 = iVar8 + iVar7;
  }
  iVar7 = 0;
  local_28 = (*(code *)PTR_FUN_060cef28)();
  iVar3 = 0;
  if (0 < local_28) {
    bVar1 = param_3 < 1;
    do {
      if (bVar1) break;
      uVar5 = (*(code *)PTR_FUN_060cef2c)(iVar3);
      iVar4 = (*(code *)PTR_FUN_060cef20)(local_2c,iVar8,uVar5);
      (*(code *)PTR_FUN_060cef30)(iVar3,auStack_38,&local_34,auStack_30);
      if (iVar4 == 0) {
        local_24 = iVar8 + iVar7;
        iVar4 = local_2c + local_24 * 0x18;
        (*(code *)PTR_FUN_060cef34)(iVar4,iVar3,local_34);
        uVar5 = (*(code *)PTR_FUN_060cef2c)(iVar3);
        (*(code *)PTR_FUN_060cef10)(iVar4 + 0xc,uVar5,0xc);
        iVar7 = iVar7 + 1;
      }
      else {
        (*(code *)PTR_FUN_060cef8c)(iVar4,iVar3,local_34);
      }
      iVar3 = iVar3 + 1;
      bVar1 = param_3 <= iVar7;
    } while (iVar3 < local_28);
  }
  (*(code *)PTR_FUN_060cef90)(local_28);
  pbVar6 = (byte *)(local_2c + (iVar8 + iVar7) * 0x18 + -0xd);
  *pbVar6 = *pbVar6 | 1;
  return iVar8 + iVar7;
}



void FUN_060cef94(int *param_1,int param_2)

{
  *param_1 = param_2;
  param_1[1] = *DAT_060cefb8 + (int)DAT_060cefb4;
  param_1[2] = -1;
  param_1[4] = *(int *)(param_2 + 0x20);
  param_1[3] = 0;
  return;
}



int FUN_060cefbc(int *param_1,int param_2,uint param_3)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (*param_1 == 0) {
    (*(code *)PTR_FUN_060cf070)(param_2,0);
    return 0;
  }
  if ((param_1[2] == -1) || ((int)DAT_060cf06a < param_1[2])) {
    iVar3 = (int)DAT_060cf06c;
    iVar2 = (*(code *)PTR_FUN_060cf074)(*param_1,1,param_1[1],iVar3);
    if (iVar2 == iVar3) {
      param_1[2] = 0;
      goto LAB_060cf00e;
    }
LAB_060cf006:
    if (-1 < iVar2) {
      iVar2 = -1;
    }
  }
  else {
LAB_060cf00e:
    puVar1 = PTR_FUN_060cf078;
    iVar3 = (int)DAT_060cf06c;
    uVar4 = iVar3 - param_1[2];
    if (param_3 <= uVar4) {
      uVar4 = param_3;
    }
    (*(code *)PTR_FUN_060cf078)(param_2,param_1[1] + param_1[2]);
    param_1[2] = param_1[2] + uVar4;
    if (uVar4 < param_3) {
      iVar2 = (*(code *)PTR_FUN_060cf074)(*param_1,1,param_1[1],iVar3);
      if (iVar2 != iVar3) goto LAB_060cf006;
      (*(code *)puVar1)(param_2 + uVar4,param_1[1],param_3 - uVar4);
      param_1[2] = param_3 - uVar4;
    }
    iVar2 = 0;
  }
  return iVar2;
}



undefined FUN_060cf07c(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined local_10 [8];
  
  uVar1 = (*(code *)PTR_FUN_060cf0a4)(param_1,local_10,1);
  *param_2 = uVar1;
  return local_10[0];
}



undefined2 FUN_060cf0a8(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined2 local_10 [4];
  
  uVar1 = (*(code *)PTR_FUN_060cf0d0)(param_1,local_10,2);
  *param_2 = uVar1;
  return local_10[0];
}



undefined2 FUN_060cf0d4(undefined4 param_1,int *param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined auStack_1c [2];
  undefined2 local_1a [3];
  
  puVar1 = PTR_FUN_060cf124;
  iVar2 = (*(code *)PTR_FUN_060cf124)(param_1,auStack_1c,2);
  *param_2 = iVar2;
  if (iVar2 == 0) {
    iVar2 = (*(code *)puVar1)(param_1,local_1a,2);
    *param_2 = iVar2;
    if (iVar2 == 0) {
      return local_1a[0];
    }
  }
  return 0;
}



undefined4 FUN_060cf128(undefined4 param_1,int *param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined auStack_1c [4];
  undefined4 auStack_18 [2];
  
  puVar1 = PTR_FUN_060cf170;
  iVar2 = (*(code *)PTR_FUN_060cf170)(param_1,auStack_1c,4);
  *param_2 = iVar2;
  if (iVar2 == 0) {
    iVar2 = (*(code *)puVar1)(param_1,auStack_18,4);
    *param_2 = iVar2;
    if (iVar2 == 0) {
      return auStack_18[0];
    }
  }
  return 0;
}



undefined4 FUN_060cf174(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 local_10 [2];
  
  uVar1 = (*(code *)PTR_FUN_060cf198)(param_1,local_10,4);
  *param_2 = uVar1;
  return local_10[0];
}



char FUN_060cf19c(undefined4 *param_1,int *param_2)

{
  undefined *puVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  puVar1 = PTR_FUN_060cf210;
  cVar2 = (*(code *)PTR_FUN_060cf210)();
  if (*param_2 == 0) {
    if (cVar2 != '\0') {
      return cVar2;
    }
    iVar3 = param_1[3];
    param_1[3] = iVar3 + 1;
    if ((int)param_1[4] <= iVar3 + 1) {
      return '\0';
    }
    iVar4 = (int)DAT_060cf20e;
    iVar3 = (*(code *)PTR_FUN_060cf214)(*param_1,1,param_1[1],iVar4);
    if (iVar3 == iVar4) {
      param_1[2] = 0;
      cVar2 = (*(code *)puVar1)(param_1,param_2);
      if (*param_2 == 0) {
        return cVar2;
      }
    }
    else if (iVar3 < 1) {
      *param_2 = iVar3;
    }
    else {
      *param_2 = -1;
    }
  }
  return '\0';
}



int FUN_060cf220(int *param_1,int *param_2)

{
  bool bVar1;
  undefined *puVar2;
  int *piVar3;
  char cVar6;
  int iVar4;
  undefined uVar7;
  uint uVar5;
  byte bVar8;
  undefined *puVar9;
  char unaff_r9;
  byte *pbVar10;
  int *piVar11;
  int local_34;
  int *piStack_30;
  int iStack_2c;
  byte local_25;
  int *piStack_24;
  
  if (*param_1 == 0) {
    piStack_30 = param_2 + 2;
    goto LAB_060cf56c;
  }
  piStack_30 = param_2;
  cVar6 = (*(code *)PTR_FUN_060cf34c)(param_1,&local_34);
  *(char *)(piStack_30 + 2) = cVar6;
  puVar9 = PTR_FUN_060cf350;
  if (local_34 != 0) {
    return local_34;
  }
  if (cVar6 == '\0') {
    return 0;
  }
  (*(code *)PTR_FUN_060cf350)(param_1,&local_34);
  puVar2 = PTR_FUN_060cf354;
  if (local_34 != 0) {
    return local_34;
  }
  iVar4 = (*(code *)PTR_FUN_060cf354)(param_1,&local_34);
  *piStack_30 = DAT_060cf348 + iVar4;
  if (local_34 != 0) {
    return local_34;
  }
  iVar4 = (*(code *)puVar2)(param_1,&local_34);
  piStack_30[1] = iVar4;
  iVar4 = 0;
  if (local_34 != 0) {
    return local_34;
  }
  do {
    (*(code *)puVar9)(param_1,&local_34);
    puVar2 = PTR_FUN_060cf350;
    iVar4 = iVar4 + 1;
    if (local_34 != 0) {
      return local_34;
    }
  } while (iVar4 < 7);
  local_25 = (*(code *)PTR_FUN_060cf350)(param_1);
  if (local_34 != 0) {
    return local_34;
  }
  uVar7 = (*(code *)puVar2)(param_1,&local_34);
  *(undefined *)((int)piStack_30 + 10) = uVar7;
  if (local_34 != 0) {
    return local_34;
  }
  uVar7 = (*(code *)puVar2)(param_1,&local_34);
  *(undefined *)((int)piStack_30 + 0xb) = uVar7;
  if (local_34 != 0) {
    return local_34;
  }
  (*(code *)PTR_FUN_060cf358)(param_1,&local_34);
  if (local_34 != 0) {
    return local_34;
  }
  uVar5 = (*(code *)puVar2)(param_1,&local_34);
  if (local_34 != 0) {
    return local_34;
  }
  iStack_2c = (uVar5 & 0xff) + 0x21;
  iVar4 = 0;
  piVar11 = piStack_30 + 3;
  do {
    piVar3 = piStack_24;
    if ((uVar5 & 0xff) < 9) {
      if ((int)(uVar5 & 0xff) <= iVar4) break;
    }
    else if (7 < iVar4) break;
    unaff_r9 = (*(code *)PTR_FUN_060cf4ac)(param_1,&local_34);
    iVar4 = iVar4 + 1;
    if (local_34 != 0) {
      return local_34;
    }
    piVar3 = piStack_24;
    if (unaff_r9 == ';') break;
    *(char *)piVar11 = unaff_r9;
    piVar11 = (int *)((int)piVar11 + 1);
    piVar3 = piVar11;
  } while (unaff_r9 != '.');
  piStack_24 = piVar3;
  puVar9 = PTR_FUN_060cf4ac;
  if (unaff_r9 == ';') {
    bVar1 = (int)(uVar5 & 0xff) <= iVar4;
    if (!bVar1) {
      do {
        (*(code *)puVar9)(param_1,&local_34);
        iVar4 = iVar4 + 1;
        if (local_34 != 0) {
          return local_34;
        }
      } while (iVar4 < (int)(uVar5 & 0xff));
      goto LAB_060cf3fa;
    }
  }
  else {
    if (unaff_r9 != '.') {
      bVar1 = (int)(uVar5 & 0xff) <= iVar4;
      if (bVar1) goto LAB_060cf3fc;
      do {
        cVar6 = (*(code *)puVar9)(param_1,&local_34);
        iVar4 = iVar4 + 1;
        if (local_34 != 0) {
          return local_34;
        }
        if (cVar6 == '.') {
          *(char *)piVar11 = '.';
          piVar11 = (int *)((int)piVar11 + 1);
          piStack_24 = piVar11;
          break;
        }
      } while (iVar4 < (int)(uVar5 & 0xff));
    }
LAB_060cf3fa:
    bVar1 = (int)(uVar5 & 0xff) <= iVar4;
  }
LAB_060cf3fc:
  if (!bVar1) {
    do {
      cVar6 = (*(code *)PTR_FUN_060cf4ac)(param_1,&local_34);
      iVar4 = iVar4 + 1;
      if (local_34 != 0) {
        return local_34;
      }
      if (cVar6 == ';') {
        if (iVar4 < (int)(uVar5 & 0xff)) {
          do {
            (*(code *)PTR_FUN_060cf4ac)(param_1,&local_34);
            iVar4 = iVar4 + 1;
            if (local_34 != 0) {
              return local_34;
            }
          } while (iVar4 < (int)(uVar5 & 0xff));
        }
        break;
      }
      if (((int)piVar11 - (int)piStack_24 < 4) &&
         ((int)((int)piVar11 + (-0xc - (int)piStack_30)) < 0xc)) {
        *(char *)piVar11 = cVar6;
        piVar11 = (int *)((int)piVar11 + 1);
      }
    } while (iVar4 < (int)(uVar5 & 0xff));
  }
  if ((int)((int)piVar11 + (-0xc - (int)piStack_30)) < 0xc) {
    *(char *)piVar11 = '\0';
  }
  if (((uVar5 & 0xff) + 1 & 1) != 0) {
    (*(code *)PTR_FUN_060cf4ac)(param_1,&local_34);
    if (local_34 != 0) {
      return local_34;
    }
    iStack_2c = iStack_2c + 1;
  }
  piVar11 = piStack_30 + 3;
  if (*(char *)piVar11 == '\0') {
    *(undefined2 *)piVar11 = *(undefined2 *)PTR_DAT_060cf4b0;
  }
  else if (*(char *)piVar11 == '\x01') {
    puVar9 = PTR_DAT_060cf588 + 2;
    *(undefined2 *)piVar11 = *(undefined2 *)PTR_DAT_060cf588;
    *(undefined *)((int)piStack_30 + 0xe) = *puVar9;
  }
  pbVar10 = (byte *)(piStack_30 + 2);
  if (iStack_2c < (int)(uint)*pbVar10) {
    (*(code *)PTR_FUN_060cf58c)(param_1,&local_34);
    puVar9 = PTR_FUN_060cf590;
    if (local_34 != 0) {
      return local_34;
    }
    bVar8 = (*(code *)PTR_FUN_060cf590)(param_1,&local_34);
    *(byte *)((int)piStack_30 + 9) = bVar8 & 0xf8;
    if (local_34 != 0) {
      return local_34;
    }
    (*(code *)puVar9)(param_1,&local_34);
    if (local_34 != 0) {
      return local_34;
    }
    (*(code *)PTR_FUN_060cf594)(param_1,&local_34);
    if (local_34 == 0) {
      uVar7 = (*(code *)puVar9)(param_1,&local_34);
      *(undefined *)((int)piStack_30 + 0x19) = uVar7;
      if (local_34 != 0) {
        return local_34;
      }
      iVar4 = iStack_2c + 9;
      if (iVar4 < (int)(uint)*pbVar10) {
        do {
          (*(code *)puVar9)(param_1,&local_34);
          iVar4 = iVar4 + 1;
          if (local_34 != 0) {
            return local_34;
          }
        } while (iVar4 < (int)(uint)*pbVar10);
        return 0;
      }
      return 0;
    }
    return local_34;
  }
  if ((local_25 & 2) == 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = 0x80;
  }
  *(undefined *)((int)piStack_30 + 9) = uVar7;
  piStack_30 = (int *)((int)piStack_30 + 0x19);
LAB_060cf56c:
  *(undefined *)piStack_30 = 0;
  return 0;
}



void FUN_060cf598(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  *(undefined *)((int)param_1 + 10) = *(undefined *)((int)param_2 + 0x19);
  *(undefined *)((int)param_1 + 0xb) = *(undefined *)((int)param_2 + 9);
  *(undefined *)(param_1 + 2) = *(undefined *)((int)param_2 + 10);
  *(undefined *)((int)param_1 + 9) = *(undefined *)((int)param_2 + 0xb);
  return;
}



void FUN_060cf5d4(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  *(undefined *)((int)param_1 + 10) = 0;
  *(undefined *)((int)param_1 + 0xb) = 4;
  *(undefined *)(param_1 + 2) = 0;
  *(undefined *)((int)param_1 + 9) = 0;
  (*(code *)PTR_FUN_060cf60c)(param_2,1);
  return;
}



void FUN_060cf610(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  *(undefined *)((int)param_1 + 10) = 0;
  *(undefined *)((int)param_1 + 0xb) = 2;
  *(undefined *)(param_1 + 2) = 0;
  *(undefined *)((int)param_1 + 9) = 0;
  return;
}



bool FUN_060cf638(undefined4 param_1,int *param_2,undefined4 *param_3)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 local_30;
  undefined auStack_2c [12];
  int aiStack_20 [2];
  
  if ((*(uint *)(*DAT_060cf6b8 + (int)DAT_060cf6b4) & 2) != 0) {
    (*(code *)*DAT_060cf6bc)(aiStack_20);
    puVar1 = PTR_FUN_060cf6c0;
    iVar3 = 0;
    if (aiStack_20[0] < 1) {
      return false;
    }
    do {
      (*(code *)*DAT_060cf6c4)(iVar3,&local_30);
      iVar2 = (*(code *)puVar1)(param_1,auStack_2c,0xc);
      if (iVar2 == 0) {
        *param_2 = iVar3;
        *param_3 = local_30;
        return iVar2 == 0;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < aiStack_20[0]);
  }
  return false;
}



bool FUN_060cf6c8(int *param_1,int *param_2,int param_3)

{
  char *pcVar1;
  
  if (param_1 < param_2) {
    pcVar1 = (char *)((int)param_1 + 0xb);
    do {
      if ((*pcVar1 == '\x02') && (*param_1 == param_3)) {
        return *param_1 == param_3;
      }
      param_1 = param_1 + 3;
      pcVar1 = pcVar1 + 0xc;
    } while (param_1 < param_2);
  }
  return false;
}



int FUN_060cf6f8(int param_1,int param_2,undefined4 param_3)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = PTR_FUN_060cf744;
  iVar3 = 0;
  if (0 < param_2) {
    do {
      iVar2 = (*(code *)puVar1)(param_1 + 0xc,param_3,0xc);
      iVar3 = iVar3 + 1;
      if (iVar2 == 0) {
        return param_1;
      }
      param_1 = param_1 + 0x18;
    } while (iVar3 < param_2);
  }
  return 0;
}



void FUN_060cf748(int param_1)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = PTR_FUN_060cf77c;
  iVar2 = 0;
  if (0 < param_1) {
    do {
      (*(code *)puVar1)(iVar2,0);
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_1);
  }
  return;
}



undefined4 * FUN_060cf7b0(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 1;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  (*(code *)PTR_FUN_060cf7ec)();
  param_1[0xd] = 0;
  (*(code *)PTR_FUN_060cf7f0)(param_1,3);
  return param_1;
}



undefined4 FUN_060cf7f4(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  uVar1 = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(param_1 + 0x38) = param_2;
  return uVar1;
}



void FUN_060cf808(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x2c) = param_2;
  return;
}



void FUN_060cf814(int param_1,undefined4 param_2)

{
  bool bVar1;
  
  *(undefined4 *)(param_1 + 0x18) = param_2;
  bVar1 = *(int *)(param_1 + 0x34) == 6;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  if (bVar1) {
    *(undefined4 *)(param_1 + 0x34) = 0;
    if ((*(int *)(param_1 + 0x38) - 1U <= (uint)bVar1) || (*(int *)(param_1 + 0x38) == 3)) {
      *(uint *)(param_1 + 8) = *(int *)(param_1 + 8) + 3U & 0xfffffffc;
    }
  }
  return;
}



undefined4 FUN_060cf848(int param_1)

{
  return *(undefined4 *)(param_1 + 0x18);
}



undefined4 FUN_060cf860(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0x14) = param_2;
  return uVar1;
}



void FUN_060cf86c(int param_1)

{
  *(undefined4 *)(param_1 + 0x30) = 1;
  return;
}



void FUN_060cf884(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined auStack_24 [8];
  
  iVar3 = (int)DAT_060cf926;
  *(undefined4 *)(*DAT_060cf928 + iVar3) = 0;
  iVar2 = DAT_060cf930;
  puVar1 = PTR_FUN_060cf92c;
  iVar4 = *(int *)(param_1 + 0xa0);
  if (iVar4 != 0) {
    while (1 < iVar4 - 6U) {
      (*(code *)puVar1)(param_1,auStack_24);
      piVar5 = (int *)(*DAT_060cf928 + iVar3);
      iVar4 = *piVar5 + 1;
      *piVar5 = iVar4;
      if ((iVar2 < iVar4) || (iVar4 = *(int *)(param_1 + 0xa0), iVar4 == 0)) break;
    }
  }
  if (*(int *)(param_1 + 0x78) != 0) {
    (*(code *)PTR_FUN_060cf934)(param_1,*(int *)(param_1 + 0x78),param_2);
    *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + *(int *)(*(int *)(param_1 + 0x78) + 0xc);
    *(undefined4 *)(param_1 + 0x78) = 0;
  }
  if (*(int *)(param_1 + 0x7c) != 0) {
    (*(code *)PTR_FUN_060cf938)(param_1 + 0x6c);
    *(undefined4 *)(param_1 + 0x7c) = 0;
  }
  *(undefined4 *)(param_1 + 0xa0) = 6;
  return;
}



int FUN_060cf93c(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  int in_r2;
  int iVar2;
  int iVar3;
  
  puVar1 = PTR_FUN_060cf9bc;
  switch(*(undefined4 *)(param_1 + 0xa4)) {
  case 0:
  case 1:
  case 2:
    iVar3 = 1;
    if (*(int *)(param_1 + 0xa0) != 0) {
      iVar3 = 2;
    }
    break;
  default:
    iVar3 = 1;
  }
  iVar2 = 0;
  if (iVar3 != 0) {
    while (in_r2 = (*(code *)puVar1)(param_1,param_2), in_r2 != 7) {
      iVar2 = iVar2 + 1;
      if ((in_r2 != 0) && (in_r2 != 6)) {
        return in_r2;
      }
      if (iVar3 <= iVar2) {
        return in_r2;
      }
    }
  }
  return in_r2;
}



int FUN_060cf9c0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x84) < 1) {
    return 6;
  }
  if (*(int *)(param_1 + 0x9c) != 0) {
    iVar1 = *(int *)(param_1 + 0xa0);
    if (iVar1 == 0) {
      (*(code *)PTR_FUN_060cfa30)(param_1);
      if (*(int *)(param_1 + 0x78) == 0) goto LAB_060cfa22;
      *(undefined4 *)(param_1 + 0xa0) = 5;
    }
    else if (iVar1 != 5) {
      return iVar1;
    }
    (*(code *)PTR_FUN_060cfa34)(param_1,*(undefined4 *)(param_1 + 0x78),0xffffffff);
    *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + *(int *)(*(int *)(param_1 + 0x78) + 0xc);
    uVar2 = 0;
    *(undefined4 *)(param_1 + 0x78) = 0;
    if (*(int *)(param_1 + 0x84) <= *(int *)(param_1 + 0x88)) {
      uVar2 = 6;
    }
    *(undefined4 *)(param_1 + 0xa0) = uVar2;
  }
LAB_060cfa22:
  return *(int *)(param_1 + 0xa0);
}



undefined4 FUN_060cfa38(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = param_1 + 0x6c;
  uVar4 = 0;
  if (*(int *)(param_1 + 0x84) < 1) {
    *param_2 = 0;
    return 6;
  }
  if (*(int *)(param_1 + 0x9c) == 0) {
    *param_2 = 0;
    goto LAB_060cfb12;
  }
  switch(*(undefined4 *)(param_1 + 0xa0)) {
  case 0:
    (*(code *)PTR_FUN_060cfb24)(param_1);
    if (*(int *)(param_1 + 0x78) != 0) {
      *(undefined4 *)(param_1 + 0xa0) = 1;
      goto switchD_060cfa7c_caseD_1;
    }
    break;
  case 1:
switchD_060cfa7c_caseD_1:
    (*(code *)PTR_FUN_060cfb28)(iVar3);
    if (*(int *)(param_1 + 0x7c) != 0) {
      *(undefined4 *)(param_1 + 0xa0) = 2;
      goto switchD_060cfa7c_caseD_2;
    }
    break;
  case 2:
switchD_060cfa7c_caseD_2:
    iVar1 = (*(code *)PTR_FUN_060cfb2c)(iVar3);
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 0xa0) = 3;
      goto switchD_060cfa7c_caseD_3;
    }
    break;
  case 3:
switchD_060cfa7c_caseD_3:
    iVar1 = (*(code *)PTR_FUN_060cfb30)(param_1);
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 0xa0) = 4;
      goto switchD_060cfa7c_caseD_4;
    }
    break;
  case 4:
switchD_060cfa7c_caseD_4:
    iVar1 = (*(code *)PTR_FUN_060cfb34)(iVar3);
    if (iVar1 < 1) {
      uVar4 = 1;
      *(undefined4 *)(param_1 + 0xa0) = 5;
      goto switchD_060cfa7c_caseD_5;
    }
    break;
  case 5:
switchD_060cfa7c_caseD_5:
    if (*(int *)(param_1 + 0x8c) == *(int *)(*(int *)(param_1 + 0x78) + 8)) {
      (*(code *)PTR_FUN_060cfb38)(param_1,*(int *)(param_1 + 0x78),0xffffffff);
      *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + *(int *)(*(int *)(param_1 + 0x78) + 0xc)
      ;
      *(undefined4 *)(param_1 + 0x78) = 0;
    }
    (*(code *)PTR_FUN_060cfb3c)(iVar3,*(undefined4 *)(param_1 + 0x7c));
    uVar2 = 0;
    *(undefined4 *)(param_1 + 0x7c) = 0;
    if (*(int *)(param_1 + 0x84) <= *(int *)(param_1 + 0x88)) {
      uVar2 = 6;
    }
    *(undefined4 *)(param_1 + 0xa0) = uVar2;
  }
  *param_2 = uVar4;
LAB_060cfb12:
  return *(undefined4 *)(param_1 + 0xa0);
}



void FUN_060cfb40(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x88);
  if (*(int *)(param_1 + 0x80) < iVar3) {
    iVar3 = *(int *)(param_1 + 0x80);
  }
  if (1 < *(int *)(param_1 + 0x98)) {
    if (*(int *)(param_1 + 0x78) != 0) {
      iVar3 = (*(code *)PTR_FUN_060cfbbc)
                        (*(int *)(*(int *)(param_1 + 0x78) + 8) - *(int *)(param_1 + 0x8c));
    }
    uVar1 = (*(code *)PTR_FUN_060cfbc0)(param_1 + 0x6c);
    iVar2 = (*(code *)PTR_FUN_060cfbbc)(uVar1,*(undefined4 *)(param_1 + 0x98));
    if (iVar2 < iVar3) {
      iVar3 = iVar2;
    }
  }
  if (*(int *)(param_1 + 0x78) == 0) {
    iVar3 = (*(code *)PTR_FUN_060cfbc4)(param_1,iVar3);
    *(int *)(param_1 + 0x78) = iVar3;
    if (iVar3 != 0) {
      *(undefined4 *)(param_1 + 0x8c) = 0;
    }
  }
  return;
}



void FUN_060cfbc8(int param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  puVar1 = PTR_FUN_060cfc1c;
  if (*(int *)(param_1 + 0x2c) < 2) {
    iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8) - *(int *)(param_1 + 0x20);
    iVar2 = (*(code *)PTR_FUN_060cfc1c)(param_1);
    if (iVar2 <= iVar4) {
      iVar4 = (*(code *)puVar1)(param_1);
    }
  }
  else {
    iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 8);
  }
  uVar3 = (*(code *)PTR_FUN_060cfc20)(param_1,iVar4);
  *(undefined4 *)(param_1 + 0x10) = uVar3;
  return;
}



undefined4 FUN_060cfd00(void)

{
  return 1;
}



void FUN_060cfd0c(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,uint param_6)

{
  uint *puVar1;
  uint uVar2;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  int iStack_4c;
  int iStack_48;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  int iStack_28;
  int iStack_24;
  
  uVar2 = param_6 >> 2;
  iStack_24 = param_4;
  if (uVar2 != 0) {
    (*(code *)PTR_FUN_060cfde4)();
    local_58 = 0;
    uStack_54 = 1;
    uStack_50 = 0xf;
    (*(code *)PTR_FUN_060cfde8)(&local_58);
    iStack_4c = iStack_24;
    if (0 < param_3) {
      uStack_40 = (uint)(0 < param_3);
    }
    else {
      uStack_40 = 2;
      if (-1 < param_3) {
        uStack_40 = 0;
      }
    }
    if (0 < param_5) {
      uStack_3c = (uint)(0 < param_5);
    }
    else {
      uStack_3c = 2;
      if (-1 < param_5) {
        uStack_3c = 0;
      }
    }
    uStack_38 = 0x800;
    uStack_34 = 0x200;
    uStack_30 = 0;
    iStack_28 = (int)DAT_060cfde0;
    iStack_48 = param_2;
    uStack_44 = uVar2;
    (*(code *)PTR_FUN_060cfdec)(&iStack_4c,param_1);
    (*(code *)PTR_FUN_060cfdf0)(param_1);
    (*(code *)PTR_FUN_060cfdf4)(param_2,param_6);
  }
  puVar1 = DAT_060cfdf8;
  *DAT_060cfdf8 = param_6 & 3;
  puVar1[2] = uVar2 * param_3 * 4 + param_2;
  puVar1[1] = uVar2 * param_5 * 4 + iStack_24;
  return;
}



bool FUN_060cfdfc(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = (*(code *)PTR_FUN_060cfe28)();
  bVar1 = iVar2 != 0;
  if (bVar1) {
    (*(code *)PTR_FUN_060cfe30)(DAT_060cfe2c[-1],DAT_060cfe2c[1],*DAT_060cfe2c);
  }
  return !bVar1 && iVar2 == 0;
}



undefined4 FUN_060cfedc(void)

{
  return 1;
}



void FUN_060cfee8(undefined4 *param_1,int param_2,undefined4 *param_3,int param_4,uint param_5)

{
  int iVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    iVar1 = 0;
    if (param_5 >> 2 != 0) {
      do {
        iVar1 = iVar1 + 1;
        *param_1 = *param_3;
        param_1 = param_1 + param_2;
        param_3 = param_3 + param_4;
      } while (iVar1 < (int)(param_5 >> 2));
    }
    (*(code *)PTR_FUN_060cff24)(param_5 & 3,param_1);
  }
  return;
}



undefined4 FUN_060cff28(void)

{
  return 0;
}



uint FUN_060cff34(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(param_1 + 0x38);
  if (iVar1 == 0) {
    uVar2 = **(uint **)(param_1 + 0x10) & DAT_060cff8c;
    if ((uVar2 + DAT_060cff90 <= DAT_060cff94) || (uVar2 + DAT_060cff98 <= DAT_060cff9c)) {
      iVar1 = 3;
    }
  }
  else if (iVar1 == 4) {
    return (uint)(iVar1 == 4);
  }
  uVar2 = (**(code **)(PTR_PTR_LAB_060cffa0 + iVar1 * 0xc))();
  return uVar2;
}



undefined4 FUN_060cffa4(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  uint *puVar5;
  
  piVar4 = *(int **)(param_1 + 0x78);
  puVar5 = *(uint **)(param_1 + 0x7c);
  if (*(int *)(param_1 + 0xa4) == 4) {
    uVar1 = (**(code **)(param_1 + 0x94))(*(undefined4 *)(param_1 + 0x90),piVar4[3]);
    if ((int)uVar1 < 0) {
      piVar4[2] = uVar1;
      return 0;
    }
    piVar4[3] = uVar1;
    puVar5[3] = uVar1;
    uVar1 = uVar1 * *(int *)(param_1 + 0x98);
    piVar4[2] = uVar1;
    puVar5[2] = uVar1;
    *(uint *)(param_1 + 0x8c) = uVar1;
  }
  else {
    if ((*(int *)(param_1 + 0x8c) == 0) &&
       (iVar2 = (*(code *)PTR_FUN_060d0060)(piVar4,param_1 + 0xc), iVar2 == 0)) {
      return 0;
    }
    iVar2 = *(int *)(param_1 + 0xa4);
    uVar1 = puVar5[2];
    if ((iVar2 == 0) &&
       ((uVar3 = *puVar5 & DAT_060d0064, uVar3 + DAT_060d0068 <= DAT_060d006c ||
        (uVar3 + DAT_060d0070 <= DAT_060d0074)))) {
      iVar2 = 3;
    }
    (**(code **)(PTR_PTR_LAB_060d0078 + iVar2 * 0xc + 4))
              (*puVar5,puVar5[1],piVar4[1] * *(int *)(param_1 + 0x8c) + *piVar4,piVar4[1],uVar1);
    *(uint *)(param_1 + 0x8c) = *(int *)(param_1 + 0x8c) + uVar1;
  }
  return 1;
}



uint FUN_060d007c(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(param_1 + 0x38);
  if (iVar1 == 0) {
    uVar2 = **(uint **)(param_1 + 0x10) & DAT_060d00d8;
    if ((uVar2 + DAT_060d00dc <= DAT_060d00e0) || (uVar2 + DAT_060d00e4 <= DAT_060d00e8)) {
      iVar1 = 3;
    }
  }
  else if (iVar1 == 4) {
    return ((*(uint **)(param_1 + 0x10))[3] >> 0x10) * 2 >> 0x10;
  }
  uVar2 = (**(code **)(PTR_PTR_LAB_060d00ec + iVar1 * 0xc + 8))();
  return uVar2;
}



void FUN_060d00f0(int param_1,undefined *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 local_8;
  
  if (0 < param_1) {
    iVar1 = 0;
    local_8 = *param_3;
    if (0 < param_1) {
      do {
        *param_2 = *(undefined *)((int)&local_8 + iVar1);
        iVar1 = iVar1 + 1;
        param_2 = param_2 + 1;
      } while (iVar1 < param_1);
    }
  }
  return;
}



int FUN_060d0124(int param_1)

{
  return *(int *)(param_1 + 4) * *(int *)(param_1 + 0x2c) - *(int *)(param_1 + 8);
}



int * FUN_060d013c(int *param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  
  piVar1 = (int *)(*DAT_060d016c + (int)DAT_060d016a);
  if (piVar1[4] == 0) {
    uVar2 = (uint)(piVar1[4] == 0);
    *piVar1 = *param_1 + param_1[2];
    piVar1[1] = uVar2;
    piVar1[2] = param_2;
    piVar1[4] = uVar2;
  }
  else {
    piVar1 = (int *)0x0;
  }
  return piVar1;
}



void FUN_060d0170(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x38) != 4) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + *(int *)(param_2 + 8);
  }
  *(undefined4 *)(param_2 + 0x10) = 0;
  return;
}



void FUN_060d018c(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  *param_2 = *param_1;
  *param_3 = param_1[1];
  *param_4 = param_1[0xb];
  return;
}



void FUN_060d01a0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[0xb] = param_4;
  param_1[2] = 0;
  return;
}



void FUN_060d01b4(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x90) = param_3;
  *(undefined4 *)(param_1 + 0x94) = param_2;
  *(undefined4 *)(param_1 + 0xa4) = 4;
  return;
}



void FUN_060d0220(int param_1)

{
  (**(code **)(PTR_PTR_FUN_060d024c + *(int *)(param_1 + 0x28) * 0x10))
            (param_1 + 0xc,DAT_060d0248,0);
  return;
}



void FUN_060d0250(int param_1)

{
  (**(code **)(PTR_PTR_FUN_060d0274 + *(int *)(param_1 + 0x28) * 0x10 + 4))(param_1 + 0xc);
  return;
}



void FUN_060d0278(undefined4 param_1,int param_2)

{
  (**(code **)(PTR_PTR_FUN_060d0298 + *(int *)(param_2 + 0x1c) * 0x10 + 8))();
  return;
}



void FUN_060d029c(int param_1)

{
  (**(code **)(PTR_PTR_FUN_060d02c0 + *(int *)(param_1 + 0x28) * 0x10 + 0xc))(param_1 + 0xc);
  return;
}



bool FUN_060d02d0(int param_1)

{
  undefined *puVar1;
  int iVar2;
  bool bVar3;
  undefined local_24;
  undefined local_23;
  undefined local_22;
  undefined local_21;
  undefined local_20;
  undefined local_1f;
  undefined4 uStack_1c;
  undefined4 local_18 [2];
  
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x34) = 1;
  puVar1 = PTR_FUN_060d03c4;
  local_24 = *(undefined *)(param_1 + 0xe);
  local_23 = 0;
  local_22 = 0;
  local_21 = 0;
  local_20 = 0;
  local_1f = 0;
  *(undefined *)(param_1 + 0x2c) = local_24;
  *(undefined *)(param_1 + 0x2d) = 0;
  *(undefined *)(param_1 + 0x2e) = 0;
  *(undefined *)(param_1 + 0x2f) = 0;
  *(undefined *)(param_1 + 0x30) = 0;
  *(undefined *)(param_1 + 0x31) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  iVar2 = (*(code *)puVar1)(&uStack_1c);
  puVar1 = PTR_FUN_060d03c8;
  bVar3 = false;
  if (iVar2 == 0) {
    *(undefined4 *)(param_1 + 0x20) = uStack_1c;
    iVar2 = (*(code *)puVar1)(local_18);
    puVar1 = PTR_FUN_060d03d0;
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 0x28) = local_18[0];
      iVar2 = (*(code *)puVar1)(local_18[0],*(undefined4 *)(param_1 + 0x34),&local_24,0,0);
      if (iVar2 == 0) {
        iVar2 = (*(code *)PTR_FUN_060d03d4)(local_18[0],uStack_1c,0xff);
        bVar3 = false;
        if (iVar2 == 0) {
          iVar2 = (*(code *)PTR_FUN_060d03d8)();
          bVar3 = false;
          if (iVar2 == 0) {
            bVar3 = iVar2 == 0;
          }
        }
      }
      else {
        bVar3 = false;
      }
    }
    else {
      (*(code *)PTR_FUN_060d03cc)(uStack_1c);
      bVar3 = false;
    }
  }
  return bVar3;
}



void FUN_060d03dc(int param_1)

{
  (*(code *)PTR_FUN_060d03fc)(*(undefined4 *)(param_1 + 4));
  (*(code *)PTR_FUN_060d0400)(*(undefined4 *)(param_1 + 0xc));
  return;
}



int FUN_060d0404(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int local_28;
  int iStack_24;
  int iStack_20;
  int aiStack_1c [2];
  
  iVar1 = (*(code *)PTR_FUN_060d04a0)
                    (*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x40),param_2,
                     &local_28,param_3);
  if (iVar1 == 0) {
    iVar1 = (*(code *)PTR_FUN_060d04a4)();
    if (iVar1 == 0) {
      if (param_3 == (int *)0x0) {
        return local_28;
      }
      (*(code *)PTR_FUN_060d04a8)(param_1,0,0,&iStack_24,&iStack_20,aiStack_1c,0,0);
      iVar1 = (*(code *)PTR_FUN_060d04ac)(param_1 + 0x1c);
      if (iVar1 + local_28 < iStack_20) {
        return local_28;
      }
      if (aiStack_1c[0] == 0) {
        return local_28;
      }
      if (local_28 < 1) {
        return local_28;
      }
      *param_3 = *param_3 - (iStack_24 - aiStack_1c[0]);
      return local_28;
    }
  }
  return 0;
}



void FUN_060d0524(int param_1)

{
  (*(code *)PTR_FUN_060d0544)(*(undefined4 *)(param_1 + 4),0,0xffffffff);
  (*(code *)PTR_FUN_060d0548)();
  return;
}



int FUN_060d054c(int param_1)

{
  return *(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x24);
}



int FUN_060d055c(int param_1)

{
  int iVar1;
  int local_c [2];
  
  iVar1 = (*(code *)PTR_FUN_060d05a4)(*(undefined4 *)(param_1 + 4),0,DAT_060d05a0,local_c,0);
  if ((iVar1 == 0) && (iVar1 = (*(code *)PTR_FUN_060d05a8)(), iVar1 == 0)) {
    if (local_c[0] < 0) {
      local_c[0] = 0;
    }
  }
  else {
    local_c[0] = -1;
  }
  return local_c[0];
}



int FUN_060d05ac(int param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = param_1 + 0x1c;
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (param_3 == 1) {
    iVar2 = (*(code *)PTR_FUN_060d0694)(iVar4);
    iVar2 = param_2 + iVar2;
    iVar5 = param_2;
  }
  else {
    iVar2 = (*(code *)PTR_FUN_060d0694)(iVar4);
    if (iVar2 == param_2) {
      return param_2;
    }
    iVar5 = (*(code *)PTR_FUN_060d0698)(iVar4);
    iVar2 = param_2;
    if (iVar5 < 0) {
      return -1;
    }
  }
  if (*(int *)(param_1 + 0x4c) == 0) {
    bVar1 = 0 < iVar5;
    if (*(int *)(param_1 + 0x3c) <= iVar2) {
      iVar3 = (*(code *)PTR_FUN_060d0694)(iVar4);
      bVar1 = 0 < iVar5;
      if (iVar2 < iVar3) {
        iVar5 = iVar2 - *(int *)(param_1 + 0x3c);
        bVar1 = 0 < iVar5;
      }
    }
    if (bVar1) {
      (*(code *)PTR_FUN_060d069c)(*(undefined4 *)(param_1 + 0x20),0,iVar5);
      iVar5 = (*(code *)PTR_FUN_060d06a0)();
      if (iVar5 != 0) {
        return -1;
      }
    }
    *(int *)(param_1 + 0x3c) = iVar2;
    *(undefined4 *)(param_1 + 0x40) = 0;
  }
  else if (*(int *)(param_1 + 0x4c) == 1) {
    if ((param_3 == 1) && (iVar5 = (*(code *)PTR_FUN_060d0698)(iVar4), iVar5 < 0)) {
      return -1;
    }
    if ((iVar2 < *(int *)(param_1 + 0x3c)) || (*(int *)(param_1 + 0x3c) + iVar5 + 1 < iVar2)) {
      iVar5 = (*(code *)PTR_FUN_060d06a4)(iVar4);
      if (iVar5 != 0) {
        return -1;
      }
      *(int *)(param_1 + 0x3c) = iVar2;
    }
    *(int *)(param_1 + 0x40) = iVar2 - *(int *)(param_1 + 0x3c);
  }
  iVar4 = (*(code *)PTR_FUN_060d0694)(iVar4);
  return iVar4;
}



bool FUN_060d0788(int param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = (*(code *)PTR_FUN_060d07b8)
                    (*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 0x24),
                     *(undefined4 *)(param_1 + 0xc));
  bVar2 = false;
  if (iVar1 == 0) {
    iVar1 = (*(code *)PTR_FUN_060d07bc)();
    bVar2 = false;
    if (iVar1 == 0) {
      bVar2 = iVar1 == 0;
    }
  }
  return bVar2;
}



void FUN_060d0814(int param_1,undefined4 param_2)

{
  (*(code *)PTR_FUN_060d082c)(param_2,*(undefined4 *)(param_1 + 0x1c));
  return;
}



bool FUN_060d0830(int param_1)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = (*(code *)PTR_FUN_060d085c)
                    (*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x1c));
  bVar2 = false;
  if (iVar1 == 0) {
    iVar1 = (*(code *)PTR_FUN_060d0860)();
    bVar2 = false;
    if (iVar1 == 0) {
      bVar2 = iVar1 == 0;
    }
  }
  return bVar2;
}



bool FUN_060d0864(int param_1)

{
  uint uVar1;
  
  uVar1 = (*(code *)PTR_FUN_060d0888)();
  if (-1 < (int)uVar1) {
    *(uint *)(param_1 + 0x1c) = uVar1;
  }
  return uVar1 < 0x80000000;
}



void FUN_060d088c(int param_1)

{
  (*(code *)PTR_FUN_060d08a0)(*(undefined4 *)(param_1 + 0x1c));
  return;
}



void FUN_060d08a4(int param_1)

{
  (*(code *)PTR_FUN_060d08b8)(*(undefined4 *)(param_1 + 0x1c));
  return;
}



void FUN_060d08bc(int param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = DAT_060d08e4;
  if (param_1 == 0) {
    iVar3 = *DAT_060d08e4;
  }
  else {
    iVar3 = *DAT_060d08e4;
  }
  bVar1 = param_1 != 0;
  *(bool *)(iVar3 + 0x17) = bVar1;
  *(bool *)(*piVar2 + 0x2f) = bVar1;
  return;
}



undefined4 FUN_060d08e8(int param_1,undefined4 param_2)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  byte local_28 [12];
  int iStack_1c;
  byte local_18 [8];
  
  *DAT_060d0ad4 = param_1;
  *DAT_060d0ad8 = 0;
  (*(code *)PTR_FUN_060d0adc)();
  (*(code *)PTR_FUN_060d0ae0)(param_2);
  (*(code *)PTR_FUN_060d0ae4)(local_28);
  switch(local_28[0] & 0xf) {
  case 7:
    uVar5 = 0xfffffff2;
    break;
  default:
    uVar4 = (*(code *)PTR_FUN_060d0ae8)();
    if ((uVar4 & 0x20) == 0) {
      (*(code *)PTR_FUN_060d0aec)();
      iVar6 = (*(code *)PTR_FUN_060d0af0)(0,0,4,0xf);
      iVar8 = DAT_060d0af8;
      puVar2 = PTR_FUN_060d0af4;
      if (iVar6 == 0) {
        iVar6 = 0;
        iStack_1c = 0;
        while (iVar7 = (*(code *)puVar2)(0,0xffffffff), puVar3 = PTR_FUN_060d0afc, iVar7 != 0) {
          bVar1 = iVar8 < iVar6;
          if (iVar7 != -1) {
            return 0xfffffffe;
          }
          iVar6 = iVar6 + 1;
          if (bVar1) {
            return 0xfffffffe;
          }
          iStack_1c = -1;
        }
        *(undefined4 *)(*DAT_060d0ad4 + 0x3c) = 0x30000;
        iStack_1c = 0;
        while (iVar8 = (*(code *)puVar3)(0x40), iVar8 == 0) {
          iVar8 = *(int *)(*DAT_060d0ad4 + 0x3c) + -1;
          *(int *)(*DAT_060d0ad4 + 0x3c) = iVar8;
          if (iVar8 == 0) {
            return 0xfffffffe;
          }
        }
        *(undefined4 *)(*DAT_060d0ad4 + 0x3c) = 0;
        (*(code *)PTR_FUN_060d0b00)(0xffffffe7);
        iVar8 = 0;
        bVar1 = false;
        iVar6 = (int)DAT_060d0ac6;
        do {
          iVar7 = (*(code *)PTR_FUN_060d0afc)(iVar6);
          if (iVar7 != 0) {
            iVar8 = iVar8 + 1;
            (*(code *)PTR_FUN_060d0b00)((int)DAT_060d0ac8);
            if (DAT_060d0aca < iVar8) {
              return 0xfffffffe;
            }
            (*(code *)PTR_FUN_060d0ae4)(local_28);
            switch(local_28[0] & 0xf) {
            case 1:
            case 2:
              bVar1 = true;
            default:
              break;
            case 9:
              goto switchD_060d092a_caseD_9;
            case 10:
              goto switchD_060d092a_caseD_a;
            }
          }
        } while (!bVar1);
        (*(code *)PTR_FUN_060d0b04)(&iStack_1c);
        iVar6 = (int)DAT_060d0acc;
        iVar8 = *DAT_060d0b08;
        iStack_1c = (*(code *)PTR_FUN_060d0b0c)(iVar8 + iVar6);
        puVar2 = PTR_FUN_060d0b10;
        if (iStack_1c == 0) {
          (*(code *)PTR_FUN_060d0b10)(0,local_18);
          (*(code *)puVar2)(local_18[0],local_18);
          if ((*(uint *)((uint)local_18[0] * 4 + iVar8 + iVar6 + -4) & DAT_060d0b14) == 0) {
            return 0xfffffff1;
          }
          iStack_1c = (*(code *)PTR_FUN_060d0b18)((int)DAT_060d0ad0,(int)DAT_060d0ace);
          *(undefined4 *)(*DAT_060d0ad4 + 0x3c) = 0x30000;
          do {
            iVar8 = (*(code *)PTR_FUN_060d0afc)(0x40);
            puVar2 = PTR_FUN_060d0ae4;
            if (iVar8 != 0) {
              iVar8 = *DAT_060d0ad4;
              *(undefined4 *)(iVar8 + 0x3c) = 0;
              (*(code *)puVar2)(iVar8 + 0x40);
              return 0;
            }
            iVar8 = *(int *)(*DAT_060d0ad4 + 0x3c) + -1;
            *(int *)(*DAT_060d0ad4 + 0x3c) = iVar8;
          } while (iVar8 != 0);
        }
      }
      return 0xfffffffe;
    }
  case 6:
    uVar5 = 0xfffffff3;
    break;
  case 9:
switchD_060d092a_caseD_9:
    uVar5 = 0xfffffff6;
    break;
  case 10:
switchD_060d092a_caseD_a:
    uVar5 = 0xfffffff0;
  }
  return uVar5;
}



undefined4 FUN_060d0b1c(int *param_1)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    pcVar1 = (char *)(*DAT_060d0b54 + iVar2 + 0x18);
    if (*pcVar1 == '\0') {
      *pcVar1 = '\x01';
      *param_1 = iVar2;
      return 0;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x18);
  *param_1 = -1;
  return 0xfffffffd;
}



undefined4 FUN_060d0b58(uint param_1)

{
  undefined4 uVar1;
  char *pcVar2;
  
  if (param_1 < 0x18) {
    pcVar2 = (char *)(*DAT_060d0b84 + param_1 + 0x18);
    uVar1 = 0xfffffff9;
    if (*pcVar2 == '\x01') {
      *pcVar2 = '\0';
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0xfffffffa;
  }
  return uVar1;
}



undefined4 FUN_060d0b88(int *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*(char *)(*DAT_060d0bb8 + iVar1) == '\0') {
      *(undefined *)(*DAT_060d0bb8 + iVar1) = 1;
      *param_1 = iVar1;
      return 0;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x18);
  *param_1 = -1;
  return 0xfffffffc;
}



undefined8 FUN_060d0bbc(uint param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = 0x17;
  if (param_1 < 0x18) {
    iVar4 = (int)*(char *)(param_1 + *DAT_060d0c38);
    uVar3 = 0xfffffff9;
    if (iVar4 == 1) {
      (*(code *)PTR_FUN_060d0c3c)(param_1,0,0xffffffff);
      puVar1 = PTR_FUN_060d0c44;
      (*(code *)PTR_FUN_060d0c44)(DAT_060d0c40);
      puVar2 = PTR_FUN_060d0c48;
      do {
        iVar4 = (*(code *)PTR_FUN_060d0c4c)();
        if (iVar4 == 3) {
          uVar3 = 0xfffffff4;
          goto LAB_060d0c2c;
        }
        uVar3 = 0xfffffff0;
        if (iVar4 == 2) goto LAB_060d0c2c;
        iVar4 = (*(code *)puVar2)(param_1);
      } while (iVar4 != 1);
      (*(code *)puVar1)(0);
      iVar4 = 0;
      *(undefined *)(param_1 + *DAT_060d0c38) = 0;
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0xfffffffa;
  }
LAB_060d0c2c:
  return CONCAT44(iVar4,uVar3);
}



uint FUN_060d0c50(void)

{
  undefined *puVar1;
  uint local_10 [2];
  
  puVar1 = PTR_FUN_060d0c7c;
  (*(code *)PTR_FUN_060d0c7c)(0,local_10);
  (*(code *)puVar1)(local_10[0]._0_1_,local_10);
  return local_10[0] & DAT_060d0c80;
}



undefined4 FUN_060d0c84(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = DAT_060d0cb4;
  iVar4 = *DAT_060d0cb4;
  if (*(int *)(iVar4 + 0x30) == 1) {
    uVar2 = 0xfffffffb;
  }
  else {
    *(undefined4 *)(iVar4 + 0x30) = 1;
    iVar3 = *(int *)(iVar4 + 0x38) + 1;
    *(int *)(iVar4 + 0x38) = iVar3;
    if (iVar3 < 0) {
      *(undefined4 *)(iVar4 + 0x38) = 0;
    }
    uVar2 = *(undefined4 *)(*piVar1 + 0x38);
  }
  return uVar2;
}



undefined4 FUN_060d0cb8(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *DAT_060d0ce0;
  if (*(int *)(iVar2 + 0x30) == 0) {
    uVar1 = 0xfffffff9;
  }
  else {
    uVar1 = 0xfffffff7;
    if (*(int *)(iVar2 + 0x38) == param_1) {
      *(undefined4 *)(iVar2 + 0x30) = 0;
      uVar1 = 0;
    }
  }
  return uVar1;
}



bool FUN_060d0ce4(int param_1)

{
  bool bVar1;
  
  if (*(int *)(*DAT_060d0d04 + 0x30) == 0) {
    bVar1 = false;
  }
  else {
    bVar1 = *(int *)(*DAT_060d0d04 + 0x38) == param_1;
  }
  return bVar1;
}



undefined4
FUN_060d0d08(int param_1,undefined param_2,undefined *param_3,undefined4 param_4,undefined4 param_5)

{
  bool bVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined auStack_14 [8];
  
  piVar6 = DAT_060d0dc4;
  iVar4 = *DAT_060d0dc4;
  if (*(char *)(iVar4 + param_1 + 0x18) == '\x01') {
    if (*(int *)(iVar4 + 0x54) < 0x18) {
      bVar1 = *(uint *)(iVar4 + 0x58) == 0;
      if (bVar1) {
        *(uint *)(iVar4 + 0x58) = (uint)bVar1;
      }
      iVar4 = *(int *)(iVar4 + 0x54) * 0x10;
      *(char *)(*piVar6 + iVar4 + 0x5c) = (char)param_1;
      *(undefined *)(*piVar6 + iVar4 + 0x5d) = param_2;
      iVar5 = *piVar6 + iVar4;
      *(undefined *)(iVar5 + 0x5e) = *param_3;
      *(undefined *)(iVar5 + 0x5f) = param_3[1];
      *(undefined *)(iVar5 + 0x60) = param_3[2];
      *(undefined *)(iVar5 + 0x61) = param_3[3];
      *(undefined *)(iVar5 + 0x62) = param_3[4];
      *(undefined *)(iVar5 + 99) = param_3[5];
      puVar2 = PTR_FUN_060d0dc8;
      iVar5 = *piVar6;
      iVar4 = iVar5 + iVar4;
      *(undefined4 *)(iVar4 + 100) = param_4;
      piVar6 = (int *)(iVar5 + 0x54);
      *(undefined4 *)(iVar4 + 0x68) = param_5;
      *piVar6 = *piVar6 + 1;
      (*(code *)puVar2)(auStack_14);
      uVar3 = 0;
    }
    else {
      uVar3 = 0xfffffff8;
    }
  }
  else {
    uVar3 = 0xfffffff9;
  }
  return uVar3;
}



undefined4 FUN_060d0e14(int param_1,int param_2)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  undefined auStack_c [8];
  
  if ((param_1 == DAT_060d0e5c) ||
     (uVar2 = 0xfffffff9, *(char *)(*DAT_060d0e64 + param_1 + 0x18) == '\x01')) {
    iVar3 = *DAT_060d0e64;
    bVar1 = *(int *)(iVar3 + 0x38) == param_2;
    if (bVar1) {
      *(uint *)(iVar3 + DAT_060d0e5e) = (uint)bVar1;
      *(int *)(iVar3 + DAT_060d0e60) = param_1;
      (*(code *)PTR_FUN_060d0e68)(auStack_c);
      uVar2 = 0;
    }
    else {
      uVar2 = 0xfffffff7;
    }
  }
  return uVar2;
}



undefined4 FUN_060d0e6c(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  byte local_18 [16];
  
  if (*(int *)(*DAT_060d0ec0 + 0x38) == param_2) {
    uVar2 = (*(code *)PTR_FUN_060d0ec4)(local_18);
    uVar1 = 0xfffffff3;
    if ((uVar2 & 0x20) == 0) {
      if ((local_18[0] & 0xf) == 7) {
        uVar1 = 0xfffffff2;
      }
      else {
        (*(code *)PTR_FUN_060d0ec8)(0xffffffeb);
        (*(code *)PTR_FUN_060d0ecc)(param_1);
        *DAT_060d0ed0 = 1;
        uVar1 = 0;
      }
    }
  }
  else {
    uVar1 = 0xfffffff7;
  }
  return uVar1;
}



undefined4
FUN_060d0ed4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  undefined auStack_10 [8];
  
  iVar3 = *DAT_060d0f34;
  bVar1 = *(uint *)(iVar3 + DAT_060d0f26) == 0;
  if (bVar1) {
    *(uint *)(iVar3 + DAT_060d0f26) = (uint)bVar1;
    *(undefined4 *)(iVar3 + DAT_060d0f28) = param_1;
    *(undefined4 *)(iVar3 + DAT_060d0f2a) = param_2;
    *(undefined4 *)(iVar3 + DAT_060d0f2c) = param_3;
    *(undefined4 *)(iVar3 + DAT_060d0f2e) = 0;
    *(undefined4 *)(iVar3 + DAT_060d0f30) = param_4;
    *(undefined4 *)(iVar3 + DAT_060d0f32) = param_5;
    (*(code *)PTR_FUN_060d0f38)(auStack_10);
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



undefined4 FUN_060d0f3c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined auStack_c [8];
  
  iVar4 = *DAT_060d0f90;
  iVar3 = (int)DAT_060d0f86;
  if (*(uint *)(iVar4 + iVar3) == 0) {
    bVar1 = *(int *)(iVar4 + 0x34) == -1;
    if (bVar1) {
      *(undefined4 *)(iVar4 + 0x34) = param_1;
      *(uint *)(iVar4 + iVar3) = (uint)bVar1;
      *(undefined4 *)(iVar4 + DAT_060d0f88) = param_1;
      *(undefined4 *)(iVar4 + DAT_060d0f8a) = param_2;
      *(undefined4 *)(iVar4 + DAT_060d0f8c) = param_3;
      (*(code *)PTR_FUN_060d0f94)(auStack_c);
      uVar2 = 0;
    }
    else {
      uVar2 = 0xfffffffb;
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



undefined4 FUN_060d0f98(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = DAT_060d0fd4;
  if (*(int *)(*DAT_060d0fd4 + 0x34) == -1) {
    uVar2 = 0xfffffff9;
  }
  else {
    iVar3 = (*(code *)PTR_FUN_060d0fd8)();
    *(undefined4 *)(*piVar1 + 0x34) = 0xffffffff;
    if (iVar3 == 0) {
      (*(code *)PTR_FUN_060d0fdc)();
      uVar2 = 0;
    }
    else {
      uVar2 = 0xfffffff6;
    }
  }
  return uVar2;
}



undefined4 FUN_060d0fe0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined auStack_c [8];
  
  iVar2 = *DAT_060d1030;
  if (*(int *)(iVar2 + DAT_060d1028) == 0) {
    if (*(int *)(iVar2 + 0x34) == param_1) {
      uVar1 = 0xfffffffb;
    }
    else {
      *(int *)(iVar2 + DAT_060d1028) = 1;
      *(int *)(iVar2 + DAT_060d102a) = param_1;
      *(undefined4 *)(iVar2 + DAT_060d102c) = param_2;
      *(undefined4 *)(iVar2 + DAT_060d102e) = param_3;
      (*(code *)PTR_FUN_060d1034)(auStack_c);
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



undefined4 FUN_060d1038(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(*DAT_060d1064 + (int)DAT_060d105e) == 0) {
    uVar1 = 1;
  }
  else {
    uVar1 = 1;
    if (*(int *)(*DAT_060d1064 + (int)DAT_060d1060) == param_1) {
      uVar1 = 0;
    }
  }
  return uVar1;
}



uint FUN_060d1068(byte *param_1)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_18 [3];
  
  if (param_1 != (byte *)0x0) {
    iVar2 = -8;
    if (*DAT_060d10d8 == 1) {
      *DAT_060d10d8 = 0;
    }
    else {
      iVar2 = (*(code *)PTR_FUN_060d10dc)(param_1);
    }
    if (iVar2 != 0) {
      (*(code *)PTR_FUN_060d10e0)(param_1);
    }
  }
  uVar3 = (*(code *)PTR_FUN_060d10e4)();
  if (((*param_1 & 0xf) == 10) && ((uVar3 & 0x20) == 0)) {
    local_18[0] = 0;
    (*(code *)PTR_FUN_060d10e8)(local_18);
    puVar1 = PTR_FUN_060d10ec;
    (*(code *)PTR_FUN_060d10ec)();
    (*(code *)puVar1)();
  }
  return uVar3;
}



undefined4 FUN_060d10f0(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  byte local_18 [16];
  
  if (*(int *)(*DAT_060d1138 + 0x38) == param_2) {
    uVar2 = (*(code *)PTR_FUN_060d113c)(local_18);
    uVar1 = 0xfffffff3;
    if ((uVar2 & 0x20) == 0) {
      if ((local_18[0] & 0xf) == 7) {
        uVar1 = 0xfffffff2;
      }
      else {
        (*(code *)PTR_FUN_060d1140)(param_1);
        uVar1 = 0;
      }
    }
  }
  else {
    uVar1 = 0xfffffff7;
  }
  return uVar1;
}



undefined4 FUN_060d11dc(uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 < 0x18) {
    uVar1 = 0xfffffff9;
    if (*(char *)(param_1 + *DAT_060d1218) != '\0') {
      iVar2 = (*(code *)PTR_FUN_060d121c)(param_1);
      uVar1 = 0xfffffff6;
      if (iVar2 == 0) {
        (*(code *)PTR_FUN_060d1220)();
        uVar1 = 0;
      }
    }
  }
  else {
    uVar1 = 0xfffffffa;
  }
  return uVar1;
}



undefined4 FUN_060d1224(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  int *piVar4;
  undefined auStack_c [8];
  
  pcVar3 = (char *)(*DAT_060d1290 + param_2);
  if ((pcVar3[0x18] == '\x01') && (*pcVar3 == '\x01')) {
    piVar4 = (int *)(*DAT_060d1290 + (int)DAT_060d1286);
    uVar1 = 0xffffffff;
    if (*piVar4 == 0) {
      iVar2 = 1;
      if (param_1 == -1) {
        iVar2 = 3;
      }
      *piVar4 = iVar2;
      iVar2 = *DAT_060d1290;
      *(short *)(iVar2 + DAT_060d1288) = (short)param_1;
      *(short *)(iVar2 + DAT_060d128a) = (short)param_2;
      *(undefined4 *)(iVar2 + DAT_060d128c) = param_3;
      (*(code *)PTR_FUN_060d1294)(auStack_c);
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0xfffffffb;
  }
  return uVar1;
}



undefined4 FUN_060d1298(uint param_1,uint param_2,uint param_3)

{
  bool bVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  uint *puVar6;
  int iVar7;
  undefined auStack_c [8];
  
  piVar5 = DAT_060d1378;
  iVar7 = *(int *)(*DAT_060d1378 + (int)DAT_060d136c);
  if (((((param_1 == (int)DAT_060d136e) || (param_1 == 0xfffffffe)) || (param_1 < 0x18)) &&
      (param_2 < 0x18)) &&
     (((param_3 == (int)DAT_060d136e || (param_3 == 0xfffffffe)) || (param_3 < 0x18)))) {
    if ((((param_1 == (int)DAT_060d136e) || (param_1 == 0xfffffffe)) ||
        (uVar3 = 0xfffffff9, *(char *)(*DAT_060d1378 + param_1 + 0x18) == '\x01')) &&
       (((param_3 == (int)DAT_060d136e || (param_3 == 0xfffffffe)) ||
        (uVar3 = 0xfffffff9, *(char *)(*DAT_060d1378 + param_3 + 0x18) == '\x01')))) {
      uVar3 = 0xfffffff9;
      if ((*(char *)(param_2 + *DAT_060d1378) == '\x01') && (uVar3 = 0xfffffff8, iVar7 < 0x18)) {
        puVar6 = (uint *)(*DAT_060d1378 + (int)DAT_060d1370);
        bVar1 = *puVar6 == 0;
        if (bVar1) {
          *puVar6 = (uint)bVar1;
        }
        iVar4 = *piVar5;
        iVar7 = iVar7 * 0xc + iVar4;
        *(uint *)(DAT_060d1372 + iVar7) = param_1;
        *(uint *)(DAT_060d1374 + iVar7) = param_2;
        *(uint *)(DAT_060d1376 + iVar7) = param_3;
        puVar2 = PTR_FUN_060d137c;
        piVar5 = (int *)(iVar4 + DAT_060d136c);
        *piVar5 = *piVar5 + 1;
        (*(code *)puVar2)(auStack_c);
        uVar3 = 0;
      }
    }
  }
  else {
    uVar3 = 0xfffffffa;
  }
  return uVar3;
}



undefined4 FUN_060d1380(int param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  int local_24;
  int iStack_20;
  int aiStack_1c [2];
  
  iVar2 = (*(code *)PTR_FUN_060d1448)(&local_24,&iStack_20,aiStack_1c);
  if (iVar2 == 0) {
    if ((param_1 < local_24) || (iStack_20 + local_24 <= param_1)) {
      iVar2 = (*(code *)PTR_FUN_060d144c)(0x17,param_1);
      puVar1 = PTR_FUN_060d1450;
      if (iVar2 != 0) {
        return 0xfffffff5;
      }
      iVar2 = (int)DAT_060d1444;
      do {
        iVar3 = (*(code *)puVar1)(iVar2);
      } while (iVar3 == 0);
      iVar2 = (*(code *)PTR_FUN_060d1448)(&local_24,&iStack_20,aiStack_1c);
      if (iVar2 != 0) {
        return 0xfffffff5;
      }
      if ((param_1 < local_24) && (iStack_20 + local_24 <= param_1)) {
        return 0xfffffff5;
      }
    }
    iVar2 = (*(code *)PTR_FUN_060d1454)(param_1,param_2);
    if (iVar2 == 0) {
      pbVar4 = (byte *)(param_2 + 0xb);
      if ((*pbVar4 & 2) != 0) {
        *pbVar4 = *pbVar4 | 0x80;
      }
      if ((aiStack_1c[0] != 0) && (local_24 + iStack_20 + -1 == param_1)) {
        *pbVar4 = *pbVar4 | 1;
      }
      (*(code *)PTR_FUN_060d1458)();
      return 0;
    }
  }
  return 0xfffffff5;
}



undefined4 FUN_060d145c(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined auStack_14 [4];
  undefined auStack_10 [4];
  undefined4 auStack_c [2];
  
  iVar1 = (*(code *)PTR_FUN_060d148c)(auStack_14,auStack_10,auStack_c);
  uVar2 = 0xfffffff6;
  if (iVar1 == 0) {
    (*(code *)PTR_FUN_060d1490)();
    uVar2 = auStack_c[0];
  }
  return uVar2;
}



uint FUN_060d1494(void)

{
  int *piVar1;
  undefined *puVar2;
  undefined *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  code *pcVar7;
  int iVar8;
  bool bVar9;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int aiStack_1c [2];
  
  aiStack_1c[0] = 0;
  iVar6 = *(int *)(*DAT_060d1574 + 0x3c);
  iVar8 = 0;
  if ((iVar6 == 0) || (iVar6 = iVar6 + -1, *(int *)(*DAT_060d1574 + 0x3c) = iVar6, 0 < iVar6)) {
    iVar6 = (*(code *)PTR_FUN_060d157c)((int)DAT_060d1570);
    if (iVar6 == 1) {
      (*(code *)PTR_FUN_060d1580)((int)DAT_060d1572);
      piVar1 = DAT_060d1574;
      (*(code *)PTR_FUN_060d1584)(*DAT_060d1574 + 0x40);
      pcVar7 = *(code **)(*piVar1 + 0x4c);
      if (pcVar7 != (code *)0x0) {
        (*pcVar7)(*(undefined4 *)(*piVar1 + 0x50));
      }
    }
    else {
      (*(code *)PTR_FUN_060d1584)(&local_28);
      if ((local_28._0_1_ & 0xf) == 10) {
        return 2;
      }
      iVar6 = *DAT_060d1574;
      *(undefined4 *)(iVar6 + 0x40) = local_28;
      *(undefined4 *)(iVar6 + 0x44) = local_24;
      *(undefined4 *)(iVar6 + 0x48) = local_20;
    }
    puVar3 = PTR_FUN_060d158c;
    puVar2 = PTR_FUN_060d1588;
    iVar6 = 0;
    do {
      iVar5 = (*(code *)puVar2)(iVar6);
      if (iVar5 == 0) {
        uVar4 = (*(code *)puVar3)(iVar6,aiStack_1c);
        if ((int)uVar4 < 0) {
          return uVar4;
        }
        bVar9 = 0x1e < aiStack_1c[0];
        iVar8 = iVar8 + uVar4;
        if (bVar9) break;
      }
      iVar6 = iVar6 + 1;
      bVar9 = 0 < iVar8;
    } while (iVar6 < 8);
    uVar4 = (uint)bVar9;
  }
  else {
    (*(code *)PTR_FUN_060d1578)();
    uVar4 = 3;
  }
  return uVar4;
}



bool FUN_060d1590(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int in_r2;
  
  switch(param_1) {
  case 0:
    in_r2 = *(int *)(*DAT_060d1614 + 0x58);
    goto switchD_060d15a4_caseD_8;
  case 1:
    iVar1 = (int)DAT_060d1604;
    iVar2 = *DAT_060d1614;
    break;
  case 2:
    iVar1 = (int)DAT_060d1606;
    iVar2 = *DAT_060d1614;
    break;
  case 3:
    iVar1 = (int)DAT_060d1608;
    iVar2 = *DAT_060d1614;
    break;
  case 4:
    iVar1 = (int)DAT_060d160a;
    iVar2 = *DAT_060d1614;
    break;
  case 5:
    iVar1 = (int)DAT_060d160c;
    iVar2 = *DAT_060d1614;
    break;
  case 6:
    iVar1 = (int)DAT_060d160e;
    iVar2 = *DAT_060d1614;
    break;
  case 7:
    iVar2 = *DAT_060d1614;
    iVar1 = (int)DAT_060d1610;
    break;
  default:
    goto switchD_060d15a4_caseD_8;
  }
  in_r2 = *(int *)(iVar2 + iVar1);
switchD_060d15a4_caseD_8:
  return in_r2 == 0;
}



void FUN_060d1618(undefined4 param_1,undefined4 param_2)

{
  switch(param_1) {
  case 0:
    (*(code *)PTR_FUN_060d169c)();
    break;
  case 1:
    (*(code *)PTR_FUN_060d16a0)();
    break;
  case 2:
    (*(code *)PTR_FUN_060d16a4)();
    break;
  case 3:
    (*(code *)PTR_FUN_060d16a8)();
    break;
  case 4:
    (*(code *)PTR_FUN_060d16ac)();
    break;
  case 5:
    (*(code *)PTR_FUN_060d16b0)();
    break;
  case 6:
    (*(code *)PTR_FUN_060d16b4)();
    break;
  case 7:
    (*(code *)PTR_FUN_060d16b8)(param_2);
  }
  return;
}



void FUN_060d16bc(undefined4 param_1)

{
  *(undefined4 *)(*DAT_060d16cc + 0x3c) = param_1;
  return;
}



int FUN_060d16d0(void)

{
  undefined *puVar1;
  int iVar2;
  
  (*(code *)PTR_FUN_060d1704)(DAT_060d1700);
  puVar1 = PTR_FUN_060d1708;
  do {
    iVar2 = (*(code *)puVar1)();
  } while (iVar2 == 1);
  (*(code *)PTR_FUN_060d1704)(0);
  return iVar2;
}



undefined4 FUN_060d170c(int *param_1)

{
  bool bVar1;
  int *piVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  undefined4 local_24;
  
  puVar3 = PTR_FUN_060d18bc;
  piVar2 = DAT_060d18b8;
  iVar9 = 0;
  if (0 < *(int *)(*DAT_060d18b8 + 0x54)) {
    iVar10 = 0;
    local_24 = 0x5c;
    do {
      iVar4 = *piVar2;
      if (*(int *)(iVar4 + 0x58) == 1) {
        iVar4 = (*(code *)PTR_FUN_060d18c0)
                          (*(undefined *)(iVar4 + iVar10 + 0x5c),
                           *(undefined *)(iVar4 + iVar10 + 0x5d));
        if (iVar4 != 0) break;
        (*(code *)puVar3)();
        *param_1 = *param_1 + 1;
        *(undefined4 *)(*piVar2 + 0x58) = 2;
        iVar4 = *piVar2;
      }
      if (*(int *)(iVar4 + 0x58) == 2) {
        iVar4 = (*(code *)PTR_FUN_060d18c4)
                          (*(undefined *)(iVar4 + iVar10 + 0x5c),local_24 + iVar4 + 2);
        if (iVar4 != 0) break;
        (*(code *)puVar3)();
        *param_1 = *param_1 + 1;
        bVar1 = *(int *)(*piVar2 + iVar10 + 0x68) == 0;
        if (bVar1) {
          uVar11 = (uint)bVar1;
        }
        else {
          uVar11 = 3;
        }
        *(uint *)(*piVar2 + 0x58) = uVar11;
      }
      iVar4 = *piVar2 + iVar10;
      if (*(int *)(*piVar2 + 0x58) == 3) {
        iVar4 = (*(code *)PTR_FUN_060d18c8)
                          (*(undefined *)(iVar4 + 0x5c),*(undefined4 *)(iVar4 + 100),
                           *(undefined4 *)(iVar4 + 0x68));
        if (iVar4 != 0) break;
        (*(code *)puVar3)();
        *param_1 = *param_1 + 1;
        *(undefined4 *)(*piVar2 + 0x58) = 1;
      }
      local_24 = local_24 + 0x10;
      iVar9 = iVar9 + 1;
      iVar10 = iVar10 + 0x10;
    } while (iVar9 < *(int *)(*piVar2 + 0x54));
  }
  piVar2 = DAT_060d18b8;
  iVar10 = 0;
  if (iVar9 < *(int *)(*DAT_060d18b8 + 0x54)) {
    iVar4 = 0;
    iVar7 = iVar9 << 4;
    do {
      iVar8 = *piVar2;
      iVar6 = iVar4 + iVar8;
      iVar5 = iVar7 + iVar8;
      iVar7 = iVar7 + 0x10;
      *(undefined4 *)(iVar6 + 0x5c) = *(undefined4 *)(iVar5 + 0x5c);
      iVar9 = iVar9 + 1;
      *(undefined4 *)(iVar6 + 0x60) = *(undefined4 *)(iVar5 + 0x60);
      iVar4 = iVar4 + 0x10;
      *(undefined4 *)(iVar6 + 100) = *(undefined4 *)(iVar5 + 100);
      *(undefined4 *)(iVar6 + 0x68) = *(undefined4 *)(iVar5 + 0x68);
      iVar10 = iVar10 + 1;
    } while (iVar9 < *(int *)(iVar8 + 0x54));
    *(int *)(*DAT_060d18b8 + 0x54) = iVar10;
  }
  else {
    *(int *)(*DAT_060d18b8 + 0x54) = 0;
  }
  iVar9 = (*(code *)PTR_FUN_060d18cc)(0x40);
  if ((iVar9 != 0) && (*(int *)(*DAT_060d18b8 + 0x54) == 0)) {
    *(undefined4 *)(*DAT_060d18b8 + 0x58) = 0;
  }
  return *(undefined4 *)(*DAT_060d18b8 + 0x54);
}



undefined4 FUN_060d18d0(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = DAT_060d1950;
  iVar3 = (int)DAT_060d194a;
  if (*(int *)(iVar3 + *DAT_060d1950) == 1) {
    iVar2 = (*(code *)PTR_FUN_060d1954)(*(undefined4 *)(*DAT_060d1950 + (int)DAT_060d194c));
    *param_1 = *param_1 + 1;
    if (iVar2 == 0) {
      *(undefined4 *)(iVar3 + *piVar1) = 2;
    }
    (*(code *)PTR_FUN_060d1958)();
  }
  piVar1 = DAT_060d1950;
  iVar3 = (int)DAT_060d194a;
  if ((*(int *)(iVar3 + *DAT_060d1950) == 2) &&
     (iVar2 = (*(code *)PTR_FUN_060d195c)(0x40), iVar2 != 0)) {
    *(undefined4 *)(iVar3 + *piVar1) = 0;
  }
  return *(undefined4 *)(*DAT_060d1950 + (int)DAT_060d194a);
}



undefined4 FUN_060d1960(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_1c;
  int aiStack_18 [2];
  
  piVar1 = DAT_060d1aa0;
  iVar6 = (int)DAT_060d1a92;
  if (*(int *)(iVar6 + *DAT_060d1aa0) == 1) {
    (*(code *)PTR_FUN_060d1aa4)(*(undefined4 *)(*DAT_060d1aa0 + (int)DAT_060d1a94),&local_1c);
    (*(code *)PTR_FUN_060d1aa8)();
    *param_1 = *param_1 + 1;
    iVar5 = *piVar1;
    local_1c = local_1c - *(int *)(iVar5 + DAT_060d1a96);
    if (*(int *)(iVar5 + DAT_060d1a98) < local_1c) {
      local_1c = *(int *)(iVar5 + DAT_060d1a98);
    }
    **(int **)(iVar5 + DAT_060d1a9a) = local_1c;
    iVar4 = *piVar1;
    iVar5 = (int)DAT_060d1a9c;
    if (*(int *)(iVar4 + iVar5) == 0) {
      *(undefined4 *)(iVar6 + iVar4) = 0;
      return 0;
    }
    if (local_1c < 1) {
      *(undefined4 *)(iVar6 + iVar4) = 0;
      **(undefined4 **)(iVar4 + iVar5) = 0;
      return 0;
    }
    *(undefined4 *)(iVar6 + iVar4) = 2;
  }
  piVar1 = DAT_060d1aa0;
  iVar6 = *DAT_060d1aa0;
  iVar5 = (int)DAT_060d1a92;
  if (*(int *)(iVar5 + iVar6) == 2) {
    if (*(int *)(iVar6 + 0x34) != -1) {
      return 2;
    }
    iVar4 = (int)DAT_060d1a94;
    iVar3 = (int)DAT_060d1a9a;
    *(undefined4 *)(iVar6 + 0x34) = *(undefined4 *)(iVar6 + iVar4);
    iVar6 = (*(code *)PTR_FUN_060d1aac)
                      (*(undefined4 *)(iVar6 + iVar4),*(undefined4 *)(DAT_060d1a96 + iVar6),
                       **(undefined4 **)(iVar3 + iVar6));
    if (iVar6 != 0) {
      return 2;
    }
    (*(code *)PTR_FUN_060d1aa8)();
    *param_1 = *param_1 + 1;
    *(undefined4 *)(iVar5 + *piVar1) = 3;
  }
  piVar1 = DAT_060d1aa0;
  iVar6 = (int)DAT_060d1a92;
  uVar2 = 1;
  if (*(int *)(iVar6 + *DAT_060d1aa0) == 3) {
    iVar5 = (*(code *)PTR_FUN_060d1ab0)(aiStack_18);
    if (iVar5 == 0) {
      (*(code *)PTR_FUN_060d1aa8)();
      *param_1 = *param_1 + 1;
      iVar5 = *piVar1;
      iVar4 = (int)DAT_060d1a9c;
      *(undefined4 *)(iVar6 + iVar5) = 0;
      **(int **)(iVar4 + iVar5) = aiStack_18[0] * 2;
      *(undefined4 *)(*piVar1 + 0x34) = 0xffffffff;
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  return uVar2;
}



undefined4 FUN_060d1ab4(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = DAT_060d1b44;
  iVar3 = *DAT_060d1b44;
  iVar4 = (int)DAT_060d1b3a;
  if (*(int *)(iVar4 + iVar3) == 1) {
    iVar3 = (*(code *)PTR_FUN_060d1b48)
                      (*(undefined4 *)(iVar3 + DAT_060d1b40),*(undefined4 *)(iVar3 + DAT_060d1b3e),
                       *(undefined4 *)(iVar3 + DAT_060d1b3c));
    if (iVar3 != 0) {
      return 1;
    }
    (*(code *)PTR_FUN_060d1b4c)();
    *param_1 = *param_1 + 1;
    *(undefined4 *)(iVar4 + *piVar1) = 2;
  }
  piVar1 = DAT_060d1b44;
  iVar3 = (int)DAT_060d1b3a;
  uVar2 = 1;
  if (*(int *)(iVar3 + *DAT_060d1b44) == 2) {
    iVar4 = (*(code *)PTR_FUN_060d1b50)(0);
    if (iVar4 == 0) {
      *(undefined4 *)(iVar3 + *piVar1) = 0;
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  return uVar2;
}



bool FUN_060d1b54(int *param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  piVar2 = DAT_060d1c70;
  iVar3 = *DAT_060d1c70;
  iVar4 = (int)DAT_060d1c66;
  bVar1 = true;
  if (*(int *)(iVar4 + iVar3) == 1) {
    if ((*(int *)(iVar3 + DAT_060d1c68) == 0) && (*(int *)(iVar3 + DAT_060d1c6a) == -1)) {
      iVar3 = (*(code *)PTR_FUN_060d1c74)(0,*(undefined4 *)(iVar3 + DAT_060d1c6c));
      if (iVar3 != 0) {
        return true;
      }
      (*(code *)PTR_FUN_060d1c78)();
      *param_1 = *param_1 + 1;
      *(undefined4 *)(iVar4 + *piVar2) = 4;
    }
    else if (*(int *)(*DAT_060d1c70 + (int)DAT_060d1c6a) == 0) {
      bVar1 = false;
    }
    else {
      *(undefined4 *)((int)DAT_060d1c66 + *DAT_060d1c70) = 2;
    }
  }
  piVar2 = DAT_060d1c70;
  iVar3 = *DAT_060d1c70;
  iVar4 = (int)DAT_060d1c66;
  if (*(int *)(iVar4 + iVar3) == 2) {
    iVar3 = (*(code *)PTR_FUN_060d1c7c)
                      (*(undefined4 *)(iVar3 + DAT_060d1c6c),*(undefined4 *)(iVar3 + DAT_060d1c68),
                       *(undefined4 *)(iVar3 + DAT_060d1c6a));
    *param_1 = *param_1 + 1;
    if (iVar3 == 0) {
      *(undefined4 *)(iVar4 + *piVar2) = 3;
      (*(code *)PTR_FUN_060d1c78)();
    }
  }
  if ((*(int *)(*DAT_060d1c70 + (int)DAT_060d1c66) == 3) &&
     (iVar3 = (*(code *)PTR_FUN_060d1c80)((int)DAT_060d1c6e), iVar3 != 0)) {
    bVar1 = false;
  }
  if ((*(int *)(*DAT_060d1c70 + (int)DAT_060d1c66) == 4) &&
     (iVar3 = (*(code *)PTR_FUN_060d1c80)(0x40), iVar3 != 0)) {
    bVar1 = false;
  }
  if (!bVar1) {
    (*(code *)PTR_FUN_060d1c84)(0xfffffff7);
    *(undefined4 *)((int)DAT_060d1c66 + *DAT_060d1c70) = 0;
  }
  return bVar1;
}



undefined8 FUN_060d1c88(int *param_1)

{
  int *piVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  piVar1 = DAT_060d1dd4;
  iVar5 = *DAT_060d1dd4;
  iVar7 = (int)DAT_060d1dc4;
  if (*(int *)(iVar7 + iVar5) == 1) {
    iVar6 = (int)DAT_060d1dc8;
    (*(code *)PTR_FUN_060d1dd8)(*(undefined4 *)(iVar6 + iVar5),iVar5 + DAT_060d1dc6);
    puVar2 = PTR_FUN_060d1ddc;
    *param_1 = *param_1 + 1;
    (*(code *)puVar2)();
    puVar3 = (undefined4 *)(*(code *)PTR_FUN_060d1de0)(*(undefined4 *)(iVar6 + *piVar1),0);
    uVar4 = 1;
    if (puVar3 != (undefined4 *)0x0) goto LAB_060d1db2;
    (*(code *)puVar2)();
    *param_1 = *param_1 + 1;
    *(undefined4 *)(iVar7 + *piVar1) = 2;
  }
  piVar1 = DAT_060d1dd4;
  iVar5 = *DAT_060d1dd4;
  iVar7 = (int)DAT_060d1dc4;
  if (*(int *)(iVar7 + iVar5) == 2) {
    puVar3 = (undefined4 *)
             (*(code *)PTR_FUN_060d1de4)
                       (*(undefined4 *)(iVar5 + DAT_060d1dce),*(undefined4 *)(iVar5 + DAT_060d1dcc),
                        *(undefined4 *)(iVar5 + DAT_060d1dca),*(undefined4 *)(iVar5 + DAT_060d1dc8))
    ;
    uVar4 = 1;
    if (puVar3 != (undefined4 *)0x0) goto LAB_060d1db2;
    (*(code *)PTR_FUN_060d1ddc)();
    *param_1 = *param_1 + 1;
    *(undefined4 *)(iVar7 + *piVar1) = 3;
    iVar5 = *DAT_060d1dd4;
    iVar7 = (int)DAT_060d1dc4;
  }
  piVar1 = DAT_060d1dd4;
  if ((*(int *)(iVar7 + iVar5) == 3) &&
     (iVar5 = (*(code *)PTR_FUN_060d1de8)((int)DAT_060d1dd0), iVar5 != 0)) {
    *(undefined4 *)(iVar7 + *piVar1) = 4;
  }
  piVar1 = DAT_060d1dd4;
  iVar5 = *DAT_060d1dd4;
  iVar7 = (int)DAT_060d1dc4;
  if (*(int *)(iVar7 + iVar5) == 4) {
    puVar3 = (undefined4 *)
             (*(code *)PTR_FUN_060d1de0)
                       (*(undefined4 *)(iVar5 + DAT_060d1dc8),*(undefined4 *)(iVar5 + DAT_060d1dc6))
    ;
    uVar4 = 1;
    if (puVar3 != (undefined4 *)0x0) goto LAB_060d1db2;
    *param_1 = *param_1 + 1;
    *(undefined4 *)(iVar7 + *piVar1) = 5;
  }
  piVar1 = DAT_060d1dd4;
  iVar5 = (int)DAT_060d1dc4;
  if ((*(int *)(iVar5 + *DAT_060d1dd4) == 5) &&
     (iVar7 = (*(code *)PTR_FUN_060d1de8)(0x40), iVar7 == 1)) {
    *(undefined4 *)(iVar5 + *piVar1) = 0;
  }
  puVar3 = (undefined4 *)(*DAT_060d1dd4 + (int)DAT_060d1dc4);
  uVar4 = *puVar3;
LAB_060d1db2:
  return CONCAT44(puVar3,uVar4);
}



undefined4 FUN_060d1dec(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  ushort *puVar7;
  int iVar8;
  byte local_30 [12];
  int iStack_24;
  int iStack_20;
  undefined auStack_1c [8];
  
  piVar1 = DAT_060d1ee8;
  iVar8 = (int)DAT_060d1ede;
  if (*(int *)(iVar8 + *DAT_060d1ee8) == 1) {
    iVar3 = (*(code *)PTR_FUN_060d1eec)(&iStack_24,&iStack_20,auStack_1c);
    if (iVar3 == 0) {
      *param_1 = *param_1 + 1;
      piVar2 = DAT_060d1ee8;
      iVar6 = *piVar1;
      puVar7 = (ushort *)(iVar6 + DAT_060d1ee2);
      if (((ushort)(iVar3 == 0) < *puVar7) &&
         ((iVar3 = (int)(short)*puVar7, iVar3 < iStack_24 || (iStack_20 + iStack_24 <= iVar3)))) {
        iVar8 = (*(code *)PTR_FUN_060d1ef0)(0x17,(int)*(short *)(*DAT_060d1ee8 + (int)DAT_060d1ee2))
        ;
        if (iVar8 != 0) {
          iVar8 = *piVar2;
          *(undefined4 *)(DAT_060d1ede + iVar8) = 0;
          puVar5 = *(undefined4 **)(DAT_060d1ee0 + iVar8);
          goto LAB_060d1f9a;
        }
        *param_1 = *param_1 + 1;
        *(undefined4 *)((int)DAT_060d1ede + *piVar2) = 2;
      }
      else {
        *(undefined4 *)(iVar8 + iVar6) = 3;
      }
      goto LAB_060d1e92;
    }
    iVar6 = (int)DAT_060d1ee0;
    iVar3 = *piVar1;
  }
  else {
LAB_060d1e92:
    piVar1 = DAT_060d1ee8;
    iVar8 = (int)DAT_060d1ede;
    if ((*(int *)(iVar8 + *DAT_060d1ee8) == 2) &&
       (iVar3 = (*(code *)PTR_FUN_060d1ef4)((int)DAT_060d1ee4), iVar3 != 0)) {
      iVar3 = (*(code *)PTR_FUN_060d1eec)(&iStack_24,&iStack_20,auStack_1c);
      if ((iVar3 != 0) ||
         ((iVar3 = (int)*(short *)(*piVar1 + (int)DAT_060d1ee2), iVar3 < iStack_24 &&
          (iStack_20 + iStack_24 <= iVar3)))) {
        iVar6 = (int)DAT_060d1ee0;
        iVar3 = *piVar1;
        goto LAB_060d1f94;
      }
      *(undefined4 *)((int)DAT_060d1fca + *DAT_060d1fd4) = 3;
    }
    piVar1 = DAT_060d1fd4;
    iVar8 = (int)DAT_060d1fca;
    if (*(int *)(iVar8 + *DAT_060d1fd4) == 3) {
      uVar4 = (*(code *)PTR_FUN_060d1fd8)(local_30);
      if ((uVar4 & 0x20) != 0) {
        return 0xfffffff3;
      }
      if ((local_30[0] & 0xf) == 7) {
        return 0xfffffff2;
      }
      iVar3 = *piVar1;
      iVar3 = (*(code *)PTR_FUN_060d1fdc)
                        ((int)*(short *)(iVar3 + DAT_060d1fce),(int)*(short *)(iVar3 + DAT_060d1fcc)
                        );
      if (iVar3 != 0) {
        return 1;
      }
      (*(code *)PTR_FUN_060d1fe0)();
      *param_1 = *param_1 + 1;
      *(undefined4 *)(iVar8 + *piVar1) = 4;
    }
    piVar1 = DAT_060d1fd4;
    iVar8 = (int)DAT_060d1fca;
    if ((*(int *)(iVar8 + *DAT_060d1fd4) != 4) ||
       (iVar3 = (*(code *)PTR_FUN_060d1fe4)((int)DAT_060d1fd0), iVar3 == 0)) {
LAB_060d1fae:
      return *(undefined4 *)(*DAT_060d1fd4 + (int)DAT_060d1fca);
    }
    *(undefined4 *)(iVar8 + *piVar1) = 0;
    iVar3 = (*(code *)PTR_FUN_060d1fe8)(&iStack_24,&iStack_20,auStack_1c);
    if (iVar3 == 0) {
      **(int **)((int)DAT_060d1fd2 + *piVar1) = iStack_20;
      goto LAB_060d1fae;
    }
    iVar3 = *piVar1;
    iVar6 = (int)DAT_060d1fd2;
  }
LAB_060d1f94:
  *(undefined4 *)(iVar8 + iVar3) = 0;
  puVar5 = *(undefined4 **)(iVar6 + iVar3);
LAB_060d1f9a:
  *puVar5 = 0xffffffff;
  return 0xfffffff5;
}



undefined4 FUN_060d1fec(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  byte bVar8;
  int iVar7;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  
  piVar4 = DAT_060d2120;
  iVar10 = 0;
  if (0 < *(int *)((int)DAT_060d2114 + *DAT_060d2120)) {
    iVar11 = 0;
    do {
      iVar1 = *(int *)((int)DAT_060d2116 + *piVar4 + iVar11);
      bVar8 = iVar1 != -2;
      if (!(bool)bVar8) {
        iVar1 = (int)DAT_060d2118;
      }
      iVar2 = *(int *)((int)DAT_060d211a + *piVar4 + iVar11);
      if (iVar2 == -2) {
        iVar2 = (int)DAT_060d2118;
      }
      else {
        bVar8 = bVar8 | 2;
      }
      iVar1 = (*(code *)PTR_FUN_060d2124)
                        (*(undefined4 *)(*piVar4 + iVar11 + (int)DAT_060d211c),bVar8,iVar1,iVar2);
      if (iVar1 != 0) break;
      iVar11 = iVar11 + 0xc;
      (*(code *)PTR_FUN_060d2128)();
      iVar10 = iVar10 + 1;
      *param_1 = *param_1 + 1;
    } while (iVar10 < *(int *)(*piVar4 + (int)DAT_060d2114));
  }
  iVar11 = (int)DAT_060d2114;
  piVar4 = (int *)(*DAT_060d2120 + iVar11);
  iVar1 = 0;
  if (iVar10 < *piVar4) {
    iVar12 = (int)DAT_060d211c;
    iVar6 = (int)DAT_060d2116;
    iVar7 = (int)DAT_060d211a;
    iVar9 = 0;
    iVar2 = iVar10 * 0xc;
    do {
      iVar5 = *DAT_060d2120;
      iVar3 = iVar5 + iVar9;
      iVar13 = iVar5 + iVar2;
      iVar10 = iVar10 + 1;
      *(undefined4 *)(iVar12 + iVar3) = *(undefined4 *)(iVar12 + iVar13);
      iVar1 = iVar1 + 1;
      *(undefined4 *)(iVar6 + iVar3) = *(undefined4 *)(iVar6 + iVar13);
      iVar2 = iVar2 + 0xc;
      *(undefined4 *)(iVar7 + iVar3) = *(undefined4 *)(iVar7 + iVar13);
      iVar9 = iVar9 + 0xc;
    } while (iVar10 < *(int *)(iVar11 + iVar5));
    *(int *)(iVar5 + DAT_060d2114) = iVar1;
  }
  else {
    *piVar4 = 0;
  }
  iVar10 = (*(code *)PTR_FUN_060d212c)(0x40);
  if ((iVar10 != 0) && (*(int *)(*DAT_060d2120 + (int)DAT_060d2114) == 0)) {
    *(undefined4 *)((int)DAT_060d211e + *DAT_060d2120) = 0;
  }
  return *(undefined4 *)(*DAT_060d2120 + (int)DAT_060d2114);
}



bool FUN_060d2130(uint param_1)

{
  uint uVar1;
  
  uVar1 = (*(code *)PTR_FUN_060d2150)();
  return (param_1 & uVar1) != 0;
}



void FUN_060d2154(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = DAT_060d21d0;
  iVar2 = 0;
  do {
    *(undefined *)(*piVar1 + iVar2) = 0;
    iVar3 = *piVar1 + iVar2;
    iVar2 = iVar2 + 1;
    *(undefined *)(iVar3 + 0x18) = 0;
  } while (iVar2 < 0x17);
  iVar2 = (int)DAT_060d21c0;
  iVar3 = *DAT_060d21d0;
  *(undefined4 *)(iVar3 + 0x30) = 0;
  *(undefined4 *)(iVar3 + 0x34) = 0xffffffff;
  *(undefined4 *)(iVar3 + 0x38) = 0xffffffff;
  *(undefined4 *)(iVar3 + 0x3c) = 0;
  *(undefined4 *)(iVar3 + 0x4c) = 0;
  *(undefined4 *)(iVar3 + 0x50) = 0;
  *(undefined4 *)(iVar3 + 0x54) = 0;
  *(undefined4 *)(iVar3 + 0x58) = 0;
  *(undefined4 *)(iVar3 + iVar2) = 0;
  *(undefined4 *)(iVar3 + DAT_060d21c2) = 0;
  *(undefined4 *)(iVar3 + DAT_060d21c4) = 0;
  *(undefined4 *)(iVar3 + DAT_060d21c6) = 0;
  *(undefined4 *)(iVar3 + DAT_060d21c8) = 0;
  *(undefined4 *)(iVar3 + DAT_060d21ca) = 0;
  *(undefined4 *)(iVar3 + DAT_060d21cc) = 0;
  *(undefined4 *)(iVar3 + DAT_060d21ce) = 0;
  return;
}



void FUN_060d21d4(void)

{
  undefined local_14 [16];
  
  (*(code *)PTR_FUN_060d21f8)(local_14);
  *(undefined *)(*DAT_060d21fc + 0x40) = local_14[0];
  return;
}



void FUN_060d2200(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *DAT_060d2218;
  *(undefined4 *)(iVar1 + 0x4c) = param_1;
  *(undefined4 *)(iVar1 + 0x50) = param_2;
  return;
}



bool FUN_060d221c(void)

{
  uint uVar1;
  
  uVar1 = (*(code *)PTR_FUN_060d223c)();
  return ((int)DAT_060d223a & uVar1) != 0;
}



void FUN_060d2240(void)

{
  (*(code *)PTR_FUN_060d2258)((int)DAT_060d2254);
  return;
}



bool FUN_060d225c(void)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  
  puVar2 = PTR_FUN_060d229c;
  puVar1 = PTR_FUN_060d2298;
  iVar4 = 0;
  do {
    iVar3 = (*(code *)puVar1)();
    iVar4 = iVar4 + 1;
    if (iVar3 == 1) {
      (*(code *)puVar2)();
      return false;
    }
  } while (DAT_060d2296 >= iVar4);
  return DAT_060d2296 < iVar4;
}



void FUN_060d22a0(void)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_060d22b8;
  *DAT_060d22b8 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  return;
}



void FUN_060d22bc(int param_1,int param_2)

{
  undefined4 local_10 [2];
  
  if (param_2 < 0) {
    local_10[0] = 0;
  }
  else {
    (*(code *)PTR_FUN_060d2300)(param_2,local_10,0,0);
  }
  *(undefined4 *)(param_1 + 0x1c) = 1;
  *(undefined4 *)(param_1 + 0x20) = local_10[0];
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}



undefined4 FUN_060d2460(void)

{
  return *(undefined4 *)PTR_DAT_060d246c;
}



void FUN_060d2470(undefined4 param_1,int *param_2,undefined4 *param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = (*(code *)PTR_FUN_060d24c0)();
  if (iVar1 == 0) {
    iVar3 = 0;
    uVar2 = 0;
    uVar4 = 0;
  }
  else {
    iVar3 = iVar1 + 0x20;
    uVar4 = *(undefined4 *)(iVar1 + 0x14);
    uVar2 = (uint)*(ushort *)(iVar1 + 0x1c);
  }
  if (param_2 != (int *)0x0) {
    *param_2 = iVar3;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = uVar4;
  }
  if (param_4 != (uint *)0x0) {
    *param_4 = uVar2;
  }
  return;
}



int FUN_060d24c4(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = (int *)(*(code *)PTR_FUN_060d24f0)();
  if (piVar1 == (int *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = 0;
    for (iVar3 = *piVar1; iVar3 != 0; iVar3 = *(int *)(iVar3 + (int)piVar1)) {
      iVar2 = iVar2 + 1;
    }
  }
  return iVar2;
}



int FUN_060d24f4(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_FUN_060d2510)();
  iVar2 = iVar1 + 4;
  if (iVar1 == 0) {
    iVar2 = 0;
  }
  return iVar2;
}



void FUN_060d2514(undefined4 param_1,undefined2 param_2)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_FUN_060d2538)();
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 0x1e) = param_2;
  }
  return;
}



int FUN_060d253c(void)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_FUN_060d255c)();
  if (iVar1 == 0) {
    iVar1 = -1;
  }
  else {
    iVar1 = (int)*(short *)(iVar1 + 0x1e);
  }
  return iVar1;
}



int * FUN_060d2560(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(*(code *)PTR_FUN_060d2598)();
  iVar2 = 0;
  if (piVar1 == (int *)0x0) {
LAB_060d2574:
    piVar1 = (int *)0x0;
  }
  else if (0 < param_1) {
    do {
      iVar2 = iVar2 + 1;
      if (*piVar1 == 0) goto LAB_060d2574;
      piVar1 = (int *)((int)piVar1 + *piVar1);
    } while (iVar2 < param_1);
  }
  return piVar1;
}



void FUN_060d259c(void)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_060d25b4;
  *DAT_060d25b4 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  return;
}



void FUN_060d25b8(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x1c) = 2;
  *(undefined4 *)(param_1 + 0x20) = param_2;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}



void FUN_060d2718(int param_1,uint param_2,int *param_3)

{
  uint uVar1;
  
  uVar1 = *(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x28);
  if ((int)param_2 < (int)uVar1) {
    uVar1 = param_2;
  }
  if (1 < (int)uVar1) {
    uVar1 = (uint)(1 < (int)uVar1);
  }
  *param_3 = uVar1 * (int)DAT_060d2742;
  return;
}



uint FUN_060d295c(undefined4 *param_1,int *param_2)

{
  bool bVar1;
  undefined2 uVar2;
  int *piVar3;
  char *pcVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined *puVar8;
  uint uVar9;
  char cVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  
  piVar3 = DAT_060d2b00;
  bVar1 = 1 < (byte)(*DAT_060d2af8 - 1U);
  if (bVar1) {
    *param_1 = 0;
    uVar9 = (uint)bVar1;
  }
  else {
    if ((*DAT_060d2afc & 0x10) == 0) {
      *DAT_060d2b04 = 0;
      *DAT_060d2b00 = 0;
    }
    else {
      iVar13 = *DAT_060d2b00;
      iVar11 = iVar13 + 1;
      *DAT_060d2b00 = iVar11;
      if (2 < iVar11) {
        *DAT_060d2b04 = 1;
        *piVar3 = iVar13;
      }
    }
    if (*DAT_060d2b0c < (int)(uint)*DAT_060d2b08) {
      *DAT_060d2b0c = *DAT_060d2b0c + 1;
      uVar9 = 0;
    }
    else {
      *DAT_060d2b0c = 0;
      pcVar4 = DAT_060d2b14;
      if ((*DAT_060d2b10 == 0) || ((byte)(*DAT_060d2b14 - 2U) < 2)) {
        cVar10 = '\x04';
        if (*DAT_060d2b14 == '\x04') {
          cVar10 = '\0';
        }
        *DAT_060d2b14 = cVar10;
        if (*DAT_060d2b14 == '\0') {
          *DAT_060d2b18 = *DAT_060d2b18 + 1;
        }
        if (*DAT_060d2b18 < 3) {
          (*(code *)PTR_FUN_060d2b34)();
        }
        else {
          if (*DAT_060d2b1c == '\x01') {
            (*(code *)PTR_FUN_060d2b20)(0xf);
          }
          if (0 < *DAT_060d2b24) {
            *DAT_060d2b28 = *DAT_060d2b28 + 1;
          }
          (*(code *)PTR_FUN_060d2b2c)();
          piVar5 = DAT_060d2b30;
          piVar3 = DAT_060d2b28;
          uVar2 = DAT_060d2af6;
          iVar11 = *DAT_060d2b28;
          while (iVar11 < 2) {
            *(char *)(*piVar5 + *piVar3 * 2) = (char)uVar2;
            *(undefined *)(*piVar3 * 2 + *piVar5 + 1) = 0;
            iVar11 = *piVar3 + 1;
            *piVar3 = iVar11;
          }
          *DAT_060d2b18 = *DAT_060d2b18 - 1;
        }
      }
      else {
        if (*DAT_060d2b14 != '\x04') {
          *DAT_060d2b18 = 0;
        }
        *pcVar4 = '\0';
      }
      if (*DAT_060d2b38 == '\x01') {
        *DAT_060d2b3c = 1;
        puVar6 = DAT_060d2b40;
        uVar12 = *DAT_060d2b40;
        *DAT_060d2b44 = uVar12;
        puVar7 = DAT_060d2b48;
        *puVar6 = *DAT_060d2b48;
        *puVar7 = uVar12;
      }
      else {
        *DAT_060d2b3c = 0;
      }
      piVar5 = DAT_060d2b50;
      piVar3 = DAT_060d2b30;
      iVar11 = *DAT_060d2b30;
      *DAT_060d2b4c = iVar11;
      puVar6 = DAT_060d2b54;
      *piVar3 = *piVar5;
      *piVar5 = iVar11;
      uVar12 = *puVar6;
      *DAT_060d2b44 = uVar12;
      puVar7 = DAT_060d2b58;
      *puVar6 = *DAT_060d2b58;
      *puVar7 = uVar12;
      *param_1 = uVar12;
      puVar8 = PTR_FUN_060d2b5c;
      *param_2 = *piVar5;
      (*(code *)puVar8)();
      uVar9 = (*(code *)PTR_FUN_060d2b60)();
    }
  }
  return uVar9;
}



void FUN_060d3194(void)

{
  if ((int)(uint)*DAT_060d31b4 <= *DAT_060d31b8) {
    *DAT_060d31bc = 1;
  }
  return;
}



void FUN_060d31c0(void)

{
  if ((DAT_060d31e8 < *DAT_060d31e4) && ((*DAT_060d31ec & 0x20) != 0)) {
    *DAT_060d31f0 = 2;
  }
  return;
}



void FUN_060d31f4(uint param_1)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  piVar1 = DAT_060d323c;
  iVar3 = *DAT_060d3238;
  *DAT_060d3234 = iVar3;
  *piVar1 = iVar3;
  *DAT_060d3240 = 1;
  puVar2 = DAT_060d3244;
  uVar4 = *DAT_060d3244;
  while (uVar4 < param_1) {
    *(undefined *)*piVar1 = *(undefined *)*puVar2;
    *piVar1 = *piVar1 + 1;
    uVar4 = *puVar2 + 2;
    *puVar2 = uVar4;
  }
  return;
}



void FUN_060d3248(void)

{
  byte *pbVar1;
  int *piVar2;
  byte *pbVar3;
  uint uVar4;
  
  pbVar3 = DAT_060d32a0;
  piVar2 = DAT_060d329c;
  pbVar1 = DAT_060d3298;
  uVar4 = 0;
  if (*DAT_060d3298 != 0) {
    do {
      *(undefined *)(uVar4 + *DAT_060d32a4 + (*pbVar3 + 2) * *piVar2 + 2) =
           *(undefined *)(uVar4 * *DAT_060d32a8 + *DAT_060d32ac);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *pbVar1);
  }
  return;
}



void FUN_060d32b0(void)

{
  int *piVar1;
  
  *DAT_060d3308 = 1;
  *DAT_060d330c = 0;
  *DAT_060d3310 = 0;
  *DAT_060d3314 = 0;
  *DAT_060d3318 = 0;
  *DAT_060d331c = 0;
  *DAT_060d3320 = 0;
  *DAT_060d3324 = 0;
  *DAT_060d3328 = 0;
  *DAT_060d332c = 0;
  *DAT_060d3330 = 0;
  *DAT_060d3334 = 0;
  piVar1 = DAT_060d3338;
  *(undefined *)*DAT_060d3338 = 0xf0;
  *(undefined *)(*piVar1 + 1) = 0;
  *(undefined *)(*piVar1 + 2) = 0xf0;
  *(undefined *)(*piVar1 + 3) = 0;
  return;
}



undefined4 FUN_060d333c(void)

{
  char *pcVar1;
  undefined4 uVar2;
  undefined *puVar3;
  undefined *puVar4;
  
  pcVar1 = DAT_060d338c;
  if (*DAT_060d338c == '\x04') {
    uVar2 = 1;
  }
  else {
    *DAT_060d338c = '\x03';
    uVar2 = 1;
    if ((*DAT_060d3390 & 1) == 0) {
      *DAT_060d3390 = 1;
      puVar4 = DAT_060d3398 + 2;
      puVar3 = DAT_060d3398 + 1;
      uVar2 = 0;
      *DAT_060d3394 = *DAT_060d3398;
      *DAT_060d339c = *puVar3;
      *DAT_060d33a0 = *puVar4;
      *DAT_060d33a4 = 0x10;
      *pcVar1 = '\x02';
    }
  }
  return uVar2;
}



void FUN_060d33a8(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  piVar2 = DAT_060d3400;
  piVar1 = DAT_060d33fc;
  if (0 < *DAT_060d33fc) {
    iVar4 = (int)DAT_060d33f8;
    do {
      if ((int)(uint)*DAT_060d3404 <= *piVar2) {
        return;
      }
      (*(code *)PTR_FUN_060d3408)(iVar4);
      (*(code *)PTR_FUN_060d340c)(0xf);
      iVar3 = *piVar1 + -1;
      *piVar1 = iVar3;
      *piVar2 = *piVar2 + 1;
    } while (0 < iVar3);
  }
  return;
}



void FUN_060d3410(undefined param_1)

{
  *(undefined *)((*DAT_060d3430 + 2) * *DAT_060d3434 + *DAT_060d3438) = param_1;
  return;
}



void FUN_060d343c(undefined param_1)

{
  *(undefined *)(*DAT_060d3468 + (*DAT_060d3460 + 2) * *DAT_060d3464 + 1) = param_1;
  return;
}



void FUN_060d346c(void)

{
  undefined *puVar1;
  char cVar2;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  puVar1 = PTR_FUN_060d34cc;
  local_24 = *DAT_060d34b8;
  uStack_20 = *DAT_060d34bc;
  uStack_1c = *DAT_060d34c0;
  uStack_18 = *DAT_060d34c4;
  uStack_14 = *DAT_060d34c8;
  uStack_10 = *DAT_060d34d0;
  cVar2 = (*(code *)PTR_FUN_060d34cc)(&local_24);
  if (cVar2 != '\0') {
    (*(code *)puVar1)(&local_24);
  }
  return;
}



undefined4 FUN_060d34d4(int *param_1)

{
  undefined2 uVar1;
  byte *pbVar2;
  int *piVar3;
  byte *pbVar4;
  int *piVar5;
  ushort *puVar6;
  byte *pbVar7;
  byte bVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  
  if (param_1[5] < 1) {
    *(undefined *)param_1[2] = *(undefined *)param_1[3];
    *(undefined *)(param_1[2] + 1) = *(undefined *)(param_1[3] + 1);
  }
  else {
    param_1[5] = param_1[5] + -1;
  }
  uVar10 = param_1[4];
  uVar9 = (uint)*(byte *)(param_1[2] + 1);
  iVar12 = 0;
  if ((int)uVar10 < (int)uVar9) {
    uVar14 = (uint)*(byte *)(param_1[3] + 1);
    if (uVar14 < uVar9) {
      if ((int)uVar10 < (int)uVar14) {
        iVar12 = uVar14 - uVar10;
        iVar13 = uVar9 - uVar14;
        uVar14 = uVar10;
      }
      else {
        iVar12 = 0;
        iVar13 = uVar9 - uVar10;
      }
    }
    else {
      iVar12 = uVar9 - uVar10;
      iVar13 = 0;
      uVar14 = uVar10;
    }
    param_1[4] = 0;
    uVar1 = DAT_060d3686;
    pbVar2 = DAT_060d3688;
    piVar3 = DAT_060d368c;
  }
  else {
    iVar13 = 0;
    uVar14 = (uint)*(byte *)(param_1[3] + 1);
    param_1[4] = uVar10 - uVar9;
    uVar10 = uVar9;
    uVar1 = DAT_060d3686;
    pbVar2 = DAT_060d3688;
    piVar3 = DAT_060d368c;
  }
  while( true ) {
    piVar5 = DAT_060d368c;
    pbVar4 = DAT_060d3688;
    DAT_060d3686 = uVar1;
    pbVar7 = pbVar2;
    DAT_060d368c = piVar3;
    if (iVar12 < 1) {
      while( true ) {
        DAT_060d3688 = pbVar7;
        if (iVar13 < 1) {
          bVar8 = *DAT_060d3688;
          *param_1 = (bVar8 + 2) * (uint)*(byte *)(param_1[2] + 1) + *param_1;
          param_1[1] = (bVar8 + 2) * (uint)*(byte *)(param_1[3] + 1) + param_1[1];
          param_1[2] = param_1[2] + 2;
          param_1[3] = param_1[3] + 2;
          return 1;
        }
        *(char *)(*param_1 + (*pbVar2 + 2) * uVar10) = (char)uVar1;
        *(undefined *)((*pbVar2 + 2) * uVar10 + *param_1 + 1) = 0xf;
        puVar6 = DAT_060d3690;
        iVar12 = *piVar3;
        *piVar3 = iVar12 + 1;
        iVar13 = iVar13 + -1;
        if ((int)(uint)*puVar6 <= iVar12 + 1) break;
        uVar10 = uVar10 + 1;
        pbVar7 = DAT_060d3688;
      }
      return 0;
    }
    bVar8 = *DAT_060d3688;
    DAT_060d3688 = pbVar2;
    *(undefined *)((bVar8 + 2) * uVar10 + *param_1) =
         *(undefined *)((bVar8 + 2) * uVar14 + param_1[1]);
    *(undefined *)((*pbVar4 + 2) * uVar10 + *param_1 + 1) =
         *(undefined *)((*pbVar4 + 2) * uVar14 + param_1[1] + 1);
    bVar8 = *pbVar4;
    for (iVar11 = 0; puVar6 = DAT_060d3690, iVar11 < (int)(uint)bVar8; iVar11 = iVar11 + 1) {
      *(undefined *)((*pbVar4 + 2) * uVar10 + iVar11 + *param_1 + 2) =
           *(undefined *)((*pbVar4 + 2) * uVar14 + iVar11 + param_1[1] + 2);
      bVar8 = *pbVar4;
    }
    iVar11 = *piVar5;
    *piVar5 = iVar11 + 1;
    uVar14 = uVar14 + 1;
    if ((int)(uint)*puVar6 <= iVar11 + 1) break;
    iVar12 = iVar12 + -1;
    uVar10 = uVar10 + 1;
    uVar1 = DAT_060d3686;
    pbVar2 = DAT_060d3688;
    piVar3 = DAT_060d368c;
    DAT_060d368c = piVar5;
    DAT_060d3688 = pbVar4;
  }
  return 0;
}



void FUN_060d3694(int param_1,undefined4 param_2)

{
  *(undefined4 *)(DAT_060d36b4 + param_1 * 4) = param_2;
  (*(code *)*DAT_060d36bc)(param_1,*(undefined4 *)(PTR_PTR_LAB_060d36b8 + param_1 * 4));
  return;
}



undefined4 FUN_060d36c0(int param_1)

{
  return *(undefined4 *)(param_1 * 4 + DAT_060d36d0);
}



void FUN_060d3cf8(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  do {
  } while ((*DAT_060d3e14 & 1) != 0);
  *DAT_060d3e14 = 1;
  *DAT_060d3e18 = 7;
  do {
  } while ((*DAT_060d3e14 & 1) != 0);
  *DAT_060d3e1c = DAT_060d3e06;
  iVar2 = DAT_060d3e24;
  (*(code *)PTR_FUN_060d3e28)(DAT_060d3e24,DAT_060d3e20);
  (*(code *)PTR_FUN_060d3e2c)(iVar2,*param_1,*(undefined2 *)(param_1 + 1));
  *DAT_060d3e30 = *DAT_060d3e34 + iVar2;
  iVar3 = *DAT_060d3e3c + iVar2;
  *DAT_060d3e38 = iVar3;
  *DAT_060d3e40 = CONCAT22(*DAT_060d3e44,*DAT_060d3e48) + iVar2;
  *DAT_060d3e4c = iVar3;
  *DAT_060d3e50 = *DAT_060d3e54 + iVar2;
  *DAT_060d3e58 = DAT_060d3e08 + iVar3;
  *DAT_060d3e5c = DAT_060d3e0a + iVar3;
  *DAT_060d3e60 = DAT_060d3e0c + iVar3;
  *DAT_060d3e64 = DAT_060d3e0e + iVar3;
  *DAT_060d3e68 = iVar3 + DAT_060d3e10;
  uVar1 = (uint)*(ushort *)(param_1 + 3) * 2;
  (*(code *)PTR_FUN_060d3e2c)
            (*(int *)(*DAT_060d3e30 + 8) + DAT_060d3e24,param_1[2],
             (uVar1 + 4) - (uVar1 - (uVar1 & 0xfffffffc)));
  *DAT_060d3e6c = 0;
  do {
  } while ((*DAT_060d3e14 & 1) != 0);
  *DAT_060d3e14 = 1;
  *DAT_060d3e18 = 6;
  do {
  } while ((*DAT_060d3e14 & 1) != 0);
  return;
}



void FUN_060d3e70(undefined4 param_1,undefined4 param_2)

{
  undefined4 local_18;
  uint *apuStack_14 [2];
  
  (*(code *)PTR_FUN_060d3eac)(&local_18,apuStack_14);
  (*(code *)PTR_FUN_060d3eb0)(local_18,param_1,param_2);
  *apuStack_14[0] = *apuStack_14[0] | DAT_060d3eb4;
  return;
}



undefined4 FUN_060d3eb8(undefined param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  char cVar4;
  int iVar5;
  
  piVar1 = DAT_060d3f78;
  if (*DAT_060d3f78 == 0) {
    *DAT_060d3f78 = 1;
    cVar4 = (*(code *)PTR_FUN_060d3f7c)();
    piVar2 = DAT_060d3f80;
    if (cVar4 == '\0') {
      *piVar1 = 0;
      uVar3 = 1;
    }
    else {
      *(undefined *)(*DAT_060d3f80 + 2) = param_1;
      *(undefined2 *)*piVar2 = DAT_060d3f74;
      if (*(short *)*piVar2 != 0) {
        iVar5 = 0;
        do {
          do {
            iVar5 = iVar5 + 1;
          } while (iVar5 < 0x20);
          iVar5 = 0;
        } while (*(short *)*DAT_060d3f80 != 0);
      }
      cVar4 = (*(code *)PTR_FUN_060d3f7c)();
      piVar1 = DAT_060d3f80;
      if (cVar4 == '\0') {
        *DAT_060d3f78 = 0;
        uVar3 = 1;
      }
      else {
        *(undefined *)(*DAT_060d3f80 + 2) = param_1;
        *(undefined2 *)*piVar1 = DAT_060d3f74;
        if (*(short *)*piVar1 != 0) {
          iVar5 = 0;
          do {
            do {
              iVar5 = iVar5 + 1;
            } while (iVar5 < 0x20);
            iVar5 = 0;
          } while (*(short *)*DAT_060d3f80 != 0);
        }
        *DAT_060d3f78 = 0;
        uVar3 = 0;
      }
    }
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}



undefined4 FUN_060d3f84(undefined param_1)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  
  piVar1 = DAT_060d3fd8;
  if (*DAT_060d3fd8 == 0) {
    *DAT_060d3fd8 = 1;
    cVar3 = (*(code *)PTR_FUN_060d3fdc)();
    piVar2 = DAT_060d3fe0;
    if (cVar3 != '\0') {
      *(undefined *)(*DAT_060d3fe0 + 2) = param_1;
      *(undefined2 *)*piVar2 = DAT_060d3fd4;
      *piVar1 = 0;
      return 0;
    }
    *DAT_060d3fd8 = 0;
  }
  return 1;
}



undefined4 FUN_060d3fe4(undefined param_1)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  
  piVar1 = DAT_060d4038;
  if (*DAT_060d4038 == 0) {
    *DAT_060d4038 = 1;
    cVar3 = (*(code *)PTR_FUN_060d403c)();
    piVar2 = DAT_060d4040;
    if (cVar3 != '\0') {
      *(undefined *)(*DAT_060d4040 + 2) = param_1;
      *(undefined2 *)*piVar2 = DAT_060d4034;
      *piVar1 = 0;
      return 0;
    }
    *DAT_060d4038 = 0;
  }
  return 1;
}



undefined4 FUN_060d4044(undefined param_1,undefined param_2)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  
  piVar1 = DAT_060d40a4;
  if (*DAT_060d40a4 == 0) {
    *DAT_060d40a4 = 1;
    cVar3 = (*(code *)PTR_FUN_060d40a8)();
    piVar2 = DAT_060d40ac;
    if (cVar3 != '\0') {
      *(undefined *)(*DAT_060d40ac + 2) = param_1;
      *(undefined *)(*piVar2 + 3) = param_2;
      *(undefined2 *)*piVar2 = DAT_060d40a0;
      *piVar1 = 0;
      return 0;
    }
    *DAT_060d40a4 = 0;
  }
  return 1;
}



undefined4 FUN_060d40b0(undefined param_1,char param_2,undefined4 param_3)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  byte bVar4;
  
  piVar1 = DAT_060d4128;
  if (*DAT_060d4128 == 0) {
    *DAT_060d4128 = 1;
    cVar3 = (*(code *)PTR_FUN_060d412c)();
    piVar2 = DAT_060d4130;
    if (cVar3 != '\0') {
      *(undefined *)(*DAT_060d4130 + 2) = param_1;
      bVar4 = (*(code *)PTR_FUN_060d4134)(param_3);
      *(byte *)(*piVar2 + 3) = bVar4 | param_2 * ' ';
      *(undefined2 *)*piVar2 = DAT_060d4126;
      *piVar1 = 0;
      return 0;
    }
    *DAT_060d4128 = 0;
  }
  return 1;
}



undefined4 FUN_060d41cc(void)

{
  int *piVar1;
  char cVar2;
  
  piVar1 = DAT_060d4214;
  if (*DAT_060d4214 == 0) {
    *DAT_060d4214 = 1;
    cVar2 = (*(code *)PTR_FUN_060d4218)();
    if (cVar2 != '\0') {
      *(undefined2 *)*DAT_060d421c = DAT_060d4210;
      *piVar1 = 0;
      return 0;
    }
    *DAT_060d4214 = 0;
  }
  return 1;
}



undefined4 FUN_060d4220(void)

{
  int *piVar1;
  char cVar2;
  
  piVar1 = DAT_060d4268;
  if (*DAT_060d4268 == 0) {
    *DAT_060d4268 = 1;
    cVar2 = (*(code *)PTR_FUN_060d426c)();
    if (cVar2 != '\0') {
      *(undefined2 *)*DAT_060d4270 = DAT_060d4264;
      *piVar1 = 0;
      return 0;
    }
    *DAT_060d4268 = 0;
  }
  return 1;
}



undefined4 FUN_060d4274(undefined param_1,undefined param_2,undefined param_3,undefined param_4)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  
  piVar1 = DAT_060d42fc;
  if (*DAT_060d42fc == 0) {
    *DAT_060d42fc = 1;
    cVar3 = (*(code *)PTR_FUN_060d4300)();
    piVar2 = DAT_060d4304;
    if (cVar3 != '\0') {
      *(undefined *)(*DAT_060d4304 + 2) = param_1;
      *(undefined *)(*piVar2 + 3) = param_2;
      *(undefined *)(*piVar2 + 4) = param_3;
      *(undefined *)(*piVar2 + 5) = param_4;
      (*(code *)PTR_FUN_060d4308)();
      *(undefined2 *)*piVar2 = DAT_060d42f8;
      (*(code *)PTR_FUN_060d430c)();
      *piVar1 = 0;
      return 0;
    }
    *DAT_060d42fc = 0;
  }
  return 1;
}



undefined4 FUN_060d4310(undefined param_1)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  
  piVar1 = DAT_060d4374;
  if (*DAT_060d4374 == 0) {
    *DAT_060d4374 = 1;
    cVar3 = (*(code *)PTR_FUN_060d4378)();
    piVar2 = DAT_060d437c;
    if (cVar3 != '\0') {
      *(undefined *)(*DAT_060d437c + 2) = param_1;
      (*(code *)PTR_FUN_060d4380)();
      *(undefined2 *)*piVar2 = DAT_060d4370;
      (*(code *)PTR_FUN_060d4384)();
      *piVar1 = 0;
      return 0;
    }
    *DAT_060d4374 = 0;
  }
  return 1;
}



undefined4 FUN_060d4388(undefined param_1)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  
  piVar1 = DAT_060d43dc;
  if (*DAT_060d43dc == 0) {
    *DAT_060d43dc = 1;
    cVar3 = (*(code *)PTR_FUN_060d43e0)();
    piVar2 = DAT_060d43e4;
    if (cVar3 != '\0') {
      *(undefined *)(*DAT_060d43e4 + 2) = param_1;
      *(undefined2 *)*piVar2 = DAT_060d43d8;
      *piVar1 = 0;
      return 0;
    }
    *DAT_060d43dc = 0;
  }
  return 1;
}



undefined4 FUN_060d4520(undefined param_1,undefined param_2)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  
  piVar1 = DAT_060d4590;
  if (*DAT_060d4590 == 0) {
    *DAT_060d4590 = 1;
    cVar3 = (*(code *)PTR_FUN_060d4594)();
    piVar2 = DAT_060d4598;
    if (cVar3 != '\0') {
      *(undefined *)(*DAT_060d4598 + 2) = param_1;
      *(undefined *)(*piVar2 + 3) = param_2;
      (*(code *)PTR_FUN_060d459c)();
      *(undefined2 *)*piVar2 = DAT_060d458c;
      (*(code *)PTR_FUN_060d45a0)();
      *piVar1 = 0;
      return 0;
    }
    *DAT_060d4590 = 0;
  }
  return 1;
}



undefined4 FUN_060d473c(byte *param_1,byte *param_2)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  byte bVar4;
  
  piVar1 = DAT_060d4844;
  if (*DAT_060d4844 == 0) {
    *DAT_060d4844 = 1;
    cVar3 = (*(code *)PTR_FUN_060d4848)();
    piVar2 = DAT_060d484c;
    if (cVar3 != '\0') {
      *(byte *)(*DAT_060d484c + 2) = *param_1 | *param_2;
      bVar4 = (*(code *)PTR_FUN_060d4850)((int)(char)param_2[2]);
      *(byte *)(*piVar2 + 3) = bVar4 | param_2[1] * ' ';
      *(byte *)(*piVar2 + 4) = param_1[2];
      *(byte *)(*piVar2 + 5) = param_1[3];
      *(byte *)(*piVar2 + 6) = param_1[4];
      *(byte *)(*piVar2 + 7) = param_1[5];
      *(byte *)(*piVar2 + 8) = param_2[4];
      *(byte *)(*piVar2 + 9) = param_2[5];
      *(byte *)(*piVar2 + 10) = param_2[6] * '\b' | param_2[7];
      *(byte *)(*piVar2 + 0xb) = param_2[8] * '\b' | param_2[9];
      *(undefined *)(*piVar2 + 0xd) = 0;
      *(undefined2 *)*piVar2 = DAT_060d4842;
      *piVar1 = 0;
      return 0;
    }
    *DAT_060d4844 = 0;
  }
  return 1;
}



undefined4 FUN_060d4854(undefined param_1)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  
  piVar1 = DAT_060d48a8;
  if (*DAT_060d48a8 == 0) {
    *DAT_060d48a8 = 1;
    cVar3 = (*(code *)PTR_FUN_060d48ac)();
    piVar2 = DAT_060d48b0;
    if (cVar3 != '\0') {
      *(undefined *)(*DAT_060d48b0 + 2) = param_1;
      *(undefined2 *)*piVar2 = DAT_060d48a4;
      *piVar1 = 0;
      return 0;
    }
    *DAT_060d48a8 = 0;
  }
  return 1;
}



undefined4 FUN_060d48b4(undefined param_1,undefined param_2)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  
  piVar1 = DAT_060d4924;
  if (*DAT_060d4924 == 0) {
    *DAT_060d4924 = 1;
    cVar3 = (*(code *)PTR_FUN_060d4928)();
    piVar2 = DAT_060d492c;
    if (cVar3 != '\0') {
      *(undefined *)(*DAT_060d492c + 2) = param_1;
      *(undefined *)(*piVar2 + 3) = param_2;
      (*(code *)PTR_FUN_060d4930)();
      *(undefined2 *)*piVar2 = DAT_060d4920;
      (*(code *)PTR_FUN_060d4934)();
      *piVar1 = 0;
      return 0;
    }
    *DAT_060d4924 = 0;
  }
  return 1;
}



void FUN_060d4bb0(ushort *param_1,int param_2)

{
  ushort *puVar1;
  
  puVar1 = (ushort *)(param_2 * 2 + *DAT_060d4bd0);
  *param_1 = *puVar1 & (ushort)DAT_060d4bd4;
  *(char *)(param_1 + 1) = (char)*puVar1;
  return;
}



void FUN_060d4bf0(undefined *param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = DAT_060d4c10;
  *param_1 = (char)((ushort)*(undefined2 *)(*DAT_060d4c10 + param_2 * 2) >> 8);
  param_1[1] = (char)*(undefined2 *)(param_2 * 2 + *piVar1);
  return;
}



void FUN_060d4c7c(undefined4 param_1,undefined4 param_2)

{
  (*(code *)PTR_FUN_060d4c94)(param_1,0,param_2);
  return;
}



void FUN_060d4c98(int *param_1,int *param_2,uint param_3,uint param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  piVar1 = DAT_060d4d0c;
  uVar2 = *(uint *)*DAT_060d4d0c;
  iVar3 = 1;
  while( true ) {
    if ((DAT_060d4d10 & uVar2) != 0) {
      return;
    }
    if (((DAT_060d4d14 & uVar2) >> 0x1c == param_3) && ((DAT_060d4d18 & uVar2) >> 0x18 == param_4))
    break;
    uVar2 = *(uint *)(iVar3 * 8 + *DAT_060d4d0c);
    iVar3 = iVar3 + 1;
  }
  *param_1 = (DAT_060d4d1c & uVar2) + DAT_060d4d20;
  *param_2 = (iVar3 + -1) * 8 + *piVar1 + 4;
  return;
}



uint FUN_060d4d24(uint param_1)

{
  if ((int)param_1 < 0) {
    param_1 = ~param_1 + 0x11;
  }
  return param_1 & 0xffff;
}



void FUN_060d4d3e(void)

{
  (*(code *)PTR_FUN_060d4d50)();
  return;
}



bool FUN_060d4d54(void)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  
  if (*(char *)*DAT_060d4de4 == '\0') {
    uVar3 = *DAT_060d4de8;
    *DAT_060d4de4 = uVar3;
    puVar1 = DAT_060d4de4;
    if (uVar3 < uVar3 + 0x70) {
      uVar3 = *DAT_060d4de8;
      do {
        if (*(char *)*puVar1 == '\0') {
          return *(char *)*puVar1 == '\0';
        }
        uVar2 = *puVar1;
        *puVar1 = uVar2 + 0x10;
      } while (uVar2 + 0x10 < uVar3 + 0x70);
    }
  }
  else if (((char *)*DAT_060d4de4 < (char *)(*DAT_060d4de8 + 0x70)) &&
          (uVar3 = *DAT_060d4de4, *DAT_060d4de4 = uVar3 + 0x10, puVar1 = DAT_060d4de4,
          uVar3 + 0x10 < *DAT_060d4de8 + 0x70)) {
    uVar3 = *DAT_060d4de8;
    do {
      if (*(char *)*puVar1 == '\0') {
        return *(char *)*puVar1 == '\0';
      }
      uVar2 = *puVar1;
      *puVar1 = uVar2 + 0x10;
    } while (uVar2 + 0x10 < uVar3 + 0x70);
  }
  return false;
}



bool FUN_060d4f24(void)

{
  return *(char *)*DAT_060d4f40 == '\0';
}



void FUN_060d4f44(void)

{
  *DAT_060d4f64 = (uint)*DAT_060d4f6c * 0x10 + *DAT_060d4f68;
  return;
}



void FUN_060d4f70(void)

{
  *DAT_060d4f98 = (char)(*DAT_060d4f98 + 1) + (char)((int)(*DAT_060d4f98 + 1 >> 2) >> 1) * -8;
  return;
}



void FUN_060d4f9c(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  
  piVar2 = DAT_060d500c;
  *DAT_060d500c = param_3;
  (*(code *)PTR_FUN_060d5010)(param_3,0,param_1 * 0x3c + param_2 * 0x30 + 0x30);
  piVar2 = (int *)*piVar2;
  *piVar2 = (int)(piVar2 + 0xc);
  piVar2[1] = param_1;
  piVar2[3] = param_2;
  piVar2[0xb] = 0;
  piVar2[2] = param_1 * 0x3c + *piVar2;
  piVar2[5] = -1;
  piVar2[6] = -1;
  puVar1 = DAT_060d5014;
  *DAT_060d5014 = 0;
  puVar1[1] = 0;
  piVar2[7] = 0;
  piVar2[8] = 0x300;
  piVar2[9] = 0;
  piVar2[10] = 0;
  return;
}



undefined4 * FUN_060d5018(void)

{
  undefined4 *puVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  undefined4 *puVar5;
  
  puVar1 = *(undefined4 **)*DAT_060d508c;
  iVar2 = 0;
  if (0 < (int)((undefined4 *)*DAT_060d508c)[1]) {
    iVar4 = (int)DAT_060d5088;
    pcVar3 = (char *)((int)puVar1 + 0x3a);
    puVar5 = puVar1 + 0xe;
    do {
      iVar2 = iVar2 + 1;
      if (*pcVar3 == '\0') {
        *puVar1 = 0;
        puVar1[1] = 0;
        puVar1[2] = 0;
        puVar1[3] = 0;
        puVar1[4] = 0;
        puVar1[5] = iVar4;
        puVar1[6] = (int)DAT_060d508a;
        puVar1[7] = 0;
        puVar1[8] = 0;
        puVar1[9] = 0;
        puVar1[10] = 0;
        puVar1[0xb] = DAT_060d5090;
        puVar1[0xc] = 0;
        puVar1[0xd] = 0xffffffff;
        *(undefined2 *)puVar5 = 0;
        *pcVar3 = '\x01';
        return puVar1;
      }
      pcVar3 = pcVar3 + 0x3c;
      puVar5 = puVar5 + 0xf;
      puVar1 = puVar1 + 0xf;
    } while (iVar2 < *(int *)(*DAT_060d508c + 4));
  }
  return (undefined4 *)0x0;
}



int FUN_060d5094(void)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  
  iVar1 = *(int *)(*DAT_060d50c8 + 8);
  iVar2 = *(int *)(*DAT_060d50c8 + 0xc);
  iVar4 = 0;
  if (0 < iVar2) {
    pcVar3 = (char *)(iVar1 + 0x2d);
    do {
      iVar4 = iVar4 + 1;
      if (*pcVar3 == '\0') {
        return iVar1;
      }
      pcVar3 = pcVar3 + 0x30;
      iVar1 = iVar1 + 0x30;
    } while (iVar4 < iVar2);
  }
  return 0;
}



undefined4 FUN_060d50cc(int param_1)

{
  undefined auStack_10 [4];
  undefined4 auStack_c [2];
  
  if (*(int *)(param_1 + 0xc) == 0) {
    auStack_c[0] = 0x96;
  }
  else {
    (*(code *)PTR_FUN_060d50f8)
              (*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x14),auStack_10,auStack_c);
  }
  return auStack_c[0];
}



void FUN_060d50fc(undefined4 param_1)

{
  undefined4 uVar1;
  
  switch(param_1) {
  case 0xfffffff0:
    uVar1 = 0xffffffe7;
    break;
  case 0xfffffff1:
  case 0xfffffff2:
    uVar1 = 0xfffffffe;
    break;
  case 0xfffffff3:
  case 0xfffffffe:
    uVar1 = 0xffffffe9;
    break;
  case 0xfffffff4:
    uVar1 = 0xffffffea;
    break;
  case 0xfffffff5:
  case 0xfffffff6:
    uVar1 = 0xffffffff;
    break;
  default:
    uVar1 = 0;
  }
  (*(code *)PTR_FUN_060d515c)(uVar1);
  return;
}



undefined4 FUN_060d5160(int *param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int local_30;
  int iStack_2c;
  int iStack_28;
  int aiStack_24 [2];
  
  puVar2 = PTR_FUN_060d526c;
  (*(code *)PTR_FUN_060d526c)(*(undefined4 *)(param_2 + 0x14),&local_30,&iStack_2c);
  iVar4 = *param_1;
  piVar5 = param_1;
  while ((iVar4 != 0 &&
         ((*(code *)puVar2)(*(undefined4 *)(*piVar5 + 0x14),&iStack_28,aiStack_24),
         iStack_28 < local_30))) {
    piVar5 = (int *)(*piVar5 + 8);
    iVar4 = *piVar5;
  }
  *(int *)(param_2 + 8) = *piVar5;
  *piVar5 = param_2;
  if (*(int *)(*(int *)(param_2 + 0x14) + 0x1c) == 0) {
    aiStack_24[0] = (*(code *)PTR_FUN_060d5270)(param_1);
    if (aiStack_24[0] < iStack_2c) {
      param_1[3] = param_2;
    }
    puVar2 = PTR_FUN_060d5274;
    piVar5 = param_1 + 1;
    iVar3 = *piVar5;
    iVar4 = 0;
    while (iVar1 = iVar3, iVar1 != 0) {
      piVar5 = (int *)(iVar1 + 0xc);
      iVar4 = iVar1;
      iVar3 = *piVar5;
    }
    (*(code *)PTR_FUN_060d5274)
              (*(undefined4 *)(*(int *)(param_2 + 0x14) + 0x28),
               *(undefined4 *)(*(int *)(param_2 + 0x14) + 0x20),(int)DAT_060d526a);
    if (iVar4 == 0) {
      if (-1 < param_1[0xd]) {
        (*(code *)PTR_FUN_060d5278)(*(undefined4 *)(*(int *)(param_2 + 0x14) + 0x28));
      }
      *piVar5 = param_2;
    }
    else {
      (*(code *)puVar2)(*(undefined4 *)(*(int *)(iVar4 + 0x14) + 0x28),
                        *(undefined4 *)(*(int *)(iVar4 + 0x14) + 0x20),
                        *(undefined4 *)(*(int *)(param_2 + 0x14) + 0x20));
      *piVar5 = param_2;
    }
    *(undefined4 *)(param_2 + 0xc) = 0;
    iVar4 = (*(code *)PTR_FUN_060d527c)();
    if (iVar4 != 0) {
      (*(code *)PTR_FUN_060d5280)(iVar4);
      return 0;
    }
  }
  if (((*(ushort *)(param_1 + 0xe) & 1) == 0) && ((param_3 & 2) == 0)) {
    if (param_2 != *param_1) {
      return 1;
    }
    param_1[2] = param_2;
  }
  return 1;
}



uint FUN_060d5284(short *param_1)

{
  uint uVar1;
  
  uVar1 = 0x40;
  if (*param_1 != -1) {
    uVar1 = 0x41;
  }
  if (param_1[1] != -1) {
    uVar1 = uVar1 | 2;
  }
  if (param_1[2] != -1) {
    uVar1 = uVar1 | 4;
  }
  if (param_1[4] != -1) {
    uVar1 = uVar1 | 8;
  }
  return uVar1;
}



void FUN_060d52cc(int param_1,undefined4 param_2,undefined *param_3)

{
  undefined *puVar1;
  
  *param_3 = *(undefined *)(param_1 + 1);
  puVar1 = PTR_FUN_060d5320;
  param_3[1] = *(undefined *)(param_1 + 3);
  param_3[2] = *(undefined *)(param_1 + 5);
  param_3[3] = *(undefined *)(param_1 + 7);
  param_3[4] = *(undefined *)(param_1 + 9);
  param_3[5] = *(undefined *)(param_1 + 0xb);
  (*(code *)puVar1)();
  return;
}



int * FUN_060d5324(int *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                  byte param_6)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  undefined auStack_40 [8];
  int iStack_38;
  undefined4 uStack_34;
  int iStack_30;
  undefined4 uStack_2c;
  byte local_25;
  int iStack_24;
  
  iVar5 = param_3 + 0xc;
  local_25 = param_6;
  uStack_2c = param_4;
  iStack_24 = iVar5;
  uVar2 = (*(code *)PTR_FUN_060d5474)(iVar5,*(undefined4 *)(param_3 + 0x20));
  *(undefined4 *)(param_3 + 0x20) = uVar2;
  *(undefined4 *)(param_3 + 0x24) = 0;
  *param_1 = param_2;
  param_1[1] = (int)param_1;
  param_1[4] = param_3;
  param_1[5] = iVar5;
  param_1[6] = 0;
  param_1[7] = 0;
  puVar1 = PTR_FUN_060d5478;
  pbVar4 = (byte *)(param_1 + 0xb);
  *pbVar4 = local_25;
  (*(code *)puVar1)(iVar5,&iStack_38,&uStack_34);
  if (((*(ushort *)(param_2 + 0x38) & 2) != 0) && (*(int *)(param_2 + 0x14) <= iStack_38)) {
    *pbVar4 = *pbVar4 | 1;
  }
  *(undefined *)((int)param_1 + 0x2d) = 1;
  *(undefined4 *)(param_3 + 0xa0) = 6;
  param_1[10] = 0x96;
  if (*(int *)(param_1[5] + 0x1c) == 0) {
    uVar2 = (*(code *)PTR_FUN_060d547c)(param_5,uStack_2c,auStack_40);
    (*(code *)PTR_FUN_060d5480)
              (*(undefined4 *)(param_3 + 0x34),uVar2,auStack_40,*(undefined4 *)(iStack_24 + 4),
               *(undefined4 *)(iStack_24 + 0x14));
    iVar3 = (*(code *)PTR_FUN_060d5484)();
    if (iVar3 != 0) {
      (*(code *)PTR_FUN_060d5488)(iVar3);
      return (int *)0x0;
    }
    (*(code *)PTR_FUN_060d5490)(iVar5,DAT_060d548c);
  }
  iVar5 = (*(code *)PTR_FUN_060d5494)(param_2,param_1,local_25);
  if (iVar5 == 0) {
    param_1 = (int *)0x0;
  }
  else if (((((*(ushort *)(param_2 + 0x38) & 0x22) == 2) && (*(int **)(param_2 + 0xc) == param_1))
           && ((*(code *)PTR_FUN_060d5498)(&iStack_30,0),
              iStack_30 < *(int *)(*DAT_060d549c + 0x18) + -10)) &&
          (iVar5 = (*(code *)PTR_FUN_060d54a0)(param_2,uStack_34), iVar5 != 0)) {
    (*(code *)PTR_FUN_060d54a4)(iVar5);
  }
  return param_1;
}



void FUN_060d54a8(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined *)((int)param_1 + 0x3a) = 0;
  return;
}



undefined4 FUN_060d54bc(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  
  if (*(int *)(param_1[5] + 0x1c) == 0) {
    iVar6 = *param_1;
    piVar3 = (int *)(iVar6 + 4);
    bVar7 = (int *)*piVar3 == (int *)0x0;
    piVar4 = (int *)0x0;
    piVar1 = (int *)*piVar3;
    if (!bVar7) {
      do {
        piVar2 = piVar1;
        if (piVar2 == param_1) break;
        piVar3 = piVar2 + 3;
        piVar1 = (int *)*piVar3;
        piVar4 = piVar2;
      } while ((int *)*piVar3 != (int *)0x0);
      bVar7 = *piVar3 == 0;
    }
    if (bVar7) {
      return 1;
    }
    iVar5 = param_1[3];
    *piVar3 = iVar5;
    if (iVar5 == 0) {
      iVar5 = (int)DAT_060d553c;
    }
    else {
      iVar5 = *(int *)(*(int *)(iVar5 + 0x14) + 0x28);
    }
    if (piVar4 == (int *)0x0) {
      (*(code *)PTR_FUN_060d5540)(iVar5,*(undefined4 *)(iVar6 + 0x34));
    }
    else {
      (*(code *)PTR_FUN_060d5544)
                (*(undefined4 *)(piVar4[5] + 0x28),*(undefined4 *)(piVar4[5] + 0x20));
    }
    iVar6 = (*(code *)PTR_FUN_060d5548)();
    if (iVar6 != 0) {
      (*(code *)PTR_FUN_060d554c)(iVar6);
      return 0;
    }
  }
  return 1;
}



undefined4 FUN_060d5550(undefined4 *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  uVar3 = 1;
  if (*(char *)((int)param_1 + 0x2d) == '\x01') {
    *(char *)((int)param_1 + 0x2d) = '\0';
    piVar1 = (int *)*param_1;
    uVar3 = 1;
    if (piVar1 != (int *)0x0) {
      puVar2 = (undefined4 *)*piVar1;
      while ((puVar2 != (undefined4 *)0x0 && (puVar2 != param_1))) {
        piVar1 = puVar2 + 2;
        puVar2 = (undefined4 *)*piVar1;
      }
      if (*piVar1 != 0) {
        *piVar1 = param_1[2];
      }
      uVar3 = (*(code *)PTR_FUN_060d55a8)(param_1);
      *param_1 = 0;
    }
  }
  return uVar3;
}



void FUN_060d55ac(int param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined auStack_24 [4];
  int aiStack_20 [2];
  
  puVar1 = PTR_FUN_060d5604;
  iVar3 = (int)DAT_060d5602;
  iVar4 = 0;
  for (iVar2 = *(int *)(param_1 + 4); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xc)) {
    if ((*(int *)(*(int *)(iVar2 + 0x14) + 0x1c) == 0) &&
       ((*(code *)puVar1)(*(int *)(iVar2 + 0x14),auStack_24,aiStack_20), iVar3 < aiStack_20[0])) {
      iVar3 = aiStack_20[0];
      iVar4 = iVar2;
    }
  }
  *(int *)(param_1 + 0xc) = iVar4;
  return;
}



bool FUN_060d5608(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (param_3 != 0) {
    (*(code *)PTR_FUN_060d5628)();
  }
  return param_3 != 0;
}



int FUN_060d562c(void)

{
  int iVar1;
  
  (*(code *)PTR_FUN_060d5650)((int)DAT_060d564c);
  iVar1 = (*(code *)PTR_FUN_060d5654)();
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  return iVar1;
}



void FUN_060d5658(undefined4 *param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  ushort *puVar4;
  int *piVar5;
  uint local_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  
  piVar5 = (int *)*param_1;
  if (*(char *)((int)param_1 + 0x2d) == '\x01') {
    if (param_1 == (undefined4 *)piVar5[2]) {
      for (puVar3 = (undefined4 *)*piVar5;
          (puVar3 != (undefined4 *)0x0 &&
          ((puVar3 == param_1 || ((*(byte *)(puVar3 + 0xb) & 2) != 0))));
          puVar3 = (undefined4 *)puVar3[2]) {
      }
      piVar5[2] = (int)puVar3;
      *(ushort *)(piVar5 + 0xe) = *(ushort *)(piVar5 + 0xe) & (ushort)DAT_060d5808;
    }
    if (param_1 == (undefined4 *)piVar5[4]) {
      (*(code *)PTR_FUN_060d580c)(param_1[4],0xffffffff);
      *(undefined4 *)(param_1[4] + 0xa0) = 0;
      iVar2 = param_1[2];
      piVar5[4] = iVar2;
      if (iVar2 == 0) {
        piVar5[4] = *piVar5;
      }
      if ((undefined4 *)piVar5[4] == param_1) {
        piVar5[4] = 0;
      }
    }
    puVar1 = PTR_FUN_060d5810;
    *(undefined4 *)(param_1[5] + 0x20) = *(undefined4 *)(param_1[5] + 0x28);
    (*(code *)puVar1)(param_1);
    (*(code *)PTR_FUN_060d5814)(param_1[5],0,0,0,0,0,0,&local_28);
    if (((*(ushort *)(piVar5 + 0xe) & 2) != 0) && ((local_28 & 0x40) == 0)) {
      (*(code *)PTR_FUN_060d5818)(param_1[5],&iStack_24,&iStack_20);
      (*(code *)PTR_FUN_060d581c)(&iStack_1c,0);
      if ((iStack_24 + -10 < iStack_1c) && (iStack_1c <= iStack_20)) {
        (*(code *)PTR_FUN_060d5820)();
      }
    }
    (*(code *)PTR_FUN_060d5824)(param_1[4]);
  }
  if (param_1 == (undefined4 *)piVar5[3]) {
    (*(code *)PTR_FUN_060d5828)(piVar5);
    if ((piVar5[3] != 0) && (puVar4 = (ushort *)(piVar5 + 0xe), (*puVar4 & 2) != 0)) {
      (*(code *)PTR_FUN_060d5818)(*(undefined4 *)(piVar5[3] + 0x14),&iStack_24,&iStack_20);
      if (iStack_20 - *(int *)(*DAT_060d582c + 0x14) < 0) {
        iStack_18 = (*(code *)PTR_FUN_060d5834)(piVar5);
        (*(code *)PTR_FUN_060d5838)(piVar5);
        piVar5[5] = 0x96;
        piVar5[0xc] = piVar5[0xc] + 1;
        *puVar4 = *puVar4 & (ushort)DAT_060d583c;
        iVar2 = iStack_18;
      }
      else {
        iVar2 = (*(code *)PTR_FUN_060d5830)(piVar5);
      }
      if (iVar2 != 0) {
        (*(code *)PTR_FUN_060d5840)(iVar2);
      }
    }
  }
  if ((piVar5[1] == 0) && (puVar4 = (ushort *)(piVar5 + 0xe), (*puVar4 & 2) != 0)) {
    iVar2 = (*(code *)PTR_FUN_060d5834)(piVar5);
    if (iVar2 == 0) {
      (*(code *)PTR_FUN_060d5838)(piVar5);
      piVar5[5] = 0x96;
      piVar5[0xc] = piVar5[0xc] + 1;
      *puVar4 = *puVar4 & (ushort)DAT_060d583c;
    }
    else {
      (*(code *)PTR_FUN_060d5840)(iVar2);
    }
  }
  return;
}



void FUN_060d5844(int *param_1)

{
  undefined *puVar1;
  int iVar2;
  
  (*(code *)PTR_FUN_060d58c0)((int)DAT_060d58be);
  puVar1 = PTR_FUN_060d58c8;
  if (param_1 == (int *)0x0) {
    (*(code *)PTR_FUN_060d58c4)(0xfffffff5);
  }
  else {
    iVar2 = *param_1;
    while (iVar2 != 0) {
      (*(code *)puVar1)();
      iVar2 = *param_1;
    }
    if (-1 < param_1[0xd]) {
      *(undefined4 *)(*DAT_060d58cc + 0x10) = 0;
      (*(code *)PTR_FUN_060d58d0)(param_1[0xd]);
      param_1[0xd] = -1;
      (*(code *)PTR_FUN_060d58d4)(0,0);
      (*(code *)PTR_FUN_060d58d8)();
    }
    (*(code *)PTR_FUN_060d58dc)(param_1);
    if (*(int *)(*DAT_060d58cc + 0x1c) == 0) {
      return;
    }
  }
  (*(code *)PTR_FUN_060d58e0)();
  return;
}



int FUN_060d5970(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                byte param_5)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_34;
  undefined auStack_30 [4];
  int iStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uStack_28 = param_1;
  uStack_24 = param_4;
  iVar3 = (*(code *)PTR_FUN_060d5a64)();
  if (iVar3 == 0) {
    (*(code *)PTR_FUN_060d5a68)(0xffffffed);
  }
  else {
    iVar4 = (*(code *)PTR_FUN_060d5a6c)();
    if (iVar4 == 0) {
      (*(code *)PTR_FUN_060d5a70)(iVar3);
      (*(code *)PTR_FUN_060d5a68)(0xffffffed);
    }
    else {
      iVar4 = (*(code *)PTR_FUN_060d5a74)(iVar4,param_2,param_3);
      iVar5 = (*(code *)PTR_FUN_060d5a78)(iVar3,uStack_28,iVar4,param_2,uStack_24,param_5);
      if (iVar5 != 0) {
        if ((param_5 & 2) != 0) {
          (*(code *)PTR_FUN_060d5a80)(iVar4,1);
        }
        if (*(int *)(*(int *)(iVar3 + 0x14) + 0x1c) != 0) {
          (*(code *)PTR_FUN_060d5a84)(iVar4,0,&local_34,0);
          (*(code *)PTR_FUN_060d5a88)(iVar4,local_34);
          puVar2 = PTR_FUN_060d5a90;
          puVar1 = PTR_FUN_060d5a8c;
          do {
            (*(code *)puVar1)(iVar4);
            (*(code *)puVar2)(iVar4,auStack_30,&iStack_2c);
          } while (iStack_2c < local_34);
        }
        *(undefined4 *)(*(int *)(iVar5 + 0x10) + 4) = 1;
        *(undefined4 *)(*(int *)(iVar5 + 0x10) + 8) = 1;
        (*(code *)PTR_FUN_060d5a94)(iVar4 + 0x6c);
        return iVar5;
      }
    }
  }
  (*(code *)PTR_FUN_060d5a7c)();
  return 0;
}



undefined4 FUN_060d5a98(undefined4 param_1,undefined4 param_2,int param_3,undefined param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined auStack_30 [10];
  byte local_26;
  ushort local_24;
  undefined2 local_22;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  
  iVar1 = (*(code *)PTR_FUN_060d5b2c)(param_2,auStack_30);
  if (iVar1 == 0) {
    local_22 = *(undefined2 *)(param_3 + 2);
    local_20 = *(undefined2 *)(param_3 + 4);
    local_1e = *(undefined2 *)(param_3 + 6);
    local_1c = *(undefined2 *)(param_3 + 8);
    local_1a = *(undefined2 *)(param_3 + 10);
    local_24 = (ushort)local_26;
    uVar2 = (*(code *)PTR_FUN_060d5b30)(param_1,auStack_30,param_2,&local_24,param_4);
  }
  else {
    (*(code *)PTR_FUN_060d5b34)(iVar1);
    (*(code *)PTR_FUN_060d5b38)();
    uVar2 = 0;
  }
  return uVar2;
}



undefined4 FUN_060d5b3c(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  
  (*(code *)PTR_FUN_060d5ba4)((int)DAT_060d5ba0);
  if (param_1 == 0) {
    uVar1 = 0xfffffff5;
LAB_060d5b74:
    (*(code *)PTR_FUN_060d5ba8)(uVar1);
    (*(code *)PTR_FUN_060d5bac)();
    uVar1 = 0;
  }
  else {
    if (param_4 == 0) {
      uVar1 = 4;
    }
    else {
      uVar1 = 0xffffffef;
      if (param_4 != 1) goto LAB_060d5b74;
      uVar1 = 0;
    }
    uVar1 = (*(code *)PTR_FUN_060d5bb0)(param_1,param_2,param_3,uVar1);
  }
  return uVar1;
}



void FUN_060d5da0(int param_1)

{
  (*(code *)PTR_FUN_060d5de4)((int)DAT_060d5de2);
  if (param_1 == 0) {
    (*(code *)PTR_FUN_060d5de8)(0xfffffff5);
    (*(code *)PTR_FUN_060d5dec)();
  }
  (*(code *)PTR_FUN_060d5df0)(*(undefined4 *)(param_1 + 4));
  if (*(int *)(*DAT_060d5df4 + 0x1c) != 0) {
    (*(code *)PTR_FUN_060d5dec)();
  }
  return;
}



void FUN_060d5ec8(undefined4 param_1)

{
  *(undefined4 *)(*DAT_060d5ed8 + 0x20) = param_1;
  return;
}



void FUN_060d5edc(int param_1)

{
  if (*(int *)(*DAT_060d5ef8 + 0x1c) == 0) {
    *(int *)(*DAT_060d5ef8 + 0x1c) = param_1;
  }
  return;
}



void FUN_060d5efc(void)

{
  int iVar1;
  
  iVar1 = *DAT_060d5f2c;
  if ((*(code **)(iVar1 + 0x24) != (code *)0x0) && (*(int *)(iVar1 + 0x1c) != 0)) {
    (**(code **)(iVar1 + 0x24))(*(undefined4 *)(iVar1 + 0x28));
  }
  *(int *)(iVar1 + 0x1c) = 0;
  return;
}



undefined4 FUN_060d5f30(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1[2] == 0) {
    iVar2 = *param_1;
    while ((uVar1 = 1, iVar2 != 0 && (uVar1 = 0, *(int *)(*(int *)(iVar2 + 0x14) + 0x1c) != 0))) {
      iVar2 = *(int *)(iVar2 + 8);
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



undefined4 FUN_060d5f60(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_1[2] == 0) && (param_1[1] == 0)) {
    iVar2 = *param_1;
    uVar1 = 1;
    if (iVar2 != 0) {
      do {
        if ((*(byte *)(iVar2 + 0x2c) & 2) == 0) goto LAB_060d5f70;
        iVar2 = *(int *)(iVar2 + 8);
      } while (iVar2 != 0);
      uVar1 = 1;
    }
  }
  else {
LAB_060d5f70:
    uVar1 = 0;
  }
  return uVar1;
}



void FUN_060d5ff0(int param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = 0;
  if (param_1 == 3) {
    iVar2 = -0x17;
  }
  else if (param_1 == 4) {
    if (*(int *)(*DAT_060d6048 + 0x10) != 0) {
      iVar1 = (*(code *)PTR_FUN_060d604c)();
      bVar3 = true;
      if (iVar1 != 0) goto LAB_060d6034;
    }
    iVar2 = -2;
  }
  else if (param_1 == 6) {
    iVar2 = -0x19;
  }
  else {
    bVar3 = true;
    if (param_1 != 5) goto LAB_060d6034;
    iVar2 = -1;
  }
  bVar3 = iVar2 == 0;
LAB_060d6034:
  if (!bVar3) {
    (*(code *)PTR_FUN_060d6050)(iVar2);
  }
  return;
}



bool FUN_060d61ec(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_060d6224;
  iVar2 = *DAT_060d6224;
  if (iVar2 == 0) {
    (*(code *)PTR_FUN_060d6228)((int)DAT_060d6220);
    *piVar1 = (int)PTR_LAB_060d622c;
    piVar1[1] = param_1;
  }
  return iVar2 == 0;
}



bool FUN_060d6230(void)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
  iVar2 = (*(code *)PTR_FUN_060d6260)();
  puVar1 = PTR_FUN_060d6264;
  bVar4 = false;
  if (iVar2 != 0) {
    iVar2 = (int)DAT_060d625e;
    do {
      iVar3 = (*(code *)puVar1)();
      bVar4 = iVar3 == iVar2;
    } while (!bVar4);
  }
  return bVar4;
}



bool FUN_060d6268(int param_1)

{
  return *(int *)(*(int *)(param_1 + 0x10) + 0x78) != 0;
}



void FUN_060d6320(int *param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  
  puVar2 = PTR_FUN_060d635c;
  puVar1 = PTR_FUN_060d6358;
  for (iVar3 = *param_1; iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
    (*(code *)puVar1)(*(undefined4 *)(iVar3 + 0x10),0,0);
    (*(code *)puVar2)(iVar3);
  }
  return;
}



void FUN_060d6360(int *param_1)

{
  byte bVar1;
  undefined *puVar2;
  int iVar3;
  
  puVar2 = PTR_FUN_060d63a4;
  for (iVar3 = *param_1; iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
    bVar1 = *(byte *)(iVar3 + 0x2c);
    *(byte *)(iVar3 + 0x2c) = bVar1 & 0xcf;
    if ((bVar1 & 2) != 0) {
      (*(code *)puVar2)(*(undefined4 *)(iVar3 + 0x10),0,0);
    }
  }
  return;
}



undefined4 FUN_060d63a8(int *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (param_1[6] == (int)DAT_060d6440) {
    (*(code *)PTR_FUN_060d6444)();
    (*(code *)PTR_FUN_060d6448)(param_1);
  }
  if (param_2 == -1) {
    for (iVar1 = *param_1; (iVar1 != 0 && ((*(byte *)(iVar1 + 0x2c) & 10) != 0));
        iVar1 = *(int *)(iVar1 + 8)) {
    }
    param_1[2] = iVar1;
    *(ushort *)(param_1 + 0xe) = *(ushort *)(param_1 + 0xe) & (ushort)DAT_060d644c;
  }
  else if ((param_2 == 0) || ((*(byte *)(param_2 + 0x2c) & 2) == 0)) {
    if (param_2 != 0) {
      param_2 = *(int *)(param_2 + 4);
    }
    param_1[2] = param_2;
    *(ushort *)(param_1 + 0xe) = *(ushort *)(param_1 + 0xe) | 1;
  }
  else {
    uVar2 = 0;
  }
  param_1[0xb] = param_3;
  param_1[0xc] = 0;
  return uVar2;
}



void FUN_060d64b4(int *param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int local_1c;
  undefined auStack_18 [8];
  
  puVar1 = PTR_FUN_060d651c;
  iVar3 = param_1[5];
  for (iVar2 = *param_1; iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
    (*(code *)puVar1)(*(undefined4 *)(iVar2 + 0x14),&local_1c,auStack_18);
    if (((iVar3 <= local_1c) && ((*(byte *)(iVar2 + 0x2c) & 8) == 0)) ||
       ((*(byte *)(iVar2 + 0x2c) & 2) != 0)) {
      *(byte *)(iVar2 + 0x2c) = *(byte *)(iVar2 + 0x2c) | 1;
      *(undefined4 *)(*(int *)(iVar2 + 0x10) + 8) = 1;
    }
  }
  return;
}



void FUN_060d6520(int param_1)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined auStack_28 [4];
  int aiStack_24 [2];
  
  puVar3 = PTR_FUN_060d65b4;
  puVar2 = PTR_FUN_060d65b0;
  iVar6 = *(int *)(param_1 + 0x14);
  for (iVar5 = *(int *)(param_1 + 4); iVar5 != 0; iVar5 = *(int *)(iVar5 + 0xc)) {
    (*(code *)puVar2)(*(undefined4 *)(iVar5 + 0x14),auStack_28,aiStack_24);
    if (aiStack_24[0] < iVar6) {
      bVar1 = *(byte *)(iVar5 + 0x2c);
      if (((bVar1 & 1) != 0) && ((bVar1 & 4) != 0)) {
        *(byte *)(iVar5 + 0x2c) = bVar1 | 8;
        (*(code *)PTR_FUN_060d65b8)(iVar5);
        if (*(int *)(param_1 + 8) == iVar5) {
          uVar4 = *(undefined4 *)(param_1 + 0x30);
          (*(code *)puVar3)(param_1,0xffffffff,*(undefined4 *)(param_1 + 0x2c));
          *(undefined4 *)(param_1 + 0x30) = uVar4;
        }
        if (*(int *)(param_1 + 0xc) == iVar5) {
          (*(code *)PTR_FUN_060d65bc)(param_1);
        }
      }
    }
  }
  return;
}



int FUN_060d65c0(int *param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  int local_1c;
  int aiStack_18 [2];
  
  puVar1 = PTR_FUN_060d6624;
  if (param_2 < param_1[5]) {
    param_2 = param_1[5];
  }
  iVar2 = *param_1;
  do {
    if (iVar2 == 0) {
      return -1;
    }
    if ((*(byte *)(iVar2 + 0x2c) & 8) == 0) {
      (*(code *)puVar1)(*(undefined4 *)(iVar2 + 0x14),&local_1c,aiStack_18);
      if ((local_1c <= param_2) && (param_2 <= aiStack_18[0])) {
        return -1;
      }
      if (param_2 < local_1c) {
        return local_1c;
      }
    }
    iVar2 = *(int *)(iVar2 + 8);
  } while( true );
}



undefined4 FUN_060d6628(int param_1)

{
  undefined4 local_10;
  undefined auStack_c [8];
  
  (*(code *)PTR_FUN_060d664c)(*(undefined4 *)(*(int *)(param_1 + 8) + 0x14),&local_10,auStack_c);
  return local_10;
}



bool FUN_060d6650(int param_1,int param_2,int param_3,int param_4,int *param_5,undefined4 *param_6)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  ushort *puVar4;
  
  if (*(int *)(param_1 + 0x30) == *(int *)(param_1 + 0x2c)) {
    bVar1 = param_3 < *(int *)(param_1 + 0x14);
    if (bVar1) {
      *param_5 = -1;
      *param_6 = 0;
      return bVar1;
    }
    if (param_4 == 0) {
      uVar2 = (*(code *)PTR_FUN_060d6804)(0,0);
      (*(code *)PTR_FUN_060d6808)(uVar2);
      if (*(int *)(*DAT_060d680c + 0x18) < param_2) {
        uVar2 = (*(code *)PTR_FUN_060d6810)();
        *(undefined4 *)(param_1 + 0x14) = uVar2;
        *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + -1;
      }
    }
  }
  else if (((param_3 < *(int *)(param_1 + 0x14)) && ((*(ushort *)(param_1 + 0x38) & 2) == 0)) ||
          (*(int *)(param_1 + 4) == 0)) {
    bVar1 = *(int *)(param_1 + 8) == 0;
    if (bVar1) {
      *param_5 = -1;
      *param_6 = 0;
      return bVar1;
    }
    uVar2 = (*(code *)PTR_FUN_060d6814)(param_1);
    *(undefined4 *)(param_1 + 0x14) = uVar2;
    (*(code *)PTR_FUN_060d6818)(param_1);
  }
  puVar4 = (ushort *)(param_1 + 0x38);
  if ((*puVar4 & 2) == 0) {
    if (-1 < *(int *)(param_1 + 0x34)) {
      iVar3 = (*(code *)PTR_FUN_060d681c)(param_1,*(undefined4 *)(param_1 + 0x14));
      *param_5 = iVar3;
      if (-1 < iVar3) {
        *(int *)(param_1 + 0x14) = iVar3;
      }
      *param_6 = 1;
      *(int *)(param_1 + 0x18) = (int)DAT_060d6802;
      *param_5 = -1;
      return false;
    }
    *param_5 = -1;
  }
  else if ((*puVar4 & 4) == 0) {
    *param_5 = -1;
  }
  else {
    if (param_3 < param_2) {
      if (param_4 != 0) {
        *param_5 = -1;
        *param_6 = 0;
        return false;
      }
      *(int *)(param_1 + 0x14) = param_2;
      *puVar4 = *puVar4 & (ushort)DAT_060d6820;
      (*(code *)PTR_FUN_060d6828)(param_1,0);
      iVar3 = (*(code *)PTR_FUN_060d682c)(param_1);
      if (iVar3 == 0) {
        *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
      }
      *param_6 = 0;
      *param_5 = -1;
      if ((*(int *)(param_1 + 8) != 0) && (*(int *)(param_1 + 0x30) < *(int *)(param_1 + 0x2c))) {
        return false;
      }
      return true;
    }
    uVar2 = (*(code *)PTR_FUN_060d6804)(0);
    (*(code *)PTR_FUN_060d6808)(uVar2);
    if ((param_4 == 0) && (*(int *)(*DAT_060d680c + 0x18) < param_2)) {
      *(int *)(param_1 + 0x14) = param_2;
      *puVar4 = *puVar4 & (ushort)DAT_060d6820;
      *param_5 = -1;
    }
    else {
      *(int *)(param_1 + 0x14) = param_2;
      puVar4 = (ushort *)(param_1 + 0x38);
      if ((*puVar4 & 0x20) == 0) {
        iVar3 = (*(code *)PTR_FUN_060d681c)(param_1,param_2);
        *param_5 = iVar3;
        if (-1 < iVar3) {
          *puVar4 = *puVar4 | 0x20;
        }
      }
      else {
        if (param_4 != 2) {
          *puVar4 = (ushort)DAT_060d6824 & *puVar4;
        }
        *param_5 = -1;
      }
    }
  }
  *param_6 = 0;
  return false;
}



int FUN_060d6854(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  ushort *puVar2;
  
  iVar1 = 0;
  if (param_2 < 0) {
    if (((*(int *)(param_1 + 0x14) <= param_3) && (param_4 == 1)) &&
       (puVar2 = (ushort *)(param_1 + 0x38), (*puVar2 & 2) == 0)) {
      (*(code *)PTR_FUN_060d68b8)(param_1);
      iVar1 = (*(code *)PTR_FUN_060d68bc)(param_1);
      if (iVar1 == 0) {
        *puVar2 = *puVar2 | 2;
      }
    }
  }
  else {
    iVar1 = (*(code *)PTR_FUN_060d68b4)();
    *(int *)(param_1 + 0x14) = param_2;
  }
  return iVar1;
}



undefined4 FUN_060d68c0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_24;
  undefined4 auStack_20 [2];
  
  iVar1 = (*(code *)PTR_FUN_060d6974)();
  if (iVar1 == 1) {
    if ((((param_1[6] == (int)DAT_060d6970) || (uVar2 = 1, (*(ushort *)(param_1 + 0xe) & 0x40) != 0)
         ) && (uVar2 = 1, *param_1 != 0)) && (param_1[0xc] < param_1[0xb])) {
      (*(code *)PTR_FUN_060d6978)(param_1);
      (*(code *)PTR_FUN_060d697c)(param_1);
      param_1[5] = DAT_060d6980;
      param_1[6] = (int)DAT_060d6972;
      *(ushort *)(param_1 + 0xe) = *(ushort *)(param_1 + 0xe) & (ushort)DAT_060d6984;
      uVar2 = 1;
    }
  }
  else {
    uVar2 = (*(code *)PTR_FUN_060d6988)(param_1,param_2,param_3,param_4,&local_24,auStack_20);
    iVar1 = (*(code *)PTR_FUN_060d698c)(param_1,local_24,param_3,auStack_20[0]);
    if (iVar1 != 0) {
      (*(code *)PTR_FUN_060d6990)(iVar1);
    }
  }
  return uVar2;
}



undefined4 FUN_060d6994(int param_1)

{
  int iVar1;
  undefined4 local_c [2];
  
  if (*(int *)(*(int *)(param_1 + 0x14) + 0x1c) == 0) {
    iVar1 = (*(code *)PTR_FUN_060d69e8)
                      (*(undefined4 *)(*(int *)(param_1 + 0x14) + 0x20),0,DAT_060d69e4,local_c,0);
    if ((iVar1 != 0) || (iVar1 = (*(code *)PTR_FUN_060d69ec)(), iVar1 != 0)) {
      (*(code *)PTR_FUN_060d69f0)(iVar1);
      local_c[0] = 0;
    }
  }
  else {
    local_c[0] = (*(code *)PTR_FUN_060d69f4)(*(undefined4 *)(param_1 + 0x10));
  }
  return local_c[0];
}



int FUN_060d6a44(int *param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint local_1c [2];
  
  iVar3 = *(int *)(*param_1 + 0x14);
  if (((*(byte *)(param_1 + 0xb) & 8) == 0) || (param_4 != 0)) {
    if ((param_3 < iVar3) || (*(int *)(param_1[5] + 0x1c) != 0)) {
      if (((*(byte *)(param_1 + 0xb) & 1) != 0) && (param_4 == 0)) goto LAB_060d6ac4;
LAB_060d6ac8:
      iVar2 = param_1[10];
      if (iVar2 == DAT_060d6b14) {
        iVar2 = (*(code *)PTR_FUN_060d6b18)(*param_1);
      }
      if ((*(int *)(param_1[4] + 0x9c) != 0) &&
         (((iVar3 < param_2 || (iVar2 <= iVar3)) &&
          (iVar3 = (*(code *)PTR_FUN_060d6b1c)(param_1), iVar3 != 1)))) {
LAB_060d6af2:
        return (int)DAT_060d6b08;
      }
    }
    else {
      if (((*(byte *)(param_1 + 0xb) & 1) == 0) && ((*(byte *)(param_1 + 0xb) & 4) != 0)) {
        return 0x20;
      }
      uVar1 = (*(code *)PTR_FUN_060d6b0c)(0,local_1c);
      (*(code *)PTR_FUN_060d6b10)(uVar1);
      if ((local_1c[0] & 8) == 0) goto LAB_060d6af2;
      if (param_4 != 0) goto LAB_060d6ac8;
    }
    iVar3 = (int)DAT_060d6b06;
  }
  else {
LAB_060d6ac4:
    iVar3 = 0x100;
  }
  return iVar3;
}



undefined4 FUN_060d6b20(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_10 [2];
  
  iVar2 = *(int *)(param_1 + 0x10);
  if (((*(int *)(param_1 + 0x18) == 0) && (*(int *)(iVar2 + 0x6c) == 0)) ||
     (iVar1 = (*(code *)PTR_FUN_060d6b68)(iVar2 + 0x6c), iVar1 < 1)) {
    local_10[0] = 0;
  }
  else {
    (*(code *)PTR_FUN_060d6b6c)(iVar2,local_10);
  }
  return local_10[0];
}



void FUN_060d6b70(int param_1)

{
  ushort *puVar1;
  
  if ((*(code **)(param_1 + 0x24) != (code *)0x0) &&
     (puVar1 = (ushort *)(param_1 + 0x38), (*puVar1 & 8) != 0)) {
    (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28));
    *puVar1 = *puVar1 & (ushort)DAT_060d6ba0;
  }
  return;
}



int FUN_060d6ba4(int *param_1,int param_2,char param_3,uint *param_4,int *param_5)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_44;
  int local_40;
  int iStack_3c;
  char local_35;
  uint *puStack_34;
  int *piStack_30;
  int iStack_2c;
  int iStack_28;
  uint uStack_24;
  
  piStack_30 = param_5;
  iStack_28 = 0;
  *param_4 = 0;
  iVar8 = param_1[4];
  iVar9 = 1;
  iStack_3c = param_2;
  local_35 = param_3;
  puStack_34 = param_4;
  if (*(int *)(*(int *)(iVar8 + 0x14) + 0x1c) == 0) {
    (*(code *)PTR_FUN_060d6cc4)(*(int *)(iVar8 + 0x14),&local_44,&local_40);
  }
  else {
    local_44 = (int)DAT_060d6cc2;
    local_40 = local_44;
  }
  bVar1 = *(byte *)(iVar8 + 0x2c);
  iVar6 = *(int *)(iVar8 + 0x28);
  if (iVar6 == DAT_060d6cc8) {
    iVar6 = (*(code *)PTR_FUN_060d6ccc)(param_1);
  }
  if ((((bVar1 & 0x10) == 0) && (local_44 < param_1[5])) && (iVar6 <= param_1[5])) {
    *(byte *)(iVar8 + 0x2c) = *(byte *)(iVar8 + 0x2c) | 0x10;
  }
  if ((((bVar1 & 0x20) == 0) && (local_40 < param_1[5])) && (iVar6 <= param_1[5])) {
    *(byte *)(iVar8 + 0x2c) = *(byte *)(iVar8 + 0x2c) | 0x20;
  }
  if (((bVar1 & 0x20) == 0) && ((*(byte *)(iVar8 + 0x2c) & 0x20) != 0)) {
    iVar6 = (*(code *)PTR_FUN_060d6cd0)(*(undefined4 *)(iVar8 + 0x10));
    iVar7 = *(int *)(iVar8 + 0x10);
  }
  else {
    if (((bVar1 & 0x10) != 0) || ((*(byte *)(iVar8 + 0x2c) & 0x10) == 0)) goto LAB_060d6c94;
    iVar7 = *(int *)(iVar8 + 0x10);
    iVar6 = DAT_060d6cc8;
  }
  (*(code *)PTR_FUN_060d6cd4)(iVar7 + 0x6c,iVar6);
LAB_060d6c94:
  (*(code *)PTR_FUN_060d6cd8)(iVar8);
  iVar6 = (*(code *)PTR_FUN_060d6cdc)(iVar8);
  bVar2 = iVar6 == 1;
  iVar6 = 0;
  if (bVar2) {
    *puStack_34 = (uint)bVar2;
    iVar9 = (*(code *)PTR_FUN_060d6ce0)(iVar8,local_44,local_40,bVar2);
    *piStack_30 = iVar9;
    iVar9 = 0;
  }
  else {
    iVar7 = (int)DAT_060d6db8;
    uStack_24 = (int)local_35 - 1U & 0xff;
    iStack_2c = iVar8;
    do {
      if (iStack_28 == 1) break;
      do {
        iVar8 = *(int *)(iVar8 + 8);
        if (iVar8 == 0) {
          iVar8 = *param_1;
        }
        if (iVar8 == iStack_3c) {
          *puStack_34 = (uint)(iVar8 == iStack_3c);
        }
        iVar4 = (*(code *)PTR_FUN_060d6dc0)(*(undefined4 *)(iVar8 + 0x10));
        iVar5 = iVar7;
        iVar3 = iVar7;
        if (*(int *)(*(int *)(iVar8 + 0x14) + 0x1c) == 0) {
          (*(code *)PTR_FUN_060d6dc4)(*(int *)(iVar8 + 0x14),&local_44,&local_40);
          iVar5 = local_44;
          iVar3 = local_40;
        }
        local_40 = iVar3;
        local_44 = iVar5;
        iVar5 = (*(code *)PTR_FUN_060d6dc8)(iVar8,local_44,local_40,iVar4);
        *piStack_30 = iVar5;
        if (((0 < iVar4) || (uStack_24 < 2)) &&
           (((iVar6 == 0 && (iVar5 == DAT_060d6dba)) || ((iVar6 == 1 && (iVar5 == DAT_060d6dbc))))))
        {
          iVar9 = 0;
          iStack_28 = 1;
          break;
        }
        if ((uint)(*piStack_30 + (int)DAT_060d6dbe) < 2) {
          iVar9 = 0;
        }
      } while (iVar8 != iStack_2c);
      iVar6 = iVar6 + 1;
    } while (iVar6 < 2);
    param_1[4] = iVar8;
    if ((iStack_28 == 0) && (iVar9 == 0)) {
      *piStack_30 = (int)DAT_060d6dba;
    }
  }
  return iVar9;
}



void FUN_060d6dcc(int *param_1)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = PTR_FUN_060d6dfc;
  for (iVar2 = *param_1; iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
    (*(code *)puVar1)(*(undefined4 *)(iVar2 + 0x10),0,0);
  }
  return;
}



uint FUN_060d6e00(undefined4 *param_1,undefined param_2)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int local_2c;
  int iStack_28;
  int *piStack_24;
  
  if (param_1[4] == 0) {
    param_1[4] = *param_1;
  }
  puVar1 = PTR_FUN_060d6eb4;
  uVar4 = param_1[4];
  piStack_24 = &iStack_28;
  do {
    uVar2 = (*(code *)puVar1)(param_1,uVar4,param_2,&local_2c,piStack_24);
  } while (local_2c == 0);
  if ((iStack_28 == DAT_060d6eb0) || (param_1[6] == (int)DAT_060d6eb0)) {
    param_1[6] = iStack_28;
  }
  else {
    iVar3 = (*(code *)PTR_FUN_060d6eb8)(param_1);
    if (iVar3 == 1) {
      iVar3 = param_1[0xc];
      if ((int)param_1[0xb] <= iVar3) {
        param_1[5] = 0x96;
        uVar2 = (uint)((int)param_1[0xb] <= iVar3);
        *(ushort *)(param_1 + 0xe) = *(ushort *)(param_1 + 0xe) | 0x40;
      }
      else {
        uVar2 = 0;
        if (iStack_28 == DAT_060d6eb2) {
          param_1[0xc] = iVar3 + 1;
          *(ushort *)(param_1 + 0xe) = *(ushort *)(param_1 + 0xe) | 0x40;
        }
      }
    }
  }
  return uVar2;
}



int FUN_060d6ebc(void)

{
  bool bVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int *piVar8;
  int local_1c;
  undefined4 auStack_18 [2];
  
  puVar2 = DAT_060d6fbc;
  if ((code *)*DAT_060d6fbc == (code *)0x0) {
    (*(code *)PTR_FUN_060d6fc4)((int)DAT_060d6fb8);
    piVar3 = DAT_060d6fc0;
    iVar5 = *DAT_060d6fc0;
    piVar8 = *(int **)(iVar5 + 0x10);
    if ((piVar8 == (int *)0x0) || (*piVar8 == 0)) {
      iVar5 = (int)DAT_060d6fba;
    }
    else {
      bVar1 = *(int *)(iVar5 + 0x2c) == 0;
      if (bVar1) {
        *(uint *)(iVar5 + 0x2c) = (uint)bVar1;
        piVar4 = DAT_060d6fc8;
        if ((*DAT_060d6fc8 == 1) &&
           ((*(code *)PTR_FUN_060d6fcc)(*(undefined4 *)(piVar8[4] + 0x10),&local_1c), *piVar4 == 1))
        {
          *(undefined4 *)(*piVar3 + 0x2c) = 0;
          return piVar8[6];
        }
        (*(code *)PTR_FUN_060d6fd0)(piVar8);
        uVar6 = (*(code *)PTR_FUN_060d6fd4)(auStack_18,0);
        (*(code *)PTR_FUN_060d6fd8)(uVar6);
        if (*(int *)(*DAT_060d6fc0 + 0x1c) == 0) {
          uVar7 = (*(code *)PTR_FUN_060d6fe0)(piVar8);
          iVar5 = (*(code *)PTR_FUN_060d6fe4)(piVar8,auStack_18[0],uVar7,uVar6);
          local_1c = (*(code *)PTR_FUN_060d6fe8)(piVar8,uVar6 & 0xff);
          if ((iVar5 == 1) && (local_1c == 1)) {
            piVar8[6] = 0x100;
            (*(code *)PTR_FUN_060d6fec)(piVar8);
          }
        }
        else {
          (*(code *)PTR_FUN_060d6fdc)();
        }
        *(undefined4 *)(*DAT_060d6fc0 + 0x2c) = 0;
      }
      iVar5 = piVar8[6];
    }
  }
  else {
    iVar5 = (*(code *)*DAT_060d6fbc)(DAT_060d6fbc[1]);
    if (iVar5 == 1) {
      *puVar2 = 0;
      iVar5 = 0x104;
    }
    else {
      iVar5 = *(int *)(*DAT_060d6fc0 + 0x20);
    }
  }
  return iVar5;
}



void FUN_060d7908(int param_1,int param_2)

{
  undefined4 uVar1;
  
  (*(code *)PTR_FUN_060d7958)((int)DAT_060d7954);
  if (param_1 == 0) {
    uVar1 = 0xfffffff5;
  }
  else {
    uVar1 = 0xfffffff2;
    if (-1 < param_2) {
      (*(code *)PTR_FUN_060d7964)(*(int *)(*(int *)(param_1 + 4) + 0x10) + 0x6c,param_2);
      return;
    }
  }
  (*(code *)PTR_FUN_060d795c)(uVar1);
  (*(code *)PTR_FUN_060d7960)();
  return;
}



undefined4 FUN_060d79d4(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  (*(code *)PTR_FUN_060d7a5c)((int)DAT_060d7a5a);
  if (param_1 == 0) {
    uVar1 = 0xfffffff5;
  }
  else {
    uVar1 = 0xfffffff2;
    if (-1 < param_2) {
      iVar2 = *(int *)(*(int *)(param_1 + 4) + 0x14);
      if (*(int *)(iVar2 + 0x1c) == 0) {
        uVar1 = (*(code *)PTR_FUN_060d7a68)(iVar2,param_2);
        return uVar1;
      }
      iVar2 = (*(code *)PTR_FUN_060d7a6c)(*(int *)(param_1 + 4));
      if (param_2 < iVar2) {
        *param_3 = DAT_060d7a70;
        param_3[1] = 0;
        param_3[2] = 0;
        *(undefined *)(param_3 + 3) = 0;
        *(undefined *)((int)param_3 + 0xd) = 0;
        return 1;
      }
      return 0;
    }
  }
  (*(code *)PTR_FUN_060d7a60)(uVar1);
  (*(code *)PTR_FUN_060d7a64)();
  return 0;
}



void FUN_060d7b30(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *DAT_060d7b44;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  *(undefined4 *)(iVar1 + 0x24) = param_1;
  *(undefined4 *)(iVar1 + 0x28) = param_2;
  return;
}



undefined4 FUN_060d7b6c(void)

{
  undefined *puVar1;
  int iVar2;
  undefined auStack_18 [8];
  undefined4 uStack_10;
  
  puVar1 = PTR_FUN_060d7b90;
  do {
    iVar2 = (*(code *)puVar1)(auStack_18);
  } while (iVar2 != 0);
  return uStack_10;
}



void FUN_060d7b94(void)

{
  undefined *puVar1;
  byte local_1c [16];
  
  puVar1 = PTR_FUN_060d7bc4;
  do {
    (*(code *)puVar1)(local_1c);
  } while (1 < (byte)((local_1c[0] & 0xf) - 1));
  return;
}



void FUN_060d7bc8(undefined4 param_1,int *param_2,int *param_3)

{
  int iVar1;
  int local_18;
  uint auStack_14 [2];
  
  (*(code *)PTR_FUN_060d7c18)(param_1,0,param_2,0,&local_18,0,0,auStack_14);
  iVar1 = DAT_060d7c1c;
  if ((auStack_14[0] & 6) == 0) {
    iVar1 = *param_2 + local_18 + -1;
  }
  else {
    *param_2 = DAT_060d7c1c;
  }
  *param_3 = iVar1;
  return;
}



undefined4 FUN_060d7c20(int param_1)

{
  int iVar1;
  int iVar2;
  uint local_30;
  int iStack_2c;
  uint uStack_28;
  int iStack_24;
  undefined local_20;
  undefined auStack_1c [4];
  int iStack_18;
  undefined4 uStack_14;
  
  uStack_14 = 0;
  iVar2 = *(int *)(param_1 + 0x14);
  (*(code *)PTR_FUN_060d7c94)(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x14),auStack_1c,&iStack_18)
  ;
  if (iVar2 <= iStack_18) {
    local_30 = (uint)(iVar2 <= iStack_18);
    iStack_24 = (iStack_18 - iVar2) + 1;
    local_20 = 0;
    iStack_2c = iVar2;
    uStack_28 = local_30;
    iVar1 = (*(code *)PTR_FUN_060d7c98)(&local_30,*(undefined4 *)(param_1 + 0x34));
    if (iVar1 == -0xd) {
      uStack_14 = 0xffffffe9;
    }
    else if (iVar1 == 0) {
      iVar1 = *DAT_060d7c9c;
      *(int *)(iVar1 + 0x14) = iVar2;
      *(int *)(iVar1 + 0x18) = iStack_18;
      uStack_14 = 0;
    }
    else {
      uStack_14 = 0xffffffff;
    }
  }
  return uStack_14;
}



undefined4 FUN_060d7ca0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_10 [3];
  
  local_10[0] = 3;
  iVar1 = (*(code *)PTR_FUN_060d7cd8)(local_10,*(undefined4 *)(param_1 + 0x34));
  if (iVar1 == -0xd) {
    uVar2 = 0xffffffe9;
  }
  else if (iVar1 == 0) {
    iVar1 = *DAT_060d7cdc;
    *(undefined4 *)(iVar1 + 0x14) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x18) = 0xffffffff;
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



undefined4 FUN_060d7d14(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined local_10;
  
  local_20 = 1;
  uStack_18 = 3;
  local_10 = 0;
  uStack_1c = param_2;
  iVar1 = (*(code *)PTR_FUN_060d7d5c)(&local_20,*(undefined4 *)(param_1 + 0x34));
  if (iVar1 == -0xd) {
    uVar2 = 0xffffffe9;
  }
  else if (iVar1 == 0) {
    *(undefined4 *)(*DAT_060d7d60 + 0x14) = param_2;
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



undefined4 FUN_060d7d64(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  undefined local_14;
  
  piVar1 = DAT_060d7dc0;
  local_24 = 1;
  uStack_20 = *(undefined4 *)(*DAT_060d7dc0 + 0x14);
  uStack_1c = 1;
  iStack_18 = (param_2 - *(int *)(*DAT_060d7dc0 + 0x14)) + 1;
  local_14 = 0xff;
  iVar2 = (*(code *)PTR_FUN_060d7dc4)(&local_24,*(undefined4 *)(param_1 + 0x34));
  if (iVar2 == -0xd) {
    uVar3 = 0xffffffe9;
  }
  else if (iVar2 == 0) {
    *(int *)(*piVar1 + 0x18) = param_2;
    uVar3 = 0;
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}



bool FUN_060d7dc8(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 local_1c;
  byte local_18;
  byte local_17;
  undefined local_16;
  undefined local_15;
  
  iVar1 = (*(code *)PTR_FUN_060d7e3c)(param_1,DAT_060d7e38,0);
  if (param_2 < iVar1) {
    (*(code *)PTR_FUN_060d7e40)(*(undefined4 *)(param_1 + 0x20),param_2,&local_1c);
    *param_3 = local_1c;
    param_3[1] = (uint)local_18;
    param_3[2] = (uint)local_17;
    *(undefined *)(param_3 + 3) = local_16;
    *(undefined *)((int)param_3 + 0xd) = local_15;
  }
  return param_2 < iVar1;
}



undefined4 FUN_060d7ed4(int param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_14 [2];
  
  puVar1 = PTR_FUN_060d7f00;
  uVar3 = *(undefined4 *)(param_1 + 0x20);
  do {
    iVar2 = (*(code *)puVar1)(uVar3,local_14);
  } while (iVar2 != 0);
  return local_14[0];
}



undefined4 FUN_060d7f04(void)

{
  undefined *puVar1;
  int iVar2;
  undefined auStack_18 [4];
  undefined auStack_14 [4];
  undefined4 auStack_10 [2];
  
  puVar1 = PTR_FUN_060d7f30;
  do {
    iVar2 = (*(code *)puVar1)(auStack_18,auStack_14,auStack_10);
  } while (iVar2 != 0);
  return auStack_10[0];
}



void FUN_060d7f34(void)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  (*(code *)PTR_FUN_060d7f6c)(0xfffffffb);
  puVar1 = PTR_FUN_060d7f70;
  iVar3 = 0;
  iVar4 = (int)DAT_060d7f6a;
  do {
    uVar2 = (*(code *)puVar1)();
    iVar3 = iVar3 + 1;
    if ((uVar2 & 4) != 0) {
      return;
    }
  } while (iVar3 <= iVar4);
  return;
}



void FUN_060d7f90(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  (*(code *)PTR_FUN_060d8024)((int)DAT_060d8020);
  if (param_1 == 0) {
    (*(code *)PTR_FUN_060d8028)(0xfffffff5);
    (*(code *)PTR_FUN_060d802c)();
  }
  else {
    iVar1 = *(int *)(param_1 + 4);
    *(int *)(iVar1 + 0x18) = param_2;
    iVar2 = *(int *)(iVar1 + 0x10) + 0x6c;
    if (param_2 == 0) {
      (*(code *)PTR_FUN_060d8030)(iVar2,0,0,(int)DAT_060d8022);
      (*(code *)PTR_FUN_060d8034)(iVar2,3);
      (*(code *)PTR_FUN_060d8038)(*(undefined4 *)(iVar1 + 0x10),0,0);
      *(undefined4 *)(iVar1 + 0x1c) = 0;
    }
    else {
      (*(code *)PTR_FUN_060d8030)(iVar2,0,DAT_060d803c,(int)DAT_060d8022);
      (*(code *)PTR_FUN_060d8034)(iVar2,4);
      (*(code *)PTR_FUN_060d8038)(*(undefined4 *)(iVar1 + 0x10),PTR_LAB_060d8040,iVar1);
      *(undefined4 *)(iVar1 + 0x1c) = param_3;
    }
  }
  return;
}



undefined4 FUN_060d8044(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  (*(code *)PTR_FUN_060d80a0)((int)DAT_060d809c);
  if (param_1 == 0) {
    (*(code *)PTR_FUN_060d80a4)(0xfffffff5);
    (*(code *)PTR_FUN_060d80a8)();
    uVar1 = 0;
  }
  else {
    puVar2 = *(undefined4 **)(*(int *)(*(int *)(param_1 + 4) + 0x10) + 0x78);
    if (*(int *)(*(int *)(*(int *)(param_1 + 4) + 0x14) + 0x1c) == 0) {
      (*(code *)PTR_FUN_060d80ac)(puVar2);
    }
    *param_2 = puVar2[1];
    uVar1 = *puVar2;
  }
  return uVar1;
}



void FUN_060d81cc(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10 [2];
  
  piVar2 = (int *)(*(int *)(param_1 + 0x10) + 0x6c);
  uVar1 = (*(code *)PTR_FUN_060d8218)(piVar2);
  (*(code *)PTR_FUN_060d821c)(piVar2,uVar1);
  if (*piVar2 != 0) {
    (*(code *)PTR_FUN_060d8220)(piVar2,&local_18,&local_14,local_10);
    (*(code *)PTR_FUN_060d8224)(piVar2,local_18,local_14,local_10[0]);
  }
  return;
}



bool FUN_060d82bc(int param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_FUN_060d82dc)(*(int *)(param_1 + 0x10) + 0x6c);
  return iVar1 == 0;
}



undefined4 FUN_060d832c(void)

{
  *DAT_060d8348 = 0;
  (*(code *)PTR_FUN_060d834c)();
  return 1;
}



void FUN_060d84ec(int *param_1)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  puVar1 = PTR_FUN_060d8540;
  if (param_1 == (int *)0x0) {
    iVar3 = 0;
    iVar4 = (int)DAT_060d853e;
    do {
      piVar2 = (int *)(*(code *)puVar1)(iVar3);
      iVar3 = iVar3 + 1;
      if (piVar2 != (int *)0x0) {
        (**(code **)(iVar4 + *piVar2))(piVar2);
      }
    } while (iVar3 < 0x20);
  }
  else {
    (**(code **)((int)DAT_060d853e + *param_1))(param_1);
  }
  return;
}



void FUN_060d8544(void)

{
  (*(code *)PTR_FUN_060d8558)();
  return;
}



void FUN_060d855c(int *param_1)

{
  code *pcVar1;
  
  if (param_1 == (int *)0x0) {
    param_1 = (int *)(int)DAT_060d8580;
    pcVar1 = (code *)PTR_FUN_060d8584;
  }
  else {
    pcVar1 = *(code **)(*param_1 + (int)DAT_060d8582);
  }
  (*pcVar1)(param_1);
  return;
}



void FUN_060d8588(int param_1)

{
  code *pcVar1;
  
  pcVar1 = (code *)PTR_FUN_060d85b0;
  if (param_1 == 0) {
    param_1 = (int)DAT_060d85a8;
    pcVar1 = (code *)PTR_FUN_060d85ac;
  }
  (*pcVar1)(param_1);
  return;
}



void FUN_060d85b4(int param_1)

{
  if (param_1 == 0) {
    (*(code *)PTR_FUN_060d85dc)((int)DAT_060d85d8);
  }
  else {
    (*(code *)PTR_FUN_060d85e0)();
  }
  return;
}



void FUN_060d865c(int param_1)

{
  if (param_1 == 0) {
    (*(code *)PTR_FUN_060d8684)((int)DAT_060d8680);
  }
  else {
    (*(code *)PTR_FUN_060d8688)();
  }
  return;
}



void FUN_060d8760(int param_1,uint param_2)

{
  short sVar1;
  int iVar2;
  
  sVar1 = DAT_060d8798;
  if ((param_1 == 0) || (sVar1 = DAT_060d879a, 7 < param_2)) {
    (*(code *)PTR_FUN_060d879c)((int)sVar1);
  }
  else {
    iVar2 = (*(code *)PTR_FUN_060d87a0)();
    *(uint *)(iVar2 + 0x14) = param_2;
  }
  return;
}



void FUN_060d87d4(int param_1)

{
  if (param_1 == 0) {
    (*(code *)PTR_FUN_060d87fc)((int)DAT_060d87f8);
  }
  else {
    (*(code *)PTR_FUN_060d8800)();
  }
  return;
}



void FUN_060d8860(void)

{
  (*(code *)PTR_FUN_060d8874)();
  return;
}



void FUN_060d8890(void)

{
  (*(code *)PTR_FUN_060d88a4)();
  return;
}



void FUN_060d8954(int *param_1,int param_2)

{
  short sVar1;
  
  sVar1 = DAT_060d8986;
  if ((param_1 == (int *)0x0) || (sVar1 = DAT_060d8988, param_2 < 1)) {
    (*(code *)PTR_FUN_060d898c)((int)sVar1);
  }
  else {
    (**(code **)(*param_1 + (int)DAT_060d898a))();
  }
  return;
}



undefined4 FUN_060d8990(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    (*(code *)PTR_FUN_060d89bc)((int)DAT_060d89b6);
    uVar2 = 0xffffffff;
  }
  else {
    iVar1 = (*(code *)PTR_FUN_060d89b8)();
    uVar2 = *(undefined4 *)(iVar1 + 4);
  }
  return uVar2;
}



void FUN_060d89d8(void)

{
  (*(code *)PTR_FUN_060d89ec)();
  return;
}



void FUN_060d8abc(int *param_1)

{
  if (param_1 == (int *)0x0) {
    (*(code *)PTR_FUN_060d8ae8)((int)DAT_060d8ae4);
  }
  else {
    (**(code **)(*param_1 + (int)DAT_060d8ae6))();
  }
  return;
}



undefined4 FUN_060d8af8(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    (*(code *)PTR_FUN_060d8b3c)((int)DAT_060d8b38);
  }
  else {
    iVar1 = (*(code *)PTR_FUN_060d8b40)(param_1);
    if (iVar1 == 0) {
      return 1;
    }
    iVar1 = (*(code *)PTR_FUN_060d8b44)(param_1);
    if ((iVar1 != -1) && (iVar1 != 5)) {
      return 0;
    }
  }
  return 1;
}



void FUN_060d8b48(void)

{
  *DAT_060d8b60 = 0;
  *DAT_060d8b64 = 0;
  *DAT_060d8b68 = 0;
  return;
}



int * FUN_060d8b6c(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = DAT_060d8cc4;
  if (*DAT_060d8cc4 == 0) {
    (*(code *)PTR_FUN_060d8cc8)();
    *piVar1 = 1;
  }
  if ((((param_2 == 0) || (param_1 == (int *)0x0)) || (*param_1 == 0)) ||
     (((param_1[1] == 0 || (param_1[2] < 1)) || ((param_1[3] == 0 || (param_1[4] < 1)))))) {
    (*(code *)PTR_FUN_060d8ccc)((int)DAT_060d8c9e);
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(*(code *)PTR_FUN_060d8cd0)(param_2);
    if (piVar1 != (int *)0x0) {
      *(undefined4 *)((int)DAT_060d8ca0 + *piVar1) = 2;
      *(undefined **)((int)DAT_060d8ca2 + *piVar1) = PTR_LAB_060d8cd4;
      *(undefined **)((int)DAT_060d8ca4 + *piVar1) = PTR_LAB_060d8cd8;
      *(undefined **)((int)DAT_060d8ca6 + *piVar1) = PTR_LAB_060d8cdc;
      *(undefined **)((int)DAT_060d8ca8 + *piVar1) = PTR_LAB_060d8ce0;
      *(undefined **)((int)DAT_060d8caa + *piVar1) = PTR_LAB_060d8ce4;
      *(undefined4 *)((int)DAT_060d8cac + *piVar1) = 0xffffffff;
      *(undefined4 *)((int)DAT_060d8cae + *piVar1) = 0;
      *(undefined4 *)((int)DAT_060d8cb0 + *piVar1) = 0;
      *(undefined4 *)((int)DAT_060d8cb2 + *piVar1) = 0;
      *(undefined4 *)((int)DAT_060d8cb4 + *piVar1) = 0;
      *(undefined4 *)((int)DAT_060d8cb6 + *piVar1) = 0;
      *(undefined4 *)((int)DAT_060d8cb8 + *piVar1) = 0x800;
      *(undefined4 *)((int)DAT_060d8cba + *piVar1) = 0;
      iVar2 = (int)DAT_060d8cbc;
      *(undefined **)(iVar2 + *piVar1) = PTR_LAB_060d8ce8;
      iVar3 = (int)DAT_060d8cbe;
      *(int *)(iVar3 + *piVar1) = param_2;
      (*(code *)PTR_FUN_060d8cec)
                (*(undefined4 *)(iVar3 + *piVar1),*(undefined4 *)(iVar2 + *piVar1),piVar1);
      iVar2 = (int)DAT_060d8cc0;
      *(undefined4 *)(iVar2 + *piVar1) = 0x14;
      (*(code *)PTR_FUN_060d8cf0)(*(undefined4 *)(iVar3 + *piVar1),*(undefined4 *)(iVar2 + *piVar1))
      ;
    }
  }
  return piVar1;
}



void FUN_060d8cf4(int *param_1)

{
  code *pcVar1;
  
  if (param_1 == (int *)0x0) {
    param_1 = (int *)(int)DAT_060d8d42;
    pcVar1 = (code *)PTR_FUN_060d8d4c;
  }
  else {
    if (*(int *)(*param_1 + (int)DAT_060d8d44) != 2) {
      (*(code *)PTR_FUN_060d8d4c)((int)DAT_060d8d46);
    }
    (*(code *)PTR_FUN_060d8d50)(param_1);
    (*(code *)PTR_FUN_060d8d58)(*(undefined4 *)(*param_1 + (int)DAT_060d8d48),PTR_LAB_060d8d54,0);
    pcVar1 = (code *)PTR_FUN_060d8d5c;
  }
  (*pcVar1)(param_1);
  return;
}



void FUN_060d8d60(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  uStack_14 = 0;
  uStack_10 = 0x1000;
  uStack_c = 0x800;
  uStack_24 = 1;
  uStack_20 = 1;
  uStack_2c = param_5;
  uStack_28 = param_6;
  uStack_1c = 0;
  uStack_18 = 7;
  local_34 = param_3;
  uStack_30 = param_4;
  (*(code *)PTR_FUN_060d8da4)(param_2,&local_34);
  return;
}



void FUN_060d8de8(int *param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined auStack_28 [12];
  byte local_1c;
  undefined local_1b;
  
  iVar2 = (*(code *)PTR_FUN_060d8e58)();
  puVar1 = PTR_FUN_060d8e5c;
  if (iVar2 != 0) {
    iVar2 = (int)DAT_060d8e52;
    iVar5 = (int)DAT_060d8e54;
    while (iVar3 = (*(code *)puVar1)(*(undefined4 *)(iVar5 + *param_1),
                                     *(undefined4 *)(iVar2 + *param_1),auStack_28), iVar3 == 1) {
      if ((local_1c & 0x40) != 0) {
        (*(code *)PTR_FUN_060d8e60)(param_1,local_1b);
        return;
      }
      piVar4 = (int *)(*param_1 + iVar2);
      *piVar4 = *piVar4 + 1;
    }
  }
  return;
}



void FUN_060d8f30(int *param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined *puVar5;
  
  puVar2 = PTR_FUN_060d8fa0;
  puVar1 = PTR_FUN_060d8f94;
  if (*(int *)(*param_1 + (int)DAT_060d8f8c) != 1) {
    return;
  }
  puVar5 = *(undefined **)(*param_1 + (int)DAT_060d8f8e);
  if (puVar5 == PTR_LAB_060d8f90) {
    do {
      iVar3 = (*(code *)puVar1)();
      puVar4 = DAT_060d8f98;
    } while (iVar3 == 2);
  }
  else {
    if (puVar5 != PTR_LAB_060d8f9c) goto LAB_060d8f78;
    do {
      iVar3 = (*(code *)puVar2)();
      puVar4 = DAT_060d8fa4;
    } while (iVar3 == 2);
  }
  *puVar4 = 0;
LAB_060d8f78:
  *(undefined4 *)(*param_1 + (int)DAT_060d8f8c) = 0;
  return;
}



void FUN_060d90c0(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 local_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  int iStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  int iStack_1c;
  
  (*(code *)PTR_FUN_060d913c)(1);
  local_4c = 0;
  uStack_48 = 1;
  uStack_44 = 0xf;
  (*(code *)PTR_FUN_060d9140)(&local_4c);
  uStack_34 = 1;
  uStack_30 = 0;
  uStack_2c = 0x800;
  uStack_28 = 0x200;
  uStack_24 = 0;
  iStack_1c = (int)DAT_060d913a;
  local_40 = param_2;
  uStack_3c = param_1;
  iStack_38 = param_3;
  (*(code *)PTR_FUN_060d9144)(&local_40,1);
  (*(code *)PTR_FUN_060d9148)(1);
  *DAT_060d914c = param_1;
  *DAT_060d9150 = param_3 << 2;
  return;
}



undefined FUN_060d9154(void)

{
  int iVar1;
  undefined uVar2;
  int local_10 [3];
  
  (*(code *)PTR_FUN_060d9190)(local_10);
  uVar2 = local_10[0] == 4;
  if (!(bool)uVar2) {
    iVar1 = (*(code *)PTR_FUN_060d9194)(1);
    uVar2 = 2;
    if (iVar1 != 0) {
      (*(code *)PTR_FUN_060d91a0)(*DAT_060d919c,*DAT_060d9198);
      uVar2 = 0;
    }
  }
  return uVar2;
}



void FUN_060d92ac(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  *DAT_060d9320 = param_1;
  *DAT_060d9324 = param_3;
  uStack_2c = 0;
  uStack_28 = 2;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 7;
  uStack_14 = 3;
  local_38 = param_2;
  uStack_34 = param_1;
  uStack_30 = param_3;
  (*(code *)PTR_FUN_060d9328)(&local_38,0);
  (*(code *)PTR_FUN_060d932c)(0);
  *DAT_060d9330 = 1;
  return;
}



undefined8 FUN_060d9334(void)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint in_sr;
  uint uVar4;
  int local_14 [2];
  
  uVar3 = (in_sr & 0xf0) >> 4;
  uVar2 = (uint)DAT_060d93a8;
  uVar4 = in_sr & 0xfff0ffe | 0xf0 | (uint)(*DAT_060d93ac == '\x01');
  if ((*DAT_060d93ac == '\x01') != 0) {
    (*(code *)PTR_FUN_060d93b0)(local_14,0);
    uVar4 = uVar4 & 0xfffffffe | (uint)(local_14[0] == 1);
    if ((local_14[0] == 1) != 0) {
      uVar2 = uVar4 & uVar2 | uVar3 << 4;
      uVar1 = 2;
      goto LAB_060d939a;
    }
    (*(code *)PTR_FUN_060d93bc)(*DAT_060d93b8,*DAT_060d93b4);
  }
  uVar2 = uVar4 & uVar2 | uVar3 << 4;
  uVar1 = 0;
LAB_060d939a:
  return CONCAT44(uVar2,uVar1);
}



void FUN_060d95bc(void)

{
  *DAT_060d95d4 = 0;
  *DAT_060d95d8 = 0;
  *DAT_060d95dc = 0;
  return;
}



void FUN_060d95e0(undefined4 param_1)

{
  *DAT_060d9604 = param_1;
  if ((code *)*DAT_060d9608 != (code *)0x0) {
    (*(code *)*DAT_060d9608)(*DAT_060d960c);
  }
  return;
}



void FUN_060d9620(undefined4 param_1,undefined4 param_2)

{
  *DAT_060d9630 = param_1;
  *DAT_060d9634 = param_2;
  return;
}



void FUN_060d9638(void)

{
  return;
}



void FUN_060d9644(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int extraout_r3;
  int *piVar3;
  ulonglong uVar4;
  
  iVar1 = *param_1;
  iVar2 = iVar1 + 0x30;
  piVar3 = (int *)(iVar2 + DAT_060d968e);
  *piVar3 = param_2;
  if (8 < *(int *)(iVar1 + 0x58)) {
    param_2 = param_2 * 2;
  }
  *(int *)(iVar2 + DAT_060d9690) = param_2;
  iVar1 = *piVar3 + (int)DAT_060d9692;
  iVar1 = (int)((ulonglong)((longlong)iVar1 * (longlong)DAT_060d9698) >> 0x20) + iVar1;
  uVar4 = (*(code *)PTR_FUN_060d969c)();
  *(uint *)(extraout_r3 + (int)uVar4) = iVar1 + (uint)((uVar4 & 0x8000000000000000) != 0);
  return;
}



void FUN_060d96c4(uint param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = param_1 + 3 & 0xfffffffc;
  *DAT_060d970c = uVar1;
  if (uVar1 != param_1) {
    param_2 = param_2 - 4;
  }
  *DAT_060d9710 = param_2 & 0xfffffffc;
  if ((*DAT_060d970c == 0) || (*DAT_060d9710 == 0)) {
    (*(code *)PTR_FUN_060d9714)((int)DAT_060d970a);
  }
  return;
}



void FUN_060d9734(void)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  
  *DAT_060d97b0 = 0;
  *DAT_060d97b4 = 0;
  *DAT_060d97b8 = 0;
  *DAT_060d97bc = 0;
  *DAT_060d97c0 = 0;
  *DAT_060d97c4 = 0;
  (*(code *)PTR_FUN_060d97c8)();
  (*(code *)PTR_FUN_060d97cc)();
  (*(code *)PTR_FUN_060d97d0)();
  (*(code *)PTR_FUN_060d97dc)(DAT_060d97d8,PTR_s_PCM_Version_1_16_1995_03_31_060d97d4,0x20);
  uVar1 = 0;
  uVar3 = 0;
  puVar2 = DAT_060d97e0;
  do {
    *puVar2 = uVar1 << 0x10 | uVar3 | uVar1 << 8 | uVar1;
    puVar2 = puVar2 + 1;
    uVar1 = uVar1 + 1;
    uVar3 = uVar3 + DAT_060d97e4;
  } while ((int)uVar1 < 0x20);
  *DAT_060d97e8 = DAT_060d97ec;
  *DAT_060d97f0 = PTR_LAB_060d97f4;
  *DAT_060d97f8 = PTR_LAB_060d97fc;
  return;
}



void FUN_060d9864(void)

{
  undefined *puVar1;
  
  puVar1 = PTR_FUN_060d98c4;
  if (*DAT_060d98b8 == DAT_060d98bc) {
    *DAT_060d98c0 = *DAT_060d98c0 + 1;
    (*(code *)puVar1)();
    (*(code *)PTR_FUN_060d98c8)();
  }
  return;
}



void FUN_060d98cc(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *param_1;
  iVar1 = (int)DAT_060d992a;
  iVar3 = iVar2 + 0x30;
  *(undefined4 *)(iVar2 + 0x34) = 0;
  *(undefined4 *)(iVar2 + 0x6c) = 0;
  *(undefined4 *)(iVar2 + 0x70) = 0;
  *(undefined4 *)(iVar2 + 0x78) = *(undefined4 *)(iVar2 + 4);
  *(undefined4 *)(iVar2 + 0x7c) = *(undefined4 *)(iVar2 + 4);
  *(undefined4 *)(iVar2 + 0x90) = 0;
  *(undefined4 *)(iVar2 + 0x94) = 0;
  *(undefined4 *)(iVar3 + iVar1) = 0;
  *(undefined4 *)(iVar3 + DAT_060d992c) = 0;
  *(undefined4 *)(iVar2 + 0x98) = 0;
  *(undefined4 *)(iVar2 + 0x9c) = 0;
  *(undefined4 *)(iVar2 + 0xa0) = 0;
  *(undefined4 *)(iVar2 + 0xa4) = 0;
  *(undefined4 *)(iVar3 + DAT_060d992e) = 0;
  return;
}



void FUN_060d9930(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = (int)DAT_060d996e;
  param_1 = (undefined4 *)*param_1;
  puVar2 = param_1 + 0xc;
  *param_1 = DAT_060d9978;
  *puVar2 = DAT_060d997c;
  param_1[0x11] = DAT_060d9980;
  param_1[0x1a] = DAT_060d9984;
  param_1[0x21] = DAT_060d9988;
  *(undefined4 *)((int)puVar2 + iVar1) = DAT_060d998c;
  *(undefined4 *)((int)puVar2 + (int)DAT_060d9970) = DAT_060d9990;
  *(undefined4 *)((int)puVar2 + (int)DAT_060d9972) = DAT_060d9994;
  *(undefined4 *)((int)puVar2 + (int)DAT_060d9974) = DAT_060d9998;
  return;
}



int * FUN_060d999c(int param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint extraout_r3;
  int iVar4;
  undefined *puVar5;
  int iVar6;
  int *piVar7;
  
  iVar6 = param_1 + 0x30;
  if (*DAT_060d9b44 == DAT_060d9b48) {
    uVar1 = 0;
    puVar3 = (uint *)PTR_DAT_060d9b50;
    do {
      if ((*puVar3 & *DAT_060d9b4c) == 0) break;
      uVar1 = uVar1 + 1;
      puVar3 = puVar3 + 1;
    } while (uVar1 < 0x20);
    if (uVar1 == 0x20) {
      iVar6 = (int)DAT_060d9b24;
    }
    else {
      uVar1 = param_2[3];
      if (((int)DAT_060d9b26 & uVar1) == 0) {
        puVar3 = DAT_060d9b4c;
        puVar5 = PTR_DAT_060d9b50;
        iVar2 = (*(code *)PTR_FUN_060d9b54)();
        if (uVar1 < 2) {
          iVar6 = (int)DAT_060d9b28;
          goto LAB_060d9b06;
        }
        if (uVar1 < 0x11) {
          *puVar3 = *(uint *)(puVar5 + iVar2 * 4) | extraout_r3;
          piVar7 = (int *)(iVar2 * 4 + DAT_060d9b58);
          *piVar7 = param_1;
          (*(code *)PTR_FUN_060d9b5c)(param_1,0,(int)DAT_060d9b2a);
          *(int *)(param_1 + 4) = *param_2;
          *(int *)(param_1 + 8) = param_2[1];
          *(int *)(param_1 + 0xc) = param_2[2];
          *(int *)(param_1 + 0x10) = param_2[3];
          *(int *)(param_1 + 0x14) = param_2[4];
          *(int *)(param_1 + 0x18) = param_2[5];
          *(int *)(param_1 + 0x1c) = param_2[6];
          *(int *)(param_1 + 0x20) = param_2[7];
          *(int *)(param_1 + 0x24) = param_2[8];
          *(int *)(param_1 + 0x28) = param_2[9];
          *(int *)(param_1 + 0x2c) = param_2[10];
          (*(code *)PTR_FUN_060d9b60)(piVar7);
          *(undefined4 *)(param_1 + 0x34) = 0;
          *(undefined4 *)(param_1 + 0x38) = 0;
          *(undefined4 *)(param_1 + 0x3c) = 0;
          *(undefined4 *)(param_1 + 0x40) = 1;
          *(undefined4 *)(param_1 + 0x48) = 2;
          *(undefined4 *)(param_1 + 0x4c) = 1;
          *(undefined4 *)(param_1 + 0x6c) = 0;
          *(undefined4 *)(param_1 + 0x70) = 0;
          *(int *)(param_1 + 0x78) = *param_2;
          iVar2 = (int)DAT_060d9b2c;
          *(int *)(param_1 + 0x7c) = *param_2;
          iVar4 = (int)DAT_060d9b2e;
          *(int *)(param_1 + 0x74) = *param_2 + param_2[1];
          *(undefined4 *)(param_1 + 0x90) = 0;
          *(undefined4 *)(param_1 + 0x94) = 0;
          *(undefined4 *)(iVar6 + iVar2) = 0;
          *(undefined4 *)(iVar6 + DAT_060d9b30) = 0;
          *(undefined4 *)(param_1 + 0x98) = 0;
          *(undefined4 *)(param_1 + 0x9c) = 0;
          *(undefined4 *)(param_1 + 0xa0) = 0;
          *(undefined4 *)(param_1 + 0xa4) = 0;
          *(undefined4 *)(iVar6 + DAT_060d9b32) = 0;
          *(undefined4 *)(iVar6 + DAT_060d9b34) = 0;
          *(undefined4 *)(iVar6 + DAT_060d9b36) = 0;
          *(undefined4 *)(iVar6 + DAT_060d9b38) = 0;
          *(undefined4 *)(iVar6 + DAT_060d9b3a) = 0;
          *(undefined4 *)(iVar6 + DAT_060d9b3c) = 0;
          *(undefined **)(iVar6 + DAT_060d9b3e) = PTR_LAB_060d9b64;
          (*(code *)PTR_FUN_060d9b68)(piVar7,iVar4);
          return piVar7;
        }
      }
      iVar6 = (int)DAT_060d9b40;
    }
  }
  else {
    iVar6 = (int)DAT_060d9b22;
  }
LAB_060d9b06:
  (*(code *)PTR_FUN_060d9b6c)(iVar6);
  return (int *)0x0;
}



undefined4 FUN_060d9b70(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = param_1 - DAT_060d9ba0 >> 2;
  if ((0x1f < uVar2) || (uVar1 = 1, (*DAT_060d9ba4 & *(uint *)(PTR_DAT_060d9ba8 + uVar2 * 4)) == 0))
  {
    uVar1 = 0;
  }
  return uVar1;
}



void FUN_060d9bac(int param_1)

{
  short sVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  
  puVar2 = DAT_060d9c2c;
  sVar1 = DAT_060d9c1c;
  if ((*DAT_060d9c24 == DAT_060d9c28) &&
     (puVar4 = (uint *)(PTR_DAT_060d9c30 + (param_1 - DAT_060d9c20 >> 2) * 4), sVar1 = DAT_060d9c1e,
     (*DAT_060d9c2c & *puVar4) != 0)) {
    (*(code *)PTR_FUN_060d9c38)();
    uVar3 = ~*puVar4 & *puVar2;
    *puVar2 = uVar3;
    if (uVar3 == 0) {
      *DAT_060d9c3c = 0;
    }
  }
  else {
    (*(code *)PTR_FUN_060d9c34)((int)sVar1);
  }
  return;
}



undefined4 FUN_060d9cec(int *param_1)

{
  return *(undefined4 *)(*param_1 + 8);
}



void FUN_060d9cfc(int *param_1,undefined4 *param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  iVar1 = (*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0x70)) - *(int *)(iVar2 + 0x6c);
  *param_4 = iVar1;
  if (iVar1 < 1) {
    *param_3 = 0;
    *param_2 = 0;
  }
  else {
    if (*(uint *)(iVar2 + 0x78) < *(uint *)(iVar2 + 0x7c)) {
      *param_3 = iVar1;
    }
    else {
      *param_3 = *(int *)(iVar2 + 0x74) - *(uint *)(iVar2 + 0x78);
    }
    *param_2 = *(undefined4 *)(iVar2 + 0x78);
  }
  return;
}



void FUN_060d9d54(int *param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *param_1;
  if (0 < param_2) {
    *(int *)(iVar2 + 0x6c) = *(int *)(iVar2 + 0x6c) + param_2;
    puVar1 = (uint *)(iVar2 + 0x78);
    uVar3 = param_2 + *puVar1;
    *puVar1 = uVar3;
    if (*(uint *)(iVar2 + 0x74) <= uVar3) {
      *puVar1 = uVar3 - *(int *)(iVar2 + 8);
    }
  }
  return;
}



void FUN_060d9d90(int *param_1,int param_2)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  
  iVar1 = *param_1;
  *(int *)(iVar1 + 0x70) = *(int *)(iVar1 + 0x70) + param_2;
  puVar2 = (uint *)(iVar1 + 0x7c);
  uVar3 = param_2 + *puVar2;
  *puVar2 = uVar3;
  if (*(uint *)(iVar1 + 0x74) <= uVar3) {
    *puVar2 = uVar3 - *(int *)(iVar1 + 8);
  }
  return;
}



int FUN_060d9dfc(int *param_1)

{
  return *param_1 + 4;
}



int FUN_060d9e0c(int *param_1)

{
  return *param_1 + 0x30;
}



void FUN_060d9e1c(int *param_1)

{
  *(undefined4 *)(*param_1 + 0x34) = 2;
  return;
}



void FUN_060d9e2c(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x34) == 4) {
    (*(code *)PTR_FUN_060d9e5c)();
  }
  *(undefined4 *)(iVar1 + 0x34) = 5;
  *(undefined4 *)(iVar1 + 0x40) = 0;
  return;
}



void FUN_060d9e60(int *param_1)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  
  iVar4 = *param_1;
  sVar1 = DAT_060d9f7c;
  if ((*DAT_060d9f84 == 0) || (sVar1 = DAT_060d9f7e, *DAT_060d9f88 == 0)) {
    (*(code *)PTR_FUN_060d9f8c)((int)sVar1);
  }
  else {
    *(undefined4 *)(iVar4 + 0x30 + (int)DAT_060d9f80) = *DAT_060d9f90;
    (*(code *)PTR_FUN_060d9f94)(param_1);
    iVar3 = (*(code *)PTR_FUN_060d9f98)(param_1);
    iVar3 = iVar3 + *(int *)(iVar4 + 0xa4);
    *(int *)(iVar4 + 0xa4) = iVar3;
    iVar3 = *(int *)(iVar4 + 0x9c) - iVar3;
    if (*(int *)(iVar4 + 0x58) < 9) {
      iVar3 = -iVar3;
    }
    else {
      iVar3 = iVar3 * -2;
    }
    iVar7 = *(int *)(iVar4 + 0x8c);
    iVar6 = *(int *)(iVar4 + 0x90) + iVar3 + iVar7 * 0x100;
    iVar3 = (*(code *)PTR_FUN_060d9f9c)(iVar6,iVar7);
    piVar2 = DAT_060d9f88;
    piVar5 = DAT_060d9f84;
    iVar6 = iVar6 - iVar3 * iVar7;
    if (*(int *)(iVar4 + 0x54) == 1) {
      (*(code *)PTR_FUN_060d9fa0)
                (*DAT_060d9f84,*DAT_060d9f88,*(undefined4 *)(iVar4 + 0xc),iVar7,iVar6);
    }
    else {
      (*(code *)PTR_FUN_060d9fa0)
                (*DAT_060d9f84,*DAT_060d9f88,*(undefined4 *)(iVar4 + 0xc),iVar7,iVar6);
      (*(code *)PTR_FUN_060d9fa0)
                (*piVar5,*piVar2,*(undefined4 *)(iVar4 + 0x88),*(int *)(iVar4 + 0x8c),iVar6);
    }
    piVar5 = (int *)(iVar4 + 0x90);
    iVar6 = *piVar5 - iVar6;
    *piVar5 = iVar6;
    if (iVar6 < 0) {
      *piVar5 = *(int *)(iVar4 + 0x8c) + iVar6;
    }
    *(undefined4 *)(iVar4 + 0x34) = 1;
  }
  return;
}



void FUN_060d9fa4(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_1;
  iVar3 = iVar1 + 0x30;
  if ((*DAT_060da054 & 1) == 0) {
    iVar2 = (int)DAT_060da048;
    if (*DAT_060da058 == 0) {
      iVar2 = (int)DAT_060da04a;
    }
  }
  else {
    iVar2 = (int)DAT_060da044;
    if (*DAT_060da058 == 0) {
      *(int *)(iVar1 + 0xac) = (int)DAT_060da046;
      goto LAB_060d9ff4;
    }
  }
  *(int *)(iVar1 + 0xac) = iVar2;
LAB_060d9ff4:
  (*(code *)PTR_FUN_060da05c)(param_1);
  (*(code *)PTR_FUN_060da060)(param_1);
  *(undefined4 *)(iVar1 + 0x34) = 4;
  *(undefined4 *)(iVar1 + 0x94) = 0;
  iVar1 = *DAT_060da064;
  *(int *)(iVar3 + DAT_060da04c) = iVar1;
  *(int *)(iVar3 + DAT_060da04e) =
       (iVar1 - *(int *)(iVar3 + DAT_060da050)) + *(int *)(iVar3 + DAT_060da04e);
  return;
}



void FUN_060da068(int *param_1,int param_2)

{
  code *pcVar1;
  
  if (*(int *)(*param_1 + 0x34) == 1) {
    pcVar1 = (code *)PTR_FUN_060da0a0;
    if (param_2 != 1) {
      return;
    }
  }
  else {
    if (*(int *)(*param_1 + 0x34) != 4) {
      return;
    }
    pcVar1 = (code *)PTR_FUN_060da09c;
    if (param_2 != 0) {
      return;
    }
  }
  (*pcVar1)();
  return;
}



undefined4 FUN_060da0ac(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (*(int *)(iVar2 + 0x48) == 1) {
    if (*(int *)(iVar2 + 0x3c) != 0) {
      return 0xffffffff;
    }
    *(undefined4 *)(iVar2 + 0x34) = 3;
  }
  else {
    if (*(int *)(iVar2 + 0x6c) < 4) {
      return 0xffffffff;
    }
    if (**(int **)(iVar2 + 4) != *(int *)PTR_DAT_060da164) {
      (*(code *)PTR_FUN_060da16c)((int)DAT_060da15e);
      return 0xffffffff;
    }
    iVar1 = (*(code *)PTR_FUN_060da168)(param_1);
    if (iVar1 != 0) {
      return 0xffffffff;
    }
    iVar1 = *(int *)(iVar2 + 0x10);
    if (8 < *(int *)(iVar2 + 0x58)) {
      iVar1 = iVar1 * 2;
    }
    *(int *)(iVar2 + 0x8c) = iVar1;
    *(int *)(iVar2 + 0x88) = *(int *)(iVar2 + 0xc) + iVar1;
    (*(code *)PTR_FUN_060da170)(param_1,*(undefined4 *)(iVar2 + 0x80));
    iVar1 = *(int *)(iVar2 + 0x30 + (int)DAT_060da162);
    if (8 < *(int *)(iVar2 + 0x58)) {
      iVar1 = iVar1 * 2;
    }
    *(int *)(iVar2 + 0x30 + (int)DAT_060da160) = iVar1;
    *(undefined4 *)(iVar2 + 0x34) = 3;
  }
  return 0;
}



void FUN_060da174(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *param_1;
  if (*(int *)(iVar3 + 0x6c) < *(int *)(iVar3 + 0x24)) {
    return;
  }
  if (*(int *)(iVar3 + 0x9c) < *(int *)(iVar3 + 0x28)) {
    return;
  }
  if ((*DAT_060da22c & 1) == 0) {
    iVar1 = (int)DAT_060da220;
    if (*DAT_060da230 == 0) {
      iVar1 = (int)DAT_060da222;
    }
  }
  else {
    iVar1 = (int)DAT_060da21c;
    if (*DAT_060da230 == 0) {
      *(int *)(iVar3 + 0xac) = (int)DAT_060da21e;
      goto LAB_060da1d8;
    }
  }
  *(int *)(iVar3 + 0xac) = iVar1;
LAB_060da1d8:
  (*(code *)PTR_FUN_060da234)(param_1);
  (*(code *)PTR_FUN_060da238)(param_1);
  *(undefined4 *)(iVar3 + 0x34) = 4;
  *(undefined4 *)(iVar3 + 0x94) = 0;
  iVar1 = (int)DAT_060da224;
  uVar2 = *DAT_060da23c;
  *(undefined4 *)((int)DAT_060da226 + iVar3 + 0x30) = uVar2;
  *(undefined4 *)(iVar1 + iVar3 + 0x30) = uVar2;
  return;
}



bool FUN_060da240(int *param_1)

{
  return *(int *)(*param_1 + 0x3c) == 1;
}



void FUN_060da258(int *param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *param_1;
  bVar1 = (param_2 & 1) == 0;
  if (bVar1) {
    uVar3 = (uint)bVar1;
  }
  else {
    uVar3 = 2;
  }
  *(uint *)(iVar2 + 0x54) = uVar3;
  if ((param_2 & 4) == 0) {
    *(undefined4 *)(iVar2 + 0x5c) = DAT_060da298;
  }
  else {
    *(int *)(iVar2 + 0x5c) = (int)DAT_060da294;
  }
  *(undefined4 *)(iVar2 + 0x3c) = 0;
  return;
}



void FUN_060da2a8(int *param_1,undefined4 param_2)

{
  *(undefined4 *)(*param_1 + 0x20) = param_2;
  return;
}



undefined4 FUN_060da2d8(int *param_1,int *param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *param_1;
  iVar4 = *param_2;
  sVar1 = DAT_060da3ce;
  if (*(int *)(iVar4 + 0x34) == 0) {
    (*(code *)PTR_FUN_060da3d8)(param_2);
    iVar2 = (*(code *)PTR_FUN_060da3dc)(param_2);
    if (iVar2 != 0) {
      return 0xffffffff;
    }
    sVar1 = DAT_060da3d0;
    if ((((*(int *)(iVar3 + 0x18) == *(int *)(iVar4 + 0x18)) &&
         (*(int *)(iVar3 + 0xc) == *(int *)(iVar4 + 0xc))) &&
        (*(int *)(iVar3 + 0x10) == *(int *)(iVar4 + 0x10))) &&
       (((*(int *)(iVar3 + 0x54) == *(int *)(iVar4 + 0x54) &&
         (*(int *)(iVar3 + 0x58) == *(int *)(iVar4 + 0x58))) &&
        (*(int *)(iVar3 + 0x5c) == *(int *)(iVar4 + 0x5c))))) {
      *(undefined4 *)(iVar4 + 0x1c) = *(undefined4 *)(iVar3 + 0x1c);
      *(undefined4 *)(iVar4 + 0x20) = *(undefined4 *)(iVar3 + 0x20);
      *(undefined4 *)(iVar4 + 0x90) = *(undefined4 *)(iVar3 + 0x90);
      *(undefined4 *)(iVar4 + 0x9c) = *(undefined4 *)(iVar3 + 0x9c);
      iVar2 = (int)DAT_060da3d2;
      *(undefined4 *)(iVar4 + 0xa4) = *(undefined4 *)(iVar3 + 0xa4);
      *(undefined4 *)(iVar4 + 0xa0) = *(undefined4 *)(iVar4 + 0x9c);
      *(undefined4 *)(iVar4 + 0x30 + iVar2) = *DAT_060da3e4;
      *(undefined4 *)(iVar4 + 0x30 + (int)DAT_060da3d4) =
           *(undefined4 *)(iVar3 + 0x30 + (int)DAT_060da3d4);
      *(undefined4 *)(iVar4 + 0x94) = *(undefined4 *)(iVar3 + 0x94);
      *(undefined4 *)(iVar4 + 0xa8) = *(undefined4 *)(iVar3 + 0xa8);
      *(undefined4 *)(iVar4 + 0xac) = *(undefined4 *)(iVar3 + 0xac);
      *(undefined4 *)(iVar4 + 0x34) = 4;
      return 0;
    }
  }
  (*(code *)PTR_FUN_060da3e0)((int)sVar1);
  return 0xffffffff;
}



void FUN_060da3e8(int *param_1,undefined4 param_2)

{
  *(undefined4 *)(*param_1 + 0x40) = param_2;
  return;
}



void FUN_060da3f8(undefined4 param_1)

{
  *DAT_060da404 = param_1;
  return;
}



int FUN_060da490(int param_1)

{
  int iVar1;
  
  if ((*DAT_060da4b4 & *(uint *)(PTR_DAT_060da4b8 + param_1 * 4)) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 * 4 + DAT_060da4bc;
  }
  return iVar1;
}



void FUN_060da4d8(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if ((*DAT_060da52c == 0) || (iVar1 = (*(code *)PTR_FUN_060da530)(param_1), iVar1 != 0)) {
    (*(code *)PTR_FUN_060da534)(param_1);
  }
  if (*DAT_060da52c != 0) {
    *DAT_060da52c = 0;
    (*(code *)PTR_FUN_060da538)(param_1,0);
  }
  *(undefined4 *)(iVar2 + 0x34) = 5;
  return;
}



undefined4 FUN_060da53c(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x6c) != *(int *)(iVar1 + 0x70)) {
    if (*(int *)(iVar1 + 0x60) == -1) {
      return 0;
    }
    if (*(int *)(iVar1 + 0x98) < *(int *)(iVar1 + 0x60)) {
      return 0;
    }
  }
  return 1;
}



void FUN_060da570(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int local_18 [2];
  
  iVar3 = *param_1;
  piVar2 = (int *)(iVar3 + 0x30 + (int)DAT_060da614);
  *piVar2 = *piVar2 + 1;
  if (*(int *)(iVar3 + 0x34) - 2U < 3) {
    if (*DAT_060da618 == 0) {
      if ((*(int *)(iVar3 + 0x34) != 2) ||
         (iVar1 = (*(code *)PTR_FUN_060da620)(param_1), iVar1 == 0)) {
        (**(code **)(iVar3 + 0x30 + (int)DAT_060da616))(param_1);
        if ((*(int *)(iVar3 + 0x34) == 4) &&
           ((iVar1 = (*(code *)PTR_FUN_060da624)(param_1), iVar1 != 0 &&
            ((*(code *)PTR_FUN_060da628)(param_1,local_18),
            *(int *)(iVar3 + 0x9c) < local_18[0] + *(int *)(*param_1 + 0x2c))))) {
          (*(code *)PTR_FUN_060da62c)(param_1);
        }
        if (*(int *)(iVar3 + 0x34) == 3) {
          (*(code *)PTR_FUN_060da630)(param_1);
        }
      }
    }
    else {
      (*(code *)PTR_FUN_060da61c)();
      *(undefined4 *)(iVar3 + 0x34) = 0xffffffff;
    }
  }
  return;
}



void FUN_060da634(void)

{
  *(byte *)(int)DAT_060da652 = *(byte *)(int)DAT_060da652 & 0xfc | 2;
  *DAT_060da654 = 0;
  *DAT_060da658 = 0;
  return;
}



undefined8 FUN_060da65c(void)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  ushort *puVar4;
  uint uVar5;
  uint in_sr;
  uint uVar6;
  
  puVar4 = DAT_060da6c8;
  uVar5 = (uint)DAT_060da6be;
  cVar1 = *(char *)(int)DAT_060da6c0;
  bVar2 = *(byte *)(int)DAT_060da6c2;
  uVar3 = (int)cVar1 << 8 & 0xffff;
  uVar6 = in_sr & 0xfff0ffe | 0xf0 | (uint)((uint)*DAT_060da6c8 <= (uVar3 | bVar2));
  if (((byte)uVar6 & 1) != 1) {
    *DAT_060da6cc = *DAT_060da6cc + (int)DAT_060da6c4;
  }
  *puVar4 = (ushort)((int)cVar1 << 8) | (ushort)bVar2;
  return CONCAT44(uVar6 & uVar5 | in_sr & 0xf0,(uVar3 >> 8) + *DAT_060da6cc);
}



void FUN_060da6d0(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *param_1;
  uVar1 = (*(code *)PTR_FUN_060da718)();
  *(undefined4 *)(iVar2 + 0xa8) = uVar1;
  return;
}



undefined8 FUN_060da71c(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint in_sr;
  uint uVar4;
  
  iVar2 = *param_1;
  uVar3 = (uint)DAT_060da762;
  uVar4 = in_sr & 0xfff0fff | 0xf0;
  iVar1 = (*(code *)PTR_FUN_060da764)();
  return CONCAT44(uVar4 & uVar3 | in_sr & 0xf0,iVar1 - *(int *)(iVar2 + 0xa8));
}



uint FUN_060da768(int *param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  iVar4 = *param_1;
  switch(*(undefined4 *)(iVar4 + 0x34)) {
  default:
    iVar9 = 0;
    break;
  case 2:
  case 3:
  case 4:
  case 5:
    iVar9 = (*(code *)PTR_FUN_060da828)();
    break;
  case 0xffffffff:
  case 0:
    return 0xffffffff;
  }
  puVar1 = PTR_FUN_060da82c;
  piVar5 = (int *)(iVar4 + 0xac);
  iVar8 = *(int *)(iVar4 + 0x94);
  iVar7 = *(int *)(iVar4 + 0x5c);
  iVar4 = (*(code *)PTR_FUN_060da82c)(iVar9,*piVar5,piVar5,iVar7);
  iVar10 = iVar4 * iVar7;
  iVar6 = *piVar5;
  iVar4 = iVar4 * iVar6;
  iVar2 = (*(code *)puVar1)(iVar7,*piVar5);
  iVar3 = (*(code *)puVar1)();
  iVar3 = (*(code *)puVar1)((iVar7 - iVar3 * iVar6) * (iVar9 - iVar4),iVar6);
  return iVar8 * 0x1000 + iVar10 + iVar2 * (iVar9 - iVar4) + iVar3 & 0xfffffffc;
}



void FUN_060da8a8(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  switch(*(undefined4 *)(iVar2 + 0x34)) {
  case 1:
    iVar1 = *(int *)(iVar2 + 0xa4);
    break;
  case 2:
  case 3:
  case 4:
  case 5:
    iVar1 = (*(code *)PTR_FUN_060da908)();
    iVar1 = *(int *)(iVar2 + 0xa4) + iVar1;
    break;
  case 0xffffffff:
  case 0:
    *param_2 = -1;
    return;
  default:
    goto switchD_060da8cc_caseD_7;
  }
  *param_2 = iVar1;
switchD_060da8cc_caseD_7:
  return;
}



void FUN_060da90c(int *param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar3 = *param_1;
  if (*(int *)(iVar3 + 0x38) != 1) {
    *(int *)(iVar3 + 0x54) = (int)*(short *)(param_2 + 8);
    uVar1 = DAT_060da97c;
    *(int *)(iVar3 + 0x58) = (int)*(short *)(param_2 + 0xe);
    iVar5 = (int)DAT_060da978;
    uVar4 = (int)*(short *)(param_2 + 0x12) & uVar1;
    *(uint *)(iVar3 + 0x5c) = uVar4;
    uVar2 = (*(code *)PTR_FUN_060da980)(uVar4,iVar5 - *(short *)(param_2 + 0x10));
    *(undefined4 *)(iVar3 + 0x5c) = uVar2;
    *(uint *)(iVar3 + 0x60) =
         (int)*(short *)(param_2 + 10) << 0x10 | (int)*(short *)(param_2 + 0xc) & uVar1;
    *(undefined4 *)(iVar3 + 0x4c) = 1;
  }
  return;
}



void FUN_060da984(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x38) != 1) {
    (*(code *)PTR_FUN_060da9d0)();
    *(undefined4 *)(iVar1 + 100) = *(undefined4 *)(param_2 + 0x1a);
    *(undefined4 *)(iVar1 + 0x4c) = 6;
    *(int *)(iVar1 + 0x60) = *(int *)(iVar1 + 0x60) * 0x40;
  }
  return;
}



void FUN_060da9d4(int *param_1,int param_2)

{
  *(int *)(*param_1 + 0x80) = param_2 - (*(int *)(*param_1 + 4) + -0x10);
  return;
}



undefined4 FUN_060daa48(int *param_1)

{
  short sVar1;
  short sVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  short *psVar10;
  
  uVar4 = DAT_060dabb0;
  uVar8 = DAT_060daba8;
  iVar9 = 0xc;
  iVar6 = *param_1;
  psVar10 = *(short **)(iVar6 + 4);
  bVar3 = false;
  if (*(int *)(iVar6 + 0x6c) < 0x2c) {
    return 0xffffffff;
  }
  if (((int)*psVar10 << 0x10 | (int)psVar10[1] & DAT_060daba8) == *(uint *)PTR_DAT_060dabac) {
    *(uint *)(iVar6 + 0x50) =
         ((int)psVar10[2] << 0x10 & DAT_060dabb0 | (int)psVar10[3] & DAT_060daba8) + 8;
    uVar5 = DAT_060dacbc;
    uVar7 = DAT_060dacb4;
    if (((int)psVar10[4] << 0x10 & uVar4 | (int)psVar10[5] & uVar8) == *(uint *)PTR_DAT_060dabb4) {
      *(undefined4 *)(iVar6 + 0x48) = 2;
      psVar10 = psVar10 + 6;
      do {
        sVar1 = psVar10[2];
        sVar2 = psVar10[3];
        iVar9 = iVar9 + 8 + ((int)psVar10[2] << 0x10 & uVar4 | (int)psVar10[3] & uVar8);
        uVar7 = (int)*psVar10 << 0x10 & uVar4 | (int)psVar10[1] & uVar8;
        if (uVar7 == *(uint *)PTR_DAT_060dabb8) {
          (*(code *)PTR_FUN_060dabbc)(param_1);
          bVar3 = true;
        }
        else {
          if (uVar7 == *(uint *)PTR_DAT_060dabc0) {
            (*(code *)PTR_FUN_060dabc4)(param_1);
            if (bVar3) {
              return 0;
            }
            iVar6 = (int)DAT_060daba4;
            goto LAB_060dac92;
          }
          if (uVar7 == *(uint *)PTR_DAT_060dabc8) {
            (*(code *)*DAT_060dabcc)(param_1);
            if (bVar3) {
              return 0;
            }
            iVar6 = (int)DAT_060daba4;
            goto LAB_060dac92;
          }
        }
        psVar10 = (short *)((int)psVar10 + ((int)sVar1 << 0x10 & uVar4 | (int)sVar2 & uVar8) + 8);
      } while (iVar9 + 0x20 <= *(int *)(iVar6 + 0x6c));
      if (iVar9 <= *(int *)(iVar6 + 8)) {
        return 0xffffffff;
      }
      iVar6 = (int)DAT_060daba6;
      goto LAB_060dac92;
    }
    if (((int)psVar10[4] << 0x10 | (int)psVar10[5] & DAT_060dacb4) == *(uint *)PTR_DAT_060dacb8) {
      *(undefined4 *)(iVar6 + 0x48) = 3;
      psVar10 = psVar10 + 6;
      do {
        sVar1 = psVar10[2];
        sVar2 = psVar10[3];
        uVar8 = (int)*psVar10 << 0x10 & uVar5 | (int)psVar10[1] & uVar7;
        if (uVar8 == *(uint *)PTR_DAT_060dacc0) {
          (*(code *)PTR_FUN_060dacc4)(param_1);
          bVar3 = true;
          if ((*(int *)(iVar6 + 100) != *(int *)PTR_DAT_060dacc8) &&
             (*(int *)(iVar6 + 100) != *(int *)PTR_DAT_060daccc)) {
            iVar6 = (int)DAT_060dacae;
            goto LAB_060dac92;
          }
        }
        else if (uVar8 == *(uint *)PTR_DAT_060dacd4) {
          (*(code *)PTR_FUN_060dacd8)(param_1);
          if (bVar3) {
            return 0;
          }
          iVar6 = (int)DAT_060daba4;
          goto LAB_060dac92;
        }
        psVar10 = (short *)((int)psVar10 + ((int)sVar1 << 0x10 & uVar5 | (int)sVar2 & uVar7) + 8);
      } while (0x2b < *(int *)(iVar6 + 0x6c));
      if (0xb < *(int *)(iVar6 + 8)) {
        return 0xffffffff;
      }
      iVar6 = (int)DAT_060daba6;
      goto LAB_060dac92;
    }
  }
  iVar6 = (int)DAT_060dacb0;
LAB_060dac92:
  (*(code *)PTR_FUN_060dacd0)(iVar6);
  return 0xffffffff;
}



void FUN_060dadc0(undefined *param_1,undefined *param_2,int param_3)

{
  undefined uVar1;
  
  if (param_1 < param_2) {
    for (param_3 = param_3 + -1; -1 < param_3; param_3 = param_3 + -1) {
      uVar1 = *param_2;
      param_2 = param_2 + 1;
      *param_1 = uVar1;
      param_1 = param_1 + 1;
    }
  }
  else if (param_2 < param_1) {
    param_1 = param_1 + param_3;
    param_2 = param_2 + param_3;
    for (param_3 = param_3 + -1; -1 < param_3; param_3 = param_3 + -1) {
      param_2 = param_2 + -1;
      param_1 = param_1 + -1;
      *param_1 = *param_2;
    }
  }
  return;
}



void FUN_060dae04(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_1 < param_2) {
    for (param_3 = param_3 + -1; -1 < param_3; param_3 = param_3 + -1) {
      uVar1 = *param_2;
      param_2 = param_2 + 1;
      *param_1 = uVar1;
      param_1 = param_1 + 1;
    }
  }
  else if (param_2 < param_1) {
    param_1 = param_1 + param_3;
    param_2 = param_2 + param_3;
    for (param_3 = param_3 + -1; -1 < param_3; param_3 = param_3 + -1) {
      param_2 = param_2 + -1;
      param_1 = param_1 + -1;
      *param_1 = *param_2;
    }
  }
  return;
}



void FUN_060dae4c(undefined4 param_1,int param_2,int param_3,int param_4)

{
  undefined *puVar1;
  
  puVar1 = PTR_FUN_060dae94;
  (*(code *)PTR_FUN_060dae94)(param_1,param_2,param_4);
  (*(code *)puVar1)(param_2,param_2 + param_4,param_3 - param_4);
  (*(code *)puVar1)(param_2 + (param_3 - param_4),param_1,param_4);
  return;
}



void FUN_060dae98(undefined4 param_1,int param_2,int param_3,int param_4)

{
  undefined *puVar1;
  
  puVar1 = PTR_FUN_060daee4;
  (*(code *)PTR_FUN_060daee4)(param_1,param_2,param_4);
  (*(code *)puVar1)(param_2,param_2 + param_4 * 4,param_3 - param_4);
  (*(code *)puVar1)(param_2 + (param_3 - param_4) * 4,param_1,param_4);
  return;
}



void FUN_060dafe8(int param_1)

{
  bool bVar1;
  
  param_1 = param_1 + -1;
  do {
    bVar1 = 0 < param_1;
    param_1 = param_1 + -1;
  } while (bVar1);
  return;
}



void FUN_060daffc(byte param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  piVar1 = DAT_060db074;
  uVar4 = 0;
  iVar5 = (int)DAT_060db072;
  do {
    piVar2 = (int *)(*(code *)PTR_FUN_060db078)(uVar4);
    uVar4 = uVar4 + 1;
    if (piVar2 != (int *)0x0) {
      iVar3 = *piVar2;
      if (((*(int *)(iVar3 + 0x34) == 4) &&
          ((PTR_DAT_060db07c[*(int *)(iVar3 + 0x18)] & param_1) != 0)) &&
         (2 < *piVar1 - *(int *)(iVar5 + iVar3 + 0x30))) {
        *(int *)(iVar3 + 0x94) = *(int *)(iVar3 + 0x94) + 1;
        (*(code *)PTR_FUN_060db080)(piVar2);
      }
    }
  } while (uVar4 < 0x20);
  return;
}



void FUN_060db084(int param_1)

{
  *(undefined *)(DAT_060db0a8 + param_1) =
       *(undefined *)(DAT_060db0ac + param_1 * 2 + *DAT_060db0a4);
  return;
}



void FUN_060db0b0(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  byte bVar4;
  char *pcVar5;
  int iVar6;
  
  iVar3 = DAT_060db108;
  piVar2 = DAT_060db104;
  bVar4 = 0;
  iVar6 = 0;
  pcVar5 = DAT_060db10c;
  do {
    cVar1 = *(char *)(iVar3 + iVar6 * 2 + *piVar2);
    if (*pcVar5 != cVar1) {
      *pcVar5 = cVar1;
      bVar4 = bVar4 | PTR_DAT_060db110[iVar6];
    }
    iVar6 = iVar6 + 1;
    pcVar5 = pcVar5 + 1;
  } while (iVar6 < 8);
  if (bVar4 != 0) {
    (*(code *)PTR_FUN_060db114)();
  }
  return;
}



void FUN_060db250(int *param_1)

{
  undefined *puVar1;
  int iVar2;
  ushort uVar3;
  char cVar4;
  undefined2 uVar5;
  int iVar6;
  int iVar7;
  byte local_34 [2];
  undefined2 local_32;
  undefined2 local_30;
  undefined local_2c;
  undefined local_2b;
  undefined local_2a;
  ushort local_28;
  undefined local_26;
  undefined local_25;
  undefined local_24;
  undefined local_23;
  
  puVar1 = PTR_FUN_060db3a4;
  iVar7 = *param_1;
  iVar6 = *(int *)(iVar7 + 0x5c);
  iVar2 = (*(code *)PTR_FUN_060db3a4)(DAT_060db3a0,iVar6 + 1);
  cVar4 = PTR_DAT_060db3a8[iVar2];
  iVar2 = (*(code *)PTR_FUN_060db3ac)();
  uVar3 = (*(code *)puVar1)((iVar6 - iVar2) * 0x400,iVar2);
  puVar1 = PTR_FUN_060db3b0;
  local_2c = *(undefined *)(iVar7 + 0x1b);
  local_2b = *(undefined *)(iVar7 + 0x23);
  local_2a = *(undefined *)(iVar7 + 0x1f);
  local_28 = (ushort)((-(int)cVar4 & 0xfU) << 0xb) | DAT_060db398 & uVar3;
  local_26 = 0;
  local_25 = 0;
  local_24 = 0;
  local_23 = 0;
  if (*(int *)(iVar7 + 0x54) == 1) {
    uVar5 = 0;
    iVar2 = *(int *)(iVar7 + 0x58);
  }
  else {
    iVar2 = *(int *)(iVar7 + 0x58);
    uVar5 = DAT_060db39a;
  }
  local_34[0] = (byte)uVar5;
  if (7 < iVar2 - 9U) {
    local_34[0] = local_34[0] | 0x10;
  }
  local_32 = (undefined2)(*(uint *)(iVar7 + 0xc) >> 4);
  local_30 = *(undefined2 *)(iVar7 + 0x12);
  while (cVar4 = (*(code *)puVar1)(local_34,&local_2c), cVar4 == '\x01') {
    (*(code *)PTR_FUN_060db3b4)(100);
  }
  (*(code *)PTR_FUN_060db3b8)(*(undefined4 *)(iVar7 + 0x18));
  return;
}



void FUN_060db3bc(int *param_1)

{
  undefined *puVar1;
  char cVar2;
  int iVar3;
  
  puVar1 = PTR_FUN_060db43c;
  iVar3 = *param_1;
  while (cVar2 = (*(code *)puVar1)(*(undefined *)(iVar3 + 0x1b)), cVar2 == '\x01') {
    (*(code *)PTR_FUN_060db440)(100);
  }
  return;
}



void FUN_060db444(uint param_1,uint param_2,undefined4 param_3,int param_4,uint param_5)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if ((param_1 & 3) != 0) {
    param_1 = param_1 + 3 & 0xfffffffc;
    param_2 = param_2 - 4;
  }
  if (0 < (int)param_5) {
    do {
      uVar4 = param_2 & 0xfffffffc;
      if ((int)param_5 < (int)(param_2 & 0xfffffffc)) {
        uVar4 = param_5;
      }
      pcVar1 = (code *)PTR_FUN_060db4cc;
      iVar2 = param_4;
      uVar3 = uVar4;
      if ((uVar4 & 3) == 0) {
        pcVar1 = (code *)PTR_FUN_060db4d0;
        iVar2 = param_4 >> 2;
        uVar3 = (int)uVar4 >> 2;
      }
      param_5 = param_5 - uVar4;
      (*pcVar1)(param_1,param_3,iVar2,uVar3);
    } while (0 < (int)param_5);
  }
  return;
}



void FUN_060db4d4(int *param_1,int *param_2,int *param_3,int *param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  iVar2 = *(int *)(iVar1 + 0x94) * 0x1000 + *(int *)(iVar1 + 0xa4);
  if (*(int *)(iVar1 + 0x58) < 9) {
    iVar2 = *(int *)(iVar1 + 0x9c) - iVar2;
  }
  else {
    iVar2 = (*(int *)(iVar1 + 0x9c) - iVar2) * 2;
  }
  iVar2 = *(int *)(iVar1 + 0x8c) - iVar2;
  *param_5 = iVar2;
  if (iVar2 == 0) {
    *param_4 = 0;
    *param_2 = 0;
    *param_3 = 0;
  }
  else {
    if (*(int *)(iVar1 + 0x8c) < *(int *)(iVar1 + 0x90) + iVar2) {
      *param_4 = *(int *)(iVar1 + 0x8c) - *(int *)(iVar1 + 0x90);
    }
    else {
      *param_4 = iVar2;
    }
    *param_2 = *(int *)(iVar1 + 0xc) + *(int *)(iVar1 + 0x90);
    *param_3 = *(int *)(iVar1 + 0x88) + *(int *)(iVar1 + 0x90);
  }
  return;
}



void FUN_060db578(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = *param_1;
  iVar3 = param_2;
  if (8 < *(int *)(iVar1 + 0x58)) {
    iVar3 = param_2 >> 1;
  }
  *(int *)(iVar1 + 0x98) = *(int *)(iVar1 + 0x98) + iVar3;
  *(int *)(iVar1 + 0x9c) = *(int *)(iVar1 + 0x9c) + iVar3;
  piVar2 = (int *)(iVar1 + 0x90);
  param_2 = param_2 + *piVar2;
  *piVar2 = param_2;
  if (*(int *)(iVar1 + 0x8c) <= param_2) {
    *piVar2 = param_2 - *(int *)(iVar1 + 0x8c);
  }
  return;
}



void FUN_060db5c4(int *param_1,int param_2)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 local_2c;
  undefined4 uStack_28;
  int iStack_24;
  undefined auStack_20 [8];
  
  iVar5 = *param_1;
  iVar4 = iVar5 + 0x30;
  (*(code *)PTR_FUN_060db6ec)(param_1,&local_2c,&uStack_28,&iStack_24,auStack_20);
  if (iStack_24 < param_2) {
    *(uint *)(iVar4 + DAT_060db6de) = (uint)(iStack_24 < param_2);
    uVar7 = *(undefined4 *)(iVar5 + 0x7c);
    uVar2 = local_2c;
    if ((*(int *)(iVar5 + 0x54) != 1) && (*(int *)(iVar5 + 0x4c) == 1)) {
      uVar2 = uStack_28;
    }
    *(undefined4 *)(iVar4 + DAT_060db6e4) = uVar2;
    if (*(int *)(iVar5 + 0x54) == 1) {
      uVar2 = 0;
    }
    else {
      uVar2 = uStack_28;
      if (*(int *)(iVar5 + 0x4c) == 1) {
        uVar2 = local_2c;
      }
    }
    *(undefined4 *)(iVar4 + DAT_060db6e6) = uVar2;
    *(undefined4 *)(iVar4 + DAT_060db6e8) = uVar7;
    puVar1 = PTR_FUN_060db6f0;
    *(int *)(iVar4 + DAT_060db6ea) = iStack_24;
    (*(code *)puVar1)(param_1);
    param_2 = param_2 - iStack_24;
    if (*(int *)(iVar5 + 0x54) != 1) {
      iStack_24 = iStack_24 * 2;
    }
    iVar6 = *(int *)(iVar5 + 0x7c) + iStack_24;
    (*(code *)PTR_FUN_060db6ec)(param_1,&local_2c,&uStack_28,&iStack_24,auStack_20);
    uVar2 = local_2c;
    if ((*(int *)(iVar5 + 0x54) != 1) && (*(int *)(iVar5 + 0x4c) == 1)) {
      uVar2 = uStack_28;
    }
    *(undefined4 *)(iVar4 + DAT_060db6e0) = uVar2;
    puVar3 = (undefined4 *)(iVar4 + DAT_060db738);
    if (*(int *)(iVar5 + 0x54) != 1) {
      if (*(int *)(iVar5 + 0x4c) == 1) {
        uStack_28 = local_2c;
      }
      goto LAB_060db712;
    }
  }
  else {
    *(undefined4 *)(iVar4 + DAT_060db6de) = 0;
    iVar6 = *(int *)(iVar5 + 0x7c);
    uVar2 = local_2c;
    if ((*(int *)(iVar5 + 0x54) != 1) && (*(int *)(iVar5 + 0x4c) == 1)) {
      uVar2 = uStack_28;
    }
    *(undefined4 *)(iVar4 + DAT_060db6e0) = uVar2;
    puVar3 = (undefined4 *)(iVar4 + DAT_060db6e2);
    if (*(int *)(iVar5 + 0x54) != 1) {
      if (*(int *)(iVar5 + 0x4c) == 1) {
        uStack_28 = local_2c;
      }
      goto LAB_060db712;
    }
  }
  uStack_28 = 0;
LAB_060db712:
  *puVar3 = uStack_28;
  *(int *)(iVar4 + DAT_060db73a) = iVar6;
  *(int *)(iVar4 + DAT_060db73c) = param_2;
  (*(code *)PTR_FUN_060db740)(param_1,param_2);
  return;
}



void FUN_060db744(int *param_1,undefined4 *param_2)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined2 *puVar7;
  
  puVar7 = (undefined2 *)*param_2;
  puVar4 = (undefined2 *)param_2[1];
  puVar2 = (undefined2 *)param_2[2];
  puVar1 = *(undefined2 **)(*param_1 + 0x74);
  puVar5 = (undefined4 *)(*param_1 + 4);
  iVar6 = (int)param_2[3] >> 1;
  puVar3 = puVar2 + iVar6 * 2;
  if ((undefined2 *)*puVar5 < puVar3) {
    for (; 0 < iVar6; iVar6 = iVar6 + -1) {
      puVar3 = puVar2 + 1;
      *puVar7 = *puVar2;
      puVar7 = puVar7 + 1;
      if (puVar1 <= puVar3) {
        puVar3 = (undefined2 *)*puVar5;
      }
      puVar2 = puVar3 + 1;
      *puVar4 = *puVar3;
      puVar4 = puVar4 + 1;
      if (puVar1 <= puVar2) {
        puVar2 = (undefined2 *)*puVar5;
      }
    }
  }
  else {
    for (; puVar2 < puVar3; puVar2 = puVar2 + 2) {
      *puVar7 = *puVar2;
      puVar7 = puVar7 + 1;
      *puVar4 = puVar2[1];
      puVar4 = puVar4 + 1;
    }
  }
  return;
}



void FUN_060db7b0(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  undefined *puVar5;
  int iVar6;
  undefined *puVar7;
  
  iVar6 = param_2[3];
  puVar7 = (undefined *)*param_2;
  puVar3 = (undefined *)param_2[1];
  puVar2 = (undefined *)param_2[2];
  puVar4 = (undefined4 *)(*param_1 + 4);
  puVar1 = *(undefined **)(*param_1 + 0x74);
  puVar5 = puVar2 + iVar6 * 2;
  if ((undefined *)*puVar4 < puVar5) {
    for (; 0 < iVar6; iVar6 = iVar6 + -1) {
      puVar5 = puVar2 + 1;
      *puVar7 = *puVar2;
      puVar7 = puVar7 + 1;
      if (puVar1 <= puVar5) {
        puVar5 = (undefined *)*puVar4;
      }
      puVar2 = puVar5 + 1;
      *puVar3 = *puVar5;
      puVar3 = puVar3 + 1;
      if (puVar1 <= puVar2) {
        puVar2 = (undefined *)*puVar4;
      }
    }
  }
  else {
    for (; puVar2 < puVar5; puVar2 = puVar2 + 2) {
      *puVar7 = *puVar2;
      puVar7 = puVar7 + 1;
      *puVar3 = puVar2[1];
      puVar3 = puVar3 + 1;
    }
  }
  return;
}



void FUN_060db814(int *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  
  iVar1 = *param_1;
  puVar4 = (undefined2 *)*param_2;
  puVar3 = (undefined2 *)param_2[2];
  puVar5 = *(undefined2 **)(iVar1 + 0x74);
  puVar6 = puVar3 + ((int)param_2[3] >> 1);
  if (puVar5 < puVar6) {
    iVar2 = *(int *)(iVar1 + 8);
    for (; puVar3 < puVar5; puVar3 = puVar3 + 1) {
      *puVar4 = *puVar3;
      puVar4 = puVar4 + 1;
    }
    for (puVar3 = *(undefined2 **)(iVar1 + 4); puVar3 < puVar6 + -(iVar2 >> 1); puVar3 = puVar3 + 1)
    {
      *puVar4 = *puVar3;
      puVar4 = puVar4 + 1;
    }
  }
  else {
    for (; puVar3 < puVar6; puVar3 = puVar3 + 1) {
      *puVar4 = *puVar3;
      puVar4 = puVar4 + 1;
    }
  }
  return;
}



void FUN_060db878(int *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  
  iVar1 = *param_1;
  puVar4 = (undefined *)*param_2;
  puVar3 = (undefined *)param_2[2];
  puVar5 = *(undefined **)(iVar1 + 0x74);
  puVar6 = puVar3 + param_2[3];
  if (puVar5 < puVar6) {
    iVar2 = *(int *)(iVar1 + 8);
    for (; puVar3 < puVar5; puVar3 = puVar3 + 1) {
      *puVar4 = *puVar3;
      puVar4 = puVar4 + 1;
    }
    for (puVar3 = *(undefined **)(iVar1 + 4); puVar3 < puVar6 + -iVar2; puVar3 = puVar3 + 1) {
      *puVar4 = *puVar3;
      puVar4 = puVar4 + 1;
    }
  }
  else {
    for (; puVar3 < puVar6; puVar3 = puVar3 + 1) {
      *puVar4 = *puVar3;
      puVar4 = puVar4 + 1;
    }
  }
  return;
}



void FUN_060db8d4(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  int *piVar5;
  int iVar6;
  
  iVar2 = *param_1;
  iVar1 = (int)DAT_060db978;
  iVar6 = iVar2 + 0x30;
  iVar3 = *(int *)(iVar6 + iVar1);
  while (-1 < iVar3) {
    if (*(int *)(iVar2 + 0x54) == 1) {
      if (*(int *)(iVar2 + 0x58) < 9) {
        iVar3 = iVar6 + *(int *)(iVar6 + DAT_060db978) * 0x10 + (int)DAT_060db97a;
        pcVar4 = (code *)PTR_FUN_060db97c;
      }
      else {
        iVar3 = iVar6 + *(int *)(iVar6 + DAT_060db978) * 0x10 + (int)DAT_060db97a;
        pcVar4 = (code *)PTR_FUN_060db980;
      }
    }
    else if (*(int *)(iVar2 + 0x58) < 9) {
      iVar3 = iVar6 + *(int *)(iVar6 + DAT_060db978) * 0x10 + (int)DAT_060db97a;
      pcVar4 = (code *)PTR_FUN_060db984;
    }
    else {
      iVar3 = iVar6 + *(int *)(iVar6 + DAT_060db978) * 0x10 + (int)DAT_060db97a;
      pcVar4 = (code *)PTR_FUN_060db988;
    }
    (*pcVar4)(param_1,iVar3);
    piVar5 = (int *)(iVar6 + iVar1);
    iVar3 = *piVar5 + -1;
    *piVar5 = iVar3;
  }
  return;
}



void FUN_060db98c(int *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  undefined auStack_24 [4];
  undefined auStack_20 [4];
  undefined auStack_1c [4];
  uint auStack_18 [2];
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x50) < *(int *)(iVar1 + 0x6c)) {
    uVar3 = *(int *)(iVar1 + 0x50) - *(int *)(iVar1 + 0x70);
  }
  else {
    uVar3 = *(int *)(iVar1 + 0x6c) - *(int *)(iVar1 + 0x70);
  }
  if (*(int *)(iVar1 + 0x54) == 1) {
    iVar4 = *(int *)(iVar1 + 0x58);
  }
  else {
    uVar3 = (int)uVar3 >> 1;
    iVar4 = *(int *)(iVar1 + 0x58);
  }
  if (iVar4 < 9) {
    uVar3 = uVar3 & 0xfffffffe;
  }
  uVar3 = uVar3 & 0xfffffffc;
  if (iVar4 < 9) {
    iVar4 = *(int *)(iVar1 + 0x60) - *(int *)(iVar1 + 0x98);
  }
  else {
    iVar4 = (*(int *)(iVar1 + 0x60) - *(int *)(iVar1 + 0x98)) * 2;
  }
  if ((iVar4 <= (int)uVar3) &&
     (uVar3 = *(int *)(iVar1 + 0x60) - *(int *)(iVar1 + 0x98), 8 < *(int *)(iVar1 + 0x58))) {
    uVar3 = uVar3 * 2;
  }
  (*(code *)PTR_FUN_060dba98)(param_1,auStack_24,auStack_20,auStack_1c,auStack_18);
  if (*(int *)(iVar1 + 0x8c) < (int)auStack_18[0]) {
    piVar5 = (int *)(iVar1 + 0x30 + (int)DAT_060dba94);
    *piVar5 = *piVar5 + 1;
  }
  if ((int)auStack_18[0] < (int)uVar3) {
    uVar3 = auStack_18[0];
  }
  if (uVar3 != 0) {
    uVar2 = *(uint *)(iVar1 + 0x30 + (int)DAT_060dba96);
    if ((int)uVar2 < (int)uVar3) {
      uVar3 = uVar2;
    }
    (*(code *)PTR_FUN_060dba9c)(param_1,uVar3);
    (*(code *)PTR_FUN_060dbaa0)(param_1);
    if (*(int *)(iVar1 + 0x54) != 1) {
      uVar3 = uVar3 * 2;
    }
    (*(code *)PTR_FUN_060dbaa4)(param_1,uVar3);
  }
  return;
}



void FUN_060dbad0(int param_1,uint param_2)

{
  *(int *)param_1 = param_1;
  *DAT_060dbae4 = param_1;
  *(uint *)(param_1 + 4) = param_2 >> 3;
  return;
}



undefined4 * FUN_060dbae8(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  
  puVar1 = DAT_060dbb34;
  uVar6 = (param_1 + 7U >> 3) + 1;
  puVar2 = *(undefined4 **)*DAT_060dbb34;
  puVar5 = (undefined4 *)*DAT_060dbb34;
  while( true ) {
    puVar3 = puVar2;
    uVar4 = puVar3[1];
    if (uVar6 <= uVar4) {
      if (uVar4 == uVar6) {
        *puVar5 = *puVar3;
      }
      else {
        puVar3[1] = uVar4 - uVar6;
        puVar3 = puVar3 + (uVar4 - uVar6) * 2;
        puVar3[1] = uVar6;
      }
      *puVar1 = puVar5;
      return puVar3 + 2;
    }
    if (puVar3 == (undefined4 *)*DAT_060dbb34) break;
    puVar2 = (undefined4 *)*puVar3;
    puVar5 = puVar3;
  }
  return (undefined4 *)0x0;
}



uint FUN_060dbb38(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (*(code *)PTR_FUN_060dbb80)(param_2);
  uVar2 = 0;
  if (uVar1 != 0) {
    if (param_2 != 0) {
      do {
        *(undefined *)(uVar1 + uVar2) = *(undefined *)(param_1 + uVar2);
        uVar2 = uVar2 + 1;
      } while (uVar2 < param_2);
    }
    (*(code *)PTR_FUN_060dbb84)(param_1);
    uVar2 = uVar1;
  }
  return uVar2;
}



void FUN_060dbb88(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)(param_1 + -8);
  puVar1 = (undefined4 *)*DAT_060dbbf4;
  do {
    puVar2 = puVar1;
    if (puVar2 < puVar3) {
      puVar1 = (undefined4 *)*puVar2;
      if (puVar3 < puVar1) break;
    }
    else {
      puVar1 = (undefined4 *)*puVar2;
    }
  } while ((puVar2 < puVar1) || ((puVar3 <= puVar2 && (puVar1 <= puVar3))));
  puVar1 = (undefined4 *)*puVar2;
  if (puVar3 + *(int *)(param_1 + -4) * 2 == puVar1) {
    *(int *)(param_1 + -4) = puVar1[1] + *(int *)(param_1 + -4);
    *puVar3 = *(undefined4 *)*puVar2;
  }
  else {
    *puVar3 = puVar1;
  }
  if (puVar2 + puVar2[1] * 2 == puVar3) {
    puVar2[1] = *(int *)(param_1 + -4) + puVar2[1];
    puVar3 = (undefined4 *)*puVar3;
  }
  *puVar2 = puVar3;
  *DAT_060dbbf4 = puVar2;
  return;
}



undefined4 * FUN_060dbbf8(undefined4 *param_1,int param_2,uint param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  
  puVar2 = param_1;
  if (param_2 == 0) {
    uVar1 = (uint)param_1 & 3;
    if ((param_3 != 0) && (uVar1 != 0)) {
      while (uVar1 != 4) {
        *(undefined *)puVar2 = 0;
        puVar2 = (undefined4 *)((int)puVar2 + 1);
        param_3 = param_3 - 1;
        uVar1 = uVar1 + 1;
        if ((param_3 == 0) || ((int)uVar1 < 1)) break;
      }
    }
    for (; 3 < param_3; param_3 = param_3 - 4) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
  }
  while (param_3 = param_3 - 1, param_3 != 0xffffffff) {
    *(char *)puVar2 = (char)param_2;
    puVar2 = (undefined4 *)((int)puVar2 + 1);
  }
  return param_1;
}



int FUN_060dbc54(byte *param_1,byte *param_2)

{
  byte bVar1;
  
  bVar1 = *param_1;
  while ((bVar1 != 0 && (bVar1 == *param_2))) {
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    bVar1 = *param_1;
  }
  return (uint)*param_1 - (uint)*param_2;
}



char * FUN_060dbc80(char *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  
  cVar1 = *param_2;
  param_2 = param_2 + 1;
  *param_1 = cVar1;
  pcVar2 = param_1 + 1;
  while (cVar1 != '\0') {
    cVar1 = *param_2;
    param_2 = param_2 + 1;
    *pcVar2 = cVar1;
    pcVar2 = pcVar2 + 1;
  }
  return param_1;
}



undefined * FUN_060dbca8(undefined *param_1,undefined *param_2,int param_3)

{
  undefined uVar1;
  undefined *puVar2;
  
  puVar2 = param_1;
  for (param_3 = param_3 + -1; param_3 != -1; param_3 = param_3 + -1) {
    uVar1 = *param_2;
    param_2 = param_2 + 1;
    *puVar2 = uVar1;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}



undefined * FUN_060dbccc(undefined *param_1,undefined *param_2,int param_3)

{
  undefined uVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  if ((param_2 < param_1) && (puVar2 = param_2 + param_3, param_1 < puVar2)) {
    puVar3 = param_1 + param_3;
    for (param_3 = param_3 + -1; param_3 != -1; param_3 = param_3 + -1) {
      puVar2 = puVar2 + -1;
      puVar3 = puVar3 + -1;
      *puVar3 = *puVar2;
    }
  }
  else {
    puVar2 = param_1;
    for (param_3 = param_3 + -1; param_3 != -1; param_3 = param_3 + -1) {
      uVar1 = *param_2;
      param_2 = param_2 + 1;
      *puVar2 = uVar1;
      puVar2 = puVar2 + 1;
    }
  }
  return param_1;
}



void FUN_060dbd6c(undefined *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *local_6c [2];
  undefined4 uStack_64;
  undefined2 local_60;
  undefined *puStack_5c;
  undefined4 uStack_58;
  undefined4 local_18;
  undefined4 local_8;
  undefined4 local_4;
  
  local_60 = DAT_060dbdb8;
  uStack_64 = DAT_060dbdc0;
  uStack_58 = DAT_060dbdc0;
  local_18 = *(undefined4 *)PTR_PTR_DAT_060dbdc4;
  local_6c[0] = param_1;
  puStack_5c = param_1;
  local_8 = param_3;
  local_4 = param_4;
  (*(code *)PTR_FUN_060dbdbc)(local_6c,param_2,&local_8);
  *local_6c[0] = 0;
  return;
}



uint FUN_060dbdc8(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x30) * DAT_060dbde8 + (int)DAT_060dbde6;
  *(int *)(param_1 + 0x30) = iVar1;
  return (uint)(iVar1 * 2) >> 0x11;
}



void FUN_060dbdec(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x30) = param_2;
  return;
}



void FUN_060dbdf8(void)

{
  (*(code *)PTR_FUN_060dbe14)(*(undefined4 *)PTR_PTR_DAT_060dbe10);
  return;
}



void FUN_060dbe18(undefined4 param_1)

{
  (*(code *)PTR_FUN_060dbe34)(*(undefined4 *)PTR_PTR_DAT_060dbe30,param_1);
  return;
}



void FUN_060dbe60(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = *(int *)PTR_PTR_DAT_060dbe90;
  *(int *)(*(int *)(iVar1 + 8) + 0x54) = iVar1;
  local_c = param_2;
  local_8 = param_3;
  local_4 = param_4;
  (*(code *)PTR_FUN_060dbe94)(*(undefined4 *)(iVar1 + 8),param_1,&local_c);
  return;
}



int FUN_060dbe98(byte *param_1,byte *param_2,int param_3)

{
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 == -1) {
      return 0;
    }
    if ((uint)*param_1 != (uint)*param_2) break;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return (uint)*param_1 - (uint)*param_2;
}



char * FUN_060dbec8(char *param_1,char param_2)

{
  char cVar1;
  
  cVar1 = *param_1;
  if (cVar1 != '\0') {
    do {
      if (cVar1 == param_2) break;
      param_1 = param_1 + 1;
      cVar1 = *param_1;
    } while (cVar1 != '\0');
    cVar1 = *param_1;
  }
  if (cVar1 != param_2) {
    param_1 = (char *)0x0;
  }
  return param_1;
}



int FUN_060dbef8(char *param_1)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar2 = param_1;
  if (*param_1 != '\0') {
    pcVar1 = param_1 + 1;
    do {
      pcVar2 = pcVar1;
      pcVar1 = pcVar2 + 1;
    } while (*pcVar2 != '\0');
  }
  return (int)pcVar2 - (int)param_1;
}



int FUN_060dbf1c(byte *param_1,byte *param_2,int param_3)

{
  int iVar1;
  
  if (param_3 == 0) {
    iVar1 = 0;
  }
  else {
    while (param_3 = param_3 + -1, param_3 != -1) {
      if ((((*param_1 != *param_2) || (param_3 == 0)) || (*param_1 == 0)) || (*param_2 == 0)) break;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
    iVar1 = (uint)*param_1 - (uint)*param_2;
  }
  return iVar1;
}



char * FUN_060dbf5c(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = param_1;
  if (param_3 != 0) {
    do {
      cVar1 = *param_2;
      param_2 = param_2 + 1;
      param_3 = param_3 + -1;
      *pcVar2 = cVar1;
      pcVar2 = pcVar2 + 1;
      if (cVar1 == '\0') break;
    } while (param_3 != 0);
  }
  for (; param_3 != 0; param_3 = param_3 + -1) {
    *pcVar2 = '\0';
    pcVar2 = pcVar2 + 1;
  }
  return param_1;
}



int FUN_060dbf98(char *param_1,int param_2,uint param_3,int param_4,int param_5,int param_6,
                undefined4 param_7)

{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  if ((param_5 == 0) || ((param_3 & 2) != 0)) {
    if (param_6 == 0) goto LAB_060dc038;
  }
  else {
    iVar5 = 0;
    if (((param_6 != 0) && ((param_3 & 0x40) != 0)) &&
       (iVar3 = (*(code *)PTR_FUN_060dc0d4)(param_6,param_7), iVar3 == -1)) {
      return -1;
    }
    puVar2 = PTR_FUN_060dc0d8;
    if (0 < param_5) {
      do {
        if ((param_3 & 0x40) == 0) {
          uVar4 = 0x20;
        }
        else {
          uVar4 = 0x30;
        }
        iVar3 = (*(code *)puVar2)(uVar4,param_7);
        iVar5 = iVar5 + 1;
        if (iVar3 == -1) {
          return -1;
        }
      } while (iVar5 < param_5);
    }
    if ((param_6 == 0) || ((param_3 & 0x40) != 0)) goto LAB_060dc038;
  }
  iVar5 = (*(code *)PTR_FUN_060dc0d4)(param_6,param_7);
  if (iVar5 != 0) {
    return -1;
  }
LAB_060dc038:
  puVar2 = PTR_FUN_060dc0d8;
  iVar5 = 0;
  if (0 < param_4) {
    do {
      iVar3 = (*(code *)puVar2)(0x30,param_7);
      if (iVar3 == -1) {
        return -1;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < param_4);
  }
  puVar2 = PTR_FUN_060dc0d8;
  iVar5 = 0;
  if (0 < param_2) {
    do {
      cVar1 = *param_1;
      param_1 = param_1 + 1;
      iVar3 = (*(code *)puVar2)((int)cVar1,param_7);
      if (iVar3 == -1) {
        return -1;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < param_2);
  }
  puVar2 = PTR_FUN_060dc0d8;
  if (((param_5 != 0) && (iVar5 = 0, (param_3 & 2) != 0)) && (0 < param_5)) {
    do {
      iVar3 = (*(code *)puVar2)(0x20,param_7);
      iVar5 = iVar5 + 1;
      if (iVar3 == -1) {
        return -1;
      }
    } while (iVar5 < param_5);
  }
  param_5 = param_2 + param_4 + param_5;
  if (param_6 != 0) {
    iVar5 = (*(code *)PTR_FUN_060dc0dc)(param_6);
    param_5 = iVar5 + param_5;
  }
  return param_5;
}



void FUN_060dc0e0(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)PTR_FUN_060dc100)(*(undefined4 *)(param_1 + 0x54),param_1,param_2,param_3);
  return;
}



int FUN_060dc134(undefined4 param_1,int param_2,char *param_3,undefined4 *param_4)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined *puVar7;
  code *pcVar8;
  char *pcVar9;
  undefined *puVar10;
  uint uVar11;
  int *piVar12;
  undefined *puVar13;
  undefined *puVar14;
  uint uVar15;
  int iVar16;
  undefined *puVar17;
  undefined auStack_e8 [132];
  int local_64;
  int local_60;
  char *local_5c;
  undefined4 *local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined *local_4c;
  int local_48;
  char local_41;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 *local_38;
  char *local_34;
  int local_30;
  undefined *local_2c;
  undefined2 *local_28;
  int *local_24;
  
  local_54 = 0;
  uVar15 = 0;
  puVar17 = (undefined *)0x0;
  piVar12 = (int *)(param_2 + 0x54);
  puVar13 = (undefined *)0xffffffff;
  if (*piVar12 == 0) {
    *piVar12 = *(int *)PTR_PTR_DAT_060dc454;
  }
  local_60 = param_2;
  local_5c = param_3;
  local_58 = param_4;
  if (*(int *)(*piVar12 + 0x5c) == 0) {
    (*(code *)PTR_FUN_060dc458)();
  }
  local_64 = *piVar12;
  local_38 = local_58 + -1;
  local_34 = local_5c + -1;
switchD_060dc29a_caseD_1:
LAB_060dc1c8:
  puVar10 = PTR_FUN_060dc45c;
  if (uVar15 == 0) {
    cVar1 = *local_5c;
    while ((iVar3 = (int)cVar1, iVar3 != 0 && (iVar3 != 0x25))) {
      local_34 = local_34 + 1;
      local_5c = local_5c + 1;
      iVar3 = (*(code *)puVar10)(iVar3,local_60);
      if (iVar3 == -1) {
        return -1;
      }
      local_54 = local_54 + 1;
      cVar1 = *local_5c;
    }
    local_2c = (undefined *)(int)*local_5c;
    if (local_2c == (undefined *)0x0) {
      return local_54;
    }
    uVar15 = 1;
    local_34 = local_34 + 1;
    local_5c = local_5c + 1;
  }
  pcVar9 = local_5c + 1;
  cVar1 = *local_5c;
  local_34 = local_34 + 1;
  local_5c = pcVar9;
  switch(cVar1) {
  case '\0':
    break;
  default:
    goto switchD_060dc29a_caseD_1;
  case ' ':
    uVar15 = uVar15 | 8;
    goto switchD_060dc29a_caseD_1;
  case '#':
    uVar15 = uVar15 | 0x10;
    goto switchD_060dc29a_caseD_1;
  case '%':
    puVar7 = (undefined *)0x1;
    puVar14 = (undefined *)0x0;
    puVar13 = PTR_DAT_060dcb7c;
    puVar10 = PTR_DAT_060dcb80;
    if (1 < (int)puVar17) {
      puVar14 = puVar17 + -1;
    }
    goto LAB_060dcb20;
  case '*':
    if ((uVar15 & 0x20) == 0) goto LAB_060dc48c;
    local_38 = local_38 + 1;
    local_58 = local_58 + 1;
    puVar13 = (undefined *)*local_38;
    goto switchD_060dc29a_caseD_1;
  case '+':
    uVar15 = uVar15 | 4;
    goto switchD_060dc29a_caseD_1;
  case '-':
    uVar15 = uVar15 | 2;
    goto switchD_060dc29a_caseD_1;
  case '.':
    uVar15 = uVar15 | 0x20;
    puVar13 = (undefined *)0x0;
    goto switchD_060dc29a_caseD_1;
  case '0':
    if (puVar17 != (undefined *)0x0) goto LAB_060dc3c6;
    if ((uVar15 & 0x20) != 0) goto switchD_060dc29a_caseD_31;
    uVar15 = uVar15 | 0x40;
    goto switchD_060dc29a_caseD_1;
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
switchD_060dc29a_caseD_31:
LAB_060dc3c6:
    if ((uVar15 & 0x20) == 0) {
      local_2c = (undefined *)((int)puVar17 * 10 + (int)*local_34);
      puVar17 = local_2c + -0x30;
    }
    else {
      local_2c = (undefined *)((int)puVar13 * 10 + (int)*local_34);
      puVar13 = local_2c + -0x30;
    }
    goto switchD_060dc29a_caseD_1;
  case 'E':
  case 'F':
  case 'G':
  case 'e':
  case 'f':
  case 'g':
    local_38 = local_38 + 2;
    local_40 = *local_58;
    uStack_3c = local_58[1];
    if ((puVar13 == (undefined *)0xffffffff) || ((int)puVar13 < 0)) {
      puVar13 = (undefined *)0x6;
    }
    local_2c = (undefined *)(int)*local_34;
    local_58 = local_58 + 2;
    local_30 = (*(code *)PTR_FUN_060dc9cc)
                         (local_64,auStack_e8,local_40,uStack_3c,puVar13,puVar17,local_2c,
                          uVar15 & 0x10);
    if (local_30 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = (*(code *)PTR_FUN_060dc9c4)(local_30);
    }
    iVar16 = 0;
    if (iVar5 < (int)puVar17) {
      iVar16 = (int)puVar17 - iVar5;
    }
    iVar3 = (*(code *)PTR_FUN_060dc9d4)
                      (local_40,uStack_3c,*(undefined4 *)PTR_DAT_060dc9d0,
                       *(undefined4 *)(PTR_DAT_060dc9d0 + 4));
    puVar13 = PTR_DAT_060dc9d8;
    if (((-1 < iVar3) && (puVar13 = PTR_DAT_060dc9dc, (uVar15 & 4) == 0)) &&
       (puVar13 = (undefined *)0x0, (uVar15 & 8) != 0)) {
      puVar13 = PTR_DAT_060dc9e0;
    }
    if ((iVar16 != 0) && (puVar13 != (undefined *)0x0)) {
      iVar3 = (*(code *)PTR_FUN_060dc9c4)(puVar13);
      iVar16 = iVar16 - iVar3;
    }
    iVar6 = 0;
    pcVar8 = (code *)PTR_FUN_060dc9c8;
    iVar3 = local_30;
    goto LAB_060dca62;
  case 'L':
    uVar15 = uVar15 | (int)DAT_060dc5c0;
    goto switchD_060dc29a_caseD_1;
  case 'X':
  case 'd':
  case 'i':
  case 'o':
  case 'u':
  case 'x':
    if (((int)DAT_060dc5c0 & uVar15) == 0) {
      if (((int)DAT_060dc5c2 & uVar15) == 0) {
        local_50 = local_38[1];
      }
      else {
        local_50 = local_38[1];
      }
      local_38 = local_38 + 1;
      local_58 = local_58 + 1;
      local_2c = (undefined *)(uint)(0 < (int)local_50);
      iVar3 = (int)local_2c - ((local_50 >> 0x10) * 2 >> 0x10);
    }
    else {
      local_38 = local_38 + 2;
      puVar4 = local_58 + 2;
      local_4c = (undefined *)*local_58;
      local_48 = local_58[1];
      iVar3 = 0;
      if ((0 < (int)local_4c) || ((local_4c == (undefined *)0x0 && (local_48 != 0)))) {
        iVar3 = 1;
      }
      local_58 = puVar4;
      local_2c = local_4c;
      if ((int)local_4c < 0) {
        iVar3 = iVar3 + -1;
      }
    }
    bVar2 = puVar13 == (undefined *)0xffffffff;
    if ((bVar2) || (uVar15 = uVar15 & 0xffffffbf, bVar2)) {
      puVar13 = (undefined *)(uint)bVar2;
    }
    local_41 = *local_34;
    if ((puVar13 != (undefined *)0x0) || (iVar3 != 0)) {
      if ((uVar15 & 0x80) == 0) {
        pcVar8 = (code *)PTR_FUN_060dc740;
        uVar11 = local_50;
        if (((int)DAT_060dc736 & uVar15) == 0) goto LAB_060dc69c;
        iVar5 = (*(code *)PTR_FUN_060dc73c)(auStack_e8,local_4c,local_48,(int)local_41);
      }
      else {
        pcVar8 = (code *)PTR_FUN_060dc738;
        uVar11 = (int)local_50._2_2_;
LAB_060dc69c:
        iVar5 = (*pcVar8)(auStack_e8,uVar11,(int)local_41);
      }
      if (iVar5 == 0) {
        iVar6 = 0;
      }
      else {
        local_30 = iVar5;
        iVar6 = (*(code *)PTR_FUN_060dc744)(iVar5);
        iVar5 = local_30;
      }
      iVar16 = 0;
      if (iVar6 < (int)puVar13) {
        iVar16 = (int)puVar13 - iVar6;
      }
      puVar13 = (undefined *)0x0;
      if (iVar6 + iVar16 < (int)puVar17) {
        puVar13 = puVar17 + (-iVar16 - iVar6);
      }
      if ((local_41 == 'd') || (local_41 == 'i')) {
        puVar17 = PTR_DAT_060dc748;
        if ((-1 < iVar3) &&
           ((puVar17 = PTR_DAT_060dc74c, (uVar15 & 4) == 0 &&
            (puVar17 = PTR_DAT_060dc750, (uVar15 & 8) == 0)))) goto LAB_060dc76a;
      }
      else if (((uVar15 & 0x10) == 0) ||
              (((puVar17 = PTR_DAT_060dc754, local_41 != 'o' &&
                (puVar17 = PTR_DAT_060dc758, local_41 != 'x')) &&
               (puVar17 = PTR_DAT_060dc9c0, local_41 != 'X')))) {
LAB_060dc76a:
        puVar17 = (undefined *)0x0;
      }
      if ((puVar13 != (undefined *)0x0) && (puVar17 != (undefined *)0x0)) {
        local_30 = iVar5;
        iVar3 = (*(code *)PTR_FUN_060dc9c4)(puVar17);
        puVar13 = puVar13 + -iVar3;
        iVar5 = local_30;
      }
      iVar3 = (*(code *)PTR_FUN_060dc9c8)(iVar5,iVar6,uVar15,iVar16,puVar13,puVar17,local_60);
      if (iVar3 == -1) {
        return -1;
      }
      uVar15 = 0;
      puVar17 = (undefined *)0x0;
      puVar13 = (undefined *)0xffffffff;
      local_54 = local_54 + iVar3;
      goto switchD_060dc29a_caseD_1;
    }
    break;
  case 'c':
    puVar10 = auStack_e8 + DAT_060dc9be;
    puVar14 = (undefined *)0x0;
    local_38 = local_38 + 1;
    local_2c = (undefined *)((int)local_58 + 3);
    puVar7 = (undefined *)0x1;
    local_58 = local_58 + 1;
    *puVar10 = *local_2c;
    puVar13 = PTR_DAT_060dc9e8;
    if (1 < (int)puVar17) {
      puVar14 = puVar17 + -1;
    }
    goto LAB_060dcb20;
  case 'h':
    uVar15 = uVar15 | 0x80;
    goto switchD_060dc29a_caseD_1;
  case 'l':
    uVar15 = uVar15 | (int)DAT_060dc5be;
    goto switchD_060dc29a_caseD_1;
  case 'n':
    if ((uVar15 & 0x80) == 0) {
      local_38 = local_38 + 1;
      local_58 = local_58 + 1;
      local_24 = (int *)*local_38;
      *local_24 = local_54;
    }
    else {
      local_38 = local_38 + 1;
      local_58 = local_58 + 1;
      local_28 = (undefined2 *)*local_38;
      *local_28 = local_54._2_2_;
    }
    break;
  case 'p':
    local_38 = local_38 + 1;
    local_58 = local_58 + 1;
    iVar3 = (*(code *)PTR_FUN_060dcb6c)(auStack_e8,*local_38,0x78);
    if (iVar3 == 0) {
      iVar5 = 0;
    }
    else {
      local_30 = iVar3;
      iVar5 = (*(code *)PTR_FUN_060dcb70)(iVar3);
      iVar3 = local_30;
    }
    iVar6 = 0;
    if (iVar5 < 8) {
      iVar6 = 8 - iVar5;
    }
    uVar15 = 0x40;
    iVar16 = 0;
    pcVar8 = (code *)PTR_FUN_060dcb78;
    puVar13 = PTR_DAT_060dcb74;
LAB_060dca62:
    iVar3 = (*pcVar8)(iVar3,iVar5,uVar15,iVar6,iVar16,puVar13,local_60);
    if (iVar3 == -1) {
      return -1;
    }
    uVar15 = 0;
    puVar17 = (undefined *)0x0;
    puVar13 = (undefined *)0xffffffff;
    local_54 = local_54 + iVar3;
    goto switchD_060dc29a_caseD_1;
  case 's':
    local_38 = local_38 + 1;
    local_58 = local_58 + 1;
    puVar10 = (undefined *)*local_38;
    if ((undefined *)*local_38 == (undefined *)0x0) {
      puVar10 = PTR_s__null__060dc9e4;
    }
    puVar7 = (undefined *)(*(code *)PTR_FUN_060dc9c4)(puVar10);
    puVar14 = puVar7;
    if ((puVar13 == (undefined *)0xffffffff) || (puVar14 = puVar13, (int)puVar13 < (int)puVar7)) {
      puVar7 = puVar14;
    }
    puVar14 = (undefined *)0x0;
    puVar13 = PTR_DAT_060dc9e8;
    if ((int)puVar7 < (int)puVar17) {
      puVar14 = puVar17 + -(int)puVar7;
    }
LAB_060dcb20:
    iVar3 = (*(code *)PTR_FUN_060dcb78)(puVar10,puVar7,uVar15,0,puVar14,puVar13,local_60);
    if (iVar3 == -1) {
      return -1;
    }
    uVar15 = 0;
    puVar17 = (undefined *)0x0;
    puVar13 = (undefined *)0xffffffff;
    local_54 = local_54 + iVar3;
    goto switchD_060dc29a_caseD_1;
  }
  uVar15 = 0;
  puVar17 = (undefined *)0x0;
  puVar13 = (undefined *)0xffffffff;
  goto switchD_060dc29a_caseD_1;
LAB_060dc48c:
  local_38 = local_38 + 1;
  local_58 = local_58 + 1;
  puVar17 = (undefined *)*local_38;
  if ((int)puVar17 < 0) goto LAB_060dc4b6;
  goto LAB_060dc1c8;
LAB_060dc4b6:
  uVar15 = uVar15 | 2;
  puVar17 = (undefined *)-(int)puVar17;
  goto switchD_060dc29a_caseD_1;
}



void FUN_060dcb84(undefined4 param_1,int *param_2)

{
  if (*param_2 != 0) {
    (*(code *)PTR_FUN_060dcbb4)();
  }
  (*(code *)PTR_FUN_060dcbb8)(param_1,param_2);
  return;
}



void FUN_060dcc84(undefined4 param_1,undefined4 param_2)

{
  undefined4 *local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uStack_14 = param_1;
  uStack_18 = (*(code *)PTR_FUN_060dccb8)();
  local_20 = &uStack_14;
  uStack_1c = 1;
  uStack_10 = uStack_18;
  (*(code *)PTR_FUN_060dccbc)(param_2,&local_20);
  return;
}



uint FUN_060dccc0(undefined param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  byte *pbVar3;
  
  iVar2 = param_2[2] + -1;
  param_2[2] = iVar2;
  if (iVar2 < 0) {
    if (iVar2 < (int)param_2[6]) {
      uVar1 = (*(code *)PTR_FUN_060dcd14)();
      return uVar1;
    }
    *(undefined *)*param_2 = param_1;
    pbVar3 = (byte *)*param_2;
    if (*pbVar3 == 10) {
      uVar1 = (*(code *)PTR_FUN_060dcd14)(10);
      return uVar1;
    }
  }
  else {
    *(undefined *)*param_2 = param_1;
    pbVar3 = (byte *)*param_2;
  }
  *param_2 = pbVar3 + 1;
  return (uint)*pbVar3;
}



void FUN_060dcd18(undefined4 *param_1,undefined2 param_2,undefined2 param_3,undefined4 param_4)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  *(undefined2 *)(param_1 + 3) = param_2;
  *(undefined2 *)((int)param_1 + 0xe) = param_3;
  param_1[4] = 0;
  param_1[6] = 0;
  param_1[7] = param_1;
  param_1[8] = PTR_LAB_060dcd50;
  param_1[9] = PTR_LAB_060dcd54;
  param_1[10] = PTR_LAB_060dcd58;
  param_1[0xb] = PTR_LAB_060dcd5c;
  param_1[0x15] = param_4;
  return;
}



void FUN_060dcea0(int param_1)

{
  undefined *puVar1;
  int iVar2;
  
  *(undefined **)(param_1 + 0x60) = PTR_LAB_060dcf1c;
  *(undefined4 *)(param_1 + 0x5c) = 1;
  puVar1 = PTR_FUN_060dcf20;
  iVar2 = (int)DAT_060dcf0e;
  (*(code *)PTR_FUN_060dcf20)(param_1 + iVar2,4,0,param_1);
  (*(code *)puVar1)(param_1 + DAT_060dcf10,8,1,param_1);
  (*(code *)puVar1)(param_1 + DAT_060dcf12,10,2,param_1);
  *(undefined4 *)(param_1 + DAT_060dcf14) = 0;
  *(undefined4 *)(param_1 + DAT_060dcf16) = 3;
  *(int *)(param_1 + DAT_060dcf18) = param_1 + iVar2;
  return;
}



int FUN_060dcf5c(int param_1,int param_2,int param_3,char param_4)

{
  uint uVar1;
  uint uVar2;
  int extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined8 uVar8;
  longlong lVar9;
  undefined4 uStack_34;
  
  lVar9 = CONCAT44(param_3,param_2);
  *(undefined *)(param_1 + 0x7f) = 0;
  iVar3 = 0x7e;
  switch(param_4) {
  case 'X':
  case 'o':
  case 'u':
  case 'x':
    if (param_4 == 'u') {
      uStack_34 = 10;
    }
    else {
      uStack_34 = 0x10;
      if (param_4 == 'o') {
        uStack_34 = 8;
      }
    }
    puVar7 = (undefined *)(param_1 + 0x7e);
    do {
      uVar5 = (undefined4)((ulonglong)lVar9 >> 0x20);
      uVar4 = (undefined4)lVar9;
      if (param_4 == 'X') {
        (*(code *)PTR_FUN_060dd188)(uVar4,uVar5,0,uStack_34);
        *puVar7 = PTR_s_0123456789ABCDEF_060dd18c[extraout_r1_00];
      }
      else {
        (*(code *)PTR_FUN_060dd188)(uVar4,uVar5,0,uStack_34);
        *puVar7 = PTR_s_0123456789abcdef_060dd184[extraout_r1_01];
      }
      puVar7 = puVar7 + -1;
      iVar3 = iVar3 + -1;
      lVar9 = (*(code *)PTR_FUN_060dd190)(uVar4,uVar5,0,uStack_34);
      if (lVar9 == 0) goto LAB_060dd158;
    } while (-1 < iVar3);
  default:
    break;
  case 'd':
  case 'i':
    if (param_2 < 0) {
      if ((param_2 == DAT_060dd174) && (param_3 == 0)) {
        uVar4 = *(undefined4 *)PTR_DAT_060dd178;
        uVar5 = *(undefined4 *)(PTR_DAT_060dd178 + 4);
        uVar8 = (*(code *)PTR_FUN_060dd17c)(uVar4,uVar5,0,10);
        iVar3 = (int)((ulonglong)uVar8 >> 0x20) + 1;
        lVar9 = (*(code *)PTR_FUN_060dd180)(uVar4,uVar5,0,10);
        uVar2 = (uint)((ulonglong)lVar9 >> 0x20);
        if (((int)uVar8 + (uint)(iVar3 == 0) == 0) && (iVar3 == 10)) {
          uVar1 = uVar2 + 1;
          lVar9 = CONCAT44(uVar1,(int)lVar9 + (uint)(uVar1 < uVar2));
          iVar3 = 0;
        }
        *(undefined *)(param_1 + 0x7e) = PTR_s_0123456789abcdef_060dd184[iVar3];
        iVar3 = 0x7d;
      }
      else {
        lVar9 = CONCAT44(-param_3,-(uint)(-param_3 != 0) - param_2);
      }
    }
    puVar7 = PTR_FUN_060dd180;
    if (-1 < iVar3) {
      puVar6 = (undefined *)(param_1 + iVar3);
      do {
        uVar4 = (undefined4)((ulonglong)lVar9 >> 0x20);
        (*(code *)PTR_FUN_060dd17c)((int)lVar9,uVar4,0,10);
        *puVar6 = PTR_s_0123456789abcdef_060dd184[extraout_r1];
        puVar6 = puVar6 + -1;
        iVar3 = iVar3 + -1;
        lVar9 = (*(code *)puVar7)((int)lVar9,uVar4,0,10);
        if (lVar9 == 0) break;
      } while (-1 < iVar3);
    }
  }
LAB_060dd158:
  return param_1 + iVar3 + 1;
}



int FUN_060dd194(int param_1,int param_2,char param_3)

{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  undefined uVar4;
  undefined *extraout_r2;
  undefined *extraout_r2_00;
  undefined *puVar5;
  code *pcVar6;
  code *extraout_r3;
  code *extraout_r3_00;
  code *extraout_r3_01;
  int iVar7;
  int iVar8;
  undefined *puVar9;
  
  *(undefined *)(param_1 + 0x7f) = 0;
  iVar7 = 0x7e;
  switch(param_3) {
  case 'X':
  case 'o':
  case 'u':
  case 'x':
    pcVar6 = (code *)PTR_FUN_060dd300;
    if (param_3 == 'u') {
      iVar8 = 10;
    }
    else {
      iVar8 = 0x10;
      if (param_3 == 'o') {
        iVar8 = 8;
      }
    }
    do {
      if (param_3 == 'X') {
        iVar3 = (*pcVar6)(param_2,iVar8);
        uVar4 = PTR_s_0123456789ABCDEF_060dd304[param_2 - iVar3 * iVar8];
        puVar5 = extraout_r2;
        pcVar6 = extraout_r3;
      }
      else {
        iVar3 = (*pcVar6)(param_2,iVar8);
        uVar4 = PTR_s_0123456789abcdef_060dd2fc[param_2 - iVar3 * iVar8];
        puVar5 = extraout_r2_00;
        pcVar6 = extraout_r3_00;
      }
      iVar7 = iVar7 + -1;
      *puVar5 = uVar4;
      param_2 = (*pcVar6)(param_2,iVar8);
    } while ((param_2 != 0) && (pcVar6 = extraout_r3_01, -1 < iVar7));
  default:
switchD_060dd1ca_caseD_59:
    break;
  case 'd':
  case 'i':
    if ((param_2 < 0) && (bVar1 = param_2 == DAT_060dd2ec, param_2 = -param_2, bVar1)) {
      param_2 = (*(code *)PTR_FUN_060dd2f4)(DAT_060dd2f0,10);
      *(undefined *)(iVar7 + param_1) = *PTR_s_89abcdef_060dd2f8;
      iVar7 = iVar7 + -1;
    }
    puVar2 = PTR_s_0123456789abcdef_060dd2fc;
    puVar5 = PTR_FUN_060dd2f4;
    if (-1 < iVar7) {
      puVar9 = (undefined *)(iVar7 + param_1);
      do {
        iVar8 = (*(code *)puVar5)(param_2,10);
        iVar7 = iVar7 + -1;
        *puVar9 = puVar2[param_2 + iVar8 * -10];
        puVar9 = puVar9 + -1;
        param_2 = (*(code *)puVar5)();
        if (param_2 == 0) goto switchD_060dd1ca_caseD_59;
      } while (-1 < iVar7);
    }
  }
  return param_1 + iVar7 + 1;
}



int FUN_060dd308(int param_1,short param_2,char param_3)

{
  undefined uVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined *puVar7;
  
  *(undefined *)(param_1 + 0x7f) = 0;
  puVar7 = PTR_FUN_060dd44c;
  puVar2 = PTR_s_0123456789abcdef_060dd448;
  iVar4 = 0x7e;
  switch(param_3) {
  case 'X':
  case 'o':
  case 'u':
  case 'x':
    if (param_3 == 'u') {
      iVar6 = 10;
    }
    else {
      iVar6 = 0x10;
      if (param_3 == 'o') {
        iVar6 = 8;
      }
    }
    puVar2 = (undefined *)(param_1 + 0x7e);
    do {
      iVar3 = (int)param_2;
      if (param_3 == 'X') {
        iVar5 = (*(code *)puVar7)(iVar3,iVar6);
        uVar1 = PTR_s_0123456789ABCDEF_060dd450[iVar3 - iVar5 * iVar6];
      }
      else {
        iVar5 = (*(code *)puVar7)(iVar3,iVar6);
        uVar1 = PTR_s_0123456789abcdef_060dd448[iVar3 - iVar5 * iVar6];
      }
      iVar4 = iVar4 + -1;
      *puVar2 = uVar1;
      puVar2 = puVar2 + -1;
      param_2 = (*(code *)puVar7)((int)param_2,iVar6);
    } while ((param_2 != 0) && (-1 < iVar4));
  default:
switchD_060dd33c_caseD_59:
    iVar5 = iVar4 + 1;
    break;
  case 'd':
  case 'i':
    if (param_2 < 0) {
      param_2 = -param_2;
    }
    puVar7 = (undefined *)(param_1 + 0x7e);
    do {
      iVar5 = iVar4;
      iVar3 = (int)param_2;
      iVar6 = (*(code *)PTR_FUN_060dd44c)(iVar3,10);
      iVar4 = iVar5 + -1;
      *puVar7 = puVar2[iVar3 + iVar6 * -10];
      param_2 = (short)iVar6;
      puVar7 = puVar7 + -1;
      if (param_2 == 0) goto switchD_060dd33c_caseD_59;
    } while (-1 < iVar4);
  }
  return param_1 + iVar5;
}



void FUN_060dd454(undefined4 param_1,char *param_2,undefined4 param_3,undefined4 param_4,int param_5
                 ,undefined4 param_6,int param_7,undefined4 param_8)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int local_20;
  undefined auStack_1c [4];
  undefined auStack_18 [8];
  
  pcVar2 = (char *)(*(code *)PTR_FUN_060dd554)
                             (param_1,param_3,param_4,param_8,param_5,&local_20,auStack_1c,
                              auStack_18);
  if (local_20 == DAT_060dd550) {
    (*(code *)PTR_FUN_060dd558)(param_2,pcVar2);
  }
  else {
    cVar1 = *pcVar2;
    pcVar3 = pcVar2;
    while (cVar1 != '\0') {
      if (local_20 < 1) goto LAB_060dd4d6;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
      *param_2 = cVar1;
      local_20 = local_20 + -1;
      param_2 = param_2 + 1;
      cVar1 = *pcVar3;
    }
    for (; 0 < local_20; local_20 = local_20 + -1) {
      *param_2 = '0';
      param_2 = param_2 + 1;
    }
LAB_060dd4d6:
    if ((param_7 != 0) || (*pcVar3 != '\0')) {
      if (pcVar3 == pcVar2) {
        *param_2 = '0';
        param_2 = param_2 + 1;
      }
      *param_2 = '.';
      for (; (param_2 = param_2 + 1, local_20 < 0 && (0 < param_5)); param_5 = param_5 + -1) {
        *param_2 = '0';
        local_20 = local_20 + 1;
      }
      cVar1 = *pcVar3;
      while (cVar1 != '\0') {
        if (param_5 < 1) goto LAB_060dd53e;
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
        param_5 = param_5 + -1;
        *param_2 = cVar1;
        param_2 = param_2 + 1;
        cVar1 = *pcVar3;
      }
      for (; 0 < param_5; param_5 = param_5 + -1) {
        *param_2 = '0';
        param_2 = param_2 + 1;
      }
    }
LAB_060dd53e:
    *param_2 = '\0';
  }
  return;
}



void FUN_060dd55c(undefined4 param_1,undefined *param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,char param_6,int param_7)

{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  undefined4 local_24;
  undefined auStack_20 [4];
  undefined auStack_1c [8];
  
  puVar2 = (undefined *)
           (*(code *)PTR_FUN_060dd6a0)
                     (param_1,param_3,param_4,2,param_5 + 1,&local_24,auStack_20,auStack_1c);
  if (local_24 == (int)DAT_060dd69c) {
    (*(code *)PTR_FUN_060dd6a4)(param_2,puVar2);
  }
  else {
    pcVar4 = puVar2 + 1;
    *param_2 = *puVar2;
    pcVar5 = param_2 + 1;
    if ((param_7 != 0) || (param_5 != 0)) {
      *pcVar5 = '.';
      pcVar5 = param_2 + 2;
    }
    cVar1 = *pcVar4;
    for (; (cVar1 != '\0' && (0 < param_5)); param_5 = param_5 + -1) {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      *pcVar5 = cVar1;
      cVar1 = *pcVar4;
      pcVar5 = pcVar5 + 1;
    }
    if (param_6 == 'g') {
      param_6 = 'e';
    }
    else if (param_6 == 'G') {
      param_6 = 'E';
    }
    else {
      for (; 0 < param_5; param_5 = param_5 + -1) {
        *pcVar5 = '0';
        pcVar5 = pcVar5 + 1;
      }
    }
    *pcVar5 = param_6;
    local_24 = local_24 - 1;
    if ((int)local_24 < 0) {
      pcVar5[1] = '-';
      local_24 = -local_24;
    }
    else {
      pcVar5[1] = '+';
    }
    pcVar4 = pcVar5 + 2;
    if (99 < (int)local_24) {
      iVar3 = (int)((longlong)(int)local_24 * (longlong)DAT_060dd6a8 >> 0x25) +
              (uint)((local_24 & 0x80000000) != 0);
      *pcVar4 = (char)iVar3 + '0';
      pcVar4 = pcVar5 + 3;
      local_24 = local_24 + iVar3 * -100;
    }
    cVar1 = (char)(int)((longlong)(int)local_24 * (longlong)DAT_060dd6ac >> 0x22) +
            ((local_24 & 0x80000000) != 0);
    *pcVar4 = cVar1 + '0';
    local_24._3_1_ = (char)local_24 + cVar1 * -10;
    pcVar4[1] = (char)local_24 + '0';
    pcVar4[2] = '\0';
  }
  return;
}



char * FUN_060dd8ac(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                   char *param_5,char param_6,int param_7)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  int local_3c;
  undefined auStack_38 [4];
  undefined auStack_34 [4];
  undefined4 uStack_30;
  char local_29;
  int iStack_28;
  char *pcStack_24;
  
  uVar7 = CONCAT44(param_3,param_2);
  iStack_28 = param_7;
  local_29 = param_6;
  pcStack_24 = param_5;
  uStack_30 = param_1;
  iVar2 = (*(code *)PTR_FUN_060dda9c)
                    (param_2,param_3,*(undefined4 *)PTR_DAT_060dda98,
                     *(undefined4 *)(PTR_DAT_060dda98 + 4));
  if (iVar2 < 0) {
    uVar7 = (*(code *)PTR_FUN_060ddaa0)(param_2,param_3);
  }
  uVar6 = (undefined4)((ulonglong)uVar7 >> 0x20);
  uVar5 = (undefined4)uVar7;
  iVar2 = (*(code *)PTR_FUN_060ddaa4)
                    (uVar5,uVar6,*(undefined4 *)PTR_DAT_060dda98,
                     *(undefined4 *)(PTR_DAT_060dda98 + 4));
  if (iVar2 == 0) {
    *pcStack_24 = '0';
    param_5 = pcStack_24 + 1;
LAB_060dda7a:
    *param_5 = '\0';
  }
  else {
    iVar2 = (*(code *)PTR_FUN_060ddaac)
                      (uVar5,uVar6,*(undefined4 *)PTR_DAT_060ddaa8,
                       *(undefined4 *)(PTR_DAT_060ddaa8 + 4));
    if (0 < iVar2) {
      uVar7 = (*(code *)PTR_FUN_060ddab0)(param_4);
      iVar2 = (*(code *)PTR_FUN_060ddab4)(uVar5,uVar6,(int)uVar7,(int)((ulonglong)uVar7 >> 0x20));
      if (iVar2 < 0) {
        iVar2 = (*(code *)PTR_FUN_060dda9c)
                          (uVar5,uVar6,*(undefined4 *)PTR_DAT_060ddabc,
                           *(undefined4 *)(PTR_DAT_060ddabc + 4));
        if (iVar2 < 0) {
          uVar4 = 3;
        }
        else {
          uVar4 = 2;
        }
        pcVar3 = (char *)(*(code *)PTR_FUN_060ddac0)
                                   (uStack_30,uVar5,uVar6,uVar4,param_4,&local_3c,auStack_38,
                                    auStack_34);
        if (local_3c == DAT_060dda94) {
          (*(code *)PTR_FUN_060ddac4)(param_5,pcVar3);
          return pcStack_24;
        }
        cVar1 = *pcVar3;
        while (cVar1 != '\0') {
          if (local_3c < 1) goto LAB_060dda08;
          cVar1 = *pcVar3;
          pcVar3 = pcVar3 + 1;
          *param_5 = cVar1;
          param_4 = param_4 + -1;
          local_3c = local_3c + -1;
          param_5 = param_5 + 1;
          cVar1 = *pcVar3;
        }
        for (; (0 < local_3c && (0 < param_4)); param_4 = param_4 + -1) {
          *param_5 = '0';
          param_5 = param_5 + 1;
          local_3c = local_3c + -1;
        }
LAB_060dda08:
        if ((iStack_28 != 0) || (*pcVar3 != '\0')) {
          if (param_5 == pcStack_24) {
            *param_5 = '0';
            param_5 = param_5 + 1;
          }
          *param_5 = '.';
          for (; (param_5 = param_5 + 1, local_3c < 0 && (0 < param_4)); param_4 = param_4 + -1) {
            *param_5 = '0';
            local_3c = local_3c + 1;
          }
          cVar1 = *pcVar3;
          for (; (cVar1 != '\0' && (0 < param_4)); param_4 = param_4 + -1) {
            cVar1 = *pcVar3;
            pcVar3 = pcVar3 + 1;
            *param_5 = cVar1;
            cVar1 = *pcVar3;
            param_5 = param_5 + 1;
          }
          if (iStack_28 != 0) {
            for (; 0 < param_4; param_4 = param_4 + -1) {
              *param_5 = '0';
              param_5 = param_5 + 1;
            }
          }
        }
        goto LAB_060dda7a;
      }
    }
    (*(code *)PTR_FUN_060ddab8)
              (uStack_30,pcStack_24,uVar5,uVar6,param_4 + -1,(int)local_29,iStack_28);
  }
  return pcStack_24;
}



undefined4
FUN_060ddac8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            uint param_5,undefined4 param_6,char param_7,undefined4 param_8)

{
  undefined4 uVar1;
  
  switch(param_7) {
  case 'E':
  case 'e':
    (*(code *)PTR_FUN_060ddbac)(param_1,param_2,param_3,param_4,param_5,(int)param_7,param_8);
  default:
    break;
  case 'F':
  case 'f':
    uVar1 = 1;
    if (param_5 == 0) {
      uVar1 = param_8;
    }
    (*(code *)PTR_FUN_060ddba4)(param_1,param_2,param_3,param_4,param_5,(int)param_7,uVar1,3);
    break;
  case 'G':
  case 'g':
    if (param_5 == 0) {
      param_5 = (uint)(param_5 == 0);
    }
    (*(code *)PTR_FUN_060ddba8)(param_1,param_3,param_4,param_5,param_2,(int)param_7,param_8);
  }
  return param_2;
}



void FUN_060ddbb0(int param_1,int param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int *piVar7;
  int iVar8;
  
  puVar1 = PTR_FUN_060ddc74;
  piVar7 = (int *)(param_2 * 4 + param_1 + (int)DAT_060ddc6c);
  if (*piVar7 == 0) {
    uVar3 = (*(code *)PTR_FUN_060ddc74)(param_1,0);
    iVar8 = 0xb;
    if (((int)DAT_060ddc6e & uVar3) != 0) {
      (*(code *)puVar1)(param_1,(int)DAT_060ddc70 - ((int)DAT_060ddc6e & uVar3));
    }
    puVar2 = PTR_FUN_060ddc78;
    if (8 < param_2) {
      iVar8 = param_2 + 3;
    }
    iVar4 = (*(code *)PTR_FUN_060ddc78)(1,(iVar8 + -3) - param_2);
    if (iVar8 < param_2) {
      iVar8 = param_2;
    }
    uVar5 = (*(code *)puVar2)(1,iVar8);
    puVar6 = (undefined4 *)(*(code *)puVar1)(param_1,uVar5);
    if (puVar6 != (undefined4 *)0xffffffff) {
      if (((uint)puVar6 & 7) != 0) {
        puVar6 = (undefined4 *)((int)puVar6 - ((uint)puVar6 & 7));
        iVar4 = iVar4 + -1;
      }
      *piVar7 = (int)puVar6;
      iVar8 = (*(code *)puVar2)(1,param_2 + 3);
      while (iVar4 = iVar4 + -1, 0 < iVar4) {
        *puVar6 = (undefined4 *)((int)puVar6 + iVar8);
        puVar6 = (undefined4 *)((int)puVar6 + iVar8);
      }
      *puVar6 = 0;
    }
  }
  return;
}



int * FUN_060ddc7c(int param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar3 = 0;
  for (uVar2 = (param_2 + 7U & 0xfffffffc) - 1 >> 3; uVar2 != 0; uVar2 = uVar2 >> 1) {
    iVar3 = iVar3 + 1;
  }
  iVar5 = iVar3 * 4 + param_1;
  piVar4 = (int *)(iVar5 + DAT_060ddcf6);
  if (*piVar4 == 0) {
    (*(code *)PTR_FUN_060ddcfc)(param_1,iVar3);
  }
  piVar1 = (int *)*piVar4;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    *piVar4 = *piVar1;
    *(undefined *)piVar1 = 0xff;
    *(char *)((int)piVar1 + 1) = (char)iVar3;
    piVar4 = (int *)(iVar5 + DAT_060ddcf8);
    piVar1 = piVar1 + 1;
    *piVar4 = *piVar4 + 1;
  }
  return piVar1;
}



void FUN_060ddd00(int param_1,int param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  char *pcVar3;
  
  if ((param_2 != 0) && (pcVar3 = (char *)(param_2 + -4), *pcVar3 == -1)) {
    param_1 = *(char *)(param_2 + -3) * 4 + param_1;
    puVar1 = (undefined4 *)(DAT_060ddd36 + param_1);
    *(undefined4 *)pcVar3 = *puVar1;
    *puVar1 = pcVar3;
    piVar2 = (int *)(param_1 + DAT_060ddd38);
    *piVar2 = *piVar2 + -1;
  }
  return;
}



undefined4 FUN_060ddeb8(uint *param_1,undefined4 *param_2)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int unaff_r11;
  int *piVar8;
  uint unaff_r13;
  uint uVar9;
  
  if (param_2[2] != 0) {
    if ((((*(ushort *)(param_1 + 3) & 8) == 0) || (param_1[4] == 0)) &&
       (iVar4 = (*(code *)PTR_FUN_060ddfec)(param_1), iVar4 != 0)) {
      return 0xffffffff;
    }
    puVar2 = PTR_FUN_060ddff0;
    uVar7 = 0;
    piVar8 = (int *)*param_2;
    if ((*(ushort *)(param_1 + 3) & 2) != 0) {
      uVar9 = (uint)DAT_060ddfe8;
      bVar1 = true;
      do {
        if (bVar1) {
          unaff_r11 = *piVar8;
          uVar7 = piVar8[1];
          piVar8 = piVar8 + 2;
        }
        else {
          uVar6 = uVar7;
          if (uVar9 < uVar7) {
            uVar6 = uVar9;
          }
          iVar4 = (*(code *)param_1[9])(param_1[7],unaff_r11,uVar6);
          if (iVar4 < 1) goto LAB_060de0f6;
          unaff_r11 = unaff_r11 + iVar4;
          iVar5 = param_2[2];
          uVar7 = uVar7 - iVar4;
          param_2[2] = iVar5 - iVar4;
          if (iVar5 - iVar4 == 0) {
            return 0;
          }
        }
        bVar1 = uVar7 == 0;
      } while( true );
    }
    if ((*(ushort *)(param_1 + 3) & 1) == 0) {
      bVar1 = true;
      do {
        if (bVar1) {
          unaff_r11 = *piVar8;
          uVar7 = piVar8[1];
          piVar8 = piVar8 + 2;
        }
        else {
          uVar9 = param_1[2];
          if ((*(ushort *)(param_1 + 3) & 0x200) == 0) {
            if ((param_1[4] < *param_1) && (uVar9 < uVar7)) {
              (*(code *)puVar2)(*param_1,unaff_r11,uVar9);
              puVar3 = PTR_FUN_060ddff4;
              *param_1 = *param_1 + uVar9;
              iVar4 = (*(code *)puVar3)(param_1);
              if (iVar4 != 0) goto LAB_060de0f6;
            }
            else if (uVar7 < param_1[5]) {
              (*(code *)puVar2)(*param_1,unaff_r11,uVar7);
              param_1[2] = param_1[2] - uVar7;
              *param_1 = *param_1 + uVar7;
              uVar9 = uVar7;
            }
            else {
              uVar9 = (*(code *)param_1[9])(param_1[7],unaff_r11,param_1[5]);
              if ((int)uVar9 < 1) goto LAB_060de0f6;
            }
          }
          else {
            if (uVar7 < uVar9) {
              uVar9 = uVar7;
            }
            (*(code *)puVar2)(*param_1,unaff_r11,uVar9);
            param_1[2] = param_1[2] - uVar9;
            *param_1 = *param_1 + uVar9;
            uVar9 = uVar7;
          }
          unaff_r11 = unaff_r11 + uVar9;
          iVar4 = param_2[2];
          uVar7 = uVar7 - uVar9;
          param_2[2] = iVar4 - uVar9;
          if (iVar4 - uVar9 == 0) {
            return 0;
          }
        }
        bVar1 = uVar7 == 0;
      } while( true );
    }
    bVar1 = false;
    do {
      if (uVar7 == 0) {
        bVar1 = false;
        do {
          unaff_r11 = *piVar8;
          uVar7 = piVar8[1];
          piVar8 = piVar8 + 2;
        } while (uVar7 == 0);
      }
      if (!bVar1) {
        iVar4 = (*(code *)PTR_FUN_060de118)(unaff_r11,10,uVar7);
        if (iVar4 == 0) {
          unaff_r13 = uVar7 + 1;
        }
        else {
          unaff_r13 = iVar4 - (unaff_r11 + -1);
        }
        bVar1 = true;
      }
      uVar9 = unaff_r13;
      if (uVar7 < unaff_r13) {
        uVar9 = uVar7;
      }
      uVar6 = param_1[2] + param_1[5];
      if ((param_1[4] < *param_1) && ((int)uVar6 < (int)uVar9)) {
        (*(code *)PTR_FUN_060de11c)(*param_1,unaff_r11,uVar6);
        puVar2 = PTR_FUN_060de120;
        *param_1 = *param_1 + uVar6;
        iVar4 = (*(code *)puVar2)(param_1);
        if (iVar4 != 0) goto LAB_060de0f6;
        unaff_r13 = unaff_r13 - uVar6;
        uVar9 = uVar6;
      }
      else if ((int)uVar9 < (int)param_1[5]) {
        (*(code *)PTR_FUN_060de11c)(*param_1,unaff_r11,uVar9);
        param_1[2] = param_1[2] - uVar9;
        *param_1 = *param_1 + uVar9;
        unaff_r13 = unaff_r13 - uVar9;
      }
      else {
        uVar9 = (*(code *)param_1[9])(param_1[7],unaff_r11,param_1[5]);
        if ((int)uVar9 < 1) {
LAB_060de0f6:
          *(ushort *)(param_1 + 3) = *(ushort *)(param_1 + 3) | 0x40;
          return 0xffffffff;
        }
        unaff_r13 = unaff_r13 - uVar9;
      }
      unaff_r11 = unaff_r11 + uVar9;
      if (unaff_r13 == 0) {
        iVar4 = (*(code *)PTR_FUN_060de120)(param_1);
        if (iVar4 != 0) goto LAB_060de0f6;
        bVar1 = false;
      }
      iVar4 = param_2[2];
      uVar7 = uVar7 - uVar9;
      param_2[2] = iVar4 - uVar9;
    } while (iVar4 - uVar9 != 0);
  }
  return 0;
}



uint FUN_060de124(byte param_1,int *param_2)

{
  int iVar1;
  byte *pbVar2;
  int *piVar3;
  uint uVar4;
  
  piVar3 = param_2 + 0x15;
  if (*piVar3 == 0) {
    *piVar3 = *(int *)PTR_PTR_DAT_060de1dc;
  }
  if (*(int *)(*piVar3 + 0x5c) == 0) {
    (*(code *)PTR_FUN_060de1e0)();
  }
  param_2[2] = param_2[6];
  if ((((*(ushort *)(param_2 + 3) & 8) == 0) || (param_2[4] == 0)) &&
     (iVar1 = (*(code *)PTR_FUN_060de1e4)(param_2), iVar1 != 0)) {
    return 0xffffffff;
  }
  iVar1 = *param_2 - param_2[4];
  uVar4 = (uint)param_1;
  if (param_2[5] <= iVar1) {
    iVar1 = (*(code *)PTR_FUN_060de1e8)(param_2);
    if (iVar1 != 0) {
      return 0xffffffff;
    }
    iVar1 = 0;
  }
  pbVar2 = (byte *)*param_2;
  param_2[2] = param_2[2] + -1;
  *param_2 = (int)(pbVar2 + 1);
  *pbVar2 = param_1;
  if (iVar1 + 1 != param_2[5]) {
    if ((*(ushort *)(param_2 + 3) & 1) == 0) {
      return uVar4;
    }
    if (uVar4 != 10) {
      return uVar4;
    }
  }
  iVar1 = (*(code *)PTR_FUN_060de1e8)(param_2);
  if (iVar1 == 0) {
    return uVar4;
  }
  return 0xffffffff;
}



undefined4 FUN_060de320(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  if (param_1 == (int *)0x0) {
    uVar1 = (*(code *)PTR_FUN_060de3d0)(*(undefined4 *)PTR_PTR_DAT_060de3cc,PTR_FUN_060de3c8);
  }
  else {
    piVar3 = param_1 + 0x15;
    if (*piVar3 == 0) {
      *piVar3 = *(int *)PTR_PTR_DAT_060de3cc;
    }
    if (*(int *)(*piVar3 + 0x5c) == 0) {
      (*(code *)PTR_FUN_060de3d4)();
    }
    if ((*(ushort *)(param_1 + 3) & 8) != 0) {
      iVar5 = param_1[4];
      if (iVar5 != 0) {
        iVar4 = *param_1 - iVar5;
        *param_1 = iVar5;
        if ((*(ushort *)(param_1 + 3) & 3) == 0) {
          iVar2 = param_1[5];
        }
        else {
          iVar2 = 0;
        }
        param_1[2] = iVar2;
        while (0 < iVar4) {
          iVar2 = (*(code *)param_1[9])(param_1[7],iVar5,iVar4);
          iVar4 = iVar4 - iVar2;
          if (iVar2 < 1) {
            *(ushort *)(param_1 + 3) = *(ushort *)(param_1 + 3) | 0x40;
            return 0xffffffff;
          }
          iVar5 = iVar5 + iVar2;
        }
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



uint FUN_060de3d8(int param_1,code *param_2)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  
  uVar7 = 0;
  for (piVar6 = (int *)(param_1 + DAT_060de438); piVar6 != (int *)0x0; piVar6 = (int *)*piVar6) {
    iVar3 = piVar6[1] + -1;
    iVar5 = piVar6[2];
    if (-1 < iVar3) {
      psVar4 = (short *)(iVar5 + 0xc);
      do {
        sVar1 = *psVar4;
        psVar4 = psVar4 + 0x2c;
        if (sVar1 != 0) {
          uVar2 = (*param_2)(iVar5);
          uVar7 = uVar7 | uVar2;
        }
        iVar3 = iVar3 + -1;
        iVar5 = iVar5 + 0x58;
      } while (-1 < iVar3);
    }
  }
  return uVar7;
}



int FUN_060de43c(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  uint uVar10;
  uint *puVar11;
  uint *puVar12;
  int iVar13;
  uint uVar14;
  undefined2 *puVar15;
  uint *puStack_28;
  undefined2 *puStack_24;
  
  if (*(int *)(param_1 + 0x10) < *(int *)(param_2 + 0x10)) {
    iVar2 = 0;
  }
  else {
    iVar13 = *(int *)(param_2 + 0x10) + -1;
    puVar11 = (uint *)(param_1 + 0x18);
    puVar12 = puVar11 + iVar13;
    puVar3 = (uint *)(param_2 + 0x18U) + iVar13;
    iVar2 = (*(code *)PTR_FUN_060de5cc)(*puVar12,*puVar3 + 1);
    uVar1 = DAT_060de5d0;
    if (iVar2 != 0) {
      iVar7 = 0;
      uVar14 = 0;
      puStack_24 = (undefined2 *)(param_1 + 0x1a);
      puStack_28 = (uint *)(param_2 + 0x18U);
      do {
        puVar4 = puStack_28 + 1;
        uVar10 = (*puStack_28 & uVar1) * iVar2 + uVar14;
        uVar8 = (*puStack_28 >> 0x10) * iVar2 + (uVar10 >> 0x10);
        uVar14 = uVar8 >> 0x10;
        iVar5 = ((*puVar11 & uVar1) - (uVar10 & uVar1)) + iVar7;
        iVar7 = ((*puVar11 >> 0x10) - (uVar8 & uVar1)) + (int)(short)((uint)iVar5 >> 0x10);
        *(short *)puVar11 = (short)iVar7;
        iVar7 = (int)(short)((uint)iVar7 >> 0x10);
        *puStack_24 = (short)iVar5;
        puStack_24 = puStack_24 + 2;
        puVar11 = puVar11 + 1;
        puStack_28 = puVar4;
      } while (puVar4 <= puVar3);
      if (*puVar12 == 0) {
        while ((puVar12 = puVar12 + -1, (uint *)(param_1 + 0x18) < puVar12 && (*puVar12 == 0))) {
          iVar13 = iVar13 + -1;
        }
        *(int *)(param_1 + 0x10) = iVar13;
      }
    }
    iVar7 = (*(code *)PTR_FUN_060de5d4)(param_1,param_2);
    uVar1 = DAT_060de5d0;
    if (-1 < iVar7) {
      iVar7 = 0;
      uVar14 = 0;
      puVar12 = (uint *)(param_1 + 0x18);
      puVar15 = (undefined2 *)(param_1 + 0x1a);
      iVar2 = iVar2 + 1;
      puStack_28 = (uint *)(param_2 + 0x18);
      do {
        puVar11 = puStack_28 + 1;
        uVar10 = (*puStack_28 & uVar1) + uVar14;
        uVar8 = (*puStack_28 >> 0x10) + (uVar10 >> 0x10);
        uVar14 = uVar8 >> 0x10;
        iVar5 = ((*puVar12 & uVar1) - (uVar10 & uVar1)) + iVar7;
        iVar6 = ((*puVar12 >> 0x10) - (uVar8 & uVar1)) + (int)(short)((uint)iVar5 >> 0x10);
        iVar7 = (int)(short)((uint)iVar6 >> 0x10);
        *(short *)puVar12 = (short)iVar6;
        *puVar15 = (short)iVar5;
        puVar15 = puVar15 + 2;
        puVar12 = puVar12 + 1;
        puStack_28 = puVar11;
      } while (puVar11 <= puVar3);
      piVar9 = (int *)(param_1 + 0x18) + iVar13;
      if (*piVar9 == 0) {
        while ((piVar9 = piVar9 + -1, (int *)(param_1 + 0x18) < piVar9 && (*piVar9 == 0))) {
          iVar13 = iVar13 + -1;
        }
        *(int *)(param_1 + 0x10) = iVar13;
      }
    }
  }
  return iVar2;
}



char * FUN_060de644(int param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint *param_6,
                   undefined4 *param_7,undefined4 *param_8)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  undefined4 uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  undefined *puVar16;
  char *pcVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  uint local_a0;
  uint uStack_9c;
  int iStack_98;
  int iStack_94;
  uint uStack_90;
  uint uStack_8c;
  int iStack_88;
  undefined4 uStack_84;
  int iStack_80;
  uint uStack_7c;
  int iStack_78;
  int iStack_74;
  uint uStack_70;
  uint uStack_6c;
  uint uStack_68;
  uint uStack_64;
  uint local_60;
  int local_5c;
  int local_58;
  int local_54;
  uint local_50;
  int local_4c;
  int local_48;
  undefined4 local_44;
  int local_40;
  int local_3c;
  int local_38;
  char *local_34;
  undefined4 local_30;
  undefined *local_2c;
  int local_28;
  
  piVar11 = (int *)(param_1 + 100);
  iStack_80 = param_1;
  uStack_7c = param_4;
  if (*piVar11 != 0) {
    local_30 = (int *)(param_1 + 0x68);
    *(int *)(*piVar11 + 4) = *local_30;
    iVar10 = *piVar11;
    uVar4 = (*(code *)PTR_FUN_060de80c)(1,*local_30);
    *(undefined4 *)(iVar10 + 8) = uVar4;
    (*(code *)PTR_FUN_060de810)(iStack_80,*piVar11);
    *piVar11 = 0;
  }
  if ((param_2 & DAT_060de814) == 0) {
    *param_7 = 0;
    local_a0 = param_2;
  }
  else {
    *param_7 = 1;
    local_a0 = param_2 & DAT_060de818;
  }
  if ((local_a0 & DAT_060de81c) == DAT_060de81c) {
    *param_6 = (int)DAT_060de804;
    puVar16 = PTR_DAT_060de820;
    if ((param_3 == 0) && ((local_a0 & DAT_060de824) == 0)) {
      puVar16 = PTR_s_Infinity_060de828;
    }
    if (param_8 != (undefined4 *)0x0) {
      pcVar8 = puVar16 + 3;
      if (*pcVar8 != '\0') {
        pcVar8 = puVar16 + 8;
      }
      *param_8 = pcVar8;
    }
LAB_060de75a:
                    // WARNING: Could not recover jumptable at 0x060de760. Too many branches
                    // WARNING: Treating indirect jump as call
    pcVar8 = (char *)(*DAT_060de764)();
    return pcVar8;
  }
  iVar10 = (*(code *)PTR_FUN_060de830)
                     (local_a0,param_3,*(undefined4 *)PTR_DAT_060de82c,
                      *(undefined4 *)(PTR_DAT_060de82c + 4));
  if (iVar10 == 0) {
    *param_6 = (uint)(iVar10 == 0);
    if (param_8 != (undefined4 *)0x0) {
      local_2c = PTR_DAT_060de834 + 1;
      *param_8 = local_2c;
    }
    goto LAB_060de75a;
  }
  local_30 = &iStack_94;
  local_44 = (*(code *)PTR_FUN_060de838)(iStack_80,local_a0,param_3,&iStack_98,local_30);
  local_30 = (int *)(local_a0 * 2);
  uVar15 = (uint)local_30 >> 0x15;
  if (uVar15 == 0) {
    iVar10 = iStack_94 + iStack_98 + (int)DAT_060de808;
    if (iVar10 < 0x21) {
      uVar15 = (*(code *)PTR_FUN_060de980)(param_3,0x20 - iVar10);
    }
    else {
      uVar15 = (*(code *)PTR_FUN_060de80c)(local_a0,0x40 - iVar10);
      uVar13 = (*(code *)PTR_FUN_060de840)(param_3,iVar10 + -0x20);
      uVar15 = uVar15 | uVar13;
    }
    uVar18 = (*(code *)PTR_FUN_060de984)(uVar15);
    if ((int)uVar15 < 0) {
      uVar18 = (*(code *)PTR_FUN_060de98c)
                         ((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),
                          *(undefined4 *)PTR_DAT_060de988,*(undefined4 *)(PTR_DAT_060de988 + 4));
    }
    uStack_8c = (uint)((ulonglong)uVar18 >> 0x20);
    uVar15 = iVar10 + DAT_060de97c;
    uStack_90 = (int)uVar18 + DAT_060de990;
    local_48 = 1;
  }
  else {
    local_30 = (int *)(local_a0 & DAT_060de824);
    uVar15 = uVar15 + (int)DAT_060de806;
    uStack_90 = (uint)local_30 | DAT_060de83c;
    local_48 = 0;
    uStack_8c = param_3;
  }
  uVar18 = (*(code *)PTR_FUN_060de998)
                     (uStack_90,uStack_8c,*(undefined4 *)PTR_DAT_060de994,
                      *(undefined4 *)(PTR_DAT_060de994 + 4));
  puVar3 = PTR_FUN_060de9a0;
  uVar18 = (*(code *)PTR_FUN_060de9a0)
                     ((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),*(undefined4 *)PTR_DAT_060de99c,
                      *(undefined4 *)(PTR_DAT_060de99c + 4));
  puVar2 = PTR_FUN_060de98c;
  uVar18 = (*(code *)PTR_FUN_060de98c)
                     ((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),*(undefined4 *)PTR_DAT_060de9a4,
                      *(undefined4 *)(PTR_DAT_060de9a4 + 4));
  puVar16 = PTR_FUN_060de984;
  uVar19 = (*(code *)PTR_FUN_060de984)(uVar15);
  uVar19 = (*(code *)puVar3)((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),
                             *(undefined4 *)PTR_DAT_060de9a8,*(undefined4 *)(PTR_DAT_060de9a8 + 4));
  uVar18 = (*(code *)puVar2)((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar19,
                             (int)((ulonglong)uVar19 >> 0x20));
  uVar12 = (undefined4)((ulonglong)uVar18 >> 0x20);
  uVar4 = (undefined4)uVar18;
  uStack_64 = (*(code *)PTR_FUN_060de9ac)(uVar4,uVar12);
  iVar10 = (*(code *)PTR_FUN_060de9b4)
                     (uVar4,uVar12,*(undefined4 *)PTR_DAT_060de9b0,
                      *(undefined4 *)(PTR_DAT_060de9b0 + 4));
  if (iVar10 < 0) {
    uVar18 = (*(code *)puVar16)(uStack_64);
    iVar10 = (*(code *)PTR_FUN_060de9b8)(uVar4,uVar12,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
    if (iVar10 != 0) {
      uStack_64 = uStack_64 - 1;
    }
  }
  local_5c = 1;
  if (uStack_64 < 0x17) {
    iVar10 = (*(code *)PTR_FUN_060de9b4)
                       (local_a0,param_3,*(undefined4 *)(PTR_DAT_060de9bc + uStack_64 * 8),
                        *(undefined4 *)((int)(PTR_DAT_060de9bc + uStack_64 * 8) + 4));
    if (iVar10 < 0) {
      uStack_64 = uStack_64 - 1;
    }
    local_5c = 0;
  }
  local_54 = (iStack_94 - uVar15) + -1;
  if (local_54 < 0) {
    iStack_78 = -local_54;
    local_54 = 0;
  }
  else {
    iStack_78 = 0;
  }
  if ((int)uStack_64 < 0) {
    iStack_78 = iStack_78 - uStack_64;
    iStack_74 = -uStack_64;
    local_50 = 0;
  }
  else {
    iStack_74 = 0;
    local_50 = uStack_64;
    local_54 = local_54 + uStack_64;
  }
  if (9 < uStack_7c) {
    uStack_7c = 0;
  }
  bVar1 = 5 < (int)uStack_7c;
  if (bVar1) {
    uStack_7c = uStack_7c - 4;
  }
  local_58 = 1;
  switch(uStack_7c) {
  case 0:
  case 1:
    uStack_70 = 0xffffffff;
    uVar15 = 0x12;
    uStack_68 = 0xffffffff;
    param_5 = 0;
    break;
  case 2:
    local_58 = 0;
  case 4:
    if ((int)param_5 < 1) {
      param_5 = 1;
    }
    uStack_68 = param_5;
    uStack_70 = param_5;
    uVar15 = param_5;
    break;
  case 3:
    local_58 = 0;
  case 5:
    uStack_68 = param_5 + uStack_64;
    uStack_70 = uStack_68 + 1;
    uVar15 = uStack_70;
    if ((int)uStack_70 < 1) {
      uVar15 = 1;
    }
  }
  iVar10 = 4;
  piVar11 = (int *)(iStack_80 + 0x68);
  *piVar11 = 0;
  if (0x1c < uVar15) {
    do {
      iVar10 = iVar10 * 2;
      *piVar11 = *piVar11 + 1;
    } while (iVar10 + 0x18U < uVar15);
  }
  local_30 = (int *)(iStack_80 + 0x68);
  iVar10 = (*(code *)PTR_FUN_060ded0c)(iStack_80,*local_30);
  local_30 = (int *)(iStack_80 + 100);
  *local_30 = iVar10;
  puVar16 = PTR_FUN_060ded20;
  pcVar8 = (char *)(iVar10 + 0x18);
  uStack_9c = param_3;
  local_34 = pcVar8;
  if ((0xe < uStack_70) || (bVar1)) {
LAB_060deee6:
    pcVar8 = local_34;
    uVar18 = CONCAT44(uStack_9c,local_a0);
    if ((iStack_98 < 0) || (0xe < (int)uStack_64)) {
      local_40 = 0;
      local_3c = 0;
      iVar10 = iStack_78;
      iVar6 = iStack_74;
      if (local_58 != 0) {
        if ((int)uStack_7c < 2) {
          if (local_48 == 0) {
            uVar15 = 0x36 - iStack_94;
          }
          else {
            uVar15 = iStack_98 + DAT_060df1c6;
          }
        }
        else {
          iVar6 = uStack_70 - 1;
          if (iStack_74 < iVar6) {
            local_50 = local_50 + (iVar6 - iStack_74);
            iStack_74 = iStack_74 + (iVar6 - iStack_74);
            iVar6 = 0;
          }
          else {
            iVar6 = iStack_74 - iVar6;
          }
          uVar15 = uStack_70;
          if ((int)uStack_70 < 0) {
            iVar10 = iStack_78 - uStack_70;
            uVar15 = 0;
          }
        }
        iStack_78 = iStack_78 + uVar15;
        local_54 = local_54 + uVar15;
        local_3c = (*(code *)PTR_FUN_060df1d4)(iStack_80,1);
      }
      if ((0 < iVar10) && (0 < local_54)) {
        iVar9 = iVar10;
        if (local_54 < iVar10) {
          iVar9 = local_54;
        }
        iStack_78 = iStack_78 - iVar9;
        iVar10 = iVar10 - iVar9;
        local_54 = local_54 - iVar9;
      }
      if (0 < iStack_74) {
        iVar9 = iStack_74;
        if (local_58 != 0) {
          if (0 < iVar6) {
            local_3c = (*(code *)PTR_FUN_060df1d8)(iStack_80,local_3c,iVar6);
            uVar4 = (*(code *)PTR_FUN_060df1dc)(iStack_80,local_3c,local_44);
            (*(code *)PTR_FUN_060df1e0)(iStack_80,local_44);
            local_44 = uVar4;
          }
          iVar9 = iStack_74 - iVar6;
          if (iVar9 == 0) goto LAB_060df1f8;
        }
        local_44 = (*(code *)PTR_FUN_060df3f4)(iStack_80,local_44,iVar9);
      }
LAB_060df1f8:
      local_38 = (*(code *)PTR_FUN_060df3f8)(iStack_80,1);
      if (0 < (int)local_50) {
        local_38 = (*(code *)PTR_FUN_060df3f4)(iStack_80,local_38,local_50);
      }
      if ((int)uStack_7c < 2) {
        if (((uStack_9c == 0) && ((DAT_060df3fc & local_a0) == 0)) &&
           ((DAT_060df400 & local_a0) != 0)) {
          iStack_78 = iStack_78 + 1;
          local_54 = local_54 + 1;
          local_4c = 1;
        }
        else {
          local_4c = 0;
        }
      }
      if (local_50 == 0) {
        uVar15 = local_54 + 1;
      }
      else {
        local_28 = *(int *)(local_38 + 0x10);
        local_30 = (int *)(local_28 * 4 + local_38);
        iVar6 = (*(code *)PTR_FUN_060df404)(*(undefined4 *)((int)local_30 + 0x14));
        local_30 = (int *)(local_54 + 0x20);
        uVar15 = (int)local_30 - iVar6;
      }
      uVar15 = uVar15 & 0x1f;
      if (uVar15 != 0) {
        uVar15 = 0x20 - uVar15;
      }
      if ((int)uVar15 < 5) {
        iVar6 = uVar15 + 0x1c;
        if ((int)uVar15 < 4) goto LAB_060df2ec;
      }
      else {
        iVar6 = uVar15 - 4;
LAB_060df2ec:
        iStack_78 = iStack_78 + iVar6;
        iVar10 = iVar10 + iVar6;
        local_54 = local_54 + iVar6;
      }
      if (0 < iStack_78) {
        local_44 = (*(code *)PTR_FUN_060df408)(iStack_80,local_44,iStack_78);
      }
      if (0 < local_54) {
        local_38 = (*(code *)PTR_FUN_060df408)(iStack_80,local_38,local_54);
      }
      if ((local_5c != 0) &&
         (iVar6 = (*(code *)PTR_FUN_060df40c)(local_44,local_38), puVar16 = PTR_FUN_060df410,
         iVar6 < 0)) {
        uStack_64 = uStack_64 - 1;
        local_44 = (*(code *)PTR_FUN_060df410)(iStack_80,local_44,10,0);
        if (local_58 != 0) {
          local_3c = (*(code *)puVar16)(iStack_80,local_3c,10,0);
        }
        uStack_70 = uStack_68;
      }
      puVar2 = PTR_FUN_060df668;
      puVar16 = PTR_FUN_060df658;
      if ((0 < (int)uStack_70) || ((int)uStack_7c < 3)) {
        if (local_58 != 0) {
          if (0 < iVar10) {
            local_3c = (*(code *)PTR_FUN_060df64c)(iStack_80,local_3c,iVar10);
          }
          local_40 = local_3c;
          uVar15 = 1;
          if (local_4c != 0) {
            local_3c = (*(code *)PTR_FUN_060df650)(iStack_80,*(undefined4 *)(local_3c + 4));
            (*(code *)PTR_FUN_060df654)
                      (local_3c + 0xc,local_40 + 0xc,*(int *)(local_40 + 0x10) * 4 + 0x18);
            local_3c = (*(code *)PTR_FUN_060df64c)(iStack_80,local_3c,1);
          }
LAB_060df494:
          iVar10 = (*(code *)PTR_FUN_060df658)(local_44,local_38);
          uVar13 = iVar10 + 0x30;
          iVar6 = (*(code *)PTR_FUN_060df65c)(local_44,local_40);
          iVar9 = (*(code *)PTR_FUN_060df660)(iStack_80,local_38,local_3c);
          iVar14 = 1;
          if (*(int *)(iVar9 + 0xc) == 0) {
            iVar14 = (*(code *)PTR_FUN_060df65c)(local_44,iVar9);
          }
          (*(code *)PTR_FUN_060df664)(iStack_80,iVar9);
          if (((iVar14 == 0) && (uStack_7c == 0)) && ((uStack_9c & 1) == 0)) {
            if (uVar13 == 0x39) {
LAB_060df582:
              *pcVar8 = '9';
              pcVar8 = pcVar8 + 1;
              goto LAB_060df6ba;
            }
            if (0 < iVar6) {
              uVar13 = iVar10 + 0x31;
            }
          }
          else {
            if ((-1 < iVar6) && (((iVar6 != 0 || (uStack_7c != 0)) || ((uStack_9c & 1) != 0)))) {
              if (0 < iVar14) {
                if (uVar13 == 0x39) goto LAB_060df582;
                goto LAB_060df588;
              }
              *pcVar8 = (char)uVar13;
              pcVar8 = pcVar8 + 1;
              if (uVar15 == uStack_70) goto LAB_060df66c;
              local_44 = (*(code *)PTR_FUN_060df668)(iStack_80,local_44,10,0);
              if (local_40 == local_3c) {
                local_40 = (*(code *)PTR_FUN_060df668)(iStack_80,local_3c,10);
                local_3c = local_40;
              }
              else {
                local_40 = (*(code *)PTR_FUN_060df668)(iStack_80,local_40,10,0);
                local_3c = (*(code *)PTR_FUN_060df668)(iStack_80,local_3c,10,0);
              }
              uVar15 = uVar15 + 1;
              goto LAB_060df494;
            }
            if (0 >= iVar14) goto LAB_060df510;
            local_44 = (*(code *)PTR_FUN_060df64c)(iStack_80,local_44,0 < iVar14);
            iVar6 = (*(code *)PTR_FUN_060df65c)(local_44,local_38);
            if ((0 < iVar6) || ((iVar6 == 0 && ((uVar13 & 1) != 0)))) {
              if (iVar10 + 0x31 == 0x3a) goto LAB_060df582;
              *pcVar8 = (char)(iVar10 + 0x31);
              goto LAB_060df6da;
            }
          }
LAB_060df510:
          *pcVar8 = (char)uVar13;
          goto LAB_060df6da;
        }
        iVar10 = 1;
        while( true ) {
          iVar6 = (*(code *)puVar16)(local_44,local_38);
          uVar13 = iVar6 + 0x30;
          *pcVar8 = (char)uVar13;
          pcVar8 = pcVar8 + 1;
          if ((int)uStack_70 <= iVar10) break;
          local_44 = (*(code *)puVar2)(iStack_80,local_44,10,0);
          iVar10 = iVar10 + 1;
        }
LAB_060df66c:
        local_44 = (*(code *)PTR_FUN_060df77c)(iStack_80,local_44,1);
        iVar10 = (*(code *)PTR_FUN_060df780)(local_44,local_38);
        if ((0 < iVar10) ||
           ((pcVar17 = pcVar8 + -1, iVar10 == 0 && (pcVar17 = pcVar8 + -1, (uVar13 & 1) != 0)))) {
LAB_060df6ba:
          pcVar8 = pcVar8 + -1;
          if (*pcVar8 == '9') goto LAB_060df6ae;
          uVar13 = (uint)*pcVar8;
LAB_060df588:
          *pcVar8 = (char)uVar13 + '\x01';
          goto LAB_060df6da;
        }
        do {
          pcVar8 = pcVar17;
          pcVar17 = pcVar8 + -1;
        } while (*pcVar8 == '0');
        goto LAB_060df6da;
      }
      if (-1 < (int)uStack_70) {
        local_38 = (*(code *)PTR_FUN_060df410)(iStack_80,local_38,5,0);
        iVar10 = (*(code *)PTR_FUN_060df40c)(local_44,local_38);
        goto joined_r0x060df3d6;
      }
    }
    else {
      local_30 = (int *)(PTR_DAT_060df03c + uStack_64 * 8);
      iVar10 = *local_30;
      iVar6 = local_30[1];
      if ((-1 < (int)param_5) || (0 < (int)uStack_70)) {
        uVar15 = 1;
        pcVar17 = local_34;
        do {
          uStack_9c = (uint)((ulonglong)uVar18 >> 0x20);
          local_a0 = (uint)uVar18;
          uVar18 = (*(code *)PTR_FUN_060df014)(local_a0,uStack_9c,iVar10,iVar6);
          uVar13 = (*(code *)PTR_FUN_060df020)((int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
          uVar18 = (*(code *)PTR_FUN_060df024)(uVar13);
          puVar16 = PTR_FUN_060df030;
          uVar18 = (*(code *)PTR_FUN_060df030)
                             ((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),iVar10,iVar6);
          uVar18 = (*(code *)PTR_FUN_060df018)
                             (local_a0,uStack_9c,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
          uVar12 = (undefined4)((ulonglong)uVar18 >> 0x20);
          uVar4 = (undefined4)uVar18;
          local_30 = (int *)(uVar13 + 0x30);
          *pcVar17 = (char)local_30;
          pcVar8 = pcVar17 + 1;
          if (uVar15 == uStack_70) {
            uVar18 = (*(code *)PTR_FUN_060df034)(uVar4,uVar12,uVar4,uVar12);
            uVar4 = (undefined4)((ulonglong)uVar18 >> 0x20);
            iVar9 = (*(code *)PTR_FUN_060df038)((int)uVar18,uVar4,iVar10,iVar6);
            if (0 < iVar9) goto LAB_060df056;
            iVar10 = (*(code *)PTR_FUN_060df048)((int)uVar18,uVar4,iVar10,iVar6);
            if ((iVar10 == 0) && ((uVar13 & 1) != 0)) goto LAB_060df058;
            break;
          }
          uVar18 = (*(code *)puVar16)(*(undefined4 *)PTR_DAT_060df1c8,
                                      *(undefined4 *)(PTR_DAT_060df1c8 + 4),uVar4,uVar12);
          iVar9 = (*(code *)PTR_FUN_060df1d0)
                            ((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),
                             *(undefined4 *)PTR_DAT_060df1cc,*(undefined4 *)(PTR_DAT_060df1cc + 4));
          uVar15 = uVar15 + 1;
          pcVar17 = pcVar8;
        } while (iVar9 != 0);
        goto LAB_060df71e;
      }
      local_3c = 0;
      local_38 = 0;
      if (-1 < (int)uStack_70) {
        uVar18 = (*(code *)PTR_FUN_060df030)
                           (iVar10,iVar6,*(undefined4 *)PTR_DAT_060df040,
                            *(undefined4 *)(PTR_DAT_060df040 + 4));
        iVar10 = (*(code *)PTR_FUN_060df044)
                           (local_a0,uStack_9c,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
joined_r0x060df3d6:
        if (0 < iVar10) goto LAB_060df3e8;
      }
    }
LAB_060df3da:
    uStack_64 = ~param_5;
  }
  else {
    iVar10 = 2;
    uStack_90 = local_a0;
    local_60 = uStack_64;
    uStack_6c = uStack_70;
    if ((int)uStack_64 < 1) {
      uVar15 = -uStack_64;
      uStack_8c = param_3;
      if (uVar15 != 0) {
        uVar18 = (*(code *)PTR_FUN_060ded20)
                           (local_a0,param_3,*(undefined4 *)(PTR_DAT_060ded10 + (uVar15 & 0xf) * 8),
                            *(undefined4 *)((int)(PTR_DAT_060ded10 + (uVar15 & 0xf) * 8) + 4));
        uStack_9c = (uint)((ulonglong)uVar18 >> 0x20);
        local_a0 = (uint)uVar18;
        uVar15 = (int)uVar15 >> 4;
        if (uVar15 != 0) {
          iVar6 = 0;
          do {
            uStack_9c = (uint)((ulonglong)uVar18 >> 0x20);
            local_a0 = (uint)uVar18;
            if ((uVar15 & 1) != 0) {
              iVar10 = iVar10 + 1;
              uVar18 = (*(code *)puVar16)(local_a0,uStack_9c,
                                          *(undefined4 *)(PTR_DAT_060ded1c + iVar6),
                                          *(undefined4 *)((int)(PTR_DAT_060ded1c + iVar6) + 4));
            }
            uStack_9c = (uint)((ulonglong)uVar18 >> 0x20);
            local_a0 = (uint)uVar18;
            uVar15 = (int)uVar15 >> 1;
            iVar6 = iVar6 + 8;
          } while (uVar15 != 0);
        }
      }
    }
    else {
      uVar18 = CONCAT44(*(undefined4 *)((int)(PTR_DAT_060ded10 + (uStack_64 & 0xf) * 8) + 4),
                        *(undefined4 *)(PTR_DAT_060ded10 + (uStack_64 & 0xf) * 8));
      uVar15 = (int)uStack_64 >> 4;
      local_30 = (int *)(uVar15 & 0x10);
      uStack_8c = param_3;
      if (local_30 != (int *)0x0) {
        uVar15 = uVar15 & 0xf;
        uVar19 = (*(code *)PTR_FUN_060ded18)
                           (local_a0,param_3,*(undefined4 *)PTR_DAT_060ded14,
                            *(undefined4 *)(PTR_DAT_060ded14 + 4));
        uStack_9c = (uint)((ulonglong)uVar19 >> 0x20);
        local_a0 = (uint)uVar19;
        iVar10 = 3;
      }
      iVar6 = 0;
      while( true ) {
        uVar4 = (undefined4)((ulonglong)uVar18 >> 0x20);
        if (uVar15 == 0) break;
        if ((uVar15 & 1) != 0) {
          iVar10 = iVar10 + 1;
          local_30 = (int *)(PTR_DAT_060ded1c + iVar6);
          uVar18 = (*(code *)PTR_FUN_060ded20)((int)uVar18,uVar4,*local_30,local_30[1]);
        }
        uVar15 = (int)uVar15 >> 1;
        iVar6 = iVar6 + 8;
      }
      uVar18 = (*(code *)PTR_FUN_060ded18)(local_a0,uStack_9c,(int)uVar18,uVar4);
      uStack_9c = (uint)((ulonglong)uVar18 >> 0x20);
      local_a0 = (uint)uVar18;
    }
    uVar18 = CONCAT44(uStack_9c,local_a0);
    if (((local_5c != 0) &&
        (iVar6 = (*(code *)PTR_FUN_060ded28)
                           (local_a0,uStack_9c,*(undefined4 *)PTR_DAT_060ded24,
                            *(undefined4 *)(PTR_DAT_060ded24 + 4)),
        uVar18 = CONCAT44(uStack_9c,local_a0), iVar6 < 0)) &&
       (uVar18 = CONCAT44(uStack_9c,local_a0), 0 < (int)uStack_70)) {
      if (0 < (int)uStack_68) {
        uStack_70 = uStack_68;
        uStack_64 = uStack_64 - 1;
        uVar18 = (*(code *)PTR_FUN_060ded20)
                           (*(undefined4 *)PTR_DAT_060ded2c,*(undefined4 *)(PTR_DAT_060ded2c + 4),
                            local_a0,uStack_9c);
        iVar10 = iVar10 + 1;
        goto LAB_060dec82;
      }
LAB_060deece:
      local_a0 = uStack_90;
      uStack_9c = uStack_8c;
      uStack_64 = local_60;
      uStack_70 = uStack_6c;
      goto LAB_060deee6;
    }
LAB_060dec82:
    uStack_9c = (uint)((ulonglong)uVar18 >> 0x20);
    local_a0 = (uint)uVar18;
    uVar19 = (*(code *)PTR_FUN_060ded30)(iVar10);
    uVar19 = (*(code *)PTR_FUN_060ded20)
                       ((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),local_a0,uStack_9c);
    uVar19 = (*(code *)PTR_FUN_060ded38)
                       ((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),*(undefined4 *)PTR_DAT_060ded34
                        ,*(undefined4 *)(PTR_DAT_060ded34 + 4));
    uStack_84 = (undefined4)((ulonglong)uVar19 >> 0x20);
    iVar10 = (int)uVar19 + DAT_060ded3c;
    iStack_88 = iVar10;
    if (uStack_70 != 0) {
      if (local_58 != 0) {
        uVar19 = (*(code *)PTR_FUN_060df014)
                           (*(undefined4 *)PTR_DAT_060df010,*(undefined4 *)(PTR_DAT_060df010 + 4),
                            *(undefined4 *)(PTR_PTR_LAB_060df00c + uStack_70 * 8),
                            *(undefined4 *)((int)(PTR_PTR_LAB_060df00c + uStack_70 * 8) + 4));
        puVar16 = PTR_FUN_060df018;
        uVar19 = (*(code *)PTR_FUN_060df018)
                           ((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),iVar10,uStack_84);
        puVar2 = PTR_FUN_060df01c;
        iVar10 = 0;
        while( true ) {
          uStack_84 = (undefined4)((ulonglong)uVar19 >> 0x20);
          iStack_88 = (int)uVar19;
          uStack_9c = (uint)((ulonglong)uVar18 >> 0x20);
          local_a0 = (uint)uVar18;
          iVar6 = (*(code *)PTR_FUN_060df020)(local_a0,uStack_9c);
          uVar18 = (*(code *)PTR_FUN_060df024)(iVar6);
          uVar18 = (*(code *)puVar16)(local_a0,uStack_9c,(int)uVar18,
                                      (int)((ulonglong)uVar18 >> 0x20));
          uVar12 = (undefined4)((ulonglong)uVar18 >> 0x20);
          uVar4 = (undefined4)uVar18;
          local_30 = (int *)(iVar6 + 0x30);
          *pcVar8 = (char)local_30;
          pcVar8 = pcVar8 + 1;
          iVar6 = (*(code *)puVar2)(uVar4,uVar12,iStack_88,uStack_84);
          if (iVar6 < 0) break;
          uVar18 = (*(code *)puVar16)(*(undefined4 *)PTR_DAT_060df028,
                                      *(undefined4 *)(PTR_DAT_060df028 + 4),uVar4,uVar12);
          iVar6 = (*(code *)puVar2)((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),iStack_88,uStack_84
                                   );
          puVar3 = PTR_FUN_060df030;
          if (iVar6 < 0) goto LAB_060df056;
          iVar10 = iVar10 + 1;
          if ((int)uStack_70 <= iVar10) goto LAB_060deece;
          uVar18 = (*(code *)PTR_FUN_060df030)
                             (*(undefined4 *)PTR_DAT_060df02c,*(undefined4 *)(PTR_DAT_060df02c + 4),
                              iStack_88,uStack_84);
          uStack_84 = (undefined4)((ulonglong)uVar18 >> 0x20);
          iStack_88 = (int)uVar18;
          uVar18 = (*(code *)puVar3)(*(undefined4 *)PTR_DAT_060df02c,
                                     *(undefined4 *)(PTR_DAT_060df02c + 4),uVar4,uVar12);
          uVar19 = CONCAT44(uStack_84,iStack_88);
        }
        goto LAB_060df71e;
      }
      uVar19 = (*(code *)PTR_FUN_060df030)
                         (iVar10,uStack_84,*(undefined4 *)(PTR_PTR_LAB_060df00c + uStack_70 * 8),
                          *(undefined4 *)((int)(PTR_PTR_LAB_060df00c + uStack_70 * 8) + 4));
      puVar16 = PTR_FUN_060df018;
      uVar15 = 1;
      uVar4 = *(undefined4 *)PTR_DAT_060df010;
      uVar12 = *(undefined4 *)(PTR_DAT_060df010 + 4);
      pcVar17 = pcVar8;
      while( true ) {
        uStack_9c = (uint)((ulonglong)uVar18 >> 0x20);
        local_a0 = (uint)uVar18;
        uStack_84 = (undefined4)((ulonglong)uVar19 >> 0x20);
        iStack_88 = (int)uVar19;
        iVar10 = (*(code *)PTR_FUN_060df020)(local_a0,uStack_9c);
        uVar18 = (*(code *)PTR_FUN_060df024)(iVar10);
        uVar18 = (*(code *)puVar16)(local_a0,uStack_9c,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20))
        ;
        uVar7 = (undefined4)((ulonglong)uVar18 >> 0x20);
        uVar5 = (undefined4)uVar18;
        local_30 = (int *)(iVar10 + 0x30);
        *pcVar17 = (char)local_30;
        pcVar8 = pcVar17 + 1;
        if (uVar15 == uStack_70) break;
        uVar15 = uVar15 + 1;
        uVar18 = (*(code *)PTR_FUN_060df030)
                           (*(undefined4 *)PTR_DAT_060df02c,*(undefined4 *)(PTR_DAT_060df02c + 4),
                            uVar5,uVar7);
        uVar19 = CONCAT44(uStack_84,iStack_88);
        pcVar17 = pcVar8;
      }
      uVar18 = (*(code *)PTR_FUN_060df034)(uVar4,uVar12,iStack_88,uStack_84);
      iVar10 = (*(code *)PTR_FUN_060df038)(uVar5,uVar7,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20))
      ;
      if (0 < iVar10) goto LAB_060df056;
      uVar18 = (*(code *)puVar16)(uVar4,uVar12,iStack_88,uStack_84);
      iVar10 = (*(code *)PTR_FUN_060df01c)(uVar5,uVar7,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20))
      ;
      if (iVar10 < 0) {
        do {
          pcVar8 = pcVar17;
          pcVar17 = pcVar8 + -1;
        } while (*pcVar8 == '0');
        pcVar8 = pcVar8 + 1;
        goto LAB_060df71e;
      }
      goto LAB_060deece;
    }
    local_3c = 0;
    local_38 = 0;
    uVar18 = (*(code *)PTR_FUN_060ded44)
                       (local_a0,uStack_9c,*(undefined4 *)PTR_DAT_060ded40,
                        *(undefined4 *)(PTR_DAT_060ded40 + 4));
    uVar4 = (undefined4)((ulonglong)uVar18 >> 0x20);
    iVar6 = (*(code *)PTR_FUN_060ded48)((int)uVar18,uVar4,iVar10,uStack_84);
    if (iVar6 < 1) {
      uVar19 = (*(code *)PTR_FUN_060ded4c)(iVar10,uStack_84);
      iVar10 = (*(code *)PTR_FUN_060ded28)
                         ((int)uVar18,uVar4,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
      if (-1 < iVar10) goto LAB_060deece;
      goto LAB_060df3da;
    }
LAB_060df3e8:
    *pcVar8 = '1';
    pcVar8 = pcVar8 + 1;
    uStack_64 = uStack_64 + 1;
  }
LAB_060df6dc:
  puVar16 = PTR_FUN_060df784;
  (*(code *)PTR_FUN_060df784)(iStack_80,local_38);
  if (local_3c != 0) {
    if ((local_40 != 0) && (local_40 != local_3c)) {
      (*(code *)puVar16)(iStack_80,local_40);
    }
    (*(code *)PTR_FUN_060df784)(iStack_80,local_3c);
  }
LAB_060df71e:
  (*(code *)PTR_FUN_060df784)(iStack_80,local_44);
  *pcVar8 = '\0';
  *param_6 = uStack_64 + 1;
  if (param_8 != (undefined4 *)0x0) {
    *param_8 = pcVar8;
  }
  return local_34;
LAB_060df6ae:
  if (pcVar8 == local_34) goto LAB_060df6c6;
  goto LAB_060df6ba;
LAB_060df6c6:
  uStack_64 = uStack_64 + 1;
  *pcVar8 = '1';
LAB_060df6da:
  pcVar8 = pcVar8 + 1;
  goto LAB_060df6dc;
LAB_060df058:
  if (*pcVar17 != '9') goto LAB_060df060;
  pcVar8 = pcVar17;
  if (pcVar17 == local_34) {
    uStack_64 = uStack_64 + 1;
    *pcVar17 = '0';
    goto LAB_060df060;
  }
LAB_060df056:
  pcVar17 = pcVar8 + -1;
  goto LAB_060df058;
LAB_060df060:
  *pcVar17 = *pcVar17 + '\x01';
  pcVar8 = pcVar17 + 1;
  goto LAB_060df71e;
}



int * FUN_060df788(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  if (*(int *)(param_1 + 0x70) == 0) {
    iVar1 = (*(code *)PTR_FUN_060df80c)(param_1,4,0x10);
    *(int *)(param_1 + 0x70) = iVar1;
    if (iVar1 != 0) goto LAB_060df7b2;
LAB_060df7e4:
    piVar2 = (int *)0x0;
  }
  else {
LAB_060df7b2:
    piVar4 = (int *)(param_1 + 0x70);
    piVar3 = (int *)(param_2 * 4 + *piVar4);
    piVar2 = (int *)*piVar3;
    if (piVar2 == (int *)0x0) {
      iVar1 = (*(code *)PTR_FUN_060df810)(piVar2 == (int *)0x0,param_2);
      piVar2 = (int *)(*(code *)PTR_FUN_060df80c)(param_1,iVar1 + 0x1b,4);
      if (piVar2 == (int *)0x0) goto LAB_060df7e4;
      *(int *)((int)piVar2 + 4) = param_2;
      *(int *)((int)piVar2 + 8) = iVar1;
      *(undefined4 *)((int)piVar2 + 0x14) = *(undefined4 *)(*piVar4 + 0x3c);
      *(int **)(*piVar4 + 0x3c) = piVar2;
    }
    else {
      *piVar3 = *piVar2;
    }
    *(undefined4 *)((int)piVar2 + 0x10) = 0;
    *(undefined4 *)((int)piVar2 + 0xc) = 0;
  }
  return piVar2;
}



void FUN_060df814(int param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(*(int *)(param_1 + 0x70) + param_2[1] * 4);
    *(undefined4 **)(*(int *)(param_1 + 0x70) + param_2[1] * 4) = param_2;
  }
  return;
}



int FUN_060df83c(undefined4 param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  
  uVar1 = DAT_060df8dc;
  iVar6 = *(int *)(param_2 + 0x10);
  puVar5 = (uint *)(param_2 + 0x18);
  iVar4 = 0;
  do {
    iVar4 = iVar4 + 1;
    uVar3 = (*puVar5 & uVar1) * param_3 + param_4;
    uVar2 = (*puVar5 >> 0x10) * param_3 + (uVar3 >> 0x10);
    param_4 = uVar2 >> 0x10;
    *puVar5 = uVar2 * 0x10000 + (uVar3 & uVar1);
    puVar5 = puVar5 + 1;
  } while (iVar4 < iVar6);
  iVar4 = param_2;
  if (param_4 != 0) {
    if (*(int *)(param_2 + 8) <= iVar6) {
      iVar4 = (*(code *)PTR_FUN_060df8e0)(param_1,*(int *)(param_2 + 4) + 1);
      (*(code *)PTR_FUN_060df8e4)(iVar4 + 0xc,param_2 + 0xc,*(int *)(param_2 + 0x10) * 4 + 0x18);
      (*(code *)PTR_FUN_060df8e8)(param_1,param_2);
    }
    *(uint *)(iVar6 * 4 + iVar4 + 0x18) = param_4;
    *(int *)(iVar4 + 0x10) = iVar6 + 1;
  }
  return iVar4;
}



int FUN_060df990(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if ((DAT_060df9e4 & param_1) == 0) {
    iVar1 = 0x10;
    param_1 = param_1 << 0x10;
  }
  if ((DAT_060df9e8 & param_1) == 0) {
    iVar1 = iVar1 + 8;
    param_1 = param_1 << 8;
  }
  if ((DAT_060df9ec & param_1) == 0) {
    iVar1 = iVar1 + 4;
    param_1 = param_1 << 4;
  }
  if ((DAT_060df9f0 & param_1) == 0) {
    iVar1 = iVar1 + 2;
    param_1 = param_1 << 2;
  }
  if (((DAT_060df9f4 & param_1) == 0) && (iVar1 = iVar1 + 1, (DAT_060df9f8 & param_1) == 0)) {
    iVar1 = 0x20;
  }
  return iVar1;
}



int FUN_060df9fc(uint *param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *param_1;
  if ((uVar2 & 7) == 0) {
    iVar1 = 0;
    if ((uVar2 & 0xffff) == 0) {
      iVar1 = 0x10;
      uVar2 = uVar2 >> 0x10;
    }
    if ((uVar2 & 0xff) == 0) {
      iVar1 = iVar1 + 8;
      uVar2 = uVar2 >> 8;
    }
    if ((uVar2 & 0xf) == 0) {
      iVar1 = iVar1 + 4;
      uVar2 = uVar2 >> 4;
    }
    if ((uVar2 & 3) == 0) {
      iVar1 = iVar1 + 2;
      uVar2 = uVar2 >> 2;
    }
    if ((uVar2 & 1) == 0) {
      uVar2 = uVar2 >> 1;
      iVar1 = iVar1 + 1;
      if (uVar2 == 0) {
        return 0x20;
      }
    }
    *param_1 = uVar2;
  }
  else {
    iVar1 = 0;
    if ((uVar2 & 1) == 0) {
      if ((uVar2 & 2) == 0) {
        *param_1 = uVar2 >> 2;
        iVar1 = 2;
      }
      else {
        *param_1 = uVar2 >> 1;
        iVar1 = 1;
      }
    }
  }
  return iVar1;
}



void FUN_060dfa7c(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_FUN_060dfa9c)(param_1,1);
  *(undefined4 *)(iVar1 + 0x18) = param_2;
  *(undefined4 *)(iVar1 + 0x10) = 1;
  return;
}



int FUN_060dfaa0(undefined4 param_1,int param_2,int param_3)

{
  undefined2 *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  int *piVar6;
  int iVar7;
  undefined4 *puVar8;
  uint *puVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint *puVar13;
  int iVar14;
  uint *puVar15;
  int iVar16;
  undefined4 *puVar17;
  uint *puVar18;
  int iVar19;
  
  iVar11 = param_2;
  if (*(int *)(param_2 + 0x10) < *(int *)(param_3 + 0x10)) {
    iVar11 = param_3;
    param_3 = param_2;
  }
  iVar7 = *(int *)(iVar11 + 4);
  iVar14 = *(int *)(iVar11 + 0x10);
  iVar19 = *(int *)(param_3 + 0x10);
  iVar16 = iVar19 + iVar14;
  if (*(int *)(iVar11 + 8) < iVar16) {
    iVar7 = iVar7 + 1;
  }
  iVar7 = (*(code *)PTR_FUN_060dfc0c)(param_1,iVar7);
  puVar8 = (undefined4 *)(iVar7 + 0x18);
  puVar17 = puVar8 + iVar16;
  for (; puVar8 < puVar17; puVar8 = puVar8 + 1) {
    *puVar8 = 0;
  }
  puVar18 = (uint *)(iVar11 + 0x18);
  puVar13 = (uint *)(param_3 + 0x18);
  puVar2 = puVar13 + iVar19;
  puVar15 = (uint *)(iVar7 + 0x18);
  for (; puVar13 < puVar2; puVar13 = puVar13 + 1) {
    uVar3 = *puVar13;
    uVar12 = uVar3 & 0xffff;
    if (uVar12 != 0) {
      uVar3 = 0;
      puVar1 = (undefined2 *)((int)puVar15 + 2);
      puVar5 = puVar15;
      puVar9 = puVar18;
      do {
        uVar10 = *puVar9;
        puVar9 = puVar9 + 1;
        uVar4 = (uVar10 & 0xffff) * uVar12 + (*puVar5 & 0xffff) + uVar3;
        uVar10 = (uVar10 >> 0x10) * uVar12 + (*puVar5 >> 0x10) + (uVar4 >> 0x10);
        uVar3 = uVar10 >> 0x10;
        *(short *)puVar5 = (short)uVar10;
        *puVar1 = (short)uVar4;
        puVar1 = puVar1 + 2;
        puVar5 = puVar5 + 1;
      } while (puVar9 < puVar18 + iVar14);
      *puVar5 = uVar3;
      uVar3 = *puVar13;
    }
    uVar3 = uVar3 >> 0x10;
    if (uVar3 != 0) {
      uVar12 = 0;
      uVar4 = *puVar15;
      puVar1 = (undefined2 *)((int)puVar15 + 2);
      puVar5 = puVar15;
      puVar9 = puVar18;
      do {
        uVar12 = (*puVar9 & 0xffff) * uVar3 + (*puVar5 >> 0x10) + uVar12;
        *(short *)puVar5 = (short)uVar12;
        *puVar1 = (short)uVar4;
        uVar4 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar5 = puVar5 + 1;
        uVar4 = (uVar4 >> 0x10) * uVar3 + (*puVar5 & 0xffff) + (uVar12 >> 0x10);
        uVar12 = uVar4 >> 0x10;
        puVar1 = puVar1 + 2;
      } while (puVar9 < puVar18 + iVar14);
      *puVar5 = uVar4;
    }
    puVar15 = puVar15 + 1;
  }
  piVar6 = (int *)(iVar7 + 0x18 + iVar16 * 4);
  while ((piVar6 = piVar6 + -1, 0 < iVar16 && (*piVar6 == 0))) {
    iVar16 = iVar16 + -1;
  }
  *(int *)(iVar7 + 0x10) = iVar16;
  return iVar7;
}



undefined4 FUN_060dfc1c(int param_1,undefined4 param_2,uint param_3)

{
  code *pcVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  if ((param_3 & 3) != 0) {
    param_2 = (*(code *)PTR_FUN_060dfccc)
                        (param_1,param_2,*(undefined4 *)(PTR_PTR_FUN_060dfcc8 + (param_3 & 3) * 4),0
                        );
  }
  param_3 = (int)param_3 >> 2;
  if (param_3 != 0) {
    puVar2 = *(undefined4 **)(param_1 + 0x6c);
    uVar4 = param_2;
    pcVar1 = (code *)PTR_FUN_060dfcd4;
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)(*(code *)PTR_FUN_060dfcd0)(param_1,(int)DAT_060dfcc6);
      *(undefined4 **)(param_1 + 0x6c) = puVar2;
      *puVar2 = 0;
      pcVar1 = (code *)PTR_FUN_060dfcd4;
    }
    while( true ) {
      puVar3 = puVar2;
      param_2 = uVar4;
      if ((param_3 & 1) != 0) {
        param_2 = (*pcVar1)(param_1,uVar4,puVar3);
        (*(code *)PTR_FUN_060dfcd8)(param_1,uVar4);
      }
      param_3 = (int)param_3 >> 1;
      if (param_3 == 0) break;
      puVar2 = (undefined4 *)*puVar3;
      uVar4 = param_2;
      if ((undefined4 *)*puVar3 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)(*pcVar1)(param_1,puVar3,puVar3);
        *puVar3 = puVar2;
        *puVar2 = 0;
      }
    }
  }
  return param_2;
}



int FUN_060dfcdc(undefined4 param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  uint *puVar9;
  int iStack_28;
  
  iVar4 = (int)param_3 >> 5;
  iVar2 = *(int *)(param_2 + 0x10) + iVar4;
  iStack_28 = iVar2 + 1;
  iVar8 = *(int *)(param_2 + 4);
  for (iVar3 = *(int *)(param_2 + 8); iVar3 < iStack_28; iVar3 = iVar3 * 2) {
    iVar8 = iVar8 + 1;
  }
  iVar3 = (*(code *)PTR_FUN_060dfdc0)(param_1,iVar8);
  iVar8 = 0;
  puVar6 = (uint *)(iVar3 + 0x18);
  if (0 < iVar4) {
    do {
      *puVar6 = 0;
      iVar8 = iVar8 + 1;
      puVar6 = puVar6 + 1;
    } while (iVar8 < iVar4);
  }
  puVar5 = (uint *)(param_2 + 0x18);
  param_3 = param_3 & 0x1f;
  puVar9 = puVar5 + *(int *)(param_2 + 0x10);
  if (param_3 == 0) {
    do {
      uVar7 = *puVar5;
      puVar5 = puVar5 + 1;
      *puVar6 = uVar7;
      puVar6 = puVar6 + 1;
    } while (puVar5 < puVar9);
  }
  else {
    uVar7 = 0;
    do {
      uVar1 = (*(code *)PTR_FUN_060dfdc4)(*puVar5,param_3);
      *puVar6 = uVar1 | uVar7;
      puVar6 = puVar6 + 1;
      uVar7 = *puVar5;
      puVar5 = puVar5 + 1;
      uVar7 = (*(code *)PTR_FUN_060dfdc8)(uVar7,0x20 - param_3);
    } while (puVar5 < puVar9);
    *puVar6 = uVar7;
    if (uVar7 != 0) {
      iStack_28 = iVar2 + 2;
    }
  }
  *(int *)(iVar3 + 0x10) = iStack_28 + -1;
  (*(code *)PTR_FUN_060dfdcc)(param_1,param_2);
  return iVar3;
}



int FUN_060dfdd0(int param_1,int param_2)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  
  iVar3 = *(int *)(param_2 + 0x10);
  iVar1 = *(int *)(param_1 + 0x10) - iVar3;
  if (iVar1 == 0) {
    puVar4 = (uint *)(param_1 + 0x18) + iVar3;
    puVar2 = (uint *)(param_2 + 0x18 + iVar3 * 4);
    do {
      puVar4 = puVar4 + -1;
      puVar2 = puVar2 + -1;
      if (*puVar4 != *puVar2) {
        if (*puVar2 <= *puVar4) {
          return 1;
        }
        return -1;
      }
    } while ((uint *)(param_1 + 0x18) < puVar4);
    iVar1 = 0;
  }
  return iVar1;
}



int FUN_060dfe10(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined2 *puVar9;
  uint *puVar10;
  undefined2 *puVar11;
  int iVar13;
  uint uVar14;
  undefined2 *puVar15;
  uint *puVar16;
  int *piVar12;
  
  iVar1 = (*(code *)PTR_FUN_060dff18)(param_2,param_3);
  if (iVar1 == 0) {
    iVar2 = (*(code *)PTR_FUN_060dff1c)(param_1,0);
    *(undefined4 *)(iVar2 + 0x10) = 1;
    *(undefined4 *)(iVar2 + 0x18) = 0;
  }
  else {
    iVar5 = param_2;
    if (iVar1 < 0) {
      iVar5 = param_3;
      param_3 = param_2;
    }
    iVar2 = (*(code *)PTR_FUN_060dff1c)(param_1,*(undefined4 *)(iVar5 + 4));
    *(uint *)(iVar2 + 0xc) = (uint)(iVar1 < 0);
    uVar7 = DAT_060dff20;
    puVar10 = (uint *)(iVar5 + 0x18);
    puVar3 = (uint *)(param_3 + 0x18);
    iVar13 = 0;
    iVar1 = *(int *)(iVar5 + 0x10);
    puVar15 = (undefined2 *)(iVar2 + 0x1a);
    puVar4 = puVar10 + iVar1;
    puVar16 = puVar3 + *(int *)(param_3 + 0x10);
    puVar11 = (undefined2 *)(iVar2 + 0x18);
    do {
      puVar9 = puVar11;
      uVar14 = *puVar10;
      puVar10 = puVar10 + 1;
      uVar8 = *puVar3;
      puVar3 = puVar3 + 1;
      iVar5 = ((uVar14 & uVar7) - (uVar8 & uVar7)) + iVar13;
      iVar6 = ((uVar14 >> 0x10) - (uVar8 >> 0x10)) + (int)(short)((uint)iVar5 >> 0x10);
      iVar13 = (int)(short)((uint)iVar6 >> 0x10);
      *puVar9 = (short)iVar6;
      *puVar15 = (short)iVar5;
      uVar8 = DAT_060dff20;
      puVar15 = puVar15 + 2;
      puVar11 = puVar9 + 2;
    } while (puVar3 < puVar16);
    if (puVar10 < puVar4) {
      puVar9 = puVar9 + 3;
      do {
        uVar7 = *puVar10;
        puVar10 = puVar10 + 1;
        iVar5 = (uVar7 & uVar8) + iVar13;
        iVar6 = (uVar7 >> 0x10) + (int)(short)((uint)iVar5 >> 0x10);
        iVar13 = (int)(short)((uint)iVar6 >> 0x10);
        *puVar11 = (short)iVar6;
        *puVar9 = (short)iVar5;
        puVar9 = puVar9 + 2;
        puVar11 = puVar11 + 2;
      } while (puVar10 < puVar4);
    }
    piVar12 = (int *)(puVar11 + -2);
    iVar5 = *piVar12;
    while (iVar5 == 0) {
      piVar12 = piVar12 + -1;
      iVar1 = iVar1 + -1;
      iVar5 = *piVar12;
    }
    *(int *)(iVar2 + 0x10) = iVar1;
  }
  return iVar2;
}



int FUN_060e0098(undefined4 param_1,uint param_2,uint param_3,int *param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  uint uStack_28;
  uint auStack_24 [2];
  
  iVar1 = (*(code *)PTR_FUN_060e0194)(param_1,1);
  puVar5 = (uint *)(iVar1 + 0x18);
  auStack_24[0] = param_2 & DAT_060e0198;
  uVar6 = (param_2 & DAT_060e019c) >> 0x14;
  if (uVar6 != 0) {
    auStack_24[0] = DAT_060e01a0 | auStack_24[0];
  }
  uStack_28 = param_3;
  if (param_3 == 0) {
    iVar2 = (*(code *)PTR_FUN_060e01a4)(auStack_24);
    iVar4 = 1;
    iVar2 = iVar2 + 0x20;
    *puVar5 = auStack_24[0];
    *(undefined4 *)(iVar1 + 0x10) = 1;
  }
  else {
    iVar2 = (*(code *)PTR_FUN_060e01a4)(&uStack_28);
    if (iVar2 == 0) {
      *puVar5 = uStack_28;
    }
    else {
      uVar3 = (*(code *)PTR_FUN_060e01a8)(auStack_24[0],0x20 - iVar2);
      *puVar5 = uStack_28 | uVar3;
      auStack_24[0] = (*(code *)PTR_FUN_060e01ac)(auStack_24[0],iVar2);
    }
    *(uint *)(iVar1 + 0x1c) = auStack_24[0];
    iVar4 = 1;
    if (auStack_24[0] != 0) {
      iVar4 = 2;
    }
    *(int *)(iVar1 + 0x10) = iVar4;
  }
  if (uVar6 == 0) {
    *param_4 = DAT_060e0190 + iVar2;
    iVar2 = (*(code *)PTR_FUN_060e01b0)(puVar5[iVar4 + -1]);
    iVar2 = iVar4 * 0x20 - iVar2;
  }
  else {
    *param_4 = DAT_060e018e + iVar2 + uVar6;
    iVar2 = 0x35 - iVar2;
  }
  *param_5 = iVar2;
  return iVar1;
}



undefined8 FUN_060e035c(int param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  
  puVar2 = PTR_FUN_060e03c0;
  puVar1 = PTR_DAT_060e03bc;
  uVar3 = CONCAT44(*(undefined4 *)(PTR_DAT_060e03b4 + 4),*(undefined4 *)PTR_DAT_060e03b4);
  if (param_1 < 0x18) {
    uVar3 = CONCAT44(*(undefined4 *)((int)(PTR_DAT_060e03b8 + param_1 * 8) + 4),
                     *(undefined4 *)(PTR_DAT_060e03b8 + param_1 * 8));
  }
  else if (0 < param_1) {
    do {
      uVar3 = (*(code *)puVar2)((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),*(undefined4 *)puVar1,
                                *(undefined4 *)(puVar1 + 4));
      param_1 = param_1 + -1;
    } while (0 < param_1);
  }
  return uVar3;
}



void FUN_060e03c4(int *param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = DAT_060e03f0;
  *DAT_060e03f0 = 0;
  (*(code *)PTR_FUN_060e03f4)(param_2);
  if (*piVar1 != 0) {
    *param_1 = *piVar1;
  }
  return;
}



undefined4 FUN_060e041c(undefined4 *param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  int *piVar3;
  
  piVar3 = param_1 + 0x15;
  if (*piVar3 == 0) {
    *piVar3 = *(int *)PTR_PTR_DAT_060e04e8;
  }
  if (*(int *)(*piVar3 + 0x5c) == 0) {
    (*(code *)PTR_FUN_060e04ec)();
  }
  uVar1 = *(ushort *)(param_1 + 3);
  if ((uVar1 & 8) == 0) {
    if ((uVar1 & 0x10) == 0) {
      return 0xffffffff;
    }
    if ((uVar1 & 4) != 0) {
      if ((undefined4 *)param_1[0xc] != (undefined4 *)0x0) {
        if ((undefined4 *)param_1[0xc] != param_1 + 0x10) {
          (*(code *)PTR_FUN_060e04f0)(*piVar3);
        }
        param_1[0xc] = 0;
      }
      *(ushort *)(param_1 + 3) = *(ushort *)(param_1 + 3) & 0xffdb;
      param_1[1] = 0;
      *param_1 = param_1[4];
    }
    *(ushort *)(param_1 + 3) = *(ushort *)(param_1 + 3) | 8;
  }
  if (param_1[4] == 0) {
    (*(code *)PTR_FUN_060e04f4)(param_1);
  }
  if ((*(ushort *)(param_1 + 3) & 1) == 0) {
    uVar2 = 0;
    if ((*(ushort *)(param_1 + 3) & 2) == 0) {
      uVar2 = param_1[5];
    }
    param_1[2] = uVar2;
  }
  else {
    param_1[2] = 0;
    param_1[6] = -param_1[5];
  }
  return 0;
}



byte * FUN_060e04f8(byte *param_1,uint param_2,int param_3)

{
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 == -1) {
      return (byte *)0x0;
    }
    if (*param_1 == param_2) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



void FUN_060e0558(int *param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = DAT_060e0584;
  *DAT_060e0584 = 0;
  (*(code *)PTR_FUN_060e0588)(param_2);
  if (*piVar1 != 0) {
    *param_1 = *piVar1;
  }
  return;
}



void FUN_060e058c(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  
  piVar1 = DAT_060e05bc;
  *DAT_060e05bc = 0;
  (*(code *)PTR_FUN_060e05c0)(param_2,param_3,param_4);
  if (*piVar1 != 0) {
    *param_1 = *piVar1;
  }
  return;
}



void FUN_060e05c4(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  
  piVar1 = DAT_060e05f4;
  *DAT_060e05f4 = 0;
  (*(code *)PTR_FUN_060e05f8)(param_2,param_3,param_4);
  if (*piVar1 != 0) {
    *param_1 = *piVar1;
  }
  return;
}



void FUN_060e05fc(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  
  piVar1 = DAT_060e062c;
  *DAT_060e062c = 0;
  (*(code *)PTR_FUN_060e0630)(param_2,param_3,param_4);
  if (*piVar1 != 0) {
    *param_1 = *piVar1;
  }
  return;
}



int FUN_060e0634(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_FUN_060e066c)(param_1,param_2 * param_3);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    (*(code *)PTR_FUN_060e0670)(iVar1,0,param_2 * param_3);
  }
  return iVar1;
}



void FUN_060e0674(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)PTR_FUN_060e0690)(3,param_1,param_2,param_3);
  return;
}



void FUN_060e0694(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)PTR_FUN_060e06b0)(0x13,param_1,param_2,param_3);
  return;
}



void FUN_060e06c0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)PTR_FUN_060e06dc)(4,param_1,param_2,param_3);
  return;
}



void FUN_060e06e0(undefined4 param_1)

{
  (*(code *)PTR_FUN_060e06fc)(6,param_1,0,0);
  return;
}



undefined * FUN_060e071c(int param_1)

{
  uint *puVar1;
  undefined *puVar2;
  undefined local_14 [4];
  
  puVar1 = DAT_060e0764;
  if (*DAT_060e0764 == 0) {
    *DAT_060e0764 = DAT_060e0768;
  }
  puVar2 = (undefined *)*puVar1;
  if (local_14 < puVar2) {
    (*(code *)PTR_FUN_060e0770)(local_14 < puVar2,PTR_s_Heap_and_stack_collision_060e076c,0x19);
    (*(code *)PTR_FUN_060e0774)();
  }
  *puVar1 = *puVar1 + param_1;
  return puVar2;
}



undefined4 FUN_060e0778(undefined4 param_1,int param_2)

{
  *(undefined4 *)(param_2 + 4) = 0x2000;
  return 0;
}



undefined4 FUN_060e07b4(void)

{
  return 1;
}



void FUN_060e07c0(undefined4 param_1)

{
  (*(code *)PTR_FUN_060e07dc)(1,param_1,0,0);
  return;
}



void FUN_060e07e0(void)

{
  (*(code *)PTR_FUN_060e0800)(1,DAT_060e07fc,0,0);
  return;
}



undefined4 FUN_060e0804(void)

{
  return 1;
}



int FUN_060e092c(char *param_1,int param_2,uint param_3,int param_4,int param_5,int param_6,
                undefined4 param_7)

{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  if ((param_5 == 0) || ((param_3 & 2) != 0)) {
    if (param_6 == 0) goto LAB_060e09cc;
  }
  else {
    iVar5 = 0;
    if (((param_6 != 0) && ((param_3 & 0x40) != 0)) &&
       (iVar3 = (*(code *)PTR_FUN_060e0a68)(param_6,param_7), iVar3 == -1)) {
      return -1;
    }
    puVar2 = PTR_FUN_060e0a6c;
    if (0 < param_5) {
      do {
        if ((param_3 & 0x40) == 0) {
          uVar4 = 0x20;
        }
        else {
          uVar4 = 0x30;
        }
        iVar3 = (*(code *)puVar2)(uVar4,param_7);
        iVar5 = iVar5 + 1;
        if (iVar3 == -1) {
          return -1;
        }
      } while (iVar5 < param_5);
    }
    if ((param_6 == 0) || ((param_3 & 0x40) != 0)) goto LAB_060e09cc;
  }
  iVar5 = (*(code *)PTR_FUN_060e0a68)(param_6,param_7);
  if (iVar5 != 0) {
    return -1;
  }
LAB_060e09cc:
  puVar2 = PTR_FUN_060e0a6c;
  iVar5 = 0;
  if (0 < param_4) {
    do {
      iVar3 = (*(code *)puVar2)(0x30,param_7);
      if (iVar3 == -1) {
        return -1;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < param_4);
  }
  puVar2 = PTR_FUN_060e0a6c;
  iVar5 = 0;
  if (0 < param_2) {
    do {
      cVar1 = *param_1;
      param_1 = param_1 + 1;
      iVar3 = (*(code *)puVar2)((int)cVar1,param_7);
      if (iVar3 == -1) {
        return -1;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < param_2);
  }
  puVar2 = PTR_FUN_060e0a6c;
  if (((param_5 != 0) && (iVar5 = 0, (param_3 & 2) != 0)) && (0 < param_5)) {
    do {
      iVar3 = (*(code *)puVar2)(0x20,param_7);
      iVar5 = iVar5 + 1;
      if (iVar3 == -1) {
        return -1;
      }
    } while (iVar5 < param_5);
  }
  param_5 = param_2 + param_4 + param_5;
  if (param_6 != 0) {
    iVar5 = (*(code *)PTR_FUN_060e0a70)(param_6);
    param_5 = iVar5 + param_5;
  }
  return param_5;
}



void FUN_060e0a74(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)PTR_FUN_060e0a94)(*(undefined4 *)(param_1 + 0x54),param_1,param_2,param_3);
  return;
}



int FUN_060e0ac0(undefined4 param_1,int param_2,char *param_3,undefined4 *param_4)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  undefined *puVar4;
  int iVar5;
  undefined *puVar6;
  char *pcVar7;
  undefined4 *puVar8;
  int *piVar9;
  int iVar10;
  undefined *puVar11;
  uint uVar12;
  undefined *puVar13;
  undefined *puVar14;
  undefined auStack_d8 [128];
  undefined local_58 [4];
  int local_54;
  char *local_50;
  undefined4 *local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined *local_40;
  int local_3c;
  char local_35;
  char *local_34;
  undefined *local_30;
  undefined4 *local_2c;
  undefined *local_28;
  int local_24;
  
  local_48 = 0;
  uVar12 = 0;
  puVar14 = (undefined *)0x0;
  piVar9 = (int *)(param_2 + 0x54);
  puVar13 = (undefined *)0xffffffff;
  if (*piVar9 == 0) {
    *piVar9 = *(int *)PTR_PTR_DAT_060e0de0;
  }
  local_54 = param_2;
  local_50 = param_3;
  local_4c = param_4;
  if (*(int *)(*piVar9 + 0x5c) == 0) {
    (*(code *)PTR_FUN_060e0de4)();
  }
  local_2c = local_4c + -1;
  local_34 = local_50 + -1;
switchD_060e0c22_caseD_1:
LAB_060e0b3e:
  puVar4 = PTR_FUN_060e0de8;
  if (uVar12 == 0) {
    cVar1 = *local_50;
    while ((iVar3 = (int)cVar1, iVar3 != 0 && (iVar3 != 0x25))) {
      local_34 = local_34 + 1;
      local_50 = local_50 + 1;
      iVar3 = (*(code *)puVar4)(iVar3,local_54);
      if (iVar3 == -1) {
        return -1;
      }
      local_48 = local_48 + 1;
      cVar1 = *local_50;
    }
    local_28 = (undefined *)(int)*local_50;
    if (local_28 == (undefined *)0x0) {
      return local_48;
    }
    uVar12 = 1;
    local_34 = local_34 + 1;
    local_50 = local_50 + 1;
  }
  pcVar7 = local_50 + 1;
  cVar1 = *local_50;
  local_34 = local_34 + 1;
  local_50 = pcVar7;
  switch(cVar1) {
  case '\0':
    break;
  default:
    goto switchD_060e0c22_caseD_1;
  case ' ':
    uVar12 = uVar12 | 8;
    goto switchD_060e0c22_caseD_1;
  case '#':
    uVar12 = uVar12 | 0x10;
    goto switchD_060e0c22_caseD_1;
  case '%':
    puVar6 = (undefined *)0x1;
    puVar13 = (undefined *)0x0;
    puVar4 = PTR_DAT_060e1370;
    if (1 < (int)puVar14) {
      puVar13 = puVar14 + -1;
    }
    goto LAB_060e12f6;
  case '*':
    if ((uVar12 & 0x20) == 0) goto LAB_060e0e06;
    local_2c = local_2c + 1;
    local_4c = local_4c + 1;
    puVar13 = (undefined *)*local_2c;
    goto switchD_060e0c22_caseD_1;
  case '+':
    uVar12 = uVar12 | 4;
    goto switchD_060e0c22_caseD_1;
  case '-':
    uVar12 = uVar12 | 2;
    goto switchD_060e0c22_caseD_1;
  case '.':
    uVar12 = uVar12 | 0x20;
    puVar13 = (undefined *)0x0;
    goto switchD_060e0c22_caseD_1;
  case '0':
    if ((puVar14 != (undefined *)0x0) || ((uVar12 & 0x20) != 0)) goto LAB_060e0d50;
    uVar12 = uVar12 | 0x40;
    goto switchD_060e0c22_caseD_1;
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
LAB_060e0d50:
    if ((uVar12 & 0x20) == 0) {
      local_28 = (undefined *)((int)puVar14 * 10 + (int)*local_34);
      puVar14 = local_28 + -0x30;
    }
    else {
      local_28 = (undefined *)((int)puVar13 * 10 + (int)*local_34);
      puVar13 = local_28 + -0x30;
    }
    goto switchD_060e0c22_caseD_1;
  case 'L':
    uVar12 = uVar12 | (int)DAT_060e0f12;
    goto switchD_060e0c22_caseD_1;
  case 'X':
  case 'd':
  case 'i':
  case 'o':
  case 'u':
  case 'x':
    if (((int)DAT_060e0f12 & uVar12) == 0) {
      if (((int)DAT_060e0f14 & uVar12) == 0) {
        local_44 = local_2c[1];
      }
      else {
        local_44 = local_2c[1];
      }
      local_4c = local_4c + 1;
      local_2c = local_2c + 1;
      local_28 = (undefined *)(uint)(0 < (int)local_44);
      iVar3 = (int)local_28 - ((local_44 >> 0x10) * 2 >> 0x10);
    }
    else {
      puVar8 = local_4c + 2;
      local_2c = local_2c + 2;
      local_40 = (undefined *)*local_4c;
      local_3c = local_4c[1];
      iVar3 = 0;
      if ((0 < (int)local_40) || ((local_40 == (undefined *)0x0 && (local_3c != 0)))) {
        iVar3 = 1;
      }
      local_4c = puVar8;
      local_28 = local_40;
      if ((int)local_40 < 0) {
        iVar3 = iVar3 + -1;
      }
    }
    bVar2 = puVar13 == (undefined *)0xffffffff;
    if ((bVar2) || (uVar12 = uVar12 & 0xffffffbf, bVar2)) {
      puVar13 = (undefined *)(uint)bVar2;
    }
    local_35 = *local_34;
    if ((puVar13 != (undefined *)0x0) || (iVar3 != 0)) {
      if ((uVar12 & 0x80) == 0) {
        if (((int)DAT_060e10ae & uVar12) == 0) {
          puVar4 = (undefined *)(*(code *)PTR_FUN_060e10b8)(auStack_d8,local_44,(int)local_35);
        }
        else {
          puVar4 = (undefined *)
                   (*(code *)PTR_FUN_060e10b4)(auStack_d8,local_40,local_3c,(int)local_35);
        }
      }
      else {
        puVar4 = (undefined *)
                 (*(code *)PTR_FUN_060e10b0)(auStack_d8,(int)local_44._2_2_,(int)local_35);
      }
      if (puVar4 == (undefined *)0x0) {
        iVar5 = 0;
      }
      else {
        local_30 = puVar4;
        iVar5 = (*(code *)PTR_FUN_060e10bc)(puVar4);
        puVar4 = local_30;
      }
      iVar10 = 0;
      if (iVar5 < (int)puVar13) {
        iVar10 = (int)puVar13 - iVar5;
      }
      puVar13 = (undefined *)0x0;
      if (iVar5 + iVar10 < (int)puVar14) {
        puVar13 = puVar14 + (-iVar10 - iVar5);
      }
      if ((local_35 == 'd') || (local_35 == 'i')) {
        puVar14 = PTR_DAT_060e10c0;
        if ((-1 < iVar3) &&
           ((puVar14 = PTR_DAT_060e10c4, (uVar12 & 4) == 0 &&
            (puVar14 = PTR_DAT_060e10c8, (uVar12 & 8) == 0)))) goto LAB_060e10e8;
      }
      else if (((uVar12 & 0x10) == 0) ||
              (((puVar14 = PTR_DAT_060e10cc, local_35 != 'o' &&
                (puVar14 = PTR_DAT_060e1354, local_35 != 'x')) &&
               (puVar14 = PTR_DAT_060e1358, local_35 != 'X')))) {
LAB_060e10e8:
        puVar14 = (undefined *)0x0;
      }
      if ((puVar13 != (undefined *)0x0) && (puVar14 != (undefined *)0x0)) {
        local_30 = puVar4;
        local_24 = iVar10;
        iVar3 = (*(code *)PTR_FUN_060e135c)(puVar14);
        puVar13 = puVar13 + -iVar3;
        puVar4 = local_30;
        iVar10 = local_24;
      }
      iVar3 = (*(code *)PTR_FUN_060e1360)(puVar4,iVar5,uVar12,iVar10,puVar13,puVar14,local_54);
      if (iVar3 == -1) {
        return -1;
      }
      uVar12 = 0;
      puVar14 = (undefined *)0x0;
      puVar13 = (undefined *)0xffffffff;
      local_48 = local_48 + iVar3;
      goto switchD_060e0c22_caseD_1;
    }
    break;
  case 'c':
    local_2c = local_2c + 1;
    puVar13 = (undefined *)0x0;
    puVar8 = local_4c + 1;
    local_28 = (undefined *)((int)local_4c + 3);
    puVar6 = (undefined *)0x1;
    local_58[0] = *local_28;
    puVar4 = local_58;
    local_4c = puVar8;
    if (1 < (int)puVar14) {
      puVar13 = puVar14 + -1;
    }
    goto LAB_060e12f6;
  case 'h':
    uVar12 = uVar12 | 0x80;
    goto switchD_060e0c22_caseD_1;
  case 'l':
    uVar12 = uVar12 | (int)DAT_060e0f10;
    goto switchD_060e0c22_caseD_1;
  case 'n':
    if ((uVar12 & 0x80) == 0) {
      local_2c = local_2c + 1;
      local_4c = local_4c + 1;
      *(int *)*local_2c = local_48;
    }
    else {
      local_2c = local_2c + 1;
      local_4c = local_4c + 1;
      *(undefined2 *)*local_2c = local_48._2_2_;
    }
    break;
  case 'p':
    local_2c = local_2c + 1;
    local_4c = local_4c + 1;
    puVar4 = (undefined *)(*(code *)PTR_FUN_060e136c)(auStack_d8,*local_2c,0x78);
    if (puVar4 == (undefined *)0x0) {
      puVar6 = (undefined *)0x0;
    }
    else {
      local_30 = puVar4;
      puVar6 = (undefined *)(*(code *)PTR_FUN_060e135c)(puVar4);
      puVar4 = local_30;
    }
    iVar3 = 0;
    if ((int)puVar6 < 8) {
      iVar3 = 8 - (int)puVar6;
    }
    uVar12 = 0x40;
    puVar13 = (undefined *)0x0;
    puVar14 = PTR_DAT_060e1354;
    goto LAB_060e1304;
  case 's':
    local_2c = local_2c + 1;
    local_4c = local_4c + 1;
    puVar4 = (undefined *)*local_2c;
    if ((undefined *)*local_2c == (undefined *)0x0) {
      puVar4 = PTR_s__null__060e1364;
    }
    puVar6 = (undefined *)(*(code *)PTR_FUN_060e135c)(puVar4);
    puVar11 = puVar6;
    if ((puVar13 == (undefined *)0xffffffff) || (puVar11 = puVar13, (int)puVar13 < (int)puVar6)) {
      puVar6 = puVar11;
    }
    puVar13 = (undefined *)0x0;
    if ((int)puVar6 < (int)puVar14) {
      puVar13 = puVar14 + -(int)puVar6;
    }
LAB_060e12f6:
    iVar3 = 0;
    puVar14 = PTR_DAT_060e1368;
LAB_060e1304:
    iVar3 = (*(code *)PTR_FUN_060e1360)(puVar4,puVar6,uVar12,iVar3,puVar13,puVar14,local_54);
    if (iVar3 == -1) {
      return -1;
    }
    uVar12 = 0;
    puVar14 = (undefined *)0x0;
    puVar13 = (undefined *)0xffffffff;
    local_48 = local_48 + iVar3;
    goto switchD_060e0c22_caseD_1;
  }
  uVar12 = 0;
  puVar14 = (undefined *)0x0;
  puVar13 = (undefined *)0xffffffff;
  goto switchD_060e0c22_caseD_1;
LAB_060e0e06:
  local_2c = local_2c + 1;
  local_4c = local_4c + 1;
  puVar14 = (undefined *)*local_2c;
  if ((int)puVar14 < 0) goto LAB_060e0e20;
  goto LAB_060e0b3e;
LAB_060e0e20:
  uVar12 = uVar12 | 2;
  puVar14 = (undefined *)-(int)puVar14;
  goto switchD_060e0c22_caseD_1;
}



void FUN_060e1374(int *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  ushort *puVar4;
  undefined auStack_54 [4];
  uint uStack_50;
  
  puVar4 = (ushort *)(param_1 + 3);
  if ((*puVar4 & 2) == 0) {
    bVar1 = false;
    if ((*(short *)((int)param_1 + 0xe) < 0) ||
       (iVar2 = (*(code *)PTR_FUN_060e1478)
                          (param_1[0x15],(int)*(short *)((int)param_1 + 0xe),auStack_54), iVar2 < 0)
       ) {
      iVar2 = (int)(short)DAT_060e1470;
      *puVar4 = *puVar4 | DAT_060e1472;
    }
    else {
      iVar2 = (int)(short)DAT_060e1470;
      bVar1 = (uStack_50 & DAT_060e147c) == (int)DAT_060e1474;
      if (((uStack_50 & DAT_060e147c) == DAT_060e1480) &&
         ((undefined *)param_1[10] == PTR_LAB_060e1484)) {
        *puVar4 = *puVar4 | DAT_060e1470;
        param_1[0x13] = iVar2;
      }
      else {
        *(ushort *)(param_1 + 3) = *(ushort *)(param_1 + 3) | DAT_060e1472;
      }
    }
    iVar3 = (*(code *)PTR_FUN_060e1488)(param_1[0x15],iVar2);
    if (iVar3 == 0) {
      *(ushort *)(param_1 + 3) = *(ushort *)(param_1 + 3) | 2;
      *param_1 = (int)param_1 + 0x43;
      param_1[4] = (int)param_1 + 0x43;
      param_1[5] = (uint)(iVar3 == 0);
    }
    else {
      *(undefined **)(param_1[0x15] + 0x60) = PTR_LAB_060e148c;
      puVar4 = (ushort *)(param_1 + 3);
      *puVar4 = *puVar4 | 0x80;
      *param_1 = iVar3;
      param_1[4] = iVar3;
      param_1[5] = iVar2;
      if ((bVar1) &&
         (iVar2 = (*(code *)PTR_FUN_060e1490)((int)*(short *)((int)param_1 + 0xe)), iVar2 != 0)) {
        *puVar4 = *puVar4 | 1;
      }
    }
    return;
  }
  *param_1 = (int)param_1 + 0x43;
  param_1[4] = (int)param_1 + 0x43;
  param_1[5] = 1;
  return;
}



undefined4 FUN_060e1494(void)

{
  int iVar1;
  int in_vbr;
  undefined8 uVar2;
  
  uVar2 = (**(code **)(in_vbr + 0x88))();
  iVar1 = (int)((ulonglong)uVar2 >> 0x20);
  if (iVar1 != 0) {
    *DAT_060e14a4 = iVar1;
  }
  return (int)uVar2;
}



void FUN_060e14a8(void)

{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR_FUN_060e14c8;
  puVar1 = PTR_FUN_060e14c4;
  do {
    (*(code *)puVar1)(6);
    (*(code *)puVar2)(1);
  } while( true );
}



void FUN_060e14cc(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  
  piVar1 = DAT_060e14fc;
  *DAT_060e14fc = 0;
  (*(code *)PTR_FUN_060e1500)(param_2,param_3);
  if (*piVar1 != 0) {
    *param_1 = *piVar1;
  }
  return;
}



void FUN_060e1504(undefined4 param_1)

{
  (*(code *)PTR_FUN_060e1520)(*(undefined4 *)PTR_PTR_DAT_060e151c,param_1);
  return;
}



void FUN_060e1524(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)PTR_FUN_060e1550)();
  (*(code *)PTR_FUN_060e1554)(param_1,uVar1,param_2);
  return;
}



void FUN_060e1558(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  
  piVar1 = DAT_060e1588;
  *DAT_060e1588 = 0;
  (*(code *)PTR_FUN_060e158c)(param_2,param_3);
  if (*piVar1 != 0) {
    *param_1 = *piVar1;
  }
  return;
}



void FUN_060e1590(void)

{
  (*(code *)PTR_FUN_060e15a4)();
  return;
}



uint FUN_060e15a8(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_2 < 0x20) {
    uVar1 = (int)param_1 >> 1;
    uVar2 = param_1;
    switch(param_2) {
    case 0:
      return param_1;
    case 0xf:
      param_1 = uVar1;
    case 0xe:
      param_1 = (int)param_1 >> 1;
    case 0xd:
      param_1 = (int)param_1 >> 1;
    case 0xc:
      param_1 = (int)param_1 >> 1;
    case 0xb:
      param_1 = (int)param_1 >> 1;
    case 10:
      param_1 = (int)param_1 >> 1;
    case 9:
      param_1 = (int)param_1 >> 1;
    case 8:
      param_1 = (int)param_1 >> 1;
    case 7:
      param_1 = (int)param_1 >> 1;
    case 6:
      param_1 = (int)param_1 >> 1;
    case 5:
      param_1 = (int)param_1 >> 1;
    case 4:
      param_1 = (int)param_1 >> 1;
    case 3:
      param_1 = (int)param_1 >> 1;
    case 2:
      param_1 = (int)param_1 >> 1;
    case 1:
      return (int)param_1 >> 1;
    case 0x17:
      param_1 = uVar1;
    case 0x16:
      param_1 = (int)param_1 >> 1;
    case 0x15:
      param_1 = (int)param_1 >> 1;
    case 0x14:
      param_1 = (int)param_1 >> 1;
    case 0x13:
      param_1 = (int)param_1 >> 1;
    case 0x12:
      param_1 = (int)param_1 >> 1;
    case 0x11:
      param_1 = (int)param_1 >> 1;
    case 0x10:
      return (int)(short)(param_1 >> 0x10);
    case 0x1e:
      param_1 = uVar1;
    case 0x1d:
      param_1 = (int)param_1 >> 1;
    case 0x1c:
      param_1 = (int)param_1 >> 1;
    case 0x1b:
      param_1 = (int)param_1 >> 1;
    case 0x1a:
      param_1 = (int)param_1 >> 1;
    case 0x19:
      param_1 = (int)param_1 >> 1;
    case 0x18:
      return (int)(char)(param_1 >> 0x18);
    }
  }
  return -(uint)((uVar2 & 0x80000000) != 0);
}



uint FUN_060e162c(uint param_1,int param_2)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  uint uVar9;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  uint uVar39;
  uint uVar40;
  uint uVar8;
  uint uVar10;
  
  uVar7 = (uint)((param_1 & 0x80000000) != 0);
  uVar8 = uVar7 - param_2;
  bVar4 = uVar8 <= uVar7;
  uVar12 = param_1 << 2;
  bVar3 = (uVar8 & 0x80000000) == 0;
  uVar7 = uVar8 * 2 | (uint)((param_1 & 0x40000000) != 0);
  uVar8 = (uint)bVar4 * (uVar7 - param_2) + (uint)!bVar4 * (uVar7 + param_2);
  cVar1 = bVar4 * (uVar7 < uVar8) + !bVar4 * (uVar8 < uVar7);
  bVar5 = bVar3 * cVar1 + (!bVar3 && cVar1 == '\0');
  uVar7 = (uint)bVar5 << 8;
  uVar9 = uVar8 * 2 | (uint)((uVar12 & 0x80000000) != 0);
  bVar3 = (bVar5 & 1) == ((byte)(uVar7 >> 9) & 1);
  bVar2 = (bool)((byte)(uVar7 >> 9) & 1) == ((uVar8 & 0x80000000) != 0);
  uVar10 = (uint)bVar3 * (uVar9 - param_2) + (uint)!bVar3 * (uVar9 + param_2);
  cVar1 = bVar3 * (uVar9 < uVar10) + !bVar3 * (uVar10 < uVar9);
  uVar8 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar13 = uVar7 & 0xfffffeff | uVar8;
  uVar6 = uVar7 & 0xfffffefe;
  uVar9 = uVar6 | uVar8;
  uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x40000000) != 0);
  bVar3 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
  bVar2 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
  uVar10 = (uint)bVar3 * (uVar11 - param_2) + (uint)!bVar3 * (uVar11 + param_2);
  cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
  uVar9 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar14 = uVar6 | uVar8 & 0xfffffeff | uVar9;
  uVar6 = uVar6 | uVar8 & 0xfffffefe;
  uVar8 = uVar6 | uVar9;
  uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x20000000) != 0);
  bVar3 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
  bVar2 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
  uVar10 = (uint)bVar3 * (uVar11 - param_2) + (uint)!bVar3 * (uVar11 + param_2);
  cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
  uVar8 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar15 = uVar6 | uVar9 & 0xfffffeff | uVar8;
  uVar6 = uVar6 | uVar9 & 0xfffffefe;
  uVar9 = uVar6 | uVar8;
  uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x10000000) != 0);
  bVar3 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
  bVar2 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
  uVar10 = (uint)bVar3 * (uVar11 - param_2) + (uint)!bVar3 * (uVar11 + param_2);
  cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
  uVar9 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar16 = uVar6 | uVar8 & 0xfffffeff | uVar9;
  uVar6 = uVar6 | uVar8 & 0xfffffefe;
  uVar8 = uVar6 | uVar9;
  uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x8000000) != 0);
  bVar3 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
  bVar2 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
  uVar10 = (uint)bVar3 * (uVar11 - param_2) + (uint)!bVar3 * (uVar11 + param_2);
  cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
  uVar8 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar17 = uVar6 | uVar9 & 0xfffffeff | uVar8;
  uVar6 = uVar6 | uVar9 & 0xfffffefe;
  uVar9 = uVar6 | uVar8;
  uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x4000000) != 0);
  bVar3 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
  bVar2 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
  uVar10 = (uint)bVar3 * (uVar11 - param_2) + (uint)!bVar3 * (uVar11 + param_2);
  cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
  uVar9 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar18 = uVar6 | uVar8 & 0xfffffeff | uVar9;
  uVar6 = uVar6 | uVar8 & 0xfffffefe;
  uVar8 = uVar6 | uVar9;
  uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x2000000) != 0);
  bVar3 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
  bVar2 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
  uVar10 = (uint)bVar3 * (uVar11 - param_2) + (uint)!bVar3 * (uVar11 + param_2);
  cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
  uVar8 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar19 = uVar6 | uVar9 & 0xfffffeff | uVar8;
  uVar6 = uVar6 | uVar9 & 0xfffffefe;
  uVar9 = uVar6 | uVar8;
  uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x1000000) != 0);
  bVar3 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
  bVar2 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
  uVar10 = (uint)bVar3 * (uVar11 - param_2) + (uint)!bVar3 * (uVar11 + param_2);
  cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
  uVar9 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar20 = uVar6 | uVar8 & 0xfffffeff | uVar9;
  uVar6 = uVar6 | uVar8 & 0xfffffefe;
  uVar8 = uVar6 | uVar9;
  uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x800000) != 0);
  bVar3 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
  bVar2 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
  uVar10 = (uint)bVar3 * (uVar11 - param_2) + (uint)!bVar3 * (uVar11 + param_2);
  cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
  uVar8 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar21 = uVar6 | uVar9 & 0xfffffeff | uVar8;
  uVar6 = uVar6 | uVar9 & 0xfffffefe;
  uVar9 = uVar6 | uVar8;
  uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x400000) != 0);
  bVar3 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
  bVar2 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
  uVar10 = (uint)bVar3 * (uVar11 - param_2) + (uint)!bVar3 * (uVar11 + param_2);
  cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
  uVar9 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar22 = uVar6 | uVar8 & 0xfffffeff | uVar9;
  uVar6 = uVar6 | uVar8 & 0xfffffefe;
  uVar8 = uVar6 | uVar9;
  uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x200000) != 0);
  bVar3 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
  bVar2 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
  uVar10 = (uint)bVar3 * (uVar11 - param_2) + (uint)!bVar3 * (uVar11 + param_2);
  cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
  uVar8 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar23 = uVar6 | uVar9 & 0xfffffeff | uVar8;
  uVar6 = uVar6 | uVar9 & 0xfffffefe;
  uVar9 = uVar6 | uVar8;
  uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x100000) != 0);
  bVar3 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
  bVar2 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
  uVar10 = (uint)bVar3 * (uVar11 - param_2) + (uint)!bVar3 * (uVar11 + param_2);
  cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
  uVar9 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar24 = uVar6 | uVar8 & 0xfffffeff | uVar9;
  uVar6 = uVar6 | uVar8 & 0xfffffefe;
  uVar8 = uVar6 | uVar9;
  uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x80000) != 0);
  bVar3 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
  bVar2 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
  uVar10 = (uint)bVar3 * (uVar11 - param_2) + (uint)!bVar3 * (uVar11 + param_2);
  cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
  uVar8 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar25 = uVar6 | uVar9 & 0xfffffeff | uVar8;
  uVar6 = uVar6 | uVar9 & 0xfffffefe;
  uVar9 = uVar6 | uVar8;
  uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x40000) != 0);
  bVar3 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
  bVar2 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
  uVar10 = (uint)bVar3 * (uVar11 - param_2) + (uint)!bVar3 * (uVar11 + param_2);
  cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
  uVar9 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar26 = uVar6 | uVar8 & 0xfffffeff | uVar9;
  uVar6 = uVar6 | uVar8 & 0xfffffefe;
  uVar8 = uVar6 | uVar9;
  uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x20000) != 0);
  bVar3 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
  bVar2 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
  uVar10 = (uint)bVar3 * (uVar11 - param_2) + (uint)!bVar3 * (uVar11 + param_2);
  cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
  uVar8 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar27 = uVar6 | uVar9 & 0xfffffeff | uVar8;
  uVar6 = uVar6 | uVar9 & 0xfffffefe;
  uVar9 = uVar6 | uVar8;
  uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x10000) != 0);
  bVar3 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
  bVar2 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
  uVar10 = (uint)bVar3 * (uVar11 - param_2) + (uint)!bVar3 * (uVar11 + param_2);
  cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
  uVar9 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar28 = uVar6 | uVar8 & 0xfffffeff | uVar9;
  uVar6 = uVar6 | uVar8 & 0xfffffefe;
  uVar8 = uVar6 | uVar9;
  uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x8000) != 0);
  bVar3 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
  bVar2 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
  uVar10 = (uint)bVar3 * (uVar11 - param_2) + (uint)!bVar3 * (uVar11 + param_2);
  cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
  uVar8 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar29 = uVar6 | uVar9 & 0xfffffeff | uVar8;
  uVar6 = uVar6 | uVar9 & 0xfffffefe;
  uVar9 = uVar6 | uVar8;
  uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x4000) != 0);
  bVar3 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
  bVar2 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
  uVar10 = (uint)bVar3 * (uVar11 - param_2) + (uint)!bVar3 * (uVar11 + param_2);
  cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
  uVar9 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar30 = uVar6 | uVar8 & 0xfffffeff | uVar9;
  uVar6 = uVar6 | uVar8 & 0xfffffefe;
  uVar8 = uVar6 | uVar9;
  uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x2000) != 0);
  bVar3 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
  bVar2 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
  uVar10 = (uint)bVar3 * (uVar11 - param_2) + (uint)!bVar3 * (uVar11 + param_2);
  cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
  uVar8 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar31 = uVar6 | uVar9 & 0xfffffeff | uVar8;
  uVar6 = uVar6 | uVar9 & 0xfffffefe;
  uVar9 = uVar6 | uVar8;
  uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x1000) != 0);
  bVar3 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
  bVar2 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
  uVar10 = (uint)bVar3 * (uVar11 - param_2) + (uint)!bVar3 * (uVar11 + param_2);
  cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
  uVar9 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar32 = uVar6 | uVar8 & 0xfffffeff | uVar9;
  uVar6 = uVar6 | uVar8 & 0xfffffefe;
  uVar8 = uVar6 | uVar9;
  uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x800) != 0);
  bVar3 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
  bVar2 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
  uVar10 = (uint)bVar3 * (uVar11 - param_2) + (uint)!bVar3 * (uVar11 + param_2);
  cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
  uVar8 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar33 = uVar6 | uVar9 & 0xfffffeff | uVar8;
  uVar6 = uVar6 | uVar9 & 0xfffffefe;
  uVar9 = uVar6 | uVar8;
  uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x400) != 0);
  bVar3 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
  bVar2 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
  uVar10 = (uint)bVar3 * (uVar11 - param_2) + (uint)!bVar3 * (uVar11 + param_2);
  cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
  uVar9 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar34 = uVar6 | uVar8 & 0xfffffeff | uVar9;
  uVar6 = uVar6 | uVar8 & 0xfffffefe;
  uVar8 = uVar6 | uVar9;
  uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x200) != 0);
  bVar3 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
  bVar2 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
  uVar10 = (uint)bVar3 * (uVar11 - param_2) + (uint)!bVar3 * (uVar11 + param_2);
  cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
  uVar8 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar35 = uVar6 | uVar9 & 0xfffffeff | uVar8;
  uVar6 = uVar6 | uVar9 & 0xfffffefe;
  uVar9 = uVar6 | uVar8;
  uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x100) != 0);
  bVar3 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
  bVar2 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
  uVar10 = (uint)bVar3 * (uVar11 - param_2) + (uint)!bVar3 * (uVar11 + param_2);
  cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
  uVar9 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar36 = uVar6 | uVar8 & 0xfffffeff | uVar9;
  uVar6 = uVar6 | uVar8 & 0xfffffefe;
  uVar8 = uVar6 | uVar9;
  uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x80) != 0);
  bVar3 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
  bVar2 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
  uVar10 = (uint)bVar3 * (uVar11 - param_2) + (uint)!bVar3 * (uVar11 + param_2);
  cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
  uVar8 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar37 = uVar6 | uVar9 & 0xfffffeff | uVar8;
  uVar6 = uVar6 | uVar9 & 0xfffffefe;
  uVar9 = uVar6 | uVar8;
  uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x40) != 0);
  bVar3 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
  bVar2 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
  uVar10 = (uint)bVar3 * (uVar11 - param_2) + (uint)!bVar3 * (uVar11 + param_2);
  cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
  uVar9 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar38 = uVar6 | uVar8 & 0xfffffeff | uVar9;
  uVar6 = uVar6 | uVar8 & 0xfffffefe;
  uVar8 = uVar6 | uVar9;
  uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x20) != 0);
  bVar3 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
  bVar2 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
  uVar10 = (uint)bVar3 * (uVar11 - param_2) + (uint)!bVar3 * (uVar11 + param_2);
  cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
  uVar8 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar39 = uVar6 | uVar9 & 0xfffffeff | uVar8;
  uVar6 = uVar6 | uVar9 & 0xfffffefe;
  uVar9 = uVar6 | uVar8;
  uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x10) != 0);
  bVar3 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
  bVar2 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
  uVar10 = (uint)bVar3 * (uVar11 - param_2) + (uint)!bVar3 * (uVar11 + param_2);
  cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
  uVar9 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar40 = uVar6 | uVar8 & 0xfffffeff | uVar9;
  uVar6 = uVar6 | uVar8 & 0xfffffefe;
  uVar8 = uVar6 | uVar9;
  uVar11 = uVar10 * 2 | (uint)((uVar12 & 8) != 0);
  bVar3 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
  bVar2 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
  uVar10 = (uint)bVar3 * (uVar11 - param_2) + (uint)!bVar3 * (uVar11 + param_2);
  cVar1 = bVar3 * (uVar11 < uVar10) + !bVar3 * (uVar10 < uVar11);
  uVar8 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  uVar11 = uVar6 | uVar9 & 0xfffffeff | uVar8;
  uVar6 = uVar6 | uVar9 & 0xfffffefe;
  uVar9 = uVar6 | uVar8;
  uVar12 = uVar10 * 2 | (uint)((uVar12 & 4) != 0);
  bVar3 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
  bVar2 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
  uVar9 = (uint)bVar3 * (uVar12 - param_2) + (uint)!bVar3 * (uVar12 + param_2);
  cVar1 = bVar3 * (uVar12 < uVar9) + !bVar3 * (uVar9 < uVar12);
  uVar8 = uVar6 | uVar8 & 0xfffffeff | (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
  return (((((((((((((((((((((((((((((((uint)bVar4 << 1 |
                                      (uint)((bVar5 & 1) == ((byte)(uVar7 >> 9) & 1))) << 1 |
                                     (uint)(((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1)))
                                     << 1 | (uint)(((byte)(uVar14 >> 8) & 1) ==
                                                  ((byte)(uVar14 >> 9) & 1))) << 1 |
                                   (uint)(((byte)(uVar15 >> 8) & 1) == ((byte)(uVar15 >> 9) & 1)))
                                   << 1 | (uint)(((byte)(uVar16 >> 8) & 1) ==
                                                ((byte)(uVar16 >> 9) & 1))) << 1 |
                                 (uint)(((byte)(uVar17 >> 8) & 1) == ((byte)(uVar17 >> 9) & 1))) <<
                                 1 | (uint)(((byte)(uVar18 >> 8) & 1) == ((byte)(uVar18 >> 9) & 1)))
                                << 1 | (uint)(((byte)(uVar19 >> 8) & 1) == ((byte)(uVar19 >> 9) & 1)
                                             )) << 1 |
                              (uint)(((byte)(uVar20 >> 8) & 1) == ((byte)(uVar20 >> 9) & 1))) << 1 |
                             (uint)(((byte)(uVar21 >> 8) & 1) == ((byte)(uVar21 >> 9) & 1))) << 1 |
                            (uint)(((byte)(uVar22 >> 8) & 1) == ((byte)(uVar22 >> 9) & 1))) << 1 |
                           (uint)(((byte)(uVar23 >> 8) & 1) == ((byte)(uVar23 >> 9) & 1))) << 1 |
                          (uint)(((byte)(uVar24 >> 8) & 1) == ((byte)(uVar24 >> 9) & 1))) << 1 |
                         (uint)(((byte)(uVar25 >> 8) & 1) == ((byte)(uVar25 >> 9) & 1))) << 1 |
                        (uint)(((byte)(uVar26 >> 8) & 1) == ((byte)(uVar26 >> 9) & 1))) << 1 |
                       (uint)(((byte)(uVar27 >> 8) & 1) == ((byte)(uVar27 >> 9) & 1))) << 1 |
                      (uint)(((byte)(uVar28 >> 8) & 1) == ((byte)(uVar28 >> 9) & 1))) << 1 |
                     (uint)(((byte)(uVar29 >> 8) & 1) == ((byte)(uVar29 >> 9) & 1))) << 1 |
                    (uint)(((byte)(uVar30 >> 8) & 1) == ((byte)(uVar30 >> 9) & 1))) << 1 |
                   (uint)(((byte)(uVar31 >> 8) & 1) == ((byte)(uVar31 >> 9) & 1))) << 1 |
                  (uint)(((byte)(uVar32 >> 8) & 1) == ((byte)(uVar32 >> 9) & 1))) << 1 |
                 (uint)(((byte)(uVar33 >> 8) & 1) == ((byte)(uVar33 >> 9) & 1))) << 1 |
                (uint)(((byte)(uVar34 >> 8) & 1) == ((byte)(uVar34 >> 9) & 1))) << 1 |
               (uint)(((byte)(uVar35 >> 8) & 1) == ((byte)(uVar35 >> 9) & 1))) << 1 |
              (uint)(((byte)(uVar36 >> 8) & 1) == ((byte)(uVar36 >> 9) & 1))) << 1 |
             (uint)(((byte)(uVar37 >> 8) & 1) == ((byte)(uVar37 >> 9) & 1))) << 1 |
            (uint)(((byte)(uVar38 >> 8) & 1) == ((byte)(uVar38 >> 9) & 1))) << 1 |
           (uint)(((byte)(uVar39 >> 8) & 1) == ((byte)(uVar39 >> 9) & 1))) << 1 |
          (uint)(((byte)(uVar40 >> 8) & 1) == ((byte)(uVar40 >> 9) & 1))) << 1 |
         (uint)(((byte)(uVar11 >> 8) & 1) == ((byte)(uVar11 >> 9) & 1))) << 1 |
         (uint)(((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1));
}



void FUN_060e16ca(void)

{
  return;
}



void FUN_060e16e6(void)

{
  return;
}



void FUN_060e16ec(void)

{
  return;
}



void FUN_060e16ee(void)

{
  return;
}



void FUN_060e16f0(void)

{
  return;
}



void FUN_060e16f4(void)

{
  return;
}



void FUN_060e16f6(void)

{
  return;
}



int FUN_060e170c(int param_1,undefined4 param_2)

{
  switch(param_2) {
  case 0:
    return param_1;
  case 6:
    param_1 = param_1 << 2;
  case 4:
    param_1 = param_1 << 2;
  case 2:
    return param_1 << 2;
  case 7:
    param_1 = param_1 << 2;
  case 5:
    param_1 = param_1 << 2;
  case 3:
    param_1 = param_1 << 2;
  case 1:
    return param_1 << 1;
  case 0xe:
    param_1 = param_1 << 2;
  case 0xc:
    param_1 = param_1 << 2;
  case 10:
    param_1 = param_1 << 2;
  case 8:
    return param_1 << 8;
  case 0xf:
    param_1 = param_1 << 2;
  case 0xd:
    param_1 = param_1 << 2;
  case 0xb:
    param_1 = param_1 << 2;
  case 9:
    return param_1 << 9;
  case 0x16:
    param_1 = param_1 << 2;
  case 0x14:
    param_1 = param_1 << 2;
  case 0x12:
    param_1 = param_1 << 2;
  case 0x10:
    return param_1 << 0x10;
  case 0x17:
    param_1 = param_1 << 2;
  case 0x15:
    param_1 = param_1 << 2;
  case 0x13:
    param_1 = param_1 << 2;
  case 0x11:
    return param_1 << 0x11;
  case 0x1e:
    param_1 = param_1 << 2;
  case 0x1c:
    param_1 = param_1 << 2;
  case 0x1a:
    param_1 = param_1 << 2;
  case 0x18:
    return param_1 << 0x18;
  case 0x1f:
    param_1 = param_1 << 2;
  case 0x1d:
    param_1 = param_1 << 2;
  case 0x1b:
    param_1 = param_1 << 2;
  case 0x19:
    return param_1 << 0x19;
  default:
    return 0;
  }
}



int FUN_060e179c(int param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  bool bVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar11;
  uint uVar12;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  uint uVar39;
  uint uVar40;
  uint uVar41;
  uint uVar42;
  uint uVar10;
  uint uVar13;
  
  if (param_2 != 0) {
    uVar6 = (uint)(param_1 < 0);
    uVar7 = param_1 - (uint)(-uVar6 != 0);
    bVar1 = param_2 < 0;
    uVar2 = (uint)bVar1 << 9;
    uVar12 = uVar7 * 2;
    uVar7 = uVar6 * -2 | (uint)((uVar7 & 0x80000000) != 0);
    bVar4 = (uVar6 != 0) == bVar1;
    bVar5 = bVar1 == ((-uVar6 & 0x80000000) != 0);
    uVar8 = (uint)bVar4 * (uVar7 - param_2) + (uint)!bVar4 * (uVar7 + param_2);
    cVar3 = bVar4 * (uVar7 < uVar8) + !bVar4 * (uVar8 < uVar7);
    uVar7 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar13 = uVar2 | uVar7;
    uVar9 = uVar8 * 2 | (uint)((uVar12 & 0x80000000) != 0);
    bVar4 = ((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar13 >> 9) & 1) == ((uVar8 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar9 - param_2) + (uint)!bVar4 * (uVar9 + param_2);
    cVar3 = bVar4 * (uVar9 < uVar10) + !bVar4 * (uVar10 < uVar9);
    uVar13 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar14 = uVar2 | uVar7 & 0xfffffeff | uVar13;
    uVar9 = uVar2 | uVar7 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x40000000) != 0);
    bVar4 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - param_2) + (uint)!bVar4 * (uVar11 + param_2);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar15 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x20000000) != 0);
    bVar4 = ((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - param_2) + (uint)!bVar4 * (uVar11 + param_2);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar16 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x10000000) != 0);
    bVar4 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - param_2) + (uint)!bVar4 * (uVar11 + param_2);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar17 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x8000000) != 0);
    bVar4 = ((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - param_2) + (uint)!bVar4 * (uVar11 + param_2);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar18 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x4000000) != 0);
    bVar4 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - param_2) + (uint)!bVar4 * (uVar11 + param_2);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar19 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x2000000) != 0);
    bVar4 = ((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - param_2) + (uint)!bVar4 * (uVar11 + param_2);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar20 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x1000000) != 0);
    bVar4 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - param_2) + (uint)!bVar4 * (uVar11 + param_2);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar21 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x800000) != 0);
    bVar4 = ((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - param_2) + (uint)!bVar4 * (uVar11 + param_2);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar22 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x400000) != 0);
    bVar4 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - param_2) + (uint)!bVar4 * (uVar11 + param_2);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar23 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x200000) != 0);
    bVar4 = ((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - param_2) + (uint)!bVar4 * (uVar11 + param_2);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar24 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x100000) != 0);
    bVar4 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - param_2) + (uint)!bVar4 * (uVar11 + param_2);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar25 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x80000) != 0);
    bVar4 = ((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - param_2) + (uint)!bVar4 * (uVar11 + param_2);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar26 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x40000) != 0);
    bVar4 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - param_2) + (uint)!bVar4 * (uVar11 + param_2);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar27 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x20000) != 0);
    bVar4 = ((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - param_2) + (uint)!bVar4 * (uVar11 + param_2);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar28 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x10000) != 0);
    bVar4 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - param_2) + (uint)!bVar4 * (uVar11 + param_2);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar29 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x8000) != 0);
    bVar4 = ((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - param_2) + (uint)!bVar4 * (uVar11 + param_2);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar30 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x4000) != 0);
    bVar4 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - param_2) + (uint)!bVar4 * (uVar11 + param_2);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar31 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x2000) != 0);
    bVar4 = ((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - param_2) + (uint)!bVar4 * (uVar11 + param_2);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar32 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x1000) != 0);
    bVar4 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - param_2) + (uint)!bVar4 * (uVar11 + param_2);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar33 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x800) != 0);
    bVar4 = ((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - param_2) + (uint)!bVar4 * (uVar11 + param_2);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar34 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x400) != 0);
    bVar4 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - param_2) + (uint)!bVar4 * (uVar11 + param_2);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar35 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x200) != 0);
    bVar4 = ((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - param_2) + (uint)!bVar4 * (uVar11 + param_2);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar36 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x100) != 0);
    bVar4 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - param_2) + (uint)!bVar4 * (uVar11 + param_2);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar37 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x80) != 0);
    bVar4 = ((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - param_2) + (uint)!bVar4 * (uVar11 + param_2);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar38 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x40) != 0);
    bVar4 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - param_2) + (uint)!bVar4 * (uVar11 + param_2);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar39 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x20) != 0);
    bVar4 = ((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - param_2) + (uint)!bVar4 * (uVar11 + param_2);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar40 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x10) != 0);
    bVar4 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - param_2) + (uint)!bVar4 * (uVar11 + param_2);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar41 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 8) != 0);
    bVar4 = ((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - param_2) + (uint)!bVar4 * (uVar11 + param_2);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar42 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 4) != 0);
    bVar4 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - param_2) + (uint)!bVar4 * (uVar11 + param_2);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar11 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar12 = uVar10 * 2 | (uint)((uVar12 & 2) != 0);
    bVar4 = ((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar13 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
    cVar3 = bVar4 * (uVar12 < uVar13) + !bVar4 * (uVar13 < uVar12);
    uVar13 = uVar9 | uVar8 & 0xfffffeff |
             (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    return ((((((((((((((((((((((((((((((((uint)(((byte)((uVar2 | uVar7) >> 8) & 1) ==
                                                ((byte)((uVar2 | uVar7) >> 9) & 1)) << 1 |
                                         (uint)(((byte)(uVar14 >> 8) & 1) ==
                                               ((byte)(uVar14 >> 9) & 1))) << 1 |
                                        (uint)(((byte)(uVar15 >> 8) & 1) ==
                                              ((byte)(uVar15 >> 9) & 1))) << 1 |
                                       (uint)(((byte)(uVar16 >> 8) & 1) == ((byte)(uVar16 >> 9) & 1)
                                             )) << 1 |
                                      (uint)(((byte)(uVar17 >> 8) & 1) == ((byte)(uVar17 >> 9) & 1))
                                      ) << 1 | (uint)(((byte)(uVar18 >> 8) & 1) ==
                                                     ((byte)(uVar18 >> 9) & 1))) << 1 |
                                    (uint)(((byte)(uVar19 >> 8) & 1) == ((byte)(uVar19 >> 9) & 1)))
                                    << 1 | (uint)(((byte)(uVar20 >> 8) & 1) ==
                                                 ((byte)(uVar20 >> 9) & 1))) << 1 |
                                  (uint)(((byte)(uVar21 >> 8) & 1) == ((byte)(uVar21 >> 9) & 1))) <<
                                  1 | (uint)(((byte)(uVar22 >> 8) & 1) == ((byte)(uVar22 >> 9) & 1))
                                 ) << 1 | (uint)(((byte)(uVar23 >> 8) & 1) ==
                                                ((byte)(uVar23 >> 9) & 1))) << 1 |
                               (uint)(((byte)(uVar24 >> 8) & 1) == ((byte)(uVar24 >> 9) & 1))) << 1
                              | (uint)(((byte)(uVar25 >> 8) & 1) == ((byte)(uVar25 >> 9) & 1))) << 1
                             | (uint)(((byte)(uVar26 >> 8) & 1) == ((byte)(uVar26 >> 9) & 1))) << 1
                            | (uint)(((byte)(uVar27 >> 8) & 1) == ((byte)(uVar27 >> 9) & 1))) << 1 |
                           (uint)(((byte)(uVar28 >> 8) & 1) == ((byte)(uVar28 >> 9) & 1))) << 1 |
                          (uint)(((byte)(uVar29 >> 8) & 1) == ((byte)(uVar29 >> 9) & 1))) << 1 |
                         (uint)(((byte)(uVar30 >> 8) & 1) == ((byte)(uVar30 >> 9) & 1))) << 1 |
                        (uint)(((byte)(uVar31 >> 8) & 1) == ((byte)(uVar31 >> 9) & 1))) << 1 |
                       (uint)(((byte)(uVar32 >> 8) & 1) == ((byte)(uVar32 >> 9) & 1))) << 1 |
                      (uint)(((byte)(uVar33 >> 8) & 1) == ((byte)(uVar33 >> 9) & 1))) << 1 |
                     (uint)(((byte)(uVar34 >> 8) & 1) == ((byte)(uVar34 >> 9) & 1))) << 1 |
                    (uint)(((byte)(uVar35 >> 8) & 1) == ((byte)(uVar35 >> 9) & 1))) << 1 |
                   (uint)(((byte)(uVar36 >> 8) & 1) == ((byte)(uVar36 >> 9) & 1))) << 1 |
                  (uint)(((byte)(uVar37 >> 8) & 1) == ((byte)(uVar37 >> 9) & 1))) << 1 |
                 (uint)(((byte)(uVar38 >> 8) & 1) == ((byte)(uVar38 >> 9) & 1))) << 1 |
                (uint)(((byte)(uVar39 >> 8) & 1) == ((byte)(uVar39 >> 9) & 1))) << 1 |
               (uint)(((byte)(uVar40 >> 8) & 1) == ((byte)(uVar40 >> 9) & 1))) << 1 |
              (uint)(((byte)(uVar41 >> 8) & 1) == ((byte)(uVar41 >> 9) & 1))) << 1 |
             (uint)(((byte)(uVar42 >> 8) & 1) == ((byte)(uVar42 >> 9) & 1))) << 1 |
            (uint)(((byte)(uVar11 >> 8) & 1) == ((byte)(uVar11 >> 9) & 1))) << 1 |
           (uint)(((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1))) +
           (uint)(bVar1 != (uVar6 != 0));
  }
  return 0;
}



// WARNING: Switch with 1 destination removed at 0x060e1844

undefined * FUN_060e189c(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  while( true ) {
    param_1[0xf] = param_2[0xf];
    param_1[0xe] = param_2[0xe];
    param_1[0xd] = param_2[0xd];
    param_1[0xc] = param_2[0xc];
    param_1[0xb] = param_2[0xb];
    param_1[10] = param_2[10];
    param_1[9] = param_2[9];
    param_1[8] = param_2[8];
    param_1[7] = param_2[7];
    param_1[6] = param_2[6];
    param_1[5] = param_2[5];
    param_1[4] = param_2[4];
    param_1[3] = param_2[3];
    param_1[2] = param_2[2];
    param_1[1] = param_2[1];
    *param_1 = *param_2;
    param_3 = param_3 + -0x10;
    if (param_3 < 1) break;
    param_2 = param_2 + 0x10;
    param_1 = param_1 + 0x10;
  }
  return &LAB_060e188c + param_3 * 4;
}



uint FUN_060e18e8(uint param_1,undefined4 param_2)

{
  switch(param_2) {
  case 0:
    return param_1;
  case 6:
    param_1 = param_1 >> 2;
  case 4:
    param_1 = param_1 >> 2;
  case 2:
    return param_1 >> 2;
  case 7:
    param_1 = param_1 >> 2;
  case 5:
    param_1 = param_1 >> 2;
  case 3:
    param_1 = param_1 >> 2;
  case 1:
    return param_1 >> 1;
  case 0xe:
    param_1 = param_1 >> 2;
  case 0xc:
    param_1 = param_1 >> 2;
  case 10:
    param_1 = param_1 >> 2;
  case 8:
    return param_1 >> 8;
  case 0xf:
    param_1 = param_1 >> 2;
  case 0xd:
    param_1 = param_1 >> 2;
  case 0xb:
    param_1 = param_1 >> 2;
  case 9:
    return param_1 >> 9;
  case 0x16:
    param_1 = param_1 >> 2;
  case 0x14:
    param_1 = param_1 >> 2;
  case 0x12:
    param_1 = param_1 >> 2;
  case 0x10:
    return param_1 >> 0x10;
  case 0x17:
    param_1 = param_1 >> 2;
  case 0x15:
    param_1 = param_1 >> 2;
  case 0x13:
    param_1 = param_1 >> 2;
  case 0x11:
    return param_1 >> 0x11;
  case 0x1e:
    param_1 = param_1 >> 2;
  case 0x1c:
    param_1 = param_1 >> 2;
  case 0x1a:
    param_1 = param_1 >> 2;
  case 0x18:
    return param_1 >> 0x18;
  case 0x1f:
    param_1 = param_1 >> 2;
  case 0x1d:
    param_1 = param_1 >> 2;
  case 0x1b:
    param_1 = param_1 >> 2;
  case 0x19:
    return param_1 >> 0x19;
  default:
    return 0;
  }
}



// WARNING: Removing unreachable block (ram,0x060e1a7a)

undefined8 FUN_060e1988(uint *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint unaff_r8;
  uint uVar6;
  undefined8 uVar7;
  
  uVar4 = param_1[3];
  uVar1 = *param_1;
  uVar6 = unaff_r8 & DAT_060e1aec | ((param_1[1] << 0x10) >> 1) << 0x10;
  uVar5 = param_1[4];
  if (uVar1 < 2) {
    uVar1 = param_1[4];
    uVar6 = (uVar6 | DAT_060e1af0) & DAT_060e1af8 | param_1[3] & DAT_060e1af4;
    uVar4 = (uVar6 & DAT_060e1af4 | *(uint *)PTR_DAT_060e1afc) & DAT_060e1af4;
    uVar6 = uVar6 & DAT_060e1af8;
LAB_060e1ace:
    uVar6 = uVar6 | uVar4;
  }
  else {
    if (uVar1 == 4) {
LAB_060e1a34:
      uVar6 = uVar6 | DAT_060e1af0;
    }
    else {
      if (uVar1 != 2) {
        if ((uVar4 == 0) && (uVar5 == 0)) {
          uVar6 = 0;
          uVar1 = 0;
          goto LAB_060e1ad0;
        }
        uVar1 = param_1[2];
        if ((int)uVar1 < (int)DAT_060e1ae4) {
          uVar6 = uVar6 & DAT_060e1b00;
          if ((int)((int)DAT_060e1ae4 - uVar1) < 0x39) {
            uVar7 = (*(code *)PTR_FUN_060e1b04)();
          }
          else {
            uVar7 = 0;
          }
        }
        else {
          if ((int)DAT_060e1ae6 < (int)uVar1) goto LAB_060e1a34;
          uVar6 = uVar6 & DAT_060e1b00 | (uVar1 + (int)DAT_060e1ae6 & (int)DAT_060e1ae8) << 0x14;
          if ((uVar5 & 0xff) == (int)DAT_060e1aea) {
            iVar2 = DAT_060e1b10;
            iVar3 = DAT_060e1b14;
            uVar1 = uVar5;
            if ((uVar5 & DAT_060e1b0c) != 0) goto LAB_060e1a7e;
          }
          else {
            iVar2 = 0;
            iVar3 = 0x7f;
LAB_060e1a7e:
            uVar1 = uVar5 + iVar3;
            uVar4 = uVar4 + iVar2 + (uint)(uVar1 < uVar5);
          }
          uVar7 = CONCAT44(uVar1,uVar4);
          if (DAT_060e1b18 < uVar4) {
            uVar7 = CONCAT44(uVar1 >> 1 | (uint)((uVar4 & 1) == 1) * -0x80000000,uVar4 >> 1);
            uVar6 = uVar6 & DAT_060e1b00 |
                    ((uVar6 >> 0x14 & (int)DAT_060e1ae8) + 1 & (int)DAT_060e1ae8) << 0x14;
          }
        }
        uVar1 = (uint)uVar7 << 0x18 | (uint)((ulonglong)uVar7 >> 0x28);
        uVar4 = DAT_060e1af4 & (uint)uVar7 >> 8;
        uVar6 = uVar6 & DAT_060e1af8;
        goto LAB_060e1ace;
      }
      uVar6 = uVar6 & DAT_060e1b00;
    }
    uVar1 = 0;
    uVar6 = uVar6 & DAT_060e1af8;
  }
LAB_060e1ad0:
  return CONCAT44(uVar1,uVar6);
}



void FUN_060e1b24(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = param_1[1];
  uVar3 = *param_1 & DAT_060e1c10;
  param_2[1] = (uint)(*(byte *)param_1 >> 7);
  uVar2 = (uint)(short)(DAT_060e1c0a & *(ushort *)param_1);
  if (uVar2 == 0) {
    if ((uVar3 == 0) && (uVar4 == 0)) {
      *param_2 = 2;
      return;
    }
    param_2[2] = ((uint)((short)*(ushort *)param_1 * 0x20000) >> 0x15) + (int)DAT_060e1c0c;
    uVar2 = uVar4 >> 0x18;
    uVar4 = uVar4 << 8;
    *param_2 = 3;
    uVar3 = uVar2 | uVar3 << 8;
    uVar2 = DAT_060e1c14;
    while (uVar1 = DAT_060e1c14, uVar3 <= uVar2) {
      uVar2 = uVar4 & 0x80000000;
      uVar4 = uVar4 << 1;
      param_2[2] = param_2[2] - 1;
      uVar3 = uVar3 << 1 | (uint)(uVar2 != 0);
      uVar2 = uVar1;
    }
  }
  else {
    if (uVar2 != DAT_060e1c0a) {
      param_2[2] = ((uint)((short)*(ushort *)param_1 * 0x20000) >> 0x15) + (int)DAT_060e1c0e;
      *param_2 = 3;
      param_2[3] = uVar4 >> 0x18 | uVar3 << 8 | *(uint *)PTR_DAT_060e1c18;
      param_2[4] = uVar4 << 8;
      return;
    }
    if ((uVar3 == 0) && (uVar4 == 0)) {
      *param_2 = 4;
      return;
    }
    uVar2 = 0;
    if (param_2[1] == 0) {
      uVar2 = (uint)(param_2[1] == 0);
    }
    *param_2 = uVar2;
  }
  param_2[3] = uVar3;
  param_2[4] = uVar4;
  return;
}



uint * FUN_060e1c1c(uint *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar4 = *param_1;
  if (1 >= uVar4) {
    return param_1;
  }
  uVar2 = *param_2;
  if (uVar2 <= (1 < uVar4)) {
    return param_2;
  }
  if (uVar4 == 4) {
    if (uVar2 != 4) {
      return param_1;
    }
    if (param_1[1] == param_2[1]) {
      return param_1;
    }
    return DAT_060e1e04;
  }
  if (uVar2 == 4) {
    return param_2;
  }
  if (uVar2 == 2) {
    return param_1;
  }
  if (uVar4 == 2) {
    return param_2;
  }
  uVar8 = param_1[2];
  uVar5 = param_2[2];
  uVar6 = param_1[3];
  uVar2 = param_1[4];
  uVar7 = param_2[3];
  iVar3 = uVar8 - uVar5;
  uVar4 = param_2[4];
  if (iVar3 < 0) {
    iVar3 = -iVar3;
  }
  if (iVar3 < 0x40) {
    if ((int)uVar8 > (int)uVar5) {
      do {
        uVar5 = uVar5 + 1;
        uVar1 = uVar7 & 1;
        uVar7 = uVar7 >> 1;
        uVar4 = uVar4 & 1 | uVar4 >> 1 | (uint)(uVar1 == 1) * -0x80000000;
      } while ((int)uVar5 < (int)uVar8);
    }
    if ((int)uVar8 < (int)uVar5) {
      do {
        uVar8 = uVar8 + 1;
        uVar1 = uVar6 & 1;
        uVar6 = uVar6 >> 1;
        uVar2 = uVar2 & 1 | uVar2 >> 1 | (uint)(uVar1 == 1) * -0x80000000;
      } while ((int)uVar8 < (int)uVar5);
      uVar5 = param_1[1];
      goto LAB_060e1d18;
    }
  }
  else if ((int)uVar8 <= (int)uVar5) {
    uVar6 = 0;
    uVar2 = 0;
    uVar8 = uVar5;
  }
  else {
    uVar7 = 0;
    uVar4 = 0;
  }
  uVar5 = param_1[1];
LAB_060e1d18:
  if (uVar5 == param_2[1]) {
    param_3[1] = param_1[1];
    param_3[2] = uVar8;
    param_3[3] = uVar6 + uVar7 + (uint)(uVar2 + uVar4 < uVar2);
    param_3[4] = uVar2 + uVar4;
  }
  else {
    if (uVar5 == 0) {
      uVar4 = uVar2 - uVar4;
      uVar2 = (uVar6 - uVar7) - (uint)(uVar2 < uVar4);
    }
    else {
      uVar2 = -uVar2;
      uVar4 = uVar2 + uVar4;
      uVar2 = (-(uint)(uVar2 != 0) - uVar6) + uVar7 + (uint)(uVar4 < uVar2);
    }
    if (((int)uVar2 < 1) && ((uVar2 != 0 || (uVar4 == 0)))) {
      param_3[1] = 1;
      param_3[2] = uVar8;
      param_3[3] = -(uint)(-uVar4 != 0) - uVar2;
      param_3[4] = -uVar4;
    }
    else {
      param_3[1] = 0;
      param_3[2] = uVar8;
      param_3[3] = uVar2;
      param_3[4] = uVar4;
    }
    uVar2 = param_3[3];
    uVar4 = DAT_060e1e08;
    while (uVar2 <= uVar4) {
      uVar4 = param_3[3];
      if (uVar4 == 0) {
        if (param_3[4] == 0) break;
        uVar4 = param_3[3];
      }
      param_3[3] = uVar4 << 1 | (uint)((param_3[4] & 0x80000000) != 0);
      param_3[4] = param_3[4] << 1;
      uVar4 = DAT_060e1e08;
      uVar2 = param_3[3];
      param_3[2] = param_3[2] - 1;
    }
  }
  *param_3 = 3;
  if (DAT_060e1e0c < param_3[3]) {
    uVar4 = param_3[3];
    param_3[3] = uVar4 >> 1;
    param_3[4] = param_3[4] & 1 | param_3[4] >> 1 | (uint)((uVar4 & 1) == 1) * -0x80000000;
    param_3[2] = param_3[2] + 1;
  }
  return param_3;
}



void FUN_060e1e10(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined auStack_60 [20];
  undefined auStack_4c [20];
  undefined auStack_38 [20];
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  
  puVar1 = PTR_FUN_060e1e64;
  local_24 = param_1;
  uStack_20 = param_2;
  local_1c = param_3;
  uStack_18 = param_4;
  (*(code *)PTR_FUN_060e1e64)(&local_24,auStack_60);
  (*(code *)puVar1)(&local_1c,auStack_4c);
  uVar2 = (*(code *)PTR_FUN_060e1e68)(auStack_60,auStack_4c,auStack_38);
  (*(code *)PTR_FUN_060e1e6c)(uVar2);
  return;
}



void FUN_060e1e70(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined auStack_60 [20];
  undefined auStack_4c [4];
  uint uStack_48;
  undefined auStack_38 [20];
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  
  puVar1 = PTR_FUN_060e1ec8;
  local_24 = param_1;
  uStack_20 = param_2;
  local_1c = param_3;
  uStack_18 = param_4;
  (*(code *)PTR_FUN_060e1ec8)(&local_24,auStack_60);
  (*(code *)puVar1)(&local_1c,auStack_4c);
  uStack_48 = uStack_48 ^ 1;
  uVar2 = (*(code *)PTR_FUN_060e1ecc)(auStack_60,auStack_4c,auStack_38);
  (*(code *)PTR_FUN_060e1ed0)(uVar2);
  return;
}



// WARNING: Removing unreachable block (ram,0x060e2096)

uint * FUN_060e1ef4(uint *param_1,uint *param_2,uint *param_3)

{
  bool bVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined *puVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uStack_60;
  
  uVar6 = *param_1;
  if (uVar6 < 2) {
    param_1[1] = param_1[1] == param_2[1] ^ 1;
    return param_1;
  }
  uVar7 = *param_2;
  if (uVar7 < 2) {
    bVar1 = param_1[1] == param_2[1];
  }
  else {
    if (uVar6 == 4) {
      if (uVar7 == 2) {
        return DAT_060e21c0;
      }
      uVar6 = param_1[1];
LAB_060e1f84:
      param_1[1] = uVar6 == param_2[1] ^ 1;
      return param_1;
    }
    if (uVar7 == 4) {
      if (uVar6 == 2) {
        return DAT_060e21c0;
      }
    }
    else {
      if (uVar6 == 2) {
        uVar6 = param_1[1];
        goto LAB_060e1f84;
      }
      if (uVar7 != 2) {
        lVar2 = (ulonglong)param_2[4] * (ulonglong)param_1[4];
        uStack_60 = (uint)((ulonglong)lVar2 >> 0x20);
        uVar6 = (uint)lVar2;
        uVar3 = (ulonglong)param_2[3] * (ulonglong)param_1[4];
        iVar8 = 0;
        uVar7 = 0;
        uVar4 = uVar3 + (ulonglong)param_2[4] * (ulonglong)param_1[3];
        if (uVar4 < uVar3) {
          uVar7 = *(uint *)(PTR_DAT_060e21c4 + 4);
          iVar8 = *(int *)PTR_DAT_060e21c4;
        }
        uVar10 = (int)uVar4 + uStack_60;
        if (uVar10 < uStack_60) {
          iVar8 = iVar8 + (uint)(uVar7 + 1 < uVar7);
          uVar7 = uVar7 + 1;
        }
        uVar3 = (ulonglong)param_2[3] * (ulonglong)param_1[3] + CONCAT44(iVar8,(int)(uVar4 >> 0x20))
                + (ulonglong)uVar7;
        param_3[2] = param_1[2] + param_2[2];
        param_3[1] = param_1[1] == param_2[1] ^ 1;
        bVar1 = DAT_060e21c8 < (uint)(uVar3 >> 0x20);
        param_3[2] = param_3[2] + 4;
        while( true ) {
          uVar7 = (uint)(uVar3 >> 0x20);
          if (!bVar1) break;
          param_3[2] = param_3[2] + 1;
          if ((uVar3 & 1) != 0) {
            uVar6 = uVar6 >> 1 | (uint)((uVar10 & 1) == 1) * -0x80000000;
            uVar10 = uVar10 >> 1 | *(uint *)PTR_DAT_060e21cc;
          }
          uVar9 = uVar7 >> 1;
          uVar3 = CONCAT44(uVar9,(uint)uVar3 >> 1 | (uint)((uVar7 & 1) == 1) * -0x80000000);
          bVar1 = DAT_060e21c8 < uVar9;
        }
        while( true ) {
          puVar5 = PTR_DAT_060e21cc;
          uVar9 = (uint)(uVar3 >> 0x20);
          uVar7 = (uint)uVar3;
          if (DAT_060e21d0 < uVar9) break;
          param_3[2] = param_3[2] - 1;
          uVar7 = uVar7 << 1;
          if ((*(uint *)puVar5 & uVar10) != 0) {
            uVar7 = uVar7 | 1;
          }
          uVar3 = CONCAT44(uVar9 << 1 | (uint)((uVar3 & 0x80000000) != 0),uVar7);
          uVar7 = uVar6 & 0x80000000;
          uVar6 = uVar6 << 1;
          uVar10 = uVar10 << 1 | (uint)(uVar7 != 0);
        }
        if (((uVar7 & 0xff) == (int)DAT_060e222a) &&
           ((((uVar7 & DAT_060e2230) != 0 || (uVar10 != 0)) || (uVar6 != 0)))) {
          uVar3 = uVar3 + CONCAT44(DAT_060e2234,DAT_060e2238);
        }
        *(ulonglong *)(param_3 + 3) = uVar3;
        *param_3 = 3;
        return param_3;
      }
    }
    bVar1 = param_1[1] == param_2[1];
  }
  param_2[1] = bVar1 ^ 1;
  return param_2;
}



void FUN_060e223c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined auStack_60 [20];
  undefined auStack_4c [20];
  undefined auStack_38 [20];
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  
  puVar1 = PTR_FUN_060e2290;
  local_24 = param_1;
  uStack_20 = param_2;
  local_1c = param_3;
  uStack_18 = param_4;
  (*(code *)PTR_FUN_060e2290)(&local_24,auStack_60);
  (*(code *)puVar1)(&local_1c,auStack_4c);
  uVar2 = (*(code *)PTR_FUN_060e2294)(auStack_60,auStack_4c,auStack_38);
  (*(code *)PTR_FUN_060e2298)(uVar2);
  return;
}



undefined8 FUN_060e22a4(uint *param_1,uint *param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  uVar4 = *param_1;
  uVar3 = (uint)(uVar4 < 2);
  puVar1 = param_1;
  if (uVar3 == 0) {
    uVar3 = (uint)(*param_2 <= (uint)(uVar3 == 0));
    puVar1 = param_2;
    if (uVar3 == 0) {
      uVar3 = (uint)(uVar4 == 4);
      if ((uVar3 == 0) && (uVar3 = (uint)(uVar4 == 2), uVar3 == 0)) {
        param_1[1] = param_1[1] ^ param_2[1];
        uVar3 = 0;
        if (*param_2 == 4) {
          param_1[3] = 0;
          param_1[4] = 0;
          param_1[2] = 0;
          puVar1 = param_1;
        }
        else {
          uVar3 = (uint)(*param_2 == 2);
          if (uVar3 == 0) {
            uVar4 = param_1[3];
            uVar7 = param_1[4];
            param_1[2] = param_1[2] - param_2[2];
            uVar3 = param_2[3];
            uVar11 = param_2[4];
            if ((uVar4 < uVar3) || ((uVar3 == uVar4 && (uVar7 < uVar11)))) {
              uVar9 = uVar7 & 0x80000000;
              uVar7 = uVar7 << 1;
              uVar4 = uVar4 << 1 | (uint)(uVar9 != 0);
              param_1[2] = param_1[2] - 1;
            }
            uVar5 = *(uint *)PTR_DAT_060e23ec;
            uVar6 = *(uint *)(PTR_DAT_060e23ec + 4);
            uVar9 = 0;
            uVar10 = 0;
            do {
              uVar8 = uVar7;
              if ((uVar3 <= uVar4) && ((uVar3 != uVar4 || (uVar11 <= uVar7)))) {
                uVar9 = uVar9 | uVar5;
                uVar10 = uVar10 | uVar6;
                uVar8 = uVar7 - uVar11;
                uVar4 = (uVar4 - uVar3) - (uint)(uVar7 < uVar8);
              }
              uVar7 = uVar5 & 1;
              uVar5 = uVar5 >> 1;
              uVar6 = uVar6 >> 1 | (uint)(uVar7 == 1) * -0x80000000;
              uVar7 = uVar8 << 1;
              uVar4 = uVar4 << 1 | (uint)((uVar8 & 0x80000000) != 0);
            } while ((uVar5 != 0) || (uVar6 != 0));
            uVar3 = 0;
            uVar11 = uVar10;
            if (((uVar10 & 0xff) == (int)DAT_060e23e4) &&
               ((((uVar10 & DAT_060e23f4) != 0 || (uVar4 != 0)) ||
                (uVar3 = DAT_060e23f0, uVar7 != 0)))) {
              uVar11 = uVar10 + DAT_060e23fc;
              uVar9 = uVar9 + DAT_060e23f8 + (uint)(uVar11 < uVar10);
              uVar3 = DAT_060e23f8;
            }
            param_1[3] = uVar9;
            param_1[4] = uVar11;
            puVar1 = param_1;
          }
          else {
            *param_1 = 4;
          }
        }
      }
      else {
        puVar1 = param_1;
        puVar2 = DAT_060e23e8;
        if (uVar4 == *param_2) goto LAB_060e23d4;
      }
    }
  }
  puVar2 = puVar1;
LAB_060e23d4:
  return CONCAT44(uVar3,puVar2);
}



void FUN_060e2400(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined auStack_60 [20];
  undefined auStack_4c [20];
  undefined auStack_38 [20];
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  
  puVar1 = PTR_FUN_060e2454;
  local_24 = param_1;
  uStack_20 = param_2;
  local_1c = param_3;
  uStack_18 = param_4;
  (*(code *)PTR_FUN_060e2454)(&local_24,auStack_60);
  (*(code *)puVar1)(&local_1c,auStack_4c);
  uVar2 = (*(code *)PTR_FUN_060e2458)(auStack_60,auStack_4c,auStack_38);
  (*(code *)PTR_FUN_060e245c)(uVar2);
  return;
}



int FUN_060e2460(uint *param_1,uint *param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = *param_1;
  if ((1 >= uVar3) || (*param_2 <= (uint)(1 < uVar3))) {
    return 1;
  }
  if ((uVar3 == 4) && (*param_2 == 4)) {
    return param_2[1] - param_1[1];
  }
  if (*param_1 != 4) {
    if (*param_2 == 4) {
      uVar3 = param_2[1];
LAB_060e2540:
      iVar2 = -1;
      if (uVar3 != 0) {
        iVar2 = 1;
      }
      return iVar2;
    }
    if ((*param_1 == 2) && (*param_2 == 2)) {
      return 0;
    }
    if (*param_1 == 2) {
      uVar3 = param_2[1];
      goto LAB_060e2540;
    }
    if (*param_2 != 2) {
      uVar3 = param_1[1];
      bVar1 = uVar3 == 0;
      if (uVar3 != param_2[1]) goto LAB_060e24ae;
      if ((int)param_2[2] < (int)param_1[2]) {
        bVar1 = uVar3 == 0;
        goto LAB_060e24ae;
      }
      if ((int)param_1[2] < (int)param_2[2]) goto LAB_060e2540;
      if ((param_1[3] <= param_2[3]) && ((param_1[3] != param_2[3] || (param_1[4] <= param_2[4]))))
      {
        if (param_2[3] <= param_1[3]) {
          if (param_2[3] != param_1[3]) {
            return 0;
          }
          if (param_2[4] <= param_1[4]) {
            return 0;
          }
        }
        uVar3 = param_1[1];
        goto LAB_060e2540;
      }
    }
  }
  bVar1 = param_1[1] == 0;
LAB_060e24ae:
  if (bVar1) {
    return 1;
  }
  return -1;
}



void FUN_060e2598(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  uint local_48 [5];
  uint auStack_34 [5];
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  puVar1 = PTR_FUN_060e25f0;
  uStack_20 = param_1;
  uStack_1c = param_2;
  uStack_18 = param_3;
  uStack_14 = param_4;
  (*(code *)PTR_FUN_060e25f0)(&uStack_20,local_48);
  (*(code *)puVar1)(&uStack_18,auStack_34);
  if ((1 < local_48[0]) && ((1 < local_48[0]) < auStack_34[0])) {
    (*(code *)PTR_FUN_060e25f4)(local_48,auStack_34);
  }
  return;
}



void FUN_060e25f8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  uint local_48 [5];
  uint auStack_34 [5];
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  puVar1 = PTR_FUN_060e2650;
  uStack_20 = param_1;
  uStack_1c = param_2;
  uStack_18 = param_3;
  uStack_14 = param_4;
  (*(code *)PTR_FUN_060e2650)(&uStack_20,local_48);
  (*(code *)puVar1)(&uStack_18,auStack_34);
  if ((1 < local_48[0]) && ((1 < local_48[0]) < auStack_34[0])) {
    (*(code *)PTR_FUN_060e2654)(local_48,auStack_34);
  }
  return;
}



undefined4 FUN_060e2658(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  undefined4 uVar2;
  uint local_48 [5];
  uint auStack_34 [5];
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  puVar1 = PTR_FUN_060e26b8;
  uStack_20 = param_1;
  uStack_1c = param_2;
  uStack_18 = param_3;
  uStack_14 = param_4;
  (*(code *)PTR_FUN_060e26b8)(&uStack_20,local_48);
  (*(code *)puVar1)(&uStack_18,auStack_34);
  uVar2 = 0xffffffff;
  if ((1 < local_48[0]) && ((1 < local_48[0]) < auStack_34[0])) {
    uVar2 = (*(code *)PTR_FUN_060e26bc)(local_48,auStack_34);
  }
  return uVar2;
}



undefined4 FUN_060e26c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  undefined4 uVar2;
  uint local_48 [5];
  uint auStack_34 [5];
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  puVar1 = PTR_FUN_060e2720;
  uStack_20 = param_1;
  uStack_1c = param_2;
  uStack_18 = param_3;
  uStack_14 = param_4;
  (*(code *)PTR_FUN_060e2720)(&uStack_20,local_48);
  (*(code *)puVar1)(&uStack_18,auStack_34);
  uVar2 = 0xffffffff;
  if ((1 < local_48[0]) && ((1 < local_48[0]) < auStack_34[0])) {
    uVar2 = (*(code *)PTR_FUN_060e2724)(local_48,auStack_34);
  }
  return uVar2;
}



void FUN_060e2728(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  uint local_48 [5];
  uint auStack_34 [5];
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  puVar1 = PTR_FUN_060e2780;
  uStack_20 = param_1;
  uStack_1c = param_2;
  uStack_18 = param_3;
  uStack_14 = param_4;
  (*(code *)PTR_FUN_060e2780)(&uStack_20,local_48);
  (*(code *)puVar1)(&uStack_18,auStack_34);
  if ((1 < local_48[0]) && ((1 < local_48[0]) < auStack_34[0])) {
    (*(code *)PTR_FUN_060e2784)(local_48,auStack_34);
  }
  return;
}



void FUN_060e2788(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  uint local_48 [5];
  uint auStack_34 [5];
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  puVar1 = PTR_FUN_060e27e0;
  uStack_20 = param_1;
  uStack_1c = param_2;
  uStack_18 = param_3;
  uStack_14 = param_4;
  (*(code *)PTR_FUN_060e27e0)(&uStack_20,local_48);
  (*(code *)puVar1)(&uStack_18,auStack_34);
  if ((1 < local_48[0]) && ((1 < local_48[0]) < auStack_34[0])) {
    (*(code *)PTR_FUN_060e27e4)(local_48,auStack_34);
  }
  return;
}



undefined4 FUN_060e27f0(uint param_1)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 local_1c;
  uint uStack_18;
  int iStack_14;
  uint uStack_10;
  uint uStack_c;
  
  local_1c = 3;
  uStack_18 = (param_1 >> 0x10) * 2 >> 0x10;
  if (param_1 == 0) {
    local_1c = 2;
  }
  else {
    iStack_14 = 0x3c;
    if (uStack_18 == 0) {
      uVar2 = param_1 & 0x80000000;
    }
    else {
      bVar1 = param_1 == DAT_060e2870;
      param_1 = -param_1;
      if (bVar1) {
        return *(undefined4 *)PTR_DAT_060e2874;
      }
      uVar2 = param_1 & 0x80000000;
    }
    uStack_c = param_1;
    for (uStack_10 = -(uint)(uVar2 != 0); uStack_10 <= DAT_060e2878;
        uStack_10 = uStack_10 << 1 | (uint)(uVar2 != 0)) {
      uVar2 = uStack_c & 0x80000000;
      uStack_c = uStack_c << 1;
      iStack_14 = iStack_14 + -1;
    }
  }
  uVar3 = (*(code *)PTR_FUN_060e287c)(&local_1c);
  return uVar3;
}



int FUN_060e2880(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int extraout_r1;
  uint local_24;
  int iStack_20;
  int iStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  uStack_10 = param_1;
  uStack_c = param_2;
  (*(code *)PTR_FUN_060e2900)(&uStack_10,&local_24);
  if ((local_24 != 2) && ((local_24 != 2) < local_24)) {
    iVar1 = DAT_060e2908;
    iVar2 = DAT_060e2904;
    if (local_24 != 4) {
      if (iStack_1c < 0) goto LAB_060e28c8;
      iVar1 = DAT_060e2904;
      iVar2 = DAT_060e2908;
      if (iStack_1c < 0x1f) {
        (*(code *)PTR_FUN_060e290c)(uStack_18,uStack_14,0x3c - iStack_1c);
        if (iStack_20 == 0) {
          return extraout_r1;
        }
        return -extraout_r1;
      }
    }
    if (iStack_20 != 0) {
      return iVar1;
    }
  }
  else {
LAB_060e28c8:
    iVar2 = 0;
  }
  return iVar2;
}



void FUN_060e2910(undefined4 param_1,undefined4 param_2)

{
  undefined auStack_24 [4];
  uint uStack_20;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  uStack_10 = param_1;
  uStack_c = param_2;
  (*(code *)PTR_FUN_060e2940)(&uStack_10,auStack_24);
  uStack_20 = (uint)(uStack_20 == 0);
  (*(code *)PTR_FUN_060e2944)(auStack_24);
  return;
}



undefined8 FUN_060e29c8(int param_1,int param_2,int param_3,int param_4)

{
  int local_2c;
  int iStack_28;
  int iStack_24;
  
  iStack_24 = 0;
  if (param_1 < 0) {
    iStack_24 = -1;
    param_2 = -param_2;
    param_1 = -(param_2 == 0 ^ 1) - param_1;
  }
  if (param_3 < 0) {
    param_4 = -param_4;
    param_3 = -(param_4 == 0 ^ 1) - param_3;
  }
  (*(code *)PTR_FUN_060e2a58)(param_1,param_2,param_3,param_4,&local_2c);
  if (iStack_24 != 0) {
    iStack_28 = -iStack_28;
    local_2c = -(iStack_28 == 0 ^ 1) - local_2c;
  }
  return CONCAT44(iStack_28,local_2c);
}



undefined8 FUN_060e2a5c(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined8 uVar2;
  uint local_24;
  
  local_24 = 0;
  if (param_1 < 0) {
    local_24 = 0xffffffff;
    param_2 = -param_2;
    param_1 = -(param_2 == 0 ^ 1) - param_1;
  }
  if (param_3 < 0) {
    local_24 = ~local_24;
    param_4 = -param_4;
    param_3 = -(param_4 == 0 ^ 1) - param_3;
  }
  uVar2 = (*(code *)PTR_FUN_060e2af4)(param_1,param_2,param_3,param_4,0);
  if (local_24 != 0) {
    iVar1 = -(int)((ulonglong)uVar2 >> 0x20);
    uVar2 = CONCAT44(iVar1,-(iVar1 == 0 ^ 1) - (int)uVar2);
  }
  return uVar2;
}



undefined8 FUN_060e2af8(void)

{
  undefined4 local_10;
  undefined4 uStack_c;
  
  (*(code *)PTR_FUN_060e2b18)();
  return CONCAT44(uStack_c,local_10);
}



void FUN_060e2b1c(void)

{
  (*(code *)PTR_FUN_060e2b34)();
  return;
}



undefined8 FUN_060e2b38(undefined4 param_1,uint param_2,int param_3)

{
  undefined *puVar1;
  uint uVar2;
  
  if (param_3 != 0) {
    if (0x20 - param_3 < 1) {
      param_2 = (*(code *)PTR_FUN_060e2bac)(param_1,-(0x20 - param_3));
      param_1 = 0;
    }
    else {
      uVar2 = (*(code *)PTR_FUN_060e2bb0)(param_1);
      puVar1 = PTR_FUN_060e2bac;
      param_1 = (*(code *)PTR_FUN_060e2bac)(param_1,param_3);
      param_2 = (*(code *)puVar1)(param_2,param_3);
      param_2 = uVar2 | param_2;
    }
  }
  return CONCAT44(param_2,param_1);
}



undefined8 FUN_060e3820(uint param_1,uint param_2,uint param_3,uint param_4,uint *param_5)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  code *extraout_r2;
  code *extraout_r2_00;
  code *extraout_r2_01;
  code *extraout_r2_02;
  code *extraout_r2_03;
  code *extraout_r2_04;
  code *extraout_r2_05;
  code *extraout_r2_06;
  int extraout_r3;
  int extraout_r3_00;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uStack_48;
  uint uStack_44;
  uint uStack_40;
  int iStack_38;
  uint uStack_28;
  uint uStack_24;
  
  uStack_28 = param_2;
  uStack_24 = param_1;
  if (param_3 == 0) {
    if (param_1 < param_4) {
      if (DAT_060e395c < param_4) {
        iVar12 = 0x18;
        if (param_4 <= DAT_060e3960) {
          iVar12 = 0x10;
        }
      }
      else {
        iVar12 = 0;
        if ((uint)(int)DAT_060e3958 < param_4) {
          iVar12 = 8;
        }
      }
      iVar3 = (*(code *)PTR_FUN_060e3964)(param_4,iVar12);
      puVar1 = PTR_FUN_060e396c;
      iStack_38 = 0x20 - ((uint)(byte)PTR_DAT_060e3968[iVar3] + iVar12);
      if (iStack_38 != 0) {
        param_4 = (*(code *)PTR_FUN_060e396c)(param_4,iStack_38);
        uStack_24 = (*(code *)puVar1)(param_1,iStack_38);
        uVar14 = (*(code *)PTR_FUN_060e3964)(param_2,0x20 - iStack_38);
        uStack_24 = uStack_24 | uVar14;
        uStack_28 = (*(code *)puVar1)(param_2,iStack_38);
      }
      uVar4 = param_4 >> 0x10;
      uVar14 = uStack_24;
      iVar12 = (*(code *)PTR_FUN_060e3970)(uStack_24,uVar4);
      iVar12 = iVar12 * uVar4;
      iVar3 = (*extraout_r2)(uStack_24);
      uVar5 = iVar3 * (param_4 & 0xffff);
      uVar14 = (uVar14 - iVar12) * 0x10000 | uStack_28 >> 0x10;
      iVar12 = iVar3;
      if (uVar14 < uVar5) {
        uVar14 = uVar14 + param_4;
        iVar12 = iVar3 + -1;
        if ((param_4 <= uVar14) && (uVar14 < uVar5)) {
          iVar12 = iVar3 + -2;
          uVar14 = uVar14 + param_4;
        }
      }
      iVar8 = uVar14 - uVar5;
      iVar3 = (*(code *)PTR_FUN_060e3970)(iVar8,uVar4);
      iVar3 = iVar3 * uVar4;
      uVar4 = (*extraout_r2_00)(iVar8);
      uVar5 = uVar4 * (param_4 & 0xffff);
      uStack_28 = uStack_28 & 0xffff | (iVar8 - iVar3) * 0x10000;
      uVar14 = uVar4;
      if (uStack_28 < uVar5) {
        uStack_28 = uStack_28 + param_4;
        uVar14 = uVar4 - 1;
        if ((param_4 <= uStack_28) && (uStack_28 < uVar5)) {
          uVar14 = uVar4 - 2;
          uStack_28 = uStack_28 + param_4;
        }
      }
      uVar14 = iVar12 << 0x10 | uVar14;
      uStack_28 = uStack_28 - uVar5;
      uStack_40 = 0;
    }
    else {
      if (param_4 == 0) {
        param_4 = (*(code *)PTR_FUN_060e39d8)(param_4 == 0,0);
      }
      if (DAT_060e39dc < param_4) {
        iVar12 = 0x18;
        if (param_4 <= DAT_060e39e0) {
          iVar12 = 0x10;
        }
      }
      else {
        iVar12 = 0;
        if ((uint)(int)DAT_060e39d4 < param_4) {
          iVar12 = 8;
        }
      }
      iVar3 = (*(code *)PTR_FUN_060e39e4)(param_4,iVar12);
      puVar1 = PTR_FUN_060e3c18;
      iStack_38 = 0x20 - ((uint)(byte)PTR_DAT_060e39e8[iVar3] + iVar12);
      if (iStack_38 == 0) {
        uStack_24 = param_1 - param_4;
        uStack_40 = (uint)(iStack_38 == 0);
      }
      else {
        param_4 = (*(code *)PTR_FUN_060e3c18)(param_4,iStack_38);
        puVar2 = PTR_FUN_060e3c1c;
        iVar12 = (*(code *)PTR_FUN_060e3c1c)(param_1,0x20 - iStack_38);
        uVar14 = (*(code *)puVar1)(param_1,iStack_38);
        uVar4 = (*(code *)puVar2)(param_2,0x20 - iStack_38);
        uStack_28 = (*(code *)puVar1)(param_2,iStack_38);
        uVar6 = param_4 >> 0x10;
        iVar3 = (*(code *)PTR_FUN_060e3c20)(iVar12,uVar6);
        iVar3 = iVar3 * uVar6;
        iVar8 = (*extraout_r2_01)(iVar12);
        uVar7 = iVar8 * (param_4 & 0xffff);
        uVar5 = (uVar14 | uVar4) >> 0x10 | (iVar12 - iVar3) * 0x10000;
        iVar12 = iVar8;
        if (uVar5 < uVar7) {
          uVar5 = uVar5 + param_4;
          iVar12 = iVar8 + -1;
          if ((param_4 <= uVar5) && (uVar5 < uVar7)) {
            iVar12 = iVar8 + -2;
            uVar5 = uVar5 + param_4;
          }
        }
        iVar3 = uVar5 - uVar7;
        (*(code *)PTR_FUN_060e3c20)(iVar3,uVar6);
        uVar5 = (*extraout_r2_02)(iVar3);
        uVar7 = uVar5 * (param_4 & 0xffff);
        uStack_24 = (uVar14 | uVar4) & 0xffff | (iVar3 - extraout_r3 * uVar6) * 0x10000;
        uStack_40 = uVar5;
        if (uStack_24 < uVar7) {
          uStack_24 = uStack_24 + param_4;
          uStack_40 = uVar5 - 1;
          if ((param_4 <= uStack_24) && (uStack_24 < uVar7)) {
            uStack_40 = uVar5 - 2;
            uStack_24 = uStack_24 + param_4;
          }
        }
        uStack_40 = iVar12 << 0x10 | uStack_40;
        uStack_24 = uStack_24 - uVar7;
      }
      uVar4 = param_4 >> 0x10;
      uVar14 = uStack_24;
      iVar12 = (*(code *)PTR_FUN_060e3c20)(uStack_24,uVar4);
      iVar12 = iVar12 * uVar4;
      iVar3 = (*extraout_r2_03)(uStack_24);
      uVar5 = iVar3 * (param_4 & 0xffff);
      uVar14 = (uVar14 - iVar12) * 0x10000 | uStack_28 >> 0x10;
      iVar12 = iVar3;
      if (uVar14 < uVar5) {
        uVar14 = uVar14 + param_4;
        iVar12 = iVar3 + -1;
        if ((param_4 <= uVar14) && (uVar14 < uVar5)) {
          iVar12 = iVar3 + -2;
          uVar14 = uVar14 + param_4;
        }
      }
      iVar8 = uVar14 - uVar5;
      iVar3 = (*(code *)PTR_FUN_060e3c20)(iVar8,uVar4);
      iVar3 = iVar3 * uVar4;
      uVar4 = (*extraout_r2_04)(iVar8);
      uVar5 = uVar4 * (param_4 & 0xffff);
      uStack_28 = uStack_28 & 0xffff | (iVar8 - iVar3) * 0x10000;
      uVar14 = uVar4;
      if (uStack_28 < uVar5) {
        uStack_28 = uStack_28 + param_4;
        uVar14 = uVar4 - 1;
        if ((param_4 <= uStack_28) && (uStack_28 < uVar5)) {
          uVar14 = uVar4 - 2;
          uStack_28 = uStack_28 + param_4;
        }
      }
      uVar14 = iVar12 << 0x10 | uVar14;
      uStack_28 = uStack_28 - uVar5;
    }
    if (param_5 == (uint *)0x0) goto LAB_060e3dd2;
    uStack_44 = (*(code *)PTR_FUN_060e3c1c)(uStack_28,iStack_38);
    uStack_48 = 0;
  }
  else if (param_1 < param_3) {
    uStack_40 = 0;
    uVar14 = 0;
    uStack_48 = param_1;
    uStack_44 = param_2;
    if (param_5 == (uint *)0x0) goto LAB_060e3dd2;
  }
  else {
    if (DAT_060e3c24 < param_3) {
      iVar12 = 0x18;
      if (param_3 <= DAT_060e3c28) {
        iVar12 = 0x10;
      }
    }
    else {
      iVar12 = 0;
      if ((uint)(int)DAT_060e3c14 < param_3) {
        iVar12 = 8;
      }
    }
    iVar3 = (*(code *)PTR_FUN_060e3c1c)(param_3,iVar12);
    puVar1 = PTR_FUN_060e3df4;
    iVar12 = 0x20 - ((uint)(byte)PTR_DAT_060e3c2c[iVar3] + iVar12);
    if (iVar12 == 0) {
      uVar14 = 1;
      if ((param_3 < param_1) || (param_4 <= param_2)) {
        uStack_28 = param_2 - param_4;
        uStack_24 = (param_1 - param_3) - (uint)(param_2 < uStack_28);
      }
      else {
        uVar14 = 0;
      }
      uStack_40 = 0;
      if (param_5 == (uint *)0x0) goto LAB_060e3dd2;
      uStack_44 = uStack_28;
      uStack_48 = uStack_24;
    }
    else {
      iVar10 = 0x20 - iVar12;
      uVar4 = (*(code *)PTR_FUN_060e3df4)(param_3,iVar12);
      uVar14 = (*(code *)PTR_FUN_060e3df8)(param_4,iVar10);
      uVar4 = uVar4 | uVar14;
      uVar5 = (*(code *)puVar1)(param_4,iVar12);
      puVar2 = PTR_FUN_060e3df8;
      iVar3 = (*(code *)PTR_FUN_060e3df8)(param_1,iVar10);
      uVar14 = (*(code *)puVar1)(param_1,iVar12);
      uVar6 = (*(code *)puVar2)(param_2,iVar10);
      uVar7 = (*(code *)puVar1)(param_2,iVar12);
      uVar13 = uVar4 >> 0x10;
      iVar8 = (*(code *)PTR_FUN_060e3dfc)(iVar3,uVar13);
      iVar8 = iVar8 * uVar13;
      iVar9 = (*extraout_r2_05)(iVar3);
      uVar15 = iVar9 * (uVar4 & 0xffff);
      uVar11 = (uVar14 | uVar6) >> 0x10 | (iVar3 - iVar8) * 0x10000;
      iVar3 = iVar9;
      if (uVar11 < uVar15) {
        uVar11 = uVar11 + uVar4;
        iVar3 = iVar9 + -1;
        if ((uVar4 <= uVar11) && (uVar11 < uVar15)) {
          iVar3 = iVar9 + -2;
          uVar11 = uVar11 + uVar4;
        }
      }
      iVar8 = uVar11 - uVar15;
      (*(code *)PTR_FUN_060e3dfc)(iVar8,uVar13);
      uVar11 = (*extraout_r2_06)(iVar8);
      uVar15 = uVar11 * (uVar4 & 0xffff);
      uVar6 = (uVar14 | uVar6) & 0xffff | (iVar8 - extraout_r3_00 * uVar13) * 0x10000;
      uVar14 = uVar11;
      if (uVar6 < uVar15) {
        uVar6 = uVar6 + uVar4;
        uVar14 = uVar11 - 1;
        if ((uVar4 <= uVar6) && (uVar6 < uVar15)) {
          uVar14 = uVar11 - 2;
          uVar6 = uVar6 + uVar4;
        }
      }
      uVar14 = iVar3 << 0x10 | uVar14;
      uVar6 = uVar6 - uVar15;
      uVar13 = (uVar14 & DAT_060e3e00) * (uVar5 & DAT_060e3e00);
      uVar15 = (uVar14 >> 0x10) * (uVar5 & DAT_060e3e00);
      iVar3 = (uVar14 >> 0x10) * (uVar5 >> 0x10);
      uVar11 = (uVar14 & DAT_060e3e00) * (uVar5 >> 0x10) + (uVar13 >> 0x10) + uVar15;
      if (uVar11 < uVar15) {
        iVar3 = iVar3 + DAT_060e3e04;
      }
      uVar15 = (uVar11 >> 0x10) + iVar3;
      uVar11 = (uVar11 & DAT_060e3e00) * 0x10000 + (uVar13 & DAT_060e3e00);
      if ((uVar6 < uVar15) || ((uVar13 = uVar11, uVar15 == uVar6 && (uVar7 < uVar11)))) {
        uVar14 = uVar14 - 1;
        uVar13 = uVar11 - uVar5;
        uVar15 = (uVar15 - uVar4) - (uint)(uVar11 < uVar13);
      }
      uStack_40 = 0;
      if (param_5 == (uint *)0x0) goto LAB_060e3dd2;
      iVar3 = (uVar6 - uVar15) - (uint)(uVar7 < uVar7 - uVar13);
      uStack_44 = (*(code *)PTR_FUN_060e3df4)(iVar3,iVar10);
      puVar1 = PTR_FUN_060e3df8;
      uVar4 = (*(code *)PTR_FUN_060e3df8)(uVar7 - uVar13,iVar12);
      uStack_44 = uStack_44 | uVar4;
      uStack_48 = (*(code *)puVar1)(iVar3,iVar12);
    }
  }
  *param_5 = uStack_48;
  param_5[1] = uStack_44;
LAB_060e3dd2:
  return CONCAT44(uVar14,uStack_40);
}



undefined8 FUN_060e3c52(void)

{
  undefined *puVar1;
  uint in_r0;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  code *extraout_r2;
  code *extraout_r2_00;
  int extraout_r3;
  code *unaff_r8;
  uint uVar7;
  uint unaff_r10;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 *unaff_r14;
  uint uVar10;
  uint uVar11;
  
  puVar1 = PTR_FUN_060e3df8;
  iVar2 = (*(code *)PTR_FUN_060e3df8)(unaff_r14[0xb],unaff_r14[5]);
  uVar3 = (*unaff_r8)(unaff_r14[0xb],unaff_r14[6]);
  unaff_r14[0xb] = uVar3;
  uVar4 = (*(code *)puVar1)(unaff_r14[10],unaff_r14[5]);
  uVar8 = unaff_r14[0xb];
  unaff_r14[0xb] = uVar8 | uVar4;
  uVar3 = (*unaff_r8)(unaff_r14[10],unaff_r14[6]);
  unaff_r14[10] = uVar3;
  uVar7 = unaff_r10 >> 0x10;
  unaff_r14[8] = unaff_r10 & 0xffff;
  iVar5 = (*(code *)PTR_FUN_060e3dfc)(iVar2,uVar7);
  iVar5 = iVar5 * uVar7;
  iVar6 = (*extraout_r2)(iVar2);
  uVar10 = iVar6 * unaff_r14[8];
  uVar4 = (uVar8 | uVar4) >> 0x10 | (iVar2 - iVar5) * 0x10000;
  iVar2 = iVar6;
  if (uVar4 < uVar10) {
    uVar4 = uVar4 + unaff_r10;
    iVar2 = iVar6 + -1;
    if ((unaff_r10 <= uVar4) && (uVar4 < uVar10)) {
      iVar2 = iVar6 + -2;
      uVar4 = uVar4 + unaff_r10;
    }
  }
  iVar5 = uVar4 - uVar10;
  (*(code *)PTR_FUN_060e3dfc)(iVar5,uVar7);
  uVar8 = (*extraout_r2_00)(iVar5);
  unaff_r14[9] = (uint)*(ushort *)((int)unaff_r14 + 0x2e);
  uVar10 = uVar8 * unaff_r14[8];
  uVar7 = (uint)*(ushort *)((int)unaff_r14 + 0x2e) | (iVar5 - extraout_r3 * uVar7) * 0x10000;
  uVar4 = uVar8;
  if (uVar7 < uVar10) {
    uVar7 = uVar7 + unaff_r10;
    uVar4 = uVar8 - 1;
    if ((unaff_r10 <= uVar7) && (uVar7 < uVar10)) {
      uVar4 = uVar8 - 2;
      uVar7 = uVar7 + unaff_r10;
    }
  }
  uVar4 = iVar2 << 0x10 | uVar4;
  unaff_r14[0xb] = uVar7 - uVar10;
  uVar7 = DAT_060e3e00;
  uVar10 = (uVar4 & DAT_060e3e00) * (in_r0 & DAT_060e3e00);
  uVar11 = (uVar4 >> 0x10) * (in_r0 & DAT_060e3e00);
  iVar2 = (uVar4 >> 0x10) * (in_r0 >> 0x10);
  uVar8 = (uVar4 & DAT_060e3e00) * (in_r0 >> 0x10) + (uVar10 >> 0x10) + uVar11;
  if (uVar8 < uVar11) {
    iVar2 = iVar2 + DAT_060e3e04;
  }
  uVar11 = (uVar8 >> 0x10) + iVar2;
  uVar8 = uVar8 & DAT_060e3e00;
  unaff_r14[9] = uVar8;
  uVar7 = uVar8 * 0x10000 + (uVar10 & uVar7);
  if (((uint)unaff_r14[0xb] < uVar11) ||
     ((uVar8 = uVar7, uVar11 == unaff_r14[0xb] && ((uint)unaff_r14[10] < uVar7)))) {
    uVar4 = uVar4 - 1;
    uVar8 = uVar7 - in_r0;
    uVar11 = (uVar11 - unaff_r10) - (uint)(uVar7 < uVar8);
  }
  unaff_r14[4] = 0;
  if (unaff_r14[0x14] != 0) {
    unaff_r14[0xb] = (unaff_r14[0xb] - uVar11) - (uint)((uint)unaff_r14[10] < unaff_r14[10] - uVar8)
    ;
    unaff_r14[10] = unaff_r14[10] - uVar8;
    uVar7 = (*(code *)PTR_FUN_060e3df4)(unaff_r14[0xb],unaff_r14[5]);
    puVar1 = PTR_FUN_060e3df8;
    uVar8 = (*(code *)PTR_FUN_060e3df8)(unaff_r14[10],unaff_r14[6]);
    unaff_r14[3] = uVar7 | uVar8;
    uVar3 = (*(code *)puVar1)(unaff_r14[0xb],unaff_r14[6]);
    unaff_r14[2] = uVar3;
    uVar3 = unaff_r14[3];
    puVar9 = (undefined4 *)unaff_r14[0x14];
    *puVar9 = unaff_r14[2];
    puVar9[1] = uVar3;
  }
  unaff_r14[1] = uVar4;
  *unaff_r14 = unaff_r14[4];
  return CONCAT44(unaff_r14[1],*unaff_r14);
}



void FUN_060e3ebc(uint param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_1 & DAT_060e3eec | DAT_060e3ef0);
  if (param_2 >> 4 != 0) {
    puVar1 = puVar2 + (param_2 >> 4) * 4;
    do {
      *puVar2 = 0;
      puVar2 = puVar2 + 4;
    } while (puVar2 < puVar1);
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_060e3ef4(uint *param_1)

{
  uint uVar1;
  
  uVar1 = param_1[2];
  if ((uVar1 & 1) != 0) {
    _DAT_ffffffb0 = _DAT_ffffffb0 & 0xfffffff7 | *param_1;
  }
  if ((uVar1 & 8) != 0) {
    _DAT_ffffffb0 = _DAT_ffffffb0 & 0xfffffffe | param_1[1];
  }
  if ((uVar1 & 2) != 0) {
    _DAT_ffffffb0 = _DAT_ffffffb0 & 0xfffffffb;
  }
  if ((uVar1 & 4) != 0) {
    _DAT_ffffffb0 = _DAT_ffffffb0 & 0xfffffffd;
  }
  return;
}



void FUN_060e3f3c(undefined4 *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  if ((param_1[9] & 1) != 0) {
    *(undefined4 *)(param_2 * 0x10 + -0x80) = *param_1;
  }
  if ((param_1[9] & 2) != 0) {
    *(undefined4 *)(param_2 * 0x10 + -0x7c) = param_1[1];
  }
  if ((param_1[9] & 4) != 0) {
    *(undefined4 *)(param_2 * 0x10 + -0x78) = param_1[2];
  }
  puVar4 = (uint *)(param_2 * 0x10 + -0x74);
  uVar3 = param_1[9];
  uVar1 = *puVar4;
  if ((uVar3 & 8) != 0) {
    uVar1 = uVar1 & DAT_060e403c | ((uint)(param_1[3] << 8) >> 2) << 8;
  }
  if ((uVar3 & 0x10) != 0) {
    uVar1 = uVar1 & (int)DAT_060e402e | param_1[4] << 0xc;
  }
  if ((uVar3 & 0x20) != 0) {
    uVar1 = uVar1 & (int)DAT_060e4030 | param_1[5];
  }
  if ((uVar3 & 0x40) != 0) {
    uVar1 = uVar1 & (int)DAT_060e4032 | param_1[6];
  }
  uVar2 = uVar1 & 0xffffffe7;
  if ((uVar3 & 0x80) != 0) {
    uVar2 = uVar1 & 0xffffffe3 | param_1[7];
  }
  if (((int)DAT_060e4034 & uVar3) != 0) {
    uVar2 = uVar2 & 0xfffffffd;
  }
  *puVar4 = uVar2;
  if (((param_1[9] & (int)DAT_060e4036) != 0) && (param_1[8] - 1 < 2)) {
    *(undefined *)(param_2 + DAT_060e4038) = *(undefined *)((int)param_1 + 0x23);
  }
  return;
}



void FUN_060e4040(int param_1)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_1 * 0x10 + -0x74);
  *puVar1 = *puVar1 | 1;
  return;
}



void FUN_060e4054(int param_1)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_1 * 0x10 + -0x74);
  *puVar1 = *puVar1 & 0xfffffffe;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_060e4080(uint *param_1)

{
  uint uVar1;
  
  uVar1 = _DAT_ffffffb0;
  *param_1 = _DAT_ffffffb0 & 4;
  param_1[1] = uVar1 & 2;
  return;
}



uint FUN_060e4098(int param_1)

{
  return *(uint *)(param_1 * 0x10 + -0x74) & 2;
}



void FUN_060e40ac(undefined param_1,undefined3 param_2)

{
  undefined4 local_10;
  undefined local_c;
  undefined3 uStack_b;
  
  local_10 = 0x70000000;
  _local_c = CONCAT13(param_1,param_2);
  (*(code *)PTR_FUN_060e40dc)((int)DAT_060e40d8,&local_10);
  return;
}



void FUN_060e40e0(undefined param_1,undefined3 param_2)

{
  undefined4 local_10;
  undefined local_c;
  undefined3 uStack_b;
  
  local_10 = 0x71000000;
  _local_c = CONCAT13(param_1,param_2);
  (*(code *)PTR_FUN_060e4110)((int)DAT_060e410c,&local_10);
  return;
}



void FUN_060e4114(uint *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined auStack_1c [2];
  ushort local_1a;
  uint local_18;
  
  uStack_20 = 0;
  local_24 = 0x72000000;
  (*(code *)PTR_FUN_060e416c)(0,&local_24,auStack_1c);
  uVar1 = DAT_060e4170;
  *param_2 = (uint)local_1a;
  *param_3 = local_18 >> 0x18;
  *param_1 = local_18 & uVar1;
  return;
}



void FUN_060e4174(uint3 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_20;
  uint local_1c;
  uint local_18 [3];
  
  local_20 = 0x73000000;
  local_1c = (uint)param_1;
  iVar1 = (*(code *)PTR_FUN_060e41c4)(0,&local_20,local_18);
  if (iVar1 == 0) {
    (*(code *)PTR_FUN_060e41cc)(local_18[0] & DAT_060e41c8,param_2);
  }
  return;
}



void FUN_060e4204(void)

{
  int iVar1;
  undefined4 local_14;
  undefined4 uStack_10;
  
  uStack_10 = 0;
  local_14 = 0x75000000;
  iVar1 = (int)DAT_060e4234;
  (*(code *)PTR_FUN_060e4238)(iVar1);
  (*(code *)PTR_FUN_060e423c)(iVar1,&local_14);
  return;
}



void FUN_060e4240(byte param_1,undefined param_2)

{
  int local_10 [3];
  
  local_10[1] = 0;
  local_10[0] = CONCAT13(0x60,(uint3)param_1 << 0x10);
  local_10[0] = (uint)CONCAT21(local_10[0]._0_2_,param_2) << 8;
  (*(code *)PTR_FUN_060e4270)(0x40,local_10);
  return;
}



void FUN_060e4274(byte param_1,undefined2 param_2,undefined2 param_3)

{
  undefined2 local_10;
  undefined2 uStack_e;
  undefined4 local_c;
  
  _local_10 = CONCAT22(0x6100,param_2);
  local_c = (uint)param_1 << 0x18;
  local_c = CONCAT22(local_c._0_2_,param_3);
  (*(code *)PTR_FUN_060e42ac)((int)DAT_060e42aa,&local_10);
  return;
}



void FUN_060e42b0(byte param_1,undefined2 param_2,undefined2 param_3)

{
  undefined2 local_10;
  undefined2 uStack_e;
  undefined4 local_c;
  
  _local_10 = CONCAT22(0x6200,param_2);
  local_c = (uint)param_1 << 0x18;
  local_c = CONCAT22(local_c._0_2_,param_3);
  (*(code *)PTR_FUN_060e42e8)((int)DAT_060e42e6,&local_10);
  return;
}



void FUN_060e43a4(byte param_1,undefined2 param_2,undefined2 param_3,undefined param_4)

{
  undefined2 local_10;
  undefined2 uStack_e;
  undefined4 local_c;
  
  _local_10 = CONCAT22(CONCAT11(0x66,param_4),param_2);
  local_c = (uint)param_1 << 0x18;
  local_c = CONCAT22(local_c._0_2_,param_3);
  (*(code *)PTR_FUN_060e43e4)((int)DAT_060e43e0,&local_10);
  return;
}



void FUN_060e4424(undefined param_1,undefined3 param_2,undefined3 param_3)

{
  undefined local_10;
  undefined3 uStack_f;
  undefined local_c;
  undefined3 uStack_b;
  
  _local_10 = CONCAT13(0x40,param_2);
  _local_c = CONCAT13(param_1,param_3);
  (*(code *)PTR_FUN_060e4454)(0x40,&local_10);
  return;
}



void FUN_060e44b0(undefined param_1,undefined *param_2)

{
  undefined3 local_10;
  undefined uStack_d;
  undefined3 local_c;
  undefined local_9;
  
  _local_10 = CONCAT31(CONCAT21(CONCAT11(0x42,param_2[1]),param_2[2]),param_2[4]);
  _local_c = CONCAT31(CONCAT21(CONCAT11(param_1,*param_2),param_2[3]),param_2[5]);
  (*(code *)PTR_FUN_060e451c)(0x40,&local_10);
  return;
}



void FUN_060e459c(byte param_1,byte param_2)

{
  undefined local_10;
  int3 iStack_f;
  int local_c;
  
  _local_10 = CONCAT13(0x44,(uint3)param_2 << 0x10);
  local_c = (uint)param_1 << 0x18;
  (*(code *)PTR_FUN_060e45cc)(0x40,&local_10);
  return;
}



void FUN_060e45d0(byte param_1,uint *param_2)

{
  undefined4 local_1c;
  int local_18;
  undefined uStack_14;
  byte local_13;
  
  local_1c = 0x45000000;
  local_18 = (uint)param_1 << 0x18;
  (*(code *)PTR_FUN_060e4610)(0,&local_1c,&uStack_14);
  *param_2 = (uint)local_13;
  return;
}



void FUN_060e4614(byte param_1,undefined param_2,undefined param_3,undefined param_4)

{
  undefined3 local_10;
  undefined uStack_d;
  int local_c;
  
  _local_10 = CONCAT31(CONCAT21(CONCAT11(0x46,param_2),param_3),param_4);
  local_c = (uint)param_1 << 0x18;
  (*(code *)PTR_FUN_060e4650)(0x40,&local_10);
  return;
}



void FUN_060e46a8(byte param_1,byte param_2)

{
  undefined local_10;
  int3 iStack_f;
  int local_c;
  
  _local_10 = CONCAT13(0x48,(uint3)param_1 << 0x10);
  local_c = (uint)param_2 << 0x18;
  (*(code *)PTR_FUN_060e46d8)(0x40,&local_10);
  return;
}



void FUN_060e46dc(int param_1)

{
  undefined *puVar1;
  undefined4 local_18;
  undefined4 local_14;
  
  puVar1 = PTR_FUN_060e4728;
  local_14 = 0;
  local_18 = 0x10000000;
  (*(code *)PTR_FUN_060e4728)(param_1,(int)&local_18 + 1);
  local_14 = CONCAT13(*(undefined *)(param_1 + 0x10),local_14._1_3_);
  (*(code *)puVar1)(param_1 + 8,(int)&local_14 + 1);
  (*(code *)PTR_FUN_060e472c)(0,&local_18);
  return;
}



void FUN_060e4730(undefined4 *param_1,byte *param_2)

{
  byte bVar1;
  
  switch(*param_1) {
  default:
    bVar1 = 0;
    break;
  case 1:
    *param_2 = *(byte *)((int)param_1 + 5) | 0x80;
    param_2[1] = *(byte *)((int)param_1 + 6);
    bVar1 = *(byte *)((int)param_1 + 7);
    goto LAB_060e479e;
  case 2:
    *param_2 = 0;
    param_2[1] = *(byte *)(param_1 + 1);
    bVar1 = *(byte *)((int)param_1 + 5);
    goto LAB_060e479e;
  case 3:
    bVar1 = 0xff;
  }
  *param_2 = bVar1;
  param_2[1] = bVar1;
LAB_060e479e:
  param_2[2] = bVar1;
  return;
}



void FUN_060e47a8(undefined4 param_1)

{
  undefined4 local_10;
  undefined4 uStack_c;
  
  uStack_c = 0;
  local_10 = 0x11000000;
  (*(code *)PTR_FUN_060e47d4)(param_1,(int)&local_10 + 1);
  (*(code *)PTR_FUN_060e47d8)(0,&local_10);
  return;
}



void FUN_060e480c(uint *param_1,uint *param_2,uint *param_3)

{
  undefined4 local_24;
  undefined4 uStack_20;
  undefined auStack_1c [2];
  ushort local_1a;
  byte local_18;
  ushort local_16;
  
  uStack_20 = 0;
  local_24 = 0x50000000;
  (*(code *)PTR_FUN_060e4864)(0,&local_24,auStack_1c);
  *param_3 = (uint)local_1a;
  *param_2 = (uint)local_18;
  *param_1 = (uint)local_16;
  return;
}



void FUN_060e4868(byte param_1,uint *param_2)

{
  undefined4 local_1c;
  int local_18;
  undefined auStack_14 [6];
  ushort local_e;
  
  local_1c = 0x51000000;
  local_18 = (uint)param_1 << 0x18;
  (*(code *)PTR_FUN_060e48a8)(0,&local_1c,auStack_14);
  *param_2 = (uint)local_e;
  return;
}



void FUN_060e48ac(byte param_1,undefined2 param_2,undefined2 param_3)

{
  undefined2 local_10;
  undefined2 uStack_e;
  undefined4 local_c;
  
  _local_10 = CONCAT22(0x5200,param_2);
  local_c = (uint)param_1 << 0x18;
  local_c = CONCAT22(local_c._0_2_,param_3);
  (*(code *)PTR_FUN_060e48e4)(0x40,&local_10);
  return;
}



void FUN_060e48e8(uint *param_1)

{
  undefined4 local_20;
  undefined4 uStack_1c;
  uint local_18 [3];
  
  uStack_1c = 0;
  local_20 = 0x53000000;
  (*(code *)PTR_FUN_060e4924)(&local_20,local_18);
  *param_1 = local_18[0] & DAT_060e4928;
  return;
}



undefined4 FUN_060e492c(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = (*(code *)PTR_FUN_060e4960)();
  if ((uVar1 & 0x40) == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = (*(code *)PTR_FUN_060e4964)(0,param_1,param_2);
  }
  return uVar2;
}



void FUN_060e4968(byte param_1,undefined2 param_2,uint *param_3)

{
  undefined2 local_20;
  undefined2 uStack_1e;
  int local_1c;
  uint local_18;
  undefined local_14;
  undefined local_13;
  undefined local_12;
  undefined local_11;
  
  _local_20 = CONCAT22(0x5400,param_2);
  local_1c = (uint)param_1 << 0x18;
  (*(code *)PTR_FUN_060e49e0)(0,&local_20,&local_18);
  *param_3 = local_18 & DAT_060e49e4;
  *(undefined *)(param_3 + 1) = local_14;
  *(undefined *)((int)param_3 + 5) = local_13;
  *(undefined *)((int)param_3 + 6) = local_12;
  *(undefined *)((int)param_3 + 7) = local_11;
  return;
}



void FUN_060e4a7c(byte param_1)

{
  undefined4 local_10;
  int local_c;
  
  local_10 = 0x30000000;
  local_c = (uint)param_1 << 0x18;
  (*(code *)PTR_FUN_060e4aa8)(0x40,&local_10);
  return;
}


