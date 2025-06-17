#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int main(void){
    int a = 10, b = 20;
    printf("a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("a = %d, b = %d\n", a, b);
    int arr[5] = {1, 2, 3, 4, 5};
    int *p = arr;
    printArray(arr, 5);

    for (int i = 0; i < 5/2; i++) {
        swap(p + i, p + (5 - 1 - i));
    }

    printf("Mang sau khi dao nguoc: ");
    printArray(p, 5);
    printArray(arr, 5);


    char str[1000];
    scanf("%[^\n]", str);
    getchar();
    char *pointer = str;
    printf("Chuoi ban dau: %s\n", pointer);
    int countNumber = 0;
    int countDigit = 0;
    while (*pointer != NULL) {
        if (*pointer >= '0' && *pointer <= '9') {
            countNumber++;
        } else if (*pointer >= 'A' && *pointer <= 'z') {
            countDigit++;
        }
        pointer++;
    }
    // printf("Day co do dai: %d\n", countNumber + countDigit);
    printf("So chu so: %d\n", countNumber);
    printf("So chu cai: %d\n", countDigit);

    int m = 2, n = 2;
    int *mat = (int *)malloc(m * n * sizeof(int));

    // for (int i = 0; i < m; i++) {
    //     for (int j = 0; j < n; j++) {
    //         scanf("%d", (mat + i * n + j));
    //     }
    // }
    for (int i = 0; i < m*n; i++){
        // printf("Nhap gia tri mat");
        scanf("%d", mat + i);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // printf("%d", i*n + j);
            printf("%d ", *(mat + i * n + j));
        }
        printf("\n");
    }
}