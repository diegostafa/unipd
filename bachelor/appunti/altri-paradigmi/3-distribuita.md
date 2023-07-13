**programmazione distribuita**

tecniche di gestione di più processi su macchine diverse che operano in modo coordinato per un unico compito
* i processi possono essere eseguiti sui nodi attivi
* la mole di lavoro viene suddivisa tra i nodi
* tutti i nodi hanno i risultati
* i nodi lavorano contemporaneamente
* i nodi comunicano tramite messaggi in rete
* l'unica risorsa condivisa è la rete

**algoritmo distribuito**

* totale asincronia --> l'ordine temporale di esecuzione non è rilevante
* fallimenti non identificabili --> un nodo guasto o che non ha terminato l'elaborazione sono uguali

**RPC - remote procedure call**

* rende trasparente la chiamata del codice da nodi esterni, rendendola simile ad una chiamata locale

funzionamento
* il client chiama lo stub locale
* lo stub crea un messaggio con i parametri
* il messaggio viene inviato al nodo destinatario
* il server stub riceve il messaggio
* il server stub chiama la procedura con i parametri ricevuti
* il server risponde allo stesso modo

note:
* il server prende il nome di object broker

**RMI - remote method call**

* RPC ma invece di parametri si usano oggetti
* nasce il problema della serializzazione

**serializzazione**

* codifica di un oggetto in un messaggio
* sconsigliata la serializzazione nativa in java

problemi:
* serializzare grafi di oggetti
* non serializzare certi oggetti
* assicurare consistenza dei dati
* efficienza in tempo e spazio

**socket**

* astrazione client-server TCP/IP
* client crea collegamento, il server ascolta per le connessioni
stream creati:
* inputstream --> riceve messaggi
* outputstream --> invia messaggi
* gli stream sono tutti thread safe
    * lettura e scrittura un thread per volta
* i dati in eccesso possono essere scartati se superiori al buffer
* garanzia di oridnamento e ricezione

* a fine comunicazione il socket va CHIUSO
* appena il server riceve \n termina la comunicazione

**datagram**

* astrazione UDP
* non c'è garanzia di ricezione e ordinamento
* dimensione max del messaggio nota,  64kb
* non ci sono client e server, ma si invia un pacchetto ad un indirizzo
* possibilità di multicast (inviare a più indirizzi in contemporanea)
* unidirezionale, per ricevere una risposta ci si deve mettere in ascolto

**channel**

* canale I/O che può essere aperto e chiuso
* può ascoltare e inviare a più richieste contemporaneamente
* netowrkChannel --> rappresenta una comunicazione di rete
* asyncServersocketChannel --> gestione delle richieste async, bisogna implementare:
    * completetionHandler()
    * completed() --> invocato quando viene completata un'operazione
    * i vari handler sono chiamati da thread

**PAXOS**

algoritmo di consenso distribuito che garantisce l'assenza di blocchi nel caso di un guasto singolo
* i nodi possono essere:
    * leader
    * votanti
    * ascoltatori
    * proponenti
    * client
* il client invia una richiesta
* il proponente la invia ai votanti
* i votanti votano la richiesta
* gli ascoltatori ascoltano i votanti per evitare guasti e garantire ridondanza
* il leader coordina il protocollo e gestisce le anomalies

**RAFT**

* simile a paxos
* suddivide in sottoproblemi
* semplice da implementare
* disponibile in java

**trilemma CAP**

solo 2 tra queste possono essere garantite in un DB distribuito
* consistency --> lettura dei dati più recenti o errore 
* availability --> ogni richiesta riceve una risposta valida
* partitioned --> il sistema funzione anche in assenza di alcuni nodi

**PACELC**

* estende il CAP
* DB partizionato
    * consistency VS avaiability
* DB non partizionato
    * consistency VS latency

**OT - operational trasformation**

* ogni nodo ha le sue modifiche
* le modifche vengono propagate ad altri nodi
* i nodi che ricevono applicano le modifiche
* complesso da implementare

**CRDT - conflict-free replicated data type**

strutture dati che garantiscono di poter essere riconciliate risolvendo ogni possibileconflitto, tipo:
* last-write-win
* 2-pahse set

chiusura esplicita dello stream
**CALM - consistency as logical monotonicity**

* un programma è logicamente monotono se all'aumentare della dimensione del problema il risultato non cambia
* i programmi CP (da CAP) sono logicamente monotoni