#include<bits/stdc++.h>
const int Maxn=1e6+1;
using namespace std;

inline int read(){
	int x=0;bool w=0;char ch=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return w?-x:x;
}

inline void write(int x){
	if(x<0){x=-x;putchar('-');}
	if(x>9)write(x/10);
	putchar(x%10+48);
	return ;
}

int n,cnt;
string t[Maxn],S;

struct node{
	int end,ch[26],fail;
}ac[Maxn];

void build(string s){
	int len=s.length(),u=0;
	for(int i=0;i<len;++i){
		if(!ac[u].ch[s[i]-'a'])ac[u].ch[s[i]-'a']=++cnt;
		u=ac[u].ch[s[i]-'a'];
	}
	++ac[u].end;
	return ;
}

void get_fail(){
	queue<int>q;
	for(int i=0;i<26;++i){
		if(ac[0].ch[i]){
			ac[ac[0].ch[i]].fail=0;
			q.push(ac[0].ch[i]);
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<26;++i){
			if(ac[u].ch[i]){
				ac[ac[u].ch[i]].fail=ac[ac[u].fail].ch[i];
				q.push(ac[u].ch[i]);
			}
			else ac[u].ch[i]=ac[ac[u].fail].ch[i];
		}
	}
	return ;
}

int query(string s){
	int len=s.length(),u=0,ans=0;
	for(int i=0;i<len;++i){
		u=ac[u].ch[s[i]-'a'];
		for(int t=u;t&&ac[t].end!=-1;t=ac[t].fail){
			ans+=ac[t].end;
			ac[t].end=-1;
		}
	}
	return ans;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		cin>>t[i];
		build(t[i]);
	}
	get_fail();
	cin>>S;
	printf("%d\n",query(S));
	return 0;
}
