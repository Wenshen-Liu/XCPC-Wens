#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
int n,m;
ll mod;
ll a[N],tree[N<<2],lazy_add[N<<2],lazy_mul[N<<2];
void pushdown(int p,int l,int r){
    int mid=(l+r)>>1;
    tree[p<<1]=(tree[p<<1]*lazy_mul[p]+lazy_add[p]*(mid-l+1))%mod;
    tree[p<<1|1]=(tree[p<<1|1]*lazy_mul[p]+lazy_add[p]*(r-mid))%mod;
    lazy_add[p<<1]=(lazy_add[p<<1]*lazy_mul[p]+lazy_add[p])%mod;
    lazy_add[p<<1|1]=(lazy_add[p<<1|1]*lazy_mul[p]+lazy_add[p])%mod;
    lazy_mul[p<<1]=(lazy_mul[p<<1]*lazy_mul[p])%mod;
    lazy_mul[p<<1|1]=(lazy_mul[p<<1|1]*lazy_mul[p])%mod;
    lazy_add[p]=0;
    lazy_mul[p]=1;
    return ;
}

void build(int p,int l,int r){
    lazy_mul[p]=1;
    if(l==r){
        tree[p]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    tree[p]=(tree[p<<1]+tree[p<<1|1])%mod;
    return ;
}

void update_mul(int p,int l,int r,int L,int R,ll val){
    if(r<L||l>R)return ;
    if(l>=L&&r<=R){
        tree[p]=(tree[p]*val)%mod;
        lazy_add[p]=(lazy_add[p]*val)%mod;
        lazy_mul[p]=(lazy_mul[p]*val)%mod;
        return ;
    }
    pushdown(p,l,r);
    int mid=(l+r)>>1;
    update_mul(p<<1,l,mid,L,R,val);
    update_mul(p<<1|1,mid+1,r,L,R,val);
    tree[p]=(tree[p<<1]+tree[p<<1|1])%mod;
    return ;
}

void update_add(int p,int l,int r,int L,int R,ll val){
    if(r<L||l>R)return ;
    if(l>=L&&r<=R){
        tree[p]=(tree[p]+val*(r-l+1))%mod;
        lazy_add[p]=(lazy_add[p]+val)%mod;
        return ;
    }
    pushdown(p,l,r);
    int mid=(l+r)>>1;
    update_add(p<<1,l,mid,L,R,val);
    update_add(p<<1|1,mid+1,r,L,R,val);
    tree[p]=(tree[p<<1]+tree[p<<1|1])%mod;
    return ;
}

ll query(int p,int l,int r,int L,int R){
    if(r<L||l>R)return 0;
    if(l>=L&&r<=R){
        return tree[p];
    }
    pushdown(p,l,r);
    ll res=0;
    int mid=(l+r)>>1;
    res+=query(p<<1,l,mid,L,R)+query(p<<1|1,mid+1,r,L,R);
    return res%mod;
}

void solve(){
    scanf("%d%d%lld",&n,&m,&mod);
    for(int i=1;i<=n;++i){
        scanf("%lld",&a[i]);
    }
    build(1,1,n);
    for(int i=1;i<=m;++i){
        int type;
        scanf("%d",&type);
        if(type==1){
            int L,R;
            ll val;
            scanf("%d%d%lld",&L,&R,&val);
            update_mul(1,1,n,L,R,val);
        }
        if(type==2){
            int L,R;
            ll val;
            scanf("%d%d%lld",&L,&R,&val);
            update_add(1,1,n,L,R,val);
        }
        if(type==3){
            int L,R;
            scanf("%d%d",&L,&R);
            printf("%lld\n",query(1,1,n,L,R));
        }
        
    }
    return ;
}

int main(){
    solve();
    return 0;
}