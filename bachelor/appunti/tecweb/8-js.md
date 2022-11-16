# Javascript

caratteristiche:
* orientato agli eventi
* tipizzazione dinamica
* non supporta ereditarietà
* per creare documenti dinamici
* non supporta il networking e IO
* DOM --> rappresenta il documento con un oggetto
* in caso di errore si blocca, non è come html

scripring non intrusivo:
* miglira usabilità
* gestione errori
* migliora accessibilità
* separazione struttura comportamento

posizione script:
* head --> funzioni usate più volte
* body --> interpretabile una sola volta, ma si possno richiamare le funzioni (non usarlo così)


**tipi**

* number
* string
* boolean
* undefined
* null
* nan

**oggetti**

```
var a = new Object() // creazione
a.prop1 = "p1" // aggiunta di proprietà
```

**associativi**

```
arr = new Array()
arr["key1"] = "val1"
arr["key2"] = "val2"
arr["key3"] = "val3"

// oppure

arr = {
    "key1":"val1",
    "key2":"val2",
    "key3":"val3"
}
```

**BOM**

browser object model, non è uno standard:
* browser --> navigator
* finstra --> window
* frame --> window.frame
* barra indirizzi --> location
* barra di stato --> status

ha funzioni per aprire finestre popup e altre cose per il browser


**DOM**

tratta il documento, come un oggetto, ogni tag è un nodo, ha diverse funzioni per interagirci

**eventi**

si specificano funzioni che si attivano quando si verifica un evento

eventdelegation:
* pattern di gestione DOM
* si inserisice l'evento nel padre
* quando si clicca sul figlio viene ritornato il figlio ed eseguito l'evento su di lui
    * non si riscrive lo stesso evento su tutti i figli
    * ma c'è più overhead


**cookie**

file salvati lato client per salvare uno stato, sono formati da:
* nome
* valore
* scadenza

**localstorage**

associativo per salvare dati lato client e tra sessioni

**ajax (asynchronous javascript and xml)**

* comunicazione con il server asincrona

es:
* xmlhttpl.open("metodo", "file php")

**jquery**

* selettore di html e css