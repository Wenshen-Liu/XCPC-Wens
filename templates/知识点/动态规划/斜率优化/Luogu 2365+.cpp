/*
在原题中，我们已经得到了式子：F[i]=Min{F[j]+sumT[i]*(sumC[i]-sumC[j])+s*(sumC[n]-sumC[j])}
现在再把数据范围调到3e5,O(N^2)的时间复杂度完全不够了好吧，改；
斜率优化是一个技巧，就是把整个式子变成一个一次函数（不然为啥叫斜率优化）
	首先要把常数（不用知道j就可以得出来的数）提到外面去:F[i]=Min{F[j]-sumT[i]*sumC[j]+s*sumC[j]}+sumT[i]*sumC[i]+s*sumC[n] 
	然后就是要把min给去掉，再将式子转化为一元二次方程形式：
		y=F[j] x=sumC[j] k=sumT[i]+s b=F[i]-sumT[i]*sumC[i]-s*sumC[n]
		y=k*x+b
	由此：F[i]在b中，且除了F[i]以外的数都是可以固定下来的，于是乎，我们使b变小一些，F[i]就会变小一些
	
	接下来建议画个坐标系模拟一下：
		以sumC[j]为x轴，f[j]为y轴，有三个决策点P1(sumC[j1],f[j1]),P2(sumC[j2],f[j2]),P3(sumC[j3],f[j3])。 
		连接P1P2,P2P3。
		
*/
#include<bits/stdc++.h>
using namespace std;
const int N=5000;
int n,s,sumt[N+1],sumc[N+1],f[N+1],ans,q[N+1];
int main(){
	cin>>n>>s;
	for(int i=1;i<=n;++i){
		cin>>sumt[i]>>sumc[i];
		sumt[i]+=sumt[i-1];
		sumc[i]+=sumc[i-1];
	}
	memset(f,127,sizeof(f));
	f[0]=0;
	int l=1,r=1;
	q[l]=0;
	for(int i=1;i<=n;++i){
		while(l<r&&f[q[l+1]]-f[q[l]]<=(s+sumt[i])*(sumc[q[l+1]]-sumc[q[l]]))++l;
		f[i]=f[q[l]]-(s+sumt[i])*sumc[q[l]]+sumt[i]*sumc[i]+s*sumc[n];
		while(l<r&&(f[q[r]]-f[q[r-1]])*(sumc[i]-sumc[q[r]])>=(f[i]-f[q[r]])*(sumc[q[r]]-sumc[q[r-1]]))--r;
		q[++r]=i;
	}
	cout<<f[n]<<endl;
	return 0;
}
