#include <iostream>
#include "Funkcje.h"
#include "lista.h"
#include "Tablica.h"
#include "kopiec.h"
#include <random>
#include <windows.h>
#include <iomanip>
#include <fstream>

using namespace std;


int losowa_w_zakresie(int minimalna, int maksymalna)
{
    int val;
    random_device rd; // non-deterministic generator
    mt19937 gen(rd()); // random engine seeded with rd()
    uniform_int_distribution<> dist(minimalna, maksymalna); // distribute results between
    val = dist(gen); // pass the generator to the distribution
    return(val);
}

long long int read_QPC()
{
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    return((long long int)count.QuadPart);
}

int* losowe(int liczba)
{
    static int liczby[1000000];
    int val, min, max;
    random_device rd; // non-deterministic generator
    mt19937 gen(rd()); // random engine seeded with rd()
    uniform_int_distribution<> dist(1, 1000000); // distribute results between
    // 1 and 1000000 inclusive
    min = INT_MAX;
    max = 0;
    for (int i = 0; i < liczba; i++)
    {

        val = dist(gen); // pass the generator to the distribution
        if(val < min)
            min = val;
        if(val > max)
            max = val;
        liczby[i] = val;
    }
    cout << "min = " << min << " max = " << max << endl;
    return(liczby);
}

int testy(){
    srand(time(NULL));
    int liczba;
    cout<<"Podaj liczbe liczb do testow: ";
    cin>>liczba;
    int* tablica_liczb = losowe(liczba);

    long long int kopiec_znajdz, kopiec_usun, kopiec_dodaj, tablica_usun_pierwszy, tablica_usun_ostatni, lista_usun_srodkowy,lista_usun_pierwszy, lista_usun_ostatni, tablica_usun_srodkowy, tablica_szukanie, lista_szukanie, tablica_dodawanie_na_poczatek, tablica_dodawanie_na_koniec, tablica_dodawanie_na_srodek, lista_dodawanie_na_poczatek, lista_dodawanie_na_koniec, lista_dodawanie_na_srodek, czestotliwosc, start;
    QueryPerformanceFrequency((LARGE_INTEGER *)&czestotliwosc);
    auto tablica_dynamiczna1 = tablicaDynamiczna();
    auto tablica_dynamiczna2 = tablicaDynamiczna();
    auto tablica_dynamiczna3 = tablicaDynamiczna();

    start = read_QPC(); //rozpoczynamy liczenie czasu
    for (int i=0; i<liczba; i++){
        tablica_dynamiczna1.dodaj_na_poczatek(tablica_liczb[i]);}
    tablica_dodawanie_na_poczatek = read_QPC() - start; //kończymy liczenie czasu
    cout << "Czas dodawania na poczatek tablicy [s] = " << fixed << setprecision(3) << (float)tablica_dodawanie_na_poczatek /
                                                                                     czestotliwosc << endl;

    start = read_QPC(); //rozpoczynamy liczenie czasu
    for (int i=0; i<liczba; i++){
        tablica_dynamiczna2.dodaj_na_koniec(tablica_liczb[i]);}
    tablica_dodawanie_na_koniec = read_QPC() - start; //kończymy liczenie czasu
    cout << "Czas dodawania na koniec tablicy [s] = " << fixed << setprecision(3) << (float)tablica_dodawanie_na_koniec /
                                                                                   czestotliwosc << endl;
    start = read_QPC(); //rozpoczynamy liczenie czasu
    for (int i=0; i<liczba; i++){
        tablica_dynamiczna3.dodaj_na_pozycje(tablica_liczb[i],i/2);}
    tablica_dodawanie_na_srodek = read_QPC() - start; //kończymy liczenie czasu
    cout << "Czas dodawania na srodek tablicy [s] = " << fixed << setprecision(3) << (float)tablica_dodawanie_na_srodek /
                                                                                   czestotliwosc << endl;
    lista lista_dwukierunkowa1;
    lista lista_dwukierunkowa2;
    lista lista_dwukierunkowa3;
    start = read_QPC(); //rozpoczynamy liczenie czasu
    for (int i=0; i<liczba; i++){
        lista_dwukierunkowa1.dodaj_na_poczatek(tablica_liczb[i]);}
    lista_dodawanie_na_poczatek = read_QPC() - start; //kończymy liczenie czasu
    cout << "Czas dodawania na poczatek listy [s] = " << fixed << setprecision(3) << (float)lista_dodawanie_na_poczatek /
                                                                                       czestotliwosc << endl;

    start = read_QPC(); //rozpoczynamy liczenie czasu
    for (int i=0; i<liczba; i++){
        lista_dwukierunkowa2.dodaj_na_koniec(tablica_liczb[i]);}
    lista_dodawanie_na_koniec = read_QPC() - start; //kończymy liczenie czasu
    cout << "Czas dodawania na koniec listy [s] = " << fixed << setprecision(3) << (float)lista_dodawanie_na_koniec /
                                                                                     czestotliwosc << endl;
    start = read_QPC(); //rozpoczynamy liczenie czasu
    for (int i=0; i<liczba; i++){
        lista_dwukierunkowa3.dodaj_na_pozycje(tablica_liczb[i],i/2);}
    lista_dodawanie_na_srodek = read_QPC() - start; //kończymy liczenie czasu
    cout << "Czas dodawania na srodek listy [s] = " << fixed << setprecision(3) << (float)lista_dodawanie_na_srodek /
                                                                                     czestotliwosc << endl;
    start = read_QPC(); //rozpoczynamy liczenie czasu
    for (int i=0; i<liczba; i++){
        tablica_dynamiczna1.znajdz_element(tablica_liczb[losowa_w_zakresie(0,liczba)]);}
    tablica_szukanie = read_QPC() - start; //kończymy liczenie czasu
    cout << "Czas wyszukiwania losowych elementow z tablicy [s] = " << fixed << setprecision(3) << (float)tablica_szukanie /
                                                                                   czestotliwosc << endl;
    start = read_QPC(); //rozpoczynamy liczenie czasu
    for (int i=0; i<liczba; i++){
        lista_dwukierunkowa1.znajdz_wartosc(tablica_liczb[losowa_w_zakresie(0,liczba)]);}
    lista_szukanie = read_QPC() - start; //kończymy liczenie czasu
    cout << "Czas wyszukiwania losowych elementow z listy [s] = " << fixed << setprecision(3) << (float)lista_szukanie /
                                                                                   czestotliwosc << endl;
    start = read_QPC(); //rozpoczynamy liczenie czasu
    for (int i=0; i<liczba; i++){
        tablica_dynamiczna1.usun_pierwszy();}
    tablica_usun_pierwszy = read_QPC() - start; //kończymy liczenie czasu
    cout << "Czas usuwania z poczatku tablicy [s] = " << fixed << setprecision(3) << (float)tablica_usun_pierwszy /
                                                                                       czestotliwosc << endl;

    start = read_QPC(); //rozpoczynamy liczenie czasu
    for (int i=0; i<liczba; i++){
        tablica_dynamiczna2.usun_ostatni();}
    tablica_usun_ostatni = read_QPC() - start; //kończymy liczenie czasu
    cout << "Czas usuwania z konca tablicy [s] = " << fixed << setprecision(3) << (float)tablica_usun_ostatni /
                                                                                     czestotliwosc << endl;
    start = read_QPC(); //rozpoczynamy liczenie czasu
    for (int i=0; i<liczba; i++){
        tablica_dynamiczna3.usun((liczba-i)/2);}
    tablica_usun_srodkowy = read_QPC() - start; //kończymy liczenie czasu
    cout << "Czas usuwania ze srodka tablicy [s] = " << fixed << setprecision(3) << (float)tablica_usun_srodkowy /
                                                                                     czestotliwosc << endl;
   start = read_QPC(); //rozpoczynamy liczenie czasu
    for (int i=0; i<liczba; i++){
        lista_dwukierunkowa1.usun_pierwszy();}
    lista_usun_pierwszy = read_QPC() - start; //kończymy liczenie czasu
    cout << "Czas usuwania z poczatku listy [s] = " << fixed << setprecision(3) << (float)lista_usun_pierwszy /
                                                                                       czestotliwosc << endl;

    start = read_QPC(); //rozpoczynamy liczenie czasu
    for (int i=0; i<liczba; i++){
        lista_dwukierunkowa2.usun_ostatni();}
    lista_usun_ostatni = read_QPC() - start; //kończymy liczenie czasu
    cout << "Czas usuwania z konca listy [s] = " << fixed << setprecision(3) << (float)lista_usun_ostatni /
                                                                                     czestotliwosc << endl;
    start = read_QPC(); //rozpoczynamy liczenie czasu
    for (int i=0; i<liczba-1; i++){
        lista_dwukierunkowa3.usun(floor((liczba-i)/2));}

    lista_usun_srodkowy = read_QPC() - start; //kończymy liczenie czasu
    cout << "Czas usuwania ze srodka listy [s] = " << fixed << setprecision(3) << (float)lista_usun_srodkowy /
        czestotliwosc << endl;
    auto kopiec_binarny = kopiec();
    start = read_QPC(); //rozpoczynamy liczenie czasu
    for (int i=0; i<liczba; i++){
        kopiec_binarny.dodaj(tablica_liczb[i]);}
    kopiec_dodaj = read_QPC() - start; //kończymy liczenie czasu
    cout << "Czas dodawania elementow do kopca [s] = " << fixed << setprecision(3) << (float)kopiec_dodaj /
                                                                                  czestotliwosc << endl;

    start = read_QPC(); //rozpoczynamy liczenie czasu
    for (int i=0; i<liczba; i++){
        kopiec_binarny.znajdz(tablica_liczb[losowa_w_zakresie(0,kopiec_binarny.kopiec_binarny.rozmiar)]);}
    kopiec_znajdz = read_QPC() - start; //kończymy liczenie czasu
    cout << "Czas znajdowania elementow w kopcu [s] = " << fixed << setprecision(3) << (float)kopiec_znajdz /
                                                                          czestotliwosc << endl;
    start = read_QPC(); //rozpoczynamy liczenie czasu
    for (int i=0; i<liczba-1; i++){
        kopiec_binarny.usun();}
    kopiec_usun = read_QPC() - start; //kończymy liczenie czasu
    cout << "Czas usuwania elementow z kopca [s] = " << fixed << setprecision(3) << (float)kopiec_usun /
                                                                                  czestotliwosc << endl;

    system("pause");
    fstream plik("wyniki.txt", ios::out);

    if (plik.is_open()) {
        plik << fixed << setprecision(3) << (float)lista_dodawanie_na_poczatek /
                                            czestotliwosc << endl;
        plik << fixed << setprecision(3) << (float)lista_dodawanie_na_koniec /
                                            czestotliwosc << endl;
        plik << fixed << setprecision(3) << (float)lista_dodawanie_na_srodek /
                                            czestotliwosc << endl;
        plik << fixed << setprecision(3) << (float)lista_usun_pierwszy /
                                            czestotliwosc << endl;
        plik << fixed << setprecision(3) << (float)lista_usun_ostatni /
                                            czestotliwosc << endl;
        plik << fixed << setprecision(3) << (float)lista_usun_srodkowy /
                                            czestotliwosc << endl;
         plik << fixed << setprecision(3) << (float)lista_szukanie /
                                            czestotliwosc << endl;

        plik << endl;
        plik << fixed << setprecision(3) << (float)tablica_dodawanie_na_poczatek /
                                            czestotliwosc << endl;
        plik << fixed << setprecision(3) << (float)tablica_dodawanie_na_koniec /
                                            czestotliwosc << endl;
        plik << fixed << setprecision(3) << (float)tablica_dodawanie_na_srodek /
                                            czestotliwosc << endl;
        plik << fixed << setprecision(3) << (float)tablica_usun_pierwszy /
                                            czestotliwosc << endl;
        plik << fixed << setprecision(3) << (float)tablica_usun_ostatni /
                                            czestotliwosc << endl;
        plik << fixed << setprecision(3) << (float)tablica_usun_srodkowy /
                                            czestotliwosc << endl;
        plik << fixed << setprecision(3) << (float)tablica_szukanie /
                                            czestotliwosc << endl;
        plik << endl;
        plik << fixed << setprecision(3) << (float)kopiec_dodaj /
                                            czestotliwosc << endl;
        plik << fixed << setprecision(3) << (float)kopiec_usun /
                                            czestotliwosc << endl;
        plik << fixed << setprecision(3) << (float)kopiec_znajdz /
                                            czestotliwosc << endl;
        plik.close();}
    else {
        cout << "Nie udało się utworzyć pliku." << endl;
    }
    return 0;
}

