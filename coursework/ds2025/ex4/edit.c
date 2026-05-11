#include <stdio.h>
#include <string.h>

#define MAX_LEN 1024

typedef struct {
    int op;
    int pos;
    char str[MAX_LEN];
} EditOp;

EditOp stack[100];
int top = -1;

void insert(char *text, int pos, const char *s) {
    int len = strlen(text);
    int s_len = strlen(s);
    for (int i = len; i >= pos; i--) {
        text[i + s_len] = text[i];
    }
    for (int i = 0; i < s_len; i++) {
        text[pos + i] = s[i];
    }
}

void delete_text(char *text, int pos, int n, char *deleted_str) {
    int len = strlen(text);
    if (pos + n > len) n = len - pos;
    
    if (deleted_str != NULL) {
        strncpy(deleted_str, text + pos, n);
        deleted_str[n] = '\0';
    }
    
    for (int i = pos; i <= len - n; i++) {
        text[i] = text[i + n];
    }
}

int main() {
    char text[MAX_LEN];
    gets(text);

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        top++;
        scanf("%d %d %s", &stack[top].op, &stack[top].pos, stack[top].str);
    }

    int cmd, pos;
    char temp_str[MAX_LEN];

    while (scanf("%d", &cmd) && cmd != -1) {
        if (cmd == 1) {
            scanf("%d %s", &pos, temp_str);
            insert(text, pos, temp_str);
            top++;
            stack[top].op = 1;
            stack[top].pos = pos;
            strcpy(stack[top].str, temp_str);
        } 
        else if (cmd == 2) {
            int count;
            scanf("%d %d", &pos, &count);
            char deleted[MAX_LEN];
            delete_text(text, pos, count, deleted);
            top++;
            stack[top].op = 2;
            stack[top].pos = pos;
            strcpy(stack[top].str, deleted);
        } 
        else if (cmd == 3) {
            if (top >= 0) {
                EditOp last = stack[top--];
                if (last.op == 1) {
                    delete_text(text, last.pos, strlen(last.str), NULL);
                } else if (last.op == 2) {
                    insert(text, last.pos, last.str);
                }
            }
        }
    }

    printf("%s\n", text);

    return 0;
}