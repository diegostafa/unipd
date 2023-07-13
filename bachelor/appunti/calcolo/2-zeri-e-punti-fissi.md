# zeri delle funzioni

lo zero di una funzione è il risultato della seguente equazione:
* f(x) = 0

**metodo di bisezione**

è un algoritmo ricorsivo per determinare gli zeri di una funzione

dato un intervallo (a,b) con f(a) discorde ad f(b):
1. x0 = (b-a)/2
2. se f(x0) == 0
    * fine
3. se f(x0) discorde con f(a)
    * bisezione con (a,x0)
4. se f(x0) discorde con f(b)
    * bisezione con (x0,b)

consiste quindi nel costruire 2 successioni:
* an --> estremi sinistri
* xn --> punti medi
* bn --> estremi destri

la convergenza di questo algoritmo al punto cercato è data da:
* lim an = lim xn = limbn (teorema dei carabinieri)

pro:
* Il metodo della bisezione lavora con ipotesi minime, ovvero quelle del teorema degli zeri
* Al passo n può essere sufficiente calcolare solo f(xn) per scegliere il successivo intervall

contro:
* fattore di convergenza < 1/2

**stima**

data un quantità en che definisce l'errore assoluto, una stima determina quando questa quantità è minore di una certa tolleranza epsilon
* en < epsilon

che spesso si traduce con:
* ordine di convergenza di en < epsilon

**residuo**

è la successione che indica quanto manca alla funzione per annullarsi:
* en = |f(xn)|

la stima del residuo non è un buon indicatore:
* residuo piccolo ed errore grande --> errore sottostimato
* residuo grande ed errore piccolo --> errore sovrastimato

**residuo pesato**

è la successione che indica quanto si è vicini al punto di intersezione

è il residuo diviso la derivata tra xn,x
* en = |xn - x| =  |f(xn)|/|f'(zn)| 

zn è la successione in (x, xn) di punti determinati dal teorema di lagrange/valor medio

si dice stima empirica se si considera:
* en = |xn - x| ~= |f(xn)|/f'(xn)|

**stima a priori**

consiste nello stimare il residuo

**stima a posteriori**

consiste nello stimare il residuo pesato
* en < epsilon

si dice a posteriori in quanto la stima viene calcolata dopo aver ottenuto la successione xn

**metodo di newton**

1. calcola la retta tangente in un punto f(x) della funzione
2. calcola il punto di intersezione x0 tra la tangente e l'asse delle x
3. ripeti il metodo con f(x0)

la successione che si costruisce in questo modo è:
* x<sub>n+1</sub> = x<sub>n</sub> - f(x<sub>n</sub>)/f'(x<sub>n</sub>)

ipotesi di convergenza globale:
* f(x) derivabile 2 volte in a,b
* f(a) discorde a f(b)
* f''(x) sempre maggiore o minore di 0
* f(x0) discorde a f''(x0)  

ipotesi di convergenza locale:
* f derivabile 2 volte in un intorno dello zero di funzione
* f'(x) è sempre != 0 in questo intorno
* esiste x0 con una particolare condizione

**ordini di convergenza**

è un numero P che di base esprime il numero di cifre decimali guadagnate ad ogni iterazione

un algoritmo ha ordine di convergeneza almeno p>=1 se:
* e<sub>n+1</sub> <= ce<sub>n</sub><sup>p</sup>

quindi l'errore di ogni elemento della successione è sempre minore dell'errore del suo precedente di un ordine P

* p = 1 --> convergenza lineare
* p = 2 --> convergenza quadratica

per verificare la convergenza si usa il criterio del rapporto, cioè si fa il limite del rapporto tra l'ennesimo elemento ed il suo precedente
* L < 1 --> la successione converge

**metodo delle corde**

1. calcola la retta passante per a,b
2. calcola il punto di intersezione x0 tra la retta e l'asse delle x
3. se f(x0) = 0 --> fine
4. se f(x0) è discorde ad f(a)
    * ripeti con (a,x0)
5. se f(x0) è discorde ad f(b)
    * ripeti con (x0,b)


**metodo del punto fisso**

data una funzione g(x) in a,b che va in a,b il metodo del punto fisso per determinare g(c) = c è:
* x0 = a,b
* x1 = g(x0)
* x2 = g(x2)
...

**teorema delle contrazioni**

afferma che una funzione in stesso dominio e codominio tocca sempre almeno una volta la bisettrice

se la derivata della funzione è maggiorata da una costante tra 0-1 allora la la funzioene tocca esattamente una volta la bisettrice

ipotesi:
1. f(x) va da [a,b] in [a,b]
2. f'(x) < c con 0 < c < 1

tesi:
1. esiste il punto fisso
2. il punto fisso è unico


dimostrazione 1) 
* g(x) = x - f(x)
* se gli estremi a,b sono punti fissi --> fine
* altrimenti si ha che
    * a < f(x) < b
    * a - f(x) sicuramente negativo
    * b - f(x) sicuramente positivo
    * quindi f(x) cambia segno agli estremi --> esiste il punto fisso

dimostrazione 2)
* se x1,x2 punti fissi
* x1 - x2 = f(x1) - f(x2) < c*(x1 - x2)
