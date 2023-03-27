//
// Created by damia on 27.03.2023.
//

#ifndef SDIZO_PROJEKT_1_FUNKCJE_H
#define SDIZO_PROJEKT_1_FUNKCJE_H


class Funkcje {
#include <iostream>
#include <fstream>

using namespace std;

void wczytajLiczby() {
    ifstream plik("liczby.txt");
    int liczby[10];

    if (plik.is_open()) {
        for (int i = 0; i < 10; i++) {
            plik >> liczby[i];
        }
        plik.close();

        // Wyświetlenie wczytanych liczb
        cout << "W#include <iostream>\n"
                "#include <fstream>\n"
                "\n"
                "using namespace std;\n"
                "\n"
                "void wczytajLiczby() {\n"
                "    ifstream plik(\"liczby.txt\");\n"
                "    int liczby[10];\n"
                "\n"
                "    if (plik.is_open()) {\n"
                "        for (int i = 0; i < 10; i++) {\n"
                "            plik >> liczby[i];\n"
                "        }\n"
                "        plik.close();\n"
                "\n"
                "        // Wyświetlenie wczytanych liczb\n"
                "        cout << \"Wczytane liczby: \";\n"
                "        for (int i = 0; i < 10; i++) {\n"
                "            cout << liczby[i] << \" \";\n"
                "        }\n"
                "        cout << endl;\n"
                "    } else {\n"
                "        cout << \"Nie udało się otworzyć pliku!\" << endl;\n"
                "    }\n"
                "}czytane liczby: ";
        for (int i = 0; i < 10; i++) {
            cout << liczby[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Nie udało się otworzyć pliku!" << endl;
    }
}

};


#endif //SDIZO_PROJEKT_1_FUNKCJE_H
