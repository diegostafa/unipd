Il linguaggio macchina è l'insieme delle istruzione che la cpu può eseguire, un'istruzione è una sequenza di bit che compie una delle seguenti azioni:

* elaborazione dati --> add, sub, rtl ...
* salvataggio dati --> store
* trasferimento dati I/O --> read, write
* controllo del flusso di esecuzione --> jump, jmpz ...

un istruzione ideale richiederebbe i campi per:
* codice operativo --> identiica il tipo di istruzione
* operando risultato
* tutti gli operandi per l'istruzione
* indirizzo per l'istruzione successiva

ciò però è molto dispendioso, perciò solitamente si hanno solo codice operativo (necessario), operando 1 e operando 2 (alle volte anche operando 3)

### istruzioni con 0 operandi
sono istruzioni che utilizzano il concetto di pila, perciò non necessitano di registri che contengano gli operandi (tranne per la pila ovviamente)

un operazione che utilizza 2 operandi utilizza quelli in cima alla pila, esegue l'operazione e salva il risultato in cima (dopo aver rimosso i 2 operandi usati)

### istruzioni con 1 operando
sono istruzioni che utilizzano un registro implicito, l'accumulatore, come operando risultato, ogni operazione viene eseguita con il contenuto dell'accumulatore e l'operando indicato e salvato sull'accumulatore.

istruzioni con pochi operandi:
* pro --> sono semplici, la cpu lavora meno
* contro --> per eseguire complesse sono necessarie molte istruzioni

## **linguaggio Assembly**
di base è un linguaggio simbolico che mappa ogni codice operativo (in bit) in un codice mnemonico umano, necessita di un assemblatore che traduca il linguaggio mnemonico in macchina per la cpu.


### Indirizzamento degli operandi

* immediato --> l'operando è parte dell'istruzione
* diretto --> l'operando è nell'indirizzo specificato nell'istruzione
* indiretto --> viene specificato l'indirizzo (in memoria) dell'indirizzo (in memoria) che contiene l'operando
* a registro --> si specifica il nome del registro
* a registro indiretto --> viene specificato l'indirizzo (nel registro) dell'indirizzo (in memoria) che contiene l'operando
* a spiazzamento --> metà campo indica un indirizzo, l'altra metà è un offset da sommare
* relativo --> si somma il valore del campo a program counter
