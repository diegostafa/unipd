**agent**

function that maps perceptions to actions
* Agent : P* -> A (kleene star)

phisically an agent is:
* architecture --> robot, computer, phone...
* program --> the internal algorithm

**rational agent**

agent that based on its experience chooses the action that maximize the measure of performance

types:
* reflex agent
* reflex agent with state
* goal based agent
* utility based agent

**reflex agent**

algorithm:
1. take the last perception
3. return the associated action

**reflex agent with state**

algorithm:
1. take the last perception
2. update the state
3. return the associated action

**goal based agent**

algorithm:
1. take the last perception
2. update the state
3. for each action simulate the impact on the goal
3. return the best action for that goal 


**utility based agent**

given the utility function:
* U : State -> R 

algorithm:
1. take the last perception
2. update the internal state
3. for each action simulate and calculate how good is it based on the utlity function
4. return the action that maximize U
