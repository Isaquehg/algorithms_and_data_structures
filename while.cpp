#include<iostream>

using namespace std;

int main(){
    int idade, aux=0;
    
    do{
        cin >> idade;
        if(idade <= 7){
            aux++;
       }
    }while(idade >= 0);

    cout << "Idades menores/iguais a 7 anos: " << aux << endl;
}