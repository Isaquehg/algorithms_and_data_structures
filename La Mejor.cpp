#include <iostream>

using namespace std;

int main(){
    int n;//numero de elementos a inserir
    int maior = 0;//maio elemento
    int cont;//contador
    int num;//elemento

    cin >> n;//entrada de elementos
    
    //entrada de idades
    for(cont = 0; cont < n; cont ++){
        cin >> num;
        while(num < 0){//filtro de idades negativas
            cin >> num;
        }
        if(num > maior){//filtro da maior idade
            maior = num;
        }
    }

    //output
    cout << maior << endl;

    return 0;
}