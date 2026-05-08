#include<bits/stdc++.h>
using namespace std;
const int Maxn=201;

int Min(int a,int b){return a<b?a:b;}
int Max(int a,int b){return a>b?a:b;}

char A[Maxn],B[Maxn];
int len;
int f1[Maxn][Maxn],f2[Maxn];

int main(){
	//freopen("1.in","r",stdin);
	while(scanf("%s%s",A+1,B+1)==2){
		memset(f1,0,sizeof(f1));
		memset(f2,0,sizeof(f2));
		len=strlen(A+1);
		for(int i=len;i>=1;--i){
			f1[i][i]=1;
			for(int j=i+1;j<=len;++j){
				f1[i][j]=f1[i+1][j]+1;
				for(int k=i+1;k<=j;++k){
					if(B[i]==B[k]){
						f1[i][j]=Min(f1[i][j],f1[i+1][k-1]+f1[k][j]);
					}
				}
			}
		}
		for(int i=1;i<=len;++i){
			f2[i]=f1[1][i];
			if(A[i]==B[i]){
				f2[i]=Min(f2[i],f2[i-1]);
			}
			else {
				for(int j=1;j<=i-1;++j){
					f2[i]=Min(f2[i],f2[j]+f1[j+1][i]);
				}
			}
		}
		printf("%d\n",f2[len]);
	}
	return 0;
}
				
