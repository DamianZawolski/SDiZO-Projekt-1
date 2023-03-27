#include <iostream>

using namespace std;

int main()
{
    int wybor;

    do {
        cout << "Damian Zawolski 260353 SDiZO Projekt 1:" << endl;
        cout << "Menu wyboru:" << endl;
        cout << "1. Tablica" << endl;
        cout << "2. Lista" << endl;
        cout << "3. Kopiec binarny" << endl;
        cout << "4. Drzewo BST" << endl;
        cout << "9. Wyjście" << endl;
        cout << "Wybierz opcję: ";
        cin >> wybor;

        switch(wybor) {
            case 1:
                cout << "Wybrano opcję 1 Tablica" << endl;
                break;
            case 2:
                cout << "Wybrano opcję 2 Lista" << endl;
                break;
            case 3:
                cout << "Wybrano opcję 3 Kopiec binarny" << endl;
                break;
            case 4:
                cout << "Wybrano opcję 4 Drzewo BST" << endl;
                break;
            case 9:
                cout << "Wybrano wyjście. Do widzenia!" << endl;
                break;
            default:
                cout << "Nieprawidłowy wybór. Spróbuj ponownie." << endl;
        }
    } while(wybor != 9);

    return 0;
}
