#include <stdio.h>
#include <ctype.h>
#include <string.h>

int countAdjacentLetters(char a, char b)
{
    if (!islower(a) || !islower(b))
    {
        return -1;
    }

    int count = 0;
    for (char c = a; c <= b; c++)
    {
        if (c == a || c == b)
        {
            continue;
        }
        if ((c == a - 1 || c == a + 1) || (c == b - 1 || c == b + 1))
        {
            count++;
        }
    }

    return count;
}

int main()
{
    char a, b;
    scanf("%c %c", &a, &b);
    int count = 0;
    while (b < a-1)
    {
        count++;
        b++;
    }
    printf("%d\n", count);

    return 0;
}
