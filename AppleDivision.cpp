#include<bits/stdc++.h>
using namespace std;

#define inf LLONG_MAX
int lista[20];
long long ans = inf;


int main()
{
    int n;
    cin >> n;
    // recebe as macas 
    for(int i = 0; i < n; i++){
        cin >> lista[i];
    }
    // percorrer as mascaras
    for(int mask = 0; mask < (1 << n); mask++){
        long long s1 = 0, s2 = 0;
        for(int i = 0; i < n; i++){
            // verifica se o bit esta na mascara pra colocar ma soma1
            if(mask & (1 << i)) s1 += lista[i];
            else s2 += lista[i];
        }
        // substitui se a diferenca for menor
        if((max(s1, s2) - min(s1, s2)) < ans) ans = max(s1, s2) - min(s1, s2);
    }

    cout << ans;
    return 0;
}