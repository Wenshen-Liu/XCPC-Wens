#include<stdio.h>
#define Maxn 1010
int op,x;
int stack[Maxn];
int top=0;
int main(){
    while(1){
        scanf("%d",&op);
        if(op==-1)break;
        if(op==0){
            if(top==0){
                printf("error ");
                continue;
            }
            printf("%d ",stack[top--]);
        }
        if(op==1){
            scanf("%d",&x);
            stack[++top]=x;
        }
    }
    puts("");
    return 0;
}