#include<bits/stdc++.h>
#define N 100005
#define M 500005
using namespace std;

int read(){
	int x=0,w=0;char ch=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return w?-x:x;
}

int Min(int a,int b){return a<b?a:b;}

int n,m,ans;
int in[N],co[N],sim_from[M],sim_next[M],sim_to[M],sim_head[N],sim_cnt=0;
int dfn[N],low[N],sta[N],top=0,num=0,col=0;

void sim_add(int u,int v){
	++sim_cnt;
	sim_from[sim_cnt]=u;
	sim_to[sim_cnt]=v;
	sim_next[sim_cnt]=sim_head[u];
	sim_head[u]=sim_cnt;
	return ;
}

void Tarjan(int p){
	dfn[p]=low[p]=++num;
	sta[++top]=p;
	for(int i=sim_head[p];i;i=sim_next[i]){
		int tt=sim_to[i];
		if(!dfn[tt]){
			Tarjan(tt);
			low[p]=Min(low[p],low[tt]);
		}
		else if(!co[tt]){
			low[p]=Min(low[p],dfn[tt]);
		}
	}
	if(dfn[p]==low[p]){
		co[p]=++col;
		while(sta[top]!=p){
			co[sta[top]]=col;
			--top;
		}
		--top;
	}
	return ;
}

int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		sim_add(u,v);
	}
	for(int i=1;i<=n;++i)if(!dfn[i])Tarjan(i);
	for(int i=1;i<=m;++i){
		if(co[sim_from[i]]==co[sim_to[i]])continue;
		++in[co[sim_to[i]]];
	}
	for(int i=1;i<=col;++i){
		if(!in[i])++ans;
	}
	cout<<ans<<endl;
	return 0;
}

