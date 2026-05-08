#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int n;
    struct node *link;
};

int main()
{
    int n;
    struct node *list = NULL, *tail, *q;

    scanf("%d", &n);
    while (n != -1)
    {
        q = (struct node *)malloc(sizeof(struct node));
        q->n = n;
        q->link = NULL;

        if (list == NULL)
            list = q;
        else
            tail->link = q;
        tail = q;

        scanf("%d", &n);
    }
    int first = 1;
    while(list != NULL){
        int x = list->n;

        if(!first) printf(" ");
        first = 0;

        if(x < 1000){
            printf("%d", x);
        } else {
            int part[20];
            int cnt = 0;

            while(x > 0){
                part[cnt++] = x % 1000;
                x /= 1000;
            }

            printf("%d", part[cnt-1]);
            for(int i=cnt-2; i>=0; i--){
                printf(",%03d", part[i]);
            }
        }

        q = list;
        list = list->link;
        free(q);
    }

    puts("");
    return 0;
}