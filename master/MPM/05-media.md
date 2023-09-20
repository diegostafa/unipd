## media

classification
* content --> text, image, audio, video
* dynamic --> static, dyanmic, temporized media

props
* size
* time
* quality

compression
* reduce size --> optimize transmission
* asymmetric encoding/decoding in time
* error correction
* lossy/lossless

static media
* text, images
* size is not a problem

dynamic media
* games, videos

temporized media
* televesion, real time streaming

## compression

3 steps
* transformation
* quantization --> values are classified
* encoding

lossless algos
* run length encoding --> encode frequencies
* huffman
* LZW
* differential

lossy alogs
* jpeg
* mpeg
* mp3

## Run length encoding

props
* used with long repetitive data
* basically it just specifies the frequency of the repeated data

pros
* easy
* good for digital images

cons
* does not work with text ot images

## entropy encoding

huffman
* create the frequency table of the data
* create the frequency tree from bottom up
    * take 2 less frequent sum and repeat
    * map sx/dx branches with 0/1
    * the path is the encoded value

shannon fano
* create the frequency table of the data
* create the frequency tree from top down
    * recursively split the frequency table so that they 2 parts have roughly the same total frequencies
    * map like in huffman

props
* huffman tree is more balanced

## LZW compression

encoding
* create a dictionary containing the alphabet of the data and enumerate it (codes)
* read the data linearly and create a sequence
* if the sequence is not in the dict, add it and assign the last code+1
