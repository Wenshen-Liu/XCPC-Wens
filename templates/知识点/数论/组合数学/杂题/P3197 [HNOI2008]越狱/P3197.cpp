#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Mod=1e5+3;

inline ll Read(){
	ll x=0;bool w=0;char ch=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return w?-x:x;
}

inline void Write(ll x){
	if(x<0){x=-x;putchar('-');}
	if(x>9)Write(x/10);
	putchar(x%10+48);
	return ;
}

ll n,m,ans1,ans2;

inline ll Pow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)ans=(ans*a)%Mod;
		a=(a*a)%Mod;
		b>>=1;
	}
	return ans;
}

int main(){
	m=Read(),n=Read();
	ans1=Pow(m,n);
	ans2=m*Pow(m-1,n-1)%Mod;
	Write(((ans1-ans2)%Mod+Mod)%Mod);
	putchar('\n');
	return 0;
}
