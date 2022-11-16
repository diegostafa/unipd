## rappresentazione dei numeri
* modulo e segno
* complemento a due
* virgola mobile (numeri reali)


**modulo e segno** → dati n bit consiste nel utilizzare primi n-1 bit per rappresentare il modulo del numero, ed utilizza l'ennesimo (quello più significativo) per determinarne il segno (0 positivo, 1 negativo)


vantaggi
* semplice da implementare
svantaggi
* due rappresentazioni dello 0
* le operazioni aritmetiche richiedono controllo del segno e specifiche operazioni in base a quello

<br/>

**complemento a due** → dati n bit il complemento a due assegna all'ennesimo bit (quello più significativo) un peso negativo, ed ai restanti bit un peso positivo, ciò consente di ottenere i numeri da 0-2^n-1 -1 quando l'ennesimo bit è uguale a 0, e -2^n-1-1 altrimenti

somma (hardware)
* 2 registri A, B in input
* adder restituisce somma + eventuale bit di overflow
sottrazione
* 2 registri A, B
* si complementa a due il sottraendo
* adder restituisce la somma + eventuale bit di overflow

di base la somma si fa normalmente, la differenza di fa come somma del negato.

prodotto --> ritorna 2n bit di risultato
* di base se i segni sono positivi è ok e si usano le somme parziali
* se c'è un segno negativo si può fare il prodotto dei moduli e cambiare il segno in base al prodotto dei segni
* di base non si riesce a meno che non si estendi il segno degli operandi fino a 2n bit (non efficente) oppure si utilizza l'algoritmo di booth


algoritmo di booth--> di base si scrivono gli opernadi in 2n +1 bit, nella parte più significativa (sinistra) e si crea P in 2n +1 bit con il valore del secondo operando nei bit meno significativi.
si fa poi un check degli ultimi 2 bit
- 01 --> P = P + primo operando
- 10 --> P = P + secondo operando
si shifta a destra
cicla per n volte (n = secondo operando)

overflow → può avvenire solo se i due input hanno segno concordo


vantaggi
* unica rappresentazione dello 0
* operazioni aritmetiche analoghe ai numeri senza segno


<br/>

**floating point** → è un formato di bit che trae l'idea dalla notazione scentifica esponenziale, con qualche differenza, consente di rappresentare i numeri reali dati n bit.
i bit di memorizzazione definiscono la densità e l'accuratezza della rappresentazione.


il formato è diviso in 3 campi
* segno
* esponente polarizzato
* mantissa

configurazioni speciali:
* esp tutti 1, mantissa == 0 --> +- infinito
* esp tutti 1, mantissa != 0 --> NaN
* esp == 0, mantissa == 0 --> +- zero


segno → definisce il ±
esponente polarizzato → rappresenta l'esponente del numero + 2^n-1 -1 (lo salva come numero positivo)
mantissa → rappresenta i decimali


aritmetica → analoga alla notazione scientifica, ma richiede un algoritmo ed hardware apposito


somma/sottrazione → bisogna allienare gli esponenti, sommare le mantisse, riallineare gli esponenti, segnalare eventuale overlfow


prodotto → bisogna sommare gli esponenti, moltiplicare le mantisse, segnalare overlfow/underflow

bit di guardia --> è parte dello standard ieee 754, consiste in bit aggiunti durante un calcolo aritmetico in virgola mobile per evitare errori di arrotondamento, operazioni come la sottrazioni di numeri molto vicini tra loro può causare un risultato totalemente inaspettato se i bit a disposizione non garantiscono abbastanza precisione, questi bit servono solo durante la fase di calcolo, è compito dell'elaboratore arrotondare il risultato al formato standard di virgola mobile
