## Introduzione

concetti base:
* problema = linguagio
* algoritmo = automata
* alfabeto --> insieme di simboli
* stringa o parola --> sequenza finita di simboli
    * stringa vuota --> epsilon
    * lunghezza stringa --> \|s\|
* linguaggio --> sottoinsieme di tutte possibili parole di un alfabeto
* linguaggio regolare --> linguaggio generato da un'automa, si indica con L(A)
* computazione --> esecuzione dell'automa su una parola

## Linguaggi regolari

i linguaggi regolari sono degli insiemi di stringhe, possono essere rappresentati da:
* automi a stati finiti
* espressioni

operazioni chiuse sui linguaggi regolari:
* insiemistiche
    * complemento
    * unione
    * intersezione
    * differenza
* speciali
    * stella di kleene --> è l'asterisco delle regular expression, indicano 0 o più occorrenze del simbolo precedente
        * applicato ad un linguaggio L, L* indica l'insieme infinito di stringhe formato da concatenazioni delle stringhe di L 0 o più volte
    * concatenazione

livelli di precedenza
0. parentesi
1. stella di kleene
2. concatenazione
3. il resto

esempio:
* 01* + 1 --> (0(1*)) + 1

**automi**

tipi di automi:
* memoria finita
    * automi a stati finiti --> compilatori/protocolli di comunicazione...
* memoria infinita
    * ad accesso limitato
    * ad accesso illimitato

**DFA (automa a stati finiti deterministico)**

è una quintupla nella forma 
* A = (Q, sigma, f, q0, F)

dove:
* A --> automa
* sigma --> alfabeto dell'automa
* f --> funzione di transizione
    * input --> simbolo alfabeto
    * output --> stato
* q0 --> stato iniziale
* F --> insieme di stati finali

**rappresentazione DFA**

un DFA si può rappresentare con:
* grafo
    * nodi --> stati dell'automa
    * archi direzionali --> funzione di transizione applicata sul nodo con un simbolo
* tabella di transizione
    * righe --> stati
    * colonne --> simboli
    * celle --> risultato della funzione di transizione

**accettazione DFA**

un DFA accetta una parola w se la sua computazione termina in uno stato finale

un DFA accetta un linguaggio se ogni parola del linguaggio è accettata

**NFA (automa a stati finiti NON deterministico)**

è una quintupla nella forma 
* A = (Q, sigma, f, q0, F)

di base è un DFA in cui cambia la funzione di transizione:
* f --> funzione di transizione
    * input --> parola
    * output --> sottoinsieme Q di stati

**rappresentazione NFA**

un NFA si può rappresentare con:
* grafo di transizione
* tabella di transizione
    * celle --> che ora rappresentano sottoninsieme di stati (anche di un solo elemento)
* albero n-ario
    * radice --> stato iniziale
    * rami --> possibili stati per un input

**computazione NFA**

di base un NFA accetta una parola se esiste almeno una computazione di essa che termina in uno stato finale, la rifiuta altrimeni

**conversione tra NFA e DFA**

l'obiettivo è costruire un DFA D=(Q', sigma, f', q0, F') da un NFA N==(Q, sigma, f, q0, F), dove:
* D e N hanno lo stesso alfabeto (sigma)
* D e N hanno lo stesso stato iniziale q0

tale per cui:
* L(D) = L(N)

Q', f' ed F' si ottengono da N tramite l'algoritmo di costruzione per sottoinsiemi:
* Q' è l'insieme potenza di Q: se Q ha n stati Q' ne ha 2<sup>n</sup>
* F' è formato dall'insieme di stati di N che includono almeno uno stato accettante
* f'

algoritmo:
1. da q0 dell'NFA trova gli insiemi di stati raggiungibili con i possibili input

allora per convertirlo procedo come ho visto a lezione:
parto dagli stati dell'eclose di q0;

Eclose(q0)={q0,q1} che chiamo p1;

p1={q0,q1} con input A,B vado in {q1,q2} ora facciao l'Eclose di questi stati Eclose(q1,q2)={q1,q2,q3,q4}*, che è un nuovo stato che chiamo p2
da p1 con input 0..9 non vado in nessuono stato

p2={q1,q2,q3,q4}* con A,B vado in {q2} la cui funzione eclose genera {q2,q3,q4}* che chiamo p3
da p2 con 0..9 vado in {q3,q4} che ha eclose {q3,q4}* che chiamo p4

p3={q2,q3,q4}* con A,B è vuoto
con 0..9 vado in q4 la cui eclose è {q4}* che chiamo p5

p4={q3,q4}*
con 0..9 vado in q4 che ha per eclose q4 cioè lo stato p5
quindi ho:
p1 raggiungo p2 con etichetta A o B
p2 raggingo p3 con A o B, da p2 raggingo p4 con 0..9
p3 raggiungo con 0..9 p5
p4 raggiungo con 0..9 p5

**epsilon transizioni**

le epsilon transizioni consentono ad un automa di cambiare stato senza consumare lettere della parola

**epsilon-NFA**

di base è un NFA il cui alfabeto contiene il simbolo epsilon, l'epsilon è il simbolo vuoto, una epsilon transizione (transizione con input == epsilon) non consuma lettere della stringa

**epsilon chiusura**

di base lo si guarda come un grafo, l'epsilon chiusura di un nodo corrisponde all'insieme di nodi del grafo che arrivano al nodo scelto solo tramite epsilon transizioni

algoritmo
* si sceglie un nodo
* si aggiungono i nodi adiacenti che si collegano con epsilon chiusure
* si ripete per ogni nodo aggiunto

il risultato è l'insieme di nodi ricavati

**espressione regolare (regular expressione**

un espressione regolare è una funzione che prende in input una stringa e restituisce vero falso

di base un espressione regolare la si può vedere come un DFA accettatore che computa una stringa e ne verifica l'accettazione

costanti:
* epsilon
* insieme vuoto
* singolo simbolo

**conversione da DFA ad espressioni regolari**

per ogni automa si può costruire un espressione regolare equivalente

costruzione:
* i nodi intermediari si sostituiscono con la concatenazione
* i nodi rientranti si sostituiscono con la stella di kleene

**conversione da espressioni regolari a epsilon-NFA**

per ogni espressione regolare si può costruire un epsilon-NFA tale per cui l'NFA ha:
* un solo stato finale
* nessuna transizione entrante dallo stato inziale
* nessuna transizione uscente dallo stato finale

la costruzione è data dalla composizione delle operazioni elementari di unione, concatenazione e star di kleene

**linguaggi NON regolari**

sono tutti i linguaggi che non soddisfano il pumping lemma

**pumping lemma (linguaggi regolari)**

ipotesi
* L è un linguaggio regolare
* K è un numero maggiore di 0
* w è una parola più lunga di K

tesi:
* w la si può spezzare in xyz
* xy è al massimo lungo quanto K
* (xy)*z appartiene sempre ad L