#include<stdio.h>

int main(){
    int sum0 = 0;
    int sum;
    printf("%d %d\n", &sum, sum);
    for (int i = 0; i <= 50; i++){
        sum0 += i;
    }
    printf("%d\n", sum0);
}