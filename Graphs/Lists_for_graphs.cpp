#include <iostream>
#include <list>

using namespace std;

struct no{
    int v;//vertice
    int peso;//peso da artesta
};

int main(){
    list<no> adj[10];//vetor de listas de adjacencia p grafo
    list<no>::iterator p;//iterator p lista de adjacencia
    no aux;//aux p insercao de arestas em adj
    int u, v;//vetices de origem e destino de cada aresta
    int peso;//peso aresta
    int nvertices = 4;//numero de vertices
    int i;//contador
    int orientado = 1;//se for grafo orientado = 1
    
    //adicionando arestas
    for(i = 0; i < 3; i ++){
        cin >> u >> v >> peso;
        aux.v = v;
        aux.peso = peso;
        adj[u].push_back(aux);
        if(orientado == 0){//cria o caminho de volta, caso nao seja orientado
            aux.v = u;
            adj[v].push_back(aux);
        }
    }
    //output
    cout << "Lista de Adjacencia:" << endl;
    for(i = 0; i < nvertices; i ++){
        for(p = adj[i].begin(); p != adj[i].end(); p ++){
            cout << i << " " << p -> v << " " << p->peso << endl;
        }
    }

    return 0;
}