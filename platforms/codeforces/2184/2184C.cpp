#include<bits/stdc++.h>
typedef long long ll;
int t;
ll a,b,n;
int main(){
    scanf("%d",&t);
    while(t--){
        int step=0;
        scanf("%lld%lld",&n,&a);
        b=a;
        while(b<n){
            ++step;
            a=a*2-1;
            b=b*2+1;
        }
        if(a<=n && n<=b)printf("%d\n",step);
        else puts("-1");
    }
    return 0;
}