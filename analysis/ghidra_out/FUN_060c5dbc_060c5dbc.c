
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

