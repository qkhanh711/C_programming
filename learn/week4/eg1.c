#include<stdio.h>


long long  factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }   
    return result;
}

int main(){
    printf("5! = %lld\n", factorial(5));
    printf("3! = %lld\n", factorial(3));
    printf("7! = %lld\n", factorial(7));
    printf("10! = %lld\n", factorial(10));
}
