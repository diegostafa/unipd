### Algoritmo di Gauss (o eliminazione di Gauss, EG)

l'algoritmo di gauss trasforma una matrice in una forma ridotta di gauss

una forma ridotta di gauss è una matrice:
* a gradini
* ogni gradino deve essere alto una riga
* ogni gradino inizia con un 1
* la colonna che l'1 identifica è detta dominante, le altre libere
* il numero delle colonne dominanti è detto **rango della matrice**
* sotto i gradini ci sono solo zeri 
* numero di gradini == numero di righe non nulle
* **non unica**


le uniche 3 operazioni lecite nell'algoritmo di Gauss sono:
1. **Ei(c)** --> moltiplica una riga i per uno scalare c diverso da 0 (significa anche dividere)
2. **Eij(c)** --> somma ad una riga i, una riga j moltiplicata per uno scalare c
3. **Eij** --> scambia la riga i con la riga j (Eij == Eji)

l'operazione viene indicata con:

A → <sub>operazione</sub>→ B

esempio gauss: trovare la forma ridotta di A


``` c++
matrice A(3, 3); // la matrice è 3x3

A = { 2 -4 14
      1  3  2
     -1  0 -5 }


E1(1/2) // moltiplica la riga 1 per 1/2

A = { 1 -2  7
      1  3  2
     -1  0 -5 }

E21(-1) // somma alla riga 2 la riga 1 moltiplicata per -1

A = { 1 -2  7
      0  5 -5
     -1  0 -5 }

E31(1) // somma alla riga 3 la riga 1 moltiplicata per 1

A = { 1 -2  7
      0  5 -5
      0 -2  2 }

// --- trovata la prima colonna dominante ---


E2(1/5) // moltiplica la riga 2 per 1/5

A = { 1 -2  7
      0  1 -1
      0 -2  2 }

E32(2) // sommo alla riga 3 la riga 2 moltiplicata per 2

A = { 1 -2  7
      0  1 -1
      0  0  0 }

// --- trovata la seconda colonna dominante ---
```


**non unicità della forma ridotta di gauss**

avviene se:
* è necessario fare scambi di righe
* c'è possibilità di scelta tra diverse operazione di gauss


**EG con matrici parametriche**

nel caso di matrici a coefficenti parametrici, per trovare una forma ridotta si deve andare per casi oppure tentare scambi di righe per togliere il parametro dalla colonna dominante

---

### Eliminazione di Gauss-Jordan

di base consiste fare prima l'EG dall'alto verso il basso e poi l'EG dal basso verso l'alto, in modo tale che ogni 1 di colonna dominante abbia tutti 0 sopra l'1

``` c++

// eliminazione di Gauss

{ 1 -2  3 -3  0  0
  0  0  1  1  2  9
  0  0  0  1  5  5 }

// eliminazione di Gauss-Jordan

{ 1 -2  0  0  0  0
  0  0  1  0  2  9
  0  0  0  1  5  5 }
```