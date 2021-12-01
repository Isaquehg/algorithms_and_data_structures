#include <iostream>
#include <list>
#include <iomanip>

using namespace std;

float calcSoma(list<float> lista){
    list<float>::iterator p;//iterator p lista
    float s = 0.0;//soma de elementos
    for(p = lista.begin(); p != lista.end(); p ++){
        s += *p;
    }
    return s;
}

int main(){
    list<float> lista;//lista ligada
    float num;//num a ser inserido
    float soma;//result da soma
    float x;//aux
    //input
    cin >> x;
    while(x != 0){
        num = x;
        lista.push_back(num);
        cin >> x;
    }
    //soma
    soma = calcSoma(lista);
    //output
    cout << fixed << setprecision(2);
    cout << "soma = " << soma << endl;

    return 0;
}