
## linguaggi context-free (CFL)

**grammatica context-free**

una grammatica context-free è una notazione formale per la descrizione di linguaggi context-free

una CFG è una quadrupla G = (V, T, P, S), dove:
* V è un insieme di variabili non terminali che rappresentano linguaggi
* T è un insieme di simboli terminali che costituiscono la base del linguaggio da definire
* P è un insieme di regole di produzione nella forma A -> a, dove:
    * A è una variabile non terminale
    * a è una variabile non terminale, un simbolo terminale oppure epsilon
* S è la variabile simbolo iniziale che rappresenta il linguaggio da definire

**derivazione**

la generazione del linguaggio data una grammatica è chiamata derivazione

generazione del linguaggio:
1. scrivi variabile iniziale
2. trova una variabile scritta e una regola che inizia con quella variabile
3. sostituisci la variabile con il lato destro della regola
4. ripeti 2

**albero sintattico (parse tree)**

ogni derivazione definisce un albero sintattico, dove:
* la radice è la variabile iniziale
* i nodi sono non terminali
* le foglie sono terminali

**stringa ambigua**

una stringa è ambigua se esistono 2 o più alberi che la generano

**grammatica ambigua**

una grammatica è ambigua se genera stringhe ambigue

**conversione DFA in CFG**

algoritmo:
* una variabile per ogni stato in Q
* una regola per ogni transizione
* una regola che manda ad epsilo per lo stato finale
* q0 è il simbolo iniziale

**forma normale di chomsky**

una CFG è in forma normale di chomsky se ogni regola è nella forma:
* A -> BC
* A -> a

dove:
* a è un terminale
* B e C non sono variabili iniziali

algoritmo di trasformazione:
* si crea una nuova variabile iniziale
* si eliminano le epsilon regole
    * A -> epsilon
* si eliminano le regole unitarie
    * A -> B
* si trasformano le regole rimaste nella forma corretta

**automi a pila (PDA)**

è una sestupla nella forma 
* P = (Q, sigma, T , f, q0, F)

dove:
* Q --> insieme di stati
* sigma --> alfabeto
* T --> alfabeto della pila
* f --> funzione di transizione
    * input --> stato corrente, input e ultimo elemento dello stack
    * output --> stato destinazione e stack aggiornato
* q0 --> stato iniziale
* F --> insieme di stati finali

**rappresentazione PDA**

un DFA si può rappresentare con una tabella delle transizioni modificata:
* righe --> stati
* colonne --> alfabeto
* colonne interne --> alfabeto automa
* celle --> funzione di transizione applicata

**computazione PDA**

un PDA accetta una stringa w in 2 modi:
* accettazione per stato finale --> il PDA termina in uno stato finale in uno stato finale
* accettazione per pila vuota --> il PDA termina con pila vuota

per ogni pda che accttta per stato finale ne esiste uno equivalente che accetta per pila vuota, e viceversa

**funzionamento PDA**

1. Inserisci il simbolo marcatore $ e la variabile iniziale S sulla pila
2. Ripeti i seguenti passi:
    1. Se la cima della pila è la variabile A: scegli una regola A → u e scrivi u sulla pila
    2. Se la cima della pila è un terminale a: leggi il prossimo simbolo di input.
        * se sono uguali, procedi
        * se sono diversi, rifiuta
3. Se la cima della pila è $: vai nello stato accettante

**relazione CFL e PDA**

* un linguaggio è un CFL sse esiste un PDA che lo riconosce

**conversione da PDA a CFL**

sia P = (Q, sigma, T , f, q0, F), allora G = (V, T, P, S) è dato da:
* V = { A<sub>pq</sub> | p,q contenuti in Q}
* dati p,q,r,s in Q, u in T ed a,b in sigma, se f(p,a,epsilon) contiene (r,u) e f(s,b,u) contiene (q,epsilon), aggiungi la regola A<sub>pq</sub> -> aA<sub>rs</sub>b
* per ogni p,q,r in Q aggiungi la regola: A<sub>pq</sub> -> A<sub>pr</sub>A<sub>rq</sub>
* per ogni p in Q, aggiungi la regola: A<sub>pp</sub> -> epsilon

lemma1:
* se A<sub>pq</sub> genera X, allora la stringa X può portare p a q con vuota

lemma2:
* se la stringa X può portare p a q con pila vuota, allora A<sub>pq</sub> genera X

**pumping lemma (CFL)**

ipotesi
* L è un CFL
* k è un numero >= 0
* \|w\| >= k

tesi:
* w la si può spezzare in uvxyz
* \|vy\| > 0  è al massimo lungo quanto K
* \|vxy\| <= k
* u(v)\*x(y)\*z appartiene ad L

per dimostrare che un CFL falsifica il pumping lemma bisogna dimostrare che per ogni possibile suddivisione uvxyz, esite un esponente che genera una parola non appartenente ad L

**proprietà sugli alberi**

fissato b il massimo numero di simboli che compare in una regola di produzione è il numero massimo di figli che l'albero che la traduce può avere

ricorsivamente, se la regola richiama se stessa, l'albero può generare una stringa di lunghezza minore o uguale a b<sub>n</sub>

**DPDA (PDA deterministico)**

è una sestupla nella forma 
* P = (Q, sigma, T , f, q0, F)

dove:
* Q --> insieme di stati
* sigma --> alfabeto
* T --> alfabeto della pila
* f --> funzione di transizione
    * input --> stato corrente, input e ultimo elemento dello stack
    * output --> stato destinazione e stack aggiornato
* q0 --> stato iniziale
* F --> insieme di stati finali

per ogni q in Q, a in sigma ed x in T:
* f(q,a,x), f(q,a,epsilon), f(q,epsilon,x), f(q,epsilon,epsilon) sono tutti vuoti, tranne uno

**computazione PDA**

la computazione di un DPDA è unica e può terminare in 4 modi:
* consuma l'input e termina in uno stato finale --> accettazione
* consuma l'input e termina in uno stato non finale --> rifiuta
* hanging (si blocca senza consumare tutto l'input) --> rifiuta
* looping (entra in un loop infinito di epsilon-transizioni) --> rifiuta

il linguaggio generato è detto context-free deterministico (DCFL)

lemma1:
* per ogni DPDA esiste un altro DPDA che ne consuma sempre tutto l'input

lemma2:
* i DCFL sono chiusi rispetto al complemento

lemma3:
* esistono CFL che non sono DCFL
    * se il complementare del CFL non è un CFL non può essere un DCFL

lemma4:
* i DCFL non sono chiusi rispetto all'unione, intersezione, stella di kleene ed inversione

lemma5:
* L è un DFCL sse L con il simbolo di fine stringa è un DFCL