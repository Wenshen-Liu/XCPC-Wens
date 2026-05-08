#include<bits/stdc++.h>

int T;
int n;

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        if(n==2)puts("2");
        else if(n==3)puts("3");
        else printf("%d\n",(n&1)?1:0);
    }
    return 0;
}