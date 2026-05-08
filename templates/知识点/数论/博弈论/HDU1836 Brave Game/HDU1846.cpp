#include<stdio.h>
using namespace std;
int n,m,T;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		if(n%(m+1))printf("first\n");
		else printf("second\n");
	}
	return 0;
}
