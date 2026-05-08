#include<bits/stdc++.h>
using namespace std;
const int Maxn=200010;

typedef struct node{
    int a,b;
}node;

bool cmp1(node x1,node x2){return x1.b<x2.b;}

node x[Maxn];
int n;
int f1[Maxn];

void solve(){
    memset(f1,0,sizeof(f1));
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>x[i].a;
    }
    for(int i=1;i<=n;++i){
        cin>>x[i].b;
    }
    for(int i=1;i<=n;++i){
        int xa=x[i].a;
        for(int j=2;j<=sqrt(x[i].a)&&j<=xa;++j){
            if(xa%j==0){
                if(f1[j]){
                    puts("0");
                    return ;
                }
                f1[j]=1;
                while(xa%j==0){
                    xa/=j;
                }
            }
        }
    }
    sort(x+1,x+1+n,cmp1);
    int ans=x[1].b+x[2].b;
    for(int i=1;i<=n&&x[i].b<ans;++i){
        int xa=x[i].a+1;
        for(int j=2;j<=sqrt(x[i].a)&&j<=xa;++j){
            if(xa%j==0){
                if(f1[j]){
                    ans=min(ans,x[i].b);
                    return ;
                }
                while(xa%j==0){
                    xa/=j;
                }
            }
        }
        if(x[i].b==x[1].b){
            int xa=x[i].a+1;
            for(int j=2;j<=sqrt(x[i].a)&&j<=xa;++j){
                if(xa%j==0){
                    if(f1[j]){
                        ans=min(ans,x[i].b);
                        return ;
                    }
                    while(xa%j==0){
                        xa/=j;
                    }
                }
            }
        }
        
    }
    printf("%d\n",ans);
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