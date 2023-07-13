# -1 - presentazione - STAFA

buonasera, io sono diego stafa il mio compango è luciano wu e oggi volevamo presentarle il progetto nodejs su github.

prima di inziare volevamo solo dirle che abbiamo modificato un piccolo errore di scrittura nella presentazione dopo la consegna , spero non ci siano problemi a riguardo

# 0 - contesto - STAFA

Allora partiamo nel dire cos'è nodejs, node è un runtime javascript nato 13 anni fa che permette di utilizzare il linguaggio al di fuori dei browser, e ciò permette di scrivere codice javascript ovunque, anche se viene perlopiù usato come linguaggio di backend, per uniformare frontend e backend.

ovviamente ci sono anche altri casi duso come applicazioni desktop e micorservizi.

1min

# 1 - ITS - CIANO

Essendo un progetto che risiede su github, node usa l'its standard di github, ma si appoggia comunque ad altri canali esterni come hackerone per ticket particolari.

le attività principali che vengono offerte al contributore sono la segnalazione di bug e flaky test, cioè test falliti durante l'esecuzione di un workflow, richiesta e discussione di nuove feature e problemi legati alla documentazione dell'api di node

oltre a questi template di attività, vengono fornite numerose label per arricchire le descrizioni e creare issue mirate al problema

per quanto riguarda la segnalazione dei bug, come detto prima viene usato il template di bug reporting, ma per bug relativi alla sicurezza del sistema, node si appoggia alla piattaforma hackerOne e che premia in denaro i collaboratori o gli utenti che riescono a trovare falle nel sistema 

Queste attività seguono il workfow standard, quando una issue è considerata risolta questa viene chiusa, nel caso si sia commesso un errore i collaboratori di node possono decidere di riaprirla e ovviamente in caso richiuderla.

2:30min

---

La creazione di nuove attività avviene seguendo le linee guida contenute in CONTRIBUTING.md e selezionando il template del modulo adatto

Al momento della creazione è possibile anche richiedere l'intervento del gruppo di triage di node. il gruppo di triage è semplicemente un gruppo di collaboratori abilitati per la modifica dello stato delle issue e per la gestione delle conversazioni, il loro scopo è quello di ridurre il backlog di attività e mantenere un certa puliza nell'ITS

L'abilitazione a triager necessita solo di una conoscenza ragionevole di node, dell'organizzazione e dell'approvazione di un collaboratore

---

la gestione di queste issue viene supportata dalle board kanban automatiche di github, che in base alle diverse azioni sulle issue, queste cambiano di stato nelle board


da quanto osservato abbiamo poi notato che node non segue una determinata prassi per la creazione delle board, al momento sono presenti board per il tracciamento di flaky test e altre per questioni molto tecniche, ma analizzando quelle chiuse in precedenza possiamo supporre venga creata una board per ogni versione di node, anche perchè ogni versione ha una milestone associata

oltre alle kanban board di github viene anche usato lo strumento github project beta per tracciare il backlog di feature request

4min
---

per le statistiche e lo stato del repository node si appoggia a github insights

github insights tramite lo strumento Pulse, permette di avere una panoramica sullo stato delle issue in un determinato frangente temporale, cioè sapere quante ne sono state aperte e quante ne sono state chiuse

In generale però github Insights viene sfruttato per una reportistica di più ampio raggio, includendo informazioni sulla frequenza di commit, di contribuzioni, sullo stato delle dipendenze e molte altre piccole cose.

---


Passando alla gestione dei rilasci, questi vengono trattati dal release working group, come per i triagers, il release working group è un gruppo di collaboratori designati per la gestione dei rilasci di node, essi definiscono come avviene e il contenuto del rilascio e sono coloro che eseguono effettivamente il rilascio

I rilasci sono di tre tipi:
- current
- long term service
- maintenance


current è la release principale, viene rileasciata tipicamente ogni 6 mesi e possono introdurre rotture alle versioni precedenti

se una release riceve il long term support, questa viene detta lts, una release lts ha un focus nella stabilità e riceve aggiornamenti per 12 mesi + 18 mesi passando nello stato maintenance

oltre a queste c'è anche una release nightly che viene generata ogni 24 ore dal current branch


in generale un rilascio comprende una descrizione delle modifiche apportate, lo storico di commit e i sorgenti compressi come osservabile dalla prossima figura che mostra il rilascio della versione 18.3

come vede viene definita in alto la versione della release, vengono poi stilate le modifiche apportate, lo storico dei commit e anche se nell'immagine non si vede in basso è presente il zip del sorgente

6,30min

# 2 - VCS - STAFA

passando quindi al version control system, anche in questo caso lo strumento utilizzato è github, github è un cloud based vcs basato su git, ciò sta a significare l'hosting del repository principale è preso in incarico da github

Come succede per questo tipo di vcs, il worflow di sviluppo incoraggiato è il github flow, a grandi linee i passi per contribuire si possono quindi suddividere in:
- branching (per i collaboratori) / fork del progetto
- pull request delle modifiche apportate
- verifica 
- e infine merge nel main

---

nel dettaglio le istruzioni per le contribuzioni sono descritte nella nel file di contributing contenuto nella cartella di documentazione di node, ma il processo può essere riassunto come segue:
- con un fork del repository
- con la creazione di un branch di lavoro
- con il setup degli strumenti per rispettare le linee guida sullo stile di node
- dopo ogni commit viene suggerito un rebase per la sincronizzazione con il repository principale
- si passa poi all'esecuzione dei test in locale 
- dopodichè con la pull request vengono avviati tutti workflow impostati
- infine con la verfica finale viene fatto il merge delle modifiche

# 3 - build automation STAFA

per la build automation node utilizza 4 strumenti
- make per la gestione del processo di build
- i compilatori gcc e g++ i relativi linguaggi
- python per l'esecuzione di alcuni target che utilizzano degli script (come l'installazione e la disinstallazione)

il file di build, cioè il makefile, si trova al primo livello di gerarchia del progetto, è presente anche un BDSmakefile per la build sui sitemi operativi bsd

le istruzioni di build sono contenute nel file BUILDING.md ma si possono riassumere in:
- installazione degli strumenti necessari
- esecuzione dello script configure per configurare i vari settaggi di node, come ???
- esecuzione del comando make

il build lifecycle di node è piuttosto vasto, i principali target sono:
- l'installazione o rimozione di node
- il target clean per rimuovere gli artefatti creati in locale
- il target coverage, che esegue una build e i test, generando una reportistica in formato html
- altri target sono ---!!!LEGGI SLIDE!!!---


# 4 - test statici STAFA

passando all'aspetto di testing introduciamo i test statici, questi test vengono soprattutto fatti dai linter per i vari linguaggi utilizzati, come eslint per javascript, cpplint per c++ e così via, le configurazioni per questi linters sono contenute nella cartella tool

per il linguaggio c++ viene poi anche usato coverity, cioè un tool per ricercare ad esmepio dead code o simili

l'esecuzione di questi test avviene con i relativi target, invocabili dal makefile, o come avviene più comunemente, dai workflow di testing

oltre ai controlli statici automatizzati le pull request ricevono anche una code review da almento 2 collaboratori prima di essere approvate

10.30min

# 5 - test funzionali CIANO

per quanto riguarda i test dinamici, partiamo da quelli funzionali, questi sono definiti nella cartella test del progetto insieme ai test non funzionali

i riferimenti per la scrittura dei test sono riportati nelle slide, in queste risorse non viene indicato il paradigma di sviluppo, ma osservando i test già presenti siamo dell'idea che venga usato il paradigma Arrange Act Assert, per la quale vengono prima definiti gli input, successivamente vengono eseguite le chiamate da testare, e infine si eseguono le assert dei risultati 

la suite per i test di unità composta da
- gtest per il codice c++
- unittest
- pytest

per quanto riguarda i test di integrazione invece viene usato:
- testgyp

---

l'esecuzione di questi test va a generare una reportistica, nel caso di node si usa codecov.io come strumento per il calcolo della coverage con pubblicazione su codecov

l'esaustività dei test e la correttezza del programma non è garantita ne dai test definiti ne dai valori di coverage, ma essendo il rapporto di bug confermati su tutte le issue molto basso, significa che i test stanno effettivamente svolgendo il loro lavoro 

# 6 - test non funzionali CIANO

continuando con i test dinamici passiamo a quelli non funzionali, questi sono i test che si preoccupano di valutare aspetti qualitativi del programma

ad esempio sono presenti test di benchmark, che valutando le performance delle diverse componenti di node e possono generare una reportistica dei risultati ottenuti

sono anche presenti gli stress test, questi vengono eseguiti nella CI di jenkins e vanno ad eseguire il target di test più volte per rilevare flaky test che verranno poi aggiunti tracciati nell'its

oltre a questi vegnono effettuati anche i sanity checks per controllare la conformità dei risultati e gli smoke test

13:20min

# 7 - cicd CIANO

per quanto riguarda la continuos integretation node si avvale di github actions e di jenkins per eseguire workflow automatici

per quanto riguarda github actions i workflow sono descritti nella cartella workflow in dot github

i workflow di node possono essere categorizzati in
- workflow di build, per eseguire una build dopo determinati push o merge
- workflow di testing e analisi statica, per eseguire i test dinamici contenuti nella cartella test o per attivare i linters
- ci sono poi workflow attivati periodicamente come ad esempio la build delle release nightly ogni 24 ore

e come detto prima l'attivazione di questi workflow avviene in diversi momenti, ad esempio durante i commit, nei merge o nelle pull request


# STAFA

andando nel dettaglio, il workflow di una build esegue 2 job, il primo è build tarball, che fa un setup degli strumenti e dell'ambiente ed infine esegue il target tarball 
il secondo è test tarball, che come prima fa un setup degll strumenti e dell'ambiente, estrae la tarball ed esegue il target di test

---

per la continuos delivery viene usato Jenkins, che in pratica è un server o servizio per l'esecuzioni di workflows

la pipeline di esecuzione su jenkins per il rilascio di una versione si compone di 2 passi:
- il primo è l'esecuzione del worflow test-pull-request che verifica la stabilità del branch con test vari
- il secondo passo va ad eseguire la build di relase

per il workflow di relase, essendo privata, non siamo riusciti a trovare la configurazione usata, ma avendo analizzato il makefile supponiamo venga probabilmente chiamato il target build-release

# 8 - artifact repo STAFA  

successivamente alla release, gli artefatti generati vengono pubblicati sul repository npm, ma vengono anche usati altri canali per artefatti di diverso genere, come ad esempio quelli che delle release nightly 

passando alla gestione delle dipendenze, 

le dipendenze di node sono contenute nella cartella deps e vengono controllate ed aggiornate con cadenza settimanale con la relativa action di github, inoltre viene sfruttata la sezione dependency graph di github insight per tenere traccia delle dipendenze nei diversi file del progetto


# 9 - configuration management tool STAFA

per la gestione delle configurazioni, lo strumento utilizzato è docker, node ha infatti un repository dedicato per le i configuration items di node, come ad esempio alpine linux e bullseye

chiudendo, la tipica struttura di questi dockerfile è:
- una parte per il download della tarball, tramite connessoine ssh
- successivamente questa taball viene estratta,
- infine vengono scaricate le dipendenze e poi viene installato node


grazie per l'attenzione
