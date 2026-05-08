#include<bits/stdc++.h>
using namespace std;
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

int Min(int a,int b){return a<b?a:b;}
int Max(int a,int b){return a>b?a:b;}

int x,y,len,ans;
int f[11][11],a[11];

void pre(){
	for(int i=0;i<=9;++i)f[1][i]=1;
	for(int i=2;i<=10;++i){
		for(int j=0;j<=9;++j){
			for(int k=0;k<=9;++k){
				if(abs(k-j)>=2)f[i][j]+=f[i-1][k];
			}
		}
	}
	return;
}
int work(int x){
	len=0;
	ans=0;
	memset(a,0,sizeof(a));
	while(x){
		a[++len]=x%10;
		x/=10;
	}
	for(int i=1;i<=len-1;++i){
		for(int j=1;j<=9;++j){
			ans+=f[i][j];
		}
	}
	for(int i=1;i<=a[len]-1;++i){
		ans+=f[len][i];
	}
	for(int i=len-1;i>=1;--i){
		for(int j=0;j<=a[i]-1;++j){
			if(abs(j-a[i+1])>=2)ans+=f[i][j];
		}
		if(abs(a[i+1]-a[i])<2)break;
	}
	return ans;
}

int main(){
	pre();
	x=read(),y=read();
	write(work(y+1)-work(x));
	putchar('\n');
	return 0;
}
