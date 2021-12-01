#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int n;//qnt a inserir
    int vet[50];//vetor de armazenamento
    int x;//contador
    int num;//numero a procurar
    double vezes = 0.0;//vezes q um numero apareceu

    //input
    cin >> n;
    for(x = 0; x < n; x ++){
        cin >> vet[x];
    }
    cin >> num;
    //encontrar dado numero(num)
    for(x = 0; x < n; x ++){
        if(vet[x] == num)
            vezes += 1.0;
    }
    //output
    cout << fixed << setprecision(2);
    cout << vezes / (double)(n) * 100.0 << endl;

    return 0;
}