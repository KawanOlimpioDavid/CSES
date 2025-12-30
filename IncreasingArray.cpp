#include <bits/stdc++.h>
using namespace std;

typedef  long long int lli;

int main(){
    lli n, ans = 0;
    cin >> n;
    lli array[n];

    for(int i = 0; i < n; i++){
        cin >> array[i];
    }
    for(int i = 1; i < n; i++){
        if(array[i] < array[i-1]){
            ans +=  array[i-1] - array[i];
            array[i] = array[i-1];
        }
    }
    cout << ans;
}