#include "../header/header.h"
int n = 3;


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
  //newarea->status = newarea->status & ~STATUS_IEc;
  //newarea->status = newarea->status & ~STATUS_IEp;
  //newarea->status = newarea->status & ~STATUS_KUc;
  //newarea->status = newarea->status & ~STATUS_VMc;
  //newarea->status = newarea->status & ~STATUS_INT_UNMASKED;
  //newarea->status = newarea->status | STATUS_TE;

	newarea->status = newarea->status & ~STATUS_INT_UNMASKED;
//  newarea->status = newarea->status & ~STATUS_IEc;
	newarea->status = newarea->status & ~VM_OFF;
	newarea->status = newarea->status & ~KM_ON;
	newarea->status = newarea->status | STATUS_TE;
}



int main(){

  /* Inizializzazione delle due new Area necessarie*/

  initArea(INT_NEWAREA, (memaddr)interruptHandler);
  initArea(SYSBK_NEWAREA, (memaddr)sysHandler);

  /*Inizializzazione Pcb*/

  initPcbs();

  /*Inizializzazione ready_queue*/
  mkEmptyProcQ(&ready_queue);


  /*Creazione dei 3 processi per i 3 test*/
  addokbuf("inizio\n");

tmp = allocPcb();

  if(tmp != NULL){
    setProc(&(tmp->p_s),n);

	/*Assegniamo priorità n*/
	tmp->priority = n;

	/*Assegniamo anche la priorità originiale"*/
	tmp->original_priority = n;

  n--;

    tmp->p_s.pc_epc = (memaddr)test3;

  }
  insertProcQ(&ready_queue,tmp);

tmp = NULL;
tmp = allocPcb();
  if(tmp != NULL){
    setProc(&(tmp->p_s),n);

	/*Assegniamo priorità n*/
	tmp->priority = n;

	/*Assegniamo anche la priorità originiale"*/
	tmp->original_priority = n;
    n--;
    tmp->p_s.pc_epc = (memaddr)test2;

  }
  insertProcQ(&ready_queue,tmp);

  tmp = NULL;
  tmp = allocPcb();

  if(tmp != NULL){
    setProc(&(tmp->p_s),n);

	/*Assegniamo priorità n*/
	tmp->priority = n;

	/*Assegniamo anche la priorità originiale"*/
	tmp->original_priority = n;
    
    
  tmp->p_s.pc_epc = (memaddr)test1;

  }
  insertProcQ(&ready_queue,tmp);

  

  

  scheduler();



}
