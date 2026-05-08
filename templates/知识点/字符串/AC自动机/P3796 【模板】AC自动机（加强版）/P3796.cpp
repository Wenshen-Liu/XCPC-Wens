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
string t[Maxn];

struct node{
	int end,ch[26],fail;
}ac[Maxn];

struct ANS{
	int pos,num;
}ans[Maxn];

bool cmp1(ANS a,ANS b){
	if(a.num==b.num)return a.pos<b.pos;
	return a.num>b.num;
}

void clean(int u){
	memset(ac[u].ch,0,sizeof(ac[u].ch));
	ac[u].fail=0;
	ac[u].end=0;
	return ;
}

void build(string s,int p){
	int len=s.length(),u=0;
	for(int i=0;i<len;++i){
		if(!ac[u].ch[s[i]-'a']){
			clean(++cnt);
			ac[u].ch[s[i]-'a']=cnt;
		}
		u=ac[u].ch[s[i]-'a'];
	}	
	ac[u].end=p;
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

void query(string s){
	int len=s.length(),u=0;
	for(int i=0;i<len;++i){
		u=ac[u].ch[s[i]-'a'];
		for(int t=u;t;t=ac[t].fail){
			++ans[ac[t].end].num;
		}
	}
	return ;
}
int main(){
	while(1){
		cnt=0;
		clean(0);
		n=read();
		if(n==0)break;
		for(int i=1;i<=n;++i){
			cin>>t[i];
			ans[i].pos=i;
			ans[i].num=0;
			build(t[i],i);
		}
		get_fail();
		cin>>t[0];
		query(t[0]);
		sort(ans+1,ans+1+n,cmp1);
		write(ans[1].num);
		putchar('\n');
		for(int i=1;i<=n;++i){
			if(ans[i].num!=ans[1].num)break;
			cout<<t[ans[i].pos];
			putchar('\n');
		}
	}
	return 0;
}
