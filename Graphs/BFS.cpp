#include <iostream>
#include <list>

using namespace std;

struct no{
    int v;
    int peso;
};
void cria_aresta(list<no>adj[], int u, int v, int p){
    no aux;//auxiliar
    //criando arestas
    aux.v = v;
    aux.peso = p;
    adj[u].push_back(aux);
    //rota inversa(nao orientado)
    aux.v = u;
    adj[v].push_back(aux);
}
void bfs(list<no>adj[], int nVertices, int s){
    int state[100];//estado dos vertices
    int p[100];
    int u, v;
    list<int> Q;
    list<no>::iterator it;//iterator p adj
    for(u = 0; u < nVertices; u ++){
        if(u != s){
            state[u] = -1;//nao descoberto
            p[u] = -1;
        }
    }
    state[s] = 0;//descoberto
    p[s] = -1;
    Q.push_back(s);

    while(!Q.empty()){
        u = Q.front();
        Q.pop_front();
        cout << u << endl;
        for(it = adj[u].begin(); it != adj[u].end(); it ++){
            v = it->v;
            cout << u << " " << v << endl;
            if(state[v] == -1){
                state[v] = 0;//descoberto
                p[v] = u;
                Q.push_back(v);
            }
        }
        state[u] = 1;//processado
    }
}
int main(){
    int nvertices;//numero de vertices
    int vo;//vertice inicial
    int u, v, p;//vertices inicial e final e peso da arewsta
    list<no> adj[100];
    //input e criacao das arestas
    cin >> nvertices >> vo;
    cin >> u >> v >> p;
    while(u != -1 && v != -1 && p != -1){
        cria_aresta(adj, u, v, p);
        cin >> u >> v >> p;
    }
    //percurso em largura
    bfs(adj, nvertices, vo);

    return 0;
}