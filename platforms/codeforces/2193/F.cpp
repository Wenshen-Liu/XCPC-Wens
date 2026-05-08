#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n;
    ll Ax, Ay, Bx, By;
    cin >> n >> Ax >> Ay >> Bx >> By;
    vector<ll> vx(n), vy(n);
    for (int i = 0; i < n; ++i) cin >> vx[i];
    for (int i = 0; i < n; ++i) cin >> vy[i];
    map<ll, pair<ll, ll>> groups;
    for (int i = 0; i < n; ++i) {
        if (groups.find(vx[i]) == groups.end()) {
            groups[vx[i]] = {vy[i], vy[i]};
        } else {
            groups[vx[i]].first = min(groups[vx[i]].first, vy[i]);
            groups[vx[i]].second = max(groups[vx[i]].second, vy[i]);
        }
    }
    vector<pair<ll, ll>> cols;
    for (auto const& [x, range] : groups) {
        cols.push_back(range);
    }
    ll dp_min = 0, dp_max = 0;
    ll last_y_min = Ay, last_y_max = Ay;    
    for (int i = 0; i < cols.size(); ++i) {
        ll cur_min = cols[i].first;
        ll cur_max = cols[i].second;
        ll diff = cur_max - cur_min;
        ll next_dp_min = min(dp_min + abs(last_y_min - cur_max), 
                             dp_max + abs(last_y_max - cur_max)) + diff;

        ll next_dp_max = min(dp_min + abs(last_y_min - cur_min), 
                             dp_max + abs(last_y_max - cur_min)) + diff;
        
        dp_min = next_dp_min;
        dp_max = next_dp_max;
        last_y_min = cur_min;
        last_y_max = cur_max;
    }
    ll final_y_dist = min(dp_min + abs(last_y_min - By), dp_max + abs(last_y_max - By));
    printf("%lld\n",final_y_dist + (Bx - Ax));
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