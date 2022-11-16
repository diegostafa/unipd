# Progettazione

**differenza analisi**

* analisi --> dice le cose da fare alla progettazione
* progettazione --> dice come fare le cose da fare in modo giusto

per dijkstra:
* analisi --> definire le proprietà che soddisfano i nostri bisogni
* progettazione --> creare qualcosa che abbia quelle proprietà

**processo di progettazione**

* precede la codifica
* correttezza per correzione
* spezza il problema
* assegna i pezzi a persone diverse
    * efficienza --> si usano più persone
    * efficacia --> le parti portano alla soluzione globale
* si occupa di come fare
* deve rispettare gli stakeholders
* definisce l'architettura

**approcci di progettazione**

* top down --> si parte dalla soluzione e trova le parti (decomposizione)
* bottom up --> costruzioni delle parti verso le soluzioni

**dipendenza**

legame tra parti:
* buona --> 

**architettura**

* è un mezzo per raggiungere un obiettivo

si occupa di
* decomposizione del sistema in componenti
* organizzaizione delle componenti
    * ruoli delle componenenti e interazioni
* interfacce di interazione tra componenti
* paradigmi di composizione delle componenti

deve essere:
* sufficiente --> soddisfa i requisiti
* comprensibile
* modulare --> suddivisa in parti chiare e distinte
* robusta --> non se rompe
* flessibile --> ammette modifiche
* riusabile
* efficiente --> nelle risorse che usa
* affidabile --> funziona
* disponibile --> la manutenzione non interrompe
* sicuro --> malfunzionamenti non generano danni
* sicuro --> non è vulnerabile
* semplice --> nulla di superfluo
* incapsulazione --> lo stato interno non è visibile
* coeso --> le parti lavorano per uno stesso obiettivo
    * funzionale --> stesso compito
    * sequenziale --> agiscono come una pipeline
    * informativa --> agiscono su una stessa struttura dati
* basso accoppiamento --> distinzione tra le parti

**progettazione al dettaglio**

* si arrivano a definire le unità del sistema
* la composizione delle unità reallizza le componenti
* ogni unità dev'essere documentata e verificata

**stile architetturale**

* insieme di componenti standard
* regole che vincolnao la composizione
* significato semantico delle composizioni
* insieme di verifiche standard

**design pattern**

soluzione progettuale a problemi ricorrenti

**modularità**

* minimizzare le dipendenze cattive --> dare solo il minimo indispensabile
* le dipendenze cattive possono causare effetti domino di errori

si può moularizzare in 2 modi:
* blocchi logici
* information hiding
    * se cambia una componente interno non si deve modificare il resto
    * l'esterno non deve assumere nulla sull'interno

la bontà di un modulo dipende da quanto dipende dagli altri

**architettura statica**

riguarda la composizione delle parti

**architettura dinamica**

riguarda il comportamento delle parti in esecuzione+

**proof of concept**

* esperimento che verifica la fattibilità di un progetto con le tecnologie
* un PoC deve essere baseline per incrementi futuri

**black box**

* l'esterno non può assume nulla dell'interno
* manutenzione facile --> il modulo è il responsabile
* meno dipendeze più riuso