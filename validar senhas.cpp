#include <iostream>
#include<cstring>

using namespace std;

int main(){
    char senha[10];

    cin >> senha;

    while(strcmp(senha, "12345") != 0){
        cout << "Senha incorreta" << endl;
    }

    return 0;
}