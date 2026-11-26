#include<bits/stdc++.h>
using namespace std;

#define MAXN 1010
#define MOD 1000000007
int n;
char grid[MAXN][MAXN];
int dp[MAXN][MAXN];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> grid[i][j];
        }
    }

    if(grid[1][1] == '*'){
        cout << 0;
        return 0;
    }

    dp[1][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(grid[i][j] == '*') continue;
            if(i > 1) dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            if(j > 1) dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
        }
    }

    cout << dp[n][n];
}