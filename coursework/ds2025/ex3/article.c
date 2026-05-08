#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct{
    char *s;
    int cnt;
}Node;

char *cp(char *s){
    int len=strlen(s);
    char *p=(char*)malloc((len+1)*sizeof(char));
    if(p==NULL)return NULL;
    strcpy(p,s);
    return p;
}

int cmp(const void *a,const void *b){
    return strcmp(((Node*)a)->s,((Node*)b)->s);
}

int main(){
    FILE *fp=fopen("article.txt","r");
    if(fp==NULL)return 0;

    int cap=100,tot=0;
    Node *a=(Node*)malloc(cap*sizeof(Node));
    if(a==NULL){
        fclose(fp);
        return 0;
    }

    char s[1005];
    int len=0,ch;

    while((ch=fgetc(fp))!=EOF){
        if(isalpha(ch)){
            s[len++]=(char)tolower(ch);
        }
        else{
            if(len==0)continue;
            s[len]='\0';

            int p=-1;
            for(int i=0;i<tot;++i){
                if(strcmp(a[i].s,s)==0){
                    p=i;
                    break;
                }
            }

            if(p!=-1)++a[p].cnt;
            else{
                if(tot==cap){
                    cap*=2;
                    Node *t=(Node*)realloc(a,cap*sizeof(Node));
                    if(t==NULL){
                        for(int i=0;i<tot;++i)free(a[i].s);
                        free(a);
                        fclose(fp);
                        return 0;
                    }
                    a=t;
                }
                a[tot].s=cp(s);
                if(a[tot].s==NULL){
                    for(int i=0;i<tot;++i)free(a[i].s);
                    free(a);
                    fclose(fp);
                    return 0;
                }
                a[tot].cnt=1;
                ++tot;
            }

            len=0;
        }
    }

    if(len){
        s[len]='\0';

        int p=-1;
        for(int i=0;i<tot;++i){
            if(strcmp(a[i].s,s)==0){
                p=i;
                break;
            }
        }

        if(p!=-1)++a[p].cnt;
        else{
            if(tot==cap){
                cap*=2;
                Node *t=(Node*)realloc(a,cap*sizeof(Node));
                if(t==NULL){
                    for(int i=0;i<tot;++i)free(a[i].s);
                    free(a);
                    fclose(fp);
                    return 0;
                }
                a=t;
            }
            a[tot].s=cp(s);
            if(a[tot].s==NULL){
                for(int i=0;i<tot;++i)free(a[i].s);
                free(a);
                fclose(fp);
                return 0;
            }
            a[tot].cnt=1;
            ++tot;
        }
    }

    fclose(fp);

    qsort(a,tot,sizeof(Node),cmp);

    for(int i=0;i<tot;++i){
        printf("%s %d\n",a[i].s,a[i].cnt);
        free(a[i].s);
    }
    free(a);
    return 0;
}