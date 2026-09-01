#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, ans = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int m = i; m; m &= (m - 1)) {
            ans++;
        }
    }

    cout << ans;
}