**tipo 1**

bisogna risolvere un sistema di congruenze, nella forma:

* a<sub>1</sub>x = c<sub>1</sub> mod m<sub>1</sub>
* a<sub>2</sub>x = c<sub>2</sub> mod m<sub>3</sub>

risoluzione:
1. si verfica che il sistema abbia soluzioni esi semplifica
    * si trova d<sub>1</sub> = mcd(a<sub>1</sub>,m<sub>1</sub>)
    * si trova d<sub>2</sub> = mcd(a<sub>2</sub>,m<sub>2</sub>)
    * se d<sub>1</sub> non divide b<sub>1</sub> o d<sub>2</sub> non divide b<sub>2</sub> 
        * il sistema non ha soluzioni
2. si risolvono le due congruenze (si trovano le loro classi)
    * trovo q = b/d
    * pongo d = ia + jb e trovo i
    * trovo la soluzione particolare x<sub>0</sub> = i*q
    * trovo la soluzione generale \[x<sub>0</sub>\]m
3. si usa il teorema cinese dei resti
    * si usa il metodo di newton o lagrange (solo con 2 congruenze)
        * 

**tipo 2**

bisogna risolvere 3 sistemi lineari, nella forma:

* Ax = b

nei 3 casi:
* il sistema ha soluzioni
* il sistema non ha soluzioni
* il sistema ha infinite soluzioni

**tipo 3**

bisogna risolere un sistema lineare parametrico, nella forma:

* A(α)x = b(α)

le EG si fanno per casi

**tipo 4**

bisogna trovare l'inversa di una matrice parametrica, della forma:
* A(α)

risoluzione:
1. si fa la forma ridotta di gauss sulla matrice matrice aumentata A\|id
2. si fa la forma di gauss jordan

**tipo 5**

bisogna verficare un sottospazio e un sistema i generatori di esso

dati W e S e uno spazio vettoriale V dimostra:
* W è un sottospazio di V
* S è un insieme di generatori di W

risoluzione pt. 1:
1. si dimostra che il vettore nullo appartiene a W
2. si dimostra che w1 + w2 appartiene a W
3. si dimostra che kw1 appartiene a W

risoluzione pt. 2:
1. si verifica che S appartenga a W
2. si scrive il generico vettore di W come combinazione lineare di S
3. si risolve il sistema lineare associato
    * il sistema deve avere almeno una soluzione

**tipo 6**

bisogna verificare che un insieme di vettori sia linearmente (in)dipendente

risoluzione:
1. si pone la generica combinazione lineare == 0
2. si risolve il sistema lineare associato
3. la forma ridotta ha tutte colonne dominanti?
    * si --> LI
    * no --> LD

**tipo 7**

bisogna verficare che un insieme di vettori colonna sia linearmente (in)dipendente

risoluzione:
1. si crea la matrice formata dai vettori colonna
2. si trova una forma ridotta
3. la forma ridotta ha tutte colonne dominanti?
    * si --> LI
    * no --> LD

**tipo 8**

bisogna trovare una base da un insieme di generatori

risoluzione:
1. si eliminano i vettori nulli
2. si eliminano i vettori multipli
3. si pone la generica combinazione lineare == 0
4. si risolve il sistema lineare associato
3. la forma ridotta ha tutte colonne dominanti?
    * si --> l'insieme è una base
    * no
        * si trova una soluzione particolare del sistema
        * si elimina un vettore LD
        * step 4

**tipo 9**

bisogna trovare il rango di una matrice parametrica e una base del suo spazio delle colonne

risoluzione:
1. si trova una forma ridotta della matrice
2. il rango corrisponde alle colonne dominanti
3. la base corrisponde ai vettori colonna nelle posizioni delle colonne dominanti

**tipo 10**

bisogna trovare una base dello spazio nulla di una matrice

risoluzione:
1. si risolve il sistema lineare associato
2. per trovare i vettori della base, si crea un vettore dalla soluzione generale del sistema ponendo un parametro == 1, ed i restanti == 0

**tipo 11**

bisogna determinare la matrice associata ad un'applicazione lineare su basi del dominio e codominio

risoluzione:
1. si applica l'applcazione lineare su ogni elemento della base del dominio
2. la matrice associata ha per colonne i vettori colonna delle coordinate su base D dei precedenti vettori
3. per trovare i vettori delle coordinate
    * si scrive la generica combinazione lineare di D sui vettori
    * si risolve il sisteme lineare

**tipo 12**

bisogna calcolare la matrice di passaggio tra 2 basi di uno stesso spazio

la risoluzione è uguale al tipo 11, solo che l'applciazione lineare è la funzione identica, quindi si fanno solo step 2, 3

**tipo 13**

bisogna trovare una base ortonormale di un sottospazio generato V

risoluzione:
1. si trova una base qualunque di V, con lo spazio delle colonne
2. si trova una base ortogonale applicando gram shcmidt sulla base trovata
3. si normalizza la base trovata

**tipo 14**

bisogna trovare il complemento ortogonale di un sottospazio W e calcolare la proieizione ortogonale di un vettore su W

risoluzione pt. 1:
1. creo la matrice dei vettori colonna di W
2. ne faccio l'h-tasposta
3. trovo lo spazio nullo == complemento ortogonale

risoluzione pt. 3:
1. si trova una base di W
2. si trova una base ortogonale applicando gram shcmidt sulla base trovata
3. si normalizza la base trovata
4. la proiezione ortogonale del vettore su base è la somma dei prodotti scalari tra la base ed il vettore che moltiplicano la base

**tipo 15**

bisogna verificare quando una matrice parametrica è NON singolare

risoluzione:
1. si calcola il determinante della matrice
2. lo si pone != 0

**tipo 16**

bisogna calcolare autovalori, molt. algebriche/geometriche e basi dei loro autospazi

risoluzione:
1. si calcola il polinomio caratteristico della matrice
2. si risolve l'equazione caratteristica
3. si trovano gli autovalori e molt. algebriche
4. si trova l'autospazio di ogni autovalore
5. si trova la dimensione dell'autospazio == molt. geomtrica
6. si trova una base ponendo un parametro == 1 e i restanti == 0


**tipo 17**

bisogna verificare quando una matrice parametrica è diagonalizzabile, calcolare una sua diagonalizzazione e una sua potenza

risoluzione:
1. si calcolano gli autovalori
2. si trovano le molteplicità
    * quella algebriva --> quante volte annulla l'equazione caratteristica
    * quella geometrica --> dimensione dello spazio nullo
3. se sono uguali diagonalizzabile, altrimenti no
4. si trova la diagonale
    * matrice diagonale che ha gli autovalori nella diagonale
5. si trova la S
    * matrice che ha per colonne gli elementi della base dell'autospazio
6. si calcola la potenza
    * si calcola la poteza della matrice diagonale
    * la si moltiplica per S e S<sup>-1</sup>



**tipo 18**

pt 1: 
bisogna determinare quando una matrice parametrica con parametro non negativo, è diagonalizzabile

pt 2: 
bisogna determinare quando è unitariamente diagonalizzabile 

pt 3:

pt 4:
