//Problem：洛谷P1833樱花 混合背包模板题
//Web：https://www.luogu.com.cn/problem/P1833
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
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
int f[1050],n,V,ans;
void DP1(int w,int c)//01背包
{
	for(int i=V;i>=w;--i)
		f[i]=max(f[i],f[i-w]+c);
}
void DP2(int w,int c)//完全背包
{
	for(int i=w;i<=V;++i)
		f[i]=max(f[i],f[i-w]+c);
}
int main()
{
	int a=read(),b=read(),c=read(),d=read();
	V=(c*60+d)-(a*60+b);//背包体积
	n=read();//物品个数
	for(int i=1;i<=n;++i)
	{
		int w=read();//物品的体积
		int c=read();//物品的价值
		int p=read();
		if(p==0)DP2(w,c);//完全背包
		else
		{
			for(int j=0;p>=(1<<j);p-=1<<j,++j)//二进制分组
				DP1(w*(1<<j),c*(1<<j));//转01背包
			if(p)//没有拆完的完还会剩下一个余项
				DP1(w*p,c*p);
		}
	}
	printf("%d\n",f[V]);
	return 0;
	
}
