#include<bits/stdc++.h>
using namespace std;
const int Maxn=20100;

int to[Maxn<<1],head[Maxn],nxt[Maxn<<1],fa[Maxn];
int tot;
int dep[Maxn],root=1;

void clear(){
    tot=0;
    root=1;
    memset(fa,0,sizeof(fa));
    memset(dep,0,sizeof(dep));
    memset(head,0,sizeof(head));
}

void add(int u,int v){
    to[++tot]=v;
    nxt[tot]=head[u];
    head[u]=tot;
    return ;
}

void dfs(int p,int father){
	if(dep[p]>dep[root])root=p;
	fa[p]=father;
	for(int i=head[p];i;i=nxt[i]){
		int tt=to[i];
		if(tt==father)continue;
		dep[tt]=dep[p]+1;
		dfs(tt,p);
	}
}

int find(int p,int cnt){
    if(cnt==dep[root]/2)return p;
    return find(fa[p],cnt+1);
}

void solve(){
    clear();
    int n;
    cin>>n;
    for(int i=1;i<=n-1;++i){
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    dfs(1,0);
    dep[root]=0;
    dfs(root,0);
    int cen=find(root,0);
    int op=dep[root]+1-dep[root]/2;
    // printf("%d %d\n",root,cen);
    // for(int i=1;i<=n;++i){
    //     printf("%d ",dep[i]);
    // }
    // puts("");

    printf("%d\n",op);
    for(int i=0;i<=op-1;++i){
        printf("%d %d\n",cen,i);
    }
    // puts("------------");
    return ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}