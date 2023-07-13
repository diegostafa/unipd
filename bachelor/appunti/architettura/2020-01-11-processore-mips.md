## **Caratteristiche tecniche:**
* architettura RISC
* istruzione a lunghezza fissa di 32 bit
* 32 registri general purpose ($0-$31)
* 32 registri per i floating point ($f0-$f31)
* operazioni solo su registri (ad eccezzione di load e store)
* cache dati e istruzioni separate
* no microcodice

## **Registri**

**registri speciali**

* PC --> program counter --> contiene l'indirizzo dell'istruzione successiva
* IR --> instruction register --> contiene l'sitruzione corrente
* A --> contiene il primo operando in un R/I instruction
* B --> contiene il secondo operando in un R/I instruction
* IMM --> contine il valore immediato di una I/J instruction
* LO --> in moltiplicazione salva i 32 bit meno significativi
* HI --> in moltiplicazione salva i 32 bit più significativi

**registri general purpose**

* $0 --> contiene sempre 0 (hardcodato read-only) usato per indirizzamento diretto
* $1 (o $at) --> registro riservato al compilatore
* $2, $3 (o $v0, $v1) --> registri per i valori di ritorno
* $4 ... $7 --> registri usati per passaggio di argomenti a funzioni
* $8 ... $15 --> registri temporanei
* $16 ... $23 --> registri che si preservano alla chiamata di funzione
* $24, $25 --> registri temporanei
* $26, $27 --> riservati al kernel per gli interrupt
* $28 --> global pointer --> punta all'area dati globale
* $29 --> stack pointer
* $30 --> frame pointer
* $31 --> return address --> contiene l'indirizzo di ritorno quando si chiama una funzione per riprendere l'esecuzione del programma normalmente


## **Tipi di indirizzamento consentiti**
* immediato --> l'operando è contenuto nell'istruzione
* a spiazzamento --> indirizzo memoria + offset specificato
* diretto --> indirizzo di memoria + offset specificato=0
* indiretto --> indirizzo di memoria=0 + offset specificato

## **Tipi di istruzione MIPS**

**Istruzione di tipo R (register)**

utilizzate per operazioni aritmetico-logiche, formato macchina:

OPCODE \| RS \| RT \| RD \| SHAMT \| FUNCT

* OPCODE (6 bit)  --> specifica l'operazione da eseguire
* RS     (5 bit)  --> registro che contiene il primo operando
* RT     (5 bit)  --> registro che contiene il secondo operando
* RD     (5 bit)  --> registro che contiene l'operando destinazione
* SHAMT  (5 bit)  --> specifica di quanto fare lo shift in un operazione di shift (efftutato su RS)
* FUNCT  (6 bit)  --> specifica l'operazione dell'opcode quando c'è ambiguità (non c'è sempre corrispondenza 1 a 1 tra macchina e assembly)

il formato delle istruzioni macchina NON determina il formato delle istruzioni assembly.

formato istruzione assembly:

OPCODE RD, RS, RT

in ogni caso l'operazione compiuta è: **RD = RS opcode RT**

esempio:
add $3, $4, $5  --> RD=$3, RS=$4, RT=$5  --> $3 = $4 + $5

<br>

**Istruzione di tipo I (Immediate)**

utilizzate per operazioni in memoria store/load e aritmetico-immediato, formato macchina:

OPCODE \| RS \| RT \| IMM

* OPCODE (6 bit)  --> specifica l'operazione da eseguire (tutte univoche, non c'è FUNCT)
* RS     (5 bit)  --> source, specifica un operando oppure uno spiazzamento
* RT     (5 bit)  --> target, specifica l'operando destinazione oppure il target delle operazioni di memoria
* IMM    (16 bit) --> specifica un numero o un indirizzo di memoria

come prima, il formato assembly differisce da quello macchina:

operazione aritmetico-immediato:

OPCODE RT, RS, IMM

esempio:
addi $3, $4, 117   --> RT=$3, RS=$4, IMM=117 --> $3 = $4 + 117

operazione in memoria:
OPCODE RT, IMM(RS)

esempio:
sw $5, 0x000E($8)  --> RT=$5, RS=$8, IMM=0x000E --> $5 = MEM[0x000E + $8]

**Istruzione di tipo J (Jump)**

utilizzate per operazioni di salto, formato macchina:

OPCODE \| IMM

* OPCODE (6 bit)  --> specifica l'operazione da eseguire (tutte univoche, non c'è FUNCT)
* IMM    (26 bit) --> specifica un indirizzo di memoria

siccome di 26 bit, IMM non può indirizzare tutti gli indirizzi di memoria (2^32), essendo le istruzioni per definizione dell'architettura misp di 4 byte, queste inizieranno quindi in locazioni di memoria divisibili per 4, perciò si fa uno shift di 2 bit sull'IMM per accedere quindi alla 2^28esima locazione di memoria.

## **Pipeline**

<br/>

**IF (instruction fetch)**

di base la fase di fetch consiste nel prelevare l'istruzione dalla memoria, salvarla nell'instruction register e segnarsi l'indirizzo dell'istruzione successiva in un registro temporaneo.

* IF/ID.IR = MEM[PC];
* IF/ID.NPC = PC + 4;

* IR --> instruction register
* MEM --> memoria istruzioni
* PC --> program counter
* NPC --> next program counter

NB: non si incrementa direttamente il program counter poichè bisogna prima sapere se l'istruzione è di jump o no

<br/>

**ID (instruction decode)**

la control unit accede all'instruction register, analizza i primi 6 bit (codeop), determina il tipo di istruzione (R-I-J), emette i segnali di cotrollo adatti al tipo di istruzione per utilizzare i registri temporanei adatti.

Istruzione R
* registro A = Regs[RS];
* registro B = Regs[RT];

Istruzione I
* A   = Regs[RS];
* B   = Regs[RT];
* IMM = Imm (con segno esteso);

Istruzione J
* IMM = Imm (con segno esteso);

<br/>

**EX (execution)**

la fase di esecuzione avviene per qualsiasi tipo di istruzione, l'operazione che compie dipende  dal tipo di istruzione e dall'istruzione stessa.

Istruzione R
* ALUoutput = A op B;

Istruzione I (Aritmetico-logica)
* ALUoutput = A op IMM;

Istruzione I (load-store)
* ALUoutput = A + IMM; // indirizzo di memoria finale

Istruzione I (salto condizionato)
* ALUoutput = NPC + (IMM << 2); // indirizzo di salto
* cond = A condizione B;

Istruzione J
* ALUoutput = NPC + (IMM << 2); // indirizzo di salto

<br/>

**MEM (memory access)**

di base si occupa di aggiornare correttamente il program counter e svolgere le azioni in memoria

* PC = NPC

Istruzione I (load-store)
* LMD = MEM[ALUoutput];
* MEM[ALUoutput] = B; //operazione di store finita

Istruzione I (salto condizionato)
* if(cond) --> PC = ALUoutput;

Istruzione J
* PC = ALUoutput;

NB: LMD è un registro temporaneo che contiene i dati della memoria prelevati.

<br>

**WB (write back)**

fase della pipeline che si occupa di scrivere i risultati delle operazioni nei registri corretti, cioè registri target o destination.

Istruzione R
* Regs[RD] = ALUoutput;

Istruzione I (Aritmetico-logica)
* Regs[RD] = ALUoutput;

Istruzione I (load)
* Regs[RT] = LMD; // operazione di load finita

<br/>

## **Componenti della pipeline**

* sommatore
* memoria dati
* memoria istruzioni
* alu
* banco Registri
* hazard detection unit
* control unit
* forwarding unit

## **Data Hazards**

* Read after Write --> si legge un dato non aggiornato
* Write after Read --> non può avvenire nell'architettura mips
* Write after Write --> non può avvenire nell'architettura mips
* Read after Read --> non genera problemi

casi read after write
* R type e R type (0 stalli)
* R type e I type (0 stalli)
* I type e R type (1 stallo)
* I type e I type (1 stallo)

**R type e R type**
- add $1 $2 $3
- addi $6 $1$ 3

dipendenza: id/ex.IR[RD] == if/id.IR[RS]
si risolve con: ex/mem.ALUoutput -> id/ex.topAluInput (0 stalli)

**R type e I type (Rs)**
- add $1, $2, $4
- sw  $3, 87($1)

dipendenza: id/ex.IR[RD] == if/id.IR[RS]
si risolve con: ex/mem.ALUoutput -> id/ex.topAluInput (0 stalli)

**R type e I type (Rt)**
- add $1, $2, $4
- sw  $3, 87($1)

dipendenza: id/ex.IR[RD] == if/id.IR[RS]
si risolve con: 2 stalli + scrittura e lettura nello stesso ciclo di clock

**I type e R type (Rt)**
- lw  $4, 87($1)
- add $1, $2, $4

dipendenza: id/ex.IR[RT] == if/id.IR[RT]
si risolve con: 1 stallo + mem/wb.lmd -> id/ex.bottomAluInput
oppure: si inserisce un istruzione indipendete + forward

**I type e I type**
- lw  $4, 87($1)
- sw  $3, 87($4)

dipendenza: id/ex.IR[RT] == if/id.IR[RS]
si risolve con: 1 stallo + mem/wb.lmd -> id/ex.bottomAluInput

**soluzioni Read after Write**
1. bubble --> si inseriscono NOPs finchè non si elimina la dipendenza
2. forward dei dati --> ogni fase della pipeline è connessa all'input ALU
3. riordino delle istruzioni

## **Link Utili**

* [Architettura MIPS (uni verona)](http://www.di.univr.it/documenti/OccorrenzaIns/matdid/matdid557805.pdf)
* [Documentazione MIPS](https://en.wikibooks.org/wiki/MIPS_Assembly)
* [Lista istruzioni MIPS](http://alumni.cs.ucr.edu/~vladimir/cs161/mips.html)
