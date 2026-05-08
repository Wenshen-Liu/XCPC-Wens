#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
#define MAX 1500
inline int read()
{
	int x=0;bool t=false;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')t=true,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return t?-x:x;
}
int a[MAX],f[MAX],n;
int b[MAX],t;//t用来记录b数组的最后一个元素的下标，也就是的答案
int main()
{
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i)
		if(!t||a[i]>b[t])
		{
			f[i]=t+1;
			b[++t]=a[i];
		}
		else
		{
			int l=1,r=t,ans=0;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if(b[mid]<a[i])l=mid+1,ans=mid;
				else r=mid-1;
			}
			b[f[i]=ans+1]=a[i];	
		}
	printf("%d\n",t);
	return 0;
}
