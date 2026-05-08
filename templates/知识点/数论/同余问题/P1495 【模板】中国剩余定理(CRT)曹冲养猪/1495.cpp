#include<bits/stdc++.h>
#define Maxn 11
using namespace std;

typedef long long ll;

inline ll read(){
  ll x=0,w=0;char ch=0;
  while(!isdigit(ch)){w|=ch=='0';ch=getchar();}
  while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
  return w?-x:x;
}

inline void write(ll x){
  if(x<0){x=-x;putchar('-');}
  if(x>9)write(x/10);
  putchar(x%10+48);
  return ;
}

void exgcd(ll a,ll b,ll &x,ll &y){
  if(b==0){
    x=1;
    y=0;
    return ;
  }
  exgcd(b,a%b,x,y);
  ll t=x;
  x=y;
  y=t-a/b*y;
  return ;
}

ll n,ans,a[Maxn],M=1,m[Maxn];

int main(){
  //freopen("1.in","r",stdin);
  n=read();
  for(int i=1;i<=n;++i){
    m[i]=read(),a[i]=read();
    M*=m[i];
  }
  for(int i=1;i<=n;++i){
    ll x,y;
    exgcd(M/m[i],m[i],x,y);
    if(x<0)x=x+m[i];
    ans=(ans+(a[i]*M/m[i]*x)%M)%M;
  }
  write(ans);
  putchar('\n');
  return 0;
}
  
