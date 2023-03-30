#include <iostream>
#include "Funkcje.h"
using namespace std;

int main()
{
    cout << endl << "Damian Zawolski 260353 SDiZO Projekt 1:" << endl;
    int wybor;
    int liczbaLiczb = liczbaLiczbWPliku();
    int* liczby = wczytajLiczby();
    do {
        cout << "---------------------" << endl;
        cout << "Menu wyboru:" << endl;
        cout << "1. Tablica" << endl;
        cout << "2. Lista" << endl;
        cout << "3. Kopiec binarny" << endl;
        cout << "4. Drzewo BST" << endl;
        cout << "9. Wyjscie" << endl;
        cout << "---------------------" << endl;
        cout << "Wybierz opcje: ";
        cin >> wybor;

        switch(wybor) {
            case 1:
            {
                cout << "Wybrano opcje 1 Tablica" << endl;
                int* tablicaWyjsciowa;
                if (tablicaWyjsciowa== nullptr){
                    tablicaWyjsciowa = kopiujTablice(liczby, liczbaLiczb);
                }
                int wybor2;
                cout << "1. Dodaj element do tablicy" << endl;
                cout << "2. Usun element z tablicy" << endl;
                cout << "9. Powrot" << endl;
                cin >> wybor2;
                switch(wybor2) {
                    case 1:
                    {
                        int liczba, indeks;
                        cout<<"Jaka liczbe chcialbys dodac do tablicy?";
                        cin>>liczba;
                        cout<<"Wybierz indeks na ktory chcesz dodac liczbe "<< liczba<<":";
                        cin>>indeks;
                        tablicaWyjsciowa = dodaj_liczbe(tablicaWyjsciowa, liczbaLiczb, liczba, indeks);
                    break;
                    }
                    case 2:
                    {
                        int indeks;
                        cout<<"Ktory element chcialbys usunal tablicy? Wprowadz indeks: ";
                        cin>>indeks;
                        tablicaWyjsciowa = usun_liczbe(tablicaWyjsciowa, liczbaLiczb, indeks);
                        break;
                    }
                    case 9:
                        cout << "Powrót" << endl;
                        break;
                    default:
                        cout << "Nieprawidlowy wybór. Sprobuj ponownie." << endl;}}
            case 2:
                cout << "Wybrano opcje 2 Lista" << endl;
                break;
            case 3:
                cout << "Wybrano opcje 3 Kopiec binarny" << endl;
                break;
            case 4:
                cout << "Wybrano opcje 4 Drzewo BST" << endl;
                break;
            case 9:
                cout << "Konczenie pracy programu" << endl;
                break;
            default:
                cout << "Nieprawidlowy wybór. Sprobuj ponownie." << endl;
        }
    } while(wybor != 9);

    return 0;
}
