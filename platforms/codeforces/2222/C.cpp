#include<bits/stdc++.h>
using namespace std;
#define Maxn 5010

int a[Maxn];
int b[Maxn];
int dp[Maxn];
int les[Maxn];
int more[Maxn];
int n;

void solve(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    int mid=b[(n+1)/2];
    for(int i=1;i<=n;++i){
        les[i]=les[i-1]+(a[i]<mid?1:0);
        more[i]=more[i-1]+(a[i]>mid?1:0);
        dp[i]=-1;
    }
    dp[0]=0;
    for(int i=1;i<=n;++i){
        for(int j=i-1;j>=0;j-=2){
            if(dp[j]!=-1){
                int L=i-j;
                int c1=les[i]-les[j];
                int c2=more[i]-more[j];
                if(c1*2<L && c2*2<L){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                    }
                }
            }
        }
    }
    printf("%d\n",dp[n]);
}

int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}