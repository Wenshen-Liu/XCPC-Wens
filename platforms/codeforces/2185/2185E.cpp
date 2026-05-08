#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;
const int INF = 1e9 + 7;

int a[MAXN], b[MAXN];
int l_dist[MAXN], r_dist[MAXN];
int time_l[MAXN], time_r[MAXN];
int death_counts[MAXN];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    string gdCode;
    cin >> gdCode;
    sort(b, b + m);
    for (int i = 0; i <= k; ++i) {
        time_l[i] = time_r[i] = INF;
        death_counts[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        l_dist[i] = r_dist[i] = INF;
        int idx = lower_bound(b, b + m, a[i]) - b;
        if (idx < m) r_dist[i] = b[idx] - a[i];
        if (idx > 0) l_dist[i] = a[i] - b[idx - 1];
    }
    int cur = 0;
    for (int i = 1; i <= k; ++i) {
        if (gdCode[i - 1] == 'L') cur--;
        else cur++;

        if (cur < 0) {
            int d = -cur;
            if (d <= k && time_l[d] == INF) time_l[d] = i;
        } else if (cur > 0) {
            int d = cur;
            if (d <= k && time_r[d] == INF) time_r[d] = i;
        }
    }
    for (int i = 0; i < n; ++i) {
        int t_die = INF;
        if (l_dist[i] <= k) t_die = min(t_die, time_l[l_dist[i]]);
        if (r_dist[i] <= k) t_die = min(t_die, time_r[r_dist[i]]);
        if (t_die <= k) death_counts[t_die]++;
    }
    int current_alive = n;
    for (int i = 1; i <= k; ++i) {
        current_alive -= death_counts[i];
        printf("%d ",current_alive);
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}