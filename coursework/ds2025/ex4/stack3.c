#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FUNC 100
#define MAX_NAME 21
#define MAX_CALL 10
#define MAX_STACK 200

typedef struct {
    char name[MAX_NAME];
    char callee[MAX_CALL][MAX_NAME];
    int calleeCount;
} FuncInfo;

FuncInfo funcs[MAX_FUNC];
int funcTotal = 0;

int getFuncIndex(char *name) {
    for (int i = 0; i < funcTotal; i++) {
        if (strcmp(funcs[i].name, name) == 0) return i;
    }
    strcpy(funcs[funcTotal].name, name);
    funcs[funcTotal].calleeCount = 0;
    return funcTotal++;
}

void addCallee(int parentIdx, char *childName) {
    for (int i = 0; i < funcs[parentIdx].calleeCount; i++) {
        if (strcmp(funcs[parentIdx].callee[i], childName) == 0) return;
    }
    strcpy(funcs[parentIdx].callee[funcs[parentIdx].calleeCount++], childName);
}

int main() {
    int op;
    int stack[MAX_STACK];
    int top = -1;
    char currentName[MAX_NAME];

    while (scanf("%d", &op) != EOF) {
        if (op == 8) {
            if (scanf("%s", currentName) == 1) {
                int idx = getFuncIndex(currentName);
                if (top != -1) {
                    addCallee(stack[top], currentName);
                }
                stack[++top] = idx;
            }
        } else if (op == 0) {
            if (top != -1) {
                top--;
            }
            if (top == -1) break;
        }
    }

    for (int i = 0; i < funcTotal; i++) {
        if (funcs[i].calleeCount > 0) {
            printf("%s:", funcs[i].name);
            for (int j = 0; j < funcs[i].calleeCount; j++) {
                printf("%s", funcs[i].callee[j]);
                if (j < funcs[i].calleeCount - 1) {
                    printf(",");
                }
            }
            printf("\n");
        }
    }

    return 0;
}