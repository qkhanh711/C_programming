#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

int isPassCorrect(char *input, char *password)
{
    for (int i = 0; i < 8; i++)
    {
        if (input[i] != password[i])
        {
            return 0;
        }
    }
    return 1;
}

int bai1(void){
    char password[10] = "admin123.";
    char input[20];
    do
    {
        scanf("%s", input);
        if (isPassCorrect(input, password))
        {
            printf("Dang nhap thanh cong.\n");
            break;
        } else
        {
            printf("Sai mat khau. Vui long nhap lai.\n");
        }
    } while (1);
    return 0;
}

int bai2(void){
    int n;
    do
    {   
        scanf("%d", &n);
        if (n>0){
            printf("Ban da nhap dung: %d", n);
            break;

        }

    } while (n<=0);
    return 0;
    
}

int bai3(void){
    return 0;
}

int bai4_pi(void){
    double epsilon;
    scanf("%lf", &epsilon);
    int n = 0;
    double pi = 0;
    while ( 4.0 / ( 2 * n + 1) >= epsilon){

        pi += pow(-1, n) * (4.0 / (2 * n + 1));
        n++;
        if ( 4.0 / (2 * n + 1) < epsilon){
            pi += pow(-1, n) * (4.0 / (2 * n + 1));
            printf("%d\n", n);
            printf("%.6lf\n", pi);
            break;
        }
    }
    return 0;
}

float factorial(float n){
    if (n == 0 || n == 1){
        return 1;
    }
    return n * factorial(n - 1);
}

int bai5_e(void){
    double epsilon;
    scanf("%lf", &epsilon);
    int n = 0;
    double e = 1;

    while (1/factorial(n) >= epsilon){
        n++;
        e += 1.0 / factorial(n);
        if (1/factorial(n+1) < epsilon){
            // e += 1.0 / factorial(n+1);
            printf("%d\n", n);
            printf("%.6lf\n", e);
            break;
        }
    }
    return 0;
}

int main(void){
    double epsilon;
    scanf("%lf", &epsilon);
    double n = 1;
    double ln2 = 0;

    while (1/n >= epsilon){
        ln2 += pow(-1, n+1) * (1/n);
        n++;
        if (1/(n+1) < epsilon){
            // ln2 += pow(-1, n-1) * (1/n);
            printf("%d\n", (int)n);
            printf("%.6lf\n", ln2);
            break;
        }
    }
    return 0;
}