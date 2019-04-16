#include "../header/header.h"
void interruptHandler(){

	int cause = getCAUSE();

if(CAUSE_IP_GET(cause, INT_LOCAL_TIMER)) {
	/*Salvo lo stato del processore*/
	saveArea((state_t*)INT_OLDAREA,&(ptr->p_s));

	insertProcQ(&ready_queue, ptr);

}

scheduler();
}
