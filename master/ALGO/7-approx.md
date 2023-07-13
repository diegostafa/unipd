## P/NP

* tractable problem --> there is an algorithm for it that runs in polynomial time
* P class --> set of problems solvable in polynomial time
* NP class --> set of problems which positive answer answer can be verified in polynomial time
* co NP class --> set of problems which negative answer can be verified in polynomial time
* reduction --> A < B (A reduces to B) if solving B would solve A
* polynomial reduction --> A <_P B if there is a polynomial algorithm able to map inputs of A to inputs of B
* NP hardness --> a problem is NP hard if any problem in NP can be reduced to it
* NP completeness --> a problem is NP hard and contained in NP
* cook levin theorem --> 3SAT is NP hard

NP hard problems:
* 3SAT --> prove a boolean formula is true on some values
* TSP --> minimum cycle which passes every vert only once
* hamiltonian cycle --> cycle which passes every vert only once
* max clique --> largest complete subgraph
* max independent set --> max set of verts with no edges between them
* min vertex cover --> min set of verts that are connected to each edge
* min set cover --> min set of subsets which covers all elements

## optimization problem

defined by:
* a problem: problem x solution
* a cost function: solution -> cost

the solution minimizes the cost function

## optimization problem approximation

instead of the best solution, pick a solution which:
* satisfies an approximation factor
* is computed in polynomial time

## approximation factor

approximation factor
* ro(n) = cost(S') / cost(S*) --> hopefully close to 1

where:
* S' --> approximate solution
* S* --> optimal solution

## approximated vertex cover

always take an edge and remove the all the endpoints from E

```
approxMinVertCovert(G)
    cover = {}

    while E != {}
        take an edge (a,b)
        cover += {a, b}
        filter E where a or b are present

    return covert
```


## approximated min set cover

always pick the set with most uncovered elements

```
approxMinSetCover(elements, universe)
    cover = {}

    while universe != {}
        choice = element in universe with most uncovered elements
        elements -= elements covered by choice
        universe -= choice
        cover += choice

    return cover
```

complexity:
* O(|elements| * |universe| * min(|elements|, |universe|))


## mst - approximated metric TSP (2 approx)

preorder the mst and append the root

```
preorder(G, v)
    print(v)
    forall children c of v
        preorder(c)

approxMetricTSP(G)
    mst, root = mst(G)
    return preorderVisit(mst) + {root}
```

## christofides - approximated metric TSP (3/2 approx)

```
christofidesTSP(G)
    oddV   = verts with odd degree
    pMatch = perfect matching of graph induced by oddV
    tsp    = prim(G) + M*

    if tsp not hamiltonian
        shortcut it

    return tsp
```
