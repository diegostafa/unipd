## Standard Template Library

### Contenitori STL

ci sono diversi tipi di contenitori:
* sequenziali:
    * array
    * vector
    * deque
    * forward_list (single linked)
    * list (double linked)
* adattatori:
    * stack
    * queue
    * priority_queue
* associativi --> accesso tramite chiave
    * set
    * multiset
    * map
    * multimap
* non ordinati:
    * unordered_set
    * unordered_multiset
    * unordered_map
    * unordered_multimap

ogni contenitore STL supporta 2 tipi di iteratori:
* iterator
* const_iterator --> iteratore di sola lettura

```c++
// iterator
T& vector<T>::iterator::operator*() const;

// const_iterator
const T& vector<T>::const_iterator::operator*() const;
```

```c++
// scorrimento di un contenitore
cont<T> x;
for(cont<T>::iterator i = x.begin(); i != x.end(); i++)
{
    ...
}
```

**vector**

il vector è un template di classe che va ad aggiungere funzionalità ad un array statico con proprietà quali:
* size
* capacity
* begin
* end
* ...

vantaggi:
* accesso casuale (indicizzazione O(1))
* inserimento e rimozione in coda (O(logn))
* inserimento e rimozione in tempo lineare (O(n))
* la capacità può variare dinamicamente
    * non è allocato sull'heap, ma viene riallocato con una capacità maggiore 
    * la capacità viene raddoppiata ogni volta che si inserisce oltre la capacità massima (la capacità sarà sempre una potenza di 2 a meno di diverse inizializzazioni )
* gestione della memoria automatica

metodi importanti:
* push_back
* pop_back
* front
* back
* begin
* end

altri metodi:
* empty
* size
* insert
* erase

metodi utili:
* sort
* count
* copy
* reverse
* binary search

**rimozione**

la rimozione di un elemento avviene tramite la pop_back che rimuove l'ultimo elemento chiamando il suo distruttore su di esso

si può rimuovere un elemento in posizione arbitraria anche tramite il metodo erase

**esercizio importante**

```c++
/*
definire un template di classe dlist con:
- gestione della memoria senza condivisione
- costruttore che inizializza tutti gli elementi uniformemente
- inserimento in testa e coda in O(1)
    - insertFront
    - insertBack
- overloading operatore < che implementa ordinamento lessicografico
- iteratore costante
*/

template<class T>
class dlist
{
    private:
        class dnode
        {
            public:
                T info;
                dnode* prev, next;

                dnode(const T& i, dnode* p, dnode* n) : info(i), prev(p), next(n) {}
        }

        dnode* first, last;

        static bool isLess(const dnode* a, const dnode* b)
        {
            if(!a && !b) return false;
            if(!a) return true;
            if(!b) return false;
            if(a->info < b->info) return true;
            else if (a->info > b->inof) return false;
            else isLess(a->next, b->next);
        }

        static void destroy(dnode* n)
        {
            if(n)
            {
                destroy(n->next);
                delete n;
            }
        }

        static void deep_copy(dnode* src, dnode*& first,dnode*& last)
        {
            if(src)
            {
                first = last = new dnode(src->info);
                dnode* src_sc = src_next;
                while(src_sc)
                {
                    last = new dnode(src_sc->info, last);
                    last->prev->next = last;
                    src_sc = src_sc->next;
                }
            }
            else
            {
                first = last = nullptr;
            }
        }

    public:   
        dlist(unsigned int k, const T& t) : first(nullptr), last(nullptr)
        {
            for(unsigned int j = 0; j < k; ++j) insertFront(t);
        }

        dlist(const dlist& l) 
        {
            deep_copy(l.first,first,last
        }

        dlist& operator=(const T& l)
        {
            if(this != &l)
            {
                destroy(first);
                deep_copy(l.first,first,last);
            }
        }

        ~dlist()
        {
            destroy(first);
        }

        void insertFront(const T& t)
        {
            // speculare ad insert back
        }

        void insertBack(const T& t)
        {
            if(last)
            {
                last = new nodo(t, last, nullptr)
                (last->prev)->next = last;
            }
            else first = last = new nodo(t);
        }

        
        bool operator<(const dlist& l) const
        {
            if(this == &l) return false;
            return isLess(first, l->first)
        }

        const_iterator begin() const
        {
            return const_iterator(first, false)
        }

        const_iterator end() const
        {
            if(!last) return const_iterator();
            return const_iterator(last + 1, true)
        }
        

        class const_iterator
        {
            friend dlist<T>;
            
            private:
                const dnode* ptr;
                bool past_the_end;

                // agisce anche da convertitore dnode* => consr_iterator
                const_iterator(dnode* p, bool pte = false) : ptr(p), past_the_end(pte) {}
            public:
                // const_iterator è indefinito di default
                const_iterator() : ptr(nullptr), past_the_end(false) {}
                
                const_iterator& operator++()
                {
                    if(ptr)
                        if(!past_the_end)
                            if(ptr->next)
                                ptr = ptr->next
                    else
                    {
                        ptr = ptr + 1; past_the_end = true;
                    }
                    return *this;
                }

                const_iterator operator++(int)
                {
                    const_iterator aux(*this)
                    if(ptr)
                        if(!past_the_end)
                            if(ptr->next)
                                ptr = ptr->next
                    else
                    {
                        ptr = ptr + 1; past_the_end = true;
                    }
                    return aux
                }
                
                const_iterator& operator--()
                {
                    if(ptr)
                        if(ptr == first) ptr = nullptr;
                        else if(!past_the_end) ptr = ptr->prev;
                        else
                        {
                            ptr = ptr - 1;
                            past_the_end = false;
                        }
                    
                    return *this;
                }

                const_iterator operator--(int);
                
                bool operator==(const const_iterator& cit) const
                {
                    return ptr == cit.ptr;
                }

                bool operator!=(const const_iterator& cit) const
                {
                    return !(*this == cit);
                }
                
                const T& operator*() const
                {
                    return ptr->info;
                }

                const T* operator->() const
                {
                    return &(ptr->info)
                }
        }
}
```