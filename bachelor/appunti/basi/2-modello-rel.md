## Modello relazionale

il modello relazionale si basa sul modello di relazione matematica

**relazione**

def1nizione di relazione (tabella):
* R(A<sub>1</sub>,...A<sub>n</sub>)

dove:
* R --> tabella
* A --> colonna 

proprietà:
* ordinamento delle tuple non rilevante
* ordinamento degli attributi non rilevante
* ogni tupla è diversa
* ogni attributo è diverso
* i valori di ogni attributi sono definiti su domini specifici
* il riferimento tra diverse relazione è per valore
    * i riferimenti sono rappresentati tramite dei valori che appaiono in entrambe le relazioni

**base di dati**

definizione di schema di base di dati:
+ S = {R<sub>1</sub>(X<sub>1</sub>),...R<sub>n</sub>(X<sub>k</sub>)}

dove:
* S --> schema del database
* R --> tabella
* X --> colonne della tabella

di base lo schema del database è un insieme di tabelle con le relative colonne e dominii delle colonne

**tuple**

le tuple sono le righe di una tabella, sono delle funzioni che per dominio hanno gli attributi della tabella (colonne) e per codominio hanno il dominio degli attributi

**istanza di una relazione**

è l'insieme delle tuple di una relazione

**istanza di una base di dati**

è l'insieme di tutte le istanze di relazioni della base di dati

## Vincoli

**informazione incompleta**

quando un valore è assente in una tabella il dbms insierisce NULL, che è un valore speciale

**vincolo di integrità**

è una funzione booleana sull'istanza della base di dati

di base un vincolo è una condizione imposta su una relazione

i vincoli di intergrita possono essere:
* supportati
    * il dbms si occupa di far rispettare i vincoli e rigetta tuple che non li rispettano
* non supportati
    * il programmatore si occupa lato server che i valori inseriti siano conformi

tipi di vincoli:
* vincoli intrarelazionali
    * vincolo di tupla
        * vincoli di dominio
    * vincolo di chiave
* vincoli interrelazionali
    * vincolo integrità referenziale

**vincoli intrarelazionali**

Fanno parte dei vincoli intrarelazionali tutti quei vincoli il cui soddisfacimento è definito per singole relazioni, ovvero tutte le istanze di una relazione devono soddisfare tutti i vincoli che sono definiti sulla relazione stessa (wikipedia)

**vincoli di tupla**

esprime una condizione sui valori di ogni tupla, coinvolge più attributi, ad esempio:
* il valore nell'attributo lordo deve essere uguale alla somma del valore dell'attributo netto più il valore dell'attributo delle ritenute

**vincoli di dominio**

è un caso particolare di vincolo di tupla, agisce solo sui valori di un attributo

**vincoli di chiave**

il vincolo di chiave su un attributo impone che non ci siano 2 tuple con lo stesso attributo in quell'attributo

**vincolo di integrità referenziale**

di base è la chiave esterna, cioè la chiave esterna di una relazione deve avere i valori di una chiave primaria di un'altra relazione

## Chiavi

**superchiave**

è un qualsiasi gruppo di attributi che identifica univocamente una tupla

definizione formale:
* K = (k1,k2,...,kn)
* se t1 != t2 allora esiste t1\[k\] != t2\[k\] con k appartenente a {k1,k2,..kn}

dove:
* K --> superchiave
* k --> attributo
* t --> tupla

di base vuol dire che se 2 tuple son diverse allora esiste un attributo della superchiave che ha diversi valori nelle 2 tuple

**chiave**

è una superchiave che non contiene attributi superflui

è la più piccola superchiave (quella che utilizza meno attributi)

**chiave primaria**

è una chiave che non ammette valori nulli

**chiave esterna**

sono attributi collegati a chiavi primarie di un'altra tabella (integrità referenziale)

problemi:
* eliminazione di una tupla referenziata da una chiave esterna

soluzioni:
* rifiuto dell'eliminazione
* eliminazione in cascata dei dangling reference
* valori nulli

**viste virtuali**

di base una vista è una tabella ritornata da una query

esempio:
* Afferenza(impiegato, reparto)
* Direzione(reparto, capo)

la vista "Supervisione" è:

select impiegato,capo
from (Afferenza join Direzione) as Supervisione

motivazioni:
* servono schemi esterni per utenti diversi
* consente un sistema di autorizzazioni
* semplifica le query

quando si modifica una vista non sempre si può aggiornare la base di dati correttamente, è garantito solo se la vista è data da un join completo

**viste materiallizzate**

di base una vista materializzata è una vista che viene salvata su disco

vantaggi:
* disponibilità immediate per future query

svantaggi:
* ridondanza
* consistenza dei dati
* raramente supportate dai dbms