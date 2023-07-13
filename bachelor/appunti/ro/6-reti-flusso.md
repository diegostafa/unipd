**flussi di costo minimo**

nodo ha un bilancio:
* v = d - p --> energia offerta - energia prodotta

ogni arco:
* ha un costo c
* ha una portata u

obiettivo:
* assegnare la portata degli archi, bilanciando i nodi mantenendo i costi minimi

per ogni nodo:
* v = archi entranti - archi uscenti

formalizzazione PL
* una variabile per ogni arco
* un vincolo per ogni nodo
    * arco entrante --> variabile con segno +
    * arco uscente --> variabile con segno -
* un termine noto per ogni v del nodo

**matrice di incidenza nodo-arco**

* righe --> nodi
* colonne --> archi
* ogni riga indica gli archi uscenti (-1) ed entranti (+1) nel nodo
* somma delle righe = 0
* rk(E) = numero nodi - 1
* matrice totalmente unimodulare

**TU - matrice totalmente unimodulare**

è una matrice tale per cui ogni sua sottomatrice quadrata ha determinante -1, 0, 1

**cammini minimi**

caso particolare del flusso minimo
* nodo di partenza ha v = -1
* nodo di arrivo ha v = 1
* tutti gli altri hanno v = 0

**LCG - algoritmo label correcting generico**

* metti a 0 l'etichetta del nodo di partenza
* metti a +inf tutte le altre
* nodo = min di tutti gli archi entranti + il loro nodo
* per ogni nodo
* converge senza cicli negativi
* upper bound --> n archi * costo cammino più lungo
* lower bound --> arco più corto dalla sorgente
* trova tutti i cammini minimi dalla sorgente agli altri nodi
* crea l'albero dei cammini minimi con radice la sorgente
* si trova il cammino partendo dalla foglia e andando verso il padre
* non termina se esiste un ciclo di lunghezza negativa
* complessità pseudo polinomiale

**LC - algoritmo di label correcting (bellman-ford)**

* inizializza la sorgente a 0 e predecessore nil
* E(X) = etichetta del nodo x
* per ogni nodo aggiornato u
    * per ogni arco uscente
        * se E(u) + arco < E(destinazione)
            * E(destinazione) = E(u) + arco
* se all'n-esima iterazione sono stati aggiornati nodi c'è un ciclo negativo

caratteristiche
* complessità nodi*archi
* max numero di iterazioni = 1 + nodi (la prima è l'inizializzazione)
* finisce quando non vengono aggiornate etichette
* se si vogliono i cammini minimi con max k archi ci si ferma all'iterazione k
* bisogna sempre fare l'algoritmo completo per avere tutte le etichette giuste

costruzione dell'albero:
* radice = sorgente
* guardando i predecessori nell'ultima iterazione si costruisce l'abero

costruzione del grafo:
* si disegnano i nodi del grafo iniziale
* si disegnano gli archi dell'albero dei cammini minimi
* si mettono le etichette finali nei nodi
* si aggiungono gli archi solo se minori o uguali dell'etichetta che vogliono congiungere

**LS - algoritmo label setting (dijkstra)**

* E(X) = etichetta del nodo x
* S = vuoto
* S'= nodi
* E(sorgente) = 0
* u = extract min E(x) in S'
* inserisce u in S
* se S' è vuoto --> trovati i cammini minimi
* per ogni arco uscente in un nodo in S'
    * se E(u) + arco < E(destinazione)
        * aggiorna E(destinazione)

caratteristiche:
* si applica solo con costi >= 0
* più veloce di bellman-ford
* costruzione dell'albero e grafo uguale a bellmand ford
* non si può trovare il cammino minimo con max n archi, solo bellman ford

**zaino binario**
