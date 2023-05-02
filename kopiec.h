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
    tablicaDynamiczna kopiec_binarny;

    kopiec();

    void dodaj(int liczba);

    void usun();

    void wyswietl();

    bool znajdz(int value);

};
#endif //SDIZO_PROJEKT_1_KOPIEC_H
