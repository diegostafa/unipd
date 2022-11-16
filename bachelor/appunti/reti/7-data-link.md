## Data Link

è la prima astrazione di rete, di base si occupa di:
* codifica e decodifica di frequenze in simboli --> framing
* gestione degli errori di trasmissioe --> error control
* regolazione del flusso dati --> flow control

il datalink può configurare il canale secondo 2 parametri:
* acknowledgment
* connection

**Acknowledgment**

si sceglie se aspettare o meno un segnale di avvenuta ricezione dei paccheti

**Connection**

si sceglie se creare o meno una connessione dedicata

### Framing

definisce la creazione de frame da inviare nel canale, quindi di base consiste nel creare una sequenza di bit

solitamente è così formato:
* header
* payload
* trailer

ogni frame deve essere ben distinguibile, per capire quando inizia e finisce un frame ci sono diversi modi:
* slot temporali
    * non applicabile
* numero di caratteri del payload nell'header
    * errori nell'header rovinano tutto
* flag bytes
    * analogo delle "" in una stringa

**Flag bytes**

si prefissa e postfissa una speciale sequenza di bit (flag) per indicare dove inzia e termina un frame di dati

**Byte stuffing**

se il payload contiene una sequenza di bit uguale al flag allora si prefissa al flag interno un byte detto di stuffing che serve a fare l'escaping del flag

pro:
* semplice

contro:
* spreca molta banda se bisogna fare l'escaping molte volte

**Bit stuffing**

è come il byte stuffing, ma non si prefissa un byte, ma si aggiunge un bit ogni qual volta incontra un particolare pattern, il ricevente conoscendo i pattern sa rimuovere il bit

pro:
* utilizza un solo bit

contro:
* il pattern può ripetersi più volte

### Error Control

utile quando il canale ha pochi errori non critici, in queste condizioni si riesce anche a fare l'error correction

le tecniche di error control si dicono più o meno potenti in base alla distanza di hamming che supportano

**Distanza di Hamming**

è una misura he indica quanti bit diversi hanno 2 messaggi della stessa lunghezza

**Grafo di Hamming**

funzionamento:
* si fissa M
* si disegna un grafo
* ogni nodo è una porzione di bit lunga M
* ogni nodo adiacente differisce di un unico bit

analisi di una tecnica di error control:
* si disegna il grafo di hamming
* si colorano di verde i nodi che rispettano la tecnica
* si colorano di rosso i nodi che non la rispettano

potenza di una tecnica:
+ distanza minima tra 2 nodi verdi

correzione dell'errore:
* un nodo rosso si può correggere al più vicino nodo verde

**Parity bit M**

è una tecnica che consente di rilevare errori di trasmissione, rileva delle distanze di hamming massime di 1 bit (potenza)

funzionamento:
* divide il payload in porzioni di M bit
* somma i bit delle porzioni
    * se pari aggiunge 0 alla fine della porzione
    * se dispari aggiunge 1 alla fine della porzione

il suo error rate è di:
* Err = 1 / (M + 1)

M = 1 è il caso ottimale, con un error rate del 50%

il data rate è:
* data rate = M / (M + 1)
 
pro:
* semplice

contro:
* per ogni M scelto ha sempre potenza 1
* non ha error correction

**Repetition codes**

è una tecnica di error control che ripete ogni bit del payload N volte

esempio N = 3:
* 1011 --> 111000111111

nella scacchiera di hamming, siccome ripete sempre lo stesso bit, diventa un nodo rosso se ci sono bit diversi ed è un nodo verde se tutti i bit sono uguali, quindiha potenza N-1

se i bit flippati sono meno della metà si riesce anche a correggere l'errore

pro:
* potenza N-1
* error correction

contro:
* data rate = 1 / N

**Codice di Luhn**

è l'analogo del parity bit, ma in base 10, ha potenza 1, ma rileva anche cifre invertite (tranne 09 - 90)

funzionamento:
* si raddoppiano le cifre in posizione dispari
* si fa la somma S tutte le cifre
* il codice di Luhn è quanto manca per arrivare al multiplo di 10
* si aggiunge il codice alla fine del dato

questo codice viene utilizzato nelle carte di credito*

**Codici lineari**

sono tecniche di error control che utilizzano solo operazioni lineari, il parity bit fa parte di questa famiglia

**Codice di Hamming (X, Y)**

questa tecnica crea un codice lungo X da dei dati lunghi Y:
* X --> output dati
* Y --> input dati

funzionamento:
* si crea una matrice I<sub>Y,Y</sub>
* si crea una matrice A<sub>Y,X-Y</sub>
* si affiancano le matrici
* codice = matrice x vettore dati

distanza minima:
* si le righe della matrice
* la distanza minima è il valore più basso

migliore del repetition codes per quanto riguarda il data rate

**Hamming ibrido**

come l'hamming precedente, ma la matrice ha un'ulteriore colonna finale di tutti 1

**Parity bit versione Hamming**

essendo un codice lineare si può creare una matrice generatrice che rappresenta il parity bit

versione M=3:
```
{ 1 0 0 | 1
  0 1 0 | 1
  0 0 1 | 1 }
```
quindi è un codice (4,3,2), potenza 1

**Repetition codes versione Hamming**

matrice generatrice:
```
{ 1 1 ... 1 }
```
quindi è un codice (N,1,N), potenza N-1

**Burst error**

è il tipo di errore più comune, in uno stream di dati gli errori si concentrano in una piccola porzione di dati

per risolvere questo errore si usa l'interleaving

**Interleaving**

ogni pacchetto di bit non viene inviata sequenzialmente, ma si forma una matrice dei pacchetti e si inviano le colonne

ciò consente di spalmare la potenza di un errore su più pacchetti

**RAM**

è sufficente una potenza di 1

**ECC RAM (error correction code)**

utilizzano hamming(72,64)

**SECDED (single error correction, double error correction)**

è uno standard che le schede madri devono implementare per utilizzare le ECC RAM

**RAID**

* raid 0 --> nessuna protezione
* raid 1 --> repetition 2
* raid 2 --> hamming
* raid 3 --> parity
* raid 4 --> parity distribuito

**Erasures**

è un tipo di errore che elimina porzioni di dati (es. cd graffiato)

è meno grave di un flip in quanto si sa dove è avvenuto l'errore

**Codice Reed-Salomon RS(X,Y)**

è un codice lineare basato sull'aritmetica polinomiale, l'idea di base consiste creare dei bit extra con il resto di una divisione polinomiale, può correggere contemporaneamente:
* (X-Y)/2 errori flip
* X-Y erasures

si usa nei:
* dvd
* sonde spaziali
* blu ray
* WiMax
* tv digitale

**Codice di Hadamard**

è utilizzato nel CDMA, tratta le interferenze come vere e proprie comunicazioni

**Teorema di Shannon**

dato un certo tasso di errore X, esistono dei codici che possono arrivare ad un data rate massimo pari all'entropia del canale di comunicazione

il teorema quindi dichiara l'esistenza di questi codici, ma non li specifica

pro:
* data rate e protezione alta

contro:
* in media le risorse utilizzate per la decodifica sono alte

**CRC (Cycle Redundancy Check)**

è un codice Reed-Salomon, basato sull'aritmetica polinomiale in base 2

encoding:
* si considera un pacchetto come un polinomio P(x)
    * i bit sono i coefficenti
    * la posizione è il grado dell'incognita
    * la somma è una XOR
    * la differenza è uguale alla somma
* si sceglie un polinomio generatore G(x)
* P(x) = P(x) * x<sup>grado di G(x)</sup>
    * assicura che T(x) abbia grado maggiore di G(x)
* r(x) = P(x) % G(x)
* T(x) = P(x) + r(x)
* si trasmette T(x)

decoding:
* T(x) è il pacchetto che arriva
* T(x) % G(x)
    * se == 0 --> non c'è errore
    * se != 0 --> c'è errore
    * nb: affinchè non ci sia un errore il resto deve fare 0 in quanto T(x) + r(x) è divisibile per G(x)

analisi dell'errore:
* si definisce un errore di trasmissione come un polinomio E(x)
* il polinomio trasmesso + quindi T(x) + E(x)
* il check da fare è (T(x) + E(x)) % G(x) == 0
* per definizione T(x) % G(x) == 0
* E(x) % G(x)
    * se == 0 --> non ci accorgiamo dell'errore
    * se == 1 --> ci accorgiamo dell'errore
* bisogna quindi scegliere G(x) in modo tale che E(x) % G(x) == 1, cioè trovare G(x) che non sia fattore di E(x)
* E(x) ha una determinata forma in base al tipo di errore:
    * potenza 1:
        * E(x) = x<sup>i</sup>
        * G(x) = basta che abbia 2 termini
    * potenza 2:
        * E(x) = x<sup>i</sup> + x<sup>j</sup>
        * G(x) = basta che non sia potenza di X e che non divida x<sup>k+1</sup> con k in \[i,j\]
    * potenza dispari:
        * E(x) = x<sup>n</sup> + ... x<sup>i</sup> (dispari volte)
        * G(x) = (x+1)
            * spiegazione: G(x) non può essere un fattore di E(x) quando ha (x+1), basta sostituire 1 per verificare
    * burst error:
        * E(x) = x<sup>i</sup>(x<sup>j</sup> + ... + 1)
            * flippa i bit da una certa posizione in poi
        * G(x) = x<sup>K</sup> + 1 con k > j
            * aumentare il grado di G aumenta esponenzialmente la protezione ai burst

tipi di polinomi generatori:
* CRC-1 --> x+1
* CRC-5 --> x<sup>5</sup> + x<sup>2</sup> + 1
* CRC-16 --> x<sup>16</sup> + x<sup>15</suè> + x<sup>2</sup> + 1
    * si usa nell'USB
* CRC-16CCITT --> x<sup>16</sup> + x<sup>12</suè> + x<sup>2</sup> + 1
    * si usa nel bluetooth
* CRC-32 --> --> x<sup>32</sup> ...
    * si usa in:
        * modem
        * zip
        * fibra
        * cd-rom
        * ethernet
        * png

**QR codes**

è un GF(255) con quattro livelli di error correction:
* low --> 7%
* medium --> 15%
* quartile --> 25%
* high --> 30%

si può fare pixel art nei QR codes perchà i qr codes sanno auto risolversi gli errori

### Flow Control

si occupa della gestione del flusso dei dati (congestione, arrivo dei dati...)

definizioni:
* RTP (Round Trip Delay) --> è il tempo che un messaggio impiega per andare e tornare

#### Protocolli di trasmissione

**stop-and-wait**

è un protocollo di trasmissione sequenziale, il mittente aspetta sempre un ack di conferma prima di inviare il pacchetto successivo

data la capacità C del canale, la grandezza S del frame ed il round trip delay R, allora l'utilizzo della linea è:
* S / (S + C*R)
    * se S < C*R allora abbiamo un efficenza minore del 50%

pro:
* basta un canale half-duplex

contro:
* lento --> no parallelismo
* attesa infinita del mittente --> pacchetto sparisce, ack non viene mai inviato

**PAR (Positive Acknowledgment with Retransmission)**

è un protocollo stop and wait che aggiunge:
* timer di ritrasmissione nel mittente --> risolve attesa infinita del mittente
* numerazione dei pacchetti --> risolve pacchetti duplicati da ritrasmissione
    * es. trasmettere diego --> qualche ack non arriva --> ddiegggo (pacchetti duplicati nel ricevente)

la numerazione può avvenire in 2 modi:
* completa --> si numerano tutti i pacchetti, ma si perde di banda
* posizionale --> si distinguono pacchetti pari e dispari

**stop and wait full duplex**

stop-and-wait può essere usatio in full duplex, utilizzando il protocollo su 2 canali simplex

i questo caso il destinatario non invia l'ACK subito, ma lo invia quando ha un frame da inviare (piggybacking), funziona bene quando c'è equilibrio di comunicazione, altrimenti il timer del mittente può scadere e continuare a inviare lo stesso frame

**Sliding windows**

invece di aspettare un ACK per ogni pacchetto si inviano 2<sup>n</sup> pacchetti e si aspetta

funzionamento:
* il mittente ed il ricevente implementano una finestra di trasmissione
* ogni finestra ha:
    * una taglia massima (numero di finestre)
    * una taglia attuale (finestre aperte)
* il ricevente lascia sempre una finestra aperta
* il mittente la apre quando deve inviare un pacchetto
* quando il mittente invia lascia aperta la finestra per l'ACK
* quando riceve l'ACK chiude la finestra e apre la successiva
* il destinatario dopo aver ricevuto il pacchetto, chiude la finestra e apre la successiva

caratteristiche:
* la taglia attuale può essere al massimo metà della taglia massima
* il ricevente ha un timer di ack, dopo la quale invia l'ack senza piggybacking (il timer del ricevente deve essere minore del mittente)

pro:
* parallelismo di trasmissione

contro:
* risorse utilizzate

**Go Back N**

è un protcollo sliding windows dove il mittente ha n finestre aperte ed il ricevente ne ha 1 aperta, si chiama go back n perchè in caso di errori di trasmissione si devono ritrasmettere n pacchetti

viene usato per avere sequenzialità obbligatoria di pacchetti, ma parallelismo di trasmissione

pro:
* funziona bene quando il canale ha pochi errori e il round trip delay è alto

contro:
* il mittente deve avere N timer
* il mittente deve avere un buffer largo N per la ritrasmissione

**Selective repeat**

sia il mittente che il ricevente hanno N finestre aperte

contro:
* anche il ricevente necessita di un buffer largo N


**NAK (Not ACK)**

è il contrario dell'ack, invia un messaggio che indica errori di transmissione, il mittente reinvierà il pacchetto

il nak può essere attivato in diversi modi:
* quando un pacchetto arriva nella finestra sbagliata della sliding window
* i pacchetti non arrivano in ordine

di base:
* prima --> il mittente invia i pacchetti e se non riceve l'ACK allo scadere del timer, li reinvia
* dopo --> il mittente invia i pacchetti e se solo se riceve il NACK li reinvia

il nack viene inviato subito, senza piggybacking