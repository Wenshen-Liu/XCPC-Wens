#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define N 1010
using namespace std;

ll read(){
	ll x=0,w=0;char ch=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return w?-x:x;
}

ll fastpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b%2)ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}

ll n,inv[N],fac[N];

int main(){
	n=read();
    fac[0]=1;
	inv[0]=inv[1]=1;
    for(ll i=1;i<=2*n;i++){
        fac[i]=fac[i-1]*i%mod;
        inv[i]=fastpow(fac[i],mod-2);
    }
	for(int i=1;i<=n;++i){
		cout<<(fac[i<<1]*inv[i]%mod*inv[i]%mod-fac[i<<1]*inv[i-1]%mod*inv[i+1]%mod+mod)%mod<<" ";
	}
	return 0;
}

