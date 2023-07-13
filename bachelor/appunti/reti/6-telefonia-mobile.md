## Telefonia Mobile

**Telefonia USA**

negli USA ha vinto la telefonia fissa in quanto:
* molti standard mobili diversi
* non c'è distinzione tra numero fisso e mobile
    * chi riceve la chiamata paga la telefonata in quanto è a conoscenza del tipo di telefono chiamante e decide se accettare la chiamata
* tariffe fisse molto basse per i motivi sopra

**Telefonia EU**

in EU ha vinto la telefonia mobile in quanto:
* unico standard
* distinzione tra numero fisso e mobile
* monopolisti della telefonia fissa (prezzi alti)

**Telefonia mobile**

si basa sulla divesione del territorio, il gestore mette a disposizione l'infrastruttura sul paese che permette le comunicazioni wireless

standard telefonici:
* analogici
    * 0G (1950)
        * 0g IMTS
    * 1G (1982)
        * AMPS
        * TACS
* digitali
    * 2G
        * D-AMPS
        * GSM
        * CDMA
        * GPRS
        * EDGE
    * 3G
        * W-CDMA (aka umts)
        * CDMA2000
        * HSDPA
        * HSUPA
        * HSPA+
    * 4G
        * HSOPA (aka lte)
    * 5G

**Multiplexing telefonico**

quando più persone si collegano ad un centralino le loro connessioni vengono multiplexate in un unico cavo, 
questi gruppi sono al max 12 per il primo livello, 12\*5 nel secondo livello, 12\*5\*10 nel terzo livello

**Cambio di cella**

quando il segnale che la stazione base riceve è basso, si fa un sondaggio tra le celle adiacenti, la cella che riceve di più viene assegnata al cellulare, cambiando quindi cella con l'handoff

**Hard handoff**

la cella molla il cellulare e l'altra cella lo riprende, c'è un gap temporale tra le 2 azioni

**Soft handoff**

è stato introdotto nel 3g, la nuova cella prende il cellulare prima che la vecchia lo lasci

pro:
* no gap temporale

contro:
* il cellulare deve sapersi collegare a 2 frequenze contemporaneamente

**Griglie di celle**

le grigle non utilizzano i quadrati, ma gli esagoni, in quanto aiutano nei problemi di eccessivo cambio di cella

le microcelle sono celle più piccole inserite in una cella con problemi di overload

ogni cella ha al centro la stazione base ed un cellulare è sempre connesso ad una cella


**0G**

di base è il walkie-talkie, utilizza le onde radio, ha un solo canale per ricevere e trasmettere (half duplex) ed è push to talk

le conversazioni passano in chiaro

**IMTS**

passa a 2 frequenze, aumenta la privacy,
il gestore crea delle celle larghe centinaia di km, di 23 canali nella banda 150-450MHz

**1G**

introdotto dai laboratori Bells

standards:
* AMPS (USA)
* tacs (Italia)

diminuisce il diametro delle celle a 10-20km

pro:
* più connessioni simultanee
* meno potenza richiesta

contro:
* interferenza tra celle adiacenti
    * risolto dal teorema dei 4 colori

utilizza l'fdm, utilizzando nominalmente 832 canali full duplex (coppia di simplex), ma nella realtà ogni cella ha solo 45 canali effettivi a causa della suddivisione delle frequenze per le interferenze

funzionamente attivo:
* ogni cellulare ha un numero seriale a 32bit 
* ogni cellulare ha un numero telefonico a 10 cifre (34bit)
* ogni 15min ogni cellulare manda in broadcast i suoi 32+34bit per registrarsi alla cella
* quando si chiama si crea un canale condiviso per attivare la richiesta

funzionamento passivo:
* c'è un canale condiviso che i cellulari controllano se ci sono chiamate per loro
* se ce n'è una si crea un canale esclusivo per la chiamata

**2G D-AMPS**

DAMPS (Digital AMPS) è l'1g ma digitale, viene aumentata la banda fino a 1990MHz, è lo standard americano

utlizza la tecnica di compressione del delta modulation per fare una lossy compression della voce e trasformare l'onda analogica in una sequenza digitale

utilizza il TDM per il multiplexing

MAHO (Mobile Assistent HandOff):
* il cellulare diventa una componente attiva
* monitorare la potenza della cella
* se il segnale è basso notifica la cella e questa può disconnetterlo
* se è disconnesso il cellulare cerca attivamente un'altra cella
* si sfruttano i tempi morti del tdm per non consumare troppo

pro:
* retrocompatibile
* più banda
* antenne più piccole
 
contro:
* qualità del suono peggiorata

**2g GSM**

è lo standard 2G europeo, non è retrocompatibile e i canali sono di 200KHz, utilizza il TDM

ci sono 4 tipi di celle per grandezza:
* macro --> max 35km
* micro --> edifici
* pico --> case
* umbrella --> celle piccole e portatili

pro:
* più banda
* più utenti per cella (8)

contro:
* non è retrocompatibile


**SIM (Subscriber Identity Module)**

introdotta dal 2G GSM, serve a gestire l'identità digitale telefonica (l'identità digitale era il telefono stesso)

la SIM contiene 2 codici:
+ IMSI --> identificativo sim internazionale
* KI --> chiave di autenticazione

collegamento criptato gsm:
* il cellulare manda l'imsi in chiaro
* l'operatore manda un numero casuale al cellulare
* il cellulare cripta il numero casuale con il ki
* l'operatore (che ovviamente ha il ki) controlla che il numero criptato corrisponda

**2G CDMA (Code Division Multiple Access)**

è un altro standard statuinitense 2g che usa il cdma invece che il FDM/TDM, non ha preso piede in quanto il 2G era ormai consolidato

**2.5 GPRS (General Packet Radio Service)**

è un overlay del 2G che introduce il packet switching, si spezza la banda in microcanali per i pacchetti e nasce la tariffazione a traffico

utilizzando il packet switching supporta i classici protocolli internet IP e PPP

tipi di cellulari:
* classe C --> l'utente deve selezionare manualmente gsm o gprs
* class B --> la selezione diventa automatica
* pseudo classe A --> uso contemporaneo su una frequenza con il DTM (dual transfer mode)
* classe A --> uso contemporaneo su 2 frequenze

**2.75G EDGE/EGPRS (Enhanced Data Rates for Gsm Evolution)**

oltre alla all'FDM usa anche il TDM, aumenta il data rate nominale fino a 236kbps (edge evolution)

**3G**

standards:
* W-CDMA (wide CDMA) --> EU
* CDMA2000 --> USA

il W-CDMA usa una banda larga per canale di 5MHz con un data rate tipico di 380kbps

il CDMA2000 usa una banda più piccola di 1.25MHz con data rate tipico di 144kbps

**3.5G HSDPA (High Speed Downlink Packet Access)**

è l'evoluzione dell'utms, usa CDMA e QAM, utilizza la suddivisione assimetrica che privilegia il down stream

ha diverse varianti che vanno da 1.8 a 14.4Mbps in down e da 384Kbps a 2Mbps in up

**3.75G HSUPA (High Speed Pplink Packet Pccess)**

come l'HSDPA, ma assimetrico sull'upstream

**HSPA+**

è l'hsdpa ma con più banda e datarate

**4G HSOPA (High Speed OFDM Packet)**

anche detto 4G LTE, per la prima volta utilizza delle bande variabili da 1.25MHz a 20MHz il datarate arriva 1.2Gbps in down e 600Mbps in up

la banda è sotto i 6GHz

utilizza tutte le frequenze fino al digitale terrestre

ha varie versioni:
* CAT3 --> 100Mb down, 50Mb up
* CAT4 --> 150Mb down, 50Mb up
* CAT5 --> 300Mb down, 75Mb up
* CAT6 --> 300Mb down, 50Mb up
* CAT7 --> 300Mb down, 100Mb up
* CAT8 --> 3000Mb down, 1500Mb up --> per i vip
* CAT9 --> 450Mb down, 50Mb up
* CAT10 --> 450Mb down, 100Mb up
* CAT11 --> 600Mb down, 50Mb up
* CAT12 --> 600Mb down, 100Mb up
* CAT13 --> 400Mb down, 150Mb up
* CAT14 --> 400Mb down, 100Mb up
* CAT15 --> 4000Mb down, 1500Mb up --> per i vip

problemi ancora da risolvere:
* efficenza energetica
* data rate variabile
* connessione multiple a minor velocità

**5G**

nel 2017 si introduce il chip 5G qualcomm x50 che utilizza per la prima volta le frequenza del 4g più la banda tra 28-29GHz (scelta controversa)

nel 2019 arriva il chip 5G qualcomm x55, con antenna MIMO (Multiple Input Multiple Output) e QAM 1024, retrocompatibile con il 4G

nel 2020 qualcomm x60 che utilizza in parallelo la banda del 4G e del 5G, antenne più piccole ma sparse per il telefono

**LTE unlicensed spectrum**

si prende la banda di altre tecnologi come il bluetooth/wifi

**LAA**

si prende la parti libere di altre bande