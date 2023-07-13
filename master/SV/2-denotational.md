## terminology

* FIX --> FIX F gives the least defined fix point solution of F
* fix point solution --> x is a fixed point solution of F if F(x) = x
* pre fix point --> any point below a fix point, f(x) <= x
* post fix point --> any point above a fix point, f(x) >= x
* hasse diagram --> diagram to visualize order relations between elements
* POSET --> set with a partial order operator (<=) (reflexivity, transitivity, anti symmetry)
* least element/bottom --> if it exist, is the element <= every other element in a POSET
* power set --> special POSET, the partial order operator is the inclusion, the least element is the empty set
* upper bound --> element >= any other element
* lower bound --> element <= any other element
* LUB/top --> least upper bound
* GLB/bottom --> greatest lower bound
* chain --> every element can be compared (empty set is a chain)
* CCPO -->  POSET in which every chain has a lower bound
* lettice --> POSET in which any pair of element has LUB and GLB
* complete lettice --> POSET in which any subset of it has LUB and GLB

## partial ordering partial functions

f1 is less or equal than f2 iff f1(x) = f2(x) for every x

example:
* `f1(s) = s for all s`
* `f2(s) = s if s >= 0`
* `f3(s) = s if s = 0`
* `f4(s) = s if s <= 0`

then:
* f3 <= f2/f4 <= f1 --> visualized as hasse diagram
* f2 and f4 can't be compared

it's a POSET such that:
* any pair of it must have a LUB and GLB

a finite lettice is always a complete lettice

## continuos function

given:
* D, D' CCPO
* function f

then f is continuos if:
* f is monotone
* `LUB f d = f (LUB Y) for all Y = chains of D`

## kleene knaster tarski theorem / kleene iteration sequence

ip:
* f is a continuos function
* the domain is a CCPO

th:
* `FIX f = LUB { f^n bottom | n >= 0}`

and that's the least fix point of f

example:
```
f bt = undef

f' bt =
    | s if sx = 1
    | undef otherwise

f" bt =
    | s if sx = 1 or sx = 2
    | s[y -> sy * 2][x -> 1]
```