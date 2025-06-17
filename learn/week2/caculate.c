#include <stdio.h>
#include <stdlib.h>

int main()
{
    // in chu so hang chuc cua a
    int a;
    // printf("Nhap so a: ");
    // scanf("%d", &a);
    a = 130;
    int hangChuc = (a / 10) % 10;
    printf("%d\n", hangChuc);

    int b = 120;
    printf("a = %d, b = %d\n", a, b);
    int temp;
    temp = a;
    a = b;
    b = temp;
    printf("a = %d, b = %d\n", a, b);
}