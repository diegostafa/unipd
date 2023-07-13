## ex 1

```
given a fixed function f and the set Bf which compute f, is Bf saturated?

Bf = {x : fx = f}

(first case) f is not computable
    Bf is the trivial empty set
    Bf is recursive

(second case) f is computable
    if f is finite
        let g be a total extension of f
        g is not in Bf
        f is in Bf
        by rice shapiro it is not re
    if f is infinite


then analyze the complement
```

better use rice/rice shapiro than reduction

## ex 2

```
define the pr-class
show that
    max2(y) = max(2, y) is in pr

two ways
    rebuild the max function with primitive recursion
        build sum
        build predecessor
        build difference
        build max
        build max2
    define max2 directly
        in function of max1
```

## ex 3

* W is the domain of the computed function
* E is the codomain

```
classify the recursiveness of:
    A = {x | Wx minus Ex is infinite}

solution:
1. the set is saturated
2. write the saturated set in the standard form
    * A = { x | ev(x) in ~A}
3. ~A = { f | dom(f) - cod(f) infinite}
4. notice that the constant 1 is in ~A
5. notice that any subfuntion of it is finite
6. by rice shapiro it is not RE and no RE
7. the complement
```

## ex 4

```
1. give the definition of reduction
2. show that if a<=b and b is recursive then a is recursive
3. if A<=B then B<=A ??

solution:
1.
- given A, B, we say A<=B if there is a total computable function f such that:
- for each x, x in A iff f(x) in b

2.
- let f be the reduction function
- b is recursive --> Xb is computable
- then Xa = f(Xb(x)) which is computable
- since Xa is computable A is recursive

3.
- no
- counterexample -->
```

## ex 5

```
1.
- is there a monotone non computable function?

1.
- by diagoanlization
- fnc(x) =
    | ev(x) + 1 if ev(x) terminate
    | 0 otherwise
- let g(x) = +++ f(x) up to x
- g(x) is monotone
- g(x) is not computable because it is different fomr c(x) for any x

1. alternative
- g(x) =
```

## ex 6

```
1.
- given a countable set of cuntion
- define a function in which the domain is different from any of thpse functions

1. by diagonalization

total non computable function

t --> terminate
u --> undefined
s --> either t or u
domain of f --> values in which f terminates

    0   1   2   ...
f0  s   s   s
f1  s   s   s
f2  s   s   s

- take the diagoanl
- f(x) =
    | 0 if s is undefined
    | undef otherwise

- then it is different from any of them
```

---

## ex 1

```
1. definition of reducibility
2. prove that if A<=B and A is not recursive, then B is not recursive
3. prove that if A is recursive, then A <= {1}

1.
- given 2 set A, B
- A <= B means that there exist a total computable function f(x), such that for any x, if x in A then f(x) in b

2.
- A is not recursive
- Ca is not decidable

3.
- A is recursive
- Ca is total and computable
- hence Ca is the reduction of 1

```

## ex 2

```
1.
- is there a non computable total function f such that {x | f(x) = f(x+1)} is infinite

1.
- do the diagonalization (different values) on every multiple of 3
- make the remaining = to 0
```

## ex 3

```
1.
- recursiveness of A = {x | fx is quasi total}
- qusi total
    - domain is infinite
    - !domain is finite
- not quasi total
    - domain is finite
    - !domain is infinite

1. (A)
- let A = { x | fx in ~A}
- let ~A = set of quasi total functions
- then A is saturated
- then the costant 1 is in ~A
    - since !dom = {} which is finite
- then each subfunction of 1 is not in ~A
- by rice shapiro
    - 1 is in ~A
    - any subfunction of 1 is not in ~A
    - then A is not RE

1. (complement of A)
- let !A = { x | fx not in ~A}
    - fx is are undefined in infinite points
- let ~A = set of quasi total functions
- then A is saturated
- !A contains all the finite functions
- 1 is not in !A
- empty(x) is in !A, is finitary and is a subfunction of 1
- !A is RE
```

## ex 4

```
1.
- recursivensess of B = { x | y>2x and y in Ex}
    - Ex are all the possible outputs

1.
- we show that B is RE
- let SCb be he characteristic function on B
- SCb = (mu(z,t,y).S(x,z,y,t) and y > 2x)
    - 1 if it is found
    - undef otherwise
- SCb is computable, therefore B is RE

1.
- we show that B is not recursive
- let K <= B with S : N -> N

```

## ex 5

```
1.
- show that there are 2 programs m, n such that
- fn = fn+1
- fm != fm+1

1.
- fn = fn+1
- let S(x) = x + 1
- S(x) is total and computable
- by snd recursion theorem, there is a program n st
    - fn = f(S(n)) = f(n+1)

- fm != fm+1
- by contraddiciton
- if it were true
```

## ex 6

```
1.
- rec of A = { x | fx(x) = x^2}
- rec of B = { x | fx(y) = y^2}
- are they saturated?

1. rec A
- SCa(x) =
    - 1(fx(x) - x^2)
    - undef otherwsie
-
```

---

## ex 1

```
1.
- recursiveness of A = { x | Wx in Ex} // the domain is a subset of the codomain
- recursivenss of !A

1.
- ~A = { f | dom(f) in cod(f)}
- A = { x | fx in ~A }

check non RE with rice shapiro
- let 1 be the constant function
- 1 is not in A
- let () be the empty function
- () <= 1
- () is in A
- by rice shapiro A is not RE

2.
- ~A = { f | dom(f) in cod(f)}
- A = { x | fx NOT in ~A } // domain is not a subset of the codomain

- let 1 be the constant function
- 1 is in !A
- () is not in !A
- therefore !A is not RE
```

## ex 2

```
1.
- recursiveness of A = { x | fx is injective}
- recursiveness of !A

1.
- A is not RE

1.
- !A is RE
    - show that the charcateristic function is computable and semidecidable
- !A is not recursive
    - show that it can be reduced to the halting problem

not recursive:
- reduction from the halting to !A
- let g(x, y) =
    - 1 if x in K
    - undef otherwise
- by Smn there exist S total and comptable
- f_sx(y) = g(x, y)
- show that f_sx is the reduction function:
    - x in k --> f_sx(y) = 1 for any y = costant

```

## ex 3

```
1.
- is there a total non computable function f s.t.
- g(x) = +++ f(x) computable
```

## ex 3

```
1.
- is there a total non computable function f s.t.
- g(x) = *** f(x) computable
```

## ex 4

```
1.
- define the PR set
- given a PR definition fo f(x, y) = x*2^y

1.
- 2 = S(S(0))
- sum(x, 0) = 0
- sum(x, y+1) = 1 + sum(x, y)
- mul(x, 1) = x
- mult(x, y+1) = sum(x, mul(x, y))
- pow(x, 0) = 1
- pow(x, y+1) = mul(x, pow(x, y))
- f(x, y) = mul(pow(2, y), x)
```

## ex 5

```
1.
- state the smn theorem
- prove that there exist f(x, y) s.t. dom(f) = x*y for any x, y

1.
- given m, n >= 1
- given f(x, y) with x in N^m and y in N^n
- given the proram e that compute f
- is it possible to define a function by fixing x to f


- let h(x, y, z) =
    - 0 if x*y > z
    - undef otherwise
- h(x, y, z) = minimize(sg(x*y - z))
- h is computable
- by smn theorem sxy(z) = h(x,y,z)
```

## ex 6

```
1.
- state the snd recursion theorem
- show that there is a program x such that fx(y) = x-y

1.
- for all total computable functions f there exist a program e such that: fe(x) = f_f(e)

- let f(x, y) = x - y
- f is total and computable
- by smn theorem f(x, y) = fx(y)
- by snd recursion theorem fe = f_fx(e)
```

## ex 7

```
1.
- n is random if for all programs p that produce n: l(p) >= n
- R = { n | n is random} is not recursive

1.
- assume R is recursive
- let SCr =
    1 if n is random
    0 otherwise
- let g(n, x)
    = least random number > n
    = min z.(z in R and z > n)
    = min z.(SCr(z) - 1)
- by smn there is gn(x) = g(n, x)
- by snd recursion theorem on gn(x) there is a program e s.t.
    - fe = f_gn(e)
- the e generates a random number greater then e
- contraddiction

-

```