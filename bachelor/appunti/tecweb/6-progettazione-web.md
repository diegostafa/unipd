# Progettazione web

* comportamento --> script
* struttura-contenuto --> html
* presentazione --> css

non si può separare la struttura dal contenuto

progettazione:
* analisi dei requisiti --> individua il target
* base informativa
* servizi
* accessibilità e usabilità
* layout
* strumenti

elementi di architettura
* contenuto --> più importante, servizio e contenuti offerti
* contesto --> immagine del sito
* utenza --> target

elementi variabili:
* lingua
* alfabeto
* direzione di lettura
* valuta
* indirizzi
* ora e data
* misure
* culture
* convenzioni

le bandiere rappresentano il paese non la lingua

## utenti

**sovraccarico cognitivo**

* l'utente si perde nel sito
* troppi cammini e link interni
* non si crea una mappa mentale del sito

**metafora della pesca**

tiro perfetto
* l'utente sa cosa e come cercare
* schema esatto

trappola per aragoste
* l'utente sa cosa cercare ma vuole approfondire
* l'utente impara a raffinare la ricerca
* schema ambiguo, tutorial

pesca con la rete
* l'utenti non sa cosa cercare, ma è interessato ad un argomento generale

boa di segnalazione
* l'utente vuole solo ricordare l'argomento

la risposta viene trovata:
* ricerca
* navigazione
* domande
* iterazione e raffinazione delle precedenti

## information designer

**schemi organizzativi**

schemi esatti:
* l'utente sa quel che cerca
* raggruppamenti alfabetici, cronologici, geografici
* lista di tutte le informazioni

schemi ambigui
* l'utente vuole approfondire un argomento
* raggruppamenti per argomento, utenza, metaforici

schemi ibridi.
* usano entrambi

**strutture organizzative**

struttura a sequenza:
* impone un ordine nelle informazioni
* consigliato per siti semplici

struttura a gerarchia:
* crea una buona mappa del sito e nelle relazione delle informazioni
* bisogna trovare un equilibrio tra profondità e ampiezza
    * max 10 voci nel menu
    * max 7 livelli di specificità

struttura a ipertesto: 
* nessun tipo di struttura logica
* le informazioni sono collegate tra loro da link formando anche sottostrutture gerarchiche
* per utenti esperti

struttura a database:
* l'utente fa le query di ricerca
* si usa per le ricerche

da fare:
* usare gerarchia come base primaria
* usare sequenza per guide
* usare database per le collezioni omogenee
* usare ipertesti per contrornare e aiutare l'utente

## web designer 

il web designer:
* riceve gli schemi dell'information designer
* progetta il layout
* organizza l'informazione

**interfaccia**

uniformità:
* deve essere semplice
* si deve adattare a più dispositivi

consistenza:
* consistenza interna
* comportamento predicibile
* non uscire per completare il task
* no shortcut mmemonici

**area sicura**

pixel di pagina visibili senza scroll

contiene:
* elementi fondamentali (logo, ricerca, menu)

**impaginazione**

schema a 3 pannelli, risponde a:
* dove sono?
    * è la più importante
    * è il titolo della pagina, meglio se breve
* dove posso andare?
    * è il menu
    * deve rispettare le aspettative
    * non troppo grande
* cos'è?
* come ci sono arrivato?
* chi è?
* dove posso approfondire?

schema a schede:
* ogni scheda (interna alla pagina) rappresenta un task diverso

schema LSD:
* logo --> dove sono
* search --> ricerca esatta
* directory --> insieme di categorie
* suddivisione per categorie e sottocategorie

**design**

layout fisso:
* misure assolute
* controllo preciso
* le misure assolute non sono sempre uguali tra dispositivi
* non si adatta a dispositivi diversi

layout fluido
* misure percentuali
* si adatta
* si deforma e perde contesto in schermi troppo diversi
* progettazione complessa che deve tenere conto di tante opzioni

layout ibrido:
* mix fluido fisso

layout elastico:
* le misure dipendono dalle preferenze utente

layout responsive:
* si definiscono intervalli in base ai dispositivi
* ogni intervallo gestisce il proprio layout
* intervalli
    * 320px > 480px > 600px > 768px > 1024px > 1200px 

**layout per mobile**

organizzazione dell'interfaccia:
* menu a destra non a sinistra
* interfacce semplici
* in alto a sinistra i bottoni distruttivi

**prestazioni mobile**

* telefono hanno risorse ridotte
* un unico file css 
* evitare troppo js
* usare i manifest
* poche immagini

**priamide dei bisogni**

il sito deve essere
* accattivante --> deve attrarre
* usabile --> poco aforzo per l'utente
* robusto --> non si deve rompere
* funzionale --> efficace ed efficiente nei contenuti

**emotional design**

* umanizzazione del prodotto
* uso di personalità --> mascotte
* contrasti --> non troppo forti
    * visuali --> colore/aspetto
    * cognitivi
* sorpresa --> rottura di un pattern
* piacere
* anticipazione --> non mostrare tutto
* status --> l'utente è premium
* rewards

**validazione del design**

validare
* la mascotte
* originalità
* bisogni soddisfatti
* linguaggio chiaro e semplice
* usabilità
* feedback utenti
* feedforward --> dare istruzioni