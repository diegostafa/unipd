# Stream

uno stream è una sequenza di byte, di base un vettore di byte

```c++
/*
gerarchia c++

ios
    istream
        istringstream
        ifstream
        iostream
            stringstream
            fstream
    ostream
        osstringstream
        ofstream
        iostream
            stringstream
            fstream
*/
```

**I/O stream**

significa trasformare tipi di dato c++, in tipi di dato esterni (es. utf-8, binario, ascii...)

**buffer**

divide il vettore di byte in porzioni uguali in base al tipo di dato primitivo da inviare

**stato dello stream**

lo stato di uno stream è identificato da 3 bit, che possono generare 8 combinazioni diverse:
* eof --> lo stream/vettore ha raggiunto la posizione di eof
* fail --> la precedente operazione di stream è fallita (senza perdita di dati)
    * errore sintatico
* bad --> la precedente operazione di stream è fallita, con perdita di dati
    * accesso a file inesistenti

**operatore di input standard**

di base è un parser, prende uno stream di caratteri, ed estrae i dati del tipo primitivo specificato, ignorando i marcatori (spazi, tab, return)

**operatore di input ridefinito**

è necessario ridefinire l'operatore di input nel caso si voglia estarre dallo stream un tipo definito dall'utente

di base, come per l'output ridefinito che stampa determinati caratteri e valori, ridefinire l'input significa andare a ritroso a prendere in input quei caratteri e valori

**I/O binario**

* istream& get(char& c) --> prende un byte e ritorna lo stream
* ostream& put(char& c) --> scrive un byte e ritorna lo stream
* istream& read(char* c, int n) --> prende n byte e riotorna lo stream
* ostream& write(const char* c, int n) --> scrive n byte e ritorna lo stream

**file stream**

è un I/O stream associato ad un file

**string stream**

di base è come un file stream, ma in ram, quindi il file non esiste e si opera a livello di stringhe (i file sono stringhe in ram)

# Gestione delle eccezioni

l'idea di base è che in un call stack, la funzione attualmente in esecuzione (quella in cima allo stack) può lanciare un messaggio di eccezione, questo messaggio viene passato al livello inferiore del call stack, la funzione che riceve il messaggio può decidere di gestire l'eccezione o di passarla al livello inferiore, se nessuna funzione gestisce l'eccezione e si arriva al bottom del call stack, il programma crasha (termina lanciando il comando di abort())

in c++ questa gestione è implementata dai comandi
* throw
* try
* catch

```c++
/*

gerarchia exception c++

exception
    bad_alloc
    logic_error
        length_error
        domain_error
        out_of_range
        invalid_argument
    runtime_error
        range_error
        overflow_error
        underflow_error
    bad_cast
*/
```

**throw *espressione***

è il comando che una funzione utilizza per lanciare un'eccezione, l'eccezione può essere una variabile o un'espressione

ogni funzione che non gestisce un'eccezione ne fa il throw nascosto a fine funzione

**try { ... }**

definisce una porzione di codice che può ricevere un'eccezione

**catch(*tipo*)**

il catch definisce una porzione di codice che gestisce un eccezione di tipo specifico, il catch può rilanciare l'eccezione nel caso voglia fare una gestione dell'errore parziale

si può creare il catch anche nella funzione che lancia l'eccezione, ma non ha senso

**catch(...)**

è la catch generica, accetta ogni eccezione, viene usata per il rilascio delle risorse

le catch generiche nelle funzioni che lanciano le eccezioni hanno senso

**match di tipo nel catch**

in un catch(T) su eccezione di tipo E avviene solo se:
* T ha stesso tipo di E
* T è una superclasse di E
    * subtyping di tipo (E < T)
        * implica derivazione pubblica
    * subtyping di puntatore
    * subtyping di riferimento
* T è void*, E è un puntatore qualsiasi

**comportemnto del catch**

di solito i catch vengono utilizzati per:
* rilanciare l'eccezione
* convertire l'eccezione e rilanciarla
* ripristinare il funzionamento del programma
* risolvere l'errore e rieseguire la funzione
* invocare std::terminate()

**eccezioni vs if-else**

le eccezioni si usano quando in situazioni asincrone e di race condition, gli if else si usano in ciò che riguarda lo scope del programma

# C++ 11

**inferenza di tipo**

keywords:
* auto --> non serve specificare il tipo, il compilatore lo inferisce
* decltype --> deduce il tipo di un'espressione
* default --> esplicita al compilatore di usare la versione standard di una funzione
* delete --> non crea la versione standard
* override --> definisce l'override di un metodo virtuale
* final --> proibisce alle sottoclassi di farne l'override
* nullptr

**esercizi tipo**

```c++
/*
definire un template fi funzione bool fun(t1*, t2&) in modo tale che ritorni true sse:
- i parametri istanziati devono essere dello stesso tipo
- i parametri istanzati hanno stesso tipo dinamico
- il tipo dinamico è un sottotipo della classe ios
*/

template <class T1, class T2>
bool fun(T1* p, T2& r)
{
    return typeid(p) == typeid(&r) &&
           typeid(*p) == typeid(r) &&
           dynamic_cast<ios>(p);
}
```
