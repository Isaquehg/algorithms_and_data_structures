#include <iostream>

using namespace std;

int main(){
    int mat[100][100];//matriz 2x2
    int transposta[100][100];//matriz transposta
    int determinante;//determinante da matriz
    int l, c;//contadores
    //input
    for(l = 0; l < 2; l ++){
        for(c = 0; c < 2; c ++)
            cin >> mat[l][c];
    }
    //calculo determinante
    determinante = (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);
    //transpondo
    for(c = 0; c < 2; c ++){
        for(l = 0; l < 2; l ++)
            transposta[c][l] = mat[l][c];
    }
    //output
    //matriz
    cout << "M:" << endl;
    for(l = 0; l < 2; l ++){
        for(c = 0; c < 2; c ++)
            cout << mat[l][c] << " ";
        cout << endl;
    }
    //transposta
    cout << "M transposta:" << endl;
    for(c = 0; c < 2; c ++){
        for(l = 0; l < 2; l ++)
            cout << transposta[c][l] << " ";
        cout << endl;
    }
    //determinante
    cout << "Determinante: " << determinante << endl;

    return 0;
}