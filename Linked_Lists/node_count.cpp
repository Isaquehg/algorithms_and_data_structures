#include <iostream>
#include <list>

using namespace std;

int contar(list<int> lista){//numero de nós da lista
    int node = 0;
    list<int>::iterator p;
    for(p = lista.begin(); p != lista.end(); p ++){
        node ++;
    }
    return node;
}
int main(){
    int x;//aux
    int num;//numero a ser inserido
    int result;//resultado da soma dos nodes
    list<int> lista;//lista
    //input
    cin >> x;
    while(x != 0){
        num = x;
        lista.push_back(num);
        cin >> x;
    }
    //output
    result = contar(lista);
    cout << result << endl;

    return 0;
}