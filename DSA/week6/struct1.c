#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX 10

typedef struct Date {
    int dat;
    int month;
    int year;
} Date;


typedef struct Student{
    char name[50];
    char gender[10];
    char address[100];
    int age;
    Date dob;
    int GPA;
    int height;
    int weight;
} Student;

int menu() {
    int choice;
    printf("Menu:\n");
    printf("\t1. Input student information\n");
    printf("\t2. Display student information\n");
    printf("\t3. Find student by name\n");
    printf("\t4. Find student by age\n");
    printf("\t5. Find student by range of GPA\n");
    printf("\t6. Sort students by GPA\n");
    printf("\t0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}


Student Input() {
    Student stds;
    printf("Enter student name: ");
    scanf("%s", &stds.name);
    printf("Enter student gender: ");
    scanf("%s", &stds.gender);
    printf("Enter student address: ");
    scanf("%s", &stds.address);
    getchar();
    printf("Enter student age: ");
    scanf("%d", &stds.age);
    printf("Enter student dob: ");
    scanf("%d %d %d", &stds.dob.dat, &stds.dob.month, &stds.dob.year);
    printf("Enter student GPA: ");
    scanf("%d", &stds.GPA);
    printf("Enter student height: ");
    scanf("%d", &stds.height);
    printf("Enter student weight: ");
    scanf("%d", &stds.weight);
    return stds;
}

int Display(Student stds[], int num_students){
    if (num_students == 0){
        printf("\tNo students to display.\n");
        return 0;
    }
    for (int i = 0; i < num_students; i++){
        printf("Student %d:\n", i + 1);
        printf("\tName   : %s\n", stds[i].name);
        printf("\tGender : %s\n", stds[i].gender);
        printf("\tAddress: %s\n", stds[i].address);
        printf("\tAge    : %d\n", stds[i].age);
        printf("\tDOB    : %02d/%02d/%04d\n", stds[i].dob.dat, stds[i].dob.month, stds[i].dob.year);
        printf("\tGPA    : %d\n", stds[i].GPA);
        printf("\tHeight : %d cm\n", stds[i].height);
        printf("\tWeight : %d kg\n", stds[i].weight);
        printf("\n");
    }
}


Student findByName(Student stds[], int num_students, char name[]) {
    for (int i = 0; i < num_students; i++) {
        if (strcmp(stds[i].name, name) == 0) {
            printf("Student %d:\n", i + 1);
            printf("\tName   : %s\n", stds[i].name);
            printf("\tGPA    : %d\n", stds[i].GPA);
            printf("\tAge    : %d\n", stds[i].age);
        }
    }
} 

Student findByAge(Student stds[], int num_students, int age) {
    for (int i = 0; i < num_students; i++) {
        if (stds[i].age == age) {
            printf("Student %d:\n", i + 1);
            printf("\tName   : %s\n", stds[i].name);
            printf("\tGPA    : %d\n", stds[i].GPA);
            printf("\tAge    : %d\n", stds[i].age);
            return stds[i];
        }
    }
}

Student findByGPA(Student stds[], int num_students, int min_gpa, int max_gpa) {
    for (int i = 0; i < num_students; i++) {
        if (stds[i].GPA >= min_gpa && stds[i].GPA <= max_gpa) {
            printf("Student %d:\n", i + 1);
            printf("\tName   : %s\n", stds[i].name);
            printf("\tGPA    : %d\n", stds[i].GPA);
            printf("\tAge    : %d\n", stds[i].age);
        }
    }
}

int SortByGPA(Student stds[], int num_students) {
    // Buble Sort
    for (int i = 0; i < num_students - 1; i++) {
        for (int j = i + 1; j < num_students; j++) {
            if (stds[i].GPA > stds[j].GPA) {
                Student temp = stds[i];
                stds[i] = stds[j];
                stds[j] = temp;
            }
        }
    }
    return 0;
}

int SortByGPA1(Student stds[], int num_students) {
    // Selection Sort
    for (int i = 0; i < num_students - 1; i++) {
        int minindex = 0;
        for (int j = i + 1; j < num_students; j++) {
            if (stds[j].GPA > stds[minindex].GPA) {
                minindex = j;
            }
            if (minindex != i) {
                Student temp = stds[i];
                stds[i] = stds[minindex];
                stds[minindex] = temp;
            }
        }
    }
    return 0;
}

int main(){
    Student stds[MAX];
    int num_students = 0;
    int choice;
    do
    {
        choice = menu();
        switch (choice) 
        {
        case 1:
            stds[num_students] = Input();
            num_students++;
            break;
        case 2:
            Display(stds, num_students);
            break;
        case 3: 
            char name[50];
            printf("Enter student name to find: ");
            scanf("%s", name);
            findByName(stds, num_students, name);
            break;
        case 4:
            int age;
            printf("Enter student age to find: ");
            scanf("%d", &age);
            findByAge(stds, num_students, age);
            break;
        case 5:
            int min_gpa, max_gpa;
            printf("Enter minimum GPA: ");
            scanf("%d", &min_gpa);
            printf("Enter maximum GPA: ");
            scanf("%d", &max_gpa);
            findByGPA(stds, num_students, min_gpa, max_gpa);
            break;
        case 6:
            SortByGPA(stds, num_students);
            printf("Students sorted by GPA:\n");
            Display(stds, num_students);
            SortByGPA1(stds, num_students);
            printf("Students sorted by GPA:\n");
            Display(stds, num_students);
            break;
        case 0:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
        
    } while (choice != 0);
    
}