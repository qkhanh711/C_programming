#include<stdio.h>

int main(){
    int n; 
    long long t;
    scanf("%d %lld", &n, &t);
    long long mul = (long long) n * t;
    if (t == 0) printf("%d", 0);
    else if (n>= 3 && n<=1000) printf("%lld", mul);
    else return 0;
}
