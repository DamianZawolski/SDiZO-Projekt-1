//
// Created by damia on 01.05.2023.
//

#ifndef SDIZO_PROJEKT_1_KOPIEC_H
#define SDIZO_PROJEKT_1_KOPIEC_H

#include <iostream>
#include "Tablica.h"

class kopiec{
public:

    int rozmiar;
    tablicaDynamiczna tablica;

    kopiec();

    void dodaj(int liczba);

    void usun_ze_szczytu();

    void wyswietl();

    void znajdz(int value);

    void przywroc_wlasciwosci(int indeks);

    int lewe_dziecko(int indeks);

    int prawe_dziecko(int indeks);

};
#endif //SDIZO_PROJEKT_1_KOPIEC_H
