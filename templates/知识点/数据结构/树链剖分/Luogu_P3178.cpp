#include<bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;

//以下是快读快写 
inline ll read(){
    ll X=0,w=0; char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    return w?-X:X;
}

inline void write(ll x){
     if(x<0) putchar('-'),x=-x;
     if(x>9) write(x/10);
     putchar(x%10+'0');
}
// 以上是快读快写 

int n,m,root;
ll lazy[N<<2],tree[N<<2],a[N],va[N];
int nxt[N<<1],head[N],to[N<<1],cnt=1;
int father[N],dep[N],siz[N],son[N],top[N],seg[N];

inline void add(int x,int y){
	nxt[++cnt]=head[x];
	to[cnt]=y;
	head[x]=cnt;
	return ;
}

//以下是线段树
inline void pushdown(int p,int l,int r){
	int mid=l+r>>1;
	tree[p<<1]=tree[p<<1]+1ll*lazy[p]*(mid-l+1);
	tree[p<<1|1]=tree[p<<1|1]+1ll*lazy[p]*(r-mid);
	lazy[p<<1]=lazy[p<<1]+lazy[p];
	lazy[p<<1|1]=lazy[p<<1|1]+lazy[p];
	lazy[p]=0;
	return ;
}

inline void build(int p,int l,int r){
	if(l==r){
		tree[p]=a[l];
		return ;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	tree[p]=tree[p<<1]+tree[p<<1|1];
	return ;
}

inline void update(int p,int l,int r,int L,int R,ll val){
	if(r<L||l>R)return ;
	if(l>=L&&r<=R){
		tree[p]=tree[p]+1ll*val*(r-l+1);
		lazy[p]=lazy[p]+val;
		return ;
	}
	pushdown(p,l,r);
	int mid=l+r>>1;
	update(p<<1,l,mid,L,R,val);
	update(p<<1|1,mid+1,r,L,R,val);
	tree[p]=tree[p<<1]+tree[p<<1|1];
	return ;
}

inline ll query(int p,int l,int r,int L,int R){
	if(r<L||l>R) return 0;
	if(l>=L&&r<=R){
		return tree[p];
	}
	pushdown(p,l,r);
	int mid=l+r>>1;
	return query(p<<1,l,mid,L,R)+query(p<<1|1,mid+1,r,L,R);
}
//以上是线段树 

//以下是剖分预处理
inline void dfs1(int p,int fa){
	siz[p]=1;
	father[p]=fa;
	dep[p]=dep[fa]+1;
	for(int i=head[p];i;i=nxt[i]){
		int tt=to[i];
		if(tt==fa)continue;
		dfs1(tt,p);
		siz[p]+=siz[tt];
		if(siz[tt]>siz[son[p]])son[p]=tt;
	}
}


inline void dfs2(int p,int topf){
    seg[p]=++seg[0];
    a[seg[0]]=va[p];
    top[p]=topf;
    if(!son[p])return;
    dfs2(son[p],topf); 
    for(int i=head[p];i;i=nxt[i]){
        int tt=to[i];
        if(tt==father[p]||tt==son[p])continue;
        dfs2(tt,tt);
    }
}
inline void update_way(int x,int y,ll val){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        update(1,1,n,seg[top[x]],seg[x],val);
        x=father[top[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    update(1,1,n,seg[x],seg[y],val);
    return ;
}

inline ll query_way(int x,int y){
    ll res=0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        res+=query(1,1,n,seg[top[x]],seg[x]);
        x=father[top[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    res+=query(1,1,n,seg[x],seg[y]);
    return res;
}

inline void update_point(int x,int k){
    update(1,1,n,seg[x],seg[x]+siz[x]-1,k);
    return ;
}

inline ll query_point(int x){
    return query(1,1,n,seg[x],seg[x]+siz[x]-1);
}
//以上树链剖分 

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	n=read(),m=read(),root=1;
	for(int i=1;i<=n;++i)va[i]=read();
	for(int i=1;i<=n-1;++i){
		int x=read(),y=read();
		add(x,y);
		add(y,x);
	}
	dfs1(root,0);
	dfs2(root,root);
	build(1,1,n);
	for(int i=1;i<=m;++i){
		int type=read();
		if(type==1){
			int x=read();ll val=read();
			update_way(x,x,val);
		}
		if(type==2){
			int x=read();ll val=read();
			update_point(x,val);
		}
		if(type==3){
			int x=read();
			write(query_way(root,x));
			printf("\n");
		}
	}
	return 0;
}
