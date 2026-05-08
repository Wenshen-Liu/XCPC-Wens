#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define ll long long 
inline int read()
{
	int x=0;bool t=false;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')t=true,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return t?-x:x;
}
ll f[20][3][2];
ll calc(ll n)
{
	int a[15],l=0;ll N=n;
	while(N)a[++l]=N%10,N/=10;
	memset(f,0,sizeof(f));
	f[l+1][0][1]=1;
	for(int i=l;i;--i)//当前第i位
		for(int j=0;j<=2;++j)//从当前i-1位开始往前，连续6的个数
		{
			for(int k=0;k<=9;++k)
				if(k==6&&j==2)continue;
				else f[i][(k==6)?(j+1):0][0]+=f[i+1][j][0];
			for(int k=0;k<=a[i];++k)
				if(k==6&&j==2)continue;
				else f[i][(k==6)?(j+1):0][k==a[i]]+=f[i+1][j][1];				
		}
	n+=1;
	for(int j=0;j<=2;++j)n-=f[1][j][0]+f[1][j][1];
	return n;
}
int main()
{
	int T=read();
	while(T--)
	{
		ll x=read();
		ll l=1,r=1e10,ans=r;
		while(l<=r)
		{
			ll mid=(l+r)>>1;
			if(calc(mid)<x)l=mid+1;
			else r=mid-1,ans=mid;//当魔鬼数=x,还是会继续往左区间找，直到区间只剩一个元素，这个元素到0的魔鬼数=x,这个数也恰好是第x个魔鬼数 
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
