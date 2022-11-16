# Notazione asintotica

**notazione 𝜃(𝑔(𝑛))**

Una funzione f(n) appartiene a 𝜃(𝑔(𝑛)) se esistono due
costanti c1 e c2 tali che f(n) possa essere racchiusa tra
c1g(n) e c2g(n).

cioè f(n) cresce almeno quanto c1g(n) e al massimo quanto c2(gn), quindi:
* c1g(n) <= f(n) <= c2g(n) 

**notazione O(𝑔(𝑛))**

f(n) cresce al massimo come cg(n), quindi:
* f(n) <= c2g(n) 

oppure:
* lim f(n) / g(n) = 0

**notazione Ω(𝑔(𝑛))**

f(n) cresce al massimo come cg(n), quindi:
* c1g(n) <= f(n)

oppure:
* lim f(n) / g(n) = +inf

# Analisi degli algoritmi

**complessità**

è il numero di operazione che l'elaboratore compie su input n
se
< k^n < n!

**algoritmi iterativi**

per calcolare la complessità degli algoritmi iterativi basta sommare le complessità delle singole istruzioni e moltiplicare quella dei cicli annidati

**algoritmi iterativi**

la complessità degli algoritmi ricorsivi è data dalla loro formula di ricorrenza

**equazione di ricorrenza**

si indica con T(n), descrive formalmente come viene eseguita la ricorsione, la soluzione di un'equazione di ricorrenza è la complessità dell'algoritmo

di base indica la complessità su input n, attraverso una scrittura ricorsiva


**metodo di sostituzione**

si cerca ad occhio di capire la complessità e si dimostra che l'equzione di ricorrenza la rispetta, ci sono 3 casi:
1. T(n) = O(f(n)) --> T(n) <= c*f(n)
2. T(n) = Ω(f(n)) --> T(n) >= c*f(n)
3. T(n) = 𝛩(f(n)) --> T(n) <= c1\*f(n) e  T(n) >= c2*f(n)

funzionamento:
1. si ottiene la disequazione dai casi sopra
2. si sostituisce T(n) con c*f(n) su argomento di T
3. si risolve la disequazione su c

esempio 1:

dati:
* T(n) = T(n/2) + T(n/4) + n
* dimostrare T(n) = O(n)

soluzione:
* T(n) <= c*f(n) // caso O grande
* T(n/2) + T(n/4) + n <= cn
* cn/2 + cn/4 + n <= cn // sostituisco
* // semplifico
* -c <= -4 --> c >= 4 // soluzione

**dimostrazione con sostituzione**

* si dimostra il caso base della ricorrenza
* si definisce l'ipotesi induttiva, cioè assumi che T(n) appartenga alla classe da dimostrare
* si dimostra

esempio
* T(n) = T(n/2) + n
* dimostrare che è 𝛩(n)
    * caso base ovvio
    * ipotesi induttiva è T(n) <= cn
    * quindi: T(n) = T(n/2) + n <= cn/2 + n
    * se dimostro allora che: cn/2 + n è O(n) è fatta

**teorema dell'esperto semplice**

risolve le equazioni di ricorrenza nella forma:
* T(n) = aT(n/b) + cn^k

posto:
* j = loga / logb
* a > 1, b >= 2

allora:
* T(n) = 𝛩(n^j) se j > k
* T(n) = 𝛩(n^j * logn) se j = k
* T(n) = 𝛩(n^k) se j < k

**teorema dell'esperto esteso**

risolve le equazioni di ricorrenza nella forma:
* T(n) = aT(n/b) + f(n)

funzionamento:
* l = n^log<sub>b</sub>a
* lim f(n) / n^l = k
* k > 0
    * T(n) = 𝛩(n^l * logn)
* k = 0
    * T(n) = 𝛩(n^l) se
        * lim f(n) / n^(l-epsilon) > 0
* k = +inf
    * T(n) = 𝛩(f(n)) se
        * lim f(n) / n^(l+epsilon) > 0
        * af(n/b) <= cf(n) con 0 < c < 1

**tabella di ricorsione**

rappresenta un albero bilanciato di ricorsione, ha le seguenti colonne:
* livello --> livello corrente dell'albero partendo da 0
* costo chiamata --> costo della singola chiamata di funzione in quel livello
* numero chiamate --> numero di chiamate eseguite in quel livello
* costo livello = costo chiamata * numero chiamate

il costo dell'albero è dato da:
* costo albero = somma del costo dei livelli