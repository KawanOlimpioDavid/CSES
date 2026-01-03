#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int> c1;
    vector<int> c2;
    cin >> n;
    
    if(n == 1 || n == 2) cout << "NO";
    else if(n % 4 == 0){
        int i = 0;
        while(i < n/2){
            c1.push_back(n-i);
            c1.push_back(1+i);
            i++;
            c2.push_back(n-i);
            c2.push_back(1+i);
            i++;
        }
        sort(c1.begin(), c1.end(), greater<int>());
        sort(c2.begin(), c2.end(), greater<int>());
        cout<< "YES\n";
        cout << c1.size() << "\n";
        for(int i = 0; i < c1.size(); i++) cout << c1[i] << " ";
        cout << "\n";
        cout << c2.size() << "\n";
        for(int i = 0; i < c2.size(); i++) cout << c2[i] << " ";
    }else if((n - 3) % 4 == 0){
        c1 = {1, 2};
        c2 = {3};
        int i = 0;
        while(i < (n - 3)/2){
            c1.push_back(n-i);
            c1.push_back(4+i);
            i++;
            c2.push_back(n-i);
            c2.push_back(4+i);
            i++;
        }
        sort(c1.begin(), c1.end(), greater<int>());
        sort(c2.begin(), c2.end(), greater<int>());
        cout<< "YES\n";
        cout << c1.size() << "\n";
        for(int i = 0; i < c1.size(); i++) cout << c1[i] << " ";
        cout << "\n";
        cout << c2.size() << "\n";
        for(int i = 0; i < c2.size(); i++) cout << c2[i] << " ";
    }else cout << "NO";
}