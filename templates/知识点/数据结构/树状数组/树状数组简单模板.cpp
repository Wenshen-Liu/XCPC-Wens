#include<bits/stdc++.h>
using namespace std;
int c[1000500];
int n;
int lowbit(int x){
	return x&(-x);
}
void updata(int x,int v){
	while(x<=n){
		c[x]+=v;
		x+=lowbit(x);
	}
	return ;
}
int sum(int x){
	int res=0;
	while(x){
		res+=c[x];
		x-=lowbit(x);
	}
	return res;
}
int main(){
	int x;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		update(i,x);
	}
	cout<<sum(n);
	return 0;
}
