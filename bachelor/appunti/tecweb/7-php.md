# PHP

**tipi**

* primitivi alla C
* callable --> funzioni
* resource --> librerie esterne
* null
* const

**variabili**

superglobali:
* _server
* _get
* _post
* _files
* _cookie
* _session
* _request
* _env

stringhe:
* singolo apice --> non è interpretata
* doppio apice --> interpretata
* \ --> escape

**associativi**

```php
$var = array(
    "key1" -> "value1",
    "key2" -> "value2",
    "key3" -> "value3"
    );
```

**classi**

come in C, i costruttori si chimanao __construct

**funzioni**

parametri passati per valore di default, per riferimento se preceduti con &

**scope delle variabili**

il file stesso

**espressioni regolari**

* . --> qualsiasi carattere
* [] --> classe di caratteri
* ^ --> del set
* {} --> ripetizione
* \* --> 0 o più
* \+ --> 1 o più
* ? --> 0 o 1
