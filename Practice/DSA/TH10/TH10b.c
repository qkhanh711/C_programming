#include <stdio.h>
#include <stdlib.h>

void print_array(int K[], int i1, int i2)
{
    int i;
    for (i = i1; i < i2; i++)
    {
        printf("%d ", K[i]);
    }
}

int binarySearch(int list[], int size, int target)
{
    int lower = 0, upper = size - 1, mid;
    while (lower <= upper)
    {
        mid = (lower + upper) / 2;
        if (target < list[mid])
        {
            upper = mid - 1;
        }
        else if (target > list[mid])
        {
            lower = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int first(int arr[], int low, int high, int x, int n)
{
    if (high > low)
    {
        int mid = (low + high) / 2;
        if ((mid == 0 || x < arr[mid - 1]) && arr[mid] == x)
        {
            return mid;
        }
        else if (x < arr[mid])
        {
            return first(arr, (mid + 1), high, x, n);
        }
        else
        {
            return first(arr, low, (mid - 1), x, n);
        }
    }
    return -1;
}

int last(int arr[], int low, int high, int x, int n)
{
    if (high >= low)
    {
        int mid = (low + high) / 2;
        if ((mid == n - 1 || x > arr[mid + 1]) && arr[mid] == x)
        {
            return mid;
        }
        else if (x > arr[mid])
        {
            return last(arr, low, (mid - 1), x, n);
        }
        else
        {
            return last(arr, (mid + 1), high, x, n);
        }
    }
    return -1;
}

int Count(int arr[], int x, int n)
{
    int i, j;
    i = first(arr, 0, n - 1, x, n);
    if (i == -1)
        return -1;
    j = last(arr, i, n - 1, x, n);
    printf("%d %d\n", i, j);
    return j - i + 1;
}

int main()
{
    // int k[] = {1, 2, 2, 2, 3, 4, 5};
    int k[] = {5, 4, 3, 2, 2, 2, 1};
    int x = 2;
    int n = sizeof(k) / sizeof(k[0]);
    int c = Count(k, x, n);
    printf("\nMang da cho: ");
    print_array(k, 0, n - 1);
    printf("\nPhan tu gia tri %d xuat hien %d lan", x, c);

    return 0;
}
