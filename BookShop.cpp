#include<bits/stdc++.h>
using namespace std;

#define MAXN 100010
int n, W;
int w[MAXN], v[MAXN], dp[MAXN];

int main(){
    cin >> n >> W;
    for(int i = 1; i <= n; i++) cin >> w[i];
    for(int i = 1; i <= n; i++) cin >> v[i];

    for(int i = 1; i <= n; i++){
        for(int j = W; j >= w[i]; j--){
            dp[j] = max(dp[j], dp[j - w[i]] +v[i]);
        }
    }

    cout << dp[W] << endl;
}