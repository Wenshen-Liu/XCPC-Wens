#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    ll x;
    cin >> n >> x;
    // 使用 vector 替代定长数组，更安全
    vector<ll> a(n), b(n), c(n);
    
    ll Sfree = 0;
    ll Dmax = -2e18; // 初始化为一个极小值，虽然题目逻辑下 0 也可以
    
    for(int i = 0; i < n; ++i){
        cin >> a[i] >> b[i] >> c[i];
        // 累加免费距离
        Sfree += a[i] * (b[i] - 1);
        // 更新最大回滚净收益
        // 注意：max函数比较时，要确保类型一致
        ll profit = a[i] * b[i] - c[i];
        if (i == 0) Dmax = profit; // 简单处理初始值
        else Dmax = max(Dmax, profit);
    }

    // 【关键修正】这里必须是 >=，如果刚好走到，也是 0 次回滚
    if(Sfree >= x) {
        cout << "0\n"; // 建议使用 \n 替代 endl 加快速度
    }
    else if(Dmax <= 0) {
        cout << "-1\n";
    }
    else {
        ll rem = x - Sfree;
        // 向上取整的除法写法： (rem + Dmax - 1) / Dmax
        // 你的写法 (rem / Dmax) + (rem % Dmax != 0) 也是完全正确的
        cout << (rem + Dmax - 1) / Dmax << "\n";
    }
}

int main(){
    // 【IO加速】
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}