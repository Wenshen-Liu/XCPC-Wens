#include<bits/stdc++.h>
const int Maxn=1001;
using namespace std;

typedef long long ll;

inline int read(){
  int x=0;bool w=0;char ch=0;
  while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
  while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
  return w?-x:x;
}

int ans[Maxn*100];
int n,cnt,sum;
int d[Maxn],prime[Maxn],fac[Maxn][Maxn],ans_fac[Maxn],tot;
bool vis[Maxn];

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
  for(int i=1;i<=Maxn-2;++i){
    for(int j=1;j<=tot;++j)fac[i][j]=fac[i-1][j];
    int t=i;
    for(int j=1;j<=tot&&t>1;++j){
      while(t%prime[j]==0){
	++fac[i][j];
	t/=prime[j];
      }
    }
  }
  return ;
}

void mul(int x){
  for(int i=1;i<=ans[0];++i)ans[i]*=x;
  for(int i=1;i<=ans[0];++i){
    if(ans[i]>9){
      ans[i+1]+=ans[i]/10;
      ans[i]%=10;
      if(i==ans[0])++ans[0];
    }
  }
  return ;
}

void division(int b){
  ll x=0;
  int c[Maxn*100],s=0,top=0;
  for(int i=1;i<=ans[0];++i){
    x=(x<<1)+(x<<3)+ans[i];
    if(x/b!=0)++s;
    if(s==0)continue;
    c[++top]=x/b;
    x%=n;
  }
  ans[0]=top;
  for(int i=1;i<=top;++i){
    ans[top+1-i]=c[i];
  }
  return ;
}

int main(){
  //freopen("1.in","r",stdin);
  pre();
  n=read();
  for(int i=1;i<=n;++i){
    int x=read();
    if(x==-1){
      continue;
    }
    else {
      if(x==0){
	if(n==1)printf("1\n");
	else printf("0\n");
	return 0;
      }
      d[++cnt]=x-1;
      sum+=x-1;
    }
  }
  if(sum>n-2){
    printf("0\n");
    return 0;
  }
  ans[0]=1;
  ans[1]=1;
  for(int i=1;i<=n-2-sum;++i){
    mul(n-cnt);
  }
  for(int i=1;i<=tot;++i){
    ans_fac[i]=fac[n-2][i]-fac[n-2-sum][i];
    for(int j=1;j<=cnt;++j){
      ans_fac[i]-=fac[d[j]][i];
    }
  }
  for(int i=1;i<=tot;++i){
    for(int j=1;j<=ans_fac[i];++j)mul(prime[i]);
    for(int j=-1;j>=ans_fac[i];--j)division(prime[i]);
  }
  for(int i=ans[0];i>=1;--i)printf("%d",ans[i]);
  printf("\n");
  return 0;
}
