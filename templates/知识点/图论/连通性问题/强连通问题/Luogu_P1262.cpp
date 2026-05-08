#include<bits/stdc++.h>
using namespace std;
const int N=3e3+100,M=8e3+100,INF=0x7fffffff;

int n,m,spend_num;
int spend[N];
int c_head[N],sim_head[N],sim_cnt,c_cnt;
int col,co[N],cost[N],low[N],dfn[N],name[N],num;
int sta[N],top;
int in[N],ans1,ans2=N;
bool pay[N],flag=true;
struct node{
	int from,to,next;
}sim[M],c[M];

void sim_add(int x,int y){
	sim[++sim_cnt].next=sim_head[x];
	sim[sim_cnt].to=y;
	sim_head[x]=sim_cnt;
	sim[sim_cnt].from=x;
}

void c_add(int x,int y){
	c[++c_cnt].next=c_head[x];
	c[c_cnt].to=y;
	c_head[x]=c_cnt;
	c[c_cnt].from=x;
}

void Tarjan(int p){
	low[p]=dfn[p]=++num;
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
		cost[col]=INF;
		name[col]=p;
		if(spend[p])cost[col]=spend[p];
		while(sta[top]!=p){
			co[sta[top]]=col;
			if(spend[sta[top]])cost[col]=min(cost[col],spend[sta[top]]);
			name[col]=min(name[col],sta[top]);
			--top;
		}
		--top;
	}
}

void topo(){
	queue<int> q;
	for(int i=1;i<=col;++i){
		if(!in[i])q.push(i);
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		if(!pay[x]){
			if(cost[x]==INF){
				flag=false;
				ans2=min(ans2,name[x]);
				continue;
			}
			else {
				ans1+=cost[x];
			}
		}
		for(int i=c_head[x];i;i=c[i].next){
			int tt=c[i].to;
			pay[tt]=1;
			--in[tt];
			if(!in[tt])q.push(tt);
		}
	}
}

int main(){
	cin>>n>>spend_num;
	for(int i=1;i<=spend_num;++i){
		int x,y;
		cin>>x>>y;
		spend[x]=y;
	}
	cin>>m;
	for(int i=1;i<=m;++i){
		int x,y;
		cin>>x>>y;
		sim_add(x,y);
	}
	for(int i=1;i<=n;++i)if(!dfn[i])Tarjan(i);
	for(int i=1;i<=m;++i){
		int x=co[sim[i].from],y=co[sim[i].to];
		if(x==y)continue;
		c_add(x,y);
		++in[y];
	}
	topo();
	if(flag)cout<<"YES"<<endl<<ans1<<endl;
	else cout<<"NO"<<endl<<ans2<<endl;
	return 0;
}
