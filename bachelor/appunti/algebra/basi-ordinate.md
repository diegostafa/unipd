### Basi ordinate e coordinate

**base ordinata**

una base ordinata è una base a cui agli elementi viene dato un ordine (primo, secondo, terzo...)

**vettore delle coordinate**

dato uno spazio vettoriale V e una base B ordinata di V. un vettore v di V è individuato univocamente da una combinazione lineare di B e si chiama vettore delle coordinate di v il vettore colonna formato dai coefficenti della combinazione lineare che ottiene v

si indica con C<sub>B</sub>(v) la mappa delle coordinate di V con base B (cioè si indicano le coordinate del vettore v)

proprietà:
* C<sub>B</sub>(v1 + v2) == C<sub>B</sub>(v1) + C<sub>B</sub>(v2)
* C<sub>B</sub>(kv) == kC<sub>B</sub>(v)
* suriettività (ad ogni vettore delle coordinate corrisponde un un vettore dello spazio V)
* iniettività (vettori diversi hanno vettori delle coordinate diversi)

siccome C<sub>B</sub> gode di queste proprietà è un isomorfismo tra V e K<sup>n</sup>


**applicazione lineare**

un'applicazione lineare T è una funzione che conserva la somma e il prodotto tra uno scalare, cioè:
* T(v1 + v2) == T(v1) + T(v2)
* T(kv1) == kT(v1)


**nucleo e immagine di un'applicazione lineare**

il nucleo di un'applicazione lineare T è l'insieme degli elementi di un dominio, applicato T, hanno come immagine lo zero del codominio

si indica il nucleo del dominio su applicazione lineare T con KerT (ker == kernel == nucleo)

l'applicazione lineare è iniettiva sse il nucleo del dominio è formato solo dallo 0

nb: il nucleo è un sottospazio vettoriale del dominio

**applicazione lineare indotta da una matrice**

l'applicazione lineare indotta da una matrice è una funzione che data una matrice A<sub>mxn</sub> e un vettore colonna alto n, definisce A\*v1, cioè ottiene un vettore colonna alto m

il nucleo di LA è l'insieme dei vettori tali per cui:
* Av1 = 0 --> cioè lo spazio nullo della matrice

si dimostra anche che l'immagine di LA è un vettore appartenente al sottospazio generato da i vettori colonna di A

infatti
1. Av1
2. A\[v1,v2...vn\]
3. A(v1\*id1 + v2\*id2 +...+ vn\*idn) //scrivo il v1 come combinazione lineare delle colonne della matrice identica
4. Av1\*id1 + Av2\*id2 +...+ Avn\*idn //proprietà distributiva
5. v1Aid1 + v2Aid2 +...+ vnAidn // porto fuori lo scalre v
6. v1a1 + v2a2 +...+ vnan // il prodotto tra matrice e colonna identica == colonna della matrice
7. <a1,a2...an> è un sistema generatore 


**matrice associata rispetto alle basi ordinate**

dati gli spazi V e W con basi ordinate B e D e un'applicazione lineare T, si definisce la matrice A come:
* A { C<sub>D</sub>(T(b)) }

cioè le colonne di A sono le coordinate di D applicate a T(b)


```c++

// come ottenere la matrice associata

B = { b1, b2, b3, b4}
D = { d1, d2}

// si applica T su ogni elemento di B
w1 = T(b1)
w2 = T(b2)
w3 = T(b3)
w4 = T(b4)

// per definizione di base riscrivo i valori ottenuti

w1 = a11*d1 + a21*d2
w2 = a12*d1 + a22*d2
w3 = a13*d1 + a23*d2
w4 = a14*d1 + a24*d2

// matrice associata
A = { a11 a12 a13 a14
      a21 a22 a23 a24 }

// oppure

A = { C(T(b1)), C(T(b2)), C(T(b3)), C(T(b4)) }

// la matrice ha dim(D) righe e dim(B) colonne
```

**Matrice di passaggio tra basi**

è una matrice quadrata e invertibile che permette di effettuare il passaggio da una base di uno spazio vettoriale a un'altra base dello stesso spazio vettoriale

di base è la matrice associata solo che le basi appartegono allo stesso spazio vettoriale e la funzione T è la funzione identica

cioè la matrice A ha come colonne le coordinate rispetto ad una base di ogni elemento della l'altra base

la matrice che passa dalle coordinate B' a B si indica con:
*  M<sub>B<--B'</sub>

la matrice che passa da B a B' si indica con:
*  M<sup>-1</sup><sub>B<--B'</sub>
