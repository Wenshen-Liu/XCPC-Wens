#include<bits/stdc++.h>
using namespace std;

const int Maxn=1e4+100;

inline int Read(){
	int x=0;char ch=0;bool w=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return w?-x:x;
}

int n,m;
int fa[Maxn];

int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}

int main(){
	n=Read(),m=Read();
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i){
		int opt=Read(),u=Read(),v=Read();
		int fu=find(u),fv=find(v);
		if(opt==1){
			fa[fu]=fv;
		}
		if(opt==2){
			if(fu==fv){
				puts("Y");
			}
			else puts("N");
		}
	}
	return 0;
}
