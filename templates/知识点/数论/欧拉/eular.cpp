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

ll n;
ll prime[Maxn],tot,phi[Maxn];
bool vis[Maxn];

void eular(){
  phi[1]=1;
  for(int i=2;i<Maxn;++i){
    if(!vis[i]){
      ++tot;
      prime[tot]=i;
      phi[i]=i-1;//若i为一个质数,则eular(i)=i-1;
    }
    for(int j=1;j<=tot&&i*prime[j]<Maxn;++j){
      vis[prime[j]*i]=true;
      if(i%prime[j]==0){
	phi[i*prime[j]]=phi[i]*prime[j];//如果prime是i的一个因数,则用eular(p^k)=(p-1)*p^(k-1),(p为质数);
	break;
      }
      phi[i*prime[j]]=phi[i]*(prime[j]-1);//如果prime与i互质,则用eular函数的积性质:eular(nm)=eular(n)*eular(m),(gcd(n,m)==1);
    }
  }
  return ;
}

int main(){
  eular();
  n=read();
  for(int i=1;i<=n;++i){
    write(phi[i]);
    putchar('\n');
  }
  return 0;
}
