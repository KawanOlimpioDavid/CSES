#include <bits/stdc++.h>
using namespace std;

int main() {
    string DNA;
    cin >> DNA;

    int aux = 1, ans = 1;

    for (int i = 1; i < DNA.size(); i++) {
        if (DNA[i] == DNA[i - 1]) {
            aux++;
        } else {
            ans = max(ans, aux);
            aux = 1;
        }
    }

    ans = max(ans, aux);
    cout << ans << endl;
}
