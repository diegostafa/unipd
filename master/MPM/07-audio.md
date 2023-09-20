## human ear

props
* sound depends on
    * pinna --> ear drum --> cochlea (a cell)
* cochlea defines what we can percieve
* human range is 20Hz - 20khz
* ears are more sensitive than eyes
* ears don't capture sound linearly
* ears are most sensible around 2Khz

## sound

props
* it's a wave on a medium
* frequency --> pitch
* amplitude --> intensity/volume
* waveform --> timbre, like the id of the sound
* compression is harder (preserve timing)

noise/error
* difference between real and quantized
* each bit used increases the SINR by 6db
* sampling happens at 44.1KHz

compression techniques
* silence compression --> encode consequtive silence
* adaptive differential pulse --> encode difference betweeen samples
* linear predictive coding

theory
* fft --> each periodic wave can be decomposed in multiple sinusoids
* nquyust --> at least 2n samples required to catch a sound of max n Hz
* fletcher curves --> how sounds are perceived the same based on freq and ampl

masking
* tonal --> a pure sound hides other sounds with similar freq and lower volume
* non tonal --> noise hides lower and higher sounds
* temporized --> a sound can hide another for a certain time
    * premasking --> time it takes for the drum to start
    * postmasking --> time it takes for the drum to finish

## mpeg

layer 1
* uses tonal masking
* each sub bands contain 12 samples

layer 2
* uses tonal+temporal masking
* works with 3 bands at time

layer 3 (MP3)
* variable bitrate
* uses tonal+temporal masking
* better quality OR size than layer 1

watermarking
* done near high freqs so it is masked
* defines originality, not uniqueness

encoding
* divide the signal in 32 sub bands
* for each band, compute the mask level
* for each band, apply the mask to the signal

## midi

* like vector graphics, it represents notes, duration
* only works for music
* quality

made of
* channels --> number of instruments
* tracks --> what it gets played
* patch --> instruments