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

int linearSearch(int list[], int size, int target)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (list[i] == target)
        {
            return i;
        }
    }
    return -1;
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

int countOccurrences(int list[], int size, int target)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (list[i] == target)
        {
            count++;
        }
    }
    return count;
}

int countOccurrencesRecursive(int list[], int size, int target, int index)
{
    if (index < 0)
    {
        return 0;
    }
    return (list[index] == target) + countOccurrencesRecursive(list, size, target, index - 1);    
}

int first(int arr[], int low, int high, int x, int n){
    if (high > low) {
        int mid = (low + high) / 2;
        if ((mid == 0 || x > arr[mid - 1]) && arr[mid] == x) {
            return mid;
        } else if (x > arr[mid]) {
            return first(arr, (mid + 1), high, x, n);
        } else {
            return first(arr, low, (mid - 1), x, n);
        }
    }
    return -1;
}

int last(int arr[], int low, int high, int x, int n){
    if (high >= low) {
        int mid = (low + high) / 2;
        if ((mid == n - 1 || x < arr[mid + 1]) && arr[mid] == x) {
            return mid;
        } else if (x < arr[mid]) {
            return last(arr, low, (mid - 1), x, n);
        } else {
            return last(arr, (mid + 1), high, x, n);
        }
    }
    return -1;
}

int Count(int arr[], int x, int n)
{
    int i, j;
    i = first(arr, 0, n-1, x, n);
    if(i == -1)
        return -1;
    j = last(arr, i, n-1, x, n);
        return j-i+1;
}




int main(void)
{
    // int k[7] = {40, 66, 22, 55, 11, 88};
    // int b[7] = {11, 22, 40, 55, 66, 88};
    // int n = 6;
    // printf("\nMang da cho: ");
    // print_array(k, 0, n - 1);
    // int target = 22;
    // int r = linearSearch(k, n, target);
    // if (r == -1)
    // {
    //     printf("\nKhong ton tai phan tu %d trong mang", target);
    // }
    // else
    // {
    //     printf("\nChi so cua vi tri phan tu %d trong mang la %d", target, r);
    // }
    // printf("\nMang da cho: ");
    // print_array(b, 0, n - 1);
    // target = 22;
    // r = binarySearch(b, 6, 22);
    // if (r == -1)
    //     printf("\nKhong ton tai phan tu %d trong mang", target);
    // else
    //     printf("\nChi so cua vi tri phan tu %d trong mang la: %d", target, r);

    // int x[7] = {1, 1, 2, 2, 2, 2, 3};
    // target = 2;
    // int count = countOccurrencesRecursive(x, 7, target, 6);
    // if (count == 0)
    // {
    //     printf("\nKhong ton tai phan tu %d trong mang", target);
    // }
    // else
    // {
    //     printf("\nPhan tu %d xuat hien %d lan trong mang", target, count);
    // }

    int k[] = {1, 2, 2, 2, 3, 4, 5};
    // int k[] = {5, 4, 3, 2, 2, 2, 1};
    int x = 2;
    int n = sizeof(k)/sizeof(k[0]);
    int c = Count(k, x, n);
    printf("\nMang da cho: ");
    print_array(k, 0, n - 1);
    printf("\nPhan tu gia tri %d xuat hien %d lan", x, c);

    return 0;
}
