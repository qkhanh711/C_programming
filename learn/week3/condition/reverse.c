#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int rev = 0;
    while (n != 0){
        printf("%d %d\n", n % 10, rev);
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    printf("%d\n", rev); 
}