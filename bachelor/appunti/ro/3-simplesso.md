**forma canonica del problema PL**

* Ax = b
* A matrice mxn con m < n (ci servoo infinite soluzioni)
* B = base delle colonne di A
* A = (B|F) --> scambio le colonne della base trovata a sx
* x = (xb xf) --> scambio le righe del vec x per associarle
* Bxb + Fxf = b --> sostiutisco 
* B'Bxb + B'Fxf = B'b --> moltiplico per l'inversa di B
* xb = B'b - B'Fxf --> esplicito xb (B'B = 1) 
* z = zb + zf --> variabili usate in xb e variabili usate in xf (zf = 0)
* z = cbxb + cfxf
* z = cb(B'b - B'Fxf) + cfxf --> sostituisco xb
* z = cbB'b - cbB'Fxf + cfxf --> moltiplico
* z = cbB'b + xf(cf - cbB'F) --> raccolgo
* z = cbB'b --> cf è 0 nella soluzione di base 

visualmente:
* (A|b) --> Ax = b
* (B F|b) --> sposto le colonne della base a sinistra, cioè Bxb + Fxf = b
* (I F^|b^) --> applico gauss-jordan e B diventa Id, cioè B'Bxb + B'Fxf = B'b
* (I|b^ -F^) --> isolo l'identità, cioè xb = B'b - B'Fxf

forma canonica rispetto alla base B:
* z = zb + zf --> zb è un numero, zf è 0
* xb = B'b - B'Fxf --> le variabili in base espresse come combinazione lineare delle variabili fuori base

soluzione brute force:
* una soluzione per la base B la si trova ponendo xf = 0 
* si può reiterare questo procedimento cambiando base
* la soluzione è però ammissibile solo se B'b >= 0, in quanto ogni variabile deve essere >= 0 nella forma standard

**coefficente di costo ridotto**

sono tutti i coefficenti delle variabili fuori base che compaiono in z

**teorema sufficiente di ottimalità**

data una forma canonica, se tutti i costi ridotti sono positivi allora B è una base ottima

**metodo del simplesso**

cambia base per la forma canonica finchè non trova una base ottima, per far ciò prende cambia base con una adiacente, che migliori la soluzione e che sia ammissibile:
* variabile entrante --> deve migliorare
    * coefficente di costo ridotto < 0
* variabile uscente --> deve mantenere l'ammissibilità
    * si prende il minimo del rapporto tra b/coeff. var. entrante
algoritmo:
1. scegliere una soluzione ammssibile di base B
2. mettere in forma canonica
3. se i coeff. di costo ridotto sono >= 0 
    * stop, PL ottimo
4. scelgo una qualsiasi var di costo ridotto negativo
5. se la colonna ha solo coefficenti negativi
    * stop, PL illimitato
6. variabile entrante = variabile scelta
7. variabile uscente = var che ha il minimo rapporto
8. cambio base

**simplesso in forma tabellare**

```
(zb|zf|-1|0) --> riga 0 per la funzione obiettivo
(B |F | 0|b) --> riga restanti per base e colonne libere

si fa gauss-jordan:
(0|zf^|-1|0)
(I|F^|0|b^)

- si controlla l'ottimalità nella prima riga
- si controlla la illimitatezza
    - prendo un coefficente di costo ridotto negativo
    - se tutti i numeri in quella colonna sono negativi --> PL illmitato
- scambio le variabili
    - prendo una var esterna con coeff negativo
    - prendo la colonna sottostante a cui appartiene
    - divido i coefficenti b con i coeffiecenti della colonna presa
    - prendo la posizione della riga che ha risultato minore
    - la variabile in quella posizione è la variabile uscente
```

**base degenere**

un base si dice degener quando ci possono essere più rapporti minimi nello scambio di colonne

**anticiclo di bland**

per garantire la convergenza del simplesso bisogna sempre prendere la variabile con costo ridotto negativo di indice più basso, stessa cosa per quella che esce di base

questa regola garantisce anche 