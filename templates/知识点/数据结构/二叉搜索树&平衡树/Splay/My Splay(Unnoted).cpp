#include<bits/stdc++.h>
using namespace std;
const int Maxn=1e6;

inline int Read(){
	int x=0;char ch=0;bool w=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return w?-x:x;
}

int n;

struct Splay{
	int rt,siz[Maxn],cnt[Maxn],ch[Maxn][2],fa[Maxn],val[Maxn],cnot;
	void maintain(int x){siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+cnt[x];}
	bool get(int x){return x==ch[fa[x]][1];}
	void clear(int x){ch[x][0]=ch[x][1]=fa[x]=val[x]=siz[x]=cnt[x]=0;}
	void rotate(int x){
		int y=fa[x],z=fa[y],chk=get(x);
		ch[y][chk]=ch[x][chk^1];
		if(ch[x][chk^1])fa[ch[x][chk^1]]=y; 
		ch[x][chk^1]=y;
		fa[y]=x;
		fa[x]=z;
		if(z)ch[z][y==ch[z][1]]=x;
		maintain(x);
		maintain(y);
		return ;
	}
	void splay(int x){
		for(int f=fa[x];f=fa[x],f;rotate(x)){
			if(fa[f])rotate(get(x)==get(f)?f:x);
		}
		rt=x;
	}
	void ins(int x){
		if(!rt){
			val[++cnot]=x;
			++cnt[cnot];
			rt=cnot;
			maintain(rt);
			return ;
		}
		int cur=rt,f=0;
		while(1){
			if(val[cur]==x){
				++cnt[cur];
				maintain(cur);
				maintain(f);
				splay(cur);
				break;
			}
			f=cur;
			cur=ch[cur][val[cur]<x];
			if(!cur){
				val[++cnot]=x;
				++cnt[cnot];
				fa[cnot]=f;
				ch[f][val[f]<x]=cnot;
				maintain(cnot);
				maintain(f);
				splay(cnot);
				break;
			}
		}
	}
	int rk(int x){
		int res=0,cur=rt;
		while(cur){
			if(x<val[cur]){
				cur=ch[cur][0];
			}
			else {
				res+=siz[ch[cur][0]];
				if(x==val[cur]){
					splay(cur);
					return res+1;
				}
				res+=cnt[cur];
				cur=ch[cur][1];
			}
		}
		return res+1 ;
	}
	int kth(int x){
		int cur=rt;
		while(1){
			if(ch[cur][0]&&x<=siz[ch[cur][0]]){
				cur=ch[cur][0];
			}
			else {
				x-=cnt[cur]+siz[ch[cur][0]];
				if(x<=0){
					return val[cur];
				}
				cur=ch[cur][1];
			}
		}
	}
	int pre(){
		int cur=ch[rt][0];
		if(!cur)return cur;
		while(ch[cur][1])cur=ch[cur][1];
		splay(cur);
		return cur;
	}
	int nxt(){
		int cur=ch[rt][1];
		if(!cur)return cur;
		while(ch[cur][0])cur=ch[cur][0];
		splay(cur);
		return cur;
	}
	void del(int x){
		rk(x);
		if(cnt[rt]>1){
			--cnt[rt];
			maintain(rt);
			return ;
		}
		if(!ch[rt][0]&&!ch[rt][1]){
			clear(rt);
			rt=0;
			return ;
		}
		if(!ch[rt][0]){
			int cur=rt;
			rt=ch[rt][1];
			fa[rt]=0;
			clear(cur);
			return ;
		}
		if(!ch[rt][1]){
			int cur=rt;
			rt=ch[rt][0];
			fa[rt]=0;
			clear(cur);
			return ;
		}
		int cur=rt,y=pre();
		fa[ch[cur][1]]=y;
		ch[y][1]=ch[cur][1];
		clear(cur);
		maintain(rt);
		return ;
	}
}tree;

int main(){
	n=Read();
	while(n--){
		int type=Read(),x=Read();
		if(type==1){
			tree.ins(x);
		}
		if(type==2){
			tree.del(x);
		}
		if(type==3){
			printf("%d\n",tree.rk(x));
		}
		if(type==4){
			printf("%d\n",tree.kth(x));
		}
		if(type==5){
			tree.ins(x);
			printf("%d\n",tree.val[tree.pre()]);
			tree.del(x);
		}
		if(type==6){
			tree.ins(x);
			printf("%d\n",tree.val[tree.nxt()]);
			tree.del(x);
		}
	}
	return 0;
}
