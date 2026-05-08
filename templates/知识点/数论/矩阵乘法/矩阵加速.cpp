#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Mod=1e9+7;

inline int Read(){
	int x=0;char ch=0;bool w=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return w?-x:x;
}

void Write(int x){
	if(x>9)Write(x/10);
	putchar(x%10+'0');
	return ;
}

struct Matrix{
	ll a[4][4];
	int n,m;
};

Matrix kong;

Matrix Mult(Matrix A,Matrix B){
	Matrix C;
	C=kong;
	C.n=A.n;
	C.m=B.m;
	for(int i=1;i<=C.n;++i){
		for(int j=1;j<=C.m;++j){
			for(int k=1;k<=A.m;++k){
				C.a[i][j]+=A.a[i][k]*B.a[k][j];
				C.a[i][j]%=Mod;
			}
		}
	}
	return C;
}

void print(Matrix A){
	for(int i=1;i<=A.n;++i){
		for(int j=1;j<=A.m;++j){
			printf("%d ",A.a[i][j]);
		}
		puts("");
	}
	return ;
}

int T;
Matrix A,B,C,D;

int main(){
	T=Read();
	A.n=A.m=3;
	C.n=C.m=3;
	A.a[1][2]=A.a[2][3]=A.a[3][1]=A.a[3][3]=1;
	C.a[1][1]=C.a[2][2]=C.a[3][3]=1;
	while(T--){
		int b=Read()-3;
		if(b<=0){
			puts("1");
			continue;
		}
		B=A;
		D=C;
		while(b){
			if(b&1)D=Mult(B,D);
			B=Mult(B,B);
			b>>=1;
		}
		Write((D.a[3][1]+D.a[3][2]+D.a[3][3])%Mod);
		puts("");
	}
	return 0;
}
