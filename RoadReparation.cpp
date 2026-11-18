#include<bits/stdc++.h>
using namespace std;

#define MAXN 100010
#define MAXM 200010
struct t_aresta{
    int dis;
    int x, y;
};
// para ordenar as arestas pelo peso (distancia aqui)
bool comp(t_aresta a, t_aresta b){
    return a.dis < b.dis;
}

int m, n;
// uma guarda as arestas e a outra so a arvore final
t_aresta arestas[MAXM], mst[MAXM];
int pai[MAXN], peso[MAXN], qnt[MAXN];

int find(int x){
    if(x == pai[x]) return x;
    return pai[x] = find(pai[x]);
}

void join(int x, int y){
    x = find(x);
    y = find(y);

    if(peso[x] < peso[y]){
        pai[x] = y;
        qnt[y] += qnt[x];
    }
    if(peso[y] < peso[x]){
        pai[y] = x;
        qnt[x] += qnt[y];
    }else{
        pai[x] = y;
        qnt[y] += qnt[x];
        peso[y]++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> arestas[i].x >> arestas[i].y >> arestas[i].dis;
    }
    for(int i = 1; i <= n; i++){
        pai[i] = i;
        qnt[i] = 1;
    }
    sort(arestas+1, arestas+m+1, comp);

    int size = 0;
    for(int i = 1; i <= m; i++){
        if(find(arestas[i].x) != find(arestas[i].y)){
            join(arestas[i].x, arestas[i].y);
            mst[++size] = arestas[i];
        }
    }
    // se nao tem n-1 arestas, nao eh possivel deixar conexo
    if(size != n-1){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    // para printar a mst
    // for(int i = 1; i < n; i++){
    //     cout << mst[i].x << " " << mast[y] << " " << mst[i].dis << endl;
    // }

    // para pegar a soma total dos pesos
    long long ans = 0;
    for(int i = 1; i < n; i++){
        ans += mst[i].dis;
    }
    cout << ans;
    return 0;
}