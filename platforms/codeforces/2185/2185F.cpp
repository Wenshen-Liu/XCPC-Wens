#include<bits/stdc++.h>

using namespace std;
const int MAX_SIZE = (1 << 19) + 5;
int tree[MAX_SIZE]; 
int n_val;

void update(int p, int v, int num_leaves) {
    int idx = num_leaves + p;
    tree[idx] = v;
    for (idx /= 2; idx >= 1; idx /= 2) {
        tree[idx] = tree[2 * idx] ^ tree[2 * idx + 1];
    }
}

void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;
    n_val = n;
    int num_cows = (1 << n);
    for (int i = 0; i < num_cows; ++i) {
        cin >> tree[num_cows + i];
    }
    for (int i = num_cows - 1; i >= 1; --i) {
        tree[i] = tree[2 * i] ^ tree[2 * i + 1];
    }

    while (q--) {
        int b, c;
        cin >> b >> c;
        int p = b - 1;
        int old_val = tree[num_cows + p];
        update(p, c, num_cows);
        int ans = 0;
        int curr = num_cows + p; 
        int current_stack_size = 1;
        while (curr > 1) {
            int parent = curr / 2;
            int left_child = 2 * parent;
            int right_child = 2 * parent + 1;
            bool right_wins = tree[right_child] > tree[left_child];
            if (curr == left_child) {
                if (right_wins) {
                    ans += current_stack_size;
                }
            } else {
                if (!right_wins) {
                    ans += current_stack_size;
                }
            }
            curr = parent;
            current_stack_size *= 2;
        }

        cout << ans << "\n";
        update(p, old_val, num_cows);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}