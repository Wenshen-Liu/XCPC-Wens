#include <stdio.h>
#include <stdbool.h>
int n;
int ans[15];
bool vis[15];
void dfs(int u) {
    if (u > n) {
        for (int i = 1; i <= n; i++) {
            printf("%d%c", ans[i], i == n ? '\n' : ' ');
        }
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!vis
        [i]) {
         ans[u] = i;
            vis
        [i] = 1; 
            dfs(u + 1);
            vis
        [i] = 0;
        }
    }
}
int main() {
    if (scanf("%d", &n) != EOF) {
        dfs(1);
    }
    return 0;
}