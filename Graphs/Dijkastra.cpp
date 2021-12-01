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
void dijkstra(list<no>adj[], int nVertices, int start, int end){
    int v;//vertice
    int custo = 0;
    int destino;//vertice de destino
    int weight;//peso da aresta analisada
    int dist;//distancia auxiliar
    int u;//aux
    int parent[100];//pai do vertice
    int distancia[100];//vetor p distancias
    bool intree[100];//se esta na arvore
    list<int> stack;//pilha p resultado
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
            if(distancia[destino] > distancia[v] + weight){//dijkstra
                distancia[destino] = distancia[v] + weight;
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
    //output
    cout << "Menor caminho: ";
    stack.push_front(end);
    u = end;
    while(parent[u] != -1){
        stack.push_front(parent[u]);
        u = parent[u];
    }
    while(!stack.empty()){
        cout << *stack.begin() << " ";
        stack.pop_front();
    }
    cout << endl;
    custo = distancia[end];
    cout << "Custo: " << custo << endl;
}

int main(){
    int nvertices;//numero de vertices
    int orientado;//1: orientado
    int vo, vf;//vertices inicial e final
    int u, v, p;//vertice inicial, final e peso aresta
    list<no> adj[100];//lista adjacencia

    //input e criacao do grafo
    cin >> nvertices >> orientado >> vo >> vf;
    cin >> u >> v >> p;
    while(u != -1 && v != -1 && p != -1){
        cria_aresta(adj, u, v, p, orientado);
        cin >> u >> v >> p;
    }
    dijkstra(adj, nvertices, vo, vf);

    return 0;
}