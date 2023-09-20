## human eye

* retina retain vision for a short time
* the brain create a transition between 2 consecutive

## video

interlacing
* split each frame in even, odd lines
* you can get more fps by mixing those lines and display the new frame

frame can be sent in 3 ways
* separate components --> requires sync
* merged components --> more interference
* s component --> luminance and chrominance are separated

props
* bit depth --> usually true color
* fps --> 25 or 30

## temporal redudndecy

to compress similar frames
* divide the frame in blocks
* check where the blocks move
* track the movement with a vector

## motion jpeg

* each frame is encoded as a jpeg
* ignores frame correlation (temporal redundency)

## h261 format

props
* used for video streaming
    * CAN't use asymmetric compressions
* input fps = 30, output fps = 15
* uses i-frames
    * 1 fps
    * jpeg img
* uses p-frames
    * 14 fps
    * prediction from the frame before
p-frame


## h263 format