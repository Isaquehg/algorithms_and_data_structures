#include <iostream>

using namespace std;

int main(){
    char cod;//codigo do continente

    cin >> cod;

    switch(cod){
        case 'a':
            cout << "Africa" << endl;
            break;
        case 'b':
            cout << "America" << endl;
            break;
        case 'c':
            cout << "Antartida" << endl;
            break;
        case 'd':
            cout << "Asia" << endl;
            break;
        case 'e':
            cout << "Europa" << endl;
            break;
        case 'f':
            cout << "Oceania" << endl;
    }

    return 0;
}