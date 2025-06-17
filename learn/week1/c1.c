#include <stdio.h>
#include <stdbool.h>
// Bai 1
int suminput()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int sum0 = a + b;
    printf(sum0);
    return 0;
}


// Bai 2
int Upper(){
    char ch = 'a';
    scanf("%c", &ch);
    printf("%c", ch + 65-97);
    // return 0;
}
int array(){
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    
} 



// Duyet mang theo index
int array1(){
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    
}
// Duyet mang theo contro
int array2(){
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(a+i));
    }
}

// Duyet mang theo hang so con tro
int array3(){
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    };
    int *p = a;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(p+i));
    }
}

int main()
{
    // Bai 1
    // suminput();
    // Bai 2
    // Upper();
    // array();
    // array1();
    // array2();
    array3();
}