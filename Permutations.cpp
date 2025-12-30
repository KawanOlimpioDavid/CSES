#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main(){
    lli n;
    cin >> n;
    if(n == 3 || n == 2){
        cout << "NO SOLUTION";
        return 0;
    }

    vector<lli> array;
    for(lli i = 0; i <= n; i+=2){
        if(i > 0){
            array.push_back(i);
        }
    } 
    for(lli i = 1; i <= n; i+=2){
            array.push_back(i);
    } 
    for(int i = 0; i < n; i++){
        cout << array[i] << ' ';
    }
}