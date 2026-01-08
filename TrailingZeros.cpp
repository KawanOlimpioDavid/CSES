#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main() {
    lli n, ans = 0;
    cin >> n;

    while(n >= 1){
        ans += n / 5;
        n /= 5;
    }
    cout << ans;
}
