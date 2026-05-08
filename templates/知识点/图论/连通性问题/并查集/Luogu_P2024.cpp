#include<bits/stdc++.h>
#define N 50010
#define ll long long
using namespace std;

ll read(){
	ll x=0,w=0;char ch=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return w?-x:x;
}

ll fa[N<<2],n,m,ans;

ll find(ll x){
	if(fa[x]==fa[fa[x]])return fa[x];
	return fa[x]=find(fa[x]);
}

int main(){
	n=read(),m=read();
	for(ll i=1;i<=n*3;++i)fa[i]=i;
	while(m--){
		ll opt=read(),x=read(),y=read();
		if(x>n||y>n){
			++ans;
			continue;
		}
		ll fx=find(x),fy=find(y),fxn=find(x+n),fyn=find(y+n),fxnn=find(x+n+n),fynn=find(y+n+n);
		if(opt==1){
			if(fxn==fy||fx==fyn){
				++ans;
				continue;
			}
			fa[fx]=fy;
			fa[fxn]=fyn;
			fa[fxnn]=fynn;
		}
		if(opt==2){
			if(fx==fy||fx==fyn){
				++ans;
				continue;
			}
			fa[fxn]=fy;
			fa[fxnn]=fyn;
			fa[fx]=fynn;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
