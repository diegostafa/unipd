# HTML5

differenza con xhtml:
* chiusura dei tag non obbligatoria
* non è case sensitive
* gestione degli errori
* canvas --> non usa il DOM
* supporto audio video
* interazione api
* api geolocation
* api DB
* multithreading javascript
* pagine modificabili
* supporto offline

tag semantici:
* section --> contenuti separati ma logicamente collegati
* article --> contenuti separati
* header --> intestazione
* footer --> piè di pagina
* nav --> navigazione
* aside --> sidebar, può essere rimosso senza far perdere significato alla pagina
* figure --> figura
    * figcaption --> descrizione
* mark --> evidenzia
* time --> data ora
* meter --> misura
* progress --> barra di progresione
* small --> piccola nota

**cookies**

oltre ai cookies:
* web storage --> html5 offre gli associativi sessionStorage e localStorage
* web sql DB
* indexedDB 

**cache manifest**

file contenente le seguenti sezioni:
* cache --> pagine che vengono salvate in locale
* network --> pagine non accessibili offline
* fallback --> pagine da visualizzare offline quando si accede a pagine in network

.manifest
```
CACHE MANIFEST

CACHE:
xxx.html
xxx.html

network:
yyy.php

fallback:
zzz.html
```