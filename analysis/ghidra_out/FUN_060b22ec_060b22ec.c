
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

