#include<bits/stdc++.h>
using namespace std;
const int Maxn=8010;

int n;
bitset<Maxn>vis[Maxn];
bitset<Maxn>cv[Maxn];
bitset<Maxn>cov;
int u[Maxn],v[Maxn],tot;
int fa[Maxn];
int sz[Maxn];
int p[Maxn];
int head[Maxn],to[Maxn],nxt[Maxn],edg;
string s;

int f(int x){return fa[x]==x?x:fa[x]=f(fa[x]);}

void solve(){
    tot=0;
    edg=0;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>s;
        vis[i].reset();
        cv[i].reset();
        head[i]=0;
        p[i]=i;
        for(int j=1;j<=n;++j){
            if(s[j-1]=='1')vis[i].set(j);
        }
        sz[i]=vis[i].count();
    }
    
    sort(p+1,p+1+n,[&](int a,int b){return sz[a]>sz[b];});
    
    for(int i=1;i<=n;++i){
        cov.reset();
        for(int k=1;k<=n;++k){
            int j=p[k];
            if(i!=j&&vis[i].test(j)){
                if(!cov.test(j)){
                    u[++tot]=i;
                    v[tot]=j;
                    if(tot>=n){
                        cout<<"NO\n";
                        return;
                    }
                    cov|=vis[j];
                }
            }
        }
    }
    
    if(tot!=n-1){
        cout<<"NO\n";
        return;
    }
    
    for(int i=1;i<=n;++i)fa[i]=i;
    int cnt=0;
    for(int i=1;i<=tot;++i){
        int fx=f(u[i]),fy=f(v[i]);
        if(fx!=fy){
            fa[fx]=fy;
            cnt++;
        }
    }
    if(cnt!=n-1){
        cout<<"NO\n";
        return;
    }
    
    for(int i=1;i<=tot;++i){
        to[++edg]=v[i];
        nxt[edg]=head[u[i]];
        head[u[i]]=edg;
    }
    
    for(int k=n;k>=1;--k){
        int c=p[k];
        cv[c].set(c);
        for(int e=head[c];e;e=nxt[e]){
            cv[c]|=cv[to[e]];
        }
        if(cv[c]!=vis[c]){
            cout<<"NO\n";
            return;
        }
    }
    
    cout<<"YES\n";
    for(int i=1;i<=n-1;++i){
        cout<<u[i]<<" "<<v[i]<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    if(cin>>T){
        while(T--)solve();
    }
    return 0;
}