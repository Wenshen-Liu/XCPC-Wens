#include<bits/stdc++.h>
#define INF 10000000
using namespace std;
int n,a[2000][2000],dp[2000][2000];
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>a[i][j];
		}
	}
	dp[1][1]=a[1][1];
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+a[i][j];
		}
	}
	int ans=-INF;
	for(int i=1;i<=n;i++)ans=max(dp[n][i],ans);
	cout<<ans<<endl;
	return 0;
}
/*
5
13
11 8
12 7 26
6 14 15 8
12 7 13 24 11
*/ 
