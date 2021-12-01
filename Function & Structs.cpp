#include <iostream>
using namespace std;
struct dados{
    char nome[100];//nome do atleta
    int n1;//notas
    int n2;
    int n3;
    int n4;
};
int strongest(dados forte[], int nat){
    int soma;//soma temporaria dos valores do atleta de x
    int maior = 0;//maior nota
    int m;//posicao do atleta mais forte
    for(int x = 0; x < nat; x ++){
        soma = forte[x].n1 + forte[x].n2 + forte[x].n3 + forte[x].n4;
        if(soma > maior){
            maior = soma;
            m = x;
        }
    }
    return m;
}
int main(){
    dados forte[100];
    int i;//contador
    int n;//numero de atletas
    int pos;//posicao do atleta
    
    cin >> n;
    for(i = 0; i < n; i ++){
        cin.ignore();
        cin.getline(forte[i].nome, 100);
        cin >> forte[i].n1 >> forte[i].n2 >> forte[i].n3 >> forte[i].n4;
    }
    pos = strongest(forte, n);
    cout << "Vencedor: " << forte[pos].nome << endl;
    return 0;
}