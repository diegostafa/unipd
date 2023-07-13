# Accessibilità

rappresenta la possibilitò di accedere al sevizio a una vasta catgeoria di utenti, anche svantaggiate

categorie di accessibilità
* contenuti --> web dev
* authoring --> creatori
* navigazione --> 

utenti svantaggiati:
* disabili
* difficoltà nella lettura e comprensione
* no mouse/tastiera
* schermo non grafico
* internazionali
* sensi distratti
* lecagy browser


per alcuni siti la legge impedisce di creare siti poco accessibili

**WAI (web accessibility initiative)**

**priorità**

livelli di accessibilità:
* priorità 1 --> delle categorie di utenti non possono usare il sito
    * webdev deve conformarsi
* priorità 2 --> delle categorie di utenti hanno difficoltà nell'accedere all'informazione
    * webdev dovrebbe
* priorità --> i disabili hanno disagio
    * webdev può

livelli rispetto alla conformità sulle priorità:
* A
* AA
* AAA

**puro**

* percepibile --> accessibile a chiunque
* comprensibile --> layout consistente
* robusto --> rispetta gli standard, non si rompe
* utlizzabile --> usabilità

**principi**

* trasformazione elegante (accessibilità)
    * separare struttura e presentazione
    * fornire equivalente testuale per altri media
    * hardware indipendent, no mouse/tastiera/schermo piccolo
* navigabilità (usabilità)
    * struttura semplice
    * aiutare l'utente ad orientarsi
* contenuti equivalenti
    * traformare un contenuto in altre forme sensoriali

**aria**

* ruoli --> definisce la funzione semantica dell'elemento
* stati --> definisce lo stato modificabile (abilitato, disabilitato)
* proprietà --> aggiunge stati non modificabili

## linee guida

**testo**

da fare:
* marcatori semantici corretti
* linguaggio chiaro
* leggibilità (min 1.5 interlinea)
* colori e dimensioni appropriate

da non fare:
* testo scorrevole
* font difficili da leggere
* testo barrato
* sottolineatura

**link**

da fare:
* riconoscibili, non solo per il colore
* anchor giusti
* che si capisca dove portino
* differenziarne i diversi stati
* differenziare link interni ed esterni
* mantenere le convenzioni interne
* immagine link l'alt deve specificare dove porta
* tabindex e accesskey corretti
* link adiacenti separati da almento uno spazio

da non fare:
* link uguali
* popup

**immagini**

da fare:
* tag img solo se fa parte del contenuto
* alt significativi
* accessibilità anche senza immagini
* sostituire il testo con un'immagine rispettando gli standard

da non fare:
* alt se c'è una descrizione

**tabelle**

da fare:
* tabelle semplici solo quando servono
* associare un breve sommario (tag summary)
* associare l'intestazione alle righe/colonne, con lo scope giusto
* associare le celle alle intestazioni
* usare abbreviazioni per le intestazioni

da non fare:
* usare il tag td per le intestazioni

**form**

da fare:
* associare label agli input
* raggruppare con fieldset
* tabindex e accesskey corretti
* usare title per aggiungere informazioni
* aiuti contestuali
* pulire il form
* validazione lato client

**colori**

* evidenziare testi colorati in altri modi
* non specificare il colore degli elementi
* usare i giusti contrasti

**resto**

da fare:
* controllo dei media
* giusta semantica
* standard web
* layout fluidi o elastici

da no fare:
* usare frame, applet, mappe

**validazione**

deve essere svolta sia automaticamente che da una persona

validare:
* con strumenti automatici
* sintassi
* fogli di stile
* su browser diversi
* su browser testuali
* su screen reader
* la grammatica e leggibilità
* con altre persone

## Usabilità

indica l'efficacia, efficienza e soddsfazione dell'utente nel raggiungere l'informazione

* efficacia --> successo dell'azione
* efficienza --> risorse e tempo impiegato
* soddisfazione --> comfort nell'azione

da fare:
* sistema di navigazione interno al sito
* fornire le informazioni attese
* completezza nei contenuti
* chiarezza delle informazioni
* layout accattivante

## SEO

sono i miflioramenti per un buon indirizzamento nei motori di ricerca, il nome ha poca importanza, servono contenuti e refs da altri siti

da fare:
* meta tag corretti e pertinenti
    * title, description rappresentano link e descrizione
* usare alt in immagini e pdf
* fogli di stile e script esterni
* title diversi per pagina
* validazione del sito

da non fare:
* indirizzare pagine non accessibili