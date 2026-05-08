#include<bits/stdc++.h>
using namespace std;
const int Maxn=151;

typedef long long ll;

inline int read(){
  int x=0;bool w=0;char ch=0;
  while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
  while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
  return w?-x:x;
}

int n,tot,sum;
int d[Maxn],fac[Maxn][Maxn],ans_fac[Maxn],prime[Maxn];
ll ans=1;
bool vis[Maxn],flag;

void pre(){
  for(int i=2;i<=Maxn-1;++i){
    if(!vis[i]){
      prime[++tot]=i;
    }
    for(int j=1;j<=tot&&i*prime[j]<=Maxn-1;++j){
      vis[prime[j]*i]=true;
      if(i%prime[j]==0)break;
    }
  }
  return ;
}


int main(){
  //freopen("1.in","r",stdin);
  pre();
  n=read();
  for(int i=1;i<=n;++i){
    d[i]=read()-1;
    sum+=d[i];
    if(d[i]<0)flag=true;
  }
  if((sum!=n-2||flag)&&!(n==1&&d[1]==-1)){
    printf("0\n");
    return 0;
  }
  for(int i=1;i<=n-2;++i){
    for(int j=1;j<=tot;++j)fac[i][j]=fac[i-1][j];
    int t=i;
    for(int j=1;j<=tot&&t>1;++j){
      while(t%prime[j]==0){
	++fac[i][j];
	t/=prime[j];
      }
    }
  }
  for(int i=1;i<=tot;++i){
    ans_fac[i]=fac[n-2][i];
    for(int j=1;j<=n;++j){
      if(d[j]){
	ans_fac[i]-=fac[d[j]][i];
      }
    }
  }
  for(int i=1;i<=tot;++i){
    for(int j=1;j<=ans_fac[i];++j){
      ans*=prime[i];
    }
  }
  printf("%lld\n",ans);
  return 0;
}
