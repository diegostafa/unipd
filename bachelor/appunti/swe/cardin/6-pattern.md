**architettura software**

* insieme di elementi che permettono di ragionare sul software stesso

ragiona su:
* vista logica --> relazione tra i moduli
* vista di implementazione --> riguarda la creazione degli artefatti
* vista di processo --> relazione tra i processi
* vista di rilascio --> riguarda la configurazione di rilascio su macchine fisiche


**scaling**

per scalare il sistema alle richieste si può
* duplicare le istanze del programma (scaling orizzontale)
* aumentare le risorse (scaling verticale)
* partizionare le richieste
    * es. le richieste vengono analizzate prima di rispondere per assegnare le risorse al meglio

**architettura a strati**

* architettura di vista logica
* definisce i seguenti layer:
    * presentation --> interfaccia utente
    * business --> logica del sistema
    * persistance
    * database --> salvataggio dei dati
* ogni layer dipende solo da quelli sottostanti (possibilmente quello direttamente sotto)
* in ogni layer ci possono essere moduli con domini diversi

problema:
* si possono creare dipendeze tra moduli in uno stesso layer con domini diversi

pro:
* testing facile
* pattern facile

contro:
* downtime di manutenzione
* rilascio complesso
* prestazioni --> si va per ogni layer
* scalabilità solo orizzontale e partizione

**architettura a strati esagonale**

* business logic al centro con le funzionalità
* ogni layer definisce in e out port
    * in --> funzioanlità invocabili (casi d'uso)
    * out --> funzionalità offerte
* le in port sono implementazioni di interfacce di ciò che si vuole usare (adapter)
* le out port sono interfacce che altri implementeranno

**microservizi**

* usa decomposizione funzionale (per ogni layer crea microservizi formati da moduli di dominio comune)
    * si parte dagli UC e attori e si evidenziano i serviizi offerti
* ogni microservizio è completamente autonomo e indipendente e non condividono persistenza
* il singolo microservizio usa solitamente un'architettura esagonale

problema:
* condivisione dati tra microservizi senza il db
* prestazioni in caso di stato distribuito

**api gateway**

intermediario alle richieste degli utenti che instrada verso il microservizio giusto

**dipendenza**

A dipende da B se la modifica di B ha probabilità di modifica di A

**albero delle dipendenze**

 è l'albero costrutio ricorsivamente delle dipendeze di una componente

```
class race{
    race(ls<car>)
}

class car{
    car(wheel, fuel, driver);
}

class wheel{
    wheel{wheelType)
}

// ....

/*
l'albero delle dipendenze di race è:
- car
    - wheel
        - wheeltype
    - fuel
        ...
    - driver
        ...

quindi per costruire race si parte a costruire a ritroso dalle foglie tutto ciò che serve
*/  

```

**convenzione repository**

le classi denominate repository vanno a recuperare i dati da un sistema di persistenza esterno (db, fs, ...)

**inversion of control**

il ciclo di vita degli oggetti è gestito da un dependecy injector

**dependency injection**

* usa l'inversion of control per somministrare le dipendenze necessarie
* il componente dichiara solo le sue dipendenze

si suddivide in
* constructor injection --> le dipendenze vengono dichiarate nella firma del costruttore
    * causa telescoping
* setter injection --> le dipendenze vengono dichiarate attraverso dei setter sulla dipendenza

**dependecy injector**

* automatizzato
* presente nei framework
* si crea una classe @configuration che va a creare degli oggetti con certi parametri
* ongi qualvolta non venga fornita una dipendenza, l'oggetto da costruire viene preso qua 

si può fare senza, cioè nel main() si costruiscono gli oggetti a mano e si passano a costruttori

**pattern**

creazionali --> come vengono instanziate le classi
* singleton
* builder
* factory method
* abstract factory

strutturali --> come vengono composte le classi
* adapter
* decorator
* facade
* proxy

comportamentali --> come collaborano le classi
* observer
* strategy
* template method

architetturale
* model view controller
* model view presenter
* model view viewmodel

**singleton pattern**

risolve:
* unicità di istanza con un unico punto di accesso

* assicurare che venga instanziato un solo oggetto di una classe
* assicurare che quell'istanza condivisa da chi la usa
* è un interfaccia che deve essere estesa dalle classi che vogliono essere singleton

implementazione:
* costruttore privato
* metodo getInstance che ritorna la classe

problemi:
* usa metodi statici

```java
interface singleton{
    static bool unique;
    private singleton{}
    singleton GetInstance(){}
}
```

**prototype pattern**

è l'interfaccia clonable

**builder pattern**

risolve:
* costruzione un tipo complesso
* separa la costruzione dalla rappresentazione interna
* non ha telescoping dei costruttori
* costruisce oggetti in modo incrementale

```java
class concreteBuilder
    private field1, field2, field2;

    public withField1 (param) : classBuilder
    public withField2 (param) : classBuilder
    public withField3 (param) : classBuilder

    public build() : class

// setta i campi in momenti potenzialmente diversi e poi crea con ciò che ha settato

/*
    fluent api --> withField1().withField(2).withField(3);
    create() --> fa i controlli necessari sui field prima di creare l'oggetto
*/
```

varianti:
* builder come classe interna della classe

**factory pattern**

risolve:
* costruisce i sottotipi di una gerarchia in modo centralizzato

```java
// gerarchia fruit

class factoryFruit{
    public makeorange(){}
    public makeapple(){}
    public makePear(){}
    // per tutti i sottotipi
}
```

**factory method pattern**

risolve:
* costruisce i sottotipi di una gerarchia in modo centralizzato

```java
// gerarchia fruit

interface factoryFruit{
    public makeorange(){}
    public makeapple(){}
    public makePear(){}
    // per tutti i sottotipi
}
```

**abstract factory pattern**

* costruisce factory diverse
* si usa quando si sa la famiglia di prodotti completa (numero fisso di oggetti in versioni diverse)

implementazione:
* interfaccia factory che ha metodi astratti di ciò che vuole costruire

```java
/*
oggetti:
- scrollbar
- button
- menu

famiglie
- windows
- osx
- linux

gerarchia
- windowsfactory
    - scrollbar
    - button
    - menu
- osxFactory
    - scrollbar
    - button
    - menu
- linuxFactory
    - scrollbar
    - button
    - menu

*/

// struttura

interface abstractFactory {
    abstract buildA() : A;
    abstract BuildB() : B;
}

class factoryA implements abstractFactory{
    override buildA() : A;
    override BuildB() : B;
}

class factoryB implements abstractFactory{
    override buildA() : A;
    override BuildB() : B;
}

class client{
    private asbtractFactory fac;

}

```

**adapter pattern**

risolve:
* usare una classe esistente ma con interfaccia incompatibile
* riusare una classe che opera con classi non previste

* permette di adattare una classe ad un'interfaccia
* class adapter non permette di adattare i sottotipi
* class adapter non funziona se la classe è final
* di base è un wrapper

implementazione per composizione (object adapter)
```java
// interfaccia nostra
interface polygon {
    // metodi astratti
}

// classe di una libreria esterna non modificabile
class rectangle {
    // ...
}

// classe che adatta rectangle ed è anche un polygon
class rectangleAdapter implements polygon {
    private rectangle r;
    // implementa i metodi astratti usando i metodi di rectangle

}
```

implementazione per ereditarietà (class adapter)
```java
// interfaccia nostra
interface polygon {
    // metodi astratti
}

// classe di una libreria esterna non modificabile
class rectangle {
    // ...
}

// classe che adatta rectangle ed è anche un polygon
class rectangleAdapter extend rectangle implements polygon {
    // implementa i metodi astratti usando i metodi di rectangle

}
```

**decorator pattern**

* estende un tipo senza usare erediterietà, ma usando solo combinazioni
* permette di estendere le funzionalità a runtime (invece il builder crea e basta, non può aggiungere roba dopo la creazione)
```java
// classe da estendere senza fare gerarchie infinite
interface pizza;

interface toppedPizza implements pizza{
    private pizza base;
    abstract decorate();
}

// classi di decorazione
class mozzarella implements toppedPizza{
    // decorate() che aggiunge mozzarella
}
class patatine implements toppedPizza{
    // decorate() che aggiunge patatine 
}

// permette di fare
pizza p = new patatine( new mozzarella(new pizza)

```

**facade pattern**

* consiste nel creare un'interfaccia semplice da molti classi
* bisogna rendere facade il più semplice possibile
* facade dovrebbe chiamare nei suoi metodi almeno uno dei suoi attributi, possibilmente tutti
* solitamente usato con singleton

```java
// classi complesse
class c1;
class c2;
class c3;

class facade{
    private c1;
    private c2;
    private c3;

    // metodi esposti che facilitano l'uso di c1,c2,c3
}
```
    
**proxy pattern**

* crea una classe proxy ad un'altra classe
* aggiunge un livello di indirettezza
* redirige le chiamate che riceve all'oggetto reale

si suddivide in:
* remote proxy --> mocka un oggetto remoto
* virtual proxy --> simula un oggetto che può anche non esistere, creandolo al volo quando serve
* protection proxy --> gestisce le autorizzazioni


```java
interface abstractC;

class concreteC implements abstractC{}

class proxyC implements abstractC{
    private concreteC ref;
}

// il client usa concreteC attraverso il proxy
```

**observer pattern**

* subject --> classe che vuole essere osservata
    * non deve sapere chi lo osserva
* observer --> classe che osserva i cambiamenti di un subject

```java
abstract class subject{
    private list<observer> o;

    public attach(){}
    public detach(){}
    protected notify(){
        // chiama update() per ogni observer in lista
    }
    public getState();
}
interface observer{
    abstract public update();
}

class concreteS implements subject{
    public getState(){}
}

class concretO implements observer{
    private subject s;
    public update(){
        // l'observer egge i cambiamenti con s.getState() e poi aggiorna il suo stato
    }
}

// concreteS dovrà chiamare notify() su se stesso ogni qual volta modifica il suo stato
```

**strategy pattern**

* si usa quando ci sono diverse classi con stessa interfaccia ma diverso comportamento
* diverse versioni di uno stesso algoritmo

```java
interface context{
    public contextInterface();
}

interface strategy{
    public algorithm(context c);
}

class concreteStartegyA implements strategy{}
class concreteStartegyB implements strategy{}
```

**template method pattern**

* diverse versioni di uno stesso algoritmo ma con stesso scheletro
* l'implementazione verrà fatta dalla sottoclassi

```java
abstract class abstractClass{
    
    // metodi che verranno implementate
    public operation1();
    public operation2();

    public templateMethod(){
        // usa operation1() e 2 come segnaposto
    }

}

class concreteClass{
    public operation1(){}
    public operation2(){}
}

// se la classe astratta implementa i metodi di operazione allora questi si dicono hookm, cioè operazioni di default
```

**model view controller pattern**

* model --> business logic
    * subject
* view --> presentation logic
    * rispecchia il modello
    * observer del model
    * subject
* controller --> application logic
    * stato di transizione da presentazione a business
    * si occupa di validazione
    * observer della view

**model view presenter pattern**

* model --> business logic
    * subject
    * interagisce solo con presenter
* view
    * pura grafica
    * non esegue calcoli
    * deve implementare un'interfaccia
* presenter --> presentation e application logic
    * si occupa della comunicazione view-model
    * ha un attributo view (interfaccia) e un model
    * osserva il modello

**model view viewmodel pattern**

* model --> business logic
    * subject
* view --> presentation logic
    * osserva il viewmodel
    * ha riferimento a presenter
* viewmodel
    * subject
    * observer di view e model
    * ha uno pesudo stato interno che rappresenta il model che aggiorna osservando il model

**command pattern**

* per fare richieste senza sapere i dettagli interni
* execute non ha bisogno di parametri perchè la logica business viene fatta dal receiver con i parametri forniti da concreteCommand

```java
class invoker{
    public invoke(command c){
        // chiama i command
    }
}

abstract class command{
    public execute();
}

class concreteComand implements command{
    public execute(){
        // chiama il receiver per eseguire l'azione
    }
}

class receiver{
    public action(){
        // business logic
    }
}

class client{
    void main{
        invoker i;
        concreteCommand cc;
        i.invoke(cc)
    }
}
```