# XHTML

regole:
* una sola radice
* tag vanno sempre chiusi
* tag e attributi case sensitive
* l'ordine degli attributi è irrilevante
* i tag devono essere propriamente innestati
* tutti gli attributi devono avere un valore
* valore degli attributi tra apici, doppi o singoli
* il testo in un tag non può essere {<,>,&,'."}
* tag in linea non possono contenere tag di blocco

elementi ignorati:
* interruzioni che non siano <br />
* tabulazioni e spazi multipli
* tag <p> annidati
* tag sconosciuti
* commenti

**struttura xhtml**

```xhtml
<DOCTYPE HTML PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml" />
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="it" lang="it">
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1"/>
        <title>Titolo pagina</title>
    </head>
    <body>
        <p> Contenuto </p>
    </body>
</html>
```

**doctype**

indica il tipo di documento
* indica standard
* indica schema DTD (grammatica utilizzata)

**head**
contiene meta informazioni
* titolo
* meta, 2 tipi
    * http-equiv --> processata come se fosse da un server http, 3 tipi
    * name --> riguardano il documento
* css
* scripts
 
**http-equiv**

* content-type --> indica contentuto e codifica del documento
* refresh --> tempo d'attesa prima che il browser faccia il redirect su un'altra pagina
* expires --> tempo d'attesa prima che la pagina non sia più valida

**name**

* description --> breve descrizione del documento, mostrato nei risultati di ricerca sotto il link
* keywords --> parole chiave usate dai motori di ricerca per categorizzare la pagina
* author --> indica il creatore del documento
* robots --> indica al motore di ricerca come indicizzare la pagina
    * index --> indicizza pagina
    * noindex --> non indicizzare
    * follow --> indicizza pagina e link presenti
    * nofollow --> indicizza pagina
    * all --> indicizza tutto
    * none --> non indicizzare
* rating
* copyright

## attributi

**core**

attributi presenti in ogni elemento
* id
* class
* title --> titolo per gli screen readers
* style

**internazionalizzazione**

* dir --> direzione di lettura
* xml:lang --> lingua del contenuto

**eventi**

eventi js

## tag

**generali**

* div --> blocco
* span --> div in linea
* p --> paragrafo
* hr --> linea orizziontale

**testuali**

* code --> per il codice
* var --> per le variabili
* samp --> per l'output
* pre --> testo preformattato, non vengono ignorati tab e spazi
* ins --> sottolineatura da redazione
* del --> cancallazione da redazione (linea sopra il testo)

**enfatici**

* em
* strong

**intestaizioni**

* h1 .. h6 --> titolo semantico

**citazioni**

* blockquote --> citazione in blocco
* q --> citazione in linea
* cite --> fonte
    * attr. cite --> specifica l'uri
    * attr. title --> fonte, ma come attributo

**acronimi**

* abbr --> abbreviazione
* acronym --> acronimo, obsoleto in html5
* address --> indirizzo, usato da screen readers

**elenchi**

* ul --> non ordinati
* ol --> ordinati
* dl --> elenco di definizioni

**immagini**

ext. consentite: jpg, png, gif

* img --> inseririsce un immagine

attributi:
* alt --> descrizione dell'immagine
* longdesc --> uri che manda alla descrizione
* width/height --> per l'impaginazione

**attributi tastiera**

* accesskey --> keybind per portare il focus all'elemento
* tabindex --> ordine logico di focus

**link**

attributi
* href --> link ipertestuale
* href mailto --> per le mail

**tabelle**

* table --> crea una tabella
* tr --> definisce una riga (non può essere vuota)
* td --> definisce una cella
* th --> definisce il nome della colonna
* thead --> raggruppa le righe che rappresentano l'header
* tfoot --> raggruppa le righe che rappresentano il footer
* tbody --> raggruppa le righe che rappresentano il contenuto

attributi:
* colspan --> numero di colonne occupate da una cella
* rowspan --> numero di righe occupate da una cella
* caption --> titolo della tabella, importante
* summary --> sommario della tabella
* colgroup --> definisce un insieme di colonne
* col --> definisce una colonna


```html
<table>
    <thead>
        <tr>
        </tr>
    </thead>
    <tfoot>
        <tr>
        </tr>
    </tfoot>
    <tbody>
        <tr>
        </tr>
    </tbody>
</table>
```

**form**

* input
    * text
    * password
    * checkbox
    * radio
    * submit
    * reset
    * hidden
    * file
    * button
    * image
* textarea
* fieldset
* legend
* select
* label

attributi
* action --> indica dove inviare i dati del form
* method
    * get
        * limite di lunghezza
        * dati in chiaro
        * poco sicuro
    * post
        * nessun limite
        * si possono mandare file
        * sicuro
* name --> id dell'input
* value --> valore dell'input
* readonly --> non modificabile
* disabled --> non modificabile e inviabile al server
* checked