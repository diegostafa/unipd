## regole strutturali

regole necessarie ad ogni teoria dei tipi

## regole di contesto

i giudizi dipendono dal contesto, il contesto è paragonabile ad una knowledge base
```md
creazione del contesto:
    [] cont

formazione/espansione del contesto:
    A type [G]
    ----------
    (G, x: A) cont

assuzione delle veriabili:
    (G, x: A, D) cont
    -----------------
    x: A [G, x: A, D]
```

## regole di uguaglianza

```md
uguaglianza (identità):
    A type [G]
    ----------
    A == A [G]

uguaglianza (riflessiva):
    A == B [G]
    ----------
    B == A [G]

uguaglianza (transitiva):
    A == B [G]
    B == C [G]
    ----------
    A == C [G]

// analogamente le stesse regole si applicano anche ai termini
```

## regole di conversione

```md
conversione di tipaggio
    a: A [G]
    A = B [G]
    ---------
    a: B [G]

conversione di uguaglianza
    a = b in A [G]
    A = B [G]
    --------------
    a = b in B [G]
```

## regole di indebolimento

di base i giudizi rimangono tali se il contesto viene esteso

```md
indebolimento di tipo
    A type [G]
    (G, D) cont
    -------------
    A type [G, D]

// resto delle regole uguali per termini/uguaglianza
```

## regole di sostituzione

```md
tra tipi
    c: C [G]
    b: B(c) [G]
    A(x, y) type [G, x: C, y: B(x)]
    -------------------------------
    A(c, b) type [G]

tra uguaglianza di tipi
    c: C [G]
    b: B(c) [G]
    a(x, y): A(x, y) [G, x: C, y: B(x)]
    -----------------------------------
    a(c, b): A(c, b) [G]

tra termini
    A(x) type [G, x: C]
    c = e in C [G]
    -------------------
    A(c) = A(e) [G]


tra uguaglianza di termini
    a(x): A(x) [G, x: C]
    c = e in C [G]
    -----------------------
    a(c) = a(e) in A(c) [G]
```

## regole di sanity check

```md
se il contesto è derivabile ache una sua parte è derivabile
    (G, D) cont
    -----------
    G cont

se un tipo è derivabile in un contesto anche il contesto è derivabile
    A type [G]
    ----------
    G cont

se l'uguaglianza di 2 tipi è derivabile anche i tipi stessi lo sono
    A = B [G]
    ----------
    A type [G]
    B type [G]

se il tipo di un termine è derivabile anche il tipo del termine lo è
    a: A [G]
    ----------
    A type [G]

se l'uguaglianza di 2 termini è derivabile anche i 2 termini lo sono
    a = b in A [G]
    --------------
    a: A [G]
    b: A [G]
```