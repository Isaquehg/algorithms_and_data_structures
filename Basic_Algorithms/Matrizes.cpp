#include <iostream>

using namespace std;

int main(){
    int mat[2][3];//linhas - colunas
    int nlinhas = 2;
    int ncolunas = 3;
    int l = 0, c;//colunas
    //atribuição
    mat[0][0] = 12;
    mat[0][1] = 24;
    mat[0][2] = 37;
    mat[1][0] = 23;
    mat[1][1] = -2;
    mat[1][2] = 15;
    //primeira linha
    for(c = 0; c < ncolunas; c ++)
        cout << mat[l][c] << " ";
    cout << endl;
    //segunda coluna
    c = 1;
    for(l = 0; l < nlinhas; l ++)
        cout << mat[l][c] << endl;
    //mostrar matriz por colunas
    //se quiser mostrar por linhas, inverter c e l!!!
    for(c = 0; c < ncolunas; c ++){
        for(l = 0; l < nlinhas; l ++){
            cout << mat[l][c] << " ";
        }
    }
    //para somar matrizes, elas devem possuir o mesmo tamanho
    return 0;
}