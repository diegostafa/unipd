## tipo singoletto

rappresenta un insieme contenente un unico elemento

eliminazione:
* se abbiamo un singoletto a
* una famiglia di tipi sul singoletto M
* un oggetto di tipo M(*)
* allora possiamo creare un oggetto di tipo M(a)

```md
formazione:
    G cont
    -----------
    N1 type [G]

introduzione:
    G cont
    ---------
    *: N1 [G]

eliminazione:
    a: N1 [G]
    b: M(*) [G]
    M(z) type [G, z: N1, D]
    --------------------
    El_N1(a,b): M(a) [G]
```

## tipo dei naturali

eliminazione:
* se abbiamo un numero
* una famiglia di tipi sui naturali, M
* un oggetto di tipo M(0)
* un oggetto di tipo M(succ(n))
* allora si pul costruire un oggeto di tipo M con il nostro numero

```md
formazione:
    G cont
    ------------
    Nat type [G]

introduzione (caso  base):
    G cont
    ----------
    0: Nat [G]

introduzione (caso ricorsivo):
    n: Nat [G]
    ----------------
    succ(n): Nat [G]

eliminazione:
    a: Nat [G]
    b: M(0) [G]
    e(x, y): M(succ(x)) [G, x: Nat, y: M(x)]
    M(z) type [G, z: Nat, D]
    ----------------------------------------
    El_nat(a,b,e): M(a) [G]
```

## tipo lista

```md
formazione:
    A type [G]
    ----------------
    List(A) type [G]

introduzione (caso base):
    List(A) type [G]
    ----------------
    nil: List(A) [G]

introduzione (caso ricorsivo):
    s: List(A) [G]
    a: A [G]
    -----------------------
    cons(S, a): List(A) [G]

eliminazione:
    a: List(A) [G]
    b: M(nil) [G]
    e(x,w,y): M(cons(x,w)) [G, x: List(A),  w: A, y: M(x), D]
    M(z) type [G, z: List(A), D]
    ---------------------------------------------------------
    El_Ls(a,b,e): M(a) [G]

uguaglianza di tipo:
    A1 = A2 [G]
    -----------------------
    List(A1) = List(A2) [G]

uguaglianza di termini:
    s1 = s2 in List(A) [G]
    a1 = a2 in A [G]
    -------------------------------
    cons(s1, a2) = cons(s2, a2) [G]
```

## tipo identità proposizionale

rappresenta l'uguaglianza tra termini in un tipo

eliminazione:
* se abbiamo un oggetto identitò
* un oggetto di M istanziato su un'identità
* allora possiamo creare un oggetto M con la nostra identità

```md
formazione:
    A type [G]
    a: A [G]
    b: A [G]
    ------------------
    Id(A,a,b) type [G]

introduzione:
    a:A [G]
    --------------------
    Id(a): Id(A,a,a) [G]

eliminazione:
    t: Id(A,a,b) [G, a: A, b: A]
    e(x): M(Id(x),x,x) [G]
    M(z,z2,z3) type [G, z1: A, z2: A, z: Id(A,z1,z2)]
    -------------------------------------------------
    El_Id(t,e): M(t,a,b) [G]

uguaglianza:
    A1 = A2 [G]
    a1 = a2 in A1 [G]
    b1 = b2 in A2 [G]
    -------------------------------
    Id(A1,a1,b1) = Id(A2,a2,b2) [G]
```

## tipo somma binaria

di base rappresenta una classe base, con 2 sottoclassi (inl, inr), o un ADT

eliminazione:
* se abbiamo una somma binaria
* un oggetto M istanziato su un inL
* un oggetto M istanziato su un inR
* allora possiamo creare un oggetto M instanziato sulla nostra somma binaria

```md
formazione:
    A type [G]
    B type [G]
    ------------
    A+B type [G]

introduzione sx:
    a: A [G]
    B type [G]
    ---------------
    inL(a): A+B [G]

introduzione dx:
    b: B [G]
    A type [G]
    ---------------
    inR(b): A+B [G]

eliminazione:
    t: A+B [G]
    e1(x1): M(inL(x1)) [G, x1: A]
    e2(x2): M(inR(x2)) [G, x2: B]
    M(z) type [G, z: A+B, D]
    -----------------------------
    El_+(t,e1,e2): M(t) [G]
```

## tipo prodotto binario

rappresenta una tupla

eliminazione:
* di base si può fare la proiezioni delle componenti su una tupla

```md
formazione:
    B type [G]
    C type [G]
    ------------
    BxC type [G]

introduzione:
    b: B [G]
    c: C [G]
    --------------
    (b,c): BxC [G]

eliminazione-1:
    d: BxC [G]
    -----------
    El_p1(d): B [G]

eliminazione-2:
    d: BxC [G]
    -----------
    El_p2(d): C [G]
```

## tipo freccia

versione semplificata del prodotto dipendente

## tipo somma dipendente

* generalizzazione della somma binaria
* indica un tipo sottoposto ad una condizione
* i termini sono coppie: valori che rispettano la condizione + dimostrazione che la rispettano
* rappresenta: assioma di separazione e quantificatore esistenziale
* ~S(C,B) --> somma disgiunta di C al variare di B

formazione:
* data una famiglia di tipi su parametro B
* si può creare la somma disgiunta n-aria al variare di B

introduzione:
* se abbiamo un oggetto b
* e un oggetto c istanziato su b
* allora possiamo creare una tupla (b,c)

eliminazione:
* se abbiamo un oggetto di somma dipendente
* un oggetto di tipo M instanziato su una somma dipendente
* allora possiamo creare un oggetto di tipo M istanziato sulla nostra somma dipendente

```md
formazione:
    C(x) type [G, x: B]
    -------------------
    ~S(C,B) type [G]

introduzione:
    b: B [G]
    c: C(b) [G]
    --------------
    (b,c): ~S(C,B) [G]

eliminazione:
    t: ~S(C,B) [G]
    e(x,y): M((x,y)) [G, x: B, y: C(x)]
    M(z) type [G, z: +++ C(x)]
    -----------------------------------
    El_S(t,e): M(t) [G]
```

## tipo prodotto dipendente

* rappresenta le funzioni, in logica l'implicazione
* in logica l'applicazione è il modus ponens
* ~P(C,B) --> prodotto dipendente di C(x) al variare di B

formazione:
* data una famiglia di tipi su parametro B
* si può creare il prodotto dipendente variando B

introduzione:
* data una famiglia di tipi su parametro B
* e un suo oggetto istanziato su B il quale dipende anch'esso da B
* allora è possibile creare una lambda che prende il parametro di istanziazione e lo applica all'oggetto

eliminazione
* se abbiamo un oggetto b
* e una lambda
* allora è possibile applicare b alla lambda

```md
formazione:
    C(x) type [G, x: B]
    -------------------
    ~P(C,B) type [G]

introduzione:
    c(x): C(x) [G, x: B]
    --------------------
    \x.c(x): ~P(C,B)

eliminazione:
    b: B [G]
    f: ~P(C,B) [G]
    --------------
    Ap(f,b): C(b) [G]
```

## tipo vuoto

rappresenta il falso, tipo vuoto

```md
formazione:
    G cont
    ------
    N0 [G]

introduzione:
    non ha elementi

eliminazione:
    t: N0 [G]
    M(z) type [G, z: N0]
    --------------------
    El_N0(t): M(t) [G]
```
