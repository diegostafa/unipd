### Liste concatenate

di base sono strutture dati ricorsive.
* caso base --> lista vuota
* caso ricorsivo --> un elemento seguito dal resto della lista

le liste concatenate vengono implementate attraverso una struttura nodo, del tipo:

``` c++
struct nodo{
    int info;
    nodo* next;

    nodo(int i, nodo* n)
    {
        info = i;
        nodo = n;
    }
}
```

di base un nodo è una struttura dati che contiene un valore informativo ed un puntatore ad un nodo successivo.

una lista è quindi **un puntatore nodo\***, allocato sullo stack, che punta ad un nodo allocato sull'heap

``` c++
// crea una lista vuota
nodo* lista = NULL; 

// la lista ora punta ad un nodo
lista = new nodo(0, NULL);

//il primo elemento ora punta al secondo elemento
lista->next = new nodo(1, NULL); 

// il secondo punta al terzo e così via
lista->next->next = new nodo(1, NULL); 
```

**liste ben formate**

una lista è ben formata/corretta se:
* se il nodo* punta a NULL
* se il nodo* punta ad una lista ben formata

di base una lista ben formata è quindi una lista di nodi, posibilmente vuota, il cui ultimo elemento punta a NULL

**notazioni**

* L(n) indica una lista n ben formata
* vL(n) indica una copia di L(n)
* L(n) @ L(m) indica la concatenazione tra n e m
* Lk(n) indica una lista n formata dai primi k-1 nodi
    * L0(n) --> lista vuota
    * L1(n) --> primo nodo
    * ...
    * Lk-1
    * R indica il resto di una lista
* L(n)<sup>R</sup> è la lista invertita di L(n)
---

### Operazioni sulle liste

**creazione di una lista di n elementi (decrescente)**

* pre: n è >= 0
* post:restituisce una lista con n nodi e campi info decrescenti 

```c++
nodo* build(int n)
{
    if(n == 0)
        return 0;
    return new nodo(n, build(n-1));
}
```

correttezza:
* caso base:
    * banale, si ritorna 0 come specfica la post
* caso ricorsivo:
    * siccome m non è 0, la pre ricorsiva è verficata

    
**creazione di una lista di n elementi (crescente)**

* pre: 0 <= n <= dim
* post:restituisce una lista con dim-n nodi e campi info crescenti 

```c++
nodo* build(int n)
{
    if(n == dim)
        return 0;
    return new nodo(n, build(n+1, dim));
}
```

correttezza:
* caso base:
    * banale, se ritorna dim-m nodi allora se d==m ritorna 0 nodi
* caso ricorsivo:
    * siccome m non è dim, la pre ricorsiva è verficata

**distruzione di una lista (left to right)**

* pre: la lista è ben formata
* post: la lista è stata deallocata

```c++
nodo* distruggi(nodo* L)
{
    if(L)
    {
        nodo* t = L->next
        delete L;
        distruggi(t);
    }
}
```

**distruzione di una lista (right to left)**

* pre: la lista è ben formata
* post: la lista è stata deallocata

```c++
nodo* distruggi(nodo* L)
{
    if(L)
    {
        distruggi(L->next);
        delete L;
    }
}
```
**distruzione di una lista (iterativa)**

* pre: la lista è ben formata
* post: la lista è stata deallocata

```c++
int dim = lunghezza(L);

nodo* pila = new nodo*[dim] // array di nodo*

// assegna ogni nodo all'array
for(int i = 0; i < dim; i++)
{
    pila[i] = L;
    L = L->next;
}

// left to right
for(int i = 0; i < dim; i++)
    delete pila[i]

// right to left
for(int i = dim - 1; i >= 0; i++)
    delete pila[i]

```

**stampa di una lista (left to right)**

* pre: la lista è ben formata
* post: stampa i campi info della lista

```c++
nodo* stampa(nodo* L)
{
    if(L)
    {
        cout << L->info;
        stampa(L->next);
    }
}
```

**stampa di una lista (right to left)**

* pre: la lista è ben formata
* post: stampa i campi info della lista

```c++
nodo* stampa(nodo* L)
{
    if(L)
    {
        stampa(L->next);
        cout << L->info;
    }
}
```

**lunghezza di una lista**

* pre: la lista è ben formata
* post: restituisce la lunghezza della lista

```c++
int lunghezza(nodo* L)
{
    if (!L)
        return 0;
    return 1 + lunghezza(L->next);
}
```

**concatenazione tra liste**

si indica con L1@L2

* pre: L1 e L2 sono ben formate
* post: restituisce L1@L2

```c++
nodo* concatena(nodo* L1, nodo* L2)
{
    if (!L1)
        return L2;
    L!->next = concatenza (L1->next, L2);
    return L1;
}
```

correttezza:
* caso base:
    * banale, se L1 è vuota ritorna L2
* caso ricorsivo:
    * L1->next è una lista ben formata per definizione


**inserimento a fine lista (tipo 1)**

* pre: L è una lista ben formata
* post: restituisce L@nodo(c, 0)

```c++
nodo* InsEnd(nodo* L, char c)
{
    // scorre fino alla fine
    if (!L)
        return new nodo(c); // crea e ritorna il nodo
    L->next = InsEnd(L->next); // aggancia la lista passata concatenata al nuovo nodo
    return L; // ritorna la lista
}
```

**inserimento a fine lista (tipo 2)**

* pre: L è una lista ben formata e non vuota
* post: restituisce L@nodo(c, 0)

```c++
void InsEnd(nodo* L, char c)
{
    if(!L->next)
        L->next = new nodo(c);
    else
        InsEnd(L->next,c);
}
```

**inserimento a fine lista (tipo 3)**

* pre: L è una lista ben formata
* post: restituisce L@nodo(c, 0)

```c++
void InsEnd(nodo* &L, char c)
{
    if(!L)
        L = new nodo(c);
    else
        InsEnd(L->next,c);
}
```

**pop di una lista (tipo 1)**

* pre: L è una lista ben formata e non vuota
* post: restituisce vL - ultimo nodo

```c++
nodo* pop(nodo* L)
{
    if(!L->next)
    {
        delete L;
        return 0;
    }
    L->next = pop(L->next);
    return L;
}
```

**pop di una lista (tipo 2)**

* pre: L è una lista ben formata e con almeno 2 nodi
* post: restituisce vL - ultimo nodo

```c++
void pop(nodo* L)
{
    if(!L->next->next)
    {
        delete L->next;
        L->next = 0;
    }
    else
        pop(L->next);
}
```

**pop di una lista (tipo 3)**

* pre: L è una lista ben formata e con almeno 2 nodi
* post: restituisce vL - ultimo nodo

```c++
void pop(nodo* &L)
{
    // se non esiste il prossimo elemento, cioè è l'ultimo nodo
    if(!L->next)
    {
        // elimina l'ultimo nodo
        delete L;
        // mette il penultimo a 0
        L = 0;
    }
    else
        pop(L->next);
}
```

**inserimento in posizione k (tipo 1)**

* pre: L è una lista ben formata, k >= 0, vL = L
* post: restituisce vLk@nodo(c)@R

```c++
nodo* ins(nodo* L, int k, int c)
{
    if(!k)
        return new nodo(c, L);
    if(!L)
        return 0;
    L->next = ins(L->next, k-1, c)
}
```

**inserimento in posizione k (tipo 2)**

* pre: L è una lista ben formata e non vuota, k > 0, vL = L
* post: restituisce vLk@nodo(c)@R

```c++
void ins(nodo* L, int k, int c)
{
    if(!k-1)
        L->next = new nodo(c, L->next);
    if(L->next)
        ins(L->next, k-1, c)
}
```

**inserimento in posizione k (tipo 3)**

* pre: L è una lista ben formata, k >= 0, vL = L
* post: restituisce vLk@nodo(c)@R

```c++
void ins(nodo* &L, int k, int c)
{
    if(!k)
        L = new nodo(c, L);
    if(L)
        ins(L->next, k-1, c)
}
```

**inversione di una lista (v1)**

* pre: L è una lista ben formata
* post: restituisce L<sup>R</sup>

```c++
nodo* inverti(nodo* L)
{
    if(!L)
        return 0;
    nodo* t = inverti(L->next);
    return InsEnd(t, L);
}
```

**inversione di una lista (v2)**

* pre: L e Q sono liste ben formate
* post: restituisce L<sup>R</sup>@Q

```c++
nodo* inverti(nodo* L, nodo* Q)
{
    if(!L)
        return Q;
    nodo* t = L;
    L = L->next;
    t->next = Q;
    return inverti(L, t);
}
```

**inversione di una lista (v2 - iterativa)**

* R: Q = (vL - L)<sup>R</sup>

```c++
nodo* inverti(nodo* L)
{
    nodo * Q = 0;
    while(L)
    {
        nodo* t = L;
        L = L->next;
        t->next = Q;
        Q = t;
    }
    return Q;
} 
```