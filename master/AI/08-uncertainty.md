## terminology

prior probability
* given a random variable, it's the probability of it assuming a certain value

prior probability distribution
* given a random variable, it's the table of the probabilities of its values

prior joint probability distribution
* given multiple random variable, it's the table of the probabilities of their values happening together

marginal distribution
* distribution in which some variable are eliminated and the rows are summed out

posterior probability
* it's the prior probability of a variable after an event happened
* P(A|B) = P(A and B) / P(B)

posterior joint probability distribution
* given a joint distribution and an evidence, the posterior joint distribution is a new joint distribution updated on the evidence

product rule
* a 2-joint distribution can be written as a product of a conditional distribution and the prior distribution
* P(a, b) = P(a|b)*P(b)

bayes rule:
* reformulation of the product rule
* P(A, B) = P(B|A) * P(A)/P(B)

chain rule
* every joint distribution can be written as a product of conditional distributions
* P(X1,X2, ... XN) = ***P(Xi|X1, ... X_i-1)

independence
* P(A,B) = P(A)*P(B)

conditional independence
* P(a,b|c) = P(a|c)*P(b|c) --> you can decouple vars depending on the same event

marginalization
* given a distribution, marginalizing a variable means finding all the rows of that variables and summing the probabilities

## stochastic reasoning

logic agents might fail because of:
* partial information
* complexity in representing logic propositions

utility theory
* actions are governed by a utility function

decision theory
* utility theory + stochastic choice

rational agent:
an agent is rational iff it chooses the action that yields the highest expected utility, averaged over all the possible outcomes of
the action

## inference by enumeration

given a full joint distribution
* let Q be the query variables
* let E be the evidence variables
* let H be all the other variables
* then P(Q|E) = +++h P(Q|E, H)
    * sum out by enumerating all possible H combinations

complexity
* time = space = exponential over H

## CPT - conditional probability table

notation for representing for full joint distributions
* space complexity is exponential over the dependencies

```
A depends on B
A depends on C

CPT(A) =
    B C P(A|B,C)
    0 0 .95
    0 1 .93
    1 0 .29
    1 1 .001
```

## bayesian networks

directed acyclic graph for representing full joint tables decoupled by conditional independence:
* verts are variables
* edges are direct dependencies
* verts are associated with a CPT

given a query, the conditional probability distribution is:
* P(Q) = P(Q|parents(Q))

global semantics
* P(X1...Xn) = P(X1|parents(X1)) * ... * P(XN|parents(XN))

props
* CPT complexity grows linearly on the verts --> better full distributions

inference:
* exact inference
    * enumeration
    * variable elimination
* approximated inference --> stochastic sampling simulation
    * prior sampling
    * rejection sampling
    * mcsm

## variable elimination

instead of doing normal enumeration over the full joint distribution, apply marginalization before joining the tables, s that the resulting products are smaller

complexity:
* single edges --> O(n*d^k) --> linear on the networks size
* multi edges --> reduces to 3SAT --> NP hard

## approximated inference

* generate many samples
* each sample is a complete assignment of all variables
