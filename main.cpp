#include <iostream>
#include "Funkcje.h"
#include "lista.h"
#include "Tablica.h"
#include "kopiec.h"
#include "testy.h"
using namespace std;

int main()
{
    int tryb;
    do{
    cout << endl << "Damian Zawolski 260353 SDiZO Projekt 1:" << endl;
    cout << "Wybierz tryb programu:"<<endl;
    cout << "1. Testowanie automatyczne"<<endl;
    cout << "2. Testowanie reczne"<<endl;
    cin >> tryb;
    if (tryb==1)
    {
        testy();
    }
    else if (tryb == 2){
    string nazwa_pliku;
    cout<<"Podaj nazwe pliku: ";
    cin>>nazwa_pliku;
    int wybor;
    int wybor1;
    int wybor2;
    int wybor3;
    bool tablica_ustawiona = false;
    bool lista_ustawiona = false;
    bool kopiec_ustawiony = false;
    auto tablica_dynamiczna = tablicaDynamiczna();
    lista lista_dwukierunkowa;
    kopiec kopiec_binarny;
    int liczbaLiczb = liczbaLiczbWPliku(nazwa_pliku);
    int* liczby = wczytajLiczby(nazwa_pliku);
    do {
        tablica_ustawiona = false;
        lista_ustawiona = false;
        kopiec_ustawiony = false;
        cout << "---------------------" << endl;
        cout << "Menu wyboru:" << endl;
        cout << "1. Tablica dynamiczna" << endl;
        cout << "2. Lista dwukierunkowa" << endl;
        cout << "3. Kopiec binarny" << endl;
        cout << "9. Wyjscie" << endl;
        cout << "---------------------" << endl;
        cout << "Wybierz opcje: ";
        cin >> wybor;

        if (wybor== 1){
            do{
            {
                cout <<endl<< "Tablica" << endl;

                if (tablica_dynamiczna.rozmiar == 0 && !tablica_ustawiona){
                    for (int i=0; i<liczbaLiczb; i++){
                        tablica_dynamiczna.dodaj_na_poczatek(liczby[i]);
                    }
                    tablica_ustawiona = true;
                    tablica_dynamiczna.wyswietl();
                }
                cout << "1. Dodaj element na poczatek tablicy" << endl;
                cout << "2. Dodaj element na koniec tablicy" << endl;
                cout << "3. Dodaj element na wybrany indeks tablicy" << endl;
                cout << "4. Usun pierwszy element z tablicy" << endl;
                cout << "5. Usun ostatni element z tablicy" << endl;
                cout << "6. Usun wybrany element z tablicy" << endl;
                cout << "7. Wyszukaj wartosc w tablicy" << endl;

                cout << "9. Powrot" << endl;
                cin >> wybor1;

                if (wybor1 == 1)
                    {
                        int liczba;
                        cout<<"Jaka liczbe chcialbys dodac na poczatek tablicy?";
                        cin>>liczba;
                        tablica_dynamiczna.dodaj_na_poczatek(liczba);
                        tablica_dynamiczna.wyswietl();
                    }
                else if (wybor1 == 2)
                    {
                        int liczba;
                        cout<<"Jaka liczbe chcialbys dodac na koniec tablicy?";
                        cin>>liczba;
                        tablica_dynamiczna.dodaj_na_koniec(liczba);
                        tablica_dynamiczna.wyswietl();
                    }
                else if (wybor1 == 3)
                    {
                        int liczba, indeks;
                        cout<<"Jaka liczbe chcialbys dodac do tablicy?";
                        cin>>liczba;
                        cout<<"Wybierz indeks na ktory chcesz dodac liczbe "<< liczba<<":";
                        cin>>indeks;
                        tablica_dynamiczna.dodaj_na_pozycje(liczba, indeks);
                        tablica_dynamiczna.wyswietl();
                    }
                else if (wybor1 == 4)
                    {
                        cout<<"Usunieto pierwsza liczbe z tablicy"<< endl;
                        tablica_dynamiczna.usun_pierwszy();
                        tablica_dynamiczna.wyswietl();
                    }
                else if (wybor1 == 5)
                    {
                        cout<<"Usunieto ostatnia liczbe z tablicy"<< endl;
                        tablica_dynamiczna.usun_ostatni();
                        tablica_dynamiczna.wyswietl();
                    }
                else if (wybor1 == 6)
                    {
                        int indeks;
                        cout<<"Ktory element chcialbys usunac z tablicy? Wprowadz indeks: ";
                        cin>>indeks;
                        tablica_dynamiczna.usun(indeks);
                        tablica_dynamiczna.wyswietl();
                    }
                else if (wybor1 == 7)
                {
                    int wartosc;
                    cout<<"Ktory element chcialbys wyszukac w tablicy? Wprowadz wartosc: ";
                    cin>>wartosc;
                    int indeks = tablica_dynamiczna.znajdz_element(wartosc);
                    tablica_dynamiczna.wyswietl();
                    if (indeks == -1){
                        cout<<"Brak wartosci " + to_string(wartosc) + " w tablicy."<<endl;
                    }
                    else{
                        cout<<"Wartosc " + to_string(wartosc) +" znajduje sie na pozycji o indeksie " + to_string(indeks)<<endl;
                    }
                }
                else if (wybor1 == 9){
                        cout << "Powrot" << endl;
                        break;}
                else{
                        cout << "Nieprawidlowy wybor. Sprobuj ponownie." << endl;}}
        } while(wybor1 != 9);}
        else if (wybor == 2){
            do{{
                cout << endl<<"Lista dwukierunkowa"<<endl;
                if (lista_dwukierunkowa.rozmiar==0 && !lista_ustawiona) {
                    for (int i=0; i<liczbaLiczb; i++){
                        lista_dwukierunkowa.dodaj_na_poczatek(liczby[i]);
                }
                    lista_ustawiona = true;
                    cout<<"Lista od przodu"<<endl;
                    lista_dwukierunkowa.wyswietl_od_przodu();
                    cout<<"Lista od tylu"<<endl;
                    lista_dwukierunkowa.wyswietl_od_tylu();
                }
                cout << "1. Dodaj element na poczatek listy" << endl;
                cout << "2. Dodaj element na koniec listy" << endl;
                cout << "3. Dodaj element na wybrane miejsce listy" << endl;
                cout << "4. Usun pierwszy element z listy" << endl;
                cout << "5. Usun ostatni element z listy" << endl;
                cout << "6. Usun wybrany element z listy" << endl;
                cout << "7. Wyszukaj wartosc w tablicy" << endl;
                cout << "9. Powrot" << endl;
                cin >> wybor2;
                if (wybor2==1)
                    {
                        int liczba;
                        cout<<"Jaka liczbe chcialbys dodac na poczatek listy?";
                        cin>>liczba;
                        lista_dwukierunkowa.dodaj_na_poczatek(liczba);
                        cout<<"Lista od przodu"<<endl;
                        lista_dwukierunkowa.wyswietl_od_przodu();
                        cout<<"Lista od tylu"<<endl;
                        lista_dwukierunkowa.wyswietl_od_tylu();
                    }
                else if (wybor2==2)
                    {
                        int liczba;
                        cout<<"Jaka liczbe chcialbys dodac na koniec listy?";
                        cin>>liczba;
                        lista_dwukierunkowa.dodaj_na_koniec(liczba);
                        cout<<"Lista od przodu"<<endl;
                        lista_dwukierunkowa.wyswietl_od_przodu();
                        cout<<"Lista od tylu"<<endl;
                        lista_dwukierunkowa.wyswietl_od_tylu();
                    }
                else if (wybor2==3)
                    {
                        int liczba, indeks;
                        cout<<"Jaka liczbe chcialbys dodac do listy?";
                        cin>>liczba;
                        cout<<"Wybierz indeks na ktory chcesz dodac liczbe "<< liczba<<":";
                        cin>>indeks;
                        lista_dwukierunkowa.dodaj_na_pozycje(liczba, indeks);
                        cout<<"Lista od przodu"<<endl;
                        lista_dwukierunkowa.wyswietl_od_przodu();
                        cout<<"Lista od tylu"<<endl;
                        lista_dwukierunkowa.wyswietl_od_tylu();
                    }
                else if (wybor2==4)
                    {
                        cout<<"Usuwanie pierwszego elementu z listy"<<endl;
                        lista_dwukierunkowa.usun_pierwszy();
                        cout<<"Lista od przodu"<<endl;
                        lista_dwukierunkowa.wyswietl_od_przodu();
                        cout<<"Lista od tylu"<<endl;
                        lista_dwukierunkowa.wyswietl_od_tylu();
                    }
                else if (wybor2==5)
                    {
                        cout<<"Usuwanie ostatniego elementu z listy"<<endl;
                        lista_dwukierunkowa.usun_ostatni();
                        cout<<"Lista od przodu"<<endl;
                        lista_dwukierunkowa.wyswietl_od_przodu();
                        cout<<"Lista od tylu"<<endl;
                        lista_dwukierunkowa.wyswietl_od_tylu();
                    }
                else if (wybor2==6)
                    {
                        int indeks;
                        cout<<"Ktory element chcialbys usunac z listy? Wprowadz indeks: ";
                        cin>>indeks;
                        cout<<"Usuwanie " + to_string(indeks) + " elementu z listy"<<endl;
                        lista_dwukierunkowa.usun(indeks);
                        cout<<"Lista od przodu"<<endl;
                        lista_dwukierunkowa.wyswietl_od_przodu();
                        cout<<"Lista od tylu"<<endl;
                        lista_dwukierunkowa.wyswietl_od_tylu();
                    }
                else if (wybor2 == 7)
                {
                    int wartosc;
                    cout<<"Ktory element chcialbys wyszukac w liscie? Wprowadz wartosc: ";
                    cin>>wartosc;
                    int pozycja = lista_dwukierunkowa.znajdz_wartosc(wartosc);
                    if (pozycja == -1){
                        cout<<"Brak wartosci " + to_string(wartosc) + " w liscie."<<endl;
                    }
                    else{
                        cout<<"Wartosc " + to_string(wartosc) +" znajduje sie na pozycji " + to_string(pozycja)<<endl;
                    }
                    cout<<"Lista od przodu"<<endl;
                    lista_dwukierunkowa.wyswietl_od_przodu();
                    cout<<"Lista od tylu"<<endl;
                    lista_dwukierunkowa.wyswietl_od_tylu();
                }
                else if (wybor2==9) {
                        cout << "Powrot" << endl;
                        break;
                    }
                else{
                        cout << "Nieprawidlowy wybor. Sprobuj ponownie." << endl;}}
        } while(wybor2 != 9);}
        else if (wybor == 3){
            do{
            {
                cout <<endl<< "Kopiec binarny" << endl;
                if (kopiec_binarny.rozmiar==0 && !kopiec_ustawiony) {
                    for (int i=0; i<liczbaLiczb; i++){
                        kopiec_binarny.dodaj(liczby[i]);
                    }
                    kopiec_ustawiony = true;
                    kopiec_binarny.przywroc_wlasciwosci(0);
                }
                kopiec_binarny.wyswietl();
                cout << "1. Dodaj element do kopca" << endl;
                cout << "2. Usun element ze szczytu kopca" << endl;
                cout << "3. Znajdz wartosc w kopcu"<<endl;
                cout << "9. Powrot" << endl;
                cin >> wybor3;

                if (wybor3 == 1)
                    {
                        int liczba;
                        cout<<"Jaka liczbe chcialbys dodac do kopca? ";
                        cin>>liczba;
                        kopiec_binarny.dodaj(liczba);
                        cout<<"Kopiec po dodaniu elementu " + to_string(liczba)<<endl;
                        kopiec_binarny.tablica.wyswietl();
                    }
                else if (wybor3 == 2){

                        cout<<"Usuwanie ze szczytu";
                        kopiec_binarny.usun_ze_szczytu();
                        cout<<"Kopiec po usunieciu elementu ze szczytu"<<endl;
                        kopiec_binarny.tablica.wyswietl();

                    }
                else if (wybor3 == 3){
                        int liczba;
                        cout<<"Jaka wartosc chcialbys znalezc w kopcu? ";
                        cin>>liczba;
                        int czy_znaleziono = kopiec_binarny.znajdz(liczba);
                        if (czy_znaleziono == -1)
                            cout<<"Nie znaleziono wartosci " + to_string(liczba) + " w kopcu"<<endl;
                        else
                            cout<<"Wartosc " + to_string(liczba) + " ma indeks " + to_string(czy_znaleziono) <<endl;
                    }
                else if (wybor3 == 9) {
                    cout << "Powrot" << endl;
                    break;
                }
                else{
                        cout << "Nieprawidlowy wybor. Sprobuj ponownie." << endl;}}
        } while(wybor3 != 9);}
        else if (wybor == 9){

                cout << "Konczenie pracy programu" << endl;
                break;}
        else{
                cout << "Nieprawidlowy wybor. Sprobuj ponownie." << endl;
        }
    } while(wybor != 9);}
    else
    {
        cout<<"Bledny wybor. Konczenie pracy programu";
    }
    return 0;
}while (tryb !=9);}
