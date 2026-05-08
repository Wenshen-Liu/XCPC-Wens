#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,b,c;
    int v1,v2;
    cin>>n>>b>>c;
    cin>>v1>>v2;
    n/=2;
    if(v1<v2){
        swap(v1,v2);
        swap(b,c);
    }
    // cout<<n<<' '<<b<<' '<<c<<endl;
    // cout<<v1<<' '<<v2<<endl;
    if(b>=n){
        printf("%d\n",v1*n);
    }
    else if(b+c>=n){
        printf("%d\n",v1*b+v2*(n-b));
    }
    else {
        printf("%d\n",v1*b+v2*c);
    }
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