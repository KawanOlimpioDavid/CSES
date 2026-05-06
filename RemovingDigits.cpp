#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int ans = 0;

    while(n > 0){
        int temp = n;
        int maior = 0;

        while(temp > 0){
            maior = max(maior, temp % 10); 
            temp /= 10; 
        }
        n -= maior;
        ans++;
    }

    cout << ans << endl;
}