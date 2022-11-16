Concetti hardware:
* testina --> dispositivo che permette di eseguire read/write
* traccia --> anello concentrico del disco, ce ne sono migliaia in un disco
* settore --> porzione di traccia, ce ne sono migliaia in una traccia

Prestazioni di un disco
* T<sub>s</sub> = Seek time --> tempo che impiega la testina per posizionarsi sopra la traccia corretta
* T<sub>l</sub> = latency --> tempo impiegato dal disco per far passare sotto la testina il settore corretto
* T<sub>t</sub> = transfer time --> tempo impiegato dall'hard disk per leggere i dati con la testina

* T<sub>TOT</sub> = T<sub>S</sub> + T<sub>L</sub> + T<sub>T</sub>

**Formule**
1. T<sub>S</sub> --> viene dato o si ricava dalla formula
2. T<sub>L</sub> = (1000/(rpm/60)) / 2
3. T<sub>T</sub> = (b/B * 1000/(rpm/60)) / n

b = byte da trasferire
B = byte per traccia
n = n cilinndri se c'è trasferimento in parallelo
