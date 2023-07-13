### **Concetto di Serie**

Definizioni necessarie:

* successione --> sono termini definiti da una formula (aka funzione di dominio naturale)
* sommatoria di una successione --> è la somma dei primi K termini di una successione

**serie** --> è la sommatoria di una successione quando K tende a +infinito

si indica una serie scrivendo S<sub>n</sub>

### **Segno di una serie**

Il segno di una serie (aka sommatoria di una successione) dipende ovviamente dalla successione, infatti:

* S<sub>n</sub> è di segno costante se i termini della successione hanno tutti lo stesso Segno

quindi:

* S<sub>n</sub> positiva se i termini della successione sono tutti > 0 per ogni N
* S<sub>n</sub> è negativa se i termini della successione sono tutti < 0 per ogni N
* S<sub>n</sub> definitivamente positiva se i termini della successione sono tutti > 0 per ogni N > n0
* S<sub>n</sub> è definitivamente negativa se i termini della successione sono tutti < 0 per ogni N > n0


### **Carattere di una serie**

le serie possono:
1. divergere a +infinito
2. divergere a -infinito
3. convergere semplicemente
4. convergere assolutamente --> convergenza semplice
4. è indeterminata


<br>
<br>

### **proprietà di una serie**

1. se una serie è di segno costante (aka positiva o negativa) allora la serie **NON** può essere indeterminata

nello specifico:

una serie (definitivamente) positiva può solo convergere o divergere positivamente
una serie (definitivamente) negativa può solo convergere o divergere negativamente

NB: per determinare il segno di una serie basta porre a<sub>n</sub> > 0

### **Tipi di serie**

il tipo di una serie dipende anch'esso dalla successione, si hanno 3 casi:

* serie geometrica
* serie telescopica
* serie armonica

dal tipo riusciamo a ricavarne il carattere

**serie geometrica**

una serie è geometrica se la successione si presenta nella forma:

q<sup>k</sup>

* con q un qualsiasi numero reale
* con k un qualsiasi numero naturale

CARATTERE

- se q > 1 la serie diverge positivamente
- se q = 1 la serie diverge positivamente
- se \|q\| < 1 la serie converge a L = (1 - q<sup>n+1</sup>)/(1 - q)
- se q < -1 la serie è indeterminata

**serie telescopica**

una serie è telescopica se la successione si presenta nella forma:

a<sub>n</sub> - a<sub>n+k</sub>

* con k un qualsiasi numero naturale

CARATTERE

- converge sempre a L = a<sub>1</sub> + ... + a<sub>k</sub>

(aka converge alla sommatoria dei primi k termini della successione)

**serie armonica generalizzata**

una serie è armonica se la successione si presenta nella forma:

1/(n<sup>a</sup> * log(n)<sup>b</sup>

* con a un qualsiasi numero reale
* con b un qualsiasi numero reale

CARATTERE

- se a < 1 la serie diverge positivamente
- se a > 1 la serie converge

- se a = 1 e b <= 1 la serie diverge positivamente
- se a = 1 e b >1 la serie converge

**criteri per lo studio di serie a segno costante**
* criterio del rapporto
* criterio della radice
* criterio del confronto

**criteri per lo studio di serie a segni alterni**
* criterio di dirichelet
* criterio dell'integrale

<br>
<br>

---------------------------------------------------------------

condizione **NECESSARIA** per la convergenza di una serie:

limite a<sub>n</sub> = 0

---------------------------------------------------------------

<br>
<br>


### **criterio del rapporto**

di base fai il limite del rapporto tra a<sub>n+1</sub> / a<sub>n</sub>

* L > 1 --> la serie diverge positivamente
* L < 1 --> la serive converge
* L = 1 --> nulla si può dire

### **criterio della radice**

di base fai il limite della radice ennesima di a<sub>n</sub> della successione

* L > 1 --> la serie diverge positivamente
* L < 1 --> la serive converge
* L = 1 --> nulla si può dire

### **criterio del confronto asintotico**

di base fai il limite del rapporto tra a<sub>n</sub> e una successione b<sub>n</sub>

* L = 1 --> a<sub>n</sub> ha lo stesso carattere di b<sub>n</sub>

NB: b<sub>n</sub> lo scegliamo noi, solitamente si sceglie una successione di cui sappiamo già il carattere


### **criterio del confronto**

Ipotesi

* a<sub>n</sub> < b<sub>n</sub> definitivamente

Tesi:

* se b<sub>n</sub> converge --> a<sub>n</sub> converge
* se a<sub>n</sub> diverge --> b<sub>n</sub> diverge


<br>
<br>

### **criterio di Dirichelet**

Ipotesi

* a<sub>n</sub> --> decrescente e infinitesima
* b<sub>n</sub> --> somme parziali limitate (aka S<sub>bn</sub> < \|M\|

Tesi:

* La serie del prodotto tra a<sub>n</sub> e b<sub>n</sub> è convergente

<br>
<br>

### **criterio dell'integrale**

Ipotesi

* f(x) --> funzione decrescente e infinitesima
* f(n) = f(x) con x appartenente ai naturali

Tesi:

* la serie di f(n) converge se e solo se l'integrale di f(x) converge

# **Studio del carattere di una serie**

di base ci sono 2 tipi di serie, a segni alterni e a termini positivi (se è a termini negativi basta portare fuori il segno meno dal simbolo di sommatoria)

**studio di serie a segni alterni**

1. si impone la condizione necessaria di convergenza
2. se non la rispetta allora non può convergere
