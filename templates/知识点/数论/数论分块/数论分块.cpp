#include<bits/stdc++.h>
#define ll long long 
using namespace std;
inline int read(){
	int r=0,f=0;
	char c;
	while(!isdigit(c=getchar()))f|=(c=='-');
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?-r:r;
}
ll n;
int main(){
	n=read();
	for(ll l=1,r=0;l<=n;l=r+1){
		r=n/(n/l);
		cout<<l<<" "<<r<<endl;
	}
	return 0;
}
