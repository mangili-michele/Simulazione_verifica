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

Il programma deve stampare a video la lista degli ID di tutti i processi nell'ordine in cui verranno eseguiti.*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Struttura per memorizzare i dati di un singolo processo
struct Processo 
{
    int id;
    int arrivo;
    int durata;
    int priorita;
};

void schedulaProcessiES1(vector<Processo> vettProcessi) 
{
    int tempo_corrente = 0;
    cout << "es 1"<< endl;
    //SCRIVI QUI IL CODICE PER L'ESERCIZIO 1
    for(int i = 0; i < vettProcessi.size(); i++){

        int Pa = vettProcessi[i].arrivo;
        int Pd = vettProcessi[i].durata;
        int Pp = vettProcessi[i].priorita;

        if(Pa == 0)
        {
            tempo_corrente = Pd;
            cout << vettProcessi [i].id << " " << Pa <<" "<< tempo_corrente << endl;
        }
        else
        {
            if(tempo_corrente < Pa)
            {
                tempo_corrente = Pa + Pd;
                cout << vettProcessi [i].id << " " << Pa <<" "<< tempo_corrente << endl;
            }
            else
            {
                tempo_corrente += Pd;
                cout << vettProcessi [i].id << " " << Pa <<" "<< tempo_corrente << endl;
            }
        }

 
    
}




void schedulaProcessiES2(vector<Processo> vettProcessi) 
{   
    //SCRIVI QUI IL CODICE PER L'ESERCIZIO 2

    int tempo_corrente = 0;
    cout << "es 2"<< endl;
    for(int i = 0; i < vettProcessi.size(); i++){
        
        int Pa = vettProcessi[i].arrivo;
        int Pd = vettProcessi[i].durata;
        int Pp = vettProcessi[i].priorita;

        if(Pa == 0)
        {
            tempo_corrente = Pd;
            cout << vettProcessi [i].id << " " << Pa <<" "<< tempo_corrente << endl;
        }
        else
        {
            if(tempo_corrente < Pa)
            {
                tempo_corrente = Pa + Pd;
                cout << vettProcessi [i].id << " " << Pa <<" "<< tempo_corrente << endl;
            }
            else
            {
                tempo_corrente += Pd;
                cout << vettProcessi [i].id << " " << Pa <<" "<< tempo_corrente << endl;
            }
        }

    }


    

    
}

int main()
{
    ifstream file("input.txt");
    
    // Controllo se il file esiste e si apre correttamente
    if (!file.is_open()) {
        cout << "Errore nell'apertura del file!" << endl;
        return 1;
    }

    int n;
    file >> n; // Legge il numero totale di processi dalla prima riga

    vector<Processo> vettProcessi(n);

    // Popola il vettore di processi
    for (int i = 0; i < n; i++) 
    {
        file >> vettProcessi[i].id 
             >> vettProcessi[i].arrivo 
             >> vettProcessi[i].durata 
             >> vettProcessi[i].priorita;
    }
    
    file.close();

    //Test esercizio 1
    schedulaProcessiES1(vettProcessi);
    
    //Test esercizio 2
    schedulaProcessiES2(vettProcessi);
    return 0;
}




