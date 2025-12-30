#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main(){
    int t;
    lli y = 0, x = 0;
    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> y >> x;
        lli m = max(y, x);
        if(m % 2 == 1){
            cout << (m*m) - (y-1) - (m-x) << "\n";
        }else{
            cout << (m*m) - (x-1) - (m-y) << "\n";
        }
    }
}