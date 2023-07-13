
## language BNF

```
// type
t =
    | data type
    | type -> type
    | tv

// type variable
tv = 'a | 'b | ...

// expression
e =
    | var
    | \var.e
    | e e
    | let [rec] var = e1 in e2

//values
val =
    | literal
    | closures

// environment - gamma
G =
    | empty
    | G, (var: t) // G is extended with var of type


// evaluation - delta
D =
    | empty
    | F, (var -> v) // D is extended with var of value v

// type scheme - sigma
S =
    | tv, t
```