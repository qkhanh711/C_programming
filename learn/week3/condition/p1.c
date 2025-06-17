#include<stdio.h>
// #include<math.h>
// gcc p3.c -o output/p3 -lm                                                                                                                                                                           INT  base py  at 07:37:56 
// ./output/p3    

int main(){
    float a = 0;

    if ( 9.0 <= a && a <= 10.0) {
        printf("A+");
    }
    else if ( 8.5 <= a && a < 9.0) {
        printf("A");
    }
    else if ( 8 <= a && a < 8.5) {
        printf("B+");
    }
    else if ( 7.0 <= a && a < 8.0) {
        printf("B");
    }
    else if ( 6.0 <= a && a < 7.0) {
        printf("C+");
    }
    else if ( 5.0 <= a && a < 6.0) {
        printf("C");
    }    
    else if ( 4.5 <= a && a < 5.0) {
        printf("D+");
    }
    else if ( 4.0 <= a && a < 4.5) {
        printf("D");
    }
    else
        printf("F");
}