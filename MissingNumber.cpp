#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    scanf("%lld", &n);

    long long total = n * (n + 1) / 2;
    long long sum = 0, x;

    for (int i = 0; i < n - 1; i++) {
        scanf("%lld", &x);
        sum += x;
    }

    printf("%lld\n", total - sum);
    return 0;
}
