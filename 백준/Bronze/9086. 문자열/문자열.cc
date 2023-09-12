#pragma warning(disable:4996);
#include <stdio.h>
#include <string.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        char s[1002];
        scanf("%s", s);
        printf("%c%c\n", s[0], s[strlen(s)-1]);
    }
    return 0;
}
