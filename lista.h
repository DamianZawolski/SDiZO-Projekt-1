//
// Created by damia on 29.04.2023.
//

#ifndef SDIZO_PROJEKT_1_LISTA_H
#define SDIZO_PROJEKT_1_LISTA_H


struct Element{       //struktura, która tworzy elementy posiadające wskaźnik na element następny i poprzedni - tak jak to się dzieje w liście
    int wartosc{};        //zmienna odpowiadająca za przechowywanie wartości danego elementu
    Element* nastepny;
    Element* poprzedni;

    Element()
    {
        nastepny = nullptr;
        poprzedni = nullptr;
    }
};

class lista
{
public:

    Element* glowa = new Element; //tworzymy element, który będzie początkiem naszej listy
    Element* ogon = new Element;//tworzymy element, który będzie końcem naszej listy
    int rozmiar{};


    lista(); //Konstruktor

    void dodaj_na_poczatek(int wartosc); //funkcja odpowiadająca za dodanie elementu na przód listy

    void dodaj_na_koniec(int wartosc); //funkcja odpowiadająca za dodanie elementu na tył listy

    void dodaj_na_pozycje(int wartosc, int pozycja); //funkcja odpowiadająca za dodanie elementu na dowolną pozycję listy

    void usun_pierwszy(); //funkcja odpowiadająca za usunięcie elementów z przodu listy

    void usun_ostatni(); //funkcja odpowiadająca za usunięcie elementów z tyłu listy

    void usun(int pozycja); //funkcja odpowiadająca za usunięcie elementów z tyłu listy

    void wyswietl_od_przodu(); //funkcja odpowiadająca za wyświetlenie elementów od początku listy

    void wyswietl_od_tylu(); //funkcja odpowiadająca za wyświetlenie elementów od końca listy

    int element_na_pozycji(int pozycja);

    int znajdz_wartosc(int wartosc);

    int rozmiar_listy();

};

#endif //SDIZO_PROJEKT_1_LISTA_H
