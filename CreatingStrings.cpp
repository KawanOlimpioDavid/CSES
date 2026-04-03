#include<bits/stdc++.h>
using namespace std;

string s;
vector<string> ans;
set<string> sans;
int indx, n;

void back(int indx, string s){
    if(indx == (int)s.size()){
        if(sans.find(s) == sans.end()){
            sans.emplace(s);
            ans.push_back(s);
            n++;
        }
        return;
    }

    for(int i = indx; i < (int)s.size(); i++){
        swap(s[indx], s[i]);
        back(indx+1, s);
        swap(s[indx], s[i]);
    }
}

int main(){
    cin >> s;
    back(0, s);
    sort(ans.begin(), ans.end());
    cout << n << endl;
    for(int i = 0; i < (int)ans.size(); i++){
        cout << ans[i] << endl;
    }
}