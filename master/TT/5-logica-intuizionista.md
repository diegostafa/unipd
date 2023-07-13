 ## principi di induzione

singoletto:
* se M(z) prop [G, z: N1] derivabile, allora
    * se M(*)
    * allora M(x) derivabile per ogni x in N1

naturali:
* se M(z) prop [G, z: Nat] derivabile, allora
    * se M(0) && M(x) -> M(succ(x)) per ogni Nat
    * allora allora M(x) derivabile per ogni Nat

lista:
* se M(z) prop [G, z: List(A)] derivabile, allora
    * se M(nil) && M(x) -> M(cons(x, w)) per ogni x in List(A), w in A
    * allora M(x) derivabile per ogni x in List(A)

somma binaria:
* se M(z) prop [g, z: A+B] derivabile, allora
    * se M(inl(x)) && M(inr(y)) per ogni x in A, y in B
    * allora M(x) derivabile per ogni x in A+B

somma dipendente:
* se M(z) prop [g, z: S(C,B)] derivabile, allora
    * se M((x, y)) per ogni x in B, y in C(x)
    * allora M(x) derivabile per ogni x in S(C,B)

## equivalenza tra tipi

2 tipi A, B sono equivalenti se:
* A <-> B true [G]

## isomorfismo tra tipi

2 tipi A, B sono isomorfi, se derivano 2 termini f(x), h(y) tali per cui:
* pf1: Id(A, x, h(f(x)))
* pf2: Id(B, y, f(h(y)))