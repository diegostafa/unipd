## Teoria della comunicazione

**Bandwidth**

l'insieme delle frequenze che si possono trasmettere in un canale, si misura in Hz

più frequenze in una banda più informazione si riesce ad inviare

più alte sono le frequenze più alto è il costo e la potenza necessaria, ma si riescono a trasmettere più dati (la frequenza ha più picchi)

siccome quindi la parte importante è il limite di frequenza alta disponibile (quella bassa è garantita) i dispositivi non vengono specificati con banda 0-100Hz ma ci si concentra solo sulla frequenza più alta (es. wifi a 2.4GHz)

**Data rate**

quanta dati vengono trasmessi in un secondo, in base all'informazione
* bit --> quanti 0 e 1 vengono trasmessi in 1 secondo
* baud --> quanti simboli vengono trasmessi in un secondo

dato un insieme di N simboli, allora:
* bitrate = baudrate * log<sub>2</sub>(N)

**Forma del segnale**

il segnale in un canale viene trasmesso secondo la trasformata di fourier

**Trasformata di Fourier**

la trasformata di Fourier è una formula che consente di approssimare una curva digitale (0 e 1) con delle frequenze analogiche (Hz)

più frequenze si hanno migliore è l'approssimazione, ovviamente non basta avere il giusto numero di frequenze, ma anche le frequenze giuste

**Attenuazione del segnale**

ogni onda trasmesso in un mezzo che non sia il vuoto viene attenuata (si rimpicciolisce) dal mezzo e dipende dalla frequenza

l'attenuzione è data da:
* potenza trasmessa / potenza ricevuta

siccome le frequenze si attenuano in modo diverso, un onda iniziale può essere distrutta, più larga è la banda più irregolare è l'attenuazione

si risolve limitando la banda su frequenze che non sfasano di molto tra loro e utilizzando aggiustatori

**Dispersione del segnale**

la dispersione cambia la frequenza delle onde in altre frequenze

per risolvere ciò si aggiungono ripetitori e si riducono le distanze

**Teorema di Nyquist**

in un canale di comunicazione ideale, data la banda massima B e il numero F delle frequenze utilizzate della banda, il datarate massimo è dato da:
* datarate<sub>max</sub> = 2Blog<sub>2</sub>F

**Teorema di Shannon**

nei canali reali si aggiunge un'altra variabile N (noise) che definisce il rumore del canale che interferisce con il segnale

la qualità del segnale è definito dal rapporto tra potenza del segnale S e il rumore N:
* SNR = 10log<sub>10</sub>(S/N) --> decibel

il teorema di Shannon generalizza nyquist aggiungendo la qualità come fattore:
* datarate<sub>max</sub> = Blog<sub>2</sub>(1 + S/N)

nel caso in cui la qualità si altissima si può semplificare la formula come segue:
* datarate<sub>max</sub> = B/3 * SNR

**Solitoni**

sono delle onde speciali che non si disperdono e non vengnon affette da altre onde, sono perfette per le fibre ottiche

siccome non sono influenzate da altre onde si possono creare canali bidirezionali usando 2 onde solitoniche

**Trasmissione digitale**

3 modi per trasmette un bit:
* modulando ampliezza
    * altezza dell'onda
* modulando frequenza (FSK - Frequency Shift Keying)
    * numero di picchi 
* modulando fase (PSK - Phase Shift Keying)
    * posizione del pennino nel tempo

**QPSK (Quadrature Phase Shift Keying)**

è una modulazione di fase che utilizza 4 sfasamenti simmetrici, quindi ha un bitrate doppio
troppi sfasamenti rendono le fasi troppo simili

**QAM-16 (Quadrature Amplitude Modulation)**

si tiene la frequenza al massimo (aiuta sincronizzazione e generazione del segnale) e si usano ampiezza e fase insieme per massimizzare il numero di codifiche (baudrate) fino a 16 simboli, il bitrate è quadruplo

**QAM-64**

come il 16. ma si utilizzano più fasi e ampliezze, il bitrate è sestuplo

**QAM Circolari**

come sopra, ma i simboli sono disposti in modo circolare anzichè rettangolare, la spaziatura è ottimale e quindi le interferenze fisiche diventano meno rilevanti

i QAM rettangolari sono comunque più utilizzati perchè più veloci da generare e decodificare

**Constellation diagrams**

per rappresentare queste modulazioni si disegnano i punti (simboli su un piano) con un cerchio di riferimento

**FDM (Frequency Division Multiplexing)**

è una tecnica che divide le frequenze per creare più canali di trasmissione (es. 300-1000Hz è un canale, 1001-2000Hx è un altro canale...), per avere connessioni multipli sullo stesso cavo, ad ogni canale quindi corrisponde una porzione di banda

**WDM (wavelength Division Multiplexing)**

di base è la FDM ma fatta in fibra ottica

**TDM (Temporal Division Multiplexing)**

suddivide il tempo, di base ogni ad ogni canale si associa una frazione di seocondo riservata (es 24 canali si associano 1/24 secondi ad ognuno)

è meglio del FDM/WDM in quanto è molto più flessibile, quello sulle frequenze è limitato dal range di frequenze, quello temporale non ha limiti di suddivisione

lo svantaggio è che il datarate del singolo canale scende in proporzione al numero di canali in parallelo

**Delta modulation**

è una tecnica che consente di trasformare un segnale analogico in digitale

dato un offset costante delta e un quanto di tempo t, ad ogni quanto di tempo se la frequenza aumenta rispetto a prima si invia il valore 1, se diminuisce 0

il ricevente da questi dati, sapendo offset e quanto di tempo riesce a ricostruire una curva approssimata di qualità abbastanza buona

**CDMA**

funzionamento:
* si crea una base ortogonale di vettori, su dominio \[1,-1\]
* si ruota la base di 45°
    * ogni vettore della base risultante contiene quindi solo 1 o -1
    * ogni vettore della base rappresenta quindi un onda
* ad ogni cellulare è assegnato un vettore della base
* tutti i cellulari comunicano in un determinato istante
* invio dei dati:
    * bit 1 --> manda il suo vettore
    * bit 0 --> manda il suo vettore negativo
* il vettore viene tradotto in un onda digitale e approssimata con fourier
* onde contemporaneamente si sommano
* il gestore della cella riceve l'onda e determina:
    * chi ha inviato --> prodotto scalare != 0
    * cosa ha inviato
        * bit 1 --> prodotto scalare > 0
        * bit 0 --> prodotto scalare < 0
        * nulla --> prodotto scalare == 0

a causa dell'attenuazione delle onde la distanza di un cellulare dalla gestore influenzava la somma delle onde

per risolvere ciò si moltiplica l'onda di un cellulare per la sua distanza con il gestore

pro:
* comunicazione parallela
* si utilizza una sola porzione di banda
    * niente interferenze tra celle adiacenti
    * basta tenere conto dei cellulari adiacenti con gli stessi vettori, ma il costo è irrisorio
* siccome non ci sono frequenze riservate se qualcuno non comunica non spreca banda
