**percettrone**

funzione lineare:
* h(x) = f(tx)

dove:
* x --> parametri di input
* t --> peso dei parametri
* f --> funzione di attivazione

**rete neurale**

funzione composta da percettroni collegati:
* input --> input layer
* parametri --> collegamenti + bias
* output --> output layer
* ipotesi --> hidden layer

definisce
* layer --> # colonne di collegamenti
* livello --> # colonne di neuroni

i collegamenti tra neuroni sono i parametri, forma matriciale:
* t<sup>l</sup></sub>ij</sub>

dove:
* l --> layer in cui si trova
* i --> neurone di partenza
* j --> neurone di arrivo

```
--- rappresentazione matriciale rete neurale

a1  a2  a3  a4
o           o
o   o   o   o
o   o   o   o
o   o   o   o
o           o

a1 = x --> input layer
a2...a3 --> hidden layer
a4 = h(x) --> output layer

```

ipotesi:
* h(a1) = f(z4)

funzione di costo:
* J = -1/m +++ +++ yij*log(h(xi)j) + (1 - h(xi)j)

**rete neurale fully connected**

ogni neurone di un livello è collegato a tutti i neuroni del livello successivo

**funzioni logiche**

modificando i pesi degli input e la soglia di attivazione si possono creare funzioni logiche:
* and --> pesi negativi
* or --> pesi positivi

**classificazione**

una rete neural può classificare in 2 modi:
* multi label --> assegnare più label ad un input
* multi classe --> assegnare una sola classe ad un input 

**one vs one**

classificazione multi classe:

**one vs all**

classificazione multi classe:
* k(k-1)/2 classificatori binari (perceptron)
* ogni perceptron è allenato tra 2 classi
* alla fine si fa una votazione

contro:
* servono tanti nodi

**one hot encoding**

vettore di k bit che mappa una classe per bit

**forward propagation**

processo che calco

**backward propagation**

si calcola l'errore dell'ouput layer rispetto al target:
* d_out = a_out - y

si aggiustano i parametri dei layer precedenti:
* di = ti*d_i+1 * f'(zi)

dove:
* f'(zi) = ai*(1 - ai)

implementazione:
```
for k = 1 to m

    ai = xk

    // forward propagation
    for i = 2 to L 
        compute perceotron


    // backward propagation
    compute d_out
    compute d
```
