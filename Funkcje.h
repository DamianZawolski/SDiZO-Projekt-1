//
// Created by damia on 27.03.2023.
//

#ifndef SDIZO_PROJEKT_1_FUNKCJE_H
#define SDIZO_PROJEKT_1_FUNKCJE_H

int* wczytajLiczby();

int* kopiujTablice(int* tablicaWejsciowa, int rozmiarTablicy);

int liczbaLiczbWPliku();

int* dodaj_liczbe(int* tablicaWejsciowa, int liczbaLiczb, int liczba,int indeks);

int* usun_liczbe(int* tablicaWejsciowa, int liczbaLiczb, int indeks);

struct Wezel;

void dodaj_do_listy(Wezel** adres_glowy, int elementy[], int n);

void wyswietl_liste(Wezel* glowa);

void dodaj_do_listy(Wezel** adres_glowy, int nowa_wartosc, int pozycja);

long long int read_QPC();

void usun_z_listy(Wezel** adres_glowy, int pozycja);

#endif //SDIZO_PROJEKT_1_FUNKCJE_H
