# Algebra relazionale

L'algebra relazionale è un linguaggio matematico di query, ha 6 operatori di base e diversi operatori derivati

nomencaltura:
* R --> relazione
* a --> attributo
* θ --> condizione

operatori primitivi:
* binari
    * unione --> R<sub>1</sub> ∪ R<sub>2</sub>
    * differenza --> R<sub>1</sub> − R<sub>2</sub>
    * prodotto cartesiano --> R<sub>1</sub> × R<sub>2</sub>
* unari
    * selezione --> σ<sub>θ</sub>(R)
    * proiezione --> Π<sub>a<sub>1</sub>,a<sub>2</sub>...</sub>(R)
    * ridenominazione --> ρ<sub>a new / a old</sub>(R)

operatori derivati:
* intersezione --> R<sub>1</sub> ∩ R<sub>2</sub>
* divisione --> R<sub>1</sub> ÷ R<sub>2</sub>
* joins
    * inner
        * natural --> R<sub>1</sub> ⋈ R<sub>2</sub> (aka join)
        * equi --> R<sub>1</sub> ⋈<sub>a<sub>1</sub>=a<sub>2</sub></sub> R<sub>2</sub>
        * theta --> R<sub>1</sub> ⋈<sub>θ</sub> R<sub>2</sub>
    * outer    
        * left --> R<sub>1</sub> ⟕ R<sub>2</sub>
        * right --> R<sub>1</sub> ⟖ R<sub>2</sub>
        * full --> R<sub>1</sub> ⟗ R<sub>2</sub>

## Operatori primitivi

### Binari

questi operatori sono ricavati dalle normali operazioni insiemistiche

**unione**

ritorna una relazione che contiene le tuple appartenenti ad entrambe le relazioni, senza ripetizioni

**differenza**

ritorna una relazione che contiene le tuple della prima relazione che non appartengono alla seconda

**prodotto cartesiano**

ritorna una relazione che contiene il prodotto cartesiano delle tuple delle 2 relazioni, il prodotto cartesiano delle relazioni di base è un grafo bipartito completo, ogni tupla connette con tutte le tuple dell'altra relazione

### Unari

**selezione**

ritorna una relazione che contiene le tuple che rispettano una determinata condizione sugli attributi

**proiezione**

ritorna una relazione con solo gli attributi specificati, rimuove le ripetizioni

**ridenominazione**

ritorna una relazione con attributi di nome diverso

## Operatori derivati

**intersezione**

ritorna una relazione che contiene le tuple in comune ad entrambe le relazione, si ricava come !(A-B)

### Inner joins

**natural join**

fa il prodotto cartesiano e seleziona le tuple che hanno 2 attributi specificati uguali

numero di tuple finali:
* 0 (join vuoto) <= R1 join R2 <= R1 x R2 (join completo)

**equi-join**

è il theta join che usa l'operatore di uguaglianza nella condizione

**theta-join**

fa il prodotto cartesiano e seleziona le tuple che rispettano una condizione theta

### Outer joins

**left join**

è l'inner join, ma se una tupla della prima relazione non matcha viene inserita comunque

**right join**

è l'inner join, ma se una tupla della seconda relazione non matcha viene inserita comunque

**full join**

è l'unione del left e right join

**semi join**

(fatto in classe) fa un normale inner join, ma proietta solo gli attributi della prima tabella

**gestione dei valori nulli**

per rifersi ai valori nulli in una selezione si utilizzano le condizioni:
* is null
* is not null