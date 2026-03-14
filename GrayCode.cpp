#include<bits/stdc++.h>
using namespace std;

int n;
string ans1, ans2;

int main(){
    cin >> n;
    int p = n * 2;
    ans1 += string(n, '0');
    ans1 += string(n, '1');
    ans2 += string(n, '1');
    ans2 += string(n, '0');
    int ini = 0, fim = n - 1;
    while(fim != p){
        cout << ans1.substr(ini, fim - ini +1) << endl;
        ini++, fim++;
    }
    ini = 1, fim = n;
    while(fim != p-1){
        cout << ans2.substr(ini, fim - ini +1) << endl;
        ini++, fim++;
    }
}