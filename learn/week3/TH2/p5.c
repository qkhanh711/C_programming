#include<stdio.h>

int main(){
    int a, b, i;
    scanf("%d %d", &a, &b);
    int mul = a * b;
    if (mul > 0){
        i = 1;
    }
    else if (mul < 0){
        i = -1;
    }
    else{
        i = 0;
    }
    printf("%d", i);
}