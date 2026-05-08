//Problem：LOJ#10147 石子合并
//Web：https://loj.ac/p/10147
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
#define MAX 450
inline int read()
{
	int x=0;bool t=false;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')t=true,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return t?-x:x;
}
int n,ans,f[MAX][MAX],a[MAX],s[MAX];
int S(int l,int r){return s[r]-s[l-1];}//区间和
int main()
{
	n=read();
	for(int i=1;i<=n;++i)a[i]=a[i+n]=read();//复制一份在后面
	for(int i=1;i<=n+n;++i)s[i]=s[i-1]+a[i];//前缀和
	//先求最小代价
	memset(f,63,sizeof(f));//一开始显然所有值都是正无穷
	for(int i=1;i<=n+n;++i)f[i][i]=0;//初值
	for(int l=2;l<=n;++l)//枚举区间长度
		for(int i=1;i+l-1<=n+n;++i)//枚举左端点
		{
			int j=i+l-1;//右端点
			for(int k=i;k<j;++k)//枚举断点
				f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+S(i,j));
		}
	ans=2e9;
	for(int i=1;i<=n;++i)ans=min(ans,f[i][i+n-1]);
	printf("%d\n",ans);
	//最大代价是一样的
	memset(f,-63,sizeof(f));//一开始初值都赋值为负无穷
	for(int i=1;i<=n+n;++i)f[i][i]=0;//初值
	for(int l=2;l<=n;++l)//枚举区间长度
		for(int i=1;i+l-1<=n+n;++i)//枚举左端点
		{
			int j=i+l-1;//右端点
			for(int k=i;k<j;++k)//枚举断点
				f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]+S(i,j));
		}
	ans=0;
	for(int i=1;i<=n;++i)ans=max(ans,f[i][i+n-1]);
	printf("%d\n",ans);
	return 0;
}
