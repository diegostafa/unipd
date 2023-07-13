## tipo del primo universo (tarski)

* rappresenta l'insieme di tutti i tipi piccoli, ma non se stesso
* è predicativo, non induttivo

```md
formazione:
    G cont
    -----------
    U0 type [G]

introduzioni:
    G cont
    ----------
    N0/N1/Nat...: U0 [G]

eliminazione:
    a: U0 [G]
    ---------
    T(a) type [G]

conversioni:
    G cont
    ------------------------------------
    T(N0/N1/Nat/...) = N0/N1/Nat/... [G]

```

## tipo del primo universo (russel)

stesse regole più o meno

## peculiarità della teoria di tipi di martin lof

* è una teoria aperta --> si può estendere aggiungendo tipi con giudizi decidibili
* con MLTT0/1/... viene indicato quali universi contiene
* l'insieme dei tipi piccoli senza universo non formalizza la matematica --> Id(Nat,0,1) non è dimostrabile senza universo