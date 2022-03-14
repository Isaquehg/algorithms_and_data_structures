#include <iostream> // Entrada e sa�da
#include <climits> // INT_MAX

using namespace std;

int main()
{
	int custo[100][100]; // 100 -> numero maximo de cidades
						 // custo[i][j] = custo de ir da cidade 'i' para a cidade 'j'
	int cidade_inicial; // Primeira e ultima cidade
	int n; // numero de cidades
	
	//cout << "Entre com o numero de cidades" << endl;
	cin >> n;
	//cout << "Entre com a cidade inicial" << endl;
	cin >> cidade_inicial;
	
	for(int i = 0;i < n;i++)
		for(int j = i+1;j < n;j++) 
		{
			//cout << "Entre com o custo de ir da cidade " << i << " para a cidade " << j << endl;
			cin >> custo[i][j];
			custo[j][i] = custo[i][j]; // Custo de i->j = custo de j->i
		}
	
	bool vis[100]; // marca se ja visitou ou nao uma cidade
	int menor_custo; // menor custo da viagem
	int custo_at; // menor custo atual
	int cidade_atual; // cidade atual
	int proxima_cidade; // proxima cidade
		
	// inicializando vetor vis (nenhuma cidade foi visitada no inicio)
	for(int i = 0;i < n;i++)
		vis[i] = false;
	
	// guloso
	menor_custo = 0;
	cidade_atual = cidade_inicial;
	for(int i = 0;i < n-1;i++) // n-1 vezes = qnt de caminhos (exceto a volta para a cidade inicial)
	{
		vis[cidade_atual] = true; // marco que ja visitei a cidade atual
		// encontrar qual a proxima cidade mais proxima
		custo_at = INT_MAX;
		for(int j = 0;j < n;j++)
		{
			if(!vis[j] && custo_at > custo[cidade_atual][j])
			{
				proxima_cidade = j;
				custo_at = custo[cidade_atual][j];
			}	
		}
		menor_custo += custo_at;
		cidade_atual = proxima_cidade;
	}
	menor_custo += custo[cidade_atual][cidade_inicial];
	cout << "Menor custo = " << menor_custo << endl;
	
	return 0;
}







