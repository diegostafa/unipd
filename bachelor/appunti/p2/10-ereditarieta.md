## Ereditarietà

implementa la relazione di classe di generalizzazione, una classe viene definita come un'altra classe più qualcos'altro

terminologia:
* classe base, superclasse, supertipo, padre
* classe derivata, sottoclasse, sottotipo, figlio
* sottotipo proprio significa che è diverso dalla classe base

rappresentazione testuale di una gerarchia:
* sottoclasse <= superclasse

i casi d'uso tipici dell'ereditarietà sono:
* estensione di un tipo
    * la sottoclasse aggiunge funzionalità alla superclasse
* specializzazione di un tipo
    * la sottoclasse è un tipo concreto della superclasse astratta
* ridefinizione di un tipo
    * la sottoclasse reimplementa i metodi della superclasse (override)
* riutilizzo di codice
    * non c'è vera ereditarietà, la sottoclasse riutilizza solo il codice, senza subtyping

**gerarchie di classi**

un sottotipo/sottoclasse di dice diretto se deriva direttamente da una classe, indiretto se ci sono uno o più livelli di indirettezza tra il sottotipo e la superclasse

**subtyping di tipo**

vale solo per l'ereditarietà pubblica
è una forma di polimorfismo sui tipi, nella quale il sottotipo è un tipo di dato è in relazione ad un altro tipo di dato, mediante il concetto di sustituibiità
di base quindi funzioni che operano su una superclasse devono operare normalmente anche sulle sue sottoclassi

**subtyping su puntatori**

è il polimorfismo, un puntatore ad una superclasse deve tranquillamente poter puntare ad una sottoclasse

**subtyping su riferimenti**

come per i puntatori

**protected**

protected significa accessibile mediante sottoggetti
di base è la stessa cosa con il private, fuori dalla classe nemmeno un oggetto della classe stessa può accedere ai membri privati, nello stesso modo, la classe stessa non può accedere nemmeno alla parte protetta

**tipi di ereditarietà**

ci sono 3 tipi di ereditarietà:
* sottoclasse : public superclasse --> ereditarietà di tipo
    * i membri privati della superclasse sono inaccessibili alla sottoclasse
    * i membri protetti della superclasse vengono ereditati come membri protetti 
    * i membri pubblici della superclasse vegnon ereditati come membri pubblici
* sottoclasse : protected superclasse --> viola information hiding, poco utilizzato
    * i membri privati della superclasse sono inaccessibili alla sottoclasse
    * i membri protetti della superclasse vengono ereditati come membri protetti 
    * i membri pubblici della superclasse vengono ereditati come membri protetti 
* sottoclasse : private superclasse --> riutillizzo di codice, non supporta subtyping
    * i membri privati della superclasse sono inaccessibili alla sottoclasse
    * i membri protetti della superclasse vegnono ereditati come membri privati
    * i membri pubblici della superclasse vegnono ereditati come membri privati

**ereditarietà privata vs has-a**

similarità:
* entrambi creano un sottooggetto
* non c'è subtyping

differenze:
* è necessaria la relazione di composizione se servono più oggetti
* l'ereditarietà privata introduce l'ereditarietà mulitpla non necessaria
* l'ereditarietà privata permette il subtyping di puntatore (polimorfismo)
* l'ereditarietà privata da accesso alla parte protetta

**ereditarietà ed amicizia**

le dichiarazioni di amicizia NON sono ereditabili

**ridefinizione dei campi**

una sottoclasse può ridefinire i campi della superclasse (ad esempio cambiandone tipo)

**ridefinizione dei metodi**

una sottoclasse può reimplementare i metodi della superclasse

**name hiding rule**

la ridefinizione di un metodo in una sottoclasse nasconde sempre il metodo della superclasse (solo accessibile tramite scoping)

vuol dire che metodi anche con argomenti diversi vengono nascosti da una sottoclasse che ridefinisce il metodo

**costruttore di default**

i costruttori delle sottoclassi possono contenere chiamate ai costruttori della superclasse nella lista di inizializzazione

l'ordine di costruzione del compilatore è:
* prima il sottoggetto
* poi i membri dati

la costruzione avviene nel seguente modo:
1. viene sempre invocato implicitamente o eplicitamente il costruttore di default del sottoggetto
2. vengono costruiti i campi della sottoclasse
3. viene eseguito il corpo del costruttore

**costruttore di default standard**

in assenza di un costruttore di default definito dall'utente, quello standard del compilatore si preoccuperà della costruzione, nel seguente modo:
1. viene invocato il costruttore di default del sottoggetto
2. vengono costruiti i campi dati con il loro costruttori di default

costruttore di default standard:
* Classe() : superclasse(), d1(), d2(), ... {}

**costruttore di copia**

la costruzione di copia ridefinita costruisce di **default** i membri della classe non costruiti esplicitamente

**costruttore di copia standard**

la costruzione di copia standard funziona nel seguente modo:
1. il sottogetto dell'oggetto di invocazione viene creato di copia con il parametro del costruttore di copia
2. i membri dati dell'oggetto di invocazione vengon creati di copia con i membri dati del parametro del costruttore di copia

costruttore di copia ridefinito:
* Classe(const Classe& c) : superclasse(c), d1(c.d1), d2(c.d2), ... {}

**assegnazione standard**

si comporta nel seguente modo:
1. il parametro viene assegnato al sottoggetto dell'oggetto di invocazione
2. campo per campo vengono assegnati il membri dati del parametro all'oggetto di invocazione

**distruzione standard**

si comporta nel seguente modo:
1. invoca il distruttore sui membri dati
2. invoca il distruttore sul sottoggetto

**ereditarietà multipla**

definisce una relazione tra un entità figlia e più entità padri

probelemi:
* complessità/ambiguità
* problema del diamante

in c++ viene implementata tramite l'ereditarietà virtuale
 
```c++
// sintassi

#include "orario.h"
#include "data.h"

class dataora : public data, public ora
{
    // ...
};
```

**ambiguità**

con ereditarietà multipla si crea ambiguità tra metodi con lo stesso nome in superclassi diverse

soluzione:
* scoping dei metodi
* ridefinizione del metodo nella sottoclasse (nasconde l'ambiguità e costringe lo scoping)

**problema del diamante**

accade quando nell'ereditarietà multipla le superclassi ereditano da una stessa superclasse

```c++
// situazione a diamante

class A;

class B : public A;
class C : public A;

class D : public B, public C;

/* 

situazione in memoria di un oggetto D

D               
    B
        A
    C
        A

- il sottoggetto A occupa i doppio dello spazio
- ambiguità di subtyping

*/
```

problemi:
* si crea ambiguità tra i sottoggetti A quando si fa subtyping di puntatore o quando
* si crea un doppio sottoggetto A, spreco di memoria

soluzione:
* derivazione virtuale (non centra nulla con i metodi virtuali)

**derivazione virtuale**

fa sì che non si creino 2 sottoggetti, ma ne venga creato solo uno

```c++
class A; // detta anche base virtuale

class B : virtual public A; // passo di derivazione virtuale
class C : virtual public A; // passo di derivazione virtuale

class D : public B. public C; // derivazione finale

/* 

situazione in memoria

D               
    B
        A*
    C
        A*
    A

- B e C guadagnano un puntatore nascosto al sottoggetto A
- il sottoggetto A è unico
- non c'è ambiguità di subtyping
- D si deve occupare di inizializzare A
*/
```

a differenza della normale ereditarietà, le classi si devono occupare di inizializzare i sottoggetti delle superclassi e anche i sottoggetti delle basi virtuali

siccome la base si occupa di inizializzare la base virtuale, quando si crea un oggetto, vengono ignorate le chiamate ai costruttori delle superclassi alla base virtuale

funzionamento del costruttore:
1. vengono invocati i costruttori delle basi virtuali
    * in presenza di più basi virtuali l'ordine è quello di precedenza, left to right - top bottom
    * la costruzione di una base vrtuale implica automaticamente la costruzione delle sue superclassi
2. vegono richiamati i costruttori delle basi dirette
    * questi costruttori vanno ad ignorare i chiamate ai costruttori delle basi virtuali
3. vengono costruiti i campi
4. viene eseguito il corpo


**unique final overriding**

in una derivazione virtuale, se le base virtuale ha un metodo virtuale, e le due sottoclassi ne fanno l'overriding, la sottoclasse finale DEVE fare l'overriding del metodo virtuale della base virtuale

di base la classe sottoclasse deve fare l'overriding di ogni metodo virtuale della base virtuale 

**visibilità con derivazioni virtuali**

```c++
class A;

class B : virtual private A;
class C : virtual public A;

class D : public B, public C; // prevale la derivazione più aperta

```

**costruttore di default**

il costruttore di default si deve occupare di costruire nel seguente ordine:
* basi virtuali nel corretto ordine
* le basi dirette
* i campi della classe

costruttore di default standard:
* Classe() : base_virtuale(), base_diretta(), ... , f1(), f2() ... {}

**costruttore di copia**

il costruttore di copia segue le stesse regole della costruzione di default, ma utilizza il parametro per costruire di copia

costruttore di copia ridefinito:
* Classe(const Classe& c) : base_virtuale(c), f1(c.f1) ... {}
    * i campi e sottoggetti non inizializzati vengono rimpiazzati da chiamate ai rispettivi costruttori di DEFAULT

costruttore di copia standard:
* Classe(const Classe& c) : base_virtuale(c), base_diretta(c), f1(c.f1), f2(c.f2) ... {}