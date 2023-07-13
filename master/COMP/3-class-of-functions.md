## a-class - rich class

set of functions containing at least:
* basic functions
    * zero constant
    * successor
    * projection
* basic operations
    * generalized composition
    * primitive recursion
    * unbounded minimalisation

properties:
* intersection of a-classes are a-classes

example:
* F-class (all functions) is a rich class

## r-class - partial recursive class

least rich class, contains:
* basic functions
* basic operations

## c-class - computable class

set of functions computed by an URM machine

## c-class is equivalent to r-class

equivalence of basic functions:
* zero constant --> computed by Z(1)
* successor --> computed by S(1)
* projection --> computed by T(i, 1)

equivalence of basic operations:
* composition --> program concatenation
* primitive recursion --> for loop
* unbounded minalisation --> while loop

note: composition and primitive recursion are closed under totality

## r-class is equivalent to c-class

partial recursive functions are equivalent ro urm because we can encode registers

## pr-class - primitive recursive class

* basically it's r-class without unbound minimalisation
* it's strictly less than the c-class (ackermann function)
* it's strictly less than the class of all total computable functions