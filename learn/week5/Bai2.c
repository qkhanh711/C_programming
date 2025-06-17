#include <stdio.h>
#include <string.h>


int main(void){
    char A[100], B[100];
    scanf("%s", A);
    getchar();
    scanf("%s", B);
    // int i = 0;
    int len_a = strlen(A);
    int len_b = strlen(B);

    for (int i = 0; i < len_a; i++){
        int j = 0;
        int u = 0;
        while (i< len_a && u < len_b && B[j] == A[i+j]){
            if (A[i] == B[j]){
                A[i] = '@'; 
            }
           
            u++;
            j++;
            if (u == len_b){
                u = 0;
              
            }
        }
    }


    printf("%s\n", A);
}