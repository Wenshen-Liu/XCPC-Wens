#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int start;
    int length;
    struct Node *next;
}Node;

int main(){
    int n;
    if(scanf("%d",&n)!=1)return 0;

    Node *head=NULL,*tail=NULL;
    for(int i=0;i<n;++i){
        int s,l;
        scanf("%d%d",&s,&l);

        Node *newNode=(Node*)malloc(sizeof(Node));
        newNode->start=s;
        newNode->length=l;
        newNode->next=NULL;

        if(!head){
            head=newNode;
            tail=newNode;
            newNode->next=head;
        }
        else{
            tail->next=newNode;
            tail=newNode;
            newNode->next=head;
        }
    }

    Node *current=head;
    int req;

    while(scanf("%d",&req)==1&&req!=-1){
        if(!current)continue;

        Node *temp=current;
        Node *prev=current;
        while(prev->next!=current){
            prev=prev->next;
        }

        Node *best_node=NULL,*best_prev=NULL;
        int min_diff=-1;

        do{
            if(temp->length>=req){
                int diff=temp->length-req;
                if(min_diff==-1||diff<min_diff){
                    min_diff=diff;
                    best_node=temp;
                    best_prev=prev;
                }
            }
            prev=temp;
            temp=temp->next;
        }while(temp!=current);

        if(best_node){
            if(min_diff==0){
                if(best_node->next==best_node){
                    free(best_node);
                    current=NULL;
                }
                else{
                    best_prev->next=best_node->next;
                    current=best_node->next;
                    if(best_node==head)head=best_node->next;
                    if(best_node==tail)tail=best_prev;
                    free(best_node);
                }
            }
            else{
                best_node->length-=req;
                current=best_node;
            }
        }
    }

    if(current){
        Node *temp=current;
        do{
            printf("%d %d\n",temp->start,temp->length);
            temp=temp->next;
        }while(temp!=current);
    }

    return 0;
}