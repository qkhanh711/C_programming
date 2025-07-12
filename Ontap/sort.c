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

int Part(int K[], int LB, int UB){
    int i,m;
    i = LB + 1;
    int j = UB;

    while(i<=j)
    {
        while (K[i] > K[LB]) i++;
        while (K[j] < K[LB]) j--;

        if (i<j){

            m = K[i];
            K[i] = K[j];
            K[j] = m;
            i++;
            j--;
        }
    }
    if (K[LB] < K[j]){
        m = K[LB];
        K[LB] = K[j];
        K[j] = m;
        
    }
    return j;
}


void QuickSort(int K[], int LB, int UB){
    int j;
    if (LB < UB){
        j = Part(K, LB, UB);
        QuickSort(K, LB, j - 1);
        QuickSort(K, j + 1, UB);
    }
}

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


void countSort(int a[], int b[], int c[], int k, int n){
    for (int i = 0; i<=k; i++) {
        b[i] = 0;
    }

    for (int i = 0; i<n; i++) {
        b[a[i]]++;
    }

    for (int i = k-1; i>=0; i--) {
        b[i] += b[i+1];
    }

    for (int i = n-1; i>=0; i--) {
        c[b[a[i]]-1] = a[i];
        b[a[i]]--;
    }
}