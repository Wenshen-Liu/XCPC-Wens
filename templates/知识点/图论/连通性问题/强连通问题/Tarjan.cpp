
void Tarjan(int p){
	dfn[p]=low[p]=++num;
	st[++top]=p;
	for(int i=head[p];i;i=sim[i].next){
		int tt=sim[i].to;
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
		while(st[top]!=p){
			co[st[top]]=col;
			--top;
		}
		--top;
	}
}

int main(){
	for(int i=1;i<=n;++i)if(!dfn[i])Tarjan(i);
	memset(head,0,sizeof(head));
	for(int i=1;i<=m;++i){
		int x=co[sim[i].from],y=co[sim[i].to];
		if(x==y)continue;
		add_c(x,y);
	}
} 

/*
例题:
Luogu:
	P1262 间谍网络
	P2341 [USACO03FALL][HAOI2006]受欢迎的牛 G
	P2746 [USACO5.3]校园网Network of Schools(网络协议)
	P3387 【模板】缩点
*/ 
