#include<stdio.h>
#include<stdlib.h>

int main(){
    float epsilon;
    float sum = 0, n = 0;
    scanf("%f", &epsilon);
    do
    {
        sum += 4 / (2*n + 1);
        n++;
        if (4 / (2*n + 1) < epsilon)
            break;
        sum -= 4 / (2*n + 1);
        n++;
        if (4 / (2*n + 1) < epsilon)
            break;
    } while (4 / (2*n + 1) >= epsilon);
    

    printf("%d\n", (int)n);
    printf("%.6f\n", sum + 4 / (2*n + 1));
    return 0;

}