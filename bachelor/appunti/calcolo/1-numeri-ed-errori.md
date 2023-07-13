**rappresentazione dei reali**

un reale è definito da:
* parte intera --> numero naturale
* parte frazionaria --> numero reale \[0,1\]

un numero in base b lo si può indicare come somma delle cifre moltiplicate per la base elevata alla sua posizione

es: 
* 12,4 in b=10 --> 1\*10 + 2\*1 + 4*0.1

**troncamento**

il troncamento di un reale di k cifre è dato da:
* parte intera + prime k cifre della parte frazionaria

il troncamento aprossima un intorno destro con errore massimo di 1/base<sup>k</sup>

**arrotondamento**

l'arrotondamento di un reale alla k-esima cifra è dato da:
* parte intera + prime k-1 cifre della parte frazionaria + k-esima cifra arrotondata per eccesso/difetto

l'arrotondamento aprossima un intorno circolare con errore massimo di 1/2b<sup>k</sup>

l'arrotondamento di un numero x si indica con fl(x)

**errore assoluto**

è il valore assoluto della differenza tra un valore e la sua approssimazione

**errore relativo**

L’errore relativo è l’errore assoluto su una quantità, pesato dalla grandezza della quantità

è quindi l'errore assoluto diviso il numero reale

l'errore relativo sull'approssimazione di un numero x viene indicato con:
* epsilon<sub>x</sub>

**stima dell'errore**

la stima consiste nel risolvere la disequazione:
* |x - xj| < b<sup>-n</sup>

**virgola mobile**

di base è la notazione scientifica, ogni reale scritto in forma convenzionale, si può riscrivere come:
* 0.mantissa * b<sup>p</sup>

dove:
* mantissa --> parte intera e parte frazionaria
* p --> numero di cifre prima della

**reali macchina**

sono i numeri reali rappresentati in virgola mobile con una mantissa di lunghezza limitata definita dalla macchina, l'errore di questi arrotondamenti è influenzato dalla lunghezza della  mantissa

**precisione di macchina**

si indica con epsilon<sub>M</sub> ed è l'errore relativo più grande di arrotondamento della macchina, ogni reale approssimato ha un errore relativo non superiore alla precisione macchina

**aritmetica macchina**

indicate con:
* ⋆ --> operazione aritmetica
* ⍟ --> operazione aritmetica macchina

dati 2 reali x e y, l'operazione macchina associata si indica con:
* x ⍟ y = fl( fl(x) ⋆ fl(y) 

di base si esegue l'operazione aritmetica tra gli arrotondamenti e poi si arrotonda il risultato

**stabilità dell'aritmetica macchina**

un operazione macchina è stabile se l'errore sul risultato ha lo stesso ordine di grandezza della precisione macchina 

le operazioni macchina stabili sono:
* prodotto
* divisione
* radice
* reciproco
* addizione (somma algebrica a segni concordi)
* integrale

le operazioni macchina instabili sono:
* sottrazione (somma algebrica a segni discordi)
* derivazione

la sottrazione amplifica l'errore tanto più quando i 2 numeri sono molto vicini tra loro

**indice di condizionamento**

data una funzione macchina f ed un numero x, l'indice di condizionamento indica l'errore di f(x):
* cond(x) = (|f'(x)|*|x|) / |x|

da cui:
* cond(x) molto grande --> f(x) instabile
* cond(x) molto piccolo --> f(x) stabile

quindi una f(x) è instabile se:
* lim<sub>x->x0</sub> cond(x) = +inf 

**costo computazionale degli algoritmi numerici**

è influenzato da due parametri:
* numero di floating point operations (FLOPS) --> machine indipendent
* tempo di calcolo --> machine dependent

il tempo di calcolo è influenzato da:
* velocità del processore (petaflops/exaflops...)
* velocità di accesso alla memoria