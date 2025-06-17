#include<stdio.h>
#include<ctype.h>
#include<string.h>


int sum(int n){
    // printf("%d\n", n);
    int A[n],sum = 0;
    for (int i = 0; i < n; i++){
        scanf("%d", &A[i]);
        // printf("%d ", A[i]);
    }

    for (int i = 0; i < n; i++){
        if (A[i] % 2 == 0){
            sum += A[i];
        }
    }
    printf("\n");
    return sum;
}


int matrix(int n, int m){
    int A[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &A[i][j]);
        }
    }

    int sum_row_0 = 0, sum_col_0 = 0;

    for (int i = 0; i < n; i++){

        for (int j = 0; j < m; j++){
            if (i == 0){
                sum_row_0 += A[i][j];
            }
            if (j == 0){
                sum_col_0 += A[i][j];
            }
        }
    }
    printf("%d \n", sum_row_0);
    printf("%d", sum_col_0);
    return 0;  

}


int count(void){
    // int n;
    // scanf("%d", &n);
    // printf("%d\n", sum(n));
    
    // int n,m;
    // scanf("%d %d", &n, &m);
    // matrix(n, m);

    int n;
    scanf("%d", &n);
    char s[n];
    getchar();
    scanf("%[^\n]", s);
    int count_num = 0;
    int count_char = 0;
    int counnt_special = 0;
    // printf(isdigit('1') ? "yes\n" : "no\n");

    for (int i = 0; i < n; i++){
        if (isdigit(s[i])){
            count_num++;
        }
        else if (isalpha(s[i])){
            count_char++;
        }
        else{
            counnt_special++;
        }
    }
    printf("%d\n", count_num);
    printf("%d\n", count_char);
    printf("%d\n", counnt_special);
    return 0;
}


int main(void){
    // char s1[100], s2[100];
    // // scanf("%[^\n]", s1);
    // scanf("%s", s1);
    // getchar();
    // scanf("%[^\n]", s2);
    // int i = 0;
    // while (s1[i] != "\0" && s2[i] != "\0"){
    //     printf("%c %c\n", s1[i], s2[i]);
    //     printf(s1[i] != NULL && s2[i] != NULL ? "yes\n" : "no\n");
    //     if (s1[i] > s2[i]){
    //         printf("%s\n", s1);
    //         break;
    //     }
    //     else if (s1[i] < s2[i]){
    //         printf("%s\n", s2);
    //         break;
    //     }
    //     i++;
    // }
    // printf('e'> NULL ? "yes\n" : "no\n");

    printf("Bai 1:\n");

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



    printf("Bai 2:\n");

    char A[100], B[100];
    scanf("%s", A);
    getchar();
    scanf("%s", B);
    int i = 0;
    while (A[i] != NULL && B[i] != NULL){
        if (A[i]  == B[i]){
            B[i] = '-';
        }
        i++;

    }
    printf("%s\n", B);
}
