# Tabelle hash

**tabelle ad access diretto**

dato un insieme di chiavi, una tabella ad indirizzamento diretto è un vettore V che fa corrispondere alla chiave k, la cella di indice k che punta alla coppia chiave valore (k,val)

```
ricerca(x)
    return V[x.key]

inserisci(x)
    V[x.key] = x

rimuovi(x)
    V[x.key] = null

```

pro:
* inserimento ricerca e rimozione in O(1):

contro:
* l'universo di chiavi può essere troppo grande
* anche se vengono utilizzate poche chiavi, si spreca lo spazio equivalente ad usarle tutte


**funzione hash**

è una funzione che prende una chiave dall'universo e la mappa ad un valore da 0 a m-1, è definita nel seguente modo:
* h : U -> (0..m-1)

cioè va dall'insieme univero ad un indice di un vettore, se l'universo è un sottoinsime di N, allora si può creare una tabella hash ad indirizzamento diretto con la funzione hash:
* h(k) = k

**funzione hash unforme semplice**

una funzione hash si dice uniforme semplice se una chiave può essere mappata ad ogni valore con la stessa probabilità, ci sono 2 metodi per creare una funzione hash uniforme:
* metodo della divisione --> h(k) = k mod m
* metodo della moltiplicazione --> h(k) = m(k*A mod 1) con 0 < A < 1
* hashing universale

**tabelle ad indirizzamento hash**

dato un insieme di chiavi, una tabella ad indirizzamento hash è un vettore V che fa corrispondere alla chiave k la cella di indice h(k) che punta alla coppia chiave valore (k,val)

**collisioni**

le collisioni tra chiavi si risolvono in 2 modi:
* chaining --> ogni cella punta alla lista di elementi che collidono
* open addressing --> ogni cella contiene un solo elemento, l'inserimento in collisione viene fatto con una seconda funzione h(k,i)

la funzione dell'open addressig è detta di ispezione

**ispezione lineare**

si aggiunge sequenzialmente alla cella di collisione, finchè non trova il primo spazio libero:
* h(k,i) = h(k) + i

causa agglomeramenti, se aggiungi sempre in sequenza aumenta la probabilità di collisiione nella sequenza

**ispezione quadratica**

* h(k,i) = h(k) + Ai + Bi^2 (con A,B costanti)

**doppio hashing**

si calcola un secondo hash per la chiave da inserire e lo si somma alla sua posizione iniziale h1(k), creando una distribuzione uniforme:
* h(k, i) = (h1(k) + i*h2(k)) mod m
