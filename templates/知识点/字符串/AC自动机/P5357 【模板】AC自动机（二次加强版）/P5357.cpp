#include<bits/stdc++.h>
using namespace std;
const int Maxn=2e5+1;

inline int read(){
	int x=0;bool w=0;char ch=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return w?-x:x;
}

inline void write(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>9)write(x/10);
	putchar(x%10+48);
	return ;
}

int n;
int pos[Maxn];
string t[Maxn];
struct AC{
	int end,

void build(int )

int main(){
	n=read();
	for(int i=1;i<=n;++i){
		cin>>t[i];
		build(t[i]);
	}
	
	return 0;
}
