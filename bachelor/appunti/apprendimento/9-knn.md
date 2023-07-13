**modello parametrico**

un modello è parametrico se cerchiamo H(x) con dei parametri

**modello non parametrico**

* non c'è theta
* solitamente ci si riferisce ai modelli nearest neighboars
* non si fa quindi un tunining dei parametri allenando il modello, ma lo si esgue e basta
* lenti a test time

**lazy learning**

non viene definito un modello, ma viene fatto tutto in fase di predizione


**nearest neighboars**

caratteristiche:
* instance based learning --> non viene creato un modello, ma 

funzionamento:
* dato un'istanza
* calcola la distanza tra tutti gli altri punti
* prendi il punto con distanza minima --> regola di decisione
* l'istanza appartiene alla classe

NN non calcola decision boundaries, ma vengono creati da soli dalla regola di decisione, il boundary è un diagramma voronoi

affetto da outliers

complessità:
* training time -- O(1)
* prediction time --> O(n)

**k nearest neighbours**

NN ma si prendono i K (dispari) più vicini, si conta quale classe si ripete di più

scelta di k:
* k piccoli è suscettibile ad outilier
* k grandi è suscettibile alla classe più frequente
* di solito si sceglie k = radice del dataset

**estensioni knn**

* feature scaling --> 
* knn con apprendimento di una metrica
* pre elebaorazione del dataset per velocizzare il calcolo delle distnaze