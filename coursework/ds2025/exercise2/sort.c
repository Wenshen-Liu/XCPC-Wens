#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Maxn 110

struct Node{
    char name[30];
    char phone[20];
}a[Maxn],ans[Maxn];

int n,m;
char raw[Maxn][30];
int cnt[Maxn];

int same(char *s,char *t){
    return strcmp(s,t)==0;
}

int cmp(const void *p1,const void *p2){
    struct Node *a=(struct Node *)p1;
    struct Node *b=(struct Node *)p2;
    return strcmp(a->name,b->name);
}

void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%s%s",a[i].name,a[i].phone);
    }

    m=0;
    for(int i=1;i<=n;++i){
        int dup=0;
        for(int j=1;j<=m;++j){
            if(same(a[i].name,raw[j])&&same(a[i].phone,ans[j].phone)){
                dup=1;
                break;
            }
        }
        if(dup)continue;

        ++m;
        strcpy(raw[m],a[i].name);
        strcpy(ans[m].phone,a[i].phone);

        int num=0;
        for(int j=1;j<m;++j){
            if(same(raw[j],a[i].name)){
                ++num;
            }
        }

        if(num==0){
            strcpy(ans[m].name,a[i].name);
        }
        else{
            sprintf(ans[m].name,"%s_%d",a[i].name,num);
        }
    }

    qsort(ans+1,m,sizeof(struct Node),cmp);
    for(int i=1;i<=m;++i){
        printf("%s %s\n",ans[i].name,ans[i].phone);
    }
    return ;
}

int main(){
    solve();
    return 0;
}