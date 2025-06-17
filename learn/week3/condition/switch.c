#include<stdio.h>

int main(){
    int a = 5;
    switch (a) {
        case 1:
            printf("A");
            break;
        case 3:
            printf("C");
            break;
        case 5:
            printf("E");
            break;
        default:
            printf("F");
            break;
    }
}