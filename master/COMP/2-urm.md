## URM - unlimited register machine

* infinite registers --> R1-R2-...
* finite instruction set
* termination happens when the next instruction does not exist
* all registers except inputs are set to 0 at the start

## instructions

* Z(n) --> set Rn to 0
* S(n) --> increment Rn
* T(n,m) --> transfer Rn to Rm
* J(n,m,t) --> jump to instruction T if Rn == Rm

## notation

* downward arrow means termination with a result
* upward arrow means non termination
* p(P) is the max index used in program P
* l(P) is the number of instructions in program P
* P is in standard form if it terminates at l(P)+1
* P[i1...ik -> i] --> syntactic sugar
    * input is given in registers i1..ik
    * output is stored in register i
* concatenation of programs is done by shifting the registers of the second program by l(P)

## enumeration of instructions

given the set of instructions:
* `F = {Z(m), S(n), T(m, n), J(m,n,t) for each m,n,t in N}`

it is possible to enumerate in this way (modulo trick):
* `Z(n) --> 4(n-1)`
* `S(n) --> 4(n-1) + 1`
* `T(m,n) --> 4(E(m-1,n-1)) + 2`
* `J(m,n,t) --> 4(E(m-1,n-1, t-1)) + 3`

example:
* `Z(19) --> 4*(19-1) --> 72`
* `T(2,9) --> 4*(E(1, 8)) - 2 --> 4*((2 * 17) - 1) - 2 --> 4*33 - 2 --> 130`

## enumeration of programs

the enumeration of a program is the encoding of the sequence of the encoding of its instructions
* `E(P) = E(E(I1), E(I2), ...)` where I is an URM instruction

## enumeration of registers

given the list of used URM register, it is possible to encode them with:
* `*** P^Ri` --> the product of all primes to the content of the respective register

example:
* `E(0,0,12,3,0,3) --> 1^0 * 2^0 * 3^12 * 5^3 * 7^0 * 11^3`

## URM variants

to prove equivalence of URM variants:
* find every occurrence of the newly introduced instruction
* prove that it is possible to emulate it with the other URM model