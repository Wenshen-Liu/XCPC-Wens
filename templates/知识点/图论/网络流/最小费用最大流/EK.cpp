#include<bits/stdc++.h>
#define Maxn 5001
#define Maxm 50001
using namespace std;

inline int read(){
  int x=0,w=0;char ch=0;
  while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
  while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
  return w?-x:x;
}

int Min(int a,int b){return a<b?a:b;}

int n,m,s,t,ans1,ans2;
struct node{
  int dis,to,flow,nxt;
}edge[Maxm<<1];
int head[Maxn],cnt=1;
int dis[Maxn],first[Maxn],last[Maxn],flow[Maxn];
bool vis[Maxn];

void add(int u,int v,int w,int d){
  ++cnt;
  edge[cnt].to=v;
  edge[cnt].flow=w;
  edge[cnt].dis=d;
  edge[cnt].nxt=head[u];
  head[u]=cnt;
  return ;
}

bool spfa(){
  for(int i=1;i<=n;++i){
    vis[i]=false;
    dis[i]=0x7fffffff;
    flow[i]=0x7fffffff;
  }
  queue<int > q;
  q.push(s);
  dis[s]=0;
  first[t]=0;
  while(!q.empty()){
    int u=q.front();
    q.pop();
    vis[u]=0;
    for(int i=head[u];i;i=edge[i].nxt){
      int v=edge[i].to;
      if(edge[i].flow>0&&dis[v]>dis[u]+edge[i].dis){
	dis[v]=dis[u]+edge[i].dis;
	first[v]=u;
	last[v]=i;
	flow[v]=Min(flow[u],edge[i].flow);
	if(!vis[v]){
	  q.push(v);
	  vis[v]=1;
	}
      }
    }
  }
  return first[t];
}

int main(){
  //  freopen("1.in","r",stdin);
  n=read(),m=read(),s=read(),t=read();
  for(int i=1;i<=m;++i){
    int u=read(),v=read(),w=read(),d=read();
    add(u,v,w,d);
    add(v,u,0,-d);
  }
  while(spfa()){
    ans1+=flow[t];
    ans2+=flow[t]*dis[t];
    int p=t;
    while(p!=s){
      edge[last[p]].flow-=flow[t];
      edge[last[p]^1].flow+=flow[t];
      p=first[p];
    }
  }
  printf("%d %d\n",ans1,ans2);
  return 0;
}
