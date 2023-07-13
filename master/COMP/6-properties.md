## property

is a predicate which can be used to induce a set of programs, a property can be:
* decidable --> induces a recursive set
    ```
    P(x) =
        | 1 if x is in the set
        | 0 otherwise
    ```
* semidecidable --> induces a recursively enumerable set
    ```
    P(x) =
        | 1 if x is in the set
        | undef otherwise
    ```
* non decidable --> induces a non recursive
    ```
    P(x) = undef
    ```

note:
* given q property P, then the induced set of programs is: `{ x : P(x)}`
* every decidable property can be expressed by a primitive recursive function
* recursive set are closed under and/or/not

## reduction

* given 2 set A, b
* A <= B (A reduces to B)
* if there is a total computable function f
* x in A iff f(x) in B

consequences:
* B recursive/RE --> A recursive/RE
* B not recursive --> A not recursive
* A not RE --> B not RE

## behavioral property

a property P is behavioral if given 2 programs a, b:
* if P(a) is true and f(a) = f(b) then P(b) is true

## theorems

* A is recursive iff A and !A are re
* A is RE iff A = dom(f) with f computable
* a total computable function applied on a re set gives an re set
* **structure theorem** --> a property is semidecidable iff it can be expressed as a decidable property with an existential quantifier
* **projection theorem** --> semidecidable properties are closed under the existential quantifier
* **reducibility theorem**
    * given a reduction A<=B:


## finitary property

given a set of computable functions A, for each f:
* f in A iff there is a finite subfunction g of f in A

basically every function in A has a finite subfunction in A

## rice theorem

ip:
* A is saturated
* A is not empty
* A is not N

th:
* A is not recursive

## rice shapiro theorem

given:
* ~A a set of computable functions
* `A = { x | fx in ~A }

then:
* if A is re then there must be a finitary subfunction in ~A

use cases, prove that a set is not re (2 ways):
* f is not in ~A, but a subfunction of it in ~A
* f is in ~A, but no subfunctions of it are in ~A
