/*
这个题目其实是不用斜率优化的，但是如果数据范围再大一些就需要了
先说说这道题吧，它需要我们算出在最优分组方案下的加工总花费，又因为它是按照顺序来的，因此易得式子：
f[i][j]=min{f[k][j]+(sumT[i]+s)*(sumC[i]-sumC[k])} 
然而这个方程需要有三维的循环来求，因此再改。

费用提前计算优化
根据以往的做题经验，我们尝试把二维化成一维，即让dp[i]dp[i]表示前ii个任务分批执行的最小费用。
但是这样我们就不知道机器启动过几次了！
别慌，冷静分析一下你会发现，如果我们要从dp[j]dp[j]转移到dp[i]dp[i]的话，
由于第j+1\sim ij+1～i都是在同一批内完成的，我们只需要把ss对j+1j+1后的影响补充到费用中就可以了！
时间复杂度O(n^2)
这就是费用提前计算的思想。 

出门左转进 该题+ 
*/ 
#include<bits/stdc++.h>
using namespace std;
const int N=5000;
int n,s,sumt[N+1],sumc[N+1],f[N+1],ans;
int main(){
	cin>>n>>s;
	for(int i=1;i<=n;++i){
		int t,c;
		cin>>t>>c;
		sumt[i]=sumt[i-1]+t;
		sumc[i]=sumc[i-1]+c;//记下前缀和 
	}
	memset(f,127,sizeof(f));
	f[0]=0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=i-1;++j){
			f[i]=min(f[i],f[j]+sumt[i]*(sumc[i]-sumc[j])+s*(sumc[n]-sumc[j]));//dp式子拿准就行了
		}
	}
	cout<<f[n]<<endl;
	return 0;
}
