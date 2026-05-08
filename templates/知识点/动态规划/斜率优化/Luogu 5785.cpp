/*
怎么说吧，这玩意我并没有学懂，我也觉得题高组不会考，然而袁老师让学，只能勉强地上了。
首先我们要用上弱化版中的式子： F[i]=Min{F[j]+sumT[i]*(sumC[i]-sumC[j])+s*(sumC[n]-sumC[j])}
	很长，很难看，但我们必须要用
斜率优化是一个技巧，就是把整个式子变成一个一次函数（不然为啥叫斜率优化），比如该式变为 ：
y=F[j] x=sumC[j] k=sumT[i]+s b=F[i]-sumT[i]*sumC[i]-s*sumC[n]
y=k*x+b
然后呢，可以发现，f[i]存在与b中
待补。。。 
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=3e5;
ll t[N+1],c[N+1],f[N+1],q[N+1],n,s;
ll search(ll l,ll r,ll k){
	while(l<r){
		int mid=(l+r)>>1;
		if(f[q[mid+1]]-f[q[mid]]<=k*(c[q[mid+1]]-c[q[mid]]))l=mid+1;
		else r=mid;
	}
	return q[l];
}
int main(){
	cin>>n>>s;
	for(int i=1;i<=n;++i){
		cin>>t[i]>>c[i];
		t[i]+=t[i-1];
		c[i]+=c[i-1];
	}
	int l=1,r=1;
	q[l]=0;
	for(ll i=1;i<=n;++i){
		int j=search(l,r,s+t[i]);
		f[i]=f[j]-(s+t[i])*c[j]+t[i]*c[i]+s*c[n];
		while(l<r&&(f[q[r]]-f[q[r-1]])*(c[i]-c[q[r]])>=(f[i]-f[q[r]])*(c[q[r]]-c[q[r-1]]))--r;
		q[++r]=i;
	}
	cout<<f[n]<<endl;
	return 0;
}
/*
F[i][j]=Min{F[k][j-1]+(sumT[i]+s*j)*(sumC[i]-sumC[k])}
F[i]=Min{F[j]+sumT[i]*(sumC[i]-sumC[j])+s*(sumC[n]-sumC[j])}
F[i]=Min{F[j]+sumT[i]*sumC[i]-sumT[i]*sumC[j]+s*sumC[n]-s*sumC[j]}
F[i]=Min{F[j]-sumT[i]*sumC[j]+s*sumC[j]}+sumT[i]*sumC[i]+s*sumC[n]
F[j]=F[i]+(sumT[i]+s)*sumC[j]-sumT[i]*sumC[i]-s*sumC[n]
y=F[j] x=sumC[j] k=sumT[i]+s b=F[i]-sumT[i]*sumC[i]-s*sumC[n]
y=k*x+b
*/
