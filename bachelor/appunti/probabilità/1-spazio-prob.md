## Spazio di probabilità

si indica con S = (omega, F, P), dove:
* omega indica lo spazio campionario
* F è sottoninsieme di omega, con struttura sigma algebra
* P indica la misura di probabilità

**spazio campionario**

si indica con omega ed è l'insieme di tutti gli esiti di un esperimento aleatorio

omega = { o1, o2, o3 ... on }

notazioni:
* esiti (omega piccolo) sono elementi dell'insieme omega
    * { o1, o2, o3 ... }
* eventi (E) sono insiemi di esiti
    * { o1, o3 }, { o3, o4, o5 }

nb:
* se \|omega\| <= \|N\|, allora si dice spazio campionario discreto
* se \|omega\| <= \|R\|, allora si dice spazio campionario continuo

**sigma algebra**

si indica con F corsivo

è un insieme di eventi, tale per cui:
* F non è vuoto
* se un evento appartiene a F, anche il suo complementare appartiene ad F
* l'unione tra eventi di F appartiene ad F

proprietà:
* l'insieme vuoto appartiene sempre a sigma algebra
* omega appertiene sempre a sigma algebra
* l'intersezione tra elementi di F appertiene ad F

tipi di sigma algebra:
* omega e insieme vuoto (banale)
* omega, E, E<sup>c</sup>, insieme vuoto
* sigma massima --> l'insieme delle parti di omega (tutti i possibili sottinsiemi)

su spazi campionari discreti si scegli sempre la sigma massima (sigma algebra delle parti)

**misura di probabilità**

è una funzione P che va da sigma algebra in \[0-1\], tale per cui:
* normalizzazione --> P(omega) == 1
* la sommatoria di P su eventi disgiunti == P della loro unione

di base associa ad ogni elemento della sigma un numero tra 0 e 1, che corrisponde alla probabilità dell'evento di accedere

**probabilità di eventi complementari**

P(E) == 1 - P(not E)

**probabilità di eventi compatibili**

P(E or F) == P(E) + P(F) - P(E and F) (teorema della probabilità totale)

**probabilità di eventi incompatibili**

P(E or F) == P(E) + P(F)  (teorema della probabilità totale)

assiomi:

* P(ins. vuoto) == 0
* P(sottoinsieme) <  P(insieme)

**probabilità di un evento**

di base gli eventi compatibili/incompatibili hanno importanza se c'è l'or, indipendenza e dipendenza se c'è un and

per calcolare la probabilità di un evento si calcolano tutte le probailità dei suoi esiti e si sommano
* P(E) = P(w1) + P(w2) + ...

**probabilità di un evento in uno spazio di prob. uniforme**

tutti gli esiti sono equiprobabili, quindi la loro singola probabilità è 1/\|omega\|

la probilità dell'evento è quindi \|E\| / \|Omega\|

per calcolare la cardinalità degli insiemi si utilizza la combinatoria (conteggi)

**incompatibilità tra 2 eventi**

E e F sono incompatibili se la loro intersezione è vuota:
* E and F = 0

proprietà:
* P(E or F) = P(E) or P(F)

2 eventi sono incompatibili se il verificarsi di uno esculde il verfificarsi del'altro

**decomposizione di un evento rispetto l'intersezione**

dato un evento F ed una partizione P formata da E1, E2, E3..En, allora: 
* F = F and E<sub>1</sub> + F and E<sub>2</sub> + ... F and E<sub>n</sub>  

**decomposizione dell'unione di 2 eventi rispetto la differenza**

dato due eventi E ed F:
* E or F =  E\F or E and F or F\E
* F or E = F or E-F

**partizione di un insieme**

dato un insieme A, una partizione è un gruppo di sottoinsiemi con le seguenti proprietà:
* ogni sottoinsieme è disgiunto tra loro (intersezione == 0)
* l'unione di tutti da A

esempi:
* { E, not E }

