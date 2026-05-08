#include<bits/stdc++.h>
#define ll long long 
#define N 3000005
using namespace std;

ll read(){
	ll x=0,w=0;char ch=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return w?-x:x;
}

void write(ll x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);putchar(x%10^48);
}

ll inv[N],n,p;

void pre(ll mod){
	inv[0]=inv[1]=1;
	for(int i=2;i<=n;++i){
		inv[i]=((mod-mod/i)*inv[mod%i])%mod;
	}
	return ;
}

int main(){
	n=read(),p=read();
	pre(p);
	for(int i=1;i<=n;++i){
		write(inv[i]);
		printf("\n");
	}
	return 0;
}
/*

*/ 
