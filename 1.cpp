#include <iostream>
#include <iomanip>

using namespace std;

float mediaImpares(int *vetor, int N){
    int *q;//pointer p varrer
    int j;//aux
    int N_impares = 0;//quantidade de num impares no vetor
    float med = 0.0;//media impares
    //calculando med
    q = vetor;
    for(j = 0; j < N; j ++){
        if(*q % 2 != 0){
            med += *q;
            N_impares ++;
        }
        q ++;
    }
    med /= (N_impares * 1.0);
    //output func
    return med;
}

int main(){
    int tam;//tamanho vetor
    int i;//aux
    float media_imp;//media dos impares
    int *vet = NULL;//vetor armaz
    int *p;//input pointer
    //input
    cin >> tam;
    vet = new int[tam];//din mem aloc
    p = vet;
    for(i = 0; i < tam; i ++){
        cin >> *p;
        p ++;
    }
    //calculando media
    media_imp = mediaImpares(vet, tam);
    //output
    cout << fixed << setprecision(2);
    cout << "Media dos elementos impares: " << media_imp << endl;

    return 0;
}