**reactive extension**

* astrazione dei sistemi concorrenti
* costrutti semantici per l'elaborazione asincrona
* si basa sull'observable pattern:
    * observable --> oggetto che emette uno stream
    * subject --> consuma observable e può diventare un observable
    * subscriber --> legge lo stream dell'observer e produce un risultato
    * scheduler --> parametro di concorrenza da applicare ad un obsevable

**reactive manifesto**

un sistema è reattivo se:
* responsive --> bassa latenza
* resiliente --> gestire i fallimenti, si ottinee con replicazione e sostituzione dei nodi
* elastico --> adatta i nodi al carico, evita colli di bottiglia
* orientato ai messaggi --> i nodi possono comunicare e gestirsi

**reactive stream**

* fast data --> grande mole di dati da elaborare velocemente
* back pressure --> indica quante richieste può soddisfares 
* ogni nodo può fissare un limite di dati da ricevere
* reactive stream --> impedisce di sovraccaricare un nodo di dati
* si basa su publisher pattern
    * publisher --> equivalente di observable
    * subscriber --> ma controlla anche il flusso di ingresso
    * subscription --> legame tra publisher e subscriver, controlla il flusso di dati
    * processor --> sia subscriber che publisher, 