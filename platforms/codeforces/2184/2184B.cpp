#include<bits/stdc++.h>
using namespace std;

int T;

int func(int s,int k,int m){
    if(s>=k){
        int r=m/k;
        m%=k;
        if(r&1){
            return k-m;
        }
        else return s-m;
    }
    if(s<k){
        m%=k;
        if(m<s){
            return s-m;
        }
        else return 0;
    }
    return -1;
}

int main(){
    scanf("%d",&T);
    while(T--){
        int s,m,k;
        scanf("%d%d%d",&s,&k,&m);
        printf("%d\n",func(s,k,m));
    }
    return 0;
}