
# Dispositivi di rete

siccome le reti ethernet servono solo per il locale (efficenza cala con la grandezza della rete), per creare una rete su scala globale si utilizzano le reti di reti, e la connessione di reti avviene su più livelli:
* fisico --> hubs e ripetitori
* data link --> switch
* network --> routers

## Data link layer

**ripetitori e hubs**

il ripetitore serve a ripetere e amplificare il segnale, l'hub propaga un segnale in tutte le sue porte

**switch**

servono a collegare logicamente reti locali ed inoltrare i pacchetti da una rete all'altra

fase di apprendimento dello switch:
* prende un pacchetto dela stazione A della rete 1
* sa che la stazione A è nella rete 1 e mette questa informazione in una teballa
* lo inoltra a tutti
* man mano che si scambiano pacchetti si popola la switch table

dopo un tot di tempo lo switch resetta la tabella (per rinfrescare le informazioni della rete)

## Network layer

**router**

mentre lo switch instrada pacchetti in reti locali collegate, il router lo deve fare su reti di scala globale, dove il router non conosce in che rete si trova il destinatario

**flooding**

il router ritrasmette il pacchetto in tutte le altre reti

pro:
* sceglie sempre la via migliore
* è robusto a modifiche di rete

contro:
* non è scalabile

* hopcounting --> si da un tempo di vita al pacchetto in flooding per non saturare la rete
* tracking --> si numerano i pacchetti arrivati

**distance vector routing**

usato nell'arpanet, funzionamento:
* ogni router chiede ai router adiacenti
* da queste tabelle costruire la sua tabella 

pro:
* modifiche buone della rete aggiornano le tabelle

contro:
* si comporta male quando la rete si guasta

problema count-to-infinity --> se un router cambia distanza il distance vector non si aggiorna subito

**link state routing**

funzionamento:
* calcola le distanze come il distance vector
* le inoltra a tutti i router con il flooding

di base usa il flooding per risolvere count-to-infinity

**quality of service**

indica la qualità del servizio offerto, nelle reti è identificato da 4 parametri:
* affidabilità
* bandawidth
* delay di trasmissione
* jitter --> indica se il delay di trasmissione varia tanto o poco

questi parametri variano in base al servizio interessato:
* email --> interessa solo affidabilità
* ftp --> interessa affidabilità e banda
* video --> interessa jitter e banda

soluzioni per il QoS:
* affidabilità --> error control e detection
* bandwidth --> congestion control

**choke packet**

si usa per limitare la congestione, se un router si accorge che c'è congestione, invia un pacchetto speciale a chi sta creando congestione per indicarlgi di rallentare, solitamente dopo un choke packet l'host dimezza il suo data rate esponenzialmente (50%, 25%, 12%...)

contro:
* un host può ricevere diversi chokes da diversi routers --> sol. si filtrano temporalmente
* il choke può metterci molto tempo per arrivare --> si risolve parzilmente con il choke by hop, si manda il pacchetto di choke che agisce subito sul router in cui arriva e viene passato fino al destinatario

**leaky bucket**

si usa per limitare la congestione, di base il router salva i pacchetti in memoria, e li manda in uscita con un data rate costante

pro:
* semplice ma efficace

contro:
* il data rate è costante

**token bucket**

di base il router ogni tot di tempo incrementa un contatore e un pacchetto per uscire deve decrementarlo, non esce se il contatore è 0, consente di limitare il data rate in base alla frequenza con cui si incrementa il contatore
