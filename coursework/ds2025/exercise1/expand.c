#include <stdio.h>
#include <string.h>
#include <ctype.h>

int check(char c)
{
    if (isdigit(c))
        return 1;
    if (islower(c))
        return 2;
    if (isupper(c))
        return 3;
    return 0;
}

int main()
{
    char s[1005];
    scanf("%s", s);
    int len = strlen(s);

    for (int i = 0; i < len; i++)
    {
        if (s[i] == '-' && i > 0 && i < len - 1)
        {
            char pre = s[i - 1], nxt = s[i + 1];
            int t1 = check(pre), t2 = check(nxt);
            if (t1 && t1 == t2 && nxt > pre)
            {
                for (char c = pre + 1; c < nxt; c++)
                {
                    putchar(c);
                }
            }
            else
            {
                putchar('-');
            }
        }
        else
        {
            putchar(s[i]);
        }
    }
    putchar('\n');
    return 0;
}