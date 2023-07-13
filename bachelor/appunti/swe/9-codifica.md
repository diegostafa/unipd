**codifica**

* deve facilitare la verifica

deve essere:
* predecibile
    * no side effect --> il mio stato interno può essere modificato da entità esterne (var globali)
    * i risultati dipendono dall'ordine di esecuzione delle sue parti (no thread)
    * passaggio dei parametri


**principi di programmazione**

* il codice deve riflettere l'architettura, cos' mantiene le sue proprietà
    * programmazione a moduli
* separare interfaccia da implementazione
* usare l'incapsulamento
    * membri privati --> circoscrivono gli errori
* estendere i tipi
* l'uscita delle funzioni deve essere unica (o ilmeno possibile)