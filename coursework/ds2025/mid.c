#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coef;        // 系数
    int exp;         // 次数
    struct Node *next;
} Node;

// 创建新节点
Node* createNode(int coef, int exp) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// 插入并维护多项式，同时统计比较次数
void insertOrUpdate(Node **head, int coef, int exp, int *compareCount) {
    Node *prev = NULL;
    Node *curr = *head;

    while (curr != NULL && curr->exp > exp) {
        (*compareCount)++;
        prev = curr;
        curr = curr->next;
    }

    // 找到相同次数的节点
    if (curr != NULL && curr->exp == exp) {
        (*compareCount)++;
        curr->coef += coef;
        if (curr->coef == 0) {
            if (prev == NULL) *head = curr->next;
            else prev->next = curr->next;
            free(curr);
        }
    } 
    // 未找到相同次数，新建节点插入
    else {
        if (coef != 0) {
            Node *newNode = createNode(coef, exp);
            if (prev == NULL) {
                newNode->next = *head;
                *head = newNode;
            } else {
                newNode->next = curr;
                prev->next = newNode;
            }
        }
    }
}

void printList(Node *head) {
    Node *curr = head;
    if (curr == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }
    while (curr != NULL) {
        printf("Coef: %d, Exp: %d\n", curr->coef, curr->exp);
        curr = curr->next;
    }
}

int main() {
    Node *head = NULL;
    int c, e;
    int totalCompares = 0;

    printf("Enter coef and exp (0 0 to stop):\n");
    while (scanf("%d %d", &c, &e) && (c != 0 || e != 0)) {
        insertOrUpdate(&head, c, e, &totalCompares);
    }

    printf("\n--- Result ---\n");
    printList(head);
    printf("Total comparisons: %d\n", totalCompares);

    return 0;
}