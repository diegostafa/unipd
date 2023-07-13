## polimorfismo

si tratta del subtyping di puntatori e riferimenti, ma non di tipo

di base consiste in una superclasse che utilizza il suo tipo statico per interpretare un tipo derivato

```c++
super base;
sotto deriv;

super* base_ptr = &deriv;
sotto* deriv_ptr = &base;

// polimorfismo
base_ptr = deriv_ptr;
// base_ptr ha tipo statico super* e tipo dinamico sotto*
```

**tipo statico**

è il tipo di dichiarazione di un oggetto, quello definito nel sorgente

**tipo dinamico**

è il tipo di un oggetto in runtime

**static binding**

è il normale collegamento che il compilatore crea tra l'oggetto e metodo di una classe

in un contesto polimorfico, lo static 

**dynamic binding**

detto anche late binding, è il collegamento creato a runtime tra un puntatore polimorfo e il metodo di una sottoclasse

**virtual**

un metodo marcato come virtual permette alle sottoclassi di farne l'overriding, ciò permette di fare il binding dinamico

di base il comportamento del compilatore è:
* cerca sempre il metodo nella classe del tipo statico
* se c'è e non è marcato virtual fa il binding statico
* se c'è ed è marcato virtual fa il binding con il prototipo della metodo virtuale ed a runtime verrà deciso il giusto metodo
* se non c'è da errore di compilazione

nb: la parte fondamentale è capire che il compilatore cerca sempre nel tipo statico e se trova virtual decide cosa fare in base al tipo dinamico

quando si utilizza l'operatore di scoping il binding è sempre statico

**overriding**

consiste nel ridefinire un metodo virtuale, che soddisfa le seguenti regole:
* firma identica
* tipo di ritorno uguale o covarinate
    * covariante significa che se il tipo di ritorno è un puntatore ad una superclasse, si può sostituire con un puntatore ad una sottoclasse
* se il metodo virtuale ha valori di default, questi valori non vanno messo nell'override

l'override si fa nel seguente modo:
```c++
class A{
    public:
        virtual void f() {...}
}

class B : public A{
    public:
        virtual void f() {...}
}
```

**virtual method table**

la virtual table è il meccanismo di implementazione del dynamic binding

quando una classe dichiara un metodo virtuale il compilatore aggiunge nella classe un puntatore nascosto (virtual pointer), questo puntatore punta ad un array di puntatori a indirizzi di funzione (function pointer), che contengnono tutti gli indirizzi di metodi virtuali della classe, che a loro volta puntano al loro codice

quindi, in una normale superclasse:
* virtual pointer --> virtual table --> codice metodi

una sottoclasse possiede il proprio virtual pointer ela propria virtual table, al momento della derivazoine però la virtual table della sottoclasse viene riempita con la virtual table della superclasse e per la sottoclasse fare l'override significa far puntare il metodo della sua virtual table ad un'altra sezione di codice

quindi, nella sottoclasse:
* virtual pointer --> virtual table (almeno grande quanto quella della super classe) --> codice metodi (diversi su quelli con override)

ogni sottoclasse di una superclasse polimorfa (con metodi virtuali) è polimorfa

**distruttore virtuale**

siccome il binding statico viene fatto anche per i distruttori, quando una un puntatore polimorfo va a distruggere ciò a cui punta, viene distrutto solo il sottoggetto

per risolvere ciò la superclasse marca il distruttore come virtual, la sottoclasse fa l'override e cos' il puntatore polimorfo utilizza il giusto distruttore

**classe polimorfa**

è una classe che include almeno un metodo virtuale

**classe astratta**

è una classe che contiene almeno un metodo virtuale puro e non è instanziabile

i campi dati possono tranquillamente esserci

se si vuole creare una classe astratta senza metodi puri a caso basta segnare il distruttore come distruttore puro

**metodo virtuale puro**

è un metodo virtuale che non ha implementazione

viene così specificato:
```c++
class A{
    public:
        virtual void f() = 0;
}
```

i metodi virtuali puri sono dei contratti, le sottoclassi se vogliono essere istanziabili lo devono implementare, altrimenti rimangono astratte

**classe astratta pura**

è una classe che contiene solo metodi virtuali puri

**interfaccia**

sinonimo di classe astratta pura

**classe concreta**

è una classe che può essere istanziata

**rtti (RunTime Type Information)**

l'rtti consente di avere informazioni sul tipo dinamico, in c++ è implementato tramite:
* typeid
* dynamic_cast

**typeid**

di base ritorna il tipo dinamico di un puntatore dereferenziato polimorfo o riferimento polimorfo

funzionamento:
* typeid(tipo) --> ritorna il tipo del tipo
* typeid(espressione) --> ritorna il tipo dell'espressione
* typeid(*ptr_NON_polimorfo) --> ritorna il tipo statico
* typeid(ref_NON_polimorfo) --> ritorna il tipo statico
* typeid(*ptr_polimorfo) --> ritorna il tipo dinamico
* typeid(ref_polimorfo) --> ritorna il tipo dinamico

**dynamic cast**

di base ritorna il puntatore/riferimento al sottoggetto di un puntatore polimorfo

funzionamento puntatori:
* dynamic_cast<A*>(ptr)
    * ritorna il puntatore A* di ptr se il tipo dinamico di ptr è sottotipo di A
    * ritorna nullptr altrimenti

funzionamento riferimenti:
* dynamic_cast<A&>(ref)
    * ritorna il riferimento A& di ref se il tipo dinamico di ref è un sottotipo di A
    * lancia una eccezione bad_cast altrimenti

il dynamic cast si deve usare solo quando non si conosce il tipo dinamico di un oggetto, ad esempio quando si passa un puntatore ad una base come parametro

**upcasting**

è una conversione da puntatore sottoclasse a puntatore superclasse

**downcast**

è una conversione da puntatore superclasse a puntatore sottoclasse

**solid**

* le classe devono occuparsi di una cosa sola
* chiuso per modifiche, aperto per esensioni
* sostituire una superclasse con una sottoclasse non deve dare errori
* meglio pià interfacce singole che una complessa
* le astrazioni non devono dipendere dai dettagli

**clonable pattern**

è un design pattern dell'OOP, ogni superclasse definisce il metodo virtuale puro:
* virtual superclasse* clone() const = 0;

le sottoclassi andranno ad implementare questo metodo cambiandone il tipo di ritorno con la coercion