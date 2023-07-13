## wireless networks

technical aspects:
* network delay/RTT
* bit error rate
* packet error rate
* data rate
* traffic mode --> continuous/burst

divided in:
* fixed topology/infrastructure networks
    * cellular systems
    * wlan
    * satellite systems
    * bluetooth --> cable replacement
* dynamic topology - ad hoc
    * sensor networks
    * underwater sensor networks
    * mesh networks
    * opportunistic networks
    * manet - mobile ad hoc
    * vanet - vehicular ad hoc
* other types
    * rfid
    * nano networks

## ad hoc networks

it's a peer to peer network, where the infrastructure are the peers themeselves, props:
* normal routing tables don't work, multihopping is used to communicate
* performance depends on the peers
* multihop is subject to interference
* more power can avoid multihop, but it consumes more energy and generates more interference

ad hoc networks can be:
* sensor networks --> focused on energy saving, usually it sends the data to a central server
* mesh networks
* manet --> topology is highly dynamic
* vanet --> used to coordinate vehicles, energy consumption is irrelevant
* fanet
* opportunistic --> uses other peers to use a specific service, like internet

## mesh networks

WLAN+ad hoc network, consists of 3 layers:
* wired access points connected to the internet
* wireless access points
* ad hoc peers communicating with the wireless access points

bigger coverage than WLAN, but still centralized for the access points

## sensor networks

* low energy
* high number of nodes
* nodes can help each other

## RFID - radio frequency id

components:
* reader --> emits signals/query and read the tag's id
* tag --> answer a signal by sending its ID