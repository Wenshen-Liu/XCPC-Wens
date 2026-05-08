#include<bits/stdc++.h>
#define N 201
#define M 5001
using namespace std;
typedef long long ll;

inline int read(){
	int x=0,w=0;char ch=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^'0');ch=getchar();}
	return w?-x:x;
}

ll Min(ll a,ll b){return a<b?a:b;}

int n,m,s,t;
ll ans,val[M<<1];
int nxt[M<<1],to[M<<1],head[N],cnt=1;
int dep[N];

void add(int u,int v,int w){
	++cnt;
	to[cnt]=v;
	val[cnt]=w;
	nxt[cnt]=head[u];
	head[u]=cnt;
	return;
}
//bfs: BFS is used to check if the flow can get to the end.
bool bfs(){
	memset(dep,0,sizeof(dep));
	queue<int> q;
	dep[s]=1;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(val[i]&&!dep[v]){
				dep[v]=dep[u]+1;
				q.push(v);
    	  	}
    	}
  	}
 	return dep[t]; 
}
// dfs: After BFS's check ,DFS can update the data and explore the flow.

ll dfs(int u,ll in){
	if(u==t){
		return in;
	}
	ll out=0;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(dep[v]!=dep[u]+1||!val[i])continue;
		ll res=dfs(v,Min(in,val[i]));
		in-=res;
		out+=res;
		val[i]-=res;
		val[i^1]+=res;
	}
	if(out==0){
		dep[u]=0;
	}
	return out;
}

int main(){
//	freopen("1.in","r",stdin);
	n=read(),m=read(),s=read(),t=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		add(u,v,w);
		add(v,u,0);
	}	
	while(bfs()){
		ll res=0;
		if((res=dfs(s,1e16))>0)ans+=res;
	}
	printf("%lld\n",ans);
	return 0;
}

