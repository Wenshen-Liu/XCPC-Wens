#include<bits/stdc++.h>
#define Maxn 10001
using namespace std;
typedef long long ll;

inline ll read(){
  ll x=0,w=0;char ch=0;
  while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
  while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
  return w?-x:x;
}

inline void write(ll x){
  if(x<0)x=-x;
  if(x>9)write(x/10);
  putchar(x%10+48);
  return ;
}

ll Pow(ll a,ll b,ll mod){
  ll ans=1;
  while(b){
    if(b%2)ans=ans*a%mod;
    a=a*a%mod;
    b>>=1;
  }
  return ans;
}

ll a,Mod,m,b,phim;

int main(){
  a=read();
  phim=1;
  Mod=m=read();
  a%=Mod;
  for(int i=2;i*i<=Mod;++i){//用性质2来求出m的eular值
    //cout<<m<<" "<<i<<" "<<m%i<<endl;
    if(m%i==0){
      //cout<<"!"<<endl;
      phim*=(i-1);
      while(m%i==0){
	m/=i;
	phim*=i;
      }
    }
  }
  if(m>1)phim*=(m-1);
  //cout<<phim<<" ";
  char s=0;
  bool flag=0;
  while(!isdigit(s))s=getchar();
  while(isdigit(s)){//边读边模，想起20年暑假又一次考试差点做出来一道题。
    b=b*10+s-48;
    s=getchar();
    if(b>phim){
      flag=true;
      b%=phim;
    }
  }
  if(flag)write(Pow(a,b+phim,Mod));//如果eular(b)>b再进行降次
  else write(Pow(a,b,Mod));//否则直接快速幂
  putchar('\n');
  return 0;
}
