### **Limitatezza di una successione**

**ipotesi**:
* lim a<sub>n</sub> -> L ∀ n ≥ n<sub>0</sub>

**tesi**:
* a<sub>n</sub> è una successione limitata

**dimostrazione**
1. si scrive la definizione di limite che tende a L
2. ∀ n ≥ n<sub>0</sub> la successione è limitata per definizione del limite
3. ∀ n < n<sub>0</sub> la successione è limitata perchè ha un numero finito di elementi
4. a<sub>n</sub> è limitata perchè è l'unione di due insiemi limitati
<br>


### **Teorema dell'unicità del limite**

**ipotesi**:
* lim a<sub>n</sub> -> L ∀ n ≥ n<sub>0</sub>

**tesi**:
* L è unico

**dimostrazione per assurdo**
1. si scrive la definizione di limite per L<sub>1</sub>
2. si scrive la definizione di limite per L<sub>2</sub>
3. si impone un n<sub>0</sub> a partire dal quale 1) e 2) sono verificate
4. si usa la disuguaglianza triangolare
5. si arriva a 0 ≤ \|L<sub>1</sub> - L<sub>2</sub>\| ≤ epsilon
6. si arriva ad L<sub>1</sub> - L<sub>2</sub> = 0
7. assurdo dimostrato

<br>
#### **Teorema della permanenza del segno**

**ipotesi**:
* lim a<sub>n</sub> -> L ∀ n ≥ n<sub>0</sub>

**tesi**:
1. se L > 0 allora a<sub>n</sub> ≥ 0 ∀ n ≥ n<sub>0</sub>
2. se L < 0 allora a<sub>n</sub> ≤ 0 ∀ n ≥ n<sub>0</sub>
3. in generale se L diverso da 0 allora \|a<sub>n</sub>\| > \|L/2\|0 ∀ n ≥ n<sub>0</sub>

**dimostrazione 1)**
1. si scrive la definizione di lim a<sub>n</sub> -> L, cioè: \|a<sub>n</sub> - L\| ≤ epsilon
2. si sceglie epsilon uguale a L/2 e si ha si ha \|a<sub>n</sub>\| ≤ L/2
3. si scrive il valore assoluto come intervallo
4. si porta L fuori dal valore assoluto
5. si ha in particolare che L/2 ≤ a<sub>n</sub>

**dimostrazione 2)**
uguale alla 1) solo che si scegli epsilon uguale a -L/2

**dimostrazione 3)**
è solo l'unione dei casi precedenti

<br>
#### **Teorema dei due carabinieri**

**ipotesi**:
* a<sub>n</sub> ≤ c<sub>n</sub> ≤ b<sub>n</sub>
* lim a<sub>n</sub> = lim a<sub>n</sub> = L

**tesi**:
* lim a<sub>n</sub> = L

**dimostrazione**
1. si scrive la definizione di lim a<sub>n</sub> = L
2. si scrive la definizione di lim b<sub>n</sub> = L
3. si impone un n<sub>0</sub> a partire dal quale 1) e 2) sono verificate
4. si ha che L - epsilon ≤ a<sub>n</sub> ≤ L + epsilon
5. si ha anche che L - epsilon ≤ b<sub>n</sub> ≤ L + epsilon
5. dall'ipotesi L - epsilon ≤ a<sub>n</sub> ≤ c<sub>n</sub> ≤ b<sub>n</sub> ≤ L + epsilon
6. quindi in particolare L - epsilon ≤ c<sub>n</sub> ≤ L + epsilon

NB: l'immagine sopra ha lettere scambiate ma esprime lo stesso concetto
