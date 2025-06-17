#include<stdio.h>

int main(){
    int opt;
    do
    {
        printf("++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("1. Troi nang\n");
        printf("2. Troi mua\n");
        scanf("%d", &opt);
        printf("++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        switch (opt)
        {
            case 1:
                printf("Can mang o\n");
                break;
            case 2:
                printf("Can mang ao mua\n");
                break;
            default:
                printf("Khong biet mang gi\n");
                break;
        }
    } while (opt != 0);
    
}