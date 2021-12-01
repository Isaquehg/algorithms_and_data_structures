#include <iostream>
#include <list>

using namespace std;

int soma(list<int> lista){//soma dos elem da lista
    list<int>::iterator p;//iterator p lista
    int s = 0;//soma de elementos
    for(p = lista.begin(); p != lista.end(); p ++){
        s += *p;
    }
    return s;
}
int main(){
    int x;//aux
    int num;//numero a ser inserido
    int result;//resultado da soma
    list<int> lista;//lista
    //input
    cin >> x;
    while(x != 0){
        num = x;
        lista.push_back(num);
        cin >> x;
    }
    //somando
    result = soma(lista);
    //output
    cout << result << endl;

    return 0;
}