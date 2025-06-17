#include <stdio.h>
int sum(int a[], int);
int main()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int total;

    printf("Array size: %d\n", sizeof arr / sizeof arr[0]);
    printf("Array size: %d\n", sizeof(arr) / sizeof arr[0]);
    return 0;
}
