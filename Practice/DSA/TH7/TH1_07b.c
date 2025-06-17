#include <stdio.h>
#include <stdlib.h>

int PartHead(int K[], int LB, int UB)
{
    int i, m;
    i = LB + 1;
    int j = UB;
    while (i <= j)
    {
        while (K[i] < K[LB])
            i++;
        while (K[j] > K[LB])
            j--;

        if (i < j)
        {

            m = K[i];
            K[i] = K[j];
            K[j] = m;
            i++;
            j--;
        }
    }
    if (K[LB] > K[j])
    {
        m = K[LB];
        K[LB] = K[j];
        K[j] = m;
    }
    return j;
}

int PartTail(int K[], int LB, int UB)
{
    int i, m;
    i = UB - 1;
    int j = LB;

    while (i >= j)
    {
        while (K[i] > K[UB])
            i--;
        while (K[j] < K[UB])
            j++;

        if (i > j)
        {

            m = K[i];
            K[i] = K[j];
            K[j] = m;
            i--;
            j++;
        }
    }

    if (K[UB] < K[j])
    {
        m = K[UB];
        K[UB] = K[j];
        K[j] = m;
    }
    return j;
}

int PartBody(int K[], int LB, int UB)
{
    int key = K[(int)(LB + UB) / 2];
    int i = LB;
    int j = UB;
    int m;
    while (i <= j)
    {
        while (K[i] < key)
            i++;
        while (K[j] > key)
            j--;

        if (i <= j)
        {
            m = K[i];
            K[i] = K[j];
            K[j] = m;
            i++;
            j--;
        }
    }

    if (LB < j)
    {
        m = K[LB];
        K[LB] = K[j];
        K[j] = m;
    }

    return i;
}

void QuickSort(int K[], int LB, int UB)
{
    int j;
    if (LB < UB)
    {
        j = PartHead(K, LB, UB);
        // j = PartTail(K, LB, UB);
        // j = PartBody(K, LB, UB);
        QuickSort(K, LB, j - 1);
        QuickSort(K, j + 1, UB);
    }
}

void print_array(int k[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", k[i]);
    }
    printf("\n");
}

int main(void)
{
    // int n;
    // scanf("%d", &n);

    // int K[n];
    // for (int i = 0; i < n; i++) {
    //     scanf("%d ", &K[i]);
    // }
    // getchar();

    int K[12] = {0, 42, 23, 74, 11, 65, 58, 94, 36, 99, 87, 30000};

    printf("\nMang truoc khi sap xep: ");
    print_array(K, 12);
    QuickSort(K, 0, 11);

    printf("\nMang sau khi sap xep  : ");
    print_array(K, 12);

}


// Noi dung de kiem tra giua ky
// Cho 1 doan code co trong, dien vao cho trong
// Bai 1 LinkedList Stack Queue
// Bai 2 BT, BST
// Bai 3 Sorts
// Yeu cau: Chep lai day du doan code, gach chan phan dien