#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Maxn 200010

int nxt[Maxn<<1],to[Maxn<<1],head[Maxn],tot;
ll dis[Maxn],val[Maxn<<1];
bool vis[Maxn];

void add(int u,int v,ll w){
    to[++tot]=v;
    nxt[tot]=head[u];
    head[u]=tot;
    val[tot]=w;
    return ;
}

void Dijkstra(int n){
    priority_queue< pair<ll,int>>q;
    for(int i=1;i<=n;++i){
        q.push(make_pair(-dis[i],i));
    }
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int i=head[u];i;i=nxt[i]){
            int tt=to[i];
            if(dis[u]+val[i]<dis[tt]){
                dis[tt]=dis[u]+val[i];
                q.push(make_pair(-dis[tt],tt));
            }
        }
    }
    return ;
}

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        ll u,v,w;
        cin>>u>>v>>w;
        add(u,v,2*w);
        add(v,u,2*w);
    }
    for(int i=1;i<=n;++i){
        cin>>dis[i];
    }
    Dijkstra(n);
    for(int i=1;i<=n;++i){
        printf("%lld ",dis[i]);
    }
    puts("");
    return ;
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