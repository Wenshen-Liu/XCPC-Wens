#include<bits/stdc++.h>
using namespace std;
const int Maxn=100010;

int n;
int c[Maxn],p[Maxn];

void solve(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>c[i]>>p[i];
    }
    
    double f=0;
    for(int i=n;i>=1;--i){
        double k=1.0-p[i]/100.0;
        f=max(f,c[i]+k*f);
    }
    cout<<fixed<<setprecision(10)<<f<<"\n";
}

int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}