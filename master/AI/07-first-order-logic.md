## quantifiers

* universal instantiation
    * substitute the quantified term with any other term in the KB
    * can be done infinite time
    * the new KB is equivalent
* existential instantiation
    * substitute the quantified term with a new term
    * can be done once
    * the new KB is not equivalent

## reduction to propositional logic

* quantifier instantiation until entailment is achieved is semidecidable
* unification is used to instantiate the right term

## unification

computes a substitution (the most general unifier) that unifies 2 expressions

algorithm:
* if a != b --> return err
* if a == b --> return nothing
* if they are expressions --> unify the arguments and the operator
* if they are list -->unify the heads and the tails
* if a they are variables
    * if FI contains the variable --> return FI
    * if a substitution exists --> add it to FI
    * if they occur in each other --> return failure


## generalized modus ponens

```
p'1...pk, (p1...pk -> q)
------------------------
        FI(q)

note: pi, pi' are the same under FI
```

soundness - show that it derive FI(q):
* FI(pi) = FI(p'i) by unification
* (p1...pn => q) becomes (FI(p1)...FI(pn) => FI(q))
* p'1...p'n becomes FI(p'1)...FI(p'n)
* with the first hypothesis follows modus ponens

## generalized resolution

simply put, if 2 expression in CNF have a common opposite element, it can be removed

## generalized horn clause

* can not express all fol
* but it's decidable because it does not allow functions

## generalized CNF

conversion:
* simplify implication and double implication
* move the ! inside the quantifiers
* every quantifier should have different variable names
* replace existential quantification with a function (skolemize)
    * Ex Animal(x) becomes Animal(F(x))
* remove universal quantification
* distribute the or (multiplication)

## generalized forward chaining

props:
* used deductive databases, datalog
* sound and complete for single literal horn clause
* time complexity --> polynomial (improved by indexing the KB)
* undecidable

## generalized backward chaining

props:
* used in logic programming, prolog
* infinite loops --> check if goal is in the current stack
* repeated subgoals --> memoization
* linear space complexity

prolog:
* backward chaining + horn clauses
* negation as a failure

## resolution algorithm

strategies:
* subsumption --> remove sentences that are more specific than others
* unit preference --> every resolution must involve a single literal
* set of support --> every resolution must involve a clause in a set of support
* input resolution --> every resolution must involve an input sentence


proof - completeness:
* any KB can be transformed in CNF
* assume KB is unsatisfiable
* then there is a subset which is unsatisfiable
* then a contradiction can be found