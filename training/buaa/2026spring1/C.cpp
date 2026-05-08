#include<bits/stdc++.h>
using namespace std;
int x;
void solve(){
    cin>>x;
    int x3=x/111;
    for(int i=x3;i>=0;--i){
        if((x-i*111)%11==0){
            puts("YES");
            return ;
        }
    }
    puts("NO");
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