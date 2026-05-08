#include<bits/stdc++.h>
using namespace std;
#define Maxn 100010
typedef long long ll;
int n,m;
ll a1[Maxn],a2[Maxn];

void solve(){
    cin>>n>>m;
    ll sum=0;
    int n1=0,n2=0;
    for(int i=1;i<=n;++i){
        if(i&1){
            ++n1;
            cin>>a1[n1];
            sum+=a1[n1];
        }
        else {
            ++n2;
            cin>>a2[n2];
            sum+=a2[n2];
        }
    }
    sort(a1+1,a1+1+n1);
    sort(a2+1,a2+1+n2);
    int m1=0,m2=0;
    for(int i=1;i<=m;++i){
        int x;
        cin>>x;
        if(x&1)++m1;
        else ++m2;
    }
    for(int i=n1;i>=1&&n1-i+1<=m1;--i){
        if(a1[i]>0||i==n1){
            sum-=a1[i];
        }
    }
    for(int i=n2;i>=1&&n2-i+1<=m2;--i){
        if(a2[i]>0||i==n2){
            sum-=a2[i];
        }
    }
    printf("%lld\n",sum);
}

int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}