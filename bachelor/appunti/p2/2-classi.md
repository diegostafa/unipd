## Classi e oggetti

**classi**

il concetto di classe implementa il concetto di ADT in programmazione

una classe è quindi formata da:
* dichiarazione --> campi e metodi
* definizione --> implementazione metodi

concetti base:
* le variabili di una classe si chiamano campi
* le funzioni di una classe si chimano metodi
* le istanze di una classe sono chiamate oggetti
* l'oggetto su cui viene invocato un metodo è chiamato oggetto di invocazione

**oggetti**

ogni istanza ha la sua porzione di memoria nello stack

**metodi**

i metodi sono unici tra tutti le istanze di una classe, il binding tra metodo e istanza avviene tramite il parametro formale nascosto 'this'

**this**

è il parametro formale che ogni metodo contiene, è un puntatore al tipo della classe

il parametro attuale è implicitamente passato ad ongi invocazione:
* oggetto.metodo() --> interfaccia
* metodo(&oggetto) --> implemntazione

si utilizza il this solo con:
* ambiguità tra parametri e campi
* per ritornare l'oggetto di invocazione

**specificatori di accesso**

* strutture --> tutto pubblico
* classi --> tutto privato

**campi statici**

sono campi comuni a tutte le istanze, non si possono inizializzare all'interno di una classe, si inizializzano fuori nella seguente forma:
* T nomeClasse::var = ... ;

**metodi statici**

sono metodi di una classe che non contengono il puntatore this, ed hanno quindi i seguenti vincoli:
* non si può accedere ai campi non statici
* non si può utilizzare il this

**modificatore friend**

è un modificatore solo interno ad una classe, consente di dare visbilità alla parte privata ad un'altra funzione o classe

friend ad una funzione:
* friend T nomeFunzione(params);

friend ad una classe:
* friend class nomeClasse;

**esempio classe orario**

```c++
// orario.h
class orario{
    private:
        int sec;
    public:
        int Ore();
        int Minuti();
        int Secondi();
}

// orario.cpp
int orario::Ore() { return sec / 3600; }
int orario::Minuti() { return (sec / 60) % 60; }
int orario::Secondi() { return sec % 60; }
```

## Costruttori

**costruttori**

sono metodi speciali che hanno lo scopo di inizializzare gli oggetti di una classe

sintassi:
* *className*(...){///}

uso:
* costruttore standard --> *nomeClasse* var;
* costruttore di default --> *nomeClasse* var(...);
* costruttore di copia --> *nom eClasse* var = *nomeClasse*(...);

**costruttore di default**

è un costruttore con 0 parametri formali

**costruttore standard**

è un costruttore di default creato implicitamente dal compilatore in assenza di un QUALSIASI tipo di costruttore, 
il costruttore standard di un oggetto chiama il costruttore standard per ogni campo dell'oggetto

**costruttore di copia**

costruttore invocato durante un'assegnazione che inizializza un oggetto non ancora inizializzato

firma:
* *className*(const obj&) --> obj è un riferimento a obj costante

viene automaticamente invocato quando:
* un oggetto viene dichiarato ed inizialiazzato con un altro oggetto
* quando si passa un paramentro per valore
* quando si ritorna per valore

**costruttore di copia standard**

è il costruttore di copia definito dal compilatore in assenza di un costruttore di copia, il costruttore di copia standard fa una shallow copy dell'oggetto (copia campo per)


**comportamento del costruttore**

data una classe con n campi dati di qualsiasi tipo ed un qualsiasi costruttore, il comportamento del costruttore è quanto segue:
1. per ogni tipo primitivo viene allocato il corrispondente spazio non inizializzato
2. per ogni tipo definito da utente viene invocato il suo costruttore di default
3. viene eseguito il codice interno al costruttore

nb: lil compilatore segue l'ordine di dichiarazione dei campi


**lista di inizializzazione**

sintassi:
* classe() : campo1(X1), campo2(X2) ... , parN(XN){}

di base modifica il passo 2 del comportamento del costruttore, invece di invocare il costruttore di default per quei campi, chiama i[{l costruttore di copia con gli oggetti specificati

vantaggi:
* non si inizializza tramite un'assegnazione, ma si usa il costruttore di copia
* campi dati riferimento

**firma dei costruttori standard**

default:
* C() : x1() , x2, ... , xn() {}

copia: 
* C(const C& obj) : x1(obk.x1) , x2(obj.x2) , ... , xn(obj.xn) {}

## Conversioni di tipo

**conversione implicita**

ogni costruttore è un costruttore convertitore quando in un assegnazione/copia si assegna un oggetto ad un altro oggetto di tipo diverso

un espressione del tipo:
* *className* obj1 = obj2;

significa costruire l'oggetto obj con l'oggetto obj2, si possono verificare 2 casi:
* obj1 e obj2 hanno stesso tipo --> viene invocato il costruttore di copia
* obj2 ha un tipo diverso:
    1. viene invocato costruttore(obj2) se esiste che crea un oggetto temporaneo
    2. viene assegnato l'oggetto temporaneo
    3. viene deallocato l'oggetto temporaneo

se il costruttore viene definito con la keyword *explicit* tutto questo non succede automaticamente ma bisogna invocare il costruttore esplicitamente

**conversione esplicita**

si possono definire conversioni esplicite dal tipo della classe a un tipo qualsiasi

firma:
* operator *tipo*();


## Distruttori

il distruttore è un metodo che va a deallocare ogni risorsa quando un oggetto viene distrutto

il costruttore viene invocato automaticamente nelle seguenti condizioni:
* oggetti statici --> all'uscita dal main()
* oggetti automatici --> all'uscita dal blocco di definizione (pop del call stack)
* oggetti dinamici --> all'invocazione dell'operatore *delete*
* oggetti annidati --> alla distruzione del parent

in particolare nell funzioni l'ordine di invocazione del costruttore è il seguente:
* sulle variabili locali
* sui parametri passati per valore
* sul temporaneo anonimo ritornato per valore

oggetti automatici/statici che hanno stesso tempo di vita (definiti nello stesso blocco) vengono distrutti nel modo inverso in sono stati costruiti


comportamento del costruttore:
1. viene eseguito il corpo (se esiste) del costruttore
2. vengono chiamati i distruttori per i campi dati nell'ordine inverso alla loro lista di dichiarazione
    1. per ogni tipo primitivo e derivato viene rilasciata la memoria occupata
    2. per i tipi classe viene invocato il distruttore della classe


**distruttore standard**

è il distruttore creato automaticamente dal compilatore in assenza di un distruttore esplicito, di base chiama il distruttore standard per ogni campo dato della classe in ordine inverso

**distruzione profonda**

è un distruttore che va a deallocare anche i referimenti dei puntatori e la memoria occupara sull'heap

**rule of three**

se si ridefinisce un distruttore, costruttore di copia o operatore di assegnazione, probabilmente bisogna definirli tutti e tre

**reference counting**

di base è il processo di contare da quanti oggetti e referenziata una risorsa (quanti puntatori puntano allo stesso elemento)

**smart pointer**

è un ADT che incpsula i puntatori e implementa il reference counting, nello standard il tipo è std::shared_ptr

## information hiding

**dichiarazioni incomplete**

una dichiarazione incompleta è la seguente:
* classe c;

si definisce il nome della classe, ci si preoccupa della sua implementazione successivamente, questa tecnica è utile per nascondere la parte privata negli header file, in una sintassi del tipo:

class orario_rappr{
    private:
        class orario;
        orario* o;
    public:
        // ...
}

in questo caso la classe orario viene solo dichiarata, la sua implementazione va fatta su un file differente, cioò consente di nascondere l'implementazione di orario

di base si implemnta l'information hiding degli header files tramite una classe wrapper formata da una dichiarazione incompleta e un puntaore alla classe
