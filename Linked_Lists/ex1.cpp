#include <iostream>
#include <list>

using namespace std;

bool encontrar(list<float> lista, float x){//buscando na lista
    list<float>::iterator p;//iterator p lista
    for(p = lista.begin(); p != lista.end(); p ++){
        if(*p == x)
            return true;
    }
    return false;
}
int main(){
    int n;//numero a pesquisar
    int num;//numero a inserir
    int x;//numero de entradas
    bool result;//verificar se foi encontrado
    list<float> lista;//lista
    //input
    cin >> x;
    while(x != 0){
        num = x;
        lista.push_back(num);
        cin >> x;
    }
    cin >> n;
    //buscar numero
    result = encontrar(lista, n);
    //output
    if(result == false){
        cout << "Nao encontrado" << endl;
    }
    else
        cout << "Encontrado" << endl;

    return 0;
}