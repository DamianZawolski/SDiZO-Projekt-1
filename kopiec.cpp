#include <iostream>
#include "kopiec.h"
using namespace std;

kopiec::kopiec()
//konstruktor- ustawiamy wielkość naszego kopca na 0
{
    rozmiar = 0;
}

void kopiec::dodaj(int liczba)
// Dodawanie liczby "liczba" do kopca
{
    rozmiar++; //zwiększenie rozmiaru kopca
    kopiec_binarny.dodaj_na_koniec(liczba); // dodanie nowego elementu
    int pozycja = rozmiar - 1;
    while (pozycja > 1)
    {
        if (kopiec_binarny.tablica[pozycja / 2] < kopiec_binarny.tablica[pozycja])  // Zamiana miejscami, jeśli dziecko jest większe od rodzica
        {
            kopiec_binarny.zamien_elementy(pozycja / 2, pozycja);
            pozycja = pozycja / 2;
        } else break;
    }
}

void kopiec::usun() {
// Usuwanie elementu z kopca
    if (rozmiar == 0) {
        return;

    } else if (rozmiar == 1) {
        kopiec_binarny.usun_ostatni();

    } else {
        kopiec_binarny.zamien_elementy(1, rozmiar);
        int pozycja = 1;
        while (pozycja * 2 < rozmiar) {
            int dziecko = pozycja * 2;

            if (dziecko != rozmiar - 1) {
                if (dziecko < dziecko + 1) {
                    dziecko++;
                }
            }
            if (dziecko > pozycja) {
                kopiec_binarny.zamien_elementy(dziecko, pozycja);
                pozycja = dziecko;
            } else {
                break;
            }
        }
        rozmiar = rozmiar - 1;
    }
}

void kopiec::wyswietl()
//Wyświetlanie kopca
{
    int n = 1;

    for (int i = 1; i < rozmiar; i++) {

        if ((n & (n - 1)) == 0) // Dodawanie nowych linii w celu zwiększenie estetyki/ czytelności kopca
        {
            cout << endl;
        }

        cout << kopiec_binarny.tablica[i] << " ";
        n++;

    }
    cout << endl;
}

bool kopiec::znajdz(int wartosc)
// Szukanie wartości w kopcu
{
    bool czy_znaleziono = false;
    for(int i = 0; i < kopiec_binarny.rozmiar; i++)
    {
        if(kopiec_binarny.tablica[i] == wartosc)
        {
            czy_znaleziono = true;
            break;
        }
    }
    return czy_znaleziono;

}