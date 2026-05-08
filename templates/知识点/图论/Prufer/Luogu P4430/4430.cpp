#include<bits/stdc++.h>
const int Mod=9999991;
using namespace std;

typedef long long ll;

inline int read(){
  int x=0;bool w=0;char ch=0;
  while(!isdigit(ch)){w|=ch=='0';ch=getchar();}
  while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
  return w?-x:x;
}

ll Pow(ll a,int b){
  ll ans=1;
  while(b){
    if(b%2)ans=ans*a%Mod;
    a=a*a%Mod;
    b>>=1;
  }
  return ans;
}

int n;
ll ans=1;

int main(){
  n=read();
  for(int i=1;i<=n-1;++i){
    ans=ans*i%Mod;
  }
  ans=ans*Pow(n,n-2)%Mod;
  printf("%lld\n",ans);
  return 0;
}
