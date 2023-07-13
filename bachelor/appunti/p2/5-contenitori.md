## Contenitori

un contenitore è un ADT le cui istanze sono collezioni di altri oggetti

un tipo contenitore DEVE implementare i seguenti metodi:
* costruzione di un contenitore vuoto (costruttore)
* inserimento
* rimozione di un elemento
* rimozione totale (clear)
* accesso agli elementi
* accesso al numero di elmenti (count)

esempi dei contenitori standard:
* string
* list
* vector
* map
* set

**classi annidate**

sono classi definite all'interno di un'altra classe

**esempio bolletta**

```c++
class Bolletta{
    public:
        bolletta();
        bool Vuota() const;
        void Aggiungi(const Telefonata&);
        void Rimuovi(const Telefonata&);
        Telefonata Estrai();
    private:
        class nodo{
            public:
                nodo();
                nodo(const telefonata&, nodo*);
                telefonata info;
                nodo* next;
        };
        nodo* first;
}
```

**aliasing**

è un problema nella quale oggetti diversi possono accedere alla stessa zona di memoria in un modo non previsto dal programmatore, creando inconsistenza, è dovuto a:
* condivisione di memoria
* metodi con side effects

**shallow copy**

dati 2 oggetti dello stesso tipo aventi n campi, in una shallow copy del tipo:
* obj1 = obj2;

va a copiare tutti i campo di obj2 in obj1, senza tenere assolutamente di ciò che i campi contengono, ciò può causare aliasing

la shallow copy è implementata nei costruttori di copia standard e negli operatori di assegnazione standard

**deep copy**

di base la deep copy è una copia tra oggetti implementata dall'utente tramite overgloading dell'operatore di assegnazione e di costruttore di copia

```c++
// assegnazione profonda

tipo& tipo::operator=(const tipo& t)
{
    if(this != &t)
    {
        distruggi(...);
        copia(...);
    }
    return *this;
}

// costruttore di copia profonda

tipo::tipo(const tipo& t) : copia() {}

```

**cicli di vita delle variabili**

ci sono diversi tipi di variabili:
* automatiche
    * variabili locali
    * parametri formali di funzione
    * variabile ritornata per valore
* statiche
    * campi statici
    * variabili globali
    * dentro funzioni (bad practice)
* dinamiche
    * variabile allocate con new
