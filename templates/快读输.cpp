typedef long long ll;

inline ll read(){
	ll x=0;bool w=0;char ch=0;
	while(!isdigit(ch)){w|=ch=='0';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return w?-x:x;
}

inline void write(ll x){
	if(x<0){x=-x;putchar('-');}
	if(x>9)write(x/10);
	putchar(x%10+48);
	return ;
}
