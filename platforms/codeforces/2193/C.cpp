#include<bits/stdc++.h>
using namespace std;

int max(int a,int b){return a>b?a:b;}

void solve(){
    int n,q;
    int a[200010],b[200010];
    memset(a,0,sizeof(a));
    cin>>n>>q;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=1;i<=n;++i){
        cin>>b[i];
    }
    for(int i=n;i>=1;--i){
        a[i]=max(a[i],b[i]);
        a[i]=max(a[i],a[i+1]);
    }
    for(int i=1;i<=n;++i){
        a[i]=a[i]+a[i-1];
    }
    for(int i=1;i<=q;++i){
        int l,r;
        cin>>l>>r;
        printf("%d ",a[r]-a[l-1]);
    }
    puts("");
    return ;
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