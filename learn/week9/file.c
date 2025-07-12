#include <stdio.h>
#include <stdlib.h>

int main()
{
    // FILE *fptr = fopen("data.txt", "w");
    // if (fptr == NULL) {
    //     printf("Can not open file!\n");
    //     return 1;
    // }
    // int n = 10;
    // fprintf(fptr, "%d students\n", n);
    // fclose(fptr);
    // return 0;

    FILE *fptr = fopen("data.txt", "r");
    if (fptr == NULL)
    {
        printf("Can not open file!\n");
        return 1;
    }
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), fptr) != NULL)
    {
        printf("%s", buffer);
    }
    fclose(fptr);
    return 0;
}