#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+10;
const int MAXLOG = 30;

// prox[i][x] = elemento alcancado apos 2^i movimentos, partindo de x
int prox[MAXLOG+1][MAXN];
int n, q;

// aqui os funcionarios apontam para os chefes, sentido superior do movimento, pra cime em direcao a raiz
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    prox[0][1] = -1;
    for(int i = 2; i <= n; i++){
        cin >> prox[0][i];
    }

    for(int i = 1; i <= MAXLOG; i++){
        for(int x = 1; x <= n; x++){
            // eh preciso tomar cuidado quando algum acesso pode ser invalido 
            // pode acabar acessando prox[i][-1]
            if(prox[i-1][x] == -1){
                prox[i][x] = -1;
            }
            else{
                // prox[i-1][x] representa o destino apos 2^(i-1) movimentos
                prox[i][x] = prox[i-1][prox[i-1][x]];
            }
        }
    }

    while(q--){
        // planeta inicial e quantidade de movimentos
        int x, k;
        cin >> x >> k;
        // vai usar o binario k pra fazer as viagens
        for(int i = 0; i <= MAXLOG; i++){
            // se o bit i de k esta ligado
            if(k & (1LL << i)){
                // se chegou o chefe de todos
                if(x == -1) break;
                // se nao continua
                x = prox[i][x];  
            } 
        }

        cout << x << endl;
    }
}