
void dfs(int p,int father){
	if(deep[p]>deep[num])num=p;
	fa[p]=father;
	for(int i=head[p];i;i=next[i]){
		int tt=to[i];
		if(tt==father||mark[tt])continue;
		deep[tt]=deep[p]+1;
		dfs(tt,p);
	}
}

int main(){
	dfs(1,0);
	deep[num]=0;
	dfs(num,0);
	top=num;
}
