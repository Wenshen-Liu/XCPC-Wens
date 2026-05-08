#include<bits/stdc++.h>
using namespace std;

int a[1010];

void solve(){
    memset(a,0,sizeof(a));
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        int x;
        scanf("%d",&x);
        ++a[x];
    }
    // for(int i=1;i<=n;++i){
    //     printf("%d ",a[i]);
    // }
    // puts("");
    for(int i=1;i<=n;++i){
        if(a[i]>2){
            a[i+1]+=a[i]-2;
            a[i]=2;
        }
    }
    for(int i=1;i<=n;++i){
        if(a[i]&1){
            puts("NO");
            return ;
        }
        // printf("%d ",a[i]);
    }
    puts("YES");
    return ;
}

int main(){
    
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}