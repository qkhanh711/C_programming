#include<stdio.h>


int main(){
    int d;
    char ch;
    scanf("%c %d", &ch, &d);
    printf("%c", (ch - 'a' + d) % 26 + 'a');
}