#include<bits/stdc++.h>
using namespace std;

set<int> conjunto;
int n;

int main(){
    cin >> n;
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        conjunto.emplace(x);
    }
    cout << conjunto.size();
}