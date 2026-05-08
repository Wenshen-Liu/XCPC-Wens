#include<bits/stdc++.h>
using namespace std;

const int Maxn=1e6;

inline int Max(int a,int b){return a>b?a:b;}

struct node{
	vector<int> a;
	bool fu;
	node():a(Maxn,0),fu(0){}
}kong;

node init2(){
	node A;
	string ch;
	if(!(cin>>ch)) return A;
	if(ch[0]=='-'){
		A.fu=1;
		A.a[0]=ch.length()-1;
	}
	else {
		A.a[0]=ch.length();
		ch=" "+ch;
	}
	for(int i=1;i<=A.a[0];++i){
		A.a[i]=ch[A.a[0]-i+1]-48;
	}
	return A;
}


void print(const node &A){
	if(A.fu==1)putchar('-');
	for(int i=A.a[0];i>=1;--i){
		putchar(48+A.a[i]);
	}
	putchar(' ');
	return ;
}

node Plus(const node &A,const node &B){
	node C;
	C.a[0]=Max(A.a[0],B.a[0]);
	for(int i=1;i<=C.a[0];++i){
		C.a[i]+=A.a[i]+B.a[i];
		C.a[i+1]+=C.a[i]/10;
		C.a[i]%=10;
	}
	while(C.a[C.a[0]+1])++C.a[0];
	return C;
}

node Mult(const node &A,const node &B){
	node C;
	C.fu=A.fu^B.fu;
	C.a[0]=A.a[0]+B.a[0];
	for(int i=1;i<=A.a[0];++i){
		for(int j=1;j<=B.a[0];++j){
			C.a[i+j-1]+=A.a[i]*B.a[j];
			C.a[i+j]+=C.a[i+j-1]/10;
			C.a[i+j-1]%=10;
		}
	}
	while(C.a[0]>1&&!C.a[C.a[0]])--C.a[0];
	return C;
}

bool cmpare(const node &A,const node &B){
	if(A.a[0]>B.a[0])return 1;
	if(A.a[0]<B.a[0])return 0;
	for(int i=A.a[0];i>=1;--i){
		if(A.a[i]>B.a[i])return 1;
		if(A.a[i]<B.a[i])return 0;
	}
	return 1;
}

node Redu(const node &A,const node &B){
	node C;
	const node *X=&A,*Y=&B;
	if(!cmpare(A,B)){
		swap(X,Y);
		C.fu=1;
	}
	C.a[0]=X->a[0];
	int borrow=0;
	for(int i=1;i<=C.a[0];++i){
		int cur=X->a[i]-borrow-Y->a[i];
		if(cur<0){
			cur+=10;
			borrow=1;
		}
		else borrow=0;
		C.a[i]=cur;
	}
	while(C.a[0]>1&&!C.a[C.a[0]])--C.a[0];
	return C;
}


node Work(const node &A,const node &B,bool x){
	node C;
	bool bfu=B.fu^x;
	if(A.fu^bfu){
		C=Redu(A,B);
		C.fu^=A.fu;
	}
	else {
		C=Plus(A,B);
		C.fu=A.fu;
	}
	if(C.a[0]==1&&C.a[1]==0)C.fu=0;
	return C;
}

node A,B,fy;

int main(){
	A=init2();
	B=init2();
	A=Work(A,B,0);
	print(A);
	return 0;
}
