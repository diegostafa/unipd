**PLI - programmazione lineare intera**

problemi:
* generare le soluzioni ammissibili
* trovare l'ottima

generazione delle soluzioni:
* si crea un albero in tecninca branch and bound

ricerca dell'ottimo
* si analizzano le foglie dell'albero

**branch and bounding**

tecnica di programmazione che consiste nel generare un albero (branching), determinare i bound di ammissinilità della soluzione (bounding) e potare i sottoalberi che non rientrano nelle condizioi di bound

consente di enumerare tutte le possibili soluzioni di un problema decisionale finito

progettazione:
* branch dei sottoproblemi deve portare alla soluzione ottima
* trovare un bound minimo e massimo
* fathoming:
    * n.m. --> branch non migliorante, lo si pota
    * s.a. --> soluzione ammissibile
    * n.a. --> non ammissibile
* esplorazione:
    * DFS
    * BFS
    * BBF
* criterio di stop
    * soluzione ottimale

**rilassamento continuo**

risolve un PLI con un simplesso nomrale per trovare un bound

data la soluzione x del problema allora si riesce anche a trovare un metodo di branching