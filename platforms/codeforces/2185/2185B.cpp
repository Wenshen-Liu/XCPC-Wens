#include<bits/stdc++.h>


int t;

int main(){
    scanf("%d",&t);
    while(t--){
        int n,x,tmp=0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            scanf("%d",&x);
            if(x>tmp)tmp=x;
        }
        printf("%d\n",n*tmp);
    }
    return 0;
}