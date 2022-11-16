### Spazi vettoriali

di base uno spazio vettoriale su campo k è un insieme di vettori a coefficenti su K, tali per cui:
* esiste il vettore nullo
* la somma tra vettori è chiusa all'insieme
* il prodotto di uno scalare per un vettore è chiuso all'insieme

**esempi di spazi vettoriali**

1. **spazi vettoriali su matrici/vettori**
    * R<sup>n</sup> è uno spazio vettoriale di vettori colonna alti n, su campo reale, oppure spazio vettoriale reale
    * R<sub>n</sub> è uno spazio vettoriale di vettori riga lunghi n, su campo reale
    * M<sub>mxn</sub>(R) è uno spazio vettoriale reale di matrici mxn
2. spazi vettoriali su funzioni
3. **spazi vettoriali su polinomi**
    * R\[x\] spazio vettoriale reale di polinomi
    * R<sub>n</sub>\[x\] spazio vettoriale reale di polinomi di grado minore o uguale ad n
4. **spazio vettoriale di un elemento**
    * \{0\}

ogni esempio sopra si può riscrivere con il campo dei complessi e si dirà spazio vettoriale e basta.

---

### Sottospazi vettoriali

sono sottoinsiemi di spazi vettoriali che godono delle stesse proprietà, cioè sono spazi vettoriali

**spazio nullo di una matrice**

data una matrice A, si definisce lo spazio nullo N(A) come sottospazio vettoriale formato da vettori v tale per cui:
* Av = 0

si verifica che è uno spazio vettoriale facendo:
1. contiene il vettore nullo --> in quanto Av = 0 --> v = 0
2. la somma è interna all'insieme --> in quanto A(v1+v2) = 0 --> Av1 + Av2 = 0 --> 0 + 0 = 0
3. il prodotto tra uno scalare è interno all'insieme --> in quanto A(cv) = 0 --> c(Av) = 0 --> c(0) = 0

si dimostra che N(A) == N(U) con U forma ridotta di A

**somma di sottospazi**

dato uno spazio vettoriale V, e due sottospazi U1 e U2, si indica con:
* U1 + U2 la somma dei sottospazi

che significa sommare il generico vettore u1 di U1 con il generico vettore u2 di U2, la somma di 2 sottospazi è sempre un sottospazio

**somma diretta di sottospazi**

dato uno spazio vettoriale V, e due sottospazi U1 e U2, tali per cui:
* U1 intersecato U2 == {0} 

si indica con:
* U1 ⊕ U2 la somma diretta dei sottospazi


---

**Combinazione lineare**

di base un a combinazione lineare è un espressione del tipo:
* a<sub>1</sub>v<sub>1</sub> + a<sub>2</sub>v<sub>2</sub> + a<sub>3</sub>v<sub>3</sub> + ... + a<sub>n</sub>v<sub>n</sub>

**sistemi o insiemi generatori**

dat un spazio V, e un insieme di vettori A=(v1,v2..vn) di V, se per ogni elemento di t di V esiste una combinazione lineare di A che ottiene t, allora A è un sistema generatore di V

proprietà:
* se un insieme C contiene un sistema generatore A, allora C è un sistema generatore
* se un elemento t di un sistema generatore A è ottenibile da una combinazione lineare di altri elementi di A, allora A -{t} è ancora un sistema generatore

se A è un insieme finito si dice che V è **finitamente generabile**

**insieme dei multipli**

è uno spazio vettoriale generato da un solo vettore

---

**Vettori linearmente (in)dipendenti**

dato un insieme di vettori {v1, v2, ...vn}, questi si dicono linearmente indipendenti tra loro se l'unica soluzioni di:
* a<sub>1</sub>v<sub>1</sub> + a<sub>2</sub>v<sub>2</sub> + ... + a<sub>n</sub>v<sub>n</sub> = 0 

è:
* a<sub>1</sub> = a<sub>2</sub> = ... = a<sub>n</sub> = 0

al contrario l'insieme dei vettori è linearmente dipendente se non è linearmente indipendente, cioè se a<sub>1</sub> = a<sub>2</sub> = ... = a<sub>n</sub> = 0 non è l'unica soluzione dell'equazione

proprietà:
* se un insieme C contiene un insieme LD, allora C è LD
* se un insieme C è contenuto in un insime LI, allora C è LI