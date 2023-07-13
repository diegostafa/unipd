**java**

* sintassi C
* jvm --> permette di eseguire lo stesso bytecode su macchine diverse
* la compilazione dei srogenti è deterministica e non dipende dall'ordine di apparizione delle classi
* ogni classe deve apparire in un unica dir
* il binding dei nomi viene fatto a runtime
* i metodi sono identificati da nome e argomenti (no tipo di ritorno)
* visibilità metodi e classi
    * private --> solo stessa classe
    * protected --> solo derivate
    * default --> classi dello stesso package
    * public --> tutte le altre classi
* obbligatorio dichiarare una parte di codice soggetta ad eccezioni
* ereditarietà singola per le classi
* ereditarietà multipla per le interfacce
* diamond problem da errore semantico di compilazione
* le interfacce possono essere create da classi anonime specificano il corpo dei metodi richiesti
* le interfacce possono contenere metodo implementati
* interfaccia funzionale --> interfaccia con un solo metodo
* annotazione --> interfaccia speciale che aggiunge metadati e strutture sintattiche alle derivate
* i tipi primitivi onn sono oggetti
* i tipi primitivi hanno una relativa versione ad oggetto (boxed) meno efficente da usare
* un primitivo non può essere null
* le espressioni producono primitivi o oggetti
* le istruzioni non producono valori
* le istruzioni non sono garantite sequenziali dal compilatore, a meno di richiederlo esplicitamente
* lambda --> si può usare come sostituo alle interfacce funzionali
* try è richiesto per circondare codice possibile ad eccezioni
* l'interfaccia closable permette di non dover gestire la chiusura delle risorse
* default methods --> causano diamon problem

**paradigmi**

* concorrenza --> risorse comuni, compiti diversi
* parallelismo --> risorse comuni, compiti comuni
* rete --> risorse isolate, compiti diversi
* distribuzione --> risorse isolate, compiti comuni

**concorrenza**

* nato per motivazioni economiche
* sfrutta al meglio le risorse di una macchina
* problemi
    * non determinismo
    * starvation
    * race condition
    * deadlock --> accade solo con le condizioni di coffman
* si può implementare in modo:
    * collaborativo
    * preentivo
    * tempo reale
    * ad eventi
* una linea di esecuzione è rappresentata in java da un oggetto thread
* JVM termina correttamente solo quando i thread creati da utente terminano tutti
* un thread ha gli stati
    * new
    * runnable/running
    * blocked/waiting/timed/waiting
    * terminated
* runnable --> interfaccia che definisce un compito da eseguire
* callable --> interfaccia che definisce un compito che produce un risultato (un future)
* executor --> gestore di thread callable o runnable
* stream --> struttura dati che esegue le operazioni in parallelo se necessario
    * decide cosa fare in base ai flag indicati
* splititerato --> scorre uno stream
* collector --> interfaccia per la riduzione di uno stram
* la sincornizzazione dei thread avviene con 
    * synchronized
    * wait/notify
    * lock/unlock
    * semafori

**distribuzione**

* scalabilità superiore rispetto ad un nodo
* resilienza ai guasti
* localizzazione vicina agli utenti
* problemi
    * concorrenza tra nodi
    * asincronia
    * fallimenti dei nodi
* comunicazione tra nodi con messaggi
* socket --> astrazione TCP per comunicazione bidrezionale, asincrona e non limitata
    * trasporta solo byte
datagram --> astrazione UDP, comunicazione stateless, senza connessione, il ricevente si mette in ascolto
* channel --> astrazione di socket e datagram, eventi legati da oggetti di contesto
    * attachment --> cambia stato in modo sicuro tra i thread
* stato distribuito --> oltre ai vantaggi computazionali offre vantaggi di conservazione dati
    * resilienza ai guasti
    * gestisce più richieste
    * accessibilità geografica
* CAP -->  in caso di partizione si deve scegliere tra disponibilità e consistenza
* CRDT --> strutture dati concorrenti, permettono modifiche della struttura da più entitò contemporaneamente

**reattività** 

* realizza sistemi fortemente asincroni ma semplici
* bassa latenza
* reactive extension --> insieme di interfacce per la costruzione semantica di elaborazione asincrone su streams
* reactive streams --> stream che offre garanzie di:
    * back pressure --> resistenza alla velocità di dati input
    * definire quanti dati può elaborare


**attori**

* comunicano solo con altri attori
* thread safe interno
* quando fallisce un attore il padre decide cosa fare
* operazioni SINGOLE che può eseguire al ricevimento di un messaggio
    * cambiare stato interno
    * creare figli
    * inviare messaggi
    * cambiare comportamento per i prossimi messaggi




- concorrenza
    - tipi
    - problemi
    - coffman
    - thread safety
    - thread local variables
    - accesso sincronizzato
    - stream
- distribuita
    - RPC
    - serializzazione
    - socket
    - datagram
    - channel
    - fallacie
    - framework
    - consenso
    - CAP
    - PACELC
    - CRDT
    - OT
    - teorema CALM
- reattività
    - extension
    - manifesto
    - reactive stream
- attori
    - caratteristiche
    - conseguenza
    - problemi