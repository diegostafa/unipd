### Pattern Matching su liste concatenate

**match contiguo**

* pre: T e P sono liste ben formate
* post: restituisce true sse esiste un match P in T

```c++
nodo* match(nodo* T, nodo* P)
{
    if(!dimP)
        return true;
    if(!dimT)
        return false;
    if(T->info = P->info)
        return match(T->next, P->next);
    else
        return match(T->next, P);
}
```

**rimozione di un match anche non completo (v1)**

* pre: T e P sono liste ben formate
* post: T è la lista senza pattern e restituisce la lista che matcha il pattern

```c++
nodo* match(nodo* &T, nodo* P)
{
    if(!P || !T)
        return 0;
    if(T->info == P->info)
    {
        nodo* t = T;
        T = T->next;
        t->next = match(T, P->next);
        return t;
    }
    else
        return match(T->next, P);
}
```

**rimozione di un match solo se completo (v1)**

* pre: T e P sono liste ben formate e P non vuota
* post: restituisce il match di T sse c'è un match completo, altrimenti 0

```c++
nodo* match(nodo* &T, nodo* P)
{
    if(!T)
        return 0;
    if(T->info == P->info)
    {
        if(!P->next)
        {
            nodo* t = T;
            T = T->next;
            t->next = 0;
            return t;
        }
        else
        {
            nodo* z = match(T->next, P->next);
            if(!z)
                return 0;
            nodo* t = T;
            T = T->next;
            t->next = z;
            return t;
        }
    }
    else
        return match(T->next, P);
}
```


**rimozione di un match anche non completo (v2)**

* pre: T e P ben formate, x definita
* post: restituisce DN con M = lista match, R = lista restante

```c++
struct DN
{
    nodo* M;
    nodo* R;

    DN(m = 0, r = 0)
    {
        M = m;
        R = r;
    }
}

DN match(nodo* T, nodo* P, DN x)
{
    if(!P || !T)
        return x;
    if(T->info == P->info)
    {
        nodo* t = T->next;
        x.M = InsEnd(x.M, T);
        return match(t, P->next, x);
    }
    else
    {
        nodo* t = T->next;
        x.R = InsEnd(x.R T);
        return match(t, P, x);
    }
}
```


**rimozione di un match solo se completo (v2)**

* pre: T e P sono liste ben formate e P non vuota
* post: restituisce DN con M = lista match e R = resto della lista sse c'è match completo di P in T, altrimenti restituisce Dn con M = 0 e R = T

```c++
nodo* match(nodo* &T, nodo* P)
{
    if(!T)
        return DN(0,0);
    if(T->info == P->info)
    {
        if(!P->next)
        {
            nodo* t = T->next;
            T->next = 0;
            return DN(T, t);
        }
        else
        {
            DN z = match(T->next, P->next);
            if(!z.M)
                return DM(0, T);
            else
            {
                T = T->next = z.M;
                z.M = T;
                return <>;
            }
        }
    }
    else
    {
        DN z = match(T->next, P);
        T->next = z.R;
        z.R = T;
        return z;
    }
}
```
