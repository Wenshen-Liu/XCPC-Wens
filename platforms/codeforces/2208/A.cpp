#include<bits/stdc++.h>
using namespace std;
const int Maxn=110;
int a[Maxn*Maxn];


void solve(){
    memset(a,0,sizeof(a));
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            int x;
            cin>>x;
            ++a[x];
        }
    }
    for(int i=1;i<=10000;++i){
        if(a[i]>n*(n-1)){
            puts("NO");
            return ;
        }
    }
    puts("YES");
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