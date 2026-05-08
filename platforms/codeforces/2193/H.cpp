#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 200005;
const int MAXM = 400005;

int n;
ll a[MAXN];
bool possible;

int head_adj[MAXN], to_adj[MAXM], nxt_adj[MAXM], edge_cnt_adj;
int head_g[MAXN], to_g[MAXM], nxt_g[MAXM], edge_cnt_g;
int in_degree[MAXN];
int child_req[MAXN];

int q[MAXN];
int res[MAXN];

void add_edge_adj(int u, int v) {
    edge_cnt_adj++;
    to_adj[edge_cnt_adj] = v;
    nxt_adj[edge_cnt_adj] = head_adj[u];
    head_adj[u] = edge_cnt_adj;
}

void add_edge_g(int u, int v) {
    edge_cnt_g++;
    to_g[edge_cnt_g] = v;
    nxt_g[edge_cnt_g] = head_g[u];
    head_g[u] = edge_cnt_g;
    in_degree[v]++;
}

int dfs(int u, int p) {
    if (!possible) return 0;

    for (int i = head_adj[u]; i; i = nxt_adj[i]) {
        int v = to_adj[i];
        if (v == p) continue;
        child_req[v] = dfs(v, u);
        if (!possible) return 0;
    }

    ll sum_fixed = 0;
    int odd_flex_child = -1;

    for (int i = head_adj[u]; i; i = nxt_adj[i]) {
        int v = to_adj[i];
        if (v == p) continue;

        int req = child_req[v];
        if (req == 1) {
            if (a[u] % 2 == 0) {
                possible = false;
                return 0;
            }
        } else {
            if (a[u] % 2 != 0) {
                sum_fixed += a[v];
            } else {
                if (a[v] % 2 != 0) {
                    odd_flex_child = v;
                }
            }
        }
    }

    int target_sum_parity = 1 - (int)(a[u] % 2);
    int current_sum_parity = (int)(sum_fixed % 2);
    
    bool use_flip = false;
    if (current_sum_parity != target_sum_parity) {
        if (a[u] % 2 == 0) {
            if (odd_flex_child != -1) {
                use_flip = true;
            } else {
                return 1; 
            }
        } else {
            return 1;
        }
    }

    for (int i = head_adj[u]; i; i = nxt_adj[i]) {
        int v = to_adj[i];
        if (v == p) continue;

        int req = child_req[v];
        if (req == 1) {
            add_edge_g(v, u);
        } else {
            if (a[u] % 2 != 0) {
                add_edge_g(u, v);
            } else {
                if (use_flip && v == odd_flex_child) {
                    add_edge_g(u, v);
                    use_flip = false; 
                } else {
                    add_edge_g(v, u);
                }
            }
        }
    }

    return 0;
}

void solve() {
    if (scanf("%d", &n) == EOF) return;
    
    possible = true;
    edge_cnt_adj = 0;
    edge_cnt_g = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        head_adj[i] = 0;
        head_g[i] = 0;
        in_degree[i] = 0;
    }
    
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge_adj(u, v);
        add_edge_adj(v, u);
    }

    if (dfs(1, 0) == 1) possible = false;

    if (!possible) {
        printf("NO\n");
        return;
    }

    int l = 0, r = 0;
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) q[r++] = i;
    }

    int res_cnt = 0;
    while (l < r) {
        int u = q[l++];
        res[res_cnt++] = u;
        for (int i = head_g[u]; i; i = nxt_g[i]) {
            int v = to_g[i];
            if (--in_degree[v] == 0) q[r++] = v;
        }
    }

    if (res_cnt < n) {
        printf("NO\n");
    } else {
        printf("YES\n");
        for (int i = 0; i < n; ++i) {
            printf("%d%c", res[i], (i == n - 1 ? '\n' : ' '));
        }
    }
}

int main() {
    int t;
    if (scanf("%d", &t) == EOF) return 0;
    while (t--) {
        solve();
    }
    return 0;
}