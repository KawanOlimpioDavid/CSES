#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<char>> vvc;

int colunas[8];
int dPrincipal[15];
int dSecundaria[15];
int ans = 0;

bool isSafe(int r, int c, vvc &board){
    return colunas[c] == 0 &&
           dPrincipal[r+c] == 0 &&
           dSecundaria[r-c+7] == 0 &&
           board[r][c] == '.';
}

void putQueens(int r, vvc &board){

    if(r == 8){
        ans++;
        return;
    }

    for(int c = 0; c < 8; c++){

        if(isSafe(r,c,board)){

            colunas[c] = 1;
            dPrincipal[r+c] = 1;
            dSecundaria[r-c+7] = 1;

            putQueens(r+1, board);

            colunas[c] = 0;
            dPrincipal[r+c] = 0;
            dSecundaria[r-c+7] = 0;
        }
    }
}

int main(){

    vvc board(8, vector<char>(8));

    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            cin >> board[i][j];

    putQueens(0, board);

    cout << ans;
}