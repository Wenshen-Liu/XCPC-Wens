#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int t,m,tim[105],value[105],dp[1005];

int main()
{
    scanf("%d%d",&t,&m);
    for(int i=1;i<=m;++i)scanf("%d%d",&tim[i],&value[i]);
    for(int i=1;i<=m;++i)
    for(int j=t;j>=tim[i];--j)
		dp[j]=max(dp[j],dp[j-tim[i]]+value[i]);
    printf("%d",dp[t]);
    return 0;
}
