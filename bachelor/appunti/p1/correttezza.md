### Correttezza dei programmi


Nel caso del ciclo for viene abbastanza naturale l'approccio incrementale, è vero, ma la prova di correttezza di un ciclo while e un ciclo for è sempre la stessa ovvero:
 
1. Inizializzazione: verifichi che PRE => R (invariante)
2. Conservazione dell'invariante: se è vero l'invariante prima di una iterazione del ciclo, rimane vero prima della successiva iterazione (ovvero dopo aver eseguito il ciclo)
3. Conclusione. R &&!Test_permanenza => POST

Nel caso in cui ti tornasse utile ai fini della correttezza, puoi sempre utilizzare un intero che fa un lavoro simile a quello dell'indice nel for.

---

Ha poco senso parlare di invariante in maniera generica in quanto a noi non interessano gli invarianti in generale ma gli invarianti significativi.

Un invariante è significativo quando ci dice qualcosa sul ciclo, ovvero ci permette in particolare di concludere che R && !test => POST

Quindi un invariante probabilmente sarà la post un po' rimaneggiata (se non hai idea di cosa scrivere come invariante, leggere la post è un buon punto di partenza)

---

Il punto fondamentale non è che sia sempre vero (anche se necessario chiaramente),  ma che ti dia informazioni su quello che stai facendo

La guardia di per sé non basta,  magari nel ciclo ci entri anche il numero corretto di volte (condizione di guardia) ma come sai che ogni volta hai fatto la cosa giusta? Con l'invariante

---

Quello di cui non ti puoi sbagliare è indicare che valori può avere la variabile che stá nel while (es 0<=row<=n-1 PS* PS**) e segnare che cosa succede/fá ad ogni iterazione (es. Ho stampato row righe, ho scritto j spazi, ho scritto k asterischi PS**)

PS* se while(row<n-1) per far si che si esca dal ciclo row sara' = n-1 per questo nell'invariante devi segnare valore_base<=row<=n-1.

PS** se while(sentinella) che varia tra true e false, nell'invariante dovrai scrivere a che cosa corrisponde/fa' quando la sentinella e' a true e cosa quando e' a false: ad esempio supponendo che non si esca dal ciclo fino a che non si trova il valore x "sentinella => non ho trovato il valore x" (o "sentinella => tutti gli n-esimi valori sono diversi da x") e "!sentinella => ho trovato il valore x" (o "!sentinella => il carattere n-esimo e' x"). 
se ci sono piu' sentinelle (come nell'esercizio2 fatto in laboratorio l'ultima volta) la logica e' uguale, solo che devi spiegare che cosa accade per la combinaione delle due sentinelle (trovi la solizione dell'invariante nell'ultima slide in "lezione 07 ancora invarianti File")

Spero di non averti incasinato ancora di piu' le cose lol

---

Dal Vangelo secondo Filé
"Programma nostro, che sei sul Moodle, sia debuggato il tuo codice. Venga la tua ricorsione, sia fatta la tua correttezza: come nel sorgente così nel compilatore. Dacci oggi il nostro 4/4 quotidiano, e non ci indurre in segmentation fault, ma liberaci dai dangling pointer.
Return."