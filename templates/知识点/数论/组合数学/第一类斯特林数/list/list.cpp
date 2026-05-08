#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=1e3+1;

int Min(int a,int b){return a<b?a:b;}

int n,m;
ll s[Maxn][Maxn];

int main(){
	scanf("%d%d",&n,&m);
	s[0][0]=1;
    for(ll i=1;i<=n;++i){
        for(ll j=1;j<=m;++j){
            s[i][j]=s[i-1][j-1]+s[i-1][j]*(i-1);
        }
    }
    for(ll i=0;i<=n;i++){
    	for(ll j=0;j<=Min(i,m);j++){
    		printf("%lld ",s[i][j]);
		}
		putchar('\n');
	}
    return 0;
}
