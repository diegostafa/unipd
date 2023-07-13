## wireless phisical layer

defines the network infrastructure, cable, antennas, signals...

## radio signals

electromagnetic wave defined by:
* amplitude --> height of the signal
* frequency --> oscillation in 1 second
* phase --> distance between 2 peaks

## antenna

an antenna is an object able to receive and transmit radio signals, can be:
* omni-directional
* semi-directional
* highly-directional
    * emits in a specific direction
    * must be placed accurately to avoi fresnel zone problems
* sectorized --> emits in N different directions called sectors (space multiplexing)

## fresnel zone

between highly directional antennas signals bend and can arrive at different phases, producing garbage signals

## propagation

depends on various phisical effects like reflection, refraction, diffraction

propagation is measured with:
* transmission range --> how far can it travel
* detection range --> from how far can it be detected
* interference range --> how far before the signal becomes interference

## performance

depends on the frequency of the signal

perfomance can be improved changing the type of transmission
* undirectional link --> one way communication
* symmetric link --> fair two way communication
* asymmetric link --> unfair two way communication

## multiplexing

consists in sharing a resource among different consumers, in case of wireless networks the communication channel, multiplexing can be done in:
* space --> sectorized antennas
* frequency --> unique frequencies for each device
    * static allocation
    * waste bandwidth
* time --> time slots for each
    * full bandidth in your slot
    * need synchronization of slots between devices
* code --> the device sends an encoded message, the antenna has the decoder
    * more complex
    * full bandwidth, but lower data rate