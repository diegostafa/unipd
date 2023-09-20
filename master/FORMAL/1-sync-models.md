## sync model


## sync reactive components

formal definition:
* M = {i, o, s, init, react}
    * i --> in vars
    * o --> out vars
    * s --> state vars
    * init --> initial state values
    * react --> exec function over i, o, s

props
* round/clock based
* each component is executed sequentially in a round

component
* input variables
    * public
    * not initialized (they change over time)
    * read only
    * can be shared in parallel components
* output variables
    * public
    * not initialized (they change over time)
    * can't be read before being assigned (they are undefined)
    * can't be shared in parallel components
* state variable
    * internal to the component
    * always declared and initialized
* types --> bool, int, real, enums
* local variables --> variables that do not persist

event variables:
* syntax --> event(type) x
* event can either be present/absent
* ex. event(bool) x --> if event is present x has a bool value

event operators:
* x? --> test if x is present
* x!value --> if x is absent, assign

model hypothesis
* components executes in no time
* when multiple component are composed, they execute sequentially, but still in no time

composition
* the set of out vars is the union of all out vars
* the set of in vars is the union of all in vars minus the out vars
* the set of state vars is the union of state vars
* if composition is in series --> the execution is the chaining of both executions if the components are in series
* if composition is parallel --> the execution a schedule of the tasks only if the tasks are compatible

## task

task
* atomic block of code
* specifies the variables it reads and write
* task can have a precedence

task schedule
* total ordering of the tasks consistent with the edges

task graph, requirements:
* the graph is acyclisc --> implies at least 1 schedule
* each out var is in the write set of only one task
* out vars and local vars are written before read
* write conflicting tasks must be resolved by fixing an order

(theorem) 2 components are compatible if
* they have no common out var
* the combined await dependencies are acyclic

## paralll composition

