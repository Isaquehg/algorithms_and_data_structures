#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
int main(){
    int n;
    int vet[10];
    int tam = 0;
    // 4 2 1 5 3 
    // 1 2 4 5 3
    // 1 2 4 5 3
    // 1 2 3 5 4
    // 1 2 3 4 5
    cin >> n;
    while(n != -1){
        vet[tam] = n;
        tam++;
        cin >> n;
    }
    for(int i = 0; i < tam; i++){
        int menor;
        int posmenor;
        for(int j = i; j < tam; j++){
            if(j == i || vet[j] < menor){
                menor = vet[j];
                posmenor = j;
            }
        }
        int aux = vet[i];
        vet[i] = vet[posmenor];
        vet[posmenor] = aux;
    }
    for(int i = 0; i < tam; i++)
        cout << vet[i] << ' ';
}