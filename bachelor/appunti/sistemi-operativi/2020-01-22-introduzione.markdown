## cenni storici

* computer calcolavano e basta (batch system)
* programmi --> batch --> schede perforate
* operazioni di input/output venivano fatte a parte, non simultaneamente all'esecuzione di un programma
* spooling --> possibilitò di eseguire IO simultaneamente all'esecuzione di un programma

## sistemi operativi

sistema operativo --> nasce con i nuovi linguaggi di programmazione, astrazione dell'assembler, cioè elimina i particolari di microprogrammazione al programmatore

ci sono 2 tipi di sistemi operativi:
* industriali/dedicati --> risiedono nella ROM
* commerciali --> bootstrap nella ROM, sistema operativo nella memoria esterna

il programma di bootstrap si occupa di caricare il SO in RAM all'avvio

## Processi

processo --> programma in esecuzione

definiti come:
* insieme di stati (ready, waiting ...)
* insieme di azioni (read, write ...)

divisione per privilegi:
* processi utente
* processi SO

possono anche essere divisi in:
* cpu bound --> se la loro esecuzione è principalente in cpu
* I/O bound --> se la loro esecuzione presenta molte operazioni di I/O


## Kernel

il kernel di base è un programma che deve
* monitorare lo stato dei processi
* fare lo scheduling
* gestire gli eventi (interrupt, altri eventi ...)
* offrire un sistema di communicazione tra processi

per gestire i processi si fa uso della proccess table, un processo è definito dal suo process control block, che ne definisce, lo stato, l'id, il process status word ...

il rilascio della cpu da parte di un processo può essere implementato in 2 modi:
* scambio cooperativo --> il processo decide quando lasciare la risorsa
* scambio a prerilascio --> il sistema operativo di occupa di implementare una politica di scheduling

**Scheduler**

programma che ordina una lista di processi in stato di ready secondo una determinata politica, definisce quindi il periodo di esecuzione dei processi

**Dispatcher** 

programma che si occupa dello scambio di 2 processi, contiene quindi le operazioni per effettuare il context switch e altra roba

## Risorse

una risorsa è qualsiasi cosa hardware e software necessaria ad un processo per una qualsiasi cosa tra:
* creazione
* esecuzione
* terminazione

le risorse possono essere
* durabili/consumabili
* divisibili --> definisce quanti accessi simultanei la risorsa consente
* molteplici --> definisce quante istanze della risorsa sono disponibili

la più importante e indispensabile risorsa di ogni processo è la cpu, questa può essere vista come una normale cpu dal lato fisico (senza astrazioni), oppure come una macchina virtuale dal lato logico.

la memoria è un'altra particolare risorsa che
* in scrittura --> accesso indivisibile
* in lettura --> accesso multiplo

l'accesso logico di una risorsa presenta un'interfaccia uniforme, quello fisico necessita del bios relativo
