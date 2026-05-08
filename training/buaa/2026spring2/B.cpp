#include<bits/stdc++.h>
using namespace std;
#define Maxn 200010

int vis[Maxn],y[Maxn],n;

int gcd(int a,int b){return b==0?a:gcd(b,a%b);}

int check(int k){
    if(vis[k]==1)return 1;
    if(vis[k]==-1)return 0;
    for(int i=1;i<=k;++i){
        int j=i,tmp=0;
        int res=0;
        while(j!=i||tmp==0){
            // printf("%d ",j);
            res^=y[j];
            j+=k;
            j=(j-1)%n+1;
            tmp=1;
        }
        // puts("");
        if(res){
            vis[k]=-1;
            return 0;
        }
    }
    vis[k]=1;
    return 1;
}

void solve(){
    memset(vis,0,sizeof(vis));
    int ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%1d",&y[i]);
    }
    for(int i=1;i<=n;++i){
        ans+=check(gcd(i,n));
    }
    printf("%d\n",ans);
    return ;
}

int main(){
    int T;
    T=1;
    while(T--){
        solve();
    }
    return 0;
}