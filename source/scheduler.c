#include "../header/header.h"
int x;

void aging(){
  pcb_t* proc;
  list_for_each_entry(proc,ready_queue,p_next){
      proc->priority++;
  }
}


void scheduler(){

#if 0
  ptr = container_of(ready_queue, pcb_t, p_next);
  x = ptr->priority;
  list_for_each_entry(temp,ready_queue,p_next){
    if(x < temp->priority){
      x = temp->priority;
      ptr = temp;

    }
  }
  list_for_each_entry(temp,ready_queue,p_next){
    if(temp != ptr){
      temp->priority += 3;
    }
  }
  #endif

  if( (ptr = removeProcQ(ready_queue)) != NULL ){
  aging();

  ptr->priority = ptr->original_priority;
  
  #if 0
  if(ptr->p_s.pc_epc == (memaddr)test3){
    addokbuf("test3");

  }
  if(ptr->p_s.pc_epc == (memaddr)test2){
    addokbuf("test2");

  }
  if(ptr->p_s.pc_epc == (memaddr)test1){
    addokbuf("test1");

  }
  #endif

  //  ptr->p_s.status |= STATUS_TE;
  if(ptr->time_cpu == 0)
    ptr->time_cpu = GET_TODLOW;
  //addokbuf("qui");
  //setTIMER(SCHED_TIME_SLICE);
  LDST(&(ptr->p_s));
  }
  else{
    WAIT();
  }

}
