#include <iostream>
#include <string>
#include "Tablica.h"
using namespace std;

tablicaDynamiczna::tablicaDynamiczna()
//inicjowanie tablicy
{
    tablica = nullptr;
    rozmiar = 0;
}

void tablicaDynamiczna::dodaj_na_poczatek(int wartosc)
//dodaj element "wartosc" na początek tablicy
{
    int* nowa_tablica = new int[rozmiar + 1];
    nowa_tablica[0] = wartosc;

    for(int i = 0; i < rozmiar; i++)
    {
        nowa_tablica[i + 1] = tablica[i];
    }

    delete tablica;
    tablica = nowa_tablica;
    rozmiar++;

}

void tablicaDynamiczna::dodaj_na_koniec(int wartosc)
//dodaj element "wartosc" na koniec tablicy
{
    int* nowa_tablica = new int[rozmiar + 1];
    nowa_tablica[rozmiar] = wartosc;


    for(int i = 0; i < rozmiar; i++)
    {
        nowa_tablica[i] = tablica[i];
    }
    delete tablica;
    tablica = nowa_tablica;
    rozmiar++;

}

void tablicaDynamiczna::dodaj_na_pozycje(int wartosc, int pozycja)
//dodaj element "wartosc" do tablicy w miejscu "znajdz_wartosc"
{
    if(pozycja < 0)
    {
        cout<<" Indeks ujemny- element zostanie wstawiony na poczatek listy. "<<endl;
        dodaj_na_poczatek(wartosc);
    }
    else if(pozycja >= rozmiar){
        cout<<" Indeks wiekszy od rozmiaru- element zostanie wstawiony na koniec listy. "<<endl;
        dodaj_na_koniec(wartosc);
    }
    else {
        int *nowa_tablica = new int[rozmiar + 1];  //nowa lista o rozmiarze większym o 1

        for (int i = 0; i < pozycja; i++)  //przepisanie wartości do nowej tablicy
        {
            nowa_tablica[i] = tablica[i];

        }
        nowa_tablica[pozycja] = wartosc;
        for (int i = pozycja + 1; i < rozmiar + 1; i++) //przepisanie pozostałych elementów tablicy
        {
            nowa_tablica[i] = tablica[i - 1];

        }
        delete tablica;
        tablica = nowa_tablica;
        rozmiar++;
    }
}

void tablicaDynamiczna::usun_ostatni()
//usuń ostatni element tablicy
{
    if (rozmiar==0){
        return;
    }
    else{
        int* nowa_tablica = new int[rozmiar - 1];

        for(int i = 0; i < rozmiar - 1; i++) //przepisanie wartości do nowej tablicy bez ostatniego elementu
        {
            nowa_tablica[i] = tablica[i];
        }

        delete tablica;
        tablica = nowa_tablica;
        rozmiar--;
    }
}

void tablicaDynamiczna::usun_pierwszy()
//usuń pierwszy element tablicy
{
    if (rozmiar==0){
        return;
    }
    else{
        int *nowa_tablica = new int[rozmiar - 1];
        for (int i = 0; i < rozmiar - 1; i++) //przepisanie wartości do nowej tablicy bez pierwszego elementu
        {
            nowa_tablica[i] = tablica[i + 1];

        }

        delete tablica;
        tablica = nowa_tablica;
        rozmiar--;
    }
}

void tablicaDynamiczna::usun(int pozycja)
//usuń element z pozycji "znajdz_wartosc"
{
    if(pozycja < 0)
    {
        cout << " Indeks ujemny- zostanie usuniety pierwszy element " <<endl;
        usun_pierwszy();
    }
    else if(pozycja >= rozmiar)
    {
        cout << " Indeks wiekszy od rozmiaru tablicy- zostanie usuniety ostatni element " <<endl;
        usun_ostatni();
    }
    else
    {
        int *nowa_tablica = new int[rozmiar - 1];

        for (int i = 0; i < pozycja; i++) //przepisanie wartości do nowej tablicy do usuniętego elementu
        {
            nowa_tablica[i] = tablica[i];
        }
        for (int i = pozycja; i < rozmiar - 1; i++) //przepisanie wartości do nowej tablicy od usuniętego elementu
        {
            nowa_tablica[i] = tablica[i + 1];
        }

        delete tablica;
        tablica = nowa_tablica;
        rozmiar--;
    }
}

void tablicaDynamiczna::wyswietl()
//Wyświetl elementy tablicy
{
    for(int i = 0; i < rozmiar; i++)
    {
        cout << tablica[i] << " | ";
    }
    cout << endl;
}

void tablicaDynamiczna::zamien_elementy(int x, int y)
//Zamienia element o indeksie x z elementem o indeksie y
{
    int* pomocnicza = new int[1];

    pomocnicza[0] = tablica[x];
    tablica[x] = tablica[y];
    tablica[y] = pomocnicza[0];

    delete pomocnicza;
}

int tablicaDynamiczna::znajdz_element(int wartosc)
//Wyszukiwanie indeksu elementu "wartosc" w tablicy
{
    int pozycja = -1;

    for(int i = 0; i < rozmiar; i++)
    {
        if(tablica[i] == wartosc)
        {
            pozycja = i;
            break;
        }
    }
    return pozycja;
}

int* tablicaDynamiczna::zwroc_tablice(){
    return tablica;
}