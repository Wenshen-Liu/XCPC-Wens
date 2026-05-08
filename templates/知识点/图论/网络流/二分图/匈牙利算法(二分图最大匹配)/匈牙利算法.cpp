#include<bits/stdc++.h>
#define N 105
#define M 10005
using namespace std;

inline int read(){
  int x=0,w=0;char ch=0;
  while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
  while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^'0');ch=getchar();}
  return w?-x:x;
}

int n_tot,n,ans=0;
int match[N];
int head[N],to[M],nxt[M],cnt;

void add(int x,int y){
  ++cnt;
  to[cnt]=y;
  nxt[cnt]=head[x];
  head[x]=cnt;
  return ;
}
bool vis[N];
bool dfs(int p){
  for(int i=head[p];i;i=nxt[i]){
    int tt=to[i];
    if(vis[tt])continue;
    vis[tt]=true;
    if(dfs(match[tt])||!match[tt]){
      match[tt]=p;
      match[p]=tt;
      return true;
    }
  }
  return false;
}

int main(){
  //  freopen("1.in","r",stdin);
  n_tot=read(),n=read();
  int u,v;
  while(scanf("%d%d",&u,&v)!=EOF){
    add(u,v);
    add(v,u);
  }
  for(int i=1;i<=n;++i){
    if(!match[i]){
      memset(vis,0,sizeof(vis));
      if(dfs(i))++ans;
    }
    /*
    cout<<endl;
    cout<<i<<":";
    for(int j=1;j<=n;++j){
      if(match[j]){
	cout<<"("<<j<<","<<match[j]<<")"<<" ";
      }
    }
    */
  }
  printf("%d\n",ans);
  return 0;
}
