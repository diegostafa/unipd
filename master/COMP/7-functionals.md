## functional - higher order function

total function where the domain and codomain are functions
* `F : ~F(N^k) -> ~F(N^h)` --> form k-arity functions to h-arity functions

## computable functional

a functional is comptuable if there exist a computable function such that:
* `F(f)(x) = C(s, x)` where F is the functional and C is a computable function and s is a subfunction of f


formally, a functional `F : f -> g` is recursive/computable if there exist a computable funtction C, such that:
* for each f and x `F(f)(x) = y` iff `C(sub, x) = y`  and `s<=f`

consequencese:
* given a recusive functional, if f is computable, then F(f) is computable

## extensional function

given 2 program e1, e2 such that
* `ev(e1) = ev(e2)` --> they evaluate the same function

then
* `ev(ev(e')) = ev(ev(e"))` -->


## myhill-sheperdson theorem

given a recursive functional, then there exist a total computable function h such that:
* for all programs e, F(fe) = h(e) and h is extensional

## first recursion theorem

every recursive functional has a computable least fixpoint
* fixpoint --> `F(fx) = fx`
* computable --> there exist a program e such that fx = ev(e)

## second recursion theorem

* given any total computable function f
* there exist a program e
* fe = f_f(e)