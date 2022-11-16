**integrazione  numerica**

è un'operatore stabile, calcolatocon formule di quadratura, possono essere di 2 tipi:
* algebriche --> approssimazione polinomiale
* composte --> approssimazione polinomiale a tratti

**formule algebriche**

calcolano l'integrale approssimato del polinomio interpolatore:
* I(f(x)) ~= I(p(x))

si dividono per tipologia di nodi usati dall'interpolatore:
* formule di newton-cotes
    * nodi equispaziati, in generale non converge
* formula di clenshaw-curtis
    * nodi di Chebychev, converge se f è derivabile k volte
* formule gaussiane --> distribuzione speciale di nodi

ogni formula algebrica è esatta se la funzione da integrare è il polinomio interpolatore stesso

**formule composte**

si dividono in:
* formule dei trapezi --> ogni polinomio è una retta
* formule delle parabole -->  ogni polinomio è di grado 2

**derivazione numerica**

Vi sono due approcci principali alla derivazione numerica:
* globale --> si calcola f' tramite interpolazione spline
* locale --> si calcola f' tramite rapporto incrementale su un punto.