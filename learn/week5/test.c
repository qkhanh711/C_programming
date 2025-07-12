#include <stdio.h>
#include <math.h>

int sinx() {
    double x, epsilon;
    scanf("%lf %lf", &x, &epsilon);

    double term = x; // term đầu tiên
    double sinx = term;
    int n = 0;

    while (1) {
        n++;
        term *= (-1.0) * x * x / ((2 * n) * (2 * n + 1)); // cập nhật term mới
        if (fabs(term) < epsilon)
            break;
        sinx += term;
    }

    printf("%d\n", n -1);
    printf("%.6lf\n", sinx);

    return 0;
}


int cosx(){
    double x, epsilon;
    scanf("%lf %lf", &x, &epsilon);

    double term = 1;
    double cosx = 1;
    int n = 0;

    while (1){
        n++;
        term *= -1 * x * x / ((2 * n - 1) * (2 * n));
        if (fabs(term) < epsilon)
            break;
        cosx += term;
    }
    printf("%d\n", n - 1);
    printf("%.6lf\n", cosx);
    return 0;

}

int root2(){
    double x, epsilon;
    scanf("%lf %lf", &x, &epsilon);
    double term = x; 
    // int n = 1;

    while (1)
    {
        // n++;
        double temp = term;
        // printf("%lf %lf\n", x/term, term);
        term = 0.5 * (term + x / term);
        // printf("%lf %lf\n", temp, term);
        if (fabs(temp - term) < epsilon)
            break;
    }
    // printf("%d\n", n - 1);
    printf("%.6lf\n", term);
    return  0; 
}

// double pow(double base, int exp) {
//     double result = 1.0;
//     while (exp > 0) {
//         result *= base;
//         exp--;
//     }
//     return result;
// }

int rootn(){
    double x, epsilon;
    int n;
    scanf("%lf %lf %d", &x, &epsilon, &n);
    double term = x; 

    while (1)
    {
        double temp = term;
        term = term - ((pow(term, n) - x) / (n * pow(term, n - 1)));
        if (fabs(temp - term) < epsilon)
            break;
    }
    printf("%.6lf\n", term);
    return 0; 
}

int function(int n){
    return n* n -100 * n + 1;
}


int no() {
    int m1, m2;
    scanf("%d %d", &m1, &m2);

    int result[100000];  
    int count = 0;

    for (int n = 0; n <= 100000; n++) {
        int val = function(n);
        if (val > m2) break;  
        if (val >= m1 && val <= m2) {
            result[count++] = n;
        }
    }

    if (count == 0) {
        printf("vo nghiem\n");
    } else {
        printf("%d\n", count);
        for (int i = 0; i < count; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    }

    return 0;
}

int main(){
    float M;
    scanf("%f", &M);
    float Sn = 0;
    int n = 0;
    int max = 0;
    while (1){
        n++;
        Sn += 1.0 / n;
        // printf("%.6f\n", Sn);
        if (Sn <= M && Sn + 1.0 / (n + 1) > M) {
            max = n; 
            break;
        }
    }
    printf(max == 0 ? "NULL\n" : "%d\n", max); 
    return 0;
}