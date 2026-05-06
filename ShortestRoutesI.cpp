#include<bits/stdc++.h>
#include <climits>
using namespace std;
 
#define maxn 100010
#define inf 1e18
typedef long long int lli;
int n, m;
long long dist[maxn];
vector<pair<int, int>> graph[maxn];
 
void dijkstra(int src){
    for(int i = 1; i <= n; i++) dist[i] = inf;
    dist[src] = 0;
    
    priority_queue<pair<lli, int>, vector<pair<lli, int>>, greater<pair<lli, int>>> pq;
    pq.emplace(0, src);
	
    while(!pq.empty()){
        auto top = pq.top();
	pq.pop();
	
	int d = top.first; int u = top.second;
	if(d > dist[u]) continue;
	
	for(auto V: graph[u]){
	    int v = V.first;
        int w = V.second;
	    if(dist[v] > dist[u] + w){
	    	dist[v] = dist[u] + w;
		pq.emplace(dist[v], v);
	    }
	}
    }
}
 
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
    	int a, b, c;
	cin >> a >> b >> c;
	graph[a].push_back({b, c});
    }
    dijkstra(1);
    for(int i = 1; i <= n; i++) cout << dist[i] << " ";
    return 0;
}