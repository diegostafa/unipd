## mac layer - media access control

defines how networks resources are allocated

allocation algorithms:
* random access
    * aloha
    * cmsa
    * csma/cd --> no acks, listen for collisions
    * 802.11 csma/ca
    * 802.11 csma/ca + RTS/CTS
    * 802.11 polling
* controlled access
    * polling

note:
* wired phisical layer is easier to manage
* mac layer should fast, fair and resilient

## SINR - signal interference noise ratio

measures the quality of a singal for the receiver:
* sinr = signal / interference + noise

## hidden terminal problem

you send when you shouldn't
```
A is not in range of C
A transmit to B
C transmit to B
collision
```

## exposed terminal problem

you don't send when you should
```
A transmit to B
X is in range of A
X can't transmit to Y
```

## aloha

pure aloha:
* send whenever you want
* if no ack --> collision: transmit again with probability P (wait for some random time)
* max throughput --> 1/2e

slotted aloha:
* time is divided in slots
* you can send only at the start of a slot
* if no ack --> collision: transmit again with probability P
* max throughput --> 1/e

## csma - carrier sense multiple access

like aloha, but you listen for other transmitting devices

1-persistent:
* spin lock until the channel is free and transmit
* if no ack, wait random time

non-persistent:
* wait randomly until the channel is free
* if no ack, wait random time

p-persistent (slotted time):
* if the channel is free, transmit with probability P
* if the channel is busy, wait some time with probability 1-P

## 802.11 csma/ca

csma/ca:
* [sender] listen for DIFS time
* [sender] if channel busy, wait rand(0, backoff)
* [sender] if channel free, send the message
* [receiver] verify data in SIFS time and send ACK
* [sender] if no ack --> collision: double backoff

## 802.11 extra features

RTS/CTS:
* like csma/ca, but with RTS/CTS to avoid collisions (smaller packets)
* bad for small packets (voip, gaming)
* hidden terminal problem --> solved, unless collision on RTS
* exposed terminal problem --> not solved, RTS locks every other device from transmitting

DCF
* backoff is based on the number of devices
* set an upper bound
* on success reset to the min value
* DFS --> give a bigger backoff devices to limit their bandwith

PCF --> point coordinator function
* uses polling
* time multiplexing
* no collisions
* good for many senders

TSF --> time sync function
* devices go to sleep instead of waiting
* the AP buffers the packets for them
* the devices sleep and sync their time with each beacon


## 802.11 fairness

occurs when a node has a bigger backoff than other
if the backoff is too big one device might send few packet compared to other devices with smaller backoff

## MACAW

useless variation of 802.11
* on collision --> backoff * 1.5
* on success --> baclkoff - 1
* fair --> always send the backoff time in the message
