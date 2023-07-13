## Introduzione alla reti

**rete**

qualsiasi cosa che è rappresentabile con un grafo

esempi di rete:
* internet
* ethernet
* periferiche
* rete telefonica
* adsl
* bluetooth
* bancomat
* corpo umano

**classificazione delle reti**

una rete si puà classficare in base a diverse proprietà:
* per taglia:
    * WAN
    * MAN --> reti cittadine, università
    * LAN
        * wired --> ethernet, token ring
        * wireless --> fddi, atm, wifi
    * PAN
        * wired --> tastiere, mouse, stampanti
        * wireless --> tastiere, mouse, bluetooth
* per topologia:
    * P2P o point to point (importantissima)
    * bus
    * star
    * ring
    * mesh
    * tree
    * hybrid (tra le precedenti)
        * reti gerarchiche (es. internet)

**Internet**

l'internet è una rete di reti:
* formata da hosts
    * eseguono applicazioni di rete
* rete fisica
    * rame, onde radio ...
* routers 

organizzazioni:
* RFC --> request for comments
* IETF --> internet engineering task force

ogni strato comunica con dei protocolli

**multiplexing**

di base come il multitasking, è una tecnica che divide un canale per gestire multiple comunicazioni

analogia:
* cpu --> canale
* processi --> comunicazioni

**servizi e protocolli**

* protocollo --> permettono di comunicare nello stesso mondo (layer)
* servizi --> permettono di comunicare tra mondi adiacenti

**OSI**

è il modello ufficiale, ha 7 strati:
1. physical
2. data link
3. network
4. transport
5. session
6. presentation
7. application

vantaggi:
* separazione delle funzionalitù
* interoperabilità

svantaggi:
* separazione e layers troppo rigidi

**TCP/IP**

è il modello della rete internet, ha 4 strati:
1. host to network --> pastrocchio
2. internet
3. transport
4. application

svantaggi:
* gli strati non sono nettamente separati
* il modello tcp/ip è stato fatto per retrofitting
* host to network non è un vero layer
* non ci sono layer fisici/data link
* molti protocolli non sono separati

**modello ibrido**

è di base TCP/IP + OSI, ha 5 strati:
1. physical
2. data link
3. network
4. transport
5. application
