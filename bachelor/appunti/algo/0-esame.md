# Esercizi esame

* complessità
    * definizione formale delle 3 classi di complessità
    * metodo di sostituzione
    * master theorem

* dividi et impera (mergesort e ricorsione)
    * dimostrare per induzione gap, fix
    * gap(A) --> ritorna un gap di A, cioè se A[i+1] - A[i] > 1
         * vai a dest
    * over(A,x) --> ritorna il più piccolo elemento maggiore di x
        * vai a destra se minore, sinistra se maggiores
    * max(A) --> ritorna il massimo di A
        * m1 = max(parte sinistra), m2=max(parte destra)
    * fix(A) --> ritorna A[i] se A[i] = i
        * se A[i] < i  vai a destra, altrimenti a sinistra
    * subseq(X,Y,m,n) --> ritorna vero se X è contenuto in Y
        * si controlla X[m] == Y[n] e se sono uguali richiama con m-1 ed n-1, altrimenti con n-1
    * alternante(X) --> ritorna vero se X è alternante, cioè se A[i] < A[i+1] e A[i+1] > A[i+2] o viceversa

* ordinamento (counting sort e quick sort)
    * min(A,B) --> ritorna il minimo tra le 2 permutazioni A e B
        * si fissa i in A, e si scorre su B
    * revCountingSort(A,B,n,k) --> ritorna A ordinato decrescente in B
        * C[i] += C[i-1] diventa C[i] += C[i+1] partendo dalla fine
    * anagramma(A,B) --> verifica che A sia una permutazione di B
        * si fa il counting con A
        * si fa il decounting con B, true se C[0..k]=0
    * double(A,n) --> ritorna i,j t.c. A[j] = 2*A[i] in O(n)
    * top(A,n) --> max di un array bi-ordinato (una parte crescente ed una decrescente)
        * se la metà è minore del successivo cerca a destra, alrimenti a sinistra
    * perm(m,n) --> veridica che i 2 numeri m ed n siano due permutazioni
        * si svolge come anagramma ma per ottenere le cifre si fa modulo e divisione

* heap
    * secondMin(A) --> ritorna il minimo elemento maggiore della radice di un max heap
    * isMaxHeap(A) --> verifica che A sia un max heap
        * per ogni elemento fino a metà controlla che 2i e 2i+1 siano maggiori dell'elemento i
    * heapExtractMin(A) --> crea un min heap di A e ne ritorna l'elemento più piccolo
    * buildMaxHeap(A) --> costruisce un max heap da un array A

* alberi
    * maxPath(x) --> ritorna il cammino di costo massimo da x
        * se nil ret 0, se sx nil ret chiave + dx, stesso per dx, altrimenti ret chiave + max(maxPath(sx), maxPath(dx))
    * level(x, lv) --> ritorna numero di nodi che hanno chiave<=livello
        * se nil ret 0, numsx = level(sx,level+1), stesso con dx, ret sx + dx più 1 se chiave <= lv
    * isSumHeap(x) --> ritorna vero la somma delle chiavi sx e dx, se per ogni nodo la chiave è maggiore della somma delle chiavi del sottoalbero sx e dx
        * se nil ret true-0, else isSumheap(sx), isSumHeap(dx)
    * printFair(x, path) --> stampa i nodi tali per cui la somma del cammino per arrivare al nodo (escluso) è uguale alla somma del sottoalbero in quel nodo (incluso) e ritorna la somma del sottoalbero
        * se nil ret 0, sx = printFair(sx, chiave + path), stesso dx, sottoalbero = sx+dx+chiave e lo confronti con path
    * sdegree(x) --> ritorna il grado di squilibrio di x, la differenza tra le chiavi foglia a sx e dx
    * bal1(x) --> ritorna true se l'albero è true bilanciato, cioè se tutti i cammini dalla radice differiscono al massimo di 1
        * se nil ret 0-0, sxmin,sxmax=bal1(left), stesso per dx
    * k-bound(x,k) --> ritorna true se per ogni nofo di x la somma dei cammin alle foglie è <= k
    * complete(x) --> verifica che ogni nodo abbia due figli etutte le foglie hanno stessa distanza dalla radice
    * diff(x)

* tabelle hash
    * doppio hash e descrizione
    * chaining e descrizione 

* BST e red-black
    * pred(x) --> restituisce il predecessore di x nell stampa infissa
        * se sx, ret max subsx, else siccome infisso sali al pare finchè
    * isABR(A) --> verifica che l'array A sia un BST 
    * insert(T,z)
        * variante con x.pred
        * variante con x.even
    * **rep(T,k) --> ritorna il numero di occorrenze di k in T**
    * **BST(A) --> costruisce un BST di altezza minima da A e ritorna la radice**
    * range(T,k1,k2) --> fa la stampa infissa delle chiavi nel range k1,k2
        * non si analizzano sottoalberi troppo grandi/piccol
    * blackheight(T) --> per ogni nodo verifica che il numero di nodi neri in un cammino ad una foglia sia uguale
    * RBTree(T) --> verifica che T sia un red black tree