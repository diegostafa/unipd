**kernel mode**

la cpu ha completo controllo del sistema, 3 eventi permettono di entrare in kernel mode:
1. interrupt asincroni --> I/O device
2. system calls --> write()
3. eccezioni --> divisione per 0

quando si incorre a ciò la procedura è questa:
1. la cpu entra in kernel mode
2. la cpu salva il contesto del processo
3. si utilizza il numero associato all'evento per determinare la procedura da eseguire
4. se il processo chiamante 

**system calls**

interfaccia del sistema operativo per eseguire operazioni in kernel mode, sono indirizzate da un numero

la programmazione non usa system calls direttamente nel codice, ma si usano dei wrapper offerti dal linguaggio di programmazione (es. win32 api, posix api ...)

si usano wrapper perchè possono eseguire operazioni di controllo (errro codes) inoltre aumentano la portabilità del programma, le api sono comuni in tutti i sistemi, le system calls possono cambiare

esempio

user mode --> print("ciao") --> std library --> write() --> trap --> kernel mode


passaggio di parametri a system calls:
1. passaggio di parametri utilizzando i registri --> semplice ma pochie piccoli registri
2. parametri salvati in un blocco di memoria e passaggio dell'indirizzo del blocco
3. parametri caricati sullo stack

classificazione delle system calls:
* process control --> createProcess(), exit()...
* file manipulation --> createFile(), readFile()...
* IO device manipulation --> setConsole(), readConsole()...
* status control --> getTimer(), getProcessID()...
* communication --> createPipe()...
* protection --> setFileSecurity()...

## organizzazione OS

**monolitico**

tutto sta all'interno del kernel
* pro --> veloce
* contro --> complesso

**a strati**

le funzionalità dell'os sono divise
* pro --> sicurezza, debug
* contro --> la comunicazione è limitata a gli strati adiacenti

**microkernel**

opposto del monolitico, contiene il minimo indispensabile (comunicazione, siucurezza ...)
* pro --> semplice
* contro --> deve switchare tra user e kernel mode molte volte

* a moduli
pro --> veloce, debug
contro --> poco sicuro

## Processi

stato di un processo
1. new
2. ready
3. running
4. waiting
5. terminated

**PCB**

process control block, contiene tutti i dati e valori che identificano e determinano lo stato di un processo

**process state queues**

lista di processi nello stesso stato
* ready queue
* wait queue
* running queue --> cpu bound

**quantum slice** 

tempo di cpu assegnato ad un processo

**context switch** 

operazione di scambio tra processi in cpu

**creazione di processi**

un processo può essere creato, ovviamente, solo da un altro processo

es.

kernel --> ... --> user interface --> chrome

in unix la creazione di un processo è affidata alla system call Fork(), di base fork crea una copia esatta del processo chiamante tranne che per il cID da li usare la system call Exec() per usare il processo figlio come contenitore del processo che si vuole creare

cID --> id del processo figlio

NB: il padre può usare Wait() per aspettare la terminazione del processo figlio prima di continuare, wait() funziona su qualsiasi processo ma viene solitamente utilizzato nei figli

## Sicronizzazione tra processi

i processi possono si possono dividere in
* indipendenti
* cooperanti --> necessitano di altri processi per la loro esecuzione

processi cooperativi anologhi al modello di produttore-consumatore

la comunicazione può avvenire in 2 modi

1. **message passing**

utilizzo di system calls per la comunicazione tra processi (implementabili come IO bloccanti/non)

* send()
* receive()

2. **shared memory**

utilizzo di system calls per indicare aree di memoria condivise con altri processi

* mmap()

la shared memory porta al problema della sicronizzazione tra processi

### link utili

* [Corso sui sistemi operativi](http://lass.cs.umass.edu/~shenoy/courses/377/lectures.html)
* [concetti base](https://www.cs.rutgers.edu/~pxk/416/notes/03-concepts.html)
