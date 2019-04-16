#include "../header/header.h"


void KillProc(pcb_t *pcb){

    if(pcb!=NULL){
        while(!emptyChild(pcb)){
            KillProc(removeChild(pcb));
        }
        outChild(pcb);
        if(pcb == ptr){
            ptr = NULL;
        }

        outProcQ(&ready_queue, pcb);
        freePcb(pcb);
    }

    scheduler();
}



void saveArea(state_t* new,state_t* old) {
	int i; for(i=0;i<29;i++){
	(*old).gpr[i]=(*new).gpr[i];
}
	(*old).entry_hi=(*new).entry_hi;
	(*old).cause=(*new).cause;
	(*old).status=(*new).status;
	(*old).pc_epc=(*new).pc_epc;
	(*old).hi=(*new).hi;
	(*old).lo=(*new).lo;
}



void setProc(state_t* temp, int n){
	/*settaggio registri*/
	temp->status = (((0 | INT_MASK_TIME_ON) & VM_OFF) & KM_ON) | STATUS_TE;

	/*Assegnamento StackPointer*/
	temp->reg_sp = RAMTOP - FRAME_SIZE * n;


}
