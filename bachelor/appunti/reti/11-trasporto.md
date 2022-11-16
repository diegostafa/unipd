# Transport layer

lo strato di trasporto si occupa di fare multiplexing delle singole risorse in rete (macchine con un indirizzo IP)

di base fornisce il meccanismo di porte per separare processi di rete, quindi il meccanismo dei socket (IP + porta)

**UDP**

è un protocollo dello stato di trasporto, fornisce il minimo necessario, di base è un wrapper IP che fornisce il supporto ai sockets, formato da:
* source port
* dest. port
* udp lenght --> lunghezza header
* udp checksum --> opzionale
* IP frame

proprietà:
* connectionless --> perchè di base è un frame IP + porte
    * non esiste il concetto di canale, il pacchetto ha mittente e destinatario e basta

**DNS (Domain Name System)**

serve a tradurre un indirizzo human readable in indirizzo ip, siccome la traduzione è del tipo domanda e risposta si usa l'UDP

funzionamento:
* si invia il nome da tradurre al server DNS
* se il DNS contiene l'entry nella sua tabella risponde
* altrimenti inoltra la richiesta ad un DNS di livello gerarchico superiore

**TCP (Transmission Control Protocol)**

è il contrario dell'UDP, formato da:
* header lungheza variabile
* 6 flags in piggybackingù
    * ACK
    * reset connection
    * fine connessione con ACK
    * pacchetto ad alta priorità
    * pacchetto a bassa priorità
* sequence number
* sliding windows con finestra variabile (go back n e selective repeat)
* checksum di somme
* 3 way handshake

proprietà:
* full duplex
* supporta le porte
* flow control
* error control semplice

3-way handshake:
* invio un pacchetto SYN di richiesta (apri questa connessione X)
* ricevo un pacchetto SYN di conferma (apro questa connessione X?)
* invio un pacchetto SYN per confermare (sì)