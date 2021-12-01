#include <iostream>

using namespace std;

int h1(int k, int m){//probe1
    int h = k % m;//formula
    if(h < 0)
        h += m;
    return h;
}
int h2(int k, int m){//probe2
    int hh = 1 + (k % (m - 1));//formula
    if(hh < 0){
        hh += m;
    }
    return hh;
}
int hash1(int k, int m, int i){
    int dhash = (h1(k, m) + (i * h2(k, m))) % m;//formula
    return dhash;
}

int main(){
    int key;//chave
    int tam;//tamanho
    int i;//tentativas
    int result;//atribuicao da func

    //input
    cin >> key >> tam;

    //probing & output
    for(i = 0; i < tam; i ++){
        result = hash1(key, tam, i);
        cout << result << " ";
    }

    return 0;
}