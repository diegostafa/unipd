## knowledge based agent

goal based agent with:
* knowledge base --> set of sentences in formal language
* inference algorithm --> inference rules to prove sentencess

## model

example
* sentence = A and B
* model = { A:true, B:false }
* then when we entail we get if the sentence is true or not

## propositional entailment

checks if a sentence implies another sentence
* a |= b

## inference

checks if KB derives q, can be:
* sound --> contradictions can't be derived
* complete --> only facts can be derived

inference algorithms, 2 types:
* model checking
    * enumeration
    * heuristic search
* inference rules
    * forward chaining
    * backward chaining
    * resolution

## inference rules

modus ponens:
* a1 and a2 and ... -> b
* if all the premises are true, b is true

resolution:
* (a or b) and !a reduces to b

rules can be seen as successors functions
* given the initial sentence (initial node)
* apply all the rules to generate the frontier
* do it until you reach a solution

## horn form

```
horn :=
    | symbol
    | a1 and a2 and ... -> b
    | horn and horn
```

props:
* modus ponens can be applied right away
* can't express every logical proposition
* negated sentences need extra work
* reduces inference complexity

## CNF - conjunctive normal form

```
cnf :=
    | symbol
    | not symbol
    | a or !b
    | cnf and cnf

example
    (a V b V c) and (...)
```
props:
* can express every propositional logic
* resolution rule can be applied right away

CNF conversion:
* implication --> !a or b
* use de morgan
* distribute the or(a and b) or c --> (a or c) and (b or c)


## inference by enumeration

* enumerate all the possible models (symbol assignments) for the kb and the query, if kb->q in at least one model, it holds
* O(2^n) for n symbols

```
entails(KB, q)
    unassigned = extract-symbols(KB, a)
    checkAll(KB, q, unassigned, [])

checkAll(KB, q, unassigned, model)
    if unassigned = []
        if model(KB) --> return model(q)
        else --> return true
    else
        head, tail = head(unassigned), tail(unassigned)

        return
            checkAll(KB, q, tail, model + (head = tt)) &&
            checkAll(KB, q, tail, model + (head = ff))
```


## forward-chaining

from the kb, apply modus ponens to infer conclusions, add the inferred symbols to the kb and repeat

props:
* it derives every sentence entailed by the KB
* data driven --> because we use the avaible the data
* can do useless work for the goal (basicaly BFS)
* can handle multiple query
* infinite loops in circular dependencies
* less efficient in solving a single query
* time complexity --> linear over the KBj
* space complexity --> exponential over the KB
* NP-complete without horn clause

```
forward-chaining(KB, q)
    while KB.facts not empty
        fact = KB.facts.popFirst
        if fact == q
            return true
        else
            foreach clause in KB
                if premise contains a fact
                    remove it
                if premise is emty
                    add the conclusion  KB.facts
    return false
```

proof - completeness:
* by assumption, every atom implied by the KB is derived
* then the final state is a model M
* then every clause is true in M
    * assume it isn't
    * then there is a -> b which is false
    * then a = true, b = false
    * impossible because the algorithm stopped
* then M is a model of KB
* then if q is actually implied by the KB, M must entail it

## backward-chaining

props:
* avoid loops --> check if a the goal is already in the stack
* save useless work --> use memoization
* space complexity --> linear (or less) over the KB

```
backward-chaining(KB, q)
    if KB.facts contains q
        return true
    else
        forall clause in KB where conclusion = q
            forall premise in clause
                res = true &&
                    backward-chaining(KB, premise)
            return res

        return false
```

## resolution algorithm

basically, add the negated query to the KB, if the KB becomes inconsistent, the q must be true

```
resolution(KB, q)
    let clauses <- CNF(KB and ~q)
    reductions = []

    while true
        forall clauses (c1, c2)
            reduction = resolve(c1, c2)

            if reduction is empty
                return true
            else
                reductions += reduction

        if reductions already in KB
            return false
        else
            KB += reductions
```

## resolution completeness (ground resolution theorem)

* if a set of sentence can't be satisfied in any model the resolution closure contains the empty clause
* RC(S) is the final set obtained by the algorithm after running it on the clauses S

proof:
* showing that if RC(S) doesn't contain the empty clause, S is satisfiable
* a model M can be built in the following way
    * enumerate all symbols in S
    * for all symbols
    * if RC(S) contains the negated symbol and the previous symbols are false assign it false
    * else assign it true
