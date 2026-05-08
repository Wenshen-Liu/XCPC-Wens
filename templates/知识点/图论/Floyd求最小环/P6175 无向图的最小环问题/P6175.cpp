#include<bits/stdc++.h>
#define Maxn 101
#define Big 2006080500
using namespace std;

typedef long long ll;

inline int read(){
	int x=0,w=0;char ch=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return w?-x:x;
}

ll Min(ll a,ll b){return a<b?a:b;}

ll n,m,ans=Big;
ll dis[Maxn][Maxn];
ll ac[Maxn][Maxn];

int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
    	for(int j=1;j<=n;++j){
    		if(i!=j)ac[i][j]=dis[i][j]=Big;
    	}
	}
	for(int i=1;i<=m;++i){
		ll u=read(),v=read(),w=read();
		ac[u][v]=ac[v][u]=dis[u][v]=dis[v][u]=Min(dis[u][v],w);
	}
	for(int k=1;k<=n;++k){
    	for(int i=1;i<k;++i){
    		for(int j=i+1;j<k;++j){
				ans=Min(ans,dis[i][j]+ac[i][k]+ac[j][k]);
			}
    	}
		for(int i=1;i<=n;++i){
    		for(int j=1;j<=n;++j){
				dis[i][j]=dis[j][i]=Min(dis[i][j],dis[i][k]+dis[j][k]);
			}
		}
	}
	if(ans==Big)printf("No solution.\n");
	else printf("%lld\n",ans);
	return 0;
}
