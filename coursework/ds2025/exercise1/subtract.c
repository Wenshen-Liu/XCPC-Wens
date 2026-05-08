#include<stdio.h>
#include<string.h>

char s1[102],s2[102];
int len1,len2;

void swap(char *a,char *b){
    char t[102];
    strcpy(t,a);
    strcpy(a,b);
    strcpy(b,t);
}

void print1(){
    int check=0;
    for(int i=0;i<=len1-1;++i){
        if(s1[i]!=0)check=1;
        if(check==1){
            printf("%d",s1[i]);
        }
    }
    if(check==0){
        printf("0");
    }
    puts("");
    return ;
}

int main() {
    scanf("%s",s1);
    scanf("%s",s2);
    int l1=strlen(s1), l2=strlen(s2);
    int cmp = (l1!=l2) ? (l1-l2) : strcmp(s1,s2);
    if(cmp<0){
        printf("-");
        swap(s1,s2);    
    }
    len1 = strlen(s1);
    len2 = strlen(s2);
    for(int i=0;i<len1;++i)s1[i]-='0';
    for(int i=0;i<len2;++i)s2[i]-='0';
    int borrow=0;
    for(int i=len1-1,j=len2-1;j>=0;--j,--i){
        if(s1[i]<s2[j]+borrow){
            s1[i]=s1[i]-s2[j]-borrow+10;
            borrow=1;
        }
        else {
            s1[i]=s1[i]-s2[j]-borrow;
            borrow=0;
        }
        if(j==0){
            int k=i-1;
            while(borrow&&k>=0){
                s1[k]-=borrow;
                if(s1[k]<0){
                    s1[k]+=10;
                    borrow=1;
                }
                else break;
                --k;
            }
        }
    }
    print1();
    return 0;
}