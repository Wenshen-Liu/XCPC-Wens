#include<bits/stdc++.h>
using namespace std;
const int Maxn=200010;

int a[Maxn],d[Maxn],sum=0;

void solve(){
    int n;
    sum=0;
    cin>>n;
    for(int i=1;i<=n;++i){ 
        cin>>d[i];
        sum+=d[i];
    }
    if()
    for(int i=1;i<=n;++i){
        printf("%d ",d[i]);
    }
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