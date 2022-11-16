### Relazioni di ricorrenza


**relazioni di ricorrenza**

è una formula ricorsiva che esprime l'ennesimo termine della successione atraverso termini precedenti

ad esempio:
* a<sub>n</sub> = a<sub>n-1</sub> + a<sub>n-2</sub>

---

**relazioni lineari omogenee di ordine r**

sono relazioni di ricorrenza, dipendenti solo da gli ultimi n-r termini

cioè:
* a<sub>n</sub> = c<sub>1</sub>a<sub>n-1</sub> + c<sub>2</sub>a<sub>n-2</sub> + ... c<sub>r</sub>a<sub>n-r</sub>

**soluzioni**

per risolvere una relazione di ricorrenza di ordine r:

1. si crea un polinomio in X 
    * coefficenti --> c1, c2 ... cr
    * gradi di X --> n, n-1, n-2 ... n-r
2. si divide tutto il polinomio per X<sup>n-r</sup>

il polinomio ottenuto prende il nome di equazione caratteristica ed ha r soluzioni particolari

la soluzione generale è una combinazione lineare tra tutte le soluzioni, i coefficenti di questa combinazione devono essere ricavati dalle r condizioni iniziali del sistema

di base sostituendo le condizioni iniziali viene fuori un sistema con termini noti == condizioni iniziali 

---

**relazioni lineari non omogenee di ordine r**

sono relazioni di ricorrenza, dipendenti da gli ultimi n-r termini e anche da una funzione di qualsiasi genere

**non omogenee del primo ordine**

sono del tipo:
* a<sub>n</sub> = ca<sub>n-1</sub> + f(n)
* condizione iniziale a<sub>0</sub>

soluzioni:
* se c == 1
    * a<sub>n</sub> = a<sub>0</sub> + f(1) + f(2) + ... f(n)
* se c != 1
    * si cerca la soluzione generale dell'omogenea associata
    * la si somma ad una soluzione particolare della non omogenea

---

**relazioni dividi e conquista**

sono relazioni di ricorrenza, dipendenti dl n/2-esimo termine e anche da una funzione di qualsiasi genere

sono del tipo:
* a<sub>n</sub> = ca<sub>n/2</sub> + f(n)
* condizione iniziale a<sub>0</sub>

soluzioni:
* se c == 1 e f(n) == d
    * a<sub>n</sub> = dLog<sub>2</sub>n + A
* se c == 2 e f(n) == d
    * a<sub>n</sub> = An - d
* se c == 2 e f(n) == dn
    * a<sub>n</sub> = dn(Log<sub>2</sub>n + A)
* se c > 2 e f(n) == d
    * a<sub>n</sub> = An<sup>Log<sub>2</sub>n</sup> + (2d / 2 - c)n

nb: il logaritmo si deve arrotondare per eccesso ad un intero