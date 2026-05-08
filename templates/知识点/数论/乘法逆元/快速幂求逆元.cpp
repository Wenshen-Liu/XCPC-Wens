#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll a,p;

ll Pow(ll a,ll b,ll mod){
	a%=mod;
	ll ans=1;
	while(b){
		if(b%2)ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}

int main(){
	cin>>a>>p;
	cout<<Pow(a,p-2,p);
	return 0;
}
