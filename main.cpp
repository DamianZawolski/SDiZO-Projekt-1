#include <iostream>
#include "Funkcje.h"
using namespace std;

int main()
{
    int wybor;
    int liczbaLiczb = 10;
    do {
        cout << endl << "Damian Zawolski 260353 SDiZO Projekt 1:" << endl;
        int* liczby = wczytajLiczby(liczbaLiczb);
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
                int* tablicaWyjsciowa = kopiujTablice(liczby, liczbaLiczb);
                break;}
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
