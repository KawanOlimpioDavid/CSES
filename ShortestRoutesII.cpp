#include<bits/stdc++.h>
using namespace std;

#define maxn 510
#define inf 10e9+7
int n, m, q
long long dist[maxn][maxn];

void floydWarshall(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dist[i][k] != inf && dist[k][j] != inf){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main(){
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = inf;
        }
    }
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], (long long)c);
        dist[b][a] = min(dist[b][a], (long long)c);
    }
    floydWarshall();

    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        if(dist[a][b] == inf) cout << -1 << endl;
        else cout << dist[a][b] << endl;
    }
}