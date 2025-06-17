#include <stdio.h>

long long factorial(long long n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int main()
{
    int n, target;
    scanf("%d %d", &n, &target);
    int arr[n];
    int found = -1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] == target)
        {
            found = i+1;
        }
    }

    // int found = -1;
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     if (arr[i] == target)
    //     {
    //         found = i + 1;
    //         break;
    //     }
    // }
    printf("%d\n", found);
    // long long n;
    // scanf("%lld", &n);
    // if ( 0 <= n && n <= 20) {printf("%lld\n", factorial(n));}
    
}