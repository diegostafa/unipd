## Macchine di turing

è una automa ideale:
* ha memoria infinita, indicata da un nastro
* può leggere e scrivere nelle nel nastro
* può muoversi a sinistra e a destra del nastro
* gli stati di accettazione e ifiuto hanno effetto immediato

è una tupla del tipo:
* M = (Q, sigma, T, f, q0, q<sub>accept</sub>, q<sub>reject</sub>)

dove:
* Q --> insieme di stati
* sigma --> alfabeto di input, non contiene il simbolo blank
* T --> alfabeto del nastro, contiene sigma e blank
* f --> funzione di transizione
    * input --> (Q, T)
    * output --> (Q, T, (L, R))
* q0 --> stato iniziale
* q<sub>accept</sub> --> stato di accettazione
* q<sub>reject</sub> --> stato di rifiuto

**configurazione**

si dice configurazione di una TM la tripla C = (u,q,v), dove:
* u --> contenuto del nastro prima della testina
* q --> stato corrente
* v --> contenuto del nastro dalla testina in poi

proprietà:
* la configurazione iniziale su input w è sempre (/, q0, w)
* la configurazione di accettazione/rifiuto hanno come q i rispettivi stati
* una TM ha un infinito numero di configurazioni, un DFA ne ha tanti quanti i suoi stati

date 2 configurazioni C1 e C2 si dice che C1 produce C2 se C1 può passare a C2 in una mossa

esempio:
* stato corrente: q7
* nastro: 1011\[0\]1111
* configurazione: (1011, q7, 01111)

**accettazione della TM**

una TM accetta l'input se esiste una sequenze di configurazioni C1, C2 ... Ck, tale per cui:
* C1 è la configurazione iniziale
* ogni configurazione produce il suo successivo
* Ck è una configurazione di accettazione

**linguaggio turing-riconoscibile (o ricorsivamente enumerabile)**

è il linguaggio generato dalla TM,

**decisore**

è una TM che termina sempre la computazione e non va mai in loop

**linguaggio turing-decidibile (o ricorsivo)**

è il linguaggio generato da un decisore, quindi ogni linguaggio ricorsivo è anche ricorsivamente enumerabile

**varienti di TM**

ci sono diverse varianti di TM:
* a nastro semi-infinito
* multinastro
* non deterministiche

ogni variante è equivalente ad una TM, in quanto hanno le comuni caratteristiche di:
* accesso alla memoria senza restrizioni
* memoria illimitata

**enumeratore**

è una TM connessa ad una stampante

**linguaggio enumerato**

è il linguaggio generato dalla stampante di un enumeratore (tutte le stringhe stampate)

lemma1:
* un linguaggio è ricorsivamente enumerabile sse esite un enumeratore che lo enumera

**notazione formale delle TM**

* l'input è sempre una stringa
* se l'input è un oggetto, deve essere tradotto in una stringa, indicato tra parentesi angolate
* l'algoritmo viene descritto con un testo

**decidibilità**

bisogna dimostrare che il problema computazione è decidibile

**linguaggi non riconocibili**

esistono linguaggi non riconoscibili da una TM, in quanto:
* l'insieme di tutte le TM è numerabile
* l'insieme di tutti i linguaggi non è numerabile

quindi esistono dei linguaggi che le TM non possono riconoscere

**teorema di riconoscibilità**

se un linguaggio ed il suo complentare sono riconoscibili, allora il linguaggio è decidibile

**linguaggio co-turing-riconoscibile**

un linguaggio è co-turing-riconoscibile se è il complementare di un linguaggio turing riconoscibile

**teorema di decidibilità**

un linguaggio è turing decidibile sse è turing-riconoscibile e co-turing-riconoscibile


**relazioni tra classi di linguaggi e capacità computazionale**

la gerarchia è questa:

||
|---|
|riconoscibili|
|decidibili|
|context free|
|regolari|

**funzione calcolabile**

una funzione si dice calcolabile se esiste una TM che svolge lo stesso compito, cioè se la TM su input w termina con la computazione f(w) nel nastro

**riducibilità**

un linguaggio A è riducibile in B se esite una funzione calcolabile tale per cui per ogni parola w in A, f(w) è in B,se esiste una riduzione da A in B, si può risolvere A usando la soluzione di B

si indica con A <= B

**complessità di tempo**

data una TM deterministica, il tempo di esecuzione della TM è una funzione t(n) che indica il massimo numero di passi che la TM utilizza per un input di lunghezza n

nb:
* una TM ha una complessità di tempo --> tempo di esecuzion
* un linguaggio appartiene ad una classe di complssità --> esiste una TM che lo genera in quella complessità di tempo

**O-grande**

date 2 funzioni, f(n), g(n), la scrittura:
* f(n) = O(g(n))

indica che a partire da un n0, per ogni n>n0 si ha che:
* f(n) <= c(g(n))

quindi g(n) è un limite superiore asintotico per f(n)

**classe di complessità**

una classe di complessità time(t(n)) è l'insieme dei linguaggi decisi da una TM in tempo O(t(n))

**relazioni di complessità tra modelli**

* ogni TM multinastro di tempo t(n) ammette una TM equivalente a nastro singolo di tempo O(t<sup>2</sup>(n))

* ogni TM non deterministica di tempo t(n) ammette una TM equivalente a nastro singolo di tempo 2<sup>O(t(n))</sup>


**verificatore**

un verificatore è una TM:
* A = { w se V accetta l'oggetto (w,c)}

dove:
* c è un input chiamato certificato utilizzato in qualche modo per decidere se accettare la parola w

**classe di linguaggi P**

è la classe dei linguaggi in cui l'appartenenza di una stringa può essere decisa in tempo P

ogni CFL ha una classe di complessità P

**classe di linguaggi NP-easy**

è la classe dei linguaggi in cui l'appartenenza di una stringa può essere verificata in tempo P

**classe di linguaggi equivalente**

è la classe dei linguaggi in cui l'appartenenza di una stringa può essere decisa in tempo P da una TM non deterministica

**classe di linguaggi coNP**

è la classe dei linguaggi complementari alla classe NP


**classe di linguaggi NP-hard**

è la classe di linguaggi tale per cui la TM che li genera può generare tutti i linguaggi NP


**classe di linguaggi NP-completo**

è la classe di linguaggi che è sia NP-easy che NP-hard

**tipi di problemi**

* trattabili --> possono essere risolti in tempo P
* intrattabili --> non possono essere risolti in tempo P (problemi NP)
* non risolvibili --> halting problem

**circuitSAT**

è il problema NP-completo più importante, ogni problema NP può essere convertito in un circuitSAT

dato un circuito booleano, determinare se esistono degli input che permettono di ottenere l'output = 1

**NP-completezza**

per dimostrare l'NP completezza bisogna dimostrare:
* NP-easyness --> dimostrare l'esistenza di un verificatore polinomiale
* NP-hardness
    * si sceglie un problema NP hard
    * lo si riduce nel nostro problema
    * si dimostra la riduzione
    * si dimostra che la funzione di riduzione impiega tempo polinomiale

**SAT**

data una formula booleana, determinare se esistono dei valori booleani che permettono di ottenere il valore di veritò = vero

traduzione circuitSAT a SAT:
* si da un nome agli output delle porte logiche
* si scrive l'espressione booleana di ogni porta, tutte in and logico

**3SAT**

* letterale --> variabile oppure variabile negata
* clausola --> 1 letterale oppure un or logica di 2 o più letterali

una formula booleana si dice in CNF (forma normale congiuntiva) se è una congiunzione logica di and di una o più clausole


una formula booleana si dice in 3CNF (forma normale congiuntiva) se composta di clausole con esattamente 3 letterali distinti

il 3SAT è una formula booleana in 3CNF

**scelta del problema**

problemi NP completi:
* circuito hamiltoniano --> ciclo che visita ogni vertice una volta sola
* copertura di vertici --> minimo numero di vertici tale per cui ogni arco ha un estremità in questo insieme
* 3-colorazione --> colorare un grafo in modo tale che vertici adiacenti hanno colore diverso
* minVertexCover
* maxIndipendentSet --> trovare l'insieme indipendente più grande
    * l'insieme indipendente di un grafo è tale se per ogni coppia di vertici non esiste un arco che li connette

problemi P:
* cirucito euleriano --> ciclo che visita ogni arco una sola volta
* copertura di archi --> minimo numero di archi tale per cui ogni vertice è un estremità in questo insieme
* 2-colorazione --> 3-colorazione ma con 2 colori

scelta del problema
* assegnazione di bit ad oggetti --> SAT
* assegnazione di etichette ad oggetti o partizionare gli oggetti in un numero costante di sottoinsiemi --> k-colorazione
* organizzare gli oggetti in un certo ordine --> circuito hamiltoniano
* piccolo sottoinsieme che rispetta certi vincoli --> minVertexCover
* grande sottoinsieme che rispetta certi vincoli --> maxIndipendentSet
* il numero 3 appare nel problema --> 3SAT o 3color
* tutto il resto fallisce --> 3SAT o SAT
