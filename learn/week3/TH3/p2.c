#include<stdio.h>


int main() {
    int n;
    scanf("%d", &n);
    int F0 = 1, F1 = 2;
    int F2;
    for (int i = 2; i <= n; i++) {
        F2 = 2 * F1 - F0;
        F0 = F1;
        F1 = F2;
    }
    printf("%d", F2);
    
}