# Normalizzazione

## Dipendenze funzionali

**dipendenza funzionale**

un attributo Y dipende funzionalmente da un gruppo di attributi X se X riesce ad identificare univocamente Y, quindi 2 o più tuple di X con gli stessi valori devono avere anche stesso Y

si indica con X --> Y

di base è l'implica logico, una dipendeza funzionale è quando gli attributi X implicano l'atributo Y

le dipendenze funzionali si dividono in:
* banali
* parziali
* complete

**dipendenza funzionale banale**

si ha quando Y compare anche a sinistra, cioè quando:
* Y,X --> Y (y implica y duh) 

di base è una tautologia

**dipendenza funzionale parziale**

si ha quando una dipendenza funzionale rimane togliendo attributi dall'insieme X

di base significa che X contiene attributi superflui

**dipendeza funzionale completa**

si ha quando una dipendenza funzionale non rimane togliendo attributi dall'insieme X

significa che X non ha attributi superflui

**assioma di riflessività**

se Y è e contenuto in X allora X --> Y

**assioma di potenziamento**

se X --> Y allora XZ --> YZ

**assioma di transitività**

se X --> Y e Y --> Z allora X --> Z

**unione**

se X --> Y e X --> Z allora X --> YZ

**decomposizione**

se X --> YZ allora X --> Y e X --> Z

**copertura**

è un insieme di attributi Y=*a,b,c,d...* tali per cui:
* X --> Y

**insemi equivalenti**

2 insiemi A e B di dipendenze funzionali sono equivalenti se A riesce ad implicare ogni dipendenza di B e viceversa


**insiemi non ridondante**

un insieme non è ridondante se non esiste una dipendenza f tale che l'insieme F - {f} implica f

**insiemi ridotto**

un insieme è ridotto se:
* non è ridondante
* si sono rimossi tutti gli attributi di sinistra superflui nelle implicazioni

**copertura ridotta**

è una copertura con le proprietà di un insieme ridotto

## Forme Normali

una base di dati si dice in forma normale quando:
* non c'è ridondanza
* inserimenti, rimozioni e aggiornamenti non creano incosistenze

**1NF**

una relazione è in 1NF quando:
* tutti gli attributi sono atomici hanno un singolo valore

**2NF**

una relazione è in seconda forma+
* è in 1NF
* ha solo dipendenze funzionali complete

**3NF**

una relazione è in terza formale normale quando:
* è in 2NF
* in ogni X --> Y deve valere almeno una delle seguenti condizioni:
    * X è una superchiave della relazione
    * Y fa parte della superchiave chiave (attributo primo)

**boyce-codd NF**

una relazione è in forma normale di boyce e codd quando:
* è in 2NF
* in ogni X --> Y deve valere la seguente condizione:
    * X è una superchiave della relazione

**algoritmo per la 3NF**

1. si calcola la chiusura ridotta:
    * si trovano tutte le dipendenze funzionali della relazione
    * si deconpongono
        * es. AB --> CDE si spezza in: AB --> C, AB --> D, AB --> E
    * si rimuovono le dipendenze funzionali banali (AB -> A)
    * si rimuovono le dipendenze funzionali transitive
        * es. A --> B e B --> C deve rimuovere eventuali A --> C
    * si semplificano le ipotesi
        * es. ABC --> D e A --> C diventa AB --> D e A --> C
2. si calcola la chiusura di ogni dipendenza funzionale dell'insieme appena trovato:
    * la chiusura è formata da ciò che la dipendenza riesce ad implicare (anche transativamente)
    * nb: X --> Y ha chiusura X<sup>+</sup> = {X,Y}, fa parte della chiusura anche ciò che gli elementi all'interno riescono ad implicare
3. si crea una partizione per le dipendenze funzionali che hanno la stessa chiusura
4. si crea una relazione per ogni partizione
    * partizione = { A-->B, A-->C} crea una relazione R(A,B,C) di base si prendono gli attributi distiniti
5. si eliminano le relazioni appena create il cui insieme di attributi è sottoinsieme di un'altra relazione
6. se non esiste una relazione che contiene tutte le chiavi, la si crea
7. il risultato è in 3NF

algoritmo di base:
1. si calcola la chiusura ridotta:
    * si trovano tutte le dipendenze funzionali della relazione
    * si deconpongono
    * si rimuovono le dipendenze funzionali banali (AB -> A)
    * si rimuovono le dipendenze funzionali transitive
    * si semplificano le ipotesi
2. si calcola la chiusura di ogni dipendenza funzionale dell'insieme appena trovato:
    * la chiusura è formata da ciò che la dipendenza riesce ad implicare (anche transativamente)
3. si crea una partizione per le dipendenze funzionali che hanno la stessa chiusura
4. si crea una relazione per ogni partizione
5. si eliminano le relazioni appena create il cui insieme di attributi è sottoinsieme di un'altra relazione
6. se non esiste una relazione che contiene tutte le chiavi, la si crea
7. il risultato è in 3NF

**algoritmo per boyce-codd**

1. si calcolano le dipendenze funzionali
2. se X --> Y vìola la boyce codd NF si crea una relazione R(XY) con X chiave e di elimina Y dalla relazione precedente