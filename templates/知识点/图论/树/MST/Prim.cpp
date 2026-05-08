#include<bits/stdc++.h>
using namespace std;

const int Maxn=5e5+10;
const int Maxm=2e5+10;

inline int Read(){
	int x=0;char ch=0;bool w=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return w?-x:x;
}

int n,m,ans,cnt;
int dis[Maxn];
int nxt[Maxm<<1],to[Maxm<<1],val[Maxm<<1],head[Maxn],tot;
bool vis[Maxn];

inline void add(int u,int v,int w){
	++tot;
	to[tot]=v;
	val[tot]=w;
	nxt[tot]=head[u];
	head[u]=tot;
	return ;
}

inline void Prim(){
	priority_queue<pair<int,int> >q;
	q.push(make_pair(0,1));
	while(!q.empty()){
		int u=q.top().second,d=-q.top().first;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		ans+=d;
		++cnt;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(dis[v]>val[i]){
				dis[v]=val[i];
				q.push(make_pair(-dis[v],v));
			}
		}
	}
	return ;
}

int main(){
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	n=Read(),m=Read();
	for(int i=1;i<=m;++i){
		int u=Read(),v=Read(),w=Read();
		add(u,v,w);
		add(v,u,w);
	}
	Prim();
	if(cnt<n)puts("orz");
	else printf("%d",ans);
	return 0;
}
