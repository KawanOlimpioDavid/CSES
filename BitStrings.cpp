#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define mod 1000000007 

int main() {
    lli n, ans = 1;
    cin >> n;

    for(int i = 1; i<=n; i++){
        ans = 2 * ans % mod;
    }
    cout << ans;
}
