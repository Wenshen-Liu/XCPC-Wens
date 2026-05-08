#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn=2e3+10;
const int Maxm=3e3+10;

inline int Read(){
	int x=0;char ch=0;bool w=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return w?-x:x;
}

int T,n,m;
int nxt[Maxm<<1],to[Maxm<<1],head[Maxn],tot,val[Maxm<<1];
int dis[Maxn];
bool vis[Maxn];

inline void clean(){
	tot=0;
	memset(head,0,sizeof(head));
	memset(dis,0x3f,sizeof(dis));
	return ;
}

inline void add(int u,int v,int w){
	++tot;
	to[tot]=v;
	val[tot]=w;
	nxt[tot]=head[u];
	head[u]=tot;
	return ;
}

void spfa(){
	queue<int>q;
	q.push(1);
	dis[1]=0;
	memset(vis,0,sizeof(vis));
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(dis[v]>dis[u]+val[i]){
				dis[v]=dis[u]+val[i];
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	return ;
}

int main(){
	freopen("1.in","r",stdin);
	T=Read();
	while(T--){
		clean();
		n=Read(),m=Read();
		for(int i=1;i<=m;++i){
			int u=Read(),v=Read(),w=Read();
			add(u,v,w);
			if(w>=0)add(v,u,w);
		}
		spfa();
		printf("%d\n",dis[n]);
	}
	return 0;
}
