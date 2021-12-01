#include <iostream>

using namespace std;

int main(){
    char mat[100][100];//matriz para a cifra
    char codigo[100];//codigo recebido
    int nlinhas, ncolunas;//numero de linhas e colunas
    int l, c, j = 0;//contadores

    //input
    cin >> nlinhas >> ncolunas;
    cin >> codigo;
    //atribuição código-matriz
    for(l = 0; l < nlinhas; l ++){
        for(c = 0; c < ncolunas; c ++){
            mat[l][c] = codigo[j];
            j ++;
        }
    }
    //ouput invertido
    for(c = 0; c < ncolunas; c ++){
        for(l = 0; l < nlinhas; l ++)
            cout << mat[l][c];
    }

    return 0;
}