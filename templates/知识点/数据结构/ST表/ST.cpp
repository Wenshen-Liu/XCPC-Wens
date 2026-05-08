#include<bits/stdc++.h>
using namespace std;

const int Maxn=1e5+100;

inline int Max(int a,int b){return a>b?a:b;}

inline int Read(){
	int x=0;char ch=0;bool w=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return w?-x:x;
}

void Write(int x){
	if(x<0){x=-x;putchar('-');}
	if(x>9)Write(x/10);
	putchar('0'+x%10);
	return ;
}

int n,Q;
int f[Maxn][20],a[Maxn],log_2[Maxn];

inline int query(int l,int r){
	int k=log2(r-l+1);
	return Max(f[l][k],f[r-(1<<k)+1][k]);
}

int main(){
	n=Read(),Q=Read();
	for(int i=1;i<=n;++i){
		log_2[i]=log_2[i-1]+(i==(1<<(log_2[i-1]+1)));
	}
	for(int i=1;i<=n;++i){
		a[i]=Read();
	}
	for(int i=n;i>=1;--i){
		f[i][0]=a[i];
		for(int j=1;j<=log_2[n-i+1];++j){
			f[i][j]=Max(f[i+(1<<(j-1))][j-1],f[i][j-1]);
		}
	}
	while(Q--){
		int l=Read(),r=Read();
		Write(query(l,r));
		puts("");
	}
	return 0;
}
