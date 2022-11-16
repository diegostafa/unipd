### Probabilità condizionata

la probabilità condizionata di un evento E indica la probabilità che E si verfichi sapendo che l'evento F si è verficato, ed è così definita:
* P(E | F) = P(E and F) / P(F)

da cui:
*  P(E and F) = P(E | F)P(F) = P(F | E)P(E)

**formula delle probabilità totali**

dato uno spazio di probabilità, un evento E ed una partizione di k eventi F<sub>k</sub>, allora:
* P(E) = P(E|F<sub>1</sub>)P(F<sub>1</sub>) + P(E|F<sub>2</sub>)P(F<sub>2</sub>) + ... + P(E|F<sub>k</sub>)P(F<sub>k</sub>)

si legge come:
* la probabilità di un evento è uguale al prodotto tra la probabilità condizionata e la probabilità della condizione

**formula di bayes**

dalla formula della probabilità condizionata, si ricava che:
* P(F | E)P(E) = P(E | F)P(F)

permette di rovesciare il condizionamento

**probabilità di eventi dipendenti**

* P(E and F) = P(E)P(F|E)

**indipendenza tra 2 eventi**

2 eventi sono indipendenti se pur essendo compatibili, il verficarsi di uno non influenza il verficarsi dell'altro

E ed F sono indipendenti sse:
* P(E and F) = P(E)P(F)

l'indipendenza la indico con E \|\| F

proprietà:
* P(E|F) = P(E)
* P(F|E) = P(F)

scritture equivalenti:
* E \|\| F
* not E \|\| F
* E \|\| not F
* not E \|\| not F

eventi incompatibili non possono essere indipendenti

**indipendenza di N eventi**

N eventi sono indipendenti tra loro se tutte le combinazioni di eventi sono indipendenti, cioè sse:
* E1 || E2 || ... || EN
* P(E1 and E2 and ... and EN) = P(E1)P(E2)...P(EN)

proprietà:
* l'indipenza rimane se sostituendo uno o più eventi con i loro complementari


**risoluzione problemi**

1. calcolare la probabilità di un solo evento
2. calcolare la probabilità del suo complementare
3. calcolare la probabilita della composizione di 2 eventi (and/or)
    * or --> formula delle probabilità totali
        * se incompatibli il risultato è la somma delle probabilità
    * and --> formula della probabilità composta
        * se indipendenti il risultato è il prodotto delle probabilitò
        * se sono incompatibili è 0