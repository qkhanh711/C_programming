#include<stdio.h>

int main() {
    long long int n;
    scanf("%lld", &n);
    int a = 0;
    do {
        a++;
        if (n-a >= 0) {
            printf("%d %lld", a , n-a);
            break;
        }

    }
    while (a< n);
}