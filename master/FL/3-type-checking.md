## type checking rules

```
variable:
    x is in G
    G(x: t)
    -----------
    G |- (x: t)

lambda (must be annoted):
    G, (x: t1) |- (e: t2)
    ---------------------
    G |- (\x.e: t1 -> t2)

application:
    G |- (e1: t1 -> t2)
    G |- (e2: t1)
    -------------------
    G |- (e1 e2: t2)

let in:
    G |- (e1: t1)
    G(x:t1) |- (e2: t2)
    ---------------------------
    G |- (let x = e1 in e2: t2)

if then else:
    G |- (e1: t1)
    G |- (e2: t2)
    G |- (e3: t2)
    --------------------------------
    G |- (if e1 then e2 else e3: t2)

let rec in:
    G(x: t0), G(f: t0 -> t1) |- (e1: t1)
    G(f: t0 -> t1) |- (e2: t2)
    ---------------------------
    G |- (let rec f = \x.e1 in e2: t2)

    - let rec must be a lambda
    - to type check:
        - check the type of the lambda parameter
        - check the type of the function
        - derive the type of the function body
        - derive the type of the let rec body


derivation example:
    G |- (b: int)
    G |- ((b + 1): int)
    -------------------
    G |- (a: int)
    G(b: int) |- (b + 1: ?)
    -------------------------------
    G |- (7: ing)
    G(a: int) |. (let b = a in b + 1: ?)
    -----------------------------------------
    G |- (let a = 7 in let b = a in b + 1: ?)

    after deriving every subpart we know that the ? must be int
```

type checking rules :
* literal --> the type is its domain
* variable --> if the environment contains the variable, return the type
* lambda --> type check the parameter, extend the environment, type check the body
* application --> type check e1, type check e2, ensure e1 is a lambda
* let in --> type check e1, extend the environment with (var: t1), type check e2
* if then else --> type check e1 as bool, type check e1, type check e2 as e1