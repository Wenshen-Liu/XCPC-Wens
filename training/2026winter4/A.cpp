#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Maxn 1010

char s[Maxn];
int res[Maxn];

void solve(){
    int m, n;
    cin>>m>>n;
    cin>>s;
    ll d;
    cin>>d;
    for(int i=m-1;i>=0;--i){
        int radix=s[i]-'0';
        res[i]=d%radix;
        d/=radix;
    }
    for(int i=0;i<m;++i){
        printf("%d",res[i]);
    }
    puts(""); 
    return ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}