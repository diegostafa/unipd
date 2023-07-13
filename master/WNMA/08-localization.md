## metrics

* accuracy --> error between estimated and actual position
* precision --> error distribution of accuracy
* robusteness --> variability in different environments
* scalability --> variability in different devices
* cost --> initial/mantainance cost

notation:
* BS --> base station
* MS --> device

## localization

triangulation
* localize MS given the angles from 2 BS

trilateration
* localize MS given the distances from 3 BS

## distance estimation

time of arrival:
* send timestamps during messages
* need synced clock

RTT
* time for receiving the ack

timers can be
* hardware --> hardware timestamp triggered at the mac layer
* software
    * average estimation
    * goodtry --> the estimation is done with rts/cts and data/ack (goodtry algorithm)

## indoor localization / scene analysis

fingerprint collection:
* periodically save some information of the MS (distance, RSS)

localization
* use machine learning algorithms to associate a fingerprint to the real position

## landmark localization

* localization using scene analysis + RFID
* fingerprints are singnal
* uses knn
* depends on the quality of the RFID readers

## VR/AR

* coordinates are encoded by 4d matrices
* to represent an object in a different system it needs to translate coordinate to that system
* needs camera calibration