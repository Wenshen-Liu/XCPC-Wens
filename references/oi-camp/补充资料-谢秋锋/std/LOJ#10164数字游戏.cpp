#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int f[15][10][2];//f[i][j][0/1]表示当前考虑到了第i位，第i位的数字是多少，是否严格卡在上界上
int Calc(int n)//计算[0,n]中符合条件的数的个数
{
	int a[15],l=0;
	while(n)a[++l]=n%10,n/=10;
	memset(f,0,sizeof(f));
	f[l+1][0][1]=1;
	for(int i=l;i;--i)
		for(int j=0;j<=9;++j)
		{
			//已经没有限制(即已经确定比上界小了)的转移
			for(int k=j;k<=9;++k)//既然没有限制了，那么这一位只需要比上一位大就行了
				f[i][k][0]+=f[i+1][j][0];
			//仍然有限制的转移
			for(int k=j;k<a[i];++k)//这一位选择一个比上界的这一位小的数，这样以后就没有限制了
				f[i][k][0]+=f[i+1][j][1];
			if(a[i]>=j)//仍然卡在上界上填数，那么接下来还是会受到上界的限制
				f[i][a[i]][1]+=f[i+1][j][1];
		}
	int ans=0;
	for(int j=0;j<=9;++j)ans+=f[1][j][0]+f[1][j][1];
	return ans;
}
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
		printf("%d\n",Calc(b)-Calc(a-1));
	return 0;
}
