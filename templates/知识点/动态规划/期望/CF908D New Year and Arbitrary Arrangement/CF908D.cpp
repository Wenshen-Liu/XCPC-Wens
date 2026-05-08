#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Mod=1e9+7;
const int Maxk=1e3+1;
inline int read(){
	int x=0;bool w=0;char ch=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return w?-x:x;
}
inline void write(ll x){
	if(x<0){x=-x;putchar('-');}
	if(x>9)write(x/10);
	putchar(x%10+48);
	return ;
}

int k,a,b,invb,invab;
ll f[Maxk][Maxk];

ll Pow(ll a,int b){
	ll ans=1;
	while(b){
		if(b&1)ans=(ans*a)%Mod;
		a=(a*a)%Mod;
		b>>=1;
	}
	return ans;
}

ll dfs(int i,int j){
	if(i+j>=k)return (i+j+(1ll*a*invb%Mod))%Mod;
	if(f[i][j])return f[i][j];
	return f[i][j]=(dfs(i+1,j)*a%Mod+dfs(i,i+j)*b%Mod)*1ll*invab%Mod;
}

int main(){
	k=read(),a=read(),b=read();
	invab=Pow(a+b,Mod-2);
	invb=Pow(b,Mod-2);
	write(dfs(1,0));
	putchar('\n');
	return 0;
}
