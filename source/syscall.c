#include "../header/header.h"


void sysHandler(){

    /*Ricavo la causa*/
    unsigned int cause = CAUSE_EXCCODE_GET(getCAUSE());
    /*Ricavo il tipo di exceptions*/
    unsigned int a0 = ((state_t*) SYSBK_OLDAREA)->reg_a0;

    switch (cause) {
      case EXC_SYSCALL:


          switch (a0) {

            case SYS3:
              x--;              //Chiamo la funzione per uccidere il processo e la sua progenie
              KillProc(ptr);
              break;

            default:
              PANIC();
          }
    }

}
