#include<bits/stdc++.h>
using namespace std;

const int Maxn=2e5+10;
const int Maxm=4e5+10;

inline int Read(){
	int x=0;char ch=0;bool w=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return w?-x:x;
}

struct node{
	int u,v;
}edge[Maxm];

bool cmp1(node x,node y){return x.v>y.v;}

int n,m,sum1,sum2;
int to[Maxm],head[Maxn],nxt[Maxm],tot;
int in[Maxn],out[Maxn],root=1;
int ans[Maxn],cnt;

inline void add(int u,int v){
	++tot;
	to[tot]=v;
	nxt[tot]=head[u];
	head[u]=tot;
	return ;
}

void dfs(int u){
	for(int i=head[u];i;i=head[u]){
		int v=to[i];
		head[u]=nxt[i];
		dfs(v);
	}
	ans[++cnt]=u;
	return ;
}

int main(){
	n=Read(),m=Read();
	for(int i=1;i<=m;++i){
		edge[i].u=Read(),edge[i].v=Read();
	}
	sort(edge+1,edge+1+m,cmp1);
	for(int i=1;i<=m;++i){
		++in[edge[i].v];
		++out[edge[i].u];
		add(edge[i].u,edge[i].v);
	}
	bool flag=0;
	for(int i=1;i<=n;++i){
		if(abs(out[i]-in[i])>1){
			printf("No");
			return 0;
		}
		if(out[i]>in[i]){
			++sum1;
			root=i;
			flag=1;
		}
		if(out[i]<in[i]){
			++sum2;
			flag=1;
		}
	}
	if(flag&&(sum1!=1||sum2!=1)){
		printf("No");
		return 0;
	}
	dfs(root);
	for(int i=cnt;i>=1;--i){
		printf("%d ",ans[i]);
	}
	return 0;
}
