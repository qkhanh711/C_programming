#include<stdio.h>


void isPrime(long long n){
    int i;
    for (i = 2; i < n; i++){
        if (n % i == 0){
            printf("NO");
            return;
        }
    }
    printf("YES");
}

int main(){
    long long n; 
    scanf("%lld", &n);
    if (n < 2){
        printf("NO");
        return 0;
    }
    isPrime(n);
}