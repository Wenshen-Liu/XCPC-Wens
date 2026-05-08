#include <stdio.h>

int main()
{
    int count[26] = {0};
    int ch;
    int maxh = 0;
    while ((ch = getchar()) != EOF)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            count[ch - 'a']++;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (count[i] > maxh)
        {
            maxh = count[i];
        }
    }
    for (int h = maxh; h >= 1; h--)
    {
        for (int i = 0; i < 26; i++)
        {
            if (count[i] >= h)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    for (int i = 0; i < 26; i++)
    {
        printf("%c", 'a' + i);
    }
    printf("\n");

    return 0;
}