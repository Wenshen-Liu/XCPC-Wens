int fa[N];

int find(int x){
	if(fa[x]==fa[fa[x]])return fa[x];
	return fa[x]=find(fa[fa[x]]);//这里的find中有一个fa[x]的赋值，就是路径压缩了 
}

void merge(int x,int y){
	fa[find(x)]=find(y);
}//传统的合并操作，我是真的不喜欢这个玩意。 

void union_set(int x,int y){//按秩迭代，说实话感觉没有路径压缩快，而且麻烦 
	int fx=find(x),y=find(y);
	if(rank[x]>rank[y])fa[y]=x;
	else {
		fa[x]=y;
		if(rank[x]==rank[y])++rank[y];
	}
}

int main(){
	for(int i=1;i<=n;++i)fa[i]=i;//不初始化建议拖出去枪毙。 
} 
