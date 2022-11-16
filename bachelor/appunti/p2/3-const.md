## Const saga

**side effect**

una metodo che modifica l'oggetto di invocazione si dice che fa side effects

**oggetti costanti**

un oggetto costante è un oggetto non consente side effects su i suoi campi, ad eccezione dei costruttori

sintassi:
* const *tipo* *nomeOggetto*

vincoli:
* un oggetto costante può invocare solo metodi costanti

**metodi costanti**

un metodo costante è un metodo che non crea side effects

sintassi:
* *tipo* *nomeMetodo*(*parametri*) const {...}

vincoli:
* non si possono modificare i campi del oggetto di invocazione (side effects)
* non si possono invocare metodi non costanti nel corpo del metodo

in un metodo costante il puntatore this diventa un puntatore ad un oggetto costante, cioè può cambiare l'oggetto puntato, ma non il suo contenuto

**const e puntatori**

ci sono 3 combinazioni con puntatori e costanti
* *tipo* * const *nome* --> il puntatore è costante
* const *tipo* * *nome* --> il puntato è costante
* const *tipo* * const *nome* --> puntatore e puntato costanti

**const e riferimenti**

ci sono 3 combinazioni con reference e costanti
* *tipo* & const *nome* --> illegale, non ha senso
* const *tipo* & *nome* --> *nome* è costante
* const *tipo* & const *nome* --> illegale, non ha senso

la seconda combinazione permette scritture del tipo:
* const *tipo* & *nome* = *variabile/literal/temporaneo anonimo*

questa scrittura è importante in quanto consente di assegnar literals a riferimenti, const *tipo* & lo si pò usare come tipo di ritorno o parametro formale, con i relativi vantaggi

## Operatori di classe

gli operatori di classe sono:
* operatori aritmetici
* operatori logici
* di linguaggio:
    * \++ --> incremento
    * \-- --> decremento
    * << --> output
    * \>> --> input
    * = --> assegnazione (importante)
    * \-> --> accesso
    * [] --> subscripting
    * () --> function call
    * & --> address of
    * new --> allocazione
    * delete --> deallocazione

**overloading degli operatori**

sintassi:
* *tipo* operator*op*(*parametro*) const; 

regole:
* non si può ridefinire la posizione degli operatori
* non si può ridefinire il numero di operandi
* non si possono ridefinire regole di precedenza/associazione
* deve esserci almeno un argomento di tipo definito da utente
* esistono operatori NON sovraccaricabili
* '=','&',',' hanno sempre una versione standard fatta dal compilatore

**operatore condizionale ternario**

sintassi:
* (condizione) ? expr1 : expr2

**operatore virgola**

è un operatore ad n argomenti, ogni argomento è un espressione, valuta tutte le espressioni (compresi side effects) e ritorna quella più a destra

**operatore assegnazione**

viene invocato durante l'assegnazione di un oggetto già creato

funzionamento:
1. oggetto a sinistra invoca l'operatore di assegnazione
2. oggetto a destra è un parametro  in sola lettura
3. vengono copiati i dati in modo opportuno
4. viene ritornato l'oggetto a sinistra

firma:
* *className*& operator=(const obj&)

sintassi:
* obj1 = obj2;

dove:
* obj1 --> oggetto di invocazione
* obj2 --> parametro attuale

l'operatore di assegnazione ritorna sempre l'oggetto di invocazione, quindi alla fine del corpo del metodo ci sarà sempre:
* return *this

**assegnazione standard**

l'operatore di assegnazione tra 2 oggetti standard (in assenza di un operatore definito dall'utente) esegue una copia campo per campo tra i 2 oggetti

gli array statici non hanno l'assegnazione standard, gli array statici interni ad un'oggetti sì

**operatore di output**

ostream fornisce un flusso generico in output, standard, file, stampanti...

**output interno**

firma:
* ostream& *classe*::operator<<(ostream& os) const;

se definito internamente la sintassi di stampa non concorda con quella del linguaggio

**output esterno**

firma:
* ostream& operator<<(ostream& os, const *classe*& c);
 
se definito esternamente l'operatore non ha accesso ai campi privati dell'oggetto


## Preprocessore

il preprocessore è un programma che lavora sulle direttive di un file

le direttive sono dei comandi che il preprocessore andrà ad eseguire prima di inviare il file al compilatore

direttive:
* di inclusione
    * #include
* di macro
    * #define
* condizionali
    * #ifdef
    * #ifndef
    * #elif
    * #endif

**inclusione**

sintassi:
* #include *file*

la direttiva di inclusione copia il contenuto di *file* e lo incolla al suo posto

**macro**

sintassi:
* #define *nomeMacro*(p1,p2,...,pn) (*codice*)

le macro sono porzioni di codice a cui viene dato un nome, se lo necessita si possono definire dei parametri, quando il preprocessore incontra *nomeMacro* nel codice c++ lo va a sostituire pari pari con *codice* e va anche a sostiturire i parametri attuali passati con quelli formali nel *codice*


```c++

// ESEMPI

// sostituisce 123 ogni qualvolta incontra COST
#define COST 123 

#define max(A,B) ((A)>(B) ? (A) : (B))
/*
sostituisce tutto il il codice ogni qualvolta incontra max(x,y),
va anche a sostituire i parametri attuali x,y ai parametri formali A,B nel codice
*/
```

**condizionali**

sintassi:
* #ifdef *nome* *codice c++* *endif*

## make

è un programma che prende in input un file in linguaggio makefile, il linguaggio makefile specifica le dipendenze dei file nei programmi, e li aggiorna di conseguenza

sintassi:
```
<target file> : <lista di dipendenze
    <comando da eseguire>
```

le variabili si definiscono come in bash

funzionamento:
1. si crea un makefile del progetto/programma
2. make crea un file che monitora se le dipendenze sono state modificate
2. si modifica un file
3. make si accorge che il file è stato modificato
4. esegue solo i target necessari

sintassi:
* $ make --> esegue tutti i target
* $ make *target* --> esegue solo i target specificato