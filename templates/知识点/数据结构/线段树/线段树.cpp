ll lazy[N<<2],a[N],tree[N<<2];

inline void pushdown(int p,int l,int r){
	int mid=(l+r)>>1;
	tree[p<<1]+=lazy[p]*(mid-l+1);
	tree[p<<1|1]+=lazy[p]*(r-mid);
	lazy[p<<1]+=lazy[p];
	lazy[p<<1|1]+=lazy[p];
	lazy[p]=0;
	return ;
}

inline void build(int p,int l,int r){
	if(l==r){
		tree[p]=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	tree[p]=tree[p<<1]+tree[p<<1|1];
	return ;
}

inline void update(int p,int l,int r,int L,int R,ll val){
	if(r<L||l>R)return ;
	if(l>=L&&r<=R){
		tree[p]+=val*(r-l+1);
		lazy[p]+=val;
		return ;
	}
	pushdown(p,l,r);
	int mid=(l+r)>>1;
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
	ll res=0;
	int mid=(l+r)>>1;
	res+=query(p<<1,l,mid,L,R);
	res+=query(p<<1|1,mid+1,r,L,R);
	return res;
}


