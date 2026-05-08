//Problem：洛谷P1896互不侵犯
//Web：https://www.luogu.com.cn/problem/P1896
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std;
inline int read()
{
	int x=0;bool t=false;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')t=true,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return t?-x:x;
}
int n,K,pc[1<<9];//pc[i]记录i的二进制有几个1
ll ans,f[10][1<<9][90];
int main()
{
	n=read();K=read();
	f[0][0][0]=1;
	for(int i=1;i<(1<<n);++i)pc[i]=pc[i>>1]+(i&1);
	for(int i=1;i<=n;++i)
		for(int S1=0;S1<(1<<n);++S1)//枚举上一行状态
			for(int j=0;j<=K;++j)
			{
				if(!f[i-1][S1][j])continue;//如果方案数是0就没有转移的必要了
				for(int S2=0;S2<(1<<n);++S2)//枚举这一行状态
				{
					if((S2&S1)||(S2&(S1<<1))||(S2&(S1>>1))||(S2&(S2<<1))||(S2&(S2>>1)))continue;//不合法的情况
					if(j+pc[S2]>K)continue;
					f[i][S2][j+pc[S2]]+=f[i-1][S1][j];
				}
			}
	for(int i=0;i<(1<<n);++i)ans+=f[n][i][K];
	printf("%lld\n",ans);
	return 0;
}
//实际上这题可以有优化
//看到S1与S2不能有交，所以枚举S2的时候只需要枚举S1的补集的子集就行了
//这样子可以把复杂度中的n* 4^n *k优化到n* 3^n *k
//代码如下：
/*
  	for(int i=1;i<=n;++i)
		for(int S1=0;S1<(1<<n);++S1)
			for(int j=0;j<=K;++j)
			{
				if(!f[i-1][S1][j])continue;
				int T=((1<<n)-1)^S1;
				for(int S2=T;;S2=(S2-1)&T)
				{
					if((S2&(S1<<1))||(S2&(S1>>1))||(S2&(S2<<1))||(S2&(S2>>1)))continue;//不合法的情况
					if(j+pc[S2]>K)continue;
					f[i][S2][j+pc[S2]]+=f[i-1][S1][j];
					if(S2==0)break;
				}
			}
 */
