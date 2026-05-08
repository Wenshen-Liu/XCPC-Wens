#include<bits/stdc++.h>
using namespace std;
const int Maxn=100010;

int n;
int a[Maxn],tree[Maxn];

int lowbit(int x){
	return x&(-x);
}
void updata(int x,int v){
	while(x<=n){
		tree[x]+=v;
		x+=lowbit(x);
	}
	return ;
}
int sum(int x){
	int res=0;
	while(x){
		res+=tree[x];
		x-=lowbit(x);
	}
	return res;
}


void solve(){
    memset(tree,0,sizeof(tree));
    int q;
    cin>>n>>q;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        updata(i,a[i]);
    }
    for(int i=1;i<=q;++i){
        int op,s,p,v;
        cin>>op;
        if(op==1){
            cin>>s;
            check(s);
        }
        if(op==2){
            cin>>p>>v;
            updata(p,v-a[p]);
            a[p]=v;
        }
    }
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