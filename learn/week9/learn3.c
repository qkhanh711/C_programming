#include <stdio.h>
#include <string.h>

int check(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        // printf("%c %c\n", str[i], str[len - i - 1]);
        if (str[i] != str[len - i - 1])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    // FILE *input = fopen("input.txt", "r");
    // FILE *output = fopen("output.txt", "w");
    // if (input == NULL)
    // {
    //     printf("Can not open file!\n");
    //     return 1;
    // }

    // char inStr[100];
    // fscanf(input, "%s", inStr);
    // int i = 0;
    // while (inStr[i] != NULL){
    //     if (inStr[i] >= 'a' && inStr[i] <= 'z') {
    //         inStr[i]  = (inStr[i] - 'a' + 2) % 26 + 'a';
    //     }
    //     i++;
    // }

    // fprintf(output, "%s", inStr);
    // fclose(input);
    // fclose(output);
    // char inStr[100];
    // scanf("%[^\n]", inStr);
    // getchar();
    // int i = 0;
    // while (inStr[i] != '\0') {
    //     if (inStr[i] >= 'a' && inStr[i] <= 'z') {
    //         inStr[i] = (inStr[i] - 'a' + 2) % 26 + 'A';
    //     }
    //     i++;
    // }
    // printf("%s", inStr);
    // return 0;
    int n;
    scanf("%d", &n);
    int count = 0, i = 0;
    while (i < n)
    {
        char str[8000];
        scanf("%s", str);
        getchar();
        if (check(str))
        {
            count++;
        }

        i++;
    }
    printf("%d", count);
}