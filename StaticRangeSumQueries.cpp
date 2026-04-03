#include<bits/stdc++.h>
using namespace std;

#define maxn 200010
typedef long long ll;

ll vec[maxn];
int n, q;
ll sum;

ll rsum(int a, int b){
    if(a == 1) return vec[b-1];
    return vec[b-1] - vec[a-2];
}

int main(){
    cin >> n >> q;
    ll x = 0;
    for(int i = 0; i < n; i++){
        cin >> vec[i];
        x += vec[i];
        vec[i] = x;
    }
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        cout << rsum(min(a, b), max(a, b)) << endl;
    }
}