// What a beautiful code!
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
	void maintain(int x){siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+cnt[x];}// Calculate the size of X.
	bool get(int x){return x==ch[fa[x]][1];}// Judge wether the point X is the left son or right son of its father.
	void clear(int x){ch[x][0]=ch[x][1]=fa[x]=val[x]=siz[x]=cnt[x]=0;}// Clear the value of X.
	void rotate(int x){// Left-handed and right-handed.
		int y=fa[x],z=fa[y],chk=get(x);// Look for the father and grandpa of X,and judge wether the point X is the left son or right son of its father.
		ch[y][chk]=ch[x][chk^1];// If X is the chk son of Y,then turn another son into the chk son of Y.
		if(ch[x][chk^1])fa[ch[x][chk^1]]=y;//If this son exists,change its fa together. 
		ch[x][chk^1]=y;//turn the chk son of X into Y.
		fa[y]=x;//Change Y's fa together.
		fa[x]=z;//Turn X's fa into Y's origin fa.
		if(z)ch[z][y==ch[z][1]]=x;//If Y's origin fa exists,Judge which son of it Y is,and turn it to X.
		maintain(x);//maintain X and Y.
		maintain(y);
		return ;
	}
	void splay(int x){//Turn
		for(int f=fa[x];f=fa[x],f;rotate(x)){//From the bottom to the top,rotate the points one step by one step.
			if(fa[f])rotate(get(x)==get(f)?f:x);
			//1.If the parent of X is the root node, rotate x directly to the left or right.
			//2.If the father of X is not the root node and X is of the same type as the father's son, first rotate its father left or right, and then rotate x right or left.
			//3.If the father of X is not the root node and X is different from the son of the father, rotate x left and then right, or right and then left.
		}
		rt=x;// Turn any point into the total root.
	}
	void ins(int x){//insert X
		if(!rt){//If there is no root node,just make a new node,and look it as the root node.
			val[++cnot]=x;
			++cnt[cnot];
			rt=cnot;
			maintain(rt);
			return ;
		}
		int cur=rt,f=0;
		while(1){//Find the point of which value equals to the X.
			if(val[cur]==x){//If find a ready-made point,updata its information.
				++cnt[cur];
				maintain(cur);
				maintain(f);
				splay(cur);//Always splay the point.
				break;
			}
			f=cur;
			cur=ch[cur][val[cur]<x];//Find the point by the rules of BST.
			if(!cur){//If there is no ready-made node now,we can make one.
				val[++cnot]=x;
				++cnt[cnot];
				fa[cnot]=f;
				ch[f][val[f]<x]=cnot;
				maintain(cnot);
				maintain(f);
				splay(cnot);//Always splay the point.
				break;
			}
		}
	}
	int rk(int x){//Calculate X's rank in the numbers.
		int res=0,cur=rt;
		while(cur){//1.If cur equal to 0,it says that there is no value x in the tree.
			if(x<val[cur]){
				cur=ch[cur][0];//If X is less than val[cur],go to the left son of cur.
			}
			else {
				res+=siz[ch[cur][0]];//If not,it says that the value of the whole left subtree of the point cur is less than X.
				if(x==val[cur]){//If X==val[cur],we find it.And after calculation,we can return.
					splay(cur);// Always splay it.
					return res+1;// Remember to add one.
				}
				res+=cnt[cur];
				cur=ch[cur][1];
			}
		}
		return res+1;//1.Then,return the accumulated answer(res).
	}
	int kth(int x){// Find the x-th number.
		int cur=rt;
		while(1){
			if(ch[cur][0]&&x<=siz[ch[cur][0]]){//It says that the toalis in the left subtree of cur.
				cur=ch[cur][0];//Go go go!
			}
			else {// X is a bit big.
				x-=cnt[cur]+siz[ch[cur][0]];//Subtract cur's cnt and the size of its left suntree.
				if(x<=0){
					return val[cur];// It says toal is just this point and return it.
				}
				cur=ch[cur][1];//Go to right.
			}
		}
	}
	int pre(){// Find the rightmost node of the left subtree. 
		int cur=ch[rt][0];
		if(!cur)return cur;
		while(ch[cur][1])cur=ch[cur][1];
		splay(cur);// Always splay it.
		return cur;
	}
	int nxt(){//Find the leftmost node of the right subtree.
		int cur=ch[rt][1];
		if(!cur)return cur;
		while(ch[cur][0])cur=ch[cur][0];
		splay(cur);// Always splay it.
		return cur;
	}
	void del(int x){// The most important and difficult part.
		rk(x);//Turn the point with value equals to x into the root node.
		if(cnt[rt]>1){//If cnt[rt]>1 Just subtract one.
			--cnt[rt];
			maintain(rt);// Updata its information.
			return ;
		}
		//If cnt[rt] equals to 0 now,we need to delete the whole node.
		//Also,we should sub situation.
		if(!ch[rt][0]&&!ch[rt][1]){//If the rt has no son.
			clear(rt);
			rt=0;
			return ;
		}
		if(!ch[rt][0]){//If the point rt has right son.
			int cur=rt;
			rt=ch[rt][1];
			fa[rt]=0;
			clear(cur);
			return ;
		}
		if(!ch[rt][1]){//If rt has left son.
			int cur=rt;
			rt=ch[rt][0];
			fa[rt]=0;
			clear(cur);
			return ;
		}
		//If the root node has both left and right son.
		int cur=rt,y=pre();// Turn its precursor or Successor into new root.
		fa[ch[cur][1]]=y;//Make sure the father-son relationship between right son and the new root.
		ch[y][1]=ch[cur][1];//With this sectence.
		clear(cur);
		maintain(rt);
		return ;
	}
}tree;

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
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
			tree.ins(x);// Every time,turn the goal into the root,then we can simplify the operation to find the pre.
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
