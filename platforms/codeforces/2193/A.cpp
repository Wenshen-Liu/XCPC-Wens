#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,s,x;
    int a[20],f[200];
    memset(f,0,sizeof(f));
    cin>>n>>s>>x;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    int sum=0;
    for(int k=1;k<=n;++k){
        sum+=a[k];
    }
    if(sum<=s&&(s-sum)%x==0)puts("YES");
    else puts("NO");
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