### Foreste e alberi

**foreste**

una foresta è un grafo senza cicli/circuiti

**alberi**

è una foresta connessa

proprietà:
* ogni albero (con almeno 2 nodi) ha almeno 2 nodi di grado 2
* il numero degli archi è uguale al numero dei nodi meno 1
* ogni coppia di vertici esiste un unico cammino che li collega

**algoritmo di kruskal**

dato un grafo connesso i cui archi hanno un costo, crea l'albero più economico

per creare un albero
1. crea una lista degli archi in ordine crescente di costo
2. toglie il primo arco della lista e lo mette nel grafo
2. forma un ciclo?
    * si --> lo toglie dal grafo
    * no --> step 2

**algoritmo di dijkstra**

dato un grafo G connesso i cui archi hanno un costo ed un nodo n di partenza, trova un albero (sottografo di G) che contiene tutti i cammini di costo minimo tra n e ogni altro nodo

inizializzazione:
* n ha distanza 0
* tutti gli altri nodi hanno distanza infinito
* S è una lista di tutti i nodi in ordine crescente alle loro distanze

algoritmo:
1. prende il primo nodo p di S
2. prende un nodo q adiacente a p e contenuto in S
3. q ha una distanza maggiore di p + l'arco che li unisce?
    * si --> aggiorna la distanza di q
    * no --> step 2
4. rimuove p dalla lista S
5. step 1
