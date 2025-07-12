#include<stdio.h>  
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct Student {
    int id;
    char name[30];
    float GPA;
} Student;


int main(){
    Student stds[1000];
    int n, count = 0;
    // stds[0].
    scanf("%d", &n);
    char gender[100];

    for (int i = 0; i < n; i++) {
        scanf("%d\n%[^\n]\n%f\n%[^\n]", &stds[i].id, stds[i].name, &stds[i].GPA, &gender);
        if (stds[i].id / 1000000 == 24 && stds[i].GPA >= 2.0 && stds[i].GPA <= 2.5) {
                    count++;
        }
        printf("%d %s %.2f\n", stds[i].id, stds[i].name, stds[i].GPA);
    }
    printf("%d\n", count);
}


// 1
// 24011492
// afasf afasf
// 2.4
// Nam asdSD