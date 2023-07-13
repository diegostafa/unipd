## uninformed search

the search algorithm only knows about the given problem formalization

BFS:
* expand the nodes in the queue until you reach the goal

uniform-cost BFS
* like bfs, but at every expansion the queue is sorted by the cost to reach a node
* loops can be avoided by checking that the total cost at each step is increasing
complexity

DFS
* pop the nodes in the stack until you reach the goal

limited DFS
* basically DFS, but you can check up to a limit
* not optimal

iterative deepening DFS
* basically limited DFS with an incremental limit
* no infinite loops
* better if the solution is at lower depths
* visits nodes multiple times

bidirectional search
* run BFS from start and from end until they meet
* you know the final goal
* you can expand nodes in both directions


## complexities

BFS
* space --> O(branching^solution_depth)
* time --> O(branching^solution_depth)

uniform cost BFS
* space --> like BFS
* time = space = O(branching^(1+C/e))
    * C --> optimal solution reach cost
    * e --> min cost for each action

DFS
* space --> O(branching*depth)
* time --> O(branching^depth)

limited DFS
* space --> O(branching*limit)
* time --> O(branching^limit)

iterative deepening DFS
* space --> O(branching*solution_depth)
* time --> O(branching^solution_depth)

bidirectional search
* space --> O(branching^solution_depth/2)
* time --> O(branching^solution_depth/2)