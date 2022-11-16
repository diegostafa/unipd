**SVM - Support Vector Machine**

di base cerca di separare con una retta il dataset, ma la retta ha anche un offset, quindi in vertià cherca di separare con un tubo della retta

caratteristiche:
* chiamato anche large margin classifier
* usato per classificazione, ma può essere anche usato per la regressione
* è un classificatore binario non probabilistico
* è un classficatore lineare estendibile a non lineare con dei kernel particolari
* algoritmo di classificazione supervisionato
* generalizzazione di logistic regression


di base è un logistic regression con una funzione di costo diversa

funzione di costo:
* J(t) = +++ ycost1(x) + (1-y)cost2(x) + k+++t^2 
* J(t) = 1/k+++ ycost1(x) + (1-y)cost2(x) + +++t^2 --> moltiplica tutto per 1/k
* J(t) = CA + b

dove:
* A --> +++ ycost1(x) + (1-y)cost2(x)
* B --> +++ t^2
* C --> 1/k

**definizione primale di SVN**

funzione obiettivo
* min J(t)

se C >> 0 la f.o. diventa:
* min B

s.t.
* y(P||t||) >= 1

di base traccia una linea per separare il dataset in 2, ma c'è un margine nella quale anche se identifica correttamente, la funzione di costo sale, quindi SVM cerca di non far rientrare punti nel margin, e si va a creare un tubicino che separa il dataset


**hard margin**

SVN con margini che non trattano dataset non linearmente separabili

**soft margin**

estensione di SVN:
* min 1/2||t||^2 + +++e

s.t.
* e >= 0
* y(P||t||) >= 1-e

di base aggiunge uno slack al margine per accettare outliers

**hinge loss**

riscrittua della funzione di costo di SVM, è convessa, quindi usabile con gradient descent


**kernel methods**

permettono a SVN di classificare non linearmente, trasforma il set di feature aumentandone la dimensione, con l'ipotesi che la non linearità diventa lineare a più dimensioni