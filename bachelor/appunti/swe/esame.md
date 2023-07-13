
esercizi
* dato uml determinare i pattern utilizzati
* dato uml trovare errori sintattici
* diagramma uc

errori comuni
* sintassi asbtract e interface
* sintassi estensione per classi astratte e interfacce

diagrammi uc
* mettere le condizioni nelle estensioni se necessario
* i sottouc devono rispettare le pre post condizioni dei padri
    *  non ha senso fare un UC gestione utenti
        * ma lo si può usare come frame
* i figli di uc di visualizzazione devono solo specificare nel dettaglio gli elemnti che si visualizzano
* gli uc hanno relazioni tra loro sono nei seguenti casi
    * quando si vuole definire uno scenario alternativo all'esecuzione di un uc
    * quando si vuole definire un uc che si verifica sempre alla fine di un uc
    * quando si vuole definire al dettaglio un uc descrivendo gli uc figli