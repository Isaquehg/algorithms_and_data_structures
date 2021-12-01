#include <iostream>
#include <list>
#include <climits>

using namespace std;

struct no{
    int v;//vertice
    int peso;//peso aresta
};

void cria_aresta(list<no>adj[], int u, int v, int p, int orientado){
    no aux;//auxiliar
    //criando arestas
    aux.v = v;
    aux.peso = p;
    adj[u].push_back(aux);
    //rota inversa(nao orientado)
    if(orientado == 0){
        aux.v = u;
        adj[v].push_back(aux);
    }
}
void prim(list<no>adj[], int nVertices, int start){
    int custo = 0;
    int v;//vertice
    int destino;//vertice de destino
    int weight;//peso da aresta analisada
    int dist;//distancia auxiliar
    int u;//contador
    int parent[100];//pai do vertice
    int distancia[100];//vetor p distancias
    bool intree[100];//se pertence à arvore
    list<no>::iterator p;
    for(u = 0; u < nVertices; u ++){
        intree[u] = false;
        distancia[u] = INT_MAX;
        parent[u] = -1;
    }
    distancia[start] = 0;
    v = start;
    while(intree[v] == false){
        intree[v] = true;
        for(p = adj[v].begin(); p != adj[v].end(); p ++){
            destino = p->v;
            weight = p->peso;
            if(distancia[destino] > weight && intree[destino] == false){
                distancia[destino] = weight;
                parent[destino] = v;
            }
        }

        v = 0;
        dist = INT_MAX;
        for(u = 0; u < nVertices; u ++){
            if((intree[u] == false) && (dist > distancia[u])){
                dist = distancia[u];
                v = u;
            }
        }
    }
    cout << "Arvore Geradora Minima: " << endl;
    for(u = 0; u < nVertices; u ++){
        if(parent[u] != -1){   
            cout << parent[u] << " " << u << endl;
            custo += distancia[u];
        }
    }
    cout << "Custo: " << custo << endl;
}

int main(){
    int nvertices;//numero de vertices
    int orientado;//1: orientado
    int vo;//vertice inicial
    int u, v, p;//vertice inicial, final e peso aresta
    list<no> adj[100];//lista adjacencia

    //input e criacao do grafo
    cin >> nvertices >> orientado >> vo;
    cin >> u >> v >> p;
    while(u != -1 && v != -1 && p != -1){
        cria_aresta(adj, u, v, p, orientado);
        cin >> u >> v >> p;
    }
    prim(adj, nvertices, vo);

    return 0;
}