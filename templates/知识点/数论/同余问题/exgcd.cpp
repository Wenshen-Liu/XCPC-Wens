#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

inline ll read(){
  ll x=0,w=0;char ch=0;
  while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
  while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
  return w?-x:x;
}

ll exgcd(ll a,ll b,ll &x,ll &y){
  if(b==0){
    x=1;
    y=0;
    return a;
  }
  ll d=exgcd(b,a%b,x,y);
  ll t=x;
  x=y;
  y=t-a/b*y;
  return d;
}

ll a,b,x,y;

int main(){
  a=read();
  b=read();
  ll c=exgcd(a,b,x,y);y
  cout<<(x%abs(b)+abs(b))%abs(b)<<endl;
  return 0;
}

