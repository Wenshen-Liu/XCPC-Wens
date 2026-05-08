#include<bits/stdc++.h>
#define ll long long
#define N 20010
#define M 100010
using namespace std;

ll read(){
	ll x=0,w=0;char ch=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return w?-x:x;
}

ll fa[N<<1];
ll n,m;
struct node{
	ll x,y,val;
}way[M];

bool cmp1(node a,node b){return a.val>b.val;}

ll find(ll x){
	if(fa[x]==fa[fa[x]])return fa[x];
	return fa[x]=find(fa[x]);
}

int main(){
	n=read(),m=read();
	for(ll i=1;i<=n*2;++i)fa[i]=i;
	for(ll i=1;i<=m;++i){
		way[i].x=read(),way[i].y=read(),way[i].val=read();
	}
	sort(way+1,way+1+m,cmp1);
	for(ll i=1;i<=m;++i){
		ll fx=find(way[i].x),fy=find(way[i].y);
		if(fx==fy){
			printf("%lld\n",way[i].val);
			return 0;
		}
		ll fxn=find(way[i].x+n),fyn=find(way[i].y+n);
		fa[fx]=fa[fyn];
		fa[fy]=fa[fxn];
	}
	printf("0\n");
	return 0;
}
