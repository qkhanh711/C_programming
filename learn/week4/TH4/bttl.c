#include<stdio.h>

int isPrime(int n){
    int i;
    if (n<2){
        return 0;
    }
    for (i = 2; i*i < n; i++){
        if (n % i == 0){
            return 0;
        }
    }
    return 1;
}

int inverseint(int n){
    int result = 0;
    while (n > 0){
        result = result * 10 + n % 10;
        n /= 10;
    }
    return result;
}

int GCD(int a, int b){
    int gcd;
    while (b != 0){
        gcd = b;
        b = a % b;
        a = gcd;
    }
    return gcd;
}

int GCD2(int a, int b){
    if (b == 0){
        return a;
    }
    return GCD2(b, a % b);
}

int GCD3(int a, int b){
    if (a != b){
        if (a > b){
            return GCD3(a - b, b);
        }
        else{
            return GCD3(a, b - a);
        }
    }
    return a;
}

int LCM(int a, int b){
    return (a * b) / GCD(a, b);
}

int main(){
    // int n;
    // scanf("%d", &n);
    // printf( isPrime(n) ? "YES" : "NO");
    // printf("%d", inverseint(n));
    // int a, b;
    // scanf("%d %d", &a, &b);
    // printf("%d", GCD(a, b));
    // printf("%d", LCM(a, b));
    int A[10];
    A[0] = 5;
    printf("%d\n", A[0]);
    int B[5] = {1,2,3,4,5};
    for (int i = 0; i < 5; i++){
        printf("%d ", B[i]);
    }
    return 0;

}