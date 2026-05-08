#include<bits/stdc++.h>
using namespace std;
int maxn=0,maxnn=0,a[1005],b[1005],f[1005],c[1005],n,cnt=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=1;
		b[i]=0; // 初始化b数组，用于记录路径
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(a[i]>=a[j]){
				if(f[i]<f[j]+1){
					b[i]=j;
					f[i]=f[j]+1;
				}
			}
		}
		if(f[i]>maxn){
			maxn=f[i];
			maxnn=i;
		}
	}
	cout<<maxn<<endl;
	for(int i=maxnn;i;i=b[i])c[++cnt]=a[i];
	for(int i=cnt;i>=1;i--)cout<<c[i]<<" ";
	return 0;
}
/*
14
13 7 9 16 38 24 37 18 44 19 21 22 63 15

8
*/ 
