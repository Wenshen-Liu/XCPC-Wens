#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int coef;
    int exp;
    struct node *next;
};

struct node* newNode(int c,int e){
    struct node *p=(struct node*)malloc(sizeof(struct node));
    p->coef=c;
    p->exp=e;
    p->next=NULL;
    return p;
}

void insertPoly(struct node **head,int c,int e){
    if(c==0) return;

    struct node *pre=NULL,*p=*head;
    while(p!=NULL&&p->exp>e){
        pre=p;
        p=p->next;
    }

    if(p!=NULL&&p->exp==e){
        p->coef+=c;
        if(p->coef==0){
            if(pre==NULL) *head=p->next;
            else pre->next=p->next;
            free(p);
        }
        return;
    }

    struct node *q=newNode(c,e);
    if(pre==NULL){
        q->next=*head;
        *head=q;
    }else{
        q->next=p;
        pre->next=q;
    }
}

void readPoly(struct node **head){
    char line[10000];
    if(fgets(line,sizeof(line),stdin)==NULL) return;

    char *p=line;
    int c,e,len;
    while(sscanf(p,"%d%d%n",&c,&e,&len)==2){
        insertPoly(head,c,e);
        p+=len;
    }
}

struct node* multiply(struct node *a,struct node *b){
    struct node *res=NULL;
    struct node *pa,*pb;

    for(pa=a;pa!=NULL;pa=pa->next){
        for(pb=b;pb!=NULL;pb=pb->next){
            insertPoly(&res,pa->coef*pb->coef,pa->exp+pb->exp);
        }
    }

    return res;
}

void printPoly(struct node *head){
    struct node *p=head;
    while(p!=NULL){
        printf("%d %d",p->coef,p->exp);
        if(p->next!=NULL) printf(" ");
        p=p->next;
    }
}

void freePoly(struct node *head){
    struct node *p;
    while(head!=NULL){
        p=head;
        head=head->next;
        free(p);
    }
}

int main(){
    struct node *A=NULL,*B=NULL,*C=NULL;

    readPoly(&A);
    readPoly(&B);

    C=multiply(A,B);
    printPoly(C);

    freePoly(A);
    freePoly(B);
    freePoly(C);

    return 0;
}