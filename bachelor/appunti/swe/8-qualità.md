**qualità**

* insieme di caratteristiche necessarie ad un entità al fine di soddisfare delle esigenze
* interessa qualità di prodotto e processo
* riguarda:
    * chi fa
    * chi usa
    * chi valuta

tipi:
* intrinseca --> efficacia 
* relativa --> soddisfazione del cliente
* quantitativa --> misurabile per confronto

**sistema qualità**

* struttura organizzativa che persegue la qualità
    * piano di qualità --> strategia per assicurare qualità
    * controllo di qualità --> verifica che la strategia funzioni
    * miglioramento continuo

**piano di qualità**

pianificare le attività non è sufficiente, c'è bisogno di un elemnto di controllo, determinato dal piano di qualifica, determina:
* organizzazire il controllo di qualità
* controllare che venga attuata in modo efficace ed efficiente
* produrre un miglioramento continuo

**controllo di qualità retrospettivo**

* alla fine di tutto
* non si può sempre risolvere il problema alla fine

**controllo di qualità anticipato**

* chiamato anche quality assurance
* controlli passo passo --> agisce instantaneamente
* controllo continuo con WoW a cruscotto
* NON DEVE ESSERE INVASIVO

ad esempio, c'è un'attività assegnata ad X da finire entro venerdì, non si aspetta la fine dell'attivtà, ma si controlla lo stato di avanzamento per verificare che questa possa essere conclusa in tempo, durante lo svolgimento e si agisce al momento

si aggiorna il repo in modo sistematico, solo se le modifiche rispettano il cruscotto (SI INSERISCE SOLO RISPETTANDO IL PROCESSO DI VALUTAZIONE di QUALITÀ)

**modelli di qualità**

utili perchè:
* comprensione uniformata, sappiamo di che parliamo
* utilizzano metriche oggettive e misurabili

**misurazione quantitativa**

* processo che assegna simboli o numeri ad un attributo secondo delle regole definite

**principi di qualità**

* lavoro suddiviso in processi
* tutti devono rispettare la qualità
* misurazione oggettiva di attributi

**metrica**

* regola fissata per fare misurazioni
* permette di quantificare gli attributi di un entità
* permettono di predire e ragionare sui dati rilevati
* la qualità in uso non si può misurare, ma deriva dalla qualità di prodotto


**qualità di prodotto**

* lato fornitore
* incentrata sul prodotto (efficienza prestazionale, sicurezza, portabilità...)
* solitamente si scelgono solo gli attributi che più servono

**qualità d'uso**

* lato stakeholder
* incentrata sugli aspetti di chi usa (efficacia, efficienza, rischi, soddisfazione..) 

**valutazione di qualità**

fatta da 3 attività:
* misurazione
    * selezionare le metriche
    * misurare secondo il WoW
* valutazione
    * interpretazione delle misure attraverso gli obiettivi
* accettazione
    * criteri di accettazione delle metriche
    * si tiene ciò che è buono

meglio se tutto ciò è automatico
* il repo si aggiorna solo se l'accettazione passa

**qualità di processo**

misura l'efficienza di fare qualcosa

**qualità di prodotto**

* misura l'efficacia del prodotto

**modello a V**

* diagramma a v
* da un senso di simmetria delle attività
* l'andata sono i processi
* il ritorno è la verifica
* si va dall'alto (astrazione) al basso (dettagli)
    * l'andata è una piepline
    * la piepline stabilisce un'ordine di causa
    * quindi il piano più alto è il più
    * la piepline garantisce correttezza

andata
* capitolato --> produce test di accettazione
* analisi --> produce test di sistema
* progettazione --> produce testi di integrazione
* dettaglio --> produce test i unità

ritorno
* test di unità --> esiti registrati nel PdQ
* test di integrazione --> esiti registrati nel PdQ
* test di sistema --> esiti registrati nel PdQ --> devono essere 100% passati
* collaudo test accettazione --> esiti registrati nel PdQ


**qualità di processo**

modello concettuale:
* controllo --> con obiettivi e regole fa un miglioramento continuo del processo
* processo --> crea un prodotto con delle risorse, quindi fonrisce i valori delle metriche al controllo


**capability**

misura l'adeguatezza di un processo riguardo a ciò che deve fare

se bassa, il processo:
* dipende da chi lo attua
* è attuto in modo opportunistico
* rende difficile le previsioni
* porta compromessi tra qualità e funzionalità

se alta:
* il processo è eseguiot in modo sistematico e quantificabile

**verifica**

* precondizione della validazione
* controlla che le attività non intrducano errori
* serve a non trascinare errori
* si fa ad ogni baseline (solitamente)
* il costo di correzione aumenta nel tempo
* si attua concretamente attraverso:
    * analisi statica
    * analisi dinamica --> test di unità e integrazione

**validazione**

* conclusione del progetto
* accerta che i requisiti concordati a contratto siano rispettati
* fatta con analisi dinamica
    * test di sistema --> fatti dal fornitore
    * test di accettazione --> fatti dal committente

**analisi statica**

* non richiede l'esecuzione dell'oggetto di verfifica
* si applica ai sorgenti e alle documentazioni
* accerta la conformità alle NdP
* si attua con:
    * metodi di lettura (umana o automatizzata)--> inspection e walkthrough fatta con gli autori
    * metodi formali
        * flussi di controllo
        * flusso di dati --> consistenza dei dati (write only, var globali)
        * flusso di informazione --> cosa esce o entra nelle funzioni (side effect)
        * verifica formale --> correttezza del codice (invarianti pre post ...)
        * analisi di limite --> overflow, indici...
        * analisi stack --> controlla come si evolve lo stack
        * analisi temporale --> controlla istruzioni con esecuzioni di tempo variabile

**collaudo**

* attivita formale che implica il rilasco del prodotto e l'eventuale fine del progetto

**walkthrough**

* lettura di TUTTO il documento/codice per rilevare i difetti e le parti non conformi
* definito da:
    * pianificazione
    * lettura
    * discussione
    * correzione --> fatta solo dagli autori

**inspection**

* lettura mirata supportata da lista di controllo
* definito da:
    * lettura tramite lista di controllo
    * correzione --> fatta solo dagli autori

**analisi dinamica (test)**

* richiede l'esecuzione dell'oggetto
* effettuata tramite test, composto da
    * ambiente di esecuzione --> stato interno, sw/hw
    * attese --> pre e post condizioni
    * procedure -->
* usata anche nella validazione
* deve essere ripetibili e automatizzata

**test**

* misura la qualità di un prodotto
* dimostra la presenza di errori, non l'assenza
* ogni errore rilevato deve essere incluso come test ripetibile

ogni test è specificato tramite:
* oggetto
* obiettivo
* risorse
* passi di esecuzione
* esito atteso
* modalità di verifica

**oracolo**

contratto, indica l'esito atteso di un test in base alla specifica di una funzione

**tracciamento**

* dimostra la completezza
* applicato ad ogni fase di test
* meglio se automatizzato

**governance**

* ragionamento sul futuro
* sapere il perchè delle scelte

**maturità di un processo**

livelli di maturità
* iniziale --> non prevedibile
* gestito --> controllato da un progetto
* definito --> WoW
* quantificato --> controllo di qualitòà
* flessibile --> PDCA applicato

se i processi sono ben definiti la qualità di prodotto è più probabile sia alta

**maturità del prodotto**

* migliora all'aumentare dei test
    * solo se le correzioni non sono regressive
* implica meno difetti

* errori meno gravi solitamente non vengono risolti immediatamente e causano code-smells
* gli errori sono molto costosi se comportano modifiche all'architettura
* il numero di errori cresce linearmente nella durata di un progetto

**oggetto della prova**

gli oggetti di prova nei test sono:
* sistema nel complesso --> TS
* componenti --> TI
* unità --> TU

**classe di equivalenza**

un test determina 3 classi di equivalenza:
* interni al dominio --> rispettano il test
* al limite --> circoscrivono il dominio, casi limiti
* illegali --> non rispettano il test

**unità**

* insieme di codice assegnabile ad un singolo programmatore in poco tempo
* solitamente sono moduli
* un modulo dovrebbe essere tracciato ad un solo requisito

**test di unità funzionale (black box)**

* fa riferimento all'interfaccia dell'unità
* assicura che rispetta i requisiti
* non valuta la correttezza (servono quelli strutturali)
* contribuisce al numero di requisiti funzionali soddisfatti --> functional coverage
* input che hanno stesso risultato appartengono alla stessa classe di equivalenza


**test di unità strutturale (white box)**

* fa riferimento all'implementazione dell'unità
* verifica la logica interna --> structural coverage
* il test viene fatto sulle istruzioni, in base a qualche criterio
* verifica la copertura delle istruzioni  e delle condizioni (# eseguite / # tot istruzioni)
* definito dall'input e dallo stato interno

**structural coverage**

determinato da:
* statement coverage 100% --> ogni istruzione viene attraversata da almeno un test con esito corretto
* branch coverage 100% --> ogni ramo if/else viene attraversato da almeno un test con esito corretto
* condition coverage 100% --> la condizione del branch assume entrambi i valori in un test dedicato (più precisa del branch coverage)
* condition and decision coverage --> mcdc

**complessità ciclomatica**

* numero di cammini linearmente indipendenti in una funzione
* percorsi univoci che la funzione può prendere

**mcdc**

* verificare che ogni parte della condizione di branch possa modificare l'esito della condizione totale

**test di integrazione**

* dopo aver testato le unità i test di integrazione vanno a comporle fino ad arrivare al sistema completo
* verfica che i dati scambiati dalle componenti rispecchi l'interfaccia di progettazione
    * rileva difetti di progettazione o errori nei test di unità
* l'errore viene introdotto dall'ultima componente integrata, ogni integrazione è reversibile ad una baseline precedente

**test di integrazione bottom up**

* prima le componenti con meno dipendenze ma che vengono usate di più
* quelle meno visibili lato utente
* servono quindi pochi stub
* le funzionalità vengono ritardate però

**test di integrazione top down**

contrario di bottom-up, tanti stub ma si ha un prototipo funzionante prima

**test di regressione**

* testare che una modifica/correzione fatta in seguito ad un test non causi errori
* bisogna fare tutti i test precedenti necessari che la modifica non abbai causato errori

**continous integration**

* ogni push al repo produce un test ed un risultato che decide se può o non può passare

**legge del rendimento decrescente**

non si può fare 100% di coverage dei test
