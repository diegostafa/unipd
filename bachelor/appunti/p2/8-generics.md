**template di funzione**

i template sono porzioni di codice non compilabile che parametrizzano dei tipi

```c++
template <class T> // oppure <typename T>
T min(T a, T b)
{
    return a < b ? a : b;
}
```

un template può essere istanziato in 2 modi:
* istanziazione implicita --> attraverso l'algoritmo di deduzione degli argomenti
* istanziazione esplicita --> usando le parantesi angolate

```c++
int main()
{
    int i, j, k;
    orario r, s, t;

    // istanziazione implicita
    k = min(i, j); // T diventa un int
    t = min(r, s); // T diventa un orario

    // istanziazione esplicita
    k = min<int>(i, j);
    t = min<orario>(r, s);
}
```

**algoritmo di deduzione degli argomenti**

se ci sono più parametri attuali che corrispondono allo stesso tipo T, questi devono avere tutti lo stesso tipo, ad eccezzione di queste conversioni:
* T& --> T
* T[] --> T*
* T --> const T
* T --> const T&

tutto ciò vale solo in istanziazione implicita, in esplicita valgono tutte le conversioni sui tipi passati tra parentesi angolate

**template di classe**

analogo ai template di funzione

i campi statici di un template di classe non sono condivisi tra diverse istanze in quanto le classi istanziate di un template sono classi effettivamente diverse l'una dall'altra, i campi statici vengono allocati solo quando utilizzati

si possono istanziare in 2 modi:
* istanziazione di default
* istanziazione esplicita

l'istanziazione implicita non esiste in quanto non esistono parametri attuali di una classe

```c++
template <class T = int, size = 1024>
class buffer{
    // ...
}
 
// istanziazione di default
buffer<> bufferDefault; // diventa un buffer con i tipi di default specificati
buffer<string> bufferStrings; //diventa un buffer di stringhe con size di default

//istanziazioni esplicite
buffer<int,2048> bufferInteri;
buffer<bolletta,50> bufferBollette;
buffer<orario,90> bufferOrari;
```

**forward declaration di template**

di base consiste nel dichiarare la firma di una funzione/classe generica

```c++
template <class T> class queue;
```

**dichiarazione di amicizia**

un template di classe ha 3 tipi amicizie:
* friend non template --> con funzioni/classi non templetizzati
* friend associato --> con template di funzioni/classi
* friend non associato --> con template di funzioni/classi

```c++
// 1) normale amicizia, A può accedere alla parte privata di C
template<T> class C{
    friend class A;
    friend int foo();
    friend int A::boo();
    // ...  
};

// 2) si usano i parametri della classe C per le amicizie e nient'altro
template<T1, T2, T3> class C{
    friend class A<T1, T2>;
    friend int foo<T3>();
    friend int A::boo<T1>(const C<T3>&);
    // ...
};

// 3) la dichiarazione di amicizia usa parametri di tipo indipendenti da C
template<T> class C{
    template<class Tp>
    friend class A<Tp>;
    
    template<class Tp>    
    friend int f<Tp>();
    
    template<class Tp>
    friend int A::f(C<Tp>);

    // ...
};
```

**template annidati**

ogni classe annidata in un template di classe è un template, in quanto il parametro di tipo è disponibile ovunque nella classe, la classe annidata viene detto tipo implicito

ci sono 2 tipi di annidamenti:
* associato --> usa solo i parametri di tipo della classe che annida
* non associato --> si aggiungono altri parametri di tipo

```c++
template <class T>
class queue
{
    // template di classe annidato associato
    class queueItem
    {
        queueItem(const T& val);
    };
    
    // template di classe annifato non associato
    template<class U>
    class queueItem
    {
        queueItem(const U& val);
    }
    
    // template di metodo di istanza non associato
    template<class U>
    void foo()
    {
        // ...
    }
}
```

i tipi impliciti devono essere preceduti dalla keyword typename se dichiarati all'esterno della classe, nella deguente forma:

```c++
typename C<T>::D a // se D è un tipo implicito
typename C<T>::template E<int> // se E è un template implicito
```