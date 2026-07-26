
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

