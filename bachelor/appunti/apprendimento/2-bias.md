**bias**

errore causato da assunzioni:
* bias induttivo --> causato da ipotesi sulla f.o.
* bias algoritmico --> causato dal dataset

**bias induttivo**

assunzioni sulla natura della funzione obiettivo, può essere:
* restrittivo --> limita lo spazio di ricerca di h(x) a determinate funzioni (regressione lineare)
    * es. assumi che il dataset può essere separato linearmente
* preferenziale --> stabilisce un ordine nello spazio di ricerca (nearest neighbor)

**bias algoritmico**

assunzioni causate da un dataset non uniforme o con dati mancanti, l'algoritmo rafforzerà sempre le sue assunzioni ad ogni iterazione

**varianza**

sensibilità del modello sul dataset

**bias-variance tradeoff**

high bias - undefitting:
* ha poche feature
* limita la ricerca della f.o. oppure non ha un dataset adeguato

high variance - overfitting:
* ha tante feature 
* la sensibilità del modello tiene conto di dati inutili
* alto grado polinomiale

per risolvere overfitting:
* aumentare dataset
* diminuire le feature
* aumentare k nella regolarizzazione
* diminuire il grado polinomiale

per risolvere underfitting:
* aggiungere feature
* aumentare il grado del modello
* diminuire k nella regolarizzazione

**overfitting**

una funzione overfitta se esiste un'altra funzione con:
* più errore empirico
* meno errore reale
