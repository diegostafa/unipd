**diagrammi di sequenza**

* descrivono il funzionamento runtime di classi (istanze) --> SOLO TIPI CONCRETI
* devono rispettare le dipendenze di un diagramma di classi
* ogni colonna rappresenta un oggetto
* sotto ogni oggetto ci sono le barre di attivazione
* le barre di attivazione di oggetti a destra DEVONO iniziare dopo di quelle a sinistra
* gli oggetti sono collegati da chiamate o relazioni a funziondi di altri oggetti
* si possono richiamare funzioni dello stesso oggetto
* si possono creare oggetti temporanei (direttiva create) o distruggerli (destroy)
* si possono specificare i parametri usati nella chiamata

tipi di segnali che collegano le vite:
* freccia continua --> chiamata sincrona
* freccia vuota --> chiamata asincrona
* freccia tratteggiata inversa --> valore di ritorno
* freccia tratteggiata create --> crea un oggetto
* freccia continua destroy --> distrugge

**frame di interazione**

* riquadro che indica particolari funzioni
* alt --> if/else, si verifica il riquadro che passa la condizione
* opt --> if, si verifica il riquadro solo se passa la condizione
* loop --> il riquadro viene eseguito più volte