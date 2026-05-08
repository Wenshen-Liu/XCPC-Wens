#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Mod=1e9+7;

inline int Read(){
	int x=0;bool w=0;char ch=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return w?-x:x;
}

inline void Write(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>9)Write(x/10);
	putchar(x%10+48);
	return ;
}

int T;
int n,A,B;
ll s[50001][201],c[201][201];

int main(){
	T=Read();
    s[0][0]=1;
    for(int i=1;i<=50000;++i){
        for(int j=1;j<=200;++j){
            s[i][j]=(s[i-1][j-1]+s[i-1][j]*(i-1)%Mod)%Mod;
        }
    }
	memset(c,0,sizeof(c));
	c[0][0]=1;
    for(int i=1;i<=200;++i){
        c[i][0]=1;
        for(int j=1;j<=i;++j){
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%Mod;
		}
	}
    while(T--){
    	n=Read(),A=Read(),B=Read();
		Write(s[n-1][A+B-2]*c[A+B-2][A-1]%Mod);
		putchar('\n');
    }
    return 0;
}
