## Tecniche di mappatura
la mappatura di una cache può essere implementata in 3 diversi modi:
* associazione diretta
* associazione completa
* associazione ad N vie


### Cache ad associazione diretta
* si suddivide la memoria in blocchi (es. un blocco = 16 parole)
* si suddividono i blocchi in porzioni di blocchi (es. una porzione = 128 blocchi)
* la dimensione della porzione **DEFINISCE** il numero di linee della cache (es. se la porzione è di 128 blocchi allora la cache avrà 128 linee)
* presa una porzione, ogni blocco all'interno della porzione è **univocamente** mappato da **una** linea di Cache.

#### esempio
* blocco --> 16 parole
* porzione --> 128 blocchi --> 128 linee di cache

mappatura:
* porzione dati 1
 1. blocco 1 --> linea 1
 2. blocco 2 --> linea 2
 3. blocco 3 --> linea 3
 4. blocco 128 --> linea 128
* porzione dati 2
 1. blocco 1 --> linea 1
 2. blocco 2 --> linea 2
 3. blocco 3 --> linea 3
 4. blocco 128 --> linea 128

...e così via.

NB: tenere a mente ciò non impone che bisogni mappare solo i blocchi di porzione 1 o 2 tutti insieme, ci possono benissimo essere in cache blocchi diversi di porzioni diverse.

**considerazioni**
si nota che un blocco può essere mappato solo in una specifica linea, ciò implica che due blocchi N di porzioni diverse non possono contemporaneamente in cache.


#### **Ricerca di una parola in cache**
un indirizzo di ram con cache ad associazione diretta si scompone in:
* tag --> numero di porzione
* blocco --> numero di blocco all'interno della porzione
* word --> numero di parola all'interno del blocco

di seguito gli step che la cache esegue per inviare una parola alla cpu:

1. usa il campo blocco per trovare la linea di cache associata.
2. usa il campo tag per verificare che il blocco salvato nella linea trovata abbia lo stesso numero di porzione
3. usa il campo word per inviare la parola della posizione richiesta


### Cache ad associazione completa
la cache non divide più la memoria in porzioni, ma solo blocchi.
il numero di linee della cache non dipende più dalla ram.
di base ogni blocco può essere mappato in una qualsiasi linea della cache.


#### **Ricerca**
in pratica la cache controlla in parallelo tutte le linee per verificare la presenza di un blocco

NB: non avviene per magia, si costruisce hardware apposito nella cache, infatti questa tecnica costa tantissimo da implementare.


### Cache ad associazione ad N vie

* la ram anche qui viene divisa solo in blocchi.
* la cache viene divisa in set
* ogni set contiene N linee (l'N è dell'N vie del nome)
* ogni blocco in ram appartiene può essere mappato solo in un set specifico

di base è l'unione tra associazione diretta e completa:
* associazione diretta --> i blocchi possono essere mappati solo nelle linee di uno specifico set.
* asssociazione completa --> per individuare un blocco dentro un set si cerca tra tutte le linee in parallelo confrontando i tag

#### **Ricerca**
1. trova il set specificato nell'indirizzo
2. in parallelo controlla tutti i tag in quel set
3. se trova il tag corrispondente invia la parola di posizione indicata nel campo word.


## confronto tra le diverse tecniche

**cache ad associazione diretta**
* pro --> semplice e poco costosa
* contro --> mappatura inefficente e numero di linee dipende dalla dimensione delle porzioni

**cache ad associazione completa**
* pro --> mappatura efficente al massimo e veloce
* contro --> costa troppo

**cache ad associazione a N vie**
* pro --> è un compromesso di velocità e mappatura ed è scalabile (numero di linee per set variabile)
* contro --> nessuno
