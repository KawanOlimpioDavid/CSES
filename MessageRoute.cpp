#include<bits/stdc++.h>
using namespace std;

#define inf INT_MAX
#define maxn 100010
int n, m;
typedef pair<int, int> pii;
vector<int> dist(maxn, inf);
vector<pii> adj[maxn];
vector<int> ans(maxn, -1);

void dijkstra(int src){
    dist[src] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, src);

    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();

        int d = top.first, u = top.second;
        if(d > dist[u]) continue;

        for(auto V: adj[u]){
            int v = V.first, w = V.second;
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
                ans[v] = u;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].push_back({b, 1});
        adj[b].push_back({a, 1});
    }

    dijkstra(1);
    if(dist[n] != inf){
        cout << dist[n]+1  << endl;
        vector<int> path;
        for(int v = n; v != -1; v = ans[v]){
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
        for(int i = 0; i < (int)path.size(); i++){
            cout << path[i] << ' ';
        }
    } else cout << "IMPOSSIBLE";
}