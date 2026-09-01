#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1010;
int dist[MAXN][MAXN];
int dx[8] = {-2, -1, +1, +2, +2, +1, -1, -2};
int dy[8] = {+1, +2, +2, +1, -1, -2, -2, -1};
int n;

bool isSafe(int nx, int ny){
    return nx < n && ny < n && nx >= 0 && ny >= 0 && dist[nx][ny] == -1;
}

void bfs(){
    queue<pair<int, int>> fila;
    dist[0][0] = 0;
    fila.push({0, 0});
    
    while(!fila.empty()){
        auto [u, v] = fila.front();
        fila.pop();
        for(int i = 0; i < 8; i++){
            int nx = u + dx[i];
            int ny = v + dy[i]; 
            if(isSafe(nx, ny)){
                dist[nx][ny] = dist[u][v] + 1;
                fila.push({nx, ny});
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dist[i][j] = -1;
        }
    }
    bfs();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}