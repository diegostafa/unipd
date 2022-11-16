### Matrici

concetti base:
* sono tabelle di numeri (coefficenti della matrice)
* sono identificate da una lettera latina maiuscola
* righe e colonne partono da 1
* per rifersi al generico elemento a in posizione i,j della matrice di m righe e n colonne si scrive:
    * (a<sub>ij</sub>), m x n
* la matrice identica è una matrice quadrata con tutti 1 in diagonale

**notazioni**

* M<sub>nxm</sub>(R/C) indica l'insieme delle matrici nxm, a coefficenti reali/complessi
* M<sub>n</sub>(R/C) indica l'insieme delle matrici quadrate di ordine n, a coefficenti reali/complessi
* R/C<sup>n</sup> indica l'insieme dei vettori colonna alti n, a coefficenti reali/complessi
* R/C<sub>n</sub> indica l'insieme dei vettori riga lunghi n, a coefficenti reali/complessi
* i coefficenti di una matrice che risiedono nella diagonale sono detti coefficenti diagonali
* A = diag(d1, d2 .. dn) indica una matrice diagonale, una matrice è detta diagonale se:
    * è quadrata
    * i coefficenti non diagonali sono == 0
* una matrice scalare è una matrice identica moltiplicata per uno scalare
* un vettore coordinato contiene tutti 0, ed un 1 nella posizione i
* e<sub>i</sub> indica un vettore colonna coordinato di lunghezza non specificata
* una matrice si dice triangolare superiore/inferiore, se ha tutti 0 sotto/sopra la diagonale, 

---

**prodotto tra uno scalare**

di base è moltiplicare una matrice per un numero, si moltiplica ogni coefficente della matrice per lo scalare.

data la matrice A: 
* 0 svuota la matrice (A diventa una matrice a coefficenti == 0)
* 1 è l'elemento neutro
* tutto il resto moltiplica normalmente

**somma tra matrici**

la somma tra matrici si può fare solo con matrici dallo stesso numero di righe e colonne, si sommano i coefficenti di egual posizione.

data la matrice A: 
* -A svuota la matrice
* \[\|\|\] elemento neutro
* tutto il resto somma normalmente

**prodotto riga per colonna**

definizioni base:
* matrici di una colonna sola sono detti vettori colonna (indicato da una lettera latina minuscola e sottolineata)
* matrici di una riga sola sono detti vettori riga (indicata allo stesso modo ma con una t in alto a destra)

il prodotto riga per colonna è definito solo se le 2 vettori hanno la stessa lunghezza, ritorna uno scalare

nb: la legge di cancellazione non vale, u\*v<sup>t</sup> = 0 non implica che uno dei due vettori sia uguale a 0

**prodotto tra matrici**

data la matrice A<sub>nxm</sub> e la matrice B<sub>ixj</sub>: 
* il prodotto è definito sse m == i
* la matrice risultante è C<sub>nxj</sub>
* i coefficenti C in posizione generica (n,j) sono calcolati facendo il prodotto della riga n di A e la colonna j di B

di base se si vuole calcolare il coefficente in posizione (3,4) si moltiplica la riga 3 di A con la colonna 4 di B

data la matrice A e supposte le condizioni di esistenza del prodotto: 
* la matrice vuota ritorna una matrice vuota
* la matrice identica è l'elemento neutro
* A\*B != B*\A
* non vale la legge di cancellazione

### operatori unari

di base operatori che si applicano ad una matrice e la modificano:
* trasposizione
* coniugio
* h-trasposizione

**trasposizione di una matrice**

la trasposta della matrice A<sub>nxm</sub> è B<sub>mxn</sub>, i coefficenti B in posizione generica (m,n) sono i coefficenti A in posizione generica (n,m)


``` c++
for(int i = 0 ; i < n; i++)
    for(int j = 0 ; j < m; j++)
        B[j][i] = A[i][j];
```

si indica con: A<sup>T</sup>

proprietà:
* (A<sup>T</sup>)<sup>T</sup> == A
* (k\*A)<sup>T</sup> == k\*A<sup>T</sup>
* (A + B)<sup>T</sup> == A<sup>T</sup> + B<sup>T</sup>
* (A\*B)<sup>T</sup> == B<sup>T</sup>\*A<sup>T</sup>
* A è una matrice simmetrica se A<sup>T</sup> == A
* A è una matrice antisimmetrica se A<sup>T</sup> == -A

**coniugio di una matrice**

la coniugata della matrice A<sub>nxm</sub> è B<sub>nxm</sub>, i coefficenti B in posizione generica (n,m) sono i coefficenti A in posizione generica (n,m) coniugati

``` c++
for(int i = 0 ; i < n; i++)
    for(int j = 0 ; j < m; j++)
        B[i][j] = Coniugato(A[i][j]);
```


si indica con una barra sopra il nome della matrice

proprietà:
* il coniugato del coniugato di A è A
* il coniugato di uno scalare per una matrice è il coniugato dello scalare per il coniugato della matrice
* il coniugato della somma tra due matrici è la somma dei coniugati delle due matrici
* il coniugato del prodotto tra due matrici è il prodotto dei coniugati delle due matrici


**H-trasposizione di una matrice**

di base significa fare sia una trasposizione sia una coniugazione della stessa matrice (o viceversa, prima coniugazione e poi trasposizione)

si indica con: A<sup>H</sup>

proprietà:

* (A<sup>H</sup>)<sup>H</sup> == A
* (k\*A\)<sup>H</sup> == k coniugato \* A<sup>H</sup>
* (A + B)<sup>H</sup> == A<sup>H</sup> + B<sup>H</sup>
* (A\*B)<sup>H</sup> == B<sup>H</sup>\*A<sup>H</sup>
* A è una matrice hermitiana se A<sup>H</sup> == A
* A è una matrice antihermitiana se A<sup>T</sup> -== -A

**matrici invertibili**

di base una matrice quadrata A è invertibile se esiste una matrice quadrata B tale per cui:
* AB == matrice identica (quella con diagonale == 1)
* BA == matrice identica

la matrice B è l'inversa di A e si scrive come A<sup>-1</sup> ed è anche unica.

nb: se A è quadrata: AB == id implica BA == id e B è unica, se A non è quadrata non si può dire nulla.

**condizioni di invertibilità**

1. la sua forma ridotta di gauss ha solo colonne dominanti
2. il determinante è diverso da 0

per calcolare l'inversa di A:
* si scrive la matrice aumentata \[A \| Id\]
* si fa Eg della matrice aumentata e si ottiene \[U \| b\]
    * se U ha delle colonne libere
        * non esiste l'inversa
    * se U ha tutte le colonne dominanti
        * si esegue gauss-jordan su U
        * dopo l'eliminazione si avrà \[Id \| A<sup>-1</sup>\]

**proprietà matrici quadrate**

* (AB)<sup>-1</sup> == B<sup>-1</sup>A<sup>-1</sup>
* (A<sup>-1</sup>)<sup>-1</sup> == A
* (A<sup>T</sup>)<sup>-1</sup> == (A<sup>-1</sup>)<sup>T</sup>
* (A<sup>H</sup>)<sup>-1</sup> == (A<sup>-1</sup>)<sup>H</sup>
