#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int countAdjacentLetters(char a, char b) {
    // if (!islower(a) || !islower(b)) {
    //     return -1; 
    // }
    
    int count = 0;
    for (char c = a; c <= b; c++) {
        if (c == a || c == b) {
            continue;
        }
        if ((c == a - 1 || c == a + 1) || (c == b - 1 || c == b + 1)) {
            count++;
        }
    }
    
    return count;
}

// char validString (char *s) {
//     for (int i = 0; i < strlen(s); i++) {
//         if (!isdigit(s[i])) {
//             return 0; 
//         }
//     }
//     return 1; 
// }

int main() {
    // char a, b;
    // scanf(" %c %c", &a, &b);
    
    // int result = countAdjacentLetters(a, b);

    // printf("%d\n", result);    


    // char s[1000];
    // char c;
    // scanf("%s", s);
    // getchar();
    // scanf("%c", &c);
    // for (int i = 0; i< strlen(s); i++){
    //     if (s[i] == c){
    //         for (int j = i; j < strlen(s); j++){
    //             s[j] = s[j+1];
    //         }
    //         i--;
    //     }
    // }
    // printf("%s\n", s);

    int n;
    scanf("%d", &n);
    long long int s[n];
    int check = 1;
    int j = 0;
    while (j < n) {
        scanf("%lld", &s[j]);
        // printf("%lld ", s[j]);
        j++;
    }    
    getchar();

    for (int i = 0; i < n-1; i++) {
        if (s[i] > s[i + 1]) {
            check = 0;
            break;
        }
    }

    if (check) {
        // for (int i = 0; i < n-1; i++) {
        //     if (s[i] >= s[i + 1]) {
        //         check = 0;
        //         break;
        //     }
        // }   
        // if (check) {  
        //     printf("NO\n");
        // } else {
        //     printf("YES\n");
        // }
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    // int n;
    // scanf("%d", &n);
    // char s[n][1000];
    // getchar(); 
    // for (int i = 0; i < n; i++) {
    //     scanf("%[^\n]", s[i]);
    //     getchar(); 
    // }

    // for (int i = 0; i < n; i++) {
    //     if (validString(s[i])) {
    //         printf("%s\n", s[i]);
    //         break;
    //     }
    // }
    
    // int n;
    // scanf("%d", &n);
    // int s[n];
    // for (int i = 0; i < n; i++) {
    //     scanf("%d", &s[i]);
    // }
    // int s1[n];
    // int count = 0;
    // for (int i = 0; i < n; i++) {
    //     if (s[i] > 0) {
    //         s1[count] = s[i];
    //         count++; 
    //     }
    // }
    // if (count == 0) {
    //     printf("Day khong co phan tu duong");
    // }
    // else {
    //     printf("%d\n", count);
    //     for (int i = 0; i < count; i++) {
    //         if (s1[i] > 0) {
    //             printf("%d ", s1[i]);
    //         }
    //     }
    // }

    return 0;
}