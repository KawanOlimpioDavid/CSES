#include <bits/stdc++.h>
using namespace std;

#define MAXN 100010

int n, m;
int pai[MAXN], peso[MAXN], qnt[MAXN];

int find(int x){
    if(x == pai[x]) return x;
    return pai[x] = find(pai[x]);
}

bool join(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y) return false;

    if(peso[x] < peso[y]){
        pai[x] = y;
        qnt[y] += qnt[x];
    }
    else if(peso[x] > peso[y]){
        pai[y] = x;
        qnt[x] += qnt[y];
    }
    else{
        pai[x] = y;
        peso[y]++;
        qnt[y] += qnt[x];
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    int componentes = n;
    int maior = 1;

    for(int i = 1; i <= n; i++){
        pai[i] = i;
        peso[i] = 0;
        qnt[i] = 1;
    }

    int a, b;

    for(int i = 0; i < m; i++){
        cin >> a >> b;

        if(join(a, b)){
            componentes--;

            int raiz = find(a);
            maior = max(maior, qnt[raiz]);
        }

        cout << componentes << " " << maior << '\n';
    }
}
