## giudizi

sono ciò che si vuole dimostrare:
```md
X è un tipo:
    [G]
    ----------
    A type [G]

qualcosa è di tipo X:
    [G]
    --------
    a: A [G]

2 tipi sono uguali:
    [G]
    ---------
    A = B [G]

2 termini dello stesso tipo sono uguali:
    [G]
    --------------
    a = b in A [G]
```

## regole

* corrispondono ai passi di derivazione
* di base i giudizi sono ciò a cui si vuole arrivare a dimostrare, mentre le regole il modo per arrivarci

## regole per i tipi

i tipi devono sottostare a 5 regole:
* formazione --> definisce come creare un tipo
* introduzione --> definisce come creare i termini di un tipo
* eliminazione --> definisce come usare i termini di un tipo per ottenere un altro tipo
* conversione --> come eliminazione
* uguaglianza --> definisce l'uguaglianza tra 2 termini di un tipo

## forme dei termini

i termini si possono trovare in
* forma normale --> non sono riducibili
* forma canonica --> sono definiti tramiti la regola di introduzione
* forma non canonica --> sono definiti da una regola di eliminazione

```
NF(t) =
    t se t in NF
    s se t riduce a s
```

## riducibilità

t si riduce a s se:
* t = s --> 0 step di riduzione
* t =k s --> k step di riduzione

## teoremi

* ammissibilità --> una regola è ammissibile (o derivabile) sse premessse derivabili impicano una conclusione derivabile
* confluenza --> se un termine riduce in 2 termini, i 2 termini sono uguali
* forma normale debole --> per un termine esiste un altro termine a cui esso riduce
* forma normale forte --> ogni termine può essere ridotto
