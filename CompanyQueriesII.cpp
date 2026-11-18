
#include <bits/stdc++.h>
using namespace std;

// quantidade de niveis de ancestrais
const int MAXL = 20;

//lLimite de vertices
const int MAXN = 200010;

int n, q;

// nivel[v] = distancia de v ate a raiz
int nivel[MAXN];

// ancestral[v][j] = 2^j-esimo ancestral de v
int ancestral[MAXN][MAXL];

// retorna o k-esimo ancestral de u
int kth_ancestor(int u, int k) {
    // comecando do maior salto
    for (int i = MAXL - 1; i >= 0; i--) {
        if (k & (1 << i)) {
            u = ancestral[u][i];
        }
    }

    return u;
}

// retorna o menor ancestral comum entre u e v
int lca(int u, int v) {
    // deixa u como o vertice mais profundo
    if (nivel[u] < nivel[v]) swap(u, v);

    // igualando os niveis
    u = kth_ancestor(u, nivel[u] - nivel[v]);

    // se forem iguais, encontramos o LCA
    if (u == v) return u;

    // sobe os dois simultaneamente
    for (int i = MAXL - 1; i >= 0; i--) {
        // de novo do maior salto possivel
        // se o proximo ancestral e diferente, pode saltar 
        // aqui eles saltos ate que o pai de cada um seja o lca
        if (ancestral[u][i] != ancestral[v][i]) {
            u = ancestral[u][i];
            v = ancestral[v][i];
        }
    }
    // assim aqui retorna o ancestral imediato, que eh o lca de ambos, 2⁰ = 1 ancestral de u
    return ancestral[u][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    // lendo os chefes e definindo os ancestrais imediatos
    for (int i = 2; i <= n; i++) {
        cin >> ancestral[i][0];
        // o nivel dele vai ser o do ancestral imediato + 1
        nivel[i] = nivel[ancestral[i][0]] + 1;
    }

    // montando a tabela de binary lifting
    // aqui o j eh fora do i para podermos fazer todos os saltos 2^j possiveis a partir do vertice i
    for (int j = 1; j < MAXL; j++) {
        for (int i = 1; i <= n; i++) {
            ancestral[i][j] =
                ancestral[ancestral[i][j - 1]][j - 1];
        }
    }

    // processando as consultas
    while (q--) {
        int u, v;
        cin >> u >> v;

        cout << lca(u, v) << '\n';
    }

    return 0;
}
