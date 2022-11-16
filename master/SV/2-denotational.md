**FIX**

FIX F gives the least defined fixed point solution of F

**fixed point solution**

g is a fixed point solution of F if:
* F g = g

**hasse diagram**

diagram to visualize order relations between elements

**partial order set - POSET**

given:
* set S
* some ordering <= 

then S is a POSET if for every element:
* a <= a --> reflexivity
* a <= b and b <= c then a <= c --> transitivity
* a <=b and b <= a then a = b --> anti symmetry

**least element / bottom**

given a partial set D, d is the least/bottom element if d <= every other element

doesn't always exist

**power set**

the power set of a set is a POSET on the inclusion ordering and the least element is the empty set

**partial ordering partial functions**

f1 is less or equal than f2 iff f1(x) = f2(x) for every x 

example:
* `f1(s) = s for all s`
* `f2(s) = s if s >= 0`
* `f3(s) = s if s = 0`
* `f4(s) = s if s <= 0`

then:
* f3 <= f2/f4 <= f1 --> visualized as hasse diagram
* f2 and f4 can't be compared

**UB - upper bound**

d is an upperbound if:
* d >= any other element

**LUB - least upper bound**

* d is an upperbound
* d <= than any upperbound 

doesn't always exist

**chain**

it's a subset of a POSET such that:
* any element is comparable with each other

the empty subset is always a chain

**CCPO - Chain Complete POset**

it's a POSET such that:
* any chain of it must have a LUB

the set of partial functions is a CCPO

**lettice**

it's a POSET such that:
* any pair of it must have a LUB and GLB

a finite lettice is always a complete lettice

**complete lettice**

it's a POSET such that:
* any subset of it must have a LUB and GLB

the set of partial functions is NOT a complete lettice

**bottom**

greatest lowerbound

**top**

lowest upperbound

**POSET properties**

* the height is the cardinality of the longest chain

**continuos function**

given:
* D, D' CCPO
* function f

then f is continuos if:
* f is monotone
* `LUB f d = f (LUB Y) for all Y = chains of D`

**kleene knaster tarski theorem / kleene iteration sequence**

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
    { s if sx = 1
    { undef otherwise

f" bt =
    { s if sx = 1 or sx = 2
    { s[y -> sy * 2][x -> 1] 
```

**pre fixpoint**

basically it's a point under the fixpoint
* f(x) <= x 

**post fixpoint**

it's the point above the fixpoint
* f(x) >= x

