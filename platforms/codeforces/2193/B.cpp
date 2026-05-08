#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    int a[200010];
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    int targ=0,l=0,r=0;
    for(int i=1;i<=n;++i){
        if(a[i]!=n-i+1){
            targ=n-i+1;
            l=i;
            break;
        }
    }
    for(int i=1;i<=n;++i){
        if(a[i]==targ){
            r=i;
        }
    }
    for(int i=l,j=r;i<j;i++,j--){
        swap(a[i],a[j]);
    }
    for(int i=1;i<=n;++i){
        printf("%d ",a[i]);
    }
    puts("");
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