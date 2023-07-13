# Sicurezza

basi:
* informazioni da trasmettere --> P
* il mittente cripta il messaggio, il destinatario lo decripta
* funzione di criptaggio E
* funzione di deriptaggio D

**principio di kerckhoff**

un algoritmo di crittografia deve essere pubblico, le chiavi devono essere private

quindi E e D sono funzioni parametrizzate dalla chivi segrete

security by obscurity --> fallimentare, bisogna proteggere anche l'algoritmo

**cypher e codes**

indica il livello di granularità di crittaggio:
* cypher --> sostituzione per carattere (es. cifrario di cesare, sposta lettere di 3)
* code --> sostituzione per parola (es. parlare in lingua straniera)

**monoalphabetic substitution**

è la generalizzazione del cifraio di cesare, troppo semplice da decriptare

**one-time pad**

* si prende il plain text
* si prende una chiave causale di lunghezza plain text
* si fa lo XOR tra chiave e plain text
* il destinatario da lo XOR con la stessa chiave
* sicuro 100%

contro:
* chiave lunga quanto il messaggio
* chiave completamente casuale
* la chiave si può usare una volta sola

**block cipher**

sono una famiglia di cifrari detti a blocchi:
* si crea una chiave limitata
* si spezza il messaggio in blocchi
* si cripta ogni blocco con la chiave

il criptaggo è fatto con:
* p-box --> fanno una permutazione del blocco
* s-box --> si sostituiscono certi bit del blocco

queste operazioni vengono fatte casualmente con la chiave

**DES**

è un cifrario a blocchi:
* 64 bit di blocchi
* 56 bit di chiave --> così riescono a decifrarlo

proprietà:
* la funzione di decritaggio è opposta a quella di crittaggio:
    * E(D(P)) == D(E(P))

**triple DES**

evoluzione del DES:
* 64 bit blocchi
* 2 chiavi da 56 bit
* si applica 3 volte --> E<sub>k1</sub> - D<sub>k2</sub> - E<sub>k1</sub>

proprietà:
* 2 chiavi danno retrocompatibilità con il DES usando una stessa chiave

**AES**

è un cifrario a blocchi:
* chiavi a 128 e 256 bit

**RSA**

è un cifrario a blocchi con chiave asimmetrica, 


**attacco ECB**

è un attacco ai ciphrer blocks che scambia dei blocchi, rende impossibile il decrittaggio, si risolve con lo stream cipher

**stream cipher**

si un numero casuale e si critta N volte, si fa il one time pad del messaggio crittato finale con questo stream cipher

pro:
* risolve ECB

contro:
* IV dev'essere sempre diverso

**attacco DoS**

chi attacca supera le risorse di chi riceve

**attacco SYN**

si fa un flood di richieste SYN senza poi rispondere, il server tiene aperta la connessione finchè non riceve risosta

**IP spoofing**

siccome l'IP non ha nessun controllo, si sostituisce l'ip di mittente con un altro ip

**WEP**

utilizza un cifrario a blocchi con chiave simmetrica a 40 bit, usa lo stream cipher lungo 24 bit

problemi:
* iv 24 bit implica che dopo 2^24 stream cipher non si può più creare IV nuovi

**WPA**

utilizza codifica RC4, la chiave inserita come passphrase è facile da decrittare

**WPA2**

usa AES con lo stream cipher