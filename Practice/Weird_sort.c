#include<stdio.h>

struct Weird_sort
{
    int num;
    int frequency;
} Weird_sort[1000];


void print_num(struct Weird_sort arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i].num);
    }
}

void print_frequency(struct Weird_sort arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i].frequency);
    }
}

void sort_by_frequency(struct Weird_sort arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i].frequency < arr[j].frequency)
            {
                if (arr[i].num < arr[j].num)
                {
                    struct Weird_sort temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
}

int main (){
    int n;
    scanf("%d", &n);
    int arr[1000];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)

        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        Weird_sort[i].num = arr[i];
        Weird_sort[i].frequency = count;
    }
    
    print_num(Weird_sort, n);
    printf("\n");
    print_frequency(Weird_sort, n);
    printf("\n");
    sort_by_frequency(Weird_sort, n);
    print_num(Weird_sort, n);
}
