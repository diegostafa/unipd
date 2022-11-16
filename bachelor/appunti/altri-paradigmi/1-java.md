**packages**

* package sono chiamati con nomi di dominio in ordine inverso
    * com.oracle.package

**classi**

* dichiarate in PascalCase
* appartiene sempre ad un package
* il package di appartenenza deve essere dichiarato nella prima riga
* se la classe definisce il package.di.appartenenza allora si deve trovare nella cartella package/di/appartenenza rispetto al CLASSPATH

**visibilità**

* default --> la classe è visibile da tutte le classi interne al package, ma non al di fuori
* pubblica --> visbile da tutti

**struttura classe**

* variabili sempre in camelCase, tranne costanti
* modificatori variabili
    * final --> come una costante in c++
    * transient --> non viene serializzata
    * volatile -->

**eccezioni**

* class throwable
    * class exception --> errori non bloccanti
        * class runtimeEception --> errori nella valutazione delle espressioni
    * class error --> errori bloccanti

**inizializzatori**

porzione di codice anonimo eseguito in determinati momenti,possono essere:
* statici --> eseguiti a cascata al caricamento della classe
* di istanza --> eseguiti a cascata durante la crezione di un'istanza

**ereditarietà**

* sintassi --> class D extends B
* solo singola, evita diamond problem
* la sottoclasse ha accesso a tutto tranne che per imembri privati della superclasse
* tutti i metodi di classe sono virtual di default

**interfacce**

* dichiarazione di un tipo, senza implementazione
* possono ereditare solo da altre interfacce
* non può essere privata
* membri pubblici di default
* variabili pubbliche e final di default
* possono contenere costanti, metodi astratti e statici
* possono contenere metodi di defualt --> hanno implementazione che la derivata può non implementare
* permettono l'ereditarietà multipla
* diamond problem viene segnalato dalla JVM con un errore

**annotazioni**

* particolare interfaccia che inizia con @
* es @deprecated, @override

**generics**

classi o funzioni templatizzate alla c++


**tipi**

* java ha 2 tipi
    * primitivi
    * oggetti

* i primitivi possono essere trasportati in oggetti con le classi Primitive relative
* i primitivi onn sono trattati come oggetti, non possono essere parametri di tipo nei template
* autoboxing --> sebbene i primitivi non possano essere usati come oggetti, java se ne accorge e dfa la conversione automatica

**modificatori**

classi:
* final --> la classe non può essere ereditata
* abstract --> la classe deve essere ereditata
* strictfp --> strict floating point, espressione in virgola mobile deve combaciare di tipo, non sono ammesse conversioni

metodi:
* astract --> deve essere implementato
* static --> legato alla classe non all'istanza
* final --> implementato nativamente
* strictfp --> strictfp applicato al metodo
* synchronized --> può essere usato da un solo thread per volta

**record**

strutture alla c++, di default:
* ha membri privati
* metodi pubblici
* equals, hash e tostring autogenerati
* possono implementare interfacce, generici, de base sono classi

**this/super**

* this --> rappresenta la classe corrente
* super --> rappresenta il padre

**lambda exp**

```java
(x, y) -> x+y
(int x, int y) -> { return x+y; }
```

* non rende java un linguaggio funzionale
* viene tradotto in una funzione normale

**librerie standard**

* IO
* NIO --> async IO
* collezioni
    * set, dequeue, list, map
    * iteratori
* stream --> descrive una sequenza, pipeline di esecuzione che produce un risultato
* time
* sockets
* diagram
* channel
* url