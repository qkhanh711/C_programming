#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            // printf("%d\n", (i >> j));
            printf("%d", (i >> j) & 1);
        }
        printf("\n");
    }
    return 0;
}

// Giai thich 
// 1. (1 << n) = 2^n
// 2. (i >> j) & 1 = lay bit j cua i
// 3. (i >> j) = lay i va dich phai j bit
// 4. (i >> j) & 1 = lay bit j cua i
// 5. (i >> j) & 1 = 0 hoac 1
// 6. (i >> j) & 1 = 0 thi in ra 0
// 7. (i >> j) & 1 = 1 thi in ra 1


