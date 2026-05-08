#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b,mod;
ll Fpow(ll a,ll b){
	a%=b;
	ll ans=1;
	while(b){
		if(b%2)ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	cin>>a>>b>>mod;
	cout<<Fpow(a,b)<<endl;
	return 0;
}
