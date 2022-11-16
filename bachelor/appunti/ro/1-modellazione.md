# Modellazione

**formalizzazione del problema**

consiste nel formulare un problema reale in un modello matematico, bisogna individuare:
* variabili decisionali
* funzione obiettivo
* vincoli del problema

**elementi di un modello**

* insiemi --> insiemi di risorse, prodotti etc... elementi che vanno a definire il problema
* parametri --> dati associati agli elementi
* variabili decisionali --> quantità da ottimale da individuare
* vincoli --> condizioni di ammissibilità della soluzione
* funzione obiettivo --> valore da massimizzare o minimizzare

**formulazione del modello generale**

```
min/max z = c1x1 + ... + cnxn
s.t.
    a11x1 + a12x2 + ... + a1nxn <=> b1
    a21x1 + a22x2 + ... + a2nxn <=> b2
    ...
    am1x1 + am2x2 + ... + amnxn <=> bm
dominio:
    xi in R/I
```

dove:
* c --> coefficenti di costo
* a --> coefficenti tecnologici
* b --> termini noti

**tipi di modello**

la maggior parte dei problemi si possono classificare in:
* modelli di copertura di costo minimo
* modelli di trasporto
* modelli di mix ottimo di produzione

**modello di copertura di costo minimo**

descritto da:
* I --> insieme di risorse da acquistare
* J --> insieme di domande da coprire
* C --> costo di ogni risorsa
* D --> ammontatre di domanda
* A --> capacità della risorsa di soddisfare la domanda

si formula in:
* min Cx
* Ax >= D

**modello di trasporto**

descritto da:
* I --> insieme di offerta
* J --> insieme di domanda
* O --> ammontare di offerta
* D --> ammontare di domanda
* C--> costo del trasporto

si formula in:
* min +++i +++j CijXij
* +++j xij <= O per ogni i
* +++i xij >= D per ogni j

**modello di mix ottimo di produzione**

quando si hanno dei prodotti e delle risorse e si vuole massimizzare il ricavo trovando la combinazione ottima

descritto da:
* I --> insieme di beni producibili
* J --> insieme di risorse disponibili
* P --> profitto per bene
* Q --> quantità della risorsa
* A --> quantità di risorsa necessaria per un bene

si formula in:
* min Px
* Ax <= Q

**linearizzazione**

```
// minimo
min(x1,x2,x3)

diventa:
y <= x1
y <= x2
y <= x3

// massimo
max(x1,x2,x3)

diventa:
y >= x1
y >= x2
y >= x3

// valore assoluto
|x|

diventa:
max(x, -x)

cioè:
y >= x
y >= -x

// variabili binarie
y = {1 se x..., 0 altrimenti}

diventa:
x <= My // con M costante sufficentemente grande
``` 