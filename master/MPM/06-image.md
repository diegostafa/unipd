## human eye

props
* captures the visisble spectrum (400-800nm)
* retina made of rods and cones
    * rods --> night vision
    * cones --> rgb detection
* luminosity is more relevant to colors

## colors

cube models
* used in printers, screens
* represent colors
* hard to modify a specific color
* rgb --> addictive, from black you add colors
* cymk --> subtractive, from white you subtract color

hex models
* used in tv
* represent perception of colors
* hsv --> hue, saturation, intensity
* yuv/ycbcr
    * y --> luminance
    * u/cb --> blue chrominance
    * v/cr --> red chrominance

cie xyz
* used for calibration, camera

## image

2d matrix containing color information

color depths
* 1 bit --> monochrome
* 8 bit --> palette pointing a table of real colors
* 24 bit + 8 bit --> rgb + transparency
* 48 bit --> rgb high definition for printers
* 48+ bit --> scientific reasons

palettes
* OS palette
* standard palette --> divide the cube in 6
* optimized palette --> take the colors from the image

## bitmap format

props
* used in windows
* can represent palettes
* uncompressed/rle
* good for digital

## gif

props
* 8 bit depth
* lossless, fast
* requires a license

## png

props
* lossless
* varibale color depth
* allow transparency
* interlacing
    * missing pieces are inferred from the near values
* you can add custom channels

## jpeg

image preparation
* divide the image in 64 sectors with YUV
* Y channels is generated from rgb
* UV are undersampled --> eyes are not color sensible
* lossy, image size drops in half

apply DCT
* translate colors to frequecies
* the 0,0 block is the main color, the rest are its variations
* 0,0 is called DC
* keeping only the first cell results in a block of that color
* lossy

quantization step
* divide each dct table with a quantization table
* lossy

linearization
* linearize each block with a tail dove mapping
* this is good because useless coefficients are grouped together
* apply RLE

lossless compression
* apply huffman

props
* usefule with colorful images
* good for photos, not for digital
* missing packets can degrade the image
* losing DC result in an empty block

## jpeg 2000

DWT
* recursively downscale the image in 4 sector
* lossy
* DWT does not work block wise
* allows to generate multiple image resolutions
* getting a speciic line of the image requires to get the lines for all the subsectors

quantization
* coefficients follow the eye sensibility
* it keeps the high frequencis of the image

props
* not supported by browsers
* not compatible with jpeg
* uses DWT instead of DCT
* support huge res
* lossless ROI
    * done with maxshift --> shift quantization on that region
* better error correction
* good for digital too

## vector graphics

props
* quality is about the number of shapes used