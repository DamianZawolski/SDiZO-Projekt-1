#include <iostream>
#include "kopiec.h"
#include <cmath>
#include <string>
using namespace std;

int kopiec::lewe_dziecko(int indeks)
{
    return (indeks * 2) + 1;
}

int kopiec::prawe_dziecko(int indeks)
{
    return (indeks * 2) + 2;
}

kopiec::kopiec()
//konstruktor- ustawiamy wielkość naszego kopca na 0
{
    rozmiar = 0;
}

void kopiec::dodaj(int liczba)
// Dodawanie liczby "liczba" do kopca
{
    rozmiar++; //zwiększenie rozmiaru kopca
    tablica.dodaj_na_koniec(liczba); // dodanie nowego elementu
    int dziecko = rozmiar - 1;
    int* tablica_dynamiczna = tablica.zwroc_tablice();
    while (dziecko > 1 && tablica_dynamiczna[dziecko] > tablica_dynamiczna[dziecko / 2]){
        tablica.zamien_elementy(dziecko, dziecko / 2);
        dziecko = dziecko / 2;
    }
    przywroc_wlasciwosci(0);

}

void kopiec::usun_ze_szczytu() {
// Usuwanie elementu z kopca
    if (rozmiar == 0) {
        return;

    } else if (rozmiar == 1) {
        tablica.usun_ostatni();
        rozmiar --;

    }
    else {
        tablica.zamien_elementy(0, rozmiar-1);
        tablica.usun_ostatni();
        rozmiar --;
        przywroc_wlasciwosci(0);

    }

    }

void kopiec::wyswietl()
//Wyświetlanie kopca
{

    int poziomy = 0;
    while (pow(2,poziomy)<rozmiar){
        poziomy++;
    }
    int n = 1;

    for (int i = 0; i < rozmiar; i++) {

        if ((n & (n - 1)) == 0) // Dodawanie nowych linii w celu zwiększenie estetyki/ czytelności kopca
        {
            cout << endl;
            for (int j = 0; j <=poziomy; j++){
                cout<<" ";
            }
            poziomy--;
        }

        cout << tablica.tablica[i] << " ";
        n++;

    }
    cout << endl<< endl;
}

int kopiec::znajdz(int wartosc)
// Szukanie wartości w kopcu
{
    int indeks = -1;
    for(int i = 0; i < tablica.rozmiar; i++)
    {
        if(tablica.tablica[i] == wartosc)
        {
            indeks = i;
            break;
        }
    }
    return indeks;
}

void kopiec::przywroc_wlasciwosci(int indeks){
    int* tablica_dynamiczna = tablica.zwroc_tablice();
    int lewe_dziecko_elementu = lewe_dziecko(indeks);
    int prawe_dziecko_elementu = prawe_dziecko(indeks);
    int maksymalny_indeks = rozmiar - 1;
    if (lewe_dziecko_elementu <= maksymalny_indeks){    //jeśli indeks lewego dziecka mieści się w kopcu
        if (tablica_dynamiczna[lewe_dziecko_elementu] > tablica_dynamiczna[indeks]){    //jeśli lewe dziecko jest większe od rodzica
            if (prawe_dziecko_elementu <= maksymalny_indeks && tablica_dynamiczna[prawe_dziecko_elementu] >= tablica_dynamiczna[lewe_dziecko_elementu]){    //jeśli prawe dziecko elementu jest większe od lewego
                tablica.zamien_elementy(indeks, prawe_dziecko_elementu);
                przywroc_wlasciwosci(prawe_dziecko_elementu);
            }
            else{
                tablica.zamien_elementy(indeks, lewe_dziecko_elementu);
                przywroc_wlasciwosci(lewe_dziecko_elementu);
            }
        }
    }
    else if (prawe_dziecko_elementu <= maksymalny_indeks){  //jeśli indeks prawego dziecka mieści się w kopcu
        if (tablica_dynamiczna[prawe_dziecko_elementu]> tablica_dynamiczna[indeks]) {   //jeśli prawe dziecko jest większe od rodzica
            if (lewe_dziecko_elementu <= maksymalny_indeks && tablica_dynamiczna[lewe_dziecko_elementu] >= tablica_dynamiczna[prawe_dziecko_elementu]){    //jeśli lewe dziecko elementu jest większe od prawego
                tablica.zamien_elementy(indeks, lewe_dziecko_elementu);
                przywroc_wlasciwosci(lewe_dziecko_elementu);
            }
            else{
                tablica.zamien_elementy(indeks, prawe_dziecko_elementu);
                przywroc_wlasciwosci(prawe_dziecko_elementu);
            }
        }
    }
    else{
        return;
    }
}