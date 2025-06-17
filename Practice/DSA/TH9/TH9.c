#include<stdio.h>
#include<stdlib.h>

void countSort(int a[], int b[], int c[], int k, int n){
    for (int i = 0; i<=k; i++) {
        b[i] = 0;
    }

    for (int i = 0; i<n; i++) {
        b[a[i]]++;
    }

    for (int i = k-1; i>=0; i--) {
        b[i] += b[i+1];
    }

    for (int i = n-1; i>=0; i--) {
        c[b[a[i]]-1] = a[i];
        b[a[i]]--;
    }
}

void print_array(int arr[], int n ){
    for (int i = 0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

}


int main(void){
    int a[10] = {42, 23, 74,11,65,58,96,36,99,87};
    int c[10];
    int n = 10;
    int amax;
    int *b;

    for (int i = 0; i<n; i++) {
        if (i == 0 || a[i] > amax) {
            amax = a[i];
        }
    }

    b = (int *)malloc((amax + 1) * sizeof(int));
    countSort(a, b, c, amax, n);
    printf("\nMang truoc khi sap xep: ");
    print_array(a, n);
    printf("\nMang sau khi sap xep: ");
    print_array(c, n);
    free(b);
    return 0;
}