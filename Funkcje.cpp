//
// Created by damia on 27.03.2023.
//

#include "Funkcje.h"
#include <windows.h>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

long long int read_QPC()
{
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    return((long long int)count.QuadPart);
}
int liczbaLiczbWPliku(){
    ifstream plik("C:/Users/Damian/CLionProjects/SDiZO-Projekt-1/liczby.txt");

    if (plik.is_open()) {
    int liczbaLiczb;
    plik >> liczbaLiczb;
    return liczbaLiczb;}
    }
//wczytanie liczb z pliku
int* wczytajLiczby() {
    static int liczby[1000];
    ifstream plik("C:/Users/Damian/CLionProjects/SDiZO-Projekt-1/liczby.txt");
    int liczbaLiczb;
    if (plik.is_open()) {

        plik >> liczbaLiczb;
        for (int i = 0; i < liczbaLiczb; i++) {
            plik >> liczby[i];
        }

        plik.close();
    } else {
        cout << "Nie udalo sie otworzyc pliku!" << endl;
    }

    // wyświetlanie liczb
    cout << "Dane wejsciowe:" << endl;
    for (int i = 0; i < liczbaLiczb; i++) {
        cout<<" | "<<liczby[i];
    }
    cout<<" |"<<endl;
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
    // wyświetlanie liczb
    cout << "Tablica:" << endl;
    for (int i = 0; i < rozmiarTablicy; i++) {
        cout<<" | "<<tablica[i];
    }
    cout<<" |"<<endl;
    return tablica; // zwróć nową tablicę z elementami skopiowanymi
}

int* dodaj_liczbe(int* tablicaWejsciowa,int liczbaLiczb,int liczba,int indeks){
    int* tablicaWyjsciowa = new int[liczbaLiczb + 1]; // alokuj nową tablicę z rozmiarem zwiększonym o 1
    for (int i = 0; i < indeks; i++) {
        tablicaWyjsciowa[i] = tablicaWejsciowa[i]; // skopiuj elementy z tablicy pierwotnej do nowej tablicy do wskazanego indeksu
    }
    tablicaWyjsciowa[indeks] = liczba; // wstaw nowy element na wskazany indeks
    for (int i = indeks + 1; i < liczbaLiczb + 1; i++) {
        tablicaWyjsciowa[i] = tablicaWejsciowa[i - 1]; // skopiuj pozostałe elementy z tablicy pierwotnej do nowej tablicy
    }
    liczbaLiczb++; // zwiększ rozmiar tablicy
    delete[] tablicaWejsciowa; // zwolnij pamięć zaalokowaną dla pierwotnej tablicy

    // wyświetlanie liczb
    cout << "Tablica po dodaniu liczby "<<liczba<<" na indeks "<<indeks<<":" << endl;
    for (int i = 0; i < liczbaLiczb; i++) {
        cout<<" | "<<tablicaWyjsciowa[i];
    }
    cout<<" |"<<endl;
    return tablicaWyjsciowa; // zwróć nową tablicę z dodanym elementem
}

int* usun_liczbe(int* tablicaWejsciowa,int liczbaLiczb,int indeks){
// Sprawdź, czy tablica nie jest pusta i czy indeks jest prawidłowy
    if (tablicaWejsciowa == nullptr || indeks < 0 || indeks >= liczbaLiczb) {
        std::cout << "Błąd: indeks poza zakresem lub tablica jest pusta.\n";
        return tablicaWejsciowa;
    }

    // Przesuń elementy tablicy o 1 pozycję w lewo
    for (int i = indeks; i < liczbaLiczb - 1; i++) {
        tablicaWejsciowa[i] = tablicaWejsciowa[i + 1];
    }

    // Zmniejsz rozmiar tablicy o 1
    int* tablicaWyjsciowa = new int[liczbaLiczb - 1];
    for (int i = 0; i < liczbaLiczb - 1; i++) {
        tablicaWyjsciowa[i] = tablicaWejsciowa[i];
    }

    delete[] tablicaWejsciowa;
    tablicaWejsciowa = tablicaWyjsciowa;

    // wyświetlanie liczb
    cout << "Tablica po usunieciu liczby z indeksu "<<indeks<<":" << endl;
    for (int i = 0; i < liczbaLiczb; i++) {
        cout<<" | "<<tablicaWyjsciowa[i];
    }
    cout<<" |"<<endl;
    return tablicaWyjsciowa; // zwróć nową tablicę z dodanym elementem
}