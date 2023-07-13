seconda importante astrazione che l'os offre, di base crea l'illusione di memoria riservata ad un processo, infatti ogni processo indirizza a partire da 0 come se fosse l'unico processo in memoria.

**indirizzo virtuale** 

indirizzo utilizzato dal programma

**indirizzo fisico**

 indirizzo effettivo della ram

quando un programma emette un indirizzo questo è sempre virtuale, è compito dell'os e dell'hardware di tradurlo

il processo è definito da un area di memoria formata da:
* codice
* heap
* stack

chiamata area di indirizzamento

### base-limit memory

l'area di indirizzamento è determinata da 2 valori:
* base register --> primo indirizzo fisico dell'area di indirizzamento
* limit register --> ultimo indirizzo fisico dell'area di indirizzamento

la traduzione virtule-fisco è: base register + virtual address ed è fatta dall'MMU, dispositivo hardware che contiene i 2 registri

il context switch di un processo deve anche cambaire i valori di base e limit

se il risultato è minore del limit register allora l'indirizzo è valido, altrimenti viene lanciata un'eccezione al sistema operativo che gestisce il processo che ha tentato di accedere ad un'area di memoria non sua.

* pro --> semplice, consente protezione tra aree di memoria, traduzione veloce
* contro --> area di indirizzamento trattata come blocco unico indivisibile, frammentazione interna, molto spazio non utilizzato

### segmentation memory

di base si divide l'ares di indirizzamento in 3 sottoaree:
* codice
* heap
* stack

e si assegna un base-limit register ad ogni area

* pro --> veloce, consente codivisione di memoria tra processi, no segmentazione interna
* contro --> segmentazione esterna
