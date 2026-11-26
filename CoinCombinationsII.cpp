
#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000010
#define MOD 1000000007

int n, x;
// dp[s] = quantidade de combinacoes que formam a soma s
int dp[MAXN];
// coins[i] = valor da moeda i
int coins[110];

int main(){
    cin >> n >> x;
    // lemos os valores das moedas
    for(int i = 0; i < n; i++)
        cin >> coins[i];
    // existe uma maneira de formar a soma 0
    dp[0] = 1;

    // percorremos cada tipo de moeda
    // como o for das moedas eh o de fora, visitamos cada moeda apenas uma vez, nao permitindo a repeticao
    for(int i = 0; i < n; i++){
        // calculamos as somas que podem ser formadas
        // usando a moeda atual e as moedas anteriores
        for(int s = coins[i]; s <= x; s++){
            // adicionamos a moeda atual as combinacoes
            // que formam a soma s - coins[i]
            dp[s] = (dp[s] + dp[s - coins[i]]) % MOD;
        }
    }

    // imprimimos a quantidade de combinacoes para formar x
    cout << dp[x] << endl;
}
