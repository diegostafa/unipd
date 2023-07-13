## evaluation rules

```
variable:
    x is in D
    D(x -> v)
    -----------
    D |- (x -> v)

lamdba:
    D |- (\x.e -> <\x.e, D>) // lambdas evaluate to closures

application:
    D(e1 -> \x.e0, D'>) // the closure where the lambda was initially defined
    D(e2 -> v2) // evaluation of e2
    D'(x -> v2) |- (e0 -> v0) // evaluation of the closure with e2
    -----------------
    D |- (e1 e2 -> v0)

let in:
    D |- (e1 -> v1)
    D(e1 -> v1) |- (e2->v2)
    -----------------------------
    D |- (let x = e1 in e2 -> v2)

if then else:
    D |- (e1 -> true)
    D(e1 -> v1) |- (e2 -> v2)
    --------------------------------
    D |- (if e1 then e2 else e3 -> v2)

    D |- (e1 -> false)
    D(e1 -> false) |- (e3 -> v3)
    --------------------------------
    D |- (if e1 then e2 else e3 -> v3)

let rec in:
    D |- \x.e1 -> <\x.e1, D', f> // rec closure
    D(f -> <\x.e1, D', f>) |- (e2 -> v2)
    -----------------------------
    D |- (let rec f = \x.e1 in e2 -> v2)

application with rec closure:
    D |- (e1 -> <\x.e0, D', f>)
    D |- (e2 -> v2)
    D'(x -> v2)(f -> <\x.e0, D', f>) |- (e0 -> v0)
    ----------------------------------------------
    D |- (e1 e2 -> v0)

derivation example:
```

evaluation rules:
* literal -->
* variable -->
* lambda -->
* application -->
* let in -->
* if then else -->