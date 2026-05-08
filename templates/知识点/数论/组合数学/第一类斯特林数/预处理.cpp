#include<bits/stdc++.h>
#define ll long long
using namespace std;
const long long mod=1e9+7;
long long s[50001][205],S[50001][205],fac[500001],inv[500001];
ll Pow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b%2)ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}
int main(){
    //第一类斯特林数 
	s[0][0]=1;
    for(ll i=1;i<=50000;++i){
        for(ll j=1;j<=200;++j){
            s[i][j]=(s[i-1][j-1]+s[i-1][j]*(i-1)%mod)%mod;
        }
    }
    for(ll i=1;i<=10;i++){
    	for(ll j=1;j<=i;j++){
    		cout<<s[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
    
	//第二类斯特林数 
	S[1][1] = 1;
    for(ll i=2;i<=50000;++i){
        for(ll j=1;j<=200;++j){
            S[i][j]=S[i-1][j-1]+j*S[i-1][j];	
            if(S[i][j]>mod)S[i][j] %= mod;
        }
    }
    for(ll i=1;i<=10;i++){
    	for(ll j=1;j<=i;j++){
    		cout<<S[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
    //组合数 
    fac[0]=1;
	inv[0]=inv[1]=1;
    for(ll i=1;i<50000;i++){
        fac[i]=fac[i-1]*i%mod;
        inv[i]=Pow(fac[i],mod-2);
    }
    for(ll i=0;i<=10;i++){
    	for(ll j=0;j<=i;j++){
    		cout<<fac[i]*inv[j]%mod*inv[i-j]%mod<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
    return 0;
}
