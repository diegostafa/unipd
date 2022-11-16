**alberi di decisione**

caratteristiche
* i nodi corrispondono agli attributi
* i gli archi corrispono alle condizioni sui nodi
* ci possono essere più figli
* i figli corrispondono all'esito della condizione
* le foglie sono classi
* un albero rappresenta è una funziona h(x)
* facilmente interpretabile
* ogni livello dell'albero ha un test su una feature
* il nodo a cui arrivi corrisponde alla classe
* solitamente si creano alberi piccoli per non determinare le classi esatte, ma per ricavare informazioni utili

di base traccia delle soglie per ogni feature del dataset
come per il knn i decision boundary sono inferiti

**alberi DNF**

* percorsi verso una foglia rappresentano congiunzioni di test
* percorsi verso una classe rappresentano disgiunzioni di congiunzioni

di base significa che per arrivare ad una foglia devi fare una serie di AND
* test1 AND test2

mentre per arrivarea ad una stessa classe devi fare una serie di OR sulle foglie della stessa classe 
* (test1 AND test2) OR (test3 AND test4)


**costruzioni di un albero**

* problema NP completo
* usa algoritmi grredy con euristica
* solitamente si usa ID3

**ID3**

* S = esempi di training
* A = attributi

algoritmo:
1. crea la radice
2. se S appartiene tutto alla stessa classe
    * ritorna la radice con quella classe
3. se A è vuoto
    * ritorna la radice con la classe di maggior frequenza in S
4. altrimenti
    * scegli il milgior attributo di A per classificare (information gain)
    * dividi S in subset dato dall'attributo ottimale
    * crea un nodo di branching su quell'atribbuto
    * ripeti 1) senza l'attributo scelto

**entropia**

misuara l'incertazza di un dataset, cioè quanto è difficiel predirre un nuovo esempio

in termini probabilistici:
* H(S) = +++ p(c)logp(c)

**information gain**

usa l'entropia per misurare la certezza data una scelta

in termini probabilistici:
* IG =  H(S) - H(S|s)

cioè calcola l'entropia risultante data una scelta

**considerazioni**

* il milgior albero è quello più piccolo possibile che generalizza meglio 
* solitamente si suano meotodi misti con alberi piccoli con tanto information gain
* alberi grandi causano overfitting
* algoritmi greedy non garantiscono ottimalità
* l'inductive bias è quello che privilegia information gain nella scelta dell'attributo
* solitamente si usa una regolarizzazione per penalizzare alnberi troppo profondi

**random forest**

definsce tanti alberi di decisione in parallelo e alla fine si fa una votazione della classe risultante, aggiunge il fattore dicasualità per mitigare il bias