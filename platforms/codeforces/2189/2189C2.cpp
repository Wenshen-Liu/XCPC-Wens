#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    if ((n & (n - 1)) == 0) {
        puts("-1"); 
        return;
    }
    int p[200010];
    p[n] = 1;
    for (int i = 2; i < n; i++) {
        p[i] = i ^ 1;
    }
    if (n % 2 != 0) {
        p[1] = n - 1; 
    } else {
        p[1] = n;
        int lb = n & (-n);
        swap(p[1], p[lb + 1]);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ",p[i]);
    }
    puts("");
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}