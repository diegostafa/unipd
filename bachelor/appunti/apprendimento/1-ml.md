**machine learning**

una macchina si dice che apprende se all'aumentare dell'esperienza fornita aumenta la perfomance in un determinato task 
* (E)sperienza --> dati forniti all'algoritmo (batch o stream)
* (T)ask --> problema da risolvere
* (P)erformace --> metrica significativa dell'algoritmo (es. accuratezza)

l'utilizzo di E determina le classi di algoritmi:
* supervised learning
* unsupervised learning
* reinforcement learning

**supervised learning**

il task è trovare una funzione che mappi gli input negli output

definizione:
* E --> (x,y) cioè insieme di input e output, legati da una funzione incognita f(x) (supervisione)
* T --> trovare h(x) tale per cui h(x)=y
* P --> livello di approssimazione di h(x) rispetto ad f(x)

questo task può modellato in 2 modi:
* per regressione
    * linear regression
* per classificazione
    * logistic regressione


**unsupervised learning**

come supervised ma non viene dato la supervisione


**reinforcment learning**

* ha stato interno
* può eseguire delle azioni in base allo stato
* ogni azione genera un feedback positivo/negativo e un nuovo stato
* massimizza i feedback positivi