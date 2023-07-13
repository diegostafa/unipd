
### Grafi planari

un grafo è planare se nel suo disegno non si intersecano gli archi

**grafi minori**

sono sottografi ottenuti attraverso 3 operazioni:
* contrazione di archi
* rimozione di archi
* rimozione di vertici isolati

se un grafo minore di G è planare allora G è planare

**contrazione di un arco**

la contrazione di un arco con estremi p e q significa far collassare i due nodi in un nuico nodo eliminando l'arco

**teorema di kuratowski**

un grafo è planare sse non contiene i minori:
* K_5 --> grafo a stella
* K_3_3 --> grafo bipartito 3x3

**regioni o facce**

una regione è una porzione d piano delimitata da archi

**perimetro**

percorso chiuso (ciclo) percorrendo gli archi di una faccia/regione

la lunghezza di un perimetro è il numero di archi che si percorrono

**ponte**

è un arco la cui rimozione aumenta il numero di componenti connesse

un arco è un ponte sse non appartiene ad un ciclo

ogni ponte è percorso 2 volte in un perimetro

tutti gli archi di un albero sono ponti

ogni arco di un albero è percorso 2 volte

**ciclo hamiltoniano**

è un ciclo che attraversa ogni vertice del grafo una sola volta

il grafo si dice hamiltoniano

condizioni affinchè un grafo sia hamiltoniano:
* ogni nodo deve avere grado >= 2
* la connettività deve essere >= 2
* il numero di componenti connesse di un grafo senza n nodi deve essere < n

**teorema di dirac**

se G è un grafo semplice di n nodi e il grado di ogni nodo è >= n/2 allora H è hamiltoniano


**metodo del cerchio e delle corde**

dato un grafo che ammette un ciclo hamiltoniano, ne controlla la planarità

di base consiste nel disegnare un poligono regolare contentente i vertici del grafo, poi si disegnano gli archi, se non ci sono intersezioni è planare

**formula di eulero**

consente di trovare il numero di regioni per ogni grafo planare e connesso

dato il grafo G = (V, E), allora il numero di regioni di G è:
* r = E - V + 2

corollari
1. E <= 3V -6 (il numero di archi è sempre limitato da una funzione lineare del numero di vertici)
2. E <= 2v - 4 (se G è bipartito)
3. ogni grafo planare contiene un vertice di grado <= 5


**colorazione delle regioni**

ogni grafo planare è colorabile con almeno 4 colori, in modo tale che regioni confinanti abbiano colori distinti 

**numero cromatico**

è il minimo numero di colori necessari afficnè nodi adiacenti abbiano colori diversi

il numero cromatico è sempre <= al grado massimo di un grafo più uno

**numero arcocromatico**

è il minimo numero di colori necessari afficnè archi con estremi in comune abbiano colori diversi

il numero arcocromatico di un grafo semplice è sempre o uguale al grado massimo del grafo, o uguale al grado massimo più uno (teorema di vizing)


**scheletro**

dato un multigrafo, lo scheletro è il grafo semplice (no cappi o archi paralleli), con gli stess nodi, con gli stess nodi adiacenti

ogni scheletro di un grafo hamiltoniano è hamiltoniano


**percorsi euleriani**

è un ciclo che attraversa ogni arco del grafo una sola volta

il grafo si dice euleriano

condizioni affinchè un grafo sia euleriano:
* un grafo è euleriano sse ogni nodo ha grado pari

