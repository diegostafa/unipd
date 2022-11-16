
## Variabili aleatorie assolutamente continue

è una VA che può assumere valori in tutto R

**densità continua**

è la probabilità che la VA assuma un valore in un intervallo a-b:
* P(a <= X <= B) = a $$$ b f(x)dx

proprietà:    
* f(x) sempre maggiore di 0
* f(x) può non essere continua
* -inf $$$ +inf f(x)dx == 1
* P(X=a) è sempre = 0
* f(a) indica uanta densità si concentra in un intorno di x=a 

**funzione di distribuzione**

* P(X < x) = Fx(x) = -inf $$$ x f(y)dy

si indica con Fx, indica la probabilità che P(X<=a), uindi si racava che:
* P(a <= X <= B) = P(X<=b) - P(X<=a)
* P(a <= X <= B) = Fx(b) - Fx(a)

proprietà:
* lim -> -inf Fx(x) = 0
* lim -> +inf Fx(x) = 1
* x <= y --> Fx(x) <= Fx(y)
* Fx(x) è continua
* F'x(x) = f(x)

**teorema di caratterizzazione di VA continue**

data una VA X di cui conosciamo funzione di distribuzione e densità, se Y è una VA funzione di X, allora riusciamo a caratterizzarla:

dimostrazione:
* Fy(y) 
    * = P(Y < y)
    * = P(g(X) < y)
    * = P(X < g<sup>-1</sup>(y))
    * = Fx(g<sup>-1</sup>(y))
* f(y) 
    = F'y(y)
    = F'x(g<sup>-1</sup>(y))*g<sup>-1</sup>(y)

quindi:
* Fy(y) = Fx(g<sup>-1</sup>(y))
* fy(y) = F'x(g<sup>-1</sup>(y))*g<sup>-1</sup>(y)

**valor medio**

si indica con:
* E(X) = -inf $$$ +inf xf(x)dx

proprietà:
* stesse proprietà della discreta
* può non esistere
* E(g(x)) = -inf $$$ +inf g(x)F(x)dx 
    * in particolare se g(x) = (x - E(x))<sup>2</sup> si ha la definizione di varianza

**varianza**

uguale tra VA discrete e continue

## VA fondamentali

**VA continue uniformi**

data un intervallo a-b

X ~ U(a,b) se ha: 

densità continua:
* fx(x) =
    * 1/(b-a) se a <= x <= b
    * 0 altrimenti
    
funzione di distribuzione:
* Fx(x) =
    * 0 se x < a
    * (x-a)/(b-a) se a <= x <= b
    * 1 se x > b

caratteristiche:
* E(X) = (b+a)/2
* Var(X) = (b-a)<sup>2</sup>/12 

**VA continue esponenziali**

data un numero lambda l positivo

X ~ Exp(l) se ha: 

densità continua:
* fx(x) =
    * le<sup>-lx</sup> se  x >= 0
    * 0 altrimenti
 
funzione di distribuzione:
* Fx(x) =
    * 1-e<sup>-lx</sup> se x >= 0
    * 0  altrimenti

caratteristiche:
* E(X) = 1/l
* Var(X) = 1/l<sup>2</sup>
* P(X > T+t | X > T) = P(X > T) --> ASSENZA DI MEMORIA

 
modella il tempo di attesa tra 2 eventi

**VA gaussiana**

dati la media mi e la deviazione standard s, con s != 0, allora:

X ~ N(mi, s<sup>2</sup>)

densità continua:
* fx(x) = 1/rad(1\*pi\*r<sup>2</sup>) \* e<sup>(x-mi)<sup>2</sup>/2s<sup>2</sup></sup>

funzione di distribuzione:
* non calcolabile analiticamente

caratteristiche:
* E(X) = mi
* Var(X) = s<sup>2</sup>

**VA gaussiana affine (combinazione lineare)**

due VA gaussiane X e Y si possono sempre combinare in particolare:

se Y = aX + b, allora:

Y ~ N(a\*mi + b, a<sup>2</sup>s</sup>2</sup>)

densità continua:
* fy(y) = 1/a \* fx(y-b/a)

funzione di distribuzione:
* Fy(y) = Fx(y-b/a)

caratteristiche:
* E(Y) = a\*mi + b
* Var(Y) = a<sup>2</sup>s<sup>2</sup>

in particolare la distribuzione di una combinazione lineare gaussiana è gaussiana

**VA gaussiana centrata standard**

si indica con Z la VA centrata gaussiana quando:
* Z = (X - mi) / s

funzione di distribuzione (che si indica sempre con fi)
* -inf $$$ z 1/rad(2\*pi) \* e<sup>-x<sup>2</sup>/2</sup>dx

la funzione di distribuzione è completamente mappata

caratteristiche:
* E(Z) = 0
* Var(Z) = 1

NB: ogni VA gaussiana si può trasformare in gaussiana centrata standard attraverso la formula