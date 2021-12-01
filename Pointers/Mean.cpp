#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int *vet = NULL;//vetor p armazenar
    int *p;//pointer p varrer
    int *m;//pointer p media
    int tam;//tamanho vet
    int i;//aux
    double med = 0.0;//media dos valores
    //input
    cin >> tam;
    vet = new int[tam];//alocando
    p = vet;
    for(i = 0; i < tam; i ++){
        cin >> *p;
        p ++;
    }
    //media
    m = vet;
    for(i = 0; i < tam; i ++){
        med += *m;
        m ++;
    }
    med /= tam * 1.0;
    //output
    cout << fixed << setprecision(2);
    cout << med << endl;

    delete [] vet;
    
    return 0;
}