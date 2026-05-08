#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define Maxn 200050
typedef long long ll;

int n;
int tot,to[Maxn<<1],nxt[Maxn<<1],head[Maxn];
ll dep[Maxn];

ll Pow(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=(res*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}

int Max(int a,int b){return a>b?a:b;}

void add(int u,int v){
    to[++tot]=v;
    nxt[tot]=head[u];
    head[u]=tot;
    return ;
}

void dfs(int p,int fa){
    dep[p]=1;
    for(int i=head[p];i;i=nxt[i]){
        int tt=to[i];
        if(tt==fa)continue;
        dfs(tt,p);
        dep[p]=Max(dep[p],dep[tt]+1);
    }
    return ;
}

void solve(){
    tot=0;
    memset(head,0,sizeof(head));
    scanf("%d",&n);
    for(int i=1;i<=n-1;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    dfs(1,0);
    ll ans=0,res=Pow(2,n-1);
    for(int i=1;i<=n;++i){
        ans=(ans+(dep[i]*res%MOD))%MOD;
    }
    printf("%lld\n",ans);
    return ;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}