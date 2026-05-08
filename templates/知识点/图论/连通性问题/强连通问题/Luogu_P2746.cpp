#include<bits/stdc++.h>
using namespace std;
const int N=1e4+100,M=5e6+100;
int n,m,ans;
int cnt,next[M],to[M],head[N],from[M];
int dfn[N],low[N],col=0,co[N],sta[N],top,dfstime;
int in[N],out[N];
int no_in,no_out;
void add(int x,int y){
	next[++cnt]=head[x];
	to[cnt]=y;
	head[x]=cnt;
	from[cnt]=x;
}

void Tarjan(int p){
	low[p]=dfn[p]=++dfstime;
	sta[++top]=p;
	for(int i=head[p];i;i=next[i]){
		int tt=to[i];
		if(!dfn[tt]){
			Tarjan(tt);
			low[p]=min(low[p],low[tt]);
		}
		else if(!co[tt]){
			low[p]=min(low[p],dfn[tt]);
		}
	}
	if(low[p]==dfn[p]){
		co[p]=++col;
		int flag=0;
		while(sta[top]!=p){
			co[sta[top]]=col;
			--top;
		}
		--top;
	}
}

int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		int x;
		while(1){
			cin>>x;
			if(!x)break;
			add(i,x); 
		}
	}
	for(int i=1;i<=n;++i)if(!dfn[i])Tarjan(i);
	for(int i=1;i<=cnt;++i){
		int x=co[from[i]],y=co[to[i]];
		if(x==y)continue;
		++in[y];
		++out[x];
	}
	for(int i=1;i<=col;++i){
		if(!in[i])++no_in;
		if(!out[i])++no_out; 
	}
	cout<<no_in<<endl;
	if(col>1)cout<<abs(no_in-no_out)+min(no_in,no_out)<<endl;
	else cout<<0<<endl;
	return 0;
}
