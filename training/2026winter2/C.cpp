#include<bits/stdc++.h>
using namespace std;

void solve(){
    int len,k,tmp=0;
    string s;
    cin>>len>>k;
    cin>>s;
    if (2 * k >= len) {
        puts("NO");
        return;
    }
    for(int l=0,r=len-1;l<=r;++l,--r){
        if(s[l]!=s[r]){
            break;
        }
        ++tmp;
    }
    // printf("%d \n",tmp);
    if(tmp<k){
        puts("NO");
    }
    else puts("YES");
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