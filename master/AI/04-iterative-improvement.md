## iterative improvement algorithms

props:
* we just want to reach the goal, the path is irrelevant
* the state space is a set of all possible configurations
* the algorithm tries to find the best configuration that satisfies the constraints

types:
* offline search --> exploration is sufficient to reach a goal
* online search
    * interaction is necessary to reach a goal
    * not optimal/complete --> dead ends
    * states must have successors and predecessors
    * exploration problems
    * search can be paused/resumed
    * competitive ration --> path cost / path cost with information

## hill climbing search

at each iteration, the current state is replaced by the best neighbor

variations:
* hill climbing + limited lateral moves
* random-restart hill climbing --> restart after stalling
* stochastic hill climbing --> stochastic choice of the next state

proof - random-restart hill climbing finds the solution 1/p restarts:
* Xi is the independent binary random variable of success for the i-nth run
* P(Xi = 1) = p
* P(Xi = 0) = 1 - p
* then probability finding the solution at the k-th run is: P(X=0)^k-1 * P(X=1)
* then the expected value is: E(X) = +++ k(1-p)^k-1 * p

## simulated annealing

hill climbing variant which allows for some bad moves but each time decrease the number and frequency

## local beam

algo
* generate K random states
* generate their successors
* pick the best K successors (or)
* repeat until the goal is met

props
* different from running K parallel searches --> generated successors are visible to everyone
* picking always the best lead to same states --> biased stochastic choice

## genetic algorithm

* each state is encoded as a string
* a fitness function gives the state score
* the goal is to find the best state
* lack of initial diversity leads to suboptimal solutions

algo
* sort states by fitness function
* take the the first half (best)
* use a crossover function to generate new states form the best
* use a mutation function with low probability
* repeat until a goal is close or found


## gradient descent

* start from a random vector and move opposite to the gradient direction
* continuous envs

## depth first online search

DFS with backtracking to allow resuming from previous states

## random search

try all states randomly
* only for discrete environments
* slow

## LRTA* - learning real time A*

* choose the successor with the lowest estimated cost.
* update the current node estimate.
* repeat until reaching the goal node.
* optimistic --> unvisited states are assumed to be close to the goal to favor exploration