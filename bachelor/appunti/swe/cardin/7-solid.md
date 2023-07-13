ogni principio non può essere esaminato su una classe sola, ma deve essere analizzata in contesto di tutte le dipendenze che ha


**SRP - single responsability principle**

* l'insieme di metodi usati da altre classi sono uguali
* la classe deve avere un solo asse di cambiamento
    * si possono partizionare i metodi sulla base di chi utilizza, un asse corrisponde al numero di èartizioni

```java
class rectangle{
    public area(){}
    public draw(){}
    public vertex(){}
}

class gui{
    private rectangle r;
    // usa r.draw()
}

class compute{
    private rectangle r;
    // usa r.area() e r.vertex()
}

class altro
/*
ci sono 2 assi di cambiamento:
- gui con {draw}
- compute con {area, vertex}
soluzione --> 2 classi con le partizioni individuate

se gui e compute usassero tutti i metodi allora l'asse di cambiamento sarebbe uno solo 

rectangle non soddisfa il principio perchè una sua modifica produce modifiche in 2 altre classi
*/
```

se una classe non rispetta l'SRP la si può risolvere in 2 modi:
* per associazione --> si spezza la classe in 2 classi e si uniscono per associazione
* si creano 2 interfacce 

**OCP - open close principle**

una classe rispetta OCP se aggiungere funzionalità non va a modificare le cose vecchie

se non la rispetta di solito si usa il polimorfismo per rendere tutto il più malleabile possibile

da evitare
* variabili globali
* membri pubblici
* polimorfismo fatto male

**LSP - liskov substitution principle**

ogni sottotipo deve poter essere usato come suo supertipo senza generare alcun problema, cioè:
* le precondizioni delle derivate non devono essere più forti delle basi
    * il client deve solo preoccuparsi delle basi
* le postcondizioni delle derivate devono essere più forti delle basi
    * le derivate devono mantenere le postcondizioni delle basi, ma possono anche aggiungerne di loro

```java
public void roba(supertipo s){
    // chiama s.foo()
}

// quando passo un sottootipo a roba() non deve rompere s.foo() 
```

se non si rispetta LSP non si rispetta OCP

**dependency inversion principle**

classi astratte non devono dipendere da classi concrete

per risolvere una dipendenza concreta si inseriscono interfacce nel mezzo
```
// schif
astratta --> concreta

// nice
astratta --> interfaccia <-- concreta
```
