
# Network layer

**IP (Internet Protocol)**

storia:
* arpanet che usava il protocollo di trasmissione NCP (affidabile, error control e flow control)
* evoluzione di NCP in TCP
* TCP si spezza in TCP e IP

creato per uso militare, formato da:
* versione
* grandezza dell'header
* tipo di servizio (QoS) --> spesso ignorato, indica la qualità di trasmissione voluta
* lunghezza del pacchetto
* identification --> indica se i dati sono stati frammentati
* non frammentare/frammenta
* offset del frammento
* TTL --> time to live, età max del pacchetto
* protocol --> se i dati sono in un certo protocollo
* header checksum --> complemento a 1

pro:
* connectionless --> robustezza, se cade un pezzo di rete non succede nulla
* leggero

contro:
* TTL max 255 --> problema solo nelle reti non gerarchiche
* scarsità di indirizzi
* no protezione

**ICMP (Internet Control Message Protocol)**

i pacchetti ICMP sono incapsulati nell'IP, servono a risolvere eventi negativi della rete

**CIDR (Classless InterDomain Routing)**

gli indirizzi IP vengono distribuiti in classi a lunghezza variabile

i router salvano questi indirizzi in aggregate entries, di base vengono compattati indirizzi che hanno prefissi in comune, le eccezioni vengono gestite con la tecnica del longest matching, il prefisso più lungo ha priorità

**NAT (Network Adress Translation)**

vede la rete come un unico indirizzo IP, si occupa di tradurre gli indirizzi dei pacchetti uscenti/entranti dalla rete

di base:
* il NAT ha un indirizzo esterno xxx.xxx.xxx.xxx
* ogni host in rete ha un indirizzo associato del tipo 192.168.1.xxx
* il NAT ha una tabella delle connessioni del tipo:
    * host:porta - NAT:porta

A:30 invia un pacchetto:
* il NAT sostituisce l'indirizzo 
funzionamento:
* la macchina manda un messaggio di discovery al server DHCP
* il DHCP assegna un indirizzo IP alla macchina

pro:
* risolto problemi degli indirizzi IP

contro:
* si mescolano i livelli di internet e trasporto
* si perde la proprietà connectionless della connessione
* se cade il NAT si perdono le connessioni

la trasmissione guadagna uno stato salavato nel NAT, ciò crea un punot di fallimento della rete

**ARP (Address Resolution Protocol)**

traduce gli indirizzi IP in indirizzi MAC in un modello decentralizzato

funzionamento:
* ogni macchina ha la propria ARP table
* la macchina chiede in broadcast ch ha un certo indirizzo IP
* la macchina interessata risponde

ottimizzazioni:
* mandando in piggyback il proprio IP
* tutte le macchine che hanno ascoltato in broadcast memorizzano in ogni caso gli ip degli interessati

pro:
* funziona da controllore di coppie IP-MAC se la macchina manda in broadcast il proprio IP e riceve risposta
* milk style, nuova informazione ha priorità sulla vecchia

**IPv6**

caratteristiche:
* ha 16 byte di indirizzi
* non ha il checksum

