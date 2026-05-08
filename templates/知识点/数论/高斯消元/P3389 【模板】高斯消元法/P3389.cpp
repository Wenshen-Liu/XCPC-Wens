#include<bits/stdc++.h>
using namespace std;
const int Maxn=101;

inline int read(){
	int x=0;bool w=0;char ch=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return w?-x:x;
}

double Fabs(double a){return a<0?-a:a;}

int n;
double a[Maxn][Maxn],b[Maxn];

int main(){
	n=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			scanf("%lf",&a[i][j]);
		}
		b[i]=1.0*read();
	}
	for(int i=1;i<=n;++i){
		int p=i;
		for(int j=i+1;j<=n;++j){
			if(Fabs(a[j][i])>Fabs(a[p][j]))p=j;
		}
		for(int j=1;j<=n;++j){
			swap(a[i][j],a[p][j]);
		}
		swap(b[i],b[p]);
		if(!a[i][i]){
			printf("No Solution\n");
			return 0;
		}
		for(int j=1;j<=n;++j){
			if(j!=i){
				double tmp=a[j][i]/a[i][i];
				for(int k=i;k<=n;++k){
					a[j][k]-=a[i][k]*tmp;
				}
				b[j]-=b[i]*tmp;
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			printf("%.2lf ",a[i][j]);
		}
		printf("%.2lf\n",b[i]);
	}
	for(int i=1;i<=n;++i){
		printf("%.2lf\n",b[i]/a[i][i]);
	}
	return 0;
}
