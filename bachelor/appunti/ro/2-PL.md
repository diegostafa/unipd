# programmazione matematica

sono problemi di ottimizzazione descritti da:
* min/max f(x) = z, cioè minimizzare il valore di z
* x in S

dove:
* S = R^n (descritto dal sistema di disuguaglianze)
* x = (x1,x2..xn)
* f = f(x1,x2..xn) --> funzione obiettivo

proprietà;
* min f(x) = max -f(x)

classificazione per f:
* PO lineare --> f(x) e vincoli lineari
* PO non lineare

classificazione per S:
* PO continua --> x a componenti reali
* PO discreta --> x a componenti interi
* PO mista --> sia reali che interi

soluzioni:
* inamissibile --> S è vuoto
* illmitato --> lim f(x) --> -inf
* ottima --> esiste xi tale che f(xi) <= f(x)

classificazione vincoli sulla soluzione x:
* soddisfatto --> x rispetta la disuguaglianza
* attivo --> x rispetta l'uguaglianza
* violato --> non soddisfatto o attivo
* ridondante --> il vincolo è superfluo a S

categorie di problemi:
* allocazione ottima delle risorse
* miscelazione
* trasporto

## programmazione lineare

**richiami algebrici**

* un vettore è inteso come vettore colonna
* un vettore riga è un vettore colonna trasposto
* un sistema di equazioni si può rappresentare nella forma Ax=b
* il prodotto di 2 vettori è la somma del prodotto delle componenti
* il rango di una matrice è il numero di righe o colonne linearmente indipendenti
* un riga è linearmente indipendente se non può essere ricavata dalla combinazione lineare delle altre righe
* una matrice quadrata è invertibile se AB = Identità
* una matrice è invertibile se tutte le righe sono linearmente indipendenti
* Ax = b ha soluzioni solo se il rk(A)=rk(A|b)
* operazioni di gauss sulle righe
    * scambiare righe
    * moltiplicare per scalari non nulli
    * sottrarre righe ad altre righe
* una base è la sottomatrice quadrata di rango massimo
* determinante = 0 vuol dire che ci sono righe/colonne linearmente dipendenti
* una base si dice adiacente ad un'altra base se differiscono al più di una colonna

**PL (programmazione lineare)**

è un problema di pottimizzazione nella quale compiaiono solo espressioni lineari, cioè:
* f.o. = min/max espressione lineare
* s.t. = insieme di disequazioni lineari

**rappresentazione geometrica**

definizioni chiave:
* un insieme è convesso se dati due punti interni all'insieme, il segmento che li congiunge è anch'esso interno
* l'intersezione di insiemi convessi è un'insieme convesso
* dati 2 punti x e y, allora la loro combinazione convessa è:
    * ax + (1-a)y con 0 <= a <= 1
* la combinazione convessa identifica il segmento che congiunge 2 punti
* data una combinazione convessa di x,y allora z è combinazione convessa stretta se z appartiene al segmento che li congiunge, qundi se:
    * z = ax + (1-a)y per un qualche a
* regione identificata da:
    * ax <= b
    * ax >= b
* ogni iperpiano è un'insieme convesso
* è l'intersezione di un numero finito di iperpiani
* x è un vertice di un poliedro sse non esiste un segmento che contenga x

**teorema fondamentale della programmazione lineare**

dato un problema PL, una sola delle seguenti è risulta vera:
* è inammissibilie --> non ha soluzioni
* è illmitato --> non ha soluzioni ottime
* ammette soluzioni ottime e si trova nei vertici

**PL in forma standard**

la forma standard trasforma un problema PL affinchè si abbia:
* min cx
* Ax = b
* x >= 0

di base:
* la funzione obiettio deve esser di minimo
* i vincoli si trasformano in uguaglianze aggiundendo variabili
* tutte le variabili devono essere vincolate >= 0 
* ogni termine noto deve essere positivo

```
f.o.
max 5(-3x1 + 5x2 - 7x3) + 34

s.t.
-2x1 + 7x2 + 6x3 - 2x1 <= 5
-3x1 + x3 + 12 >= 13
x1 + x2 <= -2
x1 <= 0
x2 >= 0

/// forma standard
f.o.
min -3x1' - 5x2 + 7(x3' - x3'') // moltiplico per -1, tolgo costanti additive e moltiplicative

s.t.
4x1' + 7x2 + 6(x3' - x3'') + s1 = 5 // aggiungo lo slack
3x1' + x2 + 12 - s2 = 1 // tolgo il surplus
x1' - x2 - s3 = 2 // moltiplico per -1 per avere i termini noti positivi

x1' >= 0 // x1 = -x1'
x2 >= 0
x3' >= 0 // x3 = (x3' - x3'')
x3'' >= 0
s1 >= 0
s2 >= 0
s3 >= 0

```

**vertice poliedro standard**

il vettore x è un vertice di P sse prese le colonne di A in posizione dei valori non nulli di x, sono linearmente indipendenti

dato:
* x = {3,0,25,2,0}

allora:
* x è vertice di P se le colonne {1,3,4} sono linearmente indipendenti
* se x è vertice allora il # delle sue componenti positive deve essere <= m

esempio:
```
P = {
    3x1-2x2+x3+x4-x5+4x6 = 6
    2x1+2x3-x4+2x5+x6 = 5
    -x1-4x2+3x3+2x4+x5+3x6 = 7
    x >= 0
}

x' = (2,1,1,1,0,0) è un vertice?

1. si verifica che x' appartenga a P
    1.1. verifica che x' abbia solo componenti >= 0 e che la sostituzione rispetti l'uguaglianza

2. prendo le colonne in posizione delle componenti non nulle di x'
    2.2. (1,2,3,4)

3. verifico la loro lineare indipendenza
    3.1. verifico che il numero di colonne sia <= alle righe
        3.1.2. falso --> non è un vertice

```