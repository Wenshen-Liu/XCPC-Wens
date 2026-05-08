#include<bits/stdc++.h>
using namespace std;


int main(){
    int n=6;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            printf("%d ",i^j);
        }
        puts("");
    }
    return 0;
}
