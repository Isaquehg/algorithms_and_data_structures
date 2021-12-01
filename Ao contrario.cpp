#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char texto[50];//texto original
    int x;//contador

    //entrada
    cin.getline(texto, 50);
    //exibindo ao contrario
    for(x = strlen(texto); x >= 0; x --){
        cout << texto[x];
    }

    return 0;
}