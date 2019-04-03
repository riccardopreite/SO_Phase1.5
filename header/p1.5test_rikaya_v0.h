
#include "types_rikaya.h"
#include "types.h"
#include "const.h"
#include "listx.h"
#include "pcb.h"

static unsigned int get_microseconds();

static void delay_ms(unsigned int ms);

//devreg_t termstat(memaddr *stataddr);

unsigned int termprint(char *str, unsigned int term);

void addokbuf(char *strp);

void adderrbuf(char *strp);

void log_process_order(int process);

void test1();

void test2();

void test3();
