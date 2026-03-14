#include<bits/stdc++.h>
using namespace std;

int n, m;
int componente[1010][1010];
char board[1010][1010];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isSafe(int nx, int ny){
    return nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == '.';
}

void dfs(int x, int y){
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(isSafe(nx, ny)){
            if(componente[nx][ny] == 0){
                componente[nx][ny] = componente[x][y];
                dfs(nx, ny);
            }
        }
    }
}

int main(){

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];

            if(board[i][j] == '#')
                componente[i][j] = -1;
            else
                componente[i][j] = 0;
        }
    }

    int numComponentes = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(componente[i][j] == 0){
                numComponentes++;
                componente[i][j] = numComponentes;
                dfs(i, j);
            }
        }
    }

    cout << numComponentes;
}