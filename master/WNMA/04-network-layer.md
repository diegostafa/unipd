## network layer

defines how the messages reach their destinations (routing)

## routing

routing consists of 2 parts:
* algorithm for calculating routing tables:
    * link state --> full routing tables, does not scale
    * distance vector -->
* algorithm for sharing the tables:
    * static/proactive --> routing tables are always up to date
    * dynamic/reactive --> routing tables are are created on the fly

the choice of the algoithms depends on the network infrastructure

## proactive routing

props:
* upon a network update, update the routing tables
* protocols differ in the propagations of updates
* fast routing
* slow in highly dynamic networks

protocols
* DSDV
    * uses local tables (distance vector)
    * every node periodically broadcasts its table
        * full dumps --> sends the full table
        * incremental updates --> sends the updated parts since the last dump
    * if you receives equal routes, pick the newer one
* OLSR
    * uses full tables (link state)
    * only special relays receive these tables (avoids flooding)
* CGSR
    * extended OLSR
    * divides the network in clusters and uses OLSR on each cluster

## reactive routing

props:
* slow --> route computation
* space efficient
* scales betters

protocols
* AODV
    * dynamic route discovery
    * routes expire after a certain time
    * link failures are checked periodically by pinging
        * increase collisions
* DSR
    * dynamc route discovery
    * appen the full table to RREQ

## dynamic route discovery

* broadcast RREQ, remember each node visisted, when you reach the destination you reverse the route you built
* to avoid loops every node has a sequence number
* to avoid flooding you give RREQ a TTL