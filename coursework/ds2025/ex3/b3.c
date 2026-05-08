#include <stdio.h>
#include <stdlib.h>
struct node {
        int n;
        struct node *link;
};

int main()
{
    int n;
    struct node *list=NULL, *tail, *q;
    
    scanf("%d",&n);
    while(n!=-1){
        q = (struct node *)malloc(sizeof(struct node));
        q->n = n; 
        q->link = list;
        if(list==NULL) 
            list=q;
        else
            tail->link=q;
        tail=q;                
        scanf("%d",&n);
    }
    
        if(list==NULL) return 0;

    if(list->link==list){
        printf("%d",list->n);
        free(list);
        return 0;
    }

    struct node *p = list;
    struct node *pre = tail;
    int first = 1;

    while(p != p->link){
        if(!first) printf(" ");
        printf("%d",p->n);
        first = 0;

        pre->link = p->link;

        if(p == list)
            list = p->link;

        q = p;
        p = pre->link;
        free(q);

        if(p == pre){
            if(!first) printf(" ");
            printf("%d",p->n);
            free(p);
            return 0;
        }

        pre = p;
        p = p->link;
    }

    if(!first) printf(" ");
    printf("%d",p->n);
    free(p);
    return 0;
} 
