#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int Bai1()
{
    char a;
    scanf("%c", &a);
    printf("%c\n", (a - 'a' + 1) % 26 + 'a');
    return 0;
}

int Bai2()
{
    char str[100];
    scanf("%[^\n]", str);
    getchar();
    int i = strlen(str);
    while (i > 0)
    {
        printf("%c", str[i - 1]);
        i--;
    }
    return 0;
}

int checkdigit(char c[], int len){
    while (len > 0)
    {

        // printf("%c", c[len -1]);
        // printf("%c\n", isdigit(c[len - 1]) ? '1' : '0');
        if (c[len - 1] < '0' || c[len - 1] > '9'){
            return 0;
        }
        len--;
    }
    return 1;
}


int main()
{
    int n;
    scanf("%d", &n);
    getchar(); 
    char str[1000];
    while (n > 0)
    {
        // scanf("%[^\n]", scanf
        scanf("%[^\n]", str);
        getchar();
        int len = strlen(str);
        if (len!=10){
            printf("NO\n");
            n--;
        } else {
            int check = checkdigit(str, len);
            n--;
            printf("%s\n", check ? "YES" : "NO");
        }
        // n--;
    }
}

// int Bai4_5()
// {
//     int n;
//     scanf("%d", &n);
//     char str[1000];
//     int count = 0;
//     while (n > 0)
//     {
//         scanf("%s", str);
//         // getchar();
//         int check = 1;
//         for (int i = 0; i < strlen(str) / 2; i++)
//         {
//             // printf("%c %c\n", str[i], str[strlen(str) - 1 - i]);
//             if (str[i] != str[strlen(str) - 1 - i])
//             {
//                 check = 0;
//                 // printf("NO\n");
//                 break;
//             }
//         }
//         printf("%s\n", check ? "YES" : "NO");
//         count += check;
//         n--;
//     }
//     // printf("%d\n", count);
// }

// int main(){
//     Bai3();
// }