
### Ricorsione

consiste nel richimare una funzione dentro se stessa fino ad un caso base

un funzione ricorsvia è formata da:
* andata --> istruzioni eseguite prima della chimata ricorsiva
* ritorno --> istruzioni eseguite dopo la chimaata ricorsiva
    * se il ritorno è nullo allora la funzione si dice ricorsiva terminale

**correttezza ricorsiva**

```c++
/// pre condizione
void f(parametri_formali)
{
    // codice

    /// pre ricorsiva
    f(parametri_attuali)
    /// post ricorsiva
     
    // codice
}
/// post condizione
```

la correttezza della funzione si dimostra per induzione:

1. caso base
    * si assume la PRE vera
    * si osserva il caso base
    * si dimostra che ciò rispetta la POST
2. caso ricorsivo
    * si assume la PRE vera
    * si dimostra che i parametri attuali soddisfano la PRE ricorsiva
    * si assume che la POST ricorsiva sia vera 
    * si assume che altra PRE e POST ricorsive siano vere (passo induttivo)
    * si dimostra che ciò rispetta la POST

**funzioni ricorsive terminali**

sono funzioni le quali dopo la chiamata ricorsiva non hanno istruzioni

funzioni ricorsive terminali sono facili da tradurre in dei cicli iterativi

**relazione tra ricorsione e iterazione**

di base solitamente un ciclo iterativo aggiorna le sue variabili ad ogni iterazione, fino all'uscita del ciclo, mentre una funzione ricorsiva non aggiorna le sue variabili, ma ne crea di nuove ad ogni chiamata ricorsiva


```c++
while(a!=0)
{
    a++; // incrementa la stessa variabile 10 volte
}

void f(int a=10)
{
    if(a!=0)
        f(a+1) // crea 10 volte la stessa variabile incrementata
}
```

corrispondenze cicli-ricorsione:
* il caso base corrisponde alla condizione del ciclo
* l'andata della funzione corrisponde al corpo del ciclo
* la chiamata ricorsiva corrisponde alla modifica delle variabili del ciclo

il ritorno di una funzione non ha corrispondenza in un ciclo, quindi convertirla diventa difficile

di base il ritorno della funzione consiste nel fare un ciclo al contrario ma con altre istruzioni

per simulare il ritorno si usa una struttura ausiliaria (una pila) che serve da stack, servono almeno 2 cicli