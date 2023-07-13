### Basi di spazi vettoriali

una base B di spazio vettoriale V è un insieme di vettori, tali per cui:
* B è un sistema generatore di V
* B è un insieme di vettori LI

esempi di basi:
* l'insieme formato dai vettori colonna delle matrici identità di rango n è base dello spazio vettoriale di vettori colonna alti n
* l'insieme dei polinomi {1,x,x<sup>2</sup>...x<sup>n</sup>} è una base dello spazio vettoriale di tutte le funzioni di grado minore o uguale a n

**base di uno spazio nullo**

data una matrice A, per trovare una base dello spazio nullo N(A), si risolve prima il sistema omogeneo relativo, Ax=0, cioè si fa una EG su A e si risolve Ux=0, dopo aver trovato tutte le soluzioni (aka lo spazio nullo), si cerca la base, che avrà tanti elementi quanti la dimensione di N(A)

per ottenere il primo vettore della base, si pone a 1 il primo parametro e a 0 i restanti, per il secondo, si pone a 1 il secondo paramentro e a 0 i restanti, e così via

--- 

**teorema 1**

ogni spazio vettoriale **finitamente generabile** ha una base, di base si parte dal fatto che il sistema ha un numero finito di elementi, e attraverso un algoritmo iterativo, si elimina un elemento finchè il sistema non è anche linearmente indipendente

per eliminare gli elementi:
* i vettori nulli sono tutti eliminabili
* i vettori che sono multipli di altri vettori sono tutti eliminabili
* i vettori che nella combinazione lineare == 0 hanno coefficenti != 0

**teorema 2 (equipotenza delle basi)**

ogni base dello stesso spazio vettoriale ha lo stesso numero di elementi, e questo numero è detto **dimensione dello spazio vettoriale**

**terorema di Grassmann**

dati 2 sottospazi U1 e U2, allora:
* dim(U1 + U2) == dim(U1) + dim(U2) - dim(U1 intersecato U2)
* dim(U1 ⊕ U2) == dim(U1) + dim(U2)

**teorema 4**

un insieme generatore che abbia tanti elementi quanti la dimensione dello spazio, è una base

**teorema 5**
 
per verificare che B, formata da vettori colonna alti n, sia una base di K<sup>n</sup> basta verficare che il rango della matrice A formata dai vettori di B, sia uguale ad n

---

### Spazio delle colonne di una matrice

data la matrice A di dimensione mxn a coefficent complessi, si considera lo spazio vettoriale C(A) generato dalle colonne di A <a1,a2...an>, per trovare una base di C(A):
* si trova una forma ridotta U della matrice A
* la base B di C(A) è l'insieme dei vettori colonna di A nelle rispettive posizioni delle colonne dominanti

la dimensione di C(A) è detta **rango della matrice A** e si indica con rk A, di base quindi, il numero delle colonne dominanti di una forma ridotta indica il rango di una matrice

proprietà rango di una matrice:
* rkA == rkA<sup>T</sup> == rkA<sup>H</sup>
* rk(AB) <= rkA
* rk(AB) <= rkB

**teorema nullità + rango**

la dimensione dello spazio nullo di una matrice A == numero dello colonne di A meno il rango di A

cioè il numero delle colonne == numero di colonne libere(nullita) + numero di colonne dominanti(rango) 

in parole povere, la dimensione dello spazio nullo è uguale alla dimensione delle soluzioni del sistem Ax=0, cioè al al numero di colonne libere del forma ridotta

**teorema rouche capelli**

di base è un teorema che riformula i teoremi sulle soluzioni di un sistema lineare usando però la definizione di rango
 
