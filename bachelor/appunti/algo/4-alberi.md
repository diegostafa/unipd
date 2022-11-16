
# Strutture ad albero

**Alberi binari di ricerca (BST)**

sono alberi i cui nodi hanno a sinistra chiavi minori e a destra chiavi maggiori o uguali

ogni nodo x è così formato:
* x.k --> è la chiave
* x.p --> punta al padre
* x.left --> punta al figlio sx
* x.right --> punta al figlio dx

definizioni:
* padre sx di u--> padre di u che ha u nel sottoalbero sx
* padre dx di u--> padre di u che ha u nel sottoalbero dx

**visita di un albero**

2 modi:
* depth-first search (DFS)
* breadth-first search (BFS)

DFS:
* visita ricorsivamente i sottoalberi
* 3 varianti: pre/in/post fissa
* richiede uno stack

BFS:
* visita ogni livello
* richiede una coda
    * si prende un nodo si estraggono i figli

**stampa infissa BST**

la stampa di un BST avviene per ordine infisso, cioè prima il sottoalbero siistro, poi il nodo e poi il sottoalbero destro (di base stampa in ordine crescente)

```
infisso(x)
    if(x != nil)
        infisso(x.left)
        stampa(x.key)
        infisso(x.right)

// va ricorsivamente a sx e poi a dx
```

**min e max BST**

nodi con chiave minima e massima

```
min(x)
    if(x.left = nil)
        return x
    min(x.left)
// ricorsivamente a sx fino alla foglia
```

**successore BST**

il successore di un nodo u ritorna il più piccolo nodo maggiore di u

```
successore(x)
    if(x.right)
        return min(x.right)
    padre = x.p
    while padre and x != padre.left
        x = padre
        padre = padre.p
    return padre;
}
// se ha figlio dx ritorna il min
// altrimenti sale fino al primo padre sx
```

funzionamento:
* se u ha figlio dx
    * il successore è il min del sottoalbero dx di u
* se u non ha figlio dx
    * il successore è il primo padre che ha u nel suo sottoalbero sx

**ricerca BST**

la ricerca prende un nodo e una chiave da ricercare

```
ricerca(x,k)
    if(x = nil or x.key = k)
        return x
    if(x.key < k)
        return ricerca(x.left, k)
    else
        return ricerca(c.right, k)
```

**inserimento BST**

inserisce il nodo y mantenendo la proprietà di BST

```
insert(T, x)
    if curr = nil
        T.root = x
    
    curr = T.root
    prec = curr.p
    
    while curr != null
        prec = curr
        if x.k < curr.k
            curr = curr.left
        else
            curr = curr.right
    x.p  = prec


insert-rec(curr, x)
    if curr == null
        curr = x
    else
        if x.k <= curr.k 
            insert-rec(curr.left, x)
        else
            insert-rec(curr.right, x)               
```

**rimozione BST**

ci sono 3 casi:
* x non ha figli
    * si rimuove x
* x ha un solo figlio (sx o dx)
    * si rimuove x
    * si agganciano i pezzi
* x ha 2 figli
    * la chiave di x diventa  la chiave del suo successivo
    * si rimuove il successivo di x

**transplant**

sposta la nodo radice di un sottoalbero con un'altro nodo

```
trasplant(T, x, y)
    if(x.p = nil)
        T.root = y
    else
        if(x = x.p.left)
            x.p.left = y
        else
            x.p.right = y
    if(y != null)
        y.p = x.p
```

**rotazione dx/sx**

dati due nodi adiacenti, immagina di ruotare in senso orario/antiorario l'arco in mezzo
```
left-rotate(T, x)
    y = x.right // prende y
    
    // scambio consenziente
    x.right = y.left
    x.right.p = x
        
    // scambio consenziente
    y.left = x
    x.p = y

    transplant(T, x, y)
```


**alberi rosso-neri RBT**

sono BST, che rispettano le seguenti condizioni:
* ogni nodo è o rosso o nero
* la radice è nera
* le foglie sono nere
* se un nodo rosso i figli devono essere neri
* l'altezza nera di un nodo deve essere uguale per ogni foglia

**altezza nera**

l'altezza nera è il numero di nodi neri da un nodo (non incluso) ad un altro

**inserimento RBT**

ha 7 casi diversi, ti spari

**rimozione RBT**

ha 8 casi diversi, ti spari