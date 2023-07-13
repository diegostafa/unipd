# Basi di dati

## definizioni

**dati**

i dati sono misure di qualcosa

**informazioni**

le informazioni sono ciò che si deduce dai dati

**basi di dati**

concetto astratto, significato analogo ai linguaggi di programmazione:
* base di dati --> linguaggio c++ --> definisce cosa fa
* dbms --> c++ compiler --> implementazione

**DBMS**

sistemi software che gestiscono basi di dati

problemi:
* ridondanza
* incoerenza
* privacy

problemi di accesso:
* autorizzazione
* concorrenza

**SQL**

linguaggio di comunicazione con le basi di dati relazionali

**DML**

linguaggio per modificare i contenuti delle tabelle

**DDL**

linguaggio per la definizione delle tabelle (schema)

**transazione**

insieme di operazioni che o vengono fatte tutte assieme o non vengono fatte

**commit**

tutte le operazioni di una transazione sono state eseguite con successo

**transazioni concorrenti**

n transazioni parallele vengono eseguite sequenzialmente

**DBMS**

estensione di un file system, aggiunge:
* privatezza
* affidabilita
* efficenza
* efficacia

architteture del DBMS
1. utente
2. schema esterno (vista/view)
3. schema logico (argomento del corso)
4. schema interno
5. base di dati

vantaggi:
* i dati sono una risorsa comune
* gestione centralizzata
* riduzione ridondanze
* indipendenza dai dati

svantaggi:
* necessitano tanti utenti altrimenti sono overkill

**schema**

è l'aspetto intensionale

è la parte immutabile/statica della base di dati, definisce:
* nome della colonna
* dominio del tipo della colonna

**istanza**

aka tupla

è l'aspetto estensionale

è la parte mutabile/dinamica della base di dati, rappresenta:
* le righe di una tabella
* i loro valori

---

**schema concettuale**

detto anche schem/modello ER

rappresenta in modo astratto l'organizzazione dei dati, definisce:
* entità
* relazioni tra entità

uno schema concettuale può essere trasformato in un qualsiasi schema logico

**schema logico**

implementa lo schema concettuale secondo un modello logico:
* relazionale --> di base sono le tabelle etc..
* reticolare
* xml
* oggetti
* gerarchico

uno schema logico può essere trasformato in un qualsiasi schema interno

**schema interno**

implementa lo schema logico e si occupa di gestire l'organizzazione e manipolazione interna dei dati
 
**Architettura standard ANSI/SPARC**

1. schemi esterni (view)
2. schema logico <-- schema concettuale
3. schema interno 
4. DB



 