#include<bits/stdc++.h>
#define N 50010
using namespace std;
typedef long long ll;

inline ll read(){
    ll X=0,w=0; char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    return w?-X:X;
}

int n,block;
int a[N],blo[N];

int Max(int a,int b){return a>b?a:b;}

struct kuai{
  ll head,tail,lazy;
}b[25000];

int main(){
  n=read();
  block=sqrt(n);
  blo[0]=-1;
  for(int i=1;i<=n;++i){
    a[i]=read();
    blo[i]=i/block;
    if(blo[i]!=blo[i-1]){
      b[blo[i-1]].tail=i-1;
      b[blo[i]].head=i;	
    }
  }
  b[blo[n]].tail=n;
  for(int i=1;i<=n;++i){
    int opt=read(),l=read(),r=read(),c=read();
    if(opt==0){
      for(int j=l;b[blo[l]].tail<r&&j<=b[blo[l]].tail;++j){
	a[j]+=c;
      }
      for(int j=blo[l]+1;j<blo[r];++j){
	b[j].lazy+=c;
      }
      for(int j=Max(l,b[blo[r]].head);j<=r;++j){
	a[j]+=c;
      }
    }
    if(opt==1){
      for(int j=b[blo[r]].head;j<=b[blo[r]].tail;++j){
	a[j]+=b[blo[r]].lazy;
      }
      b[blo[r]].lazy=0;
      cout<<a[r]<<endl;
    }
  }
  return 0;
}
