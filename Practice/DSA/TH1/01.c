#include<stdio.h>
#include<stdlib.h>

int main(void){
    int h[4] = {4,5,6};
    printf("Gia tri cua h[0]=%d\n", h[0]);
    printf("Gia tri cua h[4]=%d\n", h[3]);
    printf("Dia chi cua h[0]=%p\n", &h[0]); // Cach 1
    printf("Dia chi cua h[0]=%p\n", h); // Cach 2
    printf("Dia chi cua h[1]=%p\n", &h[1]); // Cach 1
    printf("Dia chi cua h[1]=%p\n", h+1); // Cach 2
    printf("Gia tri cua h[1]=%d\n", h[1]); // Cach 1
    printf("Gia tri cua h[1]=%d\n", *(h+1)); // Cach 2
}

int ex5FindMax1() {
    int i;
    printf("\nDUYET MANG: TIM GIA TRI LON NHAT\n");
    int index, max, numArray[10];
    max = -1;
    printf("Nhap 10 gia tri so vao mang numArray: \n");
    for (index = 0; index < 10; index++) {
        scanf("%d", numArray[index]);
    }
    for (index = 0; index < 10; index++) {
        if (numArray[index] > max)
            max = numArray[index];
    }
    printf("Gia tri lon nhat la %d.\n", max);
}

void print1DimArr(int arr[], int n){
    for (int i = 0; i< n; i++){
        printf("%d ", arr[i]);
    }
}

int print2DimArrA(int arr[][3], int m){
    int i,j;

    for (i = 0; i < m; i++){
        for (j = 0; j < 3; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}


int print2DimArrB(int ar[][3], int m){
    int i, j;
    for (i = 0; i < m; i++) {
        print1DimArr(ar[i], 3);
        printf("\n");
    }
}

