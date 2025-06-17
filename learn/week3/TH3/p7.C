#include<stdio.h>

int main() {
    char ch;
    printf("Hay nhap chuoi ky tu lien tuc (khong co dau cach):\n");
    printf("Chuoi ky tu vua nhap: ");  
    while (ch != ' ' && ch != '\n') {
        scanf("%c", &ch);
        printf("%c", ch);
        if (ch == ' ' || ch == '\n') {
            break;
        }
    }
    
} 