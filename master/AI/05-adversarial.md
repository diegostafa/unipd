## game

search problem in which 2 or more agents compete or work together
* initial state --> initial game state
* successors --> all the possible successor game states
* goal test --> states in which the game is over (terminal states)
* utility --> given a terminal state returns the associated value

games can be:
* complete --> all possible moves can be computed
* deterministic --> the result solely depends on the played moves
* partial --> not complete, contains unknown elements
* non deterministic --> not deterministic, contains random elements

## minimax

returns the best move under the hypothesis that the opponent choose the best move too

```
minimax(s) =
    | utility(s) if s terminal
    | max minimax(expand(s)) if MAX turn
    | min minimax(expand(s)) if MIN turn
```

props:
* complete
* optimal
* DFS complexity --> exponential to the number of moves --> bad

## alpha-beta pruning

* keep track of the best values of min and max, if a > b || b < a--> prune
* time --> O(b^m/2) --> with perfect ordering

## resource limit problem

minimax is too expensive to run, the solutions is:
* cutoff --> replaces the terminal test
* evaluation function --> replaces the utility function
    * optimality --> monotonic over the utility function
    * optimality (nondeterminism) --> positive linear transformation of the utility function

## quiescence search

* applies the evaluation function only on quiet states to avoid the horizon effect
* horizon effect --> the algorithm tries to avoid an inevitable bad move with useless moves

## nondeterministic games

* states have an expected minimax value
* the tree gets more nodes (chance nodes)
* the probability of reaching a node decrease at each level --> a-b pruning is useless

```
minimax(s) =
    | utility(s) if s terminal
    | max minimax(expand(s)) if MAX turn
    | min minimax(expand(s)) if MIN turn
    | avg minimax(expand(s)) if CHANCE turn
```

## partial games

* compute the minimax for every possible configuration
* pick the path with the highest probability
* the choice is usually different from games with complete information