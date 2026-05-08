#include<bits/stdc++.h> 
using namespace std;
int Max(int a,int b){return a>b?a:b;}
int n,h,f[2010];
struct node{
	int a,b;
}dwarf[2010];
bool cmp1(node x,node y){return x.a+x.b<y.a+y.b;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&dwarf[i].a,&dwarf[i].b);
	}
	scanf("%d",&h);
	sort(dwarf+1,dwarf+1+n,cmp1);
	for(int i=1;i<=n;i++){
		f[i]=-0x3f3f3f3f;
		f[0]+=dwarf[i].a;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			if(f[j-1]+dwarf[i].b>=h)f[j]=Max(f[j],f[j-1]-dwarf[i].a);
		}
	}
	for(int i=n;i>=0;i--){
		if(f[i]>=0){
			printf("%d",i);
			return 0;
		}
	}
}
