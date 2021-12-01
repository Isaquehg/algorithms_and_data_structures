#include <iostream>
#include<list>

using namespace std;

struct no{
    int v;//vertice adjacente
    int peso;//peso da aresta
};

void cria_aresta(list<no>adj[], int u, int v, int p, int orientado){
    no aux;//auxiliar
    
    aux.v = v;
    aux.peso = p;
    adj[u].push_back(aux);
    if(orientado == 0){//cria o caminho de volta, caso nao seja orientado
        aux.v = u;
        adj[v].push_back(aux);
    }
}

int main(){
    list<no> adj[100];//lista adjacente
    list<no>::iterator q;//iterator p lista
    int u, v, p;//vertices de origem-destino e peso de sua aresta
    int nvertices;//numero de vertices
    int orientado;//orientado = 1
    int i;//contador

    //input
    cin >> nvertices >> orientado;
    cin >> u >> v >> p;
    while(u != -1 && v != -1 && p != -1){
        cria_aresta(adj, u, v, p, orientado);
        cin >> u >> v >> p;
    }
    //output
    for(i = 0; i < nvertices; i ++){
        for(q = adj[i].begin(); q != adj[i].end(); q ++){
            cout << i << " " << q -> v << " " << q->peso << endl;
        }
    }

    return 0;
}