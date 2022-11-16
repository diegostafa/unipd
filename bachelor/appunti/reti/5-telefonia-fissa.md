## Telefonia Fissa

**backbone transatlantica**

* costruita per la prima volta da cyrus fields l'occhiopazzo
* attualmente utilizza un cavo in fibra ottica TAT-8
* la topologia è SHR (self healing ring)

**PSTN (public switched telephone network)**

è l'infrastruttura telefonica americana, onguno è collegato con un cavo in rame ad un altro, nel tempo questa rete a stella diventava ingestibile quindi sono stati creati dei livelli

ogni utente è collegato ad un centralino e questi centralini si collegano tra loro e gestiscono la comunicazione, quando ci sono troppi centralini si aggiunge un nuovo livello

**Local Loop**

è la porzione finale di rete che connete un utente al centralino, detta anche ultimo miglio

**Legge sul liberismo**

nel 1984 il monopolio AT&T viene spezzato in 23 compagnie diverse che si fanno concorrenza per incentivare l'innovazione

**Switching**

è l'azione di dirigere il traffico, esistono 3 tecniche:
* circuit switching
* message switching
* packet switching

**Circuit switching**

è la prima tecnica di switching utilizzata, i centralinisti collegavano fisicamente i 2 cavi che dovevano comunicare, quindi si crea fisicamente un circuito tra 2 persone

pro:
* connessine dedicata fisica

contro:
* delay dovuto alla creazione della connessine

**Message switching**

è detto anche store and forward

invece di creare il cammino fisico e poi iniziare la trasmissione, si manda direttamente il messaggio, e questo resta in attesa ad ogni centralino fino a che non viene definita la sua prossima destinazione

pro:
* tempo di creazione del canale

contro:
* intoppa il centralino se il messaggio è troppo grande

**Packet switching**

come il message switching ma viene spezzato alla fonte in pacchetti di lunghezza massima per evitare l'intoppo

inoltre ogni pacchetto è poi mandato indipendentemente in un microcanale in parallelo

**Trasmissione telefonica**

la trasmissione telefonica viaggia su una banda di 4000Hz in quanto frequenze maggiori sono dannose per l'apparato uditivo, utilizzando questa banda ha un limite fisico di 35000bps con cavi UTP3

gli standards telefonici di trasmissione sono:
* simmetrici:
    * V.21 (1964) --> FSK a 300bps 
    * V.22 (1980) --> PSK a 1200bps
    * v.22bis (1984) --> QAM-16 a 2400bps
    * v.32 (1984) --> QAM-32 a 9600bps con error correction
    * v.32bis (1991) --> 14400bps
    * v.34 (1994) --> 28800bps
    * v.34bis (1996) --> 33600bps
* asimmetrici:
    * v.90 (1998) --> 56000bps down, 33600bps up
    * v.92 (1999) --> 56000bps down, 48000bps up

per risolvere il limite fisico si pone un intermediario (gestore telefonico) tra i 2 chiamanti così si utilizzano entrambi i cavi duplex per inviare, raddoppiando il bitrate e arrivando ad un bitrate massimo di 70000bps

**Modem 56k**

i modem 56Kbps non possono andare a 64Kbps perchè utilizzano una codifica ASCII (7 bit) per la trasmissione dei dati, quindi utilizza 7/8 simboli disponibili per ogni impulso

**Fax**

è un telegrafo che trasmette immagini, ci sono diversi tipi di fax:
* gruppo 1 --> obsoleto
* gruppo 2 --> obsoleto
* gruppo 3 --> 10~ secondi per la trasmissione
* super gruppo 3 --> più veloce del 3
* gruppo 4 --> utilizza le linee digitali

standard di trasmissione dei fax:
* limitati ai fax
    * v.27 (1988) --> PSK
    * v.29 (1988) --> QAM
    * v.17 (1991) --> TCM
* unione telefonica
    * v.34
    * v.34bis

**DSL (Digital Subscriber Line)**

per ovviare al limite della trasmissione telefonica le dsl rimuovono il filtro di banda imposto sulle linee telefoniche (4000Hz) passando a 1.1MHz, per rimuovere i danni per frequenze troppo alte durente le telefonate si introduce quindi lo splitter, un dispositivo che separa il segnale telefonico da quello extra (internet)

ls DSL non vanno mai alla velocità dichiarata in quanto nell'ultimo miglio il segnale degrada prima di arrivare a destinazione a causa dell'UTP

**ADSL (Asymmetric DSL)**

è la DSL ma asimmetrica, utilizza gli standard V.90, V.92

di base l'assimmetria è data da come l'FDM suddivide la banda, riserva una porzione più grande di banda per il download

suddivisione adsl:
* 0-4KHz --> banda telefonica
* 25KHz - 138KHz --> banda upstream
* 138KHz - 1104KHz --> banda downstream

siccome l'ADSL utilizza l'FDM, queste porzioni sono a loro volta suddivise in microbande, onguna di queste forma un canale indipendente trattato come connessione a se stante, quindi è come se ci fossero tanti modem singoli per il download, tanti altri modem singoli per l'upload e uno per la linea telefonica

il gap tra la banda telefonica e l'upstream è stato messo per evitare per problemi di trasmissione delle frequenze molto alte possano arrivare alla linea telefonica

standard adsl:
* ADSL lite --> 1.5 down, 0.5 up
* ADSL --> 8 down, 1 up
* ADSL2 --> 12 down, 1 up
* ADSL2+ --> 24 down, 1 up
* ADSL2 annex J --> 12 down, 3.5 up
* ADSL2 annex M --> 28 down, 3.5 up

bitrate in Mbps

le ADSL+ usano una banda doppia, 2.2MHz invece che 1.1 MHz, frequenze molto alte viagginao male sull'UTP quindi la linea deve essere buona

le varianti ADSL 2+ e All-Digital rimuovono la banda telefonica e il gap per dedicarsi solo all'up e down

**VDSL (Video DSL)**

di base è come l'ADSL, ma l'ultimo miglio è in cavo coassiale

standard vdsl:
* VDSK (2001) --> 55 down, 3 up
* VDSL2 (2006) --> 200 down, 100 up
* VDSL2 (2011) --> 300 down, 100 up

**FTTH (Fiber To The Home)**

di base si cambia l'ultimo miglio in UTP con la fibra ottica che arriva direttamente dentro casa e serve un modem con entrate ottica,
il datarate aumenta in quando la banda che passa in fibra senza degradarsi è molto alta

per la suddivione della banda si è deciso di creare più versioni diverse

evoluzione fibra
* 1990 --> 8 canali da 2.5Gbps per capello
* 1998 --> 40 canali da 2.5Gbps per capello
* 2001 --> 96 canali da 10Gbps per capello
* 2007 --> 124 canali da 50Gbps per capello

**FTTB (Fiber To The Basement)**

la fibra arriva appena fuori casa e lo si collega dentro ad un UTP