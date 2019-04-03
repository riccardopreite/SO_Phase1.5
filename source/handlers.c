#include "../header/header.h"

void tlbHandler(){
  termprint("tlb\n", 0);
  /*

  int cpuID = getPRID();
  /*Se il processo coinvolto ha precedentemente specificato il proprio gestore (SYS5),
  allora l'eccezione viene "passed-up" a un livello superiore del kernel, copiando le aree corrispondenti,
  altrimenti viene terminato
  if(&new_old_areas[TLB_OLDAREA_INDEX] != NULL){

    saveArea(&tmp->p_s,&new_old_areas[TLB_OLDAREA_INDEX]);
    LDST(&tmp->p_s);
  }
  else
  killMe(cpuID);
    Il processo corrente viene terminato e il controllo tornato allo scheduler */
}

void trapHandler(){
  termprint("trap\n", 0);
  #if 0

  int cpuID = getPRID();
  /*se il processo che ha chiamato la system call, ha gia chiamato la sys5 per un PGM TRAP,
  lo stato del processore viene copiato dalla PGMTRAP old area nell'area dello stato del processore apposito*/
  if(&new_old_areas[PGMTRAP_OLDAREA_INDEX] != NULL){
    saveArea(&tmp->p_s,&new_old_areas[PGMTRAP_OLDAREA_INDEX]);
    LDST(&tmp->p_s);
  }
  else
  killMe(cpuID); /* Il processo corrente viene terminato e il controllo tornato allo scheduler*/
#endif
}

void sysHandler(){
  termprint("sys\n", 0);

  int cpuID = getPRID();

  /*Verifico se è chiamato SYSCALL() o BREAK()*/
#if 0
  int cause = CAUSE_EXCCODE_GET(getCAUSE());

  saveArea(&tmp->p_s, &new_old_areas[SYSBK_OLDAREA_INDEX]);
  /* Check User/Kernel mode. Controllo se una istruzione privilegiata è stata chiamata in user-mode,
  in tal caso chiamo il trapHandler*/
  if(tmp->p_s.reg_a0 <= SYSCALL_MAX  ){
    if(cpuID > 0){
      saveArea(&new_old_areas[SYSBK_OLDAREA_INDEX], &new_old_areas[PGMTRAP_OLDAREA_INDEX]);
      new_old_areas[PGMTRAP_OLDAREA_INDEX]->cause = CAUSE_EXCCODE_SET(CAUSE_EXCCODE_GET(new_old_areas[PGMTRAP_OLDAREA_INDEX]->cause), EXC_RESERVEDINSTR);
    }
    else{
      saveArea((state_t*)SYSBK_OLDAREA, (state_t *)PGMTRAP_OLDAREA);
      ((state_t *)PGMTRAP_OLDAREA)->cause = CAUSE_EXCCODE_SET(CAUSE_EXCCODE_GET( ((state_t *)PGMTRAP_OLDAREA)->cause), EXC_RESERVEDINSTR);
    }
    trapHandler();
  }
  if(cause == EXC_SYSCALL){
    if (tmp->p_s.reg_a0 == TERMINATEPROCESS) {
      /* code */

      insertProcQ(&ready_queue,tmp);
      //tmp->p_s.pc_epc += WORD_SIZE;

    }
    termprint("prima scheduler\n", 0);

    LDST(&tmp->p_s);

    scheduler();

  }
  else if(cause == EXC_BREAKPOINT){
    HALT();
  }
   #endif

}
