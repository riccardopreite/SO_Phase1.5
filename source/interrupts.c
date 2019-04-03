#include "../header/header.h"
void interruptHandler(){
	addokbuf("Interrupt\n");

	int cause = getCAUSE();
	int cpuID = getPRID();

//if(CAUSE_IP_GET(cause, INT_LOCAL_TIMER)) 
if(cause == 1){
	addokbuf("Interrupt3\n");
	//setTIMER(SCHED_TIME_SLICE);
	//LDST(INT_OLDAREA);
	if(ptr != NULL){
	list_add_tail(&(ptr->p_next),&ready_queue);

	//	insertProcQ(&ready_queue, ptr);
	}
}

scheduler();
}
