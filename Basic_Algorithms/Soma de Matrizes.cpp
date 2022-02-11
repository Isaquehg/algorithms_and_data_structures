#include <iostream>

using namespace std;

int main(){
    int mat1[100][100], mat2[100][100];//matrizes a somar
    int mat3[100][100];//matriz resultante
    int l, c;//contadores
    int nlinhas, ncolunas;//numero de linhas e colunas

    //input
    cin >> nlinhas >> ncolunas;
    //matriz 1
    for(l = 0; l < nlinhas; l ++){
        for(c = 0; c < ncolunas; c ++){
            cin >> mat1[l][c];
        }
    }
    //matriz 2
    for(l = 0; l < nlinhas; l ++){
        for(c = 0; c < ncolunas; c ++){
            cin >> mat2[l][c];
        }
    }
    //soma das matrizes
    for(l = 0; l < nlinhas; l ++){
        for(c = 0; c < ncolunas; c ++){
            mat3[l][c] = mat1[l][c] + mat2[l][c];
        }
    }
    //output
    for(l = 0; l < nlinhas; l ++){
        for(c = 0; c < ncolunas; c ++){
            cout << mat3[l][c] << " ";
        }
        cout << endl;
    }

    return 0;
}