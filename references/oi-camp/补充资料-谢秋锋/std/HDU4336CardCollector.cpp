//Problem：HDU4336 Card Collector
//Web：https://vjudge.net/problem/HDU-4336
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long
int n;
double f[1<<20],p[22];
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;++i)scanf("%lf",&p[i]);
		int T=(1<<n)-1;//全集
		f[T]=0;//初值
		for(int i=T-1;~i;--i)
		{
			f[i]=0;
			double P=0;
			for(int j=0;j<n;++j)
				if((i&(1<<j))==0)//如果集合中没有j这个元素
					f[i]+=(f[i|(1<<j)])*p[j],P+=p[j];
			f[i]=(f[i]+1)/(P);
		}
		printf("%.4lf\n",f[0]);
	}
	return 0;
}
