#include<stdio.h>
#include<ctype.h>
#include<string.h>



int main(void){


    char s[100];
    char c;
    scanf("%s", s);
    getchar();
    scanf("%c", &c);
    for (int i = 0; i< strlen(s); i++){
        if (s[i] == c){
            for (int j = i; j < strlen(s); j++){
                s[j] = s[j+1];
            }
            i--;
        }
    }
    printf("%s\n", s);
}
