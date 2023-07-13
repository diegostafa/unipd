# Problemi DP

**disposizioni domino (conteggio)**

problema DP:
* tessare 2x1 da far rietrare in un rettangolo 2xn

soluzione:
* DP = 
    * 1 se n = 1
    * DP(n-1) + DP(n-2) se n > 1


**hateville (ottimizzazione)**

probelma DP:
* vettore di numeri
* somma massima che si può ottenere degli elementi sapendo che non se ne possono prendere 2 consecutivi

formalizzazione:
* DP(n) = valore massimo su lunghezza n

soluzione:
* DP(n) = 
    * 0 se n = 0
    * V[1] se n = 1 
    * max(DP(n-1), DP(n-2) + V[n]) se n > 1 

**taglio delle aste**

probelma DP:
* lunghezza di un'asta e vettore di costi
* tagliare l'asta per massimizzare il profitto

formalizzazione:
* DP(n) = valore massimo su lunghezza n

soluzione:
* DP(n) = 
    * 0 se n = 0
    * max(DP(n-k) + C(k)) se n > 1
        * 1 <= k <= n

```
// tabulazione
dp[]
cutrod(n)
    if(dp[n])
        return dp[n]

    dp[0] = 0

    value = -1
    for i da n a 1
        value = max(value, dp(n-i) + C[i])
    dp[n] = value

    return dp[n]

// memoizzazione
dp[]
cutrod(n)
    if(dp[n])
        return dp[n]
    if(n = 0)
        return 0
    else
        value = -1
        for i da 1 a n
            value = max(value, cutrod(n-i) + C[i])
        dp[n] = value
    return dp[n]
```

**zaino (ottimizzazione)**

problema DP:
* insieme di oggetti con peso e profitto
* zaino con capacità n
* trovare il sottoinsieme di oggetti con:
    * peso totale minore della capacità dello zaino
    * profitto massimo

soluzione:
* DP(n,c) = 
    * 0         se n = 0 || c = 0
    * -inf      se c < 0
    * max(DP(n-1, c-w(n)) + p(n), DP(n-1, c)) altrimenti

oppure:
* DP(n,c) = 
    * 0 se n = 0 || c = 0
    * max(DP(n-1, c-w(n)) + p(n), DP(n-1, c)) se w(n) < c
    * DP(n-1, c) se se w(n) > c

**sottosequenza**

P è sottosequenza di T se P è uguale a T meno uno o più elementi, senza scambiare l'ordine degli elementi

**sottosequenza comune**

P è una sottosequenza comune di T e U se P è sottosequenza sia di P che di U

**LCS (sottosequenza comune massimale)**

problema DP:
* trovare la sottosequenza comune tra due stringhe
* T(n) indica i primi n caratteri della stringa T
* t(n) indica il caratter in posizione n della stringa T

soluzione:
* DP(T(n),U(m)) = 
    * t(0) se n = 0 || m = 0
    * DP(T(n-1), U(m-1)) + t se t(n) = u(m)
    * max(DP(T(n), U(m-1)) + DP(T(n), U(m-1))) se t(n) != u(m)

**lunghezza LCS**

problema DP:
* trovare la lunghezza della sottosequenza comune tra due stringhe S e T

soluzione:
* DP(n,m) = 
    * 0 se n = 0 || m = 0
    * DP(n-1, m-1) + 1 se S[n] = T[n]
    * max(DP(n-1, m) + DP(n-1, m)) se S[n] = T[n]

**sottosequenza più lunga**

date 2 parole X,Y consiste nel determinare la sottosequnza S più lunga che appartiene ad entrambe

dimostrazione sottostruttura ottimale:
* se gli ultimi elementi di X,Y sono uguali allora appartengono a S e si eliminano da X,Y e si riesegue da qui
* se sono diversi, allora l'ultimo o di X o Y non appartiene a S, e si riesegue il problema per entrambe le possibilità

**occorrenza k approssimata**

P è un'occorrenzza k approssimata di T se appare in T con al massimo k errori

gli errori possono essere:
* sostituzione --> carattere diverso
* inserimento --> T non contiene il carattere
* cancellazione --> P non contiene il carattere

soluzione:
* DP(n,m) = 
    * 0 se n = 0
    * n se m = 0
    * min(DP(n-1,m-1) + x, DP(n-1,m) + 1, DP(n,m-1) + 1 altrimenti
        * con x = P(n) == T(m) ? 0, 1

**parentesizzazione**

una parentesizzazione P(i,j) di un prodotto da i a j elementi è:
* il primo elemento se i = j
* il prodotto di P(i,k) e P(k+1, j) altrimenti

la parentesizzazione è ottima se richiede il minor numero di moltiplicazioni per essere completata

**parentesizzazione minima tra prodotto di matrici**

problema:
* x matrici compatibili al prodotto

soluzione:
* DP(n,m) =
    * 0 se n = m
    * min(DP(n,k) + DP(k+1, m) + C(k)) se n < m
        * con k da 1 a m
        * con C(k) = c(k-1) * c(k) * c(k+1) // costo moltiplicazione

* dp = costo minimo tra tutte le parentesizzazioni