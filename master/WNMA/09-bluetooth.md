## bluetooth

props:
* layered protocol (core protocol + extra)
* cable replacement
* defines a piconet
* has error correction

piconet
* basic unit of a bt network
* nodes follow the master slave architecture
* one master per piconet
* masters can have up to 7 slaves
* master slave are ptp connections

scatternet
* multiple connected piconets

## msater actions

inquiry scan
* the master query for nodes presence

page scan
* the master ask nodes to connect

## addressing

* BD ADDR --> device MAC address
* AM ADDR --> active nodes, 0-7
* PM ADDR --> idle nodes, 0-255

## MAC layer

polling with variable size slots

## zigbee

* protocol used for small low power devices (sensors)
* low freqs
* slower
* ad hoc networks

nodes can be
* coordinator --> unique in the network
* router --> relay, dynamic routing
* devices --> user device