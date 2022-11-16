**diagrammi di attività**

* descrivono algoritmi
* di base sono i flow chart
* per modellare metodi complessi
* composto di azioni

**token**

* pallino nero --> inizio, genera un token
* pallino nero cerchiato --> fine, ferma l'esecuzione
* pallino croce --> stop, ferma il token (per errori)

**attività**

* rettangoli bombati
* un solo input e output
    * si possono avere più input, ma a quel punto diventa una join
* pin --> quadrattini vuoti che indicano cosa viene inviato in l'input/ouput 

**condizionale**

* azioni identificate da rombi
* branch --> dato 1 token viene generato 1 token in output nel ramo che rispetta la condizione
* merge --> unisce i branch

**cicli**

* azioni identificate da pile alte 4
* pila iniziale --> full token
* pila finale --> vuota (è una join)
* ad ogni iterazione passa un token dall'inizale alla finale


**concorrenza**

* azioni identificate da linee orizzontali
* fork --> dato 1 token in input genera 2 token in output concorrenti (punto di concorrenza)
* join --> dati 2 input genera 1 token in output (punto di sincronizzazione)
    * aspetta finchè non ci sono entrambi i token (default)
    * oppure verifica una condizione all'arrivo di ogni token e se passa genera un token

**partizione**

* si divide per colonne in base al tipo di azione
* ogni azione appartiene ad una colonna
* non va a modificare veramente il diagrammma, ma è utile per separare logicamente

**segnali**

* clessidra
    * attesa temporale se tra 2 azioni
    * timer di eventi se punto di inizio
* segnale --> maschio, indica l'accadersi di qualcosa
* evento --> femmina, fa partire un token quando viene emesso il suo segnale
