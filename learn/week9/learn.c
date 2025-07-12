#include <stdio.h>

typedef struct Student
{
    char id[5];
    int num;
    char name[100];
    char loc[100];
} Student;

int main()
{
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    if (input == NULL)
    {
        printf("Can not open file!\n");
        return 1;
    }

    // int line
    int n, threshold, count = 0;
    fscanf(input, "%d %d", &n, &threshold);
    Student stds[100];
    for (int i = 0; i < n; i++)
    {
        // int id, num, name[100], loc[100];
        fscanf(input, "%s %d %s %s", &stds[i].id, &stds[i].num, stds[i].name, stds[i].loc);
        if (stds[i].num >= threshold)
        {
            count++;
            // fprintf(output, "%d %d %s %s\n", stds[i].id, stds[i].num, stds[i].name, stds[i].loc);
        }
    }

    fprintf(output, "Tong so thi sinh trung tuyen: %d", count);
    for (int i = 0; i < n; i++)
    {
        // int id, num, name[100], loc[100];
        // fscanf(input, "%d %d %s %s", &stds[i].id, &stds[i].num, stds[i].name, stds[i].loc);
        if (stds[i].num >= threshold)
        {
            fprintf(output, "\n%s %d %s %s", stds[i].id, stds[i].num, stds[i].name, stds[i].loc);
        }
    }
    fclose(input);
    fclose(output);
}