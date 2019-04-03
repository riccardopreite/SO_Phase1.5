
pcb_t *tmp;
struct list_head* ready_queue;
state_t* new_old_areas[8];

HIDDEN void initArea(memaddr area, memaddr handler);
struct list_head* returnhead();
