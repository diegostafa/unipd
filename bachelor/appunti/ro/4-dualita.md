**coppia primale-duale**

dato un PL1 che ammette soluzione ottima, detto primale:
* z = min cx
* Ax ~ b // m vincoli
* dominio var x // n variabili

allora è possibile scrivere un PL2 equivalente, detto duale:
* w = max ub
* uA ~ c // n vincoli
* dominio var u  // m variabili

conversione primale-duale:
* vincolo --> variabile di segno uguale
* var --> vincolo di segno opposto
**teorema trasformazione duale doppia**

il duale del duale è il primale

**teorema della dualità forte**

il primale ammette ottimo finito sse il duale ammette ottimo finito

**teorema della dualità debole**

z è sempre maggiore di w, quindi:
* z identifica upper bound dell'ottimo
* w identifica lower bound dell'ottimo

**corollario forte-debole**

w è ugaule a z sse x e u sono le soluzioni ottime

**corollario inamissibilità**

* se il primale è illimitato allora il duale è inamissibile
* se il duale è illimitato allora il primale è inamissibile

**corollario soluzione ottima**

dato un primale e il suo primale, siccome la soluzione ottima è z=w, allora si può scrivere il sistema lineare:
* z = w
* Ax = b
* uA = c

e risolverlo normalmente (è facile da fare solo se i vincoli sono d'uguaglianza e le variabili libere)

**CCPD - condizioni di complementarietà primale-duale** 

x e u sono soluzioni ottime sse:
* x è ammissibile primale
* u è ammissibile duale
* ui(Aix - bi) = 0 per ogni vincolo
* xi(Aiu - di) = 0 per ogni vincolo

algoritmo data una soluzione primale:
1. verifico ammissibilità primale
2. passo al duale
3. scrivo CCPD
    * ricavo i possibili ui sostituendo la soluzione primale nel CCPD
5. scrivo il sistema per trovare i restanti ui

data una soluzione x verificare ottimalità in PL1 con CCPD:
* verifico ammissibilità x in PL1
* scrivo il problema PL2 duale corrispondente
* scrivo tutte confizioni di complementarietà
* risolvi il sistema trovato
* verifica l'ammissibilità della soluzione duale
* verifica che z(x) = w(u)