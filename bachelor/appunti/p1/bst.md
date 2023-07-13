
### Binary Search Trees - BST

un albero BST è un albero binario tale per cui ogni radice è maggiore del sottoalbero sinistro e minore del sottoalbero destro

la ricerca in un BST compie ha complessità logn ed il numero massimo di invocazioni è l'altezza dell'albero

**ricerca BST**

* pre: albero è un albero BST
* post: restituisce se c'è il nodo cercato, altrimenti 0

```c++
nodo* Cerca(nodo* albero, char c)
{
    if(!albero)
        return 0;
    else
    {
        if(albero->info == c)
            return albero;
        if (albero->info > c)
            return Cerca(albero->sx, c);
        else
            return Cerca(albero->dx, c);
    }
}
```

&nbsp;

**inserimento di un nodo BST (sol. tipo 1)**

* pre: albero è un albero BST
* post: inserisce un nodo in albero ed albero è un BST

```c++
nodo* Inserisci(nodo* albero, char c)
{
    if(!albero)
        return new nodo(c, 0)
    else
    {
        if(albero->info > c)
            r->sx = Inserisci(albero->sx, c);
        else
            r->dx = Inserisci(alberp->dx, c)
        
        return albero;
    }
}
```

&nbsp;

**inserimento di un nodo BST (sol. tipo 2 - ricorsiva)**

* pre: albero è un albero BST non vuoto
* post: inserisce un nodo in albero ed albero è un BST

```c++
void Inserisci(nodo* albero, char c)
{
    if(albero->info >= c)
        if(albero->sx)
            Inserisci(albero->sx, c);
        else
            albero->sx = new nodo(c);    
    else
        if(albero->dx)
            Inserisci(albero->dx, c);
        else
            albero->dx = new nodo(c);
}
```

&nbsp;

**inserimento di un nodo BST (sol. tipo 2 - iterativa)**

* pre: albero è un albero BST non vuoto
* post: inserisce un nodo in albero ed albero è un BST

```c++
void Inserisci(nodo* albero, char c)
{
    bool continua = true;
    while(continua)
    {
        if(albero->info >= c)
            if(albero->sx)
                albero = albero->sx;
            else
                albero->sx = new nodo(c);
                continua = false;
        else
            if(albero->dx)
                albero = albero->dx;
            else
                albero->dx = new nodo(c);
                continua = false;
    }
}
```