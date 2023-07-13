### Rappresentazione geometrica di un vettore

un vettore R<sup>2</sup> è rappresentabile graficamente in un piano cartesiano, facendo corrispondere i suoi coefficenti con le coordinate del piano, il vettore è un segmento con estremi origine e il punto individuato

**regola del parallelogramma**

la somma di 2 vettori è rappresentabile graficamente con la regola del parallelogramma

---

### Norma di un vettore

**norma taxi driver**

si indica con \|\|v\|\|<sub>1</sub>

calcola la somma dei moduli dei coefficenti del vettore

**norma euclidea**

si indica con \|\|v\|\|<sub>2</sub>

calcola la lunghezza del vettore, c
per calcolare la lunchezza euclidea di un vettore:
* radice(v<sup>t</sup>v) --> per coefficenti reali
* radice(v<sup>h</sup>v) --> per coefficenti complessi (funziona anche per i reali in quanto il coniugato di un reale è il reale stesso)

nb: si può definire come radice del prodotto scalare canonico

la lunghezza di una somma tra vettori è sempre minore o uguale alla somma delle lunghezze dei vettori, **disuguaglianza triangolare**

**norma infinito**

si indica con \|\|v\|\|<sub>inf</sub>

calcola il massimo dei coefficenti del vettore

**\|\|v\|\|<sub>inf</sub> <= \|\|v\|\|<sub>2</sub> <= \|\|v\|\|<sub>1</sub>** --> si osserva facilmente

---

**Angoli tra vettori**

dati 2 vettori v e w non nulli ed un angolo alfa associato:
* v<sup>t</sup>w = \|\|v\|\|<sub>2</sub>\*\|\|v\|\|<sub>2</sub>\*cos(alfa)

da cui:
* cos(alfa) = v<sup>t</sup>w / ( \|\|v\|\|<sub>2</sub>\*\|\|v\|\|<sub>2</sub> )

**prodotto scalare**

posto v<sup>t</sup>w == \(v \| w\)

allora \(v \| w\) si chiama prodotto scalare ed è tale per cui:
* \(v \| w\) = coniugato \(w \| v\)
* \(v \| k1w + k2z\) = k1\(v \| w\) + k2\(v \| z\)
* \(v \| v\) è sempre maggiore uguale a 0

**spazio metrico**

è uno spazio vettoriale su cui è definito il prodotto scalare

**norma indotta**

calcola la radice del prodotto scalare tra v e se stesso

**generalizzazione del coseno tra due vettori**

* cos v<sup>^</sup>w = \(v\|w\) / \|\|v\|\|<sub>2</sub>\*\|\|v\|\|<sub>2</sub>

**vettori ortogonali**

v è ortogonale a w sse il prodotto scalare tra v e w è uguale a 0

**normalizzazione**

significa moltiplicare v per l'inverso della sua norma, cioè v\*(1/\|\|v\|\|)

**insiemi di vettori ortogonali**

un insieme di vettori si dice ortoganale se tutti i vettori dell'insieme sono ortogonali tra loro

es: l'insieme delle colonne della matrice identica


**insiemi di vettori ortonormali**

un insieme di vettori si dice ortonormale se:
* è ortogonale
* tutti i vettori dell'insieme sono normalizzati  ( (v | v) == 1 per ogni v dell'insieme)

**insiemi di generatori ortogonali**

autoesplicativo

**insiemi di generatori ortonormale**

autoesplicativo

**basi ortogonali**

autoesplicativo

**basi ortonormale**

autoesplicativo

**algoritmo Gram-Schmidt**

costruisce un sistema generatore ortogonale da un sistema generatore

nb:
1. un sistema generatore ortogonale senza vettori nulli è sempre una base
2. una base su cui viene applciato GS diventa una base ortogonale
3. per costruire una base ortonormale si normalizzano tutti i vettori della base ortogonale

dati un insieme V formato da v1,v2..vn, si costruisce l'insieme ortoganale W formato da u1,u2..un, con:
* u<sub>1</sub> = v<sub>1</sub>
* u<sub>2</sub> = v<sub>2</sub> - u<sub>1</sub>Z<sub>1</sub>

* u<sub>n</sub> = v<sub>n</sub> - u<sub>1</sub>((v<sub>n</sub> \| u<sub>1</sub>) / (u<sub>1</sub> \| u<sub>1</sub>)) - u<sub>2</sub>((v<sub>n</sub> \| u<sub>2</sub>) / (u<sub>2</sub> \| u<sub>2</sub>)) - ... - u<sub>n-1</sub>((v<sub>n</sub> \| <sub>n-1</sub>) / (u<sub>n-1</sub> \| u<sub>n-1</sub>))

**complemento ortogonale di un sottospazio**

dato un sottospazio U di uno spazio V, il complemento ortogonale di U è l'insieme dei vettori in V tale per cui:
* (u \| v) = 0, per ogni u

di base sono tutti i vettori di V (quindi anche di U) che sono ortogonali a tutti i vettori di u

proprietà:
* il complemento ortogonale è un sottospazio di V
* la somma diretta di U e il suo complemento è V
* dim U + dim complemento U == dim V
* ogni vettore di V è unicamente individuato dalla somma tra 2 vettori di U e il suo complemento (proiezione ortogonale)
* complemento ortogonale == N(A<sup>H</sup>), con A la matrice che ha per colonne i vettori di U

**Proiezione ortogonale**

di base un vettore nello spazio V è individuabile da 2 vettori, uno di U, uno del complemento

si indica con P<sub>U</sub>(v) la proiezione ortogonale del vettore v sul sottospazio U

per trovare P<sub>U</sub>(v)

1. si trova una base di U
2. si trova la base ortogonale con gram schmidt
3. si trova la base ortonormale normalizzando
4. P<sub>U</sub>(v) = (b<sub>1</sub>\|v)b<sub>1</sub> + (b<sub>2</sub>\|v)b<sub>2</sub> +...+ (b<sub>n</sub>\|v)b<sub>n</sub>

**matrice di proieizione**

è una matrice quadrata Q tale per cui il prodotto tra Q e un vettore v da la proiezione ortogonale di v

la costruzione della matrice:
1. si crea una matrice nxk, che ha per colonne i vettori alti n di una base ortonormale di k elementi
2. si moltiplica questa matrice per la sua H trasposta

per calcolare la matrice di proiezione del complemento ortogonale si fa matrice identintica - matrice di proiezione

