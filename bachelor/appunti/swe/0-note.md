**corso**

* pianificazione di progetto
* sistema di qualità
*   
* analisi e PoC
* 

**note**

* progetto --> operazione che trasporta qualcosa da uno stato ad un altro stato
* processi di ciclo di vita --> attività che servono per il trasporto
* gestione di progetto --> operare a risorse finite massimizzando efficienza e efficacia
* way of working
    * sviluppo --> attività tecniche
        * analisi dei requisiti, desing, codifica
    * consapevolezza --> attività organizzative
        * pianificazione (a lungo  e corto periodo)
* documentazione --> campo aperto, si impara facendo
* rapporti esterni

**domande**

* pdca
* verifica vs validazione
* definizione qualità
* definizione verifica
* definiszione architettura

---

**analisi dei requisiti**

* risolve il problema
* il successo di un progetto dipende dalla bontà dell'analisi dei requisiti
* dominio applicativo --> tutto ciò che concerne il problema
* dominio di sistema --> tutto ciò che concerne il sistema
* dominio di intersezione --> elementi che appartengono ad entrambi i domini, non può essere vuoto
* proprietà del dominio --> vincolo descrittivo del dominio applicativo (vincoli d'ambiente)
* requisito --> vincoli prescrittivi da soddisfare nel dominio applicativo (vincoli lato utente)
* specifica --> vincoli prescrittivi da soddisfare nell'intersezione (vincoli lato sistema)
* specifica & proprietà di dominio implica requisiti
* qualità dei requisiti individividuati
    * chiari
    * completi
    * non contraddittori
    * incrementali --> permettono modifiche

**progettazione**

* trova una soluzione
* si divide in:
    * architettura --> struttura generale
    * progettazione al dettaglio --> istanza specifica della dell'architetttura
* bisogna sempre progettare in ottica di famiglia di prodotto
* interfaccia --> nasconde ciò che potrebbe cambiare e ciò che non è rilevante

**pattern**

* soluzioni note a problemi ricorrenti in un contesto specifico
* determinano best practice
* classificati per
    * obiettivi --> cioò che fa
    * dominio --> a cosa si applica (classi, relazioni, oggetti...)
* idioma --> implementazione di un pattern in un linguaggio specifico

**controllo di qualità**

* nessuna tecnica garantisce la correttezza
* nessuna tecnica fissa di controllo qualità
* il controllo di qualità non va ad eliminare tutti i difetti, ma migliora il prodotto
* risponde a
    * quando iniziare --> prima di tutto
    * quando terminare --> dopo il ritiro del prodotto
    * quali tecniche usare --> dipende dal prodotto e delle sue esigenze
    * come determinare se il prodotto è pronto --> 
    * come controllare la qualità delle versioni successive
    * come migliorare il processo
* test di regressione --> rieseguire i test delle versioni precedenti
* verifica --> stiamo costruendo correttamente il software (verifica rispetto la specifica)
* validazione --> stiamo costruendo il software corretto? (verifica rispetto all'esiegenze dell'utente)

**processo di qualità**

* la qualità non può essere aggiunta a posteriori, ma va 
* insieme di attività dedicate a controllare la qualità del software durante tutto il suo ciclo di vita
* deve bilanciare le attività in base alle esgenze
* deve rientrare nei limiti di costo
* ad ogni controllo si domanda se si è in linea con i piani, e aggiustare di conseguenza 

**processo di test**

* strategia di test --> dipende dal WoW
* piano di test --> definito dopo la strategia, descrizione completa del processo di qualità (è uno standard IEEE)
    * documenti/elementi/funzionalità da verificare
* tecnica di analisi
    * ispezione
    * compilazione  (automatica)
* tecniche di test
    * devono essere scritti prima

* test di unità --> tipicamente fatti dagli sviluppatori
* test di integrazione --> 