# Data link

## HDLC (High-level Data Link Control)

è stato il primo protocollo creato data-link, fatto da ibm, ancora usato nella rete dei bancomat e trasmissione satellitare

formato da:
* flag byte (header)
* paylod --> bit stuffed 
* checksum (2 byte) --> CRC-16
* address (1 byte) --> serve per indirizzamento in un end-point con terminali multiplic
* control (1 byte) --> consente di inviare 3 comandi
* flag byte (trailer)

la parte di control serve a mandare frame di controllo, 3 tipi:
* information
* supervisory
* unnumbered

sliding window a 3 bit (8 finestre):
* 4 pacchetti in paralllelo

**information**

usato per informare la sliding window aperta, composto da:
* 1 bit --> indica che è un comando di information
* seq (3 bit) --> numero della sliding window
* P/F (1 bit) --> poll/final, chiede di iniziare o terminare la trasmissione
* next (3 bit) --> contiene eventuale ack (piggybacking)


**supervision**

è usato per comunicare lo statp della trasmissione, composto da:
* 10 (2 bit) --> indcia che è un comando di supervision
* type (2 bit) --> 4 segnali/comandi di supervisione
* p/F (1 bit)
* next (3 bit)

tipi di segnali/comandi supervision:
* RECEIVE READY --> il flusso è sbilanciato, viene utilizzato quando non si può fare piggybacking, il messaggio inviato è solo l'ack (camion vuoto con solo ricevuta di rit.)
* REJECT --> è un NAK generico, segnala che vanno ritrasmessi tutti i frame a partire da quello indicato nella sliding window del campo next
* RECEIVE NOT READY --> segnala che ci sono problemi di congestione, il mittente smette di trasmettere fino al prossimo segnale di RECEIVE READY
* SELECTIVE REJECT --> è un NAK preciso, segnala di ritrasmettere solo il frame del campo next

**unnumbered**

usato per comandi di controllo generici, composta da:
* 11 (2 bit) --> indica che è un comando unnumbered
* type --> segnali/comandi unnumbered
* P/F
* modifier

tipi di segnali/comandi unnumbered:
* DISC --> si sta per essere disconnessi dalla rete (diverso da F di P/F)
* SNRM (Set Normal Response Mode) --> indica un canale assimmetrico dove il nuovo entrato è meno importante (è meno importante per motivi storici)
* SABM (Set Asynchronous Balanced Mode) --> come SNRM, ma chi entra ha gli stessi diritti degli altri
* FRMR (FRaMe Reject) --> indica l'arrivo di un frame con una sequenza di controllo non riconosciuta

**UA**

siccome i segnali/comandi di controllo possono essere oggetto di interferenze come altri frame, si introduce il UA (Unnumbered ACK)

i segnali unnumbered vengono emessi in modo sequenziale, mai parallelo, perciò utilizza un protoccolo stop and wait, quindi il UA non ha bisogno di essere numerato

## PPP (Point to Point Protocol)

è il protocollo utilizzato nella rete internet, si apre una connesione PPP ogni qual volta un pacchetto attravarsa un pezzo diverso di rete

si compone di 2 sottoprotocolli:
* LCP (Link Control Protocol) --> per controllo del flusso, apertura/chiusura di canali e connessioni (data-link)
* NCP (Network Control Protocol) --> comunicazione con il network layer

frame PPP:
* flag byte (header) --> byte stuffing
* address (1 Byte) --> non si usa, lasciato costante a 1111111
* control (1 Byte) --> non si usa, lasciato costante a 0000011
* protocol (1/2 byte) --> indica se si sta usando LCP (bit = 0) o NCP (bit = 1)
* payload (var byte) --> il contenuto dipende dal protocol
* checksum (2/4 byte) --> CRC, definito a configurazione
* flag byte (trailer)


**LCP**

comandi LCP:
* configurazione
    * configure-request
    * configure-ack
    * configure-nak
    * configure-reject
* terminazione
    * terminate-request 
    * terminate-ack
* rifiuto
    * code-reject
    * protocol-reject
* echo
    * echo-request --> testa la qualità di trasmissione
* test
    * discard-request --> testa la linea e rileva i loops nella rete

comandi di configurazione:
* configure-request (sender to receiver) --> propone opzioni di configurazione della linea
* configure-ack (receiver to sender) --> accetta le condizioni di configure-request
* configure-nak (receiver to sender) --> rifiuta alcune condizioni di cofigure-request
* configure-reject (receiver to sender) --> rifiura tutte le condizioni di configure-request

parametri di configurazione:
* CRC-16 o CRC-32 (risparmia 1 byte)
* la lunghezza di protocol (risparmia 1 byte)
* lunghezza payload (MTU)
    * payloads grandi --> più rischio di ritrasmissione
    * payloads piccoli --> banda sprecata
* rimozione campo address
* rimozione campo control

comandi di terminazione:
* terminate-request --> richiede di terminare la comunicazione
* terminate-ack --> accetta

comandi di rifiuto:
* code-reject (receiver to sender) --> riconosce il protocollo, ma non riconosce il comando
* protocol-reject (receiver to sender) --> non ricoosce il protocollo

comandi di echo:
* echo-request (sender to receiver) --> chiede al receiver di rimandare questo pacchetto
* echo-reply (receiver to sender) --> lo rimanda

comando di test:
* discard-request (sender to receiver) --> chiede di ignorare il pacchetto

**PPPoE (PPP Over Ethernet)**

PPP è un frame per le reti internet, ma non tutte le reti sono internet, le reti ethernet, utilizzano il protocollo ethernet non PPP, quindi per arrivare a comunicare con il PPP si deve prima passare per l'ethernet (o un'altra rete locale) e poi si arriva alla rete internet

per far ciò il frame PPP che si vuole inviare viene inglobato nel payload etherent

questo piggybacking di frames avviene ogni qual volta si voglia inviare un frame PPP in una rete non internet

**ATM (Asynchronous Transfer Mode)**

è un derivato dell'HDLC, nato per telefonia e bancomat, gestisce il flusso di controllo con sliding windows di 16 finestre, CRC-8

ha un sistema di indirizzamento gerarchico, formato da:
* path (VPI Virtual Path Id)
* channel (VCI Virtual Channel Id)

virtual sta a significare che viene creata una connessione/sessione di trasmissione tra 2 end point

siccome le centraline ATM possono ricevere frame con protocolli diversi si utilizzano 2 protocolli per mandare i frame in uscita dalla centralina:
* frame LLC (Logical Link Control) --> può contenere frame di diverso protocollo
* fram VC-MUX (Virtual Connection Multiplexing) --> può contenere solo frame dello stesso protollo

## sistemi a contesa

sono sistemi di comunicazione multipla, in cui c'è un canale condiviso da molti in cui si crea contesa per ottenere il canale per comunicare

concetti base:
* station model --> le entità ottengono il canale per tutta la durata della trasmissione
* single channel --> c'è un canale singolo per la trasmissione
* collision --> se 2 pacchetti vengono trasmessi allo stesso tempo, vengono distrutti
* il tempo può essere:
    * continuo
    * slotted
* carrier sense --> ascolto del canale

**pure aloha**

è un protocollo a contesa

idea di base:
* se vuoi trasmettere, trasmetti
* se c'è collision, lancia un dado e aspetta prima di ritrasmettere

funzionamento:
* N utenti nel sistema
* tutti i frame hanno lunghezza T
* 

proprietà:
* entità multiple utilizzano lo stesso canale di comunicazione
* la banda si assesta al 18.4% indipendentemente dal numero di entità

**slotted aloha**

si può trasmettere solo in un certo clock di tempo

**CSMA 1-persistente (Carrier Sense Multiple Access)**

idea di base:
* se vuoi trasmettere ascolti il canale
* se è occupato non trasmetti e ti tieni in ascolto
* se è libero trasmetti con probabilità 1

pro:
* banda utilizzata > 50%

contro:
* tutte le stazioni che aspettano di trasmettere quando il canale si libera trasmettono insieme e accade quasi sempre una collisione

la persistenza

**CSMA P-persistente**

è il CSMA, ma se il canale è liberotrasmette con probabilità P

pro:
* banda utilizzata quasi al 100%

contro:
* se il canale è libero si trasmette comunque con probabilità p

**CSMA non-persistente**

idea di base:
* se vuoi trasmettere ascolti il canale
* se è occupato, lancia un dado e aspetti

pro:
* scala meglio
* non ha parametri
* non ha bisogno di nessun tipo di sincronizzazione

contro:
* banda utilizzata "solo" al 90%
* se il canale è libero si trasmette direttamente

**CSMA/CD (Collision Detection)**

è il CDMA con aloha, se c'è una collisione la stazione lancia un dado e aspetta prima di riprovare

in cdma/cd la rete può assumere 3 diversi stati:
* trasmissione --> qualcuno sta trasmettendo
* contesa --> c'è contesa per trasmissione
* idle --> non succede nulla

fase di contesa:
* una stazione invia dei bit di contesa
* se riesce a fare il ping con la stazione più lontana, trasmette
* se non riesce (collisione) lancia un dado e aspetta (aloha)

il tempo minimo per verificare il vincitore della fase di contesa è il round trip delay della stazione più lontana

**sistemi a contesa wireless**

il problema maggiore è il cambio della topologia, ogni stazione ha la sua area di comunicazione, che spostandosi può cioccare con quella di altre stazioni

problema della stazione nascosta  (trasmetto quando non dovrei trasmettere):
* la stazione A trasmette a B
* la stazione C non vede A ma vede B
* la stazione C quindi conclude di poter trasmettere a B
* A e C cioccano i pacchetti

problema della stazione esposta (non trasmetto quando dovrei trasmettere):
* la stazione B trasmette ad A
* la stazione C sente che sta trasmettendo
* la stazione C non trasmette a D perchè pensa potrebbe interferire con B (eccesso di cautela)

**MACA (Multiple Access Collision Avoidèance)**

risolve i porblemi di stazione nascosta/esposta, è un protocollo che aggiunge 2 comandi alle stazioni wireless per scambiarsi informazioni:
* RTS (Request to Send) --> chiede di comunicare
* CTS (Clear to Send) --> dà il via libera

**ethernet (IEEE 802.3)**

Xbase Y dove:
* X è la banda in Mbps
* base --> indica una connessione *baseband* (frequenza unica, quindi è un protocollo a contesa)
* Y --> tipo di cavo/lunghezza

prima dell'ethernet non c'erano molte reti locali, ethernet ha avuto successo grazie al numero di stazioni collegabili su un cavo (10baseT gestisce 1024 stazioni ogni 100m)

per codificare le frequenza non usa picchi alti e bassi (problema di sincronizzazione), ma la codifica di machester

contro:
* efficenza inveramente proporzionale a banda*lunghezza (+ banda o cavo rende la rete meno effiecente)

**binary exponential truncated backoff**

ethernet usa un CDMA non persistente con una modifica, se 2 acchetti collidono si aumenta esponenzialmente il tempo di attesa

es:
* mando 1 pacchetto
* collisione
* asepetto 1s --> 2s --> 4s ... max 1024

**frame ethernet**

un frame ethernet è composto da:
* preamble (8 byte) --> 101010...101010, per sincronizzazione ad alte velocità
* dest. address (6 byte) --> per indirizzi locali  e globali (MAC)
* source address (6 byte)
* type (2 byte) --> tipo di protocollo e come usare il frame
* data (0-1500 byte)
* pad (0-46 byte) --> assicura che la lunghezza del frame sia almeno il tempo di round trip
* checksum (4 byte) --> CRC-4

**MAC address**

è un protocollo di indirizzi a 48 bit, dove:
* 3 byte identificano il produttore (OUI)
* i restanti 3 byte identificano lo spazio di indirizzi

permette di identificare uiversalmente un dispositivo, permettendogli di passare da rete locale a rete locale
