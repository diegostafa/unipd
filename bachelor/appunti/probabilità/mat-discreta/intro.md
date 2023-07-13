### Grafi

si indicano con:
* G (V, E)

dove:
* G è il grafo
* V è un insieme di vertici (nodi)
* E è un insieme di coppie di vertici (archi)

**terminologia**
* percorso: sequenza di vertici
    * il percorso è chiuso se i vertici alle estremità coincidono
* cammino: percorso con vertici. distinti
    * ll cammino è un ciclo/circuito se i vertici alle estremità coincidono
* lunghezza: numero di archi in un percorso
* isomorfismo: grafi uguali con disegno diverso

**grado di un vertice**

si indica con d(V) il grado di un vertice, ed indica di quanti archi V è un estremo

**proprietà sui gradi**

1. il grado totale di un grafo (somma dei gradi dei singoli vertici) è uguale a 2 volte il numero di archi.
2. la somma dei vertici di grado dispari è sempre un numero pari


---

### Tipi di grafi

i grafi possono essere:
* connessi: ogni vertice può raggiungere ogni altro vertice tramite un percorso
* completi: tutti i vertici sono connessi tra loro (eg. rete a stella)
* bipartiti: il grafo è formato da 2 insiemi di vertici, ogni arco connette questi 2 insiemi
    * è completo se tutti i vertici del primo insieme sono connessi a tutti i vertici del secondo
* k-regolari: ogni vertice ha grado k
    * sono chiamati cubici se K=3
* tornei: grafi orientati e completi 

**multigrafi**

sono grafi con pià archi passanti per 2 vertici
* archi passanti per 2 stessi vertici sono detti paralleli
* archi che hanno le stesse estremità sono detti cappi
    * un cappio contribuisce di 2 al grado di un nodo

**sottografi**

un grafo G' è sottografo di G se i vertici e archi di G' sono sottoinsiemi dei vertici e archi di G

per indicarli sono necessari sia vertici che archi 

**sottografi indotti**

sono sottografi che mantengono le adiacenze tra vertici, di base consiste 

per indicarli sono necessari solo i vertici, in quanto gli archi sono indotti da questi

**grafi complementari**

di base il grafo G' complentare di un grafo G, è un grafo formato dagli stessi vertici di G, ma gli archi che G non ha li ha G', e i grafi che G' non ha li ha G

**grafi isomorfi**

sono grafi uguali ma disegnati in modo diverso

se due grafi sono isomorfi allora:
* hanno stesso numero di vertici
* hanno stesso numero di archi
* hanno stesso numero di vertici con lo stesso grado
* i complementari sono isomorfi
* hanno gli stessi sottografi indotti

### Grafi bipartiti

un grafo bipartito è un grafo tale per si possono dividere i vertici in due gruppi ed ogni arco ha per estremi vertici di gruppi differenti

**condizione di bipartizione**

un grafo e bipartibile se e solo se non contene nessun ciclo/circuito di lunghezza dispari

**algoritmo di bipartizione**

1. si assegna un nodo qualsiasi ad un insieme
2. per ogni nodo appartenente ad un insieme si assegnano tutti i suoi nodi adiacenti all'altro insieme

---

### Grafi orientati

sono grafi in cui gli archi sono coppie ordinate di vertici
    * si dicono semplici se non sono multigrafi

i nodi sono:
* iniziali: coda di un arco
* finali: testa di un arco

il cammino di un grafo orientato è detto cammino orientato
    * il grafo si dice fortemente connesso se per ogni coppia di vertici esiste un cammino orientato

**gradi orientati**

si indicano con G (V, A)

* grado entrante (d<sup>in</sup>(v)): numero di archi entranti nel nodo
* grado uscente (d<sup>out</sup>(v)): numero di archi uscenti dal nodo

la somma di tutti i gradi entranti del grafo è uguale alla somma di tutti i gradi ed è anche uguale al numero di archi totali

---

### Rappresentazione matriciale

**matrice di incidenza vertici/archi (non orientato)**

è una matrice che ha per righe i vertici e per colonne gli archi

si guardano le colonne, contiene 1 se un vertice è estremo dell'arco, 0 altrimenti

**matrice di incidenza vertici/archi (orientato)**

come quella non orientata,

contiene 1 se il vertice è l'estremo uscente, -1 se è l'entrante, 0 altrimenti

**matrice di adiacenza vertici/vertici**

è una matrice quadrata che ha per dimensione il numero di vertici

contiene 1 se i vertici sono collegati, 0 altrimenti

---