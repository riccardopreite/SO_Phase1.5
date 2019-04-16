# SO_Phase1.5
Fase 1.5 del progetto di Sistemi Operativi

#Autori:
  Riccardo Preite
  Massimo Monacchi
  Guillaume Franzoni Darnois
  Roberto Barbone
  
#Per compilare:
  Entrare nella cartella master e dare il comando make;
  Verrano generati i file .core e .stab da inserire nella macchina (il file contente la macchina è già presente nel caso         qualcuno voglia usarlo);
  Per pulire il tutto basta un make clean;
  
  
Il progetto si occupa di gestire 3 processi da mandare in esecuzione switchando questi 3 test ogni 3ms.
Tutto viene gestito da uno scheduler, cuore principale del progetto, e da una syscall e un'interrupt che permette di killare definitivamente un processo e stoppare quello in esecuzione salvandone lo stato rispettivamente.
