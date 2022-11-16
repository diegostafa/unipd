# AMPL

## .mod

**commenti**

```
# commento
```

**variabili**

```
var x >= inf <= sup tipo;
```

**funzione obiettivo**

```
maximize nomefunzione: espressione;
```

**vincoli**

```
s.t. nomevincolo: disequazione;
s.t. nomevincolo: disequazione;
s.t. nomevincolo: disequazione;
```

## .run

**pulisici**

```
reset;
```

**scelta del solver**

```
option solver nomesolver;
```

**scelta del modello**

```
model file.mod;
```

**risolvi il modello**

```
solve;
```

**visualizzazione**

```
display var1, var2;
```

## .dat