# Algoritmi di ordinamento

**insertion sort**

ha complessità O(n^2), sposta a sinistra un elemento finchè non trova qualcosa di più piccolo, lo fa per ogni elemento

```
insertion sort(V):
    i = 1
    while i < V.length
        j = i
        while j > 0 and A[j-1] > A[j]
            swap(A[j], A[j-1])
            j--
        i++
```


**in-place merge sort**

ha complessità 𝛩(nlogn), è un algoritmo ricorsivo di tipo divide et impera, all'andata divide l'array, al ritorno lo ordina

```
mergesort(V, inizio, fine):
    if inizio < fine
        metà = (inizio+fine)/2
        mergesort(V, inizio, metà)
        mergesort(V, metà+1, fine)
        merge(V, inizio, metà, fine)

merge(V, inizio, metà, fine):
    L = V.split(inizio, metà)
    R = V.split(metà+1, fine)
    i=j=1
    for k da inizio a fine
        if L[i] <= R[j]
            V[k] = L[i]
            i++
        else
            V[i] = R[j]
            j++
```

**albero max heap**

il max heap è un albero binario nella quale ogni nodo è maggiore dei propri figli, un vettore è un albero binario nella quale ogni elemento di indice i (1 <= i <= metà-vettore) ha come figli quelli di indici 2i e 2i+1, nello stesso modo un vettore è un max heap quando ogni elemento di indice i è quindi maggiore di quelli di indice 2i e 2i+1

si può sempre trasformare un vettore in max-heap tramite il procedimento di max-heapify che scambia degli elementi per renderlo conforme alla definizione di max heap

proprietà max-heap:
* il primo elemento è sempre il più grande
* metà vettore è composto da nodi, l'altra metà da foglie

```
// rende max heap l'albero radicato in i
max-heapify(V, i):
    max = i
    if V[2i] > V[max]
        max =  2i
    if V[2i+1] > V[max]
        max = 2i+1
    if max != i
        swap(V[max], V[i])
        max-heapify(V, max)

// imposta l'indice alla cella nodo-figli con valore massimo
// se l'indice è diverso da quello iniziale, scambia e max heapify sul nodo sceso
```

**min heap**

come un max heap ma ogni nodo è minori dei propri figli

**heap sort**

ha complessità 𝛩(nlogn), trasforma il vettore in un max heap e siccome la radice è sempre il numero più grande del vettore, lo sposta in fondo (parte ordinata)

si suppone che V abbia i seguenti metodi:
* length --> lunghezza del vettore
* heapsize --> lunghezza del vettore da considerarsi come heap

```
// costruisce un max heap da un vettore non ordinato
// fa solo metà vettore perchè le foglie non devono rispettare dei vincoli
buildMaxHeap(V)
    for i = V.length/2 downto 1
        max-heapify(V,i)

heapsort(V)
    buildMaxHeap(V)
    for i = V.length downto 2
        swap(V[1], v[i])
        V.heapsize--
        max-heapify(V, 1)

// scambia la radice con l'ultimo nodo e max heapify la nuova radice
```

**quick sort**

ha complessità 𝛩(nlogn), è un algoritmo ricorsivo di tipo divide et impera, fissato un elemento del vettore (pivot):
* a sinistra mette tutti gli elementi minori o uguali del pivot
* a destra quelli maggiori
* contrario di mergesort, l'ordinamento viene fatto in andata e spezzato dopo

quindi la situazione è:
* S1 <= pivot < S2

per ordinare S1 ed S2 si riutilizza il quicksort ed alla fine si uniranno tutti i pezzi ordinati


```
// ordina parzialemnte il vettore sul perno
quicksort(V, inizio, fine)
    if inizio < fine
        q = pivot(V, inizio, fine) // ritorna il perno
        quicksort(V, inizio, q-1) // S1
        quicksort(V, q+1, fine) // S2

pivot(V, inizio. fine)
    perno = V[inizio]
    i = inizio
    j = fine
    while true
        while V[i] < perno // parte dall'inizio e si muove a dx finchè i valori sono minori del perno
            i++
        while V[j] > perno // parte dalla fine e si muove a sx finchè i valori sono maggiori del perno
            j--
        if i != j // scambia i valori che bloccano l'avanzamento degli indici
            swap(V[i], V[j])
        else
            break
    
    return i // posizione finale del perno
    
// setta il perno, avanza da sx e dx finche può quando non può da entrambi scambia 
```

di base prima si scegli un perno casuale (il primo elemento) e si ordinano tutti gli elementi attorno ad esso, poi si richiama ricorsivamente per S1 e S2

**counting sort**

ha complessità 𝛩(n+k) ed è oneroso in termini di spazio, si può utilizzare solo se si conosce il range di valori del vettore 0...k

si basa sul fatto che se per ogni elemento so quanti ce ne sono di più piccoli, allora so anche dove mettere quell'elemento
* elemento X ha 4 elementi più piccoli? ez allora X è in posizione 5

```
countingsort(V, k)
    count[0..k] = 0
    
    for i da 1 a V.length
        count[V[i]]++

    for i da 1 a k
        count[i] += count[i-1]
    
    for i da V.length a 1
        out[count[V[i]]] = V[i]
        count[V[i]]--
    
    return out

// crea un vettore lungo max(V)
// conta le frequenze
// conta ai precedenti
```

```        
reverse-countingsort(V, k)
    count[0..k] = 0
    for i da 1 a V.length
        count[V[i]]++

    for i = k-1 downto 0
        count[i] += count[i+1] 
    
    for i = V.length downto 1
        out[count[V[i]]] = V[i]
        count[V[i]]--

    return out
```