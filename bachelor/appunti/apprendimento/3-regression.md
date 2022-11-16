**regressione**

determinare una funzioni che approssimi al meglio il dataset

**classificazione**

determinare una funzione che separi al meglio il dataset in parti discrete

**linear regression**

modello di regressione che determina la migliore funzione lineare che approssima il dataset

ipotesi:
* h(x) = t'x in forma matriciale

funzione di costo, che determina quanto buona è la funzione lineare:
* J(t) = 1/2m +++ (h(x) - y)^2 --> scarti quadratici medi

funzione obiettivo:
* min J(t) --> la somma dei residui deve essere minima 

**linear regression**

modello di classificazione che determina la migliore funzione lineare che separa il dataset

ipotesi:
* h(x) = g(t'x)

funzione di attivazione:
* g(z) = sign(z)

contro:
* di per se cerca di interpolare, non di separare
* varianza dei dati disturba molto la retta 

**logistic regression**

modello di classificazione che determina la migliore funzione logistica che separa il dataset

ipotesi:
* h(x) = g(t'x)

funzione di attivazione:
* g(z) = 1/(1 + e^-z) --> sigmoide --> sempre compresa tra 0 e 1

derivata della sigmoide:
* g(z)' = g(z)(1 - g(z))

siccome la sigmoide non è lineare la funzione di costo a scarti non è convessa e il gradient descent non è applicabile, quindi la si linearizza con il log

funzione di costo (in forma lineare):
* J(h(x), y) = -1/m +++ yilog(h(xi)) + (1 - yi)log(1 - h(xi))

derivata della funzione di costo:
* J' =  -1/m +++ (y - h(x))*x

funzione obiettivo:
* min J(h(x), y) 

**gradient descent**

caratterstiche
* algoritmo iterativo per trovare il minimo di una funzione derivabile
* si parte da una configurazione di parametri random nella funzione di costo
* si aggiornano i parametri in modo iterativo
* garantisce convergenza globale solo se la curva è convessa

idea di base:
* se la derivata è positiva --> a destra cresce --> quindi se sottrai vai a sinistra
* se la derivata è negativa --> a destra decresce --> quindi se sottrai vai destra
* si ferma quando la derivata è 0

formula matriciale:
* tn+1 = tn - kJ'(tn) (finchè non converge)

dove:
* tn è il vettore di parametri all n-esima iterazione
* J(tn)' = è la derivata parziale sul parametro t della funzione di costo
* k indica la velocità di convergenza --> learning rate
    * se piccolo ci mette tanto, se grande può sbagliare

implementazioni:
* batch gradient descent --> si usa l'intero dataset per il calcolo della funzione di costo
* stochastic gradient descent --> usa una porzione casuale del dataset (funziona solo se è IID)

**gradient descent linear regression**

derivata della funzione di costo:
* J' = 1/m +++ (h(xi) - yi)xi

implementazione:
```
for k = 1 to m
    // calcolo il prossimo valore dei parametri
    tmp0 = t0 - kJ'(t0,t1) // derivata parziale su t0 
    tmp1 = t1 - kJ'(t0,t1) // derivata parziale su t1 

    // aggiorno il vettore di parametri
    t0 = tmp0
    t1 = tmp1
```

**regolarizzazione**

significa assegnare un peso alle feature, per forzare il modello ad assegnare t piccoli e diminuire l'effetto della feature si sommano i parametri che si vogliono annullare, così la minimizzazione è costretta ad abbassare quei parametri

funzione di costo regolarizzata (linear):
* J(t) = 1/2m +++i (h(xi) - yi)^2  +++i kti^2

caratteristiche:
* il quadrato serve solo per non essere negativi e per derivare meglio
* k serve per regolarizzare secondo una costante