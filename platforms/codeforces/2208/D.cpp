#include<bits/stdc++.h>
using namespace std;
const int Maxn=510;

int n;
int vis[Maxn][Maxn];
int cv[Maxn][Maxn];
int u[Maxn],v[Maxn],tot;
int q[Maxn];
int fa[Maxn];
string s;

int f(int x){
    return fa[x]==x?x:fa[x]=f(fa[x]);
}

void solve(){
    tot=0;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>s;
        for(int j=1;j<=n;++j){
            vis[i][j]=s[j-1]-'0';
        }
    }
    
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(i==j||vis[i][j]==0)continue;
            bool tmp=0;
            for(int k=1;k<=n;++k){
                if(i==k||j==k)continue;
                if(vis[i][k]&&vis[k][j]){
                    tmp=1;
                    break;
                }
            }
            if(tmp==0){
                u[++tot]=i;
                v[tot]=j;
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
    
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j)cv[i][j]=0;
        cv[i][i]=1;
    }
    
    for(int i=1;i<=n;++i){
        int h=1,t=0;
        q[++t]=i;
        while(h<=t){
            int c=q[h++];
            for(int e=1;e<=tot;++e){
                if(u[e]==c&&!cv[i][v[e]]){
                    cv[i][v[e]]=1;
                    q[++t]=v[e];
                }
            }
        }
    }
    
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(vis[i][j]!=cv[i][j]){
                cout<<"NO\n";
                return;
            }
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
    cin>>T;
    while(T--)solve();
    return 0;
}