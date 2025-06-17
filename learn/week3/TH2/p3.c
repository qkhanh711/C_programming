#include<stdio.h>
#include<math.h>


int main(){
    float a, b,c;
    scanf("%f %f %f", &a, &b, &c);
    float p = (a + b + c) / 2;
    float S = sqrt(p * (p - a) * (p - b) * (p - c));
    printf("%f\n", S);
    if (a > 0 && b > 0 && c > 0 && a+b > c && a + c > b && b + c > a)
    {
        printf("%.02f", S);
    }
    else
    {
        printf("Error");
    }
    return 0;
}