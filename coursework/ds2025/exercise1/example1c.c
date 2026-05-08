#include <stdio.h>
int main() {
    int stack[1000], top = -1;
    int num = 0, res = 0;
    char op = '+';
    char ch;
    while (scanf(" %c", &ch) != EOF) {
        if (ch >= '0' && ch <= '9') {
            num = num * 10 + (ch - '0');
        }
        if (((ch < '0' || ch > '9') && ch != ' ' )|| ch == '=') {
            if (op == '+') stack[++top] = num;
            else if (op == '-') stack[++top] = -num;
            else if (op == '*') stack[top] = stack[top] * num;
            else if (op == '/') stack[top] = stack[top] / num;

            if (ch == '=') break;
            op = ch;
            num = 0;
        }
    }
    while (top != -1) {
        res += stack[top--];
    }
    printf("%d\n", res);
    return 0;
}