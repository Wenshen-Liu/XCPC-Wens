#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    double ans=0.0,len=0.0,p;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>p;
        ans=ans+p*(len*2+1);
        len=(len+1)*p;
    }
    printf("%lf\n",ans);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    while(T--){
        solve();
    }
    return 0;
}