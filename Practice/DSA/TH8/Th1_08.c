#include <stdio.h>

void ADJUST(int K[], int i, int n, int reverse)
{
    int Key = K[i];
    int j = 2 * i;
    while (j < n)
    {   
        if (reverse){
            if (j < n && K[j] > K[j + 1])
            {
                j++;
            }
            if (Key <= K[j])
            {
                K[j / 2] = K[j];
                break;
            }
            }
            else {
            if (j < n && K[j] < K[j + 1])
            {
                j++;
            }
            if (Key >= K[j])
            {
                break;
            }
        }

        K[j / 2] = K[j];
        j = 2 * j;
    }
    K[j / 2] = Key;
}

void HeapSort(int K[], int n, int reverse)
{
    for (int i = n / 2; i >= 0; i--)
    {
        ADJUST(K, i, n, reverse);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int temp = K[0];
        K[0] = K[i + 1];
        K[i + 1] = temp;
        ADJUST(K, 0, i, reverse);
    }
}

void printList(int K[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", K[i]);
    }
    printf("\n");
}

int main()
{
    int K[12] = {0, 42, 23, 74, 11, 65, 58, 94, 36, 99, 87, 30000};

    printf("\nMang truoc khi sap xep: ");
    printList(K, 12);

    printf("\nMang sau khi sap xep  : ");
    HeapSort(K, 12, 0); 
    
    printList(K, 12);
    HeapSort(K, 12, 1); 

    printf("\nMang sau khi sap xep  : ");
    printList(K, 12);
    return 0;
}
