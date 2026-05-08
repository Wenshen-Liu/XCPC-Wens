#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=4201;

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
ll f[2][Maxn],ans;
int main(){
	n=read(),Mod=read();
	f[0][2]=1;
	for(int i=3;i<=n;++i){
		for(int j=2;j<=i;++j){
			f[i&1][j]=(f[i&1^1][i-j+1]+f[i&1][j-1])%Mod;
		}
	}
	for(int i=2;i<=n;++i){
		ans=(ans+f[n&1][i])%Mod;
	}
	write((ans<<1)%Mod);
	putchar('\n');
	return 0;
}
