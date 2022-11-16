## tipi

**c++ datatypes**

i tipi offerti dal c++ sono:
* primitivi
    * integer
        * int
        * char
    * floating
        * float
        * double
    * void
* derivati
    * array
    * pointer
    * reference
* user defined
    * struct
    * union
    * class
    * enum

**conversioni di tipo**

si possono definire in:
* implicite
* esplicite

oppure in:
* predefinite
* definte dall'utente

oppure ancora:
* con perdita di informazione
* senza perdita di informazione

**conversioni implicite**

sono le conversioni automatiche offerte dal c++, oppure quelle definite tramite i costruttori di copia

conversioni safe tra tipi (anche definiti da utente):
* tipo& --> tipo
* tipo[] --> tipo*
* tipo* --> void* (è un puntatore generico)
* tipo --> const tipo
* cost primitivo --> primitivo
* tipo --> const tipo*
* tipo --> const tipo&

conversioni safe di c++:
* bool --> int
* float --> double
* char --> short int --> int --> long
* unsigned char --> unsigned int --> unsigned long

per le conversioni non safe si usano i cast espliciti

**conversioni esplicite**

sono le conversioni effetuate tramite i seguenti operatori:
* static_cast
* dynamic_cast
* const_cast
* reinterpret_cast

**static cast**

si usa nelle conversioni dove si perde informazione (double --> int) oppure nelle conversioni safe per sottolineare la conversione

sintassi:
* static_cast<t>(obj)

**const cast**

di base serve a togliere il const a ciò che si punta/riferisce

sintassi:
* const_cast<t>(puntatore/riferimento)

**reinterpret cast**

va a reinterpretare il dato senza nessuna conversione

* sintassi:
* reinterpret_cast<t*>(puntatore)
