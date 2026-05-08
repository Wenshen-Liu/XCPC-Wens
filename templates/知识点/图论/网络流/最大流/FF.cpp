#include<bits/stdc++.h>
#define N 201
#define M 10005
typedef long long ll;
using namespace std;

inline ll read(){
  ll x=0,w=0;char ch=0;
  while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
  while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^'0');ch=getchar();}
  return w?-x:x;
}

ll Min(ll a,ll b){return a<b?a:b;}

ll n,m,s,t,ans=0;
ll cnt=1,nxt[M],head[N],val[M],to[M];
bool vis[N];

void add(int u,int v,int w){
  ++cnt;
  to[cnt]=v;
  val[cnt]=w;
  nxt[cnt]=head[u];
  head[u]=cnt;
  return ;
}

ll dfs(int u,int in){
  if(u==t){
    return in;
  }
  vis[u]=true;
  //--------------------------------致命难点
  for(int i=head[u];i;i=nxt[i]){
    int v=to[i];
    if(vis[v]||val[i]==0)continue;
    ll res=0;
    if((res=dfs(v,Min(in,val[i])))>0){
      val[i]-=res;
      val[i^1]+=res;
      return res;
    }
  }
  //--------------------------------致命难点/
  //我的理解是，在新的流来了之后，它会顺着反边走，然后在新流与旧流的交点处，新流与旧流就交换了一段路，把交点到汇点的路径与源点到交点的路径连上，再顺着反边回到旧流去增广增广路。
  return 0;
}

int main(){
  freopen("1.in","r",stdin);
  n=read(),m=read(),s=read(),t=read();
  for(int i=1;i<=m;++i){
    int u=read(),v=read(),w=read();
    add(u,v,w);
    add(v,u,0);
  }
  ll res;
  while((res=dfs(s,1e16))>0){
    ans+=res;
    memset(vis,false,sizeof(vis));
  }
  cout<<ans<<endl;
  return 0;
}
