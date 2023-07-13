# Variabili aleatorie discrete

una VA è una funzione che mappa gli esiti di uno spazio campionario a dei reali:
* X : omega -> R

**alfabeto**

sono i possibili valori che la VA può assumere

**densità discreta**

è definita come:
* P : X -> \[0,1\]

è la probabilitò che P(X=k), cioà la probabilità che la VA assuma il valore k, è uguale alla somma degli esiti che la verificano

**VA indicatrice**

I : omega -> \[0, 1\], dove:
* I = 1 se o appartiene ad omega
* I = 0 altrimenti

denità dicreta:
* P(I=1) = p
* P(I=0) = 1-p

**valor medio**

definito x<sub>i</sub> come esito della VA, il valor medio si indica con:
* E(X) = 1 +++ n x<sub>n</sub>\*P(X=x<sub>i</sub>) 

proprietà:
* E(aX + b) = aE(X) + b
* E(X + Y) == E(X) + E(Y)
* E(f(X)) = 1 +++ n f(x<sub>i</sub>)P(x<sub>i</sub>)

conseguenze:
* X >= 0 implica E(X) >= 0
* E(X) >= E(Y) implica X >= Y
* inf X <= E(X) <= max X

**varianza**

è un numero positivo che indica quanto l'alfabeto sia distribuito attorno al valor medio

si indica con:
* Var(X) = E(X<sup>2</sup>) - E(X)<sup>2</sup>
* Var(X) = E((X - E(X))<sup>2</sup>)
* Var(X) = 1 +++ n (x<sub>i</suB> - E(X))<sup>2</sup>P(x<sub>i</sub>)

proprietà:
* Var(X) sempre >= 0
* Var(aX + b) = a<sup>2</sup>Var(X)
* Var(X + Y) = Var(X) + Var(Y) + 2Cov(X,Y)

**covarianza**

si indica con:
* Cov(X,Y) = E\[(X-E(X))(Y-E(Y))\]

proprietà:
* Cov(X,X) = Var(X)
* Cov(X,Y) = E(XY) - E(X)E(Y)

## Variabili aleatorie discrete fondamentali


**VA di bernoulli**

data la probabilità di successo p di un evento in una prova di bernoulli:

X ~ Be(p) se:

alfabeto:
* X = 1 se l'esito ha successo
* X = 0 altrimenti

densità discreta:
* P(X=1) = p
* P(X=0) = 1 - p

caratteristiche:
* E(X) = p
* Var(X) = p(1-p) 

modella il verficarsi di un evento

**VA binomiale**

data la probabilità di successo p di un evento in una prova di bernoulli, ripetuta n volte:

X ~ Bin(n,p) se: 

alfabeto:
* X = numeri di successi ottenuti

densità discreta:
* P(X=k) = (n su k)p<sup>k</sup>(1-p)<sup>k</sup>

caratteristiche:
* E(X) = np
* Var(X) = np(1-p) 

modella il la prova di bernoulli ripetuta n volte

**VA geometrica**

data la probabilità di successo p di un evento in una prova di bernoulli:

X ~ Ge(p), dove: 
* p nell'intervallo \[0,1\]

alfabeto:
* X = numero di insuccessi prima di un successo

densità discreta:
* P(X=k) = (1-p)p<sup>k-1</sup>p

caratteristiche:
* E(X) = 1/p
* Var(X) = (1-p)/p<sup>2</sup>

modella il primo successo dopo una serie di insuccessi

**VA di Poisson**

data una variabile reale r:

X ~ Po(r) se: 

alfabeto:
* X = quante volte l'esito ha probabilmente successo

densità discreta:
* P(X=k) = e<sup>-r</sup>r<sup>k</sup>/k!

caratteristiche:
* E(X) = r
* Var(X) = r

modella il numero di eventi per unità di tempo

**teorema limite di poisson**

una VA binomiale con n >> 1 e p << 1 (quindi tantissime prove dove ogni prova ha una bassa probabilità di successo) può essere approssimata con una VA di poisson con r=n\*p

## vettori aleatori discreti

date 2 VA X e Y, un vettore aleatorio discreto V è una funzione che mappa gli esiti di uno spazio campionario ad una coppia di reali:
* V : omega -> R<sup>2</sup>

quindi:
* V(esito) = (X(esito), Y(esito))

l'alfabeto di V è un sottoinsieme del prodotto cartesiano di X e Y, ci possono essere dei vincoli sulle coppie

**densità discreta congiunta**

indica la probabilità che le 2 VA assumano determinati valori:
* P(X=xi,Y=yj)

proprietà:
* P(X=xi,Y=yj) = 0 se (xi,yj) non appartiene all'alfabeto

**densità marginale**

sono le singole densità delle VA congiunte

* P(X=xi) = j+++ P(X=xi,Y=yj)
* P(Y=yi) = j+++ P(X=xj,Y=yi)

**valor medio:**

* E(g(X,Y)) = i+++ g(xi,yi)P(X=xi,Y=yi)
* E(XY) = i+++ j+++ xiyjP(X=xi,Y=yj)

**indipendenza di VA**

2 VA X ed Y sono indipendenti se:
* P(X=xi,Y=yj) = P(X=xi)P(Y=yj)

proprietà:
* X e Y indipendenti -> f(x) e g(y) indipendenti
* E(XY) = E(X)E(Y)
* Cov(X,Y) = 0 (proprietà di scorrelazione)
* Var(X + Y) = Var(X) + Var(Y)
    * Var(aX + bY + c) = a^2Var(X) + b^2Var(Y)
* indipendenza --> scorrelazione
* scorrelazione -/> indipendenza