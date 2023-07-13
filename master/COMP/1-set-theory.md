## relation

subset of cartesian product of two sets A, B that holds for some property
* `R = { (a, b) : P(a, b) }`

## function

special type of relation where in any pair of the relation:
* if (a, b') holds and (a, b") holds then b'=b"

## finite function

function where the domain is finite and defined on it, undefined everywhere else

## predicate

* (definition 1) a normal relation on A, B
* (definition 2) a characteristic function f : AxB -> {1, 0}

## domain

subset of the input, in which the function is defined

## cardinality

* number of element in a set
* |A| == |B| if there exist a bijective function f : A -> B
* |A| <= |B| if there exist an injective function f : A -> B
* |A| >= |B| if there exist a surjective function f : A -> B

## enumerable set

* means countable --> |A| <= |N|
* relations/operations between countable set are countable

## poset - partially ordered set

basically a set in which is defined a partial ordering relation

the relation is `<=` and must obey these properties:
* reflexivity --> x <= x
* antisymmetry --> if x <= y and y <= x then x = y
* transitivity --> if x <= y and y <= z then x <= z

## well founded poset

* poset which has a minimal element
* a set is well founded iff there is no infinite ascending chain
* Z is not well founded --> does not have a least element
* N is well founded

## normal induction proof

* prove P(0)
* if P(n-1) then P(n)

## complete induction proof

* prove P(0)
* for each m < n if P(m) then P(n)

## complete induction proof over a well founded poset

* prove P(least)
* for each m < n if P(m) then P(n)

## diagonalization

* given a set it is possible to build an object different from every element of the set

consequences:
* the power set of N is not countable
* the set of all functions is not countable
* there exist a total non computable function
    * proof --> by diagonalization on the c-class we build a new function, total because it's defined on every input, but not computable because not inside the c-class

```
total non computable function

row = computable functions
col = input

    0       1       2       ...
f0  f0(0)   f0(1)   f0(2)   ...
f1  f1(0)   f1(1)   f1(2)   ...
f2  f2(0)   f2(1)   f2(2)   ...
...

- let d(x) the diagonal f0(0), f1(1) ...

let f'(x) =
     | fx(x) + 1 if f(x) terminate
     | 0 oterwise

f is not compuable because it is different from any given fn in fn(n )

```


## enumeration of a sequence

base case:
* `E(x, y) --> 2^x * (2y+1) - 1`

recursive case:
* `E(x, y, z) --> E(E(x, y), z)`