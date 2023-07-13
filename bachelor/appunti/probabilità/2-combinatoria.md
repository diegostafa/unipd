**principio fondamentale del conteggio**

di base è il prodotto cartesiano su insieme senza elementi duplicati,
* A ha 10 elementi
* B ha 20 elementi
* C ha 5 elementi
* allora 10\*20\*5 conta il numero di possibili combinazione di elementi di A, B e C

funziona se e solo se sequenze distinte di scelte individ uano combinazione diverse

**numero di sottoinsiemi**

dato un insieme di N elementi, il numero di possibili sottoinsiemi è:
* 2<sup>N</sup>

si crea una stringa di N bit associano ad ogni elemento 0 o 1, quindi il numero di possibili combinazioni e 2<sup>N</sup>

### Disposizioni

dato un insieme di N elementi, una disposizione indica un insieme ordinato posizionalmente di k elementi, con o senza elementi ripetuti

**Disposizioni con ripetizioni**

scelgo tra n elementi, k volte
* n<sup>k</sup>

**Disposizioni senza ripetizioni**

le ripetizioni non sono ammesse, quindi ad ogni scelta si rimuove un elemento dalla scelta, questo procedimento si fa k volte, quindi:
* n(n-1)(n-2)...(n-k+1)

se k = n la disposizione prende il nome di permutazione

### Combinazioni

dato un insieme di N elementi, una combinazione indica un insieme NON ordinato posizionalmente di k elementi, con o senza elementi ripetuti

**Combinazioni con ripetizioni**

non consideriamo questo caso

**combinazioni senza ripetizioni**

si fa una disposizione senza ripetizioni, e si eliminano le permutazioni che tengono conto dell'ordinamento, quindi
*  n(n-1)(n-2)...(n-k+1) / k! --> coeff. binomiale N su K

**relazione tra disposizione e combinazione**

siccome manca la condizione di ordine, il numero di combinazioni è SEMPRE minore di quello delle disposizioni

nelle disposizioni è come se ad ogni elemento del vettore venga assegnata una posizione quindi (nel caso di un alfabeto) se si scelgono 5 lettere, u2 possibili disposizioni sono:
* A1, A2, A3, T4, v%
* A1, A2, A3, T4, v%

nel caso delle combinazioni manca l'indice di ordinamento, quindi quelle 2 sono uguali