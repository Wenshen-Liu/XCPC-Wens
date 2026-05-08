#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
#define MAX 1500
#define lson (now<<1)
#define rson (now<<1|1)
inline int read()
{
	int x=0;bool t=false;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')t=true,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return t?-x:x;
}
int t[MAX<<2];//线段树
void Modify(int now,int l,int r,int p,int w)
{//将p位置用w去修改
	if(l==r){t[now]=max(t[now],w);return;}
	int mid=(l+r)>>1;
	if(p<=mid)Modify(lson,l,mid,p,w);
	else Modify(rson,mid+1,r,p,w);
	t[now]=max(t[lson],t[rson]);
}
int Query(int now,int l,int r,int L,int R)
{//now是线段树的当前节点，l和r表示当前线段树节点对应的区间是[l,r]，L和R表示要查询的区间是[L,R]
	if(L==l&&R==r)return t[now];
	int mid=(l+r)>>1;
	if(R<=mid)return Query(lson,l,mid,L,R);
	if(L>mid)return Query(rson,mid+1,r,L,R);
	return max(Query(lson,l,mid,L,mid),Query(rson,mid+1,r,mid+1,R));
}
int f[MAX],a[MAX],n,ans;
int S[MAX],tot;
int main()
{
	n=read();
	for(int i=1;i<=n;++i)a[i]=S[i]=read();
	sort(&S[1],&S[n+1]);//排序
	tot=unique(&S[1],&S[n+1])-S-1;//去重
	for(int i=1;i<=n;++i)a[i]=lower_bound(&S[1],&S[tot+1],a[i])-S;//离散化
	for(int i=1;i<=n;++i)
	{
		f[i]=Query(1,0,n,0,a[i]-1)+1;
		Modify(1,0,n,a[i],f[i]);
		ans=max(ans,f[i]);
	}
	printf("%d\n",ans);
	return 0;
}
