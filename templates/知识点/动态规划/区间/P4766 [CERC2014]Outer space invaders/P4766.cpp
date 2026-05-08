#include<bits/stdc++.h>
using namespace std;

const int Maxl=10001;
const int Maxn=301;

int Max(int a,int b){return a>b?a:b;}
int Min(int a,int b){return a<b?a:b;}

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

int T,n,len;
int rank[Maxl],f[Maxn<<1][Maxn<<1];
bool vis[Maxl];
vector<int> vec[Maxl];
struct node{
	int a,b,d;
}p[Maxn];
bool cmp1(node x,node y){return x.d<y.d;}

int main(){
	//freopen("1.in","r",stdin);
	T=read();
	while(T--){
		memset(rank,0,sizeof(rank));
		memset(vis,0,sizeof(vis));
		memset(f,0,sizeof(f));
		n=read();
		len=0;
		for(int i=1;i<=n;++i){
			p[i].a=read(),p[i].b=read(),p[i].d=read();
			vis[p[i].a]=vis[p[i].b]=true;
		}
		for(int i=1;i<=Maxl;++i){
			if(vis[i]){
				++len;
				rank[i]=len;
			}
		}
		for(int i=1;i<=n;++i){
			p[i].a=rank[p[i].a];
			p[i].b=rank[p[i].b];
		}
		sort(p+1,p+1+n,cmp1);
		for(int i=1;i<=len-1;++i){
			for(int j=1;j<=len-i;++j){
				int l=j,r=j+i;
				int id=-1;
				for(int k=1;k<=n;++k){
					if(p[k].a>=l&&p[k].b<=r&&(id==-1||p[id].d<p[k].d))id=k;
				}
				if(id==-1)continue;
				f[l][r]=0x3f3f3f3f;
				for(int k=p[id].a;k<=p[id].b;++k){
					f[l][r]=Min(f[l][r],f[l][k-1]+f[k+1][r]+p[id].d);
				}
			}
		}
		write(f[1][len]);
		putchar('\n');
	}
	return 0;
}
