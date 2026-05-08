#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,A[1000][1000],p=1e9+7,Ans[1000][1000]={1},b,flag[1000][1000];
int main(){
  cin>>n>>b;
  for(ll i=1;i<=n;i++){
    Ans[i][i]=1;
    for(ll j=1;j<=n;j++){
      cin>>A[i][j];
    }
  }
  while(b){
    if(b%2){
      for(ll i=1;i<=n;i++)for(ll j=1;j<=n;j++)for(ll k=1;k<=n;k++)flag[i][j]+=A[i][k]*Ans[k][j],flag[i][j]%=p;
      for(ll i=1;i<=n;i++)for(ll j=1;j<=n;j++)Ans[i][j]=flag[i][j],flag[i][j]=0;
    }
    for(ll i=1;i<=n;i++)for(ll j=1;j<=n;j++)for(ll k=1;k<=n;k++)flag[i][j]+=A[i][k]*A[k][j],flag[i][j]%=p;
    for(ll i=1;i<=n;i++)for(ll j=1;j<=n;j++)A[i][j]=flag[i][j],flag[i][j]=0;
    
    b>>=1;
  }
  for(ll i=1;i<=n;i++){
    for(ll j=1;j<=n;j++){
      cout<<Ans[i][j]%p<<" ";
    }
    cout<<endl;
  }
  return 0;
}

