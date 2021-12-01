#include <iostream>

using namespace std;

int main(){
    int *vet = NULL;//vector
    int tam;//vector's size
    int i;

    //input
    cin >> tam;
    vet = new int[tam];//memory alocation
    for(i = 0; i < tam; i ++)
        cin >> vet[i];
    //output
    for(i = 0; i < tam; i ++)
        cout << vet[i] << " ";
    cout << endl;

    delete [] vet;//garbage collector

    return 0;
}