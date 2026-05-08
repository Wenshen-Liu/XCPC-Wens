#include<bits/stdc++.h>
using namespace std;

int t;

void solve(){
    int n,m,h;
    int a[200010],b[200010],lazy[200010],tot=0;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(lazy,0,sizeof(lazy));
    scanf("%d%d%d",&n,&m,&h);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;++i){
        int bi,ci;
        scanf("%d%d",&bi,&ci);
        if(lazy[bi]!=tot){
            lazy[bi]=tot;
            b[bi]=0;
        }
        b[bi]+=ci;
        if(a[bi]+b[bi]>h){
            ++tot;
        }
    }
    for(int i=1;i<=n;++i){
        if(lazy[i]!=tot){
            lazy[i]=tot;
            b[i]=0;
        }
        printf("%d ",a[i]+b[i]);
    }
    puts("");
    return ;
}

int main(){
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}