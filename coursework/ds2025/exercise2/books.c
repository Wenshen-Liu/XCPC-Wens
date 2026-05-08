#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Maxn 505

struct Book{
    char name[55];
    char author[25];
    char press[35];
    char date[15];
}a[Maxn];

int n;

FILE *open_books_file_for_read(){
    FILE *fin=fopen("books.txt","r");
    if(fin!=NULL)return fin;

    const char *src=__FILE__;
    const char *p=strrchr(src,'/');
    if(p==NULL)return NULL;

    char path[1024];
    size_t dir_len=(size_t)(p-src);
    if(dir_len+10>=sizeof(path))return NULL;
    memcpy(path,src,dir_len);
    path[dir_len]='\0';
    strcat(path,"/books.txt");
    return fopen(path,"r");
}

int cmp(const void *p1,const void *p2){
    const struct Book *a=(const struct Book *)p1;
    const struct Book *b=(const struct Book *)p2;
    return strcmp(a->name,b->name);
}

void print_book(struct Book x){
    printf("%-50s%-20s%-30s%-10s\n",x.name,x.author,x.press,x.date);
}

void fprint_book(FILE *fout,struct Book x){
    fprintf(fout,"%-50s%-20s%-30s%-10s\n",x.name,x.author,x.press,x.date);
}

void load_books(){
    FILE *fin=open_books_file_for_read();
    n=0;
    if(fin==NULL)return;
    while(n<500&&fscanf(fin,"%54s%24s%34s%14s",a[n+1].name,a[n+1].author,a[n+1].press,a[n+1].date)==4){
        ++n;
    }
    fclose(fin);
    qsort(a+1,n,sizeof(struct Book),cmp);
}

void insert_book(){
    if(n>=500){
        return;
    }
    ++n;
    scanf("%54s%24s%34s%14s",a[n].name,a[n].author,a[n].press,a[n].date);
    qsort(a+1,n,sizeof(struct Book),cmp);
}

void find_book(){
    char s[55];
    scanf("%54s",s);
    for(int i=1;i<=n;++i){
        if(strstr(a[i].name,s)!=NULL){
            print_book(a[i]);
        }
    }
}

void delete_book(){
    char s[55];
    scanf("%54s",s);
    int m=0;
    for(int i=1;i<=n;++i){
        if(strstr(a[i].name,s)==NULL){
            a[++m]=a[i];
        }
    }
    n=m;
}

void save_books(){
    FILE *fout=fopen("ordered.txt","w");
    if(fout==NULL)return;
    for(int i=1;i<=n;++i){
        fprint_book(fout,a[i]);
    }
    fclose(fout);
}

void solve(){
    load_books();
    int op;
    while(scanf("%d",&op)==1){
        if(op==0){
            save_books();
            break;
        }
        if(op==1){
            insert_book();
        }
        else if(op==2){
            find_book();
        }
        else if(op==3){
            delete_book();
        }
    }
    return ;
}

int main(){
    solve();
    return 0;
}