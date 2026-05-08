#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    int max_saved=0;
    string s;
    cin>>n;
    cin>>s;
    for(int i=1;i<=n/2;++i) {
        bool match=true;
        for(int j=0;j<i;++j) {
            if(s[j]!=s[i+j]) {
                match = false;
                break;
            }
        }
        if(match){
            max_saved=max(max_saved,i-1);
        }
    }
    printf("%d\n",n-max_saved);
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    while(T--){
        solve();
    }
    return 0;
}