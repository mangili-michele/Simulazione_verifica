# Simulazione_verifica

Consegnare un repository git contenente un algoritmo per la schedulazione con priorità dei processi.
Il programma riceve in input un singolo file input.txt strutturato in questo modo:
N
I1 D1 P1
I2 D2 P2
I3 D3 P3
...
IN DN PN

La prima riga contiene il numero N dei processi. Seguono N righe, per ciascuna delle quali è leggibile l'id del processo (I, primo numero), la durata (D, secondo numero) e la priorità (P, terzo numero). Il processo a priorità più alta va eseguito per primo, e a parità di priorità si prende il processo con durata minore. Non c'è pre-emption.

Il programma deve stampare a video la lista degli ID di tutti i processi nell'ordine in cui verranno eseguiti.