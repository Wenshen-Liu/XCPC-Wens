#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,c[2000][2000],mod=1e9+7;
int main(){
  c[0][0]=1;
  for(ll i=1;i<=1000;i++){
    c[i][0]=1;
    for(ll j=1;j<=i;j++){
      c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
    }
  }
  cin>>n>>m;
  cout<<c[n+m][m]<<endl;
  return 0;
}
/*
一，问题：
	在棋盘上，从(0,0)走到（n,m），有多少种方案.。
二，输入输出：
	输入：共一行，n,m,两个数。（n，m都小于1000）
	输出：共一行，ans表示方案数。
三，样例输入输出：
	样例输入：
		5 3
	样例输出：
		56
*/ 
