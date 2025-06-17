#include<stdio.h>


int main(){
    int n, count = 1;
    scanf("%d", &n);
    int i = (n+1) / 2;
    for (i; i < n; i++){
        count++;
    }
    printf("%d", count);
}