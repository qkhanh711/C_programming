#include<stdio.h>

void isTriangle(int a, int b, int c){
    if (a + b > c && a + c > b && b + c > a)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
}

void isPrime(int n){
    int i;
    for (i = 2; i*i < n; i++){
        if (n % i == 0){
            printf("%d", i);
            printf("NO");
            return;
        }
    }
    printf("YES");
}

void isSquare(int n){
    int i;
    for (i = 1; i*i <= n; i++){
        if (n == i*i){
            printf("YES");
            return;
        }
    }
    printf("NO");
}

void countDvisible(int n, int m){
    int count = 0;
    int arr[n];
    for (int i = 1; i <= n; i++)
    {
        if (i % m == 0)
        {
            arr[count] = i;
            count++;
        }
    }
    printf("%d\n", count);
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }
}

void sort(int a, int b, int c){
    int max = a;
    if (b > max)
    {
        max = b;
    }
    if (c > max)
    {
        max = c;
    }
    int min = a;
    if (b < min)
    {
        min = b;
    }
    if (c < min)
    {
        min = c;
    }
    int mid = a + b + c - max - min;
    printf("%d %d %d", max, mid, min);
}

int main(){
    int n; 
    scanf("%d", &n);
    isSquare(n);
}