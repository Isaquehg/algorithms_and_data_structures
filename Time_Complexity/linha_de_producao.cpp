//Dynamic Programming
#include <iostream>
#include <list>
using namespace std;

int main()
{
	//Variaveis de entrada
	int n; // numero de maquinas por linha
	int a[2][100]; // a[i][j]: tempo de processamento da maquina j da linha i -> a[0,4] = 8
	int t[2][100]; //t[i][j]: tempo pra ir da maquina j da linha i para a outra linha -> t[0,4] = 4
	int e[2]; // e[i]: tempo de entrar na linha i
	int x[2]; // x[i]: tempo para sair da linha i
	
	////Variaveis que serão calculadas
	int f[2][100]; // menor tempo para levar um chassi desde a entrada ate a estacao da linha "i" e maquina "j" -> f[0,4]
	int l[2][100]; // linha cuja estacao j-1 eh usada como o caminho mais rapido atraves da estacao da linha "i" e maquina "j" -> dois valores 0 ou 1 
	
	int f_; // f* -> menor tempo total
	int l_; // l* -> linha cuja ultima estacao eh usada como o caminho mais rapido atraves de toda a fabrica
	
	// Entrada
	cout << "Entre com o numero de maquinas em cada linha: " << endl;
	cin >> n;
	
	for(int i = 0;i < 2; i++)
	{
		cout << "Entre com o custo para entrar na linha " << i << endl;
		cin >> e[i];
	}
	
	for(int i = 0; i < 2; i++)
		for(int j = 0;j < n; j++)
		{
			cout << "Entre com o tempo de operacao da maquina " << j << " da linha " << i << endl;
			cin >> a[i][j];
		}
		
	for(int i = 0; i < 2; i++)
		for(int j = 0;j < n-1; j++)
		{
			cout << "Entre com o tempo para mudar para a linha " << i << " a partir da maquina " << j << endl;
			cin >> t[i][j];
		}	
		
	for(int i = 0;i < 2; i++)
	{
		cout << "Entre com o custo para sair da linha " << i << endl;
		cin >> x[i];
	}
	
	// PROGRAMACAO DINAMICA
	// inicializacao
	int custo1, custo2;

	// caso base
	f[0][0] = e[0] + a[0][0]; //caso base
	f[1][0] = e[1] + a[1][0]; //case base
	l[0][0] = -1; 
	l[1][0] = -1;
	
	
	// caso geral
	for (int maq = 1; maq < n; maq++) // A maquina 0 ja foi processada no caso base
	{
		for(int linha = 0; linha < 2; linha++)
		{
			// calculo os custos para continuar na linha ou mudar
			// O(n)
			if(linha == 0)
			{
				custo1 = f[0][maq-1] + a[0][maq]; //manter na linha 0
				custo2 = f[1][maq-1] + t[1][maq-1] + a[0][maq]; //trocar de linha 
			}
			else //linha == 1
			{
				custo1 = f[1][maq-1] + a[1][maq]; //manter na linha 1
				custo2 = f[0][maq-1] + t[0][maq-1] + a[1][maq]; //trocar de linha
			}

			// avalio qual eh melhor
			if(custo1 < custo2) // manter na linha
			{
				f[linha][maq] = custo1;
				l[linha][maq] = linha;
			}
			else // (custo2 < custo 1) trocar de linha
			{
				f[linha][maq] = custo2;
				if(linha == 0)
					l[linha][maq] = 1;
				else
					l[linha][maq] = 0;
			}
		}	
	}
	
	// calculo para sair da linha de producao
	f[0][n] = f[0][n-1] + x[0];  //(0,6)
	l[0][n] = 0; 
	f[1][n] = f[1][n-1] + x[1]; //(1,6)
	l[1][n] = 1;

	// analise do melhor tempo total
	if(f[0][n] < f[1][n])
	{
		f_ = f[0][n];
		l_ = 0;
	}
	else
	{
		f_ = f[1][n];
		l_ = 1;
	}

	// Resposta
	cout << "Menor tempo necessario para producao: " << f_ << endl;
	cout << "Melhor saida pela linha: " << l_ << endl;

	for(int i = 0;i<2;i++){
		for(int j = 0;j <=n;j++) cout<< l[i][j] << " "; cout << endl;
	}

	// Recuperação do caminho
	// Caminho contrario
	int i = l_;
	cout << "linha " << i << " estacao " << n-1 << endl;
	for(int j = (n - 1); j > 0; j --){
		i = l[i][j];
		cout << "Linha " << i << " estacao " << j-1 << endl;
	}
	
	return 0;	
}