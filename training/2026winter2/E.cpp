#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    int a[100010];
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    if(k==0){
        printf("%d\n",n);
        return ;
    }
    sort(a+1,a+1+n);
    int tmp=0;
    for(int i=0;i<=n-1;++i){
        if(a[i+1]!=i){
            break;   
        }
        tmp=i+1;
    }
    if(tmp==a[n])++tmp;
    int MAX=a[n],MEX=tmp,ans=n;
    int p=(0.5+1.0*(MAX+MEX)/2);
    if(!binary_search(a+1,a+1+n,p)&&p!=MEX){
        ++ans;
    }
    if(p==MEX){
        ans+=k;
    }
    printf("%d\n",ans);
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