## terminology

* operational semantics --> formal definition of semantic, the meaning given to the syntax is based on it induced computation
* denotational semantics --> formal definition of semantic, the meaning given to the syntax is modelled as partial functions

* program equivalence --> two programs P and Q are equivalent if they have the same semantic
    * S;skip = S
    * S1;(S2;S3) = (S1;S2);S3
    * while b do S = if b then (S; while b do S) else skip

## while language

syntactic categories:
* `n in Num` --> numerals
* `x in Var` --> variables
* `a in Aexp` --> arithmetic expressions
* `b in Bexp` --> boolean expressions
* `S in Stm` --> statements

grammar rules:
* `n ::= 0 | 1 | n 0 | n 1`
* `x ::= n |`
* `a ::= n | x | a1 +-* a2`
* `b ::= true | false | a1 <=> a2 | !b | b1 and b2`
* `S ::= x := a | skip | S1;S2 | if b then S1 else S2 | while b do S1 | abort | S1 or S2 | S1 par S2 | [S]`

semantic categories:
* `N = {0, 1, 2 ...}` --> natural numbers
* `T = {tt, ff}` --> booleans
* `State = Var -> N`
    * lookup --> `s x`
    * update --> `s' = s[y -> v]`

linking syntactic and semantic categories:
* `~N : Num -> N`
* `s in State = Var  -> N`
* `~A : Aexp -> State -> N`
* `~B : Bexp -> State -> T`
* `~S : Stm -> State -> State`
* `~FV : Aexp --> { Var }`

semantic of arithmetic expressions:
* `~A[n]s = ~N[n]`
* `~A[x]s = s x`
* `~A[a +-* a2]s = ~A[a1]s +-* ~A[a2]s`

semantic of boolean expressions:
* `~B[true]s = tt`
* `~B[false]s = ff`
* `~B[a1 <=> a2]s = tt if the condition is met, ff otherwise`
* `~B(!b)s = tt if ~B[b]s is ff, ff otherwise`

semantic of free variables:
* `~FV(n) = {}`
* `~FV(x) = {x}`
* `~FV(a1 +-* a2) = ~FV(a1) U ~FV(a2)`

semantic of substitution:
* `n[y->a] = n`
* `x[y->a] = a if x == y, x otherwise`
* `(a1 +-* a2)[y->a] = a1[y->a0] +-* a2[y->a0]`

operational semantic of statements:
```
assignment:
    <x:=a, s> -> s[x->~A[a]s]

skip:
    <skip, s> -> s

1° composition rule:
    <S1, s> -> <S1', s>
    --------------------------
    <S1;S2, s> -> <S1';S2, s'>

2° composition rule:
    <S1, s> -> s'
    --------------------------
    <S1;S2, s> -> <S2, s'>

if - true condition:
    <if b then S1 else S2, s> -> <S1, s>

if - false condition
    <if b then S1 else S2, s> -> <S2, s>

while with true condition:
    <while b do S, s> -> <if b then (S; while b do S) else skip, s>
```

denotational semantic of statements:
```
model:
    ~S : Stm -> (State -> State)

assignment:
    ~S[x:=a]s = s[x->~A[a]s]

skip:
    ~S[skip] = id

    where:
    id s = s


composition - defined:
    ~S[S1;S2] = ~S[S2] ° ~S[S1]

    where:
    (f ° g)s =
        - f(g s) if g s and f(g s) are defined
        - undefined otherwise

composition - not defined:
    ~S[S1;S2] = undef

if then else:
    ~S[if b then S1 else S2] = cond(~B[b], ~S[S1], ~S[s2])

    where:
    cond(p, g1, g2) is the ternary operator (give undef if the branch function is undef)

while:
    ~S[while b do S] = FIX F

    where:
    F g = cond(~B[b], g ° ~S[S], id)

    FIX is the least fix point of F
```

## extended while language

adding abort:
* no rule is needed --> derivation is stuck

adding non determinism between statements:
```
or - first choice:
    <S1 or S2, s> -> <S1, s>

or - second choice:
    <S1 or S2, s> -> <S2, s>
```

adding parallelism:
```
par - first thread run entirely:
    <S1, s> -> s'
    --------------------------
    <S1 par S2, s> -> <S2, s'>


par - first thread interrupted:
    <S1, s> -> <S1', s'>
    ----------------------------------
    <S1 par S2, s> -> <S1' par S2, s'>


par - second thread run entirely:
    <S2, s> -> <S2', s'>
    ----------------------------------
    <S1 par S2, s> -> <S1 par S2', s'>

par - second thread interrupted:
    <S2, s> -> s'
    --------------------------
    <S1 par S2, s> -> <S1, s'>

explanation:
- premise S1 terminates --> S2 is left to execute with the changed state
- premise S1 is interrupted --> S1 and S2 are stil in parallel, but the state has been changed and S1 has advanced
```

adding synchronization (thread can't be interrupted):
```
sync - S terminates in one step:
    <S, s> -> s'
    --------------------
    <[S], s> -> s'

sync - S terminates in multipl steps:
    <S, s> -> <S', s'> and <[S'], s'> -> s"
    ---------------------------------------
    <[S], s> -> s"

explanation
- premise S terminates in one step --> the the sync of that instruction is the same
- premise S does not terminate and the sync of the remaining instruction produce an new state --> the sync of the instruction produce the resulting state of the remaining
```

