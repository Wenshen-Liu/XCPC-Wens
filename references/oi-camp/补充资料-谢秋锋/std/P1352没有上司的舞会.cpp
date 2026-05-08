//Problem：洛谷P1352没有上司的舞会
//Web：https://www.luogu.com.cn/problem/P1352
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
#define MAX 10000
inline int read()
{
	int x=0;bool t=false;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')t=true,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return t?-x:x;
}
struct Line{int v,next;}e[MAX];
int h[MAX],cnt=1;
void Add(int u,int v){e[cnt]=(Line){v,h[u]};h[u]=cnt++;}
int n,r[MAX],f[MAX][2],root;
bool vis[MAX];
void dfs(int u)
{
	f[u][0]=0;//当前这个点不选
	f[u][1]=r[u];//当前这个点选
	for(int i=h[u];i;i=e[i].next)
	{
		int v=e[i].v;//儿子节点
		dfs(v);//先dfs下去，消除后效性
		//在回朔阶段进行合并
		f[u][0]+=max(f[v][0],f[v][1]);//这个点不选的话，那么它的儿子选不选随意
		f[u][1]+=f[v][0];//如果这个点选了的话，儿子必定不能选
	}
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)r[i]=read();
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read();
		Add(v,u);vis[u]=true;
	}
	for(int i=1;i<=n;++i)
		if(!vis[i])root=i;//找到根节点
	dfs(root);
	printf("%d\n",max(f[root][0],f[root][1]));
	return 0;
}
