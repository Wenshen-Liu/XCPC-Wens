#include<bits/stdc++.h>
using namespace std;
#define Maxn 200010
typedef struct node{
    int id;
    long long v;
} node;

node a[Maxn];
int n;
int b[Maxn];
bool cmp1(node x,node y){
    if(x.v==y.v)return x.id<y.id;
    return x.v<y.v;
}

void solve(){
    cin>>n;
    int x=0;
    for(int i=1;i<=n;++i){
        a[i].v=x+a[i-1].v;
        cin>>x;
        a[i].id=i;
    }
    sort(a+1,a+1+n,cmp1);
    for(int i=1;i<=n;++i){
        b[a[i].id]=n-i+1;
    }
    for(int i=1;i<=n;++i){
        printf("%d ",b[i]);
    }
    puts("");
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