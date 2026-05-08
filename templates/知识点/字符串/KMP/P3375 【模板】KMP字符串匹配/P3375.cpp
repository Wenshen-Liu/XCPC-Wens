#include<bits/stdc++.h>
const int Maxn=1e6+1;
using namespace std;
int lens,lent,nxt[Maxn],cnt,ans[Maxn];
char s[Maxn],t[Maxn];
int main(){
	scanf("%s%s",s+1,t+1);
	lens=strlen(s+1);
	lent=strlen(t+1);
	for(int i=2,j=0;i<=lent;++i){
		while(j&&t[j+1]!=t[i]){
			j=nxt[j];
		}
		if(t[j+1]==t[i])++j;
		nxt[i]=j;
	}
	for(int i=1,j=0;i<=lens;++i){
		while(j&&t[j+1]!=s[i]){
			j=nxt[j];
		}
		if(t[j+1]==s[i]){
			++j;
		}
		if(j==lent){
			ans[++cnt]=i-lent+1;
		}
	}
	for(int i=1;i<=cnt;++i){
		printf("%d\n",ans[i]);
	}
	for(int i=1;i<=lent;++i){
		printf("%d ",nxt[i]);
	}
	putchar('\n');
	return 0;
}
