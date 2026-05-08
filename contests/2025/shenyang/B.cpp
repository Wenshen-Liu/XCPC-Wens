#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 使用数组统计颜色频率，sum of nm <= 10^6 
const int MAX_VAL = 1000005;
int color_counts[MAX_VAL];
int appeared[MAX_VAL];
int app_ptr = 0;

void solve() {
    int n, m;
    long long a, b;
    if (!(cin >> n >> m >> a >> b)) return;

    int zero_count = 0;
    int non_zero_total = 0;
    app_ptr = 0;

    for (int i = 0; i < n * m; ++i) {
        int p;
        cin >> p;
        if (p == 0) {
            zero_count++; 
        } else {
            if (color_counts[p] == 0) {
                appeared[app_ptr++] = p;
            }
            color_counts[p]++;
            non_zero_total++;
        }
    }

    // 方案 1：不使用全色图层，直接用画笔涂抹所有非零像素 [cite: 16]
    long long base_cost = (long long)non_zero_total * a;
    long long min_total_cost = base_cost;

    // 方案 2：尝试每一种出现的颜色作为免费的初始图层 
    for (int i = 0; i < app_ptr; ++i) {
        int c = appeared[i];
        // 节省：该颜色 c 所有的像素都不再需要画笔 [cite: 16]
        // 支出：所有目标为 0 的位置必须用橡皮擦擦除 [cite: 17, 31]
        long long current_cost = (long long)(non_zero_total - color_counts[c]) * a + (long long)zero_count * b;
        
        if (current_cost < min_total_cost) {
            min_total_cost = current_cost;
        }
        // 清理现场
        color_counts[c] = 0;
    }

    cout << min_total_cost << "\n"; 
}

int main() {
    // 提升 IO 性能以应对 10^5 级测试用例 [cite: 20]
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}