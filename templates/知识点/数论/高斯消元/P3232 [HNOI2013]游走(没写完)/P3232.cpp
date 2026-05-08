#include<bits/stdc++.h>
using namespace std;

const int Maxn=501;
const int Maxm=125001;

inline int read(){
	int x=0;bool w=0;char ch=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return w?-x:x;
}

double Fabs(double x){return x<0?-x:x;}

int n,m;
int in[Maxn],to[Maxm<<1],from[Maxm<<1],cnt;
double f[Maxn],ans,g[Maxn],a[Maxn][Maxn],b[Maxn];

void add(int u,int v){
	++cnt;
	from[cnt]=u;
	to[cnt]=v;
	return ;
}

void Gause(){
	for(int i=1;i<=n;++i){
		int p=i;
		for(int j=i+1;j<=n;++j){
			if(Fabs(a[j][i])>Fabs(a[p][j]))p=j;
		}
		for(int j=1;j<=n;++j){
			swap(a[i][j],a[p][j]);
		}
		swap(b[i],b[p]);
		for(int j=1;j<=n;++j){
			if(j!=i){
				double tmp=a[j][i]/a[i][i];
				for(int k=i;k<=n;++k){
					a[j][k]-=a[i][k]*tmp;
				}
				b[j]-=b[i]*tmp;
			}
		}
	}
	for(int i=1;i<=n;++i){
		f[i]=b[i]/a[i][i];
	}
	return ;
}

int main(){
	freopen("1.in","r",stdin);
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		in[u]+=1.0;
		in[v]+=1.0;
		if(u==n||v==n)continue;
		add(u,v);
	}
	b[1]=1.0;
	for(int i=1;i<=n;++i){
		a[i][i]=1.0;
	}
	for(int i=1;i<=cnt;++i){
		a[from[i]][to[i]]=-1.0/in[to[i]];
		a[to[i]][from[i]]=-1.0/in[from[i]];
	}
	Gause();
	
	for(int i=1;i<=n-1;++i){
		printf("%.2lf\n",f[i]);
	}
	
	for(int i=1;i<=cnt;++i){
		g[i]+=1.0*f[from[i]]/in[from[i]];
		g[i]+=1.0*f[to[i]]/in[to[i]];
	}
	/*
	for(int i=1;i<=m;++i){
		printf("%.2lf\n",g[i]);
	}
	*/
	sort(g+1,g+1+m);
	for(int i=1;i<=m;++i){
		ans+=(n-i+1)*g[i];
	}
	printf("%.3lf\n",ans);
	return 0;
}
