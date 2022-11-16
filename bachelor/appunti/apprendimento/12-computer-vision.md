**computer visiion**

obiettivo:
* creare un modello di classificazione con immaginni come input 

problemi:
* luminosità
* scala
* deformazioni
* prospettiva
* punto di vista
* occlusione
* complessità

**image histogram**

rappresentazione di un immagine tramite istogrammi RGB

molot suscettibiel a cambi di luminosità

**immagini come funzioni**

pixel x,y --> valore


**filtering**

da ogni pixel applica una funzione

tipi:
* box filter --> box(n,m) = media di 3x3 pixel


kenrel filter:
* f*h(x, y) = +++ 

**reti neurali per l'apprendimento visuale**

lgni livello va a repplicare il meccanismo gerarchico di riconoscimento:
* prima si riconoscono le linee primitive
* poi i colori
* poi l'illuminazione


**CNN - convolutioanl neural network**

rete neurale divisa in:
* layer convoluzionali
* pooling layer
* fully connected layer

**layer convoluzionale**

input:
* immagine

l'input del layer è la convulazione dell'immagini, cioè l'immagine applicata con un filtro parametrizzato, si vanno quindi a trovare i parametri di questi filtri