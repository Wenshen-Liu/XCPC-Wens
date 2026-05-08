#include<bits/stdc++.h>
using namespace std;

const int INF=1145141;

void solve() {
    int n;
    cin >> n;
    vector<bool> exists(n + 1, false);
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (val <= n) exists[val] = true;
    }
    vector<int> f(n + 1, INF);
    queue<int> q;
    vector<int> distinct_a;
    if (exists[1]) {
        f[1] = 1;
        q.push(1);
    }
    for (int i = 2; i <= n; ++i) {
        if (exists[i]) {
            f[i] = 1;
            q.push(i);
            distinct_a.push_back(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == 1) continue; 
        for (int x : distinct_a) {
            long long next_val = (long long)u * x;
            if (next_val > n) break;
            if (f[next_val] > f[u] + 1) {
                f[next_val] = f[u] + 1;
                q.push((int)next_val);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if(f[i]>=INF)printf("-1 ");
        else printf("%d ",f[i]);
    }
    puts("");
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}