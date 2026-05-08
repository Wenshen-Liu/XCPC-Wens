#include<bits/stdc++.h>
#define Maxn 20001
#define Maxm 200001
using namespace std;

inline int read(){
	int x=0,w=0;char ch=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return w?-x:x;
}

inline void write(int x){
	if(x<0){x=-x;putchar('-');}
	if(x>9)write(x/10);
	putchar(x%10+'0');
	return ;
}

int Min(int a,int b){return a<b?a:b;}

int n,m,ans1,ans2;
int nxt[Maxm],head[Maxn],to[Maxm],cnt;
int dfn[Maxn],low[Maxn],step;
int cut_point[Maxn];

struct line{
	int u,v;
}cut_way[Maxm];

bool cmp1(line a,line b){return a.u==b.u?a.v<b.v:a.u<b.u;}

void add(int u,int v){
	++cnt;
	to[cnt]=v;
	nxt[cnt]=head[u];
	head[u]=cnt;
	return ;
}

void Tarjan(int u,int root){
	dfn[u]=low[u]=++step;
	int child=0;
	bool flag=0;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(!dfn[v]){
			Tarjan(v,root);
			low[u]=Min(low[u],low[v]);
			if(low[v]>=dfn[u]&&root!=u){
				flag=true;
				++ans2;
				cut_way[ans2].u=u;
				cut_way[ans2].v=v;
			}
			if(root==u)++child;
		}
		low[u]=Min(low[u],dfn[v]); 
	}
	if(child>1&&root==u)flag=true;
	if(flag){
		++ans1;
		cut_point[ans1]=u;
	}
	return ;
}
int main(){
	freopen("1.in","r",stdin);
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;++i){
		if(!dfn[i]){
			Tarjan(i,i);
		}
	}
	sort(cut_point+1,cut_point+1+ans1);
	sort(cut_way+1,cut_way+1+ans2,cmp1);
	printf("point:\n");
	if(ans1==0)printf("None!");
	for(int i=1;i<=ans1;++i){
		write(cut_point[i]);
		putchar(' ');
	}
	putchar('\n');
	printf("edge:\n");
	if(ans2==0)printf("None!\n");
	for(int i=1;i<=ans2;++i){
		write(cut_way[i].u);
		printf("---->");
		write(cut_way[i].v);
		putchar('\n');
	}
	return 0;
}
