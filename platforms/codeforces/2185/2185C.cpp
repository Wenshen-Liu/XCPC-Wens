#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    scanf("%d",&n);
    vector<int> a(n);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    sort(a.begin(), a.end());
    int m = unique(a.begin(), a.end()) - a.begin();
    
    int ans = 1;
    int cnt = 1;
    for(int i=1;i<m;++i){
        if(a[i] == a[i-1] + 1){
            cnt++;
        } else {
            cnt = 1;
        }
        ans = max(ans, cnt);
    }
    printf("%d\n", ans);
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}