
**iteratori**

sono delle classi che consentono di scorrere gli elementi di un tipo contenitore

gli iteratori differiscono in base al contenitore da scorrere

un iteratore per dirsi tale deve implementare i seguenti operatori:
* uguaglianza
* disuguaglianza
* incremento pre/postfisso

l'operatore postfisso per distinguersi dal prefisso ha un parametro formale intero che non serve a nulla

```c++
class iteratore{
    private:
        contenitore::nodo* punt;
    public:
       bool operator==(const iteratore& i) const{
           return punt == i.punt;
       } 
       bool operator!=(const iteratore& i) const{
           return punt != i.punt;
       }
       //prefisso
       iteratore& operator++(){
           if(punt) punt = punt->next;
           return *this;
       }
       //postfisso
       iteratore operator++(int){
           iteratore aux = *this;
           if(punt) punt = punt->next;
           return aux;
       }

       tipo* operator->() const{
           return &(punt->indfo);
       }

       tipo& operator*() const{
           return punt->info;
       }
}
```

un contenitore che implementa gli iteratori deve fornirep i seguenti metodi:
* iterator begin() const
    * ritorna il primo elemento di un contenitore
* iterator end() const
    * ritorna il past the end
* tipo& operator[](const iteratore&) const

il past the end è il successivo dell'ultimo elemento della lista, il modo più semplice per ritornare il past the end è ritornare il puntatore all'ultimo elemento di un contenitore + 1, ciò consente di fare un - 1 per tornare indietro

```c++
contenitore::iteratore contenitore::begin() const{
    iteratore aux; // costruisce un iteratore
    aux.punt = first; // lo fa puntare al primo
    return aux; // lo ritorna per valore (costruttore di copia)
}

contenitore::iteratore contenitore::end() const{
    iteratore aux; // costruisce un iteratore
    aux.punt = 0;
    return aux; // lo ritorna per valore (costruttore di copia)
}

tipo& contenitore::operator[](const contenitore::iteratore& it) cosnt{
    return it.punt->info; // ritorna ciò a cui punta l'iteratore per riferimento
}
```

gli iteratori permettono di scorrere un contenitore normalmente:

```c++
int somma_elementi(const contenitore& c){
    int somma=0;
    for(contenitore::iteratore i=c.begin(); i!=c.end(); i++)
    {
        somma+=c[i];
    }
    return somma;
}
```

**esercizio tree**

```c++
class nodo{
    friend class tree: // tree può accedere alla parte privata
    private:
        char info;
        nodo* sx;
        nodo* dx;

        nodo(char c='*', nodo* d=0, nodo* s=0) : info(c), sx(s), dx(d) {}
}

class tree{
    private:
        nodo* root;

        static nodo* copia(nodo* r){
            if(r == nullptr)
                return nullptr;
            return new nodo(r->info, copia(r->sx), copia(r->dx));
        }

        static void distruggi(nodo* r){
            if(r!=nullptr){
                distruggi(sx);
                distruggi(dx);
                delete r;
            }
        }
    public:
        tree(): root(nullptr){}

        tree(const tree& t) : root(copia(t.root)) {}

        tree& operator=(const tree&){
            if(this != &t){
                distruggi(root);
                root=copia(t.root);
            }
            return *this;
        }

        ~tree(){
            if(root!=nullptr) distruggi(root)
        }
}
```

**esercizio vettore**

```c++
class vettore{
    private:
        int* a;
        unsigned int size;
        // invariante: vettore nullo se a == nullptr && size ==0
    public:
        vettore(unsigned int s = 0, int value=0) : a((s == 0) ? nullptr : new int[s]), size(s) {
            for(unsigned int i = 0; i < s; i++)
                a[i]=value;
        }

        vettore(const vettore& v) : a((v.size == 0) ? nullptr : new int[v.size]), size(v.size) {
            for(unsigned int i = 0; i < s; i++)
                a[i]=v.a[i];
        }

        vettore& operator=(const vettore& v){
            // bisogna sempre fare questo check
            if(this!=&v){
                delete[] a;
                size = v.size;
                a = (size == 0) ? nullptr : new int[size];
                for (unsigned int i = 0; i < size; i++>)
                    a[i] = v.a[i]; // da ridefinire il subscripting
                return *this;
            }
        }

        ~vettore(){
            if(a != nullptr) delete[] a;
        }

        vettore& append(const vettore& v){
            if(v.size != 0){
				int* aux = new int[size + v.size];
				
                for (unsigned int i=0; i < size; i++>)
                    aux[i] = a[i];
                
                for (unsigned int i=0; i < v.size; i++>)
                    aux[i+size] = v.a[i];
                
                size += v.size;
                delete[] a;
                a = aux;
			}
            return *this;
        }

        vettore operator+(const vettore& v) const{
			vector aux(*this);
			aux.append(v);
			return aux;
		}

        bool operator==(const vettore& v) const{
            if(this!=&v){
                if(size != v.size) return false;
                for(unsigned int i = 0; i < size; i++)
                    if(a[i]!=v.a[i]) return false;
            }
            return true;
        }

        int& operator[](const int i) const{
            return a[i];
        }

        int getSize(){
            return size;
        }
}

std::ostream& operator<<(std::ostream& os, const vettore& v){
    os << '[';
    for(unsigned int = 0; i < v.getSize(); i++)
        os << v[i] << (i != v.getSize()) ? ',' : '';
    os << ']';
    return os;
}

class nodo{
    private:
    char info;
        nodo* next;
    public:
        nodo(char i=0, nodo* n=nullptr) : info(i), next(n){}
}

```