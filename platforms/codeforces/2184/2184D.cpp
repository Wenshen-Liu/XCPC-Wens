#include <bits/stdc++.h>

using namespace std;

const int MAX_BIT = 35;
long long C[MAX_BIT][MAX_BIT];

void precompute() {
    for (int i = 0; i < MAX_BIT; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
}

void solve() {
    long long n, k;
    scanf("%lld%lld", &n, &k);
    int L = 0;
    while ((1LL << (L + 1)) <= n) {
        L++;
    }
    L = 0;
    long long temp = n;
    while (temp > 1) {
        temp >>= 1;
        L++;
    }

    long long win_count = 0;
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (i + j + 1 <= k) {
                win_count += C[i][j];
            } else {
                break;
            }
        }
    }
    if (L + 1 <= k) {
        win_count++;
    }
    printf("%lld\n", max(0LL, n - win_count));
}

int main() {
    // 预处理放在外面
    precompute();
    
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        solve();
    }
    return 0;
}