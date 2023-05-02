//
// Created by damia on 29.04.2023.
//

#ifndef SDIZO_PROJEKT_1_TABLICA_H
#define SDIZO_PROJEKT_1_TABLICA_H

#include <iostream>

class tablicaDynamiczna {
public:
    int *tablica;
    int rozmiar;

    tablicaDynamiczna();

    void dodaj_na_poczatek(int wartosc);

    void dodaj_na_koniec(int wartosc);

    void dodaj_na_pozycje(int wartosc, int pozycja);

    void usun_ostatni();

    void usun_pierwszy();

    void usun(int pozycja);

    void zamien_elementy(int x, int y);

    int znajdz_element(int wartosc);

    void wyswietl();


};

#endif //SDIZO_PROJEKT_1_TABLICA_H
