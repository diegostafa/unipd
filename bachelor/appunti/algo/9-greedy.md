# Programmazione greedy

di base:
* valuta un solo sottoproblema localmente ottimo
* arriva alla soluzione dimostrando che le soluzioni localmente ottime portnao alla soluzione globale

la soluzione S di un algoritmo greedy è quindi un insieme di n scelte:
* S = s1,s2,s3,s4 ... sn

**approccio**

per risolvere un problema greedy:
* evidenziare i passi di decisione
* evidenziare le possibili scelte localmente ottime/greedy
* evidenziare la sottostruttura ottima
    * dimostrare che il sottoproblema risultante unito alla scelta fatta porta alla soluzione globalmente ottima
    * solitamente si dimostra per assurdo con il metodo cut and paste

**correttezza**

* indica con A la soluzione dell'algoritmo
* indica con O la soluzione ottimale del problema
* assumi che A != O e trova una differenza tra le 2 soluzioni
* dimostra che sistemando le differenze la soluzione ottimale non cambia
    * spiega perchè A ed O sono differenti

**selezione attività**

definizione del problema:
* n attività con tempo inizio-fine
    * I[1..n] --> inizio
    * F[1..n] --> fine
* le attività sono ordinate in modo crescente su F
    * quindi per tempo di fine
* tempo totale T
* massimizzare il numero di attività compatibili in T

soluzione greedy:
* indicando con S(i,j) l'insime di attività che inizia dopo i e finisce prima di j
* scegli l'attività che finisce prima
* ricorsione fino a che non esaurisci T

```
selezione-attività(I, F) // inizio, fine
    A = {a1}
    last = 1
    for i = 2 to I.length
        if I[i] >= F[i]
            A += {ai}
            last = i

// 1. prende la prima attività (la più corta per definizione)
// 2. prende la prima attività che inizia dopo quella scelta
```


**codici di huffmann**

è una tecnicna di compressione:
* si ricavano le frequenze dei simboli
* si crea un albero tc la somma delle frequenze sia la minore

algoritmo, data una lista di nodi:
1. si prendono i 2 nodi con frequenza minore
2. si crea un nuovo nodo padre con la somma dei 2 nodi
3. si rimuvono i 2 nodi dalla lista inziale
4. si aggiunge il padre alla lista iniziale
5. ripetere fino ad avere un albero

spiegazione:
* viene creato un max heap, in cui i nodi più in alto sono quelli che si ripetono di più e usano quindi meno bit

**problemi greedy**

* selezione attività --> si prende l'attività più corta
* zaino --> si prende l'oggetto con costo/profitto migliore
* huffman --> codifichiamo i caratteri che si ripetono di più con meno bit
