### Connettività

un grafo è connesso se il numero di componenenti connesse è 1

due nodi sono connessi sse esiste un cammino tra i due

**proprietà di connessione**

* ogni nodo v è connesso a se stesso
* se nodo1 è connesso a nodo2 allora nodo2 è connesso a nodo1
* se nodo1 e nodo2 sono connessi, nodo2 e nodo3 sono connessi, allora nodo1 e nodo3 sono connessi

**componenti connesse di un grafo**

dato un grafo G, le componenti connesse sono sottografi di G, tali per cui, ogni nodo del sottografo è connesso

**taglio**

si indica con 𝛿(S)

dato un sottoinsieme S di vertici di un grafo G, si definisce con taglio l'insieme di archi che hanno una sola estremità in S

si dice che un taglio S separa due nodi se S contiene un nodo ma non l'altro

teorema 1:
* l'insieme complentare di S ha lo stesso taglio di S

teorema 2:
* l'insieme degli archi di un cammino tra due nodi separati e l'insieme degli archi del taglio ha almeno un arco in comune

teorema 3:
* due nodi appartengono a componenti connesse differenti sse il taglio che separa i 2 nodi non contiene neanche un nodo del cammino tra i 2

**algoritmo per estrarre componenti connesse**

per scegliere i nodi della componente connessa C:
1. se sceglie un nodo a caso
2. si scegono tutti i nodi adiacenti
3. si ripete per ogni nodo scelto 

nb: allora 𝛿(C) è sempre vuoto

---

**connettività tra due nodi**

è il numero minimo di vertici da eliminare per sconnettere 2 nodi

**connettività di un grafo**
 
si indica con K(G)

è il numero minimo di vertici da eliminare per sconnettere il grafo

l'insieme formato da questi vertici è detto **separatore**

**arcoconnettività tra due nodi**

è il numrto minimodi archi da eliminare per sconnettere due nodi

**arcoconnettività di un grafo**

si indica con K<sup>E</sup>(G)

è il minimo tra tutte le possibili arcoconnettività del grafo
 
* **K(G) <= K<sup>E</sup>(G) <= d(G)**


**teorema 1**

il minimo numero di archi in un taglio che separa due nodi == il massimo numero di cammini tra i due nodi che non hanno archi in comune

**teorema 2**

il minimo numero di elementi di un separatore che sconnette 2 nodi == il massimo numero di cammini tra i due nodi che non hanno nodi in comune