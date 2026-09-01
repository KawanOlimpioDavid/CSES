#include<bits/stdc++.h>
using namespace std;

#define maxn 200010
int songs[maxn];
int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0 ; i < n; i++){
        cin >> songs[i];
    }

    int l = 0, ans = 1;
    map<int, int> rec;
    for(int r = 0; r < n; r++){
        rec[songs[r]]++;
        while(rec[songs[r]] > 1){
            rec[songs[l]]--;
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans << endl;
}