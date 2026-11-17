
#include <bits/stdc++.h>
using namespace std;

#define MAXN 100010

int n, k;
int pai[MAXN], peso[MAXN], qnt[MAXN];

int find(int x) {
    if (pai[x] == x) return x;
    return pai[x] = find(pai[x]);
}

void join(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return;

    if (peso[x] < peso[y]) {
        pai[x] = y;
        qnt[y] += qnt[x];
    }
    else if (peso[x] > peso[y]) {
        pai[y] = x;
        qnt[x] += qnt[y];
    }
    else {
        pai[x] = y;
        peso[y]++;
        qnt[y] += qnt[x];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        pai[i] = i;
        peso[i] = 0;
        qnt[i] = 1;
    }

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        join(a, b);
    }

    vector<int> roads;

    for (int i = 1; i <= n; i++) {
        if (find(i) == i) {
            roads.push_back(i);
        }
    }

    cout << (int)roads.size() - 1 << '\n';

    for (int i = 0; i < (int)roads.size() - 1; i++) {
        cout << roads[i] << " " << roads[i + 1] << '\n';
    }

    return 0;
}
