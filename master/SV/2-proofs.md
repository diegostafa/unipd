**deterministic language**

a language is deterministic if for every statement S:
* if `<S, s> -> s'` and `<S, s> -> s"` then `s' = s"`

**decomposition lemma**

ip:
* `<S1;S2, s> =>k s"`
* `<S1, s> =>k1 s'`
* `<S2, s'> =>k2 s"`

th:
* `k = k1 + k2`

**semantic proof by induction**

given:
* `<syntax, s> =>k s'`

to prove with induction:
* base case --> assume k=0, prove the thesis
* inductive case --> assume hypothesis holds for k+1, prove thesis (usually with decomposition lemma)

**repeat until**

prove that:
* `repeat S until b = S; if b skip else repeat S until b`
* `S(repeat s until b) = cond(b, id, S(repeat S until b)) ° S(S)`
* `S(repeat s until b) = F ° g`
* ` = FIX F`

to do this we need to prove that F ° g

**for loop**

there is no denotational semantic for the for loop, meaning we can't have a recursive definition of the for loop without introducing the while construct

```
while x<= a do S; x := x+1
```

**prove equivalence of programs**

prove:
* repeat S until b = S; while !b do S

thus:
* F1 = \g.cond(p, id, g)°g0
* F2 = \g.cond(p, id, g°g0)
* FIX F1 = FIX F2
* FIX F1 <= FIX F2
* FIX F2 <= FIX F1

hints:
    - go with fix point induction lemma
    - use kleene iteration

**fix point induction lemma**

f(x) <= x then FIX f <= d

**operation and denotation equivalence**

prove that:
* `~S[S] == <S>`

where:
* ``