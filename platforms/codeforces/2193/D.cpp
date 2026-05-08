#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int min(int a,int b){return a<b?a:b;}
int max(int a,int b){return a>b?a:b;}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<ll> b(n);
    for (int i = 0; i < n; ++i) cin >> b[i];
    sort(a.begin(), a.end(), greater<ll>());
    ll total_needed = 0;
    ll max_score = 0;
    for (int k = 1; k <= n; ++k) {
        total_needed += b[k - 1]; 
        if (total_needed <= n) {
            ll x = a[total_needed - 1];
            max_score = max(max_score, x * k);
        } else {
            break;
        }
    }

    cout << max_score << "\n";
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