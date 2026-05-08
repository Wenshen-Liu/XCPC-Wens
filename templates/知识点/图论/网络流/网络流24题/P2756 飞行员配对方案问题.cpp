#include<bits/stdc++.h>
using namespace std;
const int Maxn=1e4+2;
const int Maxm=5e4+1;

inline int Read(){
	int x=0;char ch=0;bool w=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return w?-x:x;
}

inline int Min(int a,int b){return a<b?a:b;}

int n1,n,s,t,ans;
int from[Maxm<<2],nxt[Maxm<<2],head[Maxm<<2],to[Maxm<<2],tot=1,val[Maxm<<2],dep[Maxn];
bool vis[Maxn][Maxn];

inline void add(int u,int v,int w){
	++tot;
	val[tot]=w;
	to[tot]=v;
	from[tot]=u;
	nxt[tot]=head[u];
	head[u]=tot;
	return ;
}

bool bfs(){
	memset(dep,0,sizeof(dep));
	queue<int>q;
	q.push(s);
	dep[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
//		printf("%d:\n",u);
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
//			printf("%d ",v);
			if((!val[i])||dep[v])continue;
			dep[v]=dep[u]+1;
			q.push(v);
		}
//		printf("\n--------------\n");
	}
	return dep[t];
}

inline int dfs(int u,int in){
//	printf("%d %d\n",u,in);
	if(u==t)return in;
	int out=0;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(dep[v]!=dep[u]+1||val[i]==0)continue;
		int res=dfs(v,Min(val[i],in));
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
	freopen("1.in","r",stdin);
	n1=Read(),n=Read();
	t=n+1;
//	printf("%d \n",t);
	while(1){
		int u=Read(),v=Read();
		if(u==-1)break;
		if(!vis[u][v]){
			vis[u][v]=1;
			add(u,v,1);
			add(v,u,0);
		}
	}
	for(int i=1;i<=n1;++i){
		add(s,i,1);
		add(i,s,0);
	}
	for(int i=n1+1;i<=n;++i){
		add(i,t,1);
		add(t,i,0);
	}
	while(bfs()){
		ans+=dfs(s,1e8);
	}
	printf("%d\n",ans);
	for(int i=1;i<=tot;++i){
		if(1<=from[i]&&from[i]<=n1&&to[i]<=n&&to[i]>=n1+1&&val[i]==0){
			printf("%d %d\n",from[i],to[i]);
		}
	}
	return 0;
}
