#include<bits/stdc++.h>
using namespace std;

int n,a[200010];

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        int big1=0,big2=0;
        for(int i=1;i<=n;++i){
            cin>>a[i];
            if(big1<=a[i]){
                big2=big1;
                big1=a[i];
            }
            else if(a[i]>big2)big2=a[i];
        }
        for(int i=1;i<=n;++i){
            if(a[i]==big1){
                if(big1==big2){
                    printf("0 ");
                }
                else {
                    printf("%d ",a[i]-big2);
                }
            }
            else printf("%d ",a[i]-big1);
        }
        puts("");
    }
    return 0;
}