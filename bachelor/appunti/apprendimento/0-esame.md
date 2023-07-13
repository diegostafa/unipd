domanda esame:
* diverse implementazioni gradient descent
    * variare n per adattarlo alla posizione corrente

**spiegare perceptron**


il perceptron è un modello matematico del concetto di neurone biologico, è definito da:
* un bias
* dei parametri in input
* il peso di questi parametri
* un ipotesi
* un output

l'ipotesi è la funzione che lega gli input con l'ouput, nella forma più semplice è una funzione lineare:
* h(x) = tx

l'unione di più perceptron forma una rete neurale, in particolare questa definisce layer di perceptron
* input layer
* hidden layer
* output layer

questa distinzione

che architettura ????

**descrizione bias e varianza**

il bias è un errore intrinseco del modello, può essere di 2 tipi:
* induttivo
* algoritmico

il bias induttivo a sua volta si divide in:
* bias restrittivo
* bias preferenziale

il bias restrittivo è l'errore causato dalla scelta dell'ipotesi in un modello, ad esempio la scelta di un modello di regressione lineare ricercherà solo funzioni lineari

il bias preferenziale è causato da un ordinamento dello spazio delle soluzioni

il bias algoritmico invece è causato dall'uso ripetuto di un dataset non uniforme, l'algoritmo quindi reitera sugli stessi errrori confermando il bias

la varianza indica la sensibilità del modello al rumore

quando il bias è molto alto si ha un errore di underfitting, cioè il modello è lasco di assunzioni e la funzione prodotta non andà a fittare quella ricercata

quando la varianza è molto alra invece si ha overfitting, la sensibilità del modello fa si che l'errore sul dataset sia minimo, 

aspetti concreti ????


**logistic regression con gradient descent**

modello di classificazione binaria definito da:
* funzione di attivazione: g(z) = 1 / 1 + e^-z
* ipotesi: h(x) = g(tx)
* funzione di costo: J(t) = 1/2m+++ (h(x) - y )^2


**cross validation**

k fold corss validation è una tecnica di allenamento che mira a minimizzare ad avvicinare l'errore empirico al true error, lo scopo principale è quello di


domande:
* bias algoritmico
* differenza funzione di costo logistica: lineare vs logica
* test set vs validation set
* definizione formale di overfitting
* formula training/validation error
* differenza babysitting debugging curva
* micro average
* funzioni logiche neurali
* one vs all, one vs one
* soft max
* backpropagation f'

**SVM**

descrivere:
1. elementi fondamentali
2. interpretazione geomentrica
3. funzione di costo
4. differenze similutidini con logisitic regression
5. kernel trick

1)
svm è un modello di apprendimento lineare   e supervisionato per la classificazione binaria, non probabilistico


**alberi di decisione**


**algoritmo knn**

