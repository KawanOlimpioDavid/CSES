#include<bits/stdc++.h>
using namespace std;

#define maxn 200010
int nums[maxn], prefix[maxn];
int n;
long long x, ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
        // if(i == 0) prefix[i] = nums[i];
        // else prefix[i] += prefix[i - 1] + nums[i]; 
    } 

    int l = 0;
    long long sum = 0;
    for(int r = 0; r < n; r++){
        sum += nums[r];
        
        while(sum > x){
            sum -= nums[l];
            l++;
        }
        if(sum == x) ans++;
    }
    cout << ans << endl;
}