
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

