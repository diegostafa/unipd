## tcp wireless problems

mac layer
* home routers are bottlenecks
* long tcp increase the jitter (delay between 2 packets)

satellites
* high RTT --> window_size icnreases slowly

disconnection
* reduces window_size even with no congestion
* after the link is repaired, it still waits for the timer to expire before retransmitting

multihop porblem (A - B - C)
* A send packet 1 to B
* B forward packet 1 to C
* A send packet 2 to B --> collision

tcp aggressiveness
* receiver buffer is full
* the actual throughput is either above or below the real capacity

RTT unfairness:
* short RTT --> device X grows win_size quicker
* long RTT --> device Y grows win_size slowly

## TCP types

types:
* traditional --> wired tcp
* connection split
    * half wired, half wireless
    * splits the connection with a proxy, one wired and one wireless
    * snoop protocol
* pure end to end
    * pure wireless
    * delayed dupacks

## TCP snoop

algorithm:
* send a packet to the proxy
* the proxy caches it
* the proxy sends the packet to the receiver
* if the packet is lost, the proxy uses its cache instead of forwarding it back to the sender --> handle BER/PER

pros:
* transparent proxy --> almost end to end
* dupacks are retransmitted only when necessary
* caching helps against short disconnections
* works better if the wireless link has a short RTT

## TCP westwood/westwood+

props:
* sender only protocol for satellites
* periodically compute an estimate of the bandwidth based on RTT and acks
* the estimate is computed with an expoenential filter --> new samples are more important

congestion control
* on ACK
    * if win_size < SSTRESH --> winsize + 1/win_size
    * else --> increment win_size
* on collision
    * SSTRESH = bandwith estimation
    * if 3 dupacks --> win_size = min(win_size, SSTRESH)
    * if RTT timeout --> reset win_size

## TCP hybla

props:
* for heterogenous networks
* real end to end
* fair over RTT --> every device uses the same fake RTT

fairness
* define a fake_RTT
* ro = actual_RTT / fake_RTT
* adjust the window based on the ro rate

## tcp adaptive

for each link, dynamically select the best tcp based on the network type

## TCP cubic

props
* good for networks with high speed and RTT
* win_size grows cubicly (no acks involved)
* on collision --> stops, but grows again if the networks allows it

## SAP-LAW - smart AP limited adverstise window

basically it allocates a fair window to each tcp connection

to fix tcp aggressiveness (same window for everyone)
* advertise = (capacity - UDP_traffic) / TCP_conns

to fix RTT unfainress (bigger windows for high RTT)
* advertise = (capacity - UDP_traffic)*RTT / (+++ RTT/avg_RTT)

## vegas over AP

props
* vegas is used on the AP to change the advertise window
* the congestion avoidance is used on the outward connections, not the devices
