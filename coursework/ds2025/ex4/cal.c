#include<stdio.h>
#define Maxn 1010
char s[Maxn],post[Maxn*2];
double stk[Maxn];
int top,i,j;

int pri(char c){
	if(c=='+'||c=='-')return 1;
	if(c=='*'||c=='/')return 2;
	return 0;
}

int main(){
	while(scanf("%c",&s[i])==1 && s[i]!='=') i++;
	s[i]='\0';
	char opstk[Maxn];
	int optop=-1;
	i=0; j=0;
	while(s[i]){
		if(s[i]==' '){i++;continue;}
		if(s[i]>='0'&&s[i]<='9'){
			while(s[i]>='0'&&s[i]<='9') post[j++]=s[i++];
			post[j++]=' ';
			continue;
		}
		if(s[i]=='('){
			opstk[++optop]='(';
			i++; continue;
		}
		if(s[i]==')'){
			while(optop>=0 && opstk[optop]!='('){
				post[j++]=opstk[optop--];
				post[j++]=' ';
			}
			if(optop>=0) optop--;
			i++; continue;
		}
		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
			while(optop>=0 && opstk[optop]!='(' && pri(opstk[optop])>=pri(s[i])){
				post[j++]=opstk[optop--];
				post[j++]=' ';
			}
			opstk[++optop]=s[i++];
			continue;
		}
		i++;
	}
	while(optop>=0){
		post[j++]=opstk[optop--];
		post[j++]=' ';
	}
	post[j]='\0';
	i=0; top=-1;
	while(post[i]){
		if(post[i]==' '){i++;continue;}
		if(post[i]>='0'&&post[i]<='9'){
			double x=0;
			while(post[i]>='0'&&post[i]<='9'){
				x=x*10 + post[i++]-'0';
			}
			stk[++top]=x;
			continue;
		}
		if(post[i]=='+'||post[i]=='-'||post[i]=='*'||post[i]=='/'){
			double b=stk[top--];
			double a=stk[top--];
			if(post[i]=='+') stk[++top]=a+b;
			else if(post[i]=='-') stk[++top]=a-b;
			else if(post[i]=='*') stk[++top]=a*b;
			else if(post[i]=='/') stk[++top]=a/b;
			i++;
			continue;
		}
		i++;
	}
	
	printf("%.2f\n",stk[top]);
	return 0;
}