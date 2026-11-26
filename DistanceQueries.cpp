#include<bits/stdc++.h>
using namespace std;
// dma SO
// clube de regatas vasco da gama 

// constantes
const int MAXL = 20;
const int MAXN = 200010;
// variaveis basicas
int n, q;
// variaveis lca
// nivel do vertice / 2^j-esimo ancestral de u [u][j]
int nivel[MAXN], ancestral[MAXN][MAXL];
// variaveis dfs 
vector<int> adj[MAXN];

// k-esimo ancestral de u
int kesimo_ancestral(int u, int k){
    for(int i = MAXL - 1; i >= 0; i--){
        if(k & (1 << i)){
            u = ancestral[u][i];
        }
    }
    return u;
}

int lca(int u, int v){
    // deixa u mais profundo
    if(nivel[u] < nivel[v]) swap(u, v);
    // iguala os niveis
    // coloca u como o ancestral no mesmo nivel de v
    u = kesimo_ancestral(u, nivel[u] - nivel[v]);

    // se sao iguais, encontramos o lca
    if(u == v) return u;
    // cruzou na area
    for(int i = MAXL - 1; i >= 0; i--){
        if(ancestral[u][i] != ancestral[v][i]){
            u = ancestral[u][i];
            v = ancestral[v][i];
        }
    }
    // chutou no gol
    return ancestral[u][0];
}

// quando visitamos os vizinhos dos vertices tamebm encontramos o pai
// por isso o p aqui
void dfs(int u, int p){
    ancestral[u][0] = p;

    for(int v : adj[u]){
        // por isso eh comparado aqui
        if (v == p) continue;
        // o nivel agora eh o do pai +1 
        nivel[v] = nivel[u] + 1;
        // o pai e de onde viemos, entao o atual eh o pai do proximo
        dfs(v, u);
    }
}

int dist(int u, int v){
    int w = lca(u, v);
    // formula da distancia
    return nivel[u] + nivel[v] - 2 * nivel[w];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // descobre os pais e os niveis
    nivel[1] = 0;
    dfs(1, 0);

    // constroi os ancestrais
    for(int j = 1; j < MAXL; j++){
        for(int i = 1; i <= n; i++){
            ancestral[i][j] = ancestral[ancestral[i][j - 1]][j - 1];
        }
    }

    // respondendo as queries 
    while(q--){
        int u, v;
        cin >> u >> v;

        cout << dist(u, v) << "\n";
    }
}