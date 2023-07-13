## Matlab

caratteristiche:
* le variabili non si dichiarano, si assegnano e basta
* ogni scalare è una matrice 1x1


**definizione matrice**

* con scalari  --> A = [a1 a2 a3 ; b1, b2, b3]
    * lo spazio/virgola delimita una colonna, il ; le righe
    * lunghezza delle righe deve essere sempre la stessa
* con vettori --> A = [v1 ; v2 ; v3]
    * v1 e v2 devono avere la stessa dimensione

**operatori**

* operazioni base:
    * +
    * -
    * *
    * /
    * ^
    * ' --> trasposta
* A:C:B
    * genera un vettore di valori da A (incluso) a B (possibilmente escluso) con passo C
    * default passo 1 --> 1:20 sono i numeri da 1 a 20
    * es v = 1:2:10 --> 1 3 5 7 9
* v1 .OP v2 --> esegue OP come operazione componente per componente di v1 e v2, solo se v1 e v2 hanno stessa dimensione

**accesso matrici**

* per indici A[i,j] --> elemento in pos i,j
* per vettore A[v1,v2] --> lista di elementi intersecati dalle righe specificate da v1 con le colonne specificate da v2
* tutto A[:,:]
* ritorna colonna j A[:,j]
* ritorna riga i A[i,:]

**funzioni matriciali**

* zero(m,n) --> ritorna matrice mxn con tutti 0
* ones(m,n) --> ritorna matrice mxn con tutti 1
* eye(n) --> ritorna matrice identità nxn
* diag(v) --> ritorna una matrice che ha per diagonale il vettore v e tutti 0
* diag(m) --> ritorna il vettore diagonale della matrice m
* plot(v1,v2, s) --> disegna i punti (v1,v2) solo se v1 e v2 hanno stessa lunghezza, s è una stringa per la formattazione del grafico
    * s="r:s" --> linea rossa, punteggiata, con i punti del grafico quadrati
* linespace(A,B,C) --> ritorna vettore di C punti da A a B (inclusi)

**I/O**

* var = input("prompt: ") --> ritorna l'espressione valutata in input

**if-else-**

```
if <test>
    <istruzioni>
<end>

if <test>
    <istruzioni>
elseif <test>
    <istruzioni>
else
    <istruzioni>
end
```

**for**

```
for i = v
    <istruzioni>
end
```

NB: i assume ogni valore di v, come il foreach di c#

**while**

```
while <test>
    <istruzioni>
end
```

**funzioni lambda**

```
nome = @(in1, in2 ...) [out1, out2 ...]

```

NB: si può usare un vettore per la lista di parametri


**figure**

* figure(n) --> n è necessario, indica una figure n
* plot --> disegna e sovrascrive sulla figure n definita
* hold on --> se prima di figure non fa sovrascrivere
* hold off --> annulla hold on
* title(s) --> setta il titolo a s
* legend(s1,s2..., "loacation", "<loc>") --> legenda per ogni grafico stampato nel relativo ordine nel luogo (opzionale) specificato (north-west, north-east...)
* savefig(f) --> salva la figura nel disco
* openfig(f) --> apre una figura salvata
* closefig(n) --> chiude la figura di indice n 
**m-function**


```
function [out1,out2 ...] = nome(in1,in2 ...)
% commenti visualizzati nell'help
% scopo della funzione
% input:
%   in1 tipo --> ....
%   in2 tipo --> ....
%   ... tipo --> ....
% output:
%   out1 tipo --> ...
%   out2 tipo--> ...
%   ... tipo --> ...
corpo
end
```

funzione contenuta in un file separato

* implementa un algoritmo
* nome funzione == nome file
* le funzioni vedono solo le variabili che loro definiscono
* ogni out deve essere calcolato
* l'help vuole:
    * scopo della funzione
    * descrizione e vincoli sugli input e output
* nargin --> numero di tutti gli input (utile al chiamato)
* nargout --> numero di tutti gli output (utile al chiamante)
* varargin --> vettore di input opzionali
* varargout --> vettore di output opzionali

implementazioni:
* bisezione
* bisezione con residuo pesato
* newton
* newton con secanti

## Zeri e punti fissi

**teorema di cacioppoli**

se x ed f(x) in a,b ed il sup f(x) < 1, allora esiste un unico pt. fisso ni a,b

## Interpolazione

**esistenza ed unicità interpolazione punti**

dati n punti, esiste ed è unico il polinomio interpolatore di grado al più n sui quei punti

**esistenza ed unicità interpolazione di funzione**

analogalmente, dati n campionamenti di una funzione, esiste ed è unico il polinomio interpolatore sui campionamenti

**interpolazione**

operazione lineare, va da un'insieme n di punti ad un polinonio che giace nello spazio vettoriale dei polinomi di ordine n

**sistema di vandermonde**

fissata una base dello spazio vettoriale, per esprimere il vincolo di interpolazione (la funzione calcolata in xi == yi) si può usare il sistema di vandermonde:
```
|b0{x0} b1{x0} .... bn{x0}||c0|   |y0|
|b1{x1} b1{x1} .... bn{x1}||c1|   |y1|
|...... ...... .... ......||..| = |..|
|bn{x0} b1{xn} .... bn{xn}||cn|   |yn|

bi{xi} --> significa calcolare x sulla base b, quindi se la base è 1,x, x^2 ... x^i significa fare (xi)^i

c --> colonna dei coefficenti da trovare del polinomio
```

**interpolazione di lagrange**

dal sistema di vandermonde lagrange ricava il polinomio interpolante esplicito su cui si può anche effettuare la stima dell'errore


**polyfit**

```
c = polyfit(x,y,n) 

c --> vettore dei coefficenti dell'interpolatore
x --> vettore dei nodi
y --> vettore dei valori dei nodi
n --> vettore della base canonica, ordinato in modo decrescente
```

**polyval**

```
y = polyval(c,x) 

c --> vettore dei coefficenti del polinomio su base canonica ordinata in modo decrescente
x --> vettore dei nodi da calcolare
y --> vettori dei nodi calcolati
```
note
* polyfit polyval sono fatti per interpolare/valutare funzioni di grado basso
* polyfit molto instabile su problemi mal condizionati


**interpolazione ai minimi quadrati**

è come interpolazione lineare, ma si considera uno spazio vettoriale di grado <= al numero di punti

se V è la matrice di vandermonde di questo sistema, allora i coefficenti del polinomio sono la soluzione di:
* V'Va = V'y

## Quadratura

**formula dei trapezi**

approssimazione del calcolo dell'integrale definito di una funzione, si divide la funzione in sottointervalli e si fa la sommatoria delle loro aree calcolate come l'area di un trapezio

**soluzioni sistemi triangolari invertibili**

se U è una matrice invertibile e triangolare superiore allora la soluzione di Ux = b è:
* x[n] = b[n] / U[n,n]
* x[n-k] = n[n-k] / +++ U[n-k, n-k+j] + jx[n-k+j] / U[n-k, n-k]


**eliminazione gaussiana**

se A è una matrice quadrata invertibile, allora:
* [L U P] = lu(A)

calcola:
* L --> triangolare inferiore di A
* U --> triangolo superiore di A
* P --> permutazione

tali per cui:
* LU = PA 


di base fa la fattorizzazione di A

**soluzione sistemi quadrati invertibili**

data A matrice quadrata invertibile, per risolvere Ax=b:
* si calcola la fattorizzazione di A
    * LU = PA
* si risolve la triangolare invertibile Ly = Pb
* si risolve la triangolare invertibile Ux = y

**soluzione dei sistemi lineari**

backslash risolve il sistema

```
x=A\b
```


**norme matriciali**

* norm(A) --> calcolala norma 2
* norm(A, 1) --> calcola la norma 1
* norm(A, Inf) --> calcola la norma infinito

**soluzione ai minimi quadrati di sistemi sovradeterminati**

data A matrice con più righe che colonne, con rango == numero di colonne, allora:
* x = (A'A)^-1