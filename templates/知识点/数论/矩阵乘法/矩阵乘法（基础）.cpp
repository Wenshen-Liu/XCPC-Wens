#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll A[1000][1000],B[1000][1000],C[1000][1000],n,r,m;
int main(){
  cin>>n>>r;
  for(ll i=1;i<=n;i++)for(ll j=1;j<=r;j++)cin>>A[i][j];
  cin>>m;
  for(ll i=1;i<=r;i++)for(ll j=1;j<=m;j++)cin>>B[i][j];
  for(ll i=1;i<=n;i++)for(ll j=1;j<=m;j++)for(ll k=1;k<=r;k++)C[i][j]+=A[i][k]*B[k][j];
  for(ll i=1;i<=n;i++){
    for(ll j=1;j<=m;j++)cout<<C[i][j]<<" ";
    cout<<endl;
  }
  return 0;
}
