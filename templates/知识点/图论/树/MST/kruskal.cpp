#include<bits/stdc++.h>
using namespace std;
const int N=5e3+100,M=2e5+100;
int n,m,xn;
int fa[N],ans;

struct node{
	int x,y,val;
}a[M];

int find(int x){
	if(fa[x]==fa[fa[x]])return fa[x];
	return find(fa[x]=fa[fa[x]]);
}

bool cmp1(node aa,node bb){return aa.val<bb.val;}

int main(){
	cin>>n>>m;
	xn=n;
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i){
		cin>>a[i].x>>a[i].y>>a[i].val;
	}
	sort(a+1,a+1+m,cmp1);
	for(int i=1;i<=m;++i){
		int fx=find(a[i].x),fy=find(a[i].y);
		if(fx!=fy){
			fa[fx]=fy;
			--xn;
			ans+=a[i].val;
		}
		if(xn==1){
			cout<<ans<<endl;
			return 0;
		}
	}
	cout<<"orz"<<endl;
	return 0;
}
