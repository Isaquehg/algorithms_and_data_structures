#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char word1[50];//palavra a entrar
    char word2[50];//palavra a entrar
    int x;//contador

    cin >> word1 >> word2;
    if(strcmp(word1, word2) == 0){//se forem iguais
        for(x = 0; x < strlen(word1); x ++){
            if(isdigit(word1[x]) == true)//se for digito
                continue;
            else
                cout << word1[x];
        }
    }
    else{//se nao forem iguais
        cout << "Nao sao iguais!" << endl;
    }

    return 0;
}