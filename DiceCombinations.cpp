#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int n;
long long dp[1000010];

int main() {
    cin >> n;

    // pelo visto nao lancar um dado eh opcao
    dp[0] = 1;

    // transicao
    // n bonitinho para cada numero
    for (int i = 1; i <= n; i++) {
        // faz a soma dos 6 casos anteriores
        for (int j = 1; j <= 6; j++) {
            if (i >= j) {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }

    cout << dp[n] << '\n';
}
