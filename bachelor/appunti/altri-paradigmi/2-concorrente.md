**processi**

non condividono risorse, ma possono comunicare tra loro tramite messaggi

**threads**

processi che condividono le risorse

**programmazione distribuita**

le entità possono comunicare ma non possono condividere le risorse

**programmazione funzionale**

i dati sono immutabili

**programmazione concorrente**

mutabbili e condivisi, problemi:
* non determinismo --> esecuzione non prevedibile
* starvation --> il thread non riceve abbastanza risorse
* race condition --> l'ordine di accesso alle risorse modifica l'esecuzione
* deadlock --> P1 ha bisogno delle risorse di P2 per completare, stesso per P2, nessuno completa

**condizioni di coffman**

descrivono le condizioni necessarie di deadlock
* mutalmente esclusivi
* trattentua di risorse
* i processi non vengono preentivati dall'esterno
* attesa circolare

**tipi di concorrenza**

* collaborativa --> i processi cedono il controllo regolarmente
* preentiva --> il SO interrompe i processi e affida le risorse
* in tempo reale --> il SO garantisce prestazione particolari
* a eventi/asincrona --> un gestore di eventi gestisce il controllo dei processi, il programma si deve solo sottoscrivere ad un evento


**threads**

* rappresentati dalla classe Thread

stati:
* new --> thread creato
* runnable --> pronto per l'esecuzione
* running --> in esecuzione
* blocked --> accesso a risorsa bloccante
* waiting --> accesso ad una risorsa occupata
* time_waiting --> in pausa per un tot
* terminated --> thread concluso


**esecutori**

gestiscono l'esecuzione di un pool di thread

* cachedThreadPool --> riusa i thread
* scheduledThreadPool --> lancia i thread seguendo una schedule
* singleThreadExecutor --> usa un solo thread per tutto

**callables**

thread che producono un risultato, o un eccezione se non riescono

**future**

è una promessa che il calcolo prima o poi ritornerà un valore

**variabili atomiche**

* java.concurrent.atomic
* la modifica del valore è atomica e non blocca i thread
* generalizzazione dei volatile

**volatile**

* variabile leggibile solo da RAM e non da cache intermedie
* garantisce che ithread leggano lo stesso valore
* happens-beofre --> garanzia del compilatore sull'ordine di esecuzione delle istruzioni
    * costoso, il compilatore non può ottimizzare
    * necessita di supporto hardware

solitamente i thread lavorano su variabili in cache seaparate, quindi la stessa variabile può avere valori diversi in thread diversi, volatile sistema questo

**strutture dati concorrenti**

strutture efficienti rispetto a quelle sinconizzate
* concurrentMap --> atomicità e happens before
* concurenthasmap --> ricerca suddivisa in più thread
* blockingqueue

**threadlocal**

Una variabile ThreadLocal esiste in una copia
diﬀerente ed indipendente per ciascun Thread che attraversa la sua dihiarazione

**sezione ciritica**

parte di codice che contiene dati condivisi, più thread in una sezione critica possono causare errori

soluzioni:
* synchronized(this) --> definisce un metodo o blocco di codice attraversabile da un solo thread per volta, viene garabtito con un monitor condiviso
* synchronized(that) --> sincronizza rispetto al monitor dell'oggetto that
* wait() --> stoppa un thread finchè non viene risvegliato da un altro thread (oppure da solo, spurious wakeup)
* interfaccia lock --> accesso/rilascio delle risorse esplicito definito dal thread
    * lock()
    * unlock()
    * trylock()

**producer consumer**

* producer --> thread che scrive dati
* consumer --> thread che legge dati
* il semaforo gestisce la coda di accessi


**semafori**

un lock che tiene un contatore, invece che un booleano
* fair --> i thread sono ordinati per fifo
* ad ogni acquisizione si decrementa
* ad ogni rilascio si incrementa
* può essere rilasciato da un thread diverso che l'ha eseguito
* tryAcquire --> falso se non ottiene la risorsa

**stream**

* rappresenta l'iterazione su un insieme possibilmente infinito
* meno operazioni possibili 
* permette di eseguire una pipeline di operazioni su una successioe di oggetti
* approccio funzionale
* esecuzione sequenziale e parallela
* uno stream richiede un algoritmo di calcolo per la ricerca/oridnamento
* flags --> informazioni sull stato dello stream dichiarate alla sorgente
    * concurrent --> operazioni parallelizzabili
    * distinct --> non ci sono elementi uguali
    * immutable
    * nonnull
    * ordered --> garantisce di ritornare gli elementi come sono stati emessi
    * sized --> definisce la dimensione dell'insieme
    * sorted --> mantiene l'ordine degli elementi
    * subsized --> definisce la dimensione dei sottoinsiemi per la parallelizzazione
* le operazioni ai passi intermedi di calcolo devono essere funzioni pure, cioè non modificano gli elementi
* riduzione --> operazione che trasforma lo stream in un oggeto usando gli elementi
* gli errori sono gestiti come eccezioni
* manca la gestione della terminazione dello stream

**spliterator**

iteratore che
* stima gli elementi rimanenti
* contiene le caratteristiche della sorgente
* suddivide l'iterazione in più rami

**parallel streams**

forkjoinpool = # cores / 1 - BF
* blocking factor di un algoritmo
    * BF = 0 --> esecuzione perenne in CPU
    * BF = 1 --> attesa perenne di I/O