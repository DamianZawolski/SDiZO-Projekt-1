//
// Created by damia on 27.03.2023.
//

#include "Funkcje.h"
#include <windows.h>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <fstream>
using namespace std;

long long int read_QPC()
{
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    return((long long int)count.QuadPart);
}

//wczytanie liczb z pliku
int* wczytajLiczby(int liczbaLiczb) {
    static int liczby[100];
    ifstream plik("C:/Users/Damian/CLionProjects/SDiZO-Projekt-1/liczby.txt");

    if (plik.is_open()) {
        for (int i = 0; i < liczbaLiczb; i++) {
            plik >> liczby[i];
        }
        plik.close();
    } else {
        cout << "Nie udalo sie otworzyc pliku!" << endl;
    }

    return liczby;
}

int* kopiujTablice(int* tablicaWejsciowa, int rozmiarTablicy) {
    long long int frequency, start, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    start = read_QPC();
    int* tablica = new int[rozmiarTablicy]; // alokuj nową tablicę na elementy skopiowane
    for (int i = 0; i < rozmiarTablicy; i++) {
        tablica[i] = tablicaWejsciowa[i]; // skopiuj elementy z tablicy wejściowej do tablicy wyjściowej
    }
    elapsed = read_QPC() - start;
    cout << "Czas dodawania elementow do tablicy: " << setprecision(0) << (1000000.0 * elapsed) /
                                                 frequency << " [us]"<<endl;
    return tablica; // zwróć nową tablicę z elementami skopiowanymi
}