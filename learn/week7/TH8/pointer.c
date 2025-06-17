#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // int aa = 10;
    // int *p = &aa;

    // printf("Gia tri cua aa: %d\n", aa);
    // printf("Dia chi cua aa: %d\n", &aa);
    // printf("Gia tri cua p: %d\n", p);
    // // printf("Gia tri cua *p: %d\n", *p);
    // printf("Gia tri tai dia chi p tro toi : %d\n", *p);
    // aa = 55;
    // printf("Gia tri tai dia chi p tro toi : %d\n", *p);

    // printf("Gia tri cua aa: %d\n", aa);
    // printf("Dia chi cua aa: %d\n", &aa);
    // printf("Gia tri cua p: %d\n", p);
    // // printf("Gia tri cua aa: %d\n", *p);
    // printf("Gia tri tai dia chi p tro toi : %d\n", *p);

    // int arr[3] = {11, 22, 33};
    // printf("%p\n", arr);
    // printf("%p\n", arr + 1);
    // printf("%d\n", *(arr + 1));
    // int *p = arr;
    // printf("%d\n", *p);
    // p+= 1;
    // printf("%d\n", *p);
    // printf("%d\n", *p+1);
    // printf("%d\n", *(p+1));

    // arr[4] = 5;
    // printf("%d\n", arr[4]);

    int n;
    int *arr;
    printf("Nhap n: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d]: ", i);
        scanf("%d", arr + i);
    }

    printf("mang da nhap: ");
    for (int i = 0; i < n; i++)
    {
        // printf("%d ", arr[i]);
        printf("%d ", *(arr + i));
    }
}

// void modifyValue(int x){
//    x = 100;
// }
// int main() {
//    int a = 10;
//    modifyValue(a);
//    printf("a = %d", a);
// }
