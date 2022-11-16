### Sistemi lineari

dato un sistema lineare formato dalle seguenti equazioni:
- a<sub>11</sub>x<sub>1</sub> + a<sub>12</sub>x<sub>2</sub> + ... + a<sub>1n</sub>x<sub>n</sub> = b<sub>1</sub>
- a<sub>21</sub>x<sub>1</sub> + a<sub>22</sub>x<sub>2</sub> + ... + a<sub>2n</sub>x<sub>n</sub> = b<sub>2</sub>
    .
    .
    .
- a<sub>m1</sub>x<sub>1</sub> + a<sub>m2</sub>x<sub>2</sub> + ... + a<sub>mn</sub>x<sub>n</sub> = b<sub>m</sub>

**Scrittura matriciale del sistema**

la scrittura matriciale del sistema si ottiene impostando:
* si usa A<sub>nm</sub> per indicare la matrice dei coefficenti del sistema
* si usa b<sub>m</sub> (underscore) per indicare il vettore colonna dei termini noti del sistema
* si usa x<sub>n</sub> (underscore) per indicare il vettore colonna delle incognite del sistema

da cui:
* Ax = b si chiama **scrittura matriciale del sistema**
* \[A \| b\] (A affiancata a b) si chiama **matrice aumentata del sistema**

operazioni che **non** modificano le soluzioni di un sistema:
* sommare ad un equazione un'altra moltiplicata per uno scalare c
* moltiplicare un equazione per uno scalare c
* scambiare 2 equazione

che guardacaso sono le stesse operazione elementari di gauss, perciò forma ridotta e matrice oriinale hanno le stesse soluzioni

---

**risoluzione di sistemi lineari**

1. scrivere la matrice aumentata \[A \| b\]
2. trovare la forma ridotta \[U \| d\] della matrice aumentata
    * se d è una colonna dominante allora non ha soluzioni (eq. tipo 0=1)
    * se d è una colonna libera allora ci sono soluzioni
        * se U ha solo colonne dominanti allora c'è una sola soluzione
        * se U ha k colonne libere allora il sistema ha infinito alla k soluzioni
3. si risolve il sistema isolando le variabili che corrispondono alle colonne dominanti
4. le soluzioni vengono scritte in un vettore colonna v delle soluzioni