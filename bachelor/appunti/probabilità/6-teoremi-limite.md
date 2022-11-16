## Teoremi limite

**legge dei grandi numeri**

ipotesi:
* X1, X2 ... XN sono VA uguali, indipendenti ed iid
* per ogni VA, E(X) = mi
* Xm = (X1 + X2 + ... XN)/N

tesi:
* per ogni epsilon > 0 si ha che:
* lim P(\|Xm - mi\| <= epsilon) = 1

di base la media aritmetica dei risultati delle VA converge al valore atteso delle VA a +inf

**legge dei grandi numeri (corollario)**

ipotesi:
* X1, X2 ... XN sono VA uguali, indipendenti ed iid
* per ogni VA, E(g(X)) = mi
* Xm = (g(X1) + g(X2) + ... g(XN))/N

tesi:
* per ogni epsilon > 0 si ha che:
* lim P(\|Xm - mi\| <= e) = 1

di base applicare una funzione alle VA ed al valore atteso mantiene l'uguaglianza

**teorema del limite centrale**

ipotesi:
* X1, X2 ... XN sono VA uguali, indipendenti ed iid
* per ogni VA, E(X) = mi
* per ogni VA, Var(X) = s<sup>2</sup>
* Xm = (X1 + X2 + ... XN)/N
* Ym = (Xm - mi) / (s / rad(n))

tesi:
* Ym ~ N(0,1)
