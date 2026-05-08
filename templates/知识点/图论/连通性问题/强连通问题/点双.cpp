#include<bits/stdc++.h>
using namespace std;

const int Maxn=5e4+100;
const int Maxm=3e5+100;

inline int Min(int a,int b){return a<b?a:b;}

inline int Read(){
	int x=0;char ch=0;bool w=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return w?-x:x;
}

int n,m,ans1;
int nxt[Maxm<<1],to[Maxm<<1],head[Maxn],tot;
int dfn[Maxn],low[Maxn],co[Maxn],col;
int sta[Maxn],top,dfstime;
vector<int> ans[Maxn];
bool vis[Maxn],cut_point[Maxn];

inline void add(int u,int v){
	++tot;
	to[tot]=v;
	nxt[tot]=head[u];
	head[u]=tot;
	return ;
}

void Tarjan(int u){
	dfn[u]=low[u]=++dfstime;
	sta[++top]=u;
	int child=0;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(!dfn[v]){
			Tarjan(v);
			low[u]=Min(low[u],low[v]);
			if(low[v]>=dfn[u]){
				++col;
				int d;
				do{
					d=sta[top--];
					ans[col].emplace_back(d);
				}while(d!=v);
				ans[col].emplace_back(u);
				sort(ans[col].begin(),ans[col].end());
			}
		}
		else low[u]=Min(low[u],dfn[v]);
	}
	return ;
}

int main(){
	n=Read(),m=Read();
	for(int i=1;i<=m;++i){
		int u=Read(),v=Read();
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;++i){
		if(!dfn[i])Tarjan(i);
	}
	for(int i=1;i<=col;++i){
		if(ans[i].size()>1)++ans1;
	}
	printf("%d\n",ans1);
	sort(ans+1,ans+1+col);
	for(int i=1;i<=col;++i){
		for(int j=0;j<ans[i].size();++j){
			printf("%d ",ans[i][j]);
		}
		puts("");
	}
	return 0;
}
