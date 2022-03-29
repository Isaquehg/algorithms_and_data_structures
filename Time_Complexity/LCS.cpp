//Largest commom sequence
#include <iostream>

using namespace std;

int main()
{	
	int pd[100][100]; // armazena o tamanho da maior subsequencia comum
	int caminho[100][100]; // armazena o cam.
	char s1[100]; // sequencia 1
	char s2[100]; // sequencia 2
	int t1; // tamanho da sequencia 1
	int t2; // tamanho da sequencia 2
	
	// entrada:
	cout << "Entre com o tamanho da sequencia 1:";
	cin >> t1;
	cout << "Entre com o tamanho da sequencia 2:";
	cin >> t2;
	
	cout << "Entre com a sequencia 1:" << endl;
	for(int i = 0;i < t1;i++)
		cin >> s1[i];
	
	cout << "Entre com a sequencia 2:" << endl;
	for(int i = 0;i < t2;i++)
		cin >> s2[i];
	
	
	// inicializacao:
	// casos base
	for(int i = 0;i < t1;i++) //Independente de i
		pd[i][t2] = 0;
	
	for(int i = 0; i < t2;i++) //Independente de i
		pd[t1][i] = 0;
	
	// programacao dinamica:
	// caso geral
	for(int i = t1-1;i >= 0; i--) //t1 ja foi processado no caso base
		for(int j = t2-1;j >= 0; j--) 
		{
			if(s1[i] == s2[j]) // se as duas forem iguais
			{
				pd[i][j] = pd[i+1][j+1] + 1; // 1 + valor de avancar em 'i' e 'j'
				caminho[i][j] = 0;           // igual -> caminho = 0
			}
			else
			{
				if(pd[i+1][j] > pd[i][j+1]) // melhor avancar em 'i' -> caminho = 2;
				{
					pd[i][j] = pd[i+1][j];
					caminho[i][j] = 2;
				}
				else                       	// melhor avancar em 'j' -> caminho = 1;
				{
					pd[i][j] = pd[i][j+1];
					caminho[i][j] = 1;
				}
			}
		}
		
	cout << "O tamanho da LCS entre as sequencias 1 e 2 eh: " << pd[0][0] << endl;
	
	
	// recuperacao:
	cout << "Subsequencia: ";
	
	int tam_LCS = pd[0][0];
	int i = 0,j = 0;
	while(tam_LCS > 0)
	{
		if(caminho[i][j] == 0) // eh igual (diagonal)
		{
			cout << s1[i] << " "; // cout << s2[j] << " "; tambem eh valido
			tam_LCS--; // recuperei 1 valor
			i++;
			j++;
		}
		else if(caminho[i][j] == 1) // na frente (j+1)
		{
			j++;
		}
		else // caminho[i][j] == 2 -> abaixo (i+1)
		{
			i++;
		}  
	}
	cout << endl;
	
	return 0;
}