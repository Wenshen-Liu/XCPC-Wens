#include<bits/stdc++.h>
#define N 100001
#define M 200001
#define Big  2147483647
#define ll long long
using namespace std;

ll read(){
	ll x=0,w=0;char ch=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return w?-x:x;
}

void write(ll x){
	if(x<0)x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
	return ;
}

priority_queue <pair<ll,ll> > q;

int n,m,start;
int nxt[M<<1],to[M<<1],head[N],cnt=0;
ll val[M<<1],dis[N];
bool vis[N];

void add(int u,int v,ll z){
	++cnt;
	to[cnt]=v;
	nxt[cnt]=head[u];
	head[u]=cnt;
	val[cnt]=z;
}

void Dijsktra(){
	for(int i=1;i<=n;++i)dis[i]=Big;
	dis[start]=0;
	q.push(make_pair(0,start));
	while(!q.empty()){
		int p=q.top().second;
		q.pop();
		if(vis[p])continue;
		vis[p]=1;
		for(int i=head[p];i;i=nxt[i]){
			int tt=to[i];
			if(dis[tt]>dis[p]+val[i]){
				dis[tt]=dis[p]+val[i];
				q.push(make_pair(-dis[tt],tt));
			}
		}
	}
	return ;
}

int main(){
	n=read(),m=read(),start=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),z=read();
		add(u,v,z);
	}
	Dijsktra();
	for(int i=1;i<=n;++i){
		write(dis[i]);
		printf(" ");
	}
	return 0;
}
