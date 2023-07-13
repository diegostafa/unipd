**diagrammi delle classi**

* rappresentano classi
* un riquadro rappresenta una classe
* il nome è l'unica parte obbligatoria

* il riquadro delle eccezioni indica tutte le eccezioni sollevabili dalla classe 
* gli attributi derivabili sono preceduti da "/"

**molteplicità**

* 1 --> uno ed uno solo
* 0..1 --> opzionale
* 0..* --> 0 a n

molteplicità n corrisponde a liste

**visibilità**

* "-" --> privato
* "+" --> pubblico
* "#" --> protetto
* "~" --> package

**attributi**

2 modi per inserirli:
* all'interno del riquadro:
    * visibilità nome: tipo
* per relazione
    * si collegano 2 classi e si mette il nome dell'attributo nella freccia e la molteplicità
    * classe __ ha un __>1 classe
    * METTERE LA FRECCIA, altrimenti indica dipendenza circolare


si usa il primo modo quando l'attributo è primitivo, se è una classe si usa il secondo

* gli attributi/metodi statici sono sottolineati
* quelli readonly/immutabile seguono un [readonly]/{frozen} dopo il loro tipo
* le classi enum hanno <<enum>> sopra il nome
* le classi parametriche hanno un riquadro  tratteggiato in alto a destra
    * la relazione tra derivatae che istanzia il template si chiama bind
* classi thread hanno un doppio bordo verticale

**operazioni**

* visibilità nome(parametri) tipo di ritorno
* i parametri e il tipo di ritorno possono avere modificatori in/out/inout
    * in --> passaggio per valore (dafault)
    * out --> passaggio per out
    * inout --> passaggio per riferimento
    * corrispondono a passaggio per valore, riferimento o out di c#

* operazione --> firma
* metodo --> implementazione

**relazioni tra classi**

* modificare un elemento implica modificarne un altro
* il livello dipende dalla quantità di tempo che una classe lavora con un'altra classe

massimo livello quando viene derivata una classe concreta

**dipendenza**

* avviene su call, create
* indicato da freccia tratteggiata

**associazione**

* una classe ha un riferimentoa ad un'altra classe come attributo

**aggregazione**

* parte di
* come associazione ma la classe costruisce il riferimetno, quindi deve sapere come costruirlo
* un tipo è attributo di un altro tipo
* è la classe a creare l'oggetto di dipendeza, non gli viene fornito
* non esiste l'uno senza l'altro
* indicato da linea continua con diamante vuoto

es
* un post appartiene ad una categoria
    * il ciclo di vita della categoria non è influenzato dal post
    * altri post possono avere lo stesso tag

**composizione**

* ha un
* come aggregazione, ma
    * gli oggetti creati non possono essere condivisi
    * il creatore può ditruggere il creato
* indicato da diamante pieno

es:
* un post ha dei commenti
    * i commenti non possono essere condivisi da post

**associazione**

* modella un'associazione
* una persona ha dei lavori, in un'azienda lavorano delle persone --> l'associazione modella il lavoro che mette in relazione persone e aziende
* non hanno corrispettivo codice
* si indica con una linea tratteggiata collegfata alla composizione di attributi

es:
* un account ha delle entry, una entry appartiene a un account,  

**generalizzazione**

* è l'ereditarietà
* ogni oggetto A può essere sostituito da B
* indicata da una freccia vuota
    * tratteggiata --> classe estende interfaccia
    * continua --> classe estende classe oppure interfaccia estende interfaccia
* indicata da linea continua se l'interfaccia è a lollipop

**recap frecce**

```
freccia tratteggiaata       ------> dipendenza
freccia continua piena      ______> associazione
diamante vuoto              < >____ aggregazione
diamante pieno              <#>____ composizione
freccia continua vuota      _____|> generalizzazionne classe-classe
freccia tratteggiata vuota  -----|> generalizzazione classe-interfaccia o interfaccia-interfaccoa
linea continua              _______ generalizzazione interfaccia lollipop
```

**grado di dipendenza**

numero di righe dipendenti diviso numero di righe totali della classe bersaglio

**classi astratte**

si può indicare in 2 modi:
* con {asbtract} tra parentesi graffe sopra una classe o alla fine di un metodo
* con il nome della classe o del metodo in corsivo 

**interfaccia**

* classe astratta pura
* modellata in 2 modi
    * con un pallino vuoto e il nome e metodi sotto
    * come una classe normale ma si aggiunge <<interface>>
* NON PUÒ CONTENERE ATTRIBUTI
* può far uscire solo relazioni di dipendenza o generalizzazione

**package**

* raggruppamento di classi
* ogni classe può appartenere ad un solo package
* de base sono cartelle --> possono contenere altre cartelle
* stabilisce un namespace
* ogni classe può vedere le classi nello stesso package, ma non quelle fuori. tranne se pubbliche


* si può usare una classe facade pubblica che si interfaccia all'esterno

**principi di progettazione**

* common closure principle --> package di classi divisi in layer di comunicazione
* common reuse principle --> package contengono classi che verranno modificate insieme 
