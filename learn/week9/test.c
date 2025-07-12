#include<stdio.h>

typedef struct Student{
    char id[9];
    char name[100];
    float GPA;
} Student;

int main(){
    int n;
    scanf("%d", &n);
    Student stds[1000];
    for(int i = 0; i < n; i++){
        scanf("%s\n%[^\n]\n%f", stds[i].id, stds[i].name, &stds[i].GPA);
    }

    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (stds[i].GPA > stds[j].GPA){
                Student temp = stds[i];
                stds[i] = stds[j];
                stds[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++){
        printf("%s ", stds[i].id);
    }
}