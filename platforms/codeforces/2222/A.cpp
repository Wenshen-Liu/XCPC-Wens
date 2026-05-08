#include<bits/stdc++.h>
using namespace std;
const int Maxn =11;

int n;
int x;
int vis[1001];

void solve(){
    memset(vis,0,sizeof(vis));
    vis[0]=1;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>x;
        int y=100/x;
        for(int j=0;j<=100;++j){
            if(j+y>100)break;
            if(vis[j])vis[j+y]=1;
        }
    }
    for(int i=1;i<=100;++i){
        if(vis[i]==0){
            puts("NO");
            return ;
        }
    }
    puts("YES");
    return;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}