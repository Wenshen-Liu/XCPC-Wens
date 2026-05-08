#include<bits/stdc++.h>
using namespace std;

const int Maxn=1e8+100;

inline int Read(){
	int x=0;char ch=0;bool w=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return w?-x:x;
}

void Write(int x){
	if(x>9)Write(x/10);
	putchar(x%10+'0');
	return ;
}

int n,T,tot;
int prime[Maxn];
bool vis[Maxn];

void pre(){
	for(int i=2;i<=n;++i){
		if(!vis[i]){
			prime[++tot]=i;
		}
		for(int j=1;j<=tot&&prime[j]*i<=n;++j){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0){
				break;
			}
		}
	}
}

int main(){
	n=Read(),T=Read();
	pre();
	while(T--){
		int x=Read();
		Write(prime[x]);
		puts("");
	}
	return 0;
}
