#include <iostream>
#include <list>

using namespace std;

void cria_aresta(list<int>adj[], int u, int v){
    int aux;//auxiliar
    //criando arestas
    aux = v;
    adj[u].push_back(aux);
}
void ordenacao_topologica(int f[], int nVertices){
    int ordem[100];//sorted vector
    int maior = 0;//greatest
    int pos;//position
    for(int j = 0; j < nVertices; j ++){
        for(int i = 0; i < nVertices; i ++){
            if(f[i] > maior){
                maior = f[i];
                ordem[j] = i;
                pos = i;
            }
        }
        f[pos] = 0;//removing added elements
        maior = 0;
    }
    for(int j = 0; j < nVertices; j ++)
        cout << ordem[j] << " ";
    cout << endl;
}
void dfs_visit(list<int>adj[], int u, int f[], int &t, int pi[], char color[]){
    int d[100];//instante em que vertice foi descoberto
    list<int>::iterator p;
    color[u] = 'g';// White vertex u has just been discovered.
    t += 1;
    d[u] = t;
    for(p = adj[u].begin(); p != adj[u].end(); p ++){ // Explore edge (u, v).
        if(color[*p] == 'w'){
            pi[*p] = u;
            dfs_visit(adj, *p, f, t, pi, color);
        }
    }
    color[u] = 'b'; // Blacken u; it is finished.
    f[u] = t = t + 1;
}
void dfs(list<int>adj[], int nVertices){
    int u;//aux
    int t;//time
    int pi[100];//parent
    char color[100];//discovery state: White = undiscovered, Gray = discovered, Black = finished
    int f[100];//topological sorting vector
    for(u = 0; u < nVertices; u ++){
        color[u] = 'w';
        pi[u] = -1;
    }
    t = 0;
    for(u = 0; u < nVertices; u ++){
        if(color[u] == 'w'){
            dfs_visit(adj, u, f, t, pi, color);
        }
    }
    ordenacao_topologica(f, nVertices);
}

int main(){
    list<int> adj[100];//lista de tarefas a realizar
    int nvertices;//numero de tarefas
    int u, v;//tarefa v depende de u

    //input
    cin >> nvertices;
    cin >> u >> v;
    while(u != -1 && v != -1){
        cria_aresta(adj, u, v);
        cin >> u >> v;
    }
    //depth first searching
    dfs(adj, nvertices);

    return 0;
}