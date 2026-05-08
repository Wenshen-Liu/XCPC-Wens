#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Mod=1e9+7;
const int Maxn=1e5+1;
const int Maxm=101;

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

int n,m;
int head[Maxn],nxt[Maxn<<1],to[Maxn<<1],cnt;
int f[Maxn][Maxm][2][2],tmp[Maxm][2][2],siz[Maxn];


void add(int u,int v){
	++cnt;
	to[cnt]=v;
	nxt[cnt]=head[u];
	head[u]=cnt;
	return ;
}

int Plus(ll x,ll y){
	y%=Mod;
	x+=y;
	return x%Mod;
}

void dfs(int u,int fa){
	siz[u]=f[u][1][1][0]=f[u][0][0][0]=1;
	for(int e=head[u];e;e=nxt[e]){
		int v=to[e];
		if(v==fa)continue;
		dfs(v,u);
		for(int i=0;i<=Min(siz[u],m);++i){
			tmp[i][0][0]=f[u][i][0][0];
			tmp[i][1][0]=f[u][i][1][0];
			tmp[i][0][1]=f[u][i][0][1];
			tmp[i][1][1]=f[u][i][1][1];
			f[u][i][0][0]=0;
			f[u][i][1][0]=0;
			f[u][i][0][1]=0;
			f[u][i][1][1]=0;
		}
		for(int i=0;i<=Min(siz[u],m);++i){
			for(int j=0;j<=Min(siz[v],m-i);++j){
				f[u][i+j][0][0]=Plus(f[u][i+j][0][0],1ll*tmp[i][0][0]*f[v][j][0][1]);
				f[u][i+j][0][1]=Plus(f[u][i+j][0][1],1ll*tmp[i][0][1]*(f[v][j][0][1]+f[v][j][1][1]));
				f[u][i+j][0][1]=Plus(f[u][i+j][0][1],1ll*tmp[i][0][0]*f[v][j][1][1]);
				f[u][i+j][1][0]=Plus(f[u][i+j][1][0],1ll*tmp[i][1][0]*(f[v][j][0][0]+f[v][j][0][1]));
				f[u][i+j][1][1]=Plus(f[u][i+j][1][1],1ll*tmp[i][1][0]*(f[v][j][1][0]+f[v][j][1][1]));
				f[u][i+j][1][1]=Plus(f[u][i+j][1][1],1ll*tmp[i][1][1]*(1ll*f[v][j][0][0]+f[v][j][0][1]+1ll*f[v][j][1][0]+f[v][j][1][1]));
			}
		}
		siz[u]+=siz[v];
	}
	/*
	for(int i=0;i<=m;++i){
		printf("f[%d][%d][0][0]=%d,f[%d][%d][0][1]=%d,f[%d][%d][1][0]=%d,f[%d][%d][1][1]=%d\n",u,i,f[u][i][0][0],u,i,f[u][i][0][1],u,i,f[u][i][1][0],u,i,f[u][i][1][1]);
	}
	*/
	return ;
}

int main(){
	//freopen("1.in","r",stdin);
	n=read(),m=read();
	for(int i=1;i<=n-1;++i){
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	write(Plus(f[1][m][0][1],f[1][m][1][1]));
	putchar('\n');
	return 0;
}
