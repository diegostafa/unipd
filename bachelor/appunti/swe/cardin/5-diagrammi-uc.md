**diagrammi uc**

* attore principale--> entità esterna non modificabile che si interfaccia al sistema
* attore secondario --> entità esterna che aiuta l'attore principale nell'UC
* il riquadro contiene casi d'uso
* si associa sempre un id agli uc


uc è definito da:
* nome
* attori primari e secondari
* precondizioni
* postcondizioni
* scenario principali (1 solo)
* estensioni (0 o più)

**extend**

* relazione che indica un UC che estende un'altro UC
* usato per scenari alternativi
* freccia tratteggiata

**generalizzazione**

* stessa rappresentazione diagrammi di classi
* indica un uc che generalizza un altro uc
* SOLO QUANDO GLI UC DERIVATI SONO MUTUALMENTE ESCLUSIVI    
es:
* auth
    * auth di ateneo
    * auth ospite
