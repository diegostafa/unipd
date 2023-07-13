il sistema operativo è di base un programma come un altro che si occupa di creare un interfaccia con l'hardware.

il sistema operativo crea quindi un ambiente che consente l'interazione con l'hardware attraverso un interfaccia semplice (l'hardware ha un interfaccia complessa), oltre a ciò si occupa di fornire meccanismi di sicurezza

per creare queste astrazioni il sistema operativo deve avere pieno controllo della macchina ed operare quindi in kernel mode

* kernel mode --> la cpu può eseguire qualsiasi istruzione del suo ISA
* user mode --> la cpu può eseguire un ristretto numero di istruzioni del suo ISA (solitamente accesso a registri, accesso alla propria area di indirizzamento)


### struttura os

l'os è un programma particolare in quanto deve essere in grado di gestire altri programmi pur non essendo sempre in esecuzione, per consentire ciò si utilizzano degli eventi:
* interrupt --> segnali generati dall'hardware
* eccezioni --> segnali generati da istruzioni illegali
* system calls --> segnali generati da istruzioni di kernel mode

al verificarsi di un segnale tra questi l'os guadagna sempre controllo sulla cpu

per ottenere un controllo costante (non è detto che un programma esegua syscalls o eccezioni) si utilizza un timer.

timer --> letteramente un orologio hardware che invia periodicamente un interrupt alla cpu in modo da passare il controllo al so

ogni evento che passa il controllo al sistema operativo deve occuparsi di salvare il contesto del processo precedentemente in esecuzione

interrupt, eccezioni e system calls sono degli eventi che devono essere gestiti dall'os, tutti questi eventi sono identificati da un numero intero, questo numero intero viene utilizzato come indice per risalire alla procedura di gestione relativa.

il sistema operativo si occupa durante l'avvio della macchina di caricare in memoria queste tabelle di gestione (interrupt vector, trap table)

il sistema operativo è quindi un programma costruito sul concetto di evento, che entra in azione solo al verificarsi di questi
