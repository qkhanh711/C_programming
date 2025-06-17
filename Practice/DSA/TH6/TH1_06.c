#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selection_sort(int k[], int n, int reverse);
void insert_sort(int k[], int n, int reverse);
void bubble_sort(int k[], int n, int reverse);

void selection_sort(int k[], int n, int reverse)
{

    int i, j, m, x;
    for (i = 0; i < n; i++)
    {
        m = i;
        for (j = i + 1; j < n; j++)
            if (reverse ? k[j] > k[m] : k[j] < k[m])
            {
                m = j;
            }
        if (m != i)
        {
            int temp = k[i];
            k[i] = k[m];
            k[m] = temp;
            // Thêm mã chương trình để đổi chỗ k[i] và k[m]
        }
    }
}

void insert_sort(int k[], int n, int reverse)
{
    int i, j, x;
    for (i = 0; i < n; i++)
    {
        x = k[i];
        j = i - 1;
        if (reverse)
        {
            while (x > k[j] && j >= 0)
            {
                k[j + 1] = k[j];
                j--;
            }
        }
        else
        {
            while (x < k[j] && j >= 0)
            {
                k[j + 1] = k[j];
                j--;
            }
        }
        // while (x < k[j] && j >= 0) {
        //     k[j + 1] = k[j];
        //     j--;
        // }
        k[j + 1] = x;
    }
}

void bubble_sort(int k[], int n, int reverse)
{
    int i, j, x;
    for (i = 0; i < n; i++)
    {
        for (j = n - i - 1; j > 0; j--)
            if (reverse ? k[j] > k[j - 1] : k[j] < k[j - 1])
            {
                x = k[j];
                k[j] = k[j - 1];
                k[j - 1] = x;
            }
        // Thêm mã chương trình để đổi chỗ k[j] và k[j-1];
    }
}

int main(void)
{
    int k[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(k) / sizeof(k[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", k[i]);
    }
    printf("\n");

    selection_sort(k, n, 0);
    printf("Sorted array  : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", k[i]);
    }
    printf("\n");

    selection_sort(k, n, 1);
    printf("Sorted array  : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", k[i]);
    }
    printf("\n");

    insert_sort(k, n, 0);
    printf("Sorted array  : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", k[i]);
    }

    printf("\n");
    insert_sort(k, n, 1);
    printf("Sorted array  : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", k[i]);
    }
    printf("\n");

    bubble_sort(k, n, 0);
    printf("Sorted array  : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", k[i]);
    }
    printf("\n");

    bubble_sort(k, n, 1);
    printf("Sorted array  : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", k[i]);
    }

    printf("\n");

    return 0;
}