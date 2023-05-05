#include <iostream>
#include "lista.h"
#include <string>
using namespace std;

lista::lista()
//Konstruktor klasy lista
{
    glowa = nullptr;  //NULL, bo nie znamy pierwszego elementu
    ogon = nullptr; //NULL, bo nie znamy ostatniego elementu listy
}

void lista::dodaj_na_poczatek(int wartosc)
//Dodaj element "wartosc" na początek listy
{

    auto *nowaGlowa = new Element;

    if (glowa == nullptr)        // Jeśli lista jest pusta
    {
        //W przypadku pustej listy element staje się pierwszym i ostatnim
        glowa = nowaGlowa;
        ogon = nowaGlowa;
        glowa->wartosc = wartosc;
        glowa->poprzedni = nullptr;
        glowa->nastepny = nullptr;
    } else
    {
        nowaGlowa->wartosc = wartosc;
        nowaGlowa->nastepny = glowa;
        nowaGlowa->poprzedni = nullptr;           // Jest to pierwszy element, więc nie ma poprzednika
        glowa->poprzedni = nowaGlowa;           //Poprzednikiem starej głowy zostaje nowa głowa
        glowa = nowaGlowa;                     //Głową staje się nowa głowa
        if (nowaGlowa->nastepny !=
            nullptr)           // Jeśli lista ma więcej elementów to poprzednikiem następnego zostaje nowy element
            nowaGlowa->nastepny->poprzedni = nowaGlowa;
        else
            ogon = nowaGlowa;
    }
    rozmiar++;
}

void lista::dodaj_na_koniec(int wartosc)
//Dodaj element na koniec listy
{
    auto *nowyOgon = new Element;

    if (glowa == nullptr)            // Jeśli lista jest pusta
    {
        //W przypadku pustej listy element staje się pierwszym i ostatnim
        glowa = nowyOgon;
        glowa->wartosc = wartosc;
        glowa->poprzedni = nullptr;
        glowa->nastepny = nullptr;
        ogon = glowa;
    }
    else
    {
        nowyOgon->wartosc = wartosc;
        ogon->nastepny = nowyOgon;
        nowyOgon->poprzedni = ogon;
        nowyOgon->nastepny = nullptr;
        ogon = nowyOgon;
    }
    rozmiar++;
}

void
lista::dodaj_na_pozycje(int wartosc, int pozycja)
//Dodanie elementu "wartosc" na indeks "znajdz_wartosc"
{

    if (glowa == nullptr)                        // Jeśli lista jest pusta
    {
        //W przypadku pustej listy element staje się pierwszym i ostatnim
        auto *nowaGlowa = new Element;
        glowa = nowaGlowa;
        glowa->wartosc = wartosc;
        glowa->poprzedni = nullptr;
        glowa->nastepny = nullptr;
        ogon = glowa;
    }
    else
    {
        auto *obecny = new Element;
        obecny = glowa;

        for (int i = 0; i < pozycja - 1; i++) //Przemieszczamy się do elementu poprzedzającego
        {
            if (obecny->nastepny ==
                nullptr)       //Jeśli dotarliśmy do końca listy, to umieszczamy element na końcu listy
            {
                break;
            }

            obecny = obecny->nastepny;
        }

        if (obecny->nastepny ==
            nullptr) //Jeśli nie ma następnego elementu, to wstawiamy na koniec
        {
            dodaj_na_koniec(wartosc);
        } else
        {
            auto *srodek = new Element;
            srodek->wartosc = wartosc;
            srodek->nastepny = obecny->nastepny;
            obecny->nastepny->poprzedni = srodek;
            srodek->poprzedni = obecny;
            obecny->nastepny = srodek;
        }
    }
    rozmiar++;
}

void lista::usun_pierwszy(){
    //Usuwanie pierwszego elementu
    if (glowa == nullptr) //Jeśli nie ma pierwszego elementu to nic nie usuwamy
        return;

    auto *pomocnicza = new Element;
    pomocnicza = glowa;
    if (pomocnicza->nastepny == nullptr) {
        ogon = nullptr;
        glowa = nullptr;
        rozmiar--;
        return;
    }
    glowa = glowa->nastepny;
    glowa->poprzedni = nullptr;
    rozmiar--;
    delete pomocnicza;
}

void lista::usun_ostatni() {
    if (glowa == nullptr) //Jeśli nie ma pierwszego elementu to nic nie usuwamy
        return;

    auto *pomocnicza = new Element;
    pomocnicza = ogon;
    if (ogon->poprzedni == nullptr) {
        ogon = nullptr;
        glowa = nullptr;
    } else {
        ogon = ogon->poprzedni; //Ogonem staje się poprzedni element
        ogon->nastepny = nullptr;
        delete pomocnicza;
    }
    rozmiar--;
}

void lista::usun(int pozycja) {

    if (glowa == nullptr) //Jeśli nie ma pierwszego elementu to nic nie usuwamy
        return;

    else if (pozycja>=rozmiar){    //Jeśli znajdz_wartosc jest większa od rozmiaru to usuwamy ostatni
        usun_ostatni();
        pozycja = rozmiar-1;
    }
    else if(pozycja <= 0 ) //Jeśli znajdz_wartosc jest równa/ mniejsza od 0 to usuwamy pierwszy element
    {
        usun_pierwszy();
    }
    if (glowa == nullptr) //Jeśli nie ma pierwszego elementu to nic nie robimy
        return;
    auto *obecny = new Element;
    obecny = glowa;

    if(pozycja == 1)    // Osobno obsługujemy element o indeksie 1, bo wpływa na głowę
    {
        obecny->nastepny->poprzedni = glowa;
        glowa->nastepny = obecny->nastepny;
    }
    else {
        for (int i = 0; i < pozycja; i++) //Przemieszczamy się do elementu poprzedzającego
        {
            if (obecny->nastepny == nullptr) //Jeśli dotarliśmy do końca listy, to umieszczamy element na końcu listy
            {
                delete obecny;
                return;
            }
            obecny = obecny->nastepny;
        }

        if (obecny->nastepny == nullptr)       //Jeśli dotarliśmy do końca listy, to umieszczamy element na końcu listy
        {
            delete obecny;
            return;
        }
        obecny->poprzedni->nastepny = obecny->nastepny;
        obecny->nastepny->poprzedni = obecny->poprzedni;
        rozmiar--;
        delete obecny;
    }
}

void lista::wyswietl_od_przodu()
{
    //wyswietlanie tablicy od przodu
    auto *obecny = new Element;
    obecny = glowa;
    while (obecny != nullptr) {
        cout << obecny->wartosc << " | ";
        obecny = obecny->nastepny;
    }
    cout << endl;
    delete obecny;
}

void lista::wyswietl_od_tylu()
{
    //wyswietlanie tablicy od tylu
    auto *obecny = new Element;
    obecny = ogon;
    while (obecny != nullptr) {
        cout << obecny->wartosc << " | ";
        obecny = obecny->poprzedni;
    }
    cout << endl;
    delete obecny;
}

int lista::rozmiar_listy() {
//Zwróć rozmiar listy
    int rozmiar;
    if (glowa == nullptr) // Jeśli brak elementów to zwróć 0
        return 0;
    else {
        auto *pomocnicza = new Element;
        pomocnicza = glowa;
        rozmiar = 0;
        while (pomocnicza->nastepny != nullptr) {
            rozmiar++;
            pomocnicza = pomocnicza->nastepny;
        }
        rozmiar++;

        return rozmiar;
    }
}


int lista::element_na_pozycji(int pozycja) {
    auto *element = new Element;
    element = glowa;

    for (int i = 0; i < pozycja - 1; i++) {
        element = element->nastepny;
    }
    return element->wartosc;
}

int lista::znajdz_wartosc(int wartosc) {
    auto *element = new Element;
    element = glowa;
    int pozycja = -1;
    int pomocnicza = 0;

    while (element->nastepny != nullptr) {

        if(element->wartosc == wartosc)
        {
            pozycja = pomocnicza;
            break;
        }
        element = element->nastepny;
        pomocnicza++;
    }
    if(element->wartosc == wartosc)
    {
        pozycja = pomocnicza;}
    if (pozycja == -1){
        cout<<"Brak wartosci " + to_string(wartosc) + " w liscie."<<endl;
    }
    else{
        cout<<"Wartosc " + to_string(wartosc) +" znajduje sie na pozycji " + to_string(pozycja)<<endl;
    }
    return pozycja;
}
