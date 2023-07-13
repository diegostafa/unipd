## function defined by case

function defined as:
```
f(x) =
    | f1(x) if Q1
    | f2(x) if Q2
    | ...
```

if every case is a total function, then it can be seen as:
* `f(x) = f1*Xq1 + f2Xq2 ...` --> computable because it's a composition of computable functions

where:
* `Xqi=1` if qi is true, 0 otherwise

## composition

function defined as:
```
h(x) =
    | f(g1(x)...gk(x)) if every g and f terminates
    | undef otherwise
```

## primitive recursion

function defined as:
```
h(x, y) =
    | h(x, 0) = f(x)
    | h(x, y) = g(x, y-1, h(x, y-1))
```

note: primitive recursion can only recur on the previous element

## bounded operation

basically an accumulator, function defined as:
```
h(x, z) =
    | h(x, 0) = 0
    | h(x, y+1) = h(x, y) + f(x, y)
```
the bounded product is equivalent

## bounded quantification

given a decidable predicate Q(x, y) defined in a, then the properties
* for each z<=y Q holds, is computable
* there exist z<=y such that Q holds, is computable

because since you can check Q in a specific value, you can check Q in a finite set of values too

## bounded minimalisation

function defined as:
```
h(x, y) =
    | z if z<=y and f(x, z) = 0
    | y otherwise
```

compact notation:
* f must be total
* h(x, y) = min z<=y s.t f(x, z) = 0
* it's computable because it can be written as primitive recursion

## unbounded minimalisation

function defined as:
```
h(x, y) =
    | y if there exists y :  min y . f(x, y) = 0
    | undef if it diverges or diverges in some point
```

it's bounded minimalisation, without the constrain of iterating up to y

## trivial functions

* rm(x, y) --> remainder of y/x
* div(x, y) --> 1 if x divides y --> remained = 0
* D(x) --> number of divisor of x --> it's written as bounded operation
* Pr(x) --> 1 if x is prime --> not(|D(x)-2|)
* Px --> xth prime number --> it's written as bounded minimalisation
* (x)n --> exponent of the nth prime factor of x, example:
    * `20 = 2^2*3^0*5^1`
    * (20)1 = 2 --> corresponds to 2^2
    * (20)2 = 0 --> corresponds to 3^0
    * (20)3 = 1 --> corresponds to 5^1
    * (20)n = 0 for each n>=4


## ackermann function

```
psi(x, y) =
    | psi(0, y) = y + 1
    | psi(x+1, 0) = psi(x, 1)
    | psi(x+1, y+1) = psi(x, psi(x+1, y))
```

proof of totality:
* assume that for each (x',y') <= (x, y) psi terminates
* in every case the recursive function is called with smaller arguments

proof of computability:
* basically you show that it is possible to make an algorithm that search every possible output of psi

proof that it is not contained in pr-class:
* you show that psi grows too fast to be computed by for loops

## Smn theorem

ip:
* given f(x, y) computed by a program e
* we build fx(y) by fixing the x parameter (computable)
* for any x, fx(y) is computed by a program d
    * basically d is obtained from e by fixing x
* since d depends on e and the value of x, we can define:
    * S(e, x) = d --> total
* then fx(y) = S(e, x)

th:
* S(e, x) is computable

usage:
*

formal definition:
```
given m,n >= 1
there is a total computable function
Smn : N^m+1 -> N

s.t.
- for any e in N
- for any x in N^m
- for anu y in N^n
- f_e^m+n(x, y) = f_Smn(e, x)^n(y)

```

## universal function

it's the universal function for functions of arity K, it takes the encoded program and the relative input, and produce the output of the program over the input

ip:
* U(e, x) = Pe(x)

th:
* U is computable

proof:
* define Ck (memory configuration) which returns the configuration of a program after k steps of execution
* define Jk (program counter) which returns the number of instructions left after k steps of execution
* U can be written as:
    * Ck(e, x, i) until Jk(e, x, i) == 0
* prove that Ck and Jk are computable

```
Ck(e, x, t) =
    | the configuration after t steps of executions if it does not terminate
    | the final configuration otherwise

Jk(e, x, t) =
    | the number of instructions left after t steps
    | 0 otherwise
```
