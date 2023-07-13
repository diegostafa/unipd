### Alberi binari

sono strutture dati ricorsive formata da nodi, si definisce ricorsivamente come:
* un albero vuoto
* un nodo che punta ad un albero sinistro e destro

```c++
struct nodo{
    char dato;
    nodo* sx;
    nodo* dx;
}
```

si definisce come altezza di un albero la profondità massima delle foglie e per convenzione l'altezza di un albero vuoto (cioè senza nemmeno la radice) è -1

il numero di nodi di un albero equilibrato di altezza n è 2<sup>n + 1</sup> - 1

per visitare i nodi di un albero ci sono 2 modi:
* in depth
    * prefisso
    * infisso
    * postfisso
* in breadth

**rappresentazione lineare di un albero binario**

di base è come si indica la stampa a video di un albero in base al tipo di percorso specificato, si indica con:
* radice(ramosx(\_), ramodx(ramosx(\_,ramodx(\_,\_)),\_))

nb:
* le parentesi contengono i rami
* un underscore indica l'assenza di un ramo


**altezza di un albero**

* pre: l'albero è ben formato
* post: restituisce l'altezza di un albero

```c++
int Altezza(nodo* albero)
{
    if(!albero)
        return -1;
    else
    {
        // altezza dei sottoalberi
        int a = Altezza(albero->sx);
        int b = Altezza(albero->dx);

        // +1 in quanto bisogna contare il cammino radice-sottalbero
        (a > b) ? return a+1: return b+1;
    }
}
```
&nbsp;

---

### In depth

consiste nel scorrere un albero arrivando prima alle foglie

lo scorrimento dei nodi puà avvenire in diverse modalità:
* prefisso
    * radice
    * nodo sinistro
    * nodo destro
* infisso
    * nodo sinistro
    * radice
    * nodo destro
* postfisso
    * nodo sinistro
    * nodo destro
    * radice

**stampa**

* pre: l'albero è ben formato
* post: stampa l'albero in depth (pre/in/postfisso)

```c++
void StampaAlbero(nodo* radice)
{
    if(radice)
    {  
        // cout << radice->info; // stampa prefissa
        StampaAlbero(radice->sx); 
        // cout << radice->info; // stampa infissa
        StampaAlbero(radice->dx);
        // cout << radice->info; // stampa postfissa
    }
}
```

&nbsp;

**ricerca**

* pre: l'albero è ben formato
* post: restituisce il nodo se c'è match, 0 altrimenti

```c++
nodo* Cerca(nodo* albero, char frutto)
{
    if(!albero)
        return 0;
    else
    {
        if(albero->info == frutto);
            return albero;
        else
        {
            nodo* temp = Cerca(albero->sx, frutto);
            if(temo)
                return temp;
            else
                return Cerca(albero->dx, frutto);
        }
    }
}
```

&nbsp;

---

### In breadth e FIFO

consiste nel scorrere un albero per livelli, da sinistra a destro

il tipo di lista utilizzata è FIFO, in quanto dopo aver utilizzato un nodo e aggunto i suoi rami si rimuove il nodo e si passa al successivo

indicando con S l'insieme dei nodi da analizzare contenente inizialmente solo la radice:
* si analizza il primo nodo di S
* si aggiungono in S i suoi sottonodi
* si rimuove da S il nodo analizzato
* si ripete il ciclo



```c++
// nodo per struttura fifo
struct nodoF{
    nodo* info; // punta ad un elemento dell'albero
    nodoF* next; //punta al prossimo elemento della lista

    nodoF(nodo* n, nodoF* nF)
    {
        info = n;
        next = nF;
    }
}

// struttura fifo
struct FIFO{
    nodoF* primo; // punta al primo elemento
    nodoF* ultimo; // punta all'ultimo elemento

    FIFO(nodo* n)
    {
        if(n)
            primo = new nodoF(n);
            ultimo = primo;
        else
            primo = 0;
            ultimo = 0;
    }
}
```

&nbsp;

**rimozione di un elemento dalla coda**

* pre: fifo è una lista ben formata e non vuota
* post: restituisce il nodo dell'albero puntato dal primo elemento della lista.

```c++ 
nodo* pop(FIFO& fifo)
{
    nodoF* p = fifo.primo; // prende il primo 
    fifo.primo = fifo.primo->next;
    if(!fifo.primo)
        fifo.ultimo = 0;
    return p->info;
}
```

&nbsp;

**aggiunta di un elemento alla coda**

* pre: fifo è una lista ben formata
* post: restituisce la lista fifo con il nodo n in fondo

```c++ 
FIFO push(FIFO fifo, nodo* n)
{
    if(fifo.primo)
    {
        fifo.ultimo->next = new nodoF(n);
        fifo.ultimo = fifo.ultimo->next;
        return fifo;
    }
    return FIFO(n);
}
```

&nbsp;

**stampa dell'albero (iterativa)**

* pre: l'albero è ben formato
* post: stampa l'albero in breadth

```c++
void StampaAlbero(nodo* radice)
{
    FIFO coda(radice);
    while(coda.primo)
    {
        nodo* n = pop(coda);
        cout << n->info;
        if(n->sx)
            coda = push(coda, n->sx)
        if(n->dx)
            coda = push(coda, n->dx)
            
    }
}
```

&nbsp;

**stampa in breadth (iterativa)**

* pre: l'albero è ben formato
* post: 

```c++
void StampaAlbero()
{

}
```
