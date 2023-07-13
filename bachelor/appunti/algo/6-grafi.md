# Grafi

**grafo connesso**

un grafo G è connesso se ogni nodo è raggiungibile da ogni altro nodo

**grafo fortemente connesso**

grafo orientato e connesso

**componente connessa**

un sottografo G' è una componente connessa di G se è connesso e massimale

**componente fortemente connessa**

sottografo orientato e componente connessa

**massimale**

un grafo G' è massimale di G se è la componente connessa più grande di G  

**albero di copertura**

G' è un albero di copertura di G se:
* G è un albero
* contiene tutti nodi di G
* è connesso
* ha solo un cammino

**DAG**

è un grafo orientato aciclico

**ordinamento topologico**

vale solo per DAG

G' è un ordinamento topologico di G se si possono ordinare i nodi in base alla definizione degli archi

ci possono essere più ordinamenti topologici equivalenti

algoritmo:
* si tolgono in ordine i nodi che non hanno archi entranti

**grafo trasposto**

grafo orientato con nodi invertiti

**cammini minimi a singola sorgente**

dati:
* grafo orientato
* archi peati
* nodo sorgente s

problema:
* trovare i cammini minimi da s a tutti gli altri nodi

**teorema di bellman**

una soluzione ammissibile T è ottima sse:
* distanza(v) = distanza(u) + peso(u,v) per ogni arco(u,v) in T
* distanza(v) <= distanza(u) + peso(u,v) per ogni arco(u,v) in G
