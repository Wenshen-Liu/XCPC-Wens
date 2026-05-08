#include<bits/stdc++.h>
using namespace std;
const int N=1e4+100,M=5e4+100;
int n,m;
int sim_cnt,sim_head[N];
int dfn[N],low[N],num;
int top,sta[N];
int co[N],col,tot[N];
int in[N],val[N],ans;
struct node{
	int from,next,to;
}sim[M];

void sim_add(int x,int y){
	sim[++sim_cnt].next=sim_head[x];
	sim[sim_cnt].to=y;
	sim_head[x]=sim_cnt;
	sim[sim_cnt].from=x;
}

void Tarjan(int p){
	dfn[p]=low[p]=++num;
	sta[++top]=p;
	for(int i=sim_head[p];i;i=sim[i].next){
		int tt=sim[i].to;
		if(!dfn[tt]){
			Tarjan(tt);
			low[p]=min(low[p],low[tt]);
		}
		else if(!co[tt]){
			low[p]=min(low[p],dfn[tt]);
		}
	}
	if(low[p]==dfn[p]){
		co[p]=++col;
		while(sta[top]!=p){
			co[sta[top]]=col;
			--top;
			++tot[col];
		}
		++tot[col];
		--top;
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		int x,y;
		cin>>x>>y;
		sim_add(y,x);
	}
	for(int i=1;i<=n;++i)if(!dfn[i])Tarjan(i);
//	for(int i=1;i<=n;++i)cout<<i<<" "<<co[i]<<endl;
	for(int i=1;i<=m;++i){
		int x=co[sim[i].from],y=co[sim[i].to];
		if(x!=y)++in[y];
	}
	int flag=0;
	for(int i=1;i<=col;++i){
		if(!in[i])ans=tot[i],++flag;
	}
	if(flag==1)cout<<ans<<endl;
	else cout<<0<<endl;
	return 0;
}
