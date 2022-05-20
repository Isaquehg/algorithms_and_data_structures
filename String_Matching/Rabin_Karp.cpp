#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

void rabin_karp(char T[], char P[], int tamT, int tamP, int d, int q){
    //padrão: q = 13
    int ultimo;//ultima ocorrencia
    int h;//valor utilizado para calculo de hash
    int pos;//posicao aux
    int ocorrencias = 0;//numero de ocorrencias do padrao
    int p = 0; //padrão convertido p inteiro
    int t = 0; //texto convertido para inteiro

    for(int i = 0; i < tamP; i ++){
        p = (d * p + (P[i] - '0')) % q; //converte o padrao
        t = (d * t + (T[i] - '0')) % q; //converte o texto p o primeiro valor de t[0]
    }

    h = (int)pow(d, tamP - 1) % q; //utilizado p calculo hash

    for(int i = 0; i <= tamT - tamP; i ++){
        if(p == t){ //se encontrou um valor de hash valido
            //verificar se ha diferencas
            int j;
            for(j = 0; j < tamP; j ++){
                if(P[j] != T[i + j])
                    break;
            }

            if(j == tamP && i > ultimo){
                ultimo = i;
                ocorrencias ++;
            }
        }

        if(i < tamT - tamP){ //se nao chegou no final
            //atualizar t[i] para t[i] + 1
            t = (d * (t - (T[i] - '0') * h) + (T[i + tamP] - '0')) % q;
            if(t < 0)
                t += q;
        }
    }
    
    //output
    cout << "Ultima ocorrencia: " << ultimo << endl;
    cout << ocorrencias << " ocorrencia(s)" << endl;
}

int main(){
    int n;//tamanho texto
    int m;//tamanho padrao
    int q = 13;//maior primo
    int d = 26;

    cin >> n >> m;
    char T[n]; //texto
    char P[m]; //padrao

    cin >> T;
    cin >> P;
    
    rabin_karp(T, P, n, m, d, q);

    return 0;
}