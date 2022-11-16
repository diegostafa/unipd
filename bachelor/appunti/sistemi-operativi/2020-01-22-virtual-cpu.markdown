### virtualizzazione della cpu

si ottiene con la tecnica del time-sharing/multiprogrammazione, l'illusione di avere molti processi in esecuzione contemporaneamente è di base l'alternarsi di diversi processi molto velocemente (per l'utente)

### processi

l'unità di lavoro della cpu è il processo, una struttura creata dall'os per creare questa astrazione, di base un processo è un programma in esecuzione che assume diversi stati nel corso del tempo

un processo può essere rimosso dalla cpu mantenendo comunque il suo stato di esecuzione, che non è altro che l'insieme di tutti i registri e valori in un determinato istante.

context switch --> operazione software che consiste nel salvare tutti i registri della cpu in memoria di un processo e caricarne altri di un altro processo

### virtualizzazione

la virtualizzazione della cpu è gestita principalmente da 2 programmi:
* sheduler
* dispatcher

### scheduler

lo scheduler si occupa di 3 funzioni
* long term scheduling
* mid term scheduling
* short term schedulin

**long term scheduling** 

definisce quali processi sono ammessi nella coda dei processi, ciò è stabilito dall'hardware della macchina, si occupa quindi di stabilire il numero massimo di processi parallelizzabili e cose del genere

**mid term scheduling** 

di base si occupa di stabilire quali del processi in memoria possono essere swappati in memoria secondaria per fare spazio

**short term scheduling** 

determina quale processo eseguire in un lista di processi pronti in base ad una policy

le policy dello scheduler stabiliscono delle regole per selezionare quale processo mandare in esecuzione, ce ne sono diverse:

* non preemptive
    * FIFO --> seleziona il primo processo richiedente e lo esegue a terminazione
    * SJF --> seleziona il processo più corto e lo esegue a terminazione

* preemptives
    * SRTF --> seleziona il processo più corto, sostituibile dall'os da un processo più corto
    * RR --> utilizza lo schema FIFO assegnando un tempo di esecuzione fisso ad ogni processo
    * MLFQ --> come il RR solo che si hanno più code di processi in attesa di diversa priorità
    * a lotteria --> si esegue il processo con il biglietto vincente

### dispatcher

programma che si occupa di effettuare lo scambio tra processi salvando gli opportuni registri e caricando gli altri.

### stato di esecuzione di un processo

- created --> long term scheduling
- ready --> short term scheduling
- running --> la cpu esegue il codice
- blocked --> il processo viene rimosso dalla cpu poichè ha inviato una syscall bloccante (attesa di I/O)
- terminated
