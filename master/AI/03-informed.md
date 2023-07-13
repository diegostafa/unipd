## informed search

type of search algorithm that get external information/heuristics on the state/space problem

## best first search

given a desirability function f(n), after expanding a node you sort the queue on f(n) and pick the first

## admissible heuristic

the estimated cost to the goal is less than the real cost:
* h(n) <= c(n, goal)

## consistent heuristic

the estimated cost is less than the estimated cost of the next state + the actual cost to reach it
* h(n) <= c(n, m) + h(m)

proof - monotonicity:
* f(n) = c(n) + h(n)
* f(m) = c(m) + h(m) // by definition of f
* f(m) = c(n) + c(n, m) + h(m) // by expanding c(m)
* f(m) >= f(n) // by definition of consistent heuristic

props:
* consistency implies admissibility

## dominating heuristic

h1 dominates h2 if:
* h1(n) >= h2(n)

dominating heuristic are better because they are closer to the real cost

## heuristic generation

heuristic can be generated from the relaxed version of a problem
* the relaxed has less constraint, so you are sure to get lower values
* the values are obtained by running an uninformed search on the relaxed problem

## greedy search

basically BFS, but you sort the queue with by h(n)
props:
* f(n) = h(n) --> h(n) is the heuristic
* not complete --> can loop
* not optimal --> easy to prove
* space = time = DFS

## A* search

it's BFS but you sort the queue by f(n)

props:
* f(n) = g(n) +  h(n) --> c(start, n) + h(n, goal)
* optimality on trees --> h is admissible
* optimality on graphs --> h is consistent
* complete --> unless there are infinite nodes with f(n) <= f(G)
* time complexity --> O(h^depth) h is the heuristic error
* space complexity --> like bfs

proof - optimality on trees
* let G1 be the solution found
* assume G2 is optimal solution
* let B be the node which contains G2
* then f(G2) < f(G1) by assumption
* then f(B) <= f(G2) < f(G1) because B is closer
* but the algorithm would have picked B, contradiction

## A* optimality on graphs

admissibility does not work with graphs because a node could have multiple parents
```

     [A]
  5       5
[B]       [C]
  5  [D]  1
      5
     [G]

ABDG is not the optimal path
```

can be solved in 2 ways:
* algorithmic --> remember the paths and discard the most expensive one
* using consistent heuristics --> the frontier will always increase its cost

## IDA* - iterative deepening A*

like A*, but:
* introduce cutoff = min f(n) not in the queue
* it does not put nodes in the queue whose f(n) < cutoff
* at every iteration is starts from the beginning
* uses too little memory

## RBFS - recursive best first search

* run DFS but keep track of the f-value
* if a node has a bigger f(n) go back and change path
* on going back update the actual reach cost

props:
* optimal if consistent heuristic
* space complexity of DFS
* time complexity highly variable
* uses too little memory

## SMA* - simplified memory-bounded A*

same as A*, but:
* has a finite queue
* if the queue is full --> remove the worst node
* if multiple worsts --> remove the oldest one
* if worst == best --> discard it

props:
* complete only if the solution fits in memory
* not always optimal
