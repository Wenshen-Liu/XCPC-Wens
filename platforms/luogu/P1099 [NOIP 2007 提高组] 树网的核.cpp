#include<bits/stdc++.h>
using namespace std;
const int Maxn=310;
int n,s;
int to[Maxn<<1],nxt[Maxn<<1],head[Maxn],w[Maxn],tot;
int dep[Maxn],fa[Maxn],depst;

void add(int u,int v,int val){
    w[++tot]=val;
    nxt[tot]=head[u];
    head[u]=tot;
    to[tot]=v;
    return ;
}

void dfs(int p,int father){
    fa[p]=father;
    for(int i=head[p];i;i=nxt[i]){
        int tt=to[i];
        if(tt==father)
        dep[tt]=dep[p]+w[i];
        
    }
}

void solve(){
    cin>>n>>s;
    for(int i=1;i<=n-1;++i){
        int u,v,val;
        cin>>u>>v>>val;
        add(u,v,val);
    }
    dfs(1,0);
    dfs(depst,0);

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}