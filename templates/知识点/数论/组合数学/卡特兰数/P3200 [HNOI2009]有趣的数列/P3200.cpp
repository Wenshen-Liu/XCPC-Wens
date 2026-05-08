#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=1e6+1;

inline int read(){
	int x=0;bool w=0;char ch=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return w?-x:x;
}

inline void write(int x){
	if(x<0){x=-x;putchar('-');}
	if(x>9)write(x/10);
	putchar(x%10+48);
	return ;
}

int n,Mod;
ll ans=1;
int prime[Maxn],tot,cnt[Maxn<<1];
int vis[Maxn<<1];

inline void pre(int nn){
	for(int i=2;i<=nn;++i){
		if(!vis[i]){
			prime[++tot]=i;
		}
		for(int j=1;j<=tot&&prime[j]*i<=nn;++j){
			vis[prime[j]*i]=prime[j];
			if(i%prime[j]==0)break;
		}
	}
	return ;
}

inline int Pow(ll a,int b,int mod){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

int main(){
	n=read(),Mod=read();
	pre(n<<1);
	for(int i=1;i<=n;++i){
		--cnt[i];
	}
	for(int i=n+2;i<=(n<<1);++i){
		++cnt[i];
	}
	for(int i=(n<<1);i>1;--i){
		if(vis[i]){
			cnt[vis[i]]+=cnt[i];
			cnt[i/vis[i]]+=cnt[i];
		}
	}
	for(int i=1;i<=tot;++i){
		ans=ans*Pow(prime[i],cnt[prime[i]],Mod)%Mod;
	}
	write(ans);
	putchar('\n');
	return 0;
}
