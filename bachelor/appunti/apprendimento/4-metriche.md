**matrice di confusione**

un modello può generare
* TP --> true positive --> vero corretto
* TN --> true negative --> falso corretto
* FP --> false positive --> vero sbagliato
* FN --> false negative --> falso sbagliato

* P = TP + FN --> tutti i positivi effettivi
* N = TN + FP --> tutti i negativi effettivi
* P' = TP + FP --> tutti i positivi generati
* F' = TN + FN --> tutti i negativi generati 

**accuratezza**

quanto ci prende in totale:
* acc = (TP + TN) / (P + N)

fa schifo in dataset sbilanciati, soluzioni:
* macro average
* micro average

**precisione**

quanto ci prende nei positivi generati:
* prc = TP / P'

**true positive rate (recall)**

quanto ci prende nei positivi effettivi: 
* rec = TP / P

**false positive rate**

quanto non ci prende nei negativi effettivi:
* fpr = FP / N

**f1-score**

media armonica tra precisione e rec 
* f1 = 2(prc*rec / (prc + rec))

**average precision**

è la media delle precisioni a diversi livelli di recall

le precisioni vengono calcolate incrementalmente
* la precisione diminuisce con FP e aumenta con TP
* il recall aumenta all'aumentare dei casi
    
**macro average**

media delle accuracy per classe:
* dividi il dataset in classi
* risolvi i problemi distintamente 
* acc = media delle singole accuracy
* problema: le acc nelle classi piccole sono poco affidabili

**micro average**

* dividi il dataset in classi
* risolvi i problemi distintamente
* ottieni TP e FP per le singole classi
* acc = TP / P 

**curva di apprendimento**

sono le metriche al variare di:
* grandezza del dataset
* le iterazioni di gradient descent (epoche) 
* grado di h(x)

**curve di errore**

danno informazioni su bias e varianza
* undefitting --> errori di validazione e training vicini ma alti
* overfitting --> errori di validazione alti e training bassi