#include <bits/stdc++.h>
using namespace std;

#define maxn 1000010
#define mod 1000000007
int n;
long long int dp[maxn];

int main(){
    cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    dp[6] = 32;
    for(int i = 7; i <= n; i++){
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6]) % mod;
    }
    cout << dp[n];
}