## TCP - transmission control protocol

props:
* reliable
* full duplex
* byte oriented
* the ACK contains the number of the last packet arrived, not the one sent

features:
* retransmission --> for reliability
* congestion control --> avoid too many packets travelling the network
* congestion avoidance --> avoid too many packets travelling the network, but in a smart way
* flow control --> the sender can send at most the packets that fit in the receiver (advertise window)

## delay badwidth product

indicates the max capacity of the netwoek
* RTT * bandwith

## retransmission algorithms

RTO retransmit
* retransmit when RTO expires
* low RTO --> redundant retrasmissions
* high RTO --> slow speed

fast retransmit
* retransmit after receiving 3 dupacks (repeated acks)

aggressive retransmission
* after dupack + timer retransmit

## congestion control algorithms

default
* on ACK --> shift the window
* on win_size shifts --> increment win_size
* on collision --> reset win_size

AIMD
* on ACK --> increment win_size
* on collision --> halve win_size

slow start
* on ACK
    * if win_size < SSTRESH --> double win_size
    * else --> increment win_size
* on collision
    * if 3 dupacks --> halve the window
    * if RTO timeout --> reset win_size
    * SSTRESH = win_size / 2 --> fast recovery

aggressive window adaption
* on multiple loss on the same window --> decrement only once win_size
* on collision --> SSTRESH = win_size * 3/4 --> modified fast recovery

modified slow start:
* if expected - actual < y --> use normal slow start
* else --> use congestion avoidance

congestion avoidance
* a = high congestion value (few packets per RTT)
* b = low congestion value (many packets per RTT)
* ideal_rate = win_size / RTT
* actual_rate = ACKs / RTT
* if high congestion --> decrement win_size
* if low congestion --> incrmeent win_size

cons:
* sensitive to delays (contention timer in MAC layer)

## tcp variants

variants:
* tcp reno --> standard tcp
* tcp tahoe --> AIMD + no fast retransmit
* tcp new reno --> partial acks to recover multiple packets
* tcp sack --> selective acks which tell what packets were received
* tcp vegas
    * congestion avoidance
    * aggressive retransmission
    * aggressive window adaptation
    * modified slow start


## vegas friendliness

* vegas slows down because of congestion avoidance
* reno normally increases the window
