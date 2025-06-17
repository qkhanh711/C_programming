#include <stdio.h>

void printList(int K[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", K[i]);
    }
    printf("\n");
}

void ADJUST(int K[], int i, int n, int reverse)
{
    int Key = K[i];
    int j = 2 * i + 1;
    // printf("Key (before): %d", Key);
    while (j < n)
    {
        if (reverse)
        {
            if (j < n && K[j] > K[j + 1])
            {
                j++;
            }
            if (Key <= K[j])
            {
                break;
            }
        }
        else
        {
            if (j < n && K[j] < K[j + 1])
            {
                j++;
            }
            if (Key >= K[j])
            {
                break;
            }
        }
        // printf("K[(int)(j / 2)] = K[%d] ; K[%d] = %d\n", (int)(j / 2), j, K[j]);
        K[(int)((j-1) / 2)] = K[j];
        j = 2 * j + 1;
    }
    K[ (j-1) / 2] = Key;
    // printf(" Key (after): %d\n", Key);
    // printList(K, n);
    // printf("ADJUSTED\n");
}

void HeapSort(int K[], int n, int reverse)
{
    for (int i = n / 2; i >= 0; i--)
    {
        // printf("ADJUST(K, %d, %d, %d): ", i, n, reverse);
        ADJUST(K, i, n, reverse);
        // printf("ADJUSTING: ");
        // printList(K, n);
    }
    // printf("\n");
    // printList(K, n);

    for (int i = n - 2; i >= 0; i--)
    {
        printList(K, n);
        // printf("Swapping %d with %d\n", K[0], K[i + 1]);
        int temp = K[0];
        K[0] = K[i + 1];
        K[i + 1] = temp;
        ADJUST(K, 0, i, reverse);
    }
}

int main()
{
    int K[12] = {50, 42, 23};

    printf("\nMang truoc khi sap xep: \n");
    printList(K,3);

    HeapSort(K, 3, 0);
    printf("\nMang sau khi sap xep tang dan  : ");
    printList(K, 3);
    
    printf("\n");
    
    HeapSort(K, 3, 1);
    printf("\nMang sau khi sap xep giam dan : ");
    printList(K, 3);
    return 0;
}
