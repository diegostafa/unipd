# Modelli di sviluppo

**standard**

* modelli esemplari consolidati
* identificano best practice
* misurano il WoW

**modello**

insieme di specifiche che descrive un fenomeno in modo oggettivo, che permette un ragionamento su di esso per ricavare spunti interessanti PRIMA di sperimentare qualcosa

**PDCA - ciclo di deming**

è un ciclo di miglioramento continuo, formato da:
* plan --> identifica cosa fare per raggiungere i prossimi obiettivi
* do --> raggiungi gli obiettivi
* check --> confronta gli obiettivi raggiunti con quelli stabiliti inizialmente 
* act --> consolida ciò che buono nel WoW e migliora il resto

si fa plan sul miglioramento

**modello sequenziale (a cascata)**

caratteristiche:
* l'automa è una lista di stati
* ingressi e uscite sono vincolati da pre/postcondizioni
* ci si può trovare in un solo stato alla volta
* le fasi non si accavallano nel tempo
* usa cicli iterativi
* adatto a sistemi rigidi
* approccio predittivo

contro:
* difficilmente 

soluzioni:
* prototipazione --> si crea un prototipo iniziale per capire meglio i requisiti
* ritorni --> diventa modello incrementale/iterativo

processi a cascata 12207
* analisi -> progettazione -> sviluppo -> manutenzione

**modello incrementale**

caratteristiche:
* usa cicli incrementali
* prevede rilasci multipli per ogni incremento
* i requisiti vengono trattati in base alla loro importanza
* ogni incremento riduce il rischio di fallimento
* approccio adattivo
* difficilemente realizzabile

**modello evolutivo**

caratteristiche:
* risponde a bisogni non inizialmente preventivabili
* può rilasciare più versioni in parallelo
* riattraversa più stati di ciclo di vita

**modello a componenti**

caratteristiche:
* analisi dei requisiti è fatta per favorire il riuso del codice

**modello agile**

caratteristiche:
* usa il concetto di user story
* nel migliore dei casi è un modello incrementale
* l'assenza di un contratto prestabilito consente di ottimizzare le iterazioni

**user story**

consiste in:
* documento di descrizione del problema
* breve conversazione con gli stakeholders
* startegia per la realizzazione del sw che rispetti i precedenti requisiti

**manifesto agile**

manifesto:
* committenti e fornitori sono più importanti dei processi e strumenti
* il software è più importante della documentazione
* rapporto collaborativo con gli stakeholders. non di contratto
* adattarsi ai cambiamenti è più importante che seguire un piano prefissato

contro arg:
* l'assenza di documentazione produce solo costi futuri
* l'assenza di un piano non tiene conto dei rischi e avanzamenti
* bisogna adattarsi in rapporto a costi e benefici

**scrum**

3 processi
* product backlog --> analisi dei requisiti dalla user story
* sprint backlog --> sviluppo dei requisiti più importanti
* sprint --> ciclo incrementale

**ciclo di vita semat/1**

* ogni attività ha un percentuale di progresso di completamento
* si conclude quando si soddisfano tutti i requisiti

**costi nei modelli**

* sequenziale --> pesa la validazione
* iterativo --> pesa lo sviluppo
* evolutivo --> bilanciato, pesa la validazione
* a componenti --> pesa lo sviluppo evolutivo