#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int check_upper(char *str){
    // int check = 0
    for (int i = 0; i< strlen(str); i++){
        if (isupper(str[i])){
            return  1;
        }
        // if (isdigit(str[i])){
        //     check = 1;
        // }
    }
    return 0;
}

int check_digit(char *str){
    // int check = 0
    for (int i = 0; i< strlen(str); i++){
        // if (isupper(str[i])){
        //     check = 1;
        // }
        if (isdigit(str[i])){
            return 1;
        }
    }
    return 0;
}

int checker(char *str){
    int i = 0, check = 0;
    // printf("%c\n ", str[0]);
    if (str[0] != 'p'  || str[0] != 'P' ){
        check = 1;
    } 
    check = 0;
    // printf("Check P \n",check);
    // printf("Check digit \n",check);
    if (check_digit(str) && check_upper(str)){
        check = 1;
    }    
    return check;
}

void counter(char *str){
    int countalpha = 0, countdig = 0;
    for (int i = 0; i< strlen(str); i++){
        if (isalpha(str[i])){
            countalpha++;
        }
        if (isdigit(str[i])){
            countdig++;
        }
    }
    printf("String co %d chu cai, %d so\n", countalpha, countdig);
    // printf("Num digit %d\nP", countdig );
    // return 0;
}

int check_special(char c){
    if (!isalpha(c) && !isdigit(c)){
        return 0;
    }
    else {return 1;}
}

char remove_spec(char *str){
    int i = 0;
    while(i < strlen(str)){
        if (check_special(str[i])){
            printf("%c", str[i]);
        }
        i++;
    }
}

int main(){
    char str[7];
    int i = 0;
    int check = 0;
    do {
        printf("Nhap vao string: %s", &str);
        scanf("%[^\n]", &str);
        getchar();
        counter(str);
        printf("string ket qua sau khi xoa ky tu dac biet: ");
        remove_spec(str);
        check = checker(str);
        // printf("Checker %d\n", check);
        if (check == 1){
            break;
        } else {
            // printf("Re enter\n");
        }
    } while (i < strlen(str));

}