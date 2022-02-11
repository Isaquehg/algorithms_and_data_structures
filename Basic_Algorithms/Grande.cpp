#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char nome[50];//nome a entrar do funcionario
    int n;//numero de letras do funcionario
    int maiusculas = 0;//numero de maiusculas
    int x;//contador
    
    //input
    cin >> n;
    cin.ignore();
    cin.getline(nome, 50);
    //encontrando as maiusculas
    for(x = 0; x < n; x ++){
        if(isupper(nome[x]))
            maiusculas ++;
    }
    //output
    cout << maiusculas << endl;

    return 0;
}