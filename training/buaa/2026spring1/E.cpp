#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=100010;

int n;
double t[Maxn],x[Maxn];
int x1,x2;

double min(double a,double b){return a<b?a:b;}
double max(double a,double b){return a>b?a:b;}

double cost(double p,int u){
    return fabs(x[u]-p)+t[u];
}

double best(int u,int v){
    double cen=0.0;
    if(x[u]>x[v])swap(u,v);
    cen=(x[u]+x[v])/2.0+(t[v]-t[u])/2.0;
    cen=min(x[v],cen);
    cen=max(x[u],cen);
    return cen;
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>x[i];
    }
    for(int i=1;i<=n;++i){
        cin>>t[i];
    }
    if(n==1){
        printf("%lf\n",x[1]);
        return ;
    }
    if(n==2){
        printf("%lf\n",best(1,2));
        return ;
    }
    x1=1,x2=2;
    for(int i=3;i<=n;++i){
        double cen12=best(x1,x2),cen1i=best(x1,i),cen2i=best(x2,i);
        if(cost(cen12,i)<cost(cen12,x1))continue;
        if(cost(cen1i,x2)<cost(cen2i,x1)){
            x2=i;
        }
        else x1=i;
    }
    printf("%lf\n",best(x1,x2));
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