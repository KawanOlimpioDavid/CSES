#include <bits/stdc++.h>
using namespace std;

typedef long long int lli; 

int main(){
    lli n, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        lli ttl = i*i;
        // caso 1;
        ans += (ttl - 3) * 4;
        // caso 2;
        ans += (ttl - 5) * 4;
        // saco 3;
        ans += (ttl - 9) * (i-4) * (i-4);
        // caso 4;
        ans += (ttl - 4) * 8;
        // caso 5
        ans += (ttl - 5) * ((i-4)*4);
        // caso 6
        ans += (ttl - 7) * ((i-4)*4);

        ans /= 2;
        cout << ans << "\n";
        ans = 0;
    }
    
}