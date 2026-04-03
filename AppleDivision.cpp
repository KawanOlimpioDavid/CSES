#include<bits/stdc++.h>
using namespace std;

#define inf INT_MAX
int lista[20];
long long ans = inf;


int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> lista[i];
    }

    for(int mask = 0; mask < (1 << n); mask++){
        long long s1 = 0, s2 = 0;
        for(int i = 0; i < n; i++){
            if(mask & (1 << i)) s1 += lista[i];
            else s2 += lista[i];
        }
        if((max(s1, s2) - min(s1, s2)) < ans) ans = max(s1, s2) - min(s1, s2);
    }

    cout << ans;
    return 0;
}