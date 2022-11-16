**model selection**

per valutare un modello la metrica più importante è la percentuale di errore, si divide in:
* EE --> errore empirico --> errore del modello sul dataset
    * validation error
    * training error
* ER --> errore reale --> errore del modello su tutti i casi possibili

la valutazione migliora se l'errore empirico si avvicina a l'errore reale e si può fare in 2 modi:
* hold out
* k-fold cross
* leave one out

tipi di set:
* training set --> dati che il modello userà per trovare i parametri giusti
* cross-validation set --> per calcolare l'errore del modello
* test set --> per calcolare le metriche

**hold out**

1. crea 3 sottoinsiemi: training, validation e test set
2. togli validation e test set
3. allena i modelli suk training set
4. valutalo con i 2 tolti
5. scegli il modello che ha performato meglio
6. fai il test del modello scelto

contro:
* 2 sottoinsiemi non vengono usati per allenare il modello

**k-fold cross validation**

1. togli il test set
2. suddividi in k parti a caso di dimensione uguale
3. togli validation set
4. allena il modello con il training set
5. valutalo con il validation set
6. riesegui dal punto 2) k volte con un validation set diverso
7. fai la media della perfomance del modello
8. riesegui dal punto 2) k volte con un modello diverso
9. scegli il modello che ha performato meglio
10. fai il test del modello scelto

**leave one out**

caso speciale di k-fold cross in cui k è numero di elementi nel dataset

pro:
* ad ogni iterazione un solo dato non viene usato

contro:
* impraticabile con dataset grandi