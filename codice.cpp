/*leggi il readme e fai l'esercizio
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
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct Process {
    int id;
    int duration;
    int priority;
};

bool compare(Process a, Process b) {
    if (a.priority == b.priority) {
        return a.duration < b.duration; // Se le priorità sono uguali, ordina per durata
    }
    return a.priority > b.priority; // Altrimenti, ordina per priorità
}

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Errore nell'apertura del file!" << std::endl;
        return 1;
    }

    int N;
    inputFile >> N;

    std::vector<Process> processes(N);
    for (int i = 0; i < N; ++i) {
        inputFile >> processes[i].id >> processes[i].duration >> processes[i].priority;
    }

    // Ordina i processi in base alla priorità e alla durata
    std::sort(processes.begin(), processes.end(), compare);

    // Stampa l'ordine di esecuzione dei processi
    for (const auto& process : processes) {
        std::cout << process.id << std::endl;
    }

    return 0;
}




