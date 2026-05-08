#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int Mod=2008;
const int Maxn=51;

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

int n,m,tot;
ll p[Maxn];

void get_p(ll x){
	for(int i=n;i>=0;--i){
		if(!(x>>i))continue;
		if(!p[i]){
			p[i]=x;
			++tot;
			break;
		}
		x^=p[i];
	}
	return ;
}

int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		char ch[Maxn];
		scanf("%s",ch);
		ll x=0;
		for(int j=0;j<n;++j){
			if(ch[j]=='O')x|=(1ll<<(n-j));
		}
		get_p(x);
	}
	write((1ll<<tot)%Mod);
	putchar('\n');
	return 0;
}
