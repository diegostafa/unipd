**URM - unlimited register machine**

* inifinite registers --> R1-R2-...
* finite instruction set
* terminates when the next instruction does not exist or when you jump to an instruction which does not exist
* all registers except inputs are set to 0 at the start

**urm-computable**

a function is urm-computable if there exist an urm-program such that it terminates

**instructions**

arithmetic instructions
* Z(n) --> set Rn to 0
* S(n) --> increment Rn
* T(n,m) --> transfer Rn to Rm

control flow instruction
* J(n,m,t) --> jump to instruction T if Rn == Rm

**program termination**

* a downward arrow means it will terminate, the result must follow the arrow
* an upward arrow means it will diverge

**input and output**

input and output is done through special registers:
* P(i1,...,ik -> i)

where:
* i1,...,ik --> input
* i --> output

which corresponds to:
```
P[i1,...,ik]

becomes:

T(i1, 1)
...
T(ik, k)
Z(k+1)
...
Z(l(P))
P
T(1, i)


// first part puts input in registers
// last part puts output in the output register
```

**computability with different domanins**

requirements:
* D is countable
* a is the function encoding D
* a^-1 is the reverse that decodes D

example:
```
a : Z -> N
a^-1 : N -> Z

a(z) =
    { 2z if z >= 0
    { -2z +1 otherwise

a^-1(n) =
    { n/2 if n is even
    { -(n+1)/2 otherwise

f : Z -> Z
f(z) = |z|

is it computable?

f* : a ° f ° a^-1
f*(n) =
    { a(f(n/2)) if n is even --> == n
    { a(f(-(n+1)/2)) otherwise -> == n + 1

```