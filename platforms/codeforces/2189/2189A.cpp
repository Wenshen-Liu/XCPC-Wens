#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,h,l;
    cin>>n>>h>>l;
    if(h>l)swap(h,l);
    int cnth=0,cntl=0;
    for(int i=1;i<=n;++i){
        int x;
        cin>>x;
        if(x>l)continue;
        if(x>h)++cntl;
        else if(x<=h)++cnth;
    }
    if(cntl>cnth)cout<<cnth<<endl;
    else {
        cout<<(cntl+cnth)/2<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}