**unita di controllo**

ha come input l'istruzione corrente e si occupa di inviare dei segnali in ogni ciclo di clock, questi segnali possono essere di 3 tipi:
- trasferimento di registri
- funzioni della alu particolari
- trasferimento dati con la memoria/IO

l'unità di controllo può essere implementata in 2 modi:
* cablata --> tipica dei processori risc
* microprogrammata --> tipica dei processori cisc

in quella cablata le istruzioni sono definite dall'hardaware, attraverso diversi **circuiti combinatori**

in quella microprogrammata le istruzioni sono codificate da altre microistruzioni (un livello di astrazione) che sono definite sull'hardaware, ciò consente maggiore flessibilità e consente di creare istruzioni più sofisticate

NB: un circuito combinatorio è di base un insieme di porte logiche che si occupa di svolgere una specfica funzione come ad esempio il lo shifter oppure il multiplexer ed ogni input ha solo un preciso output e viceversa

di base l'unita di controllo cablata è fatta su hardaware, l'unità di controllo microprogrammata è un programma che ha in input l'istruzione e come output emette segnali per le microistruzioni che DEVONO essere eseguite sequenzialmente

## implementazione

siccome ogni microistruzione ha una combinazioni di segnali diversa si può definire come parola di controllo (è solo un altro nome), ogni parola di controllo viene inserita nella memoria di controllo interna all CU, ogni parola di controllo è associata all'indirizzo di un'altra parola di controllo, quando si esegue una parola di controllo questa chiama automaticamente la parola a cui punta, ciò consente di mantenere la sequenzialità delle istruzioni.
ad ogni codice operativo di istruzione corrisponde l'inizio di un microprogramma.

configurazione di segnali --> microistruzione <--> parola di controllo --> memoria di controllo --> control unit

**classificazione microistruzioni**
* orizzontali/orizzontali
* codifica diretta/indiretta
* microprogrammate hard/soft
* impacchetate/non impacchetate

di base quelle soft sono più incentrate nell'astrazione/ implemntazione di una logica complessa, le altre sono più rivolte all'hardaware e prestazioni

vantaggi
* flessibilità
svantaggi
* relativamente lento rispetto ad un sistema di controllo cablato



La CU per eseguire il suo ciclo di esecuzione è composta da un microprogramma (firmware) che consiste nel prendere in ingresso un'istruzione, mappare le microistruzioni corrispondenti, serializzarle ed eseguirle
