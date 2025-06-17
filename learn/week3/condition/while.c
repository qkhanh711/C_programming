#include<stdio.h>


int main(){
    int n = 0;
    do {
        printf("Enter a number between 1 and 10: ");
        scanf("%d", &n);
    } while (10 < n || n < 1);
}