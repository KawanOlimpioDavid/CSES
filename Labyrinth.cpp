#include<bits/stdc++.h>
#include <queue>
#include <utility>
using namespace std;

#define maxn 1010
#define inf INT_MAX
typedef pair<int, int> pii;
int n, m;
char grid[maxn][maxn];
int dist[maxn][maxn];
int last[maxn][maxn];
string dir = "DURL";
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isSafe(int nx, int ny){
    return nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#'; 
}

void dijkstra(pii src){
    dist[src.first][src.second] = 0;
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    pq.emplace(0, src);

    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();
        
        int d = top.first;
        auto u = top.second;
        if(d > dist[u.first][u.second]) continue;

        for(int i = 0; i < 4; i++){
            int nx = dx[i] + u.first, ny = dy[i] + u.second;
            if(isSafe(nx, ny)){
                if(dist[nx][ny] > dist[u.first][u.second] + 1){
                    dist[nx][ny] = dist[u.first][u.second] + 1;
                    pq.emplace(dist[nx][ny], make_pair(nx, ny));
                    last[nx][ny] = i;
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;
    pii A, B;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            dist[i][j] = inf;
            last[i][j] = -1;
            if(grid[i][j] == 'A') A = {i, j};
            if(grid[i][j] == 'B') B = {i, j};
        }
    }
    dijkstra(A);
    if(dist[B.first][B.second] == inf){
        cout << "NO";
    }else{
        cout << "YES\n";
        cout << dist[B.first][B.second] << endl;
        string ans;
        int x = B.first, y = B.second;
        while(last[x][y] != -1){
            int d = last[x][y];
            ans.push_back(dir[d]);
            x -= dx[d];
            y -= dy[d];
        }
        reverse(ans.begin(), ans.end());
        cout << ans;
    }  
}