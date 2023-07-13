## randomized algorithm

algorithm which at some point makes a random decision

types:
* las vegas algorithm --> always correct
* monte carlo --> might fail on some input
    * one sided --> can fail in either yes or no
    * two sided --> can fail in both decisions

in randomized algorithms the complexity might be a random variable, study the complexity means studying the expectation of the variable

## complexity

WHP, a randomized algorithm A has complexity T(n) = O(f(n)) if:
* given c, d >= 0
* P(A >= c*f(n)) <= 1/n^d

it says that the probability of the algorithm to be much slower than f(n) must be really low (exponential bound)

## correctness

WHP, a randomized algorithm A is correct if:
* given d >= 0
* P(A wrong) <= 1/n^d

it says that the probability of the algorithm being wrong must be really low

## markov lemma

ip:
* let T be a positive random variable
* let T <= b for some b
* let a <= b for some a

th:
* E(T) >= a*P(T >= a)
* E(T) <= a + (b - a)*P(T >= a)

## (monte carlo) karger min cut

find the cut with less crossing edges

```
fullContraction(G)
    for |V| - 2
        (a, b) = random edge
        contract(G, a, b)

    return |E|

randKarger(G, k)
    min = inf
    for i to k
        min = min(min, fullContraction(G))
    return min

```

after a contraction:
* V decrements by 1
* E decrements by the multiplicity of the edge in consideration
* for each cut in the contracted graph there is a same cardinality cut in the original graph

analysis:
* INCOMPLETE

## expectation

* given X = X1,.., Xn random vars where P(Xi = 1) = k
* E(X) = +++ E(Xi) = +++ P(Xi = 1) = +++ k = n*k

## chernoff bounds

given X = X1, X2, ..., Xn binary random vars where:
* P(Xi = 1) = pi
* E(X) = pi*n = m

then, given d > 0:
* P(X > m(1+d)) < (e^(1+d) / (1+d)^(1+d) )^m

variants
* P(X < m(1-d)) < e^((md^2)/2)
* P(X > m(1+d)) < e^((md^2)/2)

## RQS -  randomized quicksort

algo
* pick a pivot
* split the array in 2 subarrays
    * elements <= pivot
    * elements => pivot
* RQS on the the 3 subarrays and concat them