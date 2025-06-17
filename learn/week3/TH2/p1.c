#include<stdio.h>

int main(){
    // int n;
    // scanf("%d", &n);
    // int sum = (n + 1) * (n) / 2;
    // printf("%d\n", sum); 
    unsigned long long n;
    scanf("%llu", &n);
    long double sum = (long double)(n + 1) * (long double)(n) / 2;
    long double sum0 = 10.00 * 10.01;
    printf("%Lf\n", sum0);
    printf("%.0Lf\n", sum);
}