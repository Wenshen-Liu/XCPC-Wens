#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=100010;
ll n;
ll ai[maxn],bi[maxn];
ll mul(ll a,ll b,ll mod){
    ll res=0;
    while(b>0){
        if(b&1) res=(res+a)%mod;
        a=(a+a)%mod;
        b>>=1;
    }
    return res;
}
ll exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){x=1;y=0;return a;}
    ll d=exgcd(b,a%b,x,y);
    ll t=x;
    x=y; y=t-a/b*y;
    return d;
}
ll excrt(){
    ll x,y,k;
    ll M=bi[1],ans=ai[1];
    for(int i=2;i<=n;i++){
        ll a=M,b=bi[i],c=(ai[i]-ans%b+b)%b;
        ll d=exgcd(a,b,x,y);
		ll bg=b/d;
        if(c%d!=0) return -1;
        x=mul(x,c/d,bg);
        ans+=x*M;
        M*=bg;
        ans=(ans%M+M)%M;
    }
    return (ans%M+M)%M;
}
int main(){
	cin>>n;
    for(int i=1;i<=n;++i)cin>>bi[i]>>ai[i];
    cout<<excrt()<<endl;
    return 0;
}
