#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=60;
const int MOD=998244353;
int n;
ll maxdn;
ll frac[Maxn],C[Maxn][Maxn];
int a[Maxn],tot;

void pre(){
    frac[0]=1;
    for(int i=1;i<=50;++i){
        frac[i]=frac[i-1]*i%MOD;
    }
    C[0][0]=1;
    for(int i=1;i<=50;++i){
        C[i][0]=1;
        for(int j=1;j<=i;++j){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
            C[i][j]%=MOD;
        }
    }
    return ;
}

ll func(){
    int c1=0;
    for(int i=1;i<=n;++i){
        if(a[i]<0){
            a[0]+=a[i];
            a[i]=0;
        }
        if(a[i]==1)++c1;
        if(a[i]>1)return 0;
    }
    if(a[0]<0)return 0;
    ll ans=0;
    ans=C[c1+a[0]][c1]*frac[c1]%MOD*frac[n-c1]%MOD;
    return ans;
}

void work(){
    maxdn=0;
    cin>>n;
    cin>>a[0];
    tot=a[0];
    for(int i=1;i<=n;++i){
        cin>>a[i];
        tot+=a[i];
    }
    for(int i=1;i<=n;++i){
        a[i]-=tot/n;
    }
    sort(a+1,a+1+n);
    printf("%lld\n",func());
    // for(int i=0;i<=n;++i){
    //     printf("%d ",a[i]);
    // }
    // puts("");
    return ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pre();
    int T;
    cin>>T;
    while(T--){
        work();
    }
    return 0;
}