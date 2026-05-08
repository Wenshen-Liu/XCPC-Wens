#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}

ll count(ll n, int lcm, const int pre[]) {
    if(n<0)return 0;
    ll cnt=(n+1)/lcm;
    int rem=(n+1)%lcm;
    return cnt*pre[lcm]+pre[rem]; 
}

void solve() {
    ll a,b,q;
    cin>>a>>b>>q;
    int lcm=(a*b)/gcd(a,b);
    int pre[40010];
    memset(pre,0,sizeof(pre));
    for (int i=0;i<lcm;++i){
        pre[i+1]=pre[i];
        if(((i%a)%b)!=((i%b)%a))++pre[i+1];
    }
    for (int k = 0; k < q; ++k) {
        ll l,r;
        cin>>l>>r;
        ll ans=count(r,lcm,pre)-count(l-1,lcm,pre);
        printf("%lld ",ans);
    }
    puts("");
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