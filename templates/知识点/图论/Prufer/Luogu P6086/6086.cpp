#include<bits/stdc++.h>
#define Maxn 5000001
using namespace std;
typedef long long ll;

inline ll read(){
  ll x=0;bool w=0;char ch=0;
  while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
  while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
  return w?-x:x;
}

int n,m;
int f[Maxn],p[Maxn],d[Maxn];

void solve1(){
  for(int i=1;i<=n-1;++i){
    f[i]=read();
    ++d[f[i]];
  }
  for (int i=1,j=1;i<=n-2;i++,j++){
    while (d[j]){
      ++j;
    }
    p[i]=f[j];
    while (i <= n - 2 && !--d[p[i]] && p[i] < j){
      p[i+1]=f[p[i]];
      ++i;
    }
  }
  ll ans=0;
  for(int i=1;i<=n-2;++i){
    ans^=1ll*i*p[i];
  }
  printf("%lld\n",ans);
  return ;
}

void solve2(){
  for(int i=1;i<=n-2;++i){
    p[i]=read();
    ++d[p[i]];
  }
  p[n-1]=n;
  for (int i=1,j=1;i<n;++i,++j) {
    while(d[j]){
      ++j;
    }
    f[j]=p[i];
    while(i<n&&!--d[p[i]]&&p[i]<j){
      f[p[i]]=p[i+1];
      ++i;
    }
  }
  ll ans=0;
  for(int i=1;i<=n-1;++i){
    ans^=1ll*f[i]*i;
  }
  printf("%lld\n",ans);
  return ;
}

int main(){
  //freopen("1.in","r",stdin);
  n=read(),m=read();
  if(m==1)solve1();
  if(m==2)solve2();
  return 0;
}
