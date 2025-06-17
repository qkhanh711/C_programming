#include <stdio.h>

int main()
{   
    int i, j;
    int arr[3][3] = {{1, 2}, 
                     {4},
                     {5, 7}};
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}