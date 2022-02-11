#include <iostream>

using namespace std;

//deixar a primeira dimensão vazia e a outra preenchida
int soma(int mat[][4]){
    int li, co;//contadores
    int total = 0;//somatoria
    for(li = 0; li < 3; li ++){
        for(co = 0; co < 4; co ++){
            total += mat[li][co];
        }
    }
    return total;
}
int main(){
    int matriz[3][4];//matriz da entrada
    int l, c;//contadores
    int result;//valor da soma dos elementos da matriz
    //input
    for(l = 0; l < 3; l ++){
        for(c = 0; c < 4; c ++){
            cin >> matriz[l][c];
        }
    }
    //enviando valores p função
    result = soma(matriz);
    //output
    cout << "soma = " << result << endl;

    return 0;
}