#include <iostream>

using namespace std;

int main(){
    int vet[100];//vetor p armazenar
    int n;//quantidade de numeros a inserir
    int qn = 0;//quantidade de negativos
    int x;//contador

    //input
    cin >> n;
    for(x = 0; x < n; x ++){
        cin >> vet[x];
    }
    //contagem de negativos e output
    for(x = 0; x < n; x ++){
        if(vet[x] < 0){//se for negativo
            vet[x] = 0;
            qn ++;
        }
        cout << vet[x] << " ";
    }
    cout << "\n";
    cout << qn << endl;

    return 0;
}