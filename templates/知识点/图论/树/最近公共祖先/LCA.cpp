int fa[N+1][21],lg[N+1],deep[N+1];
int cnt,next[N<<1],to[N<<1],head[N+1];

void dfs(int p){
	for(int i=0;(1<<i)<=deep[p];++i)fa[p][i+1]=fa[fa[p][i]][i];
	for(int i=head[p];i;i=next[i]){
		int tt=to[i];
		if(tt==fa[p][0])continue;
		deep[tt]=deep[p]+1;
		fa[tt][0]=p;
		dfs(tt);
	}
}

int LCA(int x,int y){
	if(deep[x]<deep[y])swap(x,y);
	for(int i=lg[deep[x]];i>=0;--i){
		if(deep[fa[x][i]]>=deep[y])x=fa[x][i];
		if(x==y)return x;
	}
	for(int i=lg[deep[x]];i>=0;--i){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}

for(int i=1;i<=n;++i)lg[i]=lg[i-1]+(i==(1<<lg[i-1]));
