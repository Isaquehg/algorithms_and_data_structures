#include <iostream>

using namespace std;

int main(){
    int mat[10][10];//matriz para a cifra
    int qrcode[10];//codigo recebido
    int nlinhas = 3, ncolunas = 3;//numero de linhas e colunas
    int l, c, j;//contadores
    bool homem;//verificar pela entrada o sexo

    //input
    for(j = 0; j < 9; j ++)
        cin >> qrcode[j];
    if(qrcode[1] == 0)
        homem = false;
    else
        homem = true;
    //atribuição
    j = 0;
    for(l = 0; l < 3; l ++){
        for(c = 0; c < 3; c ++){
                mat[l][c] = qrcode[j];
                j ++;
        }
    }
    //output
    if(homem == true)
        cout << "MASCULINO" << endl;
    else
        cout << "FEMININO" << endl;

    return 0;
}