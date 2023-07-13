## agent

made of
* architecture --> physical device
* program --> agent function

agent function
* f : P* -> A
* takes a list of perception and returns an action

## rational agent

the chosen action maximizes the expected utility, given the agent knowledge

## PEAS

defines the properties of an agent:
* performance measure --> learning metric
* environment --> where is it placed
* actuators --> how does it interact
* sensors --> how does it perceive

## environment type

the environment in which the agent acts can be:
* observable or non observable
* deterministic or stochastic --> states depends on previous states
* episodic or sequential --> actions have future effects
* static or dynamic --> the environment can change at runtime
* discrete or continuous
* single or multi agent

## environment representation

an agent can represent the environment in 3 ways:
* atomic --> each state is as is and can't be split
* factorized --> each state can be split in particular attributes
* structured --> basically OOP, states are entities and form relations with each others

## agent type

based on the algorithm used to the next action, an agent ca be:
* reflexive
    * simple map of perception to action
    * can loop in partial observable environments
* reflexive with state (aka model-based)
    * simple map of perception and state to action and new state
    * also has a model representation of the environment
* goal based
    * simulate the result of possible actions to achieve a goal
    * the agent now works for a goal
* utility based agent
    * simulate the result of possible actions to maximize the utility function
    * the agent works to reach a goal, but in the most efficient way possible

## problem solving agent

* specific type of goal based agent used when the space of state-action is too large
* it uses a searching algorithm to find the sequence of actions to reach the goal

## problem

defined as:
* initial state --> state
* successor function : action -> state
* goal test : state -> bool
* step cost : action -> cost

the formulation of a problem starts by specifying the space of possible states