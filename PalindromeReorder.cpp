#include<bits/stdc++.h>
using namespace std;

map<char, int> mp;
string s, ans = "";
int imp = 0;
char pos = 0;

int main(){
    cin >> s;

    for(int i = 0; i < (int)s.size(); i++){
        if(mp.find(s[i]) == mp.end()) mp[s[i]] = 1;
        else mp[s[i]]++;
    }

    for(auto i = mp.begin(); i != mp.end(); i++){
        if(i->second % 2 == 1){
            imp++;
            pos = i->first;
        }
    }

    if(imp > 1){
        cout << "NO SOLUTION";
        return 0;
    }

    if(s.size() % 2 == 0 && imp > 0){
        cout << "NO SOLUTION";
        return 0;
    }

    for(auto i = mp.begin(); i != mp.end(); i++){
        if(i->first != pos){
            ans += string(i->second/2, i->first);
        }
    }

    if(s.size() % 2 != 0){
        ans += string(mp[pos], pos);
    }

    for(auto i = mp.rbegin(); i != mp.rend(); i++){
        if(i->first != pos){
            ans += string(i->second/2, i->first);
        }
    }

    cout << ans;
}