#include<bits/stdc++.h>
using namespace std;
const int N=1e4+100,M=1e5+100;
int n,m,w[N],num,ans;
int cnt,s,head[N];
int dfn[N],co[N],val[N],low[N],col;
int st[N],top;
int in[N],dis[N];
queue<int> q;

struct node{
	int next,to,from;
}sim[M],c[M];

void add_sim(int x,int y){
	sim[++cnt].next=head[x];
	sim[cnt].to=y;
	head[x]=cnt;
	sim[cnt].from=x;
}

void add_c(int x,int y){
	c[++s].next=head[x];
	c[s].to=y;
	head[x]=s;
	c[s].from=x;
}

void Tarjan(int p){
	dfn[p]=low[p]=++num;
	st[++top]=p;
	for(int i=head[p];i;i=sim[i].next){
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
		val[col]+=w[p];
		while(st[top]!=p){
			co[st[top]]=col;
			val[col]+=w[st[top]];
			--top;
		}
		--top;
	}
}

void topo(){
	for(int i=1;i<=col;++i){
		if(!in[i])q.push(i);
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		dis[x]+=val[x];
		ans=max(dis[x],ans);
		for(int i=head[x];i;i=c[i].next){
			int tt=c[i].to;
			--in[tt];
			dis[tt]=max(dis[tt],dis[x]);
			if(!in[tt])q.push(tt);
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>w[i];
	for(int i=1;i<=m;++i){
		int x,y;
		cin>>x>>y;
		add_sim(x,y);
	}
	for(int i=1;i<=n;++i)if(!dfn[i])Tarjan(i);
	memset(head,0,sizeof(head));
	for(int i=1;i<=m;++i){
		int x=co[sim[i].from],y=co[sim[i].to];
		if(x==y)continue;
		add_c(x,y);
		++in[y];
	}
	topo();
	cout<<ans<<endl;
	return 0;
}
