#include<bits/stdc++.h>
using namespace std;

const int Maxn=110;

inline int Read(){
	int x=0;bool w=0;char ch=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return w?-x:x;
}

inline double Abs(double a){return a<0?-a:a;}

int n;
double a[Maxn][Maxn],b[Maxn];
double ans[Maxn];

inline void check(){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			printf("%lf ",a[i][j]);
		}
		printf("%lf \n",b[i]);
	}
	return ;
}

void Gause(){
	int newline=1;
	for(int i=1;i<=n;++i){
		int p=newline;
		//-------------------找出绝对值最大的一个a[i][i]来 
		for(int j=p+1;j<=n;++j){
			if(Abs(a[j][i])>Abs(a[p][i]))p=j;
		}
		for(int j=1;j<=n;++j){
			swap(a[newline][j],a[p][j]);
		}
		swap(b[newline],b[p]);
		//-------------------
		if(a[newline][i]==0)continue;//如果已经找到了绝对值最大的数了仍然还为零，就说明没救了 
		for(int j=1;j<=n;++j){
			if(j!=newline){
				double tmp=a[j][i]/a[newline][i];//将a[j][i]给对掉，并将其他项相应地减去一些。 
				for(int k=i+1;k<=n;++k){
					a[j][k]-=a[newline][k]*tmp;
				}
				b[j]-=b[newline]*tmp;
			}
		}
		++newline;//下一个列 
	}
	check();
	if(newline<=n){//如果说不能删除完 
		while(newline<=n){
			if(b[newline++]!=0){//倘若有b尚且有值，儿a却为零了，那么就说明了误解 
				printf("-1\n");
				exit(0);
			}
		}
		printf("0\n");//若是每一个b都为零，又a为零，则有无穷解。 
		exit(0);
	}
	return ;
}

int main(){
//	freopen("1.in","r",stdin);
	n=Read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			a[i][j]=1.0*Read();
		}
		b[i]=1.0*Read();
	}
	Gause();
	for(int i=1;i<=n;++i){
		printf("x%d=",i);
		if(b[i]/a[i][i]==0.00||b[i]/a[i][i]==-0.00)printf("0.00\n");
		else printf("%.2lf\n",b[i]/a[i][i]);
	}
	return 0;
}
