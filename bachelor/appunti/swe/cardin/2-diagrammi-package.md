**diagrammi di package**

* descrive le dipendenze tra package
    * freccia tratteggiata
* le frecce dovrebbero seguire lo stesso verso
* evitare dipendenze circolari
* package con tanti dipendenze entranti sono importanti --> devono essere spezzate in oppure testate 100%

**divisione dipendenza circolare**

per fattorizzazione
* si crea un package che contiene le dipendenze circolari e si tolgono dalle altre

per riduzione
* si accorpano i 2 package

**package di interfaccia**

* contengono ssolo interfaccia
* pacakge possono collegarsi per generalizzazione