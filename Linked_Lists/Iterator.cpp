#include <iostream>
#include <list>

using namespace std;

int main(){
    int soma = 0;
    list<int> lista;//list
    list<int>::iterator p;//list iterator
    //insertion
    lista.push_back(2);
    lista.push_back(1);
    lista.push_back(3);
    //output
    for(p = lista.begin(); p != lista.end(); p ++){
        cout << *p << " ";
        soma += *p;
    }
    cout << endl;
    cout << "soma = " << soma << endl;
    //emptying memory
    while(!lista.empty())
        lista.pop_front();

    return 0;
}