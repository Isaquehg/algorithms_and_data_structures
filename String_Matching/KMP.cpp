#include <iostream>
#include <cstring>

using namespace std;

void calcula_LPS(int lps[], char P[], int tamP)
{
	// tamanho do maior prefixo que tambem eh sufixo anterior
	int tam = 0;

	lps[0] = 0; // caso base

	// o loop calcula lps[i] para i = 1 ate tamP-1
	int i = 1;
	while (i < tamP)
	{
		if (P[i] == P[tam]) // se encontrar uma letra que bate tanto como prefixo quanto como sufixo
		{
			tam++; // aumento o tamanho do maior prefixo que tambem eh sufixo
			lps[i] = tam; // salvo o valor para esse prefixo
			i++; // vou para o proximo prefixo
		}
		else // (p[i] != p[tam]) se encontrar uma letra que nao bate como prefixo e sufixo
		{
			if (tam != 0) // se o tamanho do maior prefixo que tambem eh sufixo atual for diferente de 0
			{
				tam = lps[tam - 1]; // volto pro maior prefixo que tambem eh sufixo considerando o prefixo anterior
				// Note que neste caso nao incrementamos o 'i'
			}
			else // se o tamanho do maior prefixo que tambem eh sufixo atual for 0
			{
				lps[i] = 0; // o maior prefixo que tambem é prefixo agora vale 0
				i++; // vou para o proximo prefixo
			}
		}
	}
}

// KMP Algorithm
void kmp(char T[], char P[], int tamT, int tamP)
{
	int lps[tamP]; // vetor que indica para onde voltarei no padrao quando ocorrer um mismatch
	// lps -> indica o tamanho do maior sufixo de p[0...i] que tambem eh prefixo de p[0...i] (exceto a string inteira)

	calcula_LPS(lps, P, tamP);

	int j = 0; // j eh tamanho do meu match atual, ONDE EU ESTOU NO MEU PADRAO
	int i = 0; // posicao no texto
	int pos = -1; // variavel que armazena a posição
	while(i < tamT)
	{
		if(T[i] == P[j]) // match
		{
			j++;
			i++;
			if(j == tamP) // encontrei o padrao no texto na posicao (i-tamP) até i
			{
				pos = i - tamP;
				cout << i - tamP << endl;
				j = lps[j - 1];
			}
		}
		else // mismatch
		{
			if(j != 0) // se ocorreu mismatch depois de j matchs
				j = lps[j - 1];
			else // mismatch na comparacao da primeira letra
				i++;
		}
	}
	if(pos == -1)
	{
		//cout << "Padrao nao encontrado" << endl;
	}
}

int main(){
    int m, n;

    char T[100]; //texto
    char P[100]; //padrao

    //input
    cin.getline(T, 100);
    cin.getline(P, 100);

    //kmp algorithm
    kmp(T, P, strlen(T), strlen(P));

    return 0;
}