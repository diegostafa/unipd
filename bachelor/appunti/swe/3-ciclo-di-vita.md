# Ciclo di vita software

indica lo stato che il prodotto assume durante la sua vita, dall'inizio alla fine, sulla base delle attività svolte

automa a stati finiti dove:
* stato --> grado di maturazione del prodotto
* arco --> connettono 2 stati attraverso un processo/attività
* fase --> tempo che intercorre nel passaggio tra uno stato e l'altro o tempo in uno stato singolo

dipende dal committente:
* one off --> versione unica
* continue evoluzione
* dipendenza dal ciclo di vita delle sue dipendenze
* coinvolgimento del committente

un ciclo di vita può avere 3 tipi di manutenzione:
* correttiva --> corregge bug
* adattiva --> adatta il sistema al variare dei requisiti
* evolutiva -> aggiunge funzionalità nel tempo

**processo di ciclo di vita**

insieme di attività necessarie per cambiare di stato

**progetto di ciclo di vita**

spinge il prodotto attraverso un dato segmento del suo ciclo di vita

**modello di ciclo di vita**

standard che descrivono quali stati e transazioni sono da privilegiare rispetto ad altri, vanno quindi a specificare i processi

**fase**

segmento temporale per passare da uno stato all'altro oppure per rimanere nello stesso stato

indica (preferibilmente) un avanzamento del progetto

**iterazione (pittura)**

* procede per rivisitazione --> torna indietro per rifare
* potenzialemente distruttiva

vantaggi:
* si può applicare a qualsiasi modello di sviluppo
* si adatta ai cambiamenti, si rifà tutto

svantaggi:
* spreco di tempo, il tempo fa avanti ma si torna ad una fase precedente
* non garantiscono una convergenza alle post condizioni

**incremento (scultura)**

* procede per raffinamento --> ripete per aggiungere (integrazione continua)
* solo costruttivo
* indica un rilascio a più versioni

vantaggi:
* produce valore ad ogni incremento
* ogni incremento riduce il rischio di fallimento, ma non lo azzera

**PoC**

può essere:
* usa e getta --> solo dimostrativo
* di partenza --> usato per incrementi

**riuso**

può essere:
* copia-incolla --> basso corso
* sistematico --> usato per una famiglia di prodotti, alto costo

**baseline**

* punto di arrivo dalla quale non si retrocede
* è un insieme di artefatti concreti che rappresenta un risultato stabile, ma non definitivo
* è solitamente assegnata ad una milestone

**milestone**

* punto di arrivo nel tempo che si prefissa determinati obiettivi
* è una data di calendario che si propone obiettivi

**fase**

tempo che intercorre tra due milestone