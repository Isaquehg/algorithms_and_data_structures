#include <iostream>

using namespace std;

//deixar a primeira dimensão vazia e a outra preenchida
int traco(int mat[][10], int dime){
    int li, co;//contadores2
    int soma = 0;//soma da diag principal
    for(li = 0; li < dime; li ++){
        for(co = 0; co < dime; co ++){
            if(co == li)
                soma += mat[li][co];
        }
    }
    return soma;
}
int main(){
    int matriz[10][10];//matriz da entrada
    int l, c;//contadores
    int dim;//dimensão da matriz
    int result;//valor do traco da matriz
    //input
    cin >> dim;
    for(l = 0; l < dim; l ++){
        for(c = 0; c < dim; c ++){
            cin >> matriz[l][c];
        }
    }
    //Atribuindo retorno da função
    result = traco(matriz, dim);
    //output
    cout << "traco = " << result << endl;

    return 0;
}