
#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000010
#define MOD 1000000007

int n, W;
// dp[j] = quantidade de sequencias que formam a soma j
int dp[MAXN];
// w[i] = valor da moeda i
int w[MAXN];

int main(){
    cin >> n >> W;

    // lemos os valores das moedas
    for(int i = 1; i <= n; i++)
        cin >> w[i];
    // existe uma maneira de formar a soma 0: nao usar moedas
    dp[0] = 1;
    // percorremos todas as somas que queremos formar
    for(int j = 1; j <= W; j++){
        // tentamos usar cada moeda como a ultima da sequencia
        for(int i = 1; i <= n; i++){
            // verificamos se a moeda pode ser usada para formar j
            if(j >= w[i]){
                // adicionamos as maneiras de formar j - w[i]
                // usando a moeda w[i] como a ultima moeda
                dp[j] += dp[j - w[i]];
                // aplicamos o modulo para evitar valores muito grandes
                dp[j] %= MOD;
            }
        }
    }

    // imprimimos a quantidade de maneiras de formar W
    cout << dp[W] << endl;
}
