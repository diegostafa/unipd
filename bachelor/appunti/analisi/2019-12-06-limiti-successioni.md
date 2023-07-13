### **successione convergente a 0**

una successione si dice convergente a 0 se:
* **lim a<sub>n</sub> -> 0**

cioè:

* ∀ epsilon > 0  ∃  n<sub>0</sub> : ∀ n ≥ n<sub>0</sub>  si ha che  \|a<sub>n</sub>\| ≤ epsilon


si legge: per ogni epsilon maggiore di 0, esiste un n<sub>0</sub> tale per cui: per ogni n maggiore o uguale a n<sub>0</sub> si ha che il valore assoluto della successione è minore di epsilon

<br>
### **successione divergente a + infinito**

una successione si dice divergente a + infinito se:

* **lim a<sub>n</sub> -> +inf**

cioè:

* ∀ M > 0  ∃  n<sub>0</sub> : ∀ n ≥ n<sub>0</sub>  si ha che  a<sub>n</sub> ≥ M

si legge: per ogni 'M' maggiore di 0, esiste un n<sub>0</sub> tale per cui: per ogni n maggiore o uguale a n<sub>0</sub> si ha che la successione è maggiore di 'M'


<br>

### **successione convergente a L**

una successione si dice convergente a L se:

* **lim a<sub>n</sub> - L -> 0**

cioè:

* ∀ epsilon > 0  ∃  n<sub>0</sub> : ∀ n ≥ n<sub>0</sub>  si ha che  \|a<sub>n</sub> - L\| ≤ epsilon

e si indica con **lim a<sub>n</sub> -> L**

si legge: per ogni epsilon maggiore di 0, esiste un n<sub>0</sub> tale per cui: per ogni n maggiore o uguale a n<sub>0</sub> si ha che il valore assoluto della successione meno 'L' è minore di epsilon
<br>

#### **proprietà successioni convergenti/divergenti (1)**

**ipotesi**:
* lim a<sub>n</sub> -> +inf

**tesi**:
* lim 1/(a<sub>n</sub>) -> 0

<br>
#### **proprietà successioni convergenti/divergenti (2)**

**ipotesi**:
* lim a<sub>n</sub> -> 0

**tesi**:
* lim \|(a<sub>n</sub>\| -> 0

<br>
#### **proprietà successioni convergenti/divergenti (3)**
**ipotesi**:
* lim -a<sub>n</sub> -> +inf

**tesi**:
* lim  a<sub>n</sub> -> -inf

<br>

#### **proprietà successioni convergenti/divergenti (4)**
**ipotesi**:
* \|a<sub>n</sub>\| ≤ M
* lim b<sub>n</sub> -> 0

**tesi**:
* lim  a<sub>n</sub> * b<sub>n</sub> -> 0

<br>

#### **Aritmetica dei limiti**

**ipotesi**:
* lim a<sub>n</sub> -> A
* lim b<sub>n</sub> -> B

**tesi**:
* lim  a<sub>n</sub> + b<sub>n</sub> -> A + B
* lim  a<sub>n</sub> - b<sub>n</sub> -> A - B
* lim  a<sub>n</sub> * b<sub>n</sub> -> A * B
* lim  a<sub>n</sub> / b<sub>n</sub> -> A / B

<br>
#### **Criterio del rapporto**

**ipotesi**:
* a<sub>n</sub> ≥ 0
* lim a<sub>n+1</sub> / a<sub>n</sub>  -> L

**tesi**:
* se L > 1 allora lim a<sub>n</sub> -> +inf
* se L < 1 allora lim a<sub>n</sub> -> 0
* L = 1 non da informazioni
