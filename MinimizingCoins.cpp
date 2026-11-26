#include<bits/stdc++.h>
using namespace std;
 

// podendo usar quantas moedas quiser 
#define maxn 110
#define maxt 1000010
#define inf 1e9+7
// dp[i] = menor menor quantidade de moedas para somar i 
int n, t, dp[maxt], coins[maxn];
 
int main(){
    cin >> n >> t;
    // inicializacoes
    // dps infinitas para sempre trocar pela menor quantia 
    for(int i = 0; i <= t; i++) dp[i] = inf;
    // lendo as moedas 
    for(int i = 0; i < n; i++) cin >> coins[i];
    // estado inicial
    dp[0] = 0;
    
    // de 1 ate a valor total da conta 
    for(int i = 1; i <= t; i++){
        // para cada moeda
        for(int c : coins){
            // se a ultima moeda pra solucao foi por exemplo 6 e o tatal eh 20
            // 20 - 6 = 14, entao temos que resolver dp[14] (minimo para formar 14)
            if(i - c >= 0){
                // testamos formar i utilizando c como ultima moeda
                // pegamos a melhor solucao para i-c e adicionamos uma moeda
                dp[i] = min(dp[i], dp[i - c] +1);
            }
        }
    }
    // se eh impossivel formar 
    if(dp[t] == inf) cout << -1;
    // se possivel
    else cout << dp[t];
}