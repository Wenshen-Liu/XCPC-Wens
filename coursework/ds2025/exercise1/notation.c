#include <stdio.h>
#include <string.h>

int main() {
    char s[128];
    if (scanf("%127s", s) != 1) {
        return 0;
    }
    int n = (int)strlen(s);
    int dot = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '.') {
            dot = i;
            break;
        }
    }
    if (s[0] != '0') {
        int exp = dot - 1;

        char first = s[0];
        char rest[128];
        int len = 0;

        for (int i = 1; i < n; ++i) {
            if (s[i] == '.') {
                continue;
            }
            rest[len++] = s[i];
        }
        while (len > 0 && rest[len - 1] == '0') {
            --len;
        }
        rest[len] = '\0';

        if (len == 0) {
            printf("%ce%d\n", first, exp);
        } else {
            printf("%c.%se%d\n", first, rest, exp);
        }
    }
    else {
        int first_non_zero = dot + 1;
        while (first_non_zero < n && s[first_non_zero] == '0') {
            ++first_non_zero;
        }

        if (first_non_zero == n) {
            printf("0e0\n");
            return 0;
        }

        int exp = -(first_non_zero - dot);
        char first = s[first_non_zero];
        char rest[128];
        int len = 0;

        for (int i = first_non_zero + 1; i < n; ++i) {
            rest[len++] = s[i];
        }
        while (len > 0 && rest[len - 1] == '0') {
            --len;
        }
        rest[len] = '\0';

        if (len == 0) {
            printf("%ce%d\n", first, exp);
        } else {
            printf("%c.%se%d\n", first, rest, exp);
        }
    }

    return 0;
}
