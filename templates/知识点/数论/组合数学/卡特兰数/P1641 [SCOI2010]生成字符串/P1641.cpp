#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Mod=20100403;
const int Maxn=2e6+1;

inline int Read(){
	int x=0;bool w=0;char ch=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return w?-x:x;
}

inline void Write(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>9)Write(x/10);
	putchar(x%10+48);
	return ;
}

ll Pow(ll a,ll b,ll mod){
	ll ans=1;
	while(b){
		if(b&1)ans=(ans*a)%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}

int n,m;
ll fac[Maxn],ans1,ans2;

int main(){
	n=Read(),m=Read();
	fac[1]=1;
	for(int i=2;i<=m+n;++i){
		fac[i]=fac[i-1]*i%Mod;
	}
	ans1=fac[m+n]*Pow(fac[n],Mod-2,Mod)%Mod*Pow(fac[m],Mod-2,Mod)%Mod;
	ans2=fac[m+n]*Pow(fac[m-1],Mod-2,Mod)%Mod*Pow(fac[n+1],Mod-2,Mod)%Mod;
	Write(((ans1-ans2)%Mod+Mod)%Mod);
	putchar('\n');
	return 0;
}
