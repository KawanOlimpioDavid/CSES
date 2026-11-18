
#include <bits/stdc++.h>
using namespace std;

#define MAXN 100010

// variaveis iniciais 
int n, k;
int pai[MAXN], peso[MAXN], qnt[MAXN];

// encontrar o pai
int find(int x) {
    // se ele eh pai de si mesmo
    if (pai[x] == x) return x;
    // se nao procura recursivamente
    return pai[x] = find(pai[x]);
}

// unir os conjuntos
void join(int x, int y) {
    // pais dos conjuntos a serem unidos
    x = find(x);
    y = find(y);
    // se eh o msm pai ja estao no mesmo conjunto
    if (x == y) return;
    // se o peso da familia x eh menor, y a recebe
    if (peso[x] < peso[y]) {
        // pai de x agora eh y
        pai[x] = y;
        // e y ganha a quantidade de x
        qnt[y] += qnt[x];
    }
    else if (peso[x] > peso[y]) {
        pai[y] = x;
        qnt[x] += qnt[y];
    }
    else {
        pai[x] = y;
        peso[y]++;
        // se são do mesmo tamanho, a arvore ganha mais um nivel, peso aumenta
        qnt[y] += qnt[x];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    // inicializa 
    for (int i = 1; i <= n; i++) {
        pai[i] = i;
        peso[i] = 0;
        qnt[i] = 1;
    }
    // une
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        join(a, b);
    }

    vector<int> roads;

    for (int i = 1; i <= n; i++) {
        if (find(i) == i) {
            roads.push_back(i);
        }
    }

    cout << (int)roads.size() - 1 << '\n';

    for (int i = 0; i < (int)roads.size() - 1; i++) {
        cout << roads[i] << " " << roads[i + 1] << '\n';
    }

    return 0;
}
