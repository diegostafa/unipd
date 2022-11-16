**C class - computable function class**

it's the class of computable functions, this class is closed under these basic operations:
* functional composition
* primitive recursion
* unbounded minimalisation

which means that applying any of those will get another computable function

**basic functions**

given the building blocks:
* zero constant --> computed by Z(1)
* successor --> computed by S(1)
* projection --> computed by T(i, 1)

building functions with basic functions and operations will produce a new computable function

**generalized function composition**

given:
* `f` --> function of k arguments
* `g1...gk` --> k functions of n arguments

the composed function is:
```
h(x) =
    { f(g1(x)...gk(x)) if every g and f terminates
    { undef otherwise
```

given programs P, Q we can compose them as:
* R = P + Q

where:
* P is unchanged
* absolute references to registers in Q are shifted by l(P)

**primitive recursion**

given:
* `f(x)` --> function of k arguments
* `g(x)` --> function of k+2 arguments
* `h(x, y)` --> function of k+1 arguments

we define:
```
h(x, y) =
    h(x, 0) = f(x)
    h(x, y) = g(x, y-1, h(x, y-1))
``` 
    
    
**function definition by case**

in order to traduce definitions by case:
```
f(x) =
    f1(x) if Q1
    f1(x) if Q2
    f1(x) if Q3

becomes

f(x) = f1*Xq1 + f2Xq2 ...

where Xqi=1 if qi is true, 0 otherwise
```

only works if all functions are defined


**decidibility algebra**

* Xq1 = q1
* X(q1 and q2) = Xq1 * Xq2 
* X(q1 or q2) = max(Xq1, Xq2)


**bounded miniminization**