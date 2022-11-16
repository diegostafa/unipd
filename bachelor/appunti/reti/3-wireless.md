## Trasmissione wireless

la trasmissione wireless avviene sfruttando lo spettro elettromagnetico

le onde elettromagnetiche si distinguono per livello di frequenza:
* onde radio
    * onde radio a bassa frequenza
    * onde radio ad alta frequenza
* micro-onde
* infrarossi
* luce visiva

le onde radio sono quelle a minor frequenza, la frequenza fornisce proprietà delle proprietà fisiche all'onda:
* direzionalità
* interferabilità
* potenza
* costo di produzione

le onde a bassa frequenza guadagnano in omnidirezionalità e minor interferabilità, ma perdono di potenza e costo, quelle ad alta frequnza l'esatto contrario

per la comunicazione wireless si usano SOLO onde radio, in quanto frequenze maggiori sono dannose per l'uomo

**banda ISM**

le bande ISM sono lle porzioni di spettro elettromagnetico libere e considerate migliori, vengono lasciate libere per future tecnologie di successo

esempio di tecnologie nate sull'ISM
* bluetooth
* telefono senza fili
* forno a microonde
* telecomandi

**trasmissioni radio**

ce ne sono di 2 tipi:
* bassa frequenza
* alta frequenza

le trasmissioni radio a bassa frequenza sono omnidirezionali e riescono a passare ostacoli senza interferenza, ma sono poco potenti seguono la curvatura terrestre

le trasmissioni radio ad alta frequenza sono direzionali e non passano molto bene gli ostacoli, ma sono molto potenti, non segue la curvatura terrestre ma viene deviata dalla ionosfera


**satelliti di comunicazione**

in base alla posizione dei satelliti relativi alle 2 fasce di van allen in atmosfera se ne distinguono 3 tipi:
* geostazionari (GEO) --> sopra le 2 fasce
    * sono i più appetibili
    * limite max 180, sull'equatore
    * usati per:
        * tv (sky) --> segnali ad alta potenza
        * meteo
        * ambiti militari
* medio-ordbitali (MEO) --> tra le 2 fasce
    * usati per il gps
* basso-orbitali (LEO) --> sotto le 2 fasce
    * usati per la telecomunicazioni per la bassa latenza
    é 

pro e contro variano in base all'altezza, più in alto il satellite più aumentano:
* costi
* potenza
* copertura
* latenza

problemi:
* frammenti nell'atmosfera

**tempo di fix**

è il tempo necessario al satellite per eseguire la triangolazione per inviare la posizione del GPS

**Iridium**

è una rete di telecomunicazione di 66 satelliti LEO che garantisce copertura globale, ogni satellite copre 48 celle, è stato lanciato nel '98.
Le comunicazioni vengono gestite dai satelliti

per utilizzare iridium è necessario un telefono apposito

è utilizzato da:
* marina
* aviazione
* governi
* industrie petrolifere
* tsunami warning system

**Global Star**

come iridium, ma la comunicazione viene gestita a terra, i satelliti servono solo come ripetitori, inoltre non coprono tutto il globo, ma solo le parti imbortanti, non necessita di un telefono apposito

aziende utilizzano global star:
* alcatel
* vodafone
* hyundai

**Digitale terrestre**

il digitale terrestre usa il QAM(4, 16 o 64), inoltre comprime i dati in MPEG2

utilizza l'FDM, ogni canale è suddiviso in microcanali:
* 2k --> 1705 microcanali
* 8k --> 6817 microcanali

**DVB-T2**

è un nuovo standard per il digitale terrestre:
* occupa meno banda
* supporta l'8k
* utilizza la compressione H.265

la transzione avverà a giugno 2022

**Satellite**

per problemi di potenza e interferenza il satellite usa il QPSK e la parabola serve a convogliare e rinforzare i segnali deboli arrivati

**Trasmissione radio mono**

utilizza una banda di 30Hz - 15KHz

**Trasmissione radio stereo**

in una radio stereo devono essere trasmessi 2 canali, S e D

la trasmissione stereo è retrocompatibile alla mono:
* banda mono 30Hz - 15KHz
* banda stereo 23-53KHz

nella banda mono si trasmette la media di S e D:
* M = (S + D) / 2

nella banda stereo si trasmette la differenza media di S e D:
* E = (S - D) / 2

la banda stereo non viene utilizzata direttamente, ma si ricavano S e D attraverso il canale mono:
* S = M + E
* D = M - E

il segnale peggiora a causa delle interferenze di differenza e media di almeno un fattore 3, percià ascoltare in mono aumenta la qualità


**RDS (Radio Data System)**

è uno standard digitale che supporta un ulteriore canale informativo dei canali radio (artista, categoria...)

**Radio digitale**

standards:
* HD Radio (Hybrid Digital)--> USA
* DAB (Digital Audio Broadcasting) --> EU

è la radio digitale, non ha preso piede a causa dei:
* interferenze domestiche
* difficoltà nel cambiare antenna
* interferenza da effetto doppler
* qualità peggiorata a causa delle compressioni