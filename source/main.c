#include "../header/header.h"
int n;
struct list_head* returnhead(){
  return ready_queue;
}
void initArea(memaddr area, memaddr handler){
  //Creo la nuova area che punta alla vecchia

  state_t* newarea = (state_t *)area;

  //Salvo lo stato attuale del processore
  STST(newarea);

  /*Settato SP a RAMTOP*/
  newarea->reg_sp = RAMTOP;

  /*Settato PC all'handler passato*/
  newarea->pc_epc = handler;

  /*Settata ker mode on, interrupt mascherati & disabilitata virtual memory & attivato timer cpu*/
  newarea->status = (((0 & ~STATUS_INT_UNMASKED) & VM_OFF) & KM_ON) | STATUS_TE;
}



int main(){

  /* Inizializzazione delle new Area*/
  initArea(INT_NEWAREA, (memaddr)interruptHandler);
  initArea(SYSBK_NEWAREA, (memaddr)sysHandler);
  initArea(TLB_NEWAREA, 0);
  initArea(PGMTRAP_NEWAREA, 0);

  /*Inizializzazione Pcb*/
  initPcbs();

  /*Inizializzazione ready_queue*/
  mkEmptyProcQ(&ready_queue);


  /*Creazione dei 3 processi per i 3 test*/
  for(n = 3; n > 0; n = n-1){
    tmp = allocPcb();

    if(tmp != NULL){
      setProc(&(tmp->p_s),n);

      /*Assegniamo priorità n*/
      tmp->priority = n;

      /*Assegniamo anche la priorità originiale"*/
      tmp->original_priority = n;
      /*switch per assegnare l'indirizzo di memoria del test da eseguire*/

      switch (n) {
        case 3:
        tmp->p_s.pc_epc = (memaddr)test3;
        break;

        case 2:
        tmp->p_s.pc_epc = (memaddr)test2;
        break;

        case 1:
        tmp->p_s.pc_epc = (memaddr)test1;
        break;

      }
      /*inserimento del processo nella coda*/
      insertProcQ(&ready_queue,tmp);
    }
    else{
      PANIC();
    }
  }


scheduler();

}
