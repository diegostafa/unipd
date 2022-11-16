**interpolazione polinomiale**

consiste nel ricostruire una funzione campionata, quindi dati un insieme di punti (xi,yi) detti nodi di una funzione f(x), la sua interpolazione è una funzione fn(x), tale per cui:
* fn(xi) = yi per ogni punto campionato

idealmente:
* dist(f,fn) -> 0 a +inf

dist(f,fn) è definito com il massimo errore assoluto tra la funzione e la sua approssimazione:
* max(f(x)  - fn(x))

**calcolo del polinomio interpolatore**

per semplicità si usa la famiglia dei polinomi per il calcolo di fn

il polinomio interpolatore è quindi il risultato del sistema di equazioni definito come:
* fn(xi) = a + a1x ... +anx<sup>n</sup>

**matrice vandermonde**

il sistema precedemte può essere scritto in forma compatta:
* Va = y

dove:
* V n+1xn+1 dei campionamenti delle xi nei differenti gradi del polinomio 
* a è il vettore colonna dei coefficenti del polinomio
* y è il vettore colonna dei campionamenti yi

**unicità del polinomio interpolatore**

se ci fossero 2 polinomi p,q che interpolano i nodi si avrebbe che:
* g(x) = p(x) - q(x)
* quindi g(xi) = 0 per ogni nodo
* g(x) avrebbe quindi n+1 radici
* questo va contro il teorema fondamentale dell'algebra

**esistenza del polinomio interpolatore**

per dimostrare l'esistenza è sufficente dimostrare che da n+1 nodi diversi è sempre possibile creare il polinomio interpolatore di lagrange L(x) tale per cui L(xi) = yi
* Ni(x) = (x - x0)(x - x1)...(x - xn) SENZA (x - xi)
* Ki(x) = Ni(x) / Ni(xi)
    * Ki(xk) = 1 se xk = xi --> diventa N(xi)/N(xi)
    * Ki(xk) = 0 se xk != xi --> (xk - xk) --> 0/N(xi)
* L(x) = +++ yiKi(x)
* verifico che interpola:
    *  L(xk) = +++ yiKi(xk) --> ki(xk) è sempre 0 tranne quando i = k  quindi la sommatoria è = yi

**osservazione 1**

se la funzione da interpolare è un polinomio, il polinomio interpolatore è la funzione stessa

**teorema di densità di weirstrass**

afferma che ogni funzione reale continua definita in un intervallo chiuso e limitato può essere approssimata a piacere con un polinomio di grado opportuno

**polinomio di miglior approssimazione uniforme**

implicazione del teorema di weirstrass, esiste sempre il polinomio in grado di approssimare al meglio la funzione rispetto ad altri polinomi, ma è difficile da trovare

**campionamento a passo costante**

dato un intervallo a,b, consiste nel suddividere campoionare n punti eqispaziati (ad es. il tempo è una misura campionata a passo costante, 1s , 1 ms...)

**funzione di rungea**

è una funzione non interpolabile se campionata a passo costante

**campionamento di chebyshev**

si divide una semicirconferneza di raggio 1 in n spicchi con angolo alfa, il coseno di quest'angolo moltiplicato per il numero dello spicchio corrisponde al nodo

campionamenti:
* cos(a*i) con i da 0 a n

il cmpionamento sarà della seguente forma:
* -1 = t0 < t1 < t2 ... < tn = 1

per creare un campionamento in un generico intervallo a,b si utilizza la seguente trasformazione applicata ad ogni nodo:
* vi = (b-a)*ti/2 + (b+a)/2

**interpolazione polinomiale a tratti**

consiste nel definire un interpolatore polinomiale per ogni partizione del campionamento

le più comuni interpolazioni a tratti sono:
* lineari --> si congingono con dei segmenti nodi a 2 a 2 adiacenti (per 2 punti passa una sola retta)
* quadratiche --> si congiungono con delle parabole nodi a 3 a 3 adiacenti (per 3 punti passa una sola parabola)

**convergenza uniforme dell'interpolazione lineare a tratti**

la convergenza uniforme di base dice che la funzione interpolatrice a tratti rientra in un tubicino attorno alla funzione

ipotesi:
* s = 1
* f derivabile s+1 volte in a,b
* xi in a,b
* n+1 nodi distinti con n multiplo di s

tesi:
* esiste k > 0 tale per cui dist(f, P) < k*s^2

dimostrazione:
* il max su tutto a,b è il max dei singoli intervalli:
    * dist(f, P) = max|f(x) - P(x)| in \[a,b\] = max(max(|f(x) - P(x)|) in \[i-1,i\])
* stimiamo l'errore
    * max(|f(x) - P(x)|) in \[i-1,i\] <= max(|f^s+1(x)|)\*h^s+1/4(s+1)  in \[i-1,i\] con h = estremi dell'intervallo / s
    * sostituisco con s = 1, h = (i - 1 - i)/2
    * max(|f(x) - P(x)|) in \[i-1,i\] <= max(|f''(x)|)\*h^2/8  in \[i-1,i\]  <= f''(x)\*h^2/8
* pongo f''(x) = M
* risulta che dist(f,P) <= M/8* h^2

**interpolazione spline**

è uno speciale interpolatore a tratti continuo nei raccordi

**approssimazione polinomiale ai minimi quadrati**

consiste nel cercare il polinomio L(x) che abbia la somma minore degli scarti quadratici
* +++ (L(xi) - yi)<sup>2</sup> = min +++ (p(xi) - yi)<sup>2</sup> 

L ha la forma:
* a0 + a1x + ... + anx<sup>n</sup>

la scrittura compatta è:
* +++ yi - (Va)i<sup>2</sup>

per trovare quinid i coefficenti del polinomio bisogna risolvere la seguente equazione:
* V'Va = V'y

dove:
* V è la matrice dei punti xi su incognita del polinomio
* V' è la trasposta di V
* y è il vettore colonna delle yi