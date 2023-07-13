# Programmazione dinamica

permette di risolvere la classe di problemi con:
* sottostruttura ottima
* sovrapposizione di sottoproblemi

tipi di problemi DP:
* ottimizzazione
* conteggio

l'implementazione si può fare in 2 modi:
* ricorsione+memoizzazione (top-down)
    * usato quando non bisogna risolvere tutti i sottoproblemi
* iterazione+tabulazione (bottom-up)
    * usato quando bisogna risolvere tutti i sottoproblemi

**sottostruttura ottima**

un problema possiede una sottostruttura ottimale se è possibile costruire efficientemente una soluzione ottimale a partire dalle soluzioni ottimali dei suoi sottoproblemi
di base significa che si può costruire la soluzione del problema usando le soluzioni dei suoi sottoproblemi

**sovrapposizione di sottoproblemi**

un problema ha una sovrapposizione di sottoproblemi se lo stesso sottoproblema deve essere risolto più volte

**memoization (annotazione)**

è l'approccio ricorsivo, ricorsivamente arriva alle foglie (casi base), le risolve e ne salva i risultati
```
dp[]
funzione(param)
    if dp[param]
        return dp[param]

    if caso base
        return <caso base>
    
    else
        dp[param] = <parte ricorsiva>
    
    return dp[param]
```

**tabulazione**

è l'approccio iterativo, risolve tutti i sottoproblemi più piccoli fino ad arrivare alla soluzione del problema iniziale
```
dp[]
funzione(param)
    if dp[param]
        return dp[param]
    
    for <condizione caso base>
        // setta dp con i casi base
    
    for <condizione caso ricorsivo>
        // setta dp con la formula ricorsiva
    
    return dp[param]
```

**formalizzazione del problema DP**

per risolveresjsj un problema DP:
* decidere lo stato ed i suoi parametri
* formulare la relazione tra stati