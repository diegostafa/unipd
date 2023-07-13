**NLP - natural language processing**

obiettivo:
* comprendere i linguaggi naturali
* acquisizione della conoscenza
* comunicazione con gli umani

tipi:
* named entity processing --> identificare le parti rilevanti di un testo
* machine translation --> tradurre un testo
* question answering --> comunicazione uomo - macchina in linguaggio naturale

applicazioni:
* spellchecking
* scraper
* classificatori
é traduttori
* chatbot
* ...


**linguaggio naturale**

* sistema che costruisce un segnale al ine di convogliare un meesaaggio
* definito da un'insieme discreto di simboli
* molto ambiguo


***livelli NLP**

1. tokenization
2. analisi morfologica --> declinazioni
3. analisi sintattica
4. analisi semantica
5. comprensione ompleta del messagio

**task NLP**

1. named entity recognition --> classificazione delle entità in una frase
* entity mention detection --> classificazione delle parole che si riferiscono a delle entità
* relation extraction --> determina le associazioni tra entità
* coreference resolution -->


**language model**

modello che predice la distribuzione di parole in un linguaggio, invece di predire la la classe di una parola predice la probabilità di occrrenza

**n-gram**

di base definisce la probabilità di rilevare una sequenza di caratteri in un testo

tipi:
* unigram
* bigram
* trigram
* ...

* P(Ci|n) --> probabilità che si presenti una sequenza C1C2..Cn

**modello ngram**

usa il concetto di catena di markov, in cui la probabilità di un carattere dipende solo da quelli precedenti

**applicazioi n-gram**

* identificazione del linguaggio --> P(testo|linguaggio), cioè calcola l'ngram più frequente del testo in un linguaggio
* predizione del testo --> 

**chain rule**

la probabilità che appia una serie di parole + uguale al prodotto delle proobabilitò di un parola data le sue precedenti

**word vector**

