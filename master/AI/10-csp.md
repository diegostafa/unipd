## csp - constraint satisfaction problems

search problem where you want to assign values to a set of variables under some constraint:
* initial state --> V = {}
* successor function --> give a value to a variable in V
* goal test --> V is completely assigned and satisfies the constraints

props:
* the state is now a data structure and not a monolithic value
* they allow to formally describe a problem by using variables and constraints
* every solution on a N variables problem is at depth N
* the path is irrelevant

variations
* binary CSP --> every constraint is related to max 2 vars

solution search
* backtracking search
* local search


## backtracking search

```
backtrack(constraints, vars)
    if vars are assigned --> return vars
    else
        foreach freevar and value
            if constraint-check && forward-check is ok
                return backtrack(csp, vars + {var:val})
        return fail
```

## backtracking improvements

which free variable to pick
* most constrained var --> can pick less values
* least constrained var --> removing this early will reduce values later on

detect failures before the recursive call
* forward checking --> when assigning a value, keep track of the remaining legal values for other variables
* constraint checking --> check the constraints before doing the recursion

optimizations on the problem structure
* check constraints with graphs algorithms

## local search

props:
* the performance is defined by R = #constraints / #vars

algo
* initialize with random values
* sort by h(n) --> min conflict variable
* reassign the first