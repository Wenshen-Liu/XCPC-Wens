#include<bits/stdc++.h>
using namespace std;

int n,m,a,b,c,cnt,v[100005],w[100005],dp[40005];

int read()
{
	int r=0,f=1;char c=getchar();
	while((c<'0'||c>'9')&&(c^'-'))c=getchar();
	if(c=='-')f=-1,c=getchar();
	while(c>='0'&&c<='9')r=(r<<1)+(r<<3)+(c^'0'),c=getchar();
	return r*f;
}

int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;++i)
	{
		a=read(),b=read(),c=read();
		int x=1;
		while(x<=c)
		{
			v[++cnt]=x*a;
			w[cnt]=x*b;
			c-=x,x<<=1;
		}
		if(c)v[++cnt]=c*a,w[cnt]=c*b;
	}
	for(int i=1;i<=cnt;++i)
		for(int j=m;j>=w[i];--j)dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
	printf("%d",dp[m]);
	return 0;
}
