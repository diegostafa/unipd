## Introduzione agli ADT

**namespace**

di base un namespace è una keyword che definisce uno scope dei nomi

sintassi:
* namespace *nome_namespace* { ... }

operatore:
* *nome_namespace*::*nome_interno* 

**alias di namespace**

definisce un nome alternativo per un namespace

sintassi:
* namespace *alias* = *nome_namespace*

**using**

di base il using rimuove il namespace (*fa uscire i buoi dal recinot*)  

sintassi:
* using namespace *nome_namespace*

consente anche di far uscire buoi particolari 

sintassi:
* using *nome_namespace*::*nome_interno*

dopo questa dichiarazione d'uso "nome_interno" non necessita di essere specificato dal namespace

**Tipi di dato astratto (ADT)**

l'ADT è un tipo di dato le cui istanze vengono modificate solo tramite la semantica (significato) del tipo e non dalla loro implementazione

un ADT viene definito definito da:
* interfaccia (accessibile) --> le operazione di manipolazione che il dato fornisce
* implementazione (inaccessibile) --> come le informazioni di stato vengono gestite

la struct non è un ADT in quanto la rappresentazione del dato è completamente pubblica e manipolabile, il tipo int invece lo è in quanto la sua implementazione è privata

**problema struct**

```
// 1) bad, è come creare un int specificando la posizione dei bit a 1
complesso c1 = {a,b}
complesso c2 = {c,d}
complesso c3
c3.re = c1.re + c2.re // è come fare la somma di 2 int con il metodo del complemento a 2
c3.im = c1.im + c2.im 

// 2) good, si lascia l'implementazione dei dati e delle operazioni al ripo di dato
complesso c1 = init(a,b)
complesso c2 = init(c,d)
complesso c3 = sum(c1,c2)
```