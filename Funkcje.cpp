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
    ifstream plik("C:/Users/damia/CLionProjects/SDiZO Projekt 1/liczby.txt");

    if (plik.is_open()) {
    int liczbaLiczb;
    plik >> liczbaLiczb;
    return liczbaLiczb;}
    }

//wczytanie liczb z pliku
int* wczytajLiczby() {
    static int liczby[1000];
    ifstream plik("C:/Users/damia/CLionProjects/SDiZO Projekt 1/liczby.txt");
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

    // wyświetlanie liczb
    cout << "Tablica po usunieciu liczby z indeksu "<<indeks<<":" << endl;
    for (int i = 0; i < liczbaLiczb; i++) {
        cout<<" | "<<tablicaWyjsciowa[i];
    }
    cout<<" |"<<endl;
    return tablicaWyjsciowa; // zwróć nową tablicę z dodanym elementem
}
struct Wezel {
    int data;
    Wezel* prev;
    Wezel* next;
};

void dodaj_do_listy(Wezel** adres_glowy, int elementy[], int n) {
    // Przejście po tablicy i dodanie elementów do listy
    for (int i = 0; i < n; i++) {
        // Tworzenie nowego elementu
        Wezel* nowy_wezel = new Wezel;
        nowy_wezel->data = elementy[i];
        nowy_wezel->prev = nullptr;
        nowy_wezel->next = (*adres_glowy);

        // Jeśli lista nie jest pusta, ustawienie wskaźnika prev poprzedniego pierwszego elementu na nowy element
        if ((*adres_glowy) != nullptr) {
            (*adres_glowy)->prev = nowy_wezel;
        }

        // Ustawienie nowego elementu jako pierwszy element listy
        (*adres_glowy) = nowy_wezel;
    }
}

void wyswietl_liste(Wezel* glowa)
{
    Wezel* obecny_wezel = glowa;
    while (obecny_wezel != nullptr) {
        cout << obecny_wezel->data << " ";
        obecny_wezel = obecny_wezel->next;
    }cout<<endl;
}
void dodaj_do_listy(Wezel** adres_glowy, int nowa_wartosc, int pozycja) {
    // Tworzenie nowego elementu
    Wezel* nowy_wezel = new Wezel;
    nowy_wezel->data = nowa_wartosc;

    // Przeszukiwanie listy, aby znaleźć element na wskazanej pozycji
    Wezel* obecny_wezel = (*adres_glowy);
    for (int i = 1; i < pozycja && obecny_wezel != nullptr; i++) {
        obecny_wezel = obecny_wezel->next;
    }

    // Jeśli lista jest pusta lub pozycja jest większa niż liczba elementów w liście, ustawienie nowego elementu jako ostatni element
    if (obecny_wezel == nullptr) {
        nowy_wezel->prev = nullptr;
        nowy_wezel->next = (*adres_glowy);
        if ((*adres_glowy) != nullptr) {
            (*adres_glowy)->prev = nowy_wezel;
        }
        (*adres_glowy) = nowy_wezel;
    }
        // W przeciwnym przypadku, wstawienie nowego elementu przed elementem na wskazanej pozycji
    else {
        nowy_wezel->prev = obecny_wezel->prev;
        nowy_wezel->next = obecny_wezel;
        if (obecny_wezel->prev != nullptr) {
            obecny_wezel->prev->next = nowy_wezel;
        }
        obecny_wezel->prev = nowy_wezel;
    }


}

void usun_z_listy(Wezel** adres_glowy, int pozycja) {
    // Jeśli lista jest pusta, nie ma nic do usunięcia
    if (*adres_glowy == nullptr) {
        return;
    }

    Wezel* obecny_wezel = *adres_glowy;
    int licznik = 1;

    // Przejście do elementu, który chcemy usunąć
    while (obecny_wezel != nullptr && licznik != pozycja) {
        obecny_wezel = obecny_wezel->next;
        licznik++;
    }

    // Jeśli pozycja jest poza zakresem listy, nie ma nic do usunięcia
    if (obecny_wezel == nullptr) {
        return;
    }

    // Jeśli element do usunięcia jest pierwszym elementem, ustawienie nowej głowy listy
    if (obecny_wezel == *adres_glowy) {
        *adres_glowy = obecny_wezel->next;
    }

    // Usunięcie elementu
    if (obecny_wezel->prev != nullptr) {
        obecny_wezel->prev->next = obecny_wezel->next;
    }
    if (obecny_wezel->next != nullptr) {
        obecny_wezel->next->prev = obecny_wezel->prev;
    }
    delete obecny_wezel;
}

