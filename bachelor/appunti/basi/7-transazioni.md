# Transazioni

una transazione è una parte di programma formata da 3 componenti:
* fase di begin-transaction
* corpo della transazione
* fase di end transaction
    * commit work --> vengono salvati gli effetti della transazione
    * rollback work/abort --> vengono annullati gli effetti della transazione

la fase di end transaction viene di solito implementata nel programma con un if-then-else, nella quale viene decisa la legalità della transazione

```sql
/* esempio di transazione che esegue una transazione monetaria tra 2 persone*/

/*fase di begin transaction*/
start transaction;

/* corpo da eseguire */
update ContoCorrente
    set saldo = saldo + 10
    where num_conto = 12201;
update ContoCorrente
    set saldo = saldo - 10
    where num_conto = 42177;

/*fase di end transaction*/
commit work;
```

le transazioni in un DBMS non vengono eseguite in ordine di arrivo, ma in ordine tale da rispetare i vincoli ACID

**ACID**

ogni transazione deve egarantire le proprietà ACID:
* Atomicità --> gestione affidabilità
* Consistenza --> gestione concorrenza
* Isolamento --> gestione concorrenza
* Durabilità --> gestione affidabilità

**Atomicità**

ogni transazione è effettuata o completamente o viene annullata

di base c'è un rollback automatico se si verificano errori nel mezzo della transazione

**Consistenza**

ogni transazione deve rispettare i vincoli della base di dati

i vincoli devono essere rispettati a fine transazione, nel mentre possono anche essere violati

**Isolamento**

una transazione non deve essere influenzata da un'altra transazione

quindi una transazione non espone i suoi stati intermedi

**Durabilità**

ogni transazione deve essere registrata permanentemente

le transazione deve essere in grado di resistere a:
* crash del DBMS --> soft crash
    * si perde la primaria (RAM) ma non la secondaria (HDD)
* failures della memoria fisica --> hard crash
    * si perde anche la secondaria ma non la stabile (RAID)

## Gestione dell'affidabilità

la gestionde dell'affidabilità garantisce le proprietà di atomicità e durabilità

**log**

il DBMS utilizza un log che registra permanentemente tutte le operazione svolte, il log delle operazioni è salvato su memoria stabile e ridondante (RAID e nastri))

il log registra:
* transazioni:
    * B(T) --> begin transaction T
    * I(T,O,AS) --> T esegue un'insert dell'oggetto O con valore AS
    * D(T,O,BS) --> T esegue una delete dell'oggetto O con valore BS
    * U(T,O,BS,AS) --> T esegue un update BS->AS
    * C(T) --> commite transaction T
    * A(T) --> abort transaction T
* record di sistema
    *  --> dump
    * C(T1,T2,T3...) --> checkpoint
 
il log può essere scritto in 2 modi:
* write-ahead-log --> prima di ogni operazione
* commite-precedence --> prima di ogni commit

**modalità di esecuzione delle transazioni**

dopo la scrittura sul log, le operazioni possono essere eseguite nel DBMS in 3 modalità:
* immediata --> dopo ia scrittura sul log
    * in caso di abort si deve fare l'undo
        * I(T,O,AS) --> D(T,O,AS)
        * U(T,O,BS,AS) --> U(T,O,AS,BS)
* differita --> dopo il commit
    * * in caso di abort NON si deve fare l'undo
* mista --> nei momenti idle del DBMS

**checkpoint**

il checkpoint è una transazione che registra quali transazioni sono attive in quel momento

l'esecuzione di un checkpoint effettua le seguenti operazioni:
1. halt del DBSM
2. ogni transazione completata prima del checkpoint viene scritta in memoria stabile
3. ogni transazione in corso prima del checkpoint viene scritta nel log
4. riparte il DBMS

**stato delle transazioni**

una transazione si può trovare in 3 stati:
* completata (hanno fatto il commit) ed eseguita
* completata ma non eseguita completamente (REDO)
* non completata (UNDO)

**warm restart**

sono le operazioni che un DBMS esegue dopo un soft crash:
1. legge l'ultimo checkpoint nel log
2. crea 2 insiemi
    * REDO --> transazioni non eseguite
    * UNDO --> transazioni non completate
3. legge il log a ritroso fino l'ultima transazione UNDO e REDO
    * nel mentre annulla ogni transazione UNDO che incontra
4. legg il log fino alla più nuova transazione REDO
    * nel mentro riesegue ogni transazione REDO che incontra

a seconda del tipo di esecuzione delle operazioni del DBMS, varia la ripresa a caldo:
* modalità immediata --> niente REDO
* modalità differita --> niente UNDO
* modalità mista --> sia UNDO che REDO

il dbms deve implementare le operazioni di redo e undo in modo tale che:
* redo(redo(T)) = redo(T)
* undo(undo(T)) = undo(T)

di base rieseguire più volte una stessa transazione è come eseguirla una volta sola, annullarla più volte è come annullarla la prima

**Dump**

il dump è una copia totale della base di dati nella memoria stabile

un dump crea un record nel log delle operazioni che indica quando questo è stato effettuato

**cold restart**

sono le operazioni che un DBMS esegue dopo un hard crash:
1. ripristina la base di dati con l'ultimo dump
2. si eseguono le operazioni sul log fino al guasto
3. si esegue la warm restart

**modello fail-stop**

è il modello di esecuzione di un dbms, è composto tra 3 stati:
* normal --> il DBMS funziona correttamente
* stop --> il DBMS va in halt e necessita un warm/cold restart
* restart --> il DBMS fa un warm/cold restart

gli stati sono collegati nel seguente modo:
* normal --> crash --> stop
* stop --> boot --> restart
* restart --> crash --> stop
* restart --> success --> normal

## Gestione della concorrenza

si indicano con:
* r1(X) --> la transazione 1 legge X
* r2(Y) --> la transazione 2 legge Y
* w1(X) --> la transazione 1 scrive X
* w2(Y) --> la transazione 2 scrive Y

**anomalie**

una situazione di concorrenza tra transizione può generare 5 anomalie
* perdita di aggiornamento
    * r1(x)r2(x)w1(x)w2(x) --> w1(x) è come se non fosse mai stato esguito
* lettura sporca --> lettura di un dato che di un'altra transazione abortita
* lettura inconsistente --> una transazione legge lo stesso dato in 2 momemnti distinti, ma nel mezzo una'altra transazione lo modifica
* aggiornamento fantasma --> un dato viene aggiornato improvvisamente
* inserimento fantasma --> un dato viene creato improvvisamente

**flags di isolemento read-only**

sono flags con livello crescente di isolamento:
* read-uncommitted (RU)
* read-committed (Rc)
* repeatable read (RR)
* serializable (S)

```sql
/* sintasi */

begin transaction isolation level,
read committed
```
livello di protezione:
* RU --> perdita aggiornamento
* RC --> RU + lettura sporca
* RR --> RC + lettura inconsistente + aggiornamento fantasma
* S --> RR + inserimento fantasma

**scheduler**

è un sistema che acccetta/rifiuta/riordina le operazioni di una transazione

**ordinamento delle transazioni**

rappresenta l'ordine temporale delle operazione delle transazioni

definizioni preliminari:
* legge-da --> r1(x) legge da w2(X) se w2(x) precede r1(x) nell'ordinamento e non ci sono scritture di X nel mezzo
* scrittura finale --> w1(x) è la scrittura finale di X se w1(x) è l'ultima scrittura di X nell'ordinamento

**conflitto**

2 transazioni a<sub>i</sub> e a<sub>j</sub> con (i!=j) sono in conflitto se operano in:
* write-read
* read-write
* write-write

**ordinamento seriale**

si indica con:
* S<sub>1</sub> : r1(x)r2(Z)w1(x)w2(z)

un ordinamento seriale non ha anomalie

**ordinamento serializzabile**

un'ordinamento delle transizioni è serializzabile se comunque eseguito, produce lo stesso risultato di un ordinamento seriale

l'idea di base è di eseguire le transizioni concorrentemente in un ordinamento serializzabile

**view-equivalenza**

2 ordinamenti sono equivalenti sse:
* hanno gli stessi legge-da
* hanno le stesse scritture finali

**view-serializzabilità**

si indica con VSR

un ordinamento è view-serializzabile se è view equivalente ad un qualche ordinamento seriale

la proprietà di view-seriallizzabilità garantisce protezione da:
* perdita di aggiornamento
* letture incosistenti
* aggiornamento fantasma

per verfiicare la view serializzabilità:
* si deve provare la view equivalenza su tutte le possibili permutazioni dell'ordinamento

non è eseguito al lato pratico

**conflict-equivalenza**

2 ordinamenti sono conflict-equivalenti se:
* hanno stesse operazioni
* ogni conflitto appare nello stesso ordine

**confilict-serializzabilità**

si indica con CSR

un ordinamento è conflict-serializzabile se è conflict-equivalente ad un qualche ordinamento seriale, oppure se l'equivalente grafo dei conflitti è aciclico

proprietà:
* CSR implica VSR

**grafo dei conflitti**

si crea un grafo con:
* un nodo per ogni transazione
* un arco orientato da t<sub>i</sub> -> t<sub>j</sub> per ogni conflitto

il grafo è aciclico se non esistono cicli all'interno, quindi se partendo da un nodo non si può tornare allo stesso nodo

traduzione in ordinamento seriale:
1. si scrivono tutte le operazioni di un nodo senza archi entranti
2. si rimuove il nodo e i suoi archi uscenti
3. passo 1

**lock**

di base quando una transazione può effettuare 3 tipi di operazione:
* r_lock --> blocca la risorsa quando legge
* w_lock --> blocca la risors quando scrive
* unlock --> rilascia la risorsa

**tavola dei conflitti**

per ogni risorsa c'è:
* un contatore che indica quanti lettori sulla risorsa
* un bool che indica un w_lock sulla risorsa

funzionamento:
* r_lock
    * risorsa unlocked --> set r_locked && contatore++
    * risorsa r_locked --> contatore++
    * risorsa w_locked --> reject
* w_lock
    * risorsa unlocked --> set w_locked
    * risorsa r_locked --> reject
    * risorsa w_locked --> reject
* unlock
    * risorsa unlocked --> reject
    * risorsa r_locked --> if --contatore < 0 set unlocked
    * risorsa w_locked --> set unlocked

**locking a 2 fasi**

le transazioni acquisiscono i lock nella fase iniziale, ma non possono più acquisirne altri in quella finale 