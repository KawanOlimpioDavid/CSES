// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
const int MAXLOGK = 30;

int prox[MAXLOGK + 1][MAXN];

int main() {
    ios::sync_with_stdio(0);ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, q;
    cin >> n >> q;

    for(int x = 1; x <= n; x++){
        cin >> prox[0][x];
    }

    for(int i = 1; i <= MAXLOGK; i++){
        for(int x = 1; x <= n; x++){
            prox[i][x] = prox[i-1][prox[i-1][x]];
        }
    }

    while(q--){
        int x, k;
        cin >> x >> k;
        for(int i = 0; i <= MAXLOGK; i++){
            if(k & (1 << i)) x = prox[i][x];
        }
        
        cout << x << endl;
    }
}
