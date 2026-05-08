#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Maxn 200010

int gcd(int a,int b){return b==0?a:gcd(b,a%b);}

int p[17]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};

int n;
ll a[Maxn];
int b[Maxn];

int check(){
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            if(a[i]==a[j])return 0;
        }
    }
    for(int k=1;k<=16;++k){
        memset(b,0,sizeof(b));
        for(int i=1;i<=n;++i){
            b[a[i]%p[k]]++;
        }
        int tmp=0;
        for(int i=0;i<p[k];++i){
            if(b[i]<2)tmp=1;
        }
        if(!tmp)return 0;
    }
    return 1;
}

void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%lld",&a[i]);
    }
    if(check())puts("YES");
    else puts("NO");
}

int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}