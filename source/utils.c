#include "../header/header.h"
void killMe(int cpuID){
	outChildBlocked(tmp);
	tmp = NULL;
	LDST(&tmp);
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
	//proc->p_s.status = proc->p_s.status & ~STATUS_KUc;
	//proc->p_s.status = proc->p_s.status & ~STATUS_VMc;
	tmp->p_s.status = tmp->p_s.status | STATUS_INT_UNMASKED;
	tmp->p_s.status = tmp->p_s.status & ~VM_OFF;
	tmp->p_s.status = tmp->p_s.status & ~KM_ON;
	tmp->p_s.status = tmp->p_s.status | STATUS_TE;
	//proc->p_s.status = proc->p_s.status | STATUS_TE;
	//proc->p_s.status = proc->p_s.status | STATUS_IEc;
	//proc->p_s.status = proc->p_s.status | STATUS_IEp;

	/*Assegnamento StackPointer*/
	temp->reg_sp = RAMTOP - FRAME_SIZE * n;


}
