#include<bits/stdc++.h>
using namespace std;
const int Maxn=221;
const int Maxr=133;

int T,n,r;
double ans,p[Maxn],po[Maxn][Maxr],f[Maxn][Maxr],g[Maxn];
int d[Maxn];

int main(){
	freopen("1.in","r",stdin);
	scanf("%d",&T);
	while(T--){
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		ans=0;
		scanf("%d%d",&n,&r);
		for(int i=1;i<=n;++i){
			scanf("%lf%d",&p[i],&d[i]);
			po[i][0]=1.0;
			for(int j=1;j<=r;++j){
				po[i][j]=po[i][j-1]*(1.0-p[i]);
			}
		}
		f[1][0]=po[1][r];
		f[1][1]=g[1]=1-f[1][0];
		for(int i=2;i<=n;++i){
			for(int j=0;j<=r;++j){
				g[i]+=f[i-1][j]*(1-po[i][r-j]);
				f[i][j]+=f[i-1][j]*po[i][r-j];
				if(j>0)f[i][j]+=f[i-1][j-1]*(1-po[i][r-j+1]);
				//printf("%.10lf ",f[i][j]);
			}
			//putchar('\n');
		}
		for(int i=1;i<=n;++i){
			ans+=g[i]*1.0*d[i];
		}
		printf("%.10lf\n",ans);
	}
	return 0;
}
