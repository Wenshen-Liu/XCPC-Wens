#include<bits/stdc++.h>
using namespace std;

priority_queue <int,vector<int>,greater<int> >q;
int n;

void solve(){
    cin>>n;
    for(int i=1;i<=n;++i){
        int op;
        cin>>op;
        if(op==1){
            int x;
            cin>>x;
            q.push(x);
        }
        if(op==2){
            printf("%d\n",q.top());
        }
        if(op==3){
            q.pop();
        }
    }
    return ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}