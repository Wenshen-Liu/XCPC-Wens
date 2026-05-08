#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=5005;

ll a[Maxn];
ll bef[Maxn];
ll all_cards[Maxn];

void solve(){
    ll n,k,p,m;
    cin>>n>>k>>p>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    
    ll wc=a[p];
    int bef_cnt=0;
    for(int i=1;i<p;++i){
        bef[++bef_cnt]=a[i];
    }
    
    sort(bef+1,bef+1+bef_cnt,greater<ll>());
    
    ll fc=wc;
    ll fz1=min((ll)bef_cnt,k-1);
    for(int i=fz1+1;i<=bef_cnt;++i){
        fc+=bef[i];
    }
    
    if(m<fc){
        cout<<0<<"\n";
        return;
    }
    
    ll ans=1;
    m-=fc;
    
    if(n<=k){
        ans+=m/wc;
        cout<<ans<<"\n";
        return;
    }
    
    int all_cnt=0;
    for(int i=1;i<=n;++i){
        if(i!=p){
            all_cards[++all_cnt]=a[i];
        }
    }
    
    sort(all_cards+1,all_cards+1+all_cnt,greater<ll>());
    
    ll lc=wc;
    for(int i=k;i<=all_cnt;++i){
        lc+=all_cards[i];
    }
    
    ans+=m/lc;
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    if(cin>>T){
        while(T--){
            solve();
        }
    }
    return 0;
}